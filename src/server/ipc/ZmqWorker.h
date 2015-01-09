/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

class ZmqWorker : public ZMQTask
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
