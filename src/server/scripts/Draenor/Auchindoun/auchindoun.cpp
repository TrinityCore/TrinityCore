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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "auchindoun.h"

enum AuchindounSpells
{
    SPELL_HALO_HEAL                  = 157795,
    SPELL_TUULANI_UNLOCK_VISUAL      = 160415,
    SPELL_GRIMRAIL_DEPOT_SCENE       = 178747,
    SPELL_GRIMRAIL_DEPOT_SELECTOR    = 178800,
    SPELL_GRIMRAIL_DEPOT_TELEPORT    = 178799,
    SPELL_GRIMRAIL_DEPOT_REMOVE_AURA = 178746

    // SPELL_INSTANCE_BOOTSTRAPPER      = 171344 // This spell appears in a lot of sniffs, but the purpose is unknown
};

enum AuchindounActions
{
    ACTION_TUULANI_INTRO = 1,
    ACTION_TUULANI_BREAK_BARRIER,
    ACTION_AUCHENAI_DEFENDER_TALK
};

enum AuchindounTexts
{
    // Auchenai Defender
    SAY_NYAMI_AWAITS    = 0,

    // Soulbinder Tuulani
    SAY_WELCOME_1       = 0,
    SAY_WELCOME_2       = 1,
    SAY_WELCOME_3       = 2,
    SAY_BREAK_BARRIER_1 = 3,
    SAY_BREAK_BARRIER_2 = 4,
    SAY_HEROES_SOULS    = 5
};

enum AuchindounMisc
{
    // Waypoint
    PATH_BARRIER      = 7924800,
    PATH_MOVE_TO_BOSS = 7924801,

    POINT_TALK    = 2,
    POINT_BARRIER = 8,

    POINT_SOULS   = 5,

    // Spawngroups
    SPAWNGROUP_TUULANI_IMPRISONED = 1264
};

// 9973 - Areatrigger
class at_auchindoun_entrance : public OnlyOnceAreaTriggerScript
{
public:
    at_auchindoun_entrance() : OnlyOnceAreaTriggerScript("at_auchindoun_entrance") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* tuulani = instance->GetCreature(DATA_SOULBINDER_TUULANI))
                tuulani->AI()->DoAction(ACTION_TUULANI_INTRO);
        }
        return true;
    }
};

// 10072 - Areatrigger
class at_auchindoun_auchenai_defender_intro : public OnlyOnceAreaTriggerScript
{
public:
    at_auchindoun_auchenai_defender_intro() : OnlyOnceAreaTriggerScript("at_auchindoun_auchenai_defender_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (Creature* auchenaiDefender = player->FindNearestCreatureWithOptions(30.0f, { .StringId = "npc_auchenai_defender_intro" }))
            auchenaiDefender->AI()->DoAction(ACTION_AUCHENAI_DEFENDER_TALK);

        return true;
    }
};

// 9974 - Areatrigger
// Not OnlyOnce because players can trigger this AT before Tuulani reaches the barrier
class at_auchindoun_barrier : public AreaTriggerScript
{
public:
    at_auchindoun_barrier() : AreaTriggerScript("at_auchindoun_barrier") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* tuulani = instance->GetCreature(DATA_SOULBINDER_TUULANI))
                tuulani->AI()->DoAction(ACTION_TUULANI_BREAK_BARRIER);
        }
        return true;
    }
};

// 10280 - Areatrigger
class at_auchindoun_soulbinder_nyami_scene : public OnlyOnceAreaTriggerScript
{
public:
    at_auchindoun_soulbinder_nyami_scene() : OnlyOnceAreaTriggerScript("at_auchindoun_soulbinder_nyami_scene") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        player->CastSpell(player, SPELL_GRIMRAIL_DEPOT_SELECTOR, true);

        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* tuulani = instance->GetCreature(DATA_SOULBINDER_TUULANI))
                tuulani->DespawnOrUnsummon();
        }
        return true;
    }
};

// 77693 - Auchenai Defender
struct npc_auchindoun_auchenai_defender : public ScriptedAI
{
    npc_auchindoun_auchenai_defender(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_AUCHENAI_DEFENDER_TALK)
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);

            _scheduler.Schedule(1s + 300ms, [this](TaskContext /*task*/)
            {
                me->SetFacingTo(3.8194849f);
                Talk(SAY_NYAMI_AWAITS);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 79248 - Soulbinder Tuulani
struct npc_auchindoun_soulbinder_tuulani : public ScriptedAI
{
    npc_auchindoun_soulbinder_tuulani(Creature* creature) : ScriptedAI(creature), _isAtBarrier(false), _actionStarted(false) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_TUULANI_INTRO)
        {
            Talk(SAY_WELCOME_1);

            _scheduler.Schedule(4s + 300ms, [this](TaskContext task)
            {
                Talk(SAY_WELCOME_2);

                task.Schedule(6s, [this](TaskContext /*task*/)
                {
                    me->GetMotionMaster()->MovePath(PATH_BARRIER, false);
                });
            });
        }
        else if (action == ACTION_TUULANI_BREAK_BARRIER)
        {
            if (!_isAtBarrier || _actionStarted)
                return;

            _actionStarted = true;

            Talk(SAY_BREAK_BARRIER_1);

            _scheduler.Schedule(3s, [this](TaskContext task)
            {
                DoCast(SPELL_TUULANI_UNLOCK_VISUAL);

                task.Schedule(4s, [this](TaskContext task)
                {
                    if (GameObject* holyBarrier = me->GetInstanceScript()->GetGameObject(DATA_HOLY_BARRIER))
                        holyBarrier->SetGoState(GO_STATE_ACTIVE);

                    task.Schedule(2s + 300ms, [this](TaskContext task)
                    {
                        Talk(SAY_BREAK_BARRIER_2);

                        task.Schedule(1s + 300ms, [this](TaskContext /*task*/)
                        {
                            me->GetMotionMaster()->MovePath(PATH_MOVE_TO_BOSS, false);
                        });
                    });
                });
            });
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_BARRIER)
        {
            switch (waypointId)
            {
                case POINT_TALK:
                {
                    _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                    {
                        Talk(SAY_WELCOME_3);
                    });
                    break;
                }
                case POINT_BARRIER:
                {
                    _isAtBarrier = true;
                    break;
                }
                default:
                    break;
            }
        }
        else if (pathId == PATH_MOVE_TO_BOSS)
        {
            if (waypointId == POINT_SOULS)
            {
                _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    me->SetFacingTo(1.727875f);
                    Talk(SAY_HEROES_SOULS);
                });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    bool _isAtBarrier;
    bool _actionStarted;
};

// 155647 - NPC Reaction
struct at_auchindoun_npc_reaction : AreaTriggerAI
{
    at_auchindoun_npc_reaction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsCreature() || unit->GetEmoteState() == EMOTE_STATE_READY1H_ALLOW_MOVEMENT || unit->GetEntry() == NPC_SOULBINDER_TUULANI)
            return;

        _scheduler.Schedule(1500ms, [this, unitGUID = unit->GetGUID()](TaskContext task)
        {
            Creature* auchenaiDefender = ObjectAccessor::GetCreature(*at, unitGUID);
            if (!auchenaiDefender)
                return;

            if (Unit* caster = at->GetCaster())
                auchenaiDefender->SetFacingToObject(caster);
            auchenaiDefender->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

            task.Schedule(4s, [this, unitGUID](TaskContext /*task*/)
            {
                Creature* auchenaiDefender = ObjectAccessor::GetCreature(*at, unitGUID);
                if (!auchenaiDefender)
                    return;

                auchenaiDefender->SetFacingTo(auchenaiDefender->GetHomePosition().GetOrientation());
            });
        });
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 157762 - Halo
class spell_auchindoun_halo : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HALO_HEAL });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        if (!GetHitUnit()->IsCreature())
            return;

        GetCaster()->CastSpell(GetHitUnit(), SPELL_HALO_HEAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_auchindoun_halo::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 178800 - Grimrail Depot
class spell_auchindoun_grimrail_depot_scene_selector : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_GRIMRAIL_DEPOT_SCENE, true);
        // GetCaster()->CastSpell(GetHitUnit(), SPELL_INSTANCE_BOOTSTRAPPER, false);
    }

    void HandleEvent(SpellEffIndex /*effIndex*/) const
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            instance->SendEncounterUnit(ENCOUNTER_FRAME_PHASE_SHIFT_CHANGED, nullptr);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_auchindoun_grimrail_depot_scene_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHit += SpellEffectFn(spell_auchindoun_grimrail_depot_scene_selector::HandleEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
    }
};

// 178747 - Grimrail Depot
class scene_auchindoun_soulbinder_nyami : public SceneScript
{
public:
    scene_auchindoun_soulbinder_nyami() : SceneScript("scene_auchindoun_soulbinder_nyami") { }

    static void HandleScene(Player* player)
    {
        player->ClearUnitState(UNIT_STATE_ROOT);
        player->CastSpell(player, SPELL_GRIMRAIL_DEPOT_TELEPORT, true);
        player->CastSpell(player, SPELL_GRIMRAIL_DEPOT_REMOVE_AURA, TRIGGERED_FULL_MASK);
        PhasingHandler::OnConditionChange(player);

        Map* map = player->GetMap();
        if (!map->IsSpawnGroupActive(SPAWNGROUP_TUULANI_IMPRISONED))
            map->SpawnGroupSpawn(SPAWNGROUP_TUULANI_IMPRISONED);
    }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->AddUnitState(UNIT_STATE_ROOT);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        HandleScene(player);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        HandleScene(player);
    }
};

void AddSC_auchindoun()
{
    new at_auchindoun_entrance();
    new at_auchindoun_auchenai_defender_intro();
    new at_auchindoun_barrier();
    new at_auchindoun_soulbinder_nyami_scene();

    RegisterAuchindounCreatureAI(npc_auchindoun_auchenai_defender);
    RegisterAuchindounCreatureAI(npc_auchindoun_soulbinder_tuulani);
    RegisterAreaTriggerAI(at_auchindoun_npc_reaction);
    RegisterSpellScript(spell_auchindoun_halo);
    RegisterSpellScript(spell_auchindoun_grimrail_depot_scene_selector);

    new scene_auchindoun_soulbinder_nyami();
}
