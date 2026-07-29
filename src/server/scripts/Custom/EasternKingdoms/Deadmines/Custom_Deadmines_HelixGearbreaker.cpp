/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ThreatManager.h"
#include "Vehicle.h"
#include "SpellAuras.h"
#include "SpellDefines.h"
#include "Map.h"
#include "TemporarySummon.h"
#include <vector>
#include <iterator>

#include "Custom_Instance_Deadmines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    // 49136 - Helix Crew
    struct npc_helix_crew : public ScriptedAI
    {
        npc_helix_crew(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            ApplyCrowdControlImmunities(me);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        }

        void Reset() override
        {
            ScriptedAI::Reset();
            _events.Reset();
            summons.DespawnAll();
            _events.RescheduleEvent(Events::HelixCrewStickyBomb, 8s, 30s);
        }

        void IsSummonedBy(WorldObject* summoner) override
        {
            if (summoner && summoner->ToCreature())
                _helixGUID = summoner->GetGUID();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void JustDied(Unit* /*killer*/) override
        {
            summons.DespawnAll();
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::HelixCrewStickyBomb:
                    {
                        Unit* target = nullptr;
                        if (Creature* helix = ObjectAccessor::GetCreature(*me, _helixGUID))
                        {
                            if (helix->GetThreatManager().GetThreatListSize() > 0)
                            {
                                std::vector<ThreatReference*> threatList = helix->GetThreatManager().GetModifiableThreatList();
                                if (!threatList.empty())
                                {
                                    auto it = threatList.begin();
                                    std::advance(it, urand(0, threatList.size() - 1));
                                    target = (*it)->GetVictim();
                                }
                            }
                        }

                        if (target && target->IsAlive())
                        {
                            me->SetFacingToObject(target);
                            Talk(Texts::HelixCrewStickyBomb);
                            me->HandleEmoteCommand(Emote::EMOTE_ONESHOT_ATTACK_THROWN);
                            if (Creature* stickyBomb = me->SummonCreature(Creatures::StickyBomb, me->GetPosition()))
                                stickyBomb->GetMotionMaster()->MoveJump(EVENT_JUMP, target->GetPosition());
                        }
                        _events.RescheduleEvent(Events::HelixCrewStickyBomb, 15s, 35s);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        SummonList summons;
        ObjectGuid _helixGUID;
    };

    // 47314 - Sticky Bomb
    struct npc_sticky_bomb : public ScriptedAI
    {
        npc_sticky_bomb(Creature* creature) : ScriptedAI(creature)
        {
            ApplyCrowdControlImmunities(me);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            ScriptedAI::Reset();
            _events.Reset();
            _events.RescheduleEvent(Events::StickyBombInitial, 200ms);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::StickyBombInitial:
                        _events.RescheduleEvent(Events::StickyBombYellow, 2s);
                        _events.RescheduleEvent(Events::StickyBombOrange, 4s);
                        _events.RescheduleEvent(Events::StickyBombRed, 5500ms);
                        _events.RescheduleEvent(Events::StickyBombArmed, 5800ms);
                        _events.RescheduleEvent(Events::StickyBombExplode, 17800ms);
                        break;
                    case Events::StickyBombYellow:
                        DoCastSelf(Spells::ArmingVisualYellow);
                        break;
                    case Events::StickyBombOrange:
                        DoCastSelf(Spells::ArmingVisualOrange);
                        break;
                    case Events::StickyBombRed:
                        DoCastSelf(Spells::ArmingVisualRed);
                        break;
                    case Events::StickyBombArmed:
                        DoCastSelf(Spells::ArmedState);
                        break;
                    case Events::StickyBombExplode:
                        DoCastSelf(Spells::StickyBombExplode);
                        me->DespawnOrUnsummon(500ms);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
    };

    // 47297 - Lumbering Oaf
    struct npc_lumbering_oaf : public ScriptedAI
    {
        npc_lumbering_oaf(Creature* creature) : ScriptedAI(creature)
        {
            ApplyCrowdControlImmunities(me);
            me->setActive(true);
        }

        void Reset() override
        {
            ScriptedAI::Reset();
            _events.Reset();
            _helixGUID.Clear();
            _ridingOaf = false;
            _helixFaceRiding = false;

            if (Vehicle* vehicle = me->GetVehicleKit())
                if (vehicle->GetPassenger(0) == nullptr)
                    if (Creature* helix = me->FindNearestCreature(Creatures::HelixGearBreaker, 30.0f, true))
                        helix->EnterVehicle(me, 0);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (Creature* helix = me->FindNearestCreature(Creatures::HelixGearBreaker, 50.0f, true))
            {
                if (helix->GetVehicle() && helix->GetVehicle()->GetBase() != me)
                {
                    helix->ExitVehicle();
                    helix->EnterVehicle(me, 0);
                }
            }
            ScriptedAI::EnterEvadeMode(why);
        }

        void DoAction(int32 action) override
        {
            if (action == Actions::OafCharge)
                _events.RescheduleEvent(Events::OafCharge1, 1500ms);
        }

        void JustEngagedWith(Unit* who) override
        {
            if (Unit* helix = me->GetVehicleKit()->GetPassenger(0))
            {
                if (CreatureAI* ai = helix->ToCreature()->AI())
                    ai->JustEngagedWith(who);
            }
            int8 randomEvent = RAND(Events::OafCharge0, Events::OafThrowHelix);

            _events.RescheduleEvent(randomEvent, 15s, 20s);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (me->GetHealth() <= damage)
                if (Vehicle* vehicle = me->GetVehicleKit())
                    vehicle->RemoveAllPassengers();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* helix = me->FindNearestCreature(Creatures::HelixGearBreaker, 20.0f, true))
                if (CreatureAI* ai = helix->AI())
                    ai->SetData(Misc::HelixOafDead, 1);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                if (id == 1)
                    _events.RescheduleEvent(Events::OafCharge2, 500ms);
                else if (id == 2)
                    _events.RescheduleEvent(Events::OafCharge3, 200ms);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Events::OafCharge0:
                {
                    if (_helixFaceRiding)
                    {
                        _events.RescheduleEvent(Events::OafCharge0, 5s);
                        break;
                    }
                    if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat, 0, 100.0f, true))
                    {
                        _ridingOaf = true;
                        me->SetReactState(REACT_PASSIVE);
                        DoCast(target, Spells::OafCharge, true);
                        Talk(Texts::OafCharge);
                    }
                    break;
                }
                case Events::OafCharge1:
                    if (Creature* moveBunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::OafMoveToBunny))
                        me->GetMotionMaster()->MovePoint(1, moveBunny->GetPosition());
                    break;
                case Events::OafCharge2:
                    if (Creature* chargeBunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::OafChargePosition))
                        me->GetMotionMaster()->MoveCharge(chargeBunny->GetPositionX(), chargeBunny->GetPositionY(), chargeBunny->GetPositionZ(), 42.0f, 2);
                    break;

                case Events::OafCharge3:
                {
                    DoCastAOE(Spells::OafSmash);
                    Talk(Texts::OafSmash);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Vehicle* vehicle = me->GetVehicleKit())
                    {
                        if (Unit* passenger = vehicle->GetPassenger(1))
                        {
                            passenger->ExitVehicle();
                            me->Attack(passenger, true);

                            if (!passenger->HasAura(Spells::HelixRide))
                                passenger->AddAura(Spells::HelixRide, passenger);
                        }
                    }
                    me->RemoveAurasDueToSpell(Spells::RideOaf);
                    _ridingOaf = false;
                    if (me->GetVictim())
                        me->GetMotionMaster()->MoveChase(me->GetVictim());

                    // Spawn rats with random timing (3-5s between each)
                    // For achievement 5367 Rat Pack
                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC)
                    {
                        for (uint8 i = 0; i < 8; ++i)
                        {
                            me->m_Events.AddEventAtOffset([this, i]()
                                {
                                    if (me && me->IsAlive())
                                        if (Creature* rat = me->SummonCreature(Creatures::MineRat, Positions::OafRatPos[i], TEMPSUMMON_CORPSE_DESPAWN))
                                            rat->GetMotionMaster()->MoveRandom(3.f);
                                }, std::chrono::milliseconds(urand(3000, 5000) * (i + 1)));
                        }
                    }

                    uint8 randomEvent = RAND(Events::OafThrowHelix, Events::OafCharge0);
                    _events.RescheduleEvent(randomEvent, 25s, 35s);
                    break;
                }
                case Events::OafThrowHelix:
                {
                    if (_ridingOaf)
                    {
                        _events.RescheduleEvent(Events::OafThrowHelix, 5s);
                        break;
                    }
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, false))
                    {
                        if (Vehicle* vehicle = me->GetVehicleKit())
                        {
                            if (Unit* helix = vehicle->GetPassenger(0))
                            {
                                _helixGUID = helix->GetGUID();
                                _helixFaceRiding = true;
                                ObjectGuid targetGUID = target->GetGUID();

                                helix->ToCreature()->AI()->Talk(Texts::HelixFaceRide);

                                me->m_Events.AddEventAtOffset([this, helixGUID = _helixGUID, targetGUID]()
                                    {
                                        if (!me || !me->IsAlive())
                                            return;

                                        if (Unit* helix = ObjectAccessor::GetUnit(*me, helixGUID))
                                        {
                                            Unit* target = ObjectAccessor::GetUnit(*me, targetGUID);
                                            if (target && target->IsAlive())
                                            {

                                                Position targetPos = target->GetPosition();

                                                if (target->IsPlayer())
                                                    me->CastSpell(target, Spells::HelixRide, true);
                                                else me->AddAura(Spells::HelixRide, target);

                                                helix->ExitVehicle(&targetPos);

                                                helix->m_Events.AddEventAtOffset([helix, targetGUID]()
                                                    {
                                                        helix->AddAura(Spells::HelixRideFaceTimerAura, helix);

                                                        if(Unit* target = ObjectAccessor::GetUnit(*helix, targetGUID))
                                                            helix->CastSpell(target, Spells::RideVehicle, true);
                                                    }, std::chrono::milliseconds(200));
                                            }
                                        }
                                        else _helixFaceRiding = false;
                                    }, std::chrono::seconds(2));

                                _events.RescheduleEvent(Events::OafPickupHelix, 12s);
                            }
                        }
                    }
                    break;
                }
                case Events::OafPickupHelix:
                {
                    if (Unit* helix = ObjectAccessor::GetUnit(*me, _helixGUID))
                    {
                        if (Vehicle* helixVehicle = helix->GetVehicle())
                        {
                            Unit* targetVehicle = helixVehicle->GetBase();
                            if (targetVehicle)
                            {
                                me->CastSpell(targetVehicle, Spells::ChestBomb, true);
                                helix->ToCreature()->AI()->Talk(Texts::HelixChestBomb, targetVehicle);

                                targetVehicle->m_Events.AddEventAtOffset([targetVehicle]()
                                    {
                                        if (targetVehicle && targetVehicle->IsAlive())
                                        {
                                            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                                            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0), 1500); // Override damage to ~1500
                                            targetVehicle->CastSpell(targetVehicle, Spells::ChestBombDMG, args);
                                        }
                                    }, std::chrono::seconds(10));
                            }
                        }

                        if (Vehicle* oafVehicle = me->GetVehicleKit())
                            helix->EnterVehicle(oafVehicle->GetBase(), 0);

                    }
                    _helixFaceRiding = false;

                    uint8 randomEvent = RAND(Events::OafThrowHelix, Events::OafCharge0);
                    _events.RescheduleEvent(randomEvent, 25s, 35s);
                    break;
                }
                default:
                    break;
                    
                }
            }

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        ObjectGuid _helixGUID;
        bool _ridingOaf = false;
        bool _helixFaceRiding = false;
    };

    // 47296 - Helix Gearbreaker
    struct boss_helix_gearbreaker : public BossAI
    {
        boss_helix_gearbreaker(Creature* creature) : BossAI(creature, DataTypes::BOSS_HELIX_GEARBREAKER), summons(me)
        {
            ApplyCrowdControlImmunities(creature);
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            _events.Reset();
            summons.DespawnAll();
            me->SetHomePosition(me->GetPosition());
            _encounterStarted = false;
            _crewSpawned = false;
            if (!_oafDead)
            {
                me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);

            if (!_encounterStarted)
            {
                Talk(Texts::HelixAggro);
                _encounterStarted = true;
            }

            if (_oafDead)
            {
                if (me->GetMap()->IsHeroic() && !_crewSpawned)
                    _events.RescheduleEvent(Events::HelixSummonCrew, 1s);

                _events.RescheduleEvent(Events::HelixThrowBomb, 5s);
            }
        }

        void JustReachedHome() override
        {
            BossAI::JustReachedHome();

            summons.DespawnAll();
            _encounterStarted = false;
            _crewSpawned = false;

            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetBossState(DataTypes::BOSS_HELIX_GEARBREAKER, NOT_STARTED);
        }

        void SetData(uint32 id, uint32 value) override
        {
            if (id == Misc::HelixOafDead && value == 1)
            {
                _oafDead = true;
                me->RemoveAura(Spells::OafGuard);
                Talk(Texts::HelixOafDead);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

                // If Helix is currently face riding a player, exit the vehicle immediately
                if (Vehicle* vehicle = me->GetVehicle())
                {
                    Unit* playerVehicle = vehicle->GetBase();
                    if (playerVehicle)
                    {
                        me->CastSpell(playerVehicle, Spells::ChestBomb, true);
                        Talk(Texts::HelixChestBomb, playerVehicle);
                    }
                    me->ExitVehicle();
                    _events.CancelEvent(Events::HelixExitFaceRide);
                }

                _events.RescheduleEvent(Events::HelixFaceRide, 10s, 15s);
                _events.RescheduleEvent(Events::HelixThrowBomb, 5s);

                if (me->GetMap()->IsHeroic() && !_crewSpawned)
                {
                    _crewSpawned = true;
                    for (uint8 i = 0; i < 4; ++i)
                        me->SummonCreature(Creatures::HelixCrew, Positions::HelixCrewSpawn[i], TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            summons.Despawn(summon);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(Texts::HelixKill);
        }

        void JustDied(Unit* killer) override
        {
            BossAI::JustDied(killer);

            Talk(Texts::HelixDeath);
            summons.DespawnAll();
        }

        void OnAuraApplied(AuraApplication const* aurApp) override
        {
            if (!aurApp)
                return;

            if (aurApp->GetBase()->GetId() == Spells::HelixRideFaceTimerAura && !_oafDead)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                if (Vehicle* vehicle = me->GetVehicle())
                    if (Unit* base = vehicle->GetBase())
                        me->Attack(base, true);
            }
        }

        void OnAuraRemoved(AuraApplication const* aurApp) override
        {
            if (!aurApp)
                return;

            if (aurApp->GetBase()->GetId() == Spells::HelixRideFaceTimerAura && !_oafDead)
                me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Events::HelixSummonCrew:
                {
                    for (uint8 i = 0; i < 4; ++i)
                        me->SummonCreature(Creatures::HelixCrew, Positions::HelixCrewSpawn[i], TEMPSUMMON_MANUAL_DESPAWN);
                    break;
                }
                case Events::HelixThrowBomb:
                {
                    if (!_oafDead && !me->HasAura(Spells::HelixRideFaceTimerAura))
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, false))
                        {
                            Talk(Texts::HelixBombs);
                            me->CastSpell(target, Spells::ThrowBomb, true);
                        }
                        _events.RescheduleEvent(Events::HelixThrowBomb, 10s, 15s);
                    }
                    else if (_oafDead)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, false))
                        {
                            Talk(Texts::HelixBombs);
                            me->CastSpell(target, Spells::ThrowBomb, true);
                        }
                        _events.RescheduleEvent(Events::HelixThrowBomb, 5s, 10s);
                    }
                    break;
                }
                case Events::HelixFaceRide:
                {
                    if (_oafDead)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, false))
                        {
                            me->CastSpell(target, Spells::HelixLeap, true);

                            me->m_Events.AddEventAtOffset([this, targetGUID = target->GetGUID()]()
                                {
                                    if (!me || !me->IsAlive())
                                        return;

                                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                                    {
                                        if (!target->IsAlive())
                                            return;

                                        if (target->IsPlayer())
                                            me->CastSpell(target, Spells::HelixRide, true);
                                        else target->AddAura(Spells::HelixRide, target);
                                        me->CastSpell(me, Spells::HelixRideFaceTimerAura, true);
                                        me->CastSpell(target, Spells::RideVehicle, true);
                                        _events.RescheduleEvent(Events::HelixExitFaceRide, 10s);
                                    }
                                }, std::chrono::seconds(1));
                        }
                    }
                    break;
                }
                case Events::HelixExitFaceRide:
                {
                    if (Vehicle* vehicle = me->GetVehicle())
                    {
                        Unit* targetVehicle = vehicle->GetBase();
                        if (targetVehicle)
                        {
                            me->CastSpell(targetVehicle, Spells::ChestBomb, true);
                            Talk(Texts::HelixChestBomb, targetVehicle);

                            targetVehicle->m_Events.AddEventAtOffset([targetVehicle]()
                                {
                                    if (targetVehicle && targetVehicle->IsAlive())
                                    {
                                        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                                        args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0), 1500); // Override damage to ~1500
                                        targetVehicle->CastSpell(targetVehicle, Spells::ChestBombDMG, args);
                                    }
                                }, std::chrono::seconds(10));
                        }
                    }
                    me->ExitVehicle();
                    _events.RescheduleEvent(Events::HelixFaceRide, 15s, 20s);
                    break;
                }
                default:
                    break;
                }
            }

            if (!UpdateVictim())
                return;

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        SummonList summons;
        bool _oafDead = false;
        bool _encounterStarted = false;
        bool _crewSpawned = false;
    };
}

void AddSC_custom_deadmines_helix_gearbreaker()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    RegisterCreatureAI(npc_helix_crew);
    RegisterCreatureAI(npc_sticky_bomb);
    RegisterCreatureAI(npc_lumbering_oaf);
    RegisterCreatureAI(boss_helix_gearbreaker);
}
