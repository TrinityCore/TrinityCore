/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "Object.h"
#include "ObjectMgr.h"
#include "end_time.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

#define GOSSIP_SENDER_TIME_DELIVER_DEVICE 700

enum Bosses
{
    BOSS_ECHO_OF_JAINA,
    BOSS_ECHO_OF_SYLVANAS,
    BOSS_ECHO_OF_TYRANDE,
    BOSS_ECHO_OF_BAINE
};

struct instance_end_time : public InstanceScript
{
    instance_end_time(InstanceMap* map) : InstanceScript(map)
    {
        TeamInInstance = 0;
        murozondStarted = false;
        bossCount = 0;
    }

    void OnPlayerEnter(Player* player) override
    {
        if (!TeamInInstance)
        {
            TeamInInstance = player->GetTeam();

            uint32 boss1 = urand(0, 3);
            uint32 boss2 = urand(0, 3);

            while (boss1 == boss2)
                boss2 = urand(0, 3);

            SetData(FIRST_BOSS, boss1);
            SetData(SECOND_BOSS, boss2);

        }

        if (!GetData(DATA_MUROZOND_STARTED))
            player->RemoveAura(102668);
    }

    void OnUnitDeath(Unit* unit) override
    {
        Creature* creature = unit->ToCreature();
        if (!creature)
            return;

        if (GetData(DATA_MUROZOND_STARTED))
            return;

        switch (creature->GetEntry())
        {
            case NPC_INFINITE_SUPPRESSOR:
            case NPC_INFINITE_WARDEN:
            {
                MurozondTrash.erase(creature->GetSpawnId());
                if (MurozondTrash.empty() && bossCount > 1)
                    if (Creature* murozond = instance->GetCreature(MurozondGUID))
                        murozond->AI()->DoAction(ACTION_MUROZOND_START);

                break;
            }
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        switch (creature->GetEntry())
        {
            case NPC_BOSS_MUROZOND:
                MurozondGUID = creature->GetGUID();
                break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case FIRST_BOSS:
                firstBoss = data;
                break;
            case SECOND_BOSS:
                secondBoss = data;
                break;
            case DATA_MUROZOND_TRASH:
                MurozondTrash.insert(data);
                break;
            case DATA_MUROZOND_STARTED:
                murozondStarted = data;
                break;
            case DATA_BOSS_COUNT:
                //sLog->outError(LOG_FILTER_GENERAL, "bossCount = %u", bossCount);
                bossCount++;
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override 
    {
        switch (type)
        {
            case FIRST_BOSS:
                return firstBoss;
            case SECOND_BOSS:
                return secondBoss;
            case DATA_MUROZOND_TRASH:
                return MurozondTrash.size();
            case DATA_MUROZOND_STARTED:
                return murozondStarted;
            case DATA_BOSS_COUNT:
                return bossCount;
            default:
                break;
        }

        return 0;
    }


protected:
    uint32 TeamInInstance;
    uint32 firstBoss;
    uint32 secondBoss;
    ObjectGuid MurozondGUID;
    bool murozondStarted;
    std::set<uint32> MurozondTrash;

    uint32 bossCount;
};

class time_deliver_device : public GameObjectScript
{
    public:
        time_deliver_device() : GameObjectScript("time_deliver_device") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            go->SetGoState(GO_STATE_READY);
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->GetData(DATA_BOSS_COUNT) == 0)
                {
                    if (instance->GetData(FIRST_BOSS) == BOSS_ECHO_OF_JAINA)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Azure Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, AZURE_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(FIRST_BOSS) == BOSS_ECHO_OF_SYLVANAS)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ruby Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, RUBY_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(FIRST_BOSS) == BOSS_ECHO_OF_TYRANDE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Obsidian Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, BLACK_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(FIRST_BOSS) == BOSS_ECHO_OF_BAINE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Emerald Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, EMERALD_DRAGONSHIRINE_TELEPORT);
                }

                if (instance->GetData(DATA_BOSS_COUNT) == 1)
                {
                    if (instance->GetData(SECOND_BOSS) == BOSS_ECHO_OF_JAINA)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Azure Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, AZURE_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(SECOND_BOSS) == BOSS_ECHO_OF_SYLVANAS)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Ruby Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, RUBY_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(SECOND_BOSS) == BOSS_ECHO_OF_TYRANDE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Obsidian Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, BLACK_DRAGONSHIRINE_TELEPORT);
                    if (instance->GetData(SECOND_BOSS) == BOSS_ECHO_OF_BAINE)
                        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Emerald Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, EMERALD_DRAGONSHIRINE_TELEPORT);
                }

                if (instance->GetData(DATA_BOSS_COUNT) >= 2)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Bronze Dragonshirine", GOSSIP_SENDER_TIME_DELIVER_DEVICE, BRONZE_DRAGONSHIRINE_TELEPORT);
                }
            }
            SendGossipMenuFor(player, player->GetGossipTextId(go), go->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* /*go*/, uint32 sender, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();
            CloseGossipMenuFor(player);
            SpellInfo const* spell = sSpellMgr->GetSpellInfo(action);
            if (!spell)
                return false;

            if (player->IsInCombat())
            {
                //Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (sender == GOSSIP_SENDER_TIME_DELIVER_DEVICE)
                player->CastSpell(player, spell, true);

            return true;
        }
};

void AddSC_instance_end_time()
{
    RegisterInstanceScript(instance_end_time, 938);
    new time_deliver_device();
}
