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

#include "iron_docks.hpp"
#include "GameObject.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum eSpells
{
    SpellBloodyCorpseExplosion  = 73163
};

enum eEvents
{
    EventRelease = 1
};

enum eAction
{
    ActionRelease = 1,
    ActionCountMovementThundlers, ///< Counts the movement of the 3 thundlers and then kicks in the event
    ActionExplodeSelf,
    ActionFinishCosmeticEvent,
    ActionStartSpell,
    ActionFinishSpell
};

enum eCosmeticEvents
{
    EventCosmetic01 = 1,
    EventCosmetic02,
    EventCosmetic03,
    EventCosmetic04,
    EventCosmetic05,
    EventCosmetic06
};

enum eTalks
{
    TalkZoggosh11 = 20, ///< Aye! aye! sir! (44058)
    TalkZoggosh08 = 17, ///< Ahm... are you sure you want to let that thing out of it's cage? I don't think we fed it since we've found it. (44055)
    TalkZoggosh07 = 16, ///< Captain they're almost here.. what are we do now!? (44054)
    TalkKoramar09 = 31, ///< I'm not playing these games anymore.. bring in the saber on and we'll be done with it. (46908)
    TalkKoramar11 = 32, ///< Put a muzzle on it (46909)
    TalkKoramar10 = 33  ///< I didn't mean.. the Cat... (46910)
};

enum eCreatures
{
    CreatureWolf        = 89012,
    CreatureRylak       = 89011,
    CreatureGuard       = 83390,
    /// Dests
    CreatureWolfDest     = 89022,
    CreatureRylakDest    = 89021,
    CreatureAcidPool     = 214746
};

enum eMovementInformed
{
    MovementInformWanlderingThundlerOshirFirstMovement = 10,
    MovementInformWanlderingThundlerOshirMoveToBreakDoor,
    MovementInformedOshirKillTargets,
    MovementInformedOshirFinishEvent,
    MovementInformedOshirCorpseExplosion,
    MovementInformedOshirBreakOut,
    MovementInformOshirPrimalAssaultDestArrival,
    MovementInformedTimeToFeed
};

Position const g_NewHomePos = { 6945.15f, -1098.29f, 4.603f, 4.579627f };

Position const g_NpcSpawnPos = { 6924.00f, -1090.61f, 4.604f, 0.102262f };

Position const g_NpcMovePos[3] =
{
    { 6972.43f, -1094.44f, 4.962f, 0.903368f },
    { 6969.16f, -1089.79f, 4.600f, 0.881810f },
    { 6964.44f, -1085.31f, 4.603f, 0.102262f }
};

///< Wandlering Thundlers
Position const g_MoveToDoorPos = { 6970.82f, -1090.432f, 4.962442f };
Position const g_FleePosition = {6931.40f, -1113.588f, 4.603908f };

void AddSC_boss_oshir()
{
    
}
