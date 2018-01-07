/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2011-2016 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Creature.h"
#include "Map.h"
#include "Unit.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "CreatureGroups.h"
#include "Player.h"
#include "MotionMaster.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "zone_gilneas.h"

enum eBattleForGilneas
{
    QUEST_RUTTHERAN                     = 14434,
    QUEST_ENDGAME                       = 26706,

    NPC_FORSAKEN_CROSSBOWMAN            = 38210,
    NPC_LORNA_CROWLEY                   = 38426,
    NPC_DARK_RANGER_ELITE               = 38464,
    NPC_LADY_SYLVANAS_WINDRUNNER        = 38469,
    NPC_TOBIAS_MISTMANTLE               = 38507,
    NPC_LADY_SYLVANAS_WINDRUNNER_38530  = 38530,
    NPC_GENERAL_WARHOWL                 = 38533,
    NPC_HIGH_EXECUTOR_CRENSHAW          = 38537,
    NPC_KRENNAN_ARANAS                  = 38553,
    NPC_FORSAKEN_GENERAL                = 38617,
    NPC_FORSAKEN_SERGANT                = 38618,
    NPC_GUNSHIP_GRUNT                   = 42141,
    NPC_LORNA_CRAWLEY_43566             = 43566,
    NPC_WORGEN_WARRIOR                  = 43651,
    NPC_GILNEAN_SHARPSHOOTER            = 43703,
    NPC_HIPPOGRYPH                      = 43747,
    NPC_TOBIAS_MISTMANTLE_43749         = 43749,
    NPC_GILNEAS_VEHICLE_ROPE            = 43793,

    GO_WORGEN_GUNSHIP                   = 203428,
    GO_ROPE                             = 204428,

    SPELL_GILNEAS_MILITIA_SHOOT         = 6660,
    SPELL_CLEAVE                        = 15496,
    SPELL_FOR_GILNEAS                   = 81790,
};

// 38507
class npc_tobias_mistmantle_38507 : public CreatureScript
{
public:
    npc_tobias_mistmantle_38507() : CreatureScript("npc_tobias_mistmantle_38507") { }

    enum eNpc
    {
        EVENT_MOVEMENT_START_PATH_1 = 301,
        EVENT_MOVEMENT_START_PATH_2,
        EVENT_MOVEMENT_START_PATH_3,
        EVENT_MOVEMENT_START_PATH_4,
        EVENT_MOVEMENT_START_PATH_5,
        EVENT_MOVEMENT_START_PATH_6,
        EVENT_MOVEMENT_START_SYLVANAS_AI,
        EVENT_WAIT_FOR_PLAYER_1,
        EVENT_WAIT_FOR_PLAYER_2,
        EVENT_WAIT_FOR_PLAYER_3,
        EVENT_WAIT_FOR_PLAYER_4,
        EVENT_WAIT_FOR_OUTSIDE_EVENT,
        EVENT_WAIT_FOR_OUTSIDE_EVENT1,
    };

    struct npc_tobias_mistmantle_38507AI : public ScriptedAI
    {
        npc_tobias_mistmantle_38507AI(Creature* pCreature) : ScriptedAI(pCreature) { }

        EventMap m_events;
        ObjectGuid   m_playerGUID;
        ObjectGuid   m_sylvanasGUID;
        ObjectGuid   m_warhowlGUID;
        ObjectGuid   m_crenshawGUID;
        uint32   m_eventPhase;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_eventPhase = 0;
            m_sylvanasGUID = ObjectGuid::Empty;
            m_warhowlGUID = ObjectGuid::Empty;
            m_crenshawGUID = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            m_playerGUID = summoner->GetGUID();
            m_eventPhase = 1;
            m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_1, 3000);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->SetWalk(true);
            switch (summon->GetEntry())
            {
                case NPC_LADY_SYLVANAS_WINDRUNNER_38530:
                    m_sylvanasGUID = summon->GetGUID();
                    me->SetFacingToObject(summon);
                    summon->AI()->SetGUID(me->GetGUID(), me->GetEntry());
                    summon->AI()->SetGUID(m_playerGUID, PLAYER_GUID);
                    summon->GetMotionMaster()->MovePoint(2005, -1600.11f, 1518.04f, 29.24f);
                    break;
                case NPC_GENERAL_WARHOWL:
                    m_warhowlGUID = summon->GetGUID();
                    summon->GetMotionMaster()->MovePoint(2006, -1593.35f, 1531.32f, 29.24f);
                    break;
                case NPC_HIGH_EXECUTOR_CRENSHAW:
                    m_crenshawGUID = summon->GetGUID();
                    summon->GetMotionMaster()->MovePoint(2007, -1587.55f, 1519.32f, 29.24f);
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            switch (type)
            {
                case WAYPOINT_MOTION_TYPE:
                {
                    if (m_eventPhase == 1 && id == 0)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                            Talk(0, player);
                    }
                    else if (m_eventPhase == 1 && id == 1)
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_PATH_1, 1000);
                    else if (m_eventPhase == 2 && id == 0)
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                            Talk(1, player);
                    }
                    else if (m_eventPhase == 2 && id == 1)
                        m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_2, 1000); // on open gate
                    else if (m_eventPhase == 3 && id == 3)
                        m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_3, 1000); // on wall 1
                    else if (m_eventPhase == 4 && id == 5)
                        m_events.ScheduleEvent(EVENT_WAIT_FOR_OUTSIDE_EVENT, 1000);
                    else if (m_eventPhase == 5 && id == 23)
                        m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_4, 1000); // inside water
                    break;
                }
                case EFFECT_MOTION_TYPE: // jump
                {
                    if (m_eventPhase == 1 && id == 2001)
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_PATH_2, 1000);
                    else if (m_eventPhase == 3 && id == 2003)
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_PATH_4, 1000);
                    else if (m_eventPhase == 5 && id == 2004)
                    {
                        me->SetFacingTo(5.6f);
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_PATH_6, 10);
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_SYLVANAS_AI, 1000);
                    }
                    break;
                }
            }
        }

        ObjectGuid GetGUID(int32 id) const override
        {
            switch (id)
            {
                case NPC_TOBIAS_MISTMANTLE:
                    return me->GetGUID();
                case NPC_LADY_SYLVANAS_WINDRUNNER_38530:
                    return m_sylvanasGUID;
                case NPC_GENERAL_WARHOWL:
                    return m_warhowlGUID;
                case NPC_HIGH_EXECUTOR_CRENSHAW:
                    return m_crenshawGUID;
                case PLAYER_GUID:
                    return m_playerGUID;
            }
            return ObjectGuid::Empty;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WAIT_FOR_PLAYER_1:
                    {
                        if (IsPlayerNear(20.0f))
                            me->GetMotionMaster()->MovePath(3850701, false);
                        else
                            m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_1, 1000);
                        break;
                    }
                    case EVENT_MOVEMENT_START_PATH_1:
                    {
                        me->GetMotionMaster()->MoveJump(-1601.925f, 1607.654f, 20.11606f, 20.0f, 20.0f, 2001);
                        break;
                    }
                    case EVENT_MOVEMENT_START_PATH_2:
                    {
                        m_eventPhase = 2;
                        me->GetMotionMaster()->MovePath(3850702, false);
                        break;
                    }
                    case EVENT_WAIT_FOR_PLAYER_2:
                    {
                        if (IsPlayerNear(8.0f))
                        {
                            m_eventPhase = 3;
                            me->GetMotionMaster()->MovePath(3850703, false);
                        }
                        else
                            m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_2, 1000);
                        break;
                    }
                    case EVENT_WAIT_FOR_PLAYER_3:
                    {
                        if (IsPlayerNear(8.0f))
                            me->GetMotionMaster()->MoveJump(-1548.65f, 1618.41f, 23.1788f, 20.0f, 5.0f, 2003);
                        else
                            m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_3, 1000);
                        break;
                    }
                    case EVENT_MOVEMENT_START_PATH_4:
                    {
                        m_eventPhase = 4;
                        me->GetMotionMaster()->MovePath(3850704, false);
                        break;
                    }
                    case EVENT_WAIT_FOR_OUTSIDE_EVENT:
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                            if (Creature* general = me->FindNearestCreature(NPC_FORSAKEN_GENERAL, 25.0f))
                                general->AI()->Talk(0, player);
                        m_events.ScheduleEvent(EVENT_WAIT_FOR_OUTSIDE_EVENT1, 6000);
                        break;
                    }
                    case EVENT_WAIT_FOR_OUTSIDE_EVENT1:
                    {
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                            Talk(2, player);
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START_PATH_5, 6000);
                        break;
                    }
                    case EVENT_MOVEMENT_START_PATH_5:
                    {
                        m_eventPhase = 5;
                        me->GetMotionMaster()->MovePath(3850705, false);
                        break;
                    }
                    case EVENT_WAIT_FOR_PLAYER_4:
                    {
                        if (IsPlayerNear(8.0f))
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                                Talk(3, player);
                            me->GetMotionMaster()->MoveJump(-1614.5f, 1533.9f, 27.26f, 20.0f, 5.0f, 2004);
                        }
                        else
                            m_events.ScheduleEvent(EVENT_WAIT_FOR_PLAYER_4, 1000);
                        break;
                    }
                    case EVENT_MOVEMENT_START_PATH_6:
                    {
                        me->SetSwim(true);
                        me->GetMotionMaster()->MovePoint(2008, -1613.95f, 1536.012f, 27.4f);
                        break;
                    }
                    case EVENT_MOVEMENT_START_SYLVANAS_AI:
                    {
                        // there are several summon spell, but all have the summoner position as spawnpoint.. 72476, 72239, 72236, 72238, 72245
                        me->SummonCreature(NPC_GENERAL_WARHOWL, -1566.053f, 1557.191f, 29.36808f, 4.273f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                        me->SummonCreature(NPC_LADY_SYLVANAS_WINDRUNNER_38530, -1567.477f, 1554.569f, 29.36808f, 0.88f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                        me->SummonCreature(NPC_HIGH_EXECUTOR_CRENSHAW, -1566.795f, 1555.300f, 29.36808f, 3.275f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                        break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        bool IsPlayerNear(float range)
        {
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                if (player->GetDistance2d(me) < range)
                    return true;
            return false;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_tobias_mistmantle_38507AI(pCreature);
    }
};

// 38530
class npc_lady_sylvanas_windrunner_38530 : public CreatureScript
{
public:
    npc_lady_sylvanas_windrunner_38530() : CreatureScript("npc_lady_sylvanas_windrunner_38530") { }

    enum eNpc
    {
        EVENT_START_TALK = 401,
        EVENT_TALK_2,
        EVENT_TALK_3,
        EVENT_TALK_4,
        EVENT_TALK_5,
        EVENT_TALK_6,
        EVENT_TALK_7,
        EVENT_TALK_8,
        EVENT_END,
        EVENT_DESPAWN_WARHOWL,
        EVENT_DESPAWN,
    };

    struct npc_lady_sylvanas_windrunner_38530AI : public ScriptedAI
    {
        npc_lady_sylvanas_windrunner_38530AI(Creature* pCreature) : ScriptedAI(pCreature) { }

        EventMap m_events;
        ObjectGuid   m_playerGUID;
        ObjectGuid   m_tobiasGUID;
        ObjectGuid   m_sylvanasGUID;
        ObjectGuid   m_warhowlGUID;
        ObjectGuid   m_crenshawGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_tobiasGUID = ObjectGuid::Empty;
            m_sylvanasGUID = ObjectGuid::Empty;
            m_warhowlGUID = ObjectGuid::Empty;
            m_crenshawGUID = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetEntry() == NPC_TOBIAS_MISTMANTLE)
                m_tobiasGUID = summoner->GetGUID();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
                if (id == 2005)
                {
                    me->SetFacingTo(5.6f);
                    m_events.ScheduleEvent(EVENT_START_TALK, 1000);
                }
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
                case PLAYER_GUID:
                    m_playerGUID = guid;
                    break;
                case NPC_TOBIAS_MISTMANTLE:
                    m_tobiasGUID = guid;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_TALK:
                    {
                        if (Creature* tobias = ObjectAccessor::GetCreature(*me, m_tobiasGUID))
                        {
                            m_playerGUID = tobias->AI()->GetGUID(PLAYER_GUID);
                            m_warhowlGUID = tobias->AI()->GetGUID(NPC_GENERAL_WARHOWL);
                            m_crenshawGUID = tobias->AI()->GetGUID(NPC_HIGH_EXECUTOR_CRENSHAW);
                        }
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            warhowl->AI()->Talk(0);
                        m_events.ScheduleEvent(EVENT_TALK_2, 10000);
                        break;
                    }
                    case EVENT_TALK_2:
                    {
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            me->SetFacingToObject(warhowl);
                        Talk(0);
                        m_events.ScheduleEvent(EVENT_TALK_3, 8000);
                        break;
                    }
                    case EVENT_TALK_3:
                    {
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            warhowl->AI()->Talk(1);
                        m_events.ScheduleEvent(EVENT_TALK_4, 11000);
                        break;
                    }
                    case EVENT_TALK_4:
                    {
                        Talk(1);
                        m_events.ScheduleEvent(EVENT_TALK_5, 14000);
                        break;
                    }
                    case EVENT_TALK_5:
                    {
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            warhowl->AI()->Talk(2);
                        m_events.ScheduleEvent(EVENT_TALK_6, 8000);
                        break;
                    }
                    case EVENT_TALK_6:
                    {
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            warhowl->GetMotionMaster()->MovePoint(2010, -1566.053f, 1557.191f, 29.36808f);
                        Talk(2);
                        m_events.ScheduleEvent(EVENT_DESPAWN_WARHOWL, 8000);
                        m_events.ScheduleEvent(EVENT_TALK_7, 5000);
                        break;
                    }
                    case EVENT_TALK_7:
                    {
                        if (Creature* crenshaw = ObjectAccessor::GetCreature(*me, m_crenshawGUID))
                        {
                            crenshaw->AI()->Talk(0);
                            me->SetFacingToObject(crenshaw);
                        }
                        m_events.ScheduleEvent(EVENT_TALK_8, 10000);
                        break;
                    }
                    case EVENT_TALK_8:
                    {
                        Talk(3);
                        m_events.ScheduleEvent(EVENT_END, 8000);
                        break;
                    }
                    case EVENT_END:
                    {
                        if (Creature* crenshaw = ObjectAccessor::GetCreature(*me, m_crenshawGUID))
                            crenshaw->GetMotionMaster()->MovePoint(2010, -1566.053f, 1557.191f, 29.36808f);
                        me->GetMotionMaster()->MovePoint(2010, -1566.053f, 1557.191f, 29.36808f);
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                            player->KilledMonsterCredit(38530);
                        m_events.ScheduleEvent(EVENT_DESPAWN, 8000);
                        break;
                    }
                    case EVENT_DESPAWN_WARHOWL:
                    {
                        if (Creature* warhowl = ObjectAccessor::GetCreature(*me, m_warhowlGUID))
                            warhowl->DespawnOrUnsummon(10);
                        break;
                    }
                    case EVENT_DESPAWN:
                    {
                        if (Creature* crenshaw = ObjectAccessor::GetCreature(*me, m_crenshawGUID))
                            crenshaw->DespawnOrUnsummon(10);
                        if (Creature* tobias = ObjectAccessor::GetCreature(*me, m_tobiasGUID))
                            tobias->DespawnOrUnsummon(10);
                        me->DespawnOrUnsummon(10);
                        break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_lady_sylvanas_windrunner_38530AI(pCreature);
    }
};

// 38540
class npc_captured_riding_bat_38540 : public CreatureScript
{
public:
    npc_captured_riding_bat_38540() : CreatureScript("npc_captured_riding_bat_38540") { }

    enum eNpc
    {
        EVENT_START_WORK_AREA = 201,
        EVENT_TIMEOUT,
    };

    struct npc_captured_riding_bat_38540AI : public ScriptedAI
    {
        npc_captured_riding_bat_38540AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap m_events;
        uint8    m_gamePhase;

        void AttackStart(Unit* /*who*/) override {}
        void EnterCombat(Unit* /*who*/) override {}

        void Reset() override
        {
            m_events.Reset();
            m_gamePhase = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (m_gamePhase == 1 && id == 3)
                {
                    m_events.ScheduleEvent(EVENT_START_WORK_AREA, 10);
                    m_events.ScheduleEvent(EVENT_TIMEOUT, 120000);
                }
                else if (m_gamePhase == 3 && id == 3)
                {
                    if (Vehicle* bat = me->GetVehicleKit())
                        bat->RemoveAllPassengers();
                    me->DespawnOrUnsummon(10);
                }
            }
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    if (who->ToPlayer()->GetQuestStatus(24920) != QUEST_STATUS_INCOMPLETE)
                    {
                        me->GetVehicleKit()->RemoveAllPassengers();
                        return;
                    }
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetSpeed(MOVE_FLIGHT, 6.0f);
                me->GetMotionMaster()->MovePath(3854001, false);
                m_gamePhase = 1;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_WORK_AREA:
                {
                    me->SetSpeed(MOVE_FLIGHT, 4.0f);
                    m_gamePhase = 2;
                    me->GetMotionMaster()->MovePath(3854002, true);
                    break;
                }
                case EVENT_TIMEOUT:
                {
                    m_gamePhase = 3;
                    me->SetSpeed(MOVE_FLIGHT, 6.0f);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePath(3854003, false);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_captured_riding_bat_38540AI(creature);
    }
};

// 72849
class spell_fly_back_72849 : public SpellScriptLoader
{
public:
    spell_fly_back_72849() : SpellScriptLoader("spell_fly_back_72849") { }

    class spell_fly_back_72849_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fly_back_72849_SpellScript);

        void HandleDummy(SpellEffIndex /*effindex*/)
        {
            if (Unit* caster = GetCaster())
                if (Creature* bat = caster->ToCreature())
                {
                    bat->SetSpeed(MOVE_FLIGHT, 6.0f);
                    bat->GetMotionMaster()->MovePath(3854003, false);
                }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_fly_back_72849_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fly_back_72849_SpellScript();
    }
};

// 72247
class spell_iron_bomb_72247 : public SpellScriptLoader
{
public:
    spell_iron_bomb_72247() : SpellScriptLoader("spell_iron_bomb_72247") { }

    class IsFriendly
    {
    public:
        IsFriendly(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object) const
        {
            if (Unit* unit = object->ToUnit())
                return _caster->IsFriendlyTo(unit);
            return true;
        }

    private:
        Unit* _caster;
    };

    class spell_iron_bomb_72247_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_iron_bomb_72247_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(IsFriendly(GetCaster()));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_iron_bomb_72247_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_iron_bomb_72247_SpellScript();
    }
};

// the endgame is in phase 191

enum eEndGame
{
    ACTION_EVENT_ID_25663 = 25663, // leave the ship
    ACTION_EVENT_ID_25664 = 25664, // ship start movening
    ACTION_EVENT_ID_25670 = 25670, // ship spawn
    ACTION_EVENT_ID_25727 = 25727, // ship on destroy

    EVENT_MAKE_SHOWFIGHT = 301,
    EVENT_START_SHOWFIGHT,
    EVENT_FLOOR_IS_ONE_REMAIN,
    EVENT_FLOOR_IS_CLEAN,
    EVENT_START_ROPE_PART,
};

// 43749
class npc_tobias_mistmantle_43749 : public CreatureScript
{
public:
    npc_tobias_mistmantle_43749() : CreatureScript("npc_tobias_mistmantle_43749") { }

    struct npc_tobias_mistmantle_43749AI : public ScriptedAI
    {
        npc_tobias_mistmantle_43749AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        EventMap m_events;
        ObjectGuid   m_gunshipGUID;
        uint32   m_gunshipEventId;
        std::list<ObjectGuid> m_hippoList;

        void Initialize()
        {
            m_gunshipGUID = ObjectGuid::Empty;
            m_gunshipEventId = 0;
            m_events.ScheduleEvent(EVENT_INIT_TARGET, 1000);
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case ACTION_EVENT_ID_25663:
            case ACTION_EVENT_ID_25727:
                m_events.Reset();
                m_events.RescheduleEvent(EVENT_TALK_PART_00, 10);
                break;
            case ACTION_EVENT_ID_25670:
                m_events.ScheduleEvent(EVENT_TALK_PART_02, 10);
                m_events.RescheduleEvent(EVENT_TALK_PART_03, 30000);
                m_events.RescheduleEvent(EVENT_TALK_PART_04, 60000);
                break;
            case ACTION_EVENT_ID_25664:
                m_events.ScheduleEvent(EVENT_TALK_PART_02, 10);
                m_events.RescheduleEvent(EVENT_TALK_PART_03, 40000);
                m_events.RescheduleEvent(EVENT_TALK_PART_04, 80000);
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INIT_TARGET:
                {
                    if (!m_gunshipGUID)
                        FindWorgenGunshipWorldwide();

                    if (GameObject* ship = ObjectAccessor::GetGameObject(*me, m_gunshipGUID))
                    {
                        m_gunshipGUID = ship->GetGUID();
                        ship->AI()->SetGUID(me->GetGUID(), me->GetEntry());
                        break;
                    }
                    m_events.ScheduleEvent(EVENT_INIT_TARGET, 1000);
                    break;
                }
                case EVENT_TALK_PART_02:
                case EVENT_TALK_PART_03:
                case EVENT_TALK_PART_04:
                {
                    Talk(1);
                    SetHippoSpellClick(false);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (CheckPlayerForQuest() && CheckIsGunshipReady())
                    {
                        SetHippoSpellClick(true);
                        Talk(0);
                    }
                    else
                    {
                        SetHippoSpellClick(false);
                        Talk(1);
                    }
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void FindNearestHippogryphs()
        {
            m_hippoList.clear();
            std::list<Creature*> hippoList = me->FindNearestCreatures(NPC_HIPPOGRYPH, 25.0f);
            for (std::list<Creature*>::iterator itr = hippoList.begin(); itr != hippoList.end(); ++itr)
                m_hippoList.push_back((*itr)->GetGUID());
        }

        void SetHippoSpellClick(bool value)
        {
            if (m_hippoList.empty())
            {
                std::list<Creature*> hippoList = me->FindNearestCreatures(NPC_HIPPOGRYPH, 15.0f);
                for (std::list<Creature*>::const_iterator itr = hippoList.begin(); itr != hippoList.end(); ++itr)
                    if (Creature* hippo = (*itr))
                        m_hippoList.push_back(hippo->GetGUID());
            }

            for (std::list<ObjectGuid>::iterator itr = m_hippoList.begin(); itr != m_hippoList.end(); ++itr)
                if (Creature* hippo = ObjectAccessor::GetCreature(*me, (*itr)))
                {
                    if (value)
                        hippo->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    else
                        hippo->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                }
        }

        bool CheckPlayerForQuest()
        {
            std::list<Player*> playerList = me->SelectNearestPlayers(25.0f);
            for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                if ((*itr)->GetQuestStatus(QUEST_ENDGAME) == QUEST_STATUS_INCOMPLETE)
                    return true;
            return false;
        }

        class GunshipSearchWorker
        {
        public:
            GunshipSearchWorker(ObjectGuid* gunshipGuid) : m_gunshipGuid(gunshipGuid) { }

            void Visit(std::unordered_map<ObjectGuid, GameObject*>& gameObjectMap)
            {
                for (auto const& p : gameObjectMap)
                    if (p.second->IsInWorld() && p.second->GetEntry() == GO_WORGEN_GUNSHIP)
                        *m_gunshipGuid = p.first;
            }

            template<class T>
            void Visit(std::unordered_map<ObjectGuid, T*>&) { }
        private:
            ObjectGuid* m_gunshipGuid;
        };

        void FindWorgenGunshipWorldwide()
        {
            GunshipSearchWorker worker(&m_gunshipGUID);
            TypeContainerVisitor<GunshipSearchWorker, MapStoredObjectTypesContainer> visitor(worker);
            visitor.Visit(me->GetMap()->GetObjectsStore());
        }

        bool CheckIsGunshipReady()
        {
            if (GameObject* ship = ObjectAccessor::GetGameObject(*me, m_gunshipGUID))
                if (Transport* transport = ship->ToTransport())
                {
                    uint32 count = transport->GetStaticPassengers().size();
                    return (count >= 39) ? true : false;
                }

            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tobias_mistmantle_43749AI(creature);
    }
};

// 43751
class npc_hippogryph_43751 : public CreatureScript
{
public:
    npc_hippogryph_43751() : CreatureScript("npc_hippogryph_43751") { }

    enum eNpc
    {
        EVENT_MOVE_LAST_POINT=201,
        EVENT_EJECT_ALL_PASSENGER,
        EVENT_JUMP_TO_LORNA,
    };

    struct npc_hippogryph_43751AI : public ScriptedAI
    {
        npc_hippogryph_43751AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap m_events;
        ObjectGuid m_playerGUID;
        ObjectGuid m_lornaGUID;
        float  m_maxSpeed;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
            m_lornaGUID = ObjectGuid::Empty;
            m_maxSpeed = 4.9f;
            if (Creature* wy = me->FindNearestCreature(43747, 10.0f))
                me->SetOrientation(wy->GetOrientation());
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            switch (type)
            {
                case WAYPOINT_MOTION_TYPE:
                {
                    if (id == 2)
                        me->SetSpeed(MOVE_RUN, m_maxSpeed);
                    else if (id == 6)
                        me->SetSpeed(MOVE_RUN, 2);
                    else if (id == 7)
                        m_events.ScheduleEvent(EVENT_MOVE_LAST_POINT, 10);
                    break;
                }
                case POINT_MOTION_TYPE:
                {
                    switch (id)
                    {
                    case 1002:
                        m_events.ScheduleEvent(EVENT_JUMP_TO_LORNA, 10);
                        break;
                    }
                }
            } // end switch
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (Player* player = who->ToPlayer())
                    if (player->GetQuestStatus(QUEST_ENDGAME) == QUEST_STATUS_INCOMPLETE)
                    {
                        m_events.ScheduleEvent(EVENT_MOVEMENT_START, 1000);
                        m_playerGUID = who->GetGUID();
                        return;
                    }
            }

            me->DespawnOrUnsummon(100);
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVEMENT_START:
                {
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetSpeed(MOVE_RUN, 3);
                    me->GetMotionMaster()->MovePath(4375101, false);
                    break;
                }
                case EVENT_MOVE_LAST_POINT:
                {
                    FindLornaGuid();
                    if (Creature* lorna = ObjectAccessor::GetCreature(*me, m_lornaGUID))
                    {
                        Position pos = lorna->GetPosition();
                        pos.m_positionZ += 15.0f;
                        me->GetMotionMaster()->MovePoint(1002, pos);
                    }
                    break;
                }
                case EVENT_JUMP_TO_LORNA:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* lorna = ObjectAccessor::GetCreature(*me, m_lornaGUID))
                        {
                            lorna->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
                            player->ExitVehicle();
                            lorna->AI()->DoAction(EVENT_TELEPORT_01);
                        }

                    me->DespawnOrUnsummon(100);
                    break;
                }
                }
            }
        }

        void FindLornaGuid()
        {
            if (ObjectAccessor::GetCreature(*me, m_lornaGUID))
                return;

            if (Creature* lorna = me->FindNearestCreature(NPC_LORNA_CRAWLEY_43566, 100.0f))
                m_lornaGUID = lorna->GetGUID();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hippogryph_43751AI(creature);
    }
};

// GO 203428
class go_worgen_gunship_203428 : public GameObjectScript
{
public:
    go_worgen_gunship_203428() : GameObjectScript("go_worgen_gunship_203428") { }

    enum eObject
    {
        EVENT_CHECK_POSITIONS = 201,
    };

    struct go_worgen_gunship_203428AI : public GameObjectAI
    {
        go_worgen_gunship_203428AI(GameObject* gameobject) : GameObjectAI(gameobject) { }

        EventMap m_events;
        ObjectGuid   m_tobiasGUID;
        ObjectGuid   m_playerGUID;
        ObjectGuid   m_triggerGUID;

        void Reset() override
        {
            m_tobiasGUID = ObjectGuid::Empty;
            m_playerGUID = ObjectGuid::Empty;
            m_triggerGUID = ObjectGuid::Empty;
            m_events.RescheduleEvent(EVENT_CHECK_POSITIONS, 2500);
        }

        void EventInform(uint32 eventId) override
        {
            if (Creature* tobias = ObjectAccessor::GetCreature(*go, m_tobiasGUID))
                tobias->AI()->DoAction(eventId);

            if (Creature* trigger = ObjectAccessor::GetCreature(*go, m_triggerGUID))
                trigger->AI()->DoAction(eventId);

            if (eventId == ACTION_EVENT_ID_25727) // ship is on destroy.. we must leave quickly.. or player char is destroyed in database storing..
            {
                WorldLocation wLoc = WorldLocation(654, -1317.54f, 2121.90f, 5.6296f, 0.218f);
                std::list<Player*> pList = go->SelectNearestPlayers(70.0f);
                for (auto player : pList)
                    player->TeleportTo(wLoc);
            }
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
                case NPC_TOBIAS_MISTMANTLE_43749:
                    m_tobiasGUID = guid;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_POSITIONS:
                {
                    if (!m_playerGUID)
                        if (Player* player = go->SelectNearestPlayer(100.0f))
                            m_playerGUID = player->GetGUID();

                    if (!m_triggerGUID)
                        if (Creature* trigger = go->FindNearestCreature(40350, 100.0f))
                            m_triggerGUID = trigger->GetGUID();

                     m_events.ScheduleEvent(EVENT_CHECK_POSITIONS, 2500);
                    break;
                }
                }
            }
        }
    };

    GameObjectAI* GetAI(GameObject* gameobject) const override
    {
        return new go_worgen_gunship_203428AI(gameobject);
    }
};

// 43566
class npc_lorna_crowley_43566 : public CreatureScript
{
public:
    npc_lorna_crowley_43566() : CreatureScript("npc_lorna_crowley_43566") { }

    struct npc_lorna_crowley_43566AI : public ScriptedAI
    {
        npc_lorna_crowley_43566AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        EventMap  m_events;
        ObjectGuid    m_bigOrcGUID;
        ObjectGuid    m_playerGUID;
        bool      m_animStarted;
        uint32    m_wp_point;
        std::list<ObjectGuid> pList;
        std::list<ObjectGuid> wList;

        void Initialize()
        {
            m_bigOrcGUID = ObjectGuid::Empty;
            m_playerGUID = ObjectGuid::Empty;
            m_wp_point = 0;
        }

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            m_animStarted = false;
            me->AddAura(SPELL_FOR_GILNEAS, me);
            SetRopeSelectableFlag(false);
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
                case PLAYER_GUID:
                {
                    m_playerGUID = guid;
                    break;
                }
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
                case EVENT_TELEPORT_01:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (!me->GetTransGUID().IsEmpty())
                        {
                            pList.push_back(player->GetGUID());
                            if (!m_animStarted)
                            {
                                m_animStarted = true;
                                m_events.RescheduleEvent(EVENT_ANIMATION_START, 100);
                            }
                        }
                    break;
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
                switch (m_wp_point)
                {
                    case 1:
                    {
                        if (id == 4)
                            m_events.ScheduleEvent(EVENT_TALK_PART_01, 1000);
                        break;
                    }
                    case 2:
                    {
                        if (id == 10)
                            m_events.ScheduleEvent(EVENT_TALK_PART_04, 1000);
                        break;
                    }
                    case 3:
                    {
                        if (id == 2)
                            m_events.ScheduleEvent(EVENT_TALK_PART_05, 1000);
                        break;
                    }
                    case 4:
                    {
                        if (id == 2)
                            m_events.ScheduleEvent(EVENT_TALK_PART_06, 1000);
                        break;
                    }
                    case 5:
                    {
                        if (id == 2)
                            m_events.ScheduleEvent(EVENT_TALK_PART_07, 1000);
                        break;
                    }
                    case 6:
                    {
                        if (id == 1)
                            m_events.ScheduleEvent(EVENT_TALK_PART_09, 1000);
                        break;
                    }
                    case 7:
                    {
                        if (id == 1)
                            m_events.ScheduleEvent(EVENT_TALK_PART_10, 1000);
                        break;
                    }
                }
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            me->CombatStop(true);
            me->SetReactState(REACT_DEFENSIVE);

            if (me->GetTransport())
                me->SetTransportHomePosition(me->GetTransport()->GetPosition());
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            if (m_animStarted && pList.size())
                for (auto guid : pList)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, guid))
                    {
                        if (me->GetTransport())
                        {
                            Position pos = me->GetTransport()->GetPosition();
                            player->MovePosition(pos, 0, 0);
                        }
                        pList.remove(guid);
                        break;
                    }

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    if (!me->IsInCombat())
                        if (Creature* target = me->FindNearestCreatureOnTransportInFloor(42141, 30.0f, 3.0f))
                        {
                            if (me->GetTransport())
                            {
                                float dist = me->GetTransOffset().GetExactDist2d(&target->GetTransOffset());
                                if (dist < 5.0f)
                                {
                                    me->CastSpell(target, 15496, true);
                                    me->Attack(target, true);
                                }
                                else
                                {
                                    me->CastSpell(target, 31942, true);
                                    m_events.ScheduleEvent(EVENT_CAST_COOLDOWN, 2000);
                                }
                            }
                        }

                    m_events.ScheduleEvent(EVENT_CHECK_ATTACK, urand(1500, 1600));
                    break;
                }
                case EVENT_CAST_COOLDOWN:
                {
                    me->CombatStop(true);
                    break;
                }
                case EVENT_ANIMATION_START:
                {
                    Talk(2);
                    m_events.RescheduleEvent(EVENT_FLOOR_IS_ONE_REMAIN, 3000);
                    break;
                }
                case EVENT_FLOOR_IS_ONE_REMAIN:
                {
                    uint32 count = CountGruntOnThisFloorZ(86.0f, 15.0f);
                    if (count < 2)
                    {
                        Talk(3);
                        m_events.ScheduleEvent(EVENT_FLOOR_IS_CLEAN, 5000);
                    }
                    else
                        m_events.ScheduleEvent(EVENT_FLOOR_IS_ONE_REMAIN, 1000);

                    break;
                }
                case EVENT_FLOOR_IS_CLEAN:
                {
                    uint32 count = CountGruntOnThisFloorZ(86.0f, 15.0f);
                    if (!count)
                    {
                        Talk(4);
                        m_events.ScheduleEvent(EVENT_START_ROPE_PART, 7000);
                    }
                    else
                        m_events.ScheduleEvent(EVENT_FLOOR_IS_CLEAN, 1000);
                    break;
                }
                case EVENT_START_ROPE_PART:
                {
                    SetRopeSelectableFlag(true);
                    std::vector<Creature*> friendsList = FindFriendlyCreatureList();
                    std::vector<Creature*> jumpTargetList = FindJumpTargetPositions(34.0f);
                    for (auto source : friendsList)
                        if (Creature* target = FindBestJumpTarget(source, 34.0f, jumpTargetList))
                        {
                            source->SetTransportHomePosition(target->GetTransOffset());
                            source->JumpTo(target, 0.4f);
                        }

                    m_events.ScheduleEvent(EVENT_WAIT_TO_MOVE, 8000);
                    break;
                }
                case EVENT_WAIT_TO_MOVE:
                {
                    uint32 count = CountGruntOnThisFloorZ(34.0f, 3.0f);
                    if (count)
                    {
                        m_events.ScheduleEvent(EVENT_WAIT_TO_MOVE, 1000);
                        break;
                    }

                    if (IsPlayerInRange(15.0f))
                        m_events.ScheduleEvent(EVENT_TALK_PART_00, 1000); // EVENT_MOVE_ATTACK
                    else
                        m_events.ScheduleEvent(EVENT_WAIT_TO_MOVE, 1000);
                    break;
                }
                case EVENT_TALK_PART_00: // lorna goes to captain and talk..
                {
                    m_wp_point = 1;
                    me->GetMotionMaster()->MovePath(4356601, false);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    Talk(6);
                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 10000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    Talk(7);
                    m_events.ScheduleEvent(EVENT_TALK_PART_03, 2000);
                    break;
                }
                case EVENT_TALK_PART_03: // walk downstair, to first grunt there
                {
                    if (IsPlayerInRange(50.0f))
                    {
                        m_wp_point = 2;
                        me->GetMotionMaster()->MovePath(4356602, false);
                    }
                    else
                        m_events.ScheduleEvent(EVENT_TALK_PART_03, 1000);
                    break;
                }
                case EVENT_TALK_PART_04: // fight to grunt on stair
                {
                    if (me->IsInCombat() || IsPlayerInCombat())
                        m_events.ScheduleEvent(EVENT_TALK_PART_04, 1000); // repeat 04 while grunt near or self in combat
                    else
                    {
                        if (IsPlayerInRange(15.0f))
                        {
                            m_wp_point = 3;
                            me->GetMotionMaster()->MovePath(4356603, false); // else walk to next position, grunt outsite floor
                        }
                        else
                            m_events.ScheduleEvent(EVENT_TALK_PART_04, 1000);
                    }
                    break;
                }
                case EVENT_TALK_PART_05: // fight to gunt outside stair
                {
                    if (me->IsInCombat() || IsPlayerInCombat())
                        m_events.ScheduleEvent(EVENT_TALK_PART_05, 1000); // repeat 05 while grunt near or self in combat
                    else
                    {
                        if (IsPlayerInRange(15.0f))
                        {
                            m_wp_point = 4;
                            me->GetMotionMaster()->MovePath(4356604, false); // else walk to middle of ship..
                        }
                        else
                            m_events.ScheduleEvent(EVENT_TALK_PART_05, 1000);
                    }
                    break;
                }
                case EVENT_TALK_PART_06: // fight to gunt inside ship
                {
                    if (me->IsInCombat() || IsPlayerInCombat())
                        m_events.ScheduleEvent(EVENT_TALK_PART_06, 1000); // repeat 06 while grunt near or self in combat
                    else
                    {
                        if (IsPlayerInRange(15.0f))
                        {
                            m_wp_point = 5;
                            me->GetMotionMaster()->MovePath(4356605, false); // else walk to machine room..
                        }
                        else
                            m_events.ScheduleEvent(EVENT_TALK_PART_06, 1000);
                    }
                    break;
                }
                case EVENT_TALK_PART_07: // fight inside machine room
                {
                    if (me->IsInCombat() || IsPlayerInCombat() || !IsPlayerInRange(20.0f))
                    {
                        m_events.ScheduleEvent(EVENT_TALK_PART_07, 1000); // repeat 06 while grunt near or self in combat
                    }
                    else
                        m_events.ScheduleEvent(EVENT_TALK_PART_08, 1000);
                    break;
                }
                case EVENT_TALK_PART_08: // the machine room is clean..
                {
                    m_wp_point = 6;
                    me->GetMotionMaster()->MovePath(4356606, false); // we go to spawn gunpowder position..
                    break;
                }
                case EVENT_TALK_PART_09: // spawn 3 gunpowder's
                {
                    if (Transport* trans = me->GetTransport())
                    {
                        if (ObjectGuid::LowType guid = me->GetMap()->GenerateLowGuid<HighGuid::GameObject>())
                        {
                            GameObjectData& data = sObjectMgr->NewGOData(guid);
                            data.id = 204458;
                            data.posX = 53.6417f;
                            data.posY = -0.00663333f;
                            data.posZ = 10.4467f;
                            data.orientation = 2.010638f;
                            GameObject* go = trans->CreateGOPassenger(guid, &data);
                            go->SetObjectScale(2.0f);
                            sObjectMgr->AddGameobjectToGrid(guid, &data);
                        }
                        if (ObjectGuid::LowType guid = me->GetMap()->GenerateLowGuid<HighGuid::GameObject>())
                        {
                            GameObjectData& data = sObjectMgr->NewGOData(guid);
                            data.id = 204458;
                            data.posX = 53.6808f;
                            data.posY = -2.18513f;
                            data.posZ = 10.4467f;
                            data.orientation = 2.010638f;
                            GameObject* go = trans->CreateGOPassenger(guid, &data);
                            go->SetObjectScale(2.0f);
                            sObjectMgr->AddGameobjectToGrid(guid, &data);
                        }
                        //
                        if (ObjectGuid::LowType guid = me->GetMap()->GenerateLowGuid<HighGuid::GameObject>())
                        {
                            GameObjectData& data = sObjectMgr->NewGOData(guid);
                            data.id = 204458;
                            data.posX = 53.1084f;
                            data.posY = 2.12947f;
                            data.posZ = 10.4467f;
                            data.orientation = 2.010638f;
                            GameObject* go = trans->CreateGOPassenger(guid, &data);
                            go->SetObjectScale(2.0f);
                            sObjectMgr->AddGameobjectToGrid(guid, &data);
                        }
                    }
                    Talk(5);
                    m_wp_point = 7;
                    me->GetMotionMaster()->MovePath(4356607, false); // go back to door.. and wait for orc..
                    m_events.ScheduleEvent(EVENT_SPAWN_OBJECT, 200);
                    break;
                }
                case EVENT_SPAWN_OBJECT: // spawn orc and let him walk to us..
                {
                    if (Transport* trans = me->GetTransport())
                        if (ObjectGuid::LowType guid = me->GetMap()->GenerateLowGuid<HighGuid::Creature>())
                        {
                            CreatureData& data = sObjectMgr->NewOrExistCreatureData(guid);
                            data.id = 43567;
                            data.posX = -47.758198f;
                            data.posY = -11.800224f;
                            data.posZ = 13.089049f;
                            data.orientation = 0.549271f;
                            Creature* npc = trans->CreateNPCPassenger(guid, &data);
                            sObjectMgr->AddCreatureToGrid(guid, &data);
                            m_bigOrcGUID = npc->GetGUID();
                        }
                    m_events.ScheduleEvent(EVENT_MOVE_PART2, 200);
                    break;
                }
                case EVENT_MOVE_PART2:
                {
                    if (Creature* orc = ObjectAccessor::GetCreature(*me, m_bigOrcGUID))
                    {
                        orc->SetSpeed(MOVE_WALK, 1.4f);
                        orc->GetMotionMaster()->MovePath(4356701, false);
                    }
                    break;
                }
                case EVENT_TALK_PART_10: // finish talk on door position
                {
                    Talk(8); // What a big orc
                    m_events.ScheduleEvent(EVENT_WAIT_FOR_ACTION_00, 4000);
                    break;
                }
                case EVENT_WAIT_FOR_ACTION_00: // wait that orc comes near..
                {
                    if (Creature* orc = ObjectAccessor::GetCreature(*me, m_bigOrcGUID))
                    {
                        Position posA = me->GetTransOffset();
                        Position posB = orc->GetTransOffset();
                        if (posA.GetExactDist(&posB) < 15.0f)
                            m_events.ScheduleEvent(EVENT_TALK_PART_11, 1000);
                        else
                            m_events.ScheduleEvent(EVENT_WAIT_FOR_ACTION_00, 1000);
                    }
                    break;
                }
                case EVENT_TALK_PART_11: // and fight
                {
                    Creature* orc = me->FindNearestCreature(43567, 40.0f);
                    if (orc)
                    {
                        if (me->GetDistance(orc) > 5.0)
                            me->CastSpell(orc, 50092, true);
                        else
                        {
                            me->CastSpell(orc, 15496, true);
                            orc->Attack(me, true);
                        }
                    }

                    if (orc)
                        m_events.ScheduleEvent(EVENT_TALK_PART_11, urand(1100, 1300)); // repeat 11 while orc living
                    else
                        m_events.ScheduleEvent(EVENT_TALK_PART_12, 1000);
                    break;
                }
                case EVENT_TALK_PART_12: // big orc is death..
                {
                    me->PlayDirectSound(23498);
                    m_events.ScheduleEvent(EVENT_TALK_PART_13, 4000);
                    break;
                }
                case EVENT_TALK_PART_13: //
                {
                    Talk(9);
                    m_events.ScheduleEvent(EVENT_TALK_PART_14, 2000);
                    break;
                }
                // the spell 81780 should now start next: visual fleeing from the gunship with new spawned whyvern..
                // but the triggered spell 95869 is visual damaged.. missing additional phase aura??
                case EVENT_TALK_PART_14: //
                {
                    wList.clear();
                    std::list<Player*> pList = me->SelectNearestPlayers(100.0f);
                    for (auto player : pList)
                    {
                        if (Transport* trans = me->GetTransport())
                            if (ObjectGuid::LowType guid = me->GetMap()->GenerateLowGuid<HighGuid::GameObject>())
                            {
                                CreatureData& data = sObjectMgr->NewOrExistCreatureData(guid);
                                data.id = 43713;
                                data.posX = player->GetTransOffset().GetPositionX();
                                data.posY = player->GetTransOffset().GetPositionY();
                                data.posZ = player->GetTransOffset().GetPositionZ();
                                data.orientation = player->GetTransOffset().GetOrientation();
                                Creature* npc = trans->CreateNPCPassenger(guid, &data);
                                sObjectMgr->AddCreatureToGrid(guid, &data);
                                npc->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
                                wList.push_back(npc->GetGUID());
                            }
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_15, 200);
                    break;
                }
                case EVENT_TALK_PART_15:
                {
                    for (auto guid : wList)
                        if (Creature* wyvern = ObjectAccessor::GetCreature(*me, guid))
                        {
                            guid = wyvern->AI()->GetGUID(PLAYER_GUID);
                            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                                player->EnterVehicle(wyvern, 0);
                        }

                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

 // ############################

        Creature* FindBestJumpTarget(Creature* source, float floorZ, std::vector<Creature*> tList)
        {
            Position posS = source->GetTransOffset();
            float dist = 100.0f;
            Creature* rTarget = nullptr;
            for (auto target : tList)
            {
                Position posT = target->GetTransOffset();
                if (fabs(posT.GetPositionZ() - floorZ) < 4.0f)
                {
                    float d1 = posS.GetExactDist2d(&posT);
                    if (d1 < dist)
                    {
                        dist = d1;
                        rTarget = target;
                    }
                }
            }
            return rTarget;
        }

        void SetGruntReactStateOnThisFloor(float floorZ, float range, ReactStates react)
        {
            std::list<Creature*> cList = me->FindNearestCreatures(NPC_GUNSHIP_GRUNT, range);
            for (auto grunt : cList)
                if (grunt->IsAlive())
                    if (fabs(grunt->GetTransOffset().GetPositionZ() - floorZ) < 3.0f)
                        grunt->SetReactState(react);
        }

        Creature* FindTargetOnThisFloor(Creature* source, float range)
        {
            std::list<Creature*> cList = me->FindNearestCreatures(NPC_GUNSHIP_GRUNT, range);
            for (auto grunt : cList)
                if (grunt->IsAlive())
                    if (fabs(source->GetTransOffset().GetPositionZ() - grunt->GetTransOffset().GetPositionZ()) < 3.0f)
                    {
                        return grunt;
                    }
            return nullptr;
        }

        bool IsPlayerInCombat()
        {
            std::list<Player*> pList = me->SelectNearestPlayers(20.0f);
            for (auto player : pList)
                if (player->IsInCombat())
                    return true;

            return false;
        }

        bool IsPlayerInRange(float range)
        {
            Player* player = me->SelectNearestPlayer(range);
            return player ? true : false;
        }

        bool isInSameTranportFloor(Creature* creature)
        {
            float diff = fabs(me->GetTransOffset().GetPositionZ() - creature->GetTransOffset().GetPositionZ());
            return (diff < 5.0f) ? true : false;
        }

        uint32 CountGruntOnThisFloorZ(float posZ, float rangeZ)
        {
            uint32 count = 0;
            std::list<Unit*>m_targetList;
            me->GetAttackableUnitListInRange(m_targetList, 75.0f); // returns only alive
            for (std::list<Unit*>::iterator itr = m_targetList.begin(); itr != m_targetList.end(); ++itr)
            {
                Position pos = (*itr)->GetTransOffset();
                if (fabs(pos.GetPositionZ() - posZ) < rangeZ)
                    count += 1;
            }

            return count;
        }

        void SetRopeSelectableFlag(bool value)
        {
            std::list<GameObject*> goList = me->FindNearestGameObjects(GO_ROPE, 30.0f); // there are 2 rope on bridge
            for (std::list<GameObject*>::const_iterator itr = goList.begin(); itr != goList.end(); ++itr)
            {
                if (value)
                    (*itr)->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                else
                    (*itr)->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }
        }

        std::vector<Creature*> FindFriendlyCreatureList()
        {
            std::vector<Creature*> rList;
            std::list<Creature*> tList = me->FindAllCreaturesInRange(18.0f);
            for (std::list<Creature*>::iterator itr = tList.begin(); itr != tList.end(); ++itr)
                if (Creature* target = (*itr))
                    if (isInSameTranportFloor(target) && target->IsAlive())
                        rList.push_back(target);

            return rList;
        }

        std::vector<Creature*> FindJumpTargetPositions(float floorZ)
        {
            std::vector<Creature*> rList;
            std::list<Creature*> tList = me->FindNearestCreatures(NPC_GILNEAS_VEHICLE_ROPE, 75.0f);
            for (std::list<Creature*>::iterator itr = tList.begin(); itr != tList.end(); ++itr)
            {
                float diff = fabs((*itr)->GetTransOffset().GetPositionZ() - floorZ);
                if (diff < 5.0f)
                    rList.push_back((*itr));
            }
            return rList;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lorna_crowley_43566AI(creature);
    }
};

// 43651
class npc_worgen_warrior_43651 : public CreatureScript
{
public:
    npc_worgen_warrior_43651() : CreatureScript("npc_worgen_warrior_43651") { }

    struct npc_worgen_warrior_43651AI : public ScriptedAI
    {
        npc_worgen_warrior_43651AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        EventMap  m_events;

        void Initialize() { }

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1200);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->GetMotionMaster()->MoveIdle();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            me->CombatStop(true);
            me->SetTransportHomePosition(me->GetTransOffset());
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    if (!me->IsInCombat())
                        if (Creature* target = me->FindNearestAttackableCreatureOnTransportInFloor(5, 3))
                        {
                            me->GetMotionMaster()->MoveIdle();
                            me->Attack(target, true);
                        }

                    m_events.ScheduleEvent(EVENT_CHECK_ATTACK, urand(900, 1200));
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_worgen_warrior_43651AI(creature);
    }
};

// 43703
class npc_gilnean_sharpshooter_43703 : public CreatureScript
{
public:
    npc_gilnean_sharpshooter_43703() : CreatureScript("npc_gilnean_sharpshooter_43703") { }

    struct npc_gilnean_sharpshooter_43703AI : public ScriptedAI
    {
        npc_gilnean_sharpshooter_43703AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_oldTargetGuid;
        uint32      m_count;

        void Reset() override
        {
            m_oldTargetGuid = ObjectGuid::Empty;
            m_count = 0;
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1000);
            me->SetReactState(REACT_DEFENSIVE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            me->CombatStop(false);
            if (me->GetTransOffset().GetPositionZ() < 50.0f)
                me->SetTransportHomePosition(me->GetTransOffset());
            else
                me->GetMotionMaster()->MoveTargetedHome();
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    if (!me->IsInCombat())
                    {
                        if (Creature* target = me->FindNearestAttackableCreatureOnTransportInFloor(35, 10))
                        {
                            if (me->GetTransOffset().GetExactDist2d(&target->GetTransOffset()) < 5.0f)
                            {
                                me->GetMotionMaster()->MoveIdle();
                                me->Attack(target, true);
                            }
                            else
                            {
                                Position p = target->GetTransOffset();
                                if (me->IsWithinLOS(p.m_positionX, p.m_positionY, p.m_positionZ))
                                    break;
                                me->CastSpell(target, 50092, true);
                                AttackStartNoMove(target);
                                m_events.ScheduleEvent(EVENT_CAST_COOLDOWN, 2000);
                                /* this is a workaround: sometimes the core make failure in attack.. on attack the core only report 'escape' and none can kill this target..*/
                                bool isEvade = target->HasUnitState(UNIT_STATE_EVADE);
                                if (m_oldTargetGuid == target->GetGUID() && isEvade)
                                {
                                    m_count += 1;
                                    if (m_count > 5)
                                        target->ClearUnitState(UNIT_STATE_EVADE);
                                }
                                else
                                {
                                    m_count = 0;
                                    m_oldTargetGuid = target->GetGUID();
                                }
                            }
                        }
                    }

                    m_events.RescheduleEvent(EVENT_CHECK_ATTACK, urand(1000, 1100));
                    break;
                }
                case EVENT_CAST_COOLDOWN:
                {
                    me->CombatStop(true);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gilnean_sharpshooter_43703AI(creature);
    }
};

// 42141
class npc_gunship_grunt_42141 : public CreatureScript
{
public:
    npc_gunship_grunt_42141() : CreatureScript("npc_gunship_grunt_42141") { }

    struct npc_gunship_grunt_42141AI : public ScriptedAI
    {
        npc_gunship_grunt_42141AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        ObjectGuid   m_playerGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            me->SetReactState(REACT_DEFENSIVE);
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (!m_playerGUID.IsEmpty())
            {
                //damage *= 2;
            }
            else
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    if (!me->IsInCombat())
                    {
                        if (Creature* target = me->FindNearestAttackableCreatureOnTransportInFloor(5.0f, 3.0f))
                            me->Attack(target, true);
                    }

                    if (!m_playerGUID)
                        if (Player* player = me->SelectNearestPlayer(75.0f))
                            m_playerGUID = player->GetGUID();

                    m_events.RescheduleEvent(EVENT_CHECK_ATTACK, urand(1000, 1100));
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_gunship_grunt_42141AI(creature);
    }
};

// GO 204428
class go_rope_204428 : public GameObjectScript
{
public:
    go_rope_204428() : GameObjectScript("go_rope_204428") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (Creature* target = FindRandomJumpTargetPosition(player))
            player->JumpTo(target, 0.4f);

        return true;
    }

    Creature* FindRandomJumpTargetPosition(Player* player)
    {
        float zHeight = player->GetPositionZ() - 10.0f;
        std::vector<Creature*> rList;
        std::list<Creature*> tList = player->FindNearestCreatures(NPC_GILNEAS_VEHICLE_ROPE, 50.0f);
        for (std::list<Creature*>::iterator itr = tList.begin(); itr != tList.end(); ++itr)
            if (Creature* target = (*itr))
                if (target->GetPositionZ() < zHeight)
                    rList.push_back(target);

        return (!rList.empty()) ? rList[urand(0, rList.size() - 1)] : nullptr;
    }
};

// 43713
class npc_wyvern_43713 : public CreatureScript
{
public:
    npc_wyvern_43713() : CreatureScript("npc_wyvern_43713") { }

    struct npc_wyvern_43713AI : public ScriptedAI
    {
        npc_wyvern_43713AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap m_events;
        ObjectGuid   m_playerGUID;
        uint32   m_flyPart;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_flyPart = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (m_flyPart == 1 && type == WAYPOINT_MOTION_TYPE && id == 2)
                m_events.ScheduleEvent(EVENT_MOVE_PART1, 200);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (who->IsPlayer())
            {
                if (apply)
                    m_events.ScheduleEvent(EVENT_MOVEMENT_START, 200);
                else
                    m_events.ScheduleEvent(EVENT_MOVE_PART2, 200);
            }
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
                case PLAYER_GUID:
                {
                    m_playerGUID = guid;
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVEMENT_START:
                {
                    m_flyPart = 1;
                    me->GetMotionMaster()->MovePath(4371301, false);                    // fly to the open ship gate..
                    break;
                }
                case EVENT_MOVE_PART1:
                {
                    if (ObjectAccessor::GetPlayer(*me, m_playerGUID)) // now we are outside the ship
                        if (Vehicle* wyv = me->GetVehicleKit())
                            wyv->RemoveAllPassengers();                                 // and leave the wyvern

                    break;
                }
                case EVENT_MOVE_PART2:
                {
                    m_flyPart = 2;
                    WorldLocation wLoc = WorldLocation(654, -1317.54f, 2121.90f, 5.6296f, 0.218f); // last we teleport to questtaker..
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        player->KilledMonsterCredit(43729);
                        player->TeleportTo(wLoc);
                    }
                    me->DespawnOrUnsummon(200);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wyvern_43713AI(creature);
    }
};

// 43727
class npc_lorna_crowley_43727 : public CreatureScript
{
public:
    npc_lorna_crowley_43727() : CreatureScript("npc_lorna_crowley_43727") { }

    bool OnQuestReward(Player* /*player*/, Creature* creature, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_ENDGAME)
        {
            creature->AI()->Talk(0);
        }
        return true;
    }
};

// 36616
class npc_admiral_nightwind_36616 : public CreatureScript
{
public:
    npc_admiral_nightwind_36616() : CreatureScript("npc_admiral_nightwind_36616") { }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_RUTTHERAN)
        {
            player->RemoveAllAuras();
            player->TeleportTo(1, 8343, 801, 4, 4.19f);
        }
        return true;
    }
};

void AddSC_zone_gilneas_city3()
{
    new npc_tobias_mistmantle_38507();
    new npc_lady_sylvanas_windrunner_38530();
    new npc_captured_riding_bat_38540();
    new spell_fly_back_72849();
    new spell_iron_bomb_72247();
    new npc_tobias_mistmantle_43749();
    new npc_hippogryph_43751();
    new go_worgen_gunship_203428();
    new npc_lorna_crowley_43566();
    new npc_worgen_warrior_43651();
    new npc_gilnean_sharpshooter_43703();
    new npc_gunship_grunt_42141();
    new go_rope_204428();
    new npc_wyvern_43713();
    new npc_lorna_crowley_43727();
    new npc_admiral_nightwind_36616();
}

