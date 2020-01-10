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

            bool GossipHello(Player* player) override
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

            bool GossipHello(Player* /*player*/) override
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

class npc_blackfathom_deeps_event : public CreatureScript
{
public:
    npc_blackfathom_deeps_event() : CreatureScript("npc_blackfathom_deeps_event") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackfathomDeepsAI<npc_blackfathom_deeps_eventAI>(creature);
    }

    struct npc_blackfathom_deeps_eventAI : public ScriptedAI
    {
        npc_blackfathom_deeps_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            if (creature->IsSummon())
            {
                creature->SetHomePosition(HomePosition);
                AttackPlayer();
            }

            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            Flee = false;

            ravageTimer = urand(5000, 8000);
            frostNovaTimer = urand(9000, 12000);
            frostBoltVolleyTimer = urand(2000, 4000);
        }

        InstanceScript* instance;

        uint32 ravageTimer;
        uint32 frostNovaTimer;
        uint32 frostBoltVolleyTimer;

        bool Flee;

        void Reset() override
        {
            Initialize();
        }

        void AttackPlayer()
        {
            Map::PlayerList const& PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    if (player->IsGameMaster())
                        continue;

                    if (player->IsAlive())
                    {
                        me->SetInCombatWith(player);
                        player->SetInCombatWith(me);
                        AddThreat(player, 0.0f);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            switch (me->GetEntry())
            {
                case NPC_AKU_MAI_SNAPJAW:
                {
                    if (ravageTimer <= diff)
                    {
                        DoCastVictim(SPELL_RAVAGE);
                        ravageTimer = urand(9000, 14000);
                    } else ravageTimer -= diff;
                    break;
                }
                case NPC_MURKSHALLOW_SOFTSHELL:
                case NPC_BARBED_CRUSTACEAN:
                {
                    if (!Flee && HealthBelowPct(15))
                    {
                        Flee = true;
                        me->DoFleeToGetAssistance();
                    }
                    break;
                }
                case NPC_AKU_MAI_SERVANT:
                {
                    if (frostBoltVolleyTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FROST_BOLT_VOLLEY);
                        frostBoltVolleyTimer = urand(5000, 8000);
                    }
                    else frostBoltVolleyTimer -= diff;

                    if (frostNovaTimer <= diff)
                    {
                        DoCastAOE(SPELL_FROST_NOVA, false);
                        frostNovaTimer = urand(25000, 30000);
                    }
                    else frostNovaTimer -= diff;
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (me->IsSummon()) //we are not a normal spawn.
                instance->SetData(DATA_EVENT, instance->GetData(DATA_EVENT) + 1);
        }
    };
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
        npc_morriduneAI(Creature* creature) : EscortAI(creature)
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

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
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
    new npc_blackfathom_deeps_event();
    new npc_morridune();
}
