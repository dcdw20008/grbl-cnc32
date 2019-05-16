#include "TFT_eSPI_ms/TFT_eSPI.cpp" // setup file has to be edited for some parameters like screen device, pins

#include "config.h"
#include "widget.hpp"
#include "evt-ctrl.hpp"
#include "wifi-ctrl.hpp"
#include "storage-ctrl.hpp"
#include "grbl-ctrl.hpp"

void setup()
{
    // screen controller
    log_i("TFT_Screen init ...");
    TFT_Screen::instance()->init();

    // event controller
    log_i("EvtCtrl init ...");
    EvtCtrl::instance()->init();

    // storage controller
    log_i("StorageCtrl init ...");
    StorageCtrl::instance()->init();

    // wifi controller
    log_i("WifiCtrl init ...");
    WifiCtrl::instance()->init();

    // grbl controller
    log_i("GrblCtrl init ...");
    GrblCtrl::instance()->init();
}

void loop()
{
    // capture events
    EvtCtrl::instance()->capture();
    // capture http request
    WifiCtrl::instance()->serve();
    // flush grbl events
    GrblCtrl::instance()->capture();
    // notify, then render screen if invalidate state
    if (TFT_Screen::instance()->isInvalidated())
    {
        TFT_Screen::instance()->render();
    }
    // flush events
    EvtCtrl::instance()->flush();
}
