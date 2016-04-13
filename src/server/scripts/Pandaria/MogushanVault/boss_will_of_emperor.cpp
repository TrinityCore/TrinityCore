/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

// TODO IMPORTANT : SPELL_MAGNETIC_ARMOR_AURA_QIN_XI & SPELL_MAGNETIC_ARMOR_AURA_JAN_XI changer le triggertime de l'effect1 à 2000
//                  SPELL_DEVASTATING_ARC doit avoit le flag pour que le boss ne tourne pas
//                  Hero : Le visuel des etincelles
//                  Hero : les conditions pour les spells d'explosions des etincelles (actuellement fou le buff aussi sur les joueurs, devrait juste le mettre sur les 3 types d'add)

// TODO MINEUR :    Les alcoves doivent s'illuminer en rouge avant un spawn de mob
//                  Les adds n'ont pas leurs armes/boucliers


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"

enum eSpells
{
    // Jan Xi & Qin Xi
    SPELL_STOMP                         = 116969,
    SPELL_DEVASTATING_ARC               = 117006,
    SPELL_MAGNETIC_ARMOR_AURA_QIN_XI    = 116815, // Aura on the boss, apply on victim & check dist
    SPELL_MAGNETIC_ARMOR_QIN_XI         = 116818, // Aura on the player, visual
    SPELL_MAGNETIC_ARMOR_AURA_JAN_XI    = 117193, // Aura on the boss, apply on victim & check dist
    SPELL_MAGNETIC_ARMOR_JAN_XI         = 117195, // Aura on the player, visual

    SPELL_TITAN_GAS                     = 116779,
    SPELL_OPPORTUNISTIC_STRIKE          = 116808,

    // Rage
    SPELL_FOCALISED_ASSAULT             = 116525,
    SPELL_WITHOUT_ARMOR                 = 116535,

    // Courage
    SPELL_FOCALISED_DEFENSE             = 116778,
    SPELL_IMPEDING_THRUST               = 117485,
    SPELL_HALF_PLATE                    = 116537,

    // Force
    SPELL_ENERGIZING_SMASH              = 116550,
    SPELL_ENERGIZED                     = 116605,
    SPELL_FULL_PLATE                    = 116540,

    // Titan Spark
    SPELL_SUMMON_TITAN_SPARK            = 117746,
    SPELL_FOCALISED_ENERGY              = 116829,
    SPELL_ENERGY_OF_CREATION            = 117734
};

enum eEvents
{
    // Jan & Qin
    EVENT_DEVASTATING_COMBO     = 1,

    // Shared
    EVENT_CHECK_TARGET          = 10,

    // Courage
    EVENT_IMPEDING_THRUST       = 12,
    
    // Strenght
    EVENT_ENERGIZING_SMASH      = 13,
};

enum eDevastatingComboPhase
{
    PHASE_NOT_STARTED           = 0,
};

class boss_jin_qin_xi : public CreatureScript
{
    public:
        boss_jin_qin_xi() : CreatureScript("boss_jin_qin_xi") {}

        struct boss_jin_qin_xiAI : public ScriptedAI
        {
            boss_jin_qin_xiAI(Creature* creature) : ScriptedAI(creature), summons(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;

            uint8 devastatingComboPhase;

            std::list<Player*> playerList;

            void Reset()
            {
                if (!me->IsAlive())
                    return;

                if (!pInstance || pInstance->GetBossState(DATA_WILL_OF_EMPEROR) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                me->ResetLootMode();
                events.Reset();
                summons.DespawnAll();

                devastatingComboPhase = 0;

                me->AddAura(me->GetEntry() == NPC_QIN_XI ? SPELL_MAGNETIC_ARMOR_AURA_QIN_XI: SPELL_MAGNETIC_ARMOR_AURA_JAN_XI, me);

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGNETIC_ARMOR_AURA_QIN_XI);
                    pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGNETIC_ARMOR_JAN_XI);
                }

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                float x = me->GetPositionX() + (15 * cos(me->GetOrientation()));
                float y = me->GetPositionY() + (15 * sin(me->GetOrientation()));

                me->GetMotionMaster()->MoveJump(x, y, 362.19f, 20.0f, 20.0f, 1);

                playerList.clear();
            }

            void MovementInform(uint32 uiType, uint32 id)
            {

        if (!me->IsInWorld())
            return;

                if (uiType != POINT_MOTION_TYPE
                 && uiType != EFFECT_MOTION_TYPE)
                    return;

                if (id == 1)
                {
                    DoZoneInCombat(me, 200.0f);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        AttackStart(target);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    events.ScheduleEvent(EVENT_DEVASTATING_COMBO, 20000);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat(me, 200.0f);

                if (pInstance)
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
                summons.DespawnAll();

                if (pInstance)
                {
                    pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    pInstance->SetBossState(DATA_WILL_OF_EMPEROR, DONE);
                }
            }

            void DoAction(int32 action)
            {
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id != SPELL_DEVASTATING_ARC && spell->Id != SPELL_STOMP)
                    return;

                for (Player* player: playerList)
                {
                    if (player->GetGUID() == target->GetGUID())
                    {
                        playerList.remove(player);
                        break;
                    }
                }
            }

            Creature* getOtherBoss()
            {
                if (pInstance)
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(pInstance->GetData64(me->GetEntry() == NPC_QIN_XI ? NPC_JAN_XI: NPC_QIN_XI)));
                else
                    return NULL;
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                Creature* otherBoss = getOtherBoss();

                if (attacker != otherBoss)
                    me->DealDamage(otherBoss, damage);
                else
                    me->LowerPlayerDamageReq(damage);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_DEVASTATING_COMBO:
                    {
                        if (!devastatingComboPhase)
                        {
                            // We check wich players are in zone on combo beginning
                            GetPlayerListInGrid(playerList, me, 12.0f);
                        }

                        float newOri = frand(0.0f, 6.28f);
                        me->SetOrientation(frand(0.0f, 6.28f));
                        me->SetFacingTo(newOri);
                        if (urand(0, 1))
                        {
                            me->CastSpell(me, SPELL_DEVASTATING_ARC, false);
                            ++devastatingComboPhase;
                        }
                        else
                        {
                            me->CastSpell(me, SPELL_STOMP, false);
                            ++devastatingComboPhase;
                        }

                        uint8 maxComboPhase = pInstance->instance->IsHeroic() ? 10: 5;

                        if (devastatingComboPhase < maxComboPhase)
                            events.ScheduleEvent(EVENT_DEVASTATING_COMBO, 100); // Dont' update while casting
                        else
                        {
                            devastatingComboPhase = 0;

                            for (Player* player: playerList)
                                player->AddAura(SPELL_OPPORTUNISTIC_STRIKE, player);

                            events.ScheduleEvent(EVENT_DEVASTATING_COMBO, 15000);
                        }
                        break;
                    }
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_jin_qin_xiAI(creature);
        }
};

struct DefaultTargetSelectorWithMultiAura : public std::unary_function<Unit*, bool>
{
    const Unit* me;
    int32 m_aura1;
    int32 m_aura2;

    DefaultTargetSelectorWithMultiAura(Unit const* unit, int32 aura1, int32 aura2) : me(unit), m_aura1(aura1), m_aura2(aura2) { }

    bool operator()(Unit const* target) const
    {
        if (!me)
            return false;

        if (!target)
            return false;

        if (target->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (!target->HasAura(m_aura1) && !target->HasAura(m_aura2))
            return false;

        return true;
    }
};

class mob_woe_add_generic : public CreatureScript
{
    public:
        mob_woe_add_generic() : CreatureScript("mob_woe_add_generic") {}

        struct mob_woe_add_genericAI : public ScriptedAI
        {
            mob_woe_add_genericAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            uint64 targetGuid;
            EventMap events;
            InstanceScript* pInstance;

            void Reset()
            {
                if (!pInstance)
                    return;

                if (!pInstance || pInstance->GetBossState(DATA_WILL_OF_EMPEROR) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);

                float x = me->GetPositionX() + (15 * cos(me->GetOrientation()));
                float y = me->GetPositionY() + (15 * sin(me->GetOrientation()));

                me->GetMotionMaster()->MoveJump(x, y, 362.19f, 20.0f, 20.0f, 1);
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE
                 && uiType != EFFECT_MOTION_TYPE)
                    return;

                if (id == 1)
                {
                    DoZoneInCombat(me, 200.0f);
                    targetGuid = 0;
                    
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    switch (me->GetEntry())
                    {
                        case NPC_EMPEROR_RAGE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                targetGuid = target->GetGUID().GetEntry();
                                AttackStart(target);
                                me->getThreatManager().addThreat(target, 1000000.0f);

                                me->AddAura(SPELL_FOCALISED_ASSAULT, target);
                            }

                            me->AddAura(SPELL_WITHOUT_ARMOR, me);

                            events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                            break;
                        }
                        case NPC_EMPEROR_COURAGE:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, DefaultTargetSelectorWithMultiAura(me, SPELL_MAGNETIC_ARMOR_QIN_XI, SPELL_MAGNETIC_ARMOR_JAN_XI)); // Only tanks have these auras

                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM);

                            if (target)
                            {
                                targetGuid = target->GetGUID().GetEntry();
                                AttackStart(target);
                                me->getThreatManager().addThreat(target, 1000000.0f);

                                me->AddAura(SPELL_FOCALISED_DEFENSE, target);
                            }

                            me->AddAura(SPELL_HALF_PLATE, me);

                            events.ScheduleEvent(EVENT_IMPEDING_THRUST, 5000);
                            events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                            break;
                        }
                        case NPC_EMPEROR_STRENGHT:
                        {
                            events.ScheduleEvent(EVENT_ENERGIZING_SMASH, urand(5000, 10000));
                            me->AddAura(SPELL_FULL_PLATE, me);
                            break;
                        }
                    }
                }
            }

            void JustDied(Unit* attacker)
            {
                if (pInstance->instance->IsHeroic())
                    me->CastSpell(me, SPELL_SUMMON_TITAN_SPARK, true);
                
                /*if (me->GetEntry() == NPC_EMPEROR_RAGE)
                {
                    if (Unit* target = Unit::GetUnit(*me, targetGuid))
                        target->RemoveAurasDueToSpell(SPELL_FOCALISED_ASSAULT, me->GetGUID());
                }                
                else if (me->GetEntry() == NPC_EMPEROR_COURAGE)
                {
                    if (Unit* target = Unit::GetUnit(*me, targetGuid))
                        target->RemoveAurasDueToSpell(SPELL_FOCALISED_DEFENSE, me->GetGUID());
                }*/
            }
            
            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (me->GetEntry() == NPC_EMPEROR_COURAGE)
                    if (me->isInFront(attacker))
                        damage = 0;
            }

            void UpdateAI(uint32 diff)
            {
                if (!pInstance || pInstance->GetBossState(DATA_WILL_OF_EMPEROR) != IN_PROGRESS)
                    me->DespawnOrUnsummon();

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_TARGET:
                        {
                            bool shouldSwitchVictim = false;

                            if (me->GetVictim())
                            {
                                /*if (me->GetVictim()->GetGUID() != targetGuid)
                                {
                                    if (Unit* target = ObjectAccessor::FindUnit(targetGuid))
                                    {
                                        if (!target->IsAlive())
                                            shouldSwitchVictim = true;
                                    }
                                    else
                                        shouldSwitchVictim = true;
                                }
                                else
                                {
                                    if (Unit* target = ObjectAccessor::FindUnit(targetGuid))
                                    {
                                        if (target->IsAlive())
                                        {
                                            me->getThreatManager().resetAllAggro();
                                            targetGuid = target->GetGUID();
                                            AttackStart(target);
                                            me->getThreatManager().addThreat(target, 1000000.0f);
                                            me->AddAura(me->GetEntry() == NPC_EMPEROR_RAGE ? SPELL_FOCALISED_ASSAULT: SPELL_FOCALISED_DEFENSE, target);
                                        }
                                    }
                                }*/
                            }

                            if (shouldSwitchVictim)
                            {
                                me->getThreatManager().resetAllAggro();
                                DoZoneInCombat(me, 200.0f);
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                {
                                    targetGuid = target->GetGUID().GetEntry();
                                    AttackStart(target);
                                    me->getThreatManager().addThreat(target, 1000000.0f);
                                    me->AddAura(me->GetEntry() == NPC_EMPEROR_RAGE ? SPELL_FOCALISED_ASSAULT: SPELL_FOCALISED_DEFENSE, target);
                                }
                            }
                            events.ScheduleEvent(EVENT_CHECK_TARGET, 2000);
                            break;
                        }
                        // Courage
                        case EVENT_IMPEDING_THRUST:
                        {
                            if (Unit* victim = me->GetVictim())
                            {
                                if (me->IsWithinMeleeRange(victim))
                                {
                                    me->CastSpell(victim, SPELL_IMPEDING_THRUST, false);
                                    events.ScheduleEvent(EVENT_IMPEDING_THRUST, 10000);
                                }
                                else
                                    events.ScheduleEvent(EVENT_IMPEDING_THRUST, 2000);
                            }
                            else
                                events.ScheduleEvent(EVENT_IMPEDING_THRUST, 2000);
                            break;
                        }
                        // Strenght
                        case EVENT_ENERGIZING_SMASH:
                        {
                            me->CastSpell(me, SPELL_ENERGIZING_SMASH, false);
                            events.ScheduleEvent(EVENT_ENERGIZING_SMASH, urand(5000, 10000));
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_woe_add_genericAI(creature);
        }
};

class mob_woe_titan_spark : public CreatureScript
{
    public:
        mob_woe_titan_spark() : CreatureScript("mob_woe_titan_spark") {}

        struct mob_woe_titan_sparkAI : public ScriptedAI
        {
            mob_woe_titan_sparkAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            uint32 distanceCheckTimer;
            uint64 targetGuid;

            void Reset()
            {
                if (!pInstance || pInstance->GetBossState(DATA_WILL_OF_EMPEROR) != IN_PROGRESS)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                targetGuid = 0;
                distanceCheckTimer = 500;

                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    targetGuid = target->GetGUID().GetEntry();
                    AttackStart(target);
                    me->getThreatManager().addThreat(target, 1000000.0f);
                    me->AddAura(SPELL_FOCALISED_ENERGY, target);
                }
            }

            void JustDied(Unit* attacker)
            {
                me->CastSpell(me, SPELL_ENERGY_OF_CREATION, false);

                //if (Unit* target = Unit::GetUnit(*me, targetGuid))
                  //  target->RemoveAurasDueToSpell(SPELL_FOCALISED_ENERGY, me->GetGUID());
            }

            void UpdateAI(uint32 diff) 
            {
                if (distanceCheckTimer <= diff)
                {
                    if (me->SelectNearestPlayer())
                        me->Kill(me);
                    distanceCheckTimer = 500;
                }
                else
                    distanceCheckTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_woe_titan_sparkAI(creature);
        }
};

// Ancient Control Console - 211584
class go_ancient_control_console : public GameObjectScript
{
    public:
        go_ancient_control_console() : GameObjectScript("go_ancient_control_console") { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (InstanceScript* pInstance = player->GetInstanceScript())
            {
                pInstance->SetBossState(DATA_WILL_OF_EMPEROR, IN_PROGRESS);
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            return false;
        }
};

class spell_will_of_emperor_magnetic_armor : public SpellScriptLoader
{
    public:
        spell_will_of_emperor_magnetic_armor() : SpellScriptLoader("spell_will_of_emperor_magnetic_armor") { }

        class spell_will_of_emperor_magnetic_armor_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_will_of_emperor_magnetic_armor_AuraScript);

            void HandlePeriodicEffect0(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                if (Unit* victim = GetTarget()->GetVictim())
                {
                    uint32 triggerSpell = aurEff->GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
                    if (!victim->HasAura(triggerSpell))
                        GetTarget()->AddAura(triggerSpell, victim);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_will_of_emperor_magnetic_armor_AuraScript::HandlePeriodicEffect0, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_will_of_emperor_magnetic_armor_AuraScript();
        }
};

class spell_will_of_emperor_magnetic_armor_grip : public SpellScriptLoader
{
    public:
        spell_will_of_emperor_magnetic_armor_grip() : SpellScriptLoader("spell_will_of_emperor_magnetic_armor_grip") { }

        class spell_will_of_emperor_magnetic_armor_grip_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_will_of_emperor_magnetic_armor_grip_SpellScript);

            bool IsQinXi(Unit* caster)
            {
                if (!caster)
                    return false;

                return caster->GetEntry() == NPC_QIN_XI;
            }

            void CheckTargetsDist(std::list<WorldObject*>& targets)
            {
                targets.clear();

                Unit* caster = GetCaster();

                if (!caster)
                    return;

                InstanceScript* pInstance = caster->GetInstanceScript();

                //if (!pInstance)
                    return;

                Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();

                for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        if (player->HasAura(IsQinXi(caster) ? SPELL_MAGNETIC_ARMOR_QIN_XI: SPELL_MAGNETIC_ARMOR_JAN_XI))
                        {
                            if (caster->GetDistance(player) > 16.0f)
                            {
                                targets.push_back(player);
                            }
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_will_of_emperor_magnetic_armor_grip_SpellScript::CheckTargetsDist, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_will_of_emperor_magnetic_armor_grip_SpellScript();
        }
};

class CheckEnergizingSmashDistance
{
    public:
        CheckEnergizingSmashDistance(Unit* caster, uint32 maxDist) : _caster(caster), _maxDist(maxDist) {}

        bool operator()(WorldObject* target)
        {
            if (!_caster)
                return true;

            if (_caster->GetDistance(target) > _maxDist)
                return true;

            return false;
        }

    private:
        Unit* _caster;
        uint32 _maxDist;
};

class spell_energizing_smash : public SpellScriptLoader
{
    public:
        spell_energizing_smash() : SpellScriptLoader("spell_energizing_smash") { }

        class spell_energizing_smash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_energizing_smash_SpellScript);

            void CheckTargetsDist(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Unit* caster = GetCaster();

                if (!caster)
                    return;

                uint32 maxDist = 10;
                if (Aura* energized = caster->GetAura(SPELL_ENERGIZED))
                    maxDist += energized->GetStackAmount();

                targets.remove_if(CheckEnergizingSmashDistance(caster, maxDist));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energizing_smash_SpellScript::CheckTargetsDist, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energizing_smash_SpellScript::CheckTargetsDist, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_energizing_smash_SpellScript();
        }
};

void AddSC_boss_will_of_emperor()
{
    new boss_jin_qin_xi();
    new mob_woe_add_generic();
    new mob_woe_titan_spark();
    new go_ancient_control_console();
    new spell_will_of_emperor_magnetic_armor();
    new spell_will_of_emperor_magnetic_armor_grip();
    new spell_energizing_smash();
}
