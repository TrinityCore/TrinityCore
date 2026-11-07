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

#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum ArathiBasinGryphonBatRiderLeaderData
{
    PATH_GRYPHON_RIDER_LEADER   = 800000059,
    PATH_BAT_RIDER_LEADER       = 800000058,
};

// 150513 - Arathor Gryphon Rider
// 150459 - Defiler Bat Rider
template<uint32 Path>
struct npc_bg_ab_gryphon_bat_rider_leader : public ScriptedAI
{
    npc_bg_ab_gryphon_bat_rider_leader(Creature* creature) : ScriptedAI(creature) { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId != Path)
            return;

        // despawn formation group
        std::list<Creature*> followers;
        me->GetCreatureListWithEntryInGrid(followers, me->GetEntry());
        for (Creature* follower : followers)
            follower->DespawnOrUnsummon(500ms);

        me->DespawnOrUnsummon(500ms);
    }
};

// 261985 - Blacksmith Working
class spell_bg_ab_blacksmith_working : public AuraScript
{
    static constexpr uint32 ITEM_BLACKSMITH_HAMMER = 5956;

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetVirtualItem(0, ITEM_BLACKSMITH_HAMMER);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            creature->LoadEquipment(creature->GetOriginalEquipmentId());
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_bg_ab_blacksmith_working::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_bg_ab_blacksmith_working::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_arathi_basin()
{
    new GenericCreatureScript<npc_bg_ab_gryphon_bat_rider_leader<PATH_GRYPHON_RIDER_LEADER>>("npc_bg_ab_arathor_gryphon_rider_leader");
    new GenericCreatureScript<npc_bg_ab_gryphon_bat_rider_leader<PATH_BAT_RIDER_LEADER>>("npc_bg_ab_defiler_bat_rider_leader");

    RegisterSpellScript(spell_bg_ab_blacksmith_working);
}
