/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "DatabaseEnv.h"
#include "SQLStorage.h"
#include "SmartAI.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "ObjectDefines.h"
#include "GridDefines.h"
#include "ConditionMgr.h"
#include "CreatureTextMgr.h"

void SmartAIMgr::LoadSmartAIFromDB()
{
    //Drop Existing SmartAI List
}

SmartAI::SmartAI(Creature *c) : CreatureAI(c)
{
    // copy script to local (pretection for table reload)
}

int SmartAI::Permissible(const Creature* creature)
{
    if (creature->GetAIName() == "SmartAI")
        return PERMIT_BASE_SPECIAL;
    return PERMIT_BASE_NO;
}

void SmartAI::UpdateAI(const uint32 /*diff*/)
{
}

void SmartAI::JustRespawned()
{
}

void SmartAI::Reset()
{
}

void SmartAI::JustReachedHome()
{
}

void SmartAI::EnterCombat(Unit* /*enemy*/)
{
}

void SmartAI::EnterEvadeMode()
{
}

void SmartAI::JustDied(Unit* /*killer*/)
{
}

void SmartAI::KilledUnit(Unit* /*victim*/)
{
}

void SmartAI::JustSummoned(Creature* /*pUnit*/)
{
}

void SmartAI::AttackStart(Unit* who)
{
    if (who && me->Attack(who, true))
        me->GetMotionMaster()->MoveChase(who);
}

void SmartAI::MoveInLineOfSight(Unit* /*who*/)
{
    //CanAIAttack
}

void SmartAI::SpellHit(Unit* /*pUnit*/, const SpellEntry* /*pSpell*/)
{
}

void SmartAI::SpellHitTarget(Unit* /*target*/, const SpellEntry* /*pSpell*/)
{
}

void SmartAI::DamageTaken(Unit* /*done_by*/, uint32& /*damage*/, DamageEffectType /*damagetype*/)
{
}

void SmartAI::HealReceived(Unit* /*done_by*/, uint32& /*addhealth*/)
{
}

void SmartAI::ReceiveEmote(Player* /*pPlayer*/, uint32 /*text_emote*/)
{
}

void SmartAI::MovementInform(uint32 /*MovementType*/, uint32 /*Data*/)
{
}

void SmartAI::IsSummonedBy(Unit* /*summoner*/)
{
}

void SmartAI::DamageDealt(Unit* /*done_to*/, uint32& /*damage*/)
{
}

void SmartAI::SummonedCreatureDespawn(Creature* /*unit*/)
{
}

void SmartAI::UpdateAIWhileCharmed(const uint32 /*diff*/)
{
}

void SmartAI::CorpseRemoved(uint32& /*respawnDelay*/)
{
}

void SmartAI::PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool /*apply*/)
{
}

void SmartAI::InitializeAI()
{
}

void SmartAI::OnCharmed(bool /*apply*/)
{
}

bool SmartAI::CanAIAttack(const Unit* /*who*/) const
{
    return true;
}

void SmartAI::DoAction(const int32 /*param*/)
{
}

uint32 SmartAI::GetData(uint32 /*id*/)
{
    return 0;
}

void SmartAI::SetData(uint32 /*id*/, uint32 /*value*/)
{
}

void SmartAI::SetGUID(const uint64& /*guid*/, int32 /*id*/)
{
}

uint64 SmartAI::GetGUID(int32 /*id*/)
{
    return 0;
}

void SmartAI::MovepointReached(uint32 /*id*/)
{
}

void SmartAI::MovepointStart(uint32 /*id*/)
{
}

void SmartAI::SetRun(bool /*run*/)
{
}

void SmartAI::SetMovePathEndAction(SMARTAI_ACTION /*action*/)
{
}
