/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "AchievementMgr.h"
#include "AchievementPackets.h"
#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "ChatTextBuilder.h"
#include "DatabaseEnv.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldSession.h"

struct VisibleAchievementCheck
{
    AchievementEntry const* operator()(std::pair<uint32, CompletedAchievementData> const& val)
    {
        AchievementEntry const* achievement = sAchievementStore.LookupEntry(val.first);
        if (achievement && !(achievement->Flags & ACHIEVEMENT_FLAG_HIDDEN))
            return achievement;
        return nullptr;
    }
};

AchievementMgr::AchievementMgr() : _achievementPoints(0) { }

AchievementMgr::~AchievementMgr() { }

/**
* called at player login. The player might have fulfilled some achievements when the achievement system wasn't working yet
*/
void AchievementMgr::CheckAllAchievementCriteria(Player* referencePlayer)
{
    // suppress sending packets
    for (uint32 i = 0; i < CRITERIA_TYPE_TOTAL; ++i)
        UpdateCriteria(CriteriaTypes(i), 0, 0, 0, NULL, referencePlayer);
}

bool AchievementMgr::HasAchieved(uint32 achievementId) const
{
    return _completedAchievements.find(achievementId) != _completedAchievements.end();
}

uint32 AchievementMgr::GetAchievementPoints() const
{
    return _achievementPoints;
}

bool AchievementMgr::CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const
{
    AchievementEntry const* achievement = tree->Achievement;
    if (!achievement)
        return false;

    if (HasAchieved(achievement->ID))
    {
        TC_LOG_TRACE("criteria.achievement", "AchievementMgr::CanUpdateCriteriaTree: (Id: %u Type %s Achievement %u) Achievement already earned",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), achievement->ID);
        return false;
    }

    if (achievement->InstanceID != -1 && referencePlayer->GetMapId() != uint32(achievement->InstanceID))
    {
        TC_LOG_TRACE("criteria.achievement", "AchievementMgr::CanUpdateCriteriaTree: (Id: %u Type %s Achievement %u) Wrong map",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), achievement->ID);
        return false;
    }

    if ((achievement->Faction == ACHIEVEMENT_FACTION_HORDE    && referencePlayer->GetTeam() != HORDE) ||
        (achievement->Faction == ACHIEVEMENT_FACTION_ALLIANCE && referencePlayer->GetTeam() != ALLIANCE))
    {
        TC_LOG_TRACE("criteria.achievement", "AchievementMgr::CanUpdateCriteriaTree: (Id: %u Type %s Achievement %u) Wrong faction",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), achievement->ID);
        return false;
    }

    return CriteriaHandler::CanUpdateCriteriaTree(criteria, tree, referencePlayer);
}

bool AchievementMgr::CanCompleteCriteriaTree(CriteriaTree const* tree)
{
    AchievementEntry const* achievement = tree->Achievement;
    if (!achievement)
        return false;

    // counter can never complete
    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
    {
        // someone on this realm has already completed that achievement
        if (sAchievementMgr->IsRealmCompleted(achievement))
            return false;
    }

    return true;
}

void AchievementMgr::CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer)
{
    AchievementEntry const* achievement = tree->Achievement;
    if (!achievement)
        return;

    // counter can never complete
    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return;

    // already completed and stored
    if (HasAchieved(achievement->ID))
        return;

    if (IsCompletedAchievement(achievement))
        CompletedAchievement(achievement, referencePlayer);
}

void AchievementMgr::AfterCriteriaTreeUpdate(CriteriaTree const* tree, Player* referencePlayer)
{
    AchievementEntry const* achievement = tree->Achievement;
    if (!achievement)
        return;

    // check again the completeness for SUMM and REQ COUNT achievements,
    // as they don't depend on the completed criteria but on the sum of the progress of each individual criteria
    if (achievement->Flags & ACHIEVEMENT_FLAG_SUMM)
        if (IsCompletedAchievement(achievement))
            CompletedAchievement(achievement, referencePlayer);

    if (std::vector<AchievementEntry const*> const* achRefList = sAchievementMgr->GetAchievementByReferencedId(achievement->ID))
        for (AchievementEntry const* refAchievement : *achRefList)
            if (IsCompletedAchievement(refAchievement))
                CompletedAchievement(refAchievement, referencePlayer);
}

bool AchievementMgr::IsCompletedAchievement(AchievementEntry const* entry)
{
    // counter can never complete
    if (entry->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(entry->CriteriaTree);
    if (!tree)
        return false;

    // For SUMM achievements, we have to count the progress of each criteria of the achievement.
    // Oddly, the target count is NOT contained in the achievement, but in each individual criteria
    if (entry->Flags & ACHIEVEMENT_FLAG_SUMM)
    {
        int64 progress = 0;
        CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
        {
            if (criteriaTree->Criteria)
                if (CriteriaProgress const* criteriaProgress = this->GetCriteriaProgress(criteriaTree->Criteria))
                    progress += criteriaProgress->Counter;
        });
        return progress >= tree->Entry->Amount;
    }

    return IsCompletedCriteriaTree(tree);
}

bool AchievementMgr::RequiredAchievementSatisfied(uint32 achievementId) const
{
    return HasAchieved(achievementId);
}

PlayerAchievementMgr::PlayerAchievementMgr(Player* owner) : _owner(owner)
{
}

void PlayerAchievementMgr::Reset()
{
    AchievementMgr::Reset();

    for (auto iter = _completedAchievements.begin(); iter != _completedAchievements.end(); ++iter)
    {
        WorldPackets::Achievement::AchievementDeleted achievementDeleted;
        achievementDeleted.AchievementID = iter->first;
        SendPacket(achievementDeleted.Write());
    }

    _completedAchievements.clear();
    _achievementPoints = 0;
    DeleteFromDB(_owner->GetGUID());

    // re-fill data
    CheckAllAchievementCriteria(_owner);
}

void PlayerAchievementMgr::DeleteFromDB(ObjectGuid const& guid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void PlayerAchievementMgr::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
{
    if (achievementResult)
    {
        do
        {
            Field* fields = achievementResult->Fetch();
            uint32 achievementid = fields[0].GetUInt32();

            // must not happen: cleanup at server startup in sAchievementMgr->LoadCompletedAchievements()
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementid);
            if (!achievement)
                continue;

            CompletedAchievementData& ca = _completedAchievements[achievementid];
            ca.Date = time_t(fields[1].GetUInt32());
            ca.Changed = false;

            _achievementPoints += achievement->Points;

            // title achievement rewards are retroactive
            if (AchievementReward const* reward = sAchievementMgr->GetAchievementReward(achievement))
                if (uint32 titleId = reward->TitleId[Player::TeamForRace(_owner->getRace()) == ALLIANCE ? 0 : 1])
                    if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
                        _owner->SetTitle(titleEntry);

        } while (achievementResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(NULL);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint64 counter = fields[1].GetUInt64();
            time_t date = time_t(fields[2].GetUInt32());

            Criteria const* criteria = sCriteriaMgr->GetCriteria(id);
            if (!criteria)
            {
                // Removing non-existing criteria data for all characters
                TC_LOG_ERROR("criteria.achievement", "Non-existing achievement criteria %u data has been removed from the table `character_achievement_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA);
                stmt->setUInt32(0, id);
                CharacterDatabase.Execute(stmt);

                continue;
            }

            if (criteria->Entry->StartTimer && time_t(date + criteria->Entry->StartTimer) < now)
                continue;

            CriteriaProgress& progress = _criteriaProgress[id];
            progress.Counter = counter;
            progress.Date = date;
            progress.Changed = false;
        } while (criteriaResult->NextRow());
    }
}

void PlayerAchievementMgr::SaveToDB(SQLTransaction& trans)
{
    if (!_completedAchievements.empty())
    {
        for (auto iter = _completedAchievements.begin(); iter != _completedAchievements.end(); ++iter)
        {
            if (!iter->second.Changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT);
            stmt->setUInt32(0, iter->first);
            stmt->setUInt64(1, _owner->GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, iter->first);
            stmt->setUInt32(2, uint32(iter->second.Date));
            trans->Append(stmt);

            iter->second.Changed = false;
        }
    }

    if (!_criteriaProgress.empty())
    {
        for (auto iter = _criteriaProgress.begin(); iter != _criteriaProgress.end(); ++iter)
        {
            if (!iter->second.Changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS_BY_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, iter->first);
            trans->Append(stmt);

            if (iter->second.Counter)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT_PROGRESS);
                stmt->setUInt64(0, _owner->GetGUID().GetCounter());
                stmt->setUInt32(1, iter->first);
                stmt->setUInt64(2, iter->second.Counter);
                stmt->setUInt32(3, uint32(iter->second.Date));
                trans->Append(stmt);
            }

            iter->second.Changed = false;
        }
    }
}

void PlayerAchievementMgr::ResetCriteria(CriteriaTypes type, uint64 miscValue1, uint64 miscValue2, bool evenIfCriteriaComplete)
{
    TC_LOG_DEBUG("criteria.achievement", "PlayerAchievementMgr::ResetCriteria(%u, " UI64FMTD ", " UI64FMTD ")", type, miscValue1, miscValue2);

    // disable for gamemasters with GM-mode enabled
    if (_owner->IsGameMaster())
        return;

    CriteriaList const& achievementCriteriaList = GetCriteriaByType(type);
    for (Criteria const* achievementCriteria : achievementCriteriaList)
    {
        if (achievementCriteria->Entry->FailEvent != miscValue1 || (achievementCriteria->Entry->FailAsset && achievementCriteria->Entry->FailAsset != int64(miscValue2)))
            continue;

        std::vector<CriteriaTree const*> const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(achievementCriteria->ID);
        bool allComplete = true;
        for (CriteriaTree const* tree : *trees)
        {
            // don't update already completed criteria if not forced or achievement already complete
            if (!(IsCompletedCriteriaTree(tree) && !evenIfCriteriaComplete) || !HasAchieved(tree->Achievement->ID))
            {
                allComplete = false;
                break;
            }
        }

        if (allComplete)
            continue;

        RemoveCriteriaProgress(achievementCriteria);
    }
}

void PlayerAchievementMgr::SendAllData(Player const* /*receiver*/) const
{
    VisibleAchievementCheck filterInvisible;
    WorldPackets::Achievement::AllAchievementData achievementData;
    achievementData.Data.Earned.reserve(_completedAchievements.size());
    achievementData.Data.Progress.reserve(_criteriaProgress.size());

    for (auto itr = _completedAchievements.begin(); itr != _completedAchievements.end(); ++itr)
    {
        AchievementEntry const* achievement = filterInvisible(*itr);
        if (!achievement)
            continue;

        WorldPackets::Achievement::EarnedAchievement earned;
        earned.Id = itr->first;
        earned.Date = itr->second.Date;
        if (!(achievement->Flags & ACHIEVEMENT_FLAG_ACCOUNT))
        {
            earned.Owner = _owner->GetGUID();
            earned.VirtualRealmAddress = earned.NativeRealmAddress = GetVirtualRealmAddress();
        }
        achievementData.Data.Earned.push_back(earned);
    }

    for (auto itr = _criteriaProgress.begin(); itr != _criteriaProgress.end(); ++itr)
    {
        WorldPackets::Achievement::CriteriaProgress progress;
        progress.Id = itr->first;
        progress.Quantity = itr->second.Counter;
        progress.Player = itr->second.PlayerGUID;
        progress.Flags = 0;
        progress.Date = itr->second.Date;
        progress.TimeFromStart = 0;
        progress.TimeFromCreate = 0;
        achievementData.Data.Progress.push_back(progress);
    }

    SendPacket(achievementData.Write());
}

void PlayerAchievementMgr::SendAchievementInfo(Player* receiver, uint32 /*achievementId = 0 */) const
{
    VisibleAchievementCheck filterInvisible;
    WorldPackets::Achievement::RespondInspectAchievements inspectedAchievements;
    inspectedAchievements.Player = _owner->GetGUID();
    inspectedAchievements.Data.Earned.reserve(_completedAchievements.size());
    inspectedAchievements.Data.Progress.reserve(_criteriaProgress.size());

    for (auto itr = _completedAchievements.begin(); itr != _completedAchievements.end(); ++itr)
    {
        AchievementEntry const* achievement = filterInvisible(*itr);
        if (!achievement)
            continue;

        WorldPackets::Achievement::EarnedAchievement earned;
        earned.Id = itr->first;
        earned.Date = itr->second.Date;
        if (!(achievement->Flags & ACHIEVEMENT_FLAG_ACCOUNT))
        {
            earned.Owner = _owner->GetGUID();
            earned.VirtualRealmAddress = earned.NativeRealmAddress = GetVirtualRealmAddress();
        }
        inspectedAchievements.Data.Earned.push_back(earned);
    }

    for (auto itr = _criteriaProgress.begin(); itr != _criteriaProgress.end(); ++itr)
    {
        WorldPackets::Achievement::CriteriaProgress progress;
        progress.Id = itr->first;
        progress.Quantity = itr->second.Counter;
        progress.Player = itr->second.PlayerGUID;
        progress.Flags = 0;
        progress.Date = itr->second.Date;
        progress.TimeFromStart = 0;
        progress.TimeFromCreate = 0;
        inspectedAchievements.Data.Progress.push_back(progress);
    }

    receiver->SendDirectMessage(inspectedAchievements.Write());
}

void PlayerAchievementMgr::CompletedAchievement(AchievementEntry const* achievement, Player* referencePlayer)
{
    // disable for gamemasters with GM-mode enabled
    if (_owner->IsGameMaster())
        return;

    if ((achievement->Faction == ACHIEVEMENT_FACTION_HORDE    && referencePlayer->GetTeam() != HORDE) ||
        (achievement->Faction == ACHIEVEMENT_FACTION_ALLIANCE && referencePlayer->GetTeam() != ALLIANCE))
        return;

    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER || HasAchieved(achievement->ID))
        return;

    if (achievement->Flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS)
        if (Guild* guild = referencePlayer->GetGuild())
            guild->AddGuildNews(GUILD_NEWS_PLAYER_ACHIEVEMENT, referencePlayer->GetGUID(), achievement->Flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER, achievement->ID);

    if (!_owner->GetSession()->PlayerLoading())
        SendAchievementEarned(achievement);

    TC_LOG_INFO("criteria.achievement", "PlayerAchievementMgr::CompletedAchievement(%u). %s", achievement->ID, GetOwnerInfo().c_str());

    CompletedAchievementData& ca = _completedAchievements[achievement->ID];
    ca.Date = time(NULL);
    ca.Changed = true;

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        sAchievementMgr->SetRealmCompleted(achievement);

    if (!(achievement->Flags & ACHIEVEMENT_FLAG_TRACKING_FLAG))
        _achievementPoints += achievement->Points;

    UpdateCriteria(CRITERIA_TYPE_COMPLETE_ACHIEVEMENT, 0, 0, 0, NULL, referencePlayer);
    UpdateCriteria(CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS, achievement->Points, 0, 0, NULL, referencePlayer);

    // reward items and titles if any
    AchievementReward const* reward = sAchievementMgr->GetAchievementReward(achievement);

    // no rewards
    if (!reward)
        return;

    // titles
    //! Currently there's only one achievement that deals with gender-specific titles.
    //! Since no common attributes were found, (not even in titleRewardFlags field)
    //! we explicitly check by ID. Maybe in the future we could move the achievement_reward
    //! condition fields to the condition system.
    if (uint32 titleId = reward->TitleId[achievement->ID == 1793 ? _owner->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER) : (_owner->GetTeam() == ALLIANCE ? 0 : 1)])
        if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
            _owner->SetTitle(titleEntry);

    // mail
    if (reward->SenderCreatureId)
    {
        MailDraft draft(uint16(reward->MailTemplateId));

        if (!reward->MailTemplateId)
        {
            // subject and text
            std::string subject = reward->Subject;
            std::string text = reward->Body;

            LocaleConstant localeConstant = _owner->GetSession()->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
            {
                if (AchievementRewardLocale const* loc = sAchievementMgr->GetAchievementRewardLocale(achievement))
                {
                    ObjectMgr::GetLocaleString(loc->Subject, localeConstant, subject);
                    ObjectMgr::GetLocaleString(loc->Body, localeConstant, text);
                }
            }

            draft = MailDraft(subject, text);
        }

        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        Item* item = reward->ItemId ? Item::CreateItem(reward->ItemId, 1, _owner) : NULL;
        if (item)
        {
            // save new item before send
            item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted

            // item
            draft.AddItem(item);
        }

        draft.SendMailTo(trans, _owner, MailSender(MAIL_CREATURE, uint64(reward->SenderCreatureId)));
        CharacterDatabase.CommitTransaction(trans);
    }
}

bool PlayerAchievementMgr::ModifierTreeSatisfied(uint32 modifierTreeId) const
{
    return AdditionalRequirementsSatisfied(sCriteriaMgr->GetModifierTree(modifierTreeId), 0, 0, nullptr, _owner);
}

void PlayerAchievementMgr::SendCriteriaUpdate(Criteria const* criteria, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPackets::Achievement::CriteriaUpdate criteriaUpdate;

    criteriaUpdate.CriteriaID = criteria->ID;
    criteriaUpdate.Quantity = progress->Counter;
    criteriaUpdate.PlayerGUID = _owner->GetGUID();
    criteriaUpdate.Flags = 0;
    if (criteria->Entry->StartTimer)
        criteriaUpdate.Flags = timedCompleted ? 1 : 0; // 1 is for keeping the counter at 0 in client

    criteriaUpdate.CurrentTime = progress->Date;
    criteriaUpdate.ElapsedTime = timeElapsed;
    criteriaUpdate.CreationTime = 0;

    SendPacket(criteriaUpdate.Write());
}

void PlayerAchievementMgr::SendCriteriaProgressRemoved(uint32 criteriaId)
{
    WorldPackets::Achievement::CriteriaDeleted criteriaDeleted;
    criteriaDeleted.CriteriaID = criteriaId;
    SendPacket(criteriaDeleted.Write());
}

void PlayerAchievementMgr::SendAchievementEarned(AchievementEntry const* achievement) const
{
    // Don't send for achievements with ACHIEVEMENT_FLAG_HIDDEN
    if (achievement->Flags & ACHIEVEMENT_FLAG_HIDDEN)
        return;

    TC_LOG_DEBUG("criteria.achievement", "PlayerAchievementMgr::SendAchievementEarned(%u)", achievement->ID);

    if (!(achievement->Flags & ACHIEVEMENT_FLAG_TRACKING_FLAG))
    {
        if (Guild* guild = sGuildMgr->GetGuildById(_owner->GetGuildId()))
        {
            Trinity::BroadcastTextBuilder _builder(_owner, CHAT_MSG_GUILD_ACHIEVEMENT, BROADCAST_TEXT_ACHIEVEMENT_EARNED, _owner->getGender(), _owner, achievement->ID);
            Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> _localizer(_builder);
            guild->BroadcastWorker(_localizer, _owner);
        }

        if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL | ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
        {
            // broadcast realm first reached
            WorldPackets::Achievement::ServerFirstAchievement serverFirstAchievement;
            serverFirstAchievement.Name = _owner->GetName();
            serverFirstAchievement.PlayerGUID = _owner->GetGUID();
            serverFirstAchievement.AchievementID = achievement->ID;
            sWorld->SendGlobalMessage(serverFirstAchievement.Write());
        }
        // if player is in world he can tell his friends about new achievement
        else if (_owner->IsInWorld())
        {
            Trinity::BroadcastTextBuilder _builder(_owner, CHAT_MSG_ACHIEVEMENT, BROADCAST_TEXT_ACHIEVEMENT_EARNED, _owner->getGender(), _owner, achievement->ID);
            Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> _localizer(_builder);
            Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder>> _worker(_owner, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), _localizer);
            Cell::VisitWorldObjects(_owner, _worker, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY));
        }
    }

    WorldPackets::Achievement::AchievementEarned achievementEarned;
    achievementEarned.Sender = _owner->GetGUID();
    achievementEarned.Earner = _owner->GetGUID();
    achievementEarned.EarnerNativeRealm = achievementEarned.EarnerVirtualRealm = GetVirtualRealmAddress();
    achievementEarned.AchievementID = achievement->ID;
    achievementEarned.Time = time(NULL);
    if (!(achievement->Flags & ACHIEVEMENT_FLAG_TRACKING_FLAG))
        _owner->SendMessageToSetInRange(achievementEarned.Write(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
    else
        _owner->SendDirectMessage(achievementEarned.Write());
}

void PlayerAchievementMgr::SendPacket(WorldPacket const* data) const
{
    _owner->SendDirectMessage(data);
}

CriteriaList const& PlayerAchievementMgr::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetPlayerCriteriaByType(type);
}

GuildAchievementMgr::GuildAchievementMgr(Guild* owner) : _owner(owner)
{
}

void GuildAchievementMgr::Reset()
{
    AchievementMgr::Reset();

    ObjectGuid guid = _owner->GetGUID();
    for (auto iter = _completedAchievements.begin(); iter != _completedAchievements.end(); ++iter)
    {
        WorldPackets::Achievement::GuildAchievementDeleted guildAchievementDeleted;
        guildAchievementDeleted.AchievementID = iter->first;
        guildAchievementDeleted.GuildGUID = guid;
        guildAchievementDeleted.TimeDeleted = time(NULL);
        SendPacket(guildAchievementDeleted.Write());
    }

    _achievementPoints = 0;
    _completedAchievements.clear();
    DeleteFromDB(guid);
}

void GuildAchievementMgr::DeleteFromDB(ObjectGuid const& guid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GUILD_ACHIEVEMENTS);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GUILD_ACHIEVEMENT_CRITERIA);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void GuildAchievementMgr::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
{
    if (achievementResult)
    {
        do
        {
            Field* fields = achievementResult->Fetch();
            uint32 achievementid = fields[0].GetUInt32();

            // must not happen: cleanup at server startup in sAchievementMgr->LoadCompletedAchievements()
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementid);
            if (!achievement)
                continue;

            CompletedAchievementData& ca = _completedAchievements[achievementid];
            ca.Date = time_t(fields[1].GetUInt32());
            Tokenizer guids(fields[2].GetString(), ' ');
            for (uint32 i = 0; i < guids.size(); ++i)
                ca.CompletingPlayers.insert(ObjectGuid::Create<HighGuid::Player>(uint64(strtoull(guids[i], nullptr, 10))));

            ca.Changed = false;

            _achievementPoints += achievement->Points;
        } while (achievementResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(NULL);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint64 counter = fields[1].GetUInt64();
            time_t date = time_t(fields[2].GetUInt32());
            ObjectGuid::LowType guid = fields[3].GetUInt64();

            Criteria const* criteria = sCriteriaMgr->GetCriteria(id);
            if (!criteria)
            {
                // we will remove not existed criteria for all guilds
                TC_LOG_ERROR("criteria.achievement", "Non-existing achievement criteria %u data removed from table `guild_achievement_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA_GUILD);
                stmt->setUInt32(0, id);
                CharacterDatabase.Execute(stmt);
                continue;
            }

            if (criteria->Entry->StartTimer && time_t(date + criteria->Entry->StartTimer) < now)
                continue;

            CriteriaProgress& progress = _criteriaProgress[id];
            progress.Counter = counter;
            progress.Date = date;
            progress.PlayerGUID = ObjectGuid::Create<HighGuid::Player>(guid);
            progress.Changed = false;
        } while (criteriaResult->NextRow());
    }
}

void GuildAchievementMgr::SaveToDB(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    std::ostringstream guidstr;
    for (auto itr = _completedAchievements.begin(); itr != _completedAchievements.end(); ++itr)
    {
        if (!itr->second.Changed)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_ACHIEVEMENT);
        stmt->setUInt64(0, _owner->GetId());
        stmt->setUInt32(1, itr->first);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_ACHIEVEMENT);
        stmt->setUInt64(0, _owner->GetId());
        stmt->setUInt32(1, itr->first);
        stmt->setUInt32(2, uint32(itr->second.Date));
        for (GuidSet::const_iterator gItr = itr->second.CompletingPlayers.begin(); gItr != itr->second.CompletingPlayers.end(); ++gItr)
            guidstr << gItr->GetCounter() << ',';

        stmt->setString(3, guidstr.str());
        trans->Append(stmt);

        guidstr.str("");
    }

    for (auto itr = _criteriaProgress.begin(); itr != _criteriaProgress.end(); ++itr)
    {
        if (!itr->second.Changed)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_ACHIEVEMENT_CRITERIA);
        stmt->setUInt64(0, _owner->GetId());
        stmt->setUInt32(1, itr->first);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_ACHIEVEMENT_CRITERIA);
        stmt->setUInt64(0, _owner->GetId());
        stmt->setUInt32(1, itr->first);
        stmt->setUInt64(2, itr->second.Counter);
        stmt->setUInt32(3, uint32(itr->second.Date));
        stmt->setUInt64(4, itr->second.PlayerGUID.GetCounter());
        trans->Append(stmt);
    }
}

void GuildAchievementMgr::SendAllData(Player const* receiver) const
{
    VisibleAchievementCheck filterInvisible;
    WorldPackets::Achievement::AllGuildAchievements allGuildAchievements;
    allGuildAchievements.Earned.reserve(_completedAchievements.size());

    for (auto itr = _completedAchievements.begin(); itr != _completedAchievements.end(); ++itr)
    {
        AchievementEntry const* achievement = filterInvisible(*itr);
        if (!achievement)
            continue;

        WorldPackets::Achievement::EarnedAchievement earned;
        earned.Id = itr->first;
        earned.Date = itr->second.Date;
        allGuildAchievements.Earned.push_back(earned);
    }

    receiver->SendDirectMessage(allGuildAchievements.Write());
}

void GuildAchievementMgr::SendAchievementInfo(Player* receiver, uint32 achievementId /*= 0*/) const
{
    WorldPackets::Achievement::GuildCriteriaUpdate guildCriteriaUpdate;
    if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementId))
    {
        if (CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(achievement->CriteriaTree))
        {
            CriteriaMgr::WalkCriteriaTree(tree, [this, &guildCriteriaUpdate](CriteriaTree const* node)
            {
                if (node->Criteria)
                {
                    auto progress = this->_criteriaProgress.find(node->Criteria->ID);
                    if (progress != this->_criteriaProgress.end())
                    {
                        WorldPackets::Achievement::GuildCriteriaProgress guildCriteriaProgress;
                        guildCriteriaProgress.CriteriaID = node->Criteria->ID;
                        guildCriteriaProgress.DateCreated = 0;
                        guildCriteriaProgress.DateStarted = 0;
                        guildCriteriaProgress.DateUpdated = progress->second.Date;
                        guildCriteriaProgress.Quantity = progress->second.Counter;
                        guildCriteriaProgress.PlayerGUID = progress->second.PlayerGUID;
                        guildCriteriaProgress.Flags = 0;

                        guildCriteriaUpdate.Progress.push_back(guildCriteriaProgress);
                    }
                }
            });
        }
    }

    receiver->SendDirectMessage(guildCriteriaUpdate.Write());
}

void GuildAchievementMgr::SendAllTrackedCriterias(Player* receiver, std::set<uint32> const& trackedCriterias) const
{
    WorldPackets::Achievement::GuildCriteriaUpdate guildCriteriaUpdate;
    guildCriteriaUpdate.Progress.reserve(trackedCriterias.size());

    for (uint32 criteriaId : trackedCriterias)
    {
        auto progress = _criteriaProgress.find(criteriaId);
        if (progress == _criteriaProgress.end())
            continue;

        WorldPackets::Achievement::GuildCriteriaProgress guildCriteriaProgress;
        guildCriteriaProgress.CriteriaID = criteriaId;
        guildCriteriaProgress.DateCreated = 0;
        guildCriteriaProgress.DateStarted = 0;
        guildCriteriaProgress.DateUpdated = progress->second.Date;
        guildCriteriaProgress.Quantity = progress->second.Counter;
        guildCriteriaProgress.PlayerGUID = progress->second.PlayerGUID;
        guildCriteriaProgress.Flags = 0;

        guildCriteriaUpdate.Progress.push_back(guildCriteriaProgress);
    }

    receiver->SendDirectMessage(guildCriteriaUpdate.Write());
}

void GuildAchievementMgr::SendAchievementMembers(Player* receiver, uint32 achievementId) const
{
    auto itr = _completedAchievements.find(achievementId);
    if (itr != _completedAchievements.end())
    {
        WorldPackets::Achievement::GuildAchievementMembers guildAchievementMembers;
        guildAchievementMembers.GuildGUID = _owner->GetGUID();
        guildAchievementMembers.AchievementID = achievementId;
        guildAchievementMembers.Member.reserve(itr->second.CompletingPlayers.size());
        for (ObjectGuid const& member : itr->second.CompletingPlayers)
            guildAchievementMembers.Member.emplace_back(member);

        receiver->SendDirectMessage(guildAchievementMembers.Write());
    }
}

void GuildAchievementMgr::CompletedAchievement(AchievementEntry const* achievement, Player* referencePlayer)
{
    TC_LOG_DEBUG("criteria.achievement", "GuildAchievementMgr::CompletedAchievement(%u)", achievement->ID);

    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER || HasAchieved(achievement->ID))
        return;

    if (achievement->Flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS)
        if (Guild* guild = referencePlayer->GetGuild())
            guild->AddGuildNews(GUILD_NEWS_GUILD_ACHIEVEMENT, ObjectGuid::Empty, achievement->Flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER, achievement->ID);

    SendAchievementEarned(achievement);
    CompletedAchievementData& ca = _completedAchievements[achievement->ID];
    ca.Date = time(NULL);
    ca.Changed = true;

    if (achievement->Flags & ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS)
    {
        if (referencePlayer->GetGuildId() == _owner->GetId())
            ca.CompletingPlayers.insert(referencePlayer->GetGUID());

        if (Group const* group = referencePlayer->GetGroup())
            for (GroupReference const* ref = group->GetFirstMember(); ref != NULL; ref = ref->next())
                if (Player const* groupMember = ref->GetSource())
                    if (groupMember->GetGuildId() == _owner->GetId())
                        ca.CompletingPlayers.insert(groupMember->GetGUID());
    }

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        sAchievementMgr->SetRealmCompleted(achievement);

    if (!(achievement->Flags & ACHIEVEMENT_FLAG_TRACKING_FLAG))
        _achievementPoints += achievement->Points;

    UpdateCriteria(CRITERIA_TYPE_COMPLETE_ACHIEVEMENT, 0, 0, 0, NULL, referencePlayer);
    UpdateCriteria(CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS, achievement->Points, 0, 0, NULL, referencePlayer);
}

void GuildAchievementMgr::SendCriteriaUpdate(Criteria const* entry, CriteriaProgress const* progress, uint32 /*timeElapsed*/, bool /*timedCompleted*/) const
{
    WorldPackets::Achievement::GuildCriteriaUpdate guildCriteriaUpdate;
    guildCriteriaUpdate.Progress.resize(1);

    WorldPackets::Achievement::GuildCriteriaProgress& guildCriteriaProgress = guildCriteriaUpdate.Progress[0];
    guildCriteriaProgress.CriteriaID = entry->ID;
    guildCriteriaProgress.DateCreated = 0;
    guildCriteriaProgress.DateStarted = 0;
    guildCriteriaProgress.DateUpdated = progress->Date;
    guildCriteriaProgress.Quantity = progress->Counter;
    guildCriteriaProgress.PlayerGUID = progress->PlayerGUID;
    guildCriteriaProgress.Flags = 0;

    _owner->BroadcastPacketIfTrackingAchievement(guildCriteriaUpdate.Write(), entry->ID);
}

void GuildAchievementMgr::SendCriteriaProgressRemoved(uint32 criteriaId)
{
    WorldPackets::Achievement::GuildCriteriaDeleted guildCriteriaDeleted;
    guildCriteriaDeleted.GuildGUID = _owner->GetGUID();
    guildCriteriaDeleted.CriteriaID = criteriaId;
    SendPacket(guildCriteriaDeleted.Write());
}

void GuildAchievementMgr::SendAchievementEarned(AchievementEntry const* achievement) const
{
    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL | ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
    {
        // broadcast realm first reached
        WorldPackets::Achievement::ServerFirstAchievement serverFirstAchievement;
        serverFirstAchievement.Name = _owner->GetName();
        serverFirstAchievement.PlayerGUID = _owner->GetGUID();
        serverFirstAchievement.AchievementID = achievement->ID;
        serverFirstAchievement.GuildAchievement = true;
        sWorld->SendGlobalMessage(serverFirstAchievement.Write());
    }

    WorldPackets::Achievement::GuildAchievementEarned guildAchievementEarned;
    guildAchievementEarned.AchievementID = achievement->ID;
    guildAchievementEarned.GuildGUID = _owner->GetGUID();
    guildAchievementEarned.TimeEarned = time(NULL);
    SendPacket(guildAchievementEarned.Write());
}

void GuildAchievementMgr::SendPacket(WorldPacket const* data) const
{
    _owner->BroadcastPacket(data);
}

CriteriaList const& GuildAchievementMgr::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetGuildCriteriaByType(type);
}

std::string PlayerAchievementMgr::GetOwnerInfo() const
{
    return Trinity::StringFormat("%s %s", _owner->GetGUID().ToString().c_str(), _owner->GetName().c_str());
}

std::string GuildAchievementMgr::GetOwnerInfo() const
{
    return Trinity::StringFormat("Guild ID " UI64FMTD " %s", _owner->GetId(), _owner->GetName().c_str());
}

AchievementGlobalMgr* AchievementGlobalMgr::Instance()
{
    static AchievementGlobalMgr instance;
    return &instance;
}

std::vector<AchievementEntry const*> const* AchievementGlobalMgr::GetAchievementByReferencedId(uint32 id) const
{
    auto itr = _achievementListByReferencedId.find(id);
    return itr != _achievementListByReferencedId.end() ? &itr->second : NULL;
}

AchievementReward const* AchievementGlobalMgr::GetAchievementReward(AchievementEntry const* achievement) const
{
    auto iter = _achievementRewards.find(achievement->ID);
    return iter != _achievementRewards.end() ? &iter->second : NULL;
}

AchievementRewardLocale const* AchievementGlobalMgr::GetAchievementRewardLocale(AchievementEntry const* achievement) const
{
    auto iter = _achievementRewardLocales.find(achievement->ID);
    return iter != _achievementRewardLocales.end() ? &iter->second : NULL;
}

bool AchievementGlobalMgr::IsRealmCompleted(AchievementEntry const* achievement) const
{
    auto itr = _allCompletedAchievements.find(achievement->ID);
    if (itr == _allCompletedAchievements.end())
        return false;

    if (itr->second == std::chrono::system_clock::time_point::min())
        return false;

    // Allow completing the realm first kill for entire minute after first person did it
    // it may allow more than one group to achieve it (highly unlikely)
    // but apparently this is how blizz handles it as well
    if (achievement->Flags & ACHIEVEMENT_FLAG_REALM_FIRST_KILL)
        return (std::chrono::system_clock::now() - itr->second) > Minutes(1);

    return true;
}

void AchievementGlobalMgr::SetRealmCompleted(AchievementEntry const* achievement)
{
    if (IsRealmCompleted(achievement))
        return;

    _allCompletedAchievements[achievement->ID] = std::chrono::system_clock::now();
}

//==========================================================
void AchievementGlobalMgr::LoadAchievementReferenceList()
{
    uint32 oldMSTime = getMSTime();

    if (sAchievementStore.GetNumRows() == 0)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement references.");
        return;
    }

    uint32 count = 0;

    for (uint32 entryId = 0; entryId < sAchievementStore.GetNumRows(); ++entryId)
    {
        AchievementEntry const* achievement = sAchievementStore.LookupEntry(entryId);
        if (!achievement || !achievement->SharesCriteria)
            continue;

        _achievementListByReferencedId[achievement->SharesCriteria].push_back(achievement);
        ++count;
    }

    DB2HotfixGenerator<AchievementEntry> hotfixes(sAchievementStore);

    // Once Bitten, Twice Shy (10 player) - Icecrown Citadel
    // Correct map requirement (currently has Ulduar); 6.0.3 note - it STILL has ulduar requirement
    hotfixes.ApplyHotfix(4539, [](AchievementEntry* achievement)
    {
        achievement->InstanceID = 631;
    });

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement references in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadCompletedAchievements()
{
    uint32 oldMSTime = getMSTime();

    // Populate _allCompletedAchievements with all realm first achievement ids to make multithreaded access safer
    // while it will not prevent races, it will prevent crashes that happen because std::unordered_map key was added
    // instead the only potential race will happen on value associated with the key
    for (AchievementEntry const* achievement : sAchievementStore)
        if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
            _allCompletedAchievements[achievement->ID] = std::chrono::system_clock::time_point::min();

    QueryResult result = CharacterDatabase.Query("SELECT achievement FROM character_achievement GROUP BY achievement");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 realm first completed achievements. DB table `character_achievement` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 achievementId = fields[0].GetUInt32();
        AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementId);
        if (!achievement)
        {
            // Remove non-existing achievements from all characters
            TC_LOG_ERROR("criteria.achievement", "Non-existing achievement %u data has been removed from the table `character_achievement`.", achievementId);

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEVMENT);
            stmt->setUInt32(0, achievementId);
            CharacterDatabase.Execute(stmt);

            continue;
        }
        else if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
            _allCompletedAchievements[achievementId] = std::chrono::system_clock::time_point::max();
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %lu realm first completed achievements in %u ms.", (unsigned long)_allCompletedAchievements.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewards()
{
    uint32 oldMSTime = getMSTime();

    _achievementRewards.clear();                           // need for reload case

    //                                               0      1        2        3     4       5        6     7
    QueryResult result = WorldDatabase.Query("SELECT entry, title_A, title_H, item, sender, subject, text, mailTemplate FROM achievement_reward");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 achievement rewards. DB table `achievement_reward` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        AchievementEntry const* achievement = sAchievementStore.LookupEntry(entry);
        if (!achievement)
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` contains a wrong achievement entry (Entry: %u), ignored.", entry);
            continue;
        }

        AchievementReward reward;
        reward.TitleId[0]       = fields[1].GetUInt32();
        reward.TitleId[1]       = fields[2].GetUInt32();
        reward.ItemId           = fields[3].GetUInt32();
        reward.SenderCreatureId = fields[4].GetUInt32();
        reward.Subject          = fields[5].GetString();
        reward.Body             = fields[6].GetString();
        reward.MailTemplateId   = fields[7].GetUInt32();

        // must be title or mail at least
        if (!reward.TitleId[0] && !reward.TitleId[1] && !reward.SenderCreatureId)
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) does not contain title or item reward data. Ignored.", entry);
            continue;
        }

        if (achievement->Faction == ACHIEVEMENT_FACTION_ANY && (!reward.TitleId[0] ^ !reward.TitleId[1]))
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains the title (A: %u H: %u) for only one team.", entry, reward.TitleId[0], reward.TitleId[1]);

        if (reward.TitleId[0])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.TitleId[0]);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid title id (%u) in `title_A`, set to 0", entry, reward.TitleId[0]);
                reward.TitleId[0] = 0;
            }
        }

        if (reward.TitleId[1])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.TitleId[1]);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid title id (%u) in `title_H`, set to 0", entry, reward.TitleId[1]);
                reward.TitleId[1] = 0;
            }
        }

        //check mail data before item for report including wrong item case
        if (reward.SenderCreatureId)
        {
            if (!sObjectMgr->GetCreatureTemplate(reward.SenderCreatureId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid creature entry %u as sender, mail reward skipped.", entry, reward.SenderCreatureId);
                reward.SenderCreatureId = 0;
            }
        }
        else
        {
            if (reward.ItemId)
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) does not have sender data, but contains an item reward. Item will not be rewarded.", entry);

            if (!reward.Subject.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) does not have sender data, but contains a mail subject.", entry);

            if (!reward.Body.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) does not have sender data, but contains mail text.", entry);

            if (reward.MailTemplateId)
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) does not have sender data, but has a MailTemplateId.", entry);
        }

        if (reward.MailTemplateId)
        {
            if (!sMailTemplateStore.LookupEntry(reward.MailTemplateId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) is using an invalid MailTemplateId (%u).", entry, reward.MailTemplateId);
                reward.MailTemplateId = 0;
            }
            else if (!reward.Subject.empty() || !reward.Body.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) is using MailTemplateId (%u) and mail subject/text.", entry, reward.MailTemplateId);
        }

        if (reward.ItemId)
        {
            if (!sObjectMgr->GetItemTemplate(reward.ItemId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid item id %u, reward mail will not contain the rewarded item.", entry, reward.ItemId);
                reward.ItemId = 0;
            }
        }

        _achievementRewards[entry] = reward;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement rewards in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewardLocales()
{
    uint32 oldMSTime = getMSTime();

    _achievementRewardLocales.clear();                       // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, subject_loc1, text_loc1, subject_loc2, text_loc2, subject_loc3, text_loc3, subject_loc4, text_loc4, "
                                             "subject_loc5, text_loc5, subject_loc6, text_loc6, subject_loc7, text_loc7, subject_loc8, text_loc8"
                                             " FROM locales_achievement_reward");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement reward locale strings.  DB table `locales_achievement_reward` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        if (_achievementRewards.find(entry) == _achievementRewards.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `locales_achievement_reward` (Entry: %u) contains locale strings for a non-existing achievement reward.", entry);
            continue;
        }

        AchievementRewardLocale& data = _achievementRewardLocales[entry];

        for (uint8 i = OLD_TOTAL_LOCALES - 1; i > 0; --i)
        {
            LocaleConstant locale = (LocaleConstant) i;
            ObjectMgr::AddLocaleString(fields[1 + 2 * (i - 1)].GetString(), locale, data.Subject);
            ObjectMgr::AddLocaleString(fields[1 + 2 * (i - 1) + 1].GetString(), locale, data.Body);
        }
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement reward locale strings in %u ms.", uint32(_achievementRewardLocales.size()), GetMSTimeDiffToNow(oldMSTime));
}
