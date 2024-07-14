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

#include "CombatLogPackets.h"
#include "UnitDefines.h"

namespace WorldPackets::CombatLog
{
ByteBuffer& operator<<(ByteBuffer& data, CombatWorldTextViewerInfo const& worldTextViewer)
{
    data << worldTextViewer.ViewerGUID;
    data.WriteBit(worldTextViewer.ColorType.has_value());
    data.WriteBit(worldTextViewer.ScaleType.has_value());
    data.FlushBits();

    if (worldTextViewer.ColorType)
        data << uint8(*worldTextViewer.ColorType);

    if (worldTextViewer.ScaleType)
        data << uint8(*worldTextViewer.ScaleType);

    return data;
}

WorldPacket const* SpellNonMeleeDamageLog::Write()
{
    *this << Me;
    *this << CasterGUID;
    *this << CastID;
    *this << int32(SpellID);
    *this << Visual;
    *this << int32(Damage);
    *this << int32(OriginalDamage);
    *this << int32(Overkill);
    *this << uint8(SchoolMask);
    *this << int32(Absorbed);
    *this << int32(Resisted);
    *this << int32(ShieldBlock);
    *this << uint32(WorldTextViewers.size());
    *this << uint32(Supporters.size());

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    WriteBit(Periodic);
    WriteBits(Flags, 7);
    WriteBit(false); // Debug info
    WriteLogDataBit();
    WriteBit(ContentTuning.has_value());
    FlushBits();

    for (CombatWorldTextViewerInfo const& worldTextViewer : WorldTextViewers)
        *this << worldTextViewer;

    WriteLogData();
    if (ContentTuning)
        *this << *ContentTuning;

    return &_worldPacket;
}

WorldPacket const* EnvironmentalDamageLog::Write()
{
    *this << Victim;
    *this << uint8(Type);
    *this << int32(Amount);
    *this << int32(Resisted);
    *this << int32(Absorbed);
    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* SpellExecuteLog::Write()
{
    *this << Caster;
    *this << int32(SpellID);
    *this << uint32(Effects->size());

    for (SpellLogEffect const& effect : *Effects)
    {
        *this << int32(effect.Effect);

        *this << uint32(effect.PowerDrainTargets ? effect.PowerDrainTargets->size() : 0);
        *this << uint32(effect.ExtraAttacksTargets ? effect.ExtraAttacksTargets->size() : 0);
        *this << uint32(effect.DurabilityDamageTargets ? effect.DurabilityDamageTargets->size() : 0);
        *this << uint32(effect.GenericVictimTargets ? effect.GenericVictimTargets->size() : 0);
        *this << uint32(effect.TradeSkillTargets ? effect.TradeSkillTargets->size() : 0);
        *this << uint32(effect.FeedPetTargets ? effect.FeedPetTargets->size() : 0);

        if (effect.PowerDrainTargets)
        {
            for (SpellLogEffectPowerDrainParams const& powerDrainTarget : *effect.PowerDrainTargets)
            {
                *this << powerDrainTarget.Victim;
                *this << uint32(powerDrainTarget.Points);
                *this << uint32(powerDrainTarget.PowerType);
                *this << float(powerDrainTarget.Amplitude);
            }
        }

        if (effect.ExtraAttacksTargets)
        {
            for (SpellLogEffectExtraAttacksParams const& extraAttacksTarget : *effect.ExtraAttacksTargets)
            {
                *this << extraAttacksTarget.Victim;
                *this << uint32(extraAttacksTarget.NumAttacks);
            }
        }

        if (effect.DurabilityDamageTargets)
        {
            for (SpellLogEffectDurabilityDamageParams const& durabilityDamageTarget : *effect.DurabilityDamageTargets)
            {
                *this << durabilityDamageTarget.Victim;
                *this << int32(durabilityDamageTarget.ItemID);
                *this << int32(durabilityDamageTarget.Amount);
            }
        }

        if (effect.GenericVictimTargets)
            for (SpellLogEffectGenericVictimParams const& genericVictimTarget : *effect.GenericVictimTargets)
                *this << genericVictimTarget.Victim;

        if (effect.TradeSkillTargets)
            for (SpellLogEffectTradeSkillItemParams const& tradeSkillTarget : *effect.TradeSkillTargets)
                *this << int32(tradeSkillTarget.ItemID);

        if (effect.FeedPetTargets)
            for (SpellLogEffectFeedPetParams const& feedPetTarget : *effect.FeedPetTargets)
                *this << int32(feedPetTarget.ItemID);
    }

    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* SpellHealLog::Write()
{
    *this << TargetGUID;
    *this << CasterGUID;
    *this << int32(SpellID);
    *this << int32(Health);
    *this << int32(OriginalHeal);
    *this << int32(OverHeal);
    *this << int32(Absorbed);
    *this << uint32(Supporters.size());

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    WriteBit(Crit);
    WriteBit(CritRollMade.has_value());
    WriteBit(CritRollNeeded.has_value());
    WriteLogDataBit();
    WriteBit(ContentTuning.has_value());
    FlushBits();

    WriteLogData();

    if (CritRollMade)
        *this << *CritRollMade;

    if (CritRollNeeded)
        *this << *CritRollNeeded;

    if (ContentTuning)
        *this << *ContentTuning;

    return &_worldPacket;
}

WorldPacket const* SpellPeriodicAuraLog::Write()
{
    *this << TargetGUID;
    *this << CasterGUID;
    *this << int32(SpellID);
    *this << uint32(Effects.size());
    WriteLogDataBit();
    FlushBits();

    for (SpellLogEffect const& effect : Effects)
    {
        *this << int32(effect.Effect);
        *this << int32(effect.Amount);
        *this << int32(effect.OriginalDamage);
        *this << int32(effect.OverHealOrKill);
        *this << int32(effect.SchoolMaskOrPower);
        *this << int32(effect.AbsorbedOrAmplitude);
        *this << int32(effect.Resisted);
        *this << uint32(effect.Supporters.size());

        for (Spells::SpellSupportInfo const& supportInfo : effect.Supporters)
            *this << supportInfo;

        WriteBit(effect.Crit);
        WriteBit(effect.DebugInfo.has_value());
        WriteBit(effect.ContentTuning.has_value());
        FlushBits();

        if (effect.ContentTuning)
            *this << *effect.ContentTuning;

        if (effect.DebugInfo)
        {
            *this << float(effect.DebugInfo->CritRollMade);
            *this << float(effect.DebugInfo->CritRollNeeded);
        }
    }

    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* SpellInterruptLog::Write()
{
    _worldPacket << Caster;
    _worldPacket << Victim;
    _worldPacket << int32(InterruptedSpellID);
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

WorldPacket const* SpellEnergizeLog::Write()
{
    *this << TargetGUID;
    *this << CasterGUID;

    *this << int32(SpellID);
    *this << int32(Type);
    *this << int32(Amount);
    *this << int32(OverEnergize);

    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* SpellInstakillLog::Write()
{
    _worldPacket << Target;
    _worldPacket << Caster;
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& buffer, SpellLogMissDebug const& missDebug)
{
    buffer << float(missDebug.HitRoll);
    buffer << float(missDebug.HitRollNeeded);
    return buffer;
}

ByteBuffer& operator<<(ByteBuffer& buffer, SpellLogMissEntry const& missEntry)
{
    buffer << missEntry.Victim;
    buffer << uint8(missEntry.MissReason);
    if (buffer.WriteBit(missEntry.Debug.has_value()))
        buffer << *missEntry.Debug;

    buffer.FlushBits();
    return buffer;
}

WorldPacket const* SpellMissLog::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << Caster;
    _worldPacket << uint32(Entries.size());
    for (SpellLogMissEntry const& missEntry : Entries)
        _worldPacket << missEntry;

    return &_worldPacket;
}

WorldPacket const* ProcResist::Write()
{
    _worldPacket << Caster;
    _worldPacket << Target;
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(Rolled.has_value());
    _worldPacket.WriteBit(Needed.has_value());
    _worldPacket.FlushBits();

    if (Rolled)
        _worldPacket << *Rolled;

    if (Needed)
        _worldPacket << *Needed;

    return &_worldPacket;
}

WorldPacket const* SpellOrDamageImmune::Write()
{
    _worldPacket << CasterGUID;
    _worldPacket << VictimGUID;
    _worldPacket << uint32(SpellID);
    _worldPacket.WriteBit(IsPeriodic);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* SpellDamageShield::Write()
{
    *this << Attacker;
    *this << Defender;
    *this << int32(SpellID);
    *this << int32(TotalDamage);
    *this << int32(OriginalDamage);
    *this << int32(OverKill);
    *this << int32(SchoolMask);
    *this << int32(LogAbsorbed);
    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* AttackerStateUpdate::Write()
{
    ByteBuffer attackRoundInfo;
    attackRoundInfo << uint32(HitInfo);
    attackRoundInfo << AttackerGUID;
    attackRoundInfo << VictimGUID;
    attackRoundInfo << int32(Damage);
    attackRoundInfo << int32(OriginalDamage);
    attackRoundInfo << int32(OverDamage);
    attackRoundInfo << uint8(SubDmg.has_value());
    if (SubDmg)
    {
        attackRoundInfo << int32(SubDmg->SchoolMask);
        attackRoundInfo << float(SubDmg->FDamage);
        attackRoundInfo << int32(SubDmg->Damage);
        if (HitInfo & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
            attackRoundInfo << int32(SubDmg->Absorbed);
        if (HitInfo & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
            attackRoundInfo << int32(SubDmg->Resisted);
    }

    attackRoundInfo << uint8(VictimState);
    attackRoundInfo << uint32(AttackerState);
    attackRoundInfo << uint32(MeleeSpellID);
    if (HitInfo & HITINFO_BLOCK)
        attackRoundInfo << int32(BlockAmount);

    if (HitInfo & HITINFO_RAGE_GAIN)
        attackRoundInfo << int32(RageGained);

    if (HitInfo & HITINFO_UNK1)
    {
        attackRoundInfo << uint32(UnkState.State1);
        attackRoundInfo << float(UnkState.State2);
        attackRoundInfo << float(UnkState.State3);
        attackRoundInfo << float(UnkState.State4);
        attackRoundInfo << float(UnkState.State5);
        attackRoundInfo << float(UnkState.State6);
        attackRoundInfo << float(UnkState.State7);
        attackRoundInfo << float(UnkState.State8);
        attackRoundInfo << float(UnkState.State9);
        attackRoundInfo << float(UnkState.State10);
        attackRoundInfo << float(UnkState.State11);
        attackRoundInfo << uint32(UnkState.State12);
    }

    if (HitInfo & (HITINFO_BLOCK | HITINFO_UNK12))
        attackRoundInfo << float(Unk);

    attackRoundInfo << ContentTuning;

    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    *this << uint32(attackRoundInfo.size());
    _worldPacket.append(attackRoundInfo);
    _fullLogPacket.append(attackRoundInfo);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& buffer, SpellDispellData const& dispellData)
{
    buffer << int32(dispellData.SpellID);
    buffer.WriteBit(dispellData.Harmful);
    buffer.WriteBit(dispellData.Rolled.has_value());
    buffer.WriteBit(dispellData.Needed.has_value());
    if (dispellData.Rolled.has_value())
        buffer << int32(*dispellData.Rolled);
    if (dispellData.Needed.has_value())
        buffer << int32(*dispellData.Needed);

    buffer.FlushBits();

    return buffer;
}

WorldPacket const* SpellDispellLog::Write()
{
    _worldPacket.WriteBit(IsSteal);
    _worldPacket.WriteBit(IsBreak);
    _worldPacket << TargetGUID;
    _worldPacket << CasterGUID;
    _worldPacket << int32(DispelledBySpellID);

    _worldPacket << uint32(DispellData.size());
    for (SpellDispellData const& data : DispellData)
        _worldPacket << data;

    return &_worldPacket;
}

WorldPacket const* SpellAbsorbLog::Write()
{
    *this << Attacker;
    *this << Victim;
    *this << int32(AbsorbedSpellID);
    *this << int32(AbsorbSpellID);
    *this << Caster;
    *this << int32(Absorbed);
    *this << int32(OriginalDamage);
    *this << uint32(Supporters.size());

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    WriteBit(Unk);
    WriteLogDataBit();
    FlushBits();
    WriteLogData();

    return &_worldPacket;
}

WorldPacket const* SpellHealAbsorbLog::Write()
{
    _worldPacket << Target;
    _worldPacket << AbsorbCaster;
    _worldPacket << Healer;
    _worldPacket << int32(AbsorbSpellID);
    _worldPacket << int32(AbsorbedSpellID);
    _worldPacket << int32(Absorbed);
    _worldPacket << int32(OriginalHeal);
    _worldPacket.WriteBit(ContentTuning.has_value());
    _worldPacket.FlushBits();

    if (ContentTuning)
        _worldPacket << *ContentTuning;

    return &_worldPacket;
}
}
