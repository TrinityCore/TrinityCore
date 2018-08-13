/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "shadowmoon_burial_grounds.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "SpellAuras.h"
#include "SpellMgr.h"

enum eNhalishSpells
{
    SpellPlanarShift                         = 153623,
    SpellTeleportSelf                        = 153621,
    SpellVoidVortexDamage                    = 152800,
    SpellVoidVortexAreaTrigger               = 152801,
    SpellVoidBlastSpellAuraDummy             = 152792,
    SpellVoidBlastDot                        = 153501,
    SpellVoidDevastationPeriodicTriggerSpell = 153067,
    SpellVoidDevstationProjectile            = 153068,
    SpellVoidDevestationDebuff               = 153070l,
    SpellVoidDevstationAreaTrigger           = 153072,
    SpellSoulStealForceCast                  = 152962,
    SpellSoulStealPeriodicDummy              = 156755,
    SpellSoulless                            = 154947,
    SpellRegainYourSoul                      = 153007,
    SpellSoulShred                           = 152979,
    SpellShadowChannel                       = 46757,
    SpellLootSparkles                        = 92376,
    SpellCloneMe                             = 45204
};

enum eNhalishEvents
{
    EventPlanarShift = 1,
    EventVoidVortex,
    EventVoidBlast,
    EventVoidDevastation,
    EventSoulSteal,
    EventRandomMovement,
    EventExhumeCrypt
};

enum eNhalishCreatures
{
   CreatureDistrubedSouls     = 76400,
   CreatureSoul               = 75899,
   CreatureNhalishProp        = 432561,
   CreatureDevestationTrigger = 543531 /// Hardcoded
};

enum eNhalishGameObjects
{
    GameObjectNhalishDoor     = 227851
};

enum eNhallishTalks
{
    TalkAggro = 1, ///< Yes... come closer, your souls are strong and proud! I will feast on your terror.. [43197]
    TalkDeath,     ///< You are just maggots.. sworm into a corpse of a dying god! [43198]
    TalkIntro01,   ///< Cower before me! [43199]
    TalkIntro02,   ///< Your undying souls will fuel my ascention from the Darkness! [43200]
    TalkIntro03,   ///< Your blisper afterlife is over! [43201]
    TalkKill01,    ///< Your mortal body are so fragile! [43202]
    TalkKill02,    ///< Another soul to DEVOUR! [43203]
    TalkSpell01,   ///< None escape the void! [43204]
    TalkSpell02,   ///< You cannot flee! [43205]
    TalkSpell03,   ///< *Nhallish laughs* [43206]
    TalkSpell04,   ///< Flee... flee from your your formal masters! [43207]
};

enum eNhalishActions
{
    ActionActivateVortex = 1,
    ActionDeactivateVortex
};

/// Nhalish - 75829
class boss_nhalish : public CreatureScript
{
public:

    boss_nhalish() : CreatureScript("boss_nhalish") { }

    struct boss_nhalishAI : public BossAI
    {
        boss_nhalishAI(Creature* creature) : BossAI(creature, eShadowmoonBurialGroundsDatas::DataBossNhallish)
        {
            m_Instance = me->GetInstanceScript();
            HandleDoorActivation();
        }

        InstanceScript* m_Instance;
        uint32 m_PhaseCounter;
        uint32 m_VortexDiff;
        bool m_Vortex;

        void Reset() override
        {
            events.Reset();
            _Reset();

            m_PhaseCounter = 0;
            m_VortexDiff = 0;
            m_Vortex = false;
            
            me->CastSpell(me, eNhalishSpells::SpellShadowChannel);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }

        void HandleDoorActivation() // Only upon boss Defeat
        {
            std::list<GameObject*> l_ListDoors;
            me->GetGameObjectListWithEntryInGrid(l_ListDoors, eNhalishGameObjects::GameObjectNhalishDoor, 300.0f);

            if (l_ListDoors.empty())
                return;

            for (auto itr : l_ListDoors)
            {
                // Activate
                itr->SetLootState(GO_READY);
                itr->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
            }
        }

        void HandleDoorEntranceActivation() // Upon wipe
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_Nhalish = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataNhalishDoorEntrance)))
                {
                    l_Nhalish->SetLootState(GO_READY);
                    l_Nhalish->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon)
            {
                switch (summon->GetEntry())
                {
                    case eNhalishCreatures::CreatureDistrubedSouls:
                        summon->CastSpell(summon, eShadowmoonBurialGroundsSpells::SpellVortexVisual);
                        break;
                }
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            HandleDoorEntranceActivation();

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossNhallish, EncounterState::FAIL);
            }

            // Adding back to Visibility List
            std::list<Player*> l_ListVisibility;
            me->GetPlayerListInGrid(l_ListVisibility, 300.0f);

            if (l_ListVisibility.empty())
                return;

            for (auto itr : l_ListVisibility)
            {
                PhasingHandler::RemovePhase(itr, 50);
            }
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case eNhalishActions::ActionActivateVortex:
                    m_Vortex = true;
                    m_VortexDiff = 2000;
                    break;
                case eNhalishActions::ActionDeactivateVortex:
                    m_Vortex = false;

                    if (m_Instance != nullptr)
                        m_Instance->DoRemoveForcedMovementsOnPlayers(me->GetGUID());
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            Talk(eNhallishTalks::TalkAggro);
            me->SetInCombatWithZone();

            if (m_Instance != nullptr)
            {
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossNhallish, EncounterState::IN_PROGRESS);

                DoZoneInCombat();
            }

            HandleDoorEntranceActivation();
            HandleDoorActivation();

            events.ScheduleEvent(eNhalishEvents::EventPlanarShift, 15 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNhalishEvents::EventSoulSteal, 70 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNhalishEvents::EventVoidBlast, 6 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNhalishEvents::EventExhumeCrypt, 10 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eNhallishTalks::TalkKill01);
                else
                    Talk(eNhallishTalks::TalkKill02);

                PhasingHandler::RemovePhase(who, 50); // Sets dead target back to normal phase.
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            Talk(eNhallishTalks::TalkDeath);

            if (m_Instance != nullptr)
            {
                m_Instance->SetBossState(eShadowmoonBurialGroundsDatas::DataBossNhallish, EncounterState::DONE);
            }

            HandleDoorActivation();
            HandleDoorEntranceActivation();

            // Adding back to Visibility List
            std::list<Player*> l_ListVisibility;
            me->GetPlayerListInGrid(l_ListVisibility, 300.0f);

            if (l_ListVisibility.empty())
                return;

            for (auto itr : l_ListVisibility)
            {
                PhasingHandler::RemovePhase(itr, 50);
            }

            // Distrubed Spirits RP moment.
            for (int i = 0; i < 10; i++)
            {
               Creature* creature = me->SummonCreature(eNhalishCreatures::CreatureDistrubedSouls, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 10 * TimeConstants::IN_MILLISECONDS);

               if (creature)
               {
                   creature->setFaction(35);
                   creature->SetReactState(ReactStates::REACT_PASSIVE);
                   creature->GetMotionMaster()->MoveRandom(15.0f);

                   if (roll_chance_i(25))
                   {
                       switch (urand(0, 1))
                       {
                           case 0:
                               me->Say("Thank you.", Language::LANG_UNIVERSAL, me);
                               break;
                           case 1:
                               me->Say("My torment is over!", Language::LANG_UNIVERSAL, me);
                               break;
                           default:
                               break;
                       }
                   }
               }
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            // Reset phase Counter
            if (m_PhaseCounter >= 4)
            {
                m_PhaseCounter = 0;
            }

            if (m_Vortex)
            {
                if (m_VortexDiff <= diff)
                {
                    std::list<Player*> l_ListPlayers;
                    me->GetPlayerListInGrid(l_ListPlayers, 25.0f);

                    if (l_ListPlayers.empty())
                        return;

                    Position position = me->GetPosition();

                    for (auto itr : l_ListPlayers)
                    {
                        if (itr->IsWithinDist(me, 25.0f, true))
                        {
                            if (itr->IsAlive() && !itr->HasMovementForce(me->GetGUID()))
                                itr->ApplyMovementForce(me->GetGUID(), 3.0f, position);
                            else if (!itr->IsAlive() && itr->HasMovementForce(me->GetGUID()))
                                itr->RemoveMovementForce(me->GetGUID());
                        }
                        else if (itr->HasMovementForce(me->GetGUID()))
                            itr->RemoveMovementForce(me->GetGUID());
                    }

                    m_VortexDiff = 2 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_VortexDiff -= diff;
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case eNhalishEvents::EventExhumeCrypt:
                    me->CastSpell(me, eShadowmoonBurialGroundsSpells::SpellExhumeTheCryptsScriptEffect, true);

                    events.ScheduleEvent(eNhalishEvents::EventExhumeCrypt, urand(8 * TimeConstants::IN_MILLISECONDS, 40 * TimeConstants::IN_MILLISECONDS));
                    break;
                case eNhalishEvents::EventPlanarShift:
                    events.CancelEvent(eNhalishEvents::EventVoidDevastation);
                    events.CancelEvent(eNhalishEvents::EventVoidVortex);

                    me->CastSpell(me, eNhalishSpells::SpellPlanarShift);

                    Talk(eNhallishTalks::TalkSpell03);

                    switch (urand(0, 1))
                    {
                        case 0:
                            events.ScheduleEvent(eNhalishEvents::EventVoidDevastation, 5 * TimeConstants::IN_MILLISECONDS);
                            break;
                        case 1:
                            events.ScheduleEvent(eNhalishEvents::EventVoidVortex, 5 * TimeConstants::IN_MILLISECONDS);
                            break;                                           
                    }

                    events.ScheduleEvent(eNhalishEvents::EventPlanarShift, 30 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eNhalishEvents::EventVoidDevastation:
                    me->CastSpell(me, eNhalishSpells::SpellVoidDevastationPeriodicTriggerSpell);

                    Talk(eNhallishTalks::TalkSpell02);

                    events.ScheduleEvent(eNhalishEvents::EventVoidDevastation, 22 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eNhalishEvents::EventSoulSteal:
                    Talk(eNhallishTalks::TalkSpell04);

                    if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        me->CastSpell(l_Random, eNhalishSpells::SpellSoulStealForceCast);

                    events.ScheduleEvent(eNhalishEvents::EventSoulSteal, 65 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eNhalishEvents::EventVoidBlast:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, eNhalishSpells::SpellVoidBlastSpellAuraDummy);

                    events.ScheduleEvent(eNhalishEvents::EventVoidBlast, 12 * TimeConstants::IN_MILLISECONDS);
                    break;
                case eNhalishEvents::EventVoidVortex:
                    me->CastSpell(me, eNhalishSpells::SpellVoidVortexAreaTrigger);

                    Talk(eNhallishTalks::TalkSpell01);

                    events.ScheduleEvent(eNhalishEvents::EventVoidVortex, 35 * TimeConstants::IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_nhalishAI(creature);
    }
};

/// Possessed Soul - 75899
class shadowmoon_burial_grounds_soul : public CreatureScript
{
public:

    shadowmoon_burial_grounds_soul() : CreatureScript("shadowmoon_burial_grounds_soul") { }

    bool OnGossipHello(Player* /*player*/, Creature* creature) override
    {   
        if (shadowmoon_burial_grounds_soul::shadowmoon_burial_grounds_creaturesAI* linkAI = CAST_AI(shadowmoon_burial_grounds_soul::shadowmoon_burial_grounds_creaturesAI, creature->GetAI()))
        {
            if (linkAI && linkAI->m_HasDied)
            {
                if (!linkAI->m_victimGUID.IsEmpty())
                {
                    if (Unit* victim = ObjectAccessor::GetUnit(*creature, linkAI->m_victimGUID))
                    {
                        victim->RemoveAura(eNhalishSpells::SpellSoulless);

                        // Returned Soul
                        if (victim->HasAura(eNhalishSpells::SpellSoulShred))
                        {
                            victim->CastSpell(victim, eNhalishSpells::SpellRegainYourSoul, true);
                            victim->RemoveAura(eNhalishSpells::SpellSoulShred);
                        }

                        PhasingHandler::AddPhase(victim, 50);

                        creature->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
                    }
                }
            }
        }

        return true;
    }

    struct shadowmoon_burial_grounds_creaturesAI : public ScriptedAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : ScriptedAI(creature)
        {
            m_HasDied = false;
        }

        ObjectGuid m_victimGUID;
        bool m_HasDied;

        void Reset() override
        {         
            events.Reset();

            if (!m_victimGUID.IsEmpty())
            {
                if (Unit* victim = ObjectAccessor::GetUnit(*me, m_victimGUID))
                {
                    me->CastSpell(victim, eNhalishSpells::SpellSoulShred); // automatically target the summoner TARGET_UNIT_SUMMONER 
                    me->CastSpell(me, eShadowmoonBurialGroundsSpells::SpellUnortodoxExistanceAuraDummy);
                }
            }

            me->SetReactState(ReactStates::REACT_PASSIVE);
        }

        void SetGUID(ObjectGuid guid, int32 /*p_Param*/) override
        {
            m_victimGUID = guid;

            if (!m_victimGUID.IsEmpty())
            {
                if (Unit* l_Victim = ObjectAccessor::GetUnit(*me, m_victimGUID))
                {
                    l_Victim->CastSpell(me, eNhalishSpells::SpellCloneMe);
                    me->CastSpell(l_Victim, eNhalishSpells::SpellSoulShred);
                }
            }

            events.ScheduleEvent(eNhalishEvents::EventRandomMovement, 1 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            m_HasDied = true;

            me->RemoveAllAuras();

            me->Respawn();
            me->setFaction(35);
            me->SetReactState(ReactStates::REACT_PASSIVE);

            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->SetFlag(OBJECT_DYNAMIC_FLAGS, UnitDynFlags::UNIT_DYNFLAG_DEAD);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
            me->SetFlag(UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);

            me->CastSpell(me, eNhalishSpells::SpellLootSparkles);
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
               case eNhalishEvents::EventRandomMovement:
                   me->GetMotionMaster()->MoveRandom(4.0f);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Nhalish Prop - 75442
class shadowmoon_burial_grounds_nhalish_prop : public CreatureScript
{
public:

    shadowmoon_burial_grounds_nhalish_prop() : CreatureScript("shadowmoon_burial_grounds_nhalish_prop") { }

    struct shadowmoon_burial_grounds_creaturesAI : public Scripted_NoMovementAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            m_Instance = me->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();

            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            me->setFaction(16);

            me->CastSpell(me, eNhalishSpells::SpellShadowChannel);
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            if (m_Instance != nullptr)
            {
                if (Creature* l_Nhalish = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossNhallish)))
                {
                    if (l_Nhalish->IsAlive() && l_Nhalish->IsInCombat())
                    me->SetHealth(l_Nhalish->GetHealthPct());
                }
            }
        }
    };
     
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Void Devestation - 543531 // Hacked, hardcoded
class shadowmoon_burial_grounds_void_devestation_trigger : public CreatureScript
{
public:

    shadowmoon_burial_grounds_void_devestation_trigger() : CreatureScript("shadowmoon_burial_grounds_void_devestation_trigger") { }

    struct shadowmoon_burial_grounds_creaturesAI : public Scripted_NoMovementAI
    {
        shadowmoon_burial_grounds_creaturesAI(Creature* creature) : Scripted_NoMovementAI(creature) {}

        uint32 m_Timer;

        void Reset() override
        {
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(35);
            me->SetDisplayId(11686);

            m_Timer = 500;
        }

        void UpdateAI(uint32 const diff) override
        {
            events.Update(diff);

            std::list<ObjectGuid> m_Targets;

            if (m_Timer <= diff)
            {
                std::list<Player*> PL_list;
                PL_list = me->SelectNearestPlayers(2.0f);

                if (PL_list.empty())
                    return;

                for (std::list<Player*>::const_iterator itr = PL_list.begin(); itr != PL_list.end(); ++itr)
                {
                    if (!(*itr)->HasAura(eNhalishSpells::SpellVoidDevestationDebuff))
                    {
                        (*itr)->CastSpell((*itr), eNhalishSpells::SpellVoidDevestationDebuff);
                        m_Targets.push_back((*itr)->GetGUID());

                        if ((*itr)->HasAura(eNhalishSpells::SpellVoidDevestationDebuff))
                        {
                            Aura* aura = (*itr)->GetAura(eNhalishSpells::SpellVoidDevestationDebuff);

                            if (aura)
                            {
                                aura->SetDuration(1);
                            }
                        }
                    }
                }

                m_Timer = 500;
            }
            else
            {
                m_Timer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shadowmoon_burial_grounds_creaturesAI(creature);
    }
};

/// Void Devestation - 153068 (TARGET_DEST_CASTER, TARGET_DEST_DEST_RADIUS)
class spell_shadowmoon_burial_grounds_void_devestation_trigger : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_void_devestation_trigger() : SpellScriptLoader("spell_shadowmoon_burial_grounds_void_devestation_trigger") { }

    class spell_shadowmoon_burial_grounds_void_devestation_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_void_devestation_trigger_SpellScript);

        bool Load() override
        {
            if (!GetSpellInfo())
                return false;

            //SpellInfo* spell = const_cast<SpellInfo*>(GetSpellInfo());
            //spell->GetEffect(0)->TargetA = Targets::TARGET_DEST_CASTER;
            //spell->GetEffect(0)->TargetB = Targets::TARGET_DEST_DEST_RADIUS;
            //spell->GetEffect(0)->RadiusEntry = sSpellRadiusStore.LookupEntry(10); // 30y
            return true;
        }

        void HandleTriggerMissile(SpellEffIndex effectIndex)
        {
            PreventHitDefaultEffect(effectIndex);

            if (!GetCaster())
                return;

           const WorldLocation* l_WorldLocation = GetExplTargetDest();
           const SpellInfo* l_SpellInfo = sSpellMgr->GetSpellInfo(eNhalishSpells::SpellVoidDevstationAreaTrigger);

           if (!l_SpellInfo)
               return;

           GetCaster()->SummonCreature(eNhalishCreatures::CreatureDevestationTrigger, l_WorldLocation->GetPositionX(), l_WorldLocation->GetPositionY(), l_WorldLocation->GetPositionZ(), l_WorldLocation->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, l_SpellInfo->GetDuration());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_burial_grounds_void_devestation_trigger_SpellScript::HandleTriggerMissile, SpellEffIndex::EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_void_devestation_trigger_SpellScript();
    }
};

/// Void Blast - 152792  
class spell_shadowmoon_burial_grounds_void_blast : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_void_blast() : SpellScriptLoader("spell_shadowmoon_burial_grounds_void_blast") { }

    class spell_shadowmoon_burial_grounds_void_blast_SpellScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_void_blast_SpellScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->IsAIEnabled)
                {
                    if (Unit* target = caster->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO))
                    {
                        caster->CastSpell(target, eNhalishSpells::SpellVoidBlastDot);
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
                    l_Instance->DoRemoveAurasDueToSpellOnPlayers(eNhalishSpells::SpellVoidBlastDot);
                }
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shadowmoon_burial_grounds_void_blast_SpellScript::OnApply,    SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_shadowmoon_burial_grounds_void_blast_SpellScript::OnRemove, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_void_blast_SpellScript();
    }
};

/// Void Vortex - 152801 
class spell_shadowmoon_burial_grounds_void_vortex : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_void_vortex() : SpellScriptLoader("spell_shadowmoon_burial_grounds_void_vortex") { }

    class spell_shadowmoon_burial_grounds_void_vortex_SpellScript : public AuraScript
    {
        PrepareAuraScript(spell_shadowmoon_burial_grounds_void_vortex_SpellScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->IsAIEnabled)
                {
                    if (caster->GetTypeId() != TypeID::TYPEID_PLAYER)
                    {
                        caster->GetAI()->DoAction(eNhalishActions::ActionActivateVortex);
                    }
                }
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                caster->GetAI()->DoAction(eNhalishActions::ActionDeactivateVortex);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_shadowmoon_burial_grounds_void_vortex_SpellScript::OnApply, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_shadowmoon_burial_grounds_void_vortex_SpellScript::OnRemove, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_TRIGGER_SPELL, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shadowmoon_burial_grounds_void_vortex_SpellScript();
    }
};

/// Soul Steal - 152962 
class spell_shadowmoon_burial_grounds_soul_steal : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_soul_steal() : SpellScriptLoader("spell_shadowmoon_burial_grounds_soul_steal") {}

    class spell_shadowmoon_burial_grounds_soul_steal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_soul_steal_SpellScript);

        bool Load() override
        {
            if (!GetSpellInfo())
                return false;

            /*SpellInfo* spell = const_cast<SpellInfo*>(GetSpellInfo());
            spell->GetEffect(0)->TriggerSpell = 0;*/
            return true;
        }

        void HandleForceCast(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            if (!GetHitUnit() && GetHitUnit()->GetTypeId() != TypeID::TYPEID_PLAYER)
                return;

            // Soulless
            GetHitUnit()->CastSpell(GetHitUnit(), eNhalishSpells::SpellSoulless);

            // Caster is boss, but doing it with pointer to prevent a crash *twerks*
            if (InstanceScript* m_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature* l_Nhalish = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eShadowmoonBurialGroundsDatas::DataBossNhallish)))
                {
                    if (Creature* Soul = GetCaster()->SummonCreature(eNhalishCreatures::CreatureSoul, GetHitUnit()->GetPosition(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 20 * TimeConstants::IN_MILLISECONDS, 0, true))
                    {
                        if (boss_nhalish::boss_nhalishAI* linkAI = CAST_AI(boss_nhalish::boss_nhalishAI, l_Nhalish->GetAI()))
                        {
                            uint32 m_phaseId = 50 + linkAI->m_PhaseCounter;

                            /// Sets new phase value
                            PhasingHandler::AddPhase(GetHitUnit(), m_phaseId);
                            PhasingHandler::AddPhase(Soul, m_phaseId);

                            if (Soul->IsAIEnabled)
                            {
                                Soul->AI()->SetGUID(GetHitUnit()->GetGUID(), 0);
                            }

                            linkAI->m_PhaseCounter++;
                        }
                    }
                }
            }
        }
  
        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shadowmoon_burial_grounds_soul_steal_SpellScript::HandleForceCast, SpellEffIndex::EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_soul_steal_SpellScript();
    }
};

/// Planar Shift - 153623   
class spell_shadowmoon_burial_grounds_planar_shift : public SpellScriptLoader
{
public:

    spell_shadowmoon_burial_grounds_planar_shift() : SpellScriptLoader("spell_shadowmoon_burial_grounds_planar_shift") {}

    class spell_shadowmoon_burial_grounds_teleport_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shadowmoon_burial_grounds_teleport_SpellScript);

        void HandleAfterCast()
        {
            if (!GetCaster())
                return;

            if (!GetCaster()->IsAIEnabled)
                return;

            if (Unit* target = GetCaster()->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                GetCaster()->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), eNhalishSpells::SpellTeleportSelf, true);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_shadowmoon_burial_grounds_teleport_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shadowmoon_burial_grounds_teleport_SpellScript();
    }
};

/// Void Devestation - 153072 
class areatrigger_void_devestation : public AreaTriggerAI
{
public:

    areatrigger_void_devestation(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        unit->CastSpell(*unit, eNhalishSpells::SpellVoidDevestationDebuff);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(eNhalishSpells::SpellVoidDevestationDebuff);
    }
};

void AddSC_nhalish()
{
    new boss_nhalish();
    new shadowmoon_burial_grounds_nhalish_prop();
    new shadowmoon_burial_grounds_soul();
    new spell_shadowmoon_burial_grounds_void_devestation_trigger();
    new spell_shadowmoon_burial_grounds_planar_shift();
    new spell_shadowmoon_burial_grounds_soul_steal();
    new spell_shadowmoon_burial_grounds_void_blast();
    new spell_shadowmoon_burial_grounds_void_vortex();
    RegisterAreaTriggerAI(areatrigger_void_devestation);
}
