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

#include "grimrail_depot.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum eNitroggThundertowerTalks
{
    TalkAggro = 1,          ///< Ready!!! [46109]
    TalkDeath,              ///< i didn't ... even ... try .. [46110]
    TalkCommanderEvent01,   ///< Let'em have it boys! [46111]
    TalkCommanderEvent02,   ///< Give'em all you got! [46112]
    TalkCommanderEvent03,   ///< I've got my sights on you! [46113]
    TalkCommanderEvent04,   ///< RAPID FIRE!!! [46114]
    TalkCommanderEvent05,   ///< Hah! Let's take this down to your level. [46115]
    TalkIntro01,            ///< Who dares challenge me? [46116]
    TalkIntro02,            ///< They are here... get up! [46117]
    TalkIntro03,            ///< Formation! NOW!! [46118]
    TalkIntro04,            ///< Come on swines! move.. like you've signed up for this. [46118]
    TalkKill01,             ///< Ha ha ha Another contender down! [46120]
    TalkKill02              ///< So weak! [46121]
};

enum eNitroggThundertowerActions
{
    ActionActivateSlagBlast = 1
};

enum eNitroggThundertowerMovments
{
    MovementPointThreeRemoveFlags = 1,
    MovementAboardOnTurret,
};

enum eNitroggThundertowerPhases
{
    PhaseOOC01,
    PhaseOOC02
};

enum eNitroggThundertowerSpellVisuals
{
    SpellFireSuppressionVisualId = 41206
};

#define OOCOrientation 4.753863f

Position const g_PositionNitroggtowerWaypoints[3] =
{
    { 1646.740f, 1719.148f, 106.951f },
    { 1646.630f, 1737.518f, 106.951f },
    { 1646.513f, 1776.855f, 107.634f }
};

Position const g_PositionBlackrockTurretPosition[6]
{
    /// Starts from left and ends at the right one
    {1628.628f, 1779.534f, 107.981f}, /// First
    { 1628.576f, 1814.675f, 107.983f }, /// Second
    { 1628.486f, 1837.735f, 107.989f }, /// Third
    { 1664.699f, 1826.430f, 108.154f }, /// Fourth
    // {1665.088f, 1838.148f, 108.154f},
    { 1664.667f, 1814.876f, 108.291f }, /// Fifth
    { 1664.475f, 1792.299f, 108.261f }, /// Sixth
    // {1664.599f, 1779.760f, 108.220f}
};

Position const g_PositionSlagBlast[3] =
{
    { 1646.737f, 1818.399f, 107.412f },
    { 1646.204f, 1796.842f, 107.471f },
    { 1646.544f, 1840.300f, 107.635f }
};

Position const g_PositionReinforce1 = { 1628.354f, 1851.177f, 114.154f, 4.650741f }; /// Right to the turret
Position const g_PositionReinforce2 = { 1653.266f, 1794.999f, 107.767f, 2.742215f }; /// Near door
Position const g_PositionReinforce3 = { 1659.568f, 1813.276f, 108.144f, 3.194596f }; /// Left to the turret

#define g_NitroggDisplay 55162
#define g_TrainFloorPositionZ 107.479

void AddSC_boss_nitrogg_thundertower()
{
    
}
