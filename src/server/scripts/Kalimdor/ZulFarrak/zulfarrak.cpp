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

/* ScriptData
SDName: Zulfarrak
SD%Complete: 50
SDComment: Consider it temporary, no instance script made for this instance yet.
SDCategory: Zul'Farrak
EndScriptData */

/* ContentData
npc_sergeant_bly
npc_weegli_blastfuse
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "zulfarrak.h"

/*######
## npc_sergeant_bly
######*/

enum blySays
{
    SAY_1 = 0,
    SAY_2 = 1
};

enum blySpells
{
    SPELL_SHIELD_BASH          = 11972,
    SPELL_REVENGE              = 12170
};

#define GOSSIP_BLY                  "That's it!  I'm tired of helping you out.  It's time we settled things on the battlefield!"

class npc_sergeant_bly : public CreatureScript
{
public:
    npc_sergeant_bly() : CreatureScript("npc_sergeant_bly") { }

    struct npc_sergeant_blyAI : public ScriptedAI
    {
        npc_sergeant_blyAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
            postGossipStep = 0;
            Text_Timer = 0;
        }

        void Initialize()
        {
            ShieldBash_Timer = 5000;
            Revenge_Timer = 8000;
        }

        InstanceScript* instance;

        uint32 postGossipStep;
        uint32 Text_Timer;
        uint32 ShieldBash_Timer;
        uint32 Revenge_Timer;                                   //this is wrong, spell should never be used unless me->GetVictim() dodge, parry or block attack. Trinity support required.
        ObjectGuid PlayerGUID;

        void Reset() override
        {
            Initialize();

            me->SetFaction(FACTION_FRIENDLY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (postGossipStep>0 && postGossipStep<4)
            {
                if (Text_Timer<diff)
                {
                    switch (postGossipStep)
                    {
                        case 1:
                            //weegli doesn't fight - he goes & blows up the door
                            if (Creature* pWeegli = ObjectAccessor::GetCreature(*me, instance->GetGuidData(ENTRY_WEEGLI)))
                                pWeegli->AI()->DoAction(0);
                            Talk(SAY_1);
                            Text_Timer = 5000;
                            break;
                        case 2:
                            Talk(SAY_2);
                            Text_Timer = 5000;
                            break;
                        case 3:
                            me->SetFaction(FACTION_MONSTER);
                            if (Player* target = ObjectAccessor::GetPlayer(*me, PlayerGUID))
                                AttackStart(target);

                            switchFactionIfAlive(ENTRY_RAVEN);
                            switchFactionIfAlive(ENTRY_ORO);
                            switchFactionIfAlive(ENTRY_MURTA);
                    }
                    postGossipStep++;
                }
                else Text_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (ShieldBash_Timer <= diff)
            {
                DoCastVictim(SPELL_SHIELD_BASH);
                ShieldBash_Timer = 15000;
            }
            else
                ShieldBash_Timer -= diff;

            if (Revenge_Timer <= diff)
            {
                DoCastVictim(SPELL_REVENGE);
                Revenge_Timer = 10000;
            }
            else
                Revenge_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        void DoAction(int32 /*param*/) override
        {
            postGossipStep=1;
            Text_Timer = 0;
        }

        void switchFactionIfAlive(uint32 entry)
        {
           if (Creature* crew = ObjectAccessor::GetCreature(*me, instance->GetGuidData(entry)))
               if (crew->IsAlive())
                   crew->SetFaction(FACTION_MONSTER);
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                PlayerGUID = player->GetGUID();
                DoAction(0);
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            if (instance->GetData(EVENT_PYRAMID) == PYRAMID_KILLED_ALL_TROLLS)
            {
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_BLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 1517, me->GetGUID());
            }
            else
                if (instance->GetData(EVENT_PYRAMID) == PYRAMID_NOT_STARTED)
                    SendGossipMenuFor(player, 1515, me->GetGUID());
                else
                    SendGossipMenuFor(player, 1516, me->GetGUID());
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetZulFarrakAI<npc_sergeant_blyAI>(creature);
    }
};

/*######
+## go_troll_cage
+######*/

class go_troll_cage : public GameObjectScript
{
public:
    go_troll_cage() : GameObjectScript("go_troll_cage") { }

    struct go_troll_cageAI : public GameObjectAI
    {
        go_troll_cageAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool GossipHello(Player* /*player*/) override
        {
            instance->SetData(EVENT_PYRAMID, PYRAMID_CAGES_OPEN);
            //set bly & co to aggressive & start moving to top of stairs
            initBlyCrewMember(ENTRY_BLY, 1884.99f, 1263, 41.52f);
            initBlyCrewMember(ENTRY_RAVEN, 1882.5f, 1263, 41.52f);
            initBlyCrewMember(ENTRY_ORO, 1886.47f, 1270.68f, 41.68f);
            initBlyCrewMember(ENTRY_WEEGLI, 1890, 1263, 41.52f);
            initBlyCrewMember(ENTRY_MURTA, 1891.19f, 1272.03f, 41.60f);
            return false;
        }

    private:
        void initBlyCrewMember(uint32 entry, float x, float y, float z)
        {
            if (Creature* crew = ObjectAccessor::GetCreature(*me, instance->GetGuidData(entry)))
            {
                crew->SetReactState(REACT_AGGRESSIVE);
                crew->SetWalk(true);
                crew->SetHomePosition(x, y, z, 0);
                crew->GetMotionMaster()->MovePoint(1, x, y, z);
                crew->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_ACTIVE);
            }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetZulFarrakAI<go_troll_cageAI>(go);
    }
};

/*######
## npc_weegli_blastfuse
######*/

enum weegliSpells
{
    SPELL_BOMB                  = 8858,
    SPELL_GOBLIN_LAND_MINE      = 21688,
    SPELL_SHOOT                 = 6660,
    SPELL_WEEGLIS_BARREL        = 10772
};

enum weegliSays
{
    SAY_WEEGLI_OHNO             = 0,
    SAY_WEEGLI_OK_I_GO          = 1
};

#define GOSSIP_WEEGLI               "Will you blow up that door now?"

class npc_weegli_blastfuse : public CreatureScript
{
public:
    npc_weegli_blastfuse() : CreatureScript("npc_weegli_blastfuse") { }

    struct npc_weegli_blastfuseAI : public ScriptedAI
    {
        npc_weegli_blastfuseAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            destroyingDoor = false;
            Bomb_Timer = 10000;
            LandMine_Timer = 30000;
        }

        uint32 Bomb_Timer;
        uint32 LandMine_Timer;
        bool destroyingDoor;
        InstanceScript* instance;

        void Reset() override
        {
            /*instance->SetData(0, NOT_STARTED);*/
        }

        void AttackStart(Unit* victim) override
        {
            AttackStartCaster(victim, 10);//keep back & toss bombs/shoot
        }

        void JustDied(Unit* /*killer*/) override
        {
            /*instance->SetData(0, DONE);*/
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Bomb_Timer < diff)
            {
                DoCastVictim(SPELL_BOMB);
                Bomb_Timer = 10000;
            }
            else
                Bomb_Timer -= diff;

            if (me->isAttackReady() && !me->IsWithinMeleeRange(me->GetVictim()))
            {
                DoCastVictim(SPELL_SHOOT);
                me->SetSheath(SHEATH_STATE_RANGED);
            }
            else
            {
                me->SetSheath(SHEATH_STATE_MELEE);
                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 /*type*/, uint32 /*id*/) override
        {
            if (instance->GetData(EVENT_PYRAMID) == PYRAMID_CAGES_OPEN)
            {
                instance->SetData(EVENT_PYRAMID, PYRAMID_ARRIVED_AT_STAIR);
                Talk(SAY_WEEGLI_OHNO);
                me->SetHomePosition(1882.69f, 1272.28f, 41.87f, 0);
            }
            else
                if (destroyingDoor)
                {
                    instance->DoUseDoorOrButton(instance->GetGuidData(GO_END_DOOR));
                    /// @todo leave the area...
                    me->DespawnOrUnsummon();
                };
        }

        void DestroyDoor()
        {
            if (me->IsAlive())
            {
                me->SetFaction(FACTION_FRIENDLY);
                me->GetMotionMaster()->MovePoint(0, 1858.57f, 1146.35f, 14.745f);
                me->SetHomePosition(1858.57f, 1146.35f, 14.745f, 3.85f); // in case he gets interrupted
                Talk(SAY_WEEGLI_OK_I_GO);
                destroyingDoor = true;
            }
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                CloseGossipMenuFor(player);
                //here we make him run to door, set the charge and run away off to nowhere
                DestroyDoor();
            }
            return true;
        }

        bool GossipHello(Player* player) override
        {
            switch (instance->GetData(EVENT_PYRAMID))
            {
                case PYRAMID_KILLED_ALL_TROLLS:
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_WEEGLI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(player, 1514, me->GetGUID());  //if event can proceed to end
                    break;
                case PYRAMID_NOT_STARTED:
                    SendGossipMenuFor(player, 1511, me->GetGUID());  //if event not started
                    break;
                default:
                    SendGossipMenuFor(player, 1513, me->GetGUID());  //if event are in progress
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetZulFarrakAI<npc_weegli_blastfuseAI>(creature);
    }
};

/*######
## go_shallow_grave
######*/

enum ShallowGrave
{
    NPC_ZOMBIE          = 7286,
    NPC_DEAD_HERO       = 7276,
    CHANCE_ZOMBIE       = 65,
    CHANCE_DEAD_HERO    = 10
};

class go_shallow_grave : public GameObjectScript
{
public:
    go_shallow_grave() : GameObjectScript("go_shallow_grave") { }

    struct go_shallow_graveAI : public GameObjectAI
    {
        go_shallow_graveAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* /*player*/) override
        {
            // randomly summon a zombie or dead hero the first time a grave is used
            if (me->GetUseCount() == 0)
            {
                uint32 randomchance = urand(0, 100);
                if (randomchance < CHANCE_ZOMBIE)
                    me->SummonCreature(NPC_ZOMBIE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                else
                    if ((randomchance - CHANCE_ZOMBIE) < CHANCE_DEAD_HERO)
                        me->SummonCreature(NPC_DEAD_HERO, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
            }
            me->AddUse();
            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetZulFarrakAI<go_shallow_graveAI>(go);
    }
};

/*######
## at_zumrah
######*/

enum zumrahConsts
{
    ZUMRAH_ID = 7271
};

class at_zumrah : public AreaTriggerScript
{
public:
    at_zumrah() : AreaTriggerScript("at_zumrah") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        Creature* pZumrah = player->FindNearestCreature(ZUMRAH_ID, 30.0f);

        if (!pZumrah)
            return false;

        pZumrah->SetFaction(FACTION_TROLL_FROSTMANE);
        return true;
    }

};

void AddSC_zulfarrak()
{
    new npc_sergeant_bly();
    new npc_weegli_blastfuse();
    new go_shallow_grave();
    new at_zumrah();
    new go_troll_cage();
}
