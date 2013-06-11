/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "zulfarrak.h"
#include "Player.h"

/*######
## npc_sergeant_bly
######*/

enum blyAndCrewFactions
{
    FACTION_HOSTILE           = 14,
    FACTION_FRIENDLY          = 35,  //while in cages (so the trolls won't attack them while they're caged)
    FACTION_FREED             = 250  //after release (so they'll be hostile towards trolls)
};

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

#define GOSSIP_BLY                  "[PH] In that case, I will take my reward!"

class npc_sergeant_bly : public CreatureScript
{
public:
    npc_sergeant_bly() : CreatureScript("npc_sergeant_bly") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_sergeant_bly::npc_sergeant_blyAI, creature->AI())->PlayerGUID = player->GetGUID();
            creature->AI()->DoAction(0);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (InstanceScript* instance = creature->GetInstanceScript())
        {
            if (instance->GetData(EVENT_PYRAMID) == PYRAMID_KILLED_ALL_TROLLS)
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->SEND_GOSSIP_MENU(1517, creature->GetGUID());
            }
            else
                if (instance->GetData(EVENT_PYRAMID) == PYRAMID_NOT_STARTED)
                    player->SEND_GOSSIP_MENU(1515, creature->GetGUID());
                else
                    player->SEND_GOSSIP_MENU(1516, creature->GetGUID());
            return true;
        }
        return false;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sergeant_blyAI (creature);
    }

    struct npc_sergeant_blyAI : public ScriptedAI
    {
        npc_sergeant_blyAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            postGossipStep = 0;
        }

        InstanceScript* instance;

        uint32 postGossipStep;
        uint32 Text_Timer;
        uint32 ShieldBash_Timer;
        uint32 Revenge_Timer;                                   //this is wrong, spell should never be used unless me->GetVictim() dodge, parry or block attack. Trinity support required.
        uint64 PlayerGUID;

        void Reset()
        {
            ShieldBash_Timer = 5000;
            Revenge_Timer = 8000;

            me->setFaction(FACTION_FRIENDLY);
        }

        void UpdateAI(uint32 diff)
        {
            if (postGossipStep>0 && postGossipStep<4)
            {
                if (Text_Timer<diff)
                {
                    switch (postGossipStep)
                    {
                        case 1:
                            //weegli doesn't fight - he goes & blows up the door
                            if (Creature* pWeegli = instance->instance->GetCreature(instance->GetData64(ENTRY_WEEGLI)))
                                pWeegli->AI()->DoAction(0);
                            Talk(SAY_1);
                            Text_Timer = 5000;
                            break;
                        case 2:
                            Talk(SAY_2);
                            Text_Timer = 5000;
                            break;
                        case 3:
                            me->setFaction(FACTION_HOSTILE);
                            if (Player* target = Player::GetPlayer(*me, PlayerGUID))
                                AttackStart(target);

                            if (instance)
                            {
                                switchFactionIfAlive(instance, ENTRY_RAVEN);
                                switchFactionIfAlive(instance, ENTRY_ORO);
                                switchFactionIfAlive(instance, ENTRY_MURTA);
                            }
                    }
                    postGossipStep++;
                }
                else Text_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (ShieldBash_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_SHIELD_BASH);
                ShieldBash_Timer = 15000;
            }
            else
                ShieldBash_Timer -= diff;

            if (Revenge_Timer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_REVENGE);
                Revenge_Timer = 10000;
            }
            else
                Revenge_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        void DoAction(int32 /*param*/)
        {
            postGossipStep=1;
            Text_Timer = 0;
        }

        void switchFactionIfAlive(InstanceScript* instance, uint32 entry)
        {
           if (Creature* crew = instance->instance->GetCreature(instance->GetData64(entry)))
               if (crew->IsAlive())
                   crew->setFaction(FACTION_HOSTILE);
        }
    };

};

/*######
+## go_troll_cage
+######*/

class go_troll_cage : public GameObjectScript
{
public:
    go_troll_cage() : GameObjectScript("go_troll_cage") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (InstanceScript* instance = go->GetInstanceScript())
        {
            instance->SetData(EVENT_PYRAMID, PYRAMID_CAGES_OPEN);
            //set bly & co to aggressive & start moving to top of stairs
            initBlyCrewMember(instance, ENTRY_BLY, 1884.99f, 1263, 41.52f);
            initBlyCrewMember(instance, ENTRY_RAVEN, 1882.5f, 1263, 41.52f);
            initBlyCrewMember(instance, ENTRY_ORO, 1886.47f, 1270.68f, 41.68f);
            initBlyCrewMember(instance, ENTRY_WEEGLI, 1890, 1263, 41.52f);
            initBlyCrewMember(instance, ENTRY_MURTA, 1891.19f, 1272.03f, 41.60f);
        }
        return false;
    }

private:
    void initBlyCrewMember(InstanceScript* instance, uint32 entry, float x, float y, float z)
    {
        if (Creature* crew = instance->instance->GetCreature(instance->GetData64(entry)))
        {
            crew->SetReactState(REACT_AGGRESSIVE);
            crew->SetWalk(true);
            crew->SetHomePosition(x, y, z, 0);
            crew->GetMotionMaster()->MovePoint(1, x, y, z);
            crew->setFaction(FACTION_FREED);
        }
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

#define GOSSIP_WEEGLI               "[PH] Please blow up the door."

class npc_weegli_blastfuse : public CreatureScript
{
public:
    npc_weegli_blastfuse() : CreatureScript("npc_weegli_blastfuse") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            //here we make him run to door, set the charge and run away off to nowhere
            creature->AI()->DoAction(0);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (InstanceScript* instance = creature->GetInstanceScript())
        {
            switch (instance->GetData(EVENT_PYRAMID))
            {
                case PYRAMID_KILLED_ALL_TROLLS:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_WEEGLI, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    player->SEND_GOSSIP_MENU(1514, creature->GetGUID());  //if event can proceed to end
                    break;
                case PYRAMID_NOT_STARTED:
                    player->SEND_GOSSIP_MENU(1511, creature->GetGUID());  //if event not started
                    break;
                default:
                    player->SEND_GOSSIP_MENU(1513, creature->GetGUID());  //if event are in progress
            }
            return true;
        }
        return false;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_weegli_blastfuseAI (creature);
    }

    struct npc_weegli_blastfuseAI : public ScriptedAI
    {
        npc_weegli_blastfuseAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            destroyingDoor=false;
            Bomb_Timer = 10000;
            LandMine_Timer = 30000;
        }

        uint32 Bomb_Timer;
        uint32 LandMine_Timer;
        bool destroyingDoor;
        InstanceScript* instance;

        void Reset()
        {
            /*if (instance)
                instance->SetData(0, NOT_STARTED);*/
        }

        void AttackStart(Unit* victim)
        {
            AttackStartCaster(victim, 10);//keep back & toss bombs/shoot
        }

        void JustDied(Unit* /*killer*/)
        {
            /*if (instance)
                instance->SetData(0, DONE);*/
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Bomb_Timer < diff)
            {
                DoCast(me->GetVictim(), SPELL_BOMB);
                Bomb_Timer = 10000;
            }
            else
                Bomb_Timer -= diff;

            if (me->isAttackReady() && !me->IsWithinMeleeRange(me->GetVictim()))
            {
                DoCast(me->GetVictim(), SPELL_SHOOT);
                me->SetSheath(SHEATH_STATE_RANGED);
            }
            else
            {
                me->SetSheath(SHEATH_STATE_MELEE);
                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 /*type*/, uint32 /*id*/)
        {
            if (instance)
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
                        instance->DoUseDoorOrButton(instance->GetData64(GO_END_DOOR));
                        /// @todo leave the area...
                        me->DespawnOrUnsummon();
                    };
            }
        }

        void DoAction(int32 /*param*/)
        {
            DestroyDoor();
        }

        void DestroyDoor()
        {
            if (me->IsAlive())
            {
                me->setFaction(FACTION_FRIENDLY);
                me->GetMotionMaster()->MovePoint(0, 1858.57f, 1146.35f, 14.745f);
                me->SetHomePosition(1858.57f, 1146.35f, 14.745f, 3.85f); // in case he gets interrupted
                Talk(SAY_WEEGLI_OK_I_GO);
                destroyingDoor=true;
            }
        }
    };

};

/*######
## go_shallow_grave
######*/

enum
{
    ZOMBIE           = 7286,
    DEAD_HERO        = 7276,
    ZOMBIE_CHANCE    = 65,
    DEAD_HERO_CHANCE = 10
};

class go_shallow_grave : public GameObjectScript
{
public:
    go_shallow_grave() : GameObjectScript("go_shallow_grave") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        // randomly summon a zombie or dead hero the first time a grave is used
        if (go->GetUseCount() == 0)
        {
            uint32 randomchance = urand(0, 100);
            if (randomchance < ZOMBIE_CHANCE)
                go->SummonCreature(ZOMBIE, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
            else
                if ((randomchance - ZOMBIE_CHANCE) < DEAD_HERO_CHANCE)
                    go->SummonCreature(DEAD_HERO, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
        }
        go->AddUse();
        return false;
    }
};

/*######
## at_zumrah
######*/

enum zumrahConsts
{
    ZUMRAH_ID = 7271,
    ZUMRAH_HOSTILE_FACTION = 37
};

class at_zumrah : public AreaTriggerScript
{
public:
    at_zumrah() : AreaTriggerScript("at_zumrah") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
    {
        Creature* pZumrah = player->FindNearestCreature(ZUMRAH_ID, 30.0f);

        if (!pZumrah)
            return false;

        pZumrah->setFaction(ZUMRAH_HOSTILE_FACTION);
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
