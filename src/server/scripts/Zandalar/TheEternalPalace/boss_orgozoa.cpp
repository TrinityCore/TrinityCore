#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"

enum Spells
{
    SPELL_DRIBBLING_ICHOR_MISSILE = 298077,
    SPELL_DRIBBLING_ICHOR_CAST = 299095,
    SPELL_DRIBBLING_ICHOR_DAMAGE = 298087,
    SPELL_INCUBATION_FLUID_DUMMY = 298242,
    SPELL_INCUBATION_FLUID_DAMAGE = 298314,
    SPELL_INCUBATION_FLUID_AURA = 298306,
    SPELL_ARCING_CURRENT = 295825,
    SPELL_CHAOTIC_GROWTH = 296914,
    SPELL_PERVASIVE_SHOCK = 295161,
    SPELL_AMNIOTIC_SPLATTER_AT = 307253,
    SPELL_AMNIOTIC_SPLATTER_DAMAGE = 298458,
    SPELL_AMNIOTIC_ERRUPTION = 298459,
    SPELL_AMNIOTIC_SPLATTER_VISUAL = 298435,
    SPELL_DESENSITIZING_STING = 298156,
    SPELL_HEART_STOPPING_PARALYSIS = 298164,
    SPELL_MASSIVE_INCUBATOR_AURA = 305347,
    SPELL_MASSIVE_INCUBATOR_CAST = 298548,
    SPELL_HATCHERY_MOULTING_AURA = 298522,
    SPELL_HATCHERY_MOULTING_MISSILE = 298525,
    SPELL_HATCHERY_MOULTING_DAMAGE = 298526,
    SPELL_HATCHERY_EGG_AT_MARK = 300276,
    SPELL_EGGSPLOSION = 300308,
    SPELL_AQUA_LANCE_MISSILE = 295799,
    SPELL_AQUA_LANCE_AURA = 295779,
    SPELL_AQUA_LANCE_AT = 295808,
    SPELL_RAGING_RAPIDS_AURA = 300244,
    SPELL_SHOCKING_LIGHTNING = 295818,
    SPELL_CONDUCTIVE_PULSE = 295822,
    SPELL_POWERFUL_STOMP = 296691,
    SPELL_REVERBERATING_TREMOR = 296698,
};

enum OrgozoaEvents
{
    EVENT_INCUBATION_FLUID = 1,
    EVENT_ARCING_CURRENT,
    EVENT_DRIBBLING_ICHOR_PHASE_1,
    EVENT_DRIBBLING_ICHOR_PHASE_2,
    EVENT_ENERGY_CHECK,
    EVENT_SUMMON_ADDS_PHASE_1,
    EVENT_DESENSITIZING_STING,
    EVENT_SUMMON_ADDS_PHASE_2,
    EVENT_AQUA_LANCE,
    EVENT_SHOCKING_LIGHTNING,
    EVENT_CONDUCTIVE_PULSE,
    EVENT_POWERFUL_STOMP,
    EVENT_PERVASIVE_SHOCK,
};

enum Timers
{
    TIMER_INCUBATION_FLUID = 23 * IN_MILLISECONDS,
    TIMER_ARCING_CURRENT = 9 * IN_MILLISECONDS,
    TIMER_DRIBBLING_ICHON = 1 * IN_MILLISECONDS,
    TIMER_ENERGY_CHECK = 2 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS_PHASE_1 = 15 * IN_MILLISECONDS,
    TIMER_DESENSITIZING_STING = 7 * IN_MILLISECONDS,
    TIMER_SUMMON_ADDS_PHASE_2 = 15 * IN_MILLISECONDS,
    TIMER_AQUA_LANCE = 15 * IN_MILLISECONDS,
    TIMER_POWERFUL_STOMP = 30 * IN_MILLISECONDS,
    TIMER_SHOCKING_LIGHTNING = 15 * IN_MILLISECONDS,
    TIMER_CONDUCTIVE_PULSE = 15 * IN_MILLISECONDS,
    TIMER_PERVASIVE_SHOCK = 10 * IN_MILLISECONDS,
};

enum MovementEvents
{
    EVENT_ACTION_MOVE_2 = 20,
    EVENT_ACTION_MOVE_3,
    EVENT_ACTION_MOVE_4,
    EVENT_ACTION_MOVE_5,
    EVENT_ACTION_MOVE_6,
    EVENT_ACTION_MOVE_7,
    EVENT_ACTION_MOVE_8,
};

enum Points
{
    POINT_1 = 200,
    POINT_2,
    POINT_3,
    POINT_4,
    POINT_5,
    POINT_6,
    POINT_7,
    POINT_8_FINAL, // cast
};

Position phase1Adds[2] =
{
    {236.22f, 707.51f, 1060.93f},
    {290.85f, 700.58f, 1060.94f},
};

Position phase2Adds[2] =
{
    {192.17f, 823.58f, 1010.77f},
    {252.74f, 818.31f, 1010.98f},
};

Position phase2Intermission[8] =
{
    {268.44f, 721.32f, 1060.82f},
    {272.97f, 741.00f, 1060.25f},
    {326.45f, 737.38f, 1051.20f},
    {346.47f, 762.44f, 1043.44f},
    {326.42f, 798.75f, 1034.46f},
    {212.08f, 774.73f, 1010.85f},
    {211.57f, 809.72f, 1010.75f},
    {220.20f, 818.42f, 1010.81f},
};

const Position firstPlatform = { 267.31f, 703.25f, 1060.80f }; //30y
const Position secondPlatform = { 220.20f, 818.42f, 1010.81f }; //50y 

Position hatcheryEgg[25] =
{
    { 218.68f, 778.92f, 1010.92f },
    {231.12f, 774.02f, 1014.37f},
    {238.68f, 782.15f, 1017.11f},
    {245.94f, 776.49f, 1019.71f},
    {259.33f, 774.78f, 1023.61f,},
    {273.67f, 779.43f, 1025.80f},
    {267.61f, 787.05f, 1025.38f},
    {283.98f, 796.09f, 1026.94f},
    {296.16f, 790.87f, 1028.03f},
    {304.71f, 799.31f, 1029.78f},
    {316.43f, 793.76f, 1032.32f},
    {321.22f, 800.04f, 1033.25f},
    {327.51f, 790.89f, 1035.81f},
    {336.40f, 783.79f, 1038.50f},
    {346.83f, 778.13f, 1040.27f},
    {337.77f, 763.72f, 1043.83f},
    {344.07f, 753.08f, 1045.55f},
    {334.71f, 748.83f, 1047.64f},
    {325.72f, 739.09f, 1051.20f},
    {314.48f, 741.38f, 1053.99f,},
    {311.12f, 729.96f, 1054.75f},
    {302.14f, 737.68f, 1057.32f},
    {292.33f, 741.42f, 1059.23f},
    {284.90f, 737.96f, 1060.05f},
    {279.57f, 745.14f, 1060.55f},
}; //used for swirly pos 2-3 patches on every pos

struct checkIncubation : public std::unary_function<Unit*, bool>
{
    checkIncubation() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        return (!player->HasAura(SPELL_INCUBATION_FLUID_AURA));
    }
};

// texts, miscs, 17048 @FIXME visual

//152128
class bfa_boss_orgozoa : public CreatureScript
{
public:
    bfa_boss_orgozoa() : CreatureScript("bfa_boss_orgozoa")
    {
    }

    struct bfa_boss_orgozoa_AI : public BossAI
    {
        bfa_boss_orgozoa_AI(Creature* creature) : BossAI(creature, DATA_ORGOZOA), summons(me)
        {
            instance = creature->GetInstanceScript();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 0);
            me->SetPower(POWER_ENERGY, 0);
            me->SetSpeed(MOVE_RUN, 5.5f);
            me->SetSpeed(MOVE_WALK, 5.5f);
            me->SetSpeed(MOVE_FLIGHT, 5.5f);
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool intermission;
        bool phase1_check;
        bool phase2_check;
        uint8 dribblingIchor;

        void Reset()
        {
            intermission = false;
            phase1_check = false;
            phase2_check = false;
            events.Reset();
            RemoveIncubationFluid();
            DespawnCreatureEntry(NPC_ZANJIR_MYRMIDON);
            DespawnCreatureEntry(NPC_DREADCOIL_HULK);
            DespawnCreatureEntry(NPC_AZSHARI_WITCH);
            DespawnCreatureEntry(NPC_ZOATROID);
            DespawnCreatureEntry(NPC_HATCHERY_EGG);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void JustDied(Unit*)
        {
            RemoveIncubationFluid();
            DespawnCreatureEntry(NPC_ZANJIR_MYRMIDON);
            DespawnCreatureEntry(NPC_DREADCOIL_HULK);
            DespawnCreatureEntry(NPC_AZSHARI_WITCH);
            DespawnCreatureEntry(NPC_ZOATROID);
            DespawnCreatureEntry(NPC_HATCHERY_EGG);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            _DespawnAtEvade(15);
        }

        void RemoveIncubationFluid()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    if (player->HasAura(SPELL_INCUBATION_FLUID_AURA))
                        player->RemoveAura(SPELL_INCUBATION_FLUID_AURA);
        }

        void HandlePhases(uint32 phaseId)
        {
            switch (phaseId)
            {
            case 1:
            {
                me->GetMotionMaster()->Clear();
                dribblingIchor = 1;
                phase1_check = true;
                me->SetPower(POWER_ENERGY, 0);
                events.Reset();
                events.ScheduleEvent(EVENT_INCUBATION_FLUID, TIMER_INCUBATION_FLUID);
                events.ScheduleEvent(EVENT_ENERGY_CHECK, TIMER_ENERGY_CHECK);
                events.ScheduleEvent(EVENT_DESENSITIZING_STING, TIMER_DESENSITIZING_STING);

                events.ScheduleEvent(EVENT_SUMMON_ADDS_PHASE_1, TIMER_SUMMON_ADDS_PHASE_1);
                break;
            }
            case 2:
            {
                for (uint32 i = 0; i < 25; ++i)
                    me->SummonCreature(NPC_HATCHERY_EGG, hatcheryEgg[i], TEMPSUMMON_MANUAL_DESPAWN);
                RemoveIncubationFluid();
                phase1_check = false;
                events.Reset();
                me->GetMotionMaster()->MovePoint(POINT_1, phase2Intermission[0], false);
                break;
            }
            case 3:
            {
                DespawnCreatureEntry(NPC_HATCHERY_EGG);
                me->GetMotionMaster()->Clear();
                GripPlayers();
                dribblingIchor = 2;
                phase2_check = true;
                events.Reset();
                me->SetPower(POWER_ENERGY, 0);

                events.ScheduleEvent(EVENT_INCUBATION_FLUID, TIMER_INCUBATION_FLUID);
                events.ScheduleEvent(EVENT_ENERGY_CHECK, TIMER_ENERGY_CHECK);
                events.ScheduleEvent(EVENT_DESENSITIZING_STING, TIMER_DESENSITIZING_STING);

                events.ScheduleEvent(EVENT_SUMMON_ADDS_PHASE_2, TIMER_SUMMON_ADDS_PHASE_2);
                break;
            }
            }
        }

        void GripPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster() && player->GetPositionZ() > 1011.00f)
                    {
                        player->GetMotionMaster()->MoveJump(204.53f, 781.75f, 1010.81f, 0.0f, 30.0f, 20.0f);
                    }
                }
        }

        void CheckAddsNearby()
        {
            std::list<Creature*> creatureList;
            me->GetCreatureListWithEntryInGrid(creatureList, NPC_ZOATROID, 200.0f);
            if (creatureList.size())
            {
                for (auto creature : creatureList)
                {
                    if (me->GetDistance(creature) <= 15.0f)
                    {
                        creature->AddAura(SPELL_CHAOTIC_GROWTH, creature);
                    }
                    else
                        creature->RemoveAura(SPELL_CHAOTIC_GROWTH);
                }
            }
        }

        void DespawnCreatureEntry(uint32 entry)
        {
            std::list<Creature*> creatureList;
            me->GetCreatureListWithEntryInGrid(creatureList, entry, 500.0f);
            if (creatureList.size())
            {
                for (auto creature : creatureList)
                    creature->DespawnOrUnsummon();
            }
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (me->HealthBelowPct(40) && !intermission)
            {
                intermission = true;
                HandlePhases(2);
            }
        }

        void OnSpellCastInterrupt(SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_MASSIVE_INCUBATOR_CAST:
                HandlePhases(3);
                break;
            }
        }

        void EnterCombat(Unit*)
        {
            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            HandlePhases(1);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            switch (pointId)
            {
            case POINT_1:
                events.ScheduleEvent(EVENT_ACTION_MOVE_2, 500);
                break;
            case POINT_2:
                events.ScheduleEvent(EVENT_ACTION_MOVE_3, 500);
                break;
            case POINT_3:
                events.ScheduleEvent(EVENT_ACTION_MOVE_4, 500);
                break;
            case POINT_4:
                events.ScheduleEvent(EVENT_ACTION_MOVE_5, 500);
                break;
            case POINT_5:
                events.ScheduleEvent(EVENT_ACTION_MOVE_6, 500);
                break;
            case POINT_6:
                events.ScheduleEvent(EVENT_ACTION_MOVE_7, 500);
                break;
            case POINT_7:
                events.ScheduleEvent(EVENT_ACTION_MOVE_8, 500);
                break;
            case POINT_8_FINAL:
                me->AddAura(SPELL_MASSIVE_INCUBATOR_AURA, me);
                me->CastSpell(me, SPELL_MASSIVE_INCUBATOR_CAST);
                break;
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_AZSHARI_WITCH:
            case NPC_DREADCOIL_HULK:
            case NPC_ZANJIR_MYRMIDON:
            case NPC_ZOATROID:
                summon->SetInCombatWithZone();
                break;
            case NPC_HATCHERY_EGG:
                summon->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                summon->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                summon->AddAura(SPELL_HATCHERY_EGG_AT_MARK, summon);
                summon->AddAura(SPELL_HATCHERY_MOULTING_AURA, summon);
                break;
            }
        }

        void HandlePhase1Adds()
        {
            for (uint8 i = 0; i < 2; ++i)
                me->SummonCreature(NPC_ZOATROID, phase1Adds[0], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_ZOATROID, phase1Adds[1], TEMPSUMMON_MANUAL_DESPAWN);

        }

        void HandlePhase2Adds()
        {
            std::vector<uint32> possibleCreature;

            //if (me->GetMap()->IsNormal())
            {
                possibleCreature.push_back(NPC_AZSHARI_WITCH);
                possibleCreature.push_back(NPC_ZANJIR_MYRMIDON);
                possibleCreature.push_back(NPC_DREADCOIL_HULK);
            }
        //    else
            {
                possibleCreature.push_back(NPC_ZOATROID);
                possibleCreature.push_back(NPC_AZSHARI_WITCH);
                possibleCreature.push_back(NPC_ZANJIR_MYRMIDON);
                possibleCreature.push_back(NPC_DREADCOIL_HULK);
            }

            if (possibleCreature.size() >= 2)
                possibleCreature.resize(2);

            if (possibleCreature.size())
            {
                for (auto creature : possibleCreature)
                {
                    for (uint8 i = 0; i < 2; ++i)
                        me->SummonCreature(creature, phase2Adds[i]);
                }
            }
        }

        void HandleArcingCurrent()
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 200.0f);
            playerList.remove_if(checkIncubation());

            if (me->GetMap()->IsMythic())
            {
                if (!playerList.empty())
                {
                    for (auto player : playerList)
                    {
                        me->CastSpell(player, SPELL_ARCING_CURRENT, true);
                    }
                }
            }
            else
            {
                if (playerList.size() >= 1)
                    playerList.resize(1);

                if (!playerList.empty())
                {
                    for (auto player : playerList)
                        me->CastSpell(player, SPELL_ARCING_CURRENT, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
                CheckAddsNearby();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INCUBATION_FLUID:
                {
                    me->CastSpell(me, SPELL_INCUBATION_FLUID_DUMMY);
                    events.ScheduleEvent(EVENT_ARCING_CURRENT, TIMER_ARCING_CURRENT);
                    break;
                }
                case EVENT_ARCING_CURRENT:
                {
                    HandleArcingCurrent();
                    events.ScheduleEvent(EVENT_INCUBATION_FLUID, TIMER_INCUBATION_FLUID);
                    break;
                }
                case EVENT_DESENSITIZING_STING:
                {
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_DESENSITIZING_STING);
                    events.ScheduleEvent(EVENT_DESENSITIZING_STING, TIMER_DESENSITIZING_STING);
                    break;
                }
                case EVENT_ENERGY_CHECK:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        if (phase1_check)
                            events.ScheduleEvent(EVENT_DRIBBLING_ICHOR_PHASE_1, 500);
                        else if (phase2_check)
                            events.ScheduleEvent(EVENT_DRIBBLING_ICHOR_PHASE_2, 500);
                        me->SetPower(POWER_ENERGY, 0);
                    }

                    me->SetPower(POWER_ENERGY, urand(1, 2));
                    events.ScheduleEvent(EVENT_ENERGY_CHECK, TIMER_ENERGY_CHECK);
                    break;
                }
                case EVENT_DRIBBLING_ICHOR_PHASE_1:
                {
                    me->CastSpell(me, SPELL_DRIBBLING_ICHOR_CAST);
                    events.ScheduleEvent(EVENT_DRIBBLING_ICHOR_PHASE_1, TIMER_SUMMON_ADDS_PHASE_1);
                    break;
                }
                case EVENT_DRIBBLING_ICHOR_PHASE_2:
                {
                    me->CastSpell(me, SPELL_DRIBBLING_ICHOR_CAST);
                    events.ScheduleEvent(EVENT_SUMMON_ADDS_PHASE_2, TIMER_SUMMON_ADDS_PHASE_2);
                    break;
                }
                case EVENT_SUMMON_ADDS_PHASE_2:
                {
                    HandlePhase2Adds();
                    break;
                }
                case EVENT_SUMMON_ADDS_PHASE_1:
                {
                    HandlePhase1Adds();
                    break;
                }
                case EVENT_ACTION_MOVE_2:
                {
                    me->GetMotionMaster()->MovePoint(POINT_2, phase2Intermission[1], false);
                    break;
                }
                case EVENT_ACTION_MOVE_3:
                {
                    me->GetMotionMaster()->MovePoint(POINT_3, phase2Intermission[2], false);
                    break;
                }
                case EVENT_ACTION_MOVE_4:
                {
                    me->GetMotionMaster()->MovePoint(POINT_4, phase2Intermission[3], false);
                    break;
                }
                case EVENT_ACTION_MOVE_5:
                {
                    me->GetMotionMaster()->MovePoint(POINT_5, phase2Intermission[4], false);
                    break;
                }
                case EVENT_ACTION_MOVE_6:
                {
                    me->GetMotionMaster()->MovePoint(POINT_6, phase2Intermission[5], false);
                    break;
                }
                case EVENT_ACTION_MOVE_7:
                {
                    me->GetMotionMaster()->MovePoint(POINT_7, phase2Intermission[6], false);
                    break;
                }
                case EVENT_ACTION_MOVE_8:
                {
                    me->GetMotionMaster()->MovePoint(POINT_8_FINAL, phase2Intermission[7], false);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_orgozoa_AI(creature);
    }
};

// 299095 // spellmgr change SPELL_AURA_PERIODIC_DUMMY effect 1
class bfa_spell_dribbling_ichor : public SpellScriptLoader
{
public:
    bfa_spell_dribbling_ichor() : SpellScriptLoader("bfa_spell_dribbling_ichor") { }

    class bfa_spell_dribbling_ichor_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_dribbling_ichor_AuraScript);

        uint8 ichor;

        bool Load()
        {
            ichor = 0;
            return true;
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (aurEff->GetTickNumber() % 3)
            {
                if (Unit* orgozoa = caster->ToCreature())
                {
                    bfa_boss_orgozoa::bfa_boss_orgozoa_AI* ai = CAST_AI(bfa_boss_orgozoa::bfa_boss_orgozoa_AI, orgozoa->GetAI());

                    ichor = ai->dribblingIchor;
                }
                if (ichor == 1)
                {
                    for (uint32 i = 0; i < 12; i++)
                    {
                        Position randomPattern = caster->GetRandomPoint(firstPlatform, 30.0f);
                        caster->CastSpell(randomPattern, SPELL_DRIBBLING_ICHOR_MISSILE, true);
                    }
                }
                else if (ichor == 2)
                {
                    for (uint32 i = 0; i < 24; i++)
                    {
                        Position randomPatter = caster->GetRandomPoint(secondPlatform, 40.0f);
                        caster->CastSpell(randomPatter, SPELL_DRIBBLING_ICHOR_MISSILE, true);
                    }
                }
            }

        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_dribbling_ichor_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_dribbling_ichor_AuraScript;
    }
};

// 298156
class bfa_spell_desensiizing_sting : public SpellScriptLoader
{
public:
    bfa_spell_desensiizing_sting() : SpellScriptLoader("bfa_spell_desensiizing_sting") { }

    class bfa_spell_desensiizing_sting_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_desensiizing_sting_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            if (this->GetStackAmount() > 9)
                caster->CastSpell(target, SPELL_HEART_STOPPING_PARALYSIS, true);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_desensiizing_sting_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_desensiizing_sting_AuraScript;
    }
};

// 298548
class bfa_spell_massive_incubator : public SpellScriptLoader
{
public:
    bfa_spell_massive_incubator() : SpellScriptLoader("bfa_spell_massive_incubator") { }

    class bfa_spell_massive_incubator_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_massive_incubator_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 200.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    player->Kill(player, false);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_massive_incubator_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_massive_incubator_SpellScript;
    }
};

// 298242
class bfa_spell_incubation_fluid : public SpellScriptLoader
{
public:
    bfa_spell_incubation_fluid() : SpellScriptLoader("bfa_spell_incubation_fluid") { }

    class bfa_spell_incubation_fluid_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_incubation_fluid_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 200.0f);
            if (playerList.size() >= (caster->GetMap()->IsMythic() ? 6 : 3))
                playerList.resize(caster->GetMap()->IsMythic() ? 6 : 3);

            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    caster->CastSpell(player, SPELL_INCUBATION_FLUID_AURA, true);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_incubation_fluid_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_incubation_fluid_SpellScript;
    }
};

class bfa_npc_zoatroid : public CreatureScript
{
public:
    bfa_npc_zoatroid() : CreatureScript("bfa_npc_zoatroid")
    {
    }

    struct bfa_npc_zoatroid_AI : public ScriptedAI
    {
        bfa_npc_zoatroid_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;
        bool _dead;

        void Reset()
        {
            _dead = false;
            events.Reset();
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth() && !_dead)
            {
                _dead = true;
                me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);
                damage = 0;
                me->AddAura(SPELL_AMNIOTIC_SPLATTER_AT, me);
                me->AddAura(SPELL_AMNIOTIC_SPLATTER_VISUAL, me);

                me->GetScheduler().Schedule(6s, [this](TaskContext /*context*/)
                    {
                        me->DespawnOrUnsummon(500);
                    });
            }
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_PERVASIVE_SHOCK, TIMER_PERVASIVE_SHOCK);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PERVASIVE_SHOCK:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_PERVASIVE_SHOCK, true);
                    events.ScheduleEvent(EVENT_PERVASIVE_SHOCK, TIMER_PERVASIVE_SHOCK);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_zoatroid_AI(creature);
    }

};

// 298443
class bfa_spell_amniotic_splatter_filter : public SpellScriptLoader
{
public:
    bfa_spell_amniotic_splatter_filter() : SpellScriptLoader("bfa_spell_amniotic_splatter_filter") { }

    class bfa_spell_amniotic_splatter_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_amniotic_splatter_filter_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 2.5f);
            if (playerList.empty())
            {
                caster->CastSpell(caster, SPELL_AMNIOTIC_ERRUPTION, true);
            }
            else if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (player->HasAura(SPELL_DESENSITIZING_STING))
                        player->RemoveAura(SPELL_DESENSITIZING_STING);
                    caster->CastSpell(player, SPELL_AMNIOTIC_SPLATTER_DAMAGE, true);
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_amniotic_splatter_filter_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_amniotic_splatter_filter_SpellScript;
    }
};

class bfa_npc_azshari_witch : public CreatureScript
{
public:
    bfa_npc_azshari_witch() : CreatureScript("bfa_npc_azshari_witch")
    {
    }

    struct bfa_npc_azshari_witch_AI : public ScriptedAI
    {
        bfa_npc_azshari_witch_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_SHOCKING_LIGHTNING, TIMER_SHOCKING_LIGHTNING);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHOCKING_LIGHTNING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        me->CastSpell(target, SPELL_SHOCKING_LIGHTNING);
                    events.ScheduleEvent(EVENT_CONDUCTIVE_PULSE, TIMER_CONDUCTIVE_PULSE);
                    break;
                case EVENT_CONDUCTIVE_PULSE:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_CONDUCTIVE_PULSE);
                    events.ScheduleEvent(EVENT_SHOCKING_LIGHTNING, TIMER_SHOCKING_LIGHTNING);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_azshari_witch_AI(creature);
    }

};

class bfa_npc_dreadcoil_hulk : public CreatureScript
{
public:
    bfa_npc_dreadcoil_hulk() : CreatureScript("bfa_npc_dreadcoil_hulk")
    {
    }

    struct bfa_npc_dreadcoil_hulk_AI : public ScriptedAI
    {
        bfa_npc_dreadcoil_hulk_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_POWERFUL_STOMP, TIMER_POWERFUL_STOMP);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_POWERFUL_STOMP:
                    me->CastSpell(me->GetVictim(), SPELL_POWERFUL_STOMP);
                    events.ScheduleEvent(EVENT_POWERFUL_STOMP, TIMER_POWERFUL_STOMP);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_dreadcoil_hulk_AI(creature);
    }

};

// 296691
class bfa_spell_powerful_stomp : public SpellScriptLoader
{
public:
    bfa_spell_powerful_stomp() : SpellScriptLoader("bfa_spell_powerful_stomp") { }

    class bfa_spell_powerful_stomp_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_powerful_stomp_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 0;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetList = targets.size();
        }

        void RecalculateDamage(SpellEffIndex index)
        {
            if (targetList > 1)
                SetHitDamage(GetHitDamage() / targetList);
            else
                GetCaster()->CastSpell(GetCaster(), SPELL_REVERBERATING_TREMOR, true);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_powerful_stomp_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_powerful_stomp_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_powerful_stomp_SpellScript();
    }
};

class bfa_npc_zanjir_myrmidon : public CreatureScript
{
public:
    bfa_npc_zanjir_myrmidon() : CreatureScript("bfa_npc_zanjir_myrmidon")
    {
    }

    struct bfa_npc_zanjir_myrmidon_AI : public ScriptedAI
    {
        bfa_npc_zanjir_myrmidon_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_AQUA_LANCE, TIMER_AQUA_LANCE);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_AQUA_LANCE:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                    {
                        std::ostringstream str;
                        str << target->GetName() << " has been targeted for |cFFF00000|h[Aqua Lance]|h|r";
                        me->TextEmote(str.str().c_str(), 0, true);
                        me->CastSpell(target, SPELL_AQUA_LANCE_MISSILE);
                    }
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_zanjir_myrmidon_AI(creature);
    }

};

// 295808
class bfa_spell_aqua_lance : public SpellScriptLoader
{
public:
    bfa_spell_aqua_lance() : SpellScriptLoader("bfa_spell_aqua_lance") { }

    class bfa_spell_aqua_lance_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_aqua_lance_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            //if (Unit* caster = GetCaster())
              //  if (WorldLocation const* target = GetExplTargetDest())
               //     caster->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_AQUA_LANCE_AT);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_aqua_lance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_CREATE_AREATRIGGER);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new bfa_spell_aqua_lance_SpellScript();
    }
};

// 17048
class bfa_at_aqua_lance : public AreaTriggerEntityScript
{
public:
    bfa_at_aqua_lance() : AreaTriggerEntityScript("bfa_at_aqua_lance") { }

    struct bfa_at_aqua_lance_AI : AreaTriggerAI
    {
        bfa_at_aqua_lance_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUpdate(uint32 diff)
        {
            std::list<Player*> playerList;
            at->GetPlayerListInGrid(playerList, 5.0f);
            if (!playerList.empty())
            {
                for (auto player : playerList)
                {
                    if (!player->HasAura(SPELL_RAGING_RAPIDS_AURA))
                    {
                        if (Aura* rapids = player->AddAura(SPELL_RAGING_RAPIDS_AURA, player))
                        {
                            rapids->SetMaxDuration(2000);
                            rapids->SetDuration(2000);
                        }
                    }
                }
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_aqua_lance_AI(areatrigger);
    }
};

class bfa_npc_hattchery_eggs : public CreatureScript
{
public:
    bfa_npc_hattchery_eggs() : CreatureScript("bfa_npc_hattchery_eggs")
    {
    }

    struct bfa_npc_hattchery_eggs_AI : public ScriptedAI
    {
        bfa_npc_hattchery_eggs_AI(Creature* creature) : ScriptedAI(creature)
        {
            creature->AddUnitState(UNIT_STATE_ROOT);
        }

        bool eggxploded;

        void Reset()
        {
            eggxploded = false;
        }
        void UpdateAI(uint32 diff)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster() && player->GetDistance(me) <= 4.0f && !eggxploded)
                    {
                        eggxploded = true;
                        me->CastSpell(me, SPELL_EGGSPLOSION);
                    }
                }
        }

        void OnSpellFinished(SpellInfo const* spellInfo)// override
        {
            switch (spellInfo->Id)
            {
            case SPELL_EGGSPLOSION:
                me->DespawnOrUnsummon(500);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_hattchery_eggs_AI(creature);
    }

};

void AddSC_boss_orgozoa()
{
    new bfa_boss_orgozoa();

    new bfa_at_aqua_lance();

    new bfa_npc_azshari_witch();
    new bfa_npc_dreadcoil_hulk();
    new bfa_npc_hattchery_eggs();
    new bfa_npc_zanjir_myrmidon();
    new bfa_npc_zoatroid();

    new bfa_spell_amniotic_splatter_filter();
    new bfa_spell_aqua_lance();
    new bfa_spell_massive_incubator();
    new bfa_spell_desensiizing_sting();
    new bfa_spell_dribbling_ichor();
    new bfa_spell_incubation_fluid();
    new bfa_spell_powerful_stomp();
}
