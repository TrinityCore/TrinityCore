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

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "spires_of_ascension.h"

enum KintaraAzules
{
    SPELL_LIFE_LINK = 345561,
    SPELL_OVERHEAD_SLASH = 320966,
    SPELL_DARK_LANCE = 327481,
    SPELL_CHARGED_SPEAR_MISSILE = 321009,
    SPELL_CHARGED_SPEAR_DAMAGE = 321034,
    SPELL_IONIZED_PLASTMA_CREATE_AT = 324663,
    SPELL_IONIZED_PLASMA_AT_DAMAGE = 324662,
    EVENT_ENERGY_GAIN,
    //
    SPELL_INSIDIOUS_VENOM = 317661,
    SPELL_ATTENUATED_BARRAGE = 324368,
    SPELL_ATTENUATED_BARRAGE_CREATE_AT = 324369,
    SPELL_ATTENUATED_BARRAGE_DAMAGE = 324370,

};

void AddSC_boss_kintara()
{
    
}