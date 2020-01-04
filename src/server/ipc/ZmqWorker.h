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

#ifndef __ZMQWORKER_H
#define __ZMQWORKER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

class TC_IPC_API ZmqWorker : public ZMQTask
{
public:
    ZmqWorker(std::string const& taskUri, std::string const& resUri);
    ~ZmqWorker();
    void Run() override;

protected:
    void HandleOpen() override;
    void HandleClose() override;
    zmqpp::socket* _results = nullptr;

private:
    void PerformWork();
    virtual void Dispatch(zmqpp::message const&) = 0;
    zmqpp::socket* _taskQueue = nullptr;
    std::string _taskUri;
    std::string _resultsUri;
};

#endif
