/**************************************************************************/
/*!
    @file     My_settings.h
    @author   XX

    @section HOW TO USE My_settings

   My_settings can be used to set project settings inside the mbed online IDE
*/
/**************************************************************************/

#ifndef MY_SETTINGS_H
#define MY_SETTINGS_H

#define PROJ_HIRES 1           //1 = high resolution (220x176) , 0 = low resolution fast mode (110x88)
#define PROJ_ENABLE_SOUND       0       // 0 = all sound functions disabled
#define PROJ_STREAMING_MUSIC    0       // 1 = enable streaming music from SD card
//#define PROJ_AUD_FREQ           11025
//#define PROJ_STREAM_TO_DAC      1       // 1 use DAC for stream, 0 = use PWM for stream
//#define PROJ_GBSOUND            0       // 1 = use Gamebuino-compatible sound interrupt
//#define PROJ_ENABLE_SYNTH       0       // 1 = use Rboy-compatible sound interrupt
//#define PROJ_USE_PWM            0       // 0 = Use only DAC for output
#define DISABLEAVRMIN

#define SPRITE_COUNT 12          // The default max sprite count
#define PROJ_SHOW_FPS_COUNTER    // Draw FPS counter on screen


#endif
