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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CombatAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "the_everbloom.h"

enum eYalnuTalks
{
    ///< Yalnu
	GenesaurBossAggro = 40,  ///<(47096)
	GenesaurBossDeath = 41,  ///<(47094)

    ///< Lady Baihu
    LadyBaihuIntro    = 50 , ///< The portal is lost! we must stop the beast before it can escape!
    LadyBaihuAggro    = 51,  ///< We've got its attention!
    LadyBaihuSpell01  = 52,  ///< The vines are overtaking everything!
    LadyBaihuSpell02  = 53,  ///< Quickly. drow it towards the flames!
    LadyBaihuSpell03  = 54  ///< Look out!
};

enum YalnuEnums
{
    // Yalnu Pre
    ANIMKIT_PRE                             = 680,
    SPELL_TELEPORT_OUT                      = 142193,

    // Yalnu
    NPC_MAGE                                = 84329,
    NPC_COLOSSAL_BLOW                       = 84964,
    NPC_GROW_WEAPON                         = 84664,
    NPC_VICIOUS_MANDRAGORA                  = 84399,
    NPC_GNARLED_ANCIENT                     = 84400,
    NPC_SWIFT_SPROUTLING                    = 84401,
    ANIMKIT                                 = 6864,
    SPELL_VEHICLE_HARDCODED                 = 46598,
    SPELL_FONT_OF_LIFE_MISSILE              = 169120,
    SPELL_COLOSSAL_BLOW                     = 169756,
    SPELL_COLOSSAL_BLOW_YALNU               = 169179,
    SPELL_ENTANGLEMENT                      = 169251,
    SPELL_ENTANGLEMENT_UNIT_SPAWN           = 169237,
    SPELL_ENTANGLEMENT_PLAYER_SPAWN         = 170127,
    SPELL_ENTANGLEMENT_VISUAL               = 169192,
    SPELL_ENTANGLEMENT_PLAYER_DAMAGE        = 170132,
    SPELL_ENTANGLEMENT_UNIT_DAMAGE          = 169240,
    SPELL_GERMINATE_ARBORBLADE_DISARM       = 169320,
    SPELL_GERMINATE_ARBORBLADE              = 169265,
    SPELL_GERMINATE_ARBORBLADE_VISUAL       = 169266,
    SPELL_GERMINATE_ARBORBLADE_MOD_SIZE     = 169306,
    SPELL_GENESIS                           = 169390,
    SPELL_GENESIS_VISUAL                    = 169613,
};

/// Rp Yalnu - 84336
class boss_yalnu_pre : public CreatureScript
{
public:
    boss_yalnu_pre() : CreatureScript("boss_yalnu_pre") { }

    struct boss_yalnu_pre_AI : public ScriptedAI
    {
        boss_yalnu_pre_AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            introDone = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!me->IsHostileTo(who))
                return;

            if (who->IsPlayer() && me->IsWithinDistInMap(who, 50.0f) && !introDone)
            {
                introDone = true;
                me->PlayOneShotAnimKitId(ANIMKIT_PRE);
                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(0, 623.6406f, 1733.708f, 143.6253f);
            }
        }

        void UpdateAI(uint32 const /*diff*/) override {}
        void AttackStart(Unit* /*target*/) override {}

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 0)
            {
                DoCast(me, SPELL_TELEPORT_OUT);
                me->DespawnOrUnsummon(1000);
            }
        }

        private:

            bool introDone;

    };
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_yalnu_pre_AI(creature);
    }
};

// Yalnu - 83846
class boss_yalnu : public CreatureScript
{
public:
    boss_yalnu() : CreatureScript("boss_yalnu") { }

    struct boss_yalnu_AI : public VehicleAI
    {
        boss_yalnu_AI(Creature* pCreature) : VehicleAI(pCreature), instance(pCreature->GetInstanceScript()), summons(pCreature) { }

        void Reset() override
        {
            VehicleAI::Reset();

            introDone = 0;
            germinateArborbladeStep = 0;

            colossalBlowTimer = 5000;
            checkColossalBlowTimer = 0;
            entanglementTimer = 11000;
            germinateArborbladeTimer = 12000;
            germinateArborbladeStepTimer = 0;
            genesisTimer = 30000;
            fontLifeTimer = 15000;

            if (!me->IsAlive())
                return;

            me->ResetLootMode();
            summons.DespawnAll();

            std::list<Creature*> listMage;
            GetCreatureListWithEntryInGrid(listMage, me, NPC_MAGE, 500.0f);
            if (!listMage.empty())
            {
                for (std::list<Creature*>::const_iterator itr = listMage.begin(); itr != listMage.end(); ++itr)
                {
                    if ((*itr)->isDead())
                    {
                        (*itr)->Respawn(true);
                        (*itr)->AI()->EnterEvadeMode();
                    }
                }
            }

            if (instance && instance->GetBossState(DATA_YALNU) != DONE)
                instance->SetBossState(DATA_YALNU, NOT_STARTED);
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            me->setActive(true);
            DoZoneInCombat();
            if (instance)
                instance->SetBossState(DATA_YALNU, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            summons.DespawnAll();

            if (instance)
            {
                instance->SetBossState(DATA_YALNU, DONE);
                instance->SaveToDB();
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            VehicleAI::EnterEvadeMode();
        }

        void JustReachedHome() override
        {
            me->SetReactState(REACT_AGGRESSIVE);
        }

        bool playersInThreat()
        {
            const std::list<HostileReference*>& threatList = me->getThreatManager().getThreatList();
            if (threatList.empty())
                return false;

            for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
            {
                HostileReference* ref = (*itr);
                if (Unit* target = ref->getTarget())
                {
                    if (target->IsPlayer())
                        return true;
                }
            }
            return false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (introDone == 2)
            {
                if (me->CanStartAttack(who, false))
                {
                    AttackStart(who);
                    return;
                }
            }

            if (!me->IsHostileTo(who))
                return;

            if (who->IsPlayer() && me->IsWithinDistInMap(who, 10.0f) && introDone == 0)
            {
                introDone = 1;
                if (Creature* growWeapon = GetClosestCreatureWithEntry(me, NPC_GROW_WEAPON, 100.0f))
                    growWeapon->CastSpell(me, SPELL_VEHICLE_HARDCODED, true);

                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(0, 962.1129f, -1221.184f, 181.3097f);
                std::list<Creature*> listMage;
                GetCreatureListWithEntryInGrid(listMage, me, NPC_MAGE, 500.0f);
                if (!listMage.empty())
                {
                    for (std::list<Creature*>::const_iterator itr = listMage.begin(); itr != listMage.end(); ++itr)
                    {
                        if ((*itr)->AI())
                            (*itr)->AI()->DoAction(1);
                    }
                }
            }
        }

        void DamageTaken(Unit* done_by, uint32 &damage) override
        {
            if (!done_by->IsPlayer())
                me->LowerPlayerDamageReq(damage);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 0)
            {
                introDone = 2;
                me->SetWalk(true);

                me->PlayOneShotAnimKitId(ANIMKIT);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

                std::list<Creature*> listMage;
                GetCreatureListWithEntryInGrid(listMage, me, NPC_MAGE, 500.0f);
                if (!listMage.empty())
                {
                    for (std::list<Creature*>::const_iterator itr = listMage.begin(); itr != listMage.end(); ++itr)
                    {
                        if ((*itr)->AI())
                            (*itr)->AI()->DoAction(2);
                    }
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            if (me->IsInCombat())
                DoZoneInCombat(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void AttackStart(Unit* victim) override
        {
            if (victim)
                me->Attack(victim, true);
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            if (!playersInThreat())
            {
                EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                return;
            }

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            if (colossalBlowTimer <= diff)
            {
                colossalBlowTimer = urand(20000, 30000);
                checkColossalBlowTimer = 1000;
                DoCast(me, SPELL_COLOSSAL_BLOW);
            }
            else
                colossalBlowTimer -= diff;

            if (checkColossalBlowTimer > 0)
            {
                if (checkColossalBlowTimer <= diff)
                {
                    checkColossalBlowTimer = 0;
                    if (Creature* colossalblow = GetClosestCreatureWithEntry(me, NPC_COLOSSAL_BLOW, 100.0f))
                    {
                        me->SetTarget(ObjectGuid::Empty);
                        me->SetFacingToObject(colossalblow);
                        DoCast(me, SPELL_COLOSSAL_BLOW_YALNU);
                    }
                }
                else
                    checkColossalBlowTimer -= diff;
            }

            if (entanglementTimer <= diff)
            {
                entanglementTimer = 60000;
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f))
                    DoCast(target, SPELL_ENTANGLEMENT);
            }
            else
                entanglementTimer -= diff;

            if (germinateArborbladeTimer <= diff)
            {
                germinateArborbladeStep = 1;
                germinateArborbladeStepTimer = 1000;
                germinateArborbladeTimer = 48000;
                DoCast(me, SPELL_GERMINATE_ARBORBLADE_DISARM);
            }
            else
                germinateArborbladeTimer -= diff;

            if (germinateArborbladeStepTimer <= diff)
            {
                switch (germinateArborbladeStep)
                {
                    case 1:
                        DoCast(me, SPELL_GERMINATE_ARBORBLADE);
                        if (Creature* growWeapon = GetClosestCreatureWithEntry(me, NPC_GROW_WEAPON, 100.0f))
                            growWeapon->CastSpell(growWeapon, SPELL_GERMINATE_ARBORBLADE_VISUAL);

                        germinateArborbladeStepTimer = 500;
                        germinateArborbladeStep++;
                        break;
                    case 2:
                        if (Creature* growWeapon = GetClosestCreatureWithEntry(me, NPC_GROW_WEAPON, 100.0f))
                            growWeapon->CastSpell(growWeapon, SPELL_GERMINATE_ARBORBLADE_MOD_SIZE);

                        germinateArborbladeStepTimer = 3000;
                        germinateArborbladeStep++;
                        break;
                    case 3:
                        if (Creature* growWeapon = GetClosestCreatureWithEntry(me, NPC_GROW_WEAPON, 100.0f))
                        {
                            growWeapon->RemoveAurasDueToSpell(SPELL_GERMINATE_ARBORBLADE_VISUAL);
                            growWeapon->RemoveAurasDueToSpell(SPELL_GERMINATE_ARBORBLADE_MOD_SIZE);
                        }

                        germinateArborbladeStep = 0;
                        germinateArborbladeStepTimer = 0;
                        break;
                    default:
                        break;
                }
            }
            else
                germinateArborbladeStepTimer -= diff;

            if (genesisTimer <= diff)
            {
                genesisTimer = 60000;
                DoCast(me, SPELL_GENESIS);
                DoCast(me, SPELL_GENESIS_VISUAL);
            }
            else
                genesisTimer -= diff;

            if (fontLifeTimer <= diff)
            {
                fontLifeTimer = 15000;
                DoCast(me, SPELL_FONT_OF_LIFE_MISSILE);
            }
            else
                fontLifeTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

            uint8 introDone;
            uint8 germinateArborbladeStep;

            uint32 colossalBlowTimer;
            uint32 checkColossalBlowTimer;
            uint32 entanglementTimer;
            uint32 germinateArborbladeTimer;
            uint32 germinateArborbladeStepTimer;
            uint32 genesisTimer;
            uint32 fontLifeTimer;

            InstanceScript* instance;
            SummonList summons;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_yalnu_AI(creature);
    }
};

class spell_genesis_missile : public SpellScriptLoader
{
    public:
        spell_genesis_missile() : SpellScriptLoader("spell_genesis_missile") { }

        class spell_genesis_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_genesis_missile_SpellScript);

            void OnHit(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                uint32 triggered_spell_id = GetSpellInfo()->GetEffect(effIndex)->TriggerSpell;

                float angle = float(rand_norm()) * static_cast<float>(2 * M_PI);
                float dist = 35.0f;
                dist *= float(rand_norm());

                Position pos = GetCaster()->GetNearPosition(dist, angle);
                GetCaster()->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), triggered_spell_id, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_genesis_missile_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_genesis_missile_SpellScript();
        }
};

enum FeralLasherEnums
{
    SPELL_SUBMERGED = 175123,
    SPELL_GENESIS_LASHER = 173537,
    SPELL_GENESIS_TRAMPLED = 173539,
    SPELL_LASHER_VENOM = 173563,
};

/// Feral Lasher - 86684
class feral_lasher : public CreatureScript
{
public:
    feral_lasher() : CreatureScript("feral_lasher") { }

    struct feral_lasherAI : public ScriptedAI
    {
        feral_lasherAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            trampled = false;
            sprouts = false;

            sproutsTimer = 15000;
            lasherVenomTimer = 500;

            DoCast(me, SPELL_SUBMERGED);
            DoCast(me, SPELL_GENESIS_LASHER);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer() && me->IsWithinDistInMap(who, 1.5f) && !trampled && !sprouts)
            {
                trampled = true;
                DoCast(me, SPELL_GENESIS_TRAMPLED);
                me->RemoveAurasDueToSpell(SPELL_SUBMERGED);
                me->RemoveAurasDueToSpell(SPELL_GENESIS_LASHER);
                me->SetObjectScale(0.1f);
                me->DespawnOrUnsummon(2000);
            }

            if (trampled || !sprouts)
                return;

            ScriptedAI::MoveInLineOfSight(who);
        }

        void AttackStart(Unit* target) override
        {
            if (trampled || !sprouts)
                return;

            ScriptedAI::AttackStart(target);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!trampled && !sprouts)
            {
                if (sproutsTimer <= diff)
                {
                    sproutsTimer = 0;
                    sprouts = true;

                    me->RemoveAurasDueToSpell(SPELL_SUBMERGED);
                    me->RemoveAurasDueToSpell(SPELL_GENESIS_LASHER);

                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                }
                else
                    sproutsTimer -= diff;
            }

            if (!UpdateVictim() || !sprouts || trampled)
                return;

            if (lasherVenomTimer <= diff)
            {
                lasherVenomTimer = 3000;
                DoCast(me, SPELL_LASHER_VENOM);
            }
            else
                lasherVenomTimer -= diff;
        }

        private:

            bool trampled;
            bool sprouts;

            uint32 sproutsTimer;
            uint32 lasherVenomTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new feral_lasherAI(creature);
    }
};

class spell_genesis : public SpellScriptLoader
{
    public:
        spell_genesis() : SpellScriptLoader("spell_genesis") { }

        class spell_genesis_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_genesis_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                for (uint8 i = 0; i < 23; i++)
                    GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_genesis_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_genesis_SpellScript();
        }
};

enum SwiftSproutlingEnums
{
    SPELL_TENDON_RIP = 169876,
};

/// Swift Sproutling - 84401
class swift_sproutling : public CreatureScript
{
public:
    swift_sproutling() : CreatureScript("swift_sproutling") { }

    struct swift_sproutlingAI : public ScriptedAI
    {
        swift_sproutlingAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            tendonRipTimer = 6000;
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            me->SetObjectScale(1.0f);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (tendonRipTimer <= diff)
            {
                tendonRipTimer = 6000;
                DoCast(me->GetVictim(), SPELL_TENDON_RIP);
            }
            else
                tendonRipTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:

        uint32 tendonRipTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new swift_sproutlingAI(creature);
    }
};

enum FontLifeStalkerEnums
{
    SPELL_FONT_OF_LIFE = 169123,
};

/// Font of Life Stalker - 85107
class mob_font_life_stalker : public CreatureScript
{
public:
    mob_font_life_stalker() : CreatureScript("mob_font_life_stalker") { }

    struct mob_font_life_stalkerAI : public ScriptedAI
    {
        mob_font_life_stalkerAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            destroyTimer = 5000;
            DoCast(me, SPELL_FONT_OF_LIFE);
        }

        void MoveInLineOfSight(Unit*) override { }

        void AttackStart(Unit*) override { }

        void UpdateAI(uint32 diff) override
        {
            if (destroyTimer <= diff)
            {
                destroyTimer = 5000;
                me->DespawnOrUnsummon();
            }
            else
                destroyTimer -= diff;
        }

        private:

            uint32 destroyTimer;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_font_life_stalkerAI(creature);
    }
};

class spell_font_life : public SpellScriptLoader
{
public:
    spell_font_life() : SpellScriptLoader("spell_font_life") { }

    class spell_font_life_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_font_life_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            switch (urand(0, 2))
            {
                case 0:
                    for (uint8 i = 0; i < 2; i++)
                    {
                        Position pos = GetCaster()->GetRandomNearPosition(3.0f);
                        GetCaster()->SummonCreature(NPC_VICIOUS_MANDRAGORA, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                    }
                    break;
                case 1:
                    GetCaster()->SummonCreature(NPC_GNARLED_ANCIENT, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ());
                    break;
                case 2:
                    for (uint8 i = 0; i < 8; i++)
                    {
                        Position pos = GetCaster()->GetRandomNearPosition(3.0f);
                        GetCaster()->SummonCreature(NPC_SWIFT_SPROUTLING, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                    }
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_font_life_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_font_life_AuraScript();
    }
};

/// Entanglement - 85194
class entanglement_player : public CreatureScript
{
public:
    entanglement_player() : CreatureScript("entanglement_player") { }

    struct entanglement_playerAI : public ScriptedAI
    {
        entanglement_playerAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            attack = false;
            DoCast(me, SPELL_ENTANGLEMENT_VISUAL);
        }

        void AttackStart(Unit* /*victim*/) override { }

        void UpdateAI(const uint32 /*diff*/) override
        {
            if (!attack)
            {
                attack = true;
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_ENTANGLEMENT_PLAYER_DAMAGE);
            }

            if (!UpdateVictim())
                return;
        }

        private:
            bool attack;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new entanglement_playerAI(creature);
    }
};

/// Entanglement - 84499
class entanglement_mob : public CreatureScript
{
public:
    entanglement_mob() : CreatureScript("entanglement_mob") { }

    struct entanglement_mobAI : public ScriptedAI
    {
        entanglement_mobAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            attack = false;
            DoCast(me, SPELL_ENTANGLEMENT_VISUAL);
        }

        void AttackStart(Unit* /*victim*/) override { }

        void UpdateAI(const uint32 /*diff*/) override
        {
            if (!attack)
            {
                attack = true;
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                DoCast(me, SPELL_ENTANGLEMENT_PLAYER_DAMAGE);
            }

            if (!UpdateVictim())
                return;
        }

        private:
            bool attack;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new entanglement_mobAI(creature);
    }
};

class spell_entanglement_missile : public SpellScriptLoader
{
    public:
        spell_entanglement_missile() : SpellScriptLoader("spell_entanglement_missile") { }

        class spell_entanglement_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_entanglement_missile_SpellScript);

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                if (GetExplTargetUnit())
                {
                    switch (GetExplTargetUnit()->GetTypeId())
                    {
                        case TYPEID_UNIT:
                            GetExplTargetUnit()->CastSpell(GetExplTargetUnit(), SPELL_ENTANGLEMENT_UNIT_SPAWN);
                            break;
                        case TYPEID_PLAYER:
                            GetExplTargetUnit()->CastSpell(GetExplTargetUnit(), SPELL_ENTANGLEMENT_PLAYER_SPAWN);
                            break;
                        default:
                            break;
                    }
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_entanglement_missile_SpellScript::OnHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_entanglement_missile_SpellScript();
        }
};

enum MageEnums
{
    SPELL_FROSTBOLT     = 170028,
    SPELL_FIREBALL      = 168666,
    SPELL_ARCANE_BLAST  = 170035,
    SPELL_ICE_COMET     = 170032,
    SPELL_FLAMESTRIKE   = 169094,
    SPELL_ARCANE_ORB    = 170040,
};

/// Kirin Tor Mage - 84329
class kirin_tor_mage : public CreatureScript
{
public:
    kirin_tor_mage() : CreatureScript("kirin_tor_mage") { }

    struct kirin_tor_mageAI : public ScriptedAI
    {
        kirin_tor_mageAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            school = urand(0, 2);

            frostboltTimer      = 500;
            fireballTimer       = 500;
            arcaneBlastTimer    = 500;
            iceCometTimer       = 24000;
            flamestrikeTimer    = 17000;
            arcaneOrbTimer      = 26000;
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case 1:
                    switch (me->GetGUID().GetCounter())
                    {
                        case 10645521:
                            me->NearTeleportTo(971.925f, -1234.89f, 181.249f, 5.43932f);
                            DoCast(me, SPELL_TELEPORT_OUT, true);
                            break;
                        case 10645518:
                            me->NearTeleportTo(966.347f, -1208.15f, 181.251f, 2.396894f);
                            DoCast(me, SPELL_TELEPORT_OUT, true);
                            break;
                        case 10645520:
                            me->NearTeleportTo(974.745f, -1213.61f, 181.249f, 0.2994629f);
                            DoCast(me, SPELL_TELEPORT_OUT, true);
                            break;
                        default:
                            break;
                    }
                    break;
                case 2:
                    switch (me->GetGUID().GetCounter())
                    {
                        case 10645513:
                            me->NearTeleportTo(948.651f, -1231.84f, 181.249f, 0.9716969f);
                            DoCast(me, SPELL_TELEPORT_OUT, true);
                            break;
                        case 10645517:
                            me->NearTeleportTo(954.493f, -1239.93f, 181.249f, 3.487406f);
                            DoCast(me, SPELL_TELEPORT_OUT, true);
                            break;
                        case 10645519:
                            me->SetWalk(false);
                            me->GetMotionMaster()->MovePoint(0, 953.743f, -1217.682f, 181.3097f);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        void AttackStart(Unit* victim) override
        {
            if (victim)
                me->Attack(victim, true);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (school)
            {
                case 0:
                    if (fireballTimer <= diff)
                    {
                        fireballTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_FIREBALL);
                    }
                    else
                        fireballTimer -= diff;

                    if (flamestrikeTimer <= diff)
                    {
                        flamestrikeTimer = 30000;
                        DoCast(me, SPELL_FLAMESTRIKE);
                    }
                    else
                        flamestrikeTimer -= diff;

                    break;
                case 1:
                    if (frostboltTimer <= diff)
                    {
                        frostboltTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_FROSTBOLT);
                    }
                    else
                        frostboltTimer -= diff;

                    if (iceCometTimer <= diff)
                    {
                        iceCometTimer = 36000;
                        DoCast(me, SPELL_ICE_COMET);
                    }
                    else
                        iceCometTimer -= diff;

                    break;
                case 2:
                    if (arcaneBlastTimer <= diff)
                    {
                        arcaneBlastTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_ARCANE_BLAST);
                    }
                    else
                        arcaneBlastTimer -= diff;

                    if (arcaneOrbTimer <= diff)
                    {
                        arcaneOrbTimer = 30000;
                        DoCast(me, SPELL_ARCANE_ORB);
                    }
                    else
                        arcaneOrbTimer -= diff;

                    break;
                default:
                    break;
            }
        }

        private:

            uint8 school;
            uint32 frostboltTimer;
            uint32 fireballTimer;
            uint32 iceCometTimer;
            uint32 flamestrikeTimer;
            uint32 arcaneBlastTimer;
            uint32 arcaneOrbTimer;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new kirin_tor_mageAI(creature);
    }
};

/// Lady Baihu - 84358
class lady_baihu : public CreatureScript
{
public:
    lady_baihu() : CreatureScript("lady_baihu") { }

    struct lady_baihuAI : public ScriptedAI
    {
        lady_baihuAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            school = urand(0, 2);

            frostboltTimer = 500;
            fireballTimer = 500;
            arcaneBlastTimer = 500;
            iceCometTimer = 24000;
            flamestrikeTimer = 17000;
            arcaneOrbTimer = 26000;
        }

        void AttackStart(Unit* victim) override
        {
            if (victim)
                me->Attack(victim, true);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (school)
            {
                case 0:
                    if (fireballTimer <= diff)
                    {
                        fireballTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_FIREBALL);
                    }
                    else
                        fireballTimer -= diff;

                    if (flamestrikeTimer <= diff)
                    {
                        flamestrikeTimer = 30000;
                        DoCast(me, SPELL_FLAMESTRIKE);
                    }
                    else
                        flamestrikeTimer -= diff;

                    break;
                case 1:
                    if (frostboltTimer <= diff)
                    {
                        frostboltTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_FROSTBOLT);
                    }
                    else
                        frostboltTimer -= diff;

                    if (iceCometTimer <= diff)
                    {
                        iceCometTimer = 36000;
                        DoCast(me, SPELL_ICE_COMET);
                    }
                    else
                        iceCometTimer -= diff;

                    break;
                case 2:
                    if (arcaneBlastTimer <= diff)
                    {
                        arcaneBlastTimer = urand(2000, 3000);
                        DoCast(me->GetVictim(), SPELL_ARCANE_BLAST);
                    }
                    else
                        arcaneBlastTimer -= diff;

                    if (arcaneOrbTimer <= diff)
                    {
                        arcaneOrbTimer = 30000;
                        DoCast(me, SPELL_ARCANE_ORB);
                    }
                    else
                        arcaneOrbTimer -= diff;

                    break;
                default:
                    break;
            }
        }

        private:

            uint8 school;
            uint32 frostboltTimer;
            uint32 fireballTimer;
            uint32 iceCometTimer;
            uint32 flamestrikeTimer;
            uint32 arcaneBlastTimer;
            uint32 arcaneOrbTimer;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new lady_baihuAI(creature);
    }
};

enum FlamestrikeEnums
{
    SPELL_FLAMSTRIKE_DAMAGE            = 169100,
};

class at_flamestrike : public AreaTriggerAI
{
public:
    at_flamestrike(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    /*void OnCreate() override
    {
        at->SetCustomRadius(6.0f);
    }*/

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* yalnu = GetClosestCreatureWithEntry(unit, NPC_YALNU, 100.0f))
        {
            if (yalnu->IsHostileTo(unit) && !unit->HasAura(SPELL_FLAMSTRIKE_DAMAGE))
                yalnu->CastSpell(unit, SPELL_FLAMSTRIKE_DAMAGE, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_FLAMSTRIKE_DAMAGE);
    }
};

enum ArcaneOrbEnums
{
    SPELL_ARCANE_ORB_DAMAGE = 170077,
};

class at_arcane_orb : public AreaTriggerAI
{
public:
    at_arcane_orb(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnCreate() override
    {
        if (Creature* yalnu = GetClosestCreatureWithEntry(at, NPC_YALNU, 100.0f))
            at->SetDestination(yalnu->GetPosition(), 2000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* yalnu = GetClosestCreatureWithEntry(unit, NPC_YALNU, 100.0f))
        {
            if (yalnu->IsHostileTo(unit) && !unit->HasAura(SPELL_ARCANE_ORB_DAMAGE))
                yalnu->CastSpell(unit, SPELL_ARCANE_ORB_DAMAGE, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_ARCANE_ORB_DAMAGE);
    }
};

enum NoxiousBreathEnums
{
    SPELL_NOXIOUS_BREATH            = 169879,
};

class at_noxious_breath : public AreaTriggerAI
{
public:
    at_noxious_breath(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Creature* mandragora = GetClosestCreatureWithEntry(unit, NPC_VICIOUS_MANDRAGORA, 100.0f))
        {
            if (mandragora->IsHostileTo(unit) && !unit->HasAura(SPELL_NOXIOUS_BREATH))
                mandragora->CastSpell(unit, SPELL_NOXIOUS_BREATH, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_NOXIOUS_BREATH);
    }
};

void AddSC_boss_yalnu()
{
    new boss_yalnu_pre();
    new boss_yalnu();
    new spell_genesis_missile();
    new feral_lasher();
    new spell_genesis();
    new swift_sproutling();
    new mob_font_life_stalker();
    new spell_font_life();
    new entanglement_player();
    new entanglement_mob();
    new spell_entanglement_missile();
    new kirin_tor_mage();
    new lady_baihu();
    RegisterAreaTriggerAI(at_flamestrike);
    RegisterAreaTriggerAI(at_arcane_orb);
    RegisterAreaTriggerAI(at_noxious_breath);
}
