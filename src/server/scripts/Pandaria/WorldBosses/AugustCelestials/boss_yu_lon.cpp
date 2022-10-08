/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

#define INITIAL_HEALTH_POINTS 92300000
#define MAX_HEALTH_POINTS 371000000
#define INCREMENTAL 3000000
#define WALLS_MAX 6
#define WALLS_Y_M 145

enum eSpells
{
    SPELL_JADEFIRE_BREATH      = 144530,
    SPELL_JADEFIRE_BUFFET      = 144630,
    SPELL_JADEFIRE_WALL_VISUAL = 144533,
    SPELL_JADEFIRE_WALL_DMG    = 144539,
    SPELL_JADEFIRE_BLAZE_BOLT  = 144532
};

enum eEvents
{
    EVENT_TIMER_HEALTH_POOL = 1,
    EVENT_TIMER_JADE_BREATH,
    EVENT_TIMER_JADEFIRE_WALL,
    EVENT_TIMER_JADEFIRE_BOLT,
    EVENT_TIMER_JADEFIRE_BUFFET,
    EVENT_TIMER_SHAO_DO_INTRO,
    EVENT_TIMER_SHAO_DO_INTRO_ATTACKABLE,
    EVENT_TIMER_SHAO_DO_OUTRO,
    EVENT_TIMER_DEATH
};

enum eCreatures
{
    MOB_JADEFIRE_WALL   = 72020,
    MOB_JADEFIRE_BLAZE  = 72016
};

enum eSays
{
    SAY_AGGRO = 0,
    SAY_INTRO = 1,
    SAY_DEATH = 2,
    SAY_KILL = 3,
    SAY_WALL = 4,
    SAY_WALL_2 = 5,
    SAY_WALL_3 = 6,
    SAY_WALL_ANN = 7
};

enum eActions
{
    ACTION_JADEFIRE_WALL = 1,
    ACTION_JADEFIRE_BLAZE = 2
};

enum wallEvent
{
    WALL_EVENT_TIMER_DESPAWN = 1,
    WALL_EVENT_TIMER_GO,
    WALL_EVENT_TIMER_DAMAGE
};

enum wallAction
{
    WALL_ACTION_GO = 1,
    WALL_ACTION_RETURN
};

enum wallMovement
{
    WALL_MOVEMENT_FORWARD = 1
};

enum Factions
{
    FACTION_FRIENDLY = 35,
    FACTION_HOSTILE_NEUTRAL = 31
};

#define MIDDLE_FACING_ANGLE 1.573f

enum Datas
{
    DATA_YU_LON = 0,
};

enum Bosses
{
    BOSS_CHI_JI = 71952,
    BOSS_NIUZAO = 71954,
    BOSS_YU_LON = 71955,
    BOSS_XUEN = 71953,
    BOSS_ORDOS = 72057
};

#define CELESTIAL_COURT_BOSS_INTRO_TIMER_1 1000
#define CELESTIAL_COURT_BOSS_INTRO_TIMER_2 15000

static Position _timelessIsleMiddle = { -650.04f, -5016.84f, -6.27f, 1.573f };

enum EmperorActions
{
    ACTION_XUEN = 1,
    ACTION_CHIJI = 2,
    ACTION_NIUZAO = 3,
    ACTION_YULON = 4,
    ACTION_MOVE_TO_MIDDLE = 100
};

enum EmprerorTalk
{
    EMPEROR_TALK_INTRO_YULON,
    EMPEROR_TALK_INTRO_XUEN,
    EMPEROR_TALK_INTRO_CHIJI,
    EMPEROR_TALK_INTRO_NIUZAO,
    EMPEROR_TALK_OUTRO_YULON,
    EMPEROR_TALK_OUTRO_XUEN,
    EMPEROR_TALK_OUTRO_CHIJI,
    EMPEROR_TALK_OUTRO_NIUZAO,
    EMPEROR_TALK_INTRO
};

enum Creatures
{
    NPC_SKUNKY_ALEMENTAL = 71908,
    NPC_EMPEROR_SHAOHAO_TI = 73303,
    NPC_ETERNAL_KILNMASTER = 72896,
    NPC_HIGH_PRIEST_OF_ORDOS = 72898,
    NPC_BLAZEBOUND_CHANTER = 72897,

    // Generic (Invisible)
    NPC_TIME_LOST_SHRINE_TRIGGER = 73461 // I think this is the correct ID :P
};

Position wallStartPos = { -561.17f, -5091.70f, -6.277f, MIDDLE_FACING_ANGLE };

class PlayerCheck
{
public:
    bool operator()(Unit* target) const
    {
        return !target->ToPlayer();
    }
};

class boss_yu_lon : public CreatureScript
{
    public:
        boss_yu_lon() : CreatureScript("boss_yu_lon") { }

        struct boss_yu_lonAI : public BossAI
        {
            boss_yu_lonAI(Creature* creature) : BossAI(creature, DATA_YU_LON) { }

            void Reset()
            {
                events.Reset();
                _Reset();

                for (auto itr : _wallList)
                    itr->AI()->DoAction(WALL_ACTION_RETURN);

                if (me->getFaction() == FACTION_HOSTILE_NEUTRAL)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetFacingTo(MIDDLE_FACING_ANGLE);
                }

                summons.DespawnAll();
                me->SetWalk(true);
                me->setActive(true);
            }

            void EnterCombat(Unit* /*target*/)
            {
                death = false;
                me->SetWalk(false);
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_TIMER_HEALTH_POOL, 10000);
                events.ScheduleEvent(EVENT_TIMER_JADE_BREATH, 6000);
                events.ScheduleEvent(EVENT_TIMER_JADEFIRE_WALL, 40000);
                events.ScheduleEvent(EVENT_TIMER_JADEFIRE_BOLT, 15000);
                events.ScheduleEvent(EVENT_TIMER_JADEFIRE_BUFFET, 30000);
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (point == 1)
                {
                    events.ScheduleEvent(EVENT_TIMER_SHAO_DO_INTRO, CELESTIAL_COURT_BOSS_INTRO_TIMER_1);
                    me->SetFacingTo(MIDDLE_FACING_ANGLE);
                    me->setFaction(FACTION_HOSTILE_NEUTRAL);
                    me->GetCreatureListWithEntryInGrid(_wallList, MOB_JADEFIRE_WALL, 250.0f);
                    me->SetHomePosition(_timelessIsleMiddle);
                }
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
                        return;
            }

            void UpdateHealth()
            {
                if (!me->isInCombat())
                    return;

                // Get the Threat List
                std::list<HostileReference*> threatlist = me->getThreatManager().getThreatList();
                if (threatlist.empty()) // He doesn't have anyone in his threatlist, useless to continue
                    return;

                uint8 count = 0;
                for (auto itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                    if (Unit* unit = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                        if (unit->IsWithinDist(me, 100.0f))
                            count++;

                uint32 hp = me->GetMaxHealth() - me->GetHealth();
                uint32 newhp = std::min<uint32>((INCREMENTAL * count), MAX_HEALTH_POINTS);
                if (newhp != me->GetMaxHealth() && newhp > INITIAL_HEALTH_POINTS)
                {
                    me->SetMaxHealth(std::min<uint32>((me->GetMaxHealth() * count), MAX_HEALTH_POINTS));
                    me->SetHealth(newhp - hp);
                }
            }; 

            void DoAction(const int32 id)
            {
                switch (id)
                {
                    case ACTION_JADEFIRE_WALL:
                    {
                        uint8 _random = urand(0, WALLS_MAX-1);
                        uint8 _count = 0;
                        for (auto wall : _wallList)
                        {
                            wall->SetFacingTo(MIDDLE_FACING_ANGLE);
                            if (_count != _random)
                                wall->AddAura(SPELL_JADEFIRE_WALL_VISUAL, wall);

                            wall->AI()->DoAction(WALL_ACTION_GO);
                            _count++;
                        }

                        Talk(urand(SAY_WALL, SAY_WALL_3));
                        break;
                    }
                    case ACTION_JADEFIRE_BLAZE:
                    {
                        std::list<Unit*> _targets;
                        me->GetAttackableUnitListInRange(_targets, 50.0f);
                        _targets.remove_if(PlayerCheck());

                        if (!_targets.empty())
                            if (auto target = MoPCore::Containers::SelectRandomContainerElement(_targets))
                                if (target->GetTypeId() == TYPEID_PLAYER)
                                    me->CastSpell(target, SPELL_JADEFIRE_BLAZE_BOLT, true);
                        break;
                    }
                    default: break;
                }
            };

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIMER_SHAO_DO_INTRO:
                        {
                            Talk(SAY_INTRO);
                            events.ScheduleEvent(EVENT_TIMER_SHAO_DO_INTRO_ATTACKABLE, CELESTIAL_COURT_BOSS_INTRO_TIMER_2);
                            break;
                        }
                        case EVENT_TIMER_SHAO_DO_INTRO_ATTACKABLE:
                        {
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            me->SetMaxHealth(INITIAL_HEALTH_POINTS);
                            break;
                        }
                        case EVENT_TIMER_JADEFIRE_BUFFET:
                        {
                            DoCastToAllHostilePlayers(SPELL_JADEFIRE_BUFFET);
                            events.ScheduleEvent(EVENT_TIMER_JADEFIRE_BUFFET, 30000);
                            break;
                        }
                        case EVENT_TIMER_JADEFIRE_BOLT:
                        {
                            if (me->HasUnitState(UNIT_STATE_CASTING))
                            {
                                events.ScheduleEvent(EVENT_TIMER_JADEFIRE_BOLT, 1500);
                                return;
                            }

                            DoAction(ACTION_JADEFIRE_BLAZE);
                            events.ScheduleEvent(EVENT_TIMER_JADEFIRE_BOLT, 15000);
                            break;
                        }
                        case EVENT_TIMER_JADEFIRE_WALL:
                        {
                            DoAction(ACTION_JADEFIRE_WALL);
                            events.ScheduleEvent(EVENT_TIMER_JADEFIRE_WALL, 60000);
                            break;
                        }
                        case EVENT_TIMER_JADE_BREATH:
                        {
                            if (me->HasUnitState(UNIT_STATE_CASTING))
                                return;

                            DoCast(SPELL_JADEFIRE_BREATH);
                            events.ScheduleEvent(EVENT_TIMER_JADE_BREATH, 10000);
                            break;
                        }
                        case EVENT_TIMER_SHAO_DO_OUTRO:
                        {
                            if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                                shao->AI()->Talk(EMPEROR_TALK_OUTRO_CHIJI);
                            break;
                        }
                        case EVENT_TIMER_DEATH:
                        {
                            if (death)
                            {
                                if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                                    shao->AI()->DoAction(ACTION_XUEN);

                                me->DisappearAndDie();
                                death = false;
                            }
                            break;
                        }
                        case EVENT_TIMER_HEALTH_POOL:
                        {
                            UpdateHealth();
                            events.ScheduleEvent(EVENT_TIMER_HEALTH_POOL, 10000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                if (!death)
                {
                    if (!UpdateVictim())
                        return;
                }

                DoMeleeAttackIfReady();
            }

            private:
                bool death = false;
                EventMap events;
                std::list<Creature*> _wallList;
        };


        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_yu_lonAI(creature);
        }
};

// Jadefire Wall
class mob_jadefire_wall : public CreatureScript
{
    public:
        mob_jadefire_wall() : CreatureScript("mob_jadefire_wall") { }

        struct mob_jadefire_wallAI : public ScriptedAI
        {
            mob_jadefire_wallAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->setActive(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
            }

            void EnterCombat(Unit* target)
            {
            }

            void EnterEvadeMode()
            {
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (point == WALL_MOVEMENT_FORWARD)
                    DoAction(WALL_ACTION_RETURN);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case WALL_ACTION_GO:
                    {
                        events.ScheduleEvent(WALL_EVENT_TIMER_GO, 1500);
                        break;
                    }
                    case WALL_ACTION_RETURN:
                    {
                        events.ScheduleEvent(WALL_EVENT_TIMER_DESPAWN, 5000);
                        hitPlayers.clear();
                        me->RemoveAura(SPELL_JADEFIRE_WALL_VISUAL);
                        shouldTele = true;
                        break;
                    }
                    default:
                        break;
                };
            };

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                switch (events.ExecuteEvent())
                {
                    case WALL_EVENT_TIMER_GO:
                    {
                        me->GetMotionMaster()->MovePoint(WALL_MOVEMENT_FORWARD, me->GetPositionX(), me->GetPositionY() + WALLS_Y_M, me->GetPositionZ());
                        events.ScheduleEvent(WALL_EVENT_TIMER_DAMAGE, 500);
                        break;
                    }
                    case WALL_EVENT_TIMER_DESPAWN:
                    {
                        if (!shouldTele)
                            return;

                        //me->Respawn();
                        Position home = me->GetHomePosition();
                        me->NearTeleportTo(home.GetPositionX(), home.GetPositionY(), home.GetPositionZ(), home.GetOrientation());
                        shouldTele = false;
                        break;
                    }
                    case WALL_EVENT_TIMER_DAMAGE:
                    {
                        if (!me->HasAura(SPELL_JADEFIRE_WALL_VISUAL))
                            return;

                        std::list<Player*> plrs;
                        me->GetPlayerListInGrid(plrs, 15.0f);
                        for (auto plr : hitPlayers)
                            plrs.remove(plr);

                        for (auto plr : plrs)
                        {
                            if (!plr->isInFront(me))
                                continue;

                            plr->CastSpell(plr, SPELL_JADEFIRE_WALL_DMG, true, NULL, NULL, me->GetGUID());
                            hitPlayers.push_back(plr);
                        }

                        events.ScheduleEvent(WALL_EVENT_TIMER_DAMAGE, 500);
                    }
                    default: break;
                }
            }

            private:
                bool shouldTele = false;
                EventMap events;
                std::list<Player*> hitPlayers;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_jadefire_wallAI(creature);
        }
};

void AddSC_boss_yu_lon()
{
    new mob_jadefire_wall();
    new boss_yu_lon();
}
