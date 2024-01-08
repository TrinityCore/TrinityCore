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
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "pit_of_saron.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_FIREBALL              = 69583, //Ymirjar Flamebearer
    SPELL_HELLFIRE              = 69586,
    SPELL_TACTICAL_BLINK        = 69584,
    SPELL_FROST_BREATH          = 69527, //Iceborn Proto-Drake
    SPELL_LEAPING_FACE_MAUL     = 69504, // Geist Ambusher
};

enum Events
{
    // Ymirjar Flamebearer
    EVENT_FIREBALL              = 1,
    EVENT_TACTICAL_BLINK        = 2,
};

bool ScheduledIcicleSummons::Execute(uint64 /*time*/, uint32 /*diff*/)
{
    if (roll_chance_i(12))
    {
        _trigger->CastSpell(_trigger, SPELL_ICICLE_SUMMON, true);
        _trigger->m_Events.AddEvent(new ScheduledIcicleSummons(_trigger), _trigger->m_Events.CalculateTime(randtime(20s, 35s)));
    }
    else
        _trigger->m_Events.AddEvent(new ScheduledIcicleSummons(_trigger), _trigger->m_Events.CalculateTime(randtime(1s, 20s)));

    return true;
}

struct npc_ymirjar_flamebearer: public ScriptedAI
{
    npc_ymirjar_flamebearer(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_FIREBALL, 4s);
        _events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15s);
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
                case EVENT_FIREBALL:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FIREBALL);
                    _events.RescheduleEvent(EVENT_FIREBALL, 5s);
                    break;
                case EVENT_TACTICAL_BLINK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_TACTICAL_BLINK);
                    DoCast(me, SPELL_HELLFIRE);
                    _events.RescheduleEvent(EVENT_TACTICAL_BLINK, 12s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_iceborn_protodrake: public ScriptedAI
{
    npc_iceborn_protodrake(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _frostBreathCooldown = 5000;
    }

    void Reset() override
    {
        Initialize();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (Vehicle* _vehicle = me->GetVehicleKit())
            _vehicle->RemoveAllPassengers();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (_frostBreathCooldown < diff)
        {
            DoCastVictim(SPELL_FROST_BREATH);
            _frostBreathCooldown = 10000;
        }
        else
            _frostBreathCooldown -= diff;
    }

private:
    uint32 _frostBreathCooldown;
};

struct npc_geist_ambusher: public ScriptedAI
{
    npc_geist_ambusher(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _leapingFaceMaulCooldown = 9000;
    }

    void Reset() override
    {
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER)
            return;

        // the max range is determined by aggro range
        if (me->GetDistance(who) > 5.0f)
            DoCast(who, SPELL_LEAPING_FACE_MAUL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (_leapingFaceMaulCooldown < diff)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 5.0f, true))
                DoCast(target, SPELL_LEAPING_FACE_MAUL);
            _leapingFaceMaulCooldown = urand(9000, 14000);
        }
        else
            _leapingFaceMaulCooldown -= diff;
    }

private:
    uint32 _leapingFaceMaulCooldown;
};

struct npc_pit_of_saron_icicle : public PassiveAI
{
    npc_pit_of_saron_icicle(Creature* creature) : PassiveAI(creature)
    {
        me->SetDisplayFromModel(0);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        _summonerGUID = summoner->GetGUID();

        _scheduler.Schedule(Milliseconds(3650), [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_ICICLE_FALL_TRIGGER, true);
            DoCastSelf(SPELL_ICICLE_FALL_VISUAL);

            if (Unit* caster = ObjectAccessor::GetUnit(*me, _summonerGUID))
                caster->RemoveDynObject(SPELL_ICICLE_SUMMON);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _summonerGUID;
};

// 70827 - Ice Shards
class spell_pos_ice_shards : public SpellScript
{
    bool Load() override
    {
        // This script should execute only in Pit of Saron
        return InstanceHasScript(GetCaster(), PoSScriptName);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (GetHitPlayer())
            GetCaster()->GetInstanceScript()->SetData(DATA_ICE_SHARDS_HIT, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pos_ice_shards::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

enum TyrannusEventCavernEmote
{
    SAY_TYRANNUS_CAVERN_ENTRANCE = 3
};

class at_pit_cavern_entrance : public AreaTriggerScript
{
    public:
        at_pit_cavern_entrance() : AreaTriggerScript("at_pit_cavern_entrance") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (instance->GetData(DATA_CAVERN_ACTIVE))
                    return true;

                instance->SetData(DATA_CAVERN_ACTIVE, 1);

                if (Creature* tyrannus = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_TYRANNUS_EVENT)))
                    tyrannus->AI()->Talk(SAY_TYRANNUS_CAVERN_ENTRANCE);
            }
            return true;
        }
};

class at_pit_cavern_end : public AreaTriggerScript
{
public:
    at_pit_cavern_end() : AreaTriggerScript("at_pit_cavern_end") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            instance->SetData(DATA_CAVERN_ACTIVE, 0);

            if (!instance->GetData(DATA_ICE_SHARDS_HIT))
                instance->DoUpdateCriteria(CriteriaType::BeSpellTarget, SPELL_DONT_LOOK_UP_ACHIEV_CREDIT, 0, player);
        }

        return true;
    }
};

void AddSC_pit_of_saron()
{
    RegisterPitOfSaronCreatureAI(npc_ymirjar_flamebearer);
    RegisterPitOfSaronCreatureAI(npc_iceborn_protodrake);
    RegisterPitOfSaronCreatureAI(npc_geist_ambusher);
    RegisterPitOfSaronCreatureAI(npc_pit_of_saron_icicle);
    RegisterSpellScript(spell_pos_ice_shards);
    new at_pit_cavern_entrance();
    new at_pit_cavern_end();
}
