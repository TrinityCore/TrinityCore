/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "BattlegroundIC.h"
#include "GameObject.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Vehicle.h"

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

class npc_four_car_garage : public CreatureScript
{
    public:
        npc_four_car_garage() : CreatureScript("npc_four_car_garage") { }

        struct npc_four_car_garageAI : public NullCreatureAI
        {
            npc_four_car_garageAI(Creature* creature) : NullCreatureAI(creature) { }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
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
                            if (BattlegroundMap* iocMap = me->GetMap()->ToBattlegroundMap())
                                if (Battleground* bgIoC = iocMap->GetBG())
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
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                /*
                 * HACK: GetWorldLocation() returns real position and not transportposition.
                 * ServertoClient: SMSG_MOVE_TELEPORT (0x0B39)
                 * counter: 45
                 * Tranpsort Guid: Full: xxxx Type: MOTransport Low: xxx
                 * Transport Position X: 0 Y: 0 Z: 0 O: 0
                 * Position: X: 7.305609 Y: -0.095246 Z: 34.51022 O: 0
                 */
                caster->TeleportTo(GetHitCreature()->GetWorldLocation(), TELE_TO_NOT_LEAVE_TRANSPORT);
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
                    if (target->m_movementInfo.GetFallTime() > 2000 && !target->GetTransport())
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
        StartLaunchEvent(Position const& pos, ObjectGuid const& guid) : _pos(pos), _guid(guid)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            Player* player = ObjectAccessor::FindPlayer(_guid);
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
        ObjectGuid _guid;
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

                GetCaster()->ToCreature()->m_Events.AddEvent(new StartLaunchEvent(*GetExplTargetDest(), GetHitPlayer()->GetGUID()), GetCaster()->ToCreature()->m_Events.CalculateTime(2500));
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
                return ValidateSpellInfo({ SPELL_A_BOMB_INABLE_CREDIT, SPELL_A_BOMB_INATION_CREDIT });
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

void AddSC_isle_of_conquest()
{
    new npc_four_car_garage();
    new npc_ioc_gunship_captain();
    new spell_ioc_gunship_portal();
    new spell_ioc_parachute_ic();
    new spell_ioc_launch();
    new spell_ioc_seaforium_blast_credit();
}
