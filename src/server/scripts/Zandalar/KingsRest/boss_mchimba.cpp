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

#include "kings_rest.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureAI.h"
#include "CreatureData.h"


enum Texts
{
    SAY_AGGRO = 0,
    SAY_BURN_CORRUPTION,
    SAY_ENTOMB,
    SAY_DEATH,
};

enum Spells
{
    SPELL_BURN_CORRUPTION_DAMAGE = 267639,
    SPELL_DRAIN_FLUIDS = 267618,
    SPELL_BURNING_GROUND_AT_DAMAGE = 267874,
    SPELL_DESSICATION = 267626,
};

enum Events
{
    EVENT_ENTOMB = 1,
    EVENT_BURN_CORRUPTION,
    EVENT_DRAIN_FLUIDS,
};

void AddSC_boss_mchimba_the_embalmber()
{
    
}
