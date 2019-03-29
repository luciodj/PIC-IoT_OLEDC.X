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
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "OLEDC_colors.h"
#include "OLEDC.h"
#include "OLEDC_graphics.h"

bool exampleInitialized = false;

const uint8_t logo[] = {
    0b11111110,0b00000000,0b01111111,
    0b11111000,0b00000000,0b00111111,
    0b11110000,0b00000000,0b00011111,
    0b11100000,0b00000000,0b00011111,
    0b11000000,0b00000000,0b00001111,
    0b10000000,0b10000000,0b10001111,
    0b10000001,0b10000001,0b10000111,
    0b00000011,0b11000011,0b11000011,
    0b00000011,0b11100011,0b11100011,
    0b00000001,0b11100001,0b11100001,
    0b00000001,0b11110001,0b11110000,
    0b00010000,0b11110000,0b11111000,
    0b00011000,0b11111000,0b11111000,
    0b00111100,0b01111100,0b01111100,
    0b01111100,0b00111100,0b00111100,
    0b11111000,0b00111100,0b00111111,
    0b11111000,0b00011100,0b00011111,
    0b11110000,0b00011000,0b00001111,
    0b11100000,0b00000000,0b00001111,
    0b11100000,0b00000000,0b00000111,
    0b11100000,0b00000000,0b00000111,
    0b11111000,0b00000000,0b00011111,
    0b11111110,0b00000000,0b01111111
};


void OLEDC_example(void){
    int8_t shift = 0;


}

