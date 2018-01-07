/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "eye_of_azshara.h"

enum Spells
{
    SPELL_RAMPAGE           = 191848,
    SPELL_RAMPAGE_AURA      = 191850,

    SPELL_TASTE_OF_BLOOD    = 213738,

    SPELL_HYDRA_HEAD        = 202680,

    SPELL_TOXIC_WOUND       = 191855,
    SPELL_TOXIC_PUDDLE_AURA = 191856,

    SPELL_POISON_SPIT       = 192050,
    SPELL_POISON_SPIT_AURA  = 191839,

    // heal 66% and 33%, 
    SPELL_SUBMERGE          = 191873
};

enum Events
{
    EVENT_RAMPAGE        = 1,
    EVENT_TASTE_OF_BLOOD,
    EVENT_HYDRA_HEAD,
    EVENT_TOXIC_WOUND,
    EVENT_POISON_SPIT,
    EVENT_SUBMERGE
};

enum Yells
{
    SAY_SUBMERGE = 0
};

void AddSC_boss_serpentrix()
{

}