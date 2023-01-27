#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "shrine_of_the_storm.h"

enum Spells
{
    SPELL_SEA_BLAST = 265001,
    SPELL_CHOKING_BRINE = 264560,
    SPELL_CHOKING_BRINE_MISSILE_SINGLE = 264714,
    SPELL_CHOKING_BRINE_MISSILE_MULTI = 264703,
    SPELL_SURGING_RUSH = 264101,
    SPELL_UNDERTOW = 264144,
    SPELL_GRASP_FROM_THE_DEPTHS = 264477,
    SPELL_GRASP_FROM_THE_DEPTHS_SUMMON = 264522,
    SPELL_GRASP_FROM_THE_DEPTHS_ROOT = 264526,

    SPELL_ERUPTING_WATER = 264903,
    SPELL_DIMINISH = 264899,

    SPELL_EMERGE_VISUAL = 274948,
};

enum Creatures
{
    BOSS_AQUSIRR = 134056,

    NPC_AQUALING = 134828,
    NPC_GRASPING_TENTACLES = 134612,
};

enum Events
{
    EVENT_SEA_BLAST_CHECK = 1,
    EVENT_SURGING_RUSH,
    EVENT_UNDERTOW,
    EVENT_CHOKING_BRINE,

    EVENT_GRASPING_TENTACLES,

    EVENT_SEA_BLAST_CAST,
};
enum Timers
{
    TIMER_SEA_BLAST_CHECK = 2 * IN_MILLISECONDS,
    TIMER_CHOKING_BRINE = 11 * IN_MILLISECONDS,
    TIMER_UNDERTOW = 30 * IN_MILLISECONDS,
    TIMER_SURGING_RUSH = 17 * IN_MILLISECONDS,

    TIMER_GRASPING_TENTACLES = 15 * IN_MILLISECONDS,

    TIMER_SEA_BLAST_CAST = 2 * IN_MILLISECONDS, //adds
};

#define ROOT me->AddUnitState(UNIT_STATE_ROOT)
#define REMOVE_ROOT me->ClearUnitState(UNIT_STATE_ROOT)

const Position centerPlatform = { 3931.72f, -1244.48f, 128.45f }; //also cheaters check 30y

// movement force
class bfa_boss_aqusirr : public CreatureScript
{
public:
    bfa_boss_aqusirr() : CreatureScript("bfa_boss_aqusirr")
    {
    }

    struct bfa_boss_aqusirr_AI : public BossAI
    {
        bfa_boss_aqusirr_AI(Creature* creature) : BossAI(creature, DATA_AQUSIRR), summons(me)
        {
            instance = me->GetInstanceScript();
            ROOT;
        }

        InstanceScript* instance;
        EventMap events;
        SummonList summons;
        bool splitPhase2;
        uint8 addsDead;
        bool cannotAttack;

        void Reset() override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            summons.DespawnAll();
            events.Reset();
            REMOVE_ROOT;
            splitPhase2 = false;
            cannotAttack = false;
            me->NearTeleportTo(me->GetHomePosition());
            addsDead = 0;
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            _DespawnAtEvade(15);
            Reset();
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer)
        {
            switch (summon->GetEntry())
            {
            case NPC_AQUALING:
            {
                ++addsDead;
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);

                if (addsDead >= 3)
                    ReturnCombat();
                break;
            }
            }
        }

        void ReturnCombat()
        {
            me->RemoveAura(SPELL_ERUPTING_WATER);
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            HandleNormalEvents();
            me->SetHealth(me->CountPctFromMaxHealth(15));
        }

        void JustDied(Unit*)
        {
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }
        
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_AQUALING:
                summon->SetInCombatWithZone();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
                break;
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (me->HealthBelowPct(50) && !splitPhase2)
            {
                splitPhase2 = true;
                cannotAttack = true;
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SummonCreature(NPC_AQUALING, 3939.58f, -1221.45f, 128.424f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(NPC_AQUALING, 3954.12f, -1250.46f, 127.809f, TEMPSUMMON_CORPSE_DESPAWN);
                me->SummonCreature(NPC_AQUALING, 3920.58f, -1258.02f, 128.144f, TEMPSUMMON_CORPSE_DESPAWN);
                events.Reset();
            }
        }

        void EnterCombat(Unit*)
        {
            ROOT;
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            HandleNormalEvents();
        }

        void HandleNormalEvents()
        {
            cannotAttack = false;
            events.ScheduleEvent(EVENT_SEA_BLAST_CHECK, TIMER_SEA_BLAST_CHECK);
            events.ScheduleEvent(EVENT_UNDERTOW, TIMER_UNDERTOW);
            events.ScheduleEvent(EVENT_CHOKING_BRINE, TIMER_CHOKING_BRINE);
            events.ScheduleEvent(EVENT_SURGING_RUSH, TIMER_SURGING_RUSH);

            if (me->GetMap()->IsHeroic() && me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_GRASPING_TENTACLES, TIMER_GRASPING_TENTACLES);
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(centerPlatform.GetPositionX(), centerPlatform.GetPositionY(), centerPlatform.GetPositionZ()) >= 30.0f ||
                            me->GetDistance(centerPlatform.GetPositionX(), centerPlatform.GetPositionY(), centerPlatform.GetPositionZ()) >= 30.0f) // all posibility
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_SURGING_RUSH:
            {
                me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
                    {
                        me->RestoreDisplayId();
                    });
                break;
            }
            }
        }

        void SelectRushPoint()
        {
            events.DelayEvents(5 * IN_MILLISECONDS);

            me->CastSpell(me, SPELL_SURGING_RUSH);

            me->GetScheduler().Schedule(4s, [this](TaskContext /*context*/)
                {
                    float x;
                    float y;
                    float z = me->GetPositionZ();

                    switch (rand() % 5)
                    {
                    case 0:
                        x = 3929.14f;
                        y = -1262.38f;
                        break;
                    case 1:
                        x = 3931.14f;
                        y = -1224.62f;
                        break;
                    case 2:
                        x = 3953.22f;
                        y = -1239.37f;
                        break;
                    case 3:
                        x = 3939.73f;
                        y = -1261.44f;
                        break;
                    case 4:
                        x = 3915.98f;
                        y = -1236.37f;
                        break;
                    }


                    me->GetMotionMaster()->MoveCharge(x, y, me->GetPositionZ());
                    //me->CastSpell(me, SPELL_EMERGE_VISUAL, true);
                    ROOT;
                });

        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->IsInCombat())
                CheckCheaters();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SEA_BLAST_CHECK:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        me->CastSpell(me->GetVictim(), SPELL_SEA_BLAST);

                    events.ScheduleEvent(EVENT_SEA_BLAST_CHECK, TIMER_SEA_BLAST_CHECK);
                    break;
                case EVENT_SURGING_RUSH:
                    SelectRushPoint();
                    REMOVE_ROOT;
                    events.ScheduleEvent(EVENT_SURGING_RUSH, TIMER_SURGING_RUSH);
                    break;
                case EVENT_UNDERTOW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                        me->CastSpell(target, SPELL_UNDERTOW);
                    events.ScheduleEvent(EVENT_UNDERTOW, TIMER_UNDERTOW);
                    break;
                case EVENT_CHOKING_BRINE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                        me->CastSpell(target, SPELL_CHOKING_BRINE);
                    break;
                case EVENT_GRASPING_TENTACLES:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                    {
                        me->CastSpell(target, SPELL_GRASP_FROM_THE_DEPTHS);
                        me->AddAura(SPELL_GRASP_FROM_THE_DEPTHS_ROOT, target);
                    }
                    break;
                }
            }
            if (!cannotAttack)
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_aqusirr_AI(creature);
    }
};


class bfa_npc_aqualing : public CreatureScript
{
public:
    bfa_npc_aqualing() : CreatureScript("bfa_npc_aqualing")
    {
    }

    struct bfa_npc_aqualing_AI : public ScriptedAI
    {
        bfa_npc_aqualing_AI(Creature* creature) : ScriptedAI(creature)
        {
            ROOT;
            me->AddAura(SPELL_DIMINISH);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_SEA_BLAST_CAST, TIMER_SEA_BLAST_CAST);
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
                case EVENT_SEA_BLAST_CAST:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        me->CastSpell(me->GetVictim(), SPELL_SEA_BLAST);
                    events.ScheduleEvent(EVENT_SEA_BLAST_CAST, TIMER_SEA_BLAST_CAST);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_aqualing_AI(creature);
    }

};

class bfa_npc_grasping_tentacle : public CreatureScript
{
public:
    bfa_npc_grasping_tentacle() : CreatureScript("bfa_npc_grasping_tentacle")
    {
    }

    struct bfa_npc_grasping_tentacle_AI : public ScriptedAI
    {
        bfa_npc_grasping_tentacle_AI(Creature* creature) : ScriptedAI(creature)
        {
            ROOT;
        }

        void JustDied(Unit*)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->HasAura(SPELL_GRASP_FROM_THE_DEPTHS_ROOT))
                            player->RemoveAura(SPELL_GRASP_FROM_THE_DEPTHS_ROOT);
                    }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_grasping_tentacle_AI(creature);
    }
};

// 264560 
class bfa_spell_choking_brine : public SpellScriptLoader
{
public:
    bfa_spell_choking_brine() : SpellScriptLoader("bfa_spell_choking_brine")
    {}

    class bfa_spell_choking_brine_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(bfa_spell_choking_brine_AuraScript);

        void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            if (!GetUnitOwner())
                return;

            Unit* owner = GetUnitOwner();
            AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

            if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL)
            {
                for (uint8 i = 0; i < 5; ++i)
                    owner->CastSpell(owner, SPELL_CHOKING_BRINE_MISSILE_MULTI, true);
            }
        }
        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_choking_brine_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_choking_brine_AuraScript();
    }
};

// 264144
class bfa_spell_undertow : public SpellScriptLoader
{
public:
    bfa_spell_undertow() : SpellScriptLoader("bfa_spell_undertow") { }

    class bfa_spell_undertow_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_undertow_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();

            if (!caster || !target)
                return;

            target->ApplyMovementForce(caster->GetGUID(), caster->GetPosition(), -5.0f, 0);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();

            if (!caster || !target)
                return;

            target->RemoveMovementForce(caster->GetGUID());
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_undertow_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_undertow_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_undertow_AuraScript();
    }
};

//264477
class bfa_spell_grasp_from_the_depths : public SpellScriptLoader
{
public:
    bfa_spell_grasp_from_the_depths() : SpellScriptLoader("bfa_spell_grasp_from_the_depths")
    {}

    class bfa_spell_grasp_from_the_depths_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(bfa_spell_grasp_from_the_depths_SpellScript);

        void HandleOnHitTarget(SpellEffIndex /* effIndex */)
        {
            if (Unit* target = GetHitUnit())
                target->CastSpell(target, SPELL_GRASP_FROM_THE_DEPTHS_SUMMON, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_grasp_from_the_depths_SpellScript::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_grasp_from_the_depths_SpellScript();
    }
};

void AddSC_boss_aqusirr()
{
    new bfa_boss_aqusirr();
    new bfa_npc_aqualing();
    new bfa_npc_grasping_tentacle();

    new bfa_spell_undertow();
    new bfa_spell_grasp_from_the_depths();
    new bfa_spell_choking_brine();
}
