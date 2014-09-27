#include "SocialServer.h"
#include "ZmqContext.h"
#include "Config.h"
#include "Log.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "World.h"
#include "Commands.h"
#include "WorldSession.h"

SocialServer::SocialServer() :
    poller(new zmqpp::poller()),
    push_socket(sContext->newSocket(zmqpp::socket_type::push)),
    pull_socket(sContext->newSocket(zmqpp::socket_type::subscribe))
{
    push_socket->connect(sConfigMgr->GetStringDefault("Redirect.SocialServer", "inproc://no-ss"));
    pull_socket->connect("tcp://localhost:9998");

    host_id = (uint32)rand32();
    printf("I am: %u\n", host_id);
    pull_socket->subscribe("\xFF\xFF\xFF\xFF");
    pull_socket->subscribe(std::string((char*)&host_id, sizeof(host_id)));
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
    msg.push_front(host_id);
    push_socket->send(msg);
}

void SocialServer::BuildPacketCommand(zmqpp::message& msg, WorldPacket& packet)
{
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

void SocialServer::HandleCommand(zmqpp::message& msg)
{
    uint32 envelope;
    uint32 source;
    uint16 command;

    msg >> envelope;
    msg >> source;
    msg >> command;

    printf("Received %u from %u envelope %u\n", command, source, envelope);
    switch (command)
    {
        case SUSPEND_COMMS:
        {
            uint32 accountId;
            msg >> accountId;
            printf("SUSPEND_COMMS: %u\n", accountId);
            if (WorldSession* session = sWorld->FindSession(accountId))
            {
                printf("Session found\n");
                // ignore if we sent this request, only disconnect client from other nodes
                if (source != host_id)
                {
                    WorldPacket suspend(SMSG_SUSPEND_COMMS, 4);
                    suspend << uint32(0);
                    session->SendPacket(&suspend);
                }
            }
            else
                printf("Session not found\n");
            break;
        }
        case BROADCAST_PACKET:
        {
            uint16 opcode;
            uint32 size;
            uint8 const* data;
            uint8 target;

            msg >> opcode;
            msg >> size;
            msg >> data;
            msg >> target;

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
                    msg >> guildId;
                    if (Guild* guild = sGuildMgr->GetGuildById(guildId))
                        guild->BroadcastPacket(msg, &packet);
                    break;
                }
                case BROADCAST_GROUP:
                {
                    uint32 groupGuid;
                    msg >> groupGuid;
                    if (Group* group = sGroupMgr->GetGroupByGUID(groupGuid))
                        group->BroadcastPacket(msg, &packet);
                    break;
                }
                case BROADCAST_PLAYER:
                {
                    uint64 guid;
                    msg >> guid;
                    if (Player* player = HashMapHolder<Player>::Find(guid))
                        player->GetSession()->SendPacket(&packet);
                    break;
                }
                case BROADCAST_ACCOUNT:
                {
                    uint32 accountId;
                    msg >> accountId;
                    if (WorldSession* session = sWorld->FindSession(accountId))
                        session->SendPacket(&packet);
                    break;
                }
                case BROADCAST_PENDING_SESSION:
                {
                    uint32 accountId;
                    msg >> accountId;
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
        case CHECK_CAN_ENTER_MAP:
        {
            uint32 mapId;

            msg >> mapId;
            if (sWorld->IsMapHandledByCurrentNode(mapId))
            {
                uint64 playerGuid;
                uint32 groupGuid;
                uint32 instanceId;

                msg >> playerGuid;
                msg >> groupGuid;
                msg >> instanceId;

                zmqpp::message response;
                response << uint16(CHECK_CAN_ENTER_MAP_RESULT);
                response << uint32(source);
                response << uint32(mapId);
                response << uint64(playerGuid);
                response << uint32(sMapMgr->CanPlayerEnterRemoteMap(mapId, groupGuid, instanceId));
                SendCommand(response);
            }
            break;
        }
        case CHECK_CAN_ENTER_MAP_RESULT:
        {
            uint32 destNode;
            uint32 mapId;
            uint64 playerGuid;
            uint32 result;

            msg >> destNode;
            msg >> mapId;
            msg >> playerGuid;
            msg >> result;

            if (Player* player = HashMapHolder<Player>::Find(playerGuid))
            {
                if (!result)
                    player->GetSession()->RedirectToNode(mapId);
                else
                    player->SendTransferAborted(mapId, TransferAbortReason(result));
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
