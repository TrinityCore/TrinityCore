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
 * Singularity may be much trickier:
    1. Check if singularity should change targets
    2. Check if despawn timer depends on how much targets singularity hits by passive spells
 * Check if Dark Fiend should change target
 * Berserk for Entropius should be triggered from Entropius' AI since M'uru originally despawns after summoning Entropius,
    NYI, currently triggered from M'uru's AI
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"

enum MuruSpells
{
    // M'uru - Initial
    SPELL_OPEN_PORTAL_PERIODIC                  = 45994,
    SPELL_DARKNESS_PERIODIC                     = 45998,
    SPELL_NEGATIVE_ENERGY_PERIODIC              = 46009,
    SPELL_SUMMON_BLOOD_ELVES_PERIODIC           = 46041,

    // M'uru - Combat
    SPELL_BERSERK                               = 26662,

    // M'uru - Transition
    SPELL_OPEN_ALL_PORTALS                      = 46177,
    SPELL_SUMMON_ENTROPIUS                      = 46217,

    // Entropius - Initial
    SPELL_ENTROPIUS_COSMETIC_SPAWN              = 46223,
    SPELL_NEGATIVE_ENERGY_PERIODIC_E            = 46284,

    // Entropius - Combat
    SPELL_DARKNESS                              = 46269,
    SPELL_BLACK_HOLE                            = 46282,

    // M'uru Portal Target
    SPELL_OPEN_PORTAL                           = 45976,
    SPELL_OPEN_PORTAL_VISUAL                    = 45977,
    SPELL_SUMMON_VOID_SENTINEL_SUMMONER         = 45978,
    SPELL_SUMMON_VOID_SENTINEL_SUMMONER_VISUAL  = 45989,
    SPELL_TRANSFORM_VISUAL_MISSILE              = 46205,

    // Void Sentinel Summoner
    SPELL_SUMMON_VOID_SENTINEL                  = 45988,

    // Void Sentinel
    SPELL_SHADOW_PULSE_PERIODIC                 = 46086,
    SPELL_VOID_BLAST                            = 46161,
    SPELL_SUMMON_VOID_SPAWN                     = 46071,

    // Void Spawn
    SPELL_SHADOW_BOLT_VOLLEY                    = 46082,

    // Dark Fiend
    SPELL_DARK_FIEND_MAGIC                      = 45934,
    SPELL_DARK_FIEND_VISUAL                     = 45936,
    SPELL_DARK_FIEND_TRAP                       = 45943,
    SPELL_DARK_FIEND_DAMAGE                     = 45944,

    // Darkness
    SPELL_VOID_ZONE_PRE_EFFECT_VISUAL           = 46265,
    SPELL_VOID_ZONE_PERIODIC                    = 46262,
    SPELL_SUMMON_DARK_FIEND                     = 46263,

    // Singularity
    SPELL_BLACK_HOLE_SUMMON_VISUAL              = 46242,
    SPELL_BLACK_HOLE_SUMMON_VISUAL_2            = 46247,
    SPELL_BLACK_HOLE_PASSIVE                    = 46228,
    SPELL_BLACK_HOLE_VISUAL_2                   = 46235,

    // Shadowsword Berserker
    SPELL_DUAL_WIELD_PASSIVE                    = 42459,
    SPELL_FLURRY                                = 46160,

    // Shadowsword Fury Mage
    SPELL_FEL_FIREBALL                          = 46101,
    SPELL_SPELL_FURY                            = 46102,

    // Scripts
    SPELL_SUMMON_BLOOD_ELVES_SCRIPT             = 46050,

    SPELL_SUMMON_BERSERKER_1                    = 46037,
    SPELL_SUMMON_BERSERKER_2                    = 46040,
    SPELL_SUMMON_FURY_MAGE_1                    = 46038,
    SPELL_SUMMON_FURY_MAGE_2                    = 46039,

    SPELL_SUMMON_DARK_FIEND_1                   = 46000,
    SPELL_SUMMON_DARK_FIEND_2                   = 46001,
    SPELL_SUMMON_DARK_FIEND_3                   = 46002,
    SPELL_SUMMON_DARK_FIEND_4                   = 46003,
    SPELL_SUMMON_DARK_FIEND_5                   = 46004,
    SPELL_SUMMON_DARK_FIEND_6                   = 46005,
    SPELL_SUMMON_DARK_FIEND_7                   = 46006,
    SPELL_SUMMON_DARK_FIEND_8                   = 46007,

    SPELL_TRANSFORM_VISUAL_MISSILE_1            = 46178,
    SPELL_TRANSFORM_VISUAL_MISSILE_2            = 46208,

    SPELL_NEGATIVE_ENERGY_DAMAGE                = 46285
};

enum MuruEvents
{
    // M'uru
    EVENT_SUMMON_BLOOD_ELVES                    = 1,
    EVENT_SUMMON_ENTROPIUS,
    EVENT_SET_INVISIBLE,
    EVENT_BERSERK,

    // Entropius
    EVENT_SPAWN_1,
    EVENT_SPAWN_2,
    EVENT_DARKNESS,
    EVENT_BLACK_HOLE
};

enum MuruMisc
{
    ACTION_BERSERK                              = 0,
    ACTION_DISPELLED_MAGIC                      = 1,
    ACTION_CANCEL_SUMMON                        = 2,
    MAX_VOID_SPAWNS                             = 6,
    NPC_WORLD_TRIGGER_MOVE_TO                   = 22515,
    POINT_ROOM                                  = 0
};

static constexpr std::array<uint32, 8> SummonDarkFiendSpells =
{
    SPELL_SUMMON_DARK_FIEND_1,
    SPELL_SUMMON_DARK_FIEND_2,
    SPELL_SUMMON_DARK_FIEND_3,
    SPELL_SUMMON_DARK_FIEND_4,
    SPELL_SUMMON_DARK_FIEND_5,
    SPELL_SUMMON_DARK_FIEND_6,
    SPELL_SUMMON_DARK_FIEND_7,
    SPELL_SUMMON_DARK_FIEND_8
};

void DoResetPortals(Creature* creature)
{
    std::vector<Creature*> portals;
    GetCreatureListWithEntryInGrid(portals, creature, NPC_MURU_PORTAL_TARGET, 100.0f);
    for (Creature* portal : portals)
        portal->RemoveAllAuras();
}

void DoDespawnSummons(Creature* creature)
{
    std::vector<Creature*> spawns;
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_ENTROPIUS, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_VOID_SENTINEL_SUMMONER, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_VOID_SENTINEL, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_VOID_SPAWN, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_DARK_FIEND, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_DARKNESS, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_SINGULARITY, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_BERSERKER, 250.0f);
    GetCreatureListWithEntryInGrid(spawns, creature, NPC_FURY_MAGE, 250.0f);
    for (Creature* spawn : spawns)
        spawn->DespawnOrUnsummon();

    std::vector<Creature*> portals;
    GetCreatureListWithEntryInGrid(portals, creature, NPC_MURU_PORTAL_TARGET, 100.0f);
    for (Creature* portal : portals)
        portal->AI()->DoAction(ACTION_CANCEL_SUMMON);
}

// 25741 - M'uru
struct boss_muru : public BossAI
{
    boss_muru(Creature* creature) : BossAI(creature, DATA_MURU), _isBerserkTriggered(false), _isInTransition(false) { }

    void Reset() override
    {
        _Reset();

        _isBerserkTriggered = false;
        _isInTransition = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_OPEN_PORTAL_PERIODIC);
        DoCastSelf(SPELL_DARKNESS_PERIODIC);
        DoCastSelf(SPELL_NEGATIVE_ENERGY_PERIODIC);

        me->SetReactState(REACT_PASSIVE);

        events.ScheduleEvent(EVENT_SUMMON_BLOOD_ELVES, 5s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (_isInTransition)
                return;

            _isInTransition = true;
            me->RemoveAurasDueToSpell(SPELL_SUMMON_BLOOD_ELVES_PERIODIC);
            me->RemoveAurasDueToSpell(SPELL_NEGATIVE_ENERGY_PERIODIC);
            me->RemoveAurasDueToSpell(SPELL_DARKNESS_PERIODIC);
            me->RemoveAurasDueToSpell(SPELL_OPEN_PORTAL_PERIODIC);
            DoCastSelf(SPELL_OPEN_ALL_PORTALS);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            events.CancelEvent(EVENT_SUMMON_BLOOD_ELVES);
            events.ScheduleEvent(EVENT_SUMMON_ENTROPIUS, 6s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SUMMON_ENTROPIUS)
            /// @todo: Temporarily replaced with SetVisible. Otherwise we will be not able to respawn M'uru in case of wipe
            /// me->DespawnOrUnsummon(1500ms);
            events.ScheduleEvent(EVENT_SET_INVISIBLE, 1500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoResetPortals(me);
        DoDespawnSummons(me);
        _DespawnAtEvade();
    }

    // Do not store anything, despawn is handled in DoDespawnSummons
    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_ENTROPIUS)
            if (_isBerserkTriggered)
                summon->AI()->DoAction(ACTION_BERSERK);
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
                case EVENT_SUMMON_BLOOD_ELVES:
                    DoCastSelf(SPELL_SUMMON_BLOOD_ELVES_PERIODIC);
                    break;
                case EVENT_SUMMON_ENTROPIUS:
                    DoCastSelf(SPELL_SUMMON_ENTROPIUS);
                    break;
                case EVENT_SET_INVISIBLE:
                    me->SetVisible(false);
                    break;
                case EVENT_BERSERK:
                {
                    _isBerserkTriggered = true;
                    DoCastSelf(SPELL_BERSERK);

                    if (Creature* entropius = instance->GetCreature(DATA_ENTROPIUS))
                        entropius->AI()->DoAction(ACTION_BERSERK);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    bool _isBerserkTriggered;
    bool _isInTransition;
};

// 25840 - Entropius
struct boss_entropius : public BossAI
{
    boss_entropius(Creature* creature) : BossAI(creature, DATA_MURU) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ENTROPIUS_COSMETIC_SPAWN);

        events.ScheduleEvent(EVENT_SPAWN_1, 1500ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_DARKNESS, 10s, 15s);
        events.ScheduleEvent(EVENT_BLACK_HOLE, 10s, 15s);
    }

    // Do not store anything, despawn is handled in DoDespawnSummons
    void JustSummoned(Creature* /*summon*/) override { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_BERSERK)
            DoCastSelf(SPELL_BERSERK);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (Creature* muru = instance->GetCreature(DATA_MURU))
            muru->AI()->EnterEvadeMode();

        DoResetPortals(me);
        DoDespawnSummons(me);
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        DoDespawnSummons(me);

        if (Creature* muru = instance->GetCreature(DATA_MURU))
            muru->DisappearAndDie();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SPAWN_1:
                    DoResetPortals(me);
                    events.ScheduleEvent(EVENT_SPAWN_2, 1500ms);
                    break;
                case EVENT_SPAWN_2:
                    DoCastSelf(SPELL_NEGATIVE_ENERGY_PERIODIC_E);
                    DoZoneInCombat();
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_DARKNESS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_DARKNESS);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_BLACK_HOLE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_BLACK_HOLE);
                    events.Repeat(20s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }
};

// 25770 - M'uru Portal Target
struct npc_muru_portal : public ScriptedAI
{
    npc_muru_portal(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_OPEN_PORTAL:
                DoCastSelf(SPELL_OPEN_PORTAL_VISUAL);
                _scheduler.Schedule(5s, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_SUMMON_VOID_SENTINEL_SUMMONER);
                });
                break;
            case SPELL_OPEN_ALL_PORTALS:
                DoCastSelf(SPELL_OPEN_PORTAL_VISUAL);
                _scheduler.Schedule(2s, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_TRANSFORM_VISUAL_MISSILE);
                });
                break;
            default:
                break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        DoCast(summon, SPELL_SUMMON_VOID_SENTINEL_SUMMONER_VISUAL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_CANCEL_SUMMON)
            _scheduler.CancelAll();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 25782 - Void Sentinel Summoner
struct npc_void_sentinel_summoner : public ScriptedAI
{
    npc_void_sentinel_summoner(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_SUMMON_VOID_SENTINEL);
            me->DespawnOrUnsummon(3500ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 25772 - Void Sentinel
struct npc_void_sentinel : public ScriptedAI
{
    npc_void_sentinel(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SHADOW_PULSE_PERIODIC);

        _scheduler.Schedule(2500ms, [this](TaskContext /*task*/)
        {
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, 15s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_VOID_BLAST);
            task.Repeat(20s, 30s);
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        for (uint8 i = 0; i < MAX_VOID_SPAWNS; ++i)
            DoCastSelf(SPELL_SUMMON_VOID_SPAWN);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 25824 - Void Spawn
struct npc_void_spawn : public ScriptedAI
{
    npc_void_spawn(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, 20s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_SHADOW_BOLT_VOLLEY);
            task.Repeat(20s, 30s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 25744 - Dark Fiend
struct npc_dark_fiend : public ScriptedAI
{
    npc_dark_fiend(Creature* creature) : ScriptedAI(creature), _isKilled(false) { }

    void InitializeAI() override
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DARK_FIEND_MAGIC);

        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            DoZoneInCombat();
            me->SetReactState(REACT_AGGRESSIVE);
        });

        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            if (me->IsWithinDist(me->GetVictim(), 2.0f))
                DoCastVictim(SPELL_DARK_FIEND_TRAP);
            else
                task.Repeat(100ms);
        });
    }

    void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DARK_FIEND_TRAP)
        {
            _scheduler.Schedule(0s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        me->RemoveAurasDueToSpell(SPELL_DARK_FIEND_MAGIC);
                        DoCastSelf(SPELL_DARK_FIEND_DAMAGE);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        task.Repeat(2500ms);
                        break;
                    case 1:
                        DoCastSelf(SPELL_DARK_FIEND_VISUAL);
                        me->DespawnOrUnsummon(3500ms);
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void DoAction(int32 action) override
    {
        /// @todo: This part requires sniff verification
        if (action == ACTION_DISPELLED_MAGIC)
        {
            me->SetReactState(REACT_PASSIVE);
            DoCastSelf(SPELL_DARK_FIEND_VISUAL);
            me->DespawnOrUnsummon(3s);
        }
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() -1;

            if (!_isKilled)
            {
                _isKilled = true;
                me->RemoveAurasDueToSpell(SPELL_DARK_FIEND_MAGIC);
                DoCastSelf(SPELL_DARK_FIEND_VISUAL);
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->DespawnOrUnsummon(4500ms);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    bool _isKilled;
    TaskScheduler _scheduler;
};

// 25879 - Darkness
struct npc_darkness : public ScriptedAI
{
    npc_darkness(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    DoCastSelf(SPELL_VOID_ZONE_PRE_EFFECT_VISUAL);
                    task.Repeat(3s);
                    break;
                case 1:
                    me->RemoveAurasDueToSpell(SPELL_VOID_ZONE_PRE_EFFECT_VISUAL);
                    DoCastSelf(SPELL_VOID_ZONE_PERIODIC);
                    task.Repeat(2500ms);
                    break;
                case 2:
                    DoCastSelf(SPELL_SUMMON_DARK_FIEND);
                    break;
                default:
                    break;
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 25855 - Singularity
struct npc_singularity : public ScriptedAI
{
    npc_singularity(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    DoCastSelf(SPELL_BLACK_HOLE_SUMMON_VISUAL);
                    task.Repeat(1s);
                    break;
                case 1:
                    DoCastSelf(SPELL_BLACK_HOLE_SUMMON_VISUAL_2);
                    task.Repeat(1s);
                    break;
                case 2:
                    DoCastSelf(SPELL_BLACK_HOLE_SUMMON_VISUAL);
                    task.Repeat(2s);
                    break;
                case 3:
                    me->RemoveAurasDueToSpell(SPELL_BLACK_HOLE_SUMMON_VISUAL_2);
                    DoCastSelf(SPELL_BLACK_HOLE_PASSIVE);
                    DoCastSelf(SPELL_BLACK_HOLE_VISUAL_2);
                    task.Repeat(1s);
                    break;
                case 4:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    me->DespawnOrUnsummon(15s);
                    break;
                default:
                    break;
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct ShadowswordBaseAI : public ScriptedAI
{
    ShadowswordBaseAI(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCorpseDelay(3, true);
    }

    void JustAppeared() override
    {
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });

        if (Creature* trigger = me->FindNearestCreature(NPC_WORLD_TRIGGER_MOVE_TO, 120.0f))
        {
            float x, y, z;
            trigger->GetClosePoint(x, y, z, 0.0f, 3.0f, float(M_PI));
            me->GetMotionMaster()->MovePoint(POINT_ROOM, x, y, z);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_ROOM)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

protected:
    TaskScheduler scheduler;
};

// 25798 - Shadowsword Berserker
struct npc_shadowsword_berserker : public ShadowswordBaseAI
{
    npc_shadowsword_berserker(Creature* creature) : ShadowswordBaseAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DUAL_WIELD_PASSIVE);
        ShadowswordBaseAI::JustAppeared();
    }

    void ScheduleEvents() override
    {
        scheduler.Schedule(10s, 20s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_FLURRY);
            task.Repeat(15s, 25s);
        });
    }
};

// 25799 - Shadowsword Fury Mage
struct npc_shadowsword_fury_mage : public ShadowswordBaseAI
{
    npc_shadowsword_fury_mage(Creature* creature) : ShadowswordBaseAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_FEL_FIREBALL);
            task.Repeat(5s, 10s);
        });

        scheduler.Schedule(20s, 40s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_SPELL_FURY);
            task.Repeat(40s, 60s);
        });
    }
};

// 46041 - Summon Blood Elves Periodic
class spell_muru_summon_blood_elves_periodic : public AuraScript
{
    PrepareAuraScript(spell_muru_summon_blood_elves_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_BLOOD_ELVES_SCRIPT });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_BLOOD_ELVES_SCRIPT);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_BLOOD_ELVES_SCRIPT);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_muru_summon_blood_elves_periodic::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_muru_summon_blood_elves_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46050 - Summon Blood Elves Script
class spell_muru_summon_blood_elves_script : public SpellScript
{
    PrepareSpellScript(spell_muru_summon_blood_elves_script);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_BERSERKER_1,
            SPELL_SUMMON_BERSERKER_2,
            SPELL_SUMMON_FURY_MAGE_1,
            SPELL_SUMMON_FURY_MAGE_2
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_BERSERKER_1);
        caster->CastSpell(caster, SPELL_SUMMON_BERSERKER_1);
        caster->CastSpell(caster, SPELL_SUMMON_FURY_MAGE_1);
        caster->CastSpell(caster, SPELL_SUMMON_FURY_MAGE_2);
        caster->CastSpell(caster, SPELL_SUMMON_BERSERKER_2);
        caster->CastSpell(caster, SPELL_SUMMON_BERSERKER_2);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_muru_summon_blood_elves_script::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45996 - Darkness
class spell_muru_darkness : public AuraScript
{
    PrepareAuraScript(spell_muru_darkness);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonDarkFiendSpells);
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 2)
        {
            Unit* target = GetTarget();
            for (uint32 SummonSpell : SummonDarkFiendSpells)
                target->CastSpell(target, SummonSpell);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_muru_darkness::HandleEffectPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 45934 - Dark Fiend
class spell_muru_dark_fiend_magic : public AuraScript
{
    PrepareAuraScript(spell_muru_dark_fiend_magic);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (Creature* target = GetTarget()->ToCreature())
            target->AI()->DoAction(ACTION_DISPELLED_MAGIC);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_muru_dark_fiend_magic::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46205 - Transform Visual Missile Periodic
class spell_muru_transform_visual_missile_periodic : public AuraScript
{
    PrepareAuraScript(spell_muru_transform_visual_missile_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRANSFORM_VISUAL_MISSILE_1, SPELL_TRANSFORM_VISUAL_MISSILE_2 });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, RAND(SPELL_TRANSFORM_VISUAL_MISSILE_1, SPELL_TRANSFORM_VISUAL_MISSILE_2));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_muru_transform_visual_missile_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 45978 - Summon Void Sentinel Summoner
class spell_muru_summon_void_sentinel_summoner : public SpellScript
{
    PrepareSpellScript(spell_muru_summon_void_sentinel_summoner);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        dest._position.m_positionZ = caster->GetMapHeight(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_muru_summon_void_sentinel_summoner::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT);
    }
};

// 46284 - Negative Energy Periodic
class spell_muru_negative_energy_periodic : public AuraScript
{
    PrepareAuraScript(spell_muru_negative_energy_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, aurEff->GetTickNumber() / 10 + 1);
        GetTarget()->CastSpell(nullptr, aurEff->GetSpellEffectInfo().TriggerSpell, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_muru_negative_energy_periodic::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 46289 - Negative Energy
class spell_muru_negative_energy : public SpellScript
{
    PrepareSpellScript(spell_muru_negative_energy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_NEGATIVE_ENERGY_DAMAGE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_NEGATIVE_ENERGY_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_muru_negative_energy::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_muru()
{
    RegisterSunwellPlateauCreatureAI(boss_muru);
    RegisterSunwellPlateauCreatureAI(boss_entropius);
    RegisterSunwellPlateauCreatureAI(npc_muru_portal);
    RegisterSunwellPlateauCreatureAI(npc_void_sentinel_summoner);
    RegisterSunwellPlateauCreatureAI(npc_void_sentinel);
    RegisterSunwellPlateauCreatureAI(npc_void_spawn);
    RegisterSunwellPlateauCreatureAI(npc_dark_fiend);
    RegisterSunwellPlateauCreatureAI(npc_darkness);
    RegisterSunwellPlateauCreatureAI(npc_singularity);
    RegisterSunwellPlateauCreatureAI(npc_shadowsword_berserker);
    RegisterSunwellPlateauCreatureAI(npc_shadowsword_fury_mage);
    RegisterSpellScript(spell_muru_summon_blood_elves_periodic);
    RegisterSpellScript(spell_muru_summon_blood_elves_script);
    RegisterSpellScript(spell_muru_darkness);
    RegisterSpellScript(spell_muru_dark_fiend_magic);
    RegisterSpellScript(spell_muru_transform_visual_missile_periodic);
    RegisterSpellScript(spell_muru_summon_void_sentinel_summoner);
    RegisterSpellScript(spell_muru_negative_energy_periodic);
    RegisterSpellScript(spell_muru_negative_energy);
}
