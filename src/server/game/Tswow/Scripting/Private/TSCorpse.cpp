/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include <memory.h>
#include "Object.h"
#include "Corpse.h"

#include "TSIncludes.h"
#include "TSCorpse.h"

TSCorpse::TSCorpse(Corpse *corpse) : TSWorldObject(corpse)
{
    this->corpse = corpse;
}

TSCorpse::TSCorpse() : TSWorldObject()
{
    this->corpse = nullptr;
}

/**
 * Returns the GUID of the [Player] that left the [Corpse] behind.
 *
 * @return uint64 ownerGUID
 */
uint64 TSCorpse::GetOwnerGUID() 
{
#if defined TRINITY || AZEROTHCORE
    return corpse->GetOwnerGUID();
#else
    return corpse->GetOwnerGuid();
#endif
}
    
/**
 * Returns the time when the [Player] became a ghost and spawned this [Corpse].
 *
 * @return uint32 ghostTime
 */
uint32 TSCorpse::GetGhostTime() 
{
    return corpse->GetGhostTime();
}
    
/**
 * Returns the [CorpseType] of a [Corpse].
 *
 *     enum CorpseType
 *     {
 *         CORPSE_BONES             = 0,
 *         CORPSE_RESURRECTABLE_PVE = 1,
 *         CORPSE_RESURRECTABLE_PVP = 2
 *
 * @return [CorpseType] corpseType
 */
uint32 TSCorpse::GetType() 
{
    return corpse->GetType();
}
    
/**
 * Sets the "ghost time" to the current time.
 *
 * See [Corpse:GetGhostTime].
 */
void TSCorpse::ResetGhostTime() 
{
    corpse->ResetGhostTime();
}
    
/**
 * Saves the [Corpse] to the database.
 */
void TSCorpse::SaveToDB() 
{
    corpse->SaveToDB();
}

TSLoot TSCorpse::GetLoot()
{
    return TSLoot(&corpse->loot);
}