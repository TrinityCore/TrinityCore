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

#include "Trainer.h"
#include "BattlePetMgr.h"
#include "Creature.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "WorldSession.h"

namespace Trainer
{
    bool Spell::IsCastable() const
    {
        return sSpellMgr->AssertSpellInfo(SpellId, DIFFICULTY_NONE)->HasEffect(SPELL_EFFECT_LEARN_SPELL);
    }

    Trainer::Trainer(uint32 id, Type type, std::string greeting, std::vector<Spell> spells) : _id(id), _type(type), _spells(std::move(spells))
    {
        _greeting[DEFAULT_LOCALE] = std::move(greeting);
    }

    void Trainer::SendSpells(Creature const* npc, Player* player, LocaleConstant locale) const
    {
        float reputationDiscount = player->GetReputationPriceDiscount(npc);

        WorldPackets::NPC::TrainerList trainerList;
        trainerList.TrainerGUID = npc->GetGUID();
        trainerList.TrainerType = AsUnderlyingType(_type);
        trainerList.TrainerID = _id;
        trainerList.Greeting = GetGreeting(locale);
        trainerList.Spells.reserve(_spells.size());
        for (Spell const& trainerSpell : _spells)
        {
            if (!player->IsSpellFitByClassAndRace(trainerSpell.SpellId))
                continue;

            if (!sConditionMgr->IsObjectMeetingTrainerSpellConditions(_id, trainerSpell.SpellId, player))
            {
                TC_LOG_DEBUG("condition", "SendSpells: conditions not met for trainer id %u spell %u player '%s' (%s)", _id, trainerSpell.SpellId, player->GetName().c_str(), player->GetGUID().ToString().c_str());
                continue;
            }

            trainerList.Spells.emplace_back();
            WorldPackets::NPC::TrainerListSpell& trainerListSpell = trainerList.Spells.back();
            trainerListSpell.SpellID = trainerSpell.SpellId;
            trainerListSpell.MoneyCost = int32(trainerSpell.MoneyCost * reputationDiscount);
            trainerListSpell.ReqSkillLine = trainerSpell.ReqSkillLine;
            trainerListSpell.ReqSkillRank = trainerSpell.ReqSkillRank;
            std::copy(trainerSpell.ReqAbility.begin(), trainerSpell.ReqAbility.end(), trainerListSpell.ReqAbility.begin());
            trainerListSpell.Usable = AsUnderlyingType(GetSpellState(player, &trainerSpell));
            trainerListSpell.ReqLevel = trainerSpell.ReqLevel;
        }

        player->SendDirectMessage(trainerList.Write());
    }

    void Trainer::TeachSpell(Creature const* npc, Player* player, uint32 spellId) const
    {
        Spell const* trainerSpell = GetSpell(spellId);
        if (!trainerSpell || !CanTeachSpell(player, trainerSpell))
        {
            SendTeachFailure(npc, player, spellId, FailReason::Unavailable);
            return;
        }

        bool sendSpellVisual = true;
        BattlePetSpeciesEntry const* speciesEntry = sSpellMgr->GetBattlePetSpecies(trainerSpell->SpellId);
        if (speciesEntry)
        {
            if (player->GetSession()->GetBattlePetMgr()->HasMaxPetCount(speciesEntry, player->GetGUID()))
            {
                // Don't send any error to client (intended)
                return;
            }

            sendSpellVisual = false;
        }

        float reputationDiscount = player->GetReputationPriceDiscount(npc);
        int64 moneyCost = int64(trainerSpell->MoneyCost * reputationDiscount);
        if (!player->HasEnoughMoney(moneyCost))
        {
            SendTeachFailure(npc, player, spellId, FailReason::NotEnoughMoney);
            return;
        }

        player->ModifyMoney(-moneyCost);

        if (sendSpellVisual)
        {
            npc->SendPlaySpellVisualKit(179, 0, 0);     // 53 SpellCastDirected
            player->SendPlaySpellVisualKit(362, 1, 0);  // 113 EmoteSalute
        }

        // learn explicitly or cast explicitly
        if (trainerSpell->IsCastable())
        {
            player->CastSpell(player, trainerSpell->SpellId, true);
        }
        else
        {
            bool dependent = false;

            if (speciesEntry)
            {
                player->GetSession()->GetBattlePetMgr()->AddPet(speciesEntry->ID, BattlePets::BattlePetMgr::SelectPetDisplay(speciesEntry),
                    BattlePets::BattlePetMgr::RollPetBreed(speciesEntry->ID), BattlePets::BattlePetMgr::GetDefaultPetQuality(speciesEntry->ID));
                // If the spell summons a battle pet, we fake that it has been learned and the battle pet is added
                // marking as dependent prevents saving the spell to database (intended)
                dependent = true;
            }

            player->LearnSpell(trainerSpell->SpellId, dependent);
        }
    }

    Spell const* Trainer::GetSpell(uint32 spellId) const
    {
        auto itr = std::find_if(_spells.begin(), _spells.end(), [spellId](Spell const& trainerSpell)
        {
            return trainerSpell.SpellId == spellId;
        });

        if (itr != _spells.end())
            return &(*itr);

        return nullptr;
    }

    bool Trainer::CanTeachSpell(Player const* player, Spell const* trainerSpell) const
    {
        SpellState state = GetSpellState(player, trainerSpell);
        if (state != SpellState::Available)
            return false;

        SpellInfo const* trainerSpellInfo = sSpellMgr->AssertSpellInfo(trainerSpell->SpellId, DIFFICULTY_NONE);
        if (trainerSpellInfo->IsPrimaryProfessionFirstRank() && !player->GetFreePrimaryProfessionPoints())
            return false;

        for (SpellEffectInfo const& effect : trainerSpellInfo->GetEffects())
        {
            if (!effect.IsEffect(SPELL_EFFECT_LEARN_SPELL))
                continue;

            SpellInfo const* learnedSpellInfo = sSpellMgr->GetSpellInfo(effect.TriggerSpell, DIFFICULTY_NONE);
            if (learnedSpellInfo && learnedSpellInfo->IsPrimaryProfessionFirstRank() && !player->GetFreePrimaryProfessionPoints())
                return false;
        }

        return true;
    }

    SpellState Trainer::GetSpellState(Player const* player, Spell const* trainerSpell) const
    {
        if (player->HasSpell(trainerSpell->SpellId))
            return SpellState::Known;

        // check race/class requirement
        if (!player->IsSpellFitByClassAndRace(trainerSpell->SpellId))
            return SpellState::Unavailable;

        // check skill requirement
        if (trainerSpell->ReqSkillLine && player->GetBaseSkillValue(trainerSpell->ReqSkillLine) < trainerSpell->ReqSkillRank)
            return SpellState::Unavailable;

        for (int32 reqAbility : trainerSpell->ReqAbility)
            if (reqAbility && !player->HasSpell(reqAbility))
                return SpellState::Unavailable;

        // check level requirement
        if (player->GetLevel() < trainerSpell->ReqLevel)
            return SpellState::Unavailable;

        // check ranks
        bool hasLearnSpellEffect = false;
        bool knowsAllLearnedSpells = true;
        for (SpellEffectInfo const& spellEffectInfo : sSpellMgr->AssertSpellInfo(trainerSpell->SpellId, DIFFICULTY_NONE)->GetEffects())
        {
            if (!spellEffectInfo.IsEffect(SPELL_EFFECT_LEARN_SPELL))
                continue;

            hasLearnSpellEffect = true;
            if (!player->HasSpell(spellEffectInfo.TriggerSpell))
                knowsAllLearnedSpells = false;
        }

        if (hasLearnSpellEffect && knowsAllLearnedSpells)
            return SpellState::Known;

        return SpellState::Available;
    }

    void Trainer::SendTeachFailure(Creature const* npc, Player const* player, uint32 spellId, FailReason reason) const
    {
        WorldPackets::NPC::TrainerBuyFailed trainerBuyFailed;
        trainerBuyFailed.TrainerGUID = npc->GetGUID();
        trainerBuyFailed.SpellID = spellId;
        trainerBuyFailed.TrainerFailedReason = AsUnderlyingType(reason);
        player->SendDirectMessage(trainerBuyFailed.Write());
    }

    std::string const& Trainer::GetGreeting(LocaleConstant locale) const
    {
        if (_greeting[locale].empty())
            return _greeting[DEFAULT_LOCALE];

        return _greeting[locale];
    }

    void Trainer::AddGreetingLocale(LocaleConstant locale, std::string greeting)
    {
        _greeting[locale] = std::move(greeting);
    }
}
