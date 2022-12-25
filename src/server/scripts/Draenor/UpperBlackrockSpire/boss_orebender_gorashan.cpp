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

#include "upper_blackrock_spire.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO                = 0,
    SAY_WARN_ACTIVE_CONDUIT  = 1,
    SAY_ACTIVE_CONDUIT_2     = 2,
    SAY_ACTIVE_CONDUIT_4     = 3,
    SAY_ACTIVE_CONDUIT_6     = 4,
    SAY_KILL_PLAYER          = 5,
    SAY_DESTROY              = 6,
    SAY_DEATH                = 7
};

enum Spells
{
    //intoRune
    SPELL_RUNE_GLOW              = 154226,
    //Gorashan
    SPELL_SEAL_CONDUIT_1         = 154302,
    SPELL_SEAL_CONDUIT_2         = 154900,
    SPELL_SEAL_CONDUIT_3         = 154901,
    SPELL_UNHARNESSED_POWER      = 154265,
    SPELL_POWER_CONDUIT          = 154294,
    SPELL_POWER_CONDUIT_AURA     = 166168,
    SPELL_POWER_CONDUIT_HANGOVER = 166169,
    //lighting sphere
    SPELL_ELECTRIC_PULSE         = 154335,
    //Phase 1
    SPELL_BLADES_OF_STEEL        = 154417,
    SPELL_SHRAPNEL_NOVA          = 154448,
    SPELL_LODESTONE_SPIKE        = 154435,
    SPELL_LODESTONE_SPIKE_AT     = 154428,
    //Phase 2
    SPELL_THUNDER_CACOPHONY      = 154899,
    //Open Cage
    SPELL_DISRUPTING_CONDUIT     = 154296
};

enum eEvents
{
    EVENT_BLADES_OF_STEEL       = 1,
    EVENT_SHRAPNEL_NOVA         = 2,
    EVENT_THUNDER_CACOPHONY     = 3,
    EVENT_LODESTONE_SPIKE       = 4
};

enum eActions
{
    ACTION_REMOVE_CONDUIT    = 1
};

enum Phases
{
    PHASE_BATTLE_1   = 1,
    PHASE_BATTLE_2   = 2
};

enum lightingPath
{
    LIGHTNING_PATH_1 = 7646400,
    LIGHTNING_PATH_2 = 7646401
};

void AddSC_boss_orebender_gorashan()
{
   
}
