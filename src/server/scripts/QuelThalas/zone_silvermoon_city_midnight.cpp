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

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

namespace Scripts::QuelThalas::SilvermoonCityMidnight
{
namespace Quests
{
    static constexpr uint32 CompleteMidnightCampaign = 90806;
}

// 1278767 - [DNT] Skip Midnight Intro - Flag Campaign
class spell_silvermoon_skip_midnight_intro : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        // HACK: This should be rewarded after completing the Intro which is nyi atm.
        if (Player* player = GetCaster()->ToPlayer())
            player->CompleteQuest(Quests::CompleteMidnightCampaign);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_silvermoon_skip_midnight_intro::HandleHitTarget, EFFECT_0, SPELL_EFFECT_COMPLETE_CAMPAIGN);
    }
};
}

void AddSC_silvermoon_city_midnight()
{
    using namespace Scripts::QuelThalas::SilvermoonCityMidnight;

    // Spells
    RegisterSpellScript(spell_silvermoon_skip_midnight_intro);
}
