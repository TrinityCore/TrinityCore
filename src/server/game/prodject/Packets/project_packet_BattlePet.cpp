#include "project_packet_BattlePet.h"

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::PetBattles::Locations const& Location)
{
    data << Location.LocationResult;
    data << Location.BattleOrigin;
    data << Location.BattleFacing;

    for (uint32 i = 0; i < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; ++i)
        data << Location.PlayerPositions[i];

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, PROJECT::Packets::PetBattles::Locations& Location)
{
    data >> Location.LocationResult;
    data >> Location.BattleOrigin;
    data >> Location.BattleFacing;

    for (uint32 i = 0; i < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; ++i)
        data >> Location.PlayerPositions[i];

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePets::Battles::ActiveAura const& aura)
{
    data << aura.AbilityID;
    data << aura.InstanceID;
    data << aura.RoundsRemaining;
    data << aura.CurrentRound;
    data << aura.CasterPBOID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePets::Battles::ActiveState const& state)
{
    data << state.StateID;
    data << state.StateValue;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePets::Battles::ActiveAbility const& ability)
{
    data << ability.AbilityID;
    data << ability.CooldownRemaining;
    data << ability.LockdownRemaining;
    data << ability.AbilityIndex;
    data << ability.Pboid;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePets::Battles::RoundData const& roundData)
{
    data << roundData.CurRound;
    data << roundData.NextPetBattleState;

    data << uint32(roundData.Effects.size());

    for (int i = 0; i < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; i++)
    {
        data << roundData.NextInputFlags[i];
        data << roundData.NextTrapStatus[i];
        data << roundData.RoundTimeSecs[i];
    }

    data << uint32(roundData.Cooldowns.size());

    for (auto cooldown : roundData.Cooldowns)
        data << cooldown;

    data.WriteBits(roundData.PetXDied.size(), 3);
    data.FlushBits();

    for (auto effect : roundData.Effects)
    {
        data << effect.AbilityEffectID;
        data << effect.Flags;
        data << effect.SourceAuraInstanceID;
        data << effect.TurnInstanceID;
        data << uint8(effect.PetBattleEffectType);
        data << effect.CasterPBOID;
        data << effect.StackDepth;

        data << uint32(effect.Targets.size());

        for (auto target : effect.Targets)
        {
            data.WriteBits(target.Type, 3);
            data.FlushBits();

            data << target.Petx;

            switch (target.Type)
            {
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_AURA:
                    data << target.AuraInstanceID;
                    data << target.AuraAbilityID;
                    data << target.RoundsRemaining;
                    data << target.CurrentRound;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_STATE:
                    data << target.StateID;
                    data << target.StateValue;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_HEALTH:
                    data << target.Health;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_NEW_STAT_VALUE:
                    data << target.NewStatValue;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_TRIGGER_ABILITY:
                    data << target.TriggerAbilityID;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_CHANGED_ABILITY:
                    data << target.ChangedAbilityID;
                    data << target.CooldownRemaining;
                    data << target.LockdownRemaining;
                    break;
                case PROJECT::BattlePets::Constants::EffectTargetType::EFFECT_TARGET_TYPE_BROADCAST_TEXT:
                    data << target.BroadcastTextID;
                    break;
            }
        }
    }

    for (auto petXDied : roundData.PetXDied)
        data << petXDied;

    return data;
}

WorldPacket const* PROJECT::Packets::PetBattles::QueueStatus::Write()
{
    _worldPacket << Status;

    _worldPacket << uint32(SlotResult.size());

    _worldPacket << Ticket;

    for (auto slotResult : SlotResult)
        _worldPacket << slotResult;

    _worldPacket.WriteBit(ClientWaitTime ? true : false);
    _worldPacket.WriteBit(AverageWaitTime ? true : false);

    if (ClientWaitTime)
        _worldPacket << *ClientWaitTime;

    if (AverageWaitTime)
        _worldPacket << *AverageWaitTime;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::RequestFailed::Write()
{
    _worldPacket << Reason;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::FinalRound::Write()
{
    _worldPacket.WriteBit(Abandoned); // TO CHECK
    _worldPacket.WriteBit(PvpBattle); // TO CHECK

    for (uint32 i = 0; i < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; ++i)
        _worldPacket.WriteBit(Winners[i]);

    _worldPacket.FlushBits();

    for (uint32 i = 0; i < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; ++i)
        _worldPacket << NpcCreatureID[i];

    _worldPacket << uint32(Pets.size());

    for (auto pet : Pets)
    {
        _worldPacket << pet.GUID; // TO CHECK

        _worldPacket << pet.Level;
        _worldPacket << pet.Xp;
        _worldPacket << pet.Health;
        _worldPacket << pet.MaxHealth;
        _worldPacket << pet.InitialLevel;
        _worldPacket << pet.Pboid;

        _worldPacket.WriteBit(pet.Captured); // TO CHECK
        _worldPacket.WriteBit(pet.Caged); // TO CHECK
        _worldPacket.WriteBit(pet.SeenAction); // TO CHECK
        _worldPacket.WriteBit(pet.AwardedXP); // TO CHECK
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::FinalizeLocation::Write()
{
    _worldPacket << Location;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::InitialUpdate::Write()
{
    for (uint32 playerId = 0; playerId < PROJECT::BattlePets::Constants::TOTAL_CHALLENGERS; ++playerId)
    {
        auto playerData = &Players[playerId];

        _worldPacket << playerData->CharacterID;
        _worldPacket << playerData->TrapAbilityID;
        _worldPacket << playerData->TrapStatus;
        _worldPacket << playerData->RoundTimeSecs;
        _worldPacket << playerData->FrontPet;
        _worldPacket << playerData->InputFlags;

        _worldPacket.WriteBits(playerData->Pets.size(), 2);
        _worldPacket.FlushBits();

        for (auto pet : playerData->Pets)
        {
            _worldPacket << pet.BattlePetGUID;
            _worldPacket << pet.SpeciesID;
            _worldPacket << pet.DisplayID;
            _worldPacket << pet.CollarID;
            _worldPacket << pet.Level;
            _worldPacket << pet.Xp;
            _worldPacket << pet.CurHealth;
            _worldPacket << pet.MaxHealth;
            _worldPacket << pet.Power;
            _worldPacket << pet.Speed;
            _worldPacket << pet.NpcTeamMemberID;
            _worldPacket << pet.BreedQuality;
            _worldPacket << pet.StatusFlags;
            _worldPacket << pet.Slot;

            _worldPacket << uint32(pet.Abilities.size());
            _worldPacket << uint32(pet.Auras.size());
            _worldPacket << uint32(pet.States.size());

            for (auto ability : pet.Abilities)
                _worldPacket << ability;

            for (auto aura : pet.Auras)
                _worldPacket << aura;

            for (auto state : pet.States)
                _worldPacket << state;

            _worldPacket.WriteBits(pet.CustomName.size(), 7);
            _worldPacket.FlushBits();
            _worldPacket.WriteString(pet.CustomName);
        }
    }

    for (auto enviro : Enviros)
    {
        _worldPacket << uint32(enviro.Auras.size());
        _worldPacket << uint32(enviro.States.size());

        for (auto aura : enviro.Auras)
            _worldPacket << aura;

        for (auto state : enviro.States)
            _worldPacket << state;
    }

    _worldPacket << WaitingForFrontPetsMaxSecs;
    _worldPacket << PvpMaxRoundTime;
    _worldPacket << CurRound;
    _worldPacket << NpcCreatureID;
    _worldPacket << NpcDisplayID;
    _worldPacket << CurPetBattleState;
    _worldPacket << ForfeitPenalty;

    _worldPacket << InitialWildPetGUID;

    _worldPacket.WriteBit(IsPVP);
    _worldPacket.WriteBit(CanAwardXP);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::FirstRound::Write()
{
    _worldPacket << RoundData;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::RoundResult::Write()
{
    _worldPacket << RoundData;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::ReplacementsMade::Write()
{
    _worldPacket << RoundData;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::PetBattles::PvPChallenge::Write()
{
    _worldPacket << ChallengerGUID;
    _worldPacket << Location;

    return &_worldPacket;
}

void PROJECT::Packets::PetBattles::QueueProposeMatchResult::Read()
{
    Accepted = _worldPacket.ReadBit();
}

void PROJECT::Packets::PetBattles::RequestPvP::Read()
{
    _worldPacket >> TargetGUID;
    _worldPacket >> Location;
}

void PROJECT::Packets::PetBattles::RequestWild::Read()
{
    _worldPacket >> TargetGUID;
    _worldPacket >> Location;
}

void PROJECT::Packets::PetBattles::Input::Read()
{
    _worldPacket >> MoveType;
    _worldPacket >> NewFrontPet;
    _worldPacket >> DebugFlags;
    _worldPacket >> BattleInterrupted;

    _worldPacket >> AbilityID;
    _worldPacket >> Round;

    IgnoreAbandonPenalty = _worldPacket.ReadBit();
}

void PROJECT::Packets::PetBattles::ReplaceFrontPet::Read()
{
    _worldPacket >> FrontPet;
}

void PROJECT::Packets::PetBattles::RequestUpdate::Read()
{
    _worldPacket >> TargetGUID;
    Canceled = _worldPacket.ReadBit();
}

void PROJECT::Packets::BattlePets::QueryBattlePetName::Read()
{
    _worldPacket >> BattlePetID;
    _worldPacket >> UnitGUID;
}

WorldPacket const* PROJECT::Packets::BattlePets::QueryBattlePetNameResponse::Write()
{
    _worldPacket << BattlePetID;
    _worldPacket << CreatureID;
    _worldPacket << Timestamp;

    _worldPacket.WriteBit(Allow);
    if (!Allow)
    {
        _worldPacket.FlushBits();
        return &_worldPacket;
    }

    _worldPacket.WriteBits(Name.size(), 8);
    _worldPacket.WriteBit(HasDeclined);

    for (auto declinedName : DeclinedNames)
        _worldPacket.WriteBits(declinedName.size(), 7);
    
    _worldPacket.FlushBits();

    for (auto declinedName : DeclinedNames)
        _worldPacket.WriteString(declinedName);

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}
