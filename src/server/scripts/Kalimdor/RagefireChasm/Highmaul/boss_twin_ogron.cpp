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

# include "highmaul.h"
#include "SpellMgr.h"

Position const g_PolMovePos[3] =
{
    { 4031.884f, 8587.818f, 343.6748f, 4.55423f },
    { 4028.196f, 8568.284f, 341.8094f, 4.51496f },
    { 4012.667f, 8523.617f, 327.2006f, 5.63415f }
};

Position const g_PolJumpPos = { 4043.08f, 8500.94f, 322.226f, 5.63415f };

Position const g_PhemosMovePos[3] =
{
    { 3949.489f, 8484.431f, 343.7032f, 0.31307f },
    { 3974.303f, 8497.139f, 335.4293f, 0.40340f },
    { 4002.597f, 8510.825f, 327.1879f, 5.63415f }
};

Position const g_PhemosJumpPos = { 4028.90f, 8485.51f, 322.226f, 5.63415f };

float const g_GorthenonFloor = 326.0f;

Position const g_CenterPos = { 4062.38f, 8470.91f, 322.226f, 0.0f };

float const g_CircleToCenterDist = 30.0f;
float const g_BlazeDistToCenter = 136.0f;

void RespawnOgrons(Creature* source, InstanceScript* p_Instance)
{
    if (source == nullptr || p_Instance == nullptr)
        return;

    if (Creature* l_Other = p_Instance->GetCreature((source->GetEntry() == eHighmaulCreatures::Phemos) ? eHighmaulCreatures::Pol : eHighmaulCreatures::Phemos))
    {
        l_Other->Respawn();
        l_Other->GetMotionMaster()->MoveTargetedHome();
    }
}

void StartOgrons(Creature* source, Unit* target)
{
    if (source == nullptr || target == nullptr)
        return;

    if (Creature* l_Other = source->FindNearestCreature((source->GetEntry() == eHighmaulCreatures::Phemos) ? eHighmaulCreatures::Pol : eHighmaulCreatures::Phemos, 30.0f))
        l_Other->AI()->AttackStart(target);
}

void AddSC_boss_twin_ogron()
{
    
}
