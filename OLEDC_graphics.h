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

#ifndef OLEDC_SHAPES_H
#define	OLEDC_SHAPES_H


#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define OLEDC_DIM_WIDTH      95
#define OLEDC_DIM_HEIGHT     95
#define OLEDC_FONT_WIDTH     5
#define OLEDC_FONT_HEIGHT    8

void OLEDC_setScale(uint8_t _sx, uint8_t _sy);

void OLEDC_setColor(uint16_t c);

void OLEDC_clearScreen(void);

void OLEDC_setBackground(uint16_t color);


void OLEDC_circle(uint8_t center_x, uint8_t center_y, uint8_t radius);
void OLEDC_ring(uint8_t center_x, uint8_t center_y, uint8_t radius, uint8_t width);
void OLEDC_rectangle(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y);
void OLEDC_line(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y, uint8_t width);
void OLEDC_point(uint8_t x, uint8_t y);
void OLEDC_thickPoint(uint8_t center_x, uint8_t center_y, uint8_t width);
void OLEDC_putc(uint8_t x, uint8_t y, char ch);
void OLEDC_puts(uint8_t x, uint8_t y, char *string);
void OLEDC_drawBitmap(uint8_t x, uint8_t y, uint8_t *bit_array, uint8_t len);

#endif	/* OLEDC_SHAPES_H */
