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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "the_everbloom.h"
#include "G3D/Vector3.h"

enum XeritacSpells
{
    GO_TOXIC_EGGS                = 234113,

    NPC_XERITAC_VEHICLE          = 84666,
    NPC_TOXIC_SPIDERLING         = 84552,
    NPC_VENOM_SPRAYER            = 86547,
    NPC_GORGED_BURSTER           = 86552,
    NPC_VENOM_CRAZED             = 84554,

    SPELL_EJECT_ALL_PASSENGERS   = 50630,

    SPELL_WEB_CRAWL_1            = 169271,
    SPELL_DESCEND_1              = 169272,
    SPELL_DESCEND_2              = 169275,
    SPELL_DESCEND_3              = 172643,
    SPELL_WEB_CRAWL_2            = 169293,
    SPELL_TOXIC_GAS_XERITAC      = 169224,
    SPELL_TOXIC_GAS_MISSILE      = 169270,
    SPELL_TOXIC_BOLT             = 169375,
    SPELL_VENOMOUS_STING         = 169376,
    SPELL_GASEOUS_VOLLEY         = 169382,
    SPELL_GASEOUS_VOLLEY_MISSILE = 169383,
    SPELL_CONSUME_VEHICLE        = 169249,
    SPELL_CONSUME                = 169248,
    SPELL_DESPAWN_AREA_TRIGGERS  = 138175,
};

/// Xeri'tac (Vehicle) - 84666
class xeri_tac_vehicle : public CreatureScript
{
public:
    xeri_tac_vehicle() : CreatureScript("xeri_tac_vehicle") { }

    struct xeri_tac_vehicleAI : public VehicleAI
    {
        xeri_tac_vehicleAI(Creature* creature) : VehicleAI(creature) {}

        void Reset() override
        {
            VehicleAI::Reset();

            descend = false;
            chargeTimer = 500;
            me->SetWalk(false);
        }

        void AttackStart(Unit* victim) override
        {
            if (victim)
                me->Attack(victim, false);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case 2:
                    DoCast(me, SPELL_EJECT_ALL_PASSENGERS);
                    me->DespawnOrUnsummon(1000);
                    break;
                default:
                    break;
            }
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_DESCEND_1:
                    descend = true;
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                        me->GetMotionMaster()->MovementExpired();
                    break;
                case SPELL_WEB_CRAWL_2:
                    chargeTimer = 5000;
                    descend = false;
                    break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!descend)
            {
                if (chargeTimer <= diff)
                {
                    chargeTimer = 5000;
                    if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 500.0f))
                    {
                        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), me->GetPositionZ());
                    }
                }
                else
                    chargeTimer -= diff;
            }
        }

        private:
            bool descend;

            uint32 chargeTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new xeri_tac_vehicleAI(creature);
    }
};

// Xeri'tac - 84550
class boss_xeritac : public CreatureScript
{
public:
    boss_xeritac() : CreatureScript("boss_xeritac") { }

    struct boss_xeritacAI : public BossAI
    {
        boss_xeritacAI(Creature* pCreature) : BossAI(pCreature, DATA_XERITAC) {}

        void Reset() override
        {
            _Reset();

            state = 0;
            killCount = 0;
            descendTimer = 6000;
            addTimer = 500;
            venomCrazedTimer = 20000;
            toxicBoltTimer = 5000;
            venomousStingTimer = 14000;
            gaseousVolleyTimer = 20000;
            consumeTimer = 40000;

            DoCast(me, SPELL_DESPAWN_AREA_TRIGGERS);
            if (Creature* veh_xeritac = me->SummonCreature(NPC_XERITAC_VEHICLE, 937.5052f, 1438.911f, 89.0f, 0.0f))
                DoCast(veh_xeritac, SPELL_WEB_CRAWL_1);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (damage >= me->GetHealth())
                DoCast(me, SPELL_DESPAWN_AREA_TRIGGERS);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case 1:
                {
                    state = 1;

                    std::list<GameObject*> goList;
                    GetGameObjectListWithEntryInGrid(goList, me, GO_TOXIC_EGGS, 100.0f);
                    if (!goList.empty())
                        for (std::list<GameObject*>::const_iterator itr = goList.begin(); itr != goList.end(); ++itr)
                            (*itr)->Delete();
                    break;
                }
                default:
                    break;
            }
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            switch (summon->GetEntry())
            {
                case NPC_TOXIC_SPIDERLING:
                    me->CastSpell(summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ(), SPELL_TOXIC_GAS_XERITAC, true);

                    killCount++;
                    if (killCount >= 8)
                    {
                        state = 2;
                        if (Creature* xeritac = GetClosestCreatureWithEntry(me, NPC_XERITAC_VEHICLE, 100.0f))
                            xeritac->AI()->DoAction(2);

                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    }
                    break;
            }
        }

        void AttackStart(Unit* victim) override
        {
            if (state >= 2)
                BossAI::AttackStart(victim);
            else
                me->Attack(victim, false);
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            switch (state)
            {
                case 1:
                    if (descendTimer <= diff)
                    {
                        descendTimer = 17000;
                        if (Creature* veh_xeritac = GetClosestCreatureWithEntry(me, NPC_XERITAC_VEHICLE, 100.0f))
                        {
                            DoCast(veh_xeritac, SPELL_DESCEND_1);
                            //me->EnterVehicle(veh_xeritac, 1);
                        }
                        DoCast(me, SPELL_DESCEND_3);
                        //DoCast(me, SPELL_TOXIC_GAS_MISSILE); A confirmer
                    }
                    else
                        descendTimer -= diff;

                    if (addTimer <= diff)
                    {
                        addTimer = 15000;
                        me->SummonCreature(NPC_TOXIC_SPIDERLING, 935.9139f, 1446.727f, 86.68246f, 2.888725f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                        me->SummonCreature(NPC_VENOM_SPRAYER, 929.7065f, 1437.282f, 86.69052f, 3.35384f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                        // Todo : Gorged Burster
                    }
                    else
                        addTimer -= diff;
                    break;
                case 2:
                    if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                        break;

                    if (toxicBoltTimer <= diff)
                    {
                        toxicBoltTimer = 22000;
                        DoCast(me->GetVictim(), SPELL_TOXIC_BOLT);
                    }
                    else
                        toxicBoltTimer -= diff;

                    if (venomousStingTimer <= diff)
                    {
                        venomousStingTimer = urand(20000, 25000);
                        DoCast(me, SPELL_VENOMOUS_STING);
                    }
                    else
                        venomousStingTimer -= diff;

                    if (gaseousVolleyTimer <= diff)
                    {
                        gaseousVolleyTimer = 30000;
                        DoCast(me, SPELL_GASEOUS_VOLLEY);
                    }
                    else
                        gaseousVolleyTimer -= diff;

                    if (consumeTimer <= diff)
                    {
                        consumeTimer = 40000;
                        me->CastSpell((Unit*)NULL, SPELL_CONSUME_VEHICLE);
                        me->CastSpell((Unit*)NULL, SPELL_CONSUME);
                        //DoCast(me, SPELL_CONSUME_VEHICLE);
                        //DoCast(me, SPELL_CONSUME);
                    }
                    else
                        consumeTimer -= diff;

                    DoMeleeAttackIfReady();
                    break;
                default:
                    break;
            }

            if (venomCrazedTimer <= diff)
            {
                venomCrazedTimer = 30000;
                me->SummonCreature(NPC_VENOM_CRAZED, 900.8246f, 1441.398f, 66.09056f, 6.064884f);
            }
            else
                venomCrazedTimer -= diff;
        }

        private:
            uint8 state;
            uint8 killCount;

            uint32 descendTimer;
            uint32 addTimer;
            uint32 venomCrazedTimer;
            uint32 toxicBoltTimer;
            uint32 venomousStingTimer;
            uint32 gaseousVolleyTimer;
            uint32 consumeTimer;
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_xeritacAI(pCreature);
    }
};

enum ToxicSpiderlingSpells
{
    SPELL_DESCEND_ADDS = 169322,
    SPELL_TOXIC_BLOOD = 169218,
};

/// Toxic Spiderling - 84552
class toxic_spiderling : public CreatureScript
{
public:
    toxic_spiderling() : CreatureScript("toxic_spiderling") { }

    struct toxic_spiderlingAI : public ScriptedAI
    {
        toxic_spiderlingAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            isArrived = false;
            checkGroundTimer = 500;

            me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_VEHICLE_PASSENGER_IS_TRANSITION_ALLOWED);
            me->GetMotionMaster()->MoveJump(920.1979f, 1443.384f, 63.60683f, 0.0f, 5.0f, 2.0f);
            DoCast(me, SPELL_DESCEND_ADDS);
            DoCast(me, SPELL_TOXIC_BLOOD);
        }

        void AttackStart(Unit* target) override
        {
            if (isArrived)
                ScriptedAI::AttackStart(target);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!isArrived)
            {
                if (checkGroundTimer <= diff)
                {
                    checkGroundTimer = 500;
                    float ground = me->GetPositionZ();
                    me->GetMap()->GetWaterOrGroundLevel(me->GetPhaseShift(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), &ground);
                    bool isInAir = G3D::fuzzyGt(me->GetPositionZ(), ground + 0.05f) || G3D::fuzzyLt(me->GetPositionZ(), ground - 0.05f);
                    if (!isInAir)
                    {
                        me->RemoveAurasDueToSpell(SPELL_DESCEND_ADDS);
                        me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_VEHICLE_PASSENGER_IS_TRANSITION_ALLOWED);
                        isArrived = true;
                    }
                }
                else
                    checkGroundTimer -= diff;
            }

            if (!UpdateVictim() || !isArrived)
                return;

            DoMeleeAttackIfReady();
        }

        private:
            bool isArrived;

            uint32 checkGroundTimer;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new toxic_spiderlingAI(creature);
    }
};

enum VenomSprayerSpells
{
    SPELL_VENOM_SPRAY = 173052,
};

/// Venom Sprayer - 86547
class venom_sprayer : public CreatureScript
{
public:
    venom_sprayer() : CreatureScript("venom_sprayer") { }

    struct venom_sprayerAI : public ScriptedAI
    {
        venom_sprayerAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            isArrived = false;
            venomSprayTimer = 3000;
            checkGroundTimer = 500;

            me->AddExtraUnitMovementFlag(MOVEMENTFLAG2_VEHICLE_PASSENGER_IS_TRANSITION_ALLOWED);
            me->GetMotionMaster()->MoveJump(929.7066f, 1437.231f, 63.81386f, 0.0f, 5.0f, 2.0f);
            DoCast(me, SPELL_DESCEND_ADDS);
            DoCast(me, SPELL_TOXIC_BLOOD);
        }

        void AttackStart(Unit* target) override
        {
            if (isArrived)
                ScriptedAI::AttackStart(target);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!isArrived)
            {
                if (checkGroundTimer <= diff)
                {
                    checkGroundTimer = 500;
                    float ground = me->GetPositionZ();
                    me->GetMap()->GetWaterOrGroundLevel(me->GetPhaseShift(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), &ground);
                    bool isInAir = G3D::fuzzyGt(me->GetPositionZ(), ground + 0.05f) || G3D::fuzzyLt(me->GetPositionZ(), ground - 0.05f);
                    if (!isInAir)
                    {
                        me->RemoveAurasDueToSpell(SPELL_DESCEND_ADDS);
                        me->RemoveExtraUnitMovementFlag(MOVEMENTFLAG2_VEHICLE_PASSENGER_IS_TRANSITION_ALLOWED);
                        isArrived = true;
                    }
                }
                else
                    checkGroundTimer -= diff;
            }

            if (!UpdateVictim() || !isArrived)
                return;

            if (venomSprayTimer <= diff)
            {
                venomSprayTimer = 2000;
                DoCast(me, SPELL_VENOM_SPRAY);
            }
            else
                venomSprayTimer -= diff;

            DoMeleeAttackIfReady();
        }

        private:
            bool isArrived;

            uint32 venomSprayTimer;
            uint32 checkGroundTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new venom_sprayerAI(creature);
    }
};

enum VenomCrazedSpells
{
    SPELL_INHALE = 169233,
    SPELL_TOXIC_GAS = 169234,
    SPELL_SWIPE = 169371,
};

/// Venom-Crazed Pale One - 84554
class venom_crazed : public CreatureScript
{
public:
    venom_crazed() : CreatureScript("venom_crazed") { }

    struct venom_crazedAI : public VehicleAI
    {
        venom_crazedAI(Creature* creature) : VehicleAI(creature) {}

        void Reset() override
        {
            VehicleAI::Reset();

            isGased = false;

            swipeTimer = 1000;
        }

        void MoveInLineOfSight(Unit* who) override 
        {
            CreatureAI::MoveInLineOfSight(who);
        }

        void AttackStart(Unit* victim) override
        {
            CreatureAI::AttackStart(victim);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_INHALE:
                    isGased = true;
                    me->SetDisplayId(58558);
                    break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (isGased)
            {
                if (swipeTimer <= diff)
                {
                    swipeTimer = 10000;
                    DoCast(me, SPELL_SWIPE);
                }
                else
                    swipeTimer -= diff;
            }
            DoMeleeAttackIfReady();
        }

        private:
            bool isGased;

            uint32 swipeTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new venom_crazedAI(creature);
    }
};

class spell_gaseous_volley : public SpellScriptLoader
{
    public:
        spell_gaseous_volley() : SpellScriptLoader("spell_gaseous_volley") { }

        class spell_gaseous_volley_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gaseous_volley_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell((Unit*)NULL, SPELL_GASEOUS_VOLLEY_MISSILE, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_gaseous_volley_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gaseous_volley_SpellScript();
        }
};

enum ToxicBloodSpells
{
    SPELL_TOXIC_BLOOD_KILL = 169267,
};

class spell_toxic_blood : public SpellScriptLoader
{
public:
    spell_toxic_blood() : SpellScriptLoader("spell_toxic_blood") { }

    class spell_toxic_blood_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_toxic_blood_AuraScript);

        void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
        {
            if (GetTarget())
            {
                if (GetStackAmount() >= 10)
                    GetTarget()->CastSpell(GetTarget(), SPELL_TOXIC_BLOOD_KILL);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_toxic_blood_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_toxic_blood_AuraScript();
    }
};

enum ToxicGasSpells
{
    SPELL_TOXIC_GAS_DAMAGE = 169223,
};

class at_toxic_gas : public AreaTriggerAI
{
public:
    at_toxic_gas(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    /*void OnCreate() override
    {
        at->SetCustomRadius(4.0f);
    }*/

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetTypeId() == TYPEID_UNIT)
        {
            switch (unit->GetEntry())
            {
                case NPC_VENOM_CRAZED:
                    if (!unit->HasAura(SPELL_TOXIC_GAS))
                    {
                        unit->CastSpell(unit, SPELL_TOXIC_GAS);
                        unit->CastSpell(unit, SPELL_INHALE);
                    }
                    break;
                default:
                    break;
            }
            return;
        }

        if (unit->IsPlayer())
        {
            if (!unit->HasAura(SPELL_TOXIC_GAS_DAMAGE))
            {
                if (Creature* xeritac = GetClosestCreatureWithEntry(unit, NPC_XERITAC, 100.0f))
                    xeritac->CastSpell(unit, SPELL_TOXIC_GAS_DAMAGE);
            }
            return;
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->RemoveAurasDueToSpell(SPELL_TOXIC_GAS_DAMAGE);
    }
};

// Toxic Eggs - 234113
class toxic_eggs_go : public GameObjectScript
{
public:
    toxic_eggs_go() : GameObjectScript("toxic_eggs_go") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* xeritac = GetClosestCreatureWithEntry(go, NPC_XERITAC, 100.0f))
        {
            xeritac->AI()->AttackStart(player);
            xeritac->AI()->DoZoneInCombat(xeritac, 500.0f);
        }

        if (Creature* vehicle = GetClosestCreatureWithEntry(go, NPC_XERITAC_VEHICLE, 100.0f))
        {
            vehicle->AI()->AttackStart(player);
            vehicle->AI()->DoZoneInCombat(vehicle, 500.0f);
        }

        go->UseDoorOrButton();
        return true;
    }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* /*unit*/) override
    {
        switch (state)
        {
            case GO_ACTIVATED:
                if (Creature* xeritac = GetClosestCreatureWithEntry(go, NPC_XERITAC, 100.0f))
                    xeritac->AI()->DoAction(1);
                break;
            default:
               break;
        }
    }
};

void AddSC_boss_xeritac()
{
    new xeri_tac_vehicle();
    new boss_xeritac();
    new toxic_spiderling();
    new venom_sprayer();
    new venom_crazed();
    new spell_gaseous_volley();
    new spell_toxic_blood();
    RegisterAreaTriggerAI(at_toxic_gas);
    new toxic_eggs_go();
}
