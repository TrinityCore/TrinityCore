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
#include "ScriptedCreature.h"
#include "deadmines.h"
#include "Spell.h"
#include "Player.h"
#include "WorldSession.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Vehicle.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "SpellScript.h"
#include "SpellInfo.h"

enum DefiasWatcher
{
    SPELL_ON_FIRE           = 91737,
    SPELL_EXPLOSIVE_SUICIDE = 91738,
    SPELL_ENERGIZE          = 89132,
    SPELL_CLEAVE            = 90980,

    FACTION_CONTROLLABLE    = 1816,

    EVENT_CLEAVE            = 1
};

struct npc_deadmines_defias_watcher : public ScriptedAI
{
    npc_deadmines_defias_watcher(Creature* creature) : ScriptedAI(creature), _isOnFire(false) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CLEAVE, 3s + 500ms);
    }

    void Reset() override
    {
        me->SetFullHealth();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_isOnFire && me->HealthBelowPctDamaged(30, damage))
        {
            me->GetThreatManager().ClearAllThreat();
            me->CombatStop();
            me->SetFaction(FACTION_CONTROLLABLE);
            DoCastSelf(SPELL_ON_FIRE);
            DoCastAOE(SPELL_ENERGIZE);
            me->setRegeneratingHealth(false);
            _isOnFire = true;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.Repeat(4s, 5s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    bool _isOnFire;
    EventMap _events;
};

enum VanessasTrapBunny
{
    EVENT_MOVE_DOWN = 1,
    EVENT_SUMMON_VALVES,
    EVENT_ANNOUNCE_VALVES,

    SAY_ANNOUNCE_ACTIVATE_VALVES = 0,

    POINT_MOLTEN_MAGMA = 1,
};

Position const trapBunnyMoveDownPos = { -205.7569f, -579.0972f, 35.98623f };

Position const steamValvePositions[] =
{
    { -199.1944f, -583.1545f, 37.33158f, 2.600541f  },
    { -201.809f,  -572.6215f, 37.33158f, 4.171337f  },
    { -209.6823f, -585.8924f, 37.33158f, 0.9599311f },
    { -212.3524f, -575.3976f, 37.33158f, 5.707227f  }
};

class npc_deadmines_vanessas_trap_bunny : public CreatureScript
{
    public:
        npc_deadmines_vanessas_trap_bunny() : CreatureScript("npc_deadmines_vanessas_trap_bunny") { }

        struct npc_deadmines_vanessas_trap_bunnyAI : public ScriptedAI
        {
            npc_deadmines_vanessas_trap_bunnyAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Inizialize();
            }

            void Inizialize()
            {
                _movementStarted = false;
            }

            void Reset() override
            {
                Inizialize();
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                if (apply && passenger->GetTypeId() == TYPEID_PLAYER && !_movementStarted)
                {
                    passenger->SetDisableGravity(true);
                    _events.ScheduleEvent(EVENT_SUMMON_VALVES, Seconds(2) + Milliseconds(900));
                    _events.ScheduleEvent(EVENT_MOVE_DOWN, Seconds(6));
                    _movementStarted = true;
                }
                else if (!apply)
                    passenger->SetDisableGravity(false);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_EJECT_PLAYERS)
                {
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        for (uint8 i = 0; i < 5; i++)
                            if (Unit* passenger = vehicle->GetPassenger(i))
                            {
                                passenger->ExitVehicle(&trapBunnyMoveDownPos);
                                DoCast(passenger, SPELL_FORCE_MAGMA_TRAP_THROW, true);
                            }
                }
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_MOLTEN_MAGMA:
                        DoCastSelf(SPELL_MOLTEN_MAGMA, true);
                        break;
                    default:
                        break;
                }
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
                        case EVENT_MOVE_DOWN:
                            me->SetSpeed(MOVE_RUN, me->GetSpeed(MOVE_WALK) * 0.5f); // Moving down very, very slow
                            me->GetMotionMaster()->MovePoint(POINT_MOLTEN_MAGMA, trapBunnyMoveDownPos, false);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_VALVES, Milliseconds(200));
                            break;
                        case EVENT_SUMMON_VALVES:
                            for (uint8 i = 0; i < 4; i++)
                                DoSummon(NPC_STEAM_VALVE, steamValvePositions[i], 0, TEMPSUMMON_MANUAL_DESPAWN);
                            break;
                        case EVENT_ANNOUNCE_VALVES:
                            Talk(SAY_ANNOUNCE_ACTIVATE_VALVES);
                            break;
                        default:
                            break;
                    }
                }

            }
        private:
            EventMap _events;
            InstanceScript* _instance;
            bool _movementStarted;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_deadmines_vanessas_trap_bunnyAI>(creature);
        }
};

class npc_deadmines_steam_valve : public CreatureScript
{
    public:
        npc_deadmines_steam_valve() : CreatureScript("npc_deadmines_steam_valve") { }

        struct npc_deadmines_steam_valveAI : public ScriptedAI
        {
            npc_deadmines_steam_valveAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) override
            {
                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                {
                    _instance->SetData(DATA_ACTIVATED_VENT, DONE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_deadmines_steam_valveAI>(creature);
        }
};

enum VanessaVanCleef
{
    SAY_GLUBTOK_INTRO_1                 = 0,
    SAY_GLUBTOK_INTRO_2                 = 1,
    SAY_ANNOUNCE_GLUBTOKS_NIGHTMARE     = 2,
    SAY_ANNOUNCE_GET_BACK_TO_THE_SHIP   = 3,
    SAY_HELIX_INTRO_1                   = 4,
    SAY_HELIX_INTRO_2                   = 5,
    SAY_MECHANICAL_INTRO_1              = 6,
    SAY_MECHANICAL_INTRO_2              = 7,
    SAY_ANNOUNCE_MECHANICAL_NIGHTMARE   = 8,
    SAY_RIPSNARL_INTRO_1                = 9,
    SAY_RIPSNARL_INTRO_2                = 10,
    SAY_ANNOUNCE_RIPSNARL_NIGHTMARE     = 11,

    EVENT_TALK_GLUBTOKS_NIGHTMARE_1 = 1,
    EVENT_TALK_GLUBTOKS_NIGHTMARE_2,
    EVENT_CANCEL_NIGHTMARE_AURA_TRAP,
    EVENT_ANNOUNCE_ENTERED_GLUBTOKS_NIGHTMARE,
    EVENT_ANNOUNCE_GET_BACK_TO_THE_SHIP,
    EVENT_TALK_HELIX_NIGHTMARE_1,
    EVENT_TALK_HELIX_NIGHTMARE_2,
    EVENT_CANCEL_NIGHTMARE_AURA_GLUBTOK,
    EVENT_TALK_MECHANICAL_NIGHTMARE_1,
    EVENT_TALK_MECHANICAL_NIGHTMARE_2,
    EVENT_CANCEL_NIGHTMARE_AURA_HELIX,
    EVENT_ANNOUNCE_ENTERED_MECHANICAL_NIGHTMARE,
    EVENT_TALK_RIPSNARL_NIGHTMARE_1,
    EVENT_TALK_RIPSNARL_NIGHTMARE_2,
    EVENT_CANCEL_NIGHTMARE_AURA_MECHANICAL,
    EVENT_ANNOUNCE_ENTERED_RIPSNARL_NIGHTMARE,
    EVENT_ADRENALINE,

    SPELL_CANCEL_NIGHTMARE_AURA         = 92583,
    SPELL_NIGHTMARE_AURA_GLUBTOK        = 92565,
    SPELL_NIGHTMARE_AURA_HELIX          = 92566,
    SPELL_NIGHTMARE_AURA_MECHANICAL     = 92567,
    SPELL_NIGHTMARE_AURA_RIPSNARL       = 92568,
};

class npc_deadmines_vanessa_van_cleef_nightmare : public CreatureScript
{
    public:
        npc_deadmines_vanessa_van_cleef_nightmare() : CreatureScript("npc_deadmines_vanessa_van_cleef_nightmare") { }

        struct npc_deadmines_vanessa_van_cleef_nightmareAI : public ScriptedAI
        {
            npc_deadmines_vanessa_van_cleef_nightmareAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) == NIGHTMARE_STAGE_GLUBTOK)
                    _events.ScheduleEvent(EVENT_TALK_GLUBTOKS_NIGHTMARE_1, Seconds(1));
                else if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) == NIGHTMARE_STAGE_HELIX)
                    _events.ScheduleEvent(EVENT_TALK_HELIX_NIGHTMARE_1, Seconds(1));
                else if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) == NIGHTMARE_STAGE_FOE_REAPER)
                    _events.ScheduleEvent(EVENT_TALK_MECHANICAL_NIGHTMARE_1, Seconds(1));
                else if (_instance->GetData(DATA_VANESSA_VAN_CLEEF_ENCOUNTER) == NIGHTMARE_STAGE_RIPSNARL)
                    _events.ScheduleEvent(EVENT_TALK_RIPSNARL_NIGHTMARE_1, Seconds(2) + Milliseconds(200));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_GLUBTOKS_NIGHTMARE_1:
                            Talk(SAY_GLUBTOK_INTRO_1);
                            _events.ScheduleEvent(EVENT_TALK_GLUBTOKS_NIGHTMARE_2, Seconds(8) + Milliseconds(400));
                            break;
                        case EVENT_TALK_GLUBTOKS_NIGHTMARE_2:
                            Talk(SAY_GLUBTOK_INTRO_2);
                            _events.ScheduleEvent(EVENT_CANCEL_NIGHTMARE_AURA_TRAP, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_CANCEL_NIGHTMARE_AURA_TRAP:
                            DoCastAOE(SPELL_CANCEL_NIGHTMARE_AURA, true);
                            DoCastAOE(SPELL_NIGHTMARE_AURA_GLUBTOK, true);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_ENTERED_GLUBTOKS_NIGHTMARE, Milliseconds(110));
                            break;
                        case EVENT_ANNOUNCE_ENTERED_GLUBTOKS_NIGHTMARE:
                            Talk(SAY_ANNOUNCE_GLUBTOKS_NIGHTMARE);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_GET_BACK_TO_THE_SHIP, Seconds(4) + Milliseconds(800));
                            break;
                        case EVENT_ANNOUNCE_GET_BACK_TO_THE_SHIP:
                            Talk(SAY_ANNOUNCE_GET_BACK_TO_THE_SHIP);
                            if (Creature* glubtok = me->FindNearestCreature(NPC_GLUBTOK_NIGHTMARE, 10.0f, true))
                                glubtok->DespawnOrUnsummon(Seconds(2) + Milliseconds(500));
                            me->DespawnOrUnsummon(Seconds(2) + Milliseconds(500));
                            break;
                        case EVENT_TALK_HELIX_NIGHTMARE_1:
                            Talk(SAY_HELIX_INTRO_1);
                            _events.ScheduleEvent(EVENT_TALK_HELIX_NIGHTMARE_2, Seconds(6));
                            break;
                        case EVENT_TALK_HELIX_NIGHTMARE_2:
                            Talk(SAY_HELIX_INTRO_2);
                            _events.ScheduleEvent(EVENT_CANCEL_NIGHTMARE_AURA_GLUBTOK, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_CANCEL_NIGHTMARE_AURA_GLUBTOK:
                            DoCastAOE(SPELL_CANCEL_NIGHTMARE_AURA, true);
                            DoCastAOE(SPELL_NIGHTMARE_AURA_HELIX, true);
                            me->DespawnOrUnsummon(Seconds(3) + Milliseconds(700));
                            break;
                        case EVENT_TALK_MECHANICAL_NIGHTMARE_1:
                            Talk(SAY_MECHANICAL_INTRO_1);
                            _events.ScheduleEvent(EVENT_TALK_MECHANICAL_NIGHTMARE_2, Seconds(3) + Milliseconds(600));
                            break;
                        case EVENT_TALK_MECHANICAL_NIGHTMARE_2:
                            Talk(SAY_MECHANICAL_INTRO_2);
                            _events.ScheduleEvent(EVENT_CANCEL_NIGHTMARE_AURA_HELIX, Seconds(3) + Milliseconds(400));
                            break;
                        case EVENT_CANCEL_NIGHTMARE_AURA_HELIX:
                            DoCastAOE(SPELL_CANCEL_NIGHTMARE_AURA, true);
                            DoCastAOE(SPELL_NIGHTMARE_AURA_MECHANICAL, true);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_ENTERED_MECHANICAL_NIGHTMARE, Milliseconds(200));
                            break;
                        case EVENT_ANNOUNCE_ENTERED_MECHANICAL_NIGHTMARE:
                            Talk(SAY_ANNOUNCE_MECHANICAL_NIGHTMARE);
                            if (Creature* reaper = me->FindNearestCreature(NPC_FOE_REAPER_5000_NIGHTMARE, 20.0f, true))
                                reaper->DespawnOrUnsummon(Seconds(2) + Milliseconds(200));
                            me->DespawnOrUnsummon(Seconds(2) + Milliseconds(200));
                            break;
                        case EVENT_TALK_RIPSNARL_NIGHTMARE_1:
                            Talk(SAY_RIPSNARL_INTRO_1);
                            _events.ScheduleEvent(EVENT_TALK_RIPSNARL_NIGHTMARE_2, Seconds(7) + Milliseconds(150));
                            break;
                        case EVENT_TALK_RIPSNARL_NIGHTMARE_2:
                            Talk(SAY_RIPSNARL_INTRO_2);
                            _events.ScheduleEvent(EVENT_CANCEL_NIGHTMARE_AURA_MECHANICAL, Seconds(4) + Milliseconds(600));
                            break;
                        case EVENT_CANCEL_NIGHTMARE_AURA_MECHANICAL:
                            DoCastAOE(SPELL_CANCEL_NIGHTMARE_AURA, true);
                            DoCastAOE(SPELL_NIGHTMARE_AURA_RIPSNARL, true);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_ENTERED_RIPSNARL_NIGHTMARE, Milliseconds(200));
                            break;
                        case EVENT_ANNOUNCE_ENTERED_RIPSNARL_NIGHTMARE:
                            Talk(SAY_ANNOUNCE_RIPSNARL_NIGHTMARE);
                            _events.ScheduleEvent(EVENT_ADRENALINE, Seconds(2));
                            break;
                        case EVENT_ADRENALINE:
                            DoCastAOE(SPELL_ADRENALINE, true);
                            if (Creature* reaper = me->FindNearestCreature(NPC_RIPSNARL_NIGHTMARE, 20.0f, true))
                                reaper->DespawnOrUnsummon(Milliseconds(300));
                            me->DespawnOrUnsummon(Milliseconds(300));
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_deadmines_vanessa_van_cleef_nightmareAI>(creature);
        }
};

enum HelixNightmare
{
    SAY_ANNOUNCE_HELIX_NIGHTMARE    = 0,
    SAY_ANNOUNCE_NIGHTMAR_SPIDERS   = 1,

    SPELL_HELIX_RIDE            = 88337,
    SPELL_RIDE_FACE_TARGETING   = 88349,
    SPELL_PESTILENCE            = 91939,
    SPELL_SHADOW_FOG            = 92792,

    EVENT_SPIRIT_STRIKE = 1,
    EVENT_TALK_NIGHTMARE = 3,
    EVENT_MAKE_ATTACKABLE,
    EVENT_RIDE_PLAYER,
    EVENT_PESTILENCE,
    EVENT_SUMMON_NIGHTMARE_SKITTERLINGS,
    EVENT_ANNOUNCE_SPIDERS,

};

class npc_deadmines_helix_nightmare : public CreatureScript
{
    public:
        npc_deadmines_helix_nightmare() : CreatureScript("npc_deadmines_helix_nightmare") { }

        struct npc_deadmines_helix_nightmareAI : public ScriptedAI
        {
            npc_deadmines_helix_nightmareAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void JustAppeared() override
            {
                _events.ScheduleEvent(EVENT_MAKE_ATTACKABLE, Seconds(7) + Milliseconds(700));
                _events.ScheduleEvent(EVENT_TALK_NIGHTMARE, Seconds(17) + Milliseconds(800));
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SPIRIT_STRIKE, Seconds(4) + Milliseconds(400));
                _events.ScheduleEvent(EVENT_RIDE_PLAYER, Seconds(2) + Milliseconds(500));
            }

            void UpdateAI(uint32 diff) override
            {
                UpdateVictim();

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MAKE_ATTACKABLE:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            break;
                        case EVENT_SPIRIT_STRIKE:
                            DoCastVictim(SPELL_SPIRIT_STRIKE);
                            _events.Repeat(Seconds(3) + Milliseconds(600));
                            break;
                        case EVENT_TALK_NIGHTMARE:
                            Talk(SAY_ANNOUNCE_HELIX_NIGHTMARE);
                            _events.ScheduleEvent(EVENT_SUMMON_NIGHTMARE_SKITTERLINGS, Milliseconds(600));
                            break;
                        case EVENT_RIDE_PLAYER:
                            DoCastAOE(SPELL_RIDE_FACE_TARGETING, true);
                            _events.Repeat(Seconds(11));
                            break;
                        case EVENT_SUMMON_NIGHTMARE_SKITTERLINGS:
                            for (uint8 i = 0; i < 100; i++)
                                me->SummonCreature(NPC_NIGHTMARE_SKITTERLING, nightmareSkitterlingPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);
                            for (uint8 i = 0; i < 3; i++)
                                me->SummonCreature(NPC_DARKWEB_DEVOURER, DarkwebDevourerPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                            me->SummonCreature(NPC_CHATTERING_HORROR, ChatteringHorrorPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000);

                            if (Creature* dummy = me->SummonCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, GeneralPurposeBunnyPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5000))
                                dummy->CastSpell(dummy, SPELL_SHADOW_FOG, true);

                            _events.ScheduleEvent(EVENT_ANNOUNCE_SPIDERS, Milliseconds(800));
                            break;
                        case EVENT_ANNOUNCE_SPIDERS:
                            Talk(SAY_ANNOUNCE_NIGHTMAR_SPIDERS);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_deadmines_helix_nightmareAI>(creature);
        }
};

enum DefiasCannon
{
    // GroupID 0 and 1 are used by Foe Reaper 5000
    SAY_ANNOUNCE_CANNON_LOADED = 2
};

class go_deadmines_defias_cannon : public GameObjectScript
{
    public:
        go_deadmines_defias_cannon() : GameObjectScript("go_deadmines_defias_cannon") { }

        struct go_deadmines_defias_cannonAI : public GameObjectAI
        {
            go_deadmines_defias_cannonAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

            bool OnReportUse(Player* /*player*/) override
            {
                if (GameObject* cannon = me->ToGameObject())
                {
                    if (_instance->GetData(DATA_BROKEN_DOOR) != DONE)
                    {
                        cannon->SendCustomAnim(0);
                        if (GameObject* door = _instance->GetGameObject(DATA_IRON_CLAD_DOOR))
                            door->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

                        if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 20.0f, true))
                            bunny->AI()->Talk(SAY_ANNOUNCE_CANNON_LOADED);

                        _instance->SetData(DATA_BROKEN_DOOR, DONE);
                        cannon->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                }
                return true;
            }
        private:
            InstanceScript* _instance;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetDeadminesAI<go_deadmines_defias_cannonAI>(go);
        }
};

class spell_deadmines_on_fire : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXPLOSIVE_SUICIDE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_EXPLOSIVE_SUICIDE, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_deadmines_on_fire::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE_PERCENT, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_deadmines_ride_magma_vehicle : public SpellScriptLoader
{
    public:
        spell_deadmines_ride_magma_vehicle() : SpellScriptLoader("spell_deadmines_ride_magma_vehicle") { }

        class spell_deadmines_ride_magma_vehicle_SpellScript : public SpellScript
        {
            void HandleHit(SpellEffIndex effIndex)
            {
                Unit* target = GetHitUnit();
                target->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_deadmines_ride_magma_vehicle_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_deadmines_ride_magma_vehicle_SpellScript();
        }
};

// We have no dummy npc in sniffs so we use a sniffed coordinate instead
class spell_deadmines_magma_trap_throw_to_location : public SpellScriptLoader
{
    public:
        spell_deadmines_magma_trap_throw_to_location() : SpellScriptLoader("spell_deadmines_magma_trap_throw_to_location") { }

        class spell_deadmines_magma_trap_throw_to_location_SpellScript : public SpellScript
        {
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitDest())
                    GetHitDest()->Relocate(-225.1973f, -563.7677f, 51.23737f);
            }

            void Register() override
            {
                OnEffectLaunch.Register(&spell_deadmines_magma_trap_throw_to_location_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_deadmines_magma_trap_throw_to_location_SpellScript();
        }
};

class spell_deadmines_bloodbath : public SpellScriptLoader
{
    public:
        spell_deadmines_bloodbath() : SpellScriptLoader("spell_deadmines_bloodbath") { }

        class spell_deadmines_bloodbath_AuraScript : public AuraScript
        {
            void HandleTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (caster->GetVictim())
                        caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic.Register(&spell_deadmines_bloodbath_AuraScript::HandleTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_deadmines_bloodbath_AuraScript();
        }
};

void AddSC_deadmines()
{
    RegisterDeadminesCreatureAI(npc_deadmines_defias_watcher);
    new npc_deadmines_vanessas_trap_bunny();
    new npc_deadmines_steam_valve();
    new npc_deadmines_vanessa_van_cleef_nightmare();
    new npc_deadmines_helix_nightmare();
    new go_deadmines_defias_cannon();
    RegisterSpellScript(spell_deadmines_on_fire);
    new spell_deadmines_ride_magma_vehicle();
    new spell_deadmines_magma_trap_throw_to_location();
    new spell_deadmines_bloodbath();
}
