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

struct npc_bot_invisible_stalker_phase_twist final : public NullCreatureAI
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

enum ChogallEvent
{
    // Texts
    SAY_HALFUS_INTRO = 0,
    SAY_HALFUS_DEAD  = 1
};

struct npc_bot_chogall final : public NullCreatureAI
{
    npc_bot_chogall(Creature* creature) : NullCreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TALK_HALFUS_WYRMBREAKER_INTRO:
                Talk(SAY_HALFUS_INTRO);
                break;
            case ACTION_TALK_HALFUS_WYRMBREAKER_DEAD:
                Talk(SAY_HALFUS_DEAD);
                break;
            default:
                break;
        }
    }
};

static constexpr uint32 const SPELL_WYVERN_STING_PERIODIC = 24336;

class spell_bot_wyvern_sting : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WYVERN_STING_PERIODIC });
    }

    void HandleAfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_WYVERN_STING_PERIODIC, CastSpellExtraArgs(true).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_bot_wyvern_sting::HandleAfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class at_bot_intro_events final : public OnlyOnceAreaTriggerScript
{
public:
    at_bot_intro_events(char const* scriptName, uint32 dataType) : OnlyOnceAreaTriggerScript(scriptName), _dataType(dataType) { }

    bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(_dataType, IN_PROGRESS);
        return true;
    }
private:
    uint32 _dataType;
};

void AddSC_bastion_of_twilight()
{
    RegisterBastionOfTwilightCreatureAI(npc_bot_invisible_stalker_phase_twist);
    RegisterBastionOfTwilightCreatureAI(npc_bot_chogall);
    RegisterSpellScript(spell_bot_wyvern_sting);
    new at_bot_intro_events("at_halfus_wyrmbreaker_intro", DATA_AT_HALFUS_WYRMBREAKER_INTRO);
    new at_bot_intro_events("at_theralion_and_valiona_intro", DATA_AT_THERALION_AND_VALIONA_INTRO);
    new at_bot_intro_events("at_ascendant_council_intro_1", DATA_AT_ASCENDANT_COUNCIL_INTRO_1);
    new at_bot_intro_events("at_ascendant_council_intro_2", DATA_AT_ASCENDANT_COUNCIL_INTRO_2);
    new at_bot_intro_events("at_ascendant_council_intro_3", DATA_AT_ASCENDANT_COUNCIL_INTRO_3);
    new at_bot_intro_events("at_chogall_intro", DATA_AT_CHOGALL_INTRO);
}
