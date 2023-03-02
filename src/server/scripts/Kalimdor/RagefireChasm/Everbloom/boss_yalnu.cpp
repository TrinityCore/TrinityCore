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
#include "CombatAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "the_everbloom.h"

enum eYalnuTalks
{
    ///< Yalnu
	GenesaurBossAggro = 40,  ///<(47096)
	GenesaurBossDeath = 41,  ///<(47094)

    ///< Lady Baihu
    LadyBaihuIntro    = 50 , ///< The portal is lost! we must stop the beast before it can escape!
    LadyBaihuAggro    = 51,  ///< We've got its attention!
    LadyBaihuSpell01  = 52,  ///< The vines are overtaking everything!
    LadyBaihuSpell02  = 53,  ///< Quickly. drow it towards the flames!
    LadyBaihuSpell03  = 54  ///< Look out!
};

enum YalnuEnums
{
    // Yalnu Pre
    ANIMKIT_PRE                             = 680,
    SPELL_TELEPORT_OUT                      = 142193,

    // Yalnu
    NPC_MAGE                                = 84329,
    NPC_COLOSSAL_BLOW                       = 84964,
    NPC_GROW_WEAPON                         = 84664,
    NPC_VICIOUS_MANDRAGORA                  = 84399,
    NPC_GNARLED_ANCIENT                     = 84400,
    NPC_SWIFT_SPROUTLING                    = 84401,
    ANIMKIT                                 = 6864,
    SPELL_VEHICLE_HARDCODED                 = 46598,
    SPELL_FONT_OF_LIFE_MISSILE              = 169120,
    SPELL_COLOSSAL_BLOW                     = 169756,
    SPELL_COLOSSAL_BLOW_YALNU               = 169179,
    SPELL_ENTANGLEMENT                      = 169251,
    SPELL_ENTANGLEMENT_UNIT_SPAWN           = 169237,
    SPELL_ENTANGLEMENT_PLAYER_SPAWN         = 170127,
    SPELL_ENTANGLEMENT_VISUAL               = 169192,
    SPELL_ENTANGLEMENT_PLAYER_DAMAGE        = 170132,
    SPELL_ENTANGLEMENT_UNIT_DAMAGE          = 169240,
    SPELL_GERMINATE_ARBORBLADE_DISARM       = 169320,
    SPELL_GERMINATE_ARBORBLADE              = 169265,
    SPELL_GERMINATE_ARBORBLADE_VISUAL       = 169266,
    SPELL_GERMINATE_ARBORBLADE_MOD_SIZE     = 169306,
    SPELL_GENESIS                           = 169390,
    SPELL_GENESIS_VISUAL                    = 169613,
};

void AddSC_boss_yalnu()
{
  
}
