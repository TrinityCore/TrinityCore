/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "ulduar.h"

// npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems."
#define GOSSIP_ITEM_2  "Confirmed."


enum texts
{
    SAY_EVENT_1 = 0,
    SAY_EVENT_2 = 1,
    SAY_EVENT_3 = 2,
    SAY_EVENT_4 = 3,
    SAY_EVENT_5 = 4,
    SAY_EVENT_6 = 5,
    SAY_EVENT_7 = 6,
    SAY_EVENT_8 = 7,
    SAY_BRANN   = 8,
};

class npc_lorekeeper : public CreatureScript
{
    public:
        npc_lorekeeper() : CreatureScript("npc_lorekeeper") { }

        struct npc_lorekeeperAI : public ScriptedAI
        {
            npc_lorekeeperAI(Creature* creature) : ScriptedAI(creature)
            {
                Step = 0;
                event = false;
                greet=false;
            }
			
            void MoveInLineOfSight(Unit* who)
            {
                if (greet)
                    return;
			
                if (me->IsWithinDistInMap(who, 10.0f) && who->GetTypeId() == TYPEID_PLAYER)
                {
                    Step=1;
                    StepTimer = 100;
                    Event();
                    greet=true;
                }
            }
			
            void Event()
            {
                if(!Step)
                    return;

                if (event)
                    return;
					
                switch (Step)
                {
                    case 1:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_1);
                        JumpNextStep(10000);
                        break;
                    case 2:
                        Talk(SAY_EVENT_1);
                        JumpNextStep(10000);
                        break;
                    case 3:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_2);
                        JumpNextStep(10000);
                        break;
                    case 4:
                        Talk(SAY_EVENT_2);
                        JumpNextStep(10000);
                        break;
                    case 5:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_3);
                        JumpNextStep(10000);
                        break;
                    case 6:
                        Talk(SAY_EVENT_3);
                        JumpNextStep(10000);
                        break;
                    case 7:
                        Talk(SAY_EVENT_4);
                        JumpNextStep(10000);
                        break;
                    case 8:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_4);
                        JumpNextStep(10000);
                        break;
                    case 9:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_5);
                        JumpNextStep(10000);
                        break;
                    case 10:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_6);
                        JumpNextStep(10000);
                        break;
                    case 11:
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 150.0f))
                            Rhydian->AI()->Talk(SAY_EVENT_7);
                        JumpNextStep(10000);
                        break;
                    case 12:
                        Talk(SAY_EVENT_8);
                        JumpNextStep(10000);
                        break;
                    case 13:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_EVENT_8);
                        JumpNextStep(1000);
                        break;
                    case 14:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        event=true;
                        break;
                    default:
                        break;
                }
            }
			
            void JumpNextStep(uint32 Time)
            {
                StepTimer = Time;
                Step++;
            }
			
            void UpdateAI(uint32 const diff)
            {
                if(StepTimer < diff)
                   Event();
                else
                   StepTimer -= diff;
				
                return;
            }
			
        private:
            uint32 StepTimer;
            uint32 Step;
            bool event;
            bool greet;
		
        };

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    if (player)
                    {
                        player->PrepareGossipMenu(creature);
                        instance->instance->LoadGrid(364, -16); // make sure leviathan is loaded

                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->SEND_GOSSIP_MENU(32000, creature->GetGUID());
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    if (player)
                        player->SEND_GOSSIP_MENU(32001, creature->GetGUID());

                    if (Creature* leviathan = instance->instance->GetCreature(instance->GetData64(BOSS_LEVIATHAN)))
                    {
                        leviathan->AI()->DoAction(ACTION_ACTIVATE_HARD_MODE);

                        if (Creature* Delorah = creature->FindNearestCreature(NPC_DELORAH, 200.0f, true))
                        {
                            if (Creature* Brann = creature->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            {
                                Delorah->GetMotionMaster()->MovePoint(0, Brann->GetPositionX() - 4, Brann->GetPositionY(), Brann->GetPositionZ());
                                Delorah->AI()->Talk(SAY_BRANN);
                            }
                        }
                        creature->SetVisible(false);
                        if (Creature* KepperUnit = creature->FindNearestCreature(NPC_KEEPER_UNIT, 150.0f))
                            KepperUnit->SetVisible(false);
                    }
                    break;
            }

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (instance && instance->GetData(BOSS_LEVIATHAN) != DONE && player)
            {
                player->PrepareGossipMenu(creature);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            }
            return true;
        }
	
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lorekeeperAI(creature);
        }
};

////npc_brann_bronzebeard this requires more work involving area triggers. if reached this guy speaks through his radio..
//#define GOSSIP_ITEM_1  "xxxxx"
//#define GOSSIP_ITEM_2  "xxxxx"
//
/*
class npc_brann_bronzebeard : public CreatureScript
{
public:
    npc_brann_bronzebeard() : CreatureScript("npc_brann_bronzebeard") { }

    //bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
    //{
    //    pPlayer->PlayerTalkClass->ClearMenus();
    //    switch(uiAction)
    //    {
    //        case GOSSIP_ACTION_INFO_DEF+1:
    //            if (pPlayer)
    //            {
    //                pPlayer->PrepareGossipMenu(creature);
    //
    //                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    //                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
    //            }
    //            break;
    //        case GOSSIP_ACTION_INFO_DEF+2:
    //            if (pPlayer)
    //                pPlayer->CLOSE_GOSSIP_MENU();
    //            if (Creature* Lorekeeper = creature->FindNearestCreature(NPC_LOREKEEPER, 1000, true)) //lore keeper of lorgannon
    //                Lorekeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    //            break;
    //    }
    //    return true;
    //}
    //bool OnGossipHello(Player* pPlayer, Creature* creature)
    //{
    //    InstanceScript* instance = creature->GetInstanceScript();
    //    if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE)
    //    {
    //        pPlayer->PrepareGossipMenu(creature);
    //
    //        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    //        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
    //    }
    //    return true;
    //}
    //
}
*/

enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310,
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
};

class npc_ulduar_warmage : public CreatureScript
{
public:
    npc_ulduar_warmage() : CreatureScript("npc_ulduar_warmage") { }

    struct npc_ulduar_warmageAI : public Scripted_NoMovementAI
    {
        npc_ulduar_warmageAI(Creature* creature) : Scripted_NoMovementAI(creature){}

        uint64 uiTargetGUID;

        void Reset()
        {
            uiTargetGUID = 0;
        }

        void EnterCombat(Unit* /*who*/) {}

        void AttackStart(Unit* /*who*/) {}

        void UpdateAI(const uint32 uiDiff)
        {
            if (me->IsNonMeleeSpellCasted(false))
                return;

            if (me->GetEntry() == NPC_ULDUAR_WARMAGE)
            {
                if (!uiTargetGUID)
                {
                    std::list<Creature*> orbList;
                    GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f);
                    if (!orbList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                        {
                            if (Creature* pOrb = *itr)
                            {
                                if (pOrb->GetPositionY() < 1000)
                                {
                                    uiTargetGUID = pOrb->GetGUID();
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (!uiTargetGUID)
                    if (Creature* pOrb = GetClosestCreatureWithEntry(me, NPC_TRANSITUS_SHIELD_DUMMY, 32.0f))
                        uiTargetGUID = pOrb->GetGUID();
            }

            if (Creature* pOrb = me->GetCreature(*me, uiTargetGUID))
                DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ulduar_warmageAI(creature);
    }
};

class npc_gauntlet_generator : public CreatureScript
{
public:
    npc_gauntlet_generator() : CreatureScript("npc_gauntlet_generator") { }

    struct npc_gauntlet_generatorAI : public ScriptedAI
    {
        npc_gauntlet_generatorAI(Creature* creature) : ScriptedAI(creature)
        {
            Step = 0;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (me->IsWithinDistInMap(who, 100.0f) && who->GetTypeId() == TYPEID_PLAYER)
            {
                Step=1;
                StepTimer = 100;
                Event();
            }
        }

        void Event()        //summon 20 dwarfs each beacon
        {
            if (!Step)
                return;

            switch (Step)
            {
                case 1:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 2:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 3:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 4:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 5:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 6:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 7:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 8:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 9:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 10:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 11:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 12:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 13:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 14:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 15:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 16:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 17:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 18:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 19:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                case 20:
                    Spawn();
                    JumpNextStep(1000);
                    break;
                default:
                    break;
            }
        }

        void Spawn()
        {
            DoCast(me, 63135);
        }

        void JumpNextStep(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }
			
        void UpdateAI(uint32 const diff)
        {
            if(StepTimer < diff)
               Event();
            else
               StepTimer -= diff;
				
            return;
        }

    private:
        uint32 StepTimer;
        uint32 Step;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gauntlet_generatorAI(creature);
    }
};

void AddSC_ulduar()
{
    new npc_gauntlet_generator();
    new npc_lorekeeper();
    new npc_ulduar_warmage();
}