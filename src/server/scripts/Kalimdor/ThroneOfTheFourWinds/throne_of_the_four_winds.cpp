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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "MoveSplineInit.h"
#include "Player.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "throne_of_the_four_winds.h"

enum Spells
{
    SPELL_JET_STREAM                = 84576,
    SPELL_JET_STREAM_TRIGGERED      = 84610,
    SPELL_CATCH_FALL                = 85268,

    SPELL_EJECT_ALL_PASSENGERS      = 68576,
    SPELL_CATCH_FALL_REMOVAL        = 85274,

    SPELL_SLIPSTREAM_SAFE_FALL      = 87740,
};

enum Events
{
    EVENT_EJECT_ALL_PASSENGERS      = 1,
    EVENT_THROW_PASSENGER           = 2
};

enum Actions
{
    // action id 1 is used by boss_conclave_of_wind
    ACTION_PLAYER_LEFT_PLATFORM = 2,
};

enum VehicleSeats
{
    SEAT_0 = 0
};

class at_totfw_jet_stream : public AreaTriggerScript
{
    public:
        at_totfw_jet_stream() : AreaTriggerScript("at_totfw_jet_stream") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (!player->HasAura(SPELL_JET_STREAM_TRIGGERED) && !player->GetVehicle())
            {
                if (Creature* trigger = player->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f, true))
                    trigger->CastSpell(player, SPELL_JET_STREAM, true);

                if (Creature* anshal = player->FindNearestCreature(BOSS_ANSHAL, 90.0f, true))
                    anshal->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);
                else if (Creature* nezir = player->FindNearestCreature(BOSS_NEZIR, 90.0f, true))
                    nezir->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);
                else if (Creature* rohash = player->FindNearestCreature(BOSS_ROHASH, 90.0f, true))
                    rohash->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);
            }
            return true;
        }
};

class at_totfw_catch_fall : public AreaTriggerScript
{
    public:
        at_totfw_catch_fall() : AreaTriggerScript("at_totfw_catch_fall") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return true;

            if (Creature* anshal = instance->GetCreature(DATA_ANSHAL))
                anshal->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);
            else if (Creature* nezir = instance->GetCreature(DATA_NEZIR))
                nezir->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);
            else if (Creature* rohash = instance->GetCreature(DATA_ROHASH))
                rohash->AI()->DoAction(ACTION_PLAYER_LEFT_PLATFORM);

            if (!instance->IsEncounterInProgress())
            {
                if (Creature* trigger = player->FindNearestCreature(NPC_WORLD_TRIGGER, 500.0f, true))
                    trigger->CastSpell(player, SPELL_CATCH_FALL, true);
            }
            else
                player->KillSelf();

            return true;
        }
};

class npc_totfw_fall_catcher : public CreatureScript
{
    public:
        npc_totfw_fall_catcher() : CreatureScript("npc_totfw_fall_catcher") { }

        struct npc_totfw_fall_catcherAI : public ScriptedAI
        {
            npc_totfw_fall_catcherAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                _events.ScheduleEvent(EVENT_EJECT_ALL_PASSENGERS, Seconds(10) + Milliseconds(400));
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                passenger->SetDisableGravity(apply, true);

                if (!apply)
                {
                    _guid = passenger->GetGUID();
                    _events.ScheduleEvent(EVENT_THROW_PASSENGER, Milliseconds(100));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EJECT_ALL_PASSENGERS:
                            DoCastSelf(SPELL_EJECT_ALL_PASSENGERS, true);
                            break;
                        case EVENT_THROW_PASSENGER:
                            if (Unit* target = ObjectAccessor::GetUnit(*me, _guid))
                                DoCast(target, SPELL_CATCH_FALL_REMOVAL);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            ObjectGuid _guid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetThroneOfTheFourWindsAI<npc_totfw_fall_catcherAI>(creature);
        }
};

class spell_totfw_jet_stream : public SpellScriptLoader
{
    public:
        spell_totfw_jet_stream() : SpellScriptLoader("spell_totfw_jet_stream") { }

        class spell_totfw_jet_stream_SpellScript : public SpellScript
        {
            void HandleForcecast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_totfw_jet_stream_SpellScript::HandleForcecast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_totfw_jet_stream_SpellScript();
        }
};

class spell_totfw_catch_fall_summon : public SpellScriptLoader
{
    public:
        spell_totfw_catch_fall_summon() : SpellScriptLoader("spell_totfw_catch_fall_summon") { }

        class spell_totfw_catch_fall_summon_SpellScript : public SpellScript
        {
            void SetDestPosition(SpellEffIndex /*effIndex*/)
            {
                float x = GetExplTargetDest()->GetPositionX();
                float y = GetExplTargetDest()->GetPositionY();
                float z = GetExplTargetDest()->GetPositionZ() + 30.0f;

                const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(x, y, z);
                GetHitDest()->Relocate(x, y, z);
            }

            void Register()
            {
                OnEffectLaunch.Register(&spell_totfw_catch_fall_summon_SpellScript::SetDestPosition, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_totfw_catch_fall_summon_SpellScript();
        }
};

class PassengerThrowEvent : public BasicEvent
{
    public:
        PassengerThrowEvent(Unit* owner, ObjectGuid guid) :  _owner(owner), _guid(guid) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (Unit* target = ObjectAccessor::GetUnit(*_owner, _guid))
            {
                target->NearTeleportTo(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ() + 130.0f, _owner->GetOrientation());
                Position offset = Position(0.0f, 0.0f, 130.0f, 0.0f);
                target->RelocateOffset(offset);


                if (InstanceScript* instance = _owner->GetInstanceScript())
                {
                    if (Creature* alakir = instance->GetCreature(DATA_ALAKIR))
                    {
                        float angle = alakir->GetAngle(target);
                        float x = alakir->GetPositionX() + cos(angle) * (alakir->GetCombatReach() + 10.0f);
                        float y = alakir->GetPositionY() + sin(angle) * (alakir->GetCombatReach() + 10.0f);
                        float z = alakir->GetPositionZ();
                        target->GetMotionMaster()->MoveJump(x, y, z, 0.0f, 40.0f, 50.0f);
                    }
                }
            }
            return true;
        }
    private:
        Unit* _owner;
        ObjectGuid _guid;
};

struct npc_totfw_slipstream : public ScriptedAI
{
    npc_totfw_slipstream(Creature* creature) : ScriptedAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!passenger)
            return;

        passenger->SetDisableGravity(apply, true);

        if (!apply)
            me->m_Events.AddEventAtOffset(new PassengerThrowEvent(me, passenger->GetGUID()), 100ms);
        else
            DoCast(passenger, SPELL_SLIPSTREAM_SAFE_FALL);
    }
};

void AddSC_throne_of_the_four_winds()
{
    new at_totfw_jet_stream();
    new at_totfw_catch_fall();
    new npc_totfw_fall_catcher();
    new spell_totfw_jet_stream();
    new spell_totfw_catch_fall_summon();
    RegisterThroneOfTheFourWindsCreatureAI(npc_totfw_slipstream);
}
