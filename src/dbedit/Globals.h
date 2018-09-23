#ifndef TRINITY_DBEDIT_GLOBALS_H
#define TRINITY_DBEDIT_GLOBALS_H

#include "IoContext.h"
#include "MainWindow.h"
#include <memory>

struct Globals
{
    static Globals const& instance() { return _instance(); }
    std::shared_ptr<Trinity::Asio::IoContext> IoCtx;
    std::unique_ptr<::MainWindow> MainWindow;
        
    private:
        static Globals& _instance() { static Globals i; return i; }
        
    friend int main(int,char**);
};

#define sGlobals Globals::instance()

#endif
