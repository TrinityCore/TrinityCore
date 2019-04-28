#include "project_packet_Misc.h"
#include "project_loot_placeholder.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Movement::MovementForce const& force);

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Misc::AccountCriteria const& criteriaData)
{
    data << uint32(criteriaData.CriteriaID);
    data << uint64(criteriaData.Quantity);
    data << criteriaData.PlayerGUID;
    data.AppendPackedTime(criteriaData.CurrentTime);
    data << uint32(criteriaData.ElapsedTime);
    data << uint32(criteriaData.CreationTime);

    data.WriteBits(criteriaData.Flags, 4);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Misc::PlayerChoiceResponseRewardEntry const& reward)
{
    data << reward.Id;
    data << reward.DisplayID; // ?
    data << uint32(0); // unk

    data.WriteBit(0); // hasUnk1
    data.WriteBit(0); // hasUnk2
    data.FlushBits();
    //if (hasUnk1)
    //if (hasUnk2)

    data << reward.Quantity;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Misc::LFGPlayerRewards const& reward)
{
    data << reward.RewardItem;
    data << reward.RewardItemQuantity;
    data << reward.BonusCurrency;
    data.WriteBit(reward.IsCurrency);
    data.FlushBits();

    return data;
}

void PROJECT::Packets::Misc::BattlemasterJoinArenaSkirmish::Read()
{
    JoinAsGroup = _worldPacket.ReadBit();
    Unk = _worldPacket.ReadBit();
    _worldPacket >> Roles;
    _worldPacket >> TeamSizeIndex;
}

WorldPacket const* PROJECT::Packets::Misc::StartTimer::Write()
{
    _worldPacket << CurrentTimer;
    _worldPacket << MaxTimer;
    _worldPacket << Type;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::GuildShiftRank::Read()
{
    _worldPacket >> RankOrder;
    ShiftUp = _worldPacket.ReadBit();
}

void PROJECT::Packets::Misc::NeutralPlayerSelectFaction::Read()
{
    _worldPacket >> Faction;
}

WorldPacket const* PROJECT::Packets::Misc::VignetteUpdate::Write()
{
    _worldPacket.WriteBit(ForceUpdate);
    _worldPacket.FlushBits();

    _worldPacket << uint32(Removed.size());

    for (ObjectGuid guid : Removed)
        _worldPacket << guid;

    _worldPacket << uint32(Added.size());

    for (ObjectGuid guid : Added)
        _worldPacket << guid;

    _worldPacket << uint32(VignetteClientAdded.size());

    for (auto vignette : VignetteClientAdded)
    {
        _worldPacket << vignette.position.GetPositionX();
        _worldPacket << vignette.position.GetPositionY();
        _worldPacket << vignette.position.GetPositionZ();
        _worldPacket << vignette.guid;
        _worldPacket << vignette.VignetteID;
        _worldPacket << vignette.ZoneRestriction;
    }

    _worldPacket << uint32(Updated.size());

    for (ObjectGuid guid : Updated)
        _worldPacket << guid;

    _worldPacket << uint32(VignetteClientUpdated.size());

    for (auto vignette : VignetteClientUpdated)
    {
        _worldPacket << vignette.position.GetPositionX();
        _worldPacket << vignette.position.GetPositionY();
        _worldPacket << vignette.position.GetPositionZ();
        _worldPacket << vignette.guid;
        _worldPacket << vignette.VignetteID;
        _worldPacket << vignette.ZoneRestriction;
    }

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::PetSlotUpdated::Write()
{
    _worldPacket << OriginPetID;
    _worldPacket << To;
    _worldPacket << TargetPetID;
    _worldPacket << From;
    return &_worldPacket;
}

void PROJECT::Packets::Misc::BuyReagentBank::Read()
{
    _worldPacket >> Unit;
}

void PROJECT::Packets::Misc::SetPetSlot::Read()
{
    _worldPacket >> PetNumberID;
    _worldPacket >> ToSlot;
    _worldPacket >> Stable;
}

WorldPacket const* PROJECT::Packets::Misc::PetStableResult::Write()
{
    _worldPacket << Message;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::GuildChallengeCompleted::Write()
{
    _worldPacket << ChallengeType;
    _worldPacket << CurrentCount;
    _worldPacket << MaxCount;
    _worldPacket << Gold;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::GuildChangeNameResult::Write()
{
    _worldPacket.WriteBit(hasRename);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::GuildNameChanged::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket.WriteBits(NewName.length(), 7);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(NewName);

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::DisplayToast::Write()
{
    _worldPacket << Quantity;
    _worldPacket << ToastMethod;
    _worldPacket << QuestID;

    _worldPacket.WriteBit(IsBonusRoll);

    _worldPacket.WriteBits(ToastType, 2);

    if (ToastType == PROJECT::Loots::TOAST_ITEM)
    {
        _worldPacket.WriteBit(Mailed);
        _worldPacket.FlushBits();

        // item instance
        bool hasItemBonus = !bonusListIDs.empty();
        _worldPacket << EntityId;
        _worldPacket << uint32(0); // RandomPropertiesSeed
        _worldPacket << uint32(RandomPropertiesID);
        _worldPacket.WriteBit(hasItemBonus);
        _worldPacket.WriteBit(false); // HasModifications
        if (hasItemBonus)
        {
            _worldPacket << uint8(1); // Indexes (works in case of 1 bonus, possibly should be bit mask of indexes?)

            uint32 bonusCount = bonusListIDs.size();
            _worldPacket << uint32(bonusCount);
            for (uint32 j = 0; j < bonusCount; ++j)
                _worldPacket << uint32(bonusListIDs[j]);
        }
        /*if (hasModifications)
        {
            var mask = packet.ReadUInt32();
            for (var j = 0; mask != 0; mask >>= 1, ++j)
                if ((mask & 1) != 0)
                    packet.ReadInt32(((ItemModifier)j).ToString(), indexes);
        }*/
        _worldPacket.FlushBits();
        
        _worldPacket << uint32(0); // SpecializationID
        _worldPacket << uint32(0);
    }
    else if (ToastType == PROJECT::Loots::TOAST_CURRENCY)
    {
        _worldPacket.FlushBits();
        _worldPacket << EntityId;
    }
    else
        _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::ChallengeModeStart::Write()
{
    _worldPacket << MapID;
    _worldPacket << KeystoneLevel;

    for (uint32 affix : Affixes)
        _worldPacket << affix;

    _worldPacket << UnkStructure; // structure todo
    _worldPacket.WriteBit(IsCharged);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::ChangePlayerDifficultyResult::Write()
{
    _worldPacket.WriteBits(Result, 4);
    switch (Result)
    {
    case 5:
    case 8:
        _worldPacket.WriteBit(Cooldown);
        _worldPacket.FlushBits();
        _worldPacket << CooldownReason;
        break;
    case 11:
        _worldPacket << InstanceMap;
        _worldPacket << DifficultyID;
        break;
    case 2:
        _worldPacket << InstanceMap;
        break;
    case 4:
        _worldPacket << Guid;
        break;
    default:
        break;
    }

    return &_worldPacket;
}

void PROJECT::Packets::Misc::StartChallengeMode::Read()
{
    _worldPacket >> Unk1;
    _worldPacket >> Unk2;
    _worldPacket >> GameObject;
}

WorldPacket const* PROJECT::Packets::Misc::ChallengeModeReset::Write()
{
    _worldPacket << MapID;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::StartElapsedTimer::Write()
{
    _worldPacket << TimerID;
    _worldPacket << CurrentTimer;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::StopElapsedTimer::Write()
{
    _worldPacket << TimerID;
    _worldPacket.WriteBit(KeepTimer);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::ChallengeModeComplete::Write()
{
    _worldPacket << Timer;
    _worldPacket << MapID;
    _worldPacket << KeystoneLevel;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::AccountCriteriaUpdate::Write()
{
    _worldPacket << CriteriaData;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::AllAccountCriteria::Write()
{
    _worldPacket << uint32(Criterias.size());

    for (auto criteria : Criterias)
        _worldPacket << criteria;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::LfgBonusFactionId::Read()
{
	_worldPacket >> FactionID;
}

void PROJECT::Packets::Misc::StartWarGame::Read()
{
    _worldPacket >> OpposingPartyMember;
    _worldPacket >> OpposingPartyMemberVirtualRealmAddress;
    _worldPacket >> OpposingPartyMemberCfgRealmID;
    _worldPacket >> QueueID;
    TournamentRules = _worldPacket.ReadBit();
}

void PROJECT::Packets::Misc::ShowTradeSkill::Read()
{
    _worldPacket >> PlayerGUID;
    _worldPacket >> SpellID;
    _worldPacket >> SkillLineID;
}

WorldPacket const* PROJECT::Packets::Misc::ShowTradeSkillResponse::Write()
{
    _worldPacket << PlayerGUID;

    _worldPacket << SpellID;

    _worldPacket << uint32(SkillLineIDs.size());
    _worldPacket << uint32(SkillRanks.size());
    _worldPacket << uint32(SkillMaxRanks.size());
    _worldPacket << uint32(KnownAbilitySpellIDs.size());

    for (auto skillLineId : SkillLineIDs)
        _worldPacket << skillLineId;

    for (auto skillRank : SkillRanks)
        _worldPacket << skillRank;

    for (auto skillMaxRank : SkillMaxRanks)
        _worldPacket << skillMaxRank;

    for (auto knownAbility : KnownAbilitySpellIDs)
        _worldPacket << knownAbility;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::KeyboundOverride::Read()
{
    _worldPacket >> OverrideID;
}

WorldPacket const* PROJECT::Packets::Misc::ScriptCast::Write()
{
    _worldPacket << SpellID;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::RemoveLossOfControl::Write()
{
    _worldPacket << Caster;
    _worldPacket << SpellID;
    _worldPacket << Victim;
    _worldPacket << Type;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::AddLossOfControl::Write()
{
    _worldPacket << Victim;
    _worldPacket << SpellID;
    _worldPacket << Caster;
    _worldPacket << Duration;
    _worldPacket << DurationRemaining;
    _worldPacket << LockoutSchoolMask;
    _worldPacket << uint8(Type);
    _worldPacket << uint8(Mechanic);

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::MoveApplyMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;

    _worldPacket << Force;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::MoveRemoveMovementForce::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << SequenceIndex;
    _worldPacket << TriggerGUID;

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::DisplayPlayerChoice::Write()
{
    _worldPacket << ChoiceID;
    _worldPacket << uint32(Responses.size());
    _worldPacket << GUID;

    _worldPacket.WriteBits(Question.size(), 8);
    _worldPacket.FlushBits();

    for (auto response : Responses)
    {
        _worldPacket << response.ResponseID;
        _worldPacket << response.ChoiceArtFileID;

        _worldPacket.WriteBits(response.Answer.size(), 9);
        _worldPacket.WriteBits(response.Title.size(), 9);
        _worldPacket.WriteBits(response.Description.size(), 11);
        _worldPacket.WriteBits(response.ConfirmationString.size(), 7);
        _worldPacket.WriteBit(response.Reward.hasReward);
        _worldPacket.FlushBits();

        if (response.Reward.hasReward)
        {
            PlayerChoiceResponseReward * reward = &response.Reward;
            _worldPacket << reward->TitleID;
            _worldPacket << reward->PackageID;
            _worldPacket << reward->SkillLineID;
            _worldPacket << reward->SkillPointCount;
            _worldPacket << reward->ArenaPointCount;
            _worldPacket << reward->HonorPointCount;
            _worldPacket << reward->Money;
            _worldPacket << reward->Xp;

            _worldPacket << uint32(reward->Items.size());
            _worldPacket << uint32(reward->Currencies.size());
            _worldPacket << uint32(reward->Factions.size());
            _worldPacket << uint32(reward->ItemChoices.size());

            for (auto rewardEntry : reward->Items)
                _worldPacket << rewardEntry;
            for (auto rewardEntry : reward->Currencies)
                _worldPacket << rewardEntry;
            for (auto rewardEntry : reward->Factions)
                _worldPacket << rewardEntry;
            for (auto rewardEntry : reward->ItemChoices)
                _worldPacket << rewardEntry;
        }

        _worldPacket.WriteString(response.Answer);
        _worldPacket.WriteString(response.Title);
        _worldPacket.WriteString(response.Description);
        _worldPacket.WriteString(response.ConfirmationString);
    }

    _worldPacket.WriteString(Question);

    return &_worldPacket;
}

void PROJECT::Packets::Misc::ChoiceResponse::Read()
{
    _worldPacket >> ChoiceID;
    _worldPacket >> ResponseID;
}

WorldPacket const* PROJECT::Packets::Misc::PetTameFailure::Write()
{
    _worldPacket << Result;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::UnlearnSpecialization::Read()
{
    _worldPacket >> SpecializationIndex;
}

WorldPacket const* PROJECT::Packets::Misc::RequestPvpRewardsResponse::Write()
{
    _worldPacket << RandomBg;

    _worldPacket.WriteBit(HasFirstRatedBg);
    _worldPacket.WriteBit(HasFirstSkirmish);
    _worldPacket.WriteBit(HasFirstRatedArena2v2);
    _worldPacket.WriteBit(HasFirstRatedArena3v3);
    _worldPacket.FlushBits();

    _worldPacket << RatedBg;
    _worldPacket << SkirmishArena;
    _worldPacket << RatedArena2v2;
    _worldPacket << RatedArena3v3;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::AdventureJournalOpenQuest::Read()
{
    _worldPacket >> JournalID;
}

WorldPacket const* PROJECT::Packets::Misc::RatedBattlefieldInfo::Write()
{
    for (int i = 0; i < 6; i++)
    {
        ClientBracketInfo& bracket = Bracket[i];
        
        _worldPacket << bracket.PersonalRating;
        _worldPacket << bracket.Ranking;
        _worldPacket << bracket.SeasonPlayed;
        _worldPacket << bracket.SeasonWon;
        _worldPacket << bracket.Unk1;
        _worldPacket << bracket.Unk2;
        _worldPacket << bracket.WeeklyPlayed;
        _worldPacket << bracket.WeeklyWon;
        _worldPacket << bracket.BestWeeklyRating;
        _worldPacket << bracket.Unk3;
        _worldPacket << bracket.BestSeasonRating;
    }

    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::ArenaPrepOpponentSpecializations::Write()
{
    _worldPacket << uint32(OpponentData.size());
    for (auto data : OpponentData)
    {
        _worldPacket << data.SpecializationID;
        _worldPacket << data.Unk1;
        _worldPacket << data.Guid;
    }
    return &_worldPacket;
}

WorldPacket const* PROJECT::Packets::Misc::LfgPlayerReward::Write()
{
    _worldPacket << ActualSlot; // unconfirmed order
    _worldPacket << QueuedSlot; // unconfirmed order
    _worldPacket << RewardMoney;
    _worldPacket << AddedXP;

    _worldPacket << uint32(Rewards.size());

    for (auto reward : Rewards)
        _worldPacket << reward;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::SetWarMode::Read()
{
    Enabled = _worldPacket.ReadBit();
}

WorldPacket const* PROJECT::Packets::Misc::AzeriteXpGain::Write()
{
    _worldPacket << AzeriteGUID;
    _worldPacket << XP;

    return &_worldPacket;
}

void PROJECT::Packets::Misc::AzeriteEmpoweredItemSelectPower::Read()
{
    _worldPacket >> Tier;
    _worldPacket >> AzeritePowerID;
    _worldPacket >> Bag;
    _worldPacket >> Slot;
}

WorldPacket const* PROJECT::Packets::Misc::AzeriteEmpoweredItemRespecOpen::Write()
{
    _worldPacket << UnitGUID;

    return &_worldPacket;
}
