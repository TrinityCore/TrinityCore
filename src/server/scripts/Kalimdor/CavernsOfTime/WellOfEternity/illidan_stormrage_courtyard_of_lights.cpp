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

#include "CombatAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "well_of_eternity.h"

enum Texts
{
    SAY_GREETING_1       = 0,
    SAY_GREETING_2       = 1,
    SAY_GREETING_WAITING = 2,
    SAY_SHADOWCLOAK      = 3,
    SAY_ESCORT_1         = 4,
    SAY_ESCORT_2         = 5,
    SAY_DISTRACT_1       = 6,
    SAY_DISTRACT_END_1   = 7,
    SAY_IDLE_1           = 8,
    SAY_COMBAT_1         = 9,

    // NYI (for part 2)
    SAY_INTRO_11        = 10,
    SAY_INTRO_12        = 11,
    SAY_INTRO_13        = 12,
    SAY_INTRO_14        = 13,
    SAY_INTRO_15        = 14,
    SAY_INTRO_16        = 15,
    SAY_INTRO_17        = 16,
    SAY_INTRO_18        = 17,
    SAY_INTRO_19        = 18,
    SAY_INTRO_20        = 19,
    SAY_INTRO_21        = 20,
    SAY_INTRO_22        = 21,
    SAY_INTRO_23        = 22,
    SAY_INTRO_24        = 23,
    SAY_INTRO_25        = 24,
    SAY_INTRO_26        = 25,
    SAY_INTRO_27        = 26,
    SAY_INTRO_28        = 27
};

enum Actions
{
    ACTION_ILLIDAN_INTRO        = 1,
    ACTION_TALK                 = 2,
    ACTION_SKIP_TALK            = 3,
    ACTION_MOVE_TO_DISTRACT     = 4,
    ACTION_START_DISTRACTION    = 5,
    ACTION_CHECK_PLAYERS        = 6,
    ACTION_FINISH_DISTRACTION   = 7,
    ACTION_ENTER_COMBAT         = 8
};

enum Spells
{
    SPELL_SHADOWCLOAK                        = 110231, // Casted on Pets
    SPELL_SHADOWCLOAK_VEHICLE                = 105915, // ToDo: Fix mount vehicle when aura is removed and applied again on Illidan
    SPELL_SHADOW_WALK_VEHICLE                = 102994, // ToDo: Fix mount vehicle when aura is removed and applied again / support player vehicles?
    SPELL_SHADOW_WALK                        = 103020,
    SPELL_SHADOW_AMBUSHER                    = 103018,
    SPELL_WALL_OF_SHADOW                     = 104400,

    // Fel Crystal / Portal Npcs
    SPELL_ARCANE_EXPLOSION                   = 98122
};

enum MovementMisc
{
    PATH_ILLIDAN_INTRO         = 5550000,
    WAYPOINT_GOSSIP            = 4,

    PATH_ILLIDAN_ESCORT        = 5550001,
    WAYPOINT_TALK              = 2,
    WAYPOINT_DISTRACT          = 9,

    PATH_ILLIDAN_CRYSTAL_1     = 5550002,
    WAYPOINT_ATTACK            = 9,

    POINT_DESPAWN_FIRST_PORTAL = 0,

    // Well of Eternity Stalker
    POINT_START_MOVING  = 0
};

enum Gossip
{
    MENU_ID_ILLIDAN_1     = 13162,
    MENU_ID_ILLIDAN_2     = 13163,
    MENU_ID_ILLIDAN_WALL  = 13395
};

enum Tasks
{
    TASK_WAITING       = 0,
    TASK_CHECK_PLAYERS = 1
};

enum Factions
{
    FACTION_WELL_OF_ETERNITY_ILLIDAN = 2385
};

constexpr Position DistractionEndPoint[2] =
{
    { 3313.2888f, -4932.8378f },
    { 3290.6479f, -4945.4965f }
};

constexpr Position IllidanSummonPos[4] =
{
    { 3173.6746f, -4875.5103f, 194.43994f, 5.3581609f },
    { 3294.2f,    -4981.97f,   181.16032f, 0.8726646f },
    { 3444.98f,   -4886.34f,   181.16032f, 4.0142574f },
    { 3471.1199f, -4839.83f,   194.21544f, 2.0071287f }
};

constexpr Position WallOfShadowStalkerPos  = { 3312.3826f, -4906.39f, 181.07674f };

// Areatrigger - 7066
struct at_woe_illidan_intro : AreaTriggerScript
{
public:
    at_woe_illidan_intro() : AreaTriggerScript("at_woe_illidan_intro") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (instance->GetData(DATA_ILLIDAN_START_INTRO) != DONE)
            {
                if (Creature* illidan = player->SummonCreature(NPC_ILLIDAN_PART_1, IllidanSummonPos[0], TEMPSUMMON_MANUAL_DESPAWN))
                    illidan->AI()->DoAction(ACTION_ILLIDAN_INTRO);
            }

        }
        return true;
    }
};

// Areatrigger - 7144
struct at_woe_illidan_skip_talk : AreaTriggerScript
{
public:
    at_woe_illidan_skip_talk() : AreaTriggerScript("at_woe_illidan_skip_talk") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (instance->GetData(DATA_ILLIDAN_START_ESCORT) != DONE)
            {
                if (Creature* illidan = instance->GetCreature(DATA_ILLIDAN_COURTYARD_OF_LIGHTS))
                    illidan->AI()->DoAction(ACTION_SKIP_TALK);
            }
        }
        return true;
    }
};

// 55500 - Illidan Stormrage (Courtyard of Lights)
struct npc_illidan_stormrage_courtyard_of_lights : public ScriptedAI
{
    npc_illidan_stormrage_courtyard_of_lights(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_COMBAT_1);
        me->RemoveAurasDueToSpell(SPELL_SHADOWCLOAK_VEHICLE);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_DESPAWN_FIRST_PORTAL)
        {
            _instance->SetData(DATA_ILLIDAN_FIRST_CRYSTAL, DONE);
            me->DespawnOrUnsummon();
            me->SummonCreature(NPC_ILLIDAN_PART_1, IllidanSummonPos[1], TEMPSUMMON_MANUAL_DESPAWN);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoCast(SPELL_SHADOWCLOAK_VEHICLE);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            /* ---------------- PART 1 --------------*/
            case ACTION_ILLIDAN_INTRO:
            {
                scheduler.Schedule(1s + 116ms, [this](TaskContext context)
                {
                    me->GetMotionMaster()->MovePath(PATH_ILLIDAN_INTRO, false);
                    context.Schedule(804ms, [this](TaskContext context)
                    {
                        Talk(SAY_GREETING_1);

                        context.Schedule(45s, 60s, TASK_WAITING, [this](TaskContext task)
                        {
                            Talk(SAY_GREETING_WAITING);
                            task.Repeat();
                        });
                    });
                });
                _instance->SetData(DATA_ILLIDAN_START_INTRO, DONE);
                break;
            }
            case ACTION_TALK:
            {
                _instance->SetData(DATA_ILLIDAN_START_ESCORT, DONE);
                _instance->DoCastSpellOnPlayers(SPELL_SHADOWCLOAK_PLAYER);
                scheduler.CancelGroup(TASK_WAITING);
                DoCast(SPELL_SHADOWCLOAK_VEHICLE);
                Talk(SAY_ESCORT_1);
                DoAction(ACTION_MOVE_TO_DISTRACT);
                break;
            }
            case ACTION_SKIP_TALK:
            {
                _instance->SetData(DATA_ILLIDAN_START_ESCORT, DONE);
                _instance->DoCastSpellOnPlayers(SPELL_SHADOWCLOAK_PLAYER);
                scheduler.CancelGroup(TASK_WAITING);
                DoCast(SPELL_SHADOWCLOAK_VEHICLE);
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_ESCORT_1);
                DoAction(ACTION_MOVE_TO_DISTRACT);
                break;
            }
            case ACTION_MOVE_TO_DISTRACT:
            {
                scheduler.Schedule(3s + 700ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePath(PATH_ILLIDAN_ESCORT, false);
                });
                break;
            }
            case ACTION_START_DISTRACTION:
            {
                scheduler.Schedule(4s + 200ms, [this](TaskContext context)
                {
                    DoCast(SPELL_WALL_OF_SHADOW);
                    context.Schedule(4s, [this](TaskContext /*context*/)
                    {
                        DoAction(ACTION_CHECK_PLAYERS);
                    });
                });
                break;
            }
            case ACTION_CHECK_PLAYERS:
            {
                scheduler.Schedule(500ms, 1s, [this](TaskContext task)
                {
                    // Hacky, but works like retail, and i didn't find any areatriggers, auras or npcs related to this event
                    // We need all players to move through the wall of shadow before Illidan starts moving again
                    Map::PlayerList const& players = _instance->instance->GetPlayers();
                    bool playerMisplaced = false;
                    for (auto const& i : players)
                    {
                        if (Player* player = i.GetSource())
                        {
                            if (player->GetDistance2d(DistractionEndPoint[0].GetPositionX(), DistractionEndPoint[0].GetPositionY()) >= 15.0f && player->GetDistance2d(DistractionEndPoint[1].GetPositionX(), DistractionEndPoint[1].GetPositionY()) >= 15.0f)
                            {
                                playerMisplaced = true;
                                break;
                            }
                        }
                    }

                    if (!playerMisplaced)
                        DoAction(ACTION_FINISH_DISTRACTION);
                    else
                        task.Repeat();
                });
                break;
            }
            case ACTION_FINISH_DISTRACTION:
            {
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_DISTRACT_END_1);
                scheduler.Schedule(3s, [this](TaskContext context)
                {
                    me->GetMotionMaster()->MovePath(PATH_ILLIDAN_CRYSTAL_1, false);

                    context.Schedule(3s + 622ms, [this](TaskContext /*context*/)
                    {
                        std::list<Creature*> demonStalkers;
                        GetCreatureListWithEntryInGrid(demonStalkers, me, NPC_DEMON_STALKER, 100.0f);

                        for (Creature* demonStalkerGroup : demonStalkers)
                            demonStalkerGroup->DespawnOrUnsummon();
                    });
                });

                break;
            }
            case ACTION_ENTER_COMBAT:
            {
                me->SetFaction(FACTION_WELL_OF_ETERNITY_ILLIDAN);
                SetCombatMovement(true);
                break;
            }
            case ACTION_ILLIDAN_ON_FIRST_CRYSTAL:
            {
                me->GetMotionMaster()->MovePoint(POINT_DESPAWN_FIRST_PORTAL, IllidanSummonPos[1]);
                break;
            }
            /* ------------ END OF PART 1 -----------*/
            default:
                break;
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_ILLIDAN_INTRO && waypointId == WAYPOINT_GOSSIP)
        {
            me->RemoveAurasDueToSpell(SPELL_SHADOWCLOAK_VEHICLE);
            Talk(SAY_GREETING_2);
            me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        }
        else if (pathId == PATH_ILLIDAN_ESCORT)
        {
            if (waypointId == WAYPOINT_TALK)
                Talk(SAY_ESCORT_2);
            else if (waypointId == WAYPOINT_DISTRACT)
            {
                Talk(SAY_DISTRACT_1);
                DoAction(ACTION_START_DISTRACTION);
                me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            }
        }
        else if (pathId == PATH_ILLIDAN_CRYSTAL_1)
        {
            if (waypointId == WAYPOINT_ATTACK)
                Talk(SAY_IDLE_1);
        }
    }

    bool OnGossipHello(Player* player) override
    {
        if (_instance->GetData(DATA_ILLIDAN_START_ESCORT) == DONE)
        {
            player->PrepareGossipMenu(me, MENU_ID_ILLIDAN_WALL, true);
            player->SendPreparedGossip(me);
            return true;
        }

        player->PrepareGossipMenu(me, MENU_ID_ILLIDAN_1, true);
        player->SendPreparedGossip(me);

        return true;
    }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        ClearGossipMenuFor(player);
        switch (menuId)
        {
            case MENU_ID_ILLIDAN_1:
            {
                player->PrepareGossipMenu(me, MENU_ID_ILLIDAN_2, true);
                player->SendPreparedGossip(me);

                Talk(SAY_SHADOWCLOAK);
                _instance->DoCastSpellOnPlayers(SPELL_SHADOWCLOAK_PLAYER);
                break;
            }
            case MENU_ID_ILLIDAN_2:
            {
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                DoAction(ACTION_TALK);
                break;
            }
        }
        return true;
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;
    }

private:
    TaskScheduler scheduler;
    InstanceScript* _instance;
};

// 103004 - Shadowcloak
class spell_woe_shadowcloak : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_WALK_VEHICLE });
    }

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SHADOW_WALK_VEHICLE, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_woe_shadowcloak::HandleEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_woe_shadowcloak_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_WALK_VEHICLE, SPELL_SHADOW_WALK, SPELL_SHADOW_AMBUSHER });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        // To-Do: Set the duration of shadow ambusher based on number of ticks that player has of shadow walk aura
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* illidan = instance->GetCreature(DATA_ILLIDAN_COURTYARD_OF_LIGHTS))
            if (npc_illidan_stormrage_courtyard_of_lights* illidanAI = CAST_AI(npc_illidan_stormrage_courtyard_of_lights, illidan->GetAI()))
                illidanAI->DoAction(ACTION_ENTER_COMBAT);
    }

    void HandleStealth(bool isNowInCombat)
    {
        if (isNowInCombat)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_SHADOW_WALK_VEHICLE);
            GetTarget()->RemoveAurasDueToSpell(SPELL_SHADOW_WALK);
        }
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_SHADOW_WALK_VEHICLE, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_woe_shadowcloak_aura::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEnterLeaveCombat += AuraEnterLeaveCombatFn(spell_woe_shadowcloak_aura::HandleStealth);
    }
};

// 110755 - (Serverside/Non-DB2) Shadowcloak Dismount
class spell_woe_shadowcloak_dismount : public AuraScript
{
    void HandleDismount(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasByType(SPELL_AURA_MOUNTED);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_woe_shadowcloak_dismount::HandleDismount, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 110121 - Distract Demon Missile
// 110103 - (Serverside/Non-DB2) Distract Demon Summon
class spell_woe_distract_demon_missile : public SpellScript
{
    void SelectTarget(WorldObject*& target)
    {
        Creature* stalker = GetCaster()->FindNearestCreatureWithOptions(50.0f, { .StringId = "wall_of_shadow_stalker" });

        if (!stalker)
            return;

        _wallOfShadowGUID = stalker->GetGUID();
        target = stalker;
    }

    void StartMoving(SpellEffIndex /*effIndex*/)
    {
        if (Creature* stalker = ObjectAccessor::GetCreature(*GetCaster(), _wallOfShadowGUID))
        {
            stalker->GetMotionMaster()->MovePoint(POINT_START_MOVING, WallOfShadowStalkerPos);
            stalker->DespawnOrUnsummon(4s);
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_woe_distract_demon_missile::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
        OnEffectHit += SpellEffectFn(spell_woe_distract_demon_missile::StartMoving, EFFECT_0, SPELL_EFFECT_ANY);
    }

private:
    ObjectGuid _wallOfShadowGUID;
};

// 104400 - Wall of Shadow
class spell_woe_wall_of_shadow : public AuraScript
{
    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        // SPELL_ATTR1_TRACK_TARGET_IN_CHANNEL doesn't work properly on this case
        GetCaster()->SetFacingToObject(GetTarget());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_woe_wall_of_shadow::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_illidan_stormrage_courtyard_of_lights()
{
    RegisterWellOfEternityCreatureAI(npc_illidan_stormrage_courtyard_of_lights);
    RegisterSpellAndAuraScriptPair(spell_woe_shadowcloak, spell_woe_shadowcloak_aura);
    RegisterSpellScript(spell_woe_shadowcloak_dismount);
    RegisterSpellScript(spell_woe_distract_demon_missile);
    RegisterSpellScript(spell_woe_wall_of_shadow);

    new at_woe_illidan_intro();
    new at_woe_illidan_skip_talk();
}
