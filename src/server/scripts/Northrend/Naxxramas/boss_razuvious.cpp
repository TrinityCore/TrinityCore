/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "naxxramas.h"

//Razuvious - NO TEXT sound only
//8852 aggro01 - Hah hah, I'm just getting warmed up!
//8853 aggro02 Stand and fight!
//8854 aggro03 Show me what you've got!
//8861 slay1 - You should've stayed home!
//8863 slay2-
//8858 cmmnd3 - You disappoint me, students!
//8855 cmmnd1 - Do as I taught you!
//8856 cmmnd2 - Show them no mercy!
//8859 cmmnd4 - The time for practice is over! Show me what you've learned!
//8861 Sweep the leg! Do you have a problem with that?
//8860 death - An honorable... death...
//8947 - Aggro Mixed? - ?

#define SOUND_AGGRO     RAND(8852, 8853, 8854)
#define SOUND_SLAY      RAND(8861, 8863)
#define SOUND_COMMND    RAND(8855, 8856, 8858, 8859, 8861)
#define SOUND_DEATH     8860
#define SOUND_AGGROMIX  8847

enum Spells
{
    SPELL_UNBALANCING_STRIKE   = 26613,
    SPELL_DISRUPTING_SHOUT     = 29107,
    SPELL_JAGGED_KNIFE         = 55550,
    SPELL_HOPELESS             = 29125
};

enum Events
{
    EVENT_NONE,
    EVENT_STRIKE,
    EVENT_SHOUT,
    EVENT_KNIFE,
    EVENT_COMMAND,
};

class boss_razuvious : public CreatureScript
{
public:
    boss_razuvious() : CreatureScript("boss_razuvious") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_razuviousAI(creature);
    }

    struct boss_razuviousAI : public BossAI
    {
        boss_razuviousAI(Creature* creature) : BossAI(creature, BOSS_RAZUVIOUS) { }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (!(rand32() % 3))
                DoPlaySoundToSet(me, SOUND_SLAY);
        }

        void DamageTaken(Unit* pDone_by, uint32& uiDamage) override
        {
            // Damage done by the controlled Death Knight understudies should also count toward damage done by players
            if (pDone_by->GetTypeId() == TYPEID_UNIT && (pDone_by->GetEntry() == 16803 || pDone_by->GetEntry() == 29941))
            {
                me->LowerPlayerDamageReq(uiDamage);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            DoPlaySoundToSet(me, SOUND_DEATH);
            me->CastSpell(me, SPELL_HOPELESS, true); /// @todo this may affect other creatures
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            DoPlaySoundToSet(me, SOUND_AGGRO);
            events.ScheduleEvent(EVENT_STRIKE, 30000);
            events.ScheduleEvent(EVENT_SHOUT, 25000);
            events.ScheduleEvent(EVENT_COMMAND, 40000);
            events.ScheduleEvent(EVENT_KNIFE, 10000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STRIKE:
                        DoCastVictim(SPELL_UNBALANCING_STRIKE);
                        events.ScheduleEvent(EVENT_STRIKE, 30000);
                        return;
                    case EVENT_SHOUT:
                        DoCastAOE(SPELL_DISRUPTING_SHOUT);
                        events.ScheduleEvent(EVENT_SHOUT, 25000);
                        return;
                    case EVENT_KNIFE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f))
                            DoCast(target, SPELL_JAGGED_KNIFE);
                        events.ScheduleEvent(EVENT_KNIFE, 10000);
                        return;
                    case EVENT_COMMAND:
                        DoPlaySoundToSet(me, SOUND_COMMND);
                        events.ScheduleEvent(EVENT_COMMAND, 40000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_razuvious()
{
    new boss_razuvious();
}
