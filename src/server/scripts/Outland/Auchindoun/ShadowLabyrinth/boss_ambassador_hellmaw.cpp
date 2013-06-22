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

enum eEnums
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_HELP        = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4,

    SPELL_BANISH            = 30231,
    SPELL_CORROSIVE_ACID    = 33551,
    SPELL_FEAR              = 33547,
    SPELL_ENRAGE            = 34970
};

class boss_ambassador_hellmaw : public CreatureScript
{
public:
    boss_ambassador_hellmaw() : CreatureScript("boss_ambassador_hellmaw") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ambassador_hellmawAI(creature);
    }

    struct boss_ambassador_hellmawAI : public npc_escortAI
    {
        boss_ambassador_hellmawAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 EventCheck_Timer;
        uint32 CorrosiveAcid_Timer;
        uint32 Fear_Timer;
        uint32 Enrage_Timer;
        bool Intro;
        bool IsBanished;
        bool Enraged;

        void Reset()
        {
            EventCheck_Timer = 5000;
            CorrosiveAcid_Timer = urand(5000, 10000);
            Fear_Timer = urand(25000, 30000);
            Enrage_Timer = 180000;
            Intro = false;
            IsBanished = true;
            Enraged = false;

            if (instance && me->IsAlive())
            {
                if (instance->GetData(TYPE_OVERSEER) != DONE)
                    DoCast(me, SPELL_BANISH, true);
            }
        }

        void JustReachedHome()
        {
            if (instance)
                instance->SetData(TYPE_HELLMAW, FAIL);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (me->HasAura(SPELL_BANISH))
                return;

            npc_escortAI::MoveInLineOfSight(who);
        }

        void WaypointReached(uint32 /*waypointId*/)
        {
        }

        void DoIntro()
        {
            if (me->HasAura(SPELL_BANISH))
                me->RemoveAurasDueToSpell(SPELL_BANISH);

            IsBanished = false;
            Intro = true;

            if (instance)
            {
                if (instance->GetData(TYPE_HELLMAW) != FAIL)
                {
                    Talk(SAY_INTRO);
                    Start(true, false, 0, NULL, false, true);
                }

                instance->SetData(TYPE_HELLMAW, IN_PROGRESS);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(TYPE_HELLMAW, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!Intro && !HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (EventCheck_Timer <= diff)
                {
                    if (instance)
                    {
                        if (instance->GetData(TYPE_OVERSEER) == DONE)
                        {
                            DoIntro();
                            return;
                        }
                    }
                    EventCheck_Timer = 5000;
                    return;
                }
                else
                {
                    EventCheck_Timer -= diff;
                    return;
                }
            }

            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (me->HasAura(SPELL_BANISH, 0))
            {
                EnterEvadeMode();
                return;
            }

            if (CorrosiveAcid_Timer <= diff)
            {
                DoCastVictim(SPELL_CORROSIVE_ACID);
                CorrosiveAcid_Timer = urand(15000, 25000);
            } else CorrosiveAcid_Timer -= diff;

            if (Fear_Timer <= diff)
            {
                DoCast(me, SPELL_FEAR);
                Fear_Timer = urand(20000, 35000);
            } else Fear_Timer -= diff;

            if (IsHeroic())
            {
                if (!Enraged && Enrage_Timer <= diff)
                {
                    DoCast(me, SPELL_ENRAGE);
                    Enraged = true;
                } else Enrage_Timer -= diff;
            }
        }
    };

};

void AddSC_boss_ambassador_hellmaw()
{
    new boss_ambassador_hellmaw();
}
