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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"
#include "Weather.h"

enum Yells
{
    // Highlord Tirion Fordring
    TIRION_SAY_WELCOME              = 0,
    TIRION_SAY_GORMOK               = 1,
    TIRION_SAY_JORMUNGARS           = 2,
    TIRION_SAY_ICEHOWL              = 3,
    TIRION_SAY_BEASTS_DONE          = 4,
    TIRION_SAY_BEASTS_WIPE          = 5,
    TIRION_SAY_WILFRED              = 6,
    TIRION_SAY_KILL_JARAXXUS        = 7,
    TIRION_SAY_LAMENT               = 8,
    TIRION_SAY_CALM_DOWN            = 9,
    TIRION_SAY_CHAMPIONS            = 10,
    TIRION_SAY_ALLOW_COMBAT         = 11,
    TIRION_SAY_TRAGIC_VICTORY       = 12,
    TIRION_SAY_WORK_TOGETHER        = 13,
    TIRION_SAY_GAME_BEGIN           = 14,
    TIRION_SAY_UNITED               = 15,
    TIRION_SAY_ARTHAS               = 16,

    // Varian Wrynn
    VARIAN_SAY_BEASTS               = 0,
    VARIAN_SAY_COME_PIGS            = 1,
    VARIAN_SAY_DEMAND_JUSTICE       = 2,
    VARIAN_SAY_FIGHT_GLORY          = 3,
    VARIAN_SAY_FACTION_DEAD         = 4,
    VARIAN_SAY_VALKYR_DEAD          = 5,
    VARIAN_SAY_KILLED               = 6,

    // Garrosh
    GARROSH_SAY_BEASTS              = 0,
    GARROSH_SAY_ALLIANCE_DOGS       = 1,
    GARROSH_SAY_DEMAND_JUSTICE      = 2,
    GARROSH_SAY_NO_MERCY            = 3,
    GARROSH_SAY_FACTION_DEAD        = 4,
    GARROSH_SAY_VALKYR_DEAD         = 5,
    GARROSH_SAY_KILLED              = 6,

    // Wilfred Fizzlebang
    WILFRED_SAY_INTRO               = 0,
    WILFRED_SAY_OBLIVION            = 1,
    WILFRED_SAY_MASTER              = 2,
    WILFRED_SAY_DEAD                = 3,

    // The Lich King Voice
    LK_VOICE_SAY_CHALLENGE          = 4,
    LK_VOICE_SAY_SOULS_WILL_BE_MINE = 5,

    //  The Lich King
    LK_SAY_EMPIRE                   = 0,

    // Highlord Tirion Fordring (Anu'barak)
    SAY_STAGE_4_06                  = 0,
    SAY_STAGE_4_07                  = 1
};

enum TrialMisc
{
    SPLINE_INITIAL_MOVEMENT    = 1,
    POINT_SUMMON               = 1,
    POINT_MIDDLE               = 2,
    GROUP_VALKYR               = 1,
    GOSSIPID_FAIL              = 1,
    POINT_BARRETT_DESPAWN      = 1,
    AREA_TRIAL_OF_THE_CRUSADER = 4722
};

enum TrialEvents
{
    EVENT_GORMOK_INTRO = 1,
    EVENT_GORMOK_EXCLAMATION,
    EVENT_SPAWM_GORMOK,
    EVENT_EXCLAMATION,
    EVENT_SUMMON_BARRET,
    EVENT_START_CALL_WILFRED,
    EVENT_KILL_JARAXXUS,
    EVENT_EMOTE_SHEATHE,
    EVENT_TIRION_LAMENT,
    EVENT_TIRION_CALM_DOWN,
    EVENT_ALLOW_COMBAT,
    EVENT_TRAGIC_VICTORY,
    EVENT_SUMMON_WILFRED,
    EVENT_START_MOVE,
    EVENT_OBLIVION,
    EVENT_SUMMON_JARAXXUS,
    EVENT_SET_TARGET,
    EVENT_LAST_TALK,
    EVENT_SUMMON_VALKYR,
    EVENT_OPEN_GATE,
    EVENT_SAY_ARTHAS,
    EVENT_ALLIANCE_DOGS,
    EVENT_COME_PIGS,
    EVENT_DEMAND_JUSTICE,
    EVENT_NO_MERCY,
    EVENT_VALKYR_DEAD,
    EVENT_LICH_KING_SAY_CHALLENGE,
    EVENT_LICH_KING_SAY_SOULS,
    EVENT_SUMMON_LICH_KING,
    EVENT_BREAK_PLATFORM,
    EVENT_EMOTE_TALK,
    EVENT_REMOVE_EMOTE_TALK,
    EVENT_EMOTE_EXCLAMATION,
    EVENT_EMOTE_KNEEL,
    EVENT_SUMMON_CHAMPIONS,
    EVENT_START_CHAMPIONS,
    EVENT_START_TALK
};

enum TocMenuIds
{
    MENUID_NORTHREND_BEASTS  = 10600,
    MENUID_JARAXXUS          = 10610,
    MENUID_FACTION_CHAMPIONS = 10687,
    MENUID_VALKYR            = 10688,
    MENUID_LK                = 10693
};

Position const BarretSpawnPosition       = { 559.1528f, 90.55729f, 395.2734f, 5.078908f };
Position const WilfredSpawnPosition      = { 563.6007f, 208.5278f, 395.2696f, 4.729842f };
Position const JaraxxusSpawnPosition     = { 563.8264f, 140.6563f, 393.9861f, 4.694936f };
Position const PortalTargetSpawnPosition = { 563.6597f, 139.7569f, 399.2507f, 4.712389f };
Position const PurpleGroundSpawnPosition = { 563.6858f, 139.4323f, 393.9862f, 4.694936f };
Position const ArthasPortalSpawnPosition = { 563.6996f, 175.9826f, 394.5042f, 4.694936f };
Position const LichKingSpawnPosition     = { 563.5712f, 174.8351f, 394.4954f, 4.712389f };
Position const CorpseTeleportPosition    = { 631.9390f, 136.5040f, 142.5540f, 0.803332f };

Position const NorthrendBeastsSpawnPositions[] =
{
    { 563.9358f, 229.8299f, 394.8061f, 4.694936f }, // Gormok \ Icehowl
    { 564.2802f, 233.1322f, 394.7897f, 1.621917f }, // Dreadscale
};

Position const AnubarakLoc[] =
{
    { 783.9305f, 132.9722f, 142.6711f, 3.141593f }, // 0 - Anub'arak Spawn Location (sniffed)
    { 695.240051f, 137.834824f, 142.200000f, 0 },  // 1 - Anub'arak move point location
    { 694.886353f, 102.484665f, 142.119614f, 0 },  // 3 - Nerub Spawn
    { 694.500671f, 185.363968f, 142.117905f, 0 },  // 5 - Nerub Spawn
    { 731.987244f, 83.3824690f, 142.119614f, 0 },  // 2 - Nerub Spawn
    { 740.184509f, 193.443390f, 142.117584f, 0 }   // 4 - Nerub Spawn
};

Position const EndSpawnLoc[] =
{
    { 648.9167f, 131.0208f, 141.6161f, 0.f }, // 0 - Highlord Tirion Fordring
    { 649.1614f, 142.0399f, 141.3057f, 0.f }, // 1 - Argent Mage
    { 644.6250f, 149.2743f, 140.6015f, 5.f }  // 2 - Portal to Dalaran
};

// ToDo: Remove it in nexts rewrites
Position const ToCCommonLoc[] =
{
    { 559.257996f, 90.266197f, 395.122986f, 0.0f },  //  0 Barrent
    { 563.672974f, 139.57100f, 393.837006f, 0.0f },    //  1 Center
    { 563.833008f, 187.244995f, 394.50000f, 0.0f },      //  2 Backdoor
    { 577.347839f, 195.338888f, 395.14000f, 0.0f },     //  3 - Right
    { 550.955933f, 195.338888f, 395.14000f, 0.0f },     //  4 - Left
    { 563.833008f, 195.244995f, 394.585561f, 0.0f }, //  5 - Center
    { 573.500000f, 180.500000f, 395.14f, 0.0f },               //  6 Move 0 Right
    { 553.5f, 180.5f, 400.5521f, 0 },               //  7 Move 0 Left
    { 573.0f, 170.0f, 400.5521f, 0 },               //  8 Move 1 Right
    { 549.5139f, 170.1389f, 394.7965f, 5.009095f }, //  9 Move 1 Left
    { 563.8f, 216.1f, 395.1f, 0 },                // 10 Behind the door

    { 575.042358f, 195.260727f, 395.137146f, 0 }, // 5
    { 552.248901f, 195.331955f, 395.132658f, 0 }, // 6
    { 573.342285f, 195.515823f, 395.135956f, 0 }, // 7
    { 554.239929f, 195.825577f, 395.137909f, 0 }, // 8
    { 571.042358f, 195.260727f, 395.137146f, 0 }, // 9
    { 556.720581f, 195.015472f, 395.132658f, 0 }, // 10
    { 569.534119f, 195.214478f, 395.139526f, 0 }, // 11
    { 569.231201f, 195.941071f, 395.139526f, 0 }, // 12
    { 558.811610f, 195.985779f, 394.671661f, 0 }, // 13
    { 567.641724f, 195.351501f, 394.659943f, 0 }, // 14
    { 560.633972f, 195.391708f, 395.137543f, 0 }, // 15
    { 565.816956f, 195.477921f, 395.136810f, 0 }  // 16
};

class ArthasPortalEvent : public BasicEvent
{
public:
    ArthasPortalEvent(Unit* owner) : BasicEvent(), _owner(owner) { }

    bool Execute(uint64 /*eventTime*/, uint32 /*diff*/) override
    {
        _owner->CastSpell(_owner, SPELL_ARTHAS_PORTAL, true);
        _owner->GetMap()->SetZoneWeather(AREA_TRIAL_OF_THE_CRUSADER, WEATHER_STATE_MEDIUM_SNOW, 0.75f);
        return true;
    }

private:
    Unit* _owner;
};

struct npc_barrett_toc : public ScriptedAI
{
    npc_barrett_toc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void SendActionToTirion(uint32 action)
    {
        if (Creature* fordring = _instance->GetCreature(DATA_FORDRING))
            fordring->AI()->DoAction(action);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        me->GetMotionMaster()->MoveAlongSplineChain(POINT_BARRETT_DESPAWN, SPLINE_INITIAL_MOVEMENT, false);
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        switch (menuId)
        {
            case MENUID_NORTHREND_BEASTS:
                if (gossipListId == GOSSIPID_FAIL)
                    SendActionToTirion(ACTION_START_GORMOK_FAIL);
                else
                    SendActionToTirion(ACTION_START_GORMOK);
                break;
            case MENUID_JARAXXUS:
                if (gossipListId == GOSSIPID_FAIL)
                {
                    if (Creature* jaraxxus = _instance->GetCreature(DATA_JARAXXUS))
                        jaraxxus->AI()->DoAction(ACTION_JARAXXUS_ENGAGE);
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_BARRETT_DESPAWN, SPLINE_INITIAL_MOVEMENT, false);
                    CloseGossipMenuFor(player);
                    return true;
                }
                else
                    SendActionToTirion(ACTION_START_JARAXXUS_EVENT);
                break;
            case MENUID_FACTION_CHAMPIONS:
                if (gossipListId == GOSSIPID_FAIL)
                    SendActionToTirion(ACTION_START_CHAMPIONS_ENGAGE);
                else
                    SendActionToTirion(ACTION_START_CHAMPIONS);
                break;
            case MENUID_VALKYR:
                if (gossipListId == GOSSIPID_FAIL)
                    SendActionToTirion(ACTION_START_VALKYR_ENGAGE);
                else
                    SendActionToTirion(ACTION_START_VALKYR);
                break;
            case MENUID_LK:
                SendActionToTirion(ACTION_START_LK_EVENT);
                break;
            default:
                return false;
        }

        CloseGossipMenuFor(player);
        return true;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        if (pointId == POINT_BARRETT_DESPAWN)
            me->DespawnOrUnsummon();
    }

private:
    InstanceScript* _instance;
};

struct boss_lich_king_toc : public ScriptedAI
{
    boss_lich_king_toc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _instance->SetBossState(DATA_LICH_KING, IN_PROGRESS);
        _events.ScheduleEvent(EVENT_START_MOVE, 1s);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        if (pointId == POINT_MIDDLE)
            _events.ScheduleEvent(EVENT_START_TALK, 4s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_MOVE:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_MIDDLE, SPLINE_INITIAL_MOVEMENT, true);
                    break;
                case EVENT_BREAK_PLATFORM:
                    DoCastSelf(SPELL_LK_FROST_NOVA, true);
                    DoCastSelf(SPELL_CORPSE_TELEPORT, true);
                    DoCastSelf(SPELL_DESTROY_FLOOR_KNOCKUP, true);
                    if (Creature* fordring = _instance->GetCreature(DATA_FORDRING))
                        fordring->AI()->DoAction(ACTION_LK_EVENT_FINISHED);
                    if (GameObject* floor = _instance->GetGameObject(DATA_COLISEUM_FLOOR))
                        floor->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                    _instance->SetBossState(DATA_LICH_KING, DONE);
                    break;
                case EVENT_EMOTE_TALK:
                    me->SetEmoteState(EMOTE_STATE_TALK);
                    me->GetMap()->SetZoneWeather(AREA_TRIAL_OF_THE_CRUSADER, WEATHER_STATE_FOG, 0.0f);
                    _events.ScheduleEvent(EVENT_EMOTE_EXCLAMATION, 10s);
                    break;
                case EVENT_EMOTE_EXCLAMATION:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    _events.ScheduleEvent(EVENT_EMOTE_KNEEL, 3s);
                    break;
                case EVENT_EMOTE_KNEEL:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                    break;
                case EVENT_START_TALK:
                    Talk(LK_SAY_EMPIRE);
                    _events.ScheduleEvent(EVENT_EMOTE_TALK, 4s);
                    _events.ScheduleEvent(EVENT_BREAK_PLATFORM, 18s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_tirion_toc : public ScriptedAI
{
    npc_tirion_toc(Creature* creature) : ScriptedAI(creature), _instance (creature->GetInstanceScript()), _factionLeaderData(0), _summons(me),
    _jormungarsSummoned(false), _icehowlSummoned(false) { }

    void Reset() override
    {
        _events.Reset();
        _factionLeaderData = _instance->GetData(DATA_TEAM) == ALLIANCE ? DATA_VARIAN : DATA_GARROSH;
        _jormungarsSummoned = false;
        _icehowlSummoned = false;
        HandleBarrettSummon();
    }

    void JustSummoned(Creature* summoned) override
    {
        _summons.Summon(summoned);
    }

    void HandleBarrettSummon()
    {
        if (IsHeroic() && _instance->GetBossState(DATA_NORTHREND_BEASTS) != DONE)
            me->SummonCreature(NPC_BARRETT_BEASTS_HC, BarretSpawnPosition);
        else if (_instance->GetBossState(DATA_NORTHREND_BEASTS) != DONE)
            me->SummonCreature(NPC_BARRETT_BEASTS, BarretSpawnPosition);
        else if (_instance->GetBossState(DATA_JARAXXUS) != DONE)
        {
            me->SummonCreature(NPC_BARRETT_JARAXXUS, BarretSpawnPosition);
            if (_instance->GetBossState(DATA_JARAXXUS) == FAIL)
                DoAction(ACTION_SUMMON_JARAXXUS);
        }
        else if (_instance->GetBossState(DATA_FACTION_CRUSADERS) != DONE)
            me->SummonCreature(NPC_BARRETT_FACTION, BarretSpawnPosition);
        else if (_instance->GetBossState(DATA_TWIN_VALKIRIES) != DONE)
            me->SummonCreature(NPC_BARRETT_VALKYR, BarretSpawnPosition);
        else if (_instance->GetBossState(DATA_LICH_KING) != DONE)
            me->SummonCreature(NPC_BARRETT_LK, BarretSpawnPosition);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_GORMOK:
                Talk(TIRION_SAY_WELCOME);
                _events.ScheduleEvent(EVENT_GORMOK_INTRO, 24s);
                break;
            case ACTION_START_GORMOK_FAIL:
                _events.ScheduleEvent(EVENT_GORMOK_INTRO, 1ms);
                break;
            case ACTION_START_JORMUNGARS:
                if (_jormungarsSummoned)
                    return;
                _jormungarsSummoned = true;
                Talk(TIRION_SAY_JORMUNGARS);
                _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
                me->SummonCreature(NPC_DREADSCALE, NorthrendBeastsSpawnPositions[1]);
                _events.ScheduleEvent(EVENT_EXCLAMATION, 7s);
                break;
            case ACTION_START_ICEHOWL:
                if (_icehowlSummoned)
                    return;
                _icehowlSummoned = true;
                Talk(TIRION_SAY_ICEHOWL);
                _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
                me->SummonCreature(NPC_ICEHOWL, NorthrendBeastsSpawnPositions[0], TEMPSUMMON_DEAD_DESPAWN);
                _events.ScheduleEvent(EVENT_EXCLAMATION, 6s);
                break;
            case ACTION_NORTHREND_BEASTS_WIPE:
                _jormungarsSummoned = false;
                _icehowlSummoned = false;
                Talk(TIRION_SAY_BEASTS_WIPE);
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 13s);
                break;
            case ACTION_NORTHREND_BEASTS_DEFEATED:
                Talk(TIRION_SAY_BEASTS_DONE);
                _events.ScheduleEvent(EVENT_EXCLAMATION, 2s);
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 6s);
                break;
            case ACTION_START_JARAXXUS_EVENT:
                _events.ScheduleEvent(EVENT_START_CALL_WILFRED, 1s);
                break;
            case ACTION_JARAXXUS_DEFEATED:
                _events.ScheduleEvent(EVENT_TIRION_LAMENT, 7s);
                break;
            case ACTION_JARAXXUS_WIPE:
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 30s);
                break;
            case ACTION_START_CHAMPIONS:
            {
                Talk(TIRION_SAY_CHAMPIONS);
                uint32 data = _instance->GetData(DATA_TEAM) == ALLIANCE ? DATA_GARROSH : DATA_VARIAN;
                if (Creature* otherFactionLeader = _instance->GetCreature(data))
                    otherFactionLeader->AI()->DoAction(ACTION_START_CHAMPIONS);
                _events.ScheduleEvent(EVENT_ALLOW_COMBAT, 26s);
                break;
            }
            case ACTION_FACTION_WIPE:
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 4s);
                break;
            case ACTION_START_CHAMPIONS_ENGAGE:
            {
                uint32 data = _instance->GetData(DATA_TEAM) == ALLIANCE ? DATA_GARROSH : DATA_VARIAN;
                if (Creature* otherFactionLeader = _instance->GetCreature(data))
                    otherFactionLeader->AI()->DoAction(ACTION_START_CHAMPIONS_ENGAGE);
                _events.ScheduleEvent(EVENT_SUMMON_CHAMPIONS, 3s);
                break;
            }
            case ACTION_CHAMPIONS_DEFEATED:
                _events.ScheduleEvent(EVENT_TRAGIC_VICTORY, 7s);
                break;
            case ACTION_SUMMON_JARAXXUS:
                me->SummonCreature(NPC_JARAXXUS, JaraxxusSpawnPosition);
                break;
            case ACTION_KILL_JARAXXUS:
                _events.ScheduleEvent(EVENT_KILL_JARAXXUS, 6s);
                break;
            case ACTION_START_VALKYR:
                Talk(TIRION_SAY_WORK_TOGETHER);
                _events.ScheduleEvent(EVENT_SUMMON_VALKYR, 17s);
                break;
            case ACTION_VALKYR_WIPE:
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 6s);
                _summons.DespawnEntry(NPC_LIGHT_ESSENCE);
                _summons.DespawnEntry(NPC_DARK_ESSENCE);
                break;
            case ACTION_VALKYR_DEFEATED:
                _events.ScheduleEvent(EVENT_SUMMON_BARRET, 4s);
                if (Creature* factionLeader = _instance->GetCreature(_factionLeaderData))
                    factionLeader->AI()->DoAction(ACTION_VALKYR_DEFEATED);
                _summons.DespawnEntry(NPC_LIGHT_ESSENCE);
                _summons.DespawnEntry(NPC_DARK_ESSENCE);
                break;
            case ACTION_START_VALKYR_ENGAGE:
                Talk(TIRION_SAY_GAME_BEGIN);
                _events.ScheduleEvent(EVENT_SUMMON_VALKYR, 5s);
                break;
            case ACTION_START_LK_EVENT:
                Talk(TIRION_SAY_UNITED);
                me->GetMap()->SetZoneWeather(AREA_TRIAL_OF_THE_CRUSADER, WEATHER_STATE_LIGHT_SNOW, 0.5f);
                _events.ScheduleEvent(EVENT_LICH_KING_SAY_CHALLENGE, 19s);
                _events.ScheduleEvent(EVENT_SAY_ARTHAS, 26s);
                break;
            case ACTION_LK_EVENT_FINISHED:
                _events.ScheduleEvent(EVENT_LICH_KING_SAY_SOULS, 2s);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        // Needed when using hotswap
        _summons.DespawnAll();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_GORMOK_INTRO:
                    Talk(TIRION_SAY_GORMOK);
                    if (Creature* factionLeader = _instance->GetCreature(_factionLeaderData))
                        factionLeader->AI()->DoAction(ACTION_START_GORMOK);
                    _events.ScheduleEvent(EVENT_GORMOK_EXCLAMATION, 6s);
                    break;
                case EVENT_GORMOK_EXCLAMATION:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    _events.ScheduleEvent(EVENT_SPAWM_GORMOK, 6s);
                    break;
                case EVENT_SPAWM_GORMOK:
                    _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
                    me->SummonCreature(NPC_GORMOK, NorthrendBeastsSpawnPositions[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 12s);
                    break;
                case EVENT_EXCLAMATION:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                    break;
                case EVENT_SUMMON_BARRET:
                    HandleBarrettSummon();
                    break;
                case EVENT_START_CALL_WILFRED:
                    Talk(TIRION_SAY_WILFRED);
                    _events.ScheduleEvent(EVENT_SUMMON_WILFRED, 7s);
                    break;
                case EVENT_SUMMON_WILFRED:
                    _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
                    me->SummonCreature(NPC_FIZZLEBANG, WilfredSpawnPosition, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 16s);
                    break;
                case EVENT_KILL_JARAXXUS:
                    Talk(TIRION_SAY_KILL_JARAXXUS);
                    _events.ScheduleEvent(EVENT_EMOTE_SHEATHE, 2s);
                    break;
                case EVENT_EMOTE_SHEATHE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_TALK_NO_SHEATHE);
                    break;
                case EVENT_TIRION_LAMENT:
                    Talk(TIRION_SAY_LAMENT);
                    if (Creature* varian = _instance->GetCreature(DATA_VARIAN))
                        varian->AI()->DoAction(ACTION_JARAXXUS_DEFEATED);
                    if (Creature* garrosh = _instance->GetCreature(DATA_GARROSH))
                        garrosh->AI()->DoAction(ACTION_JARAXXUS_DEFEATED);
                    _events.ScheduleEvent(EVENT_TIRION_CALM_DOWN, 33s);
                    break;
                case EVENT_TIRION_CALM_DOWN:
                    Talk(TIRION_SAY_CALM_DOWN);
                    _events.ScheduleEvent(EVENT_SUMMON_BARRET, 20s);
                    break;
                case EVENT_ALLOW_COMBAT:
                    Talk(TIRION_SAY_ALLOW_COMBAT);
                    _events.ScheduleEvent(EVENT_SUMMON_CHAMPIONS, 7s);
                    break;
                case EVENT_TRAGIC_VICTORY:
                    Talk(TIRION_SAY_TRAGIC_VICTORY);
                    _events.ScheduleEvent(EVENT_SUMMON_BARRET, 24s);
                    break;
                case EVENT_SUMMON_VALKYR:
                    me->SummonCreatureGroup(GROUP_VALKYR);
                    _events.ScheduleEvent(EVENT_OPEN_GATE, 3s);
                    break;
                case EVENT_OPEN_GATE:
                    _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
                    break;
                case EVENT_SAY_ARTHAS:
                    Talk(TIRION_SAY_ARTHAS);
                    break;
                case EVENT_LICH_KING_SAY_CHALLENGE:
                    if (Creature* lkVoice = _instance->GetCreature(DATA_LICH_KING_VOICE))
                        lkVoice->AI()->Talk(LK_VOICE_SAY_CHALLENGE);
                    if (Creature* arthasPortal = me->SummonCreature(NPC_ARTHAS_PORTAL, ArthasPortalSpawnPosition, TEMPSUMMON_TIMED_DESPAWN, 34s))
                        arthasPortal->m_Events.AddEventAtOffset(new ArthasPortalEvent(arthasPortal), 3s);
                    _events.ScheduleEvent(EVENT_SUMMON_LICH_KING, 5s);
                    break;
                case EVENT_LICH_KING_SAY_SOULS:
                    if (Creature* lkVoice = _instance->GetCreature(DATA_LICH_KING_VOICE))
                        lkVoice->AI()->Talk(LK_VOICE_SAY_SOULS_WILL_BE_MINE);
                    break;
                case EVENT_SUMMON_LICH_KING:
                    me->SummonCreature(NPC_LICH_KING, LichKingSpawnPosition, TEMPSUMMON_TIMED_DESPAWN, 30s);
                    break;
                case EVENT_SUMMON_CHAMPIONS:
                    if (Creature* factitonController = me->SummonCreature(NPC_CHAMPIONS_CONTROLLER, ToCCommonLoc[1]))
                        factitonController->AI()->SetData(0, _instance->GetData(DATA_TEAM)); // will be changed to DoAction soon
                    _events.ScheduleEvent(EVENT_START_CHAMPIONS, 3s);
                    break;
                case EVENT_START_CHAMPIONS:
                    if (Creature* factitonController = _instance->GetCreature(DATA_FACTION_CRUSADERS))
                        factitonController->AI()->SetData(1, NOT_STARTED); // will be changed to DoAction soon
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    uint32 _factionLeaderData;
    SummonList _summons;
    bool _jormungarsSummoned;
    bool _icehowlSummoned;
};

struct npc_open_portal_target_toc : public ScriptedAI
{
    npc_open_portal_target_toc(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _scheduler.CancelAll();
        me->SetDisableGravity(true);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_OPEN_PORTAL)
        {
            _scheduler.Schedule(2s, [this](TaskContext /*wilfredPortal*/)
            {
                DoCastSelf(SPELL_WILFRED_PORTAL);
                me->DespawnOrUnsummon(9s);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_fizzlebang_toc : public ScriptedAI
{
    npc_fizzlebang_toc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        _events.Reset();
        _events.ScheduleEvent(EVENT_START_MOVE, 1s);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == SPLINE_CHAIN_MOTION_TYPE && pointId == POINT_SUMMON)
        {
            _instance->DoUseDoorOrButton(_instance->GetGuidData(DATA_MAIN_GATE));
            Talk(WILFRED_SAY_INTRO);
            _events.ScheduleEvent(EVENT_EMOTE_TALK, 2s);
            _events.ScheduleEvent(EVENT_REMOVE_EMOTE_TALK, 9s);
            _events.ScheduleEvent(EVENT_OBLIVION, 11s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_MOVE:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_SUMMON, SPLINE_INITIAL_MOVEMENT, true);
                    break;
                case EVENT_OBLIVION:
                    me->SummonCreature(NPC_WILFRED_PORTAL, PortalTargetSpawnPosition);
                    me->SummonCreature(NPC_PURPLE_GROUND, PurpleGroundSpawnPosition, TEMPSUMMON_TIMED_DESPAWN, 16s);
                    Talk(WILFRED_SAY_OBLIVION);
                    DoCastSelf(SPELL_OPEN_PORTAL);
                    _events.ScheduleEvent(EVENT_SUMMON_JARAXXUS, 11s);
                    break;
                case EVENT_SUMMON_JARAXXUS:
                    if (Creature* fordring = _instance->GetCreature(DATA_FORDRING))
                        fordring->AI()->DoAction(ACTION_SUMMON_JARAXXUS);
                    Talk(WILFRED_SAY_MASTER);
                    _events.ScheduleEvent(EVENT_EMOTE_TALK, 2s);
                    _events.ScheduleEvent(EVENT_REMOVE_EMOTE_TALK, 7s);
                    _events.ScheduleEvent(EVENT_SET_TARGET, 4s);
                    break;
                case EVENT_SET_TARGET:
                    if (Creature* jaraxxus = _instance->GetCreature(DATA_JARAXXUS))
                        me->SetTarget(jaraxxus->GetGUID());
                    _events.ScheduleEvent(EVENT_EMOTE_SHEATHE, 6s);
                    break;
                case EVENT_EMOTE_SHEATHE:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_TALK_NO_SHEATHE);
                    _events.ScheduleEvent(EVENT_LAST_TALK, 9s);
                    break;
                case EVENT_LAST_TALK:
                    Talk(WILFRED_SAY_DEAD);
                    if (Creature* fordring = _instance->GetCreature(DATA_FORDRING))
                        fordring->AI()->DoAction(ACTION_KILL_JARAXXUS);
                    break;
                case EVENT_EMOTE_TALK:
                    me->SetEmoteState(EMOTE_STATE_TALK);
                    break;
                case EVENT_REMOVE_EMOTE_TALK:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_garrosh_toc : public ScriptedAI
{
    npc_garrosh_toc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_GORMOK:
                _events.ScheduleEvent(EVENT_GORMOK_INTRO, 12s);
                break;
            case ACTION_JARAXXUS_DEFEATED:
                _events.ScheduleEvent(EVENT_ALLIANCE_DOGS, 14s);
                break;
            case ACTION_START_CHAMPIONS:
                _events.ScheduleEvent(EVENT_DEMAND_JUSTICE, 8s);
                break;
            case ACTION_SAY_KILLED_PLAYER:
                Talk(GARROSH_SAY_KILLED);
                break;
            case ACTION_CHAMPIONS_DEFEATED:
                Talk(GARROSH_SAY_FACTION_DEAD);
                break;
            case ACTION_VALKYR_DEFEATED:
                _events.ScheduleEvent(EVENT_VALKYR_DEAD, 5s);
                break;
            case ACTION_START_CHAMPIONS_ENGAGE:
                _events.ScheduleEvent(EVENT_NO_MERCY, 6s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GORMOK_INTRO:
                    Talk(GARROSH_SAY_BEASTS);
                    break;
                case EVENT_ALLIANCE_DOGS:
                    Talk(GARROSH_SAY_ALLIANCE_DOGS);
                    break;
                case EVENT_DEMAND_JUSTICE:
                    Talk(GARROSH_SAY_DEMAND_JUSTICE);
                    _events.ScheduleEvent(EVENT_NO_MERCY, 21s);
                    break;
                case EVENT_NO_MERCY:
                    Talk(GARROSH_SAY_NO_MERCY);
                    break;
                case EVENT_VALKYR_DEAD:
                    Talk(GARROSH_SAY_VALKYR_DEAD);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

struct npc_varian_toc : public ScriptedAI
{
    npc_varian_toc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_GORMOK:
                _events.ScheduleEvent(EVENT_GORMOK_INTRO, 11s);
                break;
            case ACTION_JARAXXUS_DEFEATED:
                _events.ScheduleEvent(EVENT_COME_PIGS, 24s);
                break;
            case ACTION_START_CHAMPIONS:
                _events.ScheduleEvent(EVENT_DEMAND_JUSTICE, 9s);
                break;
            case ACTION_SAY_KILLED_PLAYER:
                Talk(VARIAN_SAY_KILLED);
                break;
            case ACTION_CHAMPIONS_DEFEATED:
                Talk(VARIAN_SAY_FACTION_DEAD);
                break;
            case ACTION_VALKYR_DEFEATED:
                _events.ScheduleEvent(EVENT_VALKYR_DEAD, 6s);
                break;
            case ACTION_START_CHAMPIONS_ENGAGE:
                _events.ScheduleEvent(EVENT_NO_MERCY, 6s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GORMOK_INTRO:
                    Talk(VARIAN_SAY_BEASTS);
                    break;
                case EVENT_COME_PIGS:
                    Talk(VARIAN_SAY_COME_PIGS);
                    break;
                case EVENT_DEMAND_JUSTICE:
                    Talk(VARIAN_SAY_DEMAND_JUSTICE);
                    _events.ScheduleEvent(EVENT_NO_MERCY, 20s);
                    break;
                case EVENT_NO_MERCY:
                    Talk(VARIAN_SAY_FIGHT_GLORY);
                    break;
                case EVENT_VALKYR_DEAD:
                    Talk(VARIAN_SAY_VALKYR_DEAD);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

// 69016 - Corpse Teleport
class spell_lich_king_teleport_corpse : public SpellScript
{
    PrepareSpellScript(spell_lich_king_teleport_corpse);

    void HandleTeleport(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->NearTeleportTo(CorpseTeleportPosition);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lich_king_teleport_corpse::HandleTeleport, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_trial_of_the_crusader()
{
    RegisterTrialOfTheCrusaderCreatureAI(npc_barrett_toc);
    RegisterTrialOfTheCrusaderCreatureAI(boss_lich_king_toc);
    RegisterTrialOfTheCrusaderCreatureAI(npc_tirion_toc);
    RegisterTrialOfTheCrusaderCreatureAI(npc_open_portal_target_toc);
    RegisterTrialOfTheCrusaderCreatureAI(npc_fizzlebang_toc);
    RegisterTrialOfTheCrusaderCreatureAI(npc_garrosh_toc);
    RegisterTrialOfTheCrusaderCreatureAI(npc_varian_toc);
    RegisterSpellScript(spell_lich_king_teleport_corpse);
}
