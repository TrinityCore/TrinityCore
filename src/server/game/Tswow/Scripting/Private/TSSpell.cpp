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
#include "Spell.h"
#include "TSIncludes.h"
#include "TSSpell.h"
#include "SpellInfo.h"
#include "Corpse.h"
#include "Item.h"
#include "Unit.h"
#include "TSObject.h"
#include "TSUnit.h"
#include "TSWorldObject.h"

TSSpell::TSSpell(Spell *spell)
{
    this->spell = spell;
}

TSSpell::TSSpell()
{
    this->spell = nullptr;
}

/**
 * Returns `true` if the [Spell] is automatically repeating, `false` otherwise.
 *
 * @return bool isAutoRepeating
 */
bool TSSpell::IsAutoRepeat() 
{
    return spell->IsAutoRepeat();
}
    
/**
 * Returns the [Unit] that casted the [Spell].
 *
 * @return [Unit] caster
 */
TSWorldObject TSSpell::GetCaster() 
{
    return TSWorldObject(spell->GetCaster());
}
    
/**
 * Returns the cast time of the [Spell].
 *
 * @return int32 castTime
 */
int32 TSSpell::GetCastTime() 
{
    return spell->GetCastTime();
}
    
/**
 * Returns the entry ID of the [Spell].
 *
 * @return uint32 entryId
 */
uint32 TSSpell::GetEntry() 
{
    return spell->m_spellInfo->Id;
}
    
/**
 * Returns the power cost of the [Spell].
 *
 * @return uint32 powerCost
 */
uint32 TSSpell::GetPowerCost() 
{
    return spell->GetPowerCost();
}
    
/**
 * Returns the spell duration of the [Spell].
 *
 * @return int32 duration
 */
int32 TSSpell::GetDuration() 
{
#if defined TRINITY || AZEROTHCORE
    return spell->GetSpellInfo()->GetDuration();
#else
    return GetSpellDuration(spell->m_spellInfo);
#endif
}
    
/**
 * Returns the target destination coordinates of the [Spell].
 *
 * @return float x : x coordinate of the [Spell]
 * @return float y : y coordinate of the [Spell]
 * @return float z : z coordinate of the [Spell]
 */
TSPosition TSSpell::GetTargetDest() 
{
#if defined TRINITY || AZEROTHCORE
    float x, y, z;
    spell->m_targets.GetDstPos()->GetPosition(x, y, z);
#else
    float x, y, z;
    spell->m_targets.getDestination(x, y, z);
#endif
    return TSPosition(0,x,y,z,0);
}
    
/**
 * Returns the target [Object] of the [Spell].
 *
 * The target can be any of the following [Object] types:
 * - [Player]
 * - [Creature]
 * - [GameObject]
 * - [Item]
 * - [Corpse]
 *
 * @return [Object] target
 */
TSObject  TSSpell::GetTarget() 
{
#if defined TRINITY || AZEROTHCORE
    if (GameObject* target = spell->m_targets.GetGOTarget())
         return TSObject(target);
    else if (Item* target = spell->m_targets.GetItemTarget())
         return TSObject(target);
    else if (Corpse* target = spell->m_targets.GetCorpseTarget())
         return TSObject(target);
    else if (Unit* target = spell->m_targets.GetUnitTarget())
         return TSObject(target);
    else if (WorldObject* target = spell->m_targets.GetObjectTarget())
         return TSObject(target);
#else
    if (GameObject* target = spell->m_targets.getGOTarget())
         return TSObject(target);
    else if (Item* target = spell->m_targets.getItemTarget())
         return TSObject(target);
    else if (Corpse* target = spell->GetCaster()->GetMap()->GetCorpse(spell->m_targets.getCorpseTargetGuid()))
         return TSObject(target);
    else if (Unit* target = spell->m_targets.getUnitTarget())
         return TSObject(target);
#endif
}
    
/**
 * Sets the [Spell] to automatically repeat.
 *
 * @param bool repeat : set variable to 'true' for spell to automatically repeat
 */
void TSSpell::SetAutoRepeat(bool repeat) 
{
    spell->SetAutoRepeat(repeat);
}
    
/**
 * Casts the [Spell].
 *
 * @param bool skipCheck = false : skips initial checks to see if the [Spell] can be casted or not, this is optional
 */
void TSSpell::Cast(bool skipCheck) 
{
    spell->cast(skipCheck);
}
    
/**
 * Cancels the [Spell].
 */
void TSSpell::Cancel() 
{
    spell->cancel();
}
    
/**
 * Finishes the [Spell].
 */
void TSSpell::Finish() 
{
    spell->finish();
}
