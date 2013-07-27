/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "Player.h"
#include "ruins_of_ahnqiraj.h"

enum Spells
{
    SPELL_STINGER_SPRAY         =  25749,
    SPELL_POISON_STINGER        =  25748,
    SPELL_PARALYZE              =  25725,
    SPELL_TRASH                 =  3391,
    SPELL_FRENZY                =  8269,
    SPELL_LASH                  =  25852,
    SPELL_FEED                  =  25721
};

enum Events
{
    EVENT_STINGER_SPRAY         = 1,
    EVENT_POISON_STINGER        = 2,
    EVENT_SUMMON_SWARMER        = 3,
    EVENT_SWARMER_ATTACK        = 4,
    EVENT_PARALYZE              = 5,
    EVENT_LASH                  = 6,
    EVENT_TRASH                 = 7
};

enum Emotes
{
    EMOTE_FRENZY                =  0
};

enum Phases
{
    PHASE_AIR                   = 0,
    PHASE_GROUND                = 1
};

enum Points
{
    POINT_AIR                   = 0,
    POINT_GROUND                = 1,
    POINT_PARALYZE              = 2
};

const Position AyamissAirPos =  { -9689.292f, 1547.912f, 48.02729f, 0.0f };
const Position AltarPos =       { -9717.18f, 1517.72f, 27.4677f, 0.0f };
/// @todo These below are probably incorrect, taken from SD2
const Position SwarmerPos =     { -9647.352f, 1578.062f, 55.32f, 0.0f };
const Position LarvaPos[2] =
{
    { -9674.4707f, 1528.4133f, 22.457f, 0.0f },
    { -9701.6005f, 1566.9993f, 24.118f, 0.0f }
};

class boss_ayamiss : public CreatureScript
{
    public:
        boss_ayamiss() : CreatureScript("boss_ayamiss") { }

        struct boss_ayamissAI : public BossAI
        {
            boss_ayamissAI(Creature* creature) : BossAI(creature, DATA_AYAMISS)
            {
            }

            void Reset() OVERRIDE
            {
                _Reset();
                _phase = PHASE_AIR;
                _enraged = false;
                SetCombatMovement(false);
            }

            void JustSummoned(Creature* who) OVERRIDE
            {
                switch (who->GetEntry())
                {
                    case NPC_SWARMER:
                        _swarmers.push_back(who->GetGUID());
                        break;
                    case NPC_LARVA:
                        who->GetMotionMaster()->MovePoint(POINT_PARALYZE, AltarPos);
                        break;
                    case NPC_HORNET:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            who->AI()->AttackStart(target);
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type == POINT_MOTION_TYPE)
                {
                    switch (id)
                    {
                        case POINT_AIR:
                            me->AddUnitState(UNIT_STATE_ROOT);
                            break;
                        case POINT_GROUND:
                            me->ClearUnitState(UNIT_STATE_ROOT);
                            break;
                    }
                }
            }

            void EnterEvadeMode() OVERRIDE
            {
                me->ClearUnitState(UNIT_STATE_ROOT);
                BossAI::EnterEvadeMode();
            }

            void EnterCombat(Unit* attacker) OVERRIDE
            {
                BossAI::EnterCombat(attacker);

                events.ScheduleEvent(EVENT_STINGER_SPRAY, urand(20000, 30000));
                events.ScheduleEvent(EVENT_POISON_STINGER, 5000);
                events.ScheduleEvent(EVENT_SUMMON_SWARMER, 5000);
                events.ScheduleEvent(EVENT_SWARMER_ATTACK, 60000);
                events.ScheduleEvent(EVENT_PARALYZE, 15000);

                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->GetMotionMaster()->MovePoint(POINT_AIR, AyamissAirPos);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (_phase == PHASE_AIR && me->GetHealthPct() < 70.0f)
                {
                    _phase = PHASE_GROUND;
                    SetCombatMovement(true);
                    me->SetCanFly(false);
                    Position VictimPos;
                    me->GetVictim()->GetPosition(&VictimPos);
                    me->GetMotionMaster()->MovePoint(POINT_GROUND, VictimPos);
                    DoResetThreat();
                    events.ScheduleEvent(EVENT_LASH, urand(5000, 8000));
                    events.ScheduleEvent(EVENT_TRASH, urand(3000, 6000));
                    events.CancelEvent(EVENT_POISON_STINGER);
                }
                else
                {
                    DoMeleeAttackIfReady();
                }

                if (!_enraged && me->GetHealthPct() < 20.0f)
                {
                    DoCast(me, SPELL_FRENZY);
                    Talk(EMOTE_FRENZY);
                    _enraged = true;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STINGER_SPRAY:
                            DoCast(me, SPELL_STINGER_SPRAY);
                            events.ScheduleEvent(EVENT_STINGER_SPRAY, urand(15000, 20000));
                            break;
                        case EVENT_POISON_STINGER:
                            DoCastVictim(SPELL_POISON_STINGER);
                            events.ScheduleEvent(EVENT_POISON_STINGER, urand(2000, 3000));
                            break;
                        case EVENT_PARALYZE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                DoCast(target, SPELL_PARALYZE);
                                instance->SetData64(DATA_PARALYZED, target->GetGUID());
                                uint8 Index = urand(0, 1);
                                me->SummonCreature(NPC_LARVA, LarvaPos[Index], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                            }
                            events.ScheduleEvent(EVENT_PARALYZE, 15000);
                            break;
                        case EVENT_SWARMER_ATTACK:
                            for (std::list<uint64>::iterator i = _swarmers.begin(); i != _swarmers.end(); ++i)
                                if (Creature* swarmer = me->GetMap()->GetCreature(*i))
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                        swarmer->AI()->AttackStart(target);

                            _swarmers.clear();
                            events.ScheduleEvent(EVENT_SWARMER_ATTACK, 60000);
                            break;
                        case EVENT_SUMMON_SWARMER:
                            Position Pos;
                            me->GetRandomPoint(SwarmerPos, 80.0f, Pos);
                            me->SummonCreature(NPC_SWARMER, Pos);
                            events.ScheduleEvent(EVENT_SUMMON_SWARMER, 5000);
                            break;
                        case EVENT_TRASH:
                            DoCastVictim(SPELL_TRASH);
                            events.ScheduleEvent(EVENT_TRASH, urand(5000, 7000));
                            break;
                        case EVENT_LASH:
                            DoCastVictim(SPELL_LASH);
                            events.ScheduleEvent(EVENT_LASH, urand(8000, 15000));
                            break;
                    }
                }
            }
        private:
            std::list<uint64> _swarmers;
            uint8 _phase;
            bool _enraged;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_ayamissAI(creature);
        }
};

class npc_hive_zara_larva : public CreatureScript
{
    public:
        npc_hive_zara_larva() : CreatureScript("npc_hive_zara_larva") { }

        struct npc_hive_zara_larvaAI : public ScriptedAI
        {
            npc_hive_zara_larvaAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type == POINT_MOTION_TYPE)
                    if (id == POINT_PARALYZE)
                        if (Player* target = ObjectAccessor::GetPlayer(*me, _instance->GetData64(DATA_PARALYZED)))
                            DoCast(target, SPELL_FEED); // Omnomnom
            }

            void MoveInLineOfSight(Unit* who) OVERRIDE

            {
                if (_instance->GetBossState(DATA_AYAMISS) == IN_PROGRESS)
                    return;

                ScriptedAI::MoveInLineOfSight(who);
            }

            void AttackStart(Unit* victim) OVERRIDE
            {
                if (_instance->GetBossState(DATA_AYAMISS) == IN_PROGRESS)
                    return;

                ScriptedAI::AttackStart(victim);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (_instance->GetBossState(DATA_AYAMISS) == IN_PROGRESS)
                    return;

                ScriptedAI::UpdateAI(diff);
            }
        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_hive_zara_larvaAI(creature);
        }
};

void AddSC_boss_ayamiss()
{
    new boss_ayamiss();
    new npc_hive_zara_larva();
}
