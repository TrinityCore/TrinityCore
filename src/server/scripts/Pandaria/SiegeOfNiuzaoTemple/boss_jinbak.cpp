#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Spells
{
    SPELL_SAP_PUDDLE_GROW = 120865,
    SPELL_SAP_PUDDLE_VISUAL = 119939,
    SPELL_COSMETIC_SHIELD_AURA = 131628,
    SPELL_DETONATE_DAMAGE = 120002,
    SPELL_DETONATE_VISUAL_OOC = 120095,
    SPELL_DETONATE = 120001,
    SPELL_DELAYED_SUMMON_SAPPLING = 119990,
    SPELL_SUMMON_SAPPLING_VISUAL_PRE_EFFECT = 120071,
};

enum Events
{
    EVENT_SAP_PUDDLE_CAST_GROW = 1,
    EVENT_VINZIER_JINBAK_CAST_DETONATE,
    EVENT_VINZIER_JINBAK_SUMMON_SAP_GLOBULES,
};

enum Actions
{
    ACTION_SAP_PUDDLE_START_GROWING = 1,
    ACTION_SAP_PUDDLE_STOP_GROWING,
    ACTION_SAP_PUDDLE_EXPLODE,
    ACTION_SAP_PUDDLE_DOUBLE_IN_SIZE,
};

enum Misc
{
    NPC_SAP_PUDDLE = 61613,
};

enum Points
{
    POINT_SAP_GLOBULE_MOVE_TO_CENTER = 1,
};

//Position CenterPos = { 1529.52f, 5163.24f, 160.57f, 0.0f };

class boss_vizier_jinbak : public CreatureScript
{
public:
    boss_vizier_jinbak() : CreatureScript("boss_vizier_jinbak") { }

    struct boss_vizier_jinbakAI : public BossAI
    {
        boss_vizier_jinbakAI(Creature* creature) : BossAI(creature, 0) { }

        void Reset()
        {
            _Reset();
            summons.DespawnAll();

            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f))
                puddle->AI()->DoAction(ACTION_SAP_PUDDLE_STOP_GROWING);
        }

        void EnterCombat(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
            {
                EnterEvadeMode();
                return;
            }

            _EnterCombat();

            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            //me->InterruptNonMeleeSpells(true);
            me->CastStop();

            Talk(1, who);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_VINZIER_JINBAK_CAST_DETONATE, urand(20000, 25000));
            events.ScheduleEvent(EVENT_VINZIER_JINBAK_SUMMON_SAP_GLOBULES, urand(11000, 30000));


            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f))
                puddle->AI()->DoAction(ACTION_SAP_PUDDLE_START_GROWING);

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(120938); // Residue @ trash, high damag buff
        }

        void JustDied(Unit* killer)
        {
            _JustDied();

            Talk(5, killer);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);


            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f))
            {
                puddle->AI()->DoAction(ACTION_SAP_PUDDLE_STOP_GROWING);
                puddle->RemoveAurasDueToSpell(SPELL_SAP_PUDDLE_GROW);
                //puddle->RemoveAllAuras();
            }
        }

        void InitializeAI()
        {
            StartVisualOOC();
        }

        void KilledUnit(Unit* victim)
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(3, victim);
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {

        }

        void JustReachedHome()
        {
            summons.DespawnAll();


            StartVisualOOC();
        }

        void StartVisualOOC()
        {
            if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 100.0f))
            {
                puddle->AI()->DoAction(ACTION_SAP_PUDDLE_STOP_GROWING);
                //me->InterruptNonMeleeSpells(true);
                me->CastStop();
                me->CastSpell(puddle, SPELL_DETONATE_VISUAL_OOC, false);
                me->SetFacingToObject(puddle);
            }
        }

        void JustSummoned(Creature* summoned)
        {
            summons.Summon(summoned);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case EVENT_VINZIER_JINBAK_CAST_DETONATE:
                if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 150.0f))
                {
                    me->CastSpell(puddle, SPELL_DETONATE, false);
                    me->SetFacingToObject(puddle);
                }

                Talk(3);
                Talk(4);
                events.ScheduleEvent(EVENT_VINZIER_JINBAK_CAST_DETONATE, urand(26000, 31000));
                break;
            case EVENT_VINZIER_JINBAK_SUMMON_SAP_GLOBULES:
                Talk(2);
                me->CastSpell(me, SPELL_DELAYED_SUMMON_SAPPLING, false);
                events.ScheduleEvent(EVENT_VINZIER_JINBAK_SUMMON_SAP_GLOBULES, urand(41000, 52000));
                break;
            }

            DoMeleeAttackIfReady();
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
        return new boss_vizier_jinbakAI(creature);
    }
};

class npc_vizier_jinbak_sap_puddle : public CreatureScript
{
public:
    npc_vizier_jinbak_sap_puddle() : CreatureScript("npc_vizier_jinbak_sap_puddle") {}

    struct npc_vizier_jinbak_sap_puddleAI : public ScriptedAI
    {
        npc_vizier_jinbak_sap_puddleAI(Creature* creature) : ScriptedAI(creature) { }

        bool playerInPuddle;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetControlled(true, UNIT_STATE_ROOT);

            me->AddAura(SPELL_SAP_PUDDLE_VISUAL, me);
            me->AddAura(SPELL_COSMETIC_SHIELD_AURA, me);

            playerInPuddle = false;
        }

        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_SAP_PUDDLE_START_GROWING:
                me->AddAura(SPELL_SAP_PUDDLE_VISUAL, me);
                events.ScheduleEvent(EVENT_SAP_PUDDLE_CAST_GROW, 1000);
                me->RemoveAurasDueToSpell(SPELL_COSMETIC_SHIELD_AURA);
                break;
            case ACTION_SAP_PUDDLE_STOP_GROWING:
                events.CancelEvent(EVENT_SAP_PUDDLE_CAST_GROW);
                me->AddAura(SPELL_COSMETIC_SHIELD_AURA, me);

                if (Aura* aura = me->GetAura(SPELL_SAP_PUDDLE_GROW))
                    aura->SetStackAmount(1);
                else
                    me->AddAura(SPELL_SAP_PUDDLE_GROW, me);

                break;
            case ACTION_SAP_PUDDLE_EXPLODE:
            {
                int32 bp = int32(me->GetAuraCount(SPELL_SAP_PUDDLE_GROW) * 22000);
                me->CastCustomSpell(SPELL_DETONATE_DAMAGE, SPELLVALUE_BASE_POINT0, bp, me, true);
                break;
            }
            case ACTION_SAP_PUDDLE_DOUBLE_IN_SIZE:
                //! Double in size unless there's a player inside the puddle
                if (Player* player = me->SelectNearestPlayer(100.0f))
                    if (!player->IsWithinDist2d(me, 0.4f * me->GetAuraCount(SPELL_SAP_PUDDLE_GROW)))
                        if (Aura* aura = me->GetAura(SPELL_SAP_PUDDLE_GROW))
                            aura->SetStackAmount(aura->GetStackAmount() * 2);

                //else
                //{
                //    me->AddAura(SPELL_SAP_PUDDLE_GROW, me);

                //    if (Aura* aura = me->GetAura(SPELL_SAP_PUDDLE_GROW))
                //        aura->SetStackAmount(3);
                //}

                break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_SAP_PUDDLE_CAST_GROW:
                me->AddAura(SPELL_SAP_PUDDLE_VISUAL, me);

                Player* player = me->SelectNearestPlayer(100.0f);

                if (!playerInPuddle || !me->HasAura(SPELL_SAP_PUDDLE_GROW))
                    me->AddAura(SPELL_SAP_PUDDLE_GROW, me);
                else if (Aura* aura = me->GetAura(SPELL_SAP_PUDDLE_GROW))
                    ReduceGrowAuraStacksByAmount(-1);

                //if (playerInPuddle)
                //    me->MonsterSay("true", LANG_UNIVERSAL, me->SelectNearestPlayer(100.0f));

                events.ScheduleEvent(EVENT_SAP_PUDDLE_CAST_GROW, 500);
                //Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                bool newPlayerInPuddle = player && player->IsWithinDist2d(me, 0.4f * me->GetAuraCount(SPELL_SAP_PUDDLE_GROW));

                //! First time someoen enters, remove 4 stacks
                if (newPlayerInPuddle && !playerInPuddle)
                    ReduceGrowAuraStacksByAmount(-4);

                playerInPuddle = newPlayerInPuddle;
                break;
            }
        }

        void ReduceGrowAuraStacksByAmount(int8 amount)
        {
            if (Aura* aura = me->GetAura(SPELL_SAP_PUDDLE_GROW))
                aura->ModStackAmount(amount, AURA_REMOVE_BY_EXPIRE);

            if (!me->HasAura(SPELL_SAP_PUDDLE_GROW))
                me->AddAura(SPELL_SAP_PUDDLE_GROW, me);
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vizier_jinbak_sap_puddleAI(creature);
    }
};

class npc_vizier_jinbak_sap_globule : public CreatureScript
{
public:
    npc_vizier_jinbak_sap_globule() : CreatureScript("npc_vizier_jinbak_sap_globule") {}

    struct npc_vizier_jinbak_sap_globuleAI : public ScriptedAI
    {
        npc_vizier_jinbak_sap_globuleAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            //me->CastSpell(me, 120071, false); //! Visual
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(POINT_SAP_GLOBULE_MOVE_TO_CENTER, 1529.52f, 5163.24f, 160.57f, true);
        }

        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                return;

            if (pointId == POINT_SAP_GLOBULE_MOVE_TO_CENTER)
            {
                if (Creature* puddle = me->FindNearestCreature(NPC_SAP_PUDDLE, 150.0f))
                {
                    puddle->AI()->DoAction(ACTION_SAP_PUDDLE_DOUBLE_IN_SIZE);
                    me->DespawnOrUnsummon();
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vizier_jinbak_sap_globuleAI(creature);
    }
};

class spell_vinzier_jinbak_detonate : public SpellScriptLoader
{
public:
    spell_vinzier_jinbak_detonate() : SpellScriptLoader("spell_vinzier_jinbak_detonate") { }

    class spell_vinzier_jinbak_detonate_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vinzier_jinbak_detonate_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
                if (Creature* puddle = caster->FindNearestCreature(NPC_SAP_PUDDLE, 150.0f))
                    puddle->AI()->DoAction(ACTION_SAP_PUDDLE_EXPLODE);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_vinzier_jinbak_detonate_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_vinzier_jinbak_detonate_AuraScript();
    }
};

class SummonSapplingDestSelector
{
public:
    SummonSapplingDestSelector() { }

    bool operator()(WorldObject* object)
    {
        return !object || object->GetEntry() != 61629;
    }
};

class spell_vinzier_jinbak_summon_sappling_periodic : public SpellScriptLoader
{
public:
    spell_vinzier_jinbak_summon_sappling_periodic() : SpellScriptLoader("spell_vinzier_jinbak_summon_sappling_periodic") { }

    class spell_vinzier_jinbak_summon_sappling_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vinzier_jinbak_summon_sappling_periodic_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {

        }

        void HandleBeforeCast()
        {
            //if (Unit* target = GetTarget())
            //    target->CastSpell(target, 120071, false);
        }

        void Register()
        {
            //BeforeCast += SpellCastFn(spell_vinzier_jinbak_summon_sappling_periodic_AuraScript::HandleBeforeCast);
            //OnEffectPeriodic += AuraEffectPeriodicFn(spell_vinzier_jinbak_summon_sappling_periodic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);;
        }
    };

    class spell_vinzier_jinbak_summon_sappling_periodic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vinzier_jinbak_summon_sappling_periodic_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(SummonSapplingDestSelector());
            Trinity::Containers::RandomResize(targets, 3);

            if (targets.empty())
                return;

            for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                if (WorldObject* targetWorldObject = (*itr))
                    if (Unit* target = targetWorldObject->ToUnit())
                        target->ToUnit()->CastSpell(target, SPELL_SUMMON_SAPPLING_VISUAL_PRE_EFFECT, false);
        }

        void HandleBeforeCast()
        {
            //if (Unit* target = GetHitUnit())
            //    target->CastSpell(target, 120071, false);
        }

        void Register()
        {
            //BeforeCast += SpellCastFn(spell_vinzier_jinbak_summon_sappling_periodic_SpellScript::HandleBeforeCast);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_vinzier_jinbak_summon_sappling_periodic_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_vinzier_jinbak_summon_sappling_periodic_SpellScript();
    }

    AuraScript* GetAuraScript() const
    {
        return new spell_vinzier_jinbak_summon_sappling_periodic_AuraScript();
    }
};

class SapPuddleAoeTargetSelector
{
public:
    SapPuddleAoeTargetSelector(Unit* caster) : _caster(caster) { }

    bool operator()(WorldObject* object)
    {
        return !object || object->GetTypeId() != TYPEID_PLAYER || !object->IsWithinDist2d(_caster, 0.4f * _caster->GetAuraCount(SPELL_SAP_PUDDLE_GROW));
    }

private:
    Unit* _caster;
};

class spell_vinzier_jinbak_sap_residue_target_selector : public SpellScriptLoader
{
public:
    spell_vinzier_jinbak_sap_residue_target_selector() : SpellScriptLoader("spell_vinzier_jinbak_sap_residue_target_selector") { }

    class spell_vinzier_jinbak_sap_residue_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vinzier_jinbak_sap_residue_target_selector_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            //targets.remove_if(SapPuddleAoeTargetSelector(GetCaster()));
        }


        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_vinzier_jinbak_sap_residue_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_vinzier_jinbak_sap_residue_target_selector_SpellScript();
    }
};

void AddSC_boss_jinbak()
{
    new boss_vizier_jinbak();

    new npc_vizier_jinbak_sap_puddle();
    new npc_vizier_jinbak_sap_globule();

    new spell_vinzier_jinbak_detonate();
    new spell_vinzier_jinbak_summon_sappling_periodic();
    new spell_vinzier_jinbak_sap_residue_target_selector();
}
