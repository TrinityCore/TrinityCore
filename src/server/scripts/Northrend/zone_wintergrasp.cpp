/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "ConditionMgr.h"
#include "Creature.h"
#include "DBCStructure.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Unit.h"
#include "Vehicle.h"

#define GOSSIP_HELLO_DEMO1  "Build catapult."
#define GOSSIP_HELLO_DEMO2  "Build demolisher."
#define GOSSIP_HELLO_DEMO3  "Build siege engine."
#define GOSSIP_HELLO_DEMO4  "I cannot build more!"

enum WintergraspQueueText
{
    TEXT_WINTERGRASP_HORDE_NOWAR    = 14775,
    TEXT_WINTERGRASP_HORDE_QUEUE    = 14790,
    TEXT_WINTERGRASP_HORDE_WAR      = 14777,
    TEXT_WINTERGRASP_ALLIANCE_NOWAR = 14782,
    TEXT_WINTERGRASP_ALLIANCE_QUEUE = 14791,
    TEXT_WINTERGRASP_ALLIANCE_WAR   = 14781,

    TEXTOPTION_JOIN         = 20077, // whats this?
};

enum WintergraspSpells
{
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_HORDE    = 61409, // Demolisher engineers spells
    SPELL_BUILD_SIEGE_VEHICLE_FORCE_ALLIANCE = 56662,
    SPELL_BUILD_CATAPULT_FORCE               = 56664,
    SPELL_BUILD_DEMOLISHER_FORCE             = 56659,
    SPELL_ACTIVATE_CONTROL_ARMS              = 49899,
    SPELL_RIDE_WG_VEHICLE                    = 60968,
    SPELL_VEHICLE_TELEPORT                   = 49759,
    SPELL_CHANNEL_SPIRIT_HEAL                = 22011, // Spirit guide
};

enum WintergraspCreatureEntries
{
    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC = 23472,
};

enum WintergraspQuestIds
{
    QUEST_BONES_AND_ARROWS_HORDE_ATT              = 13193,
    QUEST_JINXING_THE_WALLS_HORDE_ATT             = 13202,
    QUEST_SLAY_THEM_ALL_HORDE_ATT                 = 13180,
    QUEST_FUELING_THE_DEMOLISHERS_HORDE_ATT       = 13200,
    QUEST_HEALING_WITH_ROSES_HORDE_ATT            = 13201,
    QUEST_DEFEND_THE_SIEGE_HORDE_ATT              = 13223,

    QUEST_BONES_AND_ARROWS_HORDE_DEF              = 13199,
    QUEST_WARDING_THE_WALLS_HORDE_DEF             = 13192,
    QUEST_SLAY_THEM_ALL_HORDE_DEF                 = 13178,
    QUEST_FUELING_THE_DEMOLISHERS_HORDE_DEF       = 13191,
    QUEST_HEALING_WITH_ROSES_HORDE_DEF            = 13194,
    QUEST_TOPPLING_THE_TOWERS_HORDE_DEF           = 13539,
    QUEST_STOP_THE_SIEGE_HORDE_DEF                = 13185,

    QUEST_BONES_AND_ARROWS_ALLIANCE_ATT           = 13196,
    QUEST_WARDING_THE_WARRIORS_ALLIANCE_ATT       = 13198,
    QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_ATT = 13179,
    QUEST_DEFEND_THE_SIEGE_ALLIANCE_ATT           = 13222,
    QUEST_A_RARE_HERB_ALLIANCE_ATT                = 13195,

    QUEST_BONES_AND_ARROWS_ALLIANCE_DEF           = 13154,
    QUEST_WARDING_THE_WARRIORS_ALLIANCE_DEF       = 13153,
    QUEST_NO_MERCY_FOR_THE_MERCILESS_ALLIANCE_DEF = 13177,
    QUEST_SHOUTHERN_SABOTAGE_ALLIANCE_DEF         = 13538,
    QUEST_STOP_THE_SIEGE_ALLIANCE_DEF             = 13186,
    QUEST_A_RARE_HERB_ALLIANCE_DEF                = 13156,
};

static uint8 constexpr MAX_WINTERGRASP_VEHICLES = 4;
static uint32 constexpr vehiclesList[MAX_WINTERGRASP_VEHICLES] =
{
    NPC_WINTERGRASP_CATAPULT,
    NPC_WINTERGRASP_DEMOLISHER,
    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE
};

struct npc_wg_demolisher_engineer : public ScriptedAI
{
    npc_wg_demolisher_engineer(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
    }

    void UpdateAI(uint32 diff) override
    {
    }

private:

};

// 58549 Tenacity
// 59911 Tenacity
class spell_wintergrasp_tenacity_refresh : public AuraScript
{
    PrepareAuraScript(spell_wintergrasp_tenacity_refresh);

    bool Validate(SpellInfo const* spellInfo) override
    {
        uint32 triggeredSpellId = spellInfo->Effects[EFFECT_2].CalcValue();
        return !triggeredSpellId || ValidateSpellInfo({ triggeredSpellId });
    }

    void Refresh(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (uint32 triggeredSpellId = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue())
        {
            int32 bp = 0;
            if (AuraEffect const* healEffect = GetEffect(EFFECT_0))
                bp = healEffect->GetAmount();

            CastSpellExtraArgs args(aurEff);
            args
                .AddSpellMod(SPELLVALUE_BASE_POINT0, bp)
                .AddSpellMod(SPELLVALUE_BASE_POINT1, bp);
            GetTarget()->CastSpell(nullptr, triggeredSpellId, args);
        }

        RefreshDuration();
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (uint32 triggeredSpellId = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue())
            GetTarget()->RemoveAurasDueToSpell(triggeredSpellId);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_wintergrasp_tenacity_refresh::Refresh, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_wintergrasp_tenacity_refresh::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_wg_didnt_stand_a_chance : public AchievementCriteriaScript
{
    public:
        achievement_wg_didnt_stand_a_chance() : AchievementCriteriaScript("achievement_wg_didnt_stand_a_chance") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (!target)
                return false;

            if (Player* victim = target->ToPlayer())
            {
                if (!victim->IsMounted())
                    return false;

                if (Vehicle* vehicle = source->GetVehicle())
                    if (vehicle->GetVehicleInfo()->m_ID == 244) // Wintergrasp Tower Cannon
                        return true;
            }

            return false;
        }
};

class condition_is_wintergrasp_horde : public ConditionScript
{
    public:
        condition_is_wintergrasp_horde() : ConditionScript("condition_is_wintergrasp_horde") { }

        bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->GetControllingTeam() == PVP_TEAM_HORDE)
                return true;
            return false;
        }
};

class condition_is_wintergrasp_alliance : public ConditionScript
{
    public:
        condition_is_wintergrasp_alliance() : ConditionScript("condition_is_wintergrasp_alliance") { }

        bool OnConditionCheck(Condition const* /*condition*/, ConditionSourceInfo& /*sourceInfo*/)
        {
            Battlefield* wintergrasp = sBattlefieldMgr->GetEnabledBattlefield(BATTLEFIELD_BATTLEID_WINTERGRASP);
            if (wintergrasp && wintergrasp->GetControllingTeam() == PVP_TEAM_ALLIANCE)
                return true;
            return false;
        }
};

void AddSC_wintergrasp()
{
    RegisterCreatureAI(npc_wg_demolisher_engineer);
    RegisterAuraScript(spell_wintergrasp_tenacity_refresh);
    new achievement_wg_didnt_stand_a_chance();
    new condition_is_wintergrasp_horde();
    new condition_is_wintergrasp_alliance();
}
