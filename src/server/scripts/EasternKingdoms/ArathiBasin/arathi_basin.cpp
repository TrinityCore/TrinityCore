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

constexpr uint32 SPELL_BLACKSMITH_WORKING = 261985;

// Base AI class to reduce duplicate code
// Might move this to other file
struct ScheduledAI : public ScriptedAI
{
    ScheduledAI(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

protected:
    TaskScheduler scheduler;
};

// Horde & Alliance Base
struct npc_bg_ab_arathor_gryphon_rider_leader : public ScriptedAI
{
    static constexpr uint32 PATH = 800000059;
    npc_bg_ab_arathor_gryphon_rider_leader(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH, false);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId != PATH)
            return;

        // despawn formation group
        std::list<Creature*> followers;
        me->GetCreatureListWithEntryInGrid(followers, me->GetEntry());
        for (Creature* follower : followers)
            follower->DespawnOrUnsummon(500ms);

        me->DespawnOrUnsummon(500ms);
    }
};

struct npc_bg_ab_defiler_bat_rider_leader : public ScriptedAI
{
    static constexpr uint32 PATH = 800000058;
    npc_bg_ab_defiler_bat_rider_leader(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH, false);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId != PATH)
            return;

        // despawn formation group
        std::list<Creature*> followers;
        me->GetCreatureListWithEntryInGrid(followers, me->GetEntry());
        for (Creature* follower : followers)
            follower->DespawnOrUnsummon(500ms);

        me->DespawnOrUnsummon(500ms);
    }
};

struct npc_bg_ab_the_black_bride: public ScriptedAI
{
    static constexpr uint32 PATH = 800000061;
    npc_bg_ab_the_black_bride(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH, false);
        me->DespawnOrUnsummon(2min);
    }
};

struct npc_bg_ab_radulf_leder : public ScriptedAI
{
    static constexpr uint32 PATH = 800000060;
    npc_bg_ab_radulf_leder(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH, false);
        me->DespawnOrUnsummon(2min);
    }
};

struct npc_bg_ab_dominic_masonwrite : ScheduledAI
{
    static constexpr uint32 SPELL_READ_SCROLL = 122236;
    static constexpr uint32 PATH_1 = 800000062;
    static constexpr uint32 PATH_2 = 800000063;

    npc_bg_ab_dominic_masonwrite(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                DoCastSelf(SPELL_READ_SCROLL);
                scheduler.Schedule(20s, [this](TaskContext)
                {
                    me->RemoveAurasDueToSpell(SPELL_READ_SCROLL);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        DoCastSelf(SPELL_READ_SCROLL);
        scheduler.Schedule(20s, [this](TaskContext /*context*/)
        {
            me->RemoveAurasDueToSpell(SPELL_READ_SCROLL);
            me->GetMotionMaster()->MovePath(PATH_1, false);
        });
    }
};

struct npc_bg_ab_kevin_young : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000000;
    static constexpr uint32 PATH_2 = 800000001;

    npc_bg_ab_kevin_young(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                _scheduler.Schedule(2s, [this](TaskContext /*context*/)
                {
                    me->SetEmoteState(EMOTE_STAND_STATE_NONE);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        DoCastSelf(SPELL_BLACKSMITH_WORKING);
        _scheduler.Schedule(10s, 20s, [this](TaskContext context)
        {
            context.Schedule(1s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(PATH_1, false);
            });
        });
    }

private:
    TaskScheduler _scheduler;
};

struct npc_bg_ab_defiler_combatant_1 : ScheduledAI
{
    static constexpr uint32 SPELL_HOLD_TORCH = 282578;
    static constexpr uint32 PATH = 800000032;

    npc_bg_ab_defiler_combatant_1(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_HOLD_TORCH);
        scheduler.Schedule(1min, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePath(PATH, false);
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH:
                DoCastSelf(SPELL_HOLD_TORCH);
                scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePath(PATH, false);
                });
                break;
            default:
                break;
        }
    }
};

struct npc_bg_ab_defiler_combatant_2 : ScheduledAI
{
    static constexpr uint32 SPELL_HOLD_TORCH = 282578;
    static constexpr uint32 SPELL_THROW_TORCH = 291606;
    static constexpr uint32 NPC_SPELL_BUNNY = 149760;

    npc_bg_ab_defiler_combatant_2(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_HOLD_TORCH);
        scheduler.Schedule(10s, [this](TaskContext context)
        {
            Creature* target = me->FindNearestCreature(NPC_SPELL_BUNNY, 20.0f);
            me->RemoveAurasDueToSpell(SPELL_HOLD_TORCH);
            DoCast(target, SPELL_THROW_TORCH);
            context.Schedule(1s, [this](TaskContext /*context*/)
            {
                DoCastSelf(SPELL_HOLD_TORCH);
            });

            context.Repeat();
        });
    }
};

struct npc_bg_ab_derek_darkmetal : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000033;
    static constexpr uint32 PATH_2 = 800000034;
    static constexpr uint32 PATH_3 = 800000035;
    static constexpr uint32 ITEM_SWORD = 10825;
    static constexpr uint32 SPELL_STEAM = 290554;
    static constexpr uint32 NPC_SPELL_BUNNY = 149760;

    npc_bg_ab_derek_darkmetal(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                scheduler.Schedule(5s, [this](TaskContext /*context*/)
                {
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->SetVirtualItem(1, ITEM_SWORD);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
            {
                ObjectGuid targetGuid;
                if (Creature* target = me->FindNearestCreature(NPC_SPELL_BUNNY, 20.0f))
                {
                    targetGuid = target->GetGUID();
                    target->CastSpell(target, SPELL_STEAM);
                }
                me->PlayOneShotAnimKitId(17343);
                scheduler.Schedule(6s, [this, targetGuid](TaskContext /*context*/)
                {
                    if (Creature* target = me->GetMap()->GetCreature(targetGuid))
                        target->DespawnOrUnsummon();

                    me->GetMotionMaster()->MovePath(PATH_3, false);
                });
                break;
            }
            case PATH_3:
                scheduler.Schedule(1s, [this](TaskContext context)
                {
                    me->SetVirtualItem(1, 0);
                    context.Schedule(3s, [this](TaskContext /*context*/)
                    {
                        StartScript();
                    });
                });
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        me->SetEmoteState(EMOTE_STATE_WORK_SMITH);
        scheduler.Schedule(20s, [this](TaskContext context)
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            context.Schedule(1s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(PATH_1, false);
            });
        });
    }
};

struct npc_bg_ab_arathor_watchman_drinking_1 : ScheduledAI
{
    npc_bg_ab_arathor_watchman_drinking_1(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(5s, 15s, [this](TaskContext context)
        {
            me->SetAIAnimKitId(2358);
            context.Schedule(3s, [this](TaskContext /*context*/)
            {
                me->SetAIAnimKitId(0);
            });

            context.Repeat(5s, 15s);
        });
    }
};

struct npc_bg_ab_arathor_watchman_drinking_2 : ScheduledAI
{
    npc_bg_ab_arathor_watchman_drinking_2(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(5s, 15s, [this](TaskContext context)
        {
            me->PlayOneShotAnimKitId(17347); // drink
            context.Repeat();
        });
    }
};

struct npc_bg_ab_arathor_watchman_talking : ScheduledAI
{
    npc_bg_ab_arathor_watchman_talking(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(10s, 15s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Repeat();
        });
    }
};

struct npc_bg_ab_arathor_watchman_patrol_1 : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000036;
    static constexpr uint32 PATH_2 = 800000037;
    static constexpr uint32 SPELL_COSMETIC_HUMAN_MALE_KUL_TIRAN_SPYGLASS = 271087;

    npc_bg_ab_arathor_watchman_patrol_1(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                DoCastSelf(SPELL_COSMETIC_HUMAN_MALE_KUL_TIRAN_SPYGLASS);
                scheduler.Schedule(10s, [this](TaskContext /*context*/)
                {
                    me->RemoveAurasDueToSpell(SPELL_COSMETIC_HUMAN_MALE_KUL_TIRAN_SPYGLASS);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        DoCastSelf(SPELL_COSMETIC_HUMAN_MALE_KUL_TIRAN_SPYGLASS);
        scheduler.Schedule(5s, [this](TaskContext /*context*/)
        {
            me->RemoveAurasDueToSpell(SPELL_COSMETIC_HUMAN_MALE_KUL_TIRAN_SPYGLASS);
            me->GetMotionMaster()->MovePath(PATH_1, false);
        });
    }
};

struct npc_bg_ab_groundskeeper_olivia : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000039;
    static constexpr uint32 PATH_2 = 800000040;
    static constexpr uint32 PATH_3 = 800000041;

    npc_bg_ab_groundskeeper_olivia(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->SetAIAnimKitId(4760);
                scheduler.Schedule(5s, [this](TaskContext context)
                {
                    me->SetAIAnimKitId(0);
                    context.Schedule(1s, [this](TaskContext /*context*/)
                    {
                        me->GetMotionMaster()->MovePath(PATH_2, false);
                    });
                });
                break;
            case PATH_2:
                me->SetAIAnimKitId(17436);
                scheduler.Schedule(5s, [this](TaskContext context)
                {
                    me->SetAIAnimKitId(0);
                    context.Schedule(1s, [this](TaskContext /*context*/)
                    {
                        me->GetMotionMaster()->MovePath(PATH_3, false);
                    });
                });
                break;
            case PATH_3:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        me->SetAIAnimKitId(17436);
        scheduler.Schedule(10s, [this](TaskContext context)
        {
            me->SetAIAnimKitId(0);
            context.Schedule(1s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(PATH_1, false);
            });
        });
    }
};

// Lumber Mill
struct LumberjackWoodCarrierAI : ScheduledAI
{
    static constexpr uint32 SPELL_LUMBERJACKIN = 290604;
    static constexpr uint32 SPELL_CARRY_WOOD = 244453;
    static constexpr uint32 ITEM_AXE_1H = 109579;

    LumberjackWoodCarrierAI(Creature* creature, uint32 pathId1, uint32 pathId2) : ScheduledAI(creature), _pathId1(pathId1), _pathId2(pathId2) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void StartScript()
    {
        me->SetVirtualItem(0, ITEM_AXE_1H);
        DoCastSelf(SPELL_LUMBERJACKIN);

        scheduler.Schedule(10s, [this](TaskContext context)
        {
            me->RemoveAurasDueToSpell(SPELL_LUMBERJACKIN);
            me->SetVirtualItem(0, 0);

            DoCastSelf(SPELL_CARRY_WOOD, true);

            context.Schedule(1s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(_pathId1, false);
            });
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathId1)
        {
            me->RemoveAurasDueToSpell(SPELL_CARRY_WOOD);
            me->SetStandState(UNIT_STAND_STATE_KNEEL);
            scheduler.Schedule(3500ms, [this](TaskContext)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->HandleEmoteCommand(EMOTE_ONESHOT_STAND);
                me->GetMotionMaster()->MovePath(_pathId2, false);
            });
        }
        else if (pathId == _pathId2)
        {
            StartScript();
        }
    }

private:
    uint32 _pathId1;
    uint32 _pathId2;
};

struct npc_bg_ab_lumberjack_wood_carrier_1 : LumberjackWoodCarrierAI
{
    static constexpr uint32 PATH_1 = 800000042;
    static constexpr uint32 PATH_2 = 800000043;

    npc_bg_ab_lumberjack_wood_carrier_1(Creature* creature) : LumberjackWoodCarrierAI(creature, PATH_1, PATH_2) { }
};

struct npc_bg_ab_lumberjack_wood_carrier_2 : LumberjackWoodCarrierAI
{
    static constexpr uint32 PATH_1 = 800000044;
    static constexpr uint32 PATH_2 = 800000045;

    npc_bg_ab_lumberjack_wood_carrier_2(Creature* creature) : LumberjackWoodCarrierAI(creature, PATH_1, PATH_2) { }
};

struct npc_bg_ab_lumberjack_wood_carrier_3 : LumberjackWoodCarrierAI
{
    static constexpr uint32 PATH_1 = 800000046;
    static constexpr uint32 PATH_2 = 800000047;

    npc_bg_ab_lumberjack_wood_carrier_3(Creature* creature) : LumberjackWoodCarrierAI(creature, PATH_1, PATH_2) { }
};

struct npc_bg_ab_lumberjack_wood_carrier_4 : LumberjackWoodCarrierAI
{
    static constexpr uint32 PATH_1 = 800000048;
    static constexpr uint32 PATH_2 = 800000049;

    npc_bg_ab_lumberjack_wood_carrier_4(Creature* creature) : LumberjackWoodCarrierAI(creature, PATH_1, PATH_2) { }
};

struct npc_bg_ab_lumberjack_wanderer : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000050;
    static constexpr uint32 PATH_2 = 800000051;

    npc_bg_ab_lumberjack_wanderer(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void StartScript()
    {
        scheduler.Schedule(5s, 10s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Schedule(3500ms, [this](TaskContext)
            {
                me->GetMotionMaster()->MovePath(PATH_1, false);
            });
        });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                scheduler.Schedule(6s, [this](TaskContext)
                {
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }
};

struct npc_bg_ab_lumberjack_passive : ScheduledAI
{
    npc_bg_ab_lumberjack_passive(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        me->SetEmoteState(EMOTE_STATE_SIT_CHAIR_MED);
        scheduler.Schedule(5s, 10s, [this](TaskContext context)
        {
            me->PlayOneShotAnimKitId(17347); // drink
            context.Repeat();
        });
    }
};

struct npc_bg_ab_lumberjack : ScriptedAI
{
    npc_bg_ab_lumberjack(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(LumberjackWoodCarrierAI::SPELL_LUMBERJACKIN);
    }
};

// Blacksmith
struct npc_bg_ab_blacksmith_sitting : ScheduledAI
{
    npc_bg_ab_blacksmith_sitting(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        me->SetEmoteState(EMOTE_STATE_SIT_CHAIR_MED);
        scheduler.Schedule(5s, 10s, [this](TaskContext context)
        {
            me->PlayOneShotAnimKitId(5182);
            context.Repeat();
        });
    }
};

struct npc_bg_ab_blacksmith_talking : ScheduledAI
{
    npc_bg_ab_blacksmith_talking(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(10s, 15s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Repeat();
        });
    }
};

struct BlacksmithWorkingAI : ScheduledAI
{
    BlacksmithWorkingAI(Creature* creature, bool removeItem, uint32 pathId1, uint32 pathId2) : ScheduledAI(creature), _removeItem(removeItem), _pathId1(pathId1), _pathId2(pathId2) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathId1)
        {
            if (_removeItem)
                me->LoadEquipment(0, true);

            me->SetEmoteState(EMOTE_STATE_USE_STANDING);
            scheduler.Schedule(5s, [this](TaskContext /*context*/)
            {
                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                me->GetMotionMaster()->MovePath(_pathId2, false);
            });
        }
        else if (pathId == _pathId2)
        {
            StartScript();
        }
    }

    void StartScript()
    {
        DoCastSelf(SPELL_BLACKSMITH_WORKING);
        scheduler.Schedule(10s, 20s, [this](TaskContext /*context*/)
        {
            me->SetFacingTo(5.829399585723876953f);
            me->GetMotionMaster()->MovePath(_pathId1, false);
        });
    }

private:
    bool _removeItem;
    uint32 _pathId1;
    uint32 _pathId2;
};

struct npc_bg_ab_blacksmith_working_1 : BlacksmithWorkingAI
{
    static constexpr uint32 PATH_1 = 800000052;
    static constexpr uint32 PATH_2 = 800000053;

    npc_bg_ab_blacksmith_working_1(Creature* creature) : BlacksmithWorkingAI(creature, true, PATH_1, PATH_2) { }
};

struct npc_bg_ab_blacksmith_working_2 : BlacksmithWorkingAI
{
    static constexpr uint32 PATH_1 = 800000054;
    static constexpr uint32 PATH_2 = 800000055;

    npc_bg_ab_blacksmith_working_2(Creature* creature) : BlacksmithWorkingAI(creature, false, PATH_1, PATH_2) { }
};

struct npc_bg_ab_blacksmith_stone_carrier : ScheduledAI
{
    static constexpr uint32 SPELL_CARRY_STONE = 282906;
    static constexpr uint32 PATH_1 = 800000056;
    static constexpr uint32 PATH_2 = 800000057;

    npc_bg_ab_blacksmith_stone_carrier(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->RemoveAurasDueToSpell(SPELL_CARRY_STONE);
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                scheduler.Schedule(5s, [this](TaskContext /*context*/)
                {
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        me->SetEmoteState(EMOTE_STATE_USE_STANDING);
        scheduler.Schedule(5s, [this](TaskContext /*context*/)
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            DoCastSelf(SPELL_CARRY_STONE);
            me->GetMotionMaster()->MovePath(PATH_1, false);
        });
    }
};

// Farm
struct npc_bg_ab_farmer_talking : ScheduledAI
{
    npc_bg_ab_farmer_talking(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(9s, 11s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Repeat();
        });
    }
};

struct npc_bg_ab_farmer_shouting : ScheduledAI
{
    npc_bg_ab_farmer_shouting(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(5s, 10s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);
            context.Repeat();
        });
    }
};

struct FarmerWorkingAI : ScheduledAI
{
    FarmerWorkingAI(Creature* creature, uint32 pathId1, uint32 pathId2, uint32 aiAnimKitId) : ScheduledAI(creature), _pathId1(pathId1), _pathId2(pathId2), _aiAnimKitId(aiAnimKitId) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathId1)
        {
            me->SetAIAnimKitId(_aiAnimKitId);

            scheduler.Schedule(5s, 15s, [this](TaskContext /*context*/)
            {
                me->SetAIAnimKitId(0);
                me->GetMotionMaster()->MovePath(_pathId2, false);
            });
        }
        else if (pathId == _pathId2)
        {
            StartScript();
        }
    }

    void StartScript()
    {
        me->SetAIAnimKitId(_aiAnimKitId);
        scheduler.Schedule(5s, 15s, [this](TaskContext context)
        {
            me->SetAIAnimKitId(0);
            context.Schedule(2s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePath(_pathId1, false);
            });
        });
    }

private:
    uint32 _pathId1;
    uint32 _pathId2;
    uint32 _aiAnimKitId;
};

struct npc_bg_ab_farmer_working_1 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000004;
    static constexpr uint32 PATH_2 = 800000005;

    npc_bg_ab_farmer_working_1(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 4760) { }
};

struct npc_bg_ab_farmer_working_2 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000006;
    static constexpr uint32 PATH_2 = 800000007;

    npc_bg_ab_farmer_working_2(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 4760) { }
};

struct npc_bg_ab_farmer_working_3 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000008;
    static constexpr uint32 PATH_2 = 800000009;

    npc_bg_ab_farmer_working_3(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 4760) { }
};

struct npc_bg_ab_farmer_working_4 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000010;
    static constexpr uint32 PATH_2 = 800000011;

    npc_bg_ab_farmer_working_4(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 7424) { }
};

struct npc_bg_ab_farmer_working_5 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000012;
    static constexpr uint32 PATH_2 = 800000013;

    npc_bg_ab_farmer_working_5(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 7424) { }
};

struct npc_bg_ab_farmer_working_6 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000014;
    static constexpr uint32 PATH_2 = 800000015;

    npc_bg_ab_farmer_working_6(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 7424) { }
};

struct npc_bg_ab_farmer_working_7 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000016;
    static constexpr uint32 PATH_2 = 800000017;

    npc_bg_ab_farmer_working_7(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 7424) { }
};

struct npc_bg_ab_farmer_working_8 : FarmerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000018;
    static constexpr uint32 PATH_2 = 800000019;

    npc_bg_ab_farmer_working_8(Creature* creature) : FarmerWorkingAI(creature, PATH_1, PATH_2, 7424) { }
};

struct npc_bg_ab_farmer_wanderer : ScheduledAI
{
    static constexpr uint32 PATH_1 = 800000020;
    static constexpr uint32 PATH_2 = 800000021;

    npc_bg_ab_farmer_wanderer(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_1:
                me->SetEmoteState(EMOTE_STATE_USE_STANDING);
                scheduler.Schedule(5s, 10s, [this](TaskContext /*context*/)
                {
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->GetMotionMaster()->MovePath(PATH_2, false);
                });
                break;
            case PATH_2:
                StartScript();
                break;
            default:
                break;
        }
    }

    void StartScript()
    {
        me->SetEmoteState(EMOTE_STATE_USE_STANDING);
        scheduler.Schedule(5s, 10s, [this](TaskContext /*context*/)
        {
            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            me->GetMotionMaster()->MovePath(PATH_1, false);
        });
    }
};

// Stables
struct npc_bg_ab_stablehand_talking : ScheduledAI
{
    npc_bg_ab_stablehand_talking(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(5s, 10s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Repeat();
        });
    }
};

// Gold Mine
struct npc_bg_ab_miner_talking : ScheduledAI
{
    npc_bg_ab_miner_talking(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        scheduler.Schedule(5s, 15s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
            context.Repeat();
        });
    }
};

struct MinerWorkingAI : ScheduledAI
{
    static constexpr uint32 SPELL_CARRY_SACK = 175121;

    MinerWorkingAI(Creature* creature, uint32 pathId1, uint32 pathId2, uint32 pathId3) : ScheduledAI(creature), _pathId1(pathId1), _pathId2(pathId2), _pathId3(pathId3) { }

    void JustAppeared() override
    {
        StartScript();
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == _pathId1)
        {
            me->SetAIAnimKitId(1320);
            scheduler.Schedule(5s, 10s, [this](TaskContext context)
            {
                me->SetAIAnimKitId(0);
                DoCastSelf(SPELL_CARRY_SACK);
                context.Schedule(1s, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePath(_pathId2, false);
                });
            });
        }
        else if (pathId == _pathId2)
        {
            me->RemoveAurasDueToSpell(SPELL_CARRY_SACK);
            me->SetEmoteState(EMOTE_STATE_USE_STANDING);
            scheduler.Schedule(10s, [this](TaskContext /*context*/)
            {
                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                me->GetMotionMaster()->MovePath(_pathId3, false);
            });
        }
        else if (pathId == _pathId3)
        {
            StartScript();
        }
    }

    void StartScript()
    {
        me->GetMotionMaster()->MovePath(_pathId1, false);
    }

private:
    uint32 _pathId1;
    uint32 _pathId2;
    uint32 _pathId3;
};

struct npc_bg_ab_miner_working_1 : MinerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000022;
    static constexpr uint32 PATH_2 = 800000023;
    static constexpr uint32 PATH_3 = 800000024;

    npc_bg_ab_miner_working_1(Creature* creature) : MinerWorkingAI(creature, PATH_1, PATH_2, PATH_3) { }
};

struct npc_bg_ab_miner_working_2 : MinerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000025;
    static constexpr uint32 PATH_2 = 800000026;
    static constexpr uint32 PATH_3 = 800000027;

    npc_bg_ab_miner_working_2(Creature* creature) : MinerWorkingAI(creature, PATH_1, PATH_2, PATH_3) { }
};

struct npc_bg_ab_miner_working_3 : MinerWorkingAI
{
    static constexpr uint32 PATH_1 = 800000028;
    static constexpr uint32 PATH_2 = 800000029;
    static constexpr uint32 PATH_3 = 800000030;

    npc_bg_ab_miner_working_3(Creature* creature) : MinerWorkingAI(creature, PATH_1, PATH_2, PATH_3) { }
};

// Misc
struct npc_bg_ab_elemental_skirmish : ScheduledAI
{
    npc_bg_ab_elemental_skirmish(Creature* creature) : ScheduledAI(creature) { }

    void JustAppeared() override
    {
        me->SetEmoteState(EMOTE_STATE_READY_UNARMED);
        scheduler.Schedule(4s, 8s, [this](TaskContext context)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK_UNARMED);
            context.Repeat();
        });
    }
};

// Spells
// 261985 - Blacksmith Working
class spell_bg_ab_blacksmith_working : public AuraScript
{
    PrepareAuraScript(spell_bg_ab_blacksmith_working);

    static constexpr uint32 ITEM_BLACKSMITH_HAMMER = 5956;

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetUnitOwner()->SetVirtualItem(0, ITEM_BLACKSMITH_HAMMER);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* owner = GetUnitOwner())
            if (Creature* creatureOwner = owner->ToCreature())
                creatureOwner->LoadEquipment(creatureOwner->GetOriginalEquipmentId());
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_bg_ab_blacksmith_working::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_bg_ab_blacksmith_working::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_arathi_basin()
{
    RegisterCreatureAI(npc_bg_ab_arathor_gryphon_rider_leader);
    RegisterCreatureAI(npc_bg_ab_defiler_bat_rider_leader);
    RegisterCreatureAI(npc_bg_ab_the_black_bride);
    RegisterCreatureAI(npc_bg_ab_radulf_leder);
    RegisterCreatureAI(npc_bg_ab_dominic_masonwrite);
    RegisterCreatureAI(npc_bg_ab_kevin_young);
    RegisterCreatureAI(npc_bg_ab_defiler_combatant_1);
    RegisterCreatureAI(npc_bg_ab_defiler_combatant_2);
    RegisterCreatureAI(npc_bg_ab_derek_darkmetal);
    RegisterCreatureAI(npc_bg_ab_arathor_watchman_drinking_1);
    RegisterCreatureAI(npc_bg_ab_arathor_watchman_drinking_2);
    RegisterCreatureAI(npc_bg_ab_arathor_watchman_talking);
    RegisterCreatureAI(npc_bg_ab_arathor_watchman_patrol_1);
    RegisterCreatureAI(npc_bg_ab_groundskeeper_olivia);
    RegisterCreatureAI(npc_bg_ab_lumberjack);
    RegisterCreatureAI(npc_bg_ab_lumberjack_wood_carrier_1);
    RegisterCreatureAI(npc_bg_ab_lumberjack_wood_carrier_2);
    RegisterCreatureAI(npc_bg_ab_lumberjack_wood_carrier_3);
    RegisterCreatureAI(npc_bg_ab_lumberjack_wanderer);
    RegisterCreatureAI(npc_bg_ab_lumberjack_wood_carrier_4);
    RegisterCreatureAI(npc_bg_ab_lumberjack_passive);
    RegisterCreatureAI(npc_bg_ab_blacksmith_sitting);
    RegisterCreatureAI(npc_bg_ab_blacksmith_talking);
    RegisterCreatureAI(npc_bg_ab_blacksmith_working_1);
    RegisterCreatureAI(npc_bg_ab_blacksmith_working_2);
    RegisterCreatureAI(npc_bg_ab_blacksmith_stone_carrier);
    RegisterCreatureAI(npc_bg_ab_farmer_talking);
    RegisterCreatureAI(npc_bg_ab_farmer_shouting);
    RegisterCreatureAI(npc_bg_ab_farmer_working_1);
    RegisterCreatureAI(npc_bg_ab_farmer_working_2);
    RegisterCreatureAI(npc_bg_ab_farmer_working_3);
    RegisterCreatureAI(npc_bg_ab_farmer_working_4);
    RegisterCreatureAI(npc_bg_ab_farmer_working_5);
    RegisterCreatureAI(npc_bg_ab_farmer_working_6);
    RegisterCreatureAI(npc_bg_ab_farmer_working_7);
    RegisterCreatureAI(npc_bg_ab_farmer_working_8);
    RegisterCreatureAI(npc_bg_ab_farmer_wanderer);
    RegisterCreatureAI(npc_bg_ab_stablehand_talking);
    RegisterCreatureAI(npc_bg_ab_miner_talking);
    RegisterCreatureAI(npc_bg_ab_miner_working_1);
    RegisterCreatureAI(npc_bg_ab_miner_working_2);
    RegisterCreatureAI(npc_bg_ab_miner_working_3);
    RegisterCreatureAI(npc_bg_ab_elemental_skirmish);
    RegisterSpellScript(spell_bg_ab_blacksmith_working);
}
