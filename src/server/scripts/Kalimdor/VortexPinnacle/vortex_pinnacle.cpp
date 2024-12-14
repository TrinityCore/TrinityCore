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

#include "vortex_pinnacle.h"
#include "Creature.h"
#include "DB2Structure.h"
#include "EventMap.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum VPVehicleIds
{
    VEHICLE_ID_SLIPSTREAM_ENTRANCE_1        = 1305,
    VEHICLE_ID_SLIPSTREAM_ENTRANCE_2        = 1306,
    VEHICLE_ID_SLIPSTREAM_1                 = 1111,
    VEHICLE_ID_SLIPSTREAM_2                 = 1112,
    VEHICLE_ID_SLIPSTREAM_3                 = 1113,
    VEHICLE_ID_SLIPSTREAM_4                 = 1149,
    VEHICLE_ID_SLIPSTREAM_5                 = 1150,
    VEHICLE_ID_SLIPSTREAM_BACK_TO_ENTRANCE  = 1551
};

enum VPSlipstreamSpells
{
    // Spells
    SPELL_SLIPSTREAM_ENTER                          = 84965,
    SPELL_SLIPSTREAM_FIRST                          = 84980,
    SPELL_SLIPSTREAM_SECOND                         = 84988,
    SPELL_SLIPSTREAM_THIRD                          = 85394,
    SPELL_SLIPSTREAM_FOURTH                         = 85397,
    SPELL_SLIPSTREAM_LAST                           = 85016,
    SPELL_SLIPSTREAM_ASAAD                          = 95911,
    SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS              = 89498,
    SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS_TELEPORT     = 89499,
    SPELL_SLIPSTREAM_SHORTCUT_ASAAD                 = 89500,
    SPELL_SLIPSTREAM_SHORTCUT_ASAAD_TELEPORT        = 89501,
    SPELL_GENERIC_EJECT_ALL_PASSENGERS              = 79737
};

struct SlipstreamInfo
{
    SlipstreamInfo(std::string_view const& stringId, std::string_view const& targetStringId, uint32 vehicleId, bool spellClick, uint32 chainSpellId) :
        StringId(stringId), TargetStringId(targetStringId), VehicleId(vehicleId), SpellClick(spellClick), ChainSpellId(chainSpellId) { }

    std::string_view StringId;
    std::string_view TargetStringId;
    uint32 VehicleId;
    bool SpellClick;
    uint32 ChainSpellId;
};

static std::array<SlipstreamInfo const, 11> const SlipstreamData =
{
    // Sequence for Grandvizier Ertan's Slipstreams
    SlipstreamInfo("vp_slipstream_ertan_1", "vp_slipstream_ertan_2", VEHICLE_ID_SLIPSTREAM_1, true, SPELL_SLIPSTREAM_FIRST),
    SlipstreamInfo("vp_slipstream_ertan_2", "vp_slipstream_ertan_3", VEHICLE_ID_SLIPSTREAM_2, false, SPELL_SLIPSTREAM_SECOND),
    SlipstreamInfo("vp_slipstream_ertan_3", "vp_slipstream_landing_zone_1", VEHICLE_ID_SLIPSTREAM_3, false, SPELL_SLIPSTREAM_LAST),

    // Sequence for Altairus' Slipstreams
    SlipstreamInfo("vp_slipstream_altairus_1", "vp_slipstream_altairus_2", VEHICLE_ID_SLIPSTREAM_1, true, SPELL_SLIPSTREAM_FIRST),
    SlipstreamInfo("vp_slipstream_altairus_2", "vp_slipstream_altairus_3", VEHICLE_ID_SLIPSTREAM_2, false, SPELL_SLIPSTREAM_SECOND),
    SlipstreamInfo("vp_slipstream_altairus_3", "vp_slipstream_altairus_4", VEHICLE_ID_SLIPSTREAM_3, false, SPELL_SLIPSTREAM_THIRD),
    SlipstreamInfo("vp_slipstream_altairus_4", "vp_slipstream_altairus_5", VEHICLE_ID_SLIPSTREAM_4, false, SPELL_SLIPSTREAM_FOURTH),
    SlipstreamInfo("vp_slipstream_altairus_5", "vp_slipstream_landing_zone_2", VEHICLE_ID_SLIPSTREAM_5, false, SPELL_SLIPSTREAM_LAST),

    // Shortcuts
    SlipstreamInfo("vp_slipstream_entrance_1", "", VEHICLE_ID_SLIPSTREAM_ENTRANCE_1, true, SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS),
    SlipstreamInfo("vp_slipstream_entrance_2", "", VEHICLE_ID_SLIPSTREAM_ENTRANCE_2, true, SPELL_SLIPSTREAM_SHORTCUT_ASAAD),
    SlipstreamInfo("vp_slipstream_back_to_entrance", "", VEHICLE_ID_SLIPSTREAM_BACK_TO_ENTRANCE, true, SPELL_SLIPSTREAM_ASAAD)
};

struct npc_vp_slipstream : public NullCreatureAI
{
    npc_vp_slipstream(Creature* creature) : NullCreatureAI(creature) { }

    // This is a bit hacky but we have to set the vehicleId before the npc is being sent out via UpdateObject to prevent client visuals from breaking
    void InitializeAI() override
    {
        for (SlipstreamInfo const& slipstreamInfo : SlipstreamData)
        {
            if (!me->HasStringId(slipstreamInfo.StringId))
                continue;

            Vehicle const* vehicle = me->GetVehicleKit();
            // Uninstall the existing vehicle kit when the vehicleId mismatches
            if (vehicle && vehicle->GetVehicleInfo()->ID != slipstreamInfo.VehicleId)
            {
                me->RemoveVehicleKit(true);
                vehicle = nullptr;
            }

            if (!vehicle)
                me->CreateVehicleKit(slipstreamInfo.VehicleId, me->GetEntry(), true);

            if (slipstreamInfo.SpellClick)
            {
                me->SetNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            }
            break;
        }
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!apply || !who->IsPlayer())
            return;

        for (SlipstreamInfo const& slipstreamInfo : SlipstreamData)
        {
            if (!me->HasStringId(slipstreamInfo.StringId))
                continue;

            // The cast of the chain spell is slightly delayed
            me->m_Events.AddEventAtOffset([caster = me, playerGuid = who->GetGUID(), chainSpellId = slipstreamInfo.ChainSpellId]()
            {
                if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                    if (player->IsOnVehicle(caster))
                        caster->CastSpell(player, chainSpellId);
            }, 500ms);
            break;
        }
    }
};

static constexpr uint32 const EVENT_EJECT_ALL_PASSENGERS = 1;

struct npc_vp_slipstream_landing_zone : public NullCreatureAI
{
    npc_vp_slipstream_landing_zone(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        // Every time a player enters the landing zone vehicle before it can eject passengers, it will delay its cast
        _events.RescheduleEvent(EVENT_EJECT_ALL_PASSENGERS, 2s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (_events.ExecuteEvent())
            DoCastSelf(SPELL_GENERIC_EJECT_ALL_PASSENGERS);
    }

private:
    EventMap _events;
};

// 84978, 84989, 85395, 85396, 85017 - Slipstream
class spell_vp_slipstream : public SpellScript
{
    bool Load() override
    {
        Creature const* vehicle = GetCaster()->GetVehicleCreatureBase();
        if (!vehicle)
            return false;

        for (SlipstreamInfo const& slipstreamInfo : SlipstreamData)
        {
            if (!vehicle->HasStringId(slipstreamInfo.StringId))
                continue;

            _targetStringId = slipstreamInfo.TargetStringId;
            return true;
        }

        return false;
    }

    void SelectNextSlipstream(WorldObject*& target)
    {
        target = GetCaster()->FindNearestCreatureWithOptions(200.f, { .StringId = _targetStringId });
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_vp_slipstream::SelectNextSlipstream, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
private:
    std::string_view _targetStringId;
};

// 89499, 89501 - Slipstream
class spell_vp_slipstream_shortcut : public SpellScript
{
    bool Load() override
    {
        _instance = GetCaster()->GetInstanceScript();
        return _instance != nullptr;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS_TELEPORT, SPELL_SLIPSTREAM_SHORTCUT_ASAAD_TELEPORT });
    }

    // The distance between the shortcut Slipstreams and the Slipstream Landing Platforms is beyond our grid searching limit, we have to manually select the target
    void SetDestination(SpellDestination& target)
    {
        switch (GetSpellInfo()->Id)
        {
            case SPELL_SLIPSTREAM_SHORTCUT_ALTAIRUS_TELEPORT:
                if (Creature* landingZone = _instance->GetCreature(DATA_SLIPSTREAM_LANDING_ZONE_1))
                    target.Relocate(landingZone->GetPosition());
                break;
            case SPELL_SLIPSTREAM_SHORTCUT_ASAAD_TELEPORT:
                if (Creature* landingZone = _instance->GetCreature(DATA_SLIPSTREAM_LANDING_ZONE_2))
                    target.Relocate(landingZone->GetPosition());
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_vp_slipstream_shortcut::SetDestination, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
private:
    InstanceScript* _instance;
};

void AddSC_vortex_pinnacle()
{
    RegisterVortexPinnacleCreatureAI(npc_vp_slipstream);
    RegisterVortexPinnacleCreatureAI(npc_vp_slipstream_landing_zone);
    RegisterSpellScript(spell_vp_slipstream);
    RegisterSpellScript(spell_vp_slipstream_shortcut);
}
