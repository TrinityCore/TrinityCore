#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_BLADE_RUSH = 124283,
    SPELL_BLADE_RUSH_CHARGE = 124312,
    SPELL_BLADE_RUSH_SUMMON = 124277,
    SPELL_BLADE_RUSH_DISARM = 124327,
    SPELL_BLADE_RUSH_VISUAL = 124288,
    SPELL_BLADE_RUSH_VISUAL_TWO = 124307,
    SPELL_BLADE_RUSH_DUMMY = 124291,
    SPELL_BLADE_RUSH_DAMAGE_EFFECT = 124290,
    SPELL_BLADE_RUSH_FINAL_DAMAGE = 124317,
    SPELL_BULWARK = 119476,
    SPELL_AURA_PERIODIC_SUMMON_MANTID_SOLDIERS = 119781,
    SPELL_CARRYING_SIEGE_EXPLOSIVE = 119388,
    SPELL_ARMING_VISUAL = 88315,
    SPELL_DETONATE_AFTER_ARM = 119703,
    SPELL_SUMMON_SIEGE_EXPLOSIVE = 119377,
    SPELL_TEMPEST = 119875,
};

enum Events
{
    EVENT_CAST_BLADE_RUSH = 1,
    EVENT_CHARGE_AT_BLADE_RUSH_POS,
    EVENT_DO_CHARGE_DAMAGE_EFFECT,
    EVENT_START_ATTACKING_AGAIN,
    EVENT_CALL_REINFORCEMENTS,
    EVENT_STOP_BULWARK,
    EVENT_ARM_BOMB,
    EVENT_SIEGE_EXPLOSIVE_DETONATE,
    EVENT_SUMMON_SIEGE_EXPLOSIVE,
    EVENT_REPOSITION_EXPLOSIVE,
    EVENT_CAST_TEMPEST,
};

enum Actions
{
    ACTION_DELAYED_CAST_BLADE_RUSH_AT_TRIGGER = 1,
    ACTION_GENERAL_PAVALAK_BULWARK_REMOVED,
};

enum Points
{
    POINT_GENERAL_PAVALAK_CALL_IN_REINFORCEMENTS = 1,
    POINT_SIKTHIK_MOVE_TO_FIGHTZONE,
};

enum Misc
{
    NPC_BLADE_RUSH = 63720,
};

class boss_general_pavalak : public CreatureScript
{
public:
    boss_general_pavalak() : CreatureScript("boss_general_pavalak") { }

    struct boss_general_pavalakAI : public BossAI
    {
        boss_general_pavalakAI(Creature* creature) : BossAI(creature, 0) { }

        bool calledReinforcements65, calledReinforcements35, movingToReinforcementSpot;

        void Reset()
        {
            _Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            //me->GetMotionMaster()->MoveRandom(15.0f);

            calledReinforcements65 = false;
            calledReinforcements35 = false;
            movingToReinforcementSpot = false;
        }

        void JustRespawned()
        {
            Reset();
        }

        void EnterCombat(Unit* who)
        {
            _EnterCombat();

            Talk(0, who);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_CAST_BLADE_RUSH, urand(8000, 12000));
            events.ScheduleEvent(EVENT_CAST_TEMPEST, urand(15000, 19000));

        }

        void JustDied(Unit* killer)
        {
            _JustDied();

            Talk(5, killer);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            if (!calledReinforcements65 && !HealthAbovePct(65))
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                calledReinforcements65 = true;
                CallInReinforcements();
            }
            else if (!calledReinforcements35 && !HealthAbovePct(35))
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                calledReinforcements35 = true;
                CallInReinforcements();
            }
        }

        void CallInReinforcements()
        {
            Talk(3);
            //me->SetReactState(REACT_PASSIVE);
            me->CastStop();
            movingToReinforcementSpot = true;
            me->GetMotionMaster()->MovePoint(POINT_GENERAL_PAVALAK_CALL_IN_REINFORCEMENTS, 1712.538f, 5242.658f, 124.3957f);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            if (pointId == POINT_GENERAL_PAVALAK_CALL_IN_REINFORCEMENTS)
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                movingToReinforcementSpot = false;
                me->AddAura(SPELL_BULWARK, me);
                //me->SetControlled(true, UNIT_STATE_STUNNED);
                events.CancelEvent(EVENT_CAST_BLADE_RUSH);
                events.CancelEvent(EVENT_CAST_TEMPEST);
                events.ScheduleEvent(EVENT_CALL_REINFORCEMENTS, 500);
            }
            //! Charge
            else if (pointId == 1003)
            {
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                events.ScheduleEvent(EVENT_DO_CHARGE_DAMAGE_EFFECT, 250);
            }
        }

        void JustReachedHome()
        {
            summons.DespawnAll();

        }

        void JustSummoned(Creature* summoned)
        {
            summons.Summon(summoned);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_DELAYED_CAST_BLADE_RUSH_AT_TRIGGER:
                //events.ScheduleEvent(EVENT_CHARGE_AT_BLADE_RUSH_POS, 750);
                break;
            case ACTION_GENERAL_PAVALAK_BULWARK_REMOVED:
                StopBulwark();
                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            //FREAKZ_CheckBossOrder(me, diff);

            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING) || movingToReinforcementSpot)// || me->HasAura(SPELL_BLADE_RUSH_DISARM))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_BLADE_RUSH:
                    //me->SetReactState(REACT_PASSIVE);
                    DoCast(me, SPELL_BLADE_RUSH_SUMMON);
                    events.ScheduleEvent(EVENT_CAST_BLADE_RUSH, urand(9000, 19000) + 1250);
                    events.ScheduleEvent(EVENT_CHARGE_AT_BLADE_RUSH_POS, 1250);
                    break;
                case EVENT_CAST_TEMPEST:
                    me->CastSpell(me, SPELL_TEMPEST, false);
                    events.ScheduleEvent(EVENT_CAST_TEMPEST, urand(15000, 19000));
                    break;
                case EVENT_CHARGE_AT_BLADE_RUSH_POS:
                    if (Creature* bladerush = me->FindNearestCreature(NPC_BLADE_RUSH, 100.0f))
                    {
                        bladerush->AddAura(SPELL_BLADE_RUSH_VISUAL_TWO, bladerush);
                        me->CastSpell(bladerush->GetPositionX(), bladerush->GetPositionY(), bladerush->GetPositionZ(), SPELL_BLADE_RUSH_CHARGE, false);
                    }

                    break;
                case EVENT_DO_CHARGE_DAMAGE_EFFECT:
                    if (Creature* bladerush = me->FindNearestCreature(NPC_BLADE_RUSH, 150.0f))
                    {
                        me->CastSpell(bladerush, SPELL_BLADE_RUSH_FINAL_DAMAGE, false);
                        bladerush->DespawnOrUnsummon(500);
                    }

                    events.ScheduleEvent(EVENT_START_ATTACKING_AGAIN, 1000);
                    break;
                case EVENT_START_ATTACKING_AGAIN:
                    AttackStart(me->GetVictim());
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveAurasDueToSpell(SPELL_BLADE_RUSH_DISARM);
                    break;
                case EVENT_CALL_REINFORCEMENTS:
                    Talk(4);
                    events.ScheduleEvent(EVENT_SUMMON_SIEGE_EXPLOSIVE, 1500);
                    events.ScheduleEvent(EVENT_STOP_BULWARK, 60500); //! From videos
                    //events.ScheduleEvent(0, 0);
                    break;
                case EVENT_STOP_BULWARK:
                    StopBulwark();
                    break;
                case EVENT_SUMMON_SIEGE_EXPLOSIVE:
                    me->CastSpell(me, SPELL_SUMMON_SIEGE_EXPLOSIVE, false);
                    events.ScheduleEvent(EVENT_SUMMON_SIEGE_EXPLOSIVE, urand(750, 2000));
                    break;
                }
            }

            if (!me->HasAura(SPELL_BULWARK))
                DoMeleeAttackIfReady();
        }

        void StopBulwark()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            AttackStart(me->SelectNearestPlayer(150.0f));
            me->GetMotionMaster()->MoveChase(me->GetVictim());
            //me->SetControlled(false, UNIT_STATE_STUNNED);
            me->RemoveAurasDueToSpell(SPELL_BULWARK);
            events.CancelEvent(EVENT_STOP_BULWARK);
            events.CancelEvent(EVENT_SUMMON_SIEGE_EXPLOSIVE);
            events.ScheduleEvent(EVENT_CAST_BLADE_RUSH, urand(17000, 25000));
            events.ScheduleEvent(EVENT_CAST_TEMPEST, urand(15000, 19000));
        }

        bool CheckInRoom()
        {
            if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 150.0f)
            {
                EnterEvadeMode();
                return false;
            }

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_general_pavalakAI(creature);
    }
};

class npc_general_pavalak_blade_rush : public CreatureScript
{
public:
    npc_general_pavalak_blade_rush() : CreatureScript("npc_general_pavalak_blade_rush") { }

    struct npc_general_pavalak_blade_rushAI : public ScriptedAI
    {
        npc_general_pavalak_blade_rushAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddAura(SPELL_BLADE_RUSH_VISUAL, me);
            //me->AddAura(SPELL_BLADE_RUSH_VISUAL_TWO, me);

            if (Creature* pavalak = me->FindNearestCreature(61485, 150.0f))
                pavalak->AI()->DoAction(ACTION_DELAYED_CAST_BLADE_RUSH_AT_TRIGGER);

            //me->DespawnOrUnsummon(2250);
        }

        void JustRespawned()
        {
            Reset();
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell && spell->Id == SPELL_BLADE_RUSH_DUMMY)
            {
                me->AddAura(SPELL_BLADE_RUSH_VISUAL_TWO, me);
                me->CastSpell(me, SPELL_BLADE_RUSH_DAMAGE_EFFECT, false);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_general_pavalak_blade_rushAI(creature);
    }
};

class npc_general_pavalak_reinforcement_summoner : public CreatureScript
{
public:
    npc_general_pavalak_reinforcement_summoner() : CreatureScript("npc_general_pavalak_reinforcement_summoner") { }

    struct npc_general_pavalak_reinforcement_summonerAI : public ScriptedAI
    {
        npc_general_pavalak_reinforcement_summonerAI(Creature* creature) : ScriptedAI(creature), summons(creature)
        {
            creature->setActive(true);
        }

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void JustRespawned()
        {
            Reset();
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void JustSummoned(Creature* summoned)
        {
            summons.Summon(summoned);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case SPECIAL:
                me->AddAura(SPELL_AURA_PERIODIC_SUMMON_MANTID_SOLDIERS, me);
                break;
            case FAIL:
            case DONE:
                summons.DespawnAll();
                //! No break
            case NOT_STARTED:
            default:
                me->RemoveAurasDueToSpell(SPELL_AURA_PERIODIC_SUMMON_MANTID_SOLDIERS);
                break;
            }
        }

    private:
        SummonList summons;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_general_pavalak_reinforcement_summonerAI(creature);
    }
};

class npc_general_pavalak_siege_explosive : public CreatureScript
{
public:
    npc_general_pavalak_siege_explosive() : CreatureScript("npc_general_pavalak_siege_explosive") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->CastSpell(player, SPELL_CARRYING_SIEGE_EXPLOSIVE, false);
        //player->AddTemporarySpell();
        creature->DespawnOrUnsummon();
        return true;
    }

    struct npc_general_pavalak_siege_explosiveAI : public ScriptedAI
    {
        npc_general_pavalak_siege_explosiveAI(Creature* creature) : ScriptedAI(creature) { }

        bool armed;

        void Reset()
        {
            me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 30.0f, me->GetOrientation());
            events.ScheduleEvent(EVENT_REPOSITION_EXPLOSIVE, 500);
            events.ScheduleEvent(EVENT_ARM_BOMB, 6000);
            me->SetReactState(REACT_PASSIVE);
        }

        void JustRespawned()
        {
            Reset();
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void OnSpellClick(Unit* clicker, bool& result)
        {
            me->DespawnOrUnsummon();
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            Reset();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_ARM_BOMB:
                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, SPELL_ARMING_VISUAL, false);
                events.ScheduleEvent(EVENT_SIEGE_EXPLOSIVE_DETONATE, 3000);
                break;
            case EVENT_SIEGE_EXPLOSIVE_DETONATE:
                me->CastSpell(me, SPELL_DETONATE_AFTER_ARM, false);
                me->DespawnOrUnsummon(500);
                break;
            case EVENT_REPOSITION_EXPLOSIVE:
                me->SetCanFly(false);
                float myZ = me->GetPositionZ();
               // float mapZ = me->GetMap()->GetWaterOrGroundLevel(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), &myZ);
                me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), false);
                break;
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_general_pavalak_siege_explosiveAI(creature);
    }
};

class npc_general_pavalak_sikthik_soldier : public CreatureScript
{
public:
    npc_general_pavalak_sikthik_soldier() : CreatureScript("npc_general_pavalak_sikthik_soldier") { }

    struct npc_general_pavalak_sikthik_soldierAI : public ScriptedAI
    {
        npc_general_pavalak_sikthik_soldierAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->setActive(true);
        }

        void Reset()
        {
            //me->SetReactState(REACT_PASSIVE);
        }

        void JustRespawned()
        {
            //me->SetReactState(REACT_PASSIVE);
        }

        void IsSummonedBy(Unit* /*summoner*/)
        {
            //me->SetReactState(REACT_PASSIVE);
            me->SetInCombatWithZone();
            me->GetMotionMaster()->MovePoint(POINT_SIKTHIK_MOVE_TO_FIGHTZONE, 1713.696f, 5252.163f, 124.6241f);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            if (pointId == POINT_SIKTHIK_MOVE_TO_FIGHTZONE)
            {
                //me->SetReactState(REACT_AGGRESSIVE);
                //AttackStart(me->SelectNearestPlayer(100.0f));
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            //switch (events.ExecuteEvent())
            //{
            //}

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_general_pavalak_sikthik_soldierAI(creature);
    }
};

class BladeRushTargetSelector
{
public:
    BladeRushTargetSelector() { }

    bool operator()(WorldObject* object)
    {
        return !object || object->GetTypeId() != TYPEID_PLAYER;
    }
};

class spell_general_pavalak_blade_rush_target_selector : public SpellScriptLoader
{
public:
    spell_general_pavalak_blade_rush_target_selector() : SpellScriptLoader("spell_general_pavalak_blade_rush_target_selector") { }

    class spell_general_pavalak_blade_rush_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_general_pavalak_blade_rush_target_selector_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(BladeRushTargetSelector());
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_general_pavalak_blade_rush_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_general_pavalak_blade_rush_target_selector_SpellScript();
    }
};

class spell_general_pavalak_blade_rush_summon_effect : public SpellScriptLoader
{
public:
    spell_general_pavalak_blade_rush_summon_effect() : SpellScriptLoader("spell_general_pavalak_blade_rush_summon_effect") { }

    class spell_general_pavalak_blade_rush_summon_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_general_pavalak_blade_rush_summon_effect_SpellScript);

        void HandleSummon(SpellEffIndex /*effIndex*/)
        {
            WorldLocation const* loc = GetExplTargetDest();

            if (Unit* caster = GetCaster())
                if (Creature* pavalak = caster->FindNearestCreature(61485, 150.0f))
                    pavalak->CastSpell(loc->GetPositionX(), loc->GetPositionY(), loc->GetPositionZ(), SPELL_BLADE_RUSH, false);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_general_pavalak_blade_rush_summon_effect_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_general_pavalak_blade_rush_summon_effect_SpellScript();
    }
};

class spell_general_pavalak_blade_rush_charge_effect : public SpellScriptLoader
{
public:
    spell_general_pavalak_blade_rush_charge_effect() : SpellScriptLoader("spell_general_pavalak_blade_rush_charge_effect") { }

    class spell_general_pavalak_blade_rush_charge_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_general_pavalak_blade_rush_charge_effect_SpellScript);

        void HandleCharge(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            WorldLocation const* loc = GetExplTargetDest();

            if (Unit* caster = GetCaster())
            {
                //if (Creature* bladerush = caster->FindNearestCreature(NPC_BLADE_RUSH, 150.0f))
                //    caster->CastSpell(bladerush, SPELL_BLADE_RUSH_FINAL_DAMAGE, false);
                float dist = 3.0f;
                float x = loc->GetPositionX() + (dist * cos(caster->GetOrientation()));
                float y = loc->GetPositionY() + (dist * sin(caster->GetOrientation()));
                caster->GetMotionMaster()->MoveCharge(x, y, loc->GetPositionZ());
            }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_general_pavalak_blade_rush_charge_effect_SpellScript::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE_DEST);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_general_pavalak_blade_rush_charge_effect_SpellScript();
    }
};

class spell_general_pavalak_siege_explosive_summon_effect : public SpellScriptLoader
{
public:
    spell_general_pavalak_siege_explosive_summon_effect() : SpellScriptLoader("spell_general_pavalak_siege_explosive_summon_effect") { }

    class spell_general_pavalak_siege_explosive_summon_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_general_pavalak_siege_explosive_summon_effect_SpellScript);

        void HandleSummon(SpellEffIndex /*effIndex*/)
        {
            Position offset = { 0.0f, 0.0f, 30.0f, 0.0f };
            const_cast<WorldLocation*>(GetExplTargetDest())->RelocateOffset(offset);
            GetHitDest()->RelocateOffset(offset);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_general_pavalak_siege_explosive_summon_effect_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_general_pavalak_siege_explosive_summon_effect_SpellScript();
    }
};

class spell_general_pavalak_siege_explosive_trigger_effect : public SpellScriptLoader
{
public:
    spell_general_pavalak_siege_explosive_trigger_effect() : SpellScriptLoader("spell_general_pavalak_siege_explosive_trigger_effect") { }

    class spell_general_pavalak_siege_explosive_trigger_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_general_pavalak_siege_explosive_trigger_effect_SpellScript);

        void CheckTarget(SpellEffIndex effIndex)
        {
            if (Unit* caster = GetCaster())
                caster->RemoveAurasDueToSpell(119393);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_general_pavalak_siege_explosive_trigger_effect_SpellScript::CheckTarget, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_general_pavalak_siege_explosive_trigger_effect_SpellScript();
    }
};


class spell_general_pavalak_bulwark : public SpellScriptLoader     // 63120
{
public:
    spell_general_pavalak_bulwark() : SpellScriptLoader("spell_general_pavalak_bulwark") { }

    class spell_general_pavalak_bulwark_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_general_pavalak_bulwark_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature() && caster->ToCreature()->AI())
                    caster->ToCreature()->AI()->DoAction(ACTION_GENERAL_PAVALAK_BULWARK_REMOVED);
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_general_pavalak_bulwark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_AOE_CHARM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_general_pavalak_bulwark_AuraScript();
    }
};

void AddSC_boss_general_pavalak()
{
    new boss_general_pavalak();

    new npc_general_pavalak_blade_rush();
    new npc_general_pavalak_reinforcement_summoner();
    new npc_general_pavalak_siege_explosive();
    new npc_general_pavalak_sikthik_soldier();

    new spell_general_pavalak_blade_rush_target_selector();
    new spell_general_pavalak_blade_rush_summon_effect();
    new spell_general_pavalak_blade_rush_charge_effect();
    new spell_general_pavalak_siege_explosive_summon_effect();
    new spell_general_pavalak_siege_explosive_trigger_effect();
    new spell_general_pavalak_bulwark();
}
