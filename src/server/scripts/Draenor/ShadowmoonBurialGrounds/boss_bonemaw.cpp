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

#include "shadowmoon_burial_grounds.h"
#include "GameObject.h"

enum eBoneMawSpells
{
    // Carrion Worm: 88769
    SpellNecroticPitchTriggerMissile    = 153689,
    SpellNecroticPitchAreatrigger       = 153690,
    SpellNecroticPitchDummy             = 153691,
    SpellNecroticPitchDebuff            = 153692,
    SpellCorpseBreathPeriodic           = 165578,
    SpellCorpseBreathDamage             = 165579,
    SpellFetidSpitDamage                = 153681,

    SpellBodySlam                       = 154175,
    SpellInhaleVisual                   = 153721,
    SpellInhalePeriodicChannel          = 153804,
    SpellInhaleDamage                   = 153908,
    SpellInhaleAreaTrigger              = 153961,
    SpellInhaleSleep                    = 154010,
    SpellnhaleScreenEffect              = 154008,

    SpellVisualSubmerge                 = 177694
};

enum eBoneMawEvents
{
    // Carrion Worm: 88769
    EventNecroticPitch = 1,
    EventCorpseBreath,
    EventFetidSpit,
    EventBodySlam,
    EventInhale,
    EventCarrionWorm,
    EventCancelBodySlamFlags,
    EventCancelSubmerge,

    // Cosmetic - Submerge for Bonemaw
    EventSubmerge,
};

enum eBoneMawCreatures
{
    CreatureCarrionWorm             = 88769,
    CreatureInhaleTrigger           = 76250,
    CreatureNecroticPitchTrigger    = 76191,
};

enum eBoneMawGameObjects
{
    GameObjectBonemawDoors      = 233988,
    GameObjectBonemawDoors01    = 233989
};

enum eBoneMawActions
{
    ActionInhaleDeactivate = 1,
};

Position const positionBoneMaw = { 1851.256f, -558.721f, 199.027f, 1.991077f };
Position const positionAdds[2] =
{
    { 1801.369f, -521.248f, 196.795f, 0.030723f },
    { 1860.075f, -497.532f, 196.796f, 4.054334f },
};

#define FriendlyFaction 35
#define HostileFaction 16
#define InvisibleDisplay 11686

/// Bonemaw - 75452
class boss_bonemaw : public CreatureScript
{
public:
    boss_bonemaw() : CreatureScript("boss_bonemaw") { }

    struct boss_bonemawAI : public BossAI
    {
        boss_bonemawAI(Creature* creature) : BossAI(creature, eShadowmoonBurialGroundsDatas::DataBossBonemaw)
        {
            m_Instance = me->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_PoolDiff;
        uint32 m_InhaleDiff;
        bool m_HasVictimOut;
        bool m_InhaleActivated;

        void Reset() override
        {
            events.Reset();

            m_HasVictimOut = false;
            m_InhaleActivated = false;
            m_PoolDiff = 3 * TimeConstants::IN_MILLISECONDS;;
            m_InhaleDiff = 4 * TimeConstants::IN_MILLISECONDS;

            me->SetDisableGravity(true);
            me->SetCanFly(true);

            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->AddUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

            me->RemoveAllAuras();
        }

        void JustReachedHome() override
        {
            _JustReachedHome();

            HandleEntranceDoorActivation();
            summons.DespawnAll();

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossBonemaw, EncounterState::FAIL);
            }
        }

        void HandleDoorActivation()
        {
            std::list<GameObject*> l_ListDoors;
            me->GetGameObjectListWithEntryInGrid(l_ListDoors, eBoneMawGameObjects::GameObjectBonemawDoors, 100.0f);
            me->GetGameObjectListWithEntryInGrid(l_ListDoors, eBoneMawGameObjects::GameObjectBonemawDoors01, 100.0f);

            if (l_ListDoors.empty())
                return;

            for (auto itr : l_ListDoors)
            {
                /// Activate
                itr->SetLootState(GO_READY);
                itr->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
            }
        }

        void HandleEntranceDoorActivation()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_BonemawEntranceDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBonemawDoorEntrance)))
                {
                    /// Activate
                    l_BonemawEntranceDoor->SetLootState(GO_READY);
                    l_BonemawEntranceDoor->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eBoneMawActions::ActionInhaleDeactivate:
                    m_InhaleActivated = false;
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossBonemaw, EncounterState::IN_PROGRESS);

                DoZoneInCombat();
            }

            HandleEntranceDoorActivation();

            events.ScheduleEvent(eBoneMawEvents::EventNecroticPitch, 50 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBoneMawEvents::EventBodySlam, 30 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBoneMawEvents::EventCorpseBreath, 20 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBoneMawEvents::EventInhale, 60 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eBoneMawEvents::EventSubmerge, urand(70 * TimeConstants::IN_MILLISECONDS, 100 * TimeConstants::IN_MILLISECONDS));

            if (me->GetMap()->IsHeroic())
                events.ScheduleEvent(eBoneMawEvents::EventCarrionWorm, 70 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            summons.DespawnAll();

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossBonemaw, EncounterState::DONE);
            }

            HandleEntranceDoorActivation();
            HandleDoorActivation();
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            /// Inhale mechanismActionInhaleDeactivate
            if (m_InhaleActivated)
            {
                if (m_InhaleDiff <= diff)
                {
                    std::list<Player*> l_ListPlayers;
                    me->GetPlayerListInGrid(l_ListPlayers, 100.0f);

                    if (l_ListPlayers.empty())
                        return;

                    Position position = me->GetPosition();

                    for (auto itr : l_ListPlayers)
                    {            
                        if (Creature* l_BonemawMouth = m_Instance->GetCreature(DataBonemawMouth))
                        {
                            if (itr->IsWithinDistInMap(l_BonemawMouth, 4.0f))
                            {
                                itr->CastSpell(itr, eBoneMawSpells::SpellInhaleDamage);
                            }

                            if (itr->IsWithinDist(l_BonemawMouth, 100.0f, true))
                            {
                                if (itr->IsAlive() && !itr->HasMovementForce(l_BonemawMouth->GetGUID()))
                                    itr->ApplyMovementForce(l_BonemawMouth->GetGUID(), position, 3.0f, 0);
                                else if (!itr->IsAlive() && itr->HasMovementForce(l_BonemawMouth->GetGUID()))
                                    itr->RemoveMovementForce(l_BonemawMouth->GetGUID());
                            }
                            else if (itr->HasMovementForce(l_BonemawMouth->GetGUID()))
                                itr->RemoveMovementForce(l_BonemawMouth->GetGUID());
                        }
                    }

                    m_InhaleDiff = 4 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_InhaleDiff -= diff;
            }

            /// Fetid Spit mechanism - hardcoded.
            if (Unit* target = me->GetVictim())
            {
                if (me->IsWithinMeleeRange(target))
                {
                    if (m_HasVictimOut)
                    {
                        m_HasVictimOut = false;
                        events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
                    }
                }
                else
                {
                    if (m_PoolDiff <= diff)
                    {
                        m_HasVictimOut = true;

                        events.CancelEvent(eBoneMawEvents::EventFetidSpit);

                        if (me->GetVictim() != nullptr)
                            DoCastAOE(eBoneMawSpells::SpellFetidSpitDamage, true);

                        m_PoolDiff = 5 * TimeConstants::IN_MILLISECONDS;
                    }
                    else
                        m_PoolDiff -= diff;
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case eBoneMawEvents::EventFetidSpit:
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, eBoneMawSpells::SpellFetidSpitDamage);

                    events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eBoneMawEvents::EventSubmerge:
                    me->CastSpell(me, eBoneMawSpells::SpellVisualSubmerge);
                    events.Reset();

                    events.ScheduleEvent(eBoneMawEvents::EventCancelSubmerge, 8 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eBoneMawEvents::EventBodySlam:
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, eBoneMawSpells::SpellBodySlam);

                    events.ScheduleEvent(eBoneMawEvents::EventBodySlam, 20 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eBoneMawEvents::EventCarrionWorm:
                {
                    me->CastSpell(me, eBoneMawSpells::SpellVisualSubmerge);

                    for (int i = 0; i < 2; i++)
                    {
                        me->SummonCreature(eBoneMawCreatures::CreatureCarrionWorm, positionAdds[i], TEMPSUMMON_MANUAL_DESPAWN);
                    }

                    events.ScheduleEvent(eBoneMawEvents::EventCancelSubmerge, 3 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eBoneMawEvents::EventCancelSubmerge:
                {
                    std::list<Creature*> l_ListCarrionWorms;
                    me->GetCreatureListWithEntryInGrid(l_ListCarrionWorms, eBoneMawCreatures::CreatureCarrionWorm, 70.0f);

                    if (!l_ListCarrionWorms.empty())
                    {
                        for (auto itr : l_ListCarrionWorms)
                        {
                            if (itr->IsAlive())
                            {
                                itr->RemoveAura(eBoneMawSpells::SpellVisualSubmerge);
                            }
                        }
                    }

                    /// Resets all events and then rescheduel them to prevent the events from running while submerged.
                    events.Reset();

                    events.ScheduleEvent(eBoneMawEvents::EventNecroticPitch, 50 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eBoneMawEvents::EventBodySlam, 30 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eBoneMawEvents::EventCorpseBreath, 20 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eBoneMawEvents::EventInhale, 60 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
                    events.ScheduleEvent(eBoneMawEvents::EventSubmerge, urand(30 * TimeConstants::IN_MILLISECONDS, 70 * TimeConstants::IN_MILLISECONDS));

                    if (me->GetMap()->IsHeroic())
                        events.ScheduleEvent(eBoneMawEvents::EventCarrionWorm, 70 * TimeConstants::IN_MILLISECONDS);

                    events.ScheduleEvent(eBoneMawEvents::EventSubmerge, urand(70 * TimeConstants::IN_MILLISECONDS, 100 * TimeConstants::IN_MILLISECONDS));

                    me->RemoveAura(eBoneMawSpells::SpellVisualSubmerge);
                    me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    break;
                }
                case eBoneMawEvents::EventCorpseBreath:
                {
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, eBoneMawSpells::SpellCorpseBreathPeriodic);

                    events.ScheduleEvent(eBoneMawEvents::EventCorpseBreath, 15 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eBoneMawEvents::EventInhale:
                {
                    m_InhaleActivated = true;
                    m_InhaleDiff = 2 * TimeConstants::IN_MILLISECONDS;

                    me->CastSpell(me, eBoneMawSpells::SpellInhalePeriodicChannel);
                    events.ScheduleEvent(eBoneMawEvents::EventInhale, 55 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case eBoneMawEvents::EventNecroticPitch:
                {
                    if (Unit* target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, eBoneMawSpells::SpellNecroticPitchTriggerMissile);

                    events.ScheduleEvent(eBoneMawEvents::EventNecroticPitch, 25 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_bonemawAI(creature);
    }
};

/// Carrion Worm - 76057
class npc_shadowmoon_burial_grounds_creature_carrion_worm : public CreatureScript
{
public:
    npc_shadowmoon_burial_grounds_creature_carrion_worm() : CreatureScript("npc_shadowmoon_burial_grounds_creature_carrion_worm") { }

    struct npc_shadowmoon_burial_grounds_creature_carrion_wormAI : public ScriptedAI
    {
        npc_shadowmoon_burial_grounds_creature_carrion_wormAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = me->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_PoolDiff;
        bool m_HasVictimOut;

        void Reset() override
        {
            events.Reset();

            DoZoneInCombat();

            me->SetDisableGravity(true);
            me->SetCanFly(true);

            m_HasVictimOut = false;
            m_PoolDiff = 2 * TimeConstants::IN_MILLISECONDS;

            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->AddUnitFlag( UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);

            me->AddAura(eBoneMawSpells::SpellVisualSubmerge, me);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            /// Fetid Spit mechanism - hardcoded.
            if (Unit* target = me->GetVictim())
            {
                if (me->IsWithinMeleeRange(target))
                {
                    if (m_HasVictimOut)
                    {
                        m_HasVictimOut = false;
                        events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
                    }
                }
                else
                {
                    if (m_PoolDiff <= diff)
                    {
                        m_HasVictimOut = true;

                        events.CancelEvent(eBoneMawEvents::EventFetidSpit);

                        if (me->GetVictim() != nullptr)
                            DoCastAOE(eBoneMawSpells::SpellFetidSpitDamage, true);

                        m_PoolDiff = 5 * TimeConstants::IN_MILLISECONDS;
                    }
                    else
                        m_PoolDiff -= diff;
                }
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case eBoneMawEvents::EventFetidSpit:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(target, eBoneMawSpells::SpellFetidSpitDamage);

                    events.ScheduleEvent(eBoneMawEvents::EventFetidSpit, 10 * TimeConstants::IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowmoon_burial_grounds_creature_carrion_wormAI(creature);
    }
};

/// Necrotic Pitch - 76191
class npc_shadowmoon_burial_grounds_necrotic_pitch : public CreatureScript
{
public:
    npc_shadowmoon_burial_grounds_necrotic_pitch() : CreatureScript("npc_shadowmoon_burial_grounds_necrotic_pitch") { }

    struct npc_shadowmoon_burial_grounds_necrotic_pitchAI : public Scripted_NoMovementAI
    {
        npc_shadowmoon_burial_grounds_necrotic_pitchAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        uint32 m_Timer;
        InstanceScript* m_Instance;
       
        void Reset() override
        {
            events.Reset();

            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));

            me->SetFaction(FriendlyFaction);
            me->SetDisplayId(InvisibleDisplay);

            m_Timer = 2 * TimeConstants::IN_MILLISECONDS;
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            if (m_Timer <= diff)
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 1.12f);

                if (l_ListPlayers.empty())
                    return;

                for (auto itr : l_ListPlayers)
                {
                    if (!itr->HasAura(eBoneMawSpells::SpellNecroticPitchDebuff))
                    itr->AddAura(eBoneMawSpells::SpellNecroticPitchDebuff, itr);
                }

                m_Timer = 2 * TimeConstants::IN_MILLISECONDS;
            }
            else
            {
                m_Timer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shadowmoon_burial_grounds_necrotic_pitchAI(creature);
    }
};

/// Inhale - 153804 
class spell_shadowmoon_burial_grounds_inhale : public SpellScriptLoader
{
public:
    spell_shadowmoon_burial_grounds_inhale() : SpellScriptLoader("spell_inhale") { }

    class spell_shadowmoon_burial_grounds_inhale_SpellScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_inhale_SpellScript);

        void OnRemove(AuraEffect const* /*m_AurEff*/, AuraEffectHandleModes /*m_Mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (InstanceScript* l_Instance = caster->GetInstanceScript())
                {
                    if (Creature* l_Bonemaw = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossBonemaw)))
                    {
                        if (l_Bonemaw->IsAIEnabled)
                        {
                            l_Bonemaw->GetAI()->DoAction(eBoneMawActions::ActionInhaleDeactivate);
                        }
                    }
                }
            }
        }

        void Register() override
        {     
            AfterEffectRemove += AuraEffectRemoveFn(spell_shadowmoon_burial_grounds_inhale_SpellScript::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_inhale_SpellScript();
    }
};

/// Body Slam - 153686
class spell_shadowmoon_burial_grounds_body_slam : public SpellScriptLoader
{
public:
    spell_shadowmoon_burial_grounds_body_slam() : SpellScriptLoader("spell_shadowmoon_burial_grounds_body_slam") { }

    class spell_shadowmoon_burial_grounds_body_slam_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_body_slam_SpellScript);

        enum eSpell
        {
            TargetRestrict = 18748,
        };

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            SpellTargetRestrictionsEntry const* l_Restriction = sSpellTargetRestrictionsStore.LookupEntry(eSpell::TargetRestrict);
            if (l_Restriction == nullptr)
                return;

            Unit* caster = GetCaster();
            if (caster == nullptr)
                return;

            //float radius = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(caster);
            targets.remove_if([caster/*, l_Restriction*/](WorldObject* p_Object) -> bool
            {
                if (p_Object == nullptr)
                    return true;

                /*if (!p_Object->IsInAxe(caster, l_Restriction->Width, radius))
                    return true;*/

                if (!p_Object->isInFront(caster))
                    return true;

                return false;
            });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadowmoon_burial_grounds_body_slam_SpellScript::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_CONE_ENTRY_129);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_shadowmoon_burial_grounds_body_slam_SpellScript::CorrectTargets, SpellEffIndex::EFFECT_1, Targets::TARGET_UNIT_CONE_ENTRY_129);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_body_slam_SpellScript();
    }
};

/// Corpse Breath - 165578  
class spell_shadowmoon_burial_grounds_corpse_breath : public SpellScriptLoader
{
public:
    spell_shadowmoon_burial_grounds_corpse_breath() : SpellScriptLoader("spell_shadowmoon_burial_grounds_corpse_breath") { }

    class spell_shadowmoon_burial_grounds_corpse_breath_SpellScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_corpse_breath_SpellScript);

        void OnApply(AuraEffect const* /*m_AurEff*/, AuraEffectHandleModes /*m_Mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->IsAIEnabled)
                {
                    if (Unit* target = caster->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                    {
                        caster->CastSpell(target, eBoneMawSpells::SpellCorpseBreathDamage);
                    }
                }
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (InstanceScript* l_Instance = caster->GetInstanceScript())
                {
                    l_Instance->DoRemoveAurasDueToSpellOnPlayers(eBoneMawSpells::SpellCorpseBreathDamage);
                }
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shadowmoon_burial_grounds_corpse_breath_SpellScript::OnApply, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_shadowmoon_burial_grounds_corpse_breath_SpellScript::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_corpse_breath_SpellScript();
    }
};

/// Necrotic Pitch - 153689
class spell_shadowmoon_burial_grounds_necrotic_pitch : public SpellScriptLoader
{
public:
    spell_shadowmoon_burial_grounds_necrotic_pitch() : SpellScriptLoader("spell_shadowmoon_burial_grounds_necrotic_pitch") { }

    class spell_shadowmoon_burial_grounds_necrotic_pitch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_necrotic_pitch_SpellScript);

        void HandleTriggerMissile(SpellEffIndex effectIndex)
        {
            PreventHitDefaultEffect(effectIndex);

            if (!GetCaster())
                return;

            const WorldLocation* l_WorldLocation = GetExplTargetDest();

            if (l_WorldLocation != nullptr)
            GetCaster()->SummonCreature(eBoneMawCreatures::CreatureNecroticPitchTrigger, l_WorldLocation->GetPositionX(), l_WorldLocation->GetPositionY(), l_WorldLocation->GetPositionZ(), l_WorldLocation->GetOrientation(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 60 * TimeConstants::IN_MILLISECONDS);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_burial_grounds_necrotic_pitch_SpellScript::HandleTriggerMissile, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_necrotic_pitch_SpellScript();
    }
};

/// Drowned - 154010  
class spell_shadowmoon_burial_grounds_drowned : public SpellScriptLoader
{
public:
    spell_shadowmoon_burial_grounds_drowned() : SpellScriptLoader("spell_shadowmoon_burial_grounds_drowned")
    {
    }

    class spell_shadowmoon_burial_grounds_drowned_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_drowned_SpellScript);

        void HandleScript(SpellEffIndex /*effectIndex*/)
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();

            caster->NearTeleportTo(1830.360f, -505.889f, 201.652f, 5.194756f, true);          
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_burial_grounds_drowned_SpellScript::HandleScript, SpellEffIndex::EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_drowned_SpellScript();
    }
};

void AddSC_bonemaw()
{
    new boss_bonemaw();
    new npc_shadowmoon_burial_grounds_creature_carrion_worm();
    new npc_shadowmoon_burial_grounds_necrotic_pitch();
    new spell_shadowmoon_burial_grounds_body_slam();
    new spell_shadowmoon_burial_grounds_inhale();
    new spell_shadowmoon_burial_grounds_necrotic_pitch();
    new spell_shadowmoon_burial_grounds_corpse_breath();
    new spell_shadowmoon_burial_grounds_drowned();
}
