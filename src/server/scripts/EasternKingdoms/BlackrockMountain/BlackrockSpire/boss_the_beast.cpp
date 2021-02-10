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
#include "blackrock_spire.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"

enum BeastSpells
{
    SPELL_FLAMEBREAK                = 16785,
    SPELL_IMMOLATE                  = 15570,
    SPELL_TERRIFYINGROAR            = 14100,
    SPELL_BERSERKER_CHARGE          = 16636,
    SPELL_FIREBALL                  = 16788,
    SPELL_FIREBLAST                 = 16144,
    SPELL_FINKLE_IS_EINHORN         = 16710,
    SPELL_SUICIDE                   = 7
};

enum BeastEvents
{
    EVENT_FLAME_BREAK               = 1,
    EVENT_IMMOLATE                  = 2,
    EVENT_TERRIFYING_ROAR           = 3,
    EVENT_BERSERKER_CHARGE          = 4,
    EVENT_FIREBALL                  = 5,
    EVENT_FIREBLAST                 = 6
};

enum BeastMisc
{
    DATA_BEAST_REACHED              = 1,
    DATA_BEAST_ROOM                 = 2,
    BEAST_MOVEMENT_ID               = 1379690,

    NPC_BLACKHAND_ELITE             = 10317,

    SAY_BLACKHAND_DOOMED            = 0
};

Position const OrcsRunawayPosition = { 34.163567f, -536.852356f, 110.935196f, 6.056306f };

class OrcDeathEvent : public BasicEvent
{
public:
    OrcDeathEvent(Creature* me) : _me(me) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _me->CastSpell(_me, SPELL_SUICIDE, true);
        return true;
    }

private:
    Creature* _me;
};

struct boss_the_beast : public BossAI
{
    boss_the_beast(Creature* creature) : BossAI(creature, DATA_THE_BEAST), _beastReached(false), _orcYelled(false) { }

    void Reset() override
    {
        _Reset();
        if (_beastReached)
            me->GetMotionMaster()->MovePath(BEAST_MOVEMENT_ID, true);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (spellInfo->Effects[i].IsEffect(SPELL_EFFECT_SKINNING))
                if (!me->IsAlive()) // can that even happen?
                    DoCastAOE(SPELL_FINKLE_IS_EINHORN, true);
    }

    void SetData(uint32 type, uint32 /*data*/) override
    {
        switch (type)
        {
            case DATA_BEAST_ROOM:
            {
                if (!_orcYelled)
                {
                    if (_nearbyOrcsGUIDs.empty())
                        FindNearbyOrcs();

                    //! vector still empty, creatures are missing
                    if (_nearbyOrcsGUIDs.empty())
                        return;

                    _orcYelled = true;

                    // we only need one orc to say the line
                    if (Creature* orc = ObjectAccessor::GetCreature(*me, _nearbyOrcsGUIDs.front()))
                        orc->AI()->Talk(SAY_BLACKHAND_DOOMED);
                }
                break;
            }
            case DATA_BEAST_REACHED:
            {
                if (!_beastReached)
                {
                    _beastReached = true;
                    me->GetMotionMaster()->MovePath(BEAST_MOVEMENT_ID, true);

                    if (_nearbyOrcsGUIDs.empty())
                        FindNearbyOrcs();

                    for (ObjectGuid guid : _nearbyOrcsGUIDs)
                    {
                        if (Creature* orc = ObjectAccessor::GetCreature(*me, guid))
                        {
                            orc->GetMotionMaster()->MovePoint(1, orc->GetRandomPoint(OrcsRunawayPosition, 5.0f));
                            orc->m_Events.AddEvent(new OrcDeathEvent(orc), me->m_Events.CalculateTime(6s));
                            orc->SetReactState(REACT_PASSIVE);
                        }
                    }
                    // There is a chance player logged in between areatriggers (realm crash or restart)
                    // executing part of script which happens when player enters boss room
                    // otherwise we will see weird behaviour when someone steps on the previous areatrigger (dead mob yelling/moving)
                    SetData(DATA_BEAST_ROOM, DATA_BEAST_ROOM);
                }
                break;
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_FLAME_BREAK, 12s);
        events.ScheduleEvent(EVENT_IMMOLATE, 3s);
        events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 23s);
        events.ScheduleEvent(EVENT_BERSERKER_CHARGE, 2s);
        events.ScheduleEvent(EVENT_FIREBALL, 8s, 21s);
        events.ScheduleEvent(EVENT_FIREBLAST, 5s, 8s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FLAME_BREAK:
                    DoCastVictim(SPELL_FLAMEBREAK);
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_IMMOLATE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.f, true))
                        DoCast(target, SPELL_IMMOLATE);
                    events.Repeat(Seconds(8));
                    break;
                case EVENT_TERRIFYING_ROAR:
                    DoCastVictim(SPELL_TERRIFYINGROAR);
                    events.Repeat(Seconds(20));
                    break;
                case EVENT_BERSERKER_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 38.f, true))
                        DoCast(target, SPELL_BERSERKER_CHARGE);
                    events.Repeat(Seconds(15), Seconds(23));
                    break;
                case EVENT_FIREBALL:
                    DoCastVictim(SPELL_FIREBALL);
                    events.Repeat(Seconds(8), Seconds(21));
                    break;
                case EVENT_FIREBLAST:
                    DoCastVictim(SPELL_FIREBLAST);
                    events.Repeat(Seconds(5), Seconds(8));
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }

    void FindNearbyOrcs()
    {
        std::vector<Creature*> temp;
        me->GetCreatureListWithEntryInGrid(temp, NPC_BLACKHAND_ELITE, 50.0f);

        for (Creature* creature : temp)
            _nearbyOrcsGUIDs.push_back(creature->GetGUID());
    }

private:
    bool _beastReached;
    bool _orcYelled;
    GuidVector _nearbyOrcsGUIDs;
};

//! The beast room areatrigger, this one triggers boss pathing. (AT Id 2066)
class at_trigger_the_beast_movement : public AreaTriggerScript
{
public:
    at_trigger_the_beast_movement() : AreaTriggerScript("at_trigger_the_beast_movement") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) override
    {
        if (player->IsGameMaster())
            return false;

        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* beast = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_THE_BEAST)))
                beast->AI()->SetData(DATA_BEAST_REACHED, DATA_BEAST_REACHED);
            return true;
        }
        return false;
    }
};

class at_the_beast_room : public AreaTriggerScript
{
public:
    at_the_beast_room() : AreaTriggerScript("at_the_beast_room") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) override
    {
        if (player->IsGameMaster())
            return false;

        if (InstanceScript* instance = player->GetInstanceScript())
        {
            if (Creature* beast = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_THE_BEAST)))
                beast->AI()->SetData(DATA_BEAST_ROOM, DATA_BEAST_ROOM);
            return true;
        }
        return false;
    }
};

void AddSC_boss_thebeast()
{
    RegisterBlackrockSpireCreatureAI(boss_the_beast);
    new at_trigger_the_beast_movement();
    new at_the_beast_room();
}
