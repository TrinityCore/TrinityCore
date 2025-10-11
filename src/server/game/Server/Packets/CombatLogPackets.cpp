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
#include "PacketOperators.h"
#include "Spell.h"
#include "UnitDefines.h"

namespace WorldPackets::CombatLog
{
ByteBuffer& operator<<(ByteBuffer& data, CombatWorldTextViewerInfo const& worldTextViewer)
{
    data << worldTextViewer.ViewerGUID;
    data << OptionalInit(worldTextViewer.ColorType);
    data << OptionalInit(worldTextViewer.ScaleType);
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
    *this << int32(Flags);
    *this << Size<uint32>(WorldTextViewers);
    *this << Size<uint32>(Supporters);

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    *this << Bits<1>(Periodic);
    *this << Bits<1>(false); // Debug info
    WriteLogDataBit();
    *this << OptionalInit(ContentTuning);
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
    *this << Size<uint32>(*Effects);

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
                *this << int8(powerDrainTarget.PowerType);
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
    *this << Size<uint32>(Supporters);

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    *this << Bits<1>(Crit);
    *this << OptionalInit(CritRollMade);
    *this << OptionalInit(CritRollNeeded);
    WriteLogDataBit();
    *this << OptionalInit(ContentTuning);
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

ByteBuffer& operator<<(ByteBuffer& data, PeriodicalAuraLogEffectDebugInfo const& debugInfo)
{
    data << float(debugInfo.CritRollMade);
    data << float(debugInfo.CritRollNeeded);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PeriodicAuraLogEffect const& effect)
{
    data << int32(effect.Effect);
    data << int32(effect.Amount);
    data << int32(effect.OriginalDamage);
    data << int32(effect.OverHealOrKill);
    data << int32(effect.SchoolMaskOrPower);
    data << int32(effect.AbsorbedOrAmplitude);
    data << int32(effect.Resisted);
    data << Size<uint32>(effect.Supporters);

    for (Spells::SpellSupportInfo const& supportInfo : effect.Supporters)
        data << supportInfo;

    data << Bits<1>(effect.Crit);
    data << OptionalInit(effect.DebugInfo);
    data << OptionalInit(effect.ContentTuning);
    data.FlushBits();

    if (effect.ContentTuning)
        data << *effect.ContentTuning;

    if (effect.DebugInfo)
        data << *effect.DebugInfo;

    return data;
}

WorldPacket const* SpellPeriodicAuraLog::Write()
{
    *this << TargetGUID;
    *this << CasterGUID;
    *this << int32(SpellID);
    *this << Size<uint32>(Effects);
    WriteLogDataBit();
    FlushBits();

    for (PeriodicAuraLogEffect const& effect : Effects)
        *this << effect;

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
    *this << int8(Type);
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
    buffer << OptionalInit(missEntry.Debug);
    if (missEntry.Debug)
        buffer << *missEntry.Debug;

    buffer.FlushBits();

    return buffer;
}

WorldPacket const* SpellMissLog::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << Caster;
    _worldPacket << Size<uint32>(Entries);
    for (SpellLogMissEntry const& missEntry : Entries)
        _worldPacket << missEntry;

    return &_worldPacket;
}

WorldPacket const* ProcResist::Write()
{
    _worldPacket << Caster;
    _worldPacket << Target;
    _worldPacket << int32(SpellID);
    _worldPacket << OptionalInit(Rolled);
    _worldPacket << OptionalInit(Needed);
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
    _worldPacket << Bits<1>(IsPeriodic);
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

    *this << Size<uint32>(attackRoundInfo);
    _worldPacket.append(attackRoundInfo);
    _fullLogPacket.append(attackRoundInfo);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& buffer, SpellDispellData const& dispellData)
{
    buffer << int32(dispellData.SpellID);
    buffer << Bits<1>(dispellData.Harmful);
    buffer << OptionalInit(dispellData.Rolled);
    buffer << OptionalInit(dispellData.Needed);
    buffer.FlushBits();

    if (dispellData.Rolled)
        buffer << int32(*dispellData.Rolled);

    if (dispellData.Needed)
        buffer << int32(*dispellData.Needed);

    return buffer;
}

WorldPacket const* SpellDispellLog::Write()
{
    _worldPacket << Bits<1>(IsSteal);
    _worldPacket << Bits<1>(IsBreak);
    _worldPacket << TargetGUID;
    _worldPacket << CasterGUID;
    _worldPacket << int32(DispelledBySpellID);

    _worldPacket << Size<uint32>(DispellData);
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
    *this << Size<uint32>(Supporters);

    for (Spells::SpellSupportInfo const& supportInfo : Supporters)
        *this << supportInfo;

    *this << Bits<1>(Crit);
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
    _worldPacket << OptionalInit(ContentTuning);
    _worldPacket.FlushBits();

    if (ContentTuning)
        _worldPacket << *ContentTuning;

    return &_worldPacket;
}
}
