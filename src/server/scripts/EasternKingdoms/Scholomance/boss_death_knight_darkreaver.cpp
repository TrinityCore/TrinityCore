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

/* ScriptData
SDName: Boss_Death_knight_darkreaver
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

class boss_death_knight_darkreaver : public CreatureScript
{
public:
    boss_death_knight_darkreaver() : CreatureScript("boss_death_knight_darkreaver") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<boss_death_knight_darkreaverAI>(creature);
    }

    struct boss_death_knight_darkreaverAI : public ScriptedAI
    {
        boss_death_knight_darkreaverAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
        }

        void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (me->GetHealth() <= damage)
                DoCast(me, 23261, true);   //Summon Darkreaver's Fallen Charger
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
        }
    };

};

void AddSC_boss_death_knight_darkreaver()
{
    new boss_death_knight_darkreaver();
}
