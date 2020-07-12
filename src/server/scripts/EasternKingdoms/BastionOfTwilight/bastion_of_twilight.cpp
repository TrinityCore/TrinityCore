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

#include "InstanceScript.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Object.h"
#include "PassiveAI.h"
#include "Player.h"
#include "bastion_of_twilight.h"

#include <vector>

enum PhaseTwist
{
    // Events
    EVENT_REGISTER_TWISTERS = 1,
    EVENT_CHECK_TWISTERS,
    EVENT_PHASE_BURN,

    // Spells
    SPELL_PHASED_BURN = 85799
};

struct npc_bot_invisible_stalker_phase_twist : public NullCreatureAI
{
    npc_bot_invisible_stalker_phase_twist(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_REGISTER_TWISTERS, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_REGISTER_TWISTERS:
                    me->GetCreatureListWithEntryInGrid(_phaseTwisterVector, NPC_TWILIGHT_PHASE_SHIFTER, 10.f);
                    if (_phaseTwisterVector.empty()) // if the twister have not been added to the grid yet, keep searching
                        _events.Repeat(1s);
                    else
                    {
                        _events.ScheduleEvent(EVENT_CHECK_TWISTERS, 1s);
                        _events.ScheduleEvent(EVENT_PHASE_BURN, 1s);
                    }
                    break;
                case EVENT_CHECK_TWISTERS:
                {
                    uint8 deadTwisters = 0;
                    for (Unit const* twister : _phaseTwisterVector)
                    {
                        if (!twister || twister->isDead())
                            ++deadTwisters;
                    }

                    if (deadTwisters == _phaseTwisterVector.size())
                    {
                        _events.Reset();
                        me->InterruptNonMeleeSpells(true);
                        me->RemoveAllAuras();
                        me->DespawnOrUnsummon(4s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                }
                case EVENT_PHASE_BURN:
                    if (Unit* target = me->SelectNearestTarget(40.f, true))
                    {
                        DoCast(target, SPELL_PHASED_BURN);
                        _events.Repeat(8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    std::vector<Creature*> _phaseTwisterVector;
};

class at_theralion_and_valiona_intro : public AreaTriggerScript
{
    public:
        at_theralion_and_valiona_intro() : AreaTriggerScript("at_theralion_and_valiona_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_THERALION_AND_VALIONA_INTRO, IN_PROGRESS);
            return true;
        }
};

class at_ascendant_council_intro_1 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_1() : AreaTriggerScript("at_ascendant_council_intro_1") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_1, IN_PROGRESS);
            return true;
        }
};

class at_ascendant_council_intro_2 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_2() : AreaTriggerScript("at_ascendant_council_intro_2") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_2, IN_PROGRESS);
            return true;
        }
};

class at_ascendant_council_intro_3 : public AreaTriggerScript
{
    public:
        at_ascendant_council_intro_3() : AreaTriggerScript("at_ascendant_council_intro_3") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_ASCENDANT_COUNCIL_INTRO_3, IN_PROGRESS);
            return true;
        }
};

class at_chogall_intro : public AreaTriggerScript
{
    public:
        at_chogall_intro() : AreaTriggerScript("at_chogall_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_AT_CHOGALL_INTRO, IN_PROGRESS);
            return true;
        }
};

void AddSC_bastion_of_twilight()
{
    RegisterBastionOfTwilightCreatureAI(npc_bot_invisible_stalker_phase_twist);
    new at_theralion_and_valiona_intro();
    new at_ascendant_council_intro_1();
    new at_ascendant_council_intro_2();
    new at_ascendant_council_intro_3();
    new at_chogall_intro();
}
