/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "BattlegroundIC.h"
#include "Player.h"
#include "Vehicle.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TaskScheduler.h"
#include "Transport.h"

Movement::PointsArray const siegeEnginePath =
{
    { 773.6412f, -882.243f, 17.14940f },
    { 773.1412f, -879.993f, 16.89940f },
    { 772.6412f, -877.243f, 16.89940f },
    { 771.3912f, -870.243f, 16.89940f },
    { 770.6412f, -866.243f, 15.39940f },
    { 769.3912f, -859.243f, 12.89940f },
    { 772.6020f, -852.394f, 12.48976f }
};

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

class npc_four_car_garage : public CreatureScript
{
    public:
        npc_four_car_garage() : CreatureScript("npc_four_car_garage") { }

        struct npc_four_car_garageAI : public NullCreatureAI
        {
            npc_four_car_garageAI(Creature* creature) : NullCreatureAI(creature) { }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) final override
            {
                if (apply)
                {
                    uint32 spellId = 0;

                    switch (me->GetEntry())
                    {
                        case NPC_DEMOLISHER:
                            spellId = SPELL_DRIVING_CREDIT_DEMOLISHER;
                            break;
                        case NPC_GLAIVE_THROWER_A:
                        case NPC_GLAIVE_THROWER_H:
                            spellId = SPELL_DRIVING_CREDIT_GLAIVE;
                            break;
                        case NPC_SIEGE_ENGINE_H:
                        case NPC_SIEGE_ENGINE_A:
                            spellId = SPELL_DRIVING_CREDIT_SIEGE;
                            break;
                        case NPC_CATAPULT:
                            spellId = SPELL_DRIVING_CREDIT_CATAPULT;
                            break;
                        default:
                            return;
                    }

                    me->CastSpell(who, spellId, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_four_car_garageAI(creature);
        }
};

enum SiegeEngine
{
    ACTION_EXIT_WORKSHOP = 1,

    POINT_WORKSHOP_EXIT  = 1
};

// This one is special, needs to be spawned as creature with Vehicle guid, but no VehicleKit created
// After "repair process" it should move and install it's things
class npc_ioc_siege_engine : public CreatureScript
{
    public:
        npc_ioc_siege_engine() : CreatureScript("npc_ioc_siege_engine") { }

        using _MyBaseAI = npc_four_car_garage::npc_four_car_garageAI;
        struct npc_ioc_siege_engineAI : public _MyBaseAI
        {
            npc_ioc_siege_engineAI(Creature* creature) : _MyBaseAI(creature) { }

            void Reset() override
            {
                _MyBaseAI::Reset();

                _scheduler.CancelAll();
            }

            void DoAction(int32 action) override
            {
                if (action != ACTION_EXIT_WORKSHOP)
                    return;

                me->GetMotionMaster()->MoveSmoothPath(POINT_WORKSHOP_EXIT, siegeEnginePath, true);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != EFFECT_MOTION_TYPE || id != POINT_WORKSHOP_EXIT)
                    return;

                // we still have spline active, so need to schedule movement in next tick
                _scheduler.Async([this]()
                {
                    me->SetFacingTo(1.570796f);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_PVP);

                    CreatureTemplate const* creatureTemplate = me->GetCreatureTemplate();
                    ASSERT(me->CreateVehicleKit(creatureTemplate->VehicleId, creatureTemplate->Entry));

                    WorldPacket data(SMSG_PLAYER_VEHICLE_DATA, 9 + 4);
                    data << me->GetPackGUID();
                    data << uint32(creatureTemplate->VehicleId);
                    me->SendMessageToSet(&data, true);

                    me->GetVehicleKit()->Install();
                    me->GetVehicleKit()->InstallAllAccessories(false);
                });
            }

            void UpdateAI(uint32 diff) override
            {
                _scheduler.Update(diff);

                _MyBaseAI::UpdateAI(diff);
            }

        private:
            TaskScheduler _scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ioc_siege_engineAI(creature);
        }
};

enum Events
{
    EVENT_TALK  = 1,
    EVENT_DESPAWN
};

enum Texts
{
    SAY_ONBOARD = 0
};

class npc_ioc_gunship_captain : public CreatureScript
{
    public:
        npc_ioc_gunship_captain() : CreatureScript("npc_ioc_gunship_captain") { }

        struct npc_ioc_gunship_captainAI : public ScriptedAI
        {
            npc_ioc_gunship_captainAI(Creature* creature) : ScriptedAI(creature) { }

            void DoAction(int32 action) override
            {
                if (action == ACTION_GUNSHIP_READY)
                {
                    DoCast(me, SPELL_SIMPLE_TELEPORT);
                    _events.ScheduleEvent(EVENT_TALK, 3000);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK:
                            _events.ScheduleEvent(EVENT_DESPAWN, 1000);
                            Talk(SAY_ONBOARD);
                            DoCast(me, SPELL_TELEPORT_VISUAL_ONLY);
                            break;
                        case EVENT_DESPAWN:
                            if (me->GetMap()->ToBattlegroundMap())
                                if (Battleground* bgIoC = me->GetMap()->ToBattlegroundMap()->GetBG())
                                    bgIoC->DelCreature(BG_IC_NPC_GUNSHIP_CAPTAIN_1);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ioc_gunship_captainAI(creature);
        }
};

class spell_ioc_gunship_portal : public SpellScriptLoader
{
    public:
        spell_ioc_gunship_portal() : SpellScriptLoader("spell_ioc_gunship_portal") { }

        class spell_ioc_gunship_portal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ioc_gunship_portal_SpellScript);

            bool Load() override
            {
                return !GetCaster()->GetTransport() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                /*
                 * HACK: GetWorldLocation() returns real position and not transport position.
                 * ServertoClient: SMSG_MOVE_TELEPORT (0x0B39)
                 * counter: 45
                 * Tranpsort Guid: Full: xxxx Type: MOTransport Low: xxx
                 * Transport Position X: 0 Y: 0 Z: 0 O: 0
                 * Position: X: 7.305609 Y: -0.095246 Z: 34.51022 O: 0
                 */

                Transport* gunship = GetHitCreature()->GetTransport();
                ASSERT(gunship);

                Position oldPosition = GetHitCreature()->GetPosition(); // contains absolute coords
                float x, y, z, o;
                oldPosition.GetPosition(x, y, z, o);
                gunship->CalculatePassengerOffset(x, y, z, &o);

                ///@workaround: Player::TeleportTo implementation is incorrect
                if (caster->GetVehicle())
                    caster->ExitVehicle();

                // reset movement flags at teleport, because player will continue move with these flags after teleport
                caster->SetUnitMovementFlags(caster->GetUnitMovementFlags() & MOVEMENTFLAG_MASK_HAS_PLAYER_STATUS_OPCODE);

                gunship->AddPassenger(caster);
                caster->AddUnitMovementFlag(MOVEMENTFLAG_FALLING); // seen on sniff
                caster->m_movementInfo.transport.pos.Relocate(x, y, z, o);

                // pet should not be unsummoned, rather teleported with owner.
                // but pets on transports are still not implemented :/
                caster->UnsummonPetTemporaryIfAny();

                caster->CombatStop();
                caster->SetFallInformation(0, oldPosition.GetPositionZ());

                // code for finish transfer called in WorldSession::HandleMovementOpcodes()
                // at client packet MSG_MOVE_TELEPORT_ACK
                caster->SetSemaphoreTeleportNear(true);

                // near teleport, triggering send MSG_MOVE_TELEPORT_ACK from client at landing
                if (!caster->GetSession()->PlayerLogout())
                {
                    caster->Relocate(oldPosition);

                    WorldPacket data(MSG_MOVE_TELEPORT, 9 + 4 + 2 + 4 + 4 * 4 + 9 + 4 * 4 + 4 + 1 + 4 + 4 * 4);
                    data << caster->GetPackGUID();
                    caster->BuildMovementPacket(&data);
                    caster->SendMessageToSet(&data, false);

                    caster->SendTeleportAckPacket();
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ioc_gunship_portal_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ioc_gunship_portal_SpellScript();
        }
};

class spell_ioc_parachute_ic : public SpellScriptLoader
{
    public:
        spell_ioc_parachute_ic() : SpellScriptLoader("spell_ioc_parachute_ic") { }

        class spell_ioc_parachute_ic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ioc_parachute_ic_AuraScript);

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                if (Player* target = GetTarget()->ToPlayer())
                    if (target->m_movementInfo.fallTime > 2000 && !target->GetTransport())
                        target->CastSpell(target, SPELL_PARACHUTE_IC, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ioc_parachute_ic_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ioc_parachute_ic_AuraScript();
        }
};

class StartLaunchEvent : public BasicEvent
{
    public:
        StartLaunchEvent(Position const& pos, ObjectGuid::LowType lowGuid) : _pos(pos), _lowGuid(lowGuid) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            Player* player = sObjectMgr->GetPlayerByLowGUID(_lowGuid);
            if (!player || !player->GetVehicle())
                return true;

            player->AddAura(SPELL_LAUNCH_NO_FALLING_DAMAGE, player); // prevents falling damage
            float speedZ = 10.0f;
            float dist = player->GetExactDist2d(&_pos);

            player->ExitVehicle();
            player->GetMotionMaster()->MoveJump(_pos, dist, speedZ, EVENT_JUMP, true);
            return true;
        }

    private:
        Position _pos;
        ObjectGuid::LowType _lowGuid;
};

class spell_ioc_launch : public SpellScriptLoader
{
    public:
        spell_ioc_launch() : SpellScriptLoader("spell_ioc_launch") { }

        class spell_ioc_launch_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ioc_launch_SpellScript);

            void Launch()
            {
                if (!GetCaster()->ToCreature() || !GetExplTargetDest())
                    return;

                GetCaster()->ToCreature()->m_Events.AddEvent(new StartLaunchEvent(*GetExplTargetDest(), GetHitPlayer()->GetGUID().GetCounter()), GetCaster()->ToCreature()->m_Events.CalculateTime(2500));
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_ioc_launch_SpellScript::Launch);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ioc_launch_SpellScript();
        }
};

enum SeaforiumBombSpells
{
    SPELL_SEAFORIUM_BLAST       = 66676,
    SPELL_HUGE_SEAFORIUM_BLAST  = 66672,
    SPELL_A_BOMB_INABLE_CREDIT  = 68366,
    SPELL_A_BOMB_INATION_CREDIT = 68367
};

class spell_ioc_seaforium_blast_credit : public SpellScriptLoader
{
    public:
        spell_ioc_seaforium_blast_credit() : SpellScriptLoader("spell_ioc_seaforium_blast_credit") { }

        class spell_ioc_seaforium_blast_credit_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ioc_seaforium_blast_credit_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_A_BOMB_INABLE_CREDIT) || !sSpellMgr->GetSpellInfo(SPELL_A_BOMB_INATION_CREDIT))
                    return false;
                return true;
            }

            void HandleAchievementCredit(SpellEffIndex /*effIndex*/)
            {
                uint32 _creditSpell = 0;
                Unit* caster = GetOriginalCaster();
                if (!caster)
                    return;

                if (GetSpellInfo()->Id == SPELL_SEAFORIUM_BLAST)
                    _creditSpell = SPELL_A_BOMB_INABLE_CREDIT;
                else if (GetSpellInfo()->Id == SPELL_HUGE_SEAFORIUM_BLAST)
                    _creditSpell = SPELL_A_BOMB_INATION_CREDIT;

                if (GetHitGObj() && GetHitGObj()->IsDestructibleBuilding())
                    caster->CastSpell(caster, _creditSpell, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ioc_seaforium_blast_credit_SpellScript::HandleAchievementCredit, EFFECT_1, SPELL_EFFECT_GAMEOBJECT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ioc_seaforium_blast_credit_SpellScript();
        }
};

class spell_ioc_damaged : public SpellScriptLoader
{
    public:
        spell_ioc_damaged() : SpellScriptLoader("spell_ioc_damaged") { }

        class spell_ioc_damaged_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ioc_damaged_AuraScript);

            void HandleDummy(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                GetUnitOwner()->GetAI()->DoAction(ACTION_EXIT_WORKSHOP);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_ioc_damaged_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ioc_damaged_AuraScript();
        }
};

void AddSC_isle_of_conquest()
{
    new npc_four_car_garage();
    new npc_ioc_siege_engine();
    new npc_ioc_gunship_captain();
    new spell_ioc_gunship_portal();
    new spell_ioc_parachute_ic();
    new spell_ioc_launch();
    new spell_ioc_seaforium_blast_credit();
    new spell_ioc_damaged();
}
