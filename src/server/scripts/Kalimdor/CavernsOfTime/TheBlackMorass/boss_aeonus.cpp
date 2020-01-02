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

/*
Name: Boss_Aeonus
%Complete: 80
Comment: Some spells not implemented
Category: Caverns of Time, The Dark Portal
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "the_black_morass.h"

enum Enums
{
    SAY_ENTER           = 0,
    SAY_AGGRO           = 1,
    SAY_BANISH          = 2,
    SAY_SLAY            = 3,
    SAY_DEATH           = 4,
    EMOTE_FRENZY        = 5,

    SPELL_CLEAVE        = 40504,
    SPELL_TIME_STOP     = 31422,
    SPELL_ENRAGE        = 37605,
    SPELL_SAND_BREATH   = 31473,
    H_SPELL_SAND_BREATH = 39049
};

enum Events
{
    EVENT_SANDBREATH    = 1,
    EVENT_TIMESTOP      = 2,
    EVENT_FRENZY        = 3
};

class boss_aeonus : public CreatureScript
{
public:
    boss_aeonus() : CreatureScript("boss_aeonus") { }

    struct boss_aeonusAI : public BossAI
    {
        boss_aeonusAI(Creature* creature) : BossAI(creature, TYPE_AEONUS) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SANDBREATH, urand(15000, 30000));
            events.ScheduleEvent(EVENT_TIMESTOP, urand(10000, 15000));
            events.ScheduleEvent(EVENT_FRENZY, urand(30000, 45000));

            Talk(SAY_AGGRO);
        }

        void MoveInLineOfSight(Unit* who) override

        {
            //Despawn Time Keeper
            if (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_TIME_KEEPER)
            {
                if (me->IsWithinDistInMap(who, 20.0f))
                {
                    Talk(SAY_BANISH);
                    me->DealDamage(who, who->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetData(TYPE_RIFT, DONE);
            instance->SetData(TYPE_MEDIVH, DONE); // FIXME: later should be removed
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SANDBREATH:
                        DoCastVictim(SPELL_SAND_BREATH);
                        events.ScheduleEvent(EVENT_SANDBREATH, urand(15000, 25000));
                        break;
                    case EVENT_TIMESTOP:
                        DoCastVictim(SPELL_TIME_STOP);
                        events.ScheduleEvent(EVENT_TIMESTOP, urand(20000, 35000));
                        break;
                    case EVENT_FRENZY:
                         Talk(EMOTE_FRENZY);
                         DoCast(me, SPELL_ENRAGE);
                        events.ScheduleEvent(EVENT_FRENZY, urand(20000, 35000));
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackMorassAI<boss_aeonusAI>(creature);
    }
};

void AddSC_boss_aeonus()
{
    new boss_aeonus();
}
