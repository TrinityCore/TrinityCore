/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ChannelMgr.h"
#include "Player.h"
#include "RestCommon.h"
#include "ScriptMgr.h"
#include "World.h"
#include <boost/property_tree/ptree.hpp>

class RestChannelPost : public RestScript
{
public:
    RestChannelPost(const char* path) : RestScript(path) { }

protected:
    void HandlePost(Team team, boost::property_tree::ptree tree, RestResponse& response)
    {
        std::string senderName  = tree.get<std::string>("senderName", "");
        std::string channelName = tree.get<std::string>("channelName", "");
        std::string message     = tree.get<std::string>("message", "");
        bool showGMLogo         = tree.get<bool>("showGMLogo", false);

        if (!senderName.length())
            return response.setError("senderName mustn't be empty");

        if (!channelName.length())
            return response.setError("channelName mustn't be empty");

        if (!message.length())
            return response.setError("message mustn't be empty");

        ChannelMgr* mgr = nullptr;

        if (team == ALLIANCE)
            mgr = ChannelMgr::ForTeam(ALLIANCE);
        else if (team == HORDE)
            mgr = ChannelMgr::ForTeam(HORDE);

        if (!mgr)
            return response.setError("invalid teamId");

        if (!mgr->SendToAllInChannel(senderName, channelName, message, showGMLogo))
            return response.setError("SendToAllInChannel error");

        return response.setSuccess();
    }
};

class RestChannelPostAlliance : public RestChannelPost
{
public:
    RestChannelPostAlliance() : RestChannelPost("/sendChannelMessage/0") { }

    void OnPost(boost::property_tree::ptree tree, RestResponse& response) override
    {
        HandlePost(ALLIANCE, tree, response);
    }
};

class RestChannelPostHorde : public RestChannelPost
{
public:
    RestChannelPostHorde() : RestChannelPost("/sendChannelMessage/1") { }

    void OnPost(boost::property_tree::ptree tree, RestResponse& response) override
    {
        HandlePost(HORDE, tree, response);
    }
};

class RestCommandPost : public RestScript
{
public:
    RestCommandPost() : RestScript("/command") { }

    class RESTCommand
    {
        public:
            RESTCommand():  m_success(false) { }

            void appendToPrintBuffer(const char* msg)
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

            static void print(void* callbackArg, const char* msg)
            {
                ((RESTCommand*)callbackArg)->appendToPrintBuffer(msg);
            }

            static void commandFinished(void* callbackArg, bool success)
            {
                RESTCommand* con = (RESTCommand*)callbackArg;
                con->setCommandSuccess(success);
            }

            bool m_success;
            std::string m_printBuffer;
            std::promise<void> finishedPromise;
    };

    void OnPost(boost::property_tree::ptree tree, RestResponse& response) override
    {
        std::string command = tree.get<std::string>("command", "");
        RESTCommand restCommand;

        // commands are executed in the world thread. We have to wait for them to be completed
        {
            // CliCommandHolder will be deleted from world, accessing after queueing is NOT save
            CliCommandHolder* cmd = new CliCommandHolder(&restCommand, command.c_str(), &RESTCommand::print, &RESTCommand::commandFinished);
            sWorld->QueueCliCommand(cmd);
        }

        // Wait until the command has finished executing
        restCommand.finishedPromise.get_future().wait();

        if (restCommand.hasCommandSucceeded())
            response.setSuccess(restCommand.m_printBuffer);
        else
            response.setError(restCommand.m_printBuffer);
    }
};

void AddSC_rest_scripts()
{
    new RestChannelPostAlliance();
    new RestChannelPostHorde();
    new RestCommandPost();
}
