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

#include "SpellPackets.h"
#include "MovementPackets.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include <span>

namespace WorldPackets::Spells
{
void CancelAura::Read()
{
    _worldPacket >> SpellID;
}

void CancelChannelling::Read()
{
    _worldPacket >> ChannelSpell;
}

void PetCancelAura::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
}

WorldPacket const* UpdateActionButtons::Write()
{
    _worldPacket << Reason;
    if (Reason == 0 || Reason == 1)
        _worldPacket.append(ActionButtons.data(), ActionButtons.size());

    return &_worldPacket;
}

void SetActionButton::Read()
{
    _worldPacket >> Index;
    _worldPacket >> Action;
}

WorldPacket const* SendUnlearnSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spellId : Spells)
        _worldPacket << uint32(spellId);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, AuraDataInfo const& auraData)
{
    data << int32(auraData.SpellID);
    data << uint8(auraData.Flags);
    data << uint8(auraData.CastLevel);
    data << uint8(auraData.Applications);
    if (!(auraData.Flags & AFLAG_SELF_CAST))
        data << auraData.CastUnit.WriteAsPacked();

    if (auraData.Flags & AFLAG_DURATION)
    {
        data << int32(auraData.Duration);
        data << int32(auraData.Remaining);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuraInfo const& aura)
{
    data << uint8(aura.Slot);

    if (aura.AuraData)
        data << *aura.AuraData;
    else
        data << int32(0); // SpellID

    return data;
}

WorldPacket const* AuraUpdate::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    _worldPacket << Aura; // this packet can carry multiple auras, just like SMSG_AURA_UPDATE_ALL but we don't use this, skip putting it in a vector

    return &_worldPacket;
}

WorldPacket const* AuraUpdateAll::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    for (AuraInfo const& aura : Auras)
        _worldPacket << aura;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& buffer, TargetLocation& location)
{
    buffer >> location.Transport.ReadAsPacked();
    buffer >> location.Location;

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, SpellTargetData& targetData)
{
    buffer >> targetData.Flags;

    if (targetData.Flags & (TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_CORPSE_ALLY))
        buffer >> targetData.Unit.emplace().ReadAsPacked();

    if (targetData.Flags & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
        buffer >> targetData.Item.emplace().ReadAsPacked();

    if (targetData.Flags & TARGET_FLAG_SOURCE_LOCATION)
        buffer >> targetData.SrcLocation.emplace();

    if (targetData.Flags & TARGET_FLAG_DEST_LOCATION)
        buffer >> targetData.DstLocation.emplace();

    if (targetData.Flags & TARGET_FLAG_STRING)
    {
        std::array<char, 128>& name = targetData.Name.emplace();
        buffer.read(reinterpret_cast<uint8*>(name.data()), name.size());
    }

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, MissileTrajectoryRequest& trajectory)
{
    buffer >> trajectory.Pitch;
    buffer >> trajectory.Speed;

    if (buffer.read<uint8>()) // has movement update
    {
        MovementInfo& moveUpdate = trajectory.MoveUpdate.emplace();
        buffer.read_skip<uint32>(); // opcode, always MSG_MOVE_STOP
        buffer >> moveUpdate.guid.ReadAsPacked();
        buffer >> moveUpdate;
    }

    return buffer;
}

ByteBuffer& operator>>(ByteBuffer& buffer, SpellCastRequest& request)
{
    buffer >> request.CastID;
    buffer >> request.SpellID;
    buffer >> request.SendCastFlags;

    buffer >> request.Target;

    if (request.SendCastFlags & 0x2)
        buffer >> request.MissileTrajectory.emplace();

    return buffer;
}

void CastSpell::Read()
{
    _worldPacket >> Cast;
}

void PetCastSpell::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> Cast;
}

ByteBuffer& operator<<(ByteBuffer& data, InitialSpell const& initialSpell)
{
    data << uint32(initialSpell.SpellID);
    data << uint16(initialSpell.ActionBarSlot);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellHistoryEntry const& historyEntry)
{
    data << uint32(historyEntry.SpellID);
    data << uint16(historyEntry.ItemID);
    data << uint16(historyEntry.Category);

    // send infinity cooldown in special format
    if (historyEntry.OnHold)
    {
        data << uint32(1);
        data << uint32(0x80000000);
    }
    else
    {
        data << int32(historyEntry.RecoveryTime);
        data << int32(historyEntry.CategoryRecoveryTime);
    }

    return data;
}

WorldPacket const* InitialSpells::Write()
{
    _worldPacket << uint8(InitialLogin);
    _worldPacket << uint16(Spells.size());
    for (InitialSpell const& spell : Spells)
        _worldPacket << spell;

    _worldPacket << uint16(SpellHistory.size());
    for (SpellHistoryEntry const& historyEntry : SpellHistory)
        _worldPacket << historyEntry;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, TargetLocation const& targetLocation)
{
    data << targetLocation.Transport.WriteAsPacked(); // relative position guid here - transport for example
    data << targetLocation.Location;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellTargetData const& spellTargetData)
{
    data << uint32(spellTargetData.Flags);

    if (spellTargetData.Unit)
        data << spellTargetData.Unit->WriteAsPacked();

    if (spellTargetData.Item)
        data << spellTargetData.Item->WriteAsPacked();

    if (spellTargetData.SrcLocation)
        data << *spellTargetData.SrcLocation;

    if (spellTargetData.DstLocation)
        data << *spellTargetData.DstLocation;

    if (spellTargetData.Name)
        data.append(spellTargetData.Name->data(), spellTargetData.Name->size());

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellMissStatus const& spellMissStatus)
{
    data << spellMissStatus.TargetGUID;
    data << uint8(spellMissStatus.Reason);
    if (spellMissStatus.Reason == SPELL_MISS_REFLECT)
        data << uint8(spellMissStatus.ReflectStatus);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, RuneData const& runeData)
{
    data << uint8(runeData.Start);
    data << uint8(runeData.Count);
    for (uint8 cooldown : runeData.Cooldowns)
        data << uint8(cooldown);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, MissileTrajectoryResult const& traj)
{
    data << float(traj.Pitch);
    data << uint32(traj.TravelTime);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellAmmo const& spellAmmo)
{
    data << uint32(spellAmmo.DisplayID);
    data << uint32(spellAmmo.InventoryType);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, CreatureImmunities const& immunities)
{
    data << uint32(immunities.School);
    data << uint32(immunities.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellCastData const& spellCastData)
{
    data << spellCastData.CasterGUID.WriteAsPacked();
    data << spellCastData.CasterUnit.WriteAsPacked();
    data << uint8(spellCastData.CastID);                // pending spell cast?
    data << uint32(spellCastData.SpellID);              // spellId
    data << uint32(spellCastData.CastFlags);            // cast flags
    data << uint32(spellCastData.CastTime);             // timestamp

    if (spellCastData.HitTargets && spellCastData.MissStatus)
    {
        // Hit and miss target counts are both uint8, that limits us to 255 targets for each
        // sending more than 255 targets crashes the client (since count sent would be wrong)
        // Spells like 40647 (with a huge radius) can easily reach this limit (spell might need
        // target conditions but we still need to limit the number of targets sent and keeping
        // correct count for both hit and miss).
        static constexpr std::size_t PACKET_TARGET_LIMIT = std::numeric_limits<uint8>::max();

        std::span<ObjectGuid const> hitTargets(spellCastData.HitTargets->data(), std::min(spellCastData.HitTargets->size(), PACKET_TARGET_LIMIT));
        data << uint8(hitTargets.size());
        for (ObjectGuid const& target : hitTargets)
            data << target;

        std::span<SpellMissStatus const> missTargets(spellCastData.MissStatus->data(), std::min(spellCastData.MissStatus->size(), PACKET_TARGET_LIMIT));
        data << uint8(missTargets.size());
        for (SpellMissStatus const& status : missTargets)
            data << status;
    }

    data << spellCastData.Target;

    if (spellCastData.RemainingPower)
        data << uint32(*spellCastData.RemainingPower);

    if (spellCastData.RemainingRunes)
        data << *spellCastData.RemainingRunes;

    if (spellCastData.MissileTrajectory)
        data << *spellCastData.MissileTrajectory;

    if (spellCastData.Ammo)
        data << *spellCastData.Ammo;

    if (spellCastData.Immunities)
        data << *spellCastData.Immunities;

    if (spellCastData.CastFlags & CAST_FLAG_VISUAL_CHAIN)
    {
        data << uint32(0);
        data << uint32(0);
    }

    if (spellCastData.DestLocSpellCastIndex)
        data << uint8(*spellCastData.DestLocSpellCastIndex);

    if (spellCastData.TargetPoints)
    {
        data << int32(spellCastData.TargetPoints->size());
        for (TargetLocation const& targetPoint : *spellCastData.TargetPoints)
        {
            data << targetPoint.Location;
            data << targetPoint.Transport;
        }
    }

    return data;
}

WorldPacket const* SpellStart::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

WorldPacket const* SpellGo::Write()
{
    _worldPacket << Cast;

    return &_worldPacket;
}

WorldPacket const* LearnedSpell::Write()
{
    _worldPacket << int32(SpellID);
    _worldPacket << uint16(ActionBarSlot);

    return &_worldPacket;
}

WorldPacket const* SpellFailure::Write()
{
    _worldPacket << CasterUnit.WriteAsPacked();
    _worldPacket << uint8(CastID);
    _worldPacket << uint32(SpellID);
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* SpellFailedOther::Write()
{
    _worldPacket << CasterUnit.WriteAsPacked();
    _worldPacket << uint8(CastID);
    _worldPacket << uint32(SpellID);
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, SpellModifier const& spellModifier)
{
    data << uint8(spellModifier.ClassIndex);
    data << uint8(spellModifier.ModIndex);
    data << int32(spellModifier.ModifierValue);

    return data;
}

WorldPacket const* SetSpellModifier::Write()
{
    _worldPacket << Modifier;

    return &_worldPacket;
}

WorldPacket const* UnlearnedSpell::Write()
{
    _worldPacket << uint32(SpellID);

    return &_worldPacket;
}

WorldPacket const* PlaySpellVisualKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << int32(KitRecID);

    return &_worldPacket;
}

void CancelCast::Read()
{
    _worldPacket >> CastID;
    _worldPacket >> SpellID;
}

WorldPacket const* ResyncRunes::Write()
{
    _worldPacket << Count;
    for (ResyncRune const& rune : Runes)
    {
        _worldPacket << rune.RuneType;
        _worldPacket << rune.Cooldown;
    }

    return &_worldPacket;
}

WorldPacket const* MountResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}
}
