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

#include "OLEDC_graphics.h"
#include "OLEDC.h"


const uint8_t font[] = { // compact 5x8 font
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5F,0x00,0x00,0x00,0x07,0x00,0x07,0x00, //	'sp,!,"
    0x14,0x7F,0x14,0x7F,0x14, // #
    0x24,0x2A,0x7F,0x2A,0x12,0x23,0x13,0x08,0x64,0x62,0x36,0x49,0x56,0x20,0x50, //	'$,%,&
    0x00,0x08,0x07,0x03,0x00,0x00,0x1C,0x22,0x41,0x00,0x00,0x41,0x22,0x1C,0x00, //	'',(,)
    0x2A,0x1C,0x7F,0x1C,0x2A,0x08,0x08,0x3E,0x08,0x08,0x00,0x00,0x70,0x30,0x00, //	'*,+,,
    0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x60,0x60,0x00,0x20,0x10,0x08,0x04,0x02, //	'-,.,/
    0x3E,0x51,0x49,0x45,0x3E,0x00,0x42,0x7F,0x40,0x00,0x72,0x49,0x49,0x49,0x46, //	'0,1,2
    0x21,0x41,0x49,0x4D,0x33,0x18,0x14,0x12,0x7F,0x10,0x27,0x45,0x45,0x45,0x39, //	'3,4,5
    0x3C,0x4A,0x49,0x49,0x31,0x41,0x21,0x11,0x09,0x07,0x36,0x49,0x49,0x49,0x36, //	'6,7,8
    0x46,0x49,0x49,0x29,0x1E,0x00,0x00,0x14,0x00,0x00,0x00,0x40,0x34,0x00,0x00, //	'9,:,;
    0x00,0x08,0x14,0x22,0x41,0x14,0x14,0x14,0x14,0x14,0x00,0x41,0x22,0x14,0x08, //	'<,=,>
    0x02,0x01,0x59,0x09,0x06,0x3E,0x41,0x5D,0x59,0x4E,                          //  '?,@
    0x7C,0x12,0x11,0x12,0x7C,                                                   //	'A
    0x7F,0x49,0x49,0x49,0x36,0x3E,0x41,0x41,0x41,0x22,0x7F,0x41,0x41,0x41,0x3E, //	'B,C,D
    0x7F,0x49,0x49,0x49,0x41,0x7F,0x09,0x09,0x09,0x01,0x3E,0x41,0x41,0x51,0x73, //	'E,F,G
    0x7F,0x08,0x08,0x08,0x7F,0x00,0x41,0x7F,0x41,0x00,0x20,0x40,0x41,0x3F,0x01, //	'H,I,J
    0x7F,0x08,0x14,0x22,0x41,0x7F,0x40,0x40,0x40,0x40,0x7F,0x02,0x1C,0x02,0x7F, //	'K,L,M
    0x7F,0x04,0x08,0x10,0x7F,0x3E,0x41,0x41,0x41,0x3E,0x7F,0x09,0x09,0x09,0x06, //	'N,O,P
    0x3E,0x41,0x51,0x21,0x5E,0x7F,0x09,0x19,0x29,0x46,0x26,0x49,0x49,0x49,0x32, //	'Q,R,S
    0x03,0x01,0x7F,0x01,0x03,0x3F,0x40,0x40,0x40,0x3F,0x1F,0x20,0x40,0x20,0x1F, //	'T,U,V
    0x3F,0x40,0x38,0x40,0x3F,0x63,0x14,0x08,0x14,0x63,0x03,0x04,0x78,0x04,0x03, //	'W,X,Y
    0x61,0x59,0x49,0x4D,0x43,                                                   //  'Z
    0x00,0x7F,0x41,0x41,0x41,0x02,0x04,0x08,0x10,0x20,                          //	'[,backslash
    0x00,0x41,0x41,0x41,0x7F,0x04,0x02,0x01,0x02,0x04,0x40,0x40,0x40,0x40,0x40, //	'],^,_
    0x00,0x03,0x07,0x08,0x00,0x20,0x54,0x54,0x38,0x40,0x7F,0x28,0x44,0x44,0x38, //	'`,a,b
    0x38,0x44,0x44,0x44,0x28,0x38,0x44,0x44,0x28,0x7F,0x38,0x54,0x54,0x54,0x18, //	'c,d,e
    0x00,0x08,0x7E,0x09,0x02,0x0C,0x52,0x52,0x4A,0x3C,0x7F,0x08,0x04,0x04,0x78, //	'f,g,h
    0x00,0x44,0x7D,0x40,0x00,0x20,0x40,0x40,0x3D,0x00,0x7F,0x10,0x28,0x44,0x00, //	'i,j,k
    0x00,0x41,0x7F,0x40,0x00,0x7C,0x04,0x78,0x04,0x78,0x7C,0x08,0x04,0x04,0x78, //	'l,m,n
    0x38,0x44,0x44,0x44,0x38,0x7C,0x18,0x24,0x24,0x18,0x18,0x24,0x24,0x18,0x7C, //	'o,p,q
    0x7C,0x08,0x04,0x04,0x08,0x48,0x54,0x54,0x54,0x24,0x04,0x04,0x3F,0x44,0x24, //	'r,s,t
    0x3C,0x40,0x40,0x20,0x7C,0x1C,0x20,0x40,0x20,0x1C,0x3C,0x40,0x30,0x40,0x3C, //	'u,v,w
    0x44,0x28,0x10,0x28,0x44,0x4C,0x50,0x50,0x50,0x3C,0x44,0x64,0x54,0x4C,0x44, //	'x,y,z
    0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x77,0x00,0x00,0x00,0x41,0x36,0x08,0x00, //	'{,|,}
    0x02,0x01,0x02,0x04,0x02                                                    //  '~
    };

uint8_t sx=1, sy=1;
uint16_t color;
uint16_t background_color;

void OLEDC_setScale(uint8_t _sx, uint8_t _sy)
{
    sx = _sx;
    sy = _sy;
}

void OLEDC_setColor(uint16_t c)
{
    color = c;
}

void OLEDC_clearScreen(void) {
    oledC_setColumnAddressBounds(0,96);
    oledC_setRowAddressBounds(0,96);
    uint8_t x, y;
    for( x = 0; x < 96; x++){
        for( y = 0; y < 96; y++){
            oledC_sendColorInt(background_color);
        }
    }
}

void OLEDC_setBackground(uint16_t color){
    background_color = color;
    OLEDC_clearScreen();
}

uint8_t coerceAddressAdditionWithinRange(uint8_t base_address, int8_t adder){
    int16_t additionResult = base_address+adder;
    if(additionResult > (int16_t)OLEDC_DIM_WIDTH){
        return OLEDC_DIM_WIDTH;
    }
    if(additionResult < (int16_t) 0x00) {
        return 0x00;
    }
    return (uint8_t) (base_address+adder);
}

void OLEDC_point(uint8_t x, uint8_t y){
    if(x > OLEDC_DIM_WIDTH || y > OLEDC_DIM_HEIGHT){
        return;
    }
    oledC_setColumnAddressBounds(95-x,95);
    oledC_setRowAddressBounds(95-y,95);
    oledC_sendColorInt(color);
}

void OLEDC_thickPoint(uint8_t center_x, uint8_t center_y, uint8_t width){
    uint8_t max_x,min_x,max_y, min_y;
    uint8_t x, y, dx, dy;
    if((center_x-width) > OLEDC_DIM_WIDTH || (center_y-width) > OLEDC_DIM_HEIGHT){
        return;
    }
    width = (width <= 1) ? 1 : width;
    max_x = coerceAddressAdditionWithinRange(center_x, width);
    min_x = coerceAddressAdditionWithinRange(center_x, -(width));
    max_y = coerceAddressAdditionWithinRange(center_y, width);
    min_y = coerceAddressAdditionWithinRange(center_y, -(width));

    for(x = min_x; x < max_x; x++){
        dx = (center_x >= x) ? (center_x-x) : (x - center_x);
        for(y = min_y; y < max_y; y++){
            dy = (center_y >= y) ? (center_y-y) : (y - center_y);
            if(((dy+dx) <= width)|| (dy*dy+dx*dx) <= (width*width)){
                OLEDC_point(x, y);
            }
        }
    }
}

void OLEDC_filled_circle(uint8_t x0, uint8_t y0, uint8_t radius){
    int8_t xCurr, yMax = 0, y = 0, x;
    int16_t d = 0;

    radius = radius <= 1 ? 1 : radius;
    xCurr = radius+1;
    yMax = 0;
    y = 0;
    d = 0;

    while (xCurr >= yMax){
        d += (2*yMax+1);
        yMax++;
        if(d >= 0){
            for(y = y; y < yMax; y++){
                for(x = y; x < xCurr; x++){
                    OLEDC_point(x0 + x,y0 + y);
                    OLEDC_point(x0 + x,y0 - y);
                    OLEDC_point(x0 - x,y0 + y);
                    OLEDC_point(x0 - x,y0 - y);
                    OLEDC_point(x0 + y,y0 + x);
                    OLEDC_point(x0 + y,y0 - x);
                    OLEDC_point(x0 - y,y0 + x);
                    OLEDC_point(x0 - y,y0 - x);
                }
            }
            d += -2*xCurr + 1;
            xCurr--;
        }
    }
}

void OLEDC_circle(uint8_t x0, uint8_t y0, uint8_t radius, uint8_t width){
    int8_t x, y;
    int16_t d;
    radius += width >> 1;
    while(width-- > 0){
        x = radius;
        y = 0;
        d = 0;

        while (x >= y){
            OLEDC_point(x0 + x,y0 + y);
            OLEDC_point(x0 + x,y0 - y);
            OLEDC_point(x0 - x,y0 + y);
            OLEDC_point(x0 - x,y0 - y);
            OLEDC_point(x0 + y,y0 + x);
            OLEDC_point(x0 + y,y0 - x);
            OLEDC_point(x0 - y,y0 + x);
            OLEDC_point(x0 - y,y0 - x);

            d += (2*y+1);
            y++;
            if(d >= 0){
                d += -2*x + 1;
                x--;
            }
        }
        radius--;
    }
}

void point(uint8_t x, uint8_t y, uint8_t width)
{
    if (width<=1)
        OLEDC_point(x, y);
    else
        OLEDC_filled_circle(x,y,width/2);
}

void OLEDC_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t width)
{
     int steep, t ;
     int deltax, deltay, error;
     int x, y;
     int ystep;

     steep = ( abs(y1 - y0) > abs(x1 - x0));

     if ( steep )
     { // swap x and y
         t = x0; x0 = y0; y0 = t;
         t = x1; x1 = y1; y1 = t;
     }
     if (x0 > x1)
     {  // swap ends
         t = x0; x0 = x1; x1 = t;
         t = y0; y0 = y1; y1 = t;
     }

     deltax = x1 - x0;
     deltay = abs(y1 - y0);
     error = 0;
     y = y0;

     if (y0 < y1) ystep = 1; else ystep = -1;
     for (x = x0; x < x1; x++)
     {
         if ( steep) point(y,x,width); else point(x,y,width);
         error += deltay;
         if ( (error<<1) >= deltax)
         {
             y += ystep;
             error -= deltax;
         } // if
     } // for
}

void OLEDC_rectangle(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y){
    oledC_setColumnAddressBounds(95-end_x, 95 - start_x);
    oledC_setRowAddressBounds(95-end_y, 95-start_y);
    uint8_t x, y;
    for( x = start_x; x < end_x+1; x++){
        for(y = start_y; y < end_y+1; y++){
            oledC_sendColorInt(color);
        }
    }
}

void OLEDC_putc(uint8_t x, uint8_t y, char ch){
    const uint8_t *f = &font[(ch-' ')*OLEDC_FONT_WIDTH]; // find the char in our font...
    uint16_t i_x, i_y;
    for(i_x = 0; i_x < OLEDC_FONT_WIDTH * sx; i_x += sx) { // For each line of our text...
        uint8_t curr_char_byte = *f++;
        for(i_y = OLEDC_FONT_HEIGHT*sy; i_y > 0; i_y -= sy){
            if(curr_char_byte & 0x80){
                OLEDC_rectangle(x+i_x, y+i_y, x+i_x+sx-1, y+i_y+sy-1);
            }
            curr_char_byte <<= 1;
        }
    }
}

void OLEDC_puts(uint8_t x, uint8_t y, char *string)
{
    while(*string){
        OLEDC_putc(x, y*8, *string++);
        x += OLEDC_FONT_WIDTH * sx + 1;
    }
}

void OLEDC_drawBitmap(uint8_t x, uint8_t y, uint8_t *bitmap, uint8_t bitmap_length){
    const uint8_t bitmap_width = 24;
    sx = sx == 0 ? 1 : sx;
    sy = sy == 0 ? 1 : sy;
    uint8_t rowNum, bitNum, rowBits;
    for( rowNum = 0; rowNum < bitmap_length; rowNum++){
        uint8_t curr_y = y + rowNum*sy;
        for( bitNum = 0; bitNum < bitmap_width; bitNum++){
            if ((bitNum & 0x7) == 0)
                rowBits = *bitmap++;
            if(!(rowBits & 0x80)){
                uint8_t curr_x = x + (bitNum)*sx;
                OLEDC_rectangle(curr_x, curr_y, curr_x+sx-1, curr_y+sy-1);
            }
            rowBits <<= 1;
        }
    }
}

