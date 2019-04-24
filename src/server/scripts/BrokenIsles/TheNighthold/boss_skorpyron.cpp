#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Player.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Player.h"
#include "Vehicle.h"
#include "CombatAI.h"
#include "MoveSplineInitArgs.h"
#include "GridNotifiers.h"
#include "thenighthold.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "CreatureAIImpl.h"

class PlaySpellVisualEvent : public BasicEvent
{
public:
    PlaySpellVisualEvent(Unit* caster, Unit* target, uint32 spellVisualId) : _caster(caster), _target(target), _spellVisualId(spellVisualId) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/)
    {
        if (_caster && _target && _caster->IsInWorld() && _target->IsInWorld())
			_caster->SendPlaySpellVisual(_target->GetGUID(), _spellVisualId, 0.f, 0.f, 40.0f, false);

        return true;
    }

private:
    Unit* _caster;
    Unit* _target;
    uint32 _spellVisualId;
};

class MoveSmoothPathEvent : public BasicEvent
{
public:
    MoveSmoothPathEvent(Unit* scorpid, Movement::PointsArray points) : _scorpid(scorpid), _points(points) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/)
    {
        if (_scorpid && _scorpid->IsInWorld())
            _scorpid->GetMotionMaster()->MoveSmoothPath(1, _points, false);
        return true;
    }

private:
    Unit* _scorpid;
    Movement::PointsArray _points;
};

enum Spells
{
    SPELL_POWER_PERIODIC                        = 204277,
    SPELL_CHITINOUS_EXOSKELETON_VISUAL          = 206947,
    SPELL_CHITINOUS_EXOSKELETON                 = 204448,
    SPELL_ARCANOSLASH_PERIODIC                  = 205200,
    SPELL_ARCANOSLASH_DAMAGE                    = 204275,
    SPELL_ARCANE_TETHER_DEBUFF                  = 204531,
    SPELL_ARCANE_TETHER_DAMAGE                  = 211659,
    SPELL_ARCANE_TETHER_SUMMON                  = 204378,
    SPELL_ARCANE_TETHER_PERIODIC                = 214966,
    SPELL_ARCANE_TETHER_SUMMON_VISUAL           = 204373,
    SPELL_ARCANE_TETHER_VISUAL_CHAIN            = 204529,
    SPELL_ARCANE_TETHER_VISUAL_TENTACLES        = 214977,
    SPELL_FOCUSED_BLAST                         = 204471,
    SPELL_FOCUSED_BLAST_DAMAGE                  = 204483,
    SPELL_CRYSTALLINE_FRAGMENTS                 = 204509,
    SPELL_CRYSTALLINE_FRAGMENTS_AREATRIGGER     = 204306,
    SPELL_BROKEN_SHARD                          = 204284,
    SPELL_LOS_BLOCKER                           = 204289,
    SPELL_EXOSKELETAL_VULNERABILITY             = 204459,
    SPELL_INFUSED_EXOSKELETON                   = 205947,
    SPELL_SHOCKWAVE                             = 204316,
    SPELL_SHROUDED                              = 205900,
    SPELL_ENERGY_SURGE                          = 204766,
    SPELL_BOON_OF_THE_SCORPID                   = 205289,
    SPELL_AVAILABLE                             = 228943,
    SPELL_CALL_OF_THE_SCORPID_PACK_SELECT       = 204371,
    SPELL_CALL_OF_THE_SCORPID_MISSLE            = 204372,
    SPELL_CALL_OF_THE_SCORPID                   = 210172
};

enum SpellVisuals
{
    SPELL_VISUAL_FOCUSED_BLAST_1                = 53760,
    SPELL_VISUAL_FOCUSED_BLAST_2                = 53762,
    SPELL_VISUAL_FOCUSED_BLAST_3                = 53763,
    SPELL_VISUAL_FOCUSED_BLAST_4                = 55185,
    SPELL_VISUAL_FOCUSED_BLAST_5                = 55188,
    SPELL_VISUAL_DESTROY_BY_SHOCKWAVE           = 64699,
};

enum Events
{
    EVENT_ARCANOSLASH                           = 1,
    EVENT_FOCUSED_BLAST                         = 2,
    EVENT_INFUSED_EXOSKELETON                   = 3,
    EVENT_SUMMON_SCORPIDS                       = 4,
    EVENT_ENERGY_SURGE                          = 5,
    EVENT_BOON_OF_THE_SCORPID                   = 6,
    EVENT_CALL_OF_THE_SCORPID                   = 7
};

enum Actions
{
    ACTION_EXOSKELETAL_VULNERABILITY            = 1,
    ACTION_CRYSTALLINE_FRAGMENTS_DESTROY        = 2
};

enum Yells
{
    SAY_FOCUSED_BLAST                           = 0,
    SAY_SHOCKWAVE                               = 1
};

// 102263 - Skorpyron
class boss_skorpyron : public CreatureScript
{
public:
    boss_skorpyron() : CreatureScript("boss_skorpyron") { }

    struct boss_skorpyronAI : public BossAI
    {
        boss_skorpyronAI(Creature* creature) : BossAI(creature, BOSS_SKORPYRON) { }

        void Reset() override
        {
            _Reset();
            summons.DespawnAll();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            DoCastSelf(SPELL_CHITINOUS_EXOSKELETON_VISUAL, true);
            instance->SetData(DATA_CAGE_REMATCH, 0);
            _prevHealthForRemoveStack = 100.0f;
            _calcTime = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->RemoveAura(SPELL_CHITINOUS_EXOSKELETON_VISUAL);
            me->CastCustomSpell(SPELL_CHITINOUS_EXOSKELETON, SPELLVALUE_AURA_STACK, 25, me, TRIGGERED_FULL_MASK);
            DoCastSelf(SPELL_POWER_PERIODIC, true);
            events.ScheduleEvent(EVENT_ARCANOSLASH, 5000);
            events.ScheduleEvent(EVENT_SUMMON_SCORPIDS, 3000);
            events.ScheduleEvent(EVENT_FOCUSED_BLAST, 13000);
            events.ScheduleEvent(EVENT_CALL_OF_THE_SCORPID, 20000);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _DespawnAtEvade();
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetData(DATA_CAGE_REMATCH, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (instance->GetData(DATA_CAGE_REMATCH) == DONE)
                if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(ACHIEVEMENT_CAGE_REMATCH))
                    instance->DoCompletedAchievement(achievementEntry);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            float healthPctDamage = 100.0f * (me->GetHealth() - damage) / me->GetMaxHealth(); // Heath pct after taken damage
            uint8 roundedValue;
            if (!healthPctDamage) // Creature can be dead after taken damage, so, we check this
                return;

            // We must remove 1 stack of Chitinous Exoskeleton for each 1% HP
            // If aura from Chitinous Exoskeleton is absent, then we cast Exoskeletal Vulnerability
            if (me->HealthBelowPctDamaged(_prevHealthForRemoveStack, damage) && !me->HasAura(SPELL_EXOSKELETAL_VULNERABILITY))
                if (Aura* exoskeleton = me->GetAura(SPELL_CHITINOUS_EXOSKELETON))
                {
                    if (_prevHealthForRemoveStack - healthPctDamage >= 1)
                    {
                        roundedValue = _prevHealthForRemoveStack - healthPctDamage;
                        exoskeleton->ModStackAmount(-roundedValue);
                        _prevHealthForRemoveStack -= roundedValue;
                    }
                }
                else
                {
                    if (!me->HasAura(SPELL_CHITINOUS_EXOSKELETON_VISUAL) && me->HealthBelowPctDamaged(99, damage))
                    {
                        events.Reset();
                        DoCastSelf(SPELL_EXOSKELETAL_VULNERABILITY, true);
                        me->CastCustomSpell(SPELL_CHITINOUS_EXOSKELETON, SPELLVALUE_AURA_STACK, 25, me, TRIGGERED_NONE);
                        events.ScheduleEvent(EVENT_INFUSED_EXOSKELETON, 15000);
                        events.ScheduleEvent(EVENT_ARCANOSLASH, 16000);
                        events.ScheduleEvent(EVENT_FOCUSED_BLAST, 19000);
                        events.ScheduleEvent(EVENT_CALL_OF_THE_SCORPID, 29000);
                    }
                }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_EXOSKELETAL_VULNERABILITY:
                Talk(SAY_SHOCKWAVE);
                DoCastAOE(SPELL_SHOCKWAVE);
                break;
            case ACTION_CRYSTALLINE_FRAGMENTS_DESTROY:
            {
                EntryCheckPredicate pred(NPC_CRYSTALLINE_SHARD);
                summons.DoAction(ACTION_CRYSTALLINE_FRAGMENTS_DESTROY, pred);
            }
            default:
                break;
            }
        }

        void JustSummoned(Creature* creature) override
        {
            summons.Summon(creature);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == NPC_CRYSTALLINE_SCORPID)
            {
                auto itr = _scorpidsSummonMap.find(summon->GetGUID());
                if (itr != _scorpidsSummonMap.end())
                {
                    if (auto crystallineScorpid = me->SummonCreature(NPC_CRYSTALLINE_SCORPID, scorpidSpawnPosition, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                    {
                        crystallineScorpid->GetMotionMaster()->MoveSmoothPath(1, itr->second, false);
                        _scorpidsSummonMap[crystallineScorpid->GetGUID()] = itr->second;
                        _scorpidsSummonMap.erase(itr);
                    }
                }
            }
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
                case EVENT_ARCANOSLASH:
                    DoCastSelf(SPELL_ARCANOSLASH_PERIODIC, true);
                    events.ScheduleEvent(EVENT_ARCANOSLASH, 12000);
                    break;
                case EVENT_SUMMON_SCORPIDS:
                    for (auto itr : scorpidsPath)
                    {
                        if (auto crystallineScorpid = me->SummonCreature(NPC_CRYSTALLINE_SCORPID, scorpidSpawnPosition, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                        {
                            ++_calcTime;
                            _scorpidsSummonMap[crystallineScorpid->GetGUID()] = itr;
                            crystallineScorpid->m_Events.AddEvent(new MoveSmoothPathEvent(crystallineScorpid, itr), crystallineScorpid->m_Events.CalculateTime(250 * _calcTime));
                        }
                    }
                    break;
                case EVENT_FOCUSED_BLAST:
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        if (auto crystalTail = me->GetVehicleKit()->GetPassenger(0))
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->SetFacingTo(me->GetAngle(target));
                            DoCast(target, SPELL_FOCUSED_BLAST);
                            Talk(SAY_FOCUSED_BLAST);
                            events.ScheduleEvent(EVENT_FOCUSED_BLAST, 30000);
                            for (uint8 I = 0; I < 24; ++I)
                            {
                                if ((I + 1) % 2 == 0)
                                    me->m_Events.AddEvent(new PlaySpellVisualEvent(me, crystalTail, SPELL_VISUAL_FOCUSED_BLAST_5), me->m_Events.CalculateTime(I * 100));
                                else
                                    me->m_Events.AddEvent(new PlaySpellVisualEvent(me, crystalTail, SPELL_VISUAL_FOCUSED_BLAST_4), me->m_Events.CalculateTime(I * 100));
                            }
                        }
                    break;
                case EVENT_INFUSED_EXOSKELETON:
                    DoCastSelf(SPELL_INFUSED_EXOSKELETON, true);
                    break;
                case EVENT_CALL_OF_THE_SCORPID:
                    DoCastSelf(SPELL_CALL_OF_THE_SCORPID_PACK_SELECT);
                    events.ScheduleEvent(EVENT_CALL_OF_THE_SCORPID, 20000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        std::map<ObjectGuid, Movement::PointsArray> _scorpidsSummonMap;
        float _prevHealthForRemoveStack;
        uint8 _calcTime;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<boss_skorpyronAI>(creature);
    }
};

// 103209 - Crystalline Shard
class npc_crystalline_shard : public CreatureScript
{
public:
    npc_crystalline_shard() : CreatureScript("npc_crystalline_shard") { }

    struct npc_crystalline_shardAI : public ScriptedAI
    {
        npc_crystalline_shardAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* summoner) override
        {
            _ownerGuid = summoner->GetGUID();
            DoCastSelf(SPELL_CRYSTALLINE_FRAGMENTS_AREATRIGGER);
            DoCastSelf(SPELL_LOS_BLOCKER);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->ToPlayer() && who->GetExactDist(me) <= 5.0f && me->HasInArc(static_cast<float>(M_PI), who))
                who->RemoveAura(SPELL_BROKEN_SHARD);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_CRYSTALLINE_FRAGMENTS_DESTROY:
                me->SendPlaySpellVisualKit(SPELL_VISUAL_DESTROY_BY_SHOCKWAVE, 4, 500);
                me->DespawnOrUnsummon(500);
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (Creature* summoner = ObjectAccessor::GetCreature(*me, _ownerGuid))
                me->SetFacingToObject(summoner);
        }

    private:
        ObjectGuid _ownerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_crystalline_shardAI>(creature);
    }
};

// 103682 - Arcane Tether
class npc_arcane_tether : public CreatureScript
{
public:
    npc_arcane_tether() : CreatureScript("npc_arcane_tether") { }

    struct npc_arcane_tetherAI : public ScriptedAI
    {
        npc_arcane_tetherAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* summoner) override
        {
            _ownerGuid = summoner->GetGUID();
            DoCastSelf(SPELL_ARCANE_TETHER_SUMMON_VISUAL);
            DoCastSelf(SPELL_ARCANE_TETHER_PERIODIC);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            auto summoner = ObjectAccessor::GetPlayer(*me, _ownerGuid);
            if (!summoner || !summoner->IsInCombat())
                me->DespawnOrUnsummon();
        }

    private:
        ObjectGuid _ownerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_arcane_tetherAI>(creature);
    }
};

// 103217 - Crystalline Scorpid
class npc_crystalline_scorpid : public CreatureScript
{
public:
    npc_crystalline_scorpid() : CreatureScript("npc_crystalline_scorpid") { }

    struct npc_crystalline_scorpidAI : public ScriptedAI
    {
        npc_crystalline_scorpidAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            DoCastSelf(SPELL_SHROUDED);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->ToPlayer() && who->GetExactDist(me) <= 5.0f && me->HasAura(SPELL_SHROUDED))
            {
                me->RemoveAura(SPELL_SHROUDED);
                AttackStart(who);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ENERGY_SURGE, urand(1000, 4000));
            events.ScheduleEvent(EVENT_BOON_OF_THE_SCORPID, 10000);
        }

        void MovementInform(uint32 /*uiType*/, uint32 uiPointId)
        {
            if (uiPointId == 1)
                DoCastSelf(SPELL_AVAILABLE);
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
                case EVENT_ENERGY_SURGE:
                    DoCastVictim(SPELL_ENERGY_SURGE);
                    events.ScheduleEvent(EVENT_ENERGY_SURGE, urand(4000, 5000));
                    break;
                case EVENT_BOON_OF_THE_SCORPID:
                    DoCastSelf(SPELL_BOON_OF_THE_SCORPID, true);
                    events.ScheduleEvent(EVENT_BOON_OF_THE_SCORPID, 8000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_crystalline_scorpidAI>(creature);
    }
};

// 204277 - Power
// 7.1.5
class spell_skorpyron_power : public SpellScriptLoader
{
public:
    spell_skorpyron_power() : SpellScriptLoader("spell_skorpyron_power") { }

    class spell_skorpyron_power_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skorpyron_power_AuraScript);

        bool Load()
        {
            return GetCaster() && GetCaster()->ToCreature();
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Creature* caster = GetCaster()->ToCreature();
            if (!caster)
                return;

            caster->ModifyPower(POWER_ENERGY, 2);
            if (caster->GetPowerPct(POWER_ENERGY) == 100)
                caster->AI()->DoAction(ACTION_EXOSKELETAL_VULNERABILITY);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_power_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skorpyron_power_AuraScript();
    }
};

// 205200 - Arcanoslash Periodic
// 7.1.5
class spell_skorpyron_arcanoslash_periodic : public SpellScriptLoader
{
public:
    spell_skorpyron_arcanoslash_periodic() : SpellScriptLoader("spell_skorpyron_arcanoslash_periodic") { }

    class spell_skorpyron_arcanoslash_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skorpyron_arcanoslash_periodic_AuraScript);

        bool Load()
        {
            return GetCaster() && GetCaster()->ToCreature();
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                if (Unit* target = caster->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                    caster->CastSpell(target, SPELL_ARCANOSLASH_DAMAGE);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_arcanoslash_periodic_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skorpyron_arcanoslash_periodic_AuraScript();
    }
};

// 204275 - Arcanoslash Damage
// 7.1.5
class spell_skorpyron_arcanoslash_damage : public SpellScriptLoader
{
public:
    spell_skorpyron_arcanoslash_damage() : SpellScriptLoader("spell_skorpyron_arcanoslash_damage") { }

    class spell_skorpyron_arcanoslash_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_arcanoslash_damage_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_ARCANE_TETHER_DEBUFF,
                SPELL_ARCANE_TETHER_SUMMON
            });
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;


            if (target->ToPlayer() && target->ToPlayer()->GetRoleForGroup() == ROLE_TANK)
            {
                target->CastSpell(target, SPELL_ARCANE_TETHER_DEBUFF, true);
                target->CastSpell(target, SPELL_ARCANE_TETHER_SUMMON, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skorpyron_arcanoslash_damage_SpellScript::HandleHitTarget, EFFECT_ALL, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_arcanoslash_damage_SpellScript();
    }
};

// 204531 - Arcane Tether Periodic Damage
// 7.1.5
class spell_skorpyron_arcane_tether_periodic_damage : public SpellScriptLoader
{
public:
    spell_skorpyron_arcane_tether_periodic_damage() : SpellScriptLoader("spell_skorpyron_arcane_tether_periodic_damage") { }

    class spell_skorpyron_arcane_tether_periodic_damage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skorpyron_arcane_tether_periodic_damage_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_ARCANE_TETHER_VISUAL_CHAIN,
                SPELL_ARCANE_TETHER_DAMAGE
            });
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_ARCANE_TETHER_VISUAL_CHAIN))
                caster->CastSpell(caster, SPELL_ARCANE_TETHER_DAMAGE, true);
            else
                Remove();
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_arcane_tether_periodic_damage_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skorpyron_arcane_tether_periodic_damage_AuraScript();
    }
};

// 211659 - Arcane Tether Damage
// 7.1.5
class spell_skorpyron_arcane_tether_damage : public SpellScriptLoader
{
public:
    spell_skorpyron_arcane_tether_damage() : SpellScriptLoader("spell_skorpyron_arcane_tether_damage") { }

    class spell_skorpyron_arcane_tether_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_arcane_tether_damage_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ARCANE_TETHER_DEBUFF });
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Aura* arcaneTether = caster->GetAura(SPELL_ARCANE_TETHER_DEBUFF))
                    SetHitDamage(GetHitDamage() * arcaneTether->GetStackAmount());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skorpyron_arcane_tether_damage_SpellScript::HandleHitTarget, EFFECT_ALL, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_arcane_tether_damage_SpellScript();
    }
};

// 204371 - Call of the Scorpid Pack Select
// 7.1.5
class spell_skorpyron_call_of_the_scorpid_pack_select : public SpellScriptLoader
{
public:
    spell_skorpyron_call_of_the_scorpid_pack_select() : SpellScriptLoader("spell_skorpyron_call_of_the_scorpid_pack_select") { }

    class spell_skorpyron_call_of_the_scorpid_pack_select_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_call_of_the_scorpid_pack_select_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SHROUDED,
                SPELL_AVAILABLE,
                SPELL_CALL_OF_THE_SCORPID_MISSLE,
                SPELL_CALL_OF_THE_SCORPID
            });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            for (auto itr : targets)
                nearestScorpids.push_back(itr);

            targets.remove_if([](WorldObject* obj)
            {
                Creature* scorpid = obj->ToCreature();
                if (!scorpid)
                    return true;

                std::list<Creature*>nearestScorpids;
                scorpid->GetCreatureListWithEntryInGrid(nearestScorpids, NPC_CRYSTALLINE_SCORPID, 30.0f);
                nearestScorpids.remove_if(Trinity::UnitAuraCheck(false, SPELL_AVAILABLE));
                if (nearestScorpids.empty() || nearestScorpids.size() < 5)
                    return true;
                return false;
            });

            if (!targets.empty())
                targets.resize(1);
            else
            {
                for (auto itr : nearestScorpids)
                    targets.push_back(itr);
                packsAbsent = true;
            }
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (!packsAbsent)
                caster->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_CALL_OF_THE_SCORPID_MISSLE, false);
            else
                caster->CastSpell(target, SPELL_CALL_OF_THE_SCORPID);
        }

        std::list<WorldObject*>nearestScorpids;
        bool packsAbsent = false;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skorpyron_call_of_the_scorpid_pack_select_SpellScript::HandleAreaSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_skorpyron_call_of_the_scorpid_pack_select_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_call_of_the_scorpid_pack_select_SpellScript();
    }
};

// 210172 - Call of the Scorpid
// 7.1.5
class spell_skorpyron_call_of_the_scorpid : public SpellScriptLoader
{
public:
    spell_skorpyron_call_of_the_scorpid() : SpellScriptLoader("spell_skorpyron_call_of_the_scorpid") { }

    class spell_skorpyron_call_of_the_scorpid_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_call_of_the_scorpid_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHROUDED });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            if (targets.size() > 5)
                targets.resize(5);
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            target->RemoveAura(SPELL_SHROUDED);
            target->RemoveAura(SPELL_AVAILABLE);
            target->GetMotionMaster()->MovePoint(2, caster->GetPosition(), false);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skorpyron_call_of_the_scorpid_SpellScript::HandleAreaSelect, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_skorpyron_call_of_the_scorpid_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_call_of_the_scorpid_SpellScript();
    }
};

// 214966 - Arcane Tether Periodic Visual
// 7.1.5
class spell_skorpyron_arcane_tether_periodic_visual : public SpellScriptLoader
{
public:
    spell_skorpyron_arcane_tether_periodic_visual() : SpellScriptLoader("spell_skorpyron_arcane_tether_periodic_visual") { }

    class spell_skorpyron_arcane_tether_periodic_visual_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_skorpyron_arcane_tether_periodic_visual_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_ARCANE_TETHER_VISUAL_TENTACLES,
                SPELL_ARCANE_TETHER_VISUAL_CHAIN
            });
        }

        bool Load()
        {
            return GetCaster() && GetCaster()->ToTempSummon();
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            TempSummon* caster = GetCaster()->ToTempSummon();
            if (!caster)
                return;

            if (Unit* summoner = caster->GetSummoner())
                if (summoner->GetExactDist(caster) <= 10.0f)
                {
                    caster->CastSpell(summoner, SPELL_ARCANE_TETHER_VISUAL_TENTACLES, true);
                    caster->CastSpell(summoner, SPELL_ARCANE_TETHER_VISUAL_CHAIN, true);
                }
                else
                {
                    summoner->RemoveAura(SPELL_ARCANE_TETHER_VISUAL_CHAIN);
                    caster->DespawnOrUnsummon();
                }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_skorpyron_arcane_tether_periodic_visual_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_skorpyron_arcane_tether_periodic_visual_AuraScript();
    }
};

enum FocusedBlastData
{
    FOCUSED_BLAST_RIGHT_CELLS = 2,
    FOCUSED_BLAST_LEFT_CELLS  = 4,
    FOCUSED_BLAST_LINES       = 25,
};

class FocusedBlastEvent : public BasicEvent
{
public:
    FocusedBlastEvent(Unit* caster, Position const& position) : 
        _caster(caster), _position(position) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/)
    {
        if (_caster)
        {
            uint32 visual = RAND(SPELL_VISUAL_FOCUSED_BLAST_1, SPELL_VISUAL_FOCUSED_BLAST_2, SPELL_VISUAL_FOCUSED_BLAST_3);
			_caster->SendPlaySpellVisual(_position, 0.f, visual, 0.f, 0.f, 1.0f, false);
        }

        return true;
    }

private:
    Unit* _caster;
    Position _position;
};

// 204471 - Focused Blast
// 7.1.5
class spell_skorpyron_focused_blast : public SpellScriptLoader
{
public:
    spell_skorpyron_focused_blast() : SpellScriptLoader("spell_skorpyron_focused_blast") { }

    class spell_skorpyron_focused_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_focused_blast_SpellScript);

        // Default distance between the lights
        const float _distance = 2.5f;

        uint8  _ticks = 0;
        uint16 _timeout = 0;

        void MovePosition2D(Position& position, float dist, float angle)
        {
            float x = position.GetPositionX() + dist * std::cos(angle);
            float y = position.GetPositionY() + dist * std::sin(angle);

            Trinity::NormalizeMapCoord(x);
            Trinity::NormalizeMapCoord(y);

            position.Relocate(x, y);
        }

        void HandlePlay()
        {
            ++_ticks;
            if (_ticks % 2 == 0)
                _timeout += 12;
        }

        void BlastToRight(Position position)
        {
            Unit* caster = GetCaster();
            for (uint8 cell = 0; cell < FOCUSED_BLAST_RIGHT_CELLS; ++cell)
            {
                HandlePlay();
                MovePosition2D(position, _distance, caster->GetOrientation() - 90.0f);
                caster->m_Events.AddEvent(new FocusedBlastEvent(caster, position), caster->m_Events.CalculateTime(_timeout));
            }
        }

        void BlastToLeft(Position position)
        {
            Unit* caster = GetCaster();
            for (uint8 cell = 0; cell < FOCUSED_BLAST_LEFT_CELLS; ++cell)
            {
                HandlePlay();
                // First cell is placed in front of caster
                float angle = cell == 0 ? 0.0f : 90.0f;

                MovePosition2D(position, _distance, caster->GetOrientation() + angle);
                caster->m_Events.AddEvent(new FocusedBlastEvent(caster, position), caster->m_Events.CalculateTime(_timeout));
            }
        }

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            for (uint8 line = 0; line < FOCUSED_BLAST_LINES; ++line)
            {
                auto pos = caster->GetPosition();
                // Position in sniffs has no orientation
                pos.SetOrientation(0.0f);
                // Set distance for current line
                MovePosition2D(pos, caster->GetObjectSize() + _distance * line, caster->GetOrientation());

                // Safe for position values
                BlastToRight(pos);
                BlastToLeft(pos);
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_skorpyron_focused_blast_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_focused_blast_SpellScript();
    }
};

// 210074 - Shockwave Damage
// 7.1.5
class spell_skorpyron_shockwave_damage : public SpellScriptLoader
{
public:
    spell_skorpyron_shockwave_damage() : SpellScriptLoader("spell_skorpyron_shockwave_damage") { }

    class spell_skorpyron_shockwave_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skorpyron_shockwave_damage_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_BROKEN_SHARD });
        }

        bool Load()
        {
            return GetCaster() && GetCaster()->ToCreature();
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                if (target->HasAura(SPELL_BROKEN_SHARD))
                    PreventHitDamage();
        }

        void HandleCast()
        {
            if (Creature* caster = GetCaster()->ToCreature())
                caster->AI()->DoAction(ACTION_CRYSTALLINE_FRAGMENTS_DESTROY);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skorpyron_shockwave_damage_SpellScript::HandleHitTarget, EFFECT_ALL, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterCast += SpellCastFn(spell_skorpyron_shockwave_damage_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skorpyron_shockwave_damage_SpellScript();
    }
};

// 11250 - Focused Blast
// 7.1.5
class areatrigger_skorpyron_focused_blast : public AreaTriggerEntityScript
{
public:
    areatrigger_skorpyron_focused_blast() : AreaTriggerEntityScript("areatrigger_skorpyron_focused_blast") { }

    struct areatrigger_skorpyron_focused_blastAI : AreaTriggerAI
    {
        areatrigger_skorpyron_focused_blastAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnInitialize() override
        {
            if (Unit* caster = at->GetCaster())
                if (caster->ToCreature())
                    if (caster->ToCreature()->GetReactState() != REACT_AGGRESSIVE)
                        caster->ToCreature()->SetReactState(REACT_AGGRESSIVE);
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            Player* player = unit->ToPlayer();
            if (!caster || !player)
                return;

            caster->CastSpell(player, SPELL_FOCUSED_BLAST_DAMAGE, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_skorpyron_focused_blastAI(areatrigger);
    }
};

// 6197 - Crystalline Shard
// 7.1.5
class areatrigger_skorpyron_crystalline_shard : public AreaTriggerEntityScript
{
public:
    areatrigger_skorpyron_crystalline_shard() : AreaTriggerEntityScript("areatrigger_skorpyron_crystalline_shard") { }

    struct areatrigger_skorpyron_crystalline_shardAI : AreaTriggerAI
    {
        areatrigger_skorpyron_crystalline_shardAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            Player* player = unit->ToPlayer();
            if (!caster || !player)
                return;

            if (!caster->HasInArc(static_cast<float>(M_PI), player, 5.0f))
                caster->AddAura(SPELL_BROKEN_SHARD, player);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAura(SPELL_BROKEN_SHARD);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_skorpyron_crystalline_shardAI(areatrigger);
    }
};

// 32023 - Cage Rematch Achievement
// 7.1.5
class areatrigger_skorpyron_cage_rematch : public AreaTriggerEntityScript
{
public:
    areatrigger_skorpyron_cage_rematch() : AreaTriggerEntityScript("areatrigger_skorpyron_cage_rematch") { }

    struct areatrigger_skorpyron_cage_rematchAI : AreaTriggerAI
    {
        areatrigger_skorpyron_cage_rematchAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnInitialize() override
        {
            _instance = at->GetInstanceScript();
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->ToPlayer() && _instance->GetBossState(BOSS_SKORPYRON) == IN_PROGRESS)
                _instance->SetData(DATA_CAGE_REMATCH, FAIL);
        }

    private:
        InstanceScript* _instance;
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_skorpyron_cage_rematchAI(areatrigger);
    }
};

void AddSC_boss_skorpyron()
{
    new boss_skorpyron();
    new npc_arcane_tether();
    new npc_crystalline_shard();
    new npc_crystalline_scorpid();
    new spell_skorpyron_power();
    new spell_skorpyron_arcanoslash_periodic();
    new spell_skorpyron_arcanoslash_damage();
    new spell_skorpyron_arcane_tether_periodic_damage();
    new spell_skorpyron_arcane_tether_damage();
    new spell_skorpyron_arcane_tether_periodic_visual();
    new spell_skorpyron_call_of_the_scorpid_pack_select();
    new spell_skorpyron_call_of_the_scorpid();
    new spell_skorpyron_focused_blast();
    new spell_skorpyron_shockwave_damage();
    new areatrigger_skorpyron_focused_blast();
    new areatrigger_skorpyron_crystalline_shard();
    new areatrigger_skorpyron_cage_rematch();
}
