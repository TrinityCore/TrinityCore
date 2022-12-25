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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_LIGHTNING_SHIELD_AURA = 263246,
    SPELL_STATIC_SHOCK = 263257,
    SPELL_JOLT = 263318,
    SPELL_CONDUCTION = 263371,
    SPELL_GUST = 263775,
    SPELL_CYCLONE_STRIKE_CAST = 261773,
    SPELL_CYCLONE_STRIKE_DMG = 263573,
    SPELL_CYCLONE_STRIKE_AT = 263325,
    SPELL_ARC_DASH = 263425,
    SPELL_ARCING_BLADE = 263234,
    SPELL_A_PEAR_OF_THUNDER = 263365
};

enum Events
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_JOLT,
    EVENT_CONDUCTION,
    EVENT_STATIC_SHOCK,
    EVENT_CYCLONE_STRIKE,
    EVENT_A_PEAL_OF_THUNDER,
    EVENT_ARC_DASH,
    EVENT_GUST,
    EVENT_ARCING_BLADE,
    EVENT_GALE_FORCE,
};

enum Timers
{
    TIMER_CHECK_ENERGY = 3 * IN_MILLISECONDS,
    TIMER_GUST = 10 * IN_MILLISECONDS,
    TIMER_JOLT = 5 * IN_MILLISECONDS,
    TIMER_CONDUCTION = 15 * IN_MILLISECONDS,
    TIMER_CYCLONE_STRIKE = 25 * IN_MILLISECONDS,
    TIMER_A_PEAL_OF_THUNDER = 10 * IN_MILLISECONDS,
    TIMER_ARCING_BLADE = 12 * IN_MILLISECONDS,
    TIMER_GALE_FORCE = 22 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_SHIELDED = 1,
    ACTION_FINISH_OTHER,
};

enum Creatures
{
    BOSS_ADDERIS = 133379,
    BOSS_ASPIX = 133944,
};

const Position centerPos = { 3344.53f, 3148.79f, 88.43f }; //45y

uint8 AdderisAndAspix(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* adderis = instance->GetCreature(BOSS_ADDERIS);
    if (adderis && adderis->IsAlive())
        ++count;

    Creature* aspix = instance->GetCreature(BOSS_ASPIX);
    if (aspix && aspix->IsAlive())
        ++count;

    return count;
}

// gale force forcemovement

#define AGGRO_ASPIX "None can stand against our empire!"
#define SHIELD_ADDERIS "Severed!"
#define SHIELD_ASPIX "Break them, Adderis!"
#define ARCING_SLASH_ADDERIS "Arcing slash!"
#define ASPIX_DEATH "What will become... of the empire..."
#define ADDERIS_DEATH "The sands...take me..."

void AddSC_boss_adderis_and_aspix()
{
    
}
