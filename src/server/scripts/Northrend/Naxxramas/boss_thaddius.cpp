/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Player.h"
#include "ObjectGuid.h"
#include "naxxramas.h"


enum Phases
{
    PHASE_NOT_ENGAGED       = 1,
    PHASE_PETS,
    PHASE_TRANSITION,
    PHASE_THADDIUS,
    PHASE_RESETTING
};

enum AIActions
{
    ACTION_RESET_ENCOUNTER_TIMER = -1, // sent from instance AI
    ACTION_BEGIN_RESET_ENCOUNTER =  0, // sent from thaddius to pets to trigger despawn and encounter reset
    ACTION_RESET_ENCOUNTER, // sent from thaddius to pets to trigger respawn and full reset
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

class boss_thaddius : public CreatureScript
{
public:
    boss_thaddius() : CreatureScript("boss_thaddius") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_thaddiusAI>(creature);
    }

    struct boss_thaddiusAI : public BossAI
    {
        public:
            boss_thaddiusAI(Creature* creature) : BossAI(creature, BOSS_THADDIUS), stalaggAlive(true), feugenAlive(true), ballLightningEnabled(false), shockingEligibility(true)
            {
                if (instance->GetBossState(BOSS_THADDIUS) != DONE)
                {                    
                    events.SetPhase(PHASE_NOT_ENGAGED);
                    SetCombatMovement(false);

                    // initialize everything properly, and ensure that the coils are loaded by the time we initialize
                    BeginResetEncounter(true);
                }
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_TRANSITION) || (events.IsInPhase(PHASE_THADDIUS) && me->IsAlive()))
                    BeginResetEncounter();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                me->setActive(false);
                if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    stalagg->setActive(false);
                if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    feugen->setActive(false);
                Talk(SAY_DEATH);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_RESET_ENCOUNTER_TIMER:
                        if (events.IsInPhase(PHASE_RESETTING))
                            ResetEncounter();
                        break;
                    case ACTION_FEUGEN_RESET:
                    case ACTION_STALAGG_RESET:
                        if (!events.IsInPhase(PHASE_NOT_ENGAGED) && !events.IsInPhase(PHASE_RESETTING))
                            BeginResetEncounter();
                        break;
                    case ACTION_FEUGEN_AGGRO:
                    case ACTION_STALAGG_AGGRO:
                        if (events.IsInPhase(PHASE_RESETTING))
                            return BeginResetEncounter();
                        if (!events.IsInPhase(PHASE_NOT_ENGAGED))
                            return;
                        events.SetPhase(PHASE_PETS);

                        shockingEligibility = true;
                        
                        if (!instance->CheckRequiredBosses(BOSS_THADDIUS))
                            return BeginResetEncounter();
                        instance->SetBossState(BOSS_THADDIUS, IN_PROGRESS);

                        me->setActive(true);
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->setActive(true);
                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->setActive(true);
                        break;
                    case ACTION_FEUGEN_DIED:
                        if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                            feugen->AI()->DoAction(ACTION_FEUGEN_REVIVING_FX);
                        feugenAlive = false;
                        if (stalaggAlive)
                            events.ScheduleEvent(EVENT_REVIVE_FEUGEN, 5 * IN_MILLISECONDS, 0, PHASE_PETS);
                        else
                            Transition();

                        break;
                    case ACTION_STALAGG_DIED:
                        if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                            stalagg->AI()->DoAction(ACTION_STALAGG_REVIVING_FX);
                        stalaggAlive = false;
                        if (feugenAlive)
                            events.ScheduleEvent(EVENT_REVIVE_STALAGG, 5 * IN_MILLISECONDS, 0, PHASE_PETS);
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

                events.ScheduleEvent(EVENT_TRANSITION_1, 10 * IN_MILLISECONDS, 0, PHASE_TRANSITION);
                events.ScheduleEvent(EVENT_TRANSITION_2, 12 * IN_MILLISECONDS, 0, PHASE_TRANSITION);
                events.ScheduleEvent(EVENT_TRANSITION_3, 14 * IN_MILLISECONDS, 0, PHASE_TRANSITION);
            }

            void BeginResetEncounter(bool initial = false)
            {
                if (instance->GetBossState(BOSS_THADDIUS) == DONE)
                    return;
                if (events.IsInPhase(PHASE_RESETTING))
                    return;

                if (initial) // signal shorter spawn timer to instance script
                    instance->SetBossState(BOSS_THADDIUS, SPECIAL);
                instance->ProcessEvent(me, EVENT_THADDIUS_BEGIN_RESET);
                instance->SetBossState(BOSS_THADDIUS, NOT_STARTED);

                // remove polarity shift debuffs on reset
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POSITIVE_CHARGE_APPLY);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NEGATIVE_CHARGE_APPLY);

                me->DespawnOrUnsummon();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                events.SetPhase(PHASE_RESETTING);
                if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    feugen->AI()->DoAction(ACTION_BEGIN_RESET_ENCOUNTER);
                if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    stalagg->AI()->DoAction(ACTION_BEGIN_RESET_ENCOUNTER);

                me->setActive(false);
            }

            void ResetEncounter()
            {
                feugenAlive = true;
                stalaggAlive = true;

                me->Respawn(true);
                _Reset();
                events.SetPhase(PHASE_NOT_ENGAGED);

                me->CastSpell(me, SPELL_THADDIUS_INACTIVE_VISUAL, true);

                if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    feugen->AI()->DoAction(ACTION_RESET_ENCOUNTER);
                if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    stalagg->AI()->DoAction(ACTION_RESET_ENCOUNTER);
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
                            ballLightningEnabled = false;
                            me->RemoveAura(SPELL_THADDIUS_INACTIVE_VISUAL);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                            
                            DoZoneInCombat();
                            if (Unit* closest = SelectTarget(SELECT_TARGET_NEAREST, 0, 500.0f))
                                AttackStart(closest);
                            else // if there is no nearest target, then there is no target, meaning we should reset
                                return BeginResetEncounter();

                            if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                                feugen->AI()->DoAction(ACTION_TRANSITION_3);
                            if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                                stalagg->AI()->DoAction(ACTION_TRANSITION_3);

                            events.SetPhase(PHASE_THADDIUS);

                            Talk(SAY_AGGRO);

                            events.ScheduleEvent(EVENT_ENABLE_BALL_LIGHTNING, 5 * IN_MILLISECONDS, 0, PHASE_THADDIUS);
                            events.ScheduleEvent(EVENT_SHIFT, 10 * IN_MILLISECONDS, 0, PHASE_THADDIUS);
                            events.ScheduleEvent(EVENT_CHAIN, urand(10, 20) * IN_MILLISECONDS, 0, PHASE_THADDIUS);
                            events.ScheduleEvent(EVENT_BERSERK, 6 * MINUTE * IN_MILLISECONDS, 0, PHASE_THADDIUS);

                            break;
                        case EVENT_ENABLE_BALL_LIGHTNING:
                            ballLightningEnabled = true;
                            break;
                        case EVENT_SHIFT:
                            me->CastStop(); // shift overrides all other spells
                            DoCastAOE(SPELL_POLARITY_SHIFT);
                            events.ScheduleEvent(EVENT_SHIFT_TALK, 3 * IN_MILLISECONDS, PHASE_THADDIUS);
                            events.ScheduleEvent(EVENT_SHIFT, 30 * IN_MILLISECONDS, PHASE_THADDIUS);
                            break;
                        case EVENT_SHIFT_TALK:
                            Talk(SAY_ELECT);
                            Talk(EMOTE_POLARITY_SHIFTED);
                            break;
                        case EVENT_CHAIN:
                            if (me->FindCurrentSpellBySpellId(SPELL_POLARITY_SHIFT)) // delay until shift is over
                                events.ScheduleEvent(EVENT_CHAIN, 3 * IN_MILLISECONDS, 0, PHASE_THADDIUS);
                            else
                            {
                                me->CastStop();
                                DoCastVictim(SPELL_CHAIN_LIGHTNING);
                                events.ScheduleEvent(EVENT_CHAIN, urand(10, 20) * IN_MILLISECONDS, PHASE_THADDIUS);
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

                if (events.IsInPhase(PHASE_THADDIUS))
                {
                    if (me->IsWithinMeleeRange(me->GetVictim()))
                        DoMeleeAttackIfReady();
                    else
                        if (ballLightningEnabled)
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_BALL_LIGHTNING);
                }
            }

        private:
            bool stalaggAlive;
            bool feugenAlive;
            bool ballLightningEnabled;
            bool shockingEligibility;
    };

};

class npc_stalagg : public CreatureScript
{
public:
    npc_stalagg() : CreatureScript("npc_stalagg") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_stalaggAI>(creature);
    }

    struct npc_stalaggAI : public ScriptedAI
    {
        public:
            npc_stalaggAI(Creature* creature) : ScriptedAI(creature), _myCoil(ObjectGuid::Empty), _myCoilGO(ObjectGuid::Empty), isOverloading(false), refreshBeam(false), isFeignDeath(false)
            {
                Initialize();
                instance = creature->GetInstanceScript();
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
                me->DespawnOrUnsummon();
                me->setActive(false);
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
                    case ACTION_RESET_ENCOUNTER:
                        ResetEncounter();
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
                                me->AddThreat(feugen->EnsureVictim(), 0.0f);
                                me->SetInCombatWith(feugen->EnsureVictim());
                            }
                        break;
                    case ACTION_TRANSITION:
                        me->KillSelf(); // true death
                        me->DespawnOrUnsummon();

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

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_STALAGG_AGGRO);

                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_STALAGG_AGGRO);

                if (Creature* feugen = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FEUGEN)))
                    if (!feugen->IsInCombat())
                    {
                        feugen->AddThreat(who, 0.0f);
                        feugen->SetInCombatWith(who);
                    }
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
                        caster->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
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
                    caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
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
                        powerSurgeTimer = urand(25, 30) * IN_MILLISECONDS;
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
        return GetInstanceAI<npc_feugenAI>(creature);
    }

    struct npc_feugenAI : public ScriptedAI
    {
        public:
            npc_feugenAI(Creature* creature) : ScriptedAI(creature), _myCoil(ObjectGuid::Empty), _myCoilGO(ObjectGuid::Empty), isOverloading(false), refreshBeam(false), isFeignDeath(false)
            {
                Initialize();
                instance = creature->GetInstanceScript();
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
                me->DespawnOrUnsummon();
                me->setActive(false);
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
                    case ACTION_RESET_ENCOUNTER:
                        ResetEncounter();
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
                                me->AddThreat(stalagg->EnsureVictim(), 0.0f);
                                me->SetInCombatWith(stalagg->EnsureVictim());
                            }
                        staticFieldTimer = 6 * IN_MILLISECONDS;
                        magneticPullTimer = 30 * IN_MILLISECONDS;
                        break;
                    case ACTION_TRANSITION:
                        me->KillSelf(); // true death this time around
                        me->DespawnOrUnsummon();

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

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_FEUGEN_AGGRO);

                if (Creature* thaddius = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_THADDIUS)))
                    thaddius->AI()->DoAction(ACTION_STALAGG_AGGRO);

                if (Creature* stalagg = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_STALAGG)))
                    if (!stalagg->IsInCombat())
                    {
                        stalagg->AddThreat(who, 0.0f);
                        stalagg->SetInCombatWith(who);
                    }
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
                        caster->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
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
                    caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
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
        return GetInstanceAI<npc_teslaAI>(creature);
    }

    struct npc_teslaAI : public ScriptedAI
    {
        npc_teslaAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterEvadeMode() override { } // never stop casting due to evade
        void UpdateAI(uint32 /*diff*/) override { } // never do anything unless told
        void EnterCombat(Unit* /*who*/) override { }
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
                return (
                    sSpellMgr->GetSpellInfo(SPELL_POLARITY_SHIFT) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_APPLY) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_TICK) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_AMP) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_APPLY) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_TICK) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_AMP)
                    );
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
                    if (Creature* thaddius = (*it)->FindNearestCreature(NPC_THADDIUS,200.0f))
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
            return new spell_thaddius_polarity_charge_SpellScript;
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
                return (
                    sSpellMgr->GetSpellInfo(SPELL_POLARITY_SHIFT) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_APPLY) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_TICK) &&
                    sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_AMP) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_APPLY) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_TICK) &&
                    sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_AMP)
                    );
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
                return sSpellMgr->GetSpellInfo(SPELL_MAGNETIC_PULL) ? true : false;
            }

            void HandleCast() // only feugen ever casts this according to wowhead data
            {
                Unit* feugen = GetCaster();
                if (!feugen || feugen->GetEntry() != NPC_FEUGEN)
                    return;
                
                Unit* stalagg = ObjectAccessor::GetCreature(*feugen, feugen->GetInstanceScript()->GetGuidData(DATA_STALAGG));
                if (!stalagg)
                    return;

                Unit* feugenTank = feugen->GetVictim();
                Unit* stalaggTank = stalagg->GetVictim();

                if (!feugenTank || !stalaggTank)
                    return;

                ThreatManager& feugenThreat = feugen->getThreatManager();
                ThreatManager& stalaggThreat = stalagg->getThreatManager();

                if (feugenTank == stalaggTank) // special behavior if the tanks are the same (taken from retail)
                {
                    float feugenTankThreat = feugenThreat.getThreat(feugenTank);
                    float stalaggTankThreat = stalaggThreat.getThreat(stalaggTank);

                    feugenThreat.addThreat(feugenTank, stalaggTankThreat - feugenTankThreat);
                    stalaggThreat.addThreat(stalaggTank, feugenTankThreat - stalaggTankThreat);

                    feugen->CastSpell(stalaggTank, SPELL_MAGNETIC_PULL_EFFECT, true);
                }
                else // normal case, two tanks
                {
                    float feugenTankThreat = feugenThreat.getThreat(feugenTank);
                    float feugenOtherThreat = feugenThreat.getThreat(stalaggTank);
                    float stalaggTankThreat = stalaggThreat.getThreat(stalaggTank);
                    float stalaggOtherThreat = stalaggThreat.getThreat(feugenTank);

                    // set the two entries in feugen's threat table to be equal to the ones in stalagg's
                    feugenThreat.addThreat(stalaggTank, stalaggTankThreat - feugenOtherThreat);
                    feugenThreat.addThreat(feugenTank, stalaggOtherThreat - feugenTankThreat);

                    // set the two entries in stalagg's threat table to be equal to the ones in feugen's
                    stalaggThreat.addThreat(feugenTank, feugenTankThreat - stalaggOtherThreat);
                    stalaggThreat.addThreat(stalaggTank, feugenOtherThreat - stalaggTankThreat);

                    // pull the two tanks across
                    feugenTank->CastSpell(stalaggTank, SPELL_MAGNETIC_PULL_EFFECT, true);
                    stalaggTank->CastSpell(feugenTank, SPELL_MAGNETIC_PULL_EFFECT, true);

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

class at_thaddius_entrance : public AreaTriggerScript
{
    public:
        at_thaddius_entrance() : AreaTriggerScript("at_thaddius_entrance") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance || instance->GetData(DATA_HAD_THADDIUS_GREET) || instance->GetBossState(BOSS_THADDIUS) == DONE)
                return true;

            if (Creature* thaddius = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_THADDIUS)))
                thaddius->AI()->Talk(SAY_GREET);
            instance->SetData(DATA_HAD_THADDIUS_GREET, 1u);

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
    new boss_thaddius();
    new npc_stalagg();
    new npc_feugen();
    new npc_tesla();

    new spell_thaddius_polarity_charge();
    new spell_thaddius_polarity_shift();
    new spell_thaddius_magnetic_pull();

    new at_thaddius_entrance();

    new achievement_thaddius_shocking();
}
