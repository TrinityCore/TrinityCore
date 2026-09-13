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

/*
 * Combat timers requires to be revisited
 * SAY_EVENT is NYI
 * Boundary is NYI
 * Purpose of SPELL_FIRE_BOMB_DUMMY is unknown
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "zulaman.h"

enum JanalaiTexts
{
    SAY_AGGRO                   = 0,
    SAY_FIRE_BOMBS              = 1,
    SAY_SUMMON_HATCHER          = 2,
    SAY_ALL_EGGS                = 3,
    SAY_BERSERK                 = 4,
    SAY_SLAY                    = 5,
    SAY_DEATH                   = 6,
    SAY_EVENT                   = 7,
    EMOTE_FRENZY                = 8
};

enum JanalaiSpells
{
    // Jan'alai - Combat
    SPELL_FLAME_BREATH          = 43140,
    SPELL_SUMMON_HATCHER_1      = 43962,
    SPELL_SUMMON_HATCHER_2      = 45340,
    SPELL_HATCH_ALL_EGGS        = 43144,
    SPELL_FRENZY                = 44779,
    SPELL_BERSERK               = 45078,

    // Jan'alai - Combat - Bomb Sequence
    SPELL_TELEPORT_TO_CENTER    = 43098,
    SPELL_SUMMON_ALL_PLAYERS    = 43096,
    SPELL_FIRE_BOMB_INITIAL     = 42621,
    SPELL_FIRE_WALL             = 43113,
    SPELL_FIRE_BOMB_MISSILE     = 42628,

    // Fire Bomb
    SPELL_FIRE_BOMB_VISUAL      = 42629,
    SPELL_FIRE_BOMB_DAMAGE      = 42630,
    SPELL_FIRE_BOMB_DUMMY       = 42631,

    // Amani'shi Hatcher
    SPELL_HATCH_EGGS            = 42471,

    // Dragonhawk Egg
    SPELL_SUMMON_HATCHLING      = 42493,

    // Amani Dragonhawk Hatchling
    SPELL_FLAME_BUFFET          = 43299,

    // Scripts
    SPELL_SUMMON_ALL_PLAYERS_2  = 43097,
    SPELL_SUMMON_FIRE_BOMB_05   = 42622,
    SPELL_SUMMON_FIRE_BOMB_10   = 42623,
    SPELL_SUMMON_FIRE_BOMB_15   = 42624,
    SPELL_SUMMON_FIRE_BOMB_20   = 42625,
    SPELL_SUMMON_FIRE_BOMB_25   = 42626,
    SPELL_SUMMON_FIRE_BOMB_30   = 42627
};

enum JanalaiEvents
{
    // Combat
    EVENT_FLAME_BREATH          = 1,
    EVENT_SUMMON_HATCHERS,
    EVENT_HATCH_ALL_EGGS,
    EVENT_FRENZY,
    EVENT_BERSERK,

    // Combat - Fire Bomb Sequence
    EVENT_FIRE_BOMBS,
    EVENT_FIRE_BOMBS_2,
    EVENT_FIRE_BOMBS_3,
    EVENT_FIRE_BOMBS_4
};

enum JanalaiMisc
{
    NPC_AMANISHI_HATCHER_R      = 23818,
    NPC_AMANISHI_HATCHER_L      = 24504,
    NPC_DRAGONHAWK_EGG          = 23817,
    NPC_FIRE_BOMB               = 23920,
    ACTION_EXPLODE_BOMB         = 0,
    SPAWN_GROUP_EGGS            = 376,
    POINT_UPSTAIRS              = 0,
    POINT_HATCH_EGGS            = 1,
    POINT_BACKUP                = 2,
    DATA_EGGS_TO_HATCH          = 1
};

static constexpr std::array<uint32, 6> SummonFireBombSpells =
{
    SPELL_SUMMON_FIRE_BOMB_05,
    SPELL_SUMMON_FIRE_BOMB_10,
    SPELL_SUMMON_FIRE_BOMB_15,
    SPELL_SUMMON_FIRE_BOMB_20,
    SPELL_SUMMON_FIRE_BOMB_25,
    SPELL_SUMMON_FIRE_BOMB_30
};

static constexpr std::string_view EggsStringIdR = "JanalaiEggsR";
static constexpr std::string_view EggsStringIdL = "JanalaiEggsL";

static Position const UpstairsPointR  = { -55.058910f, 1147.5952f, 18.705223f, 0.0f };
static Position const UpstairsPointL  = { -55.047302f, 1153.5929f, 18.705204f, 0.0f };
static Position const HatchEggsPointR = { -34.438860f, 1104.4828f, 18.711473f, 0.0f };
static Position const HatchEggsPointL = { -34.767784f, 1192.8434f, 18.711363f, 0.0f };

// 23578 - Jan'alai
struct boss_janalai : public BossAI
{
    boss_janalai(Creature* creature) : BossAI(creature, BOSS_JANALAI), _hasTriedToHatchEggs(false), _hasUsedFrenzy(false) { }

    void JustAppeared() override
    {
        me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_EGGS, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_FLAME_BREATH, 5s, 10s);
        events.ScheduleEvent(EVENT_FIRE_BOMBS, 55s);
        events.ScheduleEvent(EVENT_SUMMON_HATCHERS, 10s);
        events.ScheduleEvent(EVENT_FRENZY, 5min);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_hasTriedToHatchEggs && me->HealthBelowPctDamaged(35, damage))
        {
            _hasTriedToHatchEggs = true;

            if (!AllEggsWereHatched())
                events.ScheduleEvent(EVENT_HATCH_ALL_EGGS, 0s);
        }

        if (!_hasUsedFrenzy && me->HealthBelowPctDamaged(20, damage))
        {
            _hasUsedFrenzy = true;
            events.RescheduleEvent(EVENT_FRENZY, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_HATCH_ALL_EGGS:
                Talk(SAY_ALL_EGGS);
                events.CancelEvent(EVENT_SUMMON_HATCHERS);
                break;
            case SPELL_FRENZY:
                Talk(EMOTE_FRENZY);
                _hasUsedFrenzy = true;
                break;
            case SPELL_BERSERK:
                Talk(SAY_BERSERK);
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_FIRE_BOMB)
            DoCast(summon, SPELL_FIRE_BOMB_MISSILE, true);
    }

    bool AllEggsWereHatched()
    {
        return GetClosestCreatureWithOptions(me, 200.0f, { .CreatureId = NPC_DRAGONHAWK_EGG, .IsAlive = true }) == nullptr;
    }

    void DoSummonHatchers()
    {
        // Verified: He summons no hatchers if both are alive, in this case he performs no emote
        // Not verified: What happens if only one hatcher was killed? Currently we spawn no hatchers and perform no emote
        if (AllEggsWereHatched())
            return;

        Creature* hatcherR = me->FindNearestCreature(NPC_AMANISHI_HATCHER_R, 150.0f, true);
        Creature* hatcherL = me->FindNearestCreature(NPC_AMANISHI_HATCHER_L, 150.0f, true);

        if (hatcherR || hatcherL)
            return;

        DoCastSelf(SPELL_SUMMON_HATCHER_1, true);
        DoCastSelf(SPELL_SUMMON_HATCHER_2, true);
        Talk(SAY_SUMMON_HATCHER);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Combat
                case EVENT_FLAME_BREATH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, true))
                        DoCast(target, SPELL_FLAME_BREATH);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_SUMMON_HATCHERS:
                    DoSummonHatchers();
                    events.Repeat(90s);
                    break;
                case EVENT_HATCH_ALL_EGGS:
                    DoCastSelf(SPELL_HATCH_ALL_EGGS, true);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY, true);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    break;

                // Combat - Fire Bomb Sequence
                case EVENT_FIRE_BOMBS:
                    Talk(SAY_FIRE_BOMBS);
                    DoCastSelf(SPELL_TELEPORT_TO_CENTER);
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_FIRE_BOMBS_2, 1200ms);
                    events.Repeat(30s);
                    break;
                case EVENT_FIRE_BOMBS_2:
                    DoCastSelf(SPELL_SUMMON_ALL_PLAYERS);
                    events.ScheduleEvent(EVENT_FIRE_BOMBS_3, 1200ms);
                    break;
                case EVENT_FIRE_BOMBS_3:
                {
                    DoCastSelf(SPELL_FIRE_BOMB_INITIAL);

                    std::vector<Creature*> triggers;
                    GetCreatureListWithOptionsInGrid(triggers, me, 100.0f, { .StringId = "JanalaiFireWallTrigger" });
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_FIRE_WALL);

                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_FIRE_BOMBS_4, 10s);
                    break;
                }
                case EVENT_FIRE_BOMBS_4:
                {
                    std::vector<Creature*> bombs;
                    GetCreatureListWithEntryInGrid(bombs, me, NPC_FIRE_BOMB, 100.0f);
                    for (Creature* bomb : bombs)
                        bomb->AI()->DoAction(ACTION_EXPLODE_BOMB);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _hasTriedToHatchEggs;
    bool _hasUsedFrenzy;
};

// 23920 - Fire Bomb (Zul'Aman)
struct npc_fire_bomb_zulaman : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_EXPLODE_BOMB)
        {
            DoCastSelf(SPELL_FIRE_BOMB_DAMAGE);
            me->RemoveAurasDueToSpell(SPELL_FIRE_BOMB_VISUAL);
            me->DespawnOrUnsummon(3600ms);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FIRE_BOMB_MISSILE)
            DoCastSelf(SPELL_FIRE_BOMB_VISUAL);
    }
};

// 23818 - Amani'shi Hatcher
// 24504 - Amani'shi Hatcher
struct npc_amanishi_hatcher : public ScriptedAI
{
    npc_amanishi_hatcher(Creature* creature) : ScriptedAI(creature), _otherHatcherId(0), _eggsToHatchCount(1) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCorpseDelay(5, true);

        switch (me->GetEntry())
        {
            case NPC_AMANISHI_HATCHER_R:
                _upstairsPoint = UpstairsPointR;
                _hatchEggsPointA = HatchEggsPointR;
                _hatchEggsPointB = HatchEggsPointL;
                _eggsStringIdA = EggsStringIdR;
                _eggsStringIdB = EggsStringIdL;
                _otherHatcherId = NPC_AMANISHI_HATCHER_L;
                break;
            case NPC_AMANISHI_HATCHER_L:
                _upstairsPoint = UpstairsPointL;
                _hatchEggsPointA = HatchEggsPointL;
                _hatchEggsPointB = HatchEggsPointR;
                _eggsStringIdA = EggsStringIdL;
                _eggsStringIdB = EggsStringIdR;
                _otherHatcherId = NPC_AMANISHI_HATCHER_R;
                break;
            default:
                break;
        }
    }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePoint(POINT_UPSTAIRS, _upstairsPoint);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    bool AreEggsHatchedA()
    {
        return GetClosestCreatureWithOptions(me, 200.0f, { .StringId = _eggsStringIdA, .IsAlive = true }) == nullptr;
    }

    bool AreEggsHatchedB()
    {
        return GetClosestCreatureWithOptions(me, 200.0f, { .StringId = _eggsStringIdB, .IsAlive = true }) == nullptr;
    }

    bool IsOtherHatcherAlive()
    {
        return me->FindNearestCreature(_otherHatcherId, 200.0f, true) != nullptr;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case POINT_UPSTAIRS:
                    _scheduler.Schedule(2s, [this](TaskContext /*task*/)
                    {
                        // Verified: If own eggs were hatched, move to the side with unhatched eggs. Yes, both hatchers move to the same side
                        if (!AreEggsHatchedA())
                            me->GetMotionMaster()->MovePoint(POINT_HATCH_EGGS, _hatchEggsPointA);
                        else
                            me->GetMotionMaster()->MovePoint(POINT_HATCH_EGGS, _hatchEggsPointB);
                    });
                    break;
                case POINT_HATCH_EGGS:
                    _scheduler.Schedule(1s, [this](TaskContext task)
                    {
                        // Verified: If eggs from the both sides are hatched, stay and continue to cast Hatch Eggs spell
                        // Verified: If own eggs were hatched, other hatcher's eggs were not hatched and other hatcher is dead, move to hatch his eggs
                        // Not verified: If own eggs were hatched, other hatcher's eggs were not hatched and other hatcher is alive, what should happen?
                        if (AreEggsHatchedA() && !AreEggsHatchedB() && !IsOtherHatcherAlive())
                        {
                            me->GetMotionMaster()->MovePoint(POINT_BACKUP, _hatchEggsPointB);
                            return;
                        }

                        DoCastSelf(SPELL_HATCH_EGGS);
                        task.Repeat(5s);
                    });
                    break;
                case POINT_BACKUP:
                    _scheduler.Schedule(1s, [this](TaskContext task)
                    {
                        DoCastSelf(SPELL_HATCH_EGGS);
                        task.Repeat(5s);
                    });
                    break;
            }
        }
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_EGGS_TO_HATCH)
            _eggsToHatchCount = value;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_EGGS_TO_HATCH)
            return _eggsToHatchCount;

        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    Position _upstairsPoint;
    Position _hatchEggsPointA;
    Position _hatchEggsPointB;
    std::string_view _eggsStringIdA;
    std::string_view _eggsStringIdB;
    uint32 _otherHatcherId;
    uint32 _eggsToHatchCount;
};

// 23817 - Dragonhawk Egg
struct npc_dragonhawk_egg : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetCorpseDelay(3, true);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_HATCH_EGGS || spellInfo->Id == SPELL_HATCH_ALL_EGGS)
            DoCastSelf(SPELL_SUMMON_HATCHLING);
    }
};

// 23598 - Amani Dragonhawk Hatchling
struct npc_amani_dragonhawk_hatchling : public ScriptedAI
{
    npc_amani_dragonhawk_hatchling(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(4, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        if (Creature* janalai = _instance->GetCreature(BOSS_JANALAI))
            janalai->AI()->JustSummoned(me);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_FLAME_BUFFET);
            task.Repeat(5s, 10s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 43096 - Summon All Players
class spell_janalai_summon_all_players : public SpellScript
{
    PrepareSpellScript(spell_janalai_summon_all_players);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ALL_PLAYERS_2 });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        // Guessed value. Patch 2.4.0 (2008-03-25): Will now only teleport players to him if they are too far away.
        if (!GetCaster()->IsWithinDist(GetHitUnit(), 30.0f, false))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ALL_PLAYERS_2, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_janalai_summon_all_players::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 42621 - Fire Bomb
class spell_janalai_fire_bomb : public AuraScript
{
    PrepareAuraScript(spell_janalai_fire_bomb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonFireBombSpells);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        uint8 index = -1;
        uint32 tick = aurEff->GetTickNumber();

        if (tick)
        {
            if (tick < 10)
                index = tick / 5;
            else
                index = tick / 10 + 1;

            if (index < 6)
                GetTarget()->CastSpell(GetTarget(), SummonFireBombSpells[index], true);
            else
                Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_janalai_fire_bomb::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 42471 - Hatch Eggs
class spell_janalai_hatch_eggs : public SpellScript
{
    PrepareSpellScript(spell_janalai_hatch_eggs);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (Creature* caster = GetCaster()->ToCreature())
        {
            targets.remove_if([caster](WorldObject const* target)
            {
                return !caster->IsWithinDist(target, 50.0f);
            });

            Trinity::Containers::RandomResize(targets, caster->GetAI()->GetData(DATA_EGGS_TO_HATCH));
        }
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitUnit()->ToCreature())
            if (target->AI()->GetData(DATA_EGGS_TO_HATCH) < 5)
                target->AI()->SetData(DATA_EGGS_TO_HATCH, target->AI()->GetData(DATA_EGGS_TO_HATCH) + 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_janalai_hatch_eggs::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_janalai_hatch_eggs::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_janalai()
{
    RegisterZulAmanCreatureAI(boss_janalai);
    RegisterZulAmanCreatureAI(npc_fire_bomb_zulaman);
    RegisterZulAmanCreatureAI(npc_amanishi_hatcher);
    RegisterZulAmanCreatureAI(npc_dragonhawk_egg);
    RegisterZulAmanCreatureAI(npc_amani_dragonhawk_hatchling);
    RegisterSpellScript(spell_janalai_summon_all_players);
    RegisterSpellScript(spell_janalai_fire_bomb);
    RegisterSpellScript(spell_janalai_hatch_eggs);
}
