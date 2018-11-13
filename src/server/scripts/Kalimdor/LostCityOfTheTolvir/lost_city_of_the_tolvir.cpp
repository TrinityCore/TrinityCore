/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "lost_city_of_the_tolvir.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"

enum Texts
{
    SAY_AGGRO       = 0,
    SAY_SMOKE_BOMB  = 1
};

enum Events
{
    EVENT_SMOKE_BOMB = 1,
    EVENT_EJECT_ALL_PASSENGERS
};

enum Spells
{
    SPELL_SMOKE_BOMB                    = 84768,
    SPELL_GENERIC_EJECT_ALL_PASSENGERS  = 79737,
    SPELL_RIDE_VEHICLE                  = 93970,
    SPELL_SLIPSTREAM                    = 85016
};

class npc_lct_augh : public CreatureScript
{
    public:
        npc_lct_augh() : CreatureScript("npc_lct_augh") { }

        struct npc_lct_aughAI : public ScriptedAI
        {
            npc_lct_aughAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _finishedPreFight = false;
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(50, damage) && !_finishedPreFight)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAuras();
                    DoCastSelf(SPELL_SMOKE_BOMB, true);
                    Talk(SAY_SMOKE_BOMB);
                    _events.ScheduleEvent(EVENT_SMOKE_BOMB, Milliseconds(800));
                    _finishedPreFight = true;
                }

                // Do not allow Augh to die
                if (damage > me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_finishedPreFight)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SMOKE_BOMB:
                            DoCastSelf(SPELL_SMOKE_BOMB);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            me->DespawnOrUnsummon(Seconds(1) + Milliseconds(200));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            bool _finishedPreFight;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetLostCityOfTheTolvirAI<npc_lct_aughAI>(creature);
        }
};

struct npc_lct_wind_tunnel_landing_zone : public ScriptedAI
{
    npc_lct_wind_tunnel_landing_zone(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisableGravity(true);
        me->SetExtraUnitMovementFlags(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!who)
            return;

        if (apply)
        {
            who->SetDisableGravity(true, true);
            _events.ScheduleEvent(EVENT_EJECT_ALL_PASSENGERS, 1s + 500ms);
        }
        else
            who->SetDisableGravity(false, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EJECT_ALL_PASSENGERS:
                    DoCast(me, SPELL_GENERIC_EJECT_ALL_PASSENGERS);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

class SlipstreamEvent : public BasicEvent
{
    public:
        SlipstreamEvent(Unit* owner, ObjectGuid windtunnelGuid) : _owner(owner), _windTunnelGUID(windtunnelGuid) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (Creature* windtunnel = ObjectAccessor::GetCreature(*_owner, _windTunnelGUID))
                windtunnel->CastSpell(_owner, SPELL_SLIPSTREAM);
            return true;
        }
    private:
        Unit* _owner;
        ObjectGuid _windTunnelGUID;
};

struct npc_lct_wind_tunnel : public ScriptedAI
{
    npc_lct_wind_tunnel(Creature* creature) : ScriptedAI(creature) { }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!who)
            return;

        if (apply)
        {
            who->SetDisableGravity(true, true);
            who->m_Events.AddEvent(new SlipstreamEvent(who, me->GetGUID()), who->m_Events.CalculateTime(500));
        }
    }

private:
    EventMap _events;
};

void AddSC_lost_city_of_the_tolvir()
{
    new npc_lct_augh();
    RegisterCreatureAI(npc_lct_wind_tunnel_landing_zone);
    RegisterCreatureAI(npc_lct_wind_tunnel);
}
