#ifndef _WIDGET_TFT_
#define _WIDGET_TFT_

#include "stdio.h"
#include "config.h"
#include "TFT_eSPI_ms/TFT_eSPI.h"
#include "language.h"
#include "evt-ctrl.hpp"

class TFT_Widget
{
public:
  TFT_Widget();
  virtual void notify(const Event *event);
  virtual void render();
  virtual void draw();
  virtual void show();
  virtual void hide();
  virtual void setPosition(int16_t _x, int16_t _y);
  virtual void setInvalidated(bool _active);
  virtual void setBackground(int16_t back)
  {
    this->background = back;
  }
  virtual void setLabel(const char *_label, ...);
  virtual const char *getLabel()
  {
    return this->label;
  }
  // Registry manipulation
  virtual TFT_Widget *findById(int16_t _id);
  TFT_Widget *add(TFT_Widget *widget);

protected:
  void init(int16_t _id, int16_t _x, int16_t _y, int16_t _w, int16_t _h);
  int16_t x;
  int16_t y;
  int16_t w;
  int16_t h;
  int16_t id;
  int16_t background = TFT_BLACK;
  char name[32];
  char label[128];
  bool visible = false;
  bool invalidated = true;
  // child
  TFT_Widget *children[32];
  int8_t child = 0;
  TFT_eSPI *tft;
};

class TFT_Layer : public TFT_Widget
{
public:
  TFT_Layer(int16_t _id, int16_t _x, int16_t _y, int16_t _w, int16_t _h);

private:
};

enum ButtonState
{
  on,
  off
};

class TFT_Button : public TFT_Widget
{
public:
  TFT_Button(int16_t _id, const char *_label, int16_t _x, int16_t _y);
  virtual void notify(const Event *event);
  virtual void draw();

protected:
  ButtonState state = off;
};

class TFT_File : public TFT_Button
{
public:
  TFT_File(int16_t _id, const char *_label, int16_t _x, int16_t _y);
  virtual void draw();

private:
};

class TFT_Joystick : public TFT_Widget
{
public:
  TFT_Joystick(int16_t _id, const char *_label, int16_t _x, int16_t _y, int16_t _w, int16_t _h);

private:
  TFT_Button *xleft;
  TFT_Button *xright;
  TFT_Button *yup;
  TFT_Button *ydown;
  TFT_Button *zup;
  TFT_Button *zdown;
  TFT_Button *pas;
};

class TFT_Group : public TFT_Widget
{
public:
  TFT_Group(int16_t _id, const char *_label, int16_t _x, int16_t _y, int16_t _w, int16_t _h);

private:
};

class TFT_Label : public TFT_Widget
{
public:
  TFT_Label(int16_t _id, const char *_label, int16_t _x, int16_t _y);
  virtual void draw();

private:
};

class TFT_Console : public TFT_Widget
{
public:
  TFT_Console(int16_t _id, const char *_label, int16_t _sz, int16_t _x, int16_t _y, int16_t _w, int16_t _h);
  void write(const char *message);

private:
  TFT_Label *lines[16];
  int16_t sz;
};

class TFT_FileGrid : public TFT_Widget
{
public:
  TFT_FileGrid(int16_t _id, const char *_label, int16_t _x, int16_t _y, int16_t _w, int16_t _h);
  virtual void notify(const Event *event);

  virtual void onRight()
  {
    this->offset++;
    if (this->offset > this->count)
    {
      this->offset = this->count - 1;
    }
    this->refresh();
  }
  virtual void onLeft()
  {
    this->offset--;
    if (this->offset < 0)
    {
      this->offset = 0;
    }
    this->refresh();
  }

  void clear();
  void set(int16_t index, const char *label);
  virtual void refresh() {}

public:
  int16_t offset = 0;
  int16_t count = 0;

private:
  TFT_Button *left;
  TFT_File *lines[4];
  TFT_Button *right;
};

#endif
