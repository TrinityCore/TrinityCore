/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "BattlePet.h"
#include "BattlePetDataStore.h"
#include "DB2Stores.h"
#include "Containers.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldSession.h"

void BattlePet::CalculateStats()
{
    float health = 0.0f;
    float power = 0.0f;
    float speed = 0.0f;

    // get base breed stats
    BattlePetStateMap const* breedState = sBattlePetDataStore->GetPetBreedStats(PacketInfo.Breed);
    if (!breedState) // non existing breed id
        return;

    health = breedState->at(STATE_STAT_STAMINA);
    power = breedState->at(STATE_STAT_POWER);
    speed = breedState->at(STATE_STAT_SPEED);

    // modify stats depending on species - not all pets have this
    BattlePetStateMap const* speciesState = sBattlePetDataStore->GetPetSpeciesStats(PacketInfo.Species);
    if (speciesState)
    {
        health += speciesState->at(STATE_STAT_STAMINA);
        power += speciesState->at(STATE_STAT_POWER);
        speed += speciesState->at(STATE_STAT_SPEED);
    }

    // modify stats by quality
    for (BattlePetBreedQualityEntry const* battlePetBreedQuality : sBattlePetBreedQualityStore)
    {
        if (battlePetBreedQuality->QualityEnum == PacketInfo.Quality)
        {
            health *= battlePetBreedQuality->StateMultiplier;
            power *= battlePetBreedQuality->StateMultiplier;
            speed *= battlePetBreedQuality->StateMultiplier;
            break;
        }
        // TOOD: add check if pet has existing quality
    }

    // scale stats depending on level
    health *= PacketInfo.Level;
    power *= PacketInfo.Level;
    speed *= PacketInfo.Level;

    // set stats
    // round, ceil or floor? verify this
    PacketInfo.MaxHealth = uint32((round(health / 20) + 100));
    PacketInfo.Power = uint32(round(power / 100));
    PacketInfo.Speed = uint32(round(speed / 100));
}
