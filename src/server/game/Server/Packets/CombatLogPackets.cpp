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
#include "SpellAuraDefines.h"
#include "UnitDefines.h"

WorldPacket const* WorldPackets::CombatLog::AttackerStateUpdate::Write()
{
    _worldPacket << int32(HitInfo);
    _worldPacket << AttackerGUID.WriteAsPacked();
    _worldPacket << VictimGUID.WriteAsPacked();
    _worldPacket << int32(Damage);
    _worldPacket << int32(OverDamage);
    _worldPacket << uint8(SubDmg.has_value());

    if (SubDmg)
    {
        _worldPacket << int32(SubDmg->SchoolMask);
        _worldPacket << float(SubDmg->FDamage);
        _worldPacket << int32(SubDmg->Damage);

        if (HitInfo & (HITINFO_FULL_ABSORB | HITINFO_PARTIAL_ABSORB))
            _worldPacket << int32(SubDmg->Absorbed);
        if (HitInfo & (HITINFO_FULL_RESIST | HITINFO_PARTIAL_RESIST))
            _worldPacket << int32(SubDmg->Resisted);
    }

    _worldPacket << uint8(VictimState);
    _worldPacket << uint32(AttackerState);
    _worldPacket << uint32(MeleeSpellID);

    if (HitInfo & HITINFO_BLOCK)
        _worldPacket << int32(BlockAmount);

    if (HitInfo & HITINFO_RAGE_GAIN)
        _worldPacket << int32(RageGained);

    if (HitInfo & HITINFO_UNK1)
    {
        _worldPacket << int32(UnkState.State1);
        _worldPacket << float(UnkState.State2);
        _worldPacket << float(UnkState.State3);
        _worldPacket << float(UnkState.State4);
        _worldPacket << float(UnkState.State5);
        _worldPacket << float(UnkState.State6);
        _worldPacket << float(UnkState.State7);
        _worldPacket << float(UnkState.State8);
        _worldPacket << float(UnkState.State9);
        _worldPacket << float(UnkState.State10);
        _worldPacket << float(UnkState.State11);
        _worldPacket << int32(UnkState.State12);
        _worldPacket << int32(UnkState.State13);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellEnergizeLog::Write()
{
    _worldPacket << TargetGUID.WriteAsPacked();
    _worldPacket << CasterGUID.WriteAsPacked();
    _worldPacket << int32(SpellID);
    _worldPacket << int32(Type);
    _worldPacket << int32(Amount);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::EnvironmentalDamageLog::Write()
{
    _worldPacket << Victim;
    _worldPacket << uint8(Type);
    _worldPacket << int32(Amount);
    _worldPacket << int32(Absorbed);
    _worldPacket << int32(Resisted);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellDamageShield::Write()
{
    _worldPacket << Defender;
    _worldPacket << Attacker;
    _worldPacket << int32(SpellID);
    _worldPacket << int32(TotalDamage);
    _worldPacket << int32(OverKill);
    _worldPacket << int32(SchoolMask);
    _worldPacket << int32(LogAbsorbed);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::CombatLog::SpellLogMissDebug const& debug)
{
    data << float(debug.HitRoll);
    data << float(debug.HitRollNeeded);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::CombatLog::SpellLogMissEntry const& entry)
{
    data << entry.Victim;
    data << uint8(entry.MissReason);
    if (entry.Debug.has_value())
        data << *entry.Debug;

    return data;
}

WorldPacket const* WorldPackets::CombatLog::SpellMissLog::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << Caster;
    _worldPacket << uint8(0); // Debug
    _worldPacket << uint32(Entries.size());

    for (SpellLogMissEntry const& entry : Entries)
        _worldPacket << entry;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::CombatLog::SpellPeriodicAuraLog::Write()
{
    _worldPacket << TargetGUID.WriteAsPacked();
    _worldPacket << CasterGUID.WriteAsPacked();
    _worldPacket << int32(SpellID);
    _worldPacket << int32(Entries.size());

    for (PeriodicAuraLogEffect const& logEffect : Entries)
    {
        _worldPacket << int32(logEffect.Effect);

        switch (logEffect.Effect)
        {
            case SPELL_AURA_PERIODIC_DAMAGE:
            case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                _worldPacket << int32(logEffect.Amount);
                _worldPacket << int32(logEffect.OverHealOrKill);
                _worldPacket << int32(logEffect.SchoolMaskOrPower);
                _worldPacket << int32(logEffect.AbsorbedOrAmplitude);
                _worldPacket << int32(logEffect.Resisted);
                _worldPacket << bool(logEffect.Crit);
                break;
            case SPELL_AURA_PERIODIC_HEAL:
            case SPELL_AURA_OBS_MOD_HEALTH:
                _worldPacket << int32(logEffect.Amount);
                _worldPacket << int32(logEffect.OverHealOrKill);
                _worldPacket << int32(logEffect.AbsorbedOrAmplitude);
                _worldPacket << bool(logEffect.Crit);
                break;
            case SPELL_AURA_OBS_MOD_POWER:
            case SPELL_AURA_PERIODIC_ENERGIZE:
                _worldPacket << int32(logEffect.SchoolMaskOrPower);
                _worldPacket << int32(logEffect.Amount);
                break;
            case SPELL_AURA_PERIODIC_MANA_LEECH:
                _worldPacket << int32(logEffect.SchoolMaskOrPower);
                _worldPacket << int32(logEffect.Amount);
                _worldPacket << float(logEffect.AbsorbedOrAmplitude);
                break;
            default:
                break;
        }
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::CombatLog::SpellDispellData const& dispellData)
{
    data << int32(dispellData.SpellID);
    data << bool(dispellData.Harmful);

    return data;
}

WorldPacket const* WorldPackets::CombatLog::SpellDispellLog::Write()
{
    _worldPacket << TargetGUID.WriteAsPacked();
    _worldPacket << CasterGUID.WriteAsPacked();
    _worldPacket << int32(DispelledBySpellID);
    _worldPacket << bool(Debug);
    _worldPacket << int32(DispellData.size());

    for (SpellDispellData const& dispellData : DispellData)
        _worldPacket << dispellData;

    if (Debug)
    {
        for (SpellDispellData const& dispellData : DispellData)
        {
            _worldPacket << int32(dispellData.Needed);
            _worldPacket << int32(dispellData.Rolled);
        }
    }

    return &_worldPacket;
}
