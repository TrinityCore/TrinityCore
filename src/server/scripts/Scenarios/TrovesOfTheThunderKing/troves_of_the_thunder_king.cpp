/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "troves_of_the_thunder_king.h"
#include "ScriptedCreature.h"

class npc_taoshi : public CreatureScript
{
public:
    npc_taoshi() : CreatureScript("npc_taoshi") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (InstanceScript* instance = creature->GetInstanceScript())
        {
            if (instance->GetData(DATA_EVENT_STARTED) == NOT_STARTED)
                player->ADD_GOSSIP_ITEM_DB(15571, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            else
                player->ADD_GOSSIP_ITEM_DB(15572, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

            return true;
        }
        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        InstanceScript* instance = creature->GetInstanceScript();
        if (!action || !instance)
            return false;

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            instance->SetData(DATA_EVENT_STARTED, DONE);
            player->CastSpell(player, SPELL_TIMED_RUN_STARTED_SPELL); // REQ item 94222 - Key to the Palace of Lei Shen
            player->AddAura(SPELL_LIMITED_TIME, player);
            player->AddAura(SPELL_TROVES_OF_THE_THUNDER_KING, player);
            creature->AI()->DoAction(ACTION_1);
        }

        if (action == GOSSIP_ACTION_INFO_DEF + 2)
            player->TeleportTo(1064, 6889.38f, 5517.79f, 2.08655f, 2.407245f); //< via 140010 but core dont support this :(

        creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        player->CLOSE_GOSSIP_MENU();

        return true;
    }

    struct npc_taoshiAI : ScriptedAI
    {
        npc_taoshiAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            events.Reset();
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case ACTION_1:
                    events.RescheduleEvent(EVENT_1, 1 * IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        events.RescheduleEvent(EVENT_2, 5 * MINUTE * IN_MILLISECONDS);
                        break;
                    case EVENT_2:
                    {
                        events.RescheduleEvent(EVENT_3, 2 * IN_MILLISECONDS);
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        if (Player* player = players.begin()->getSource())
                        {
                            player->CastSpell(player, SPELL_SCENARIO_COMPLETION_CREDIT);
                            player->CastSpell(player, SPELL_SCENARIO_COMPLETION_BLACKOUT_AURA);
                        }
                        Talk(1);
                        break;
                    }
                    case EVENT_3:
                    {
                        events.RescheduleEvent(EVENT_4, 5 * IN_MILLISECONDS);
                        Map::PlayerList const& players = me->GetMap()->GetPlayers();
                        if (Player* player = players.begin()->getSource())
                            player->NearTeleportTo(-459.669f, 1078.73f, 133.647f, 1.515818f);
                        break;
                    }
                    case EVENT_4:
                        Talk(0);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_taoshiAI(creature);
    }
};

class npc_lighting_pilar_master_bunny : public CreatureScript
{
public:
    npc_lighting_pilar_master_bunny() : CreatureScript("npc_lighting_pilar_master_bunny") { }

    struct npc_lighting_pilar_master_bunnyAI : ScriptedAI
    {
        npc_lighting_pilar_master_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
                case ACTION_1:
                    events.RescheduleEvent(EVENT_1, 2 * IN_MILLISECONDS);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        events.RescheduleEvent(EVENT_1, 15 * IN_MILLISECONDS);
                        me->AddAura(SPELL_LIGHTING_SURGE_2, me);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lighting_pilar_master_bunnyAI(creature);
    }
};

class npc_stone_sentiel : public CreatureScript
{
public:
    npc_stone_sentiel() : CreatureScript("npc_stone_sentiel") { }

    struct npc_stone_sentielAI : ScriptedAI
    {
        npc_stone_sentielAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            cast = false;
            me->AddAura(SPELL_DESATUREATE, me);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) < 16.0f && !cast && who->GetTypeId() == TYPEID_PLAYER)
                events.RescheduleEvent(EVENT_1, 3 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        events.RescheduleEvent(EVENT_2, 3 * IN_MILLISECONDS);
                        me->AddAura(SPELL_STATUE_FROZEN_SLAM_PREP, me);
                        break;
                    case EVENT_2:
                        events.RescheduleEvent(EVENT_3, 3 * IN_MILLISECONDS);
                        DoCast(SPELL_STONE_SMASH);
                        break;
                    case EVENT_3:
                        cast = false;
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
        bool cast;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_stone_sentielAI(creature);
    }
};

class spell_lighting_surge_2 : public SpellScriptLoader
{
public:
    spell_lighting_surge_2() : SpellScriptLoader("spell_lighting_surge_2") { }

    class spell_lighting_surge_2_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lighting_surge_2_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(CreatureTargetFilter());
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lighting_surge_2_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lighting_surge_2_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
        }

    private:
        class CreatureTargetFilter
        {
        public:
            CreatureTargetFilter() { }

            bool operator()(WorldObject* target)
            {
                return target->ToCreature()->GetEntry() != NPC_LIGHTING_PILAR_TARGET_BUNNY;
            }
        };
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lighting_surge_2_SpellScript();
    }
};

void AddSC_troves_of_the_thunder_king()
{
    new npc_taoshi();
    new npc_lighting_pilar_master_bunny();
    new npc_stone_sentiel();

    new spell_lighting_surge_2();
}
