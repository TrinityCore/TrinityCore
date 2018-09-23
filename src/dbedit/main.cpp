/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Globals.h"
#include "IoContext.h"
#include "LoadingWindow.h"
#include "LoadingThread.h"
#include "MainWindow.h"
#include <cstdio>
#include <QApplication>

int main(int argc, char** argv)
{
    Globals& globals = Globals::_instance();
    globals.IoCtx = std::make_shared<Trinity::Asio::IoContext>();

    QApplication test(argc, argv);
    globals.MainWindow = std::make_unique<MainWindow>();

    // SINGLE-THREADED LOGIC ENDS HERE - GLOBALS SHOULD NOT BE WRITTEN TO BELOW HERE

    LoadingWindow loading;
    LoadingThread::BeginLoading(loading);

    return test.exec();
}
