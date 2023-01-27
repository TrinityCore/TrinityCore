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
#include "SpellScript.h"
#include "ObjectMgr.h"
#include "MapManager.h"

#define MAX_HEALTH_POINTS 349000000
#define INITIAL_HEALTH_POINTS 87250000
#define INCREMENTAL 2800000

enum Spells
{
	SPELL_FIRESTORM					= 144461,
	SPELL_INSPIRING_SONG			= 144468,
	SPELL_BEACON_OF_HOPE			= 144473,
	SPELL_BLAZING_SONG				= 144471,
	SPELL_CRANE_RUSH				= 144470,
	SPELL_FIRESTORM_VISUAL			= 144463,
    SPELL_BLAZING_NOVA_AURA         = 144493,
	SPELL_BLAZING_NOVA				= 144494,
    SPELL_BEACON_OF_HOPE_AURA       = 144475
};

enum Events
{
	EVENT_FIRESTORM					= 1,
	EVENT_INSPIRING_SONG,
	EVENT_BEACON_OF_HOPE,	
    EVENT_HEALTH_66_PERCENT,
    EVENT_HEALTH_33_PERCENT,
    EVENT_SHAO_DO_OUTRO,
    EVENT_DEATH,
    EVENT_SHAO_DO_INTRO,
    EVENT_SHAO_DO_INTRO_ATTACKABLE,
    EVENT_HEALTH_POOL_TIMER
};

enum Says
{
    SAY_AGGRO                       = 0,
    SAY_INTRO                       = 1,
    SAY_DEATH                       = 2,
    SAY_KILL                        = 3,
    SAY_SPELL                       = 4,
    SAY_SPELL_2                     = 5,
    SAY_SPELL_3                     = 6
};

enum Actions
{
    ACTION_CHILDREN_OF_CHIJI_33 = 1,
    ACTION_CHILDREN_OF_CHIJI_66 = 2
};

enum Factions
{
    FACTION_FRIENDLY = 35,
    FACTION_HOSTILE_NEUTRAL = 31
};

#define MIDDLE_FACING_ANGLE 1.573f

enum Datas
{
    DATA_CHI_JI = 0,
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

class boss_chi_ji : public CreatureScript
{
    public:
        boss_chi_ji() : CreatureScript("boss_chi_ji") { }

        struct boss_chi_jiAI : public BossAI
        {
            boss_chi_jiAI(Creature* creature) : BossAI(creature, DATA_CHI_JI) {	}

            void Reset()
            {
                events.Reset();
                _Reset();

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
                me->SetWalk(false);
                death = false;
                Talk(SAY_AGGRO);
                events.ScheduleEvent(urand(EVENT_FIRESTORM, EVENT_INSPIRING_SONG), urand(10000, 15000));
                events.ScheduleEvent(EVENT_BEACON_OF_HOPE, 50000);
            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case ACTION_CHILDREN_OF_CHIJI_66:
                    {
                        DoCast(SPELL_CRANE_RUSH);
                        Talk(SAY_SPELL_3);
                        break;
                    }
                    case ACTION_CHILDREN_OF_CHIJI_33:
                    {
                        DoCast(SPELL_CRANE_RUSH);
                        Talk(SAY_SPELL_2);
                        break;
                    }
                    default: break;
                };
            }

            void DamageTaken(Unit* caster, uint32 &dmg)
            {
                if (me->GetHealthPct() > 66.6f)
                {
                    _children66 = false;
                    _children33 = false;
                }

                if (me->GetHealthPct() < 66.6f && !_children66)
                {
                    _children66 = true;
                    events.ScheduleEvent(EVENT_HEALTH_66_PERCENT, 500);
                }

                if (me->GetHealthPct() < 33.3f && !_children33)
                {
                    _children33 = true;
                    events.ScheduleEvent(EVENT_HEALTH_33_PERCENT, 500);
                }
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (point == 1)
                {
                    events.ScheduleEvent(EVENT_SHAO_DO_INTRO, CELESTIAL_COURT_BOSS_INTRO_TIMER_1);
                    me->SetFacingTo(MIDDLE_FACING_ANGLE);
                    me->setFaction(FACTION_HOSTILE_NEUTRAL);
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

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_SHAO_DO_INTRO:
                    {
                        Talk(SAY_INTRO);
                        events.ScheduleEvent(EVENT_SHAO_DO_INTRO_ATTACKABLE, CELESTIAL_COURT_BOSS_INTRO_TIMER_2);
                        break;
                    }
                    case EVENT_SHAO_DO_INTRO_ATTACKABLE:
                    {
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetMaxHealth(INITIAL_HEALTH_POINTS);
                        break;
                    }
                    case EVENT_INSPIRING_SONG:
                    {
                        DoCast(me, SPELL_INSPIRING_SONG);
                        events.ScheduleEvent(urand(EVENT_FIRESTORM, EVENT_INSPIRING_SONG), urand(8000, 12000));
                        break;
                    }
                    case EVENT_FIRESTORM:
                    {
                        DoCast(SPELL_FIRESTORM);
                        events.ScheduleEvent(urand(EVENT_FIRESTORM, EVENT_INSPIRING_SONG), urand(8000, 12000));
                        break;
                    }
                    case EVENT_BEACON_OF_HOPE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 15.0f, true))
                        {
                            DoCast(target, SPELL_BEACON_OF_HOPE, true);

                            DoCast(SPELL_BLAZING_SONG);
                            Talk(SAY_SPELL);
                        }
                        events.ScheduleEvent(EVENT_BEACON_OF_HOPE, 50000);
                        break;
                    }
                    case EVENT_HEALTH_66_PERCENT:
                    {
                        DoAction(ACTION_CHILDREN_OF_CHIJI_66);
                        break;
                    }
                    case EVENT_HEALTH_33_PERCENT:
                    {
                        DoAction(ACTION_CHILDREN_OF_CHIJI_33);
                        break;
                    }
                    case EVENT_SHAO_DO_OUTRO:
                    {
                        if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                            shao->AI()->Talk(EMPEROR_TALK_OUTRO_CHIJI);
                        break;
                    }
                    case EVENT_DEATH:
                    {
                        if (death)
                        {
                            if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                                shao->AI()->DoAction(ACTION_NIUZAO);

                            me->DisappearAndDie();
                            death = false;
                        }
                        break;
                    }
                    default:
                        break;
                }

                if (!death)
                    if (!UpdateVictim())
                        return;

                DoMeleeAttackIfReady();
            }

            private:
                bool _children66, _children33 = false;
                bool death = false;
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_chi_jiAI(creature);
        }
};

enum ChildEvents
{
    CHILD_EVENT_RUN = 1
};

enum ChildMovement
{
    CHILD_MOVEMENT = 1
};

enum ChildAction
{
    CHILD_ACTION_RUN_FORWARD = 1
};

class mob_child_of_chi_ji : public CreatureScript
{
    public:
        mob_child_of_chi_ji() : CreatureScript("mob_child_of_chi_ji") { }

        struct mob_child_of_chi_jiAI : public ScriptedAI
        {
            mob_child_of_chi_jiAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                me->setActive(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);

                events.ScheduleEvent(CHILD_EVENT_RUN, 1000);
                DoCast(SPELL_BLAZING_NOVA_AURA);
                _runCount = 1;
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

                if (point == CHILD_MOVEMENT)
                {
                    if (_runCount > 3)
                        me->DisappearAndDie();
                    else
                        events.ScheduleEvent(CHILD_EVENT_RUN, 1000);
                }

            }

            void DoAction(const int32 action)
            {
                switch (action)
                {
                    case CHILD_ACTION_RUN_FORWARD:
                    {
                        Position pos;
                        float x, y;
                        GetPositionWithDistInOrientation(me, 15.0f, me->GetOrientation(), x, y);
                        if (MapManager::IsValidMapCoord(me->GetMapId(), x, y))
                        {
                            if (me->IsWithinLOS(x, y, me->GetPositionZ()))
                            {
                                ++_runCount;
                                pos.Relocate(x, y, me->GetPositionZ());
                                me->GetMotionMaster()->MovePoint(CHILD_MOVEMENT, pos);
                                return;
                            }
                        }

                        me->DisappearAndDie();
                        break;
                    }
                    default:
                        break;
                }
            };

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);
                switch (events.ExecuteEvent())
                {
                    case CHILD_EVENT_RUN:
                    {
                        DoAction(CHILD_ACTION_RUN_FORWARD);
                        break;
                    }
                    default: break;
                }
            }

            private:
                uint8 _runCount;
                EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_child_of_chi_jiAI(creature);
        }
};

// Blazing Of Hope - 144475
class spell_chi_ji_beacon_of_hope : public SpellScriptLoader
{
    public:
        spell_chi_ji_beacon_of_hope() : SpellScriptLoader("spell_chi_ji_beacon_of_hope") { }

        class spell_chi_ji_beacon_of_hope_Spellcript : public SpellScript
        {
            PrepareSpellScript(spell_chi_ji_beacon_of_hope_Spellcript);

            void DeselectNonPlayer(std::list<WorldObject*>& targets)
            {
                targets.remove(GetCaster());

                for (auto itr : targets)
                {
                    if (itr->GetTypeId() == TYPEID_UNIT)
                    {
                        if (itr->GetEntry() == BOSS_CHI_JI)
                        {
                            targets.remove(itr);
                            continue;
                        }

                        if (Creature* unit = sObjectAccessor->GetCreature(*GetCaster(), itr->ToUnit()->GetOwnerGUID()))
                            if (unit->GetEntry() == BOSS_CHI_JI || unit->GetEntry() == BOSS_CHI_JI)
                                targets.remove(itr);
                    }
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_chi_ji_beacon_of_hope_Spellcript::DeselectNonPlayer, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_chi_ji_beacon_of_hope_Spellcript();
        }
};

void AddSC_boss_chi_ji()
{
    new spell_chi_ji_beacon_of_hope();
    new mob_child_of_chi_ji();
    new boss_chi_ji();
}