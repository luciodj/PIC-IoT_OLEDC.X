 /*
     (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#define FCY 16000000L
#include <libpic30.h>
#include "mcc_generated_files/mcc.h"
#include "OLEDC.h"


enum STREAMING_MODES {
    NOSTREAM, WRITESTREAM, READSTREAM
};
uint8_t streamingMode = NOSTREAM;

void startStreamingIfNeeded(OLEDC_COMMAND cmd);
void stopStreaming(void);
uint16_t exchangeTwoBytes(uint8_t byte1, uint8_t byte2);

oledc_color_t OLEDC_parseIntToRGB(uint16_t raw){
    oledc_color_t parsedColor;
    uint8_t byte1 = raw >> 8;
    uint8_t byte2 = raw & 0xFF;
    parsedColor.red = (byte1 >> 3);
    parsedColor.green = ((byte1 & 0x7) << 3) | (byte2 >> 5);
    parsedColor.blue = byte2 & 0x1F;
    return parsedColor;
}

uint16_t OLEDC_parseRGBToInt(uint8_t red, uint8_t green, uint8_t blue){
    red &= 0x1F;
    green &= 0x3F;
    blue &= 0x1F;
    uint8_t byte1;
    uint8_t byte2;
    byte1 = (red << 3) | (green >> 3);
    byte2 = (green << 5) | blue;
    return (((uint16_t)byte1) << 8) | byte2;
}

void startStreamingIfNeeded(OLEDC_COMMAND cmd){
    if(cmd == OLEDC_CMD_WRITE_RAM || cmd == OLEDC_CMD_READ_RAM){
        streamingMode = cmd == OLEDC_CMD_WRITE_RAM ? WRITESTREAM : READSTREAM;
    } else {
        streamingMode = NOSTREAM;
    }
}
void stopStreaming(void){
    streamingMode = NOSTREAM;
}
uint16_t exchangeTwoBytes(uint8_t byte1, uint8_t byte2){
    if(!spi_master_open(OLEDC)){
        return -1;
    };
    byte1 = spi2_exchangeByte(byte1);
    byte2 = spi2_exchangeByte(byte2);
    spi2_close();
    return ((uint16_t)byte1) << 8 | byte2;
}

void sendCommand(OLEDC_COMMAND cmd, uint8_t *payload, uint8_t payload_size){
    if(!spi_master_open(OLEDC)){
        return;
    };
    OLEDC_nCS_SetLow();
    OLEDC_DC_SetLow();
    spi2_exchangeByte(cmd);
    if(payload_size > 0){
        OLEDC_DC_SetHigh();
        spi2_writeBlock(payload, payload_size);
        OLEDC_DC_SetLow();
    }
    OLEDC_nCS_SetHigh();
    spi2_close();
    startStreamingIfNeeded(cmd);
}

void OLEDC_setRowAddressBounds(uint8_t min, uint8_t max){
    uint8_t payload[2];
    payload[0] = min > 95 ? 95 : min;
    payload[1] = max > 95 ? 95 : max;
    sendCommand(OLEDC_CMD_SET_ROW_ADDRESS, payload, 2);

}
void OLEDC_setColumnAddressBounds(uint8_t min, uint8_t max){
    min = min > 95 ? 95 : min;
    max = max > 95 ? 95 : max;
    uint8_t payload[2];
    payload[0] = 16+min;
    payload[1] = max + 16;
    sendCommand(OLEDC_CMD_SET_COLUMN_ADDRESS, payload, 2);
}

void OLEDC_setSleepMode(bool on){
    sendCommand(on ? OLEDC_CMD_SET_SLEEP_MODE_ON : OLEDC_CMD_SET_SLEEP_MODE_OFF, NULL, 0);
}

void OLEDC_startReadingDisplay(void){
    sendCommand(OLEDC_CMD_READ_RAM, NULL, 0);
    OLEDC_nCS_SetLow();
    OLEDC_DC_SetHigh();
}
void OLEDC_stopReadingDisplay(void){
    OLEDC_stopWritingDisplay();
}

uint16_t OLEDC_readColor(void){
    if(streamingMode != READSTREAM){
        OLEDC_startReadingDisplay();
    }
    if(streamingMode != READSTREAM){
        return 0xFFFF;
    }
    return exchangeTwoBytes(0xFF, 0xFF);
}

void OLEDC_startWritingDisplay(void){
    sendCommand(OLEDC_CMD_WRITE_RAM, NULL, 0);
    OLEDC_nCS_SetLow();
    OLEDC_DC_SetHigh();
}
void OLEDC_stopWritingDisplay(void){
    OLEDC_nCS_SetHigh();
    OLEDC_DC_SetLow();
    stopStreaming();
}
void OLEDC_sendColor(uint8_t r, uint8_t g, uint8_t b){
    OLEDC_sendColorInt(OLEDC_parseRGBToInt(r,g,b));
}
void OLEDC_sendColorInt(uint16_t raw){
    if(streamingMode != WRITESTREAM){
        OLEDC_startWritingDisplay();
    }
    if(streamingMode != WRITESTREAM){
        return;
    }
    exchangeTwoBytes(raw >> 8, raw & 0x00FF);
}
void OLEDC_init(void){
    OLEDC_EN_SetLow();
    OLEDC_RST_SetHigh();
    OLEDC_RW_SetLow();
    __delay_ms(1);
    OLEDC_RST_SetLow();
    __delay_us(2);
    OLEDC_RST_SetHigh();
    OLEDC_EN_SetHigh();
    __delay_ms(1);
    OLEDC_setSleepMode(false);
    __delay_ms(200);

    OLEDC_setColumnAddressBounds(0, 95);
    OLEDC_setRowAddressBounds(0, 95);
}
