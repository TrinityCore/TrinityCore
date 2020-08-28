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

#include "ScriptMgr.h"
#include "Player.h"
#include "CreatureGroups.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "MotionMaster.h"
#include "SpellScript.h"
#include "Map.h"
#include "stonecore.h"

enum Spells
{
    // Corborus Intro
    SPELL_TWILIGHT_DOCUMENTS            = 93167,
    SPELL_RING_WYRM_CHARGE              = 81237,
    SPELL_DOOR_BREAK                    = 81232,

    // Corborus
    SPELL_DAMPENING_WAVE                = 82415,
    SPELL_CRYSTAL_BARRAGE_TARGETING     = 81634,
    SPELL_CRYSTAL_BARRAGE               = 86881,
    SPELL_CRYSTAL_BARRAGE_SHARD         = 92012,
    SPELL_CLEAR_ALL_DEBUFFS             = 34098,
    SPELL_SUBMERGE                      = 81629,
    SPELL_TRASHING_CHARGE_TELEPORT      = 81839,
    SPELL_TRASHING_CHARGE_TELEPORT_2    = 81838,
    SPELL_SUMMON_TRASHING_CHARGE        = 81816,
    SPELL_TRASHING_CHARGE_VISUAL        = 81801,
    SPELL_TRASHING_CHARGE_EFFECT        = 81828,
    SPELL_EMERGE                        = 81948,

    // Rock Borer
    SPELL_ROCK_BORER_EMERGE             = 82185,
    SPELL_ROCK_BORE                     = 80028,

    // Crystal Shard
    SPELL_RANDOM_AGGRO                  = 92112,
    SPELL_CRYSTAL_SHARDS                = 92117,
    SPELL_CRYSTAL_SHARDS_TARGET         = 92116,
    SPELL_CRYSTAL_SHARDS_DAMAGE         = 92122,
    SPELL_SHRINK                        = 92079,
    SPELL_PERMANENT_FEIGN_DEATH         = 70628
};

enum Events
{
    // Corborus Intro
    EVENT_CORBORUS_CHARGE = 1,
    EVENT_CORBORUS_KNOCKBACK,
    EVENT_CORBORUS_FACE_PLAYERS,

    // Corborus boss
    EVENT_DAMPENING_WAVE,
    EVENT_CRYSTAL_BARRAGE,
    EVENT_SUBMERGE,
    EVENT_TELEPORT,
    EVENT_TRASHING_CHARGE,
    EVENT_SUMMON_BEETLE,
    EVENT_EMERGE,
    EVENT_ATTACK,

    // Rock Borer
    EVENT_EMERGED,
    EVENT_ROCK_BORE,

    // Crystal Shard
    EVENT_REMOVE_SHRINK_AURA
};

enum Phases
{
    // Corborus
    PHASE_INTRO     = 0,
    PHASE_COMBAT    = 1,

    // Crystal Shards
    PHASE_ACTIVE    = 1
};

Position const CorborusHomePos = { 1154.55f, 878.843f, 284.963f, 3.176499f };

class boss_corborus : public CreatureScript
{
    public:
        boss_corborus() : CreatureScript("boss_corborus") { }

        struct boss_corborusAI : public BossAI
        {
            boss_corborusAI(Creature* creature) : BossAI(creature, DATA_CORBORUS)
            {
                Initialize();
            }

            void Initialize()
            {
                _countTrashingCharge = 0;
            }

            void Reset() override
            {
                _Reset();
                _countTrashingCharge = 0;
                events.SetPhase(PHASE_INTRO);

                if (instance->GetData(DATA_EVENT_PROGRESS) < EVENT_INDEX_CORBORUS_INTRO)
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_DAMPENING_WAVE, Seconds(10));
                events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, Seconds(15));
                events.ScheduleEvent(EVENT_SUBMERGE, Seconds(36));
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_CORBORUS, FAIL);
                me->DespawnOrUnsummon();
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CORBORUS_INTRO: // Executes Corborus intro event
                    {
                        if (Creature* Millhouse = instance->GetCreature(DATA_MILLHOUSE_MANASTORM))
                        {
                            Millhouse->InterruptNonMeleeSpells(true);
                            Millhouse->RemoveAllAuras();
                            Millhouse->HandleEmoteCommand(EMOTE_ONESHOT_KNOCKDOWN);
                        }

                        events.ScheduleEvent(EVENT_CORBORUS_CHARGE, Seconds(1));
                        break;
                    }
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_TRASHING_CHARGE)
                    summon->CastSpell(summon, SPELL_TRASHING_CHARGE_EFFECT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CORBORUS_CHARGE:
                            // Face Millhouse and other mobs
                            instance->SetData(DATA_MILLHOUSE_EVENT_FACE, 0);

                            // Open rock gate and cast visual from nearby worldtrigger
                            instance->SetData(DATA_HANDLE_CORBORUS_ROCKDOOR, 0);
                            if (Creature* worldtrigger = me->FindNearestCreature(NPC_WORLDTRIGGER, 60.0f))
                                worldtrigger->CastSpell(worldtrigger, SPELL_DOOR_BREAK, true);

                            // Make Corborus charge
                            DoCast(me, SPELL_RING_WYRM_CHARGE, true);

                            events.ScheduleEvent(EVENT_CORBORUS_KNOCKBACK, Seconds(1));
                            break;
                        case EVENT_CORBORUS_KNOCKBACK:
                            // Spawn Twilight Documents (quest gameobject)
                            if (Creature* Millhouse = instance->GetCreature(DATA_MILLHOUSE_MANASTORM))
                                Millhouse->CastSpell(Millhouse, SPELL_TWILIGHT_DOCUMENTS, true);

                            // Knockback Millhouse and other mobs
                            instance->SetData(DATA_MILLHOUSE_EVENT_KNOCKBACK, 0);
                            events.ScheduleEvent(EVENT_CORBORUS_FACE_PLAYERS, Seconds(2));
                            break;
                        case EVENT_CORBORUS_FACE_PLAYERS:
                            me->SetFacingTo(3.176499f);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);

                            // Despawn Millhouse and all trash
                            instance->SetData(DATA_MILLHOUSE_EVENT_DESPAWN, 0);
                            break;
                        case EVENT_DAMPENING_WAVE:
                            DoCastAOE(SPELL_DAMPENING_WAVE);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_CRYSTAL_BARRAGE:
                            DoCastAOE(SPELL_CRYSTAL_BARRAGE_TARGETING, true);
                            events.Repeat(Seconds(10));
                            break;
                        case EVENT_SUBMERGE:
                            events.RescheduleEvent(EVENT_DAMPENING_WAVE, Seconds(35));
                            events.RescheduleEvent(EVENT_CRYSTAL_BARRAGE, Seconds(30));
                            events.Repeat(Minutes(1) + Seconds(40));

                            me->SetReactState(REACT_PASSIVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                            me->AttackStop();

                            DoCast(me, SPELL_SUBMERGE);

                            _countTrashingCharge = 0;
                            events.ScheduleEvent(EVENT_TELEPORT, Milliseconds(500));
                            break;
                        case EVENT_TELEPORT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_TRASHING_CHARGE_TELEPORT);
                            _countTrashingCharge++;

                            if (_countTrashingCharge <= 4)
                                events.ScheduleEvent(EVENT_TRASHING_CHARGE, Seconds(1));
                            else
                                events.ScheduleEvent(EVENT_EMERGE, Seconds(2) + Milliseconds(500));
                            break;
                        case EVENT_TRASHING_CHARGE:
                            DoCast(me, SPELL_SUMMON_TRASHING_CHARGE);
                            DoCast(me, SPELL_TRASHING_CHARGE_VISUAL);
                            events.ScheduleEvent(EVENT_TELEPORT, Seconds(5));
                            break;
                        case EVENT_EMERGE:
                            me->RemoveAllAuras();
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_EMERGE);
                            events.ScheduleEvent(EVENT_ATTACK, Seconds(2) + Milliseconds(500));
                            break;
                        case EVENT_ATTACK:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _countTrashingCharge;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<boss_corborusAI>(creature);
        }
};

class npc_rock_borer : public CreatureScript
{
    public:
        npc_rock_borer() : CreatureScript("npc_rock_borer") { }

        struct npc_rock_borerAI : public ScriptedAI
        {
            npc_rock_borerAI(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
            {
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (Creature* corborus = _instance->GetCreature(DATA_CORBORUS))
                    corborus->AI()->JustSummoned(me);

                _events.ScheduleEvent(EVENT_EMERGED, 1s + 200ms);
                _events.ScheduleEvent(EVENT_ROCK_BORE, 17s);
                DoZoneInCombat();
                DoCast(me, SPELL_ROCK_BORER_EMERGE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && me->GetReactState() != REACT_PASSIVE)
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EMERGED:
                            me->RemoveAurasDueToSpell(SPELL_ROCK_BORER_EMERGE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_ROCK_BORE:
                            DoCastVictim(SPELL_ROCK_BORE);
                            _events.Repeat(17s); // Need sniffs for this timer
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<npc_rock_borerAI>(creature);
        }
};

class npc_crystal_shard : public CreatureScript
{
    public:
        npc_crystal_shard() : CreatureScript("npc_crystal_shard") { }

        struct npc_crystal_shardAI : public ScriptedAI
        {
            npc_crystal_shardAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (Unit* target = me->SelectNearestPlayer(80.0f))
                    target->CastSpell(me, SPELL_RANDOM_AGGRO, true);

                DoCastSelf(SPELL_CRYSTAL_SHARDS, true);
                _events.ScheduleEvent(EVENT_REMOVE_SHRINK_AURA, Seconds(1) + Milliseconds(200));
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_CRYSTAL_SHARDS_TARGET)
                {
                    DoCastAOE(SPELL_CRYSTAL_SHARDS_DAMAGE, true);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH, true);
                    me->DespawnOrUnsummon(Seconds(3) + Milliseconds(500));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                UpdateVictim();

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_REMOVE_SHRINK_AURA:
                            me->RemoveAurasDueToSpell(SPELL_SHRINK);
                            _events.ScheduleEvent(EVENT_ATTACK, Seconds(2));
                            break;
                        case EVENT_ATTACK:
                            _events.SetPhase(PHASE_ACTIVE);
                            SetCombatMovement(true);
                            if (Unit* victim = me->GetVictim())
                                me->GetMotionMaster()->MoveChase(victim);
                            break;
                        default:
                            break;
                    }
                }

                if (_events.IsInPhase(PHASE_ACTIVE))
                    DoSpellAttackIfReady(SPELL_CRYSTAL_SHARDS_TARGET);
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<npc_crystal_shardAI>(creature);
        }
};

class spell_corborus_crystal_barrage_targeting : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTAL_BARRAGE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->StopMoving();
            caster->CastSpell(GetHitUnit(), SPELL_CRYSTAL_BARRAGE);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_corborus_crystal_barrage_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_corborus_crystal_barrage_targeting::HandleEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_corborus_crystal_barrage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTAL_BARRAGE_SHARD });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->GetMap()->IsHeroic())
                for (uint8 i = 0; i < 9; i++)
                    caster->CastSpell(caster, SPELL_CRYSTAL_BARRAGE_SHARD, true);
    }

    void Register() override
    {
        OnEffectRemove.Register(&spell_corborus_crystal_barrage::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_corborus()
{
    new boss_corborus();
    new npc_rock_borer();
    new npc_crystal_shard();
    RegisterSpellScript(spell_corborus_crystal_barrage_targeting);
    RegisterSpellScript(spell_corborus_crystal_barrage);
}
