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

#ifndef OLEDC_GRAPHICS_H
#define	OLEDC_GRAPHICS_H


#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define OLEDC_DIM_WIDTH      95
#define OLEDC_DIM_HEIGHT     95
#define OLEDC_FONT_WIDTH     5
#define OLEDC_FONT_HEIGHT    8

void OLEDC_Initialize(void);
void OLEDC_setScale(uint8_t _sx, uint8_t _sy);
void OLEDC_setColor(uint16_t c);
void OLEDC_clearScreen(void);
void OLEDC_setBackground(uint16_t color);

void OLEDC_filled_circle(uint8_t center_x, uint8_t center_y, uint8_t radius);
void OLEDC_circle(uint8_t center_x, uint8_t center_y, uint8_t radius, uint8_t width);
void OLEDC_rectangle(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y);
void OLEDC_line(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y, uint8_t width);
void OLEDC_point(uint8_t x, uint8_t y);
void OLEDC_thickPoint(uint8_t center_x, uint8_t center_y, uint8_t width);
void OLEDC_putc(uint8_t x, uint8_t y, char ch);
void OLEDC_puts(uint8_t x, uint8_t y, char *string);
void OLEDC_drawBitmap(uint8_t x, uint8_t y, uint8_t *bit_array, uint8_t len);

#define  OLEDC_COLOR_ALICEBLUE          0xf7df    // converted from RGB(240,248,255)
#define  OLEDC_COLOR_ANTIQUEWHITE       0xff5a    // converted from RGB(250,235,215)
#define  OLEDC_COLOR_AQUA               0x7ff     // converted from RGB(0,255,255)
#define  OLEDC_COLOR_AQUAMARINE         0x7ffa    // converted from RGB(127,255,212)
#define  OLEDC_COLOR_AZURE              0xf7ff    // converted from RGB(240,255,255)
#define  OLEDC_COLOR_BEIGE              0xf7bb    // converted from RGB(245,245,220)
#define  OLEDC_COLOR_BISQUE             0xff38    // converted from RGB(255,228,196)
#define  OLEDC_COLOR_BLACK              0x0       // converted from RGB(0,0,0)
#define  OLEDC_COLOR_BLANCHEDALMOND     0xff59    // converted from RGB(255,235,205)
#define  OLEDC_COLOR_BLUE               0x1f      // converted from RGB(0,0,255)
#define  OLEDC_COLOR_BLUEVIOLET         0x895c    // converted from RGB(138,43,226)
#define  OLEDC_COLOR_BROWN              0xa145    // converted from RGB(165,42,42)
#define  OLEDC_COLOR_BURLYWOOD          0xddd0    // converted from RGB(222,184,135)
#define  OLEDC_COLOR_CADETBLUE          0x5cf4    // converted from RGB(95,158,160)
#define  OLEDC_COLOR_CHARTREUSE         0x7fe0    // converted from RGB(127,255,0)
#define  OLEDC_COLOR_CHOCOLATE          0xd343    // converted from RGB(210,105,30)
#define  OLEDC_COLOR_CORAL              0xfbea    // converted from RGB(255,127,80)
#define  OLEDC_COLOR_CORNFLOWERBLUE     0x64bd    // converted from RGB(100,149,237)
#define  OLEDC_COLOR_CORNSILK           0xffdb    // converted from RGB(255,248,220)
#define  OLEDC_COLOR_CRIMSON            0xd8a7    // converted from RGB(220,20,60)
#define  OLEDC_COLOR_CYAN               0x7ff     // converted from RGB(0,255,255)
#define  OLEDC_COLOR_DARKBLUE           0x11      // converted from RGB(0,0,139)
#define  OLEDC_COLOR_DARKCYAN           0x451     // converted from RGB(0,139,139)
#define  OLEDC_COLOR_DARKGOLDENROD      0xbc21    // converted from RGB(184,134,11)
#define  OLEDC_COLOR_DARKGRAY           0xad55    // converted from RGB(169,169,169)
#define  OLEDC_COLOR_DARKGREEN          0x320     // converted from RGB(0,100,0)
#define  OLEDC_COLOR_DARKGREY           0xad55    // converted from RGB(169,169,169)
#define  OLEDC_COLOR_DARKKHAKI          0xbdad    // converted from RGB(189,183,107)
#define  OLEDC_COLOR_DARKMAGENTA        0x8811    // converted from RGB(139,0,139)
#define  OLEDC_COLOR_DARKOLIVEGREEN     0x5345    // converted from RGB(85,107,47)
#define  OLEDC_COLOR_DARKORANGE         0xfc60    // converted from RGB(255,140,0)
#define  OLEDC_COLOR_DARKORCHID         0x9999    // converted from RGB(153,50,204)
#define  OLEDC_COLOR_DARKRED            0x8800    // converted from RGB(139,0,0)
#define  OLEDC_COLOR_DARKSALMON         0xecaf    // converted from RGB(233,150,122)
#define  OLEDC_COLOR_DARKSEAGREEN       0x8df1    // converted from RGB(143,188,143)
#define  OLEDC_COLOR_DARKSLATEBLUE      0x49f1    // converted from RGB(72,61,139)
#define  OLEDC_COLOR_DARKSLATEGRAY      0x2a69    // converted from RGB(47,79,79)
#define  OLEDC_COLOR_DARKSLATEGREY      0x2a69    // converted from RGB(47,79,79)
#define  OLEDC_COLOR_DARKTURQUOISE      0x67a     // converted from RGB(0,206,209)
#define  OLEDC_COLOR_DARKVIOLET         0x901a    // converted from RGB(148,0,211)
#define  OLEDC_COLOR_DEEPPINK           0xf8b2    // converted from RGB(255,20,147)
#define  OLEDC_COLOR_DEEPSKYBLUE        0x5ff     // converted from RGB(0,191,255)
#define  OLEDC_COLOR_DIMGRAY            0x6b4d    // converted from RGB(105,105,105)
#define  OLEDC_COLOR_DIMGREY            0x6b4d    // converted from RGB(105,105,105)
#define  OLEDC_COLOR_DODGERBLUE         0x1c9f    // converted from RGB(30,144,255)
#define  OLEDC_COLOR_FIREBRICK          0xb104    // converted from RGB(178,34,34)
#define  OLEDC_COLOR_FLORALWHITE        0xffde    // converted from RGB(255,250,240)
#define  OLEDC_COLOR_FORESTGREEN        0x2444    // converted from RGB(34,139,34)
#define  OLEDC_COLOR_FUCHSIA            0xf81f    // converted from RGB(255,0,255)
#define  OLEDC_COLOR_GAINSBORO          0xdefb    // converted from RGB(220,220,220)
#define  OLEDC_COLOR_GHOSTWHITE         0xffdf    // converted from RGB(248,248,255)
#define  OLEDC_COLOR_GOLD               0xfea0    // converted from RGB(255,215,0)
#define  OLEDC_COLOR_GOLDENROD          0xdd24    // converted from RGB(218,165,32)
#define  OLEDC_COLOR_GRAY               0x8410    // converted from RGB(128,128,128)
#define  OLEDC_COLOR_GREEN              0x400     // converted from RGB(0,128,0)
#define  OLEDC_COLOR_GREENYELLOW        0xafe5    // converted from RGB(173,255,47)
#define  OLEDC_COLOR_GREY               0x8410    // converted from RGB(128,128,128)
#define  OLEDC_COLOR_HONEYDEW           0xf7fe    // converted from RGB(240,255,240)
#define  OLEDC_COLOR_HOTPINK            0xfb56    // converted from RGB(255,105,180)
#define  OLEDC_COLOR_INDIANRED          0xcaeb    // converted from RGB(205,92,92)
#define  OLEDC_COLOR_INDIGO             0x4810    // converted from RGB(75,0,130)
#define  OLEDC_COLOR_IVORY              0xfffe    // converted from RGB(255,255,240)
#define  OLEDC_COLOR_KHAKI              0xf731    // converted from RGB(240,230,140)
#define  OLEDC_COLOR_LAVENDER           0xe73f    // converted from RGB(230,230,250)
#define  OLEDC_COLOR_LAVENDERBLUSH      0xff9e    // converted from RGB(255,240,245)
#define  OLEDC_COLOR_LAWNGREEN          0x7fe0    // converted from RGB(124,252,0)
#define  OLEDC_COLOR_LEMONCHIFFON       0xffd9    // converted from RGB(255,250,205)
#define  OLEDC_COLOR_LIGHTBLUE          0xaedc    // converted from RGB(173,216,230)
#define  OLEDC_COLOR_LIGHTCORAL         0xf410    // converted from RGB(240,128,128)
#define  OLEDC_COLOR_LIGHTCYAN          0xe7ff    // converted from RGB(224,255,255)
#define  OLEDC_COLOR_LIGHTGOLDENRODYELLOW 0xffda  // converted from RGB(250,250,210)
#define  OLEDC_COLOR_LIGHTGRAY          0xd69a    // converted from RGB(211,211,211)
#define  OLEDC_COLOR_LIGHTGREEN         0x9772    // converted from RGB(144,238,144)
#define  OLEDC_COLOR_LIGHTGREY          0xd69a    // converted from RGB(211,211,211)
#define  OLEDC_COLOR_LIGHTPINK          0xfdb8    // converted from RGB(255,182,193)
#define  OLEDC_COLOR_LIGHTSALMON        0xfd0f    // converted from RGB(255,160,122)
#define  OLEDC_COLOR_LIGHTSEAGREEN      0x2595    // converted from RGB(32,178,170)
#define  OLEDC_COLOR_LIGHTSKYBLUE       0x867f    // converted from RGB(135,206,250)
#define  OLEDC_COLOR_LIGHTSLATEGRAY     0x7453    // converted from RGB(119,136,153)
#define  OLEDC_COLOR_LIGHTSLATEGREY     0x7453    // converted from RGB(119,136,153)
#define  OLEDC_COLOR_LIGHTSTEELBLUE     0xb63b    // converted from RGB(176,196,222)
#define  OLEDC_COLOR_LIGHTYELLOW        0xfffc    // converted from RGB(255,255,224)
#define  OLEDC_COLOR_LIME               0x7e0     // converted from RGB(0,255,0)
#define  OLEDC_COLOR_LIMEGREEN          0x3666    // converted from RGB(50,205,50)
#define  OLEDC_COLOR_LINEN              0xff9c    // converted from RGB(250,240,230)
#define  OLEDC_COLOR_MAGENTA            0xf81f    // converted from RGB(255,0,255)
#define  OLEDC_COLOR_MAROON             0x8000    // converted from RGB(128,0,0)
#define  OLEDC_COLOR_MEDIUMAQUAMARINE   0x6675    // converted from RGB(102,205,170)
#define  OLEDC_COLOR_MEDIUMBLUE         0x19      // converted from RGB(0,0,205)
#define  OLEDC_COLOR_MEDIUMORCHID       0xbaba    // converted from RGB(186,85,211)
#define  OLEDC_COLOR_MEDIUMPURPLE       0x939b    // converted from RGB(147,112,219)
#define  OLEDC_COLOR_MEDIUMSEAGREEN     0x3d8e    // converted from RGB(60,179,113)
#define  OLEDC_COLOR_MEDIUMSLATEBLUE    0x7b5d    // converted from RGB(123,104,238)
#define  OLEDC_COLOR_MEDIUMSPRINGGREEN  0x7d3     // converted from RGB(0,250,154)
#define  OLEDC_COLOR_MEDIUMTURQUOISE    0x4e99    // converted from RGB(72,209,204)
#define  OLEDC_COLOR_MEDIUMVIOLETRED    0xc0b0    // converted from RGB(199,21,133)
#define  OLEDC_COLOR_MIDNIGHTBLUE       0x18ce    // converted from RGB(25,25,112)
#define  OLEDC_COLOR_MINTCREAM          0xf7ff    // converted from RGB(245,255,250)
#define  OLEDC_COLOR_MISTYROSE          0xff3c    // converted from RGB(255,228,225)
#define  OLEDC_COLOR_MOCCASIN           0xff36    // converted from RGB(255,228,181)
#define  OLEDC_COLOR_NAVAJOWHITE        0xfef5    // converted from RGB(255,222,173)
#define  OLEDC_COLOR_NAVY               0x10      // converted from RGB(0,0,128)
#define  OLEDC_COLOR_OLDLACE            0xffbc    // converted from RGB(253,245,230)
#define  OLEDC_COLOR_OLIVE              0x8400    // converted from RGB(128,128,0)
#define  OLEDC_COLOR_OLIVEDRAB          0x6c64    // converted from RGB(107,142,35)
#define  OLEDC_COLOR_ORANGE             0xfd20    // converted from RGB(255,165,0)
#define  OLEDC_COLOR_ORANGERED          0xfa20    // converted from RGB(255,69,0)
#define  OLEDC_COLOR_ORCHID             0xdb9a    // converted from RGB(218,112,214)
#define  OLEDC_COLOR_PALEGOLDENROD      0xef55    // converted from RGB(238,232,170)
#define  OLEDC_COLOR_PALEGREEN          0x9fd3    // converted from RGB(152,251,152)
#define  OLEDC_COLOR_PALETURQUOISE      0xaf7d    // converted from RGB(175,238,238)
#define  OLEDC_COLOR_PALEVIOLETRED      0xdb92    // converted from RGB(219,112,147)
#define  OLEDC_COLOR_PAPAYAWHIP         0xff7a    // converted from RGB(255,239,213)
#define  OLEDC_COLOR_PEACHPUFF          0xfed7    // converted from RGB(255,218,185)
#define  OLEDC_COLOR_PERU               0xcc27    // converted from RGB(205,133,63)
#define  OLEDC_COLOR_PINK               0xfe19    // converted from RGB(255,192,203)
#define  OLEDC_COLOR_PLUM               0xdd1b    // converted from RGB(221,160,221)
#define  OLEDC_COLOR_POWDERBLUE         0xb71c    // converted from RGB(176,224,230)
#define  OLEDC_COLOR_PURPLE             0x8010    // converted from RGB(128,0,128)
#define  OLEDC_COLOR_RED                0xf800    // converted from RGB(255,0,0)
#define  OLEDC_COLOR_ROSYBROWN          0xbc71    // converted from RGB(188,143,143)
#define  OLEDC_COLOR_ROYALBLUE          0x435c    // converted from RGB(65,105,225)
#define  OLEDC_COLOR_SADDLEBROWN        0x8a22    // converted from RGB(139,69,19)
#define  OLEDC_COLOR_SALMON             0xfc0e    // converted from RGB(250,128,114)
#define  OLEDC_COLOR_SANDYBROWN         0xf52c    // converted from RGB(244,164,96)
#define  OLEDC_COLOR_SEAGREEN           0x2c4a    // converted from RGB(46,139,87)
#define  OLEDC_COLOR_SEASHELL           0xffbd    // converted from RGB(255,245,238)
#define  OLEDC_COLOR_SIENNA             0xa285    // converted from RGB(160,82,45)
#define  OLEDC_COLOR_SILVER             0xc618    // converted from RGB(192,192,192)
#define  OLEDC_COLOR_SKYBLUE            0x867d    // converted from RGB(135,206,235)
#define  OLEDC_COLOR_SLATEBLUE          0x6ad9    // converted from RGB(106,90,205)
#define  OLEDC_COLOR_SLATEGRAY          0x7412    // converted from RGB(112,128,144)
#define  OLEDC_COLOR_SLATEGREY          0x7412    // converted from RGB(112,128,144)
#define  OLEDC_COLOR_SNOW               0xffdf    // converted from RGB(255,250,250)
#define  OLEDC_COLOR_SPRINGGREEN        0x7ef     // converted from RGB(0,255,127)
#define  OLEDC_COLOR_STEELBLUE          0x4416    // converted from RGB(70,130,180)
#define  OLEDC_COLOR_TAN                0xd5b1    // converted from RGB(210,180,140)
#define  OLEDC_COLOR_TEAL               0x410     // converted from RGB(0,128,128)
#define  OLEDC_COLOR_THISTLE            0xddfb    // converted from RGB(216,191,216)
#define  OLEDC_COLOR_TOMATO             0xfb08    // converted from RGB(255,99,71)
#define  OLEDC_COLOR_TURQUOISE          0x471a    // converted from RGB(64,224,208)
#define  OLEDC_COLOR_VIOLET             0xec1d    // converted from RGB(238,130,238)
#define  OLEDC_COLOR_WHEAT              0xf6f6    // converted from RGB(245,222,179)
#define  OLEDC_COLOR_WHITE              0xffff    // converted from RGB(255,255,255)
#define  OLEDC_COLOR_WHITESMOKE         0xf7be    // converted from RGB(245,245,245)
#define  OLEDC_COLOR_YELLOW             0xffe0    // converted from RGB(255,255,0)
#define  OLEDC_COLOR_YELLOWGREEN        0x9e66    // converted from RGB(154,205,50)

#endif	/* OLEDC_GRAPHICS_H */
