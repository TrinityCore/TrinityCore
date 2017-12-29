/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
#include "dragon_soul.h"
#include "ScriptedGossip.h"

class npc_eiendormi : public CreatureScript
{
    public:
        npc_eiendormi() : CreatureScript("npc_eiendormi") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                creature->CastSpell(creature, SPELL_WARDEN_RING_YELLOW);

                if (instance->GetBossState(DATA_MORCHOK) == DONE)
                    player->TeleportTo(967, -1870.114f, -3077.727f, -176.308f, 0.390f);
            }

            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
};

class npc_valeera_tele : public CreatureScript
{
    public:
        npc_valeera_tele() : CreatureScript("npc_valeera_tele") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                creature->CastSpell(creature, SPELL_WARDEN_RING_GREEN);

                if (instance->GetBossState(DATA_MORCHOK) == DONE)
                    player->TeleportTo(967, -1735.930f, -1818.239f, -219.328f, 0.0f);
            }

            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
};

class npc_nethestrasz : public CreatureScript
{
    public:
        npc_nethestrasz() : CreatureScript("npc_nethestrasz") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                creature->CastSpell(creature, SPELL_WARDEN_RING_ORANGE);

                if (instance->GetBossState(DATA_YORSAHJ) == DONE && instance->GetBossState(DATA_ZONOZZ) == DONE)
                    player->TeleportTo(967, -1786.69f, -2393.67f, 341.355f, 0.16f);
            }

            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }
};

class travel_to_wyrmrest_base : public CreatureScript
{
    public:
        travel_to_wyrmrest_base() : CreatureScript("travel_to_wyrmrest_base") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                if (!instance->IsEncounterInProgress())
                {
                    player->TeleportTo(967, -1793.22f, -2391.78f, 45.604f, 5.871f);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
            }

            CloseGossipMenuFor(player);
            return true;
        }
};

class travel_to_wyrmrest_summit : public CreatureScript
{
    public:
        travel_to_wyrmrest_summit() : CreatureScript("travel_to_wyrmrest_summit") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                if (!instance->IsEncounterInProgress())
                {
                    player->TeleportTo(967, -1786.92f, -2393.18f, 341.355f, 6.141f);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
            }

            CloseGossipMenuFor(player);
            return true;
        }
};

class travel_to_the_eye_of_eternity : public CreatureScript
{
    public:
        travel_to_the_eye_of_eternity() : CreatureScript("travel_to_the_eye_of_eternity") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_YORSAHJ) == DONE && instance->GetBossState(DATA_ZONOZZ) == DONE)
                {
                    player->TeleportTo(967, 13629.7f, 13611.9f, 123.482f, 3.468f);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
            }

            CloseGossipMenuFor(player);
            return true;
        }
};

class travel_to_the_deck_of_the_skyfire : public CreatureScript
{
    public:
        travel_to_the_deck_of_the_skyfire() : CreatureScript("travel_to_the_deck_of_the_skyfire") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (InstanceScript* instance = creature->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_ULTRAXION) == DONE)
                {
                    player->TeleportTo(967, 13397.298f, -12131.405f, 153.8732f, 3.152f);
                    SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
            }

            CloseGossipMenuFor(player);
            return true;
        }
};

void AddSC_dragon_soul_teleport_and_transport()
{
    new npc_eiendormi();
    new npc_valeera_tele();
    new npc_nethestrasz();
    new travel_to_wyrmrest_base;
    new travel_to_wyrmrest_summit;
    new travel_to_the_eye_of_eternity;
    new travel_to_the_deck_of_the_skyfire;
}
