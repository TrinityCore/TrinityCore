#pragma execution_character_set("utf-8")
#include "Global.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "ArenaTeamMgr.h"
#include "GuildMgr.h"
#include "GroupMgr.h"
#include "SpellMgr.h"
#include "UpdateMask.h"
#include "World.h"
#include "ArenaTeam.h"
#include "Transport.h"
#include "Language.h"
#include "GameEventMgr.h"
#include "Spell.h"
#include "Chat.h"
#include "AccountMgr.h"
#include "InstanceSaveMgr.h"
#include "SpellAuras.h"
#include "Util.h"
#include "WaypointManager.h"
#include "GossipDef.h"
#include "Vehicle.h"
#include "AchievementMgr.h"
#include "DisableMgr.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "PoolMgr.h"
#include "Config.h"
#include <algorithm>
#include "Pet.h"
#include "FakeBot.h"

void FakeBot::LoadFakeBotConfig()
{
    _FakeBotConfigMap.clear();

    QueryResult result = WorldDatabase.Query("SELECT ���, ����ֵ FROM _��ʵ���˿��Ʊ�;");

    if (!result)
    {
        sLog->outString("���ܱ� >> [_��ʵ���˿��Ʊ�] û������");
        return;
    }

    uint32 Ct = 0;
    FakeBotConfig St;
    do
    {
        Field* fields = result->Fetch();
        St.Id = fields[0].GetUInt32();
        St.Value = fields[1].GetString();

        if (St.Value.empty() || St.Value == "")
        {
            sLog->outError("���� ���ܱ� >> [_��ʵ���˿��Ʊ�] ��������Ϊ�� �Ѻ���");
            continue;
        }

        _FakeBotConfigMap.insert(FakeBotConfigMap::value_type(St.Id, St));

        ++Ct;
    } while (result->NextRow());

    sLog->outString("���ܱ� >> ���� [_��ʵ���˿��Ʊ�] �ܼ� %u ������", Ct);
}

const char* FakeBot::GetFakeConfig(uint32 Index)
{
    auto Itr = _FakeBotConfigMap.find(Index);
    return Itr != _FakeBotConfigMap.end() ? Itr->second.Value.c_str() : "";
}

void FakeBot::LoadFakeConfig()
{
    LoadFakeBotConfig();

    Enable = uint32(atoi(GetFakeConfig(1001)));
    AccountMax = uint32(atoi(GetFakeConfig(1002)));

    uint32 MinTime = 120;
    uint32 MaxTime = 300;
    std::string Configs = std::string(GetFakeConfig(1003));
    if (Configs.find("#") != std::string::npos)
    {
        Tokenizer Store(Configs, '#');
        if (!std::string(Store[0]).empty() && std::string(Store[0]) != "" && atoi(Store[0]) > 0)
            MinTime = atoi(Store[0]);
        if (!std::string(Store[1]).empty() && std::string(Store[1]) != ""&& atoi(Store[1]) > 0)
            MaxTime = atoi(Store[1]);
    }

    uint32 NextBotLoginTime = urand(MinTime, MaxTime);

    MessageToGM = uint32(atoi(GetFakeConfig(1004)));
    CustomGuid = uint32(atoi(GetFakeConfig(1005)));

    if (AccountMax <= 0)
        AccountMax = 128;

    if (Enable > 0)
    {
        MapEvents.CancelEvent(EVENT_REMOVE_ALL);
        if (!MapEvents.GetNextEventTime(EVENT_UPDATE_ACCOUNT))
            MapEvents.RescheduleEvent(EVENT_UPDATE_ACCOUNT, 30 * MINUTE * IN_MILLISECONDS);
        if (!MapEvents.GetNextEventTime(EVENT_CHECK_PLAYERCOUNT))
            MapEvents.RescheduleEvent(EVENT_CHECK_PLAYERCOUNT, NextBotLoginTime * IN_MILLISECONDS);
    }
    else
    {
        CleanData(true);
        MapEvents.CancelEvent(EVENT_UPDATE_ACCOUNT);
        MapEvents.CancelEvent(EVENT_CHECK_PLAYERCOUNT);
    }

    LoadFakePlayerStore();
    LoadFakeRandomMsg();
    LoadFakeBotLocation();
}

uint32 FakeBot::GetFakePlayerCount() const
{
    return m_BotPlayers.size();
}

bool FakeBot::IsFakeBot(Player* player)
{
    auto const itr = m_BotPlayers.find(player->GetGUIDLow());
    return (player->GetSession() && player->IsInWorld() && itr != m_BotPlayers.end());
}

uint32 FakeBot::GetPlayerBotAccountId(uint32 PlayerGuid)
{
    for (auto const& AccountMap : m_AllAccount)
    {
        for (auto const& Guid : AccountMap.second)
        {
            if (Guid == PlayerGuid)
                return AccountMap.first;
        }
    }
    return 0;
}

void FakeBot::HandlePlayerLoginOpcode(uint32 PlayerGuid)
{
    //�����¼�ʺű�ʹ�õļ���
    if (uint32 AccountId = GetPlayerBotAccountId(PlayerGuid))
        RemoveAccountBot(AccountId, true);
}

bool FakeBot::RemovePlayerBot(uint32 PlayerGuid)
{
    auto const itr = m_BotPlayers.find(PlayerGuid);
    if (itr != m_BotPlayers.end())
    {
        RemoveFakeBotSession(PlayerGuid);

        m_BotPlayers.erase(itr);
        return true;
    }

    return false;
}

bool FakeBot::RemoveAccountBot(uint32 AccountId, bool All)
{
    auto& AccountMap = m_BotAccount[AccountId];
    for (auto itr = AccountMap.begin(); itr != AccountMap.end();)
    {
        bool Ret = RemovePlayerBot(*itr);
        itr = AccountMap.erase(itr);
        if (Ret && !All)
            return true;
    }
    return false;
}

bool FakeBot::FakePlayerLogin()
{
    SessionMap const& Sessions = sWorld->GetAllSessions();
    for (auto const& AccountMap : m_AllAccount)
    {
        uint32 AccountId = AccountMap.first;

        //�����лỰ��
        if (Sessions.find(AccountId) != Sessions.end())
            continue;

        if (m_BotAccount[AccountId].size() < AccountMax)
        {
            for (auto const& PlayerGuid : AccountMap.second)
            {
                //�����ѵ�¼��
                Player* FakeBot = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(PlayerGuid, 0, HIGHGUID_PLAYER));
                if (FakeBot && FakeBot->IsInWorld())
                    continue;

                //�������ڵ�
                auto const itr = m_BotPlayers.find(PlayerGuid);
                if (itr != m_BotPlayers.end())
                    continue;

                //������ʼ��ʧ�ܵ�
                WorldSession *FakerSession = new WorldSession(AccountId, NULL, SEC_PLAYER, 2, time(NULL), LOCALE_zhCN, 0, false, true, 0);
                if (!FakerSession)
                {
                    delete FakerSession;
                    continue;
                }

                FakerSession->SetPlayerLoading(true);

                //������ʼ��ʧ�ܵ�
                LoginQueryHolder *Holder = new LoginQueryHolder(AccountId, MAKE_NEW_GUID(PlayerGuid, 0, HIGHGUID_PLAYER));
                if (!Holder->Initialize())
                {
                    delete Holder;
                    FakerSession->SetPlayerLoading(false);
                    continue;
                }

                //��ʼ��¼����Ϸ

                auto NowLoginCallback = CharacterDatabase.DelayQueryHolder((SQLQueryHolder*)Holder);
                SQLQueryHolder* ParamHolder;
                NowLoginCallback.get(ParamHolder);
                FakerSession->HandlePlayerLoginFromDB((LoginQueryHolder*)ParamHolder);

                Player* GameBot = FakerSession->GetPlayer();
                if (!GameBot)
                {
                    sLog->outError("��ʵ���� << Ψһ��ʶ: %u �˺ű��: %u ���ؽ�ɫʧ�� �����޷�����", PlayerGuid, AccountId);
                    FakerSession->LogoutPlayer(false);
                    delete FakerSession;
                    continue;
                }

                bool DoCanFly = (GameBot->HasAuraType(SPELL_AURA_FLY) || GameBot->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || GameBot->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED));
                //���������ߴ��ķ��б�� ��ô�˴������˻ָ�
                GameBot->SetCanFly(DoCanFly);

                //����֮ǰ�������ǰ�ĵ�ͼ����
                WorldLocation DoLocation(GameBot->GetMapId(), GameBot->GetPositionX(), GameBot->GetPositionY(), GameBot->GetPositionZ(), GameBot->GetOrientation());
                TrueLocation Temp;
                Temp.GuidLow = PlayerGuid;
                Temp.Location = DoLocation;
                _TruePlayerLocations.push_back(Temp);

                //����Ự
                _FakeBotSessions.push_back(FakerSession);

                //��¼�ɹ� ��������
                m_BotAccount[AccountId].emplace_back(PlayerGuid);
                m_BotPlayers[PlayerGuid] = GameBot;

                sLog->outString("<< [��ʵ����] ��ǰ���߼������� %u", GetFakePlayerCount());

                return true;
            }
        }
    }

    return false;
}

bool FakeBot::FakePlayerLogout(bool Check)
{
    //�����Ƴ������������ļ���
    for (auto& AccountMap : m_BotAccount)
    {
        uint32 AccountId = AccountMap.first;

        if (AccountMap.second.size() > AccountMax)
        {
            for (auto itr = AccountMap.second.begin(); itr != AccountMap.second.end();)
            {
                bool Ret = RemovePlayerBot(*itr);
                itr = AccountMap.second.erase(itr);

                if (Ret)
                    return true;

                if (AccountMap.second.size() == AccountMax)
                    break;
            }
        }
    }

    if (!Check)
    {
        //���ȫ���������� ֱ���Ƴ�һ���б��еļ���
        for (auto& AccountMap : m_BotAccount)
        {
            uint32 AccountId = AccountMap.first;

            if (RemoveAccountBot(AccountId))
                return true;
        }
    }

    return false;
}

void FakeBot::CheckPlayerCount()
{
    if (!IsEnable())
        return;

    uint32 FakeCount = GetFakePlayerCount();

    if (FakeCount < AccountMax)
        if (FakePlayerLogin())
            return;

    //�Ƴ������������ļ���
    if (FakePlayerLogout(true))
        return;

    if (FakeCount > AccountMax)
        FakePlayerLogout();
}

void FakeBot::CleanData(bool All)
{
    for (auto& AccountMap : m_AllAccount)
        AccountMap.second.clear();

    m_AllAccount.clear();

    if (All)
        MapEvents.RescheduleEvent(EVENT_REMOVE_ALL, IN_MILLISECONDS);
}

void FakeBot::RemoveAllPlayerBot()
{
    for (auto& AccountMap : m_BotAccount)
        RemoveAccountBot(AccountMap.first);

    m_BotAccount.clear();
}

void FakeBot::FakeSendGlobalGMSysMessage(const char *Msg, WorldSession* Self, TeamId Team)
{
    WorldPacket Data;

    char* Buf = strdup(Msg);
    char* Pos = Buf;

    while (char* Line = ChatHandler::LineFromMessage(Pos))
    {
        ChatHandler::BuildChatPacket(Data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, NULL, Line);
        SessionMap const& Sessions = sWorld->GetAllSessions();
        for (SessionMap::const_iterator itr = Sessions.begin(); itr != Sessions.end(); ++itr)
        {
            WorldSession* Session = itr->second;
            if (!Session || Session == Self || AccountMgr::IsPlayerAccount(Session->GetSecurity()))
                continue;

            Player* player = Session->GetPlayer();
            if (!player || !player->IsInWorld())
                continue;

            if (Team == TEAM_NEUTRAL || player->GetTeamId() == Team)
                Session->SendPacket(&Data);
        }
    }

    free(Buf);
}

bool FakeBot::OnFakeWhisper(std::string const& Msg, const uint32 Lang, Player* Sender, Player* Receiver)
{
    if (IsEnable())
    {
        if (Lang == LANG_ADDON)
            return false;

        //GM����ظ�
        if (IsMessageToGM())
        {
            if (IsFakeBot(Receiver))
            {
                m_LastWhispers[Sender->GetGUIDLow()] = Receiver->GetGUIDLow();
                std::string BackMsg = "|cFF00CCCC[��ʵ������Ϣ����]|r ��Ϣ: [ |cFFFF9999" + Msg + "|r ] ���ͷ����-> " + sGlobal->GetNameLinkColor(Sender) + " ������ͷ����ֻظ�";
                FakeSendGlobalGMSysMessage(BackMsg.c_str());
            }
            else
            {
                if (m_LastWhispers.find(Receiver->GetGUIDLow()) != m_LastWhispers.end())
                {
                    uint32 zGuid = m_LastWhispers[Receiver->GetGUIDLow()];
                    if (m_BotPlayers.find(zGuid) != m_BotPlayers.end())
                    {
                        if (Player* SendBot = m_BotPlayers[zGuid])
                        {
                            if (SendBot->IsInWorld() && SendBot != Receiver)
                            {
                                SendBot->Whisper(Msg, Lang, Receiver->GetGUID());
                                std::string SendMsg = "|cFF00CCCC[��ʵ������Ϣ����]|r GM-> " + sGlobal->GetNameLinkColor(Sender) + " �ظ�: [ |cFFFF9999" + Msg + "|r ] ���շ�-> " + sGlobal->GetNameLinkColor(Receiver);
                                FakeSendGlobalGMSysMessage(SendMsg.c_str());
                                return true;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            //����ظ�
            if (IsFakeBot(Receiver))
            {
                Receiver->Whisper(GetWhisperRandom(), Lang, Sender->GetGUID());
                return true;
            }
        }
    }
    return false;
}

std::string FakeBot::GetWhisperRandom()
{
    uint32 Xy = urand(1, FakeMsgs.size());
    if (FakeMsgs.find(Xy) != FakeMsgs.end())
        return std::string(FakeMsgs[Xy]);

    return "����...";
}

uint32 FakeBot::GetFakeBotMoveDelay()
{
    uint32 MinDelay = 60;
    uint32 MaxDelay = 180;
    std::string Configs = std::string(GetFakeConfig(1006));
    if (Configs.find("#") != std::string::npos)
    {
        Tokenizer Store(Configs, '#');
        if (!std::string(Store[0]).empty() && std::string(Store[0]) != "" && atoi(Store[0]) > 0)
            MinDelay = atoi(Store[0]);
        if (!std::string(Store[1]).empty() && std::string(Store[1]) != ""&& atoi(Store[1]) > 0)
            MaxDelay = atoi(Store[1]);
    }

    return urand(MinDelay, MaxDelay);
}

void FakeBot::ResetTrueLocation(Player* FakeBot)
{
    for (auto itr = _TruePlayerLocations.begin(); itr != _TruePlayerLocations.end();)
    {
        if (itr->GuidLow == FakeBot->GetGUIDLow())
        {
            FakeBot->TeleportTo(itr->Location);
            itr = _TruePlayerLocations.erase(itr);
        }
        else
            itr++;
    }
}

void FakeBot::RemoveFakeBotSession(uint32 PlayerGuidLow)
{
    for (auto itr = _FakeBotSessions.begin(); itr != _FakeBotSessions.end();)
    {
        if ((*itr)->GetPlayer()->GetGUIDLow() == PlayerGuidLow)
        {
            ResetTrueLocation((*itr)->GetPlayer());

            WorldSession* Session = (*itr);
            Session->LogoutPlayer(true);
            delete Session;

            itr = _FakeBotSessions.erase(itr);
        }
        else
            itr++;
    }
}

void WorldSession::HandleFakeBotPackets()
{
    WorldPacket* Packet;
    while (_recvQueue.next(Packet))
    {
        OpcodeHandler& OpHandle = opcodeTable[Packet->GetOpcode()];
        (this->*OpHandle.handler)(*Packet);
        delete Packet;
    }
}

void FakeBot::UpdateAllSessions(uint32 Diff)
{
    for (auto itr = _FakeBotSessions.begin(); itr != _FakeBotSessions.end(); itr++)
    {
        if ((*itr) && (*itr)->GetPlayer()->IsBeingTeleportedFar())
            (*itr)->HandleMoveWorldportAckOpcode();
    }
}

void FakeBot::Update(Player* FakeBot, uint32 Diff)
{
    if (!IsFakeBot(FakeBot))
        return;

    if (FakeBot->IsBeingTeleportedNear())
    {
        WorldPacket Packet = WorldPacket(MSG_MOVE_TELEPORT_ACK, 8 + 4 + 4);
        Packet.appendPackGUID(FakeBot->GetGUID());
        Packet << (uint32)0;
        Packet << (uint32)0;
        FakeBot->GetSession()->HandleMoveTeleportAck(Packet);
    }
    else if (FakeBot->IsInWorld())
        FakeBot->GetSession()->HandleFakeBotPackets();

    FakeBot->FakeBotMoveTimer += Diff;

    if (FakeBot->FakeBotMoveTimer >= GetFakeBotMoveDelay() * IN_MILLISECONDS)
    {
        FakeBot->FakeBotMoveTimer = 0;

        if (FakeBot->isMoving() || FakeBot->IsBeingTeleported() || _FakeBotLocations.empty())
            return;

        FakeLocation Location = _FakeBotLocations[urand(0, _FakeBotLocations.size() - 1)];

        if (FakeBot->GetMapId() != Location.MapId)
            FakeBot->TeleportTo(Location.MapId, Location.X + frand(-1, 1), Location.Y + frand(-1, 1), Location.Z, Location.O);
        else
            FakeBot->GetMotionMaster()->MoveCharge(Location.X + frand(-1, 1), Location.Y + frand(-1, 1), Location.Z, FakeBot->GetSpeed(MOVE_RUN));
    }
}

void FakeBot::LoadFakeBotLocation()
{
    if (!IsEnable())
        return;

    _FakeBotLocations.clear();

    QueryResult result = WorldDatabase.Query("SELECT ���, ��ͼ���, ����X, ����Y, ����Z, ��λO FROM _��ʵ�����ƶ������;");

    if (!result)
    {
        sLog->outString("���ܱ� >> [_��ʵ�����ƶ������] û������");
        return;
    }

    uint32 Ct = 0;
    FakeLocation St;
    do
    {
        Field* fields = result->Fetch();
        St.Idx = fields[0].GetUInt32();
        St.MapId = fields[1].GetUInt32();
        St.X = fields[2].GetFloat();
        St.Y = fields[3].GetFloat();
        St.Z = fields[4].GetFloat();
        St.O = fields[5].GetFloat();

        _FakeBotLocations.push_back(St);

        ++Ct;
    } while (result->NextRow());

    sLog->outString("���ܱ� >> ���� [_��ʵ�����ƶ������] �ܼ� %u ������", Ct);
}

void FakeBot::LoadFakePlayerStore()
{
    if (!IsEnable())
        return;

    CleanData();

    QueryResult result = NULL;

    if (CustomGuid > 0)
        result = CharacterDatabase.PQuery("SELECT guid, account FROM characters WHERE guid <= '%u';", CustomGuid);
    else
        result = CharacterDatabase.Query("SELECT guid, account FROM characters;");

    if (!result)
    {
        sLog->outString("���ܱ� >> [_��ʵ���˽�ɫ] characters û������");
        return;
    }

    uint32 Ct = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 PlayerGuid = fields[0].GetUInt32();
        uint32 AccountId = fields[1].GetUInt32();

        //�����GM�����������
        if (AccountMgr::GetSecurity(AccountId) > SEC_PLAYER)
            continue;

        m_AllAccount[AccountId].emplace_back(PlayerGuid);

        ++Ct;
    } while (result->NextRow());

    sLog->outString("���ܱ� >> ���� [_��ʵ���˽�ɫ] characters �ܼ� %u ������", Ct);
}

void FakeBot::LoadFakeRandomMsg()
{
    if (!IsEnable())
        return;

    FakeMsgs.clear();

    QueryResult result = WorldDatabase.Query("SELECT ���, �����Ϣ FROM _��ʵ���������Ϣ;");

    if (!result)
    {
        sLog->outString("���ܱ� >> [_��ʵ���������Ϣ] û������");
        return;
    }

    uint32 Ct = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 Id = fields[0].GetUInt32();
        std::string Msg = fields[1].GetString();

        if (Msg.empty() || Msg == "")
        {
            sLog->outError("���� ���ܱ� >> [_��ʵ���������Ϣ] ��������Ϊ��");
            continue;
        }

        FakeMsgs[Id] = Msg;

        ++Ct;
    } while (result->NextRow());

    sLog->outString("���ܱ� >> ���� [_��ʵ���������Ϣ] �ܼ� %u ������", Ct);
}

class FakePlayerWorldScript : public WorldScript
{
public:
    FakePlayerWorldScript() : WorldScript("FakePlayerWorldScript")
    {
        
    }

    //�߳�ִ�к���
    void FakeThread()
    {
        sFakeBot->CheckPlayerCount();
    }

    void FakeExecuteEvent(uint32 EventId)
    {
        switch (EventId)
        {
        case EVENT_UPDATE_ACCOUNT:
            sFakeBot->LoadFakePlayerStore();
            sFakeBot->MapEvents.RepeatEvent(30 * MINUTE * IN_MILLISECONDS);
            break;
        case EVENT_CHECK_PLAYERCOUNT:
        {
            //ʹ���̵߳�¼
            std::thread DoThread(&FakePlayerWorldScript::FakeThread, this);
            DoThread.detach();

            uint32 MinTime = 120;
            uint32 MaxTime = 300;
            std::string Configs = std::string(sFakeBot->GetFakeConfig(1003));
            if (Configs.find("#") != std::string::npos)
            {
                Tokenizer Store(Configs, '#');
                if (!std::string(Store[0]).empty() && std::string(Store[0]) != "" && atoi(Store[0]) > 0)
                    MinTime = atoi(Store[0]);
                if (!std::string(Store[1]).empty() && std::string(Store[1]) != ""&& atoi(Store[1]) > 0)
                    MaxTime = atoi(Store[1]);
            }
            uint32 NextBotLoginTime = urand(MinTime, MaxTime);

            sFakeBot->MapEvents.RepeatEvent(NextBotLoginTime * IN_MILLISECONDS);
        }
        break;
        case EVENT_REMOVE_ALL:
            sFakeBot->FakePlayerLogout();
            if (!sFakeBot->IsEnable() && sFakeBot->GetFakePlayerCount() > 0)
                sFakeBot->MapEvents.RepeatEvent(IN_MILLISECONDS);
            break;
        }
    }

    void OnUpdate(uint32 diff) override
    {
        sFakeBot->MapEvents.Update(diff);
        if (sFakeBot->IsEnable())
        {
            if (uint32 EventId = sFakeBot->MapEvents.GetEvent())
                FakeExecuteEvent(EventId);
        }
    }

    void OnShutdown() override
    {
        sFakeBot->RemoveAllPlayerBot();
    }
};

class FakeBotOnline : public PlayerScript
{
public:
    FakeBotOnline() : PlayerScript("FakeBotOnline") { }

    void OnBeforeUpdate(Player* player, uint32 ptime) override
    {
        if (!sFakeBot->IsFakeBot(player))
            return;

        sFakeBot->Update(player, ptime);
    }
};

void AddSC_CustomFakePlayerScript()
{
    new FakePlayerWorldScript();
    new FakeBotOnline();
}

