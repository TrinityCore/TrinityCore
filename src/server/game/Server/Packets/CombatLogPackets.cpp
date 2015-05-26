/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "CombatLogPackets.h"
#include "SpellPackets.h"

WorldPacket const* WorldPackets::CombatLog::SpellNonMeleeDamageLog::Write()
{
    _worldPacket << Me;
    _worldPacket << CasterGUID;
    _worldPacket << SpellID;
    _worldPacket << Damage;
    _worldPacket << Overkill;
    _worldPacket << SchoolMask;
    _worldPacket << ShieldBlock;
    _worldPacket << Resisted;
    _worldPacket << Absorbed;

    _worldPacket.WriteBit(Periodic);
    _worldPacket.WriteBits(Flags, 9);
    _worldPacket.WriteBit(false); // Debug info
    _worldPacket.WriteBit(LogData.is_initialized());
    _worldPacket.FlushBits();

    if (LogData)
        _worldPacket << *LogData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::EnvironmentalDamageLog::Write()
{
    _worldPacket << Victim;
    _worldPacket << Type;
    _worldPacket << Amount;
    _worldPacket << Resisted;
    _worldPacket << Absorbed;

    _worldPacket.WriteBit(LogData.is_initialized());
    _worldPacket.FlushBits();

    if (LogData)
        _worldPacket << *LogData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellExecuteLog::Write()
{
    _worldPacket << Caster;
    _worldPacket << SpellID;

    _worldPacket << uint32(Effects.size());

    for (SpellLogEffect const& effect : Effects)
    {
        _worldPacket << effect.Effect;

        _worldPacket << uint32(effect.PowerDrainTargets.size());
        _worldPacket << uint32(effect.ExtraAttacksTargets.size());
        _worldPacket << uint32(effect.DurabilityDamageTargets.size());
        _worldPacket << uint32(effect.GenericVictimTargets.size());
        _worldPacket << uint32(effect.TradeSkillTargets.size());
        _worldPacket << uint32(effect.FeedPetTargets.size());

        for (SpellLogEffectPowerDrainParams const& powerDrainTarget : effect.PowerDrainTargets)
        {
            _worldPacket << powerDrainTarget.Victim;
            _worldPacket << powerDrainTarget.Points;
            _worldPacket << powerDrainTarget.PowerType;
            _worldPacket << powerDrainTarget.Amplitude;
        }

        for (SpellLogEffectExtraAttacksParams const& extraAttacksTarget : effect.ExtraAttacksTargets)
        {
            _worldPacket << extraAttacksTarget.Victim;
            _worldPacket << extraAttacksTarget.NumAttacks;
        }

        for (SpellLogEffectDurabilityDamageParams const& durabilityDamageTarget : effect.DurabilityDamageTargets)
        {
            _worldPacket << durabilityDamageTarget.Victim;
            _worldPacket << durabilityDamageTarget.ItemID;
            _worldPacket << durabilityDamageTarget.Amount;
        }

        for (SpellLogEffectGenericVictimParams const& genericVictimTarget : effect.GenericVictimTargets)
            _worldPacket << genericVictimTarget.Victim;

        for (SpellLogEffectTradeSkillItemParams const& tradeSkillTarget : effect.TradeSkillTargets)
            _worldPacket << tradeSkillTarget.ItemID;


        for (SpellLogEffectFeedPetParams const& feedPetTarget : effect.FeedPetTargets)
            _worldPacket << feedPetTarget.ItemID;
    }

    _worldPacket.WriteBit(LogData.is_initialized());
    _worldPacket.FlushBits();

    if (LogData)
        _worldPacket << *LogData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellHealLog::Write()
{
    _worldPacket << TargetGUID;
    _worldPacket << CasterGUID;

    _worldPacket << SpellID;
    _worldPacket << Health;
    _worldPacket << OverHeal;
    _worldPacket << Absorbed;

    _worldPacket.WriteBit(Crit);
    _worldPacket.WriteBit(Multistrike);

    _worldPacket.WriteBit(CritRollMade.is_initialized());
    _worldPacket.WriteBit(CritRollNeeded.is_initialized());
    _worldPacket.WriteBit(LogData.is_initialized());
    _worldPacket.FlushBits();

    if (CritRollMade)
        _worldPacket << *CritRollMade;

    if (CritRollNeeded)
        _worldPacket << *CritRollNeeded;

    if (LogData)
        _worldPacket << *LogData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellPeriodicAuraLog::Write()
{
    _worldPacket << TargetGUID;
    _worldPacket << CasterGUID;
    _worldPacket << SpellID;

    _worldPacket << uint32(Effects.size());

    for (SpellLogEffect const& effect : Effects)
    {
        _worldPacket << effect.Effect;
        _worldPacket << int32(effect.Amount);
        _worldPacket << int32(effect.OverHealOrKill);
        _worldPacket << int32(effect.SchoolMaskOrPower);
        _worldPacket << int32(effect.AbsorbedOrAmplitude);
        _worldPacket << int32(effect.Resisted);

        _worldPacket.WriteBit(effect.Crit);
        _worldPacket.WriteBit(effect.Multistrike);

        if (_worldPacket.WriteBit(effect.DebugInfo.is_initialized()))
        {
            _worldPacket << float(effect.DebugInfo->CritRollMade);
            _worldPacket << float(effect.DebugInfo->CritRollNeeded);
        }

        _worldPacket.FlushBits();
    }

    _worldPacket.WriteBit(LogData.is_initialized());
    _worldPacket.FlushBits();
    if (LogData)
        _worldPacket << *LogData;

    return &_worldPacket;
}
