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
#include "blackfathom_deeps.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_BLESSING_OF_BLACKFATHOM                           = 8733,
    SPELL_RAVAGE                                            = 8391,
    SPELL_FROST_NOVA                                        = 865,
    SPELL_FROST_BOLT_VOLLEY                                 = 8398,
    SPELL_TELEPORT_DARNASSUS                                = 9268
};

struct go_blackfathom_altar : public GameObjectAI
{
    go_blackfathom_altar(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* player) override
    {
        if (!player->HasAura(SPELL_BLESSING_OF_BLACKFATHOM))
            player->AddAura(SPELL_BLESSING_OF_BLACKFATHOM, player);
        return true;
    }
};

struct go_blackfathom_fire : public GameObjectAI
{
    go_blackfathom_fire(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

    InstanceScript* instance;

    bool OnGossipHello(Player* /*player*/) override
    {
        me->SetGoState(GO_STATE_ACTIVE);
        me->SetFlag(GO_FLAG_NOT_SELECTABLE);
        instance->SetData(DATA_FIRE, instance->GetData(DATA_FIRE) + 1);
        return true;
    }
};

enum Events
{
    EVENT_RAVAGE = 1,
    EVENT_FROST_NOVA,
    EVENT_FROST_BOLT_VOLLEY
};

struct npc_blackfathom_deeps_event : public ScriptedAI
{
    npc_blackfathom_deeps_event(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()), _flee(false) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _flee = false;

        switch (me->GetEntry())
        {
            case NPC_AKU_MAI_SNAPJAW:
                _events.ScheduleEvent(EVENT_RAVAGE, 5s, 8s);
                break;
            case NPC_AKU_MAI_SERVANT:
                _events.ScheduleEvent(EVENT_FROST_NOVA, 9s, 12s);
                _events.ScheduleEvent(EVENT_FROST_BOLT_VOLLEY, 2s, 4s);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _events.Reset();
        ScriptedAI::EnterEvadeMode(why);
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->IsSummon()) //we are not a normal spawn.
            _instance->SetData(DATA_EVENT, _instance->GetData(DATA_EVENT) + 1);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetEntry() != NPC_MURKSHALLOW_SOFTSHELL && me->GetEntry() != NPC_BARBED_CRUSTACEAN)
            return;

        if (!_flee && me->HealthBelowPctDamaged(15, damage))
        {
            _flee = true;
            me->DoFleeToGetAssistance();
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
                case EVENT_RAVAGE:
                    DoCastVictim(SPELL_RAVAGE);
                    _events.Repeat(9s, 14s);
                    break;
                case EVENT_FROST_NOVA:
                    DoCastAOE(SPELL_FROST_NOVA, false);
                    _events.Repeat(25s, 30s);
                    break;
                case EVENT_FROST_BOLT_VOLLEY:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FROST_BOLT_VOLLEY);
                    _events.Repeat(5s, 8s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _flee;
};

enum Morridune
{
    SAY_MORRIDUNE_1 = 0,
    SAY_MORRIDUNE_2 = 1,

    PATH_ESCORT_MORRIDUNE = 53834,
};

struct npc_morridune : public EscortAI
{
    npc_morridune(Creature* creature) : EscortAI(creature) { }

    void Reset() override
    {
        Talk(SAY_MORRIDUNE_1);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        LoadPath(PATH_ESCORT_MORRIDUNE);
        Start(false);
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        switch (waypointId)
        {
            case 4:
                SetEscortPaused(true);
                me->SetFacingTo(1.775791f);
                me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_MORRIDUNE_2);
                break;
        }
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        DoCast(player, SPELL_TELEPORT_DARNASSUS);
        return false;
    }
};

// 151159 - Darkness Calls
class spell_subjugator_korul_darkness_calls : public SpellScriptLoader
{
public:
    spell_subjugator_korul_darkness_calls() : SpellScriptLoader("spell_subjugator_korul_darkness_calls") { }

    class spell_subjugator_korul_darkness_calls_SpellScript : public SpellScript
    {
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* hitUnit = GetHitUnit())
                GetCaster()->CastSpell(hitUnit, uint32(GetEffectValue()), true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_subjugator_korul_darkness_calls_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnEffectHitTarget += SpellEffectFn(spell_subjugator_korul_darkness_calls_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_subjugator_korul_darkness_calls_SpellScript();
    }
};

void AddSC_blackfathom_deeps()
{
    RegisterBlackfathomDeepsGameObjectAI(go_blackfathom_altar);
    RegisterBlackfathomDeepsGameObjectAI(go_blackfathom_fire);
    RegisterBlackfathomDeepsCreatureAI(npc_blackfathom_deeps_event);
    RegisterBlackfathomDeepsCreatureAI(npc_morridune);
    new spell_subjugator_korul_darkness_calls();
}
