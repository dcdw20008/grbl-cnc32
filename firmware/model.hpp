#ifndef _MODEL_
#define _MODEL_

enum EventType
{
  TOUCH_SCREEN,
  LONG_TOUCH_SCREEN,
  RELEASE_SCREEN,
  BUTTON_DOWN,
  EVENT_DLG_OK,
  EVENT_DLG_CANCEL,
  NEXT_FILE,
  PREV_FILE,
  SELECT_FILE,
  grblProperty,
  GRID_CHANGE,
  FILE_SELECTED,
  SWITCH_SELECTED,
  EVENT_GRBL_STATE_METRIC,
  EVENT_GRBL_STATE_ABS,
  EVENT_GRBL_STATUS,
  EVENT_SETX,
  EVENT_SETY,
  EVENT_SETZ,
  EVENT_SETXYZ,
  EVENT_NEXT_STEP,
  EVENT_NEW_STEP,
  EVENT_WPOS,
  EVENT_MPOS,
  EVENT_ERROR,
  EVENT_BTN_MOVE,
  EVENT_BTN_STAT,
  EVENT_BTN_FILES,
  EVENT_BTN_ADM,
  EVENT_BTN_CMD,
  NUNCHUK_Z,
  NUNCHUK_C,
  NUNCHUK_DATA,
  JOG_MOVEXY,
  JOG_MOVEZ,
  JOG_STOP
};

enum EventGrbl
{
  XP,
  XM,
  YP,
  YM,
  ZP,
  ZM,
  SETX,
  SETY,
  SETZ,
  SETXYZ
};

class Event
{
public:
  EventType type;
  int16_t timestamp;
  int16_t sender;
  int16_t target;
  union {
    struct
    {
      int16_t x, y;
    } touch;
    struct
    {
      float f1, f2, f3;
    } fvalue;
    int ivalue;
    boolean bvalue;
    char message[32];
  };
};

#define WIDGET_ID_DEFAULT 0x00000
#define WIDGET_ID_GRBL 0x08000

#define WIDGET_ID_SCREEN 0x00001
#define WIDGET_ID_LAYER_MENU 0x01001
#define WIDGET_ID_LAYER_MENU_FOOTER 0x01011
#define WIDGET_ID_LAYER_MENU_GRBL_STATUS 0x01020

#define WIDGET_ID_LAYER_CTRL 0x02001
// Warning joystick take many IDs
#define WIDGET_ID_LAYER_CTRL_JOYSTICK 0x02002
#define WIDGET_ID_LAYER_CTRL_SETX 0x02020
#define WIDGET_ID_LAYER_CTRL_SETY 0x02021
#define WIDGET_ID_LAYER_CTRL_SETZ 0x02022
#define WIDGET_ID_LAYER_CTRL_SETALL 0x02023
#define WIDGET_ID_LAYER_CTRL_HOME 0x02024

#define WIDGET_ID_LAYER_ADM 0x03001
#define WIDGET_ID_LAYER_ADM_UNLOCK 0x03021
#define WIDGET_ID_LAYER_ADM_RESET 0x03022
#define WIDGET_ID_LAYER_ADM_RESUME 0x03023
#define WIDGET_ID_LAYER_ADM_PAUSE 0x03024
#define WIDGET_ID_LAYER_ADM_STATUS 0x03025

#define WIDGET_ID_LAYER_STAT 0x04001
#define WIDGET_ID_LAYER_STAT_GRBL_STATUS 0x04011
#define WIDGET_ID_LAYER_STAT_GRBL_IO 0x04012

#define WIDGET_ID_LAYER_FILE 0x05001
#define WIDGET_ID_LAYER_FILE_LIST 0x05011
#define WIDGET_ID_LAYER_CWF 0x05034

#define WIDGET_ID_DIALOG_OK 0x05015
#define WIDGET_ID_DIALOG_CANCEL 0x05036

#endif