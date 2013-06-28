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
#include "violet_hold.h"

enum SphereSpells
{
    SPELL_ARCANE_SPHERE_PASSIVE = 44263
};

class VH_arcane_sphere : public CreatureScript
{
public:
    VH_arcane_sphere() : CreatureScript("VH_arcane_sphere") { }

    CreatureAI* GetAI(Creature* c) const
    {
        return new VH_arcane_sphereAI(c);
    }

    struct VH_arcane_sphereAI : public ScriptedAI
    {
        VH_arcane_sphereAI(Creature* creature) : ScriptedAI(creature) { Reset(); }

        uint32 DespawnTimer;

        void Reset()
        {
            DespawnTimer = 3000;

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisableGravity(true);
            //me->setFaction(14);
            DoCast(me, SPELL_ARCANE_SPHERE_PASSIVE, true);
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(uint32 diff)
        {
            if (DespawnTimer <= diff)
                me->Kill(me);
            else
                DespawnTimer -= diff;
        }
    };
};

void AddSC_VH_arcane_sphere()
{
    new VH_arcane_sphere();
}
