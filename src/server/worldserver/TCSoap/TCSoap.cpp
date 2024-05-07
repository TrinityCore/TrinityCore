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

#include "TCSoap.h"
#include "AccountMgr.h"
#include "IpAddress.h"
#include "Log.h"
#include "Memory.h"
#include "Realm.h"
#include "World.h"
#include "soapH.h"
#include "soapStub.h"

std::thread* CreateSoapThread(const std::string& host, uint16 port)
{
    auto soap = Trinity::make_unique_ptr_with_deleter(new struct soap(), [](struct soap* soap)
    {
        soap_destroy(soap);
        soap_end(soap);
        soap_done(soap);
        delete soap;
    });

    soap_init(soap.get());
    soap_set_imode(soap.get(), SOAP_C_UTFSTRING);
    soap_set_omode(soap.get(), SOAP_C_UTFSTRING);

#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
    soap->bind_flags = SO_REUSEADDR;
#endif

    // check every 3 seconds if world ended
    soap->accept_timeout = 3;
    soap->recv_timeout = 5;
    soap->send_timeout = 5;
    if (!soap_valid_socket(soap_bind(soap.get(), host.c_str(), port, 100)))
    {
        TC_LOG_ERROR("network.soap", "Couldn't bind to {}:{}", host, port);
        return nullptr;
    }

    TC_LOG_INFO("network.soap", "Bound to http://{}:{}", host, port);

    return new std::thread([soap = std::move(soap)]
    {
        while (!World::IsStopped())
        {
            if (!soap_valid_socket(soap_accept(soap.get())))
                continue;   // ran into an accept timeout

            struct soap* thread_soap = soap_copy(soap.get());// make a safe copy
            TC_LOG_DEBUG("network.soap", "Accepted connection from IP={}", Trinity::Net::make_address_v4(thread_soap->ip).to_string());
            process_message(thread_soap);
        }
    });
}

void process_message(struct soap* soap_message)
{
    TC_LOG_TRACE("network.soap", "SOAPWorkingThread::process_message");

    soap_serve(soap_message);
    soap_destroy(soap_message); // dealloc C++ data
    soap_end(soap_message); // dealloc data and clean up
    soap_free(soap_message); // detach soap struct and free up the memory
}
/*
Code used for generating stubs:

int ns1__executeCommand(char* command, char** result);
*/
int ns1__executeCommand(soap* soap, char* command, char** result)
{
    // security check
    if (!soap->userid || !soap->passwd)
    {
        TC_LOG_INFO("network.soap", "Client didn't provide login information");
        return 401;
    }

    uint32 accountId = AccountMgr::GetId(soap->userid);
    if (!accountId)
    {
        TC_LOG_INFO("network.soap", "Client used invalid username '{}'", soap->userid);
        return 401;
    }

    if (!AccountMgr::CheckPassword(accountId, soap->passwd))
    {
        TC_LOG_INFO("network.soap", "Invalid password for account '{}'", soap->userid);
        return 401;
    }

    if (AccountMgr::GetSecurity(accountId, realm.Id.Realm) < SEC_ADMINISTRATOR)
    {
        TC_LOG_INFO("network.soap", "{}'s gmlevel is too low", soap->userid);
        return 403;
    }

    if (!command || !*command)
        return soap_sender_fault(soap, "Command can not be empty", "The supplied command was an empty string");

    TC_LOG_INFO("network.soap", "Received command '{}'", command);
    SOAPCommand connection;

    // commands are executed in the world thread. We have to wait for them to be completed
    {
        // CliCommandHolder will be deleted from world, accessing after queueing is NOT safe
        CliCommandHolder* cmd = new CliCommandHolder(&connection, command, &SOAPCommand::print, &SOAPCommand::commandFinished);
        sWorld->QueueCliCommand(cmd);
    }

    // Wait until the command has finished executing
    connection.finishedPromise.get_future().wait();

    // The command has finished executing already
    char* printBuffer = soap_strdup(soap, connection.m_printBuffer.c_str());
    if (connection.hasCommandSucceeded())
    {
        *result = printBuffer;
        return SOAP_OK;
    }
    else
        return soap_sender_fault(soap, printBuffer, printBuffer);
}

void SOAPCommand::commandFinished(void* soapconnection, bool success)
{
    SOAPCommand* con = (SOAPCommand*)soapconnection;
    con->setCommandSuccess(success);
}

////////////////////////////////////////////////////////////////////////////////
//
//  Namespace Definition Table
//
////////////////////////////////////////////////////////////////////////////////

struct Namespace namespaces[] =
{   { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", nullptr, nullptr }, // must be first
    { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", nullptr, nullptr }, // must be second
    { "xsi", "http://www.w3.org/1999/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", nullptr },
    { "xsd", "http://www.w3.org/1999/XMLSchema",          "http://www.w3.org/*/XMLSchema", nullptr },
    { "ns1", "urn:TC", nullptr, nullptr },     // "ns1" namespace prefix
    { nullptr, nullptr, nullptr, nullptr }
};
