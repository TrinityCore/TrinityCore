/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "nyalotha.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SHATTERED_EGO,
    SAY_VOID_GAZE,
    SAY_MINDGRASP,
    SAY_MINDGATE,
    SAY_CORRUPTING_OF_DEATHWING,
    SAY_SERVANT,
    SAY_WIPE
};

enum Spells
{
    SPELL_SANITY_BAR = 308997,
    SPELL_GIFT_OF_NZOTH = 313609,
    SPELL_MENTAY_DECAY_PERIODIC_AND_BURN = 313610,
    SPELL_SERVANT_OF_NZOTH_CONTROL = 308996,
    SPELL_AZEROTHS_RADIANCE_EXTRA_BUTTON = 310564,
    SPELL_MINDGRASP_CHANNEL = 315772,
    SPELL_MINDGRASP_PULL = 315876,
    SPELL_MINDGRASP_PUSH = 310073,
    SPELL_ETERNAL_TORMENT_AURA_TRIGGER = 318449,
    SPELL_CATACLYSMIC_FLAMES_MISSILE = 313789,
    SPELL_STUPEFYING_GLARE_CREATE_AT = 318975,
    SPELL_SANITY_SCREEN_EFFECT = 317324,
    SPELL_SANITY_RED_EFFECT_SOUND = 318336,
    SPELL_SANITY_SCREEN_EFFECT_2 = 316295,
    SPELL_PROBE_MIND = 314889,
    SPELL_BERSERK = 64238,
    SPELL_TRANDESCENT_POWER = 317639,
    SPELL_SUMMON_GATEWAY = 318091,
    SPELL_COLLAPSING_MINDSCAPE = 317292,
    SPELL_CLEANSING_PROTOCOL = 319349, // used by npc 162882
    SPELL_CLEANSING_PROTOCOL_DAMAGE = 316971,
    SPELL_MINDGATE_CREATE_AT = 316463,
    SPELL_DARK_MATTER = 318971,
};

enum Psychus
{
    EVENT_MANIFEST_MADNESS = 1,
    SPELL_MANIFEST_MADNESS = 310134,
    SPELL_SYNAPTIC_SHOCK = 313184,
    EVENT_MINDWRACK = 2,
    SPELL_MINDWRACK = 316711,
    EVENT_CREEPING_ANQUISH = 3,
    SPELL_CREEPING_ANQUISH_CREATE_AT = 310184,
    SPELL_CREEPING_ANQUISH_DAMAGE = 309991,
    SPELL_SHATTERED_EGO_STUN = 315672,
    SPELL_PERIODIC_ENERGY_GAIN = 299956,
    SPELL_MANIFEST_MADNESS_WAVE = 310135,
    EVENT_MANIFEST_MADNESS_DUMMY_TICK = 4,
    SPELL_ETERNAL_HATRED = 310130,
    SPELL_ETERNAL_HATRED_2 = 310128,

};

enum Events
{
    EVENT_BERSERK = 1,
    EVENT_ETERNAL_HUNGER,
    EVENT_MINDGRASP,
    EVENT_CATACLYSMIC_FLAMES,
    EVENT_STUPEFYING_GLARE, //npc 163950, 
    EVENT_HARVESTER
};

enum Misc
{
    ACHIEVEMENT_MYTHIC_NZOTH_THE_CORRUPTOR = 14055,
    SCENE_DEATH_OF_NZOTH = 2740,
    ACTION_INIT_PHASE_2,
    ACTION_MINDGATE,    
    NZOTH_ENCOUNTER_ID = 2344,
};

const Position synapses_pos = { -11129.0f, 9312.0f, 125.866f, 0.0f };
const Position psychus_pos = { -11194.0f, 9323.0f, 125.865f, 3.0f };
const Position basher_tentacle_pos_1 = { -11099.0f, 9278.0f, 125.866f, 2.2f };
//const Position basher_tentacle_pos_2 = { -11099.0f, 9278.0f, 125.866f, 2.2f };
const Position harvester_pos = { -11157.0f, 9321.0f, 125.866f, 3.0f };

//158041
struct boss_nzoth : public BossAI
{
    boss_nzoth(Creature* creature) : BossAI(creature, DATA_NZOTH) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_DEFENSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);        
        SetCombatMovement(false);
        if (me->IsFalling())
            me->UpdatePosition(me->GetHomePosition()), true;
        //me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        this->tentacles = 0;
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_PSYCHUS:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
            summon->AI()->DoZoneInCombat();
            break;

        case NPC_BASHER_TENTACLE:
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
            summon->AI()->DoZoneInCombat();
            break;

        case NPC_MINDS_EYE:
            summon->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);            
            break;

        case NPC_THOUGHT_HARVESTER:            
            summon->AI()->DoZoneInCombat();
            break;
        }
    }

    void EnterCombat(Unit* u) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();
        this->phase1 = true;
        me->GetScheduler().Schedule(3s, [this] (TaskContext context)
        {
            me->AddUnitState(UNIT_STAND_STATE_SUBMERGED);
            for (uint8 i = 0; i < 13; i++)
            {
                auto exposedSynapses = DoSummon(NPC_EXPOSED_SYNAPSE, me->GetRandomPoint(synapses_pos, 40.0f));
            }
            me->SummonCreature(NPC_PSYCHUS, psychus_pos, TEMPSUMMON_MANUAL_DESPAWN);
        });
        events.ScheduleEvent(EVENT_BERSERK, 13min);
        instance->DoAddAuraOnPlayers(SPELL_AZEROTHS_RADIANCE_EXTRA_BUTTON);
        instance->DoAddAuraOnPlayers(SPELL_SANITY_BAR);
        std::list<Player*> list;
        me->GetPlayerListInGrid(list, 300.0f);
        for (Player* players : list)
        {
            players->SetPower(POWER_ALTERNATE_POWER, 0);
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_MINDGRASP_CHANNEL:
            Talk(SAY_MINDGRASP);
            std::list<Player*> list;
            me->GetPlayerListInGrid(list, 100.0f);
            for (Player* players : list)
            {
                if (players->GetDistance(me) > 20.0f && (players->GetDistance(me) < 48.0f))
                {
                    DoCast(players, SPELL_MINDGRASP_PUSH);
                }
                else if (players->GetDistance(me) > 48.0f)
                {
                    DoCast(players, SPELL_MINDGRASP_PULL);
                }
            }            
            break;
        }
    }

    void DoAction(int32 param) override
    {
        switch (param)
        {
        case ACTION_INIT_PHASE_2:
        {
            events.ScheduleEvent(EVENT_ETERNAL_HUNGER, 3s);
            events.ScheduleEvent(EVENT_MINDGRASP, 8s);
            me->SummonCreature(NPC_BASHER_TENTACLE, basher_tentacle_pos_1, TEMPSUMMON_MANUAL_DESPAWN);
            auto* corrupted = DoSummon(NPC_CORRUPTOR_TENTACLE, me->GetRandomPoint(basher_tentacle_pos_1, 10.0f));
            for (uint8 i = 0; i < 3; i++)
            {
                auto spike = DoSummon(NPC_SPIKE_TENTACLE, me->GetRandomPoint(basher_tentacle_pos_1, 15.0f));
            }
            this->phase1 = false;
            this->phase2 = true;
            events.ScheduleEvent(EVENT_CATACLYSMIC_FLAMES, 13s);
            break;
        }        
        case ACTION_MINDGATE:
        {
            me->SummonCreature(NPC_BASHER_TENTACLE, basher_tentacle_pos_1, TEMPSUMMON_MANUAL_DESPAWN);
            auto* corrupted_wave_2 = DoSummon(NPC_CORRUPTOR_TENTACLE, me->GetRandomPoint(basher_tentacle_pos_1, 10.0f));
            for (uint8 i = 0; i < 3; i++)
            {
                auto spike_2 = DoSummon(NPC_SPIKE_TENTACLE, me->GetRandomPoint(basher_tentacle_pos_1, 15.0f));
            }
            break;
        }

        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_BASHER_TENTACLE:
        case NPC_CORRUPTOR_TENTACLE:
        case NPC_SPIKE_TENTACLE:
            tentacles++;

            if (this->tentacles == 4 && this->phase2)
            {
                Talk(SAY_MINDGATE);
                me->AI()->DoAction(ACTION_MINDGATE);               
            }
            else if (this->tentacles == 8 && this->phase2)
            {
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                this->phase2 = false;
                this->phase3 = true;
                events.ScheduleEvent(EVENT_STUPEFYING_GLARE, 3s);
                events.ScheduleEvent(EVENT_HARVESTER, 8s);
            }
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_MINDGRASP:
            if (this->phase1 = true)
            {
                me->CastSpell(nullptr, SPELL_MINDGRASP_CHANNEL);
            }
            else if (this->phase3 = true)
            {
                me->CastSpell(nullptr, SPELL_MINDGRASP_CHANNEL);
            }
            events.Repeat(30s);
            break;

        case EVENT_ETERNAL_HUNGER:
            if (this->phase2 = true)
            {
                me->AddAura(SPELL_ETERNAL_TORMENT_AURA_TRIGGER);
            }            
            events.Repeat(35s);
            break;

        case EVENT_BERSERK:
            me->AddAura(SPELL_BERSERK);
            me->GetScheduler().Schedule(5s, [this](TaskContext context)
            {
                instance->DoKillPlayersWithAura(SPELL_TRANDESCENT_POWER);
            });
            break;

        case EVENT_HARVESTER:
            if (this->phase3 = true)
            {
                auto* harvest = DoSummon(NPC_THOUGHT_HARVESTER, me->GetRandomPoint(harvester_pos, 30.0f));
            }            
            break;

        case EVENT_CATACLYSMIC_FLAMES:
        {
            if (this->phase2 = true)
            {
                UnitList tarlist;
                SelectTargetList(tarlist, 10, SELECT_TARGET_RANDOM, 100.0f, true);
                for (Unit* target : tarlist)
                {
                    Talk(SAY_CORRUPTING_OF_DEATHWING);
                    me->CastSpell(target, SPELL_CATACLYSMIC_FLAMES_MISSILE);
                }
            }
            events.Repeat(20s);
            break;
        }

        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_WIPE);
        _JustReachedHome();       
        me->DespawnCreaturesInArea(NPC_PSYCHUS, 125.0f);
        me->DespawnCreaturesInArea(NPC_EXPOSED_SYNAPSE, 125.0f);
        me->DespawnCreaturesInArea(NPC_CORRUPTED_NEURON, 125.0f);
        me->DespawnCreaturesInArea(NPC_BASHER_TENTACLE, 125.0f);
        me->DespawnCreaturesInArea(NPC_CORRUPTOR_TENTACLE, 125.0f);
        me->DespawnCreaturesInArea(NPC_SPIKE_TENTACLE, 125.0f);
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (me->HealthBelowPct(3))
        {
            _JustDied();
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAllAreaTriggers();
            instance->DoPlayScenePackageIdOnPlayers(SCENE_DEATH_OF_NZOTH);            
            instance->SendBossKillCredit(NZOTH_ENCOUNTER_ID);
            me->DespawnCreaturesInArea(NPC_PSYCHUS, 125.0f);
            me->DespawnCreaturesInArea(NPC_EXPOSED_SYNAPSE, 125.0f);
            me->DespawnCreaturesInArea(NPC_CORRUPTED_NEURON, 125.0f);
            me->DespawnCreaturesInArea(NPC_BASHER_TENTACLE, 125.0f);
            me->DespawnCreaturesInArea(NPC_CORRUPTOR_TENTACLE, 125.0f);
            me->DespawnCreaturesInArea(NPC_SPIKE_TENTACLE, 125.0f);
            //me->SummonGameObject(GO_VAULT_OF_THE_BLACKE_EMPIRE, Position(-6172.08f, 2483.4f, -3.83898f, 3.14159f), QuaternionData(0, 0, -1, 0), false);
            me->DespawnOrUnsummon();
        }
    }

private:
    bool phase1;
    bool phase2;
    bool phase3;
    uint8 tentacles;
};

//158376
struct npc_psychus : public ScriptedAI
{
    npc_psychus(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
    }

    void EnterCombat(Unit* unit) override
    {
        me->AddAura(SPELL_PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_MINDWRACK, 3s);
        events.ScheduleEvent(EVENT_CREEPING_ANQUISH, 8s);
        events.ScheduleEvent(EVENT_MANIFEST_MADNESS, 101s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            DoCastAOE(SPELL_MANIFEST_MADNESS);
            events.ScheduleEvent(EVENT_MANIFEST_MADNESS_DUMMY_TICK, 1s);
        }

        switch (eventId)
        {
        case EVENT_MINDWRACK:
            DoCastVictim(SPELL_MINDWRACK);
            events.Repeat(10s);
            break;

        case EVENT_CREEPING_ANQUISH:
            DoCast(SPELL_CREEPING_ANQUISH_CREATE_AT);
            events.Repeat(20s);
            break;

        case EVENT_MANIFEST_MADNESS_DUMMY_TICK:    
            DoCastAOE(SPELL_MANIFEST_MADNESS_WAVE);
            events.Repeat(2s);
            break;
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* nzoth = instance->GetCreature(NPC_NZOTH))
        {
            nzoth->AI()->Talk(SAY_SHATTERED_EGO);
            nzoth->AddAura(SPELL_SHATTERED_EGO_STUN);
            if (Creature* synapses = instance->GetCreature(NPC_EXPOSED_SYNAPSE))
            {
                synapses->AddAura(SPELL_SHATTERED_EGO_STUN);
            }
            nzoth->GetScheduler().Schedule(30s, [this, nzoth] (TaskContext context)
            {
                me->ClearUnitState(UNIT_STAND_STATE_SUBMERGED);               
                nzoth->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                nzoth->AI()->DoAction(ACTION_INIT_PHASE_2);
                for (uint8 i = 0; i < 13; i++)
                {
                    auto exposedSynapses = DoSummon(NPC_CORRUPTED_NEURON, me->GetRandomPoint(synapses_pos, 40.0f));
                }
            });
        }
    }
};

enum Exposed
{
    EVENT_PROBE_MIND = 1,
};

//159578
struct npc_exposed_synapse : public ScriptedAI
{
    npc_exposed_synapse(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
    }

    void IsSummonedBy(Unit* u) override
    {
        me->SetObjectScale(0.5f);
        //me->SetDisplayId(95373);
        me->SetDisplayId(76612);
    }

    void EnterCombat(Unit* u) override
    {
        events.ScheduleEvent(EVENT_PROBE_MIND, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_PROBE_MIND:
            DoCastRandom(SPELL_PROBE_MIND, 30.0f, false);
            events.Repeat(10s);
            break;
        }
    }

    void JustDied(Unit* u) override
    {
        if (Creature* psychus = me->FindNearestCreature(NPC_PSYCHUS, 8.0f, true))
        {
            psychus->AddAura(SPELL_SYNAPTIC_SHOCK);
            if (Creature* synapses = instance->GetCreature(NPC_EXPOSED_SYNAPSE))
            {
                if (synapses->IsAlive())
                {
                    synapses->SetHealth(synapses->GetMaxHealth());
                }
            }
        }
    }
};

enum Basher
{
    SPELL_TUMULTUOUS_BURST = 310042,
    EVENT_TUMULTUOUS_BURST = 1,
    SPELL_VOID_LASH = 309698,
    EVENT_VOID_LASH = 2,
    SPELL_EVOLVING_MIGHT = 309592,
    EVENT_EVOLVING_MIGHT = 3,
};

//158367
struct npc_basher_tentacle : public ScriptedAI
{
    npc_basher_tentacle(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
    }

    void EnterCombat(Unit* u) override
    {
        events.ScheduleEvent(EVENT_TUMULTUOUS_BURST, 1s);
        events.ScheduleEvent(EVENT_VOID_LASH, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_TUMULTUOUS_BURST:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 10.0f))
            {
                if (!me->IsWithinMeleeRange(target))
                {
                    DoCastAOE(SPELL_TUMULTUOUS_BURST);
                }                
                events.Repeat(10s);
            }            
            break;

        case EVENT_VOID_LASH:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 10.0f))
            {
                DoCast(target, SPELL_VOID_LASH, false);
            }            
            events.Repeat(15s);            
            break;

        case EVENT_EVOLVING_MIGHT:
            break;
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

enum Spike
{
    SPELL_PAIN_SPIKE = 312078,
    EVENT_PAIN_SPIKE = 1,
    SPELL_CORRUPTED_VISPERA = 318678,
    EVENT_CORRUPTED_VISPERA = 2,
};

//160249
struct npc_spike_tentacle : public ScriptedAI
{
    npc_spike_tentacle(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
    }

    void IsSummonedBy(Unit* u) override
    {
        events.ScheduleEvent(EVENT_PAIN_SPIKE, 3s);    
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_PAIN_SPIKE:
            DoCastRandom(SPELL_PAIN_SPIKE, 300.0f, true);
            events.Repeat(15s);
            break;
        }
    }

    void JustDied(Unit* u) override
    {
        UnitList tarlist;
        SelectTargetList(tarlist, 10, SELECT_TARGET_RANDOM, 100.0f, true);
        for (Unit* target : tarlist)
        {
            me->CastSpell(target, EVENT_CORRUPTED_VISPERA);
        }
    }
};

enum Corruptor
{
    SPELL_CORRUPTED_MIND = 313400,
    EVENT_CORRUPTED_MIND = 1,
};

//158375
struct npc_corruptor_tentacle_158375 : public ScriptedAI
{
    npc_corruptor_tentacle_158375(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
    }

    void IsSummonedBy(Unit* u) override
    {
        events.ScheduleEvent(EVENT_CORRUPTED_MIND, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CORRUPTED_MIND:
            DoCastRandom(SPELL_CORRUPTED_MIND, 300.0f, false);
            events.Repeat(15s);
            break;
        }
    }
};

//158122
struct npc_minds_eye : public ScriptedAI
{
    npc_minds_eye(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }
};

enum Harvester
{
    SPELL_HARVEST_THOUGHTS = 317066,
    SPELL_HARVEST_THOUGHTS_SANITY_BURN = 317166,
    EVENT_HARVEST_THOUGHTS = 1,
};

//162933
struct npc_thought_harvester : public ScriptedAI
{
    npc_thought_harvester(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        events.ScheduleEvent(EVENT_HARVEST_THOUGHTS, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_HARVEST_THOUGHTS:
            DoCastAOE(SPELL_HARVEST_THOUGHTS);
            events.Repeat(60s);
            break;
        }
    }
};

void AddSC_nzoth()
{
    RegisterCreatureAI(boss_nzoth);
    RegisterCreatureAI(npc_psychus);
    RegisterCreatureAI(npc_exposed_synapse);
    RegisterCreatureAI(npc_basher_tentacle);
    RegisterCreatureAI(npc_corruptor_tentacle_158375);
    RegisterCreatureAI(npc_spike_tentacle);
    RegisterCreatureAI(npc_minds_eye);
    RegisterCreatureAI(npc_thought_harvester);
};
