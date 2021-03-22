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

#include "ScriptMgr.h"
#include "Map.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"

class trigger_periodic : public CreatureScript
{
public:
    trigger_periodic() : CreatureScript("trigger_periodic") { }

    struct trigger_periodicAI : public NullCreatureAI
    {
        trigger_periodicAI(Creature* creature) : NullCreatureAI(creature)
        {
            spell = me->m_spells[0] ? sSpellMgr->GetSpellInfo(me->m_spells[0], me->GetMap()->GetDifficultyID()) : nullptr;
            interval = me->GetBaseAttackTime(BASE_ATTACK);
            timer = interval;
        }

        uint32 timer, interval;
        SpellInfo const* spell;

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {
                if (spell)
                    me->CastSpell(me, spell, true);
                timer = interval;
            }
            else
                timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new trigger_periodicAI(creature);
    }
};

void AddSC_generic_creature()
{
    new trigger_periodic();
}
