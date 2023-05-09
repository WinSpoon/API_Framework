#pragma once


extern HWND g_hWnd;

const int COUNT = 128;



#define WIDTH 1500
#define HEIGHT 900

const unsigned char KEYID_UP = 0x00000001;
const unsigned char KEYID_DOWN = 0x00000002;
const unsigned char KEYID_LEFT = 0x00000004;
const unsigned char KEYID_RIGHT = 0x00000008;
const unsigned char KEYID_RETURN = 0x00000010;
const unsigned char KEYID_SPACE = 0x00000020;
const unsigned char KEYID_ESCAPE = 0x00000040;
const unsigned char KEYID_CONTROL = 0x00000080;


const unsigned char STATEID_HIT = 0x00000001;
const unsigned char STATEID_ATTACK = 0x00000002;
const unsigned char STATEID_JUMP = 0x00000004;

