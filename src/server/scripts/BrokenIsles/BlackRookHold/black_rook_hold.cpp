/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "black_rook_hold.h"

enum Spells
{
    SPELL_BOULDER_EXPLOSION = 222388,
    SPELL_BOULDER_DAMAGE    = 222397,
    SPELL_BOULDER_STUN      = 222417,
};

// 100485
struct npc_brh_boulder : public ScriptedAI
{
    npc_brh_boulder(Creature* creature) : ScriptedAI(creature) { }

    // The instance will spawn it at top of stairs & make it move by spline

    void OnSplineEndReached() override
    {
        me->CastSpell(me, SPELL_BOULDER_EXPLOSION, false);
        me->DespawnOrUnsummon();
    }
};

// 12428
struct at_brh_boulder : AreaTriggerAI
{
    at_brh_boulder(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(SPELL_BOULDER_STUN))
        {
            unit->CastSpell(unit, SPELL_BOULDER_DAMAGE, true);
            unit->CastSpell(unit, SPELL_BOULDER_STUN, true);
        }
    }
};

void AddSC_black_rook_hold()
{
    RegisterCreatureAI(npc_brh_boulder);
    RegisterAreaTriggerAI(at_brh_boulder);
}
