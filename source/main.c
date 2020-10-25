#include "Intellisense.h"
#include <stdint.h>
#include <stdbool.h>

#define REG_DISPLAYCONTROL *((v_uint32*)(0x04000000))
#define VIDEOMODE_3 0x0003
#define BGMODE_2	0x0400

#define SCREENBUFFER ((v_int16*)(0x06000000))
#define SCREEN_W 240
#define SCREEN_H 160

typedef uint8_t		uint8;
typedef uint16_t	uint16;
typedef uint32_t	uint32;
typedef int8_t		int8;
typedef int16_t		int16;
typedef int32_t		int32;

typedef volatile uint8_t		v_uint8;
typedef volatile uint16_t		v_uint16;
typedef volatile uint32_t		v_uint32;
typedef volatile int8_t			v_int8;
typedef volatile int16_t		v_int16;
typedef volatile int32_t		v_int32;


int main()
{
	//set GBA rendering context to MODE 3 Bitmap Rendering
	REG_DISPLAYCONTROL = VIDEOMODE_3 | BGMODE_2;

	int t = 0;
	while(1){
		int x,y;
		for(x = 0; x < 240; ++x){
			for( y = 0; y < 160; ++y){
				SCREENBUFFER[x+y*SCREEN_W] = ((((x&y)+t) & 0X1F) << 10)|
				((((x&y)+t*3)&0x1F)<<5) | ((((x&y)+t * 5)&0x1F)<<0);
			}
		}
		++t;
	}
	return 0;
}