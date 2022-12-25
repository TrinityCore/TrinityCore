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
    SAY_NAENO_AGGRO = 0,
    SAY_PEDAL,
    SAY_BURNOUT,
    SAY_ROADKILL,
    SAY_DEATH_NAENO,
    SAY_DEATH_NAENO_TRIXIE = 3,
    SAY_NAENO_KILL,
    SAY_TRIXIE_ELECTRIC_SLIDE = 0,
    SAY_TRIXIE_MEGA_TAZE,
    SAY_TRIXIE_JUMP_START
};

enum Spells
{
    //Trixie
    SPELL_TAZE = 298669,    
    SPELL_MEGA_TAZE_VISUAL_MISSILE = 302687,
    SPELL_MEGA_TAZE_CHANNEL = 302682,
    SPELL_MEGA_TAZE_DAMAGE = 298718,
    SPELL_ELECTRIC_SLIDE = 298849,
    SPELL_JUMP_START = 298897,
    SPELL_SUPER_BOOST = 303525,//When Naeno is defeated, Trixie gains Super Boost granting her 100% Haste for the remainder of the encounter.
    //Naeno
    SPELL_BOLT_BUSTER = 298940,
    SPELL_ROADKILL_CHARGE = 298946,
    SPELL_ROLL_OUT = 298898,
    SPELL_TURBO_BOOST_MAIN = 299153,
    SPELL_TURBO_BOOST = 299241,//When defeated, Trixie uses Turbo Boost on Naeno causing his successful melee attacks to inflict 46607 Nature damage to all players for the remainder of the encounter.	
    //Mechacycle
    SPELL_SMOKE_CLOUD_CREATE_AT = 298573,
    SPELL_SMOKE_CLOUD_AURA = 298602,
    SPELL_PEDAL_TO_THE_METAL = 298651,
    SPELL_BURNOUT = 298571,    
};

enum Events
{
    EVENT_TAZE = 1,
    EVENT_MEGA_TAZE,
    EVENT_ELECTRIC_SLIDE,
    EVENT_JUMP_START,
    EVENT_BOLT_BUSTER,
    EVENT_ROADKILL,    
    EVENT_PEDAL_TO_THE_METAL,
    EVENT_BURNOUT,
    EVENT_ROLL_OUT,
    EVENT_ENTER_VEHICLE,
    EVENT_EXIT_VEHICLE,
    EVENT_RANDOM_MOVE,
    EVENT_SPAWN_WALKIE
};

enum Misc
{
    PHASE_NORMAL = 1,
    PHASE_VEHICLE
};

void AddSC_boss_trixie_naeno()
{
    
};
