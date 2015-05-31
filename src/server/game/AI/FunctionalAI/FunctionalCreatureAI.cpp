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

#include "FunctionalCreatureAI.h"

void FunctionalCreatureAI::EnterCombat(Unit* victim)
{
    OnEnterCombatEvent event(victim);
    _OnEnterCombatEvent.Invoke(event);
}

void FunctionalCreatureAI::JustDied(Unit* killer)
{
    OnJustDiedEvent event(killer);
    _OnJustDiedEvent.Invoke(event);
}

void FunctionalCreatureAI::SpellHit(Unit* caster, SpellInfo const* spell)
{
    OnSpellHitEvent event(caster, spell);
    _OnSpellHitEvent.Invoke(event);
}
