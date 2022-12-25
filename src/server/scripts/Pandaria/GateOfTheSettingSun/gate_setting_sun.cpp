/*
 * Copyright 2023 AzgathCore
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

#include "gate_setting_sun.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "GameObject.h"

enum spells
{
    SPELL_MANTID_MUNITION_EXPLOSION = 107153,
    SPELL_EXPLOSE_GATE = 115456,

    SPELL_BOMB_CAST_VISUAL = 106729,
    SPELL_BOMB_AURA = 106875
};

class mob_serpent_spine_defender : public CreatureScript
{
public:
    mob_serpent_spine_defender() : CreatureScript("mob_serpent_spine_defender") { }

    struct mob_serpent_spine_defenderAI : public ScriptedAI
    {
        mob_serpent_spine_defenderAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 attackTimer;

        void Reset() override
        {
            attackTimer = urand(1000, 5000);
        }

        void DamageDealt(Unit* /*target*/, uint32& damage, DamageEffectType /*damageType*/) override
        {
            damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->IsInCombat())
            {
                if (attackTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            AttackStart(target);
                }
                else
                    attackTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_serpent_spine_defenderAI(creature);
    }
};

#ifndef __clang_analyzer__
void AddSC_gate_setting_sun()
{
    
}
#endif
