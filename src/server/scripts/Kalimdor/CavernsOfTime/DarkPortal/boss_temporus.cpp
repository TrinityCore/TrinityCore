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
SDName: Boss_Temporus
SD%Complete: 75
SDComment: More abilities need to be implemented
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "dark_portal.h"

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

        void Reset() { }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_HASTE, urand(15000, 23000));
            events.ScheduleEvent(EVENT_MORTAL_WOUND, 8000);
            events.ScheduleEvent(EVENT_WING_BUFFET, urand(25000, 35000));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_SPELL_REFLECTION, 30000);

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
                instance->SetData(TYPE_RIFT, SPECIAL);
        }

        void MoveInLineOfSight(Unit* who)
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

        void UpdateAI(uint32 diff)
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
                }
                DoMeleeAttackIfReady();
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_temporusAI (creature);
        }
    };

};

void AddSC_boss_temporus()
{
    new boss_temporus();
}
