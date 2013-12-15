/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "razorfen_downs.h"

enum Say
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_HP50                = 2,
    SAY_HP15                = 3
};

enum Spells
{
    SPELL_DISEASE_CLOUD     = 12627,
    SPELL_FRENZY            = 12795
};

class boss_glutton : public CreatureScript
{
public:
    boss_glutton() : CreatureScript("boss_glutton") { }

    struct boss_gluttonAI : public BossAI
    {
        boss_gluttonAI(Creature* creature) : BossAI(creature, DATA_GLUTTON) { }

        void Reset() OVERRIDE
        {
            _Reset();
            hp50 = false;
            hp15 = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (!hp50 && HealthBelowPct(50))
            {
                Talk(SAY_HP50);
                hp50 = true;
            }

            if (!hp15 && HealthBelowPct(15))
            {
                Talk(SAY_HP15);
                DoCast(me, SPELL_FRENZY);
                hp15 = true;
            }

            DoMeleeAttackIfReady();
        }

    private:
        bool hp50;
        bool hp15;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_gluttonAI(creature);
    }
};

void AddSC_boss_glutton()
{
    new boss_glutton();
}
