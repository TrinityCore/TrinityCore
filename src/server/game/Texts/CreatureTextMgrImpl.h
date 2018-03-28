#ifndef CreatureTextMgrImpl_h__
#define CreatureTextMgrImpl_h__

#include "CreatureTextMgr.h"
#include "CellImpl.h"
#include "Group.h"
#include "GridNotifiers.h"
#include "World.h"
#include "WorldSession.h"

template<class Builder>
class CreatureTextLocalizer
{
    public:
        CreatureTextLocalizer(Builder const& builder, ChatMsg msgType) : _builder(builder), _msgType(msgType)
        {
            _packetCache.resize(TOTAL_LOCALES, nullptr);
        }

        ~CreatureTextLocalizer()
        {
            for (size_t i = 0; i < _packetCache.size(); ++i)
            {
                if (_packetCache[i])
                    delete _packetCache[i]->first;
                delete _packetCache[i];
            }
        }

        void operator()(Player* player)
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            WorldPacket* messageTemplate;
            size_t whisperGUIDpos;

            // create if not cached yet
            if (!_packetCache[loc_idx])
            {
                messageTemplate = new WorldPacket();
                whisperGUIDpos = _builder(messageTemplate, loc_idx);
                ASSERT(messageTemplate->GetOpcode() != NULL_OPCODE);
                _packetCache[loc_idx] = new std::pair<WorldPacket*, size_t>(messageTemplate, whisperGUIDpos);
            }
            else
            {
                messageTemplate = _packetCache[loc_idx]->first;
                whisperGUIDpos = _packetCache[loc_idx]->second;
            }

            WorldPacket data(*messageTemplate);
            switch (_msgType)
            {
                case CHAT_MSG_MONSTER_WHISPER:
                case CHAT_MSG_RAID_BOSS_WHISPER:
                    data.put<uint64>(whisperGUIDpos, player->GetGUID().GetRawValue());
                    break;
                default:
                    break;
            }

            player->SendDirectMessage(&data);
        }

    private:
        std::vector<std::pair<WorldPacket*, size_t>* > _packetCache;
        Builder const& _builder;
        ChatMsg _msgType;
};

template<class Builder>
void CreatureTextMgr::SendChatPacket(WorldObject* source, Builder const& builder, ChatMsg msgType, WorldObject const* whisperTarget /*= nullptr*/, CreatureTextRange range /*= TEXT_RANGE_NORMAL*/, Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/) const
{
    if (!source)
        return;

    CreatureTextLocalizer<Builder> localizer(builder, msgType);

    switch (msgType)
    {
        case CHAT_MSG_MONSTER_PARTY:
        {
            if (!whisperTarget)
                return;

            if (Player* whisperPlayer = const_cast<Player*>(whisperTarget->ToPlayer()))
            {
                if (Group* group = whisperPlayer->GetGroup())
                    group->BroadcastWorker(localizer);
            }
            return;
        }
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        {
            if (range == TEXT_RANGE_NORMAL) // ignores team and gmOnly
            {
                if (!whisperTarget || whisperTarget->GetTypeId() != TYPEID_PLAYER)
                    return;

                localizer(const_cast<Player*>(whisperTarget->ToPlayer()));
                return;
            }
            break;
        }
        default:
            break;
    }

    switch (range)
    {
        case TEXT_RANGE_AREA:
        {
            uint32 areaId = source->GetAreaId();
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (itr->GetSource()->GetAreaId() == areaId && (!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    localizer(itr->GetSource());
            return;
        }
        case TEXT_RANGE_ZONE:
        {
            uint32 zoneId = source->GetZoneId();
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (itr->GetSource()->GetZoneId() == zoneId && (!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    localizer(itr->GetSource());
            return;
        }
        case TEXT_RANGE_MAP:
        {
            Map::PlayerList const& players = source->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if ((!team || Team(itr->GetSource()->GetTeam()) == team) && (!gmOnly || itr->GetSource()->IsGameMaster()))
                    localizer(itr->GetSource());
            return;
        }
        case TEXT_RANGE_WORLD:
        {
            SessionMap const& smap = sWorld->GetAllSessions();
            for (SessionMap::const_iterator iter = smap.begin(); iter != smap.end(); ++iter)
                if (Player* player = iter->second->GetPlayer())
                    if ((!team || Team(player->GetTeam()) == team) && (!gmOnly || player->IsGameMaster()))
                        localizer(player);
            return;
        }
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }

    float dist = GetRangeForChatType(msgType);
    Trinity::PlayerDistWorker<CreatureTextLocalizer<Builder>> worker(source, dist, localizer);
    Cell::VisitWorldObjects(source, worker, dist);
}


#endif // CreatureTextMgrImpl_h__
