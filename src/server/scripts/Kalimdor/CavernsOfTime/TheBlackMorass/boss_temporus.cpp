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
Name: Boss_Temporus
%Complete: 75
Comment: More abilities need to be implemented
Category: Caverns of Time, The Black Morass
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "the_black_morass.h"

enum Enums
{
    SAY_ENTER               = 0,
    SAY_AGGRO               = 1,
    SAY_BANISH              = 2,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4,

    SPELL_HASTE             = 31458,
    SPELL_MORTAL_WOUND      = 31464,
    SPELL_WING_BUFFET       = 31475,
    H_SPELL_WING_BUFFET     = 38593,
    SPELL_REFLECT           = 38592                       //Not Implemented (Heroic mod)
};

enum Events
{
    EVENT_HASTE             = 1,
    EVENT_MORTAL_WOUND      = 2,
    EVENT_WING_BUFFET       = 3,
    EVENT_SPELL_REFLECTION  = 4
};

class boss_temporus : public CreatureScript
{
public:
    boss_temporus() : CreatureScript("boss_temporus") { }

    struct boss_temporusAI : public BossAI
    {
        boss_temporusAI(Creature* creature) : BossAI(creature, TYPE_TEMPORUS) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_HASTE, urand(15000, 23000));
            events.ScheduleEvent(EVENT_MORTAL_WOUND, 8000);
            events.ScheduleEvent(EVENT_WING_BUFFET, urand(25000, 35000));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_SPELL_REFLECTION, 30000);

            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetData(TYPE_RIFT, SPECIAL);
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
                    case EVENT_HASTE:
                        DoCast(me, SPELL_HASTE);
                        events.ScheduleEvent(EVENT_HASTE, urand(20000, 25000));
                        break;
                    case EVENT_MORTAL_WOUND:
                        DoCast(me, SPELL_MORTAL_WOUND);
                        events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(10000, 20000));
                        break;
                    case EVENT_WING_BUFFET:
                         DoCast(me, SPELL_WING_BUFFET);
                        events.ScheduleEvent(EVENT_WING_BUFFET, urand(20000, 30000));
                        break;
                    case EVENT_SPELL_REFLECTION: // Only in Heroic
                        DoCast(me, SPELL_REFLECT);
                        events.ScheduleEvent(EVENT_SPELL_REFLECTION, urand(25000, 35000));
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
        return GetBlackMorassAI<boss_temporusAI>(creature);
    }
};

void AddSC_boss_temporus()
{
    new boss_temporus();
}
