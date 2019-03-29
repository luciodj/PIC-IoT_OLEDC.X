/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
*/

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

/**
  Section: Included Files
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/led.h"
#include "mcc_generated_files/sensors_handling.h"
#include "mcc_generated_files/cloud/cloud_service.h"
#include "mcc_generated_files/debug_print.h"
#include "OLEDC.h"
#include "OLEDC_colors.h"
#include "OLEDC_graphics.h"
#include <time.h>

#define OLEDC_TIMEOUT 10

int oled_timeout = 0;

//This handles messages published from the MQTT server when subscribed
void receivedFromCloud(uint8_t *topic, uint8_t *payload)
{
    char *toggleToken = "\"toggle\":";
    char *subString;

    if ((subString = strstr((char*)payload, toggleToken)))
    {
        LED_holdYellowOn( subString[strlen(toggleToken)] == '1' );
    }
    OLEDC_setScale(1,1);
    OLEDC_setColor(OLEDC_COLOR_GREEN);
    OLEDC_puts(0, 0, (char*)payload);
    oled_timeout = OLEDC_TIMEOUT;
//    debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "topic: %s", topic);
    debug_printer(SEVERITY_NONE, LEVEL_NORMAL, "payload: %s", payload);
}

extern time_t timeNow;

// This will get called every CFG_SEND_INTERVAL only while we have a valid Cloud connection
void sendToCloud(void)
{
   static char json[100];

   // This part runs every seconds
   int rawTemperature = SENSORS_getTempValue();
   int light = SENSORS_getLightValue();
   int len = sprintf(json, "{\"Light\":%d,\"Temp\":\"%d.%02d\"}",
                            light,rawTemperature/100,abs(rawTemperature)%100);
   if (len >0) {
      CLOUD_publishData((uint8_t*)json, len);
      LED_flashYellow();
   }

    char s[30];
    const char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm* current_time;
    current_time = localtime(&timeNow);
    if (current_time->tm_sec % 20 == 0)
    {
        OLEDC_clearScreen();
        OLEDC_setScale(2,2);
        sprintf(s, " %02d:%02d",
               current_time->tm_hour+1, // GMT+1
               current_time->tm_min
               );
        OLEDC_puts(0, 0, s);
        sprintf(s, " %s %02d",
               months[current_time->tm_mon],
               current_time->tm_mday);
        OLEDC_puts(0, 2, s);
        oled_timeout = OLEDC_TIMEOUT;
    }

   if (oled_timeout > 0) {
       oled_timeout--;
       if (oled_timeout == 0){
           OLEDC_clearScreen();
       }
   }
}

#include "mcc_generated_files/application_manager.h"

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    application_init();
    OLEDC_init();
    OLEDC_setBackground(OLEDC_COLOR_BLACK);
    OLEDC_clearScreen();

    OLEDC_setColor(OLEDC_COLOR_RED);
    OLEDC_setScale(2, 4);
    OLEDC_puts(0, 4, "PIC-IoT");

    while (1)
    {
        // Add your application code
        runScheduler();
    }

    return 1;
}
/**
 End of File
*/

