#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_arcway.h"
#include "AreaTrigger.h"
#include "SpellHistory.h"
#include "AreaTriggerAI.h"
#include "Vehicle.h"


enum Spells
{
    // Naltira
    SPELL_BLINK_STRIKES             = 199810,
    SPELL_BLINK_STRIKES_DMG         = 199811,
    SPELL_NETHER_VENOM_AOE          = 199956,
    SPELL_NETHER_VENOM              = 200024,
    SPELL_NETHER_VENOM_AREA         = 200036,
    SPELL_NETHER_VENOM_DMG          = 200040,
    SPELL_TANGLED_WEB               = 200227,
    SPELL_TANGLED_WEB_BEAM          = 200237,
    SPELL_TANGLED_WEB_JUMP          = 200230,
    SPELL_TANGLED_WEB_DMG           = 200284,
    SPELL_TANGLED_WEB_VISUAL_AOE    = 200288,

    // Vicious Manafang
    SPELL_DEVOUR                    = 224425,
    SPELL_DEVOUR_DMG                = 211543,
    SPELL_ARCANE_WEB_BEAM           = 209834,

};

enum Events
{
    // Naltira
    EVENT_MANAFANG              = 1,
    EVENT_BLINK_STRIKES         = 2,
    EVENT_SECOND_BLINK          = 3,
    EVENT_NETHER_VENOM          = 4,
    EVENT_TANGLED_WEB           = 5,
    EVENT_BLINK_STRIKES_TANK    = 6,
    EVENT_BLINK_STRIKES_END     = 7,

    // Vicious Manafang
    EVENT_DEVOUR                = 7,
};

enum Adds
{
    NPC_VICIOUS_MANAFANG = 110966,
    NPC_SLC_GENERIC_MOP  = 68553,
};

enum Data
{
    DATA_TANGLED_WEB_TARGET_1 = 1,
    DATA_TANGLED_WEB_TARGET_2 = 2,
    DATA_SPIDER_BEAM          = 3,
    DATA_TRAPPED_PLAYER       = 4,
    DATA_BLINK_STRIKES        = 5,
};

enum Actions
{
    ACTION_TELEPORT_TANK    = 1,
    ACTION_ACTIVATE_SPIDER  = 2,
    ACTION_CAST_DEVOUR      = 3,
};


using CreatureList = std::list<Creature*>;

class boss_naltira : public CreatureScript
{
    public:
        boss_naltira() : CreatureScript("boss_naltira")
        {}

        struct boss_naltira_AI : public BossAI
        {
            explicit boss_naltira_AI(Creature* creature) : BossAI(creature, DATA_NALTIRA)
            {}

            void EnterCombat(Unit* /**/) override
            {
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                SummonSpiders();
                events.ScheduleEvent(EVENT_MANAFANG, Seconds(30));
                events.ScheduleEvent(EVENT_BLINK_STRIKES, Seconds(15));
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                BossAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /**/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void SummonSpiders()
            {
                CreatureList dummys;

                me->GetCreatureListWithEntryInGrid(dummys, NPC_SLC_GENERIC_MOP);

                for (auto & it : dummys)
                {
                    Position pos = it->GetPosition();
                    pos.m_positionZ -= 5.f;
                    auto* spider = DoSummon(NPC_VICIOUS_MANAFANG, pos, 10 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_DESPAWN);

                    if (spider)
                    {
                        spider->CastSpell(it, SPELL_ARCANE_WEB_BEAM, true);
                        spider->GetAI()->SetGUID(it->GetGUID(), DATA_SPIDER_BEAM);
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_TANGLED_WEB_TARGET_1)
                    _targetOneGuid = guid;
                else if (id == DATA_TANGLED_WEB_TARGET_2)
                    _targetTwoGuid = guid;
            }

            ObjectGuid GetGUID(int32 id) const override
            {
                if (id == DATA_TANGLED_WEB_TARGET_1)
                    return _targetOneGuid;
                else if (id == DATA_TANGLED_WEB_TARGET_2)
                    return _targetTwoGuid;

                return ObjectGuid::Empty;
            }

            void ExecuteEvent(uint32 eventId) override
            {
                me->GetSpellHistory()->ResetAllCooldowns();
                switch (eventId)
                {
                    case EVENT_MANAFANG:
                    {
                        CreatureList spiders;

                        me->GetCreatureListWithEntryInGrid(spiders, NPC_VICIOUS_MANAFANG);

                        if (!spiders.empty())
                        {
                            Creature* spider = nullptr;

                            while (!spider)
                            {
                                spider = Trinity::Containers::SelectRandomContainerElement(spiders);

                                if (spider && !spider->HasReactState(REACT_AGGRESSIVE))
                                    spider->GetAI()->DoAction(ACTION_ACTIVATE_SPIDER);
                                else
                                    spider = nullptr;
                            }
                        }

                        events.ScheduleEvent(EVENT_MANAFANG, Seconds(20));
                        break;
                    }

                    case EVENT_BLINK_STRIKES:
                    {
                        _victimGUID = me->GetVictim()->GetGUID();

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonMeleeTargetSelector(me, true)))
                            DoCast(target, SPELL_BLINK_STRIKES, true);
                        else
                            DoCastVictim(SPELL_BLINK_STRIKES, true);
                        
                        events.ScheduleEvent(EVENT_BLINK_STRIKES_TANK, IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_BLINK_STRIKES, Seconds(30));
                        events.ScheduleEvent(EVENT_NETHER_VENOM, Seconds(10));
                        break;
                    }

                    case EVENT_BLINK_STRIKES_TANK:
                    {
                        if (Unit* target = ObjectAccessor::GetPlayer(*me, _victimGUID))
                            DoCast(target, SPELL_BLINK_STRIKES, true);

                        break;
                    }

                    case EVENT_TANGLED_WEB:
                    {
                        DoCast(me, SPELL_TANGLED_WEB);
                        break;
                    }

                    case EVENT_NETHER_VENOM:
                    {
                        DoCast(me, SPELL_NETHER_VENOM_AOE);
                        events.ScheduleEvent(EVENT_TANGLED_WEB, Seconds(6));
                        break;
                    }
                }
            }

            private:
                ObjectGuid _targetOneGuid, _targetTwoGuid;
                ObjectGuid _victimGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_naltira_AI(creature);
        }
};

class npc_arc_vicious_manafang : public CreatureScript
{
    public:
        npc_arc_vicious_manafang() : CreatureScript("npc_arc_vicious_manafang")
        {}

        struct npc_arc_vicious_manafang_AI : public ScriptedAI
        {
            explicit npc_arc_vicious_manafang_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisableGravity(true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_DISABLE_GRAVITY);
                me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_JUMP_SPLINE_IN_AIR);
                
                _isInLand = false;
                _target = nullptr;
                _damage = 0;
            }

            void MovementInform(uint32 type, uint32 /*id*/) override
            {
                if (type == POINT_MOTION_TYPE && !_isInLand)
                {
                    _isInLand = true;
                    auto* dummy = ObjectAccessor::GetCreature(*me, _dummyGUID);

                    if (dummy)
                        dummy->RemoveAllAuras();
                    
                    me->CastStop();
                    me->RemoveAllAuras();
                    //me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                    me->SetDisableGravity(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_DISABLE_GRAVITY);
                    me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_JUMP_SPLINE_IN_AIR);
                    _events.ScheduleEvent(EVENT_DEVOUR, Seconds(10));
                }
            }

            void DamageTaken(Unit* /**/, uint32 & damage) override
            {
                if (_isInPlayer)
                {
                    _damage += damage;

                    if (_damage >= (me->GetMaxHealth() * 0.3f))
                    {
                        _damage = 0;
                        _isInPlayer = false;
                        _events.RescheduleEvent(EVENT_DEVOUR, Seconds(15));
                        me->CastStop();
                        if (_target)
                            _target->RemoveAurasDueToSpell(SPELL_DEVOUR_DMG);
                    }
                }
            }

            void SetGUID(ObjectGuid guid, int32 id) override
            {
                if (id == DATA_SPIDER_BEAM)
                    _dummyGUID = guid;
                else if (id == DATA_TRAPPED_PLAYER)
                {
                    _target = ObjectAccessor::GetPlayer(*me, guid);
                    _isInPlayer = true;
                    _damage = 0;
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_ACTIVATE_SPIDER)
                {
                    auto* dummy = ObjectAccessor::GetCreature(*me, _dummyGUID);
                    auto* naltira = me->FindNearestCreature(BOSS_NALTIRA, 100.f, true);
                    
                    if (dummy && naltira)
                    {
                        Position pos = dummy->GetPosition();
                        pos.m_positionZ = naltira->GetPositionZ();
                        me->GetMotionMaster()->MovePoint(0, pos);
                    }
                }
                else if (action == ACTION_CAST_DEVOUR)
                {
                    if (_target)
                        me->CastSpell(_target, SPELL_DEVOUR, false);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    if (eventId == EVENT_DEVOUR)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me, true)))
                            DoCast(target, SPELL_DEVOUR_DMG, true);
                        else
                            DoCastVictim(SPELL_DEVOUR_DMG, true);

                        _events.ScheduleEvent(EVENT_DEVOUR, Seconds(15));
                    }
                }

                if (me->HasReactState(REACT_AGGRESSIVE))
                    DoMeleeAttackIfReady();
            }

            private:
                Unit* _target;
                ObjectGuid _dummyGUID;
                bool _isInLand, _isInPlayer;
                EventMap _events;
                uint32 _damage;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_arc_vicious_manafang_AI(creature);
        }
};

class spell_naltira_blink_strikes : public SpellScriptLoader
{
    public:
        spell_naltira_blink_strikes() : SpellScriptLoader("spell_naltira_blink_strikes")
        {}

        class spell_blink_strikes_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_blink_strikes_SpellScript);

                void HandleAfterHit()
                {
                    if (!GetCaster()->ToCreature())
                        return;
                        
                    GetCaster()->ToCreature()->SetReactState(REACT_PASSIVE);
                    GetCaster()->AddUnitState(UNIT_STATE_ROOT);
                    GetCaster()->AttackStop();
                    GetCaster()->StopMoving();
                    GetCaster()->CastSpell(GetCaster(), SPELL_BLINK_STRIKES_DMG, false);
                }

                void Register() override
                {
                    AfterHit += SpellHitFn(spell_blink_strikes_SpellScript::HandleAfterHit);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_blink_strikes_SpellScript();
        }
};

class spell_naltira_blink_strikes_dmg : public SpellScriptLoader
{
    public:
        spell_naltira_blink_strikes_dmg() : SpellScriptLoader("spell_naltira_blink_strikes_dmg")
        {}

        class spell_blink_strikes_dmg_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_blink_strikes_dmg_AuraScript);

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes /**/)
                {
                    if (!GetCaster()->ToCreature())
                        return;

                    GetCaster()->ClearUnitState(UNIT_STATE_ROOT);
                    GetCaster()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                }

                void Register() override
                {
                    OnEffectRemove += AuraEffectRemoveFn(spell_blink_strikes_dmg_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_blink_strikes_dmg_AuraScript();
        }
};

class spell_naltira_tangled_web : public SpellScriptLoader
{
    public:
        spell_naltira_tangled_web() : SpellScriptLoader("spell_naltira_tangled_web")
        {}

        class spell_tangled_web_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_tangled_web_SpellScript);

                bool Load() override
                {
                    _calls = 0;
                    return true;
                }

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    if (_calls == 0)
                        GetCaster()->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TANGLED_WEB_TARGET_1);
                    else
                        GetCaster()->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TANGLED_WEB_TARGET_2);
                    
                    _calls++;
                    
                    GetHitUnit()->CastSpell(GetCaster(), SPELL_TANGLED_WEB_JUMP, true);
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_TANGLED_WEB_DMG, true);

                    
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_tangled_web_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }

                private:
                    uint8 _calls;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_tangled_web_SpellScript();
        }
};

class spell_naltira_tangled_web_dmg : public SpellScriptLoader
{
    public:
        spell_naltira_tangled_web_dmg() : SpellScriptLoader("spell_naltira_tangled_web_dmg")
        {}

        class spell_tangled_web_dmg_AuraScript : public AuraScript
        {
            public:
                PrepareAuraScript(spell_tangled_web_dmg_AuraScript);

                bool Load() override
                {
                    if (GetCaster()->GetAI())
                    {
                        _targetOne = GetCaster()->GetAI()->GetGUID(DATA_TANGLED_WEB_TARGET_1);
                        _targetTwo = GetCaster()->GetAI()->GetGUID(DATA_TANGLED_WEB_TARGET_2);
                    }
                    
                    return true;
                }

                void HandleOnApply(AuraEffect const* /**/, AuraEffectHandleModes )
                {
                    Player* targetOne = ObjectAccessor::GetPlayer(*GetCaster(), _targetOne);
                    Player* targetTwo = ObjectAccessor::GetPlayer(*GetCaster(), _targetTwo);

                    if (targetOne && targetTwo)
                        targetOne->CastSpell(targetTwo, SPELL_TANGLED_WEB_BEAM, true);
                }

                void HandleOnPeriodic(AuraEffect const* /*aurEffect*/)
                {
                    if (!GetUnitOwner())
                        return;
                    
                    GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_TANGLED_WEB_VISUAL_AOE, true);
                    
                    Player* targetOne = ObjectAccessor::GetPlayer(*GetCaster(), _targetOne);
                    Player* targetTwo = ObjectAccessor::GetPlayer(*GetCaster(), _targetTwo);

                    if (targetOne && targetTwo)
                    {
                        if (targetOne->GetDistance2d(targetTwo) >= 30.0f)
                        {
                            targetOne->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_DMG);
                            targetTwo->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_DMG);
                            targetOne->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_BEAM);
                            targetTwo->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_BEAM);
                        }
                    }
                }

                void HandleOnRemove(AuraEffect const* /**/, AuraEffectHandleModes )
                {
                    GetUnitOwner()->RemoveAurasDueToSpell(SPELL_TANGLED_WEB_BEAM);
                }

                void Register() override
                {
                    OnEffectApply += AuraEffectApplyFn(spell_tangled_web_dmg_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                    OnEffectPeriodic += AuraEffectPeriodicFn(spell_tangled_web_dmg_AuraScript::HandleOnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }

                private:
                    ObjectGuid _targetOne;
                    ObjectGuid _targetTwo;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_tangled_web_dmg_AuraScript();
        }
};

class spell_naltira_nether_venom : public SpellScriptLoader
{
    public:
        spell_naltira_nether_venom() : SpellScriptLoader("spell_naltira_nether_venom")
        {}

        class spell_nether_venom_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_nether_venom_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;
                    
                    Unit* target = GetHitUnit();

                    GetCaster()->CastSpell(target, SPELL_NETHER_VENOM, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_nether_venom_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nether_venom_SpellScript();
        }
};

class spell_naltira_nether_venom_dmg : public SpellScriptLoader
{
    public:
        spell_naltira_nether_venom_dmg() : SpellScriptLoader("spell_naltira_nether_venom_dmg")
        {}

        class spell_nether_venom_dmg_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_nether_venom_dmg_SpellScript);

                void HandleMissile(SpellEffIndex /**/)
                {
                    if (!GetHitDest())
                        return;
                    
                    WorldLocation & pos = *GetHitDest();

                    GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_NETHER_VENOM_AREA, true);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_nether_venom_dmg_SpellScript::HandleMissile, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nether_venom_dmg_SpellScript();
        }
};

class spell_arc_devour : public SpellScriptLoader
{
    public:
        spell_arc_devour() : SpellScriptLoader("spell_arc_devour")
        {}

        class spell_arc_devour_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_arc_devour_SpellScript);

            void HandleAfterHit()
            {
                if (!GetHitUnit())
                    return;

                GetCaster()->EnterVehicle(GetHitUnit());
                GetCaster()->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TRAPPED_PLAYER);
                GetCaster()->GetAI()->DoAction(ACTION_CAST_DEVOUR);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_arc_devour_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_arc_devour_SpellScript();
        }
};

class at_arc_nether_venom : public AreaTriggerEntityScript
{
    public:
        at_arc_nether_venom() : AreaTriggerEntityScript("at_arc_nether_venom")
        {}

        struct at_arc_nether_venom_AI : public AreaTriggerAI
        {
            explicit at_arc_nether_venom_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* target) override
            {
                if (!target)
                    return;
                
                if (target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_NETHER_VENOM_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (!target)
                    return;
                
                if (target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_NETHER_VENOM_DMG);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_arc_nether_venom_AI(at);
        }
};


void AddSC_boss_naltira()
{
    new boss_naltira();
    new npc_arc_vicious_manafang();
    new spell_naltira_blink_strikes();
    new spell_naltira_blink_strikes_dmg();
    new spell_naltira_tangled_web();
    new spell_naltira_tangled_web_dmg();
    new spell_naltira_nether_venom();
    new spell_naltira_nether_venom_dmg();
    new spell_arc_devour();
    new at_arc_nether_venom();
}
