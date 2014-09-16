/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Ambassador_Hellmaw
SD%Complete: 80
SDComment: Enrage spell missing/not known
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "shadow_labyrinth.h"

enum Yells
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_HELP        = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4
};

enum Spells
{
    SPELL_BANISH            = 30231,
    SPELL_CORROSIVE_ACID    = 33551,
    SPELL_FEAR              = 33547,
    SPELL_ENRAGE            = 34970
};

enum Events
{
    EVENT_CORROSIVE_ACID = 1,
    EVENT_FEAR,
    EVENT_BERSERK
};

class boss_ambassador_hellmaw : public CreatureScript
{
    public:
        boss_ambassador_hellmaw() : CreatureScript("boss_ambassador_hellmaw") { }

        struct boss_ambassador_hellmawAI : public npc_escortAI
        {
            boss_ambassador_hellmawAI(Creature* creature) : npc_escortAI(creature)
            {
                _instance = creature->GetInstanceScript();
                _intro = false;
            }

            void Reset() override
            {
                if (!me->IsAlive())
                    return;

                _events.Reset();
                _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, NOT_STARTED);

                _events.ScheduleEvent(EVENT_CORROSIVE_ACID, urand(5000, 10000));
                _events.ScheduleEvent(EVENT_FEAR, urand(25000, 30000));
                if (IsHeroic())
                    _events.ScheduleEvent(EVENT_BERSERK, 180000);

                DoAction(ACTION_AMBASSADOR_HELLMAW_BANISH);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (me->HasAura(SPELL_BANISH))
                    return;

                npc_escortAI::MoveInLineOfSight(who);
            }

            void WaypointReached(uint32 /*waypointId*/) override
            {
            }

            void DoAction(int32 actionId)
            {
                if (actionId == ACTION_AMBASSADOR_HELLMAW_INTRO)
                    DoIntro();
                else if (actionId == ACTION_AMBASSADOR_HELLMAW_BANISH)
                {
                    if (_instance->GetData(DATA_FEL_OVERSEER) && me->HasAura(SPELL_BANISH))
                        DoCast(me, SPELL_BANISH, true); // this will not work, because he is immune to banish
                }
            }

            void DoIntro()
            {
                if (_intro)
                    return;

                _intro = true;

                if (me->HasAura(SPELL_BANISH))
                    me->RemoveAurasDueToSpell(SPELL_BANISH);

                Talk(SAY_INTRO);
                Start(true, false, ObjectGuid::Empty, NULL, false, true);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, IN_PROGRESS);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, DONE);
                Talk(SAY_DEATH);
            }

            void UpdateEscortAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasAura(SPELL_BANISH))
                {
                    EnterEvadeMode();
                    return;
                }

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CORROSIVE_ACID:
                            DoCastVictim(SPELL_CORROSIVE_ACID);
                            _events.ScheduleEvent(EVENT_CORROSIVE_ACID, urand(15000, 25000));
                            break;
                        case EVENT_FEAR:
                            DoCastAOE(SPELL_FEAR);
                            _events.ScheduleEvent(EVENT_FEAR, urand(20000, 35000));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_ENRAGE, true);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _intro;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShadowLabyrinthAI<boss_ambassador_hellmawAI>(creature);
        }
};

void AddSC_boss_ambassador_hellmaw()
{
    new boss_ambassador_hellmaw();
}
