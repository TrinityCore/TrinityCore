/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef AIWORLD_SPAWNPARTICIPATIONMODE_H
#define AIWORLD_SPAWNPARTICIPATIONMODE_H

#include "Define.h"

// Runtime participation/scope boundary fix (AIWorld_Current_Roadmap.md,
// Etapa 3): data/elwynn/census/spawn_classification.csv's own
// participation_mode column, per SpawnId (not per CreatureEntry - unlike
// AgentType/WorldFactionId, this is a spawn-level distinction: the same
// CreatureEntry can have some spawns permanent and others event-gated).
// FullAgent/LightweightBackground/VanillaOnly together make up the 1863
// permanent census spawns; Excluded is the 1670 EXCLUDED_EVENT spawns that
// must never become a permanent AgentRecord - see
// SpawnParticipationCatalog's own comment for how this is enforced.
enum class SpawnParticipationMode : uint8
{
    FullAgent = 0,
    LightweightBackground = 1,
    VanillaOnly = 2,
    Excluded = 3
};

#endif // AIWORLD_SPAWNPARTICIPATIONMODE_H
