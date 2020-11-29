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

#include "TSIncludes.h"
#include "TSAura.h"
#include "TSWorldObject.h"
#include "SpellAuras.h"
#include "TSUnit.h"

TSAura::TSAura(Aura *aura)
{
    this->aura = aura;
}

TSAura::TSAura()
{
    this->aura = nullptr;
}

/**
 * Returns the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
 *
 * @return [Unit] caster
 */
TSUnit  TSAura::GetCaster() 
{
     return TSUnit(aura->GetCaster());
}
    
/**
 * Returns the GUID of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
 *
 * @return string caster_guid : the GUID of the Unit as a decimal string
 */
uint64 TSAura::GetCasterGUID() 
{
#if defined TRINITY || AZEROTHCORE
    return aura->GetCasterGUID();
#else
    return aura->GetCasterGuid();
#endif
}
    
/**
 * Returns the level of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
 *
 * @return uint32 caster_level
 */
uint32 TSAura::GetCasterLevel() 
{
#ifdef TRINITY
    return aura->GetCaster()->GetLevel();
#else
    return aura->GetCaster()->getLevel();
#endif
}
    
/**
 * Returns the amount of time left until the [Aura] expires.
 *
 * @return int32 duration : amount of time left in milliseconds
 */
int32 TSAura::GetDuration() 
{
#if defined TRINITY || AZEROTHCORE
    return aura->GetDuration();
#else
    return aura->GetAuraDuration();
#endif
}
    
/**
 * Returns the ID of the [Spell] that caused this [Aura] to be applied.
 *
 * @return uint32 aura_id
 */
uint32 TSAura::GetAuraId() 
{
    return aura->GetId();
}
    
/**
 * Returns the amount of time this [Aura] lasts when applied.
 *
 * To determine how much time has passed since this Aura was applied,
 *   subtract the result of [Aura]:GetDuration from the result of this method.
 *
 * @return int32 max_duration : the maximum duration of the Aura, in milliseconds
 */
int32 TSAura::GetMaxDuration() 
{
#if defined TRINITY || AZEROTHCORE
    return aura->GetMaxDuration();
#else
    return aura->GetAuraMaxDuration();
#endif
}
    
/**
 * Returns the number of times the [Aura] has "stacked".
 *
 * This is the same as the number displayed on the [Aura]'s icon in-game.
 *
 * @return uint32 stack_amount
 */
uint32 TSAura::GetStackAmount() 
{
    return aura->GetStackAmount();
}
    
/**
 * Returns the [Unit] that the [Aura] has been applied to.
 *
 * @return [Unit] owner
 */
TSWorldObject  TSAura::GetOwner() 
{
#if defined TRINITY || defined AZEROTHCORE
     return TSWorldObject(aura->GetOwner());
#else
     return TSWorldObject(aura->GetTarget());
#endif
}
    
/**
 * Change the amount of time before the [Aura] expires.
 *
 * @param int32 duration : the new duration of the Aura, in milliseconds
 */
void TSAura::SetDuration(int32 duration) 
{
#if defined TRINITY || defined AZEROTHCORE
    aura->SetDuration(duration);
#else
    aura->GetHolder()->SetAuraDuration(duration);
#if (defined(TBC) || defined(CLASSIC))
    aura->GetHolder()->UpdateAuraDuration();
#else
    aura->GetHolder()->SendAuraUpdate(false);
#endif
#endif
}
    
/**
 * Change the maximum amount of time before the [Aura] expires.
 *
 * This does not affect the current duration of the [Aura], but if the [Aura]
 *   is reset to the maximum duration, it will instead change to `duration`.
 *
 * @param int32 duration : the new maximum duration of the Aura, in milliseconds
 */
void TSAura::SetMaxDuration(int32 duration) 
{
#if defined TRINITY || defined AZEROTHCORE
    aura->SetMaxDuration(duration);
#else
    aura->GetHolder()->SetAuraMaxDuration(duration);
#if (defined(TBC) || defined(CLASSIC))
    aura->GetHolder()->UpdateAuraDuration();
#else
    aura->GetHolder()->SendAuraUpdate(false);
#endif
#endif
}
    
/**
 * Change the amount of times the [Aura] has "stacked" on the [Unit].
 *
 * If `amount` is greater than or equal to the current number of stacks,
 *   then the [Aura] has its duration reset to the maximum duration.
 *
 * @param uint32 amount
 */
void TSAura::SetStackAmount(uint8 amount) 
{
#if defined TRINITY || defined AZEROTHCORE
    aura->SetStackAmount(amount);
#else
    aura->GetHolder()->SetStackAmount(amount);
#endif
}
    
/**
 * Remove this [Aura] from the [Unit] it is applied to.
 */
void TSAura::Remove() 
{
#if defined TRINITY || defined AZEROTHCORE
    aura->Remove();
#else
    aura->GetTarget()->RemoveSpellAuraHolder(aura->GetHolder(), AURA_REMOVE_BY_CANCEL);
#endif
}
