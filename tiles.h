#pragma once
#include <stdint.h>

// Game palette
const unsigned char Game_pal[12] = {
0x00,0x00,0x00, //Black
0xFF,0xFF,0xFF, //White
0x00,0x00,0xFF, //Blue
0xFF,0x00,0x00, //Red
};
//Total colors 3
const uint16_t Image20000_pal[] = {
65535,0,65504,
};

//Sprite sheet:6x6
const uint8_t Image20000 [][66] ={
//[0] cell:4x0: letter P
{
16,16,

0,0,0,0,
0,0,0,0,
5,85,84,0,
5,85,85,0,
5,0,1,80,
5,0,0,80,
5,0,0,80,
5,0,1,80,
5,85,85,0,
5,85,84,0,
5,0,0,0,
5,0,0,0,
5,0,0,0,
5,0,0,0,
0,0,0,0,
0,0,0,0,
},
//[1] cell:5x0: letter A
{
16,16,

0,0,0,0,
0,0,0,0,
0,85,84,0,
1,85,85,64,
5,0,0,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
5,85,85,80,
5,85,85,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
0,0,0,0,
0,0,0,0,
},

//[2] cell:4x1: letter C
{
16,16,

0,0,0,0,
0,0,0,0,
0,85,85,0,
1,85,85,64,
5,0,0,80,
5,0,0,16,
5,0,0,0,
5,0,0,0,
5,0,0,0,
5,0,0,0,
5,0,0,16,
5,0,0,80,
1,85,85,64,
0,85,85,0,
0,0,0,0,
0,0,0,0,
},
//[3] cell:5x1: letter M
{
16,16,

0,0,0,0,
0,0,0,0,
4,0,0,16,
5,0,0,80,
5,64,1,80,
5,80,5,80,
5,20,20,80,
5,5,80,80,
5,1,64,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
5,0,0,80,
0,0,0,0,
0,0,0,0,
},


//[4] cell:4x2: letter N
{
16,16,

0,0,0,0,
0,0,0,0,
4,0,0,80,
5,0,0,80,
5,64,0,80,
5,80,0,80,
5,20,0,80,
5,5,0,80,
5,1,64,80,
5,0,80,80,
5,0,20,80,
5,0,5,80,
5,0,1,80,
5,0,0,80,
0,0,0,0,
0,0,0,0,
},
};

//Total colors 2
const uint16_t letters_pal[] = {
0,65535,
};

//Sprite sheet:5x1
const uint8_t letters [][66] ={
//[0] cell:0x0
{
16,16,

85,85,85,85,
85,85,85,85,
80,0,1,85,
80,0,0,85,
80,85,84,5,
80,85,85,5,
80,85,85,5,
80,85,84,5,
80,0,0,85,
80,0,1,85,
80,85,85,85,
80,85,85,85,
80,85,85,85,
80,85,85,85,
85,85,85,85,
85,85,85,85,
},
//[1] cell:1x0
{
16,16,

85,85,85,85,
85,85,85,85,
85,0,1,85,
84,0,0,21,
80,85,85,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
80,0,0,5,
80,0,0,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
85,85,85,85,
85,85,85,85,
},
//[2] cell:2x0
{
16,16,

85,85,85,85,
85,85,85,85,
85,0,0,85,
84,0,0,21,
80,85,85,5,
80,85,85,69,
80,85,85,85,
80,85,85,85,
80,85,85,85,
80,85,85,85,
80,85,85,69,
80,85,85,5,
84,0,0,21,
85,0,0,85,
85,85,85,85,
85,85,85,85,
},
//[3] cell:3x0
{
16,16,

85,85,85,85,
85,85,85,85,
81,85,85,69,
80,85,85,5,
80,21,84,5,
80,5,80,5,
80,65,65,5,
80,80,5,5,
80,84,21,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
80,85,85,5,
85,85,85,85,
85,85,85,85,
},
//[4] cell:4x0
{
16,16,

85,85,85,85,
85,85,85,85,
81,85,85,5,
80,85,85,5,
80,21,85,5,
80,5,85,5,
80,65,85,5,
80,80,85,5,
80,84,21,5,
80,85,5,5,
80,85,65,5,
80,85,80,5,
80,85,84,5,
80,85,85,5,
85,85,85,85,
85,85,85,85,
},
};

//Total colors 4
/*const uint16_t ghost_blinky_pal[] = {
0,65535,63488,2016,
};*/

//Sprite sheet:4x4
const uint8_t ghost_blinky [][66] ={
//[0] cell:0x0
{
16,16,

255,255,255,255,
255,250,175,255,
255,170,170,255,
254,18,132,191,
254,18,132,191,
254,2,128,191,
250,2,128,175,
250,170,170,175,
234,170,170,171,
234,170,170,171,
234,160,10,171,
234,168,42,171,
234,234,171,171,
235,250,175,235,
235,250,175,235,
255,255,255,255,
},
//[1] cell:1x0
{
16,16,

255,255,255,255,
255,250,175,255,
255,170,170,255,
254,18,132,191,
254,18,132,191,
254,2,128,191,
250,2,128,175,
250,170,170,175,
234,170,170,175,
234,170,170,175,
234,160,10,171,
250,168,42,171,
250,170,171,171,
254,174,175,235,
254,191,175,235,
255,255,255,255,
},
//[2] cell:2x0
{
16,16,

255,255,255,255,
255,250,175,255,
255,170,170,255,
254,18,132,191,
254,18,132,191,
254,2,128,191,
250,2,128,175,
250,170,170,175,
234,170,170,171,
234,170,170,171,
234,160,10,171,
234,168,42,171,
234,234,171,171,
235,250,175,235,
235,250,175,235,
255,255,255,255,
},
//[3] cell:3x0
{
16,16,

255,255,255,255,
255,250,175,255,
255,170,170,255,
254,18,132,191,
254,18,132,191,
254,2,128,191,
250,2,128,175,
250,170,170,175,
250,170,170,171,
250,170,170,171,
234,160,10,171,
234,168,42,175,
234,234,170,175,
235,250,186,191,
235,250,254,191,
255,255,255,255,
},
};

//Total colors 4
const uint16_t ghost_blinky_pal[] = {
2016,63488,0,65535,
};
const uint16_t ghost_inky_pal[] = {
2016,2047,0,65535,
};
const uint16_t ghost_clyde_pal[] = {
2016,64512,0,65535,
};
const uint16_t ghost_pinky_pal[] = {
2016,64536,0,65535,
};
const uint16_t ghost_inv_pal[] = {
2016,31,65535,0,
};
const uint16_t ghost_inv2_pal[] = {
2016,65535,65535,0,
};


//Sprite sheet:4x1
const uint8_t ghost [][66] ={
//[0] cell:0x0
{
16,16,

0,0,0,0,
0,5,80,0,
0,85,85,0,
1,185,110,64,
1,185,110,64,
1,169,106,64,
5,169,106,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,90,165,84,
21,86,149,84,
21,21,84,84,
20,5,80,20,
20,5,80,20,
0,0,0,0,
},
//[1] cell:1x0
{
16,16,

0,0,0,0,
0,5,80,0,
0,85,85,0,
1,185,110,64,
1,185,110,64,
1,169,106,64,
5,169,106,80,
5,85,85,80,
21,85,85,80,
21,85,85,80,
21,90,165,84,
5,86,149,84,
5,85,84,84,
1,81,80,20,
1,64,80,20,
0,0,0,0,
},
//[2] cell:2x0
{
16,16,

0,0,0,0,
0,5,80,0,
0,85,85,0,
1,185,110,64,
1,185,110,64,
1,169,106,64,
5,169,106,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,90,165,84,
21,86,149,84,
21,21,84,84,
20,5,80,20,
20,5,80,20,
0,0,0,0,
},
//[3] cell:3x0
{
16,16,

0,0,0,0,
0,5,80,0,
0,85,85,0,
1,185,110,64,
1,185,110,64,
1,169,106,64,
5,169,106,80,
5,85,85,80,
5,85,85,84,
5,85,85,84,
21,90,165,84,
21,86,149,80,
21,21,85,80,
20,5,69,64,
20,5,1,64,
0,0,0,0,
},
};

const uint8_t ghost_small[][18] ={
{
8,8,

0,0,
5,80,
25,100,
25,100,
21,84,
21,84,
20,20,
0,0,

},

{
8,8,

0,0,
5,80,
25,100,
25,100,
21,84,
21,84,
20,20,
0,0,

},

{
8,8,

0,0,
5,80,
25,100,
25,100,
21,84,
21,84,
20,20,
0,0,

},

{
8,8,

0,0,
5,80,
25,100,
25,100,
21,84,
21,84,
20,20,
0,0,

},
};


//Total colors 2
const uint16_t pacman_pal[] = {
2016,65504,
};

//Sprite sheet:4x4
const uint8_t pacman_sprite [][66] ={
//[0] cell:0x0
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[1] cell:1x0
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,0,
21,85,80,0,
21,85,0,0,
21,85,0,0,
21,85,80,0,
21,85,85,0,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[2] cell:2x0
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,0,
5,85,84,0,
21,85,80,0,
21,85,64,0,
21,85,0,0,
21,85,0,0,
21,85,64,0,
21,85,80,0,
5,85,84,0,
5,85,85,0,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[3] cell:3x0
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,0,
21,85,80,0,
21,85,0,0,
21,85,0,0,
21,85,80,0,
21,85,85,0,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[4] cell:0x1
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[5] cell:1x1
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
0,85,85,84,
0,5,85,84,
0,0,85,84,
0,0,85,84,
0,5,85,84,
0,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[6] cell:2x1
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
0,85,85,80,
0,21,85,80,
0,5,85,84,
0,1,85,84,
0,0,85,84,
0,0,85,84,
0,1,85,84,
0,5,85,84,
0,21,85,80,
0,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[7] cell:3x1
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
0,85,85,84,
0,5,85,84,
0,0,85,84,
0,0,85,84,
0,5,85,84,
0,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[8] cell:0x2
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[9] cell:1x2
{
16,16,

0,0,0,0,
0,0,0,0,
1,64,1,64,
5,64,1,80,
5,80,5,80,
21,80,5,84,
21,84,21,84,
21,84,21,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[10] cell:2x2
{
16,16,

0,0,0,0,
0,0,0,0,
0,0,0,0,
4,0,0,16,
5,0,0,80,
21,64,1,84,
21,80,5,84,
21,84,21,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[11] cell:3x2
{
16,16,

0,0,0,0,
0,0,0,0,
1,64,1,64,
5,64,1,80,
5,80,5,80,
21,80,5,84,
21,84,21,84,
21,84,21,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[12] cell:0x3
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,85,85,84,
5,85,85,80,
5,85,85,80,
1,85,85,64,
0,21,84,0,
0,0,0,0,
},
//[13] cell:1x3
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,84,21,84,
21,84,21,84,
21,80,5,84,
5,80,5,80,
5,64,1,80,
1,64,1,64,
0,0,0,0,
0,0,0,0,
},
//[14] cell:2x3
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,84,21,84,
21,80,5,84,
21,64,1,84,
5,0,0,80,
4,0,0,16,
0,0,0,0,
0,0,0,0,
0,0,0,0,
},
//[15] cell:3x3
{
16,16,

0,0,0,0,
0,21,84,0,
1,85,85,64,
5,85,85,80,
5,85,85,80,
21,85,85,84,
21,85,85,84,
21,85,85,84,
21,84,21,84,
21,84,21,84,
21,80,5,84,
5,80,5,80,
5,64,1,80,
1,64,1,64,
0,0,0,0,
0,0,0,0,
},
};

const uint8_t pacman_small [][18] ={
//[0] cell:0x0
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[1] cell:1x0
{
8,8,

5,80,
21,84,
85,85,
85,80,
85,80,
85,85,
21,84,
5,80,
},
//[2] cell:2x0
{
8,8,

5,80,
21,84,
85,80,
85,64,
85,64,
85,80,
21,84,
5,80,
},
//[3] cell:3x0
{
8,8,

5,80,
21,84,
85,85,
85,80,
85,80,
85,85,
21,84,
5,80,
},
//[4] cell:0x1
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[5] cell:1x1
{
8,8,

5,80,
21,84,
85,85,
5,85,
5,85,
85,85,
21,84,
5,80,
},
//[6] cell:2x1
{
8,8,

5,80,
21,84,
5,85,
1,85,
1,85,
5,85,
21,84,
5,80,
},
//[7] cell:3x1
{
8,8,

5,80,
21,84,
85,85,
5,85,
5,85,
85,85,
21,84,
5,80,
},
//[8] cell:0x2
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[9] cell:1x2
{
8,8,

4,16,
20,20,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[10] cell:2x2
{
8,8,

0,0,
16,4,
84,21,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[11] cell:3x2
{
8,8,

4,16,
20,20,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[12] cell:0x3
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
21,84,
5,80,
},
//[13] cell:1x3
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
20,20,
4,16,
},
//[14] cell:2x3
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
84,21,
16,4,
0,0,
},
//[15] cell:3x3
{
8,8,

5,80,
21,84,
85,85,
85,85,
85,85,
85,85,
20,20,
4,16,
},
};

const uint8_t pacman_small2 [][18] ={
//[0] cell:0x0
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[1] cell:1x0
{
8,8,

0,0,
5,80,
21,84,
21,80,
21,80,
21,84,
5,80,
0,0,
},
//[2] cell:2x0
{
8,8,

0,0,
5,84,
21,80,
21,64,
21,64,
21,80,
5,84,
0,0,
},
//[3] cell:3x0
{
8,8,

0,0,
5,80,
21,84,
21,80,
21,80,
21,84,
5,80,
0,0,
},
//[4] cell:0x1
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[5] cell:1x1
{
8,8,

0,0,
5,80,
21,84,
5,84,
5,84,
21,84,
5,80,
0,0,
},
//[6] cell:2x1
{
8,8,

0,0,
21,80,
5,84,
1,84,
1,84,
5,84,
21,80,
0,0,
},
//[7] cell:3x1
{
8,8,

0,0,
5,80,
21,84,
5,84,
5,84,
21,84,
5,80,
0,0,
},
//[8] cell:0x2
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[9] cell:1x2
{
8,8,

0,0,
4,16,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[10] cell:2x2
{
8,8,

0,0,
16,4,
20,20,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[11] cell:3x2
{
8,8,

0,0,
4,16,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[12] cell:0x3
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
5,80,
0,0,
},
//[13] cell:1x3
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
4,16,
0,0,
},
//[14] cell:2x3
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
20,20,
16,4,
0,0,
},
//[15] cell:3x3
{
8,8,

0,0,
5,80,
21,84,
21,84,
21,84,
21,84,
4,16,
0,0,
},
};

enum class Tile
{
	Empty = 0,
	Wall = 1,
	Pill = 2,
	PowerPill = 3,
};
Tile mazeData[21*21] {
Tile::Empty, Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::PowerPill, Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::PowerPill, Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Empty,
Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,
Tile::Empty, Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Empty, Tile::Pill, Tile::Empty, Tile::Empty, Tile::Wall,  Tile::Empty, Tile::Empty, Tile::Empty, Tile::Wall,  Tile::Empty, Tile::Empty, Tile::Pill, Tile::Empty, Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Empty,
Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,
Tile::Empty, Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Empty,     Tile::Empty, Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Empty, Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::PowerPill, Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::PowerPill, Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Wall,      Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::Wall,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Wall,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Pill,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Pill,      Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill,  Tile::Pill, Tile::Pill,  Tile::Pill,  Tile::Pill,      Tile::Wall,  Tile::Empty,
Tile::Empty, Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall,  Tile::Wall, Tile::Wall,  Tile::Wall,  Tile::Wall,      Tile::Wall,  Tile::Empty};


int mazeo[21*21] {
0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,0,
0,1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1,0,
0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
0,1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1,0,
0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1,0,
0,1,1,1,1,2,1,1,1,0,1,0,1,1,1,2,1,1,1,1,0,
0,0,0,0,1,2,1,0,0,0,0,0,0,0,1,2,1,0,0,0,0,
1,1,1,1,1,2,1,0,1,1,0,1,1,0,1,2,1,1,1,1,1,
0,0,0,0,0,2,0,0,1,0,0,0,1,0,0,2,0,0,0,0,0,
1,1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1,1,
0,0,0,0,1,2,1,0,0,0,0,0,0,0,1,2,1,0,0,0,0,
0,1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1,0,
0,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,0,
0,1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1,0,
0,1,3,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,3,1,0,
0,1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1,0,
0,1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1,0,
0,1,2,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,2,1,0,
0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

