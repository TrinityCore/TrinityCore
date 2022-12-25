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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "operation_mechagon.h"

enum Texts
{    
};

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_HIDDEN_FLAME_CANNON_PERIODIC = 285443,
    SPELL_HIDDEN_FLAME_CANNON_APPLY_AT = 285437,
    SPELL_ROARING_FLAME_MISSILE = 294867,
    SPELL_DISCOM_MISSILE = 285454,
    SPELL_SELF_TRIMMING_HEDGE_DAMAGE = 294954,
};

enum Events
{
    EVENT_HIDDEN_FLAME_CANNON = 1,
    EVENT_PLANTS, //npc 152033
    EVENT_DISCOM,
    EVENT_HEDGE
};

void AddSC_boss_machinists_garden()
{
   
};
