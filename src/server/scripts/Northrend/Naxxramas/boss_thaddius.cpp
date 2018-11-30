/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Phases
{
    PHASE_NOT_ENGAGED       = 1,
    PHASE_PETS,
    PHASE_TRANSITION,
    PHASE_THADDIUS
};

enum AIActions
{
    ACTION_BEGIN_RESET_ENCOUNTER =  0, // sent from thaddius to pets to trigger despawn and encounter reset
    ACTION_FEUGEN_DIED, // sent from respective pet to thaddius to indicate death
    ACTION_STALAGG_DIED, // ^
    ACTION_FEUGEN_RESET, // pet to thaddius
    ACTION_STALAGG_RESET, // ^
    ACTION_FEUGEN_AGGRO, // pet to thaddius on combat start
    ACTION_STALAGG_AGGRO, // ^
    ACTION_FEUGEN_REVIVING_FX, // thaddius to pet when pet reports its death
    ACTION_STALAGG_REVIVING_FX, // ^
    ACTION_FEUGEN_REVIVED, // thaddius to pet when pet should revive
    ACTION_STALAGG_REVIVED, // ^
    ACTION_TRANSITION, // thaddius to pets when transition starts (coil overload anim)
    ACTION_TRANSITION_2, // thaddius to pets to make the coils shock him
    ACTION_TRANSITION_3, // thaddius to pets to disable coil GO after spawn

    ACTION_POLARITY_CROSSED // triggers achievement failure, sent from spellscript
};

enum Events
{
    EVENT_SHIFT = 1,                // polarity shift
    EVENT_SHIFT_TALK,               // polarity shift yell (hack? couldn't find any event for cast finish)
    EVENT_CHAIN,                    // chain lightning
    EVENT_BERSERK,                  // enrage timer
    EVENT_REVIVE_FEUGEN,            // timer until feugen is revived (if stalagg still lives)
    EVENT_REVIVE_STALAGG,           // timer until stalagg is revived (if feugen still lives)
    EVENT_TRANSITION_1,             // timer until overload emote
    EVENT_TRANSITION_2,             // timer until thaddius gets zapped by the coils
    EVENT_TRANSITION_3,             // timer until thaddius engages
    EVENT_ENABLE_BALL_LIGHTNING     // grace period after thaddius aggro after which he starts being a baller (e.g. tossing ball lightning at out of range targets)
};

enum Misc
{
    MAX_POLARITY_10M        =  5,
    MAX_POLARITY_25M        = 13,

    DATA_POLARITY_CROSSED   =  1,
};

// Feugen & Stalagg
enum PetYells
{
    SAY_STALAGG_AGGRO       = 0,
    SAY_STALAGG_SLAY        = 1,
    SAY_STALAGG_DEATH       = 2,

    SAY_FEUGEN_AGGRO        = 0,
    SAY_FEUGEN_SLAY         = 1,
    SAY_FEUGEN_DEATH        = 2,

    EMOTE_FEIGN_DEATH       = 3,
    EMOTE_FEIGN_REVIVE      = 4,

    EMOTE_TESLA_LINK_BREAKS = 0,
    EMOTE_TESLA_OVERLOAD    = 1
};

enum PetSpells
{
    SPELL_STALAGG_POWERSURGE        = 28134,
    //SPELL_STALAGG_TESLA             = 28097,
    SPELL_STALAGG_TESLA_PERIODIC    = 28098,
    SPELL_STALAGG_CHAIN_VISUAL      = 28096,

    SPELL_FEUGEN_STATICFIELD        = 28135,
    //SPELL_FEUGEN_TESLA              = 28109,
    SPELL_FEUGEN_TESLA_PERIODIC     = 28110,
    SPELL_FEUGEN_CHAIN_VISUAL       = 28111,

    SPELL_MAGNETIC_PULL             = 54517,
    SPELL_MAGNETIC_PULL_EFFECT      = 28337,

    // @hack feugen/stalagg use this in P1 after gripping tanks to prevent mmaps from pathing them off the platform once they approach the ramp
    // developer from the future, if you read this and mmaps in the room has been fixed, then get rid of the hackfix, please
    SPELL_ROOT_SELF                 = 75215,

    SPELL_TESLA_SHOCK               = 28099
};

enum PetMisc
{
    OVERLOAD_DISTANCE       = 28
};


//Thaddius
enum ThaddiusYells
{
    SAY_GREET               = 0,
    SAY_AGGRO               = 1,
    SAY_SLAY                = 2,
    SAY_ELECT               = 3,
    SAY_DEATH               = 4,
    SAY_SCREAM              = 5,

    EMOTE_POLARITY_SHIFTED  = 6
};

enum ThaddiusSpells
{
    SPELL_THADDIUS_INACTIVE_VISUAL  = 28160,
    SPELL_THADDIUS_SPARK_VISUAL     = 28136,
    SPELL_SHOCK_VISUAL              = 28159,

    SPELL_BALL_LIGHTNING            = 28299,
    SPELL_CHAIN_LIGHTNING           = 28167,
    SPELL_BERSERK                   = 27680,

    // polarity handling
    SPELL_POLARITY_SHIFT            = 28089,

    SPELL_POSITIVE_CHARGE_APPLY     = 28059,
    SPELL_POSITIVE_CHARGE_TICK      = 28062,
    SPELL_POSITIVE_CHARGE_AMP       = 29659,

    SPELL_NEGATIVE_CHARGE_APPLY     = 28084,
    SPELL_NEGATIVE_CHARGE_TICK      = 28085,
    SPELL_NEGATIVE_CHARGE_AMP       = 29660,
};

struct boss_thaddius : public BossAI
{
    public:
        boss_thaddius(Creature* creature) : BossAI(creature, BOSS_THADDIUS), stalaggAlive(true), feugenAlive(true), ballLightningUnlocked(false), ballLightningEnabled(false), shockingEligibility(true) {}

        void InitializeAI() override
        {
            if (instance->GetBossState(BOSS_THADDIUS) != DONE)
            {
                events.SetPhase(PHASE_NOT_ENGAGED);
                SetCombatMovement(false);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void Reset() override { }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (!ballLightningEnabled && why == EVADE_REASON_NO_HOSTILES)
            {
                ballLightningEnabled = true;
                return; // try again
            }
            if (events.IsInPhase(PHASE_TRANSITION) || (events.IsInPhase(PHASE_THADDIUS) && me->IsAlive()))
                BeginResetEncounter();
        }

        bool CanAIAttack(Unit const* who) const override
        {
            if (ballLightningEnabled || me->IsWithinMeleeRange(who))
                return BossAI::CanAIAttack(who);
            else
                return false;
        }

        void JustAppeared() override
        {
            if (instance->GetBossState(BOSS_THADDIUS) != DONE)
                ResetEncounter();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            me->setActive(false);
            me->SetFarVisible(false);
            if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
            {
                stalagg->setActive(false);
                stalagg->SetFarVisible(false);
            }
            if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
            {
                feugen->setActive(false);
                feugen->SetFarVisible(false);
            }
            Talk(SAY_DEATH);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_FEUGEN_RESET:
                case ACTION_STALAGG_RESET:
                    if (!events.IsInPhase(PHASE_NOT_ENGAGED))
                        BeginResetEncounter();
                    break;
                case ACTION_FEUGEN_AGGRO:
                case ACTION_STALAGG_AGGRO:
                    if (!events.IsInPhase(PHASE_NOT_ENGAGED))
                        return;
                    events.SetPhase(PHASE_PETS);

                    shockingEligibility = true;

                    if (!instance->CheckRequiredBosses(BOSS_THADDIUS))
                    {
                        BeginResetEncounter();
                        return;
                    }
                    instance->SetBossState(BOSS_THADDIUS, IN_PROGRESS);

                    me->setActive(true);
                    me->SetFarVisible(true);
                    DoZoneInCombat();
                    if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    {
                        stalagg->setActive(true);
                        stalagg->SetFarVisible(true);
                    }
                    if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    {
                        feugen->setActive(true);
                        feugen->SetFarVisible(true);
                    }
                    break;
                case ACTION_FEUGEN_DIED:
                    if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                        feugen->AI()->DoAction(ACTION_FEUGEN_REVIVING_FX);
                    feugenAlive = false;
                    if (stalaggAlive)
                        events.ScheduleEvent(EVENT_REVIVE_FEUGEN, 5s, 0, PHASE_PETS);
                    else
                        Transition();

                    break;
                case ACTION_STALAGG_DIED:
                    if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                        stalagg->AI()->DoAction(ACTION_STALAGG_REVIVING_FX);
                    stalaggAlive = false;
                    if (feugenAlive)
                        events.ScheduleEvent(EVENT_REVIVE_STALAGG, 5s, 0, PHASE_PETS);
                    else
                        Transition();

                    break;

                case ACTION_POLARITY_CROSSED:
                    shockingEligibility = false;
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 id) const override
        {
            return (id == DATA_POLARITY_CROSSED && shockingEligibility) ? 1u : 0u;
        }

        void Transition() // initiate transition between pet phase and thaddius phase
        {
            events.SetPhase(PHASE_TRANSITION);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            events.ScheduleEvent(EVENT_TRANSITION_1, 10s, 0, PHASE_TRANSITION);
            events.ScheduleEvent(EVENT_TRANSITION_2, 12s, 0, PHASE_TRANSITION);
            events.ScheduleEvent(EVENT_TRANSITION_3, 14s, 0, PHASE_TRANSITION);
        }

        void BeginResetEncounter()
        {
            if (instance->GetBossState(BOSS_THADDIUS) == DONE)
                return;

            // remove polarity shift debuffs on reset
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POSITIVE_CHARGE_APPLY);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NEGATIVE_CHARGE_APPLY);

            me->DespawnOrUnsummon(0, Seconds(30));

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
            me->SetImmuneToPC(true);
            me->setActive(false);
            me->SetFarVisible(false);
            if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                feugen->AI()->DoAction(ACTION_BEGIN_RESET_ENCOUNTER);
            if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                stalagg->AI()->DoAction(ACTION_BEGIN_RESET_ENCOUNTER);
        }

        void ResetEncounter()
        {
            feugenAlive = true;
            stalaggAlive = true;

            _Reset();
            events.SetPhase(PHASE_NOT_ENGAGED);
            me->SetReactState(REACT_PASSIVE);

            // @todo these guys should really be moved to a summon group - this is merely a hack to make them work in dynamic_spawning
            instance->instance->RemoveRespawnTime(SPAWN_TYPE_CREATURE, 130958, true); // Stalagg
            instance->instance->RemoveRespawnTime(SPAWN_TYPE_CREATURE, 130959, true); // Feugen
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.IsInPhase(PHASE_NOT_ENGAGED))
                return;
            if (events.IsInPhase(PHASE_THADDIUS) && !UpdateVictim())
                return;

            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_REVIVE_FEUGEN:
                        feugenAlive = true;
                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->AI()->DoAction(ACTION_FEUGEN_REVIVED);
                        break;
                    case EVENT_REVIVE_STALAGG:
                        stalaggAlive = true;
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->AI()->DoAction(ACTION_STALAGG_REVIVED);
                        break;
                    case EVENT_TRANSITION_1: // tesla coils overload
                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->AI()->DoAction(ACTION_TRANSITION);
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->AI()->DoAction(ACTION_TRANSITION);
                        break;
                    case EVENT_TRANSITION_2: // tesla coils shock thaddius
                        me->CastSpell(me, SPELL_THADDIUS_SPARK_VISUAL, true);
                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->AI()->DoAction(ACTION_TRANSITION_2);
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->AI()->DoAction(ACTION_TRANSITION_2);
                        break;
                    case EVENT_TRANSITION_3: // thaddius becomes active
                        me->CastSpell(me, SPELL_THADDIUS_SPARK_VISUAL, true);
                        ballLightningUnlocked = false;
                        me->RemoveAura(SPELL_THADDIUS_INACTIVE_VISUAL);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                        me->SetImmuneToPC(false);
                        me->SetReactState(REACT_AGGRESSIVE);

                        DoZoneInCombat();
                        if (Unit* closest = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 500.0f))
                            AttackStart(closest);
                        else // if there is no nearest target, then there is no target, meaning we should reset
                        {
                            BeginResetEncounter();
                            return;
                        }

                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->AI()->DoAction(ACTION_TRANSITION_3);
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->AI()->DoAction(ACTION_TRANSITION_3);

                        events.SetPhase(PHASE_THADDIUS);

                        Talk(SAY_AGGRO);

                        events.ScheduleEvent(EVENT_ENABLE_BALL_LIGHTNING, 5s, 0, PHASE_THADDIUS);
                        events.ScheduleEvent(EVENT_SHIFT, 10s, 0, PHASE_THADDIUS);
                        events.ScheduleEvent(EVENT_CHAIN, 10s, 20s, 0, PHASE_THADDIUS);
                        events.ScheduleEvent(EVENT_BERSERK, 6min, 0, PHASE_THADDIUS);

                        break;
                    case EVENT_ENABLE_BALL_LIGHTNING:
                        ballLightningUnlocked = true;
                        break;
                    case EVENT_SHIFT:
                        me->CastStop(); // shift overrides all other spells
                        DoCastAOE(SPELL_POLARITY_SHIFT);
                        events.ScheduleEvent(EVENT_SHIFT_TALK, 3s, PHASE_THADDIUS);
                        events.ScheduleEvent(EVENT_SHIFT, 30s, PHASE_THADDIUS);
                        break;
                    case EVENT_SHIFT_TALK:
                        Talk(SAY_ELECT);
                        Talk(EMOTE_POLARITY_SHIFTED);
                        break;
                    case EVENT_CHAIN:
                        if (me->FindCurrentSpellBySpellId(SPELL_POLARITY_SHIFT)) // delay until shift is over
                            events.Repeat(Seconds(3));
                        else
                        {
                            me->CastStop();
                            DoCastVictim(SPELL_CHAIN_LIGHTNING);
                            events.Repeat(randtime(Seconds(10), Seconds(20)));
                        }
                        break;
                    case EVENT_BERSERK:
                        me->CastStop();
                        DoCast(me, SPELL_BERSERK);
                        break;
                    default:
                        break;
                }
            }
            if (events.IsInPhase(PHASE_THADDIUS) && !me->HasUnitState(UNIT_STATE_CASTING) && me->isAttackReady())
            {
                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    ballLightningEnabled = false;
                    DoMeleeAttackIfReady();
                }
                else if (ballLightningUnlocked)
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_BALL_LIGHTNING);
            }
        }

    private:
        bool stalaggAlive;
        bool feugenAlive;
        bool ballLightningUnlocked; // whether the initial ball lightning grace period has expired and we should proceed to exterminate with extreme prejudice
        bool ballLightningEnabled; // switch that is flipped to true if we try to evade due to no eligible targets in melee range
        bool shockingEligibility;
};

class npc_stalagg : public CreatureScript
{
public:
    npc_stalagg() : CreatureScript("npc_stalagg") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetNaxxramasAI<npc_stalaggAI>(creature);
    }

    struct npc_stalaggAI : public ScriptedAI
    {
        public:
            npc_stalaggAI(Creature* creature) : ScriptedAI(creature), _myCoil(ObjectGuid::Empty), _myCoilGO(ObjectGuid::Empty), isOverloading(false), refreshBeam(false), isFeignDeath(false)
            {
                Initialize();
                instance = creature->GetInstanceScript();
                SetBoundary(instance->GetBossBoundary(BOSS_THADDIUS));
            }

            void Initialize()
            {
                if (GameObject* coil = myCoilGO())
                    coil->SetGoState(GO_STATE_ACTIVE);

                // if the encounter reset while feigning death
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                isOverloading = false;
                isFeignDeath = false;

                // force tesla coil state refresh
                refreshBeam = true;

                powerSurgeTimer = 10 * IN_MILLISECONDS;
            }

            void Reset() override
            {
                if (isFeignDeath || !me->IsAlive())
                    return;
                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_STALAGG_RESET);
            }

            void BeginResetEncounter()
            {
                if (GameObject* coil = myCoilGO())
                    coil->SetGoState(GO_STATE_READY);
                me->DespawnOrUnsummon(0, Hours(24*7)); // will be force respawned by thaddius
                me->setActive(false);
                me->SetFarVisible(false);
            }

            void ResetEncounter()
            {
                me->Respawn(true);
                Initialize();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_BEGIN_RESET_ENCOUNTER:
                        BeginResetEncounter();
                        break;
                    case ACTION_STALAGG_REVIVING_FX:
                        break;
                    case ACTION_STALAGG_REVIVED:
                        if (!isFeignDeath)
                            break;

                        me->SetFullHealth();
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Talk(EMOTE_FEIGN_REVIVE);
                        isFeignDeath = false;

                        refreshBeam = true; // force beam refresh

                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            if (feugen->GetVictim())
                            {
                                AddThreat(feugen->EnsureVictim(), 0.0f);
                                me->SetInCombatWith(feugen->EnsureVictim());
                            }
                        break;
                    case ACTION_TRANSITION:
                        me->KillSelf(); // true death
                        me->DespawnOrUnsummon(0, Hours(24*7));

                        if (Creature* coil = myCoil())
                        {
                            coil->CastStop();
                            coil->AI()->Talk(EMOTE_TESLA_OVERLOAD);
                        }
                        break;
                    case ACTION_TRANSITION_2:
                        if (Creature* coil = myCoil())
                            if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                                coil->CastSpell(thaddius, SPELL_SHOCK_VISUAL);
                        break;
                    case ACTION_TRANSITION_3:
                        if (GameObject* coil = myCoilGO())
                            coil->SetGoState(GO_STATE_READY);
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_STALAGG_SLAY);
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_STALAGG_AGGRO);

                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_STALAGG_AGGRO);

                if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    if (!feugen->IsEngaged())
                        AddThreat(who, 0.0f, feugen);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (damage < me->GetHealth())
                    return;

                if (isFeignDeath) // don't take damage while feigning death
                {
                    damage = 0;
                    return;
                }

                isFeignDeath = true;
                isOverloading = false;

                Talk(EMOTE_FEIGN_DEATH);
                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_STALAGG_DIED);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAllAuras();
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->StopMoving();
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                damage = 0;

                // force beam refresh as we just removed auras
                refreshBeam = true;
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (!caster)
                    return;
                if (spell->Id != SPELL_STALAGG_TESLA_PERIODIC)
                    return;
                if (!isFeignDeath && me->IsInCombat() && !me->GetHomePosition().IsInDist(me, OVERLOAD_DISTANCE))
                {
                    if (!isOverloading)
                    {
                        isOverloading = true;
                        caster->SetImmuneToPC(false);
                        if (Creature* creatureCaster = caster->ToCreature())
                            creatureCaster->AI()->Talk(EMOTE_TESLA_LINK_BREAKS);
                        me->RemoveAura(SPELL_STALAGG_CHAIN_VISUAL);
                    }
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        caster->CastStop(SPELL_TESLA_SHOCK);
                        caster->CastSpell(target, SPELL_TESLA_SHOCK,true);
                    }
                }
                else if (isOverloading || refreshBeam)
                {
                    isOverloading = false;
                    refreshBeam = false;
                    caster->CastStop();
                    caster->CastSpell(me, SPELL_STALAGG_CHAIN_VISUAL, true);
                    caster->SetImmuneToPC(true);
                }
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!isFeignDeath)
                    if (!UpdateVictim())
                        return;

                if (powerSurgeTimer <= uiDiff)
                {
                    if (isFeignDeath) // delay until potential revive
                        powerSurgeTimer = 0u;
                    else
                    {
                        DoCast(me, SPELL_STALAGG_POWERSURGE);
                        powerSurgeTimer = urandms(25, 30);
                    }
                }
                else
                    powerSurgeTimer -= uiDiff;

                if (!isFeignDeath)
                    DoMeleeAttackIfReady();
            }

        private:
            Creature* myCoil()
            {
                Creature* coil = nullptr;
                if (_myCoil)
                    coil = ObjectAccessor::GetCreature(*me, _myCoil);
                if (!coil)
                {
                    coil = me->FindNearestCreature(NPC_TESLA, 1000.0f, true);
                    if (coil)
                    {
                        _myCoil = coil->GetGUID();
                        coil->SetReactState(REACT_PASSIVE);
                    }
                }
                return coil;
            }

            GameObject* myCoilGO()
            {
                GameObject* coil = nullptr;
                if (_myCoilGO)
                    coil = ObjectAccessor::GetGameObject(*me, _myCoilGO);
                if (!coil)
                {
                    coil = me->FindNearestGameObject(GO_CONS_NOX_TESLA_STALAGG, 1000.0f);
                    if (coil)
                        _myCoilGO = coil->GetGUID();
                }
                return coil;
            }

            InstanceScript* instance;

            uint32 powerSurgeTimer;

            ObjectGuid _myCoil;
            ObjectGuid _myCoilGO;
            bool isOverloading;
            bool refreshBeam;
            bool isFeignDeath;
    };

};

class npc_feugen : public CreatureScript
{
public:
    npc_feugen() : CreatureScript("npc_feugen") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetNaxxramasAI<npc_feugenAI>(creature);
    }

    struct npc_feugenAI : public ScriptedAI
    {
        public:
            npc_feugenAI(Creature* creature) : ScriptedAI(creature), _myCoil(ObjectGuid::Empty), _myCoilGO(ObjectGuid::Empty), isOverloading(false), refreshBeam(false), isFeignDeath(false)
            {
                Initialize();
                instance = creature->GetInstanceScript();
                SetBoundary(instance->GetBossBoundary(BOSS_THADDIUS));
            }

            void Initialize()
            {
                if (GameObject* coil = myCoilGO())
                    coil->SetGoState(GO_STATE_ACTIVE);

                // if the encounter reset while feigning death
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                isOverloading = false;
                isFeignDeath = false;

                // force coil state to refresh
                refreshBeam = true;

                staticFieldTimer = 6 * IN_MILLISECONDS;
                magneticPullTimer = 20 * IN_MILLISECONDS;
            }

            void Reset() override
            {
                if (isFeignDeath || !me->IsAlive())
                    return;
                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_FEUGEN_RESET);
            }

            void BeginResetEncounter()
            {
                if (GameObject* coil = myCoilGO())
                    coil->SetGoState(GO_STATE_READY);
                me->DespawnOrUnsummon(0, Hours(24*7)); // will be force respawned by thaddius
                me->setActive(false);
                me->SetFarVisible(false);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_BEGIN_RESET_ENCOUNTER:
                        BeginResetEncounter();
                        break;
                    case ACTION_FEUGEN_REVIVING_FX:
                        break;
                    case ACTION_FEUGEN_REVIVED:
                        if (!isFeignDeath)
                            break;

                        me->SetFullHealth();
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Talk(EMOTE_FEIGN_REVIVE);
                        isFeignDeath = false;

                        refreshBeam = true; // force beam refresh

                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            if (stalagg->GetVictim())
                            {
                                AddThreat(stalagg->EnsureVictim(), 0.0f);
                                me->SetInCombatWith(stalagg->EnsureVictim());
                            }
                        staticFieldTimer = 6 * IN_MILLISECONDS;
                        magneticPullTimer = 30 * IN_MILLISECONDS;
                        break;
                    case ACTION_TRANSITION:
                        me->KillSelf(); // true death this time around
                        me->DespawnOrUnsummon(0, Hours(24*7));

                        if (Creature* coil = myCoil())
                        {
                            coil->CastStop();
                            coil->AI()->Talk(EMOTE_TESLA_OVERLOAD);
                        }
                        break;
                    case ACTION_TRANSITION_2:
                        if (Creature* coil = myCoil())
                            if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                                coil->CastSpell(thaddius, SPELL_SHOCK_VISUAL);
                        break;
                    case ACTION_TRANSITION_3:
                        if (GameObject* coil = myCoilGO())
                            coil->SetGoState(GO_STATE_READY);
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_FEUGEN_SLAY);
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_FEUGEN_AGGRO);

                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_FEUGEN_AGGRO);

                if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    if (!stalagg->IsInCombat())
                        AddThreat(who, 0.0f, stalagg);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if (damage < me->GetHealth())
                    return;

                if (isFeignDeath) // don't take damage while feigning death
                {
                    damage = 0;
                    return;
                }

                isFeignDeath = true;
                isOverloading = false;

                Talk(EMOTE_FEIGN_DEATH);
                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_FEUGEN_DIED);

                me->RemoveAllAuras();
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                me->StopMoving();
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                damage = 0;

                // force beam refresh as we just removed auras
                refreshBeam = true;
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (!caster)
                    return;
                if (spell->Id != SPELL_FEUGEN_TESLA_PERIODIC)
                    return;
                if (!isFeignDeath && me->IsInCombat() && !me->GetHomePosition().IsInDist(me, OVERLOAD_DISTANCE))
                {
                    if (!isOverloading)
                    {
                        isOverloading = true;
                        caster->SetImmuneToPC(false);
                        if (Creature* creatureCaster = caster->ToCreature())
                            creatureCaster->AI()->Talk(EMOTE_TESLA_LINK_BREAKS);
                        me->RemoveAura(SPELL_STALAGG_CHAIN_VISUAL);
                    }
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        caster->CastStop(SPELL_TESLA_SHOCK);
                        caster->CastSpell(target, SPELL_TESLA_SHOCK,true);
                    }
                }
                else if (isOverloading || refreshBeam)
                {
                    isOverloading = false;
                    refreshBeam = false;
                    caster->CastStop();
                    caster->CastSpell(me, SPELL_FEUGEN_CHAIN_VISUAL, true);
                    caster->SetImmuneToPC(true);
                }
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (isFeignDeath)
                    return;
                if (!UpdateVictim())
                    return;

                if (magneticPullTimer <= uiDiff)
                {
                    DoCast(me, SPELL_MAGNETIC_PULL);
                    magneticPullTimer = 20 * IN_MILLISECONDS;
                }
                else magneticPullTimer -= uiDiff;

                if (staticFieldTimer <= uiDiff)
                {
                    DoCast(me, SPELL_FEUGEN_STATICFIELD);
                    staticFieldTimer = 6 * IN_MILLISECONDS;
                }
                else staticFieldTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }

        private:
            Creature* myCoil()
            {
                Creature* coil = nullptr;
                if (_myCoil)
                    coil = ObjectAccessor::GetCreature(*me, _myCoil);
                if (!coil)
                {
                    coil = me->FindNearestCreature(NPC_TESLA, 1000.0f, true);
                    if (coil)
                    {
                        _myCoil = coil->GetGUID();
                        coil->SetReactState(REACT_PASSIVE);
                    }
                }
                return coil;
            }

            GameObject* myCoilGO()
            {
                GameObject* coil = nullptr;
                if (_myCoilGO)
                    coil = ObjectAccessor::GetGameObject(*me, _myCoilGO);
                if (!coil)
                {
                    coil = me->FindNearestGameObject(GO_CONS_NOX_TESLA_FEUGEN, 1000.0f);
                    if (coil)
                        _myCoilGO = coil->GetGUID();
                }
                return coil;
            }
            InstanceScript* instance;

            uint32 magneticPullTimer;
            uint32 staticFieldTimer;

            ObjectGuid _myCoil;
            ObjectGuid _myCoilGO;

            bool isOverloading;
            bool refreshBeam;
            bool isFeignDeath;
    };
};

class npc_tesla : public CreatureScript
{
public:
    npc_tesla() : CreatureScript("npc_tesla") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetNaxxramasAI<npc_teslaAI>(creature);
    }

    struct npc_teslaAI : public ScriptedAI
    {
        npc_teslaAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterEvadeMode(EvadeReason /*why*/) override { } // never stop casting due to evade
        void UpdateAI(uint32 /*diff*/) override { } // never do anything unless told
        void JustEngagedWith(Unit* /*who*/) override { }
        void DamageTaken(Unit* /*who*/, uint32& damage) override { damage = 0; } // no, you can't kill it
    };
};

class spell_thaddius_polarity_charge : public SpellScriptLoader
{
    public:
        spell_thaddius_polarity_charge() : SpellScriptLoader("spell_thaddius_polarity_charge") { }

        class spell_thaddius_polarity_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thaddius_polarity_charge_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_POLARITY_SHIFT,
                    SPELL_POSITIVE_CHARGE_APPLY,
                    SPELL_POSITIVE_CHARGE_TICK,
                    SPELL_POSITIVE_CHARGE_AMP,
                    SPELL_NEGATIVE_CHARGE_APPLY,
                    SPELL_NEGATIVE_CHARGE_TICK,
                    SPELL_NEGATIVE_CHARGE_AMP
                });
            }

            void HandleTargets(std::list<WorldObject*>& targetList)
            {
                if (!GetTriggeringSpell())
                    return;

                uint32 triggeringId = GetTriggeringSpell()->Id;
                uint32 ampId;
                switch (triggeringId)
                {
                    case SPELL_POSITIVE_CHARGE_APPLY:
                        ampId = SPELL_POSITIVE_CHARGE_AMP;
                        break;
                    case SPELL_NEGATIVE_CHARGE_APPLY:
                        ampId = SPELL_NEGATIVE_CHARGE_AMP;
                        break;
                    default:
                        return;
                }

                uint8 maxStacks = 0;
                if (GetCaster())
                    switch (GetCaster()->GetMap()->GetDifficulty())
                    {
                        case RAID_DIFFICULTY_10MAN_NORMAL:
                            maxStacks = MAX_POLARITY_10M;
                            break;
                        case RAID_DIFFICULTY_25MAN_NORMAL:
                            maxStacks = MAX_POLARITY_25M;
                            break;
                        default:
                            break;
                    }

                uint8 stacksCount = 1; // do we get a stack for our own debuff?
                std::list<WorldObject*>::iterator it = targetList.begin();
                while(it != targetList.end())
                {
                    if ((*it)->GetTypeId() != TYPEID_PLAYER)
                    {
                        it = targetList.erase(it);
                        continue;
                    }
                    if ((*it)->ToPlayer()->HasAura(triggeringId))
                    {
                        it = targetList.erase(it);
                        if (stacksCount < maxStacks)
                            stacksCount++;
                        continue;
                    }

                    // this guy will get hit - achievement failure trigger
                    if (Creature* thaddius = (*it)->FindNearestCreature(NPC_THADDIUS, 200.0f))
                        thaddius->AI()->DoAction(ACTION_POLARITY_CROSSED);

                    ++it;
                }

                if (GetCaster() && GetCaster()->ToPlayer())
                {
                    if (!GetCaster()->ToPlayer()->HasAura(ampId))
                        GetCaster()->ToPlayer()->AddAura(ampId, GetCaster());
                    GetCaster()->ToPlayer()->SetAuraStack(ampId, GetCaster(), stacksCount);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thaddius_polarity_charge_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_thaddius_polarity_charge_SpellScript();
        }
};

class spell_thaddius_polarity_shift : public SpellScriptLoader
{
    public:
        spell_thaddius_polarity_shift() : SpellScriptLoader("spell_thaddius_polarity_shift") { }

        class spell_thaddius_polarity_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thaddius_polarity_shift_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_POLARITY_SHIFT,
                    SPELL_POSITIVE_CHARGE_APPLY,
                    SPELL_POSITIVE_CHARGE_TICK,
                    SPELL_POSITIVE_CHARGE_AMP,
                    SPELL_NEGATIVE_CHARGE_APPLY,
                    SPELL_NEGATIVE_CHARGE_TICK,
                    SPELL_NEGATIVE_CHARGE_AMP
                });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (target->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (roll_chance_i(50))
                        { // positive
                            target->CastSpell(target, SPELL_POSITIVE_CHARGE_APPLY, true);
                            target->RemoveAura(SPELL_POSITIVE_CHARGE_AMP);
                        }
                        else
                        { // negative
                            target->CastSpell(target, SPELL_NEGATIVE_CHARGE_APPLY, true);
                            target->RemoveAura(SPELL_NEGATIVE_CHARGE_AMP);
                        }
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_thaddius_polarity_shift_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_thaddius_polarity_shift_SpellScript();
        }
};

class spell_thaddius_magnetic_pull : public SpellScriptLoader
{
    public:
        spell_thaddius_magnetic_pull() : SpellScriptLoader("spell_thaddius_magnetic_pull") { };

        class spell_thaddius_magnetic_pull_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thaddius_magnetic_pull_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_MAGNETIC_PULL });
            }

            void HandleCast() // only feugen ever casts this according to wowhead data
            {
                Unit* feugen = GetCaster();
                if (!feugen || feugen->GetEntry() != NPC_FEUGEN)
                    return;

                Unit* stalagg = ObjectAccessor::GetCreature(*feugen, feugen->GetInstanceScript()->GetGuidData(DATA_STALAGG));
                if (!stalagg)
                    return;

                ThreatManager& feugenThreat = feugen->GetThreatManager();
                ThreatManager& stalaggThreat = stalagg->GetThreatManager();

                Unit* feugenTank = feugenThreat.GetCurrentVictim();
                Unit* stalaggTank = stalaggThreat.GetCurrentVictim();

                if (!feugenTank || !stalaggTank)
                    return;

                if (feugenTank == stalaggTank) // special behavior if the tanks are the same (taken from retail)
                {
                    float feugenTankThreat = feugenThreat.GetThreat(feugenTank);
                    float stalaggTankThreat = stalaggThreat.GetThreat(stalaggTank);

                    feugen->GetThreatManager().AddThreat(feugenTank, stalaggTankThreat - feugenTankThreat, nullptr, true, true);
                    stalagg->GetThreatManager().AddThreat(stalaggTank, feugenTankThreat - stalaggTankThreat, nullptr, true, true);

                    feugen->CastSpell(stalaggTank, SPELL_MAGNETIC_PULL_EFFECT, true);
                }
                else // normal case, two tanks
                {
                    float feugenTankThreat = feugenThreat.GetThreat(feugenTank);
                    float feugenOtherThreat = feugenThreat.GetThreat(stalaggTank);
                    float stalaggTankThreat = stalaggThreat.GetThreat(stalaggTank);
                    float stalaggOtherThreat = stalaggThreat.GetThreat(feugenTank);

                    // set the two entries in feugen's threat table to be equal to the ones in stalagg's
                    feugen->GetThreatManager().AddThreat(stalaggTank, stalaggTankThreat - feugenOtherThreat, nullptr, true, true);
                    feugen->GetThreatManager().AddThreat(feugenTank, stalaggOtherThreat - feugenTankThreat, nullptr, true, true);

                    // set the two entries in stalagg's threat table to be equal to the ones in feugen's
                    stalagg->GetThreatManager().AddThreat(feugenTank, feugenTankThreat - stalaggOtherThreat, nullptr, true, true);
                    stalagg->GetThreatManager().AddThreat(stalaggTank, feugenOtherThreat - stalaggTankThreat, nullptr, true, true);

                    // pull the two tanks across
                    feugenTank->CastSpell(stalaggTank, SPELL_MAGNETIC_PULL_EFFECT, true);
                    stalaggTank->CastSpell(feugenTank, SPELL_MAGNETIC_PULL_EFFECT, true);

                    // @hack prevent mmaps clusterfucks from breaking tesla while tanks are midair
                    feugen->AddAura(SPELL_ROOT_SELF, feugen);
                    stalagg->AddAura(SPELL_ROOT_SELF, stalagg);

                    // and make both attack their respective new tanks
                    if (feugen->GetAI())
                        feugen->GetAI()->AttackStart(stalaggTank);
                    if (stalagg->GetAI())
                        stalagg->GetAI()->AttackStart(feugenTank);
                }
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_thaddius_magnetic_pull_SpellScript::HandleCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_thaddius_magnetic_pull_SpellScript();
        }
};

class at_thaddius_entrance : public OnlyOnceAreaTriggerScript
{
    public:
        at_thaddius_entrance() : OnlyOnceAreaTriggerScript("at_thaddius_entrance") { }

        bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetBossState(BOSS_THADDIUS) == DONE)
                return true;

            if (Creature* thaddius = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_THADDIUS)))
                thaddius->AI()->Talk(SAY_GREET);

            return true;
        }
};

class achievement_thaddius_shocking : public AchievementCriteriaScript
{
    public:
        achievement_thaddius_shocking() : AchievementCriteriaScript("achievement_thaddius_shocking") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && target->GetAI() && target->GetAI()->GetData(DATA_POLARITY_CROSSED);
        }
};


void AddSC_boss_thaddius()
{
    RegisterNaxxramasCreatureAI(boss_thaddius);
    new npc_stalagg();
    new npc_feugen();
    new npc_tesla();

    new spell_thaddius_polarity_charge();
    new spell_thaddius_polarity_shift();
    new spell_thaddius_magnetic_pull();

    new at_thaddius_entrance();

    new achievement_thaddius_shocking();
}
