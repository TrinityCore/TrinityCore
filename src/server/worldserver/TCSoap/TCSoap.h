/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef _TCSOAP_H
#define _TCSOAP_H

#include "Define.h"
#include <future>
#include <string>
#include <thread>

void process_message(struct soap* soap_message);
std::thread* CreateSoapThread(const std::string& host, uint16 port);

class SOAPCommand
{
    public:
        SOAPCommand():
            m_success(false)
        {
        }

        ~SOAPCommand()
        {
        }

        void appendToPrintBuffer(std::string_view msg)
        {
            m_printBuffer += msg;
        }

        void setCommandSuccess(bool val)
        {
            m_success = val;
            finishedPromise.set_value();
        }

        bool hasCommandSucceeded() const
        {
            return m_success;
        }

        static void print(void* callbackArg, std::string_view msg)
        {
            ((SOAPCommand*)callbackArg)->appendToPrintBuffer(msg);
        }

        static void commandFinished(void* callbackArg, bool success);

        bool m_success;
        std::string m_printBuffer;
        std::promise<void> finishedPromise;
};

#endif
