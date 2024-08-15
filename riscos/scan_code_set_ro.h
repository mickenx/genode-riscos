/*
 * \brief  Mapping from PS/2 Scan-Code Set 1 to unique key codes
 * \author Norman Feske
 * \date   2007-09-29
 */

/*
 * Copyright (C) 2007-2017 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _SCAN_CODE_SET_1_H_
#define _SCAN_CODE_SET_1_H_

#include <input/keycodes.h>

enum { SCAN_CODE_SET_1_NUM_KEYS = 128 };

static uint32_t scan_code_set_ro[SCAN_CODE_SET_1_NUM_KEYS][2] = {
	/*  0 */{ Input::KEY_RESERVED,1000}     ,
	/*  1 */{ Input::KEY_ESC    ,0}      ,
	/*  2 */{ Input::KEY_1      ,17}      ,
	/*  3 */{ Input::KEY_2      ,18}      ,
	/*  4 */{ Input::KEY_3      ,19}      ,
	/*  5 */{ Input::KEY_4      ,20}      ,
	/*  6 */{ Input::KEY_5      ,21}      ,
	/*  7 */{ Input::KEY_6      ,22}      ,
	/*  8 */{ Input::KEY_7      ,23}      ,
	/*  9 */{ Input::KEY_8      ,24}      ,
	/*  a */{ Input::KEY_9      ,25}      ,
	/*  b */{ Input::KEY_0      ,26}      ,
	/*  c */{ Input::KEY_MINUS  ,27}      ,
	/*  d */{ Input::KEY_EQUAL  ,28}      ,
	/*  e */{ Input::KEY_BACKSPACE,30}    ,
	/*  f */{ Input::KEY_TAB    ,38}      ,
	/* 10 */{ Input::KEY_Q      ,39}      ,
	/* 11 */{ Input::KEY_W      ,40}      ,
	/* 12 */{ Input::KEY_E      ,41}      ,
	/* 13 */{ Input::KEY_R      ,42}      ,
	/* 14 */{ Input::KEY_T      ,43}      ,
	/* 15 */{ Input::KEY_Y      ,44}      ,
	/* 16 */{ Input::KEY_U      ,45}      ,
	/* 17 */{ Input::KEY_I      ,46}      ,
	/* 18 */{ Input::KEY_O      ,47}      ,
	/* 19 */{ Input::KEY_P      ,48}      ,
	/* 1a */{ Input::KEY_LEFTBRACE,49}    ,
	/* 1b */{ Input::KEY_RIGHTBRACE,50}   ,
	/* 1c */{ Input::KEY_ENTER  ,71}      ,
	/* 1d */{ Input::KEY_LEFTCTRL,59}     ,
	/* 1e */{ Input::KEY_A      ,60}      ,
	/* 1f */{ Input::KEY_S      ,61}      ,
	/* 20 */{ Input::KEY_D      ,62}      ,
	/* 21 */{ Input::KEY_F      ,63}      ,
	/* 22 */{ Input::KEY_G      ,64}      ,
	/* 23 */{ Input::KEY_H      ,65}      ,
	/* 24 */{ Input::KEY_J      ,66}      ,
	/* 25 */{ Input::KEY_K      ,67}      ,
	/* 26 */{ Input::KEY_L      ,68}      ,
	/* 27 */{ Input::KEY_SEMICOLON,69}   ,
	/* 28 */{ Input::KEY_APOSTROPHE,70}   ,
	/* 29 */{ Input::KEY_GRAVE  ,16}      ,
	/* 2a */{ Input::KEY_LEFTSHIFT,76}   ,
	/* 2b */{ Input::KEY_BACKSLASH,51}   ,
	/* 2c */{ Input::KEY_Z      ,78}      ,
	/* 2d */{ Input::KEY_X      ,79}      ,
	/* 2e */{ Input::KEY_C      ,80}      ,
	/* 2f */{ Input::KEY_V      ,81}      ,
	/* 30 */{ Input::KEY_B      ,82}      ,
	/* 31 */{ Input::KEY_N      ,83}      ,
	/* 32 */{ Input::KEY_M      ,84}      ,
	/* 33 */{ Input::KEY_COMMA  ,85}      ,
	/* 34 */{ Input::KEY_DOT    ,86}      ,
	/* 35 */{ Input::KEY_SLASH  ,87}      ,
	/* 36 */{ Input::KEY_RIGHTSHIFT,88}   ,
	/* 37 */{ Input::KEY_KPASTERISK,1000}   ,
	/* 38 */{ Input::KEY_LEFTALT,94}      ,
	/* 39 */{ Input::KEY_SPACE  ,95}      ,
	/* 3a */{ Input::KEY_CAPSLOCK,93}     ,
	/* 3b */{ Input::KEY_F1     ,1}      ,
	/* 3c */{ Input::KEY_F2     ,2}      ,
	/* 3d */{ Input::KEY_F3     ,3}      ,
	/* 3e */{ Input::KEY_F4     ,4}      ,
	/* 3f */{ Input::KEY_F5     ,5}      ,
	/* 40 */{ Input::KEY_F6     ,6}      ,
	/* 41 */{ Input::KEY_F7     ,7}      ,
	/* 42 */{ Input::KEY_F8     ,8}      ,
	/* 43 */{ Input::KEY_F9     ,9}      ,
	/* 44 */{ Input::KEY_F10    ,10}      ,
	/* 45 */{ Input::KEY_NUMLOCK,34}     ,
	/* 46 */{ Input::KEY_SCROLLLOCK,14}   ,
	/* 47 */{ Input::KEY_KP7    ,55}      ,
	/* 48 */{ Input::KEY_KP8    ,56}      ,
	/* 49 */{ Input::KEY_KP9    ,57}      ,
	/* 4a */{ Input::KEY_KPMINUS,58}      ,
	/* 4b */{ Input::KEY_KP4    ,72}      ,
	/* 4c */{ Input::KEY_KP5    ,73}      ,
	/* 4d */{ Input::KEY_KP6    ,74}      ,
	/* 4e */{ Input::KEY_KPPLUS ,75}      ,
	/* 4f */{ Input::KEY_KP1    ,90}      ,
	/* 50 */{ Input::KEY_KP2    ,91}      ,
	/* 51 */{ Input::KEY_KP3    ,92}      ,
	/* 52 */{ Input::KEY_KP0    ,101}      ,
	/* 53 */{ Input::KEY_KPDOT  ,102}      ,
	/* 54 */{ Input::KEY_SYSRQ   ,1000}      ,
	/* 55 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 56 */{ Input::KEY_102ND  ,1000}      ,
	/* 57 */{ Input::KEY_F11    ,11}      ,
	/* 58 */{ Input::KEY_F12    ,12}      ,
	/* 59 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5a */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5b */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5c */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5d */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5e */{ Input::KEY_UNKNOWN,1000}      ,
	/* 5f */{ Input::KEY_UNKNOWN,1000}      ,
	/* 60 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 61 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 62 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 63 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 64 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 65 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 66 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 67 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 68 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 69 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6a */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6b */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6c */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6d */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6e */{ Input::KEY_UNKNOWN,1000}      ,
	/* 6f */{ Input::KEY_SCREENLOCK,1000}   ,
	/* 70 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 71 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 72 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 73 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 74 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 75 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 76 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 77 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 78 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 79 */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7a */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7b */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7c */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7d */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7e */{ Input::KEY_UNKNOWN,1000}      ,
	/* 7f */{ Input::KEY_UNKNOWN,1000}      ,
};


/**
 * Scan-code table for keys with a prefix of 0xe0
 */
//static unsigned short scan_code_set_1_0xe0[SCAN_CODE_SET_1_NUM_KEYS];


/**
 * Init scan_code_set_1_0xe0 table
*/
#if 0
inline void init_scan_code_set_1_0xe0()
{
	for (int i = 0; i < SCAN_CODE_SET_1_NUM_KEYS; i++)
		scan_code_set_1_0xe0[i] = Input::KEY_UNKNOWN;

	scan_code_set_1_0xe0[0x1c] = Input::KEY_KPENTER;
	scan_code_set_1_0xe0[0x1d] = Input::KEY_RIGHTCTRL;
	scan_code_set_1_0xe0[0x20] = Input::KEY_MUTE;
	scan_code_set_1_0xe0[0x2e] = Input::KEY_VOLUMEDOWN;
	scan_code_set_1_0xe0[0x30] = Input::KEY_VOLUMEUP;
	scan_code_set_1_0xe0[0x35] = Input::KEY_KPSLASH;
	scan_code_set_1_0xe0[0x37] = Input::KEY_PRINT;
	scan_code_set_1_0xe0[0x38] = Input::KEY_RIGHTALT;
	scan_code_set_1_0xe0[0x46] = Input::KEY_PAUSE;     /* emitted if CTRL is pressed too */
	scan_code_set_1_0xe0[0x47] = Input::KEY_HOME;
	scan_code_set_1_0xe0[0x48] = Input::KEY_UP;
	scan_code_set_1_0xe0[0x49] = Input::KEY_PAGEUP;
	scan_code_set_1_0xe0[0x4b] = Input::KEY_LEFT;
	scan_code_set_1_0xe0[0x4d] = Input::KEY_RIGHT;
	scan_code_set_1_0xe0[0x4f] = Input::KEY_END;
	scan_code_set_1_0xe0[0x50] = Input::KEY_DOWN;
	scan_code_set_1_0xe0[0x51] = Input::KEY_PAGEDOWN;
	scan_code_set_1_0xe0[0x52] = Input::KEY_INSERT;
	scan_code_set_1_0xe0[0x53] = Input::KEY_DELETE;
	scan_code_set_1_0xe0[0x5b] = Input::KEY_LEFTMETA;
	scan_code_set_1_0xe0[0x5c] = Input::KEY_RIGHTMETA;
	scan_code_set_1_0xe0[0x5d] = Input::KEY_COMPOSE;
	scan_code_set_1_0xe0[0x5e] = Input::KEY_POWER;
	scan_code_set_1_0xe0[0x5f] = Input::KEY_SLEEP;
	scan_code_set_1_0xe0[0x63] = Input::KEY_WAKEUP;
}
#endif
#endif /* _SCAN_CODE_SET_1_H_ */
