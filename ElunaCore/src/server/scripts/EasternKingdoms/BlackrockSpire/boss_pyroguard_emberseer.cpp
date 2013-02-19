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
#include "blackrock_spire.h"

enum Text
{
    EMOTE_ONE_STACK                 = 0,
    EMOTE_TEN_STACK                 = 1,
    EMOTE_FREE_OF_BONDS             = 2,
    YELL_FREE_OF_BONDS              = 3
};

enum Spells
{
    SPELL_ENCAGED_EMBERSEER         = 15282, // Self on spawn
    SPELL_FIRE_SHIELD_TRIGGER       = 13377, // Self on spawn missing from 335 dbc
    SPELL_FREEZE_ANIM               = 16245, // Self on event start
    SPELL_EMBERSEER_GROWING         = 16048, // Self on event start
    SPELL_EMBERSEER_FULL_STRENGTH   = 16047, // Emberseer Full Strength
    SPELL_FIRENOVA                  = 23462, // Combat
    SPELL_FLAMEBUFFET               = 23341, // Combat
    SPELL_PYROBLAST                 = 17274  // Combat
};

enum Events
{
    EVENT_FIRENOVA                  = 1,
    EVENT_FLAMEBUFFET               = 2,
    EVENT_PYROBLAST                 = 3
};


class boss_pyroguard_emberseer : public CreatureScript
{
public:
    boss_pyroguard_emberseer() : CreatureScript("boss_pyroguard_emberseer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_pyroguard_emberseerAI(creature);
    }

    struct boss_pyroguard_emberseerAI : public BossAI
    {
        boss_pyroguard_emberseerAI(Creature* creature) : BossAI(creature, DATA_PYROGAURD_EMBERSEER) {}

        void Reset()
        {
            if (instance->GetBossState(DATA_PYROGAURD_EMBERSEER) == IN_PROGRESS)
                OpenDoors(false);
            // respawn any dead Blackhand Incarcerators
            DoCast(me, SPELL_ENCAGED_EMBERSEER);
            //DoCast(me, SPELL_FIRE_SHIELD_TRIGGER);
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_FIRENOVA,    6 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FLAMEBUFFET, 3 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_PYROBLAST,  14 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            OpenDoors(true);
            _JustDied();
        }

       void OpenDoors(bool Boss_Killed)
       {
           if (GameObject* door1 = me->GetMap()->GetGameObject(instance->GetData64(GO_EMBERSEER_IN)))
               door1->SetGoState(GO_STATE_ACTIVE);
           if (GameObject* door2 = me->GetMap()->GetGameObject(instance->GetData64(GO_DOORS)))
               door2->SetGoState(GO_STATE_ACTIVE);
           if (Boss_Killed)
               if (GameObject* door3 = me->GetMap()->GetGameObject(instance->GetData64(GO_EMBERSEER_OUT)))
                    door3->SetGoState(GO_STATE_ACTIVE);
       }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIRENOVA:
                        DoCastVictim(SPELL_FIRENOVA);
                        events.ScheduleEvent(EVENT_FIRENOVA, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_FLAMEBUFFET:
                        DoCastVictim(SPELL_FLAMEBUFFET);
                        events.ScheduleEvent(EVENT_FLAMEBUFFET, 14 * IN_MILLISECONDS);
                        break;
                    case EVENT_PYROBLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_PYROBLAST);
                        events.ScheduleEvent(EVENT_PYROBLAST, 15 * IN_MILLISECONDS);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_pyroguard_emberseer()
{
    new boss_pyroguard_emberseer();
}
