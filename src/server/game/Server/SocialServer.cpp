#include "SocialServer.h"
#include "ZmqContext.h"
#include "Config.h"
#include "Log.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "World.h"
#include "Commands.h"

SocialServer::SocialServer() :
    poller(new zmqpp::poller()),
    push_socket(sContext->newSocket(zmqpp::socket_type::push)),
    pull_socket(sContext->newSocket(zmqpp::socket_type::subscribe))
{
    push_socket->connect(sConfigMgr->GetStringDefault("Redirect.SocialServer", "inproc://no-ss"));
    pull_socket->connect("tcp://localhost:9998");

    pull_socket->subscribe("");

    poller->add(*pull_socket, zmqpp::poller::poll_in);

    TC_LOG_INFO("socialserver", "Connected to socialserver");
}

SocialServer::~SocialServer()
{
    delete poller;
    delete push_socket;
    delete pull_socket;
}

void SocialServer::Init(RedirectInfo const& currentNode)
{
    current_node = currentNode;
}

void SocialServer::SendCommand(zmqpp::message& msg)
{
    push_socket->send(msg);
}

void SocialServer::BuildPacketCommand(zmqpp::message& msg, WorldPacket& packet)
{
    msg << current_node.ip;
    msg << uint16(current_node.port);
    msg << uint16(BROADCAST_PACKET);
    msg << uint16(packet.GetOpcode());
    msg << uint32(packet.size());
    msg.add(packet.contents(), packet.size());
}

void SocialServer::Update()
{
    poller->poll(1);
    if (poller->events(*pull_socket) & zmqpp::poller::poll_in)
    {
        int op1;
        do
        {
            zmqpp::message msg;
            pull_socket->receive(msg);
            HandleCommand(msg);
            pull_socket->get(zmqpp::socket_option::events, op1);
        } while (op1 & zmqpp::poller::poll_in);
    }
}

void SocialServer::HandleCommand(zmqpp::message const& msg)
{
    RedirectInfo source;
    uint16 command;

    msg.get(source.ip, 0);
    msg.get(source.port, 1);
    msg.get(command, 2);

    switch (command)
    {
        case SUSPEND_COMMS:
        {
            // ignore if we sent this request, only disconnect client from other nodes
            uint32 accountId;
            msg.get(accountId, 3);

            if (WorldSession* session = sWorld->FindSession(accountId))
            {
                if (source.ip != current_node.ip || source.port != current_node.port)
                {
                    WorldPacket suspend(SMSG_SUSPEND_COMMS, 4);
                    suspend << uint32(0);
                    session->SendPacket(&suspend);
                }
            }
            break;
        }
        case BROADCAST_PACKET:
        {
            uint16 opcode;
            uint32 size;
            uint8 const* data;
            uint8 target;

            msg.get(opcode, 3);
            msg.get(size, 4);
            msg.get(data, 5);
            msg.get(target, 6);

            WorldPacket packet(opcode, size);
            if (size)
            {
                packet.resize(size);
                packet.put(0, data, size);
            }

            switch (target)
            {
                case BROADCAST_GUILD:
                {
                    uint32 guildId;
                    msg.get(guildId, 7);
                    if (Guild* guild = sGuildMgr->GetGuildById(guildId))
                        guild->BroadcastPacket(msg, &packet);
                    break;
                }
                case BROADCAST_GROUP:
                    uint32 guildId;
                    msg.get(guildId, 7);
                    //if (Group* group = sGroupMgr->GetGroupByGUID(guildId))
                    //    guild->BroadcastPacket(msg, &packet);
                    break;
                case BROADCAST_PLAYER:
                {
                    uint64 guid;
                    msg.get(guid, 7);
                    if (Player* player = HashMapHolder<Player>::Find(guid))
                        player->GetSession()->SendPacket(&packet);
                    break;
                }
                case BROADCAST_ACCOUNT:
                {
                    uint32 accountId;
                    msg.get(accountId, 7);
                    if (WorldSession* session = sWorld->FindSession(accountId))
                        session->SendPacket(&packet);
                    break;
                }
                case BROADCAST_PENDING_SESSION:
                {
                    uint32 accountId;
                    msg.get(accountId, 7);
                    auto itr = _sessionQueue.find(accountId);
                    if (itr != _sessionQueue.end())
                    {
                        itr->second->SendPacket(&packet);
                        sWorld->AddSession(itr->second);
                        _sessionQueue.erase(itr);
                    }
                    break;
                }
                default:
                    break;
            }

            break;
        }
        default:
            break;
    }
}

void SocialServer::QueueSession(WorldSession* session)
{
    _sessionQueue[session->GetAccountId()] = session;
}
