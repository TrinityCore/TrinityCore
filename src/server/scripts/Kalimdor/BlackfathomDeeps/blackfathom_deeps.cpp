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
#include "Map.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_BLESSING_OF_BLACKFATHOM                           = 8733,
    SPELL_RAVAGE                                            = 8391,
    SPELL_FROST_NOVA                                        = 865,
    SPELL_FROST_BOLT_VOLLEY                                 = 8398,
    SPELL_TELEPORT_DARNASSUS                                = 9268
};

const Position HomePosition = {-815.817f, -145.299f, -25.870f, 0};

class go_blackfathom_altar : public GameObjectScript
{
    public:
        go_blackfathom_altar() : GameObjectScript("go_blackfathom_altar") { }

        struct go_blackfathom_altarAI : public GameObjectAI
        {
            go_blackfathom_altarAI(GameObject* go) : GameObjectAI(go) { }

            bool OnGossipHello(Player* player) override
            {
                if (!player->HasAura(SPELL_BLESSING_OF_BLACKFATHOM))
                    player->AddAura(SPELL_BLESSING_OF_BLACKFATHOM, player);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetBlackfathomDeepsAI<go_blackfathom_altarAI>(go);
        }
};

class go_blackfathom_fire : public GameObjectScript
{
    public:
        go_blackfathom_fire() : GameObjectScript("go_blackfathom_fire") { }

        struct go_blackfathom_fireAI : public GameObjectAI
        {
            go_blackfathom_fireAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* /*player*/) override
            {
                me->SetGoState(GO_STATE_ACTIVE);
                me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                instance->SetData(DATA_FIRE, instance->GetData(DATA_FIRE) + 1);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetBlackfathomDeepsAI<go_blackfathom_fireAI>(go);
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

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _flee;
};

enum Morridune
{
    SAY_MORRIDUNE_1 = 0,
    SAY_MORRIDUNE_2 = 1
};

class npc_morridune : public CreatureScript
{
public:
    npc_morridune() : CreatureScript("npc_morridune") { }

    struct npc_morriduneAI : public EscortAI
    {
        npc_morriduneAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override
        {
            Talk(SAY_MORRIDUNE_1);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Start(false);
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 4:
                    SetEscortPaused(true);
                    me->SetFacingTo(1.775791f);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackfathomDeepsAI<npc_morriduneAI>(creature);
    }
};

void AddSC_blackfathom_deeps()
{
    new go_blackfathom_altar();
    new go_blackfathom_fire();
    RegisterBlackfathomDeepsCreatureAI(npc_blackfathom_deeps_event);
    new npc_morridune();
}
