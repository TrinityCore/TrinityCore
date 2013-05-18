#include "ScriptPCH.h"

class npc_change : public CreatureScript
{
    public:
        npc_change() : CreatureScript("npc_change") { }

	       bool OnGossipHello(Player *player, Creature *_creature)
             {
		      if (player->isInCombat())
                    {		
                       			_creature->MonsterWhisper("You are in Combat", player->GetGUID());
						player->CLOSE_GOSSIP_MENU();
						return true;
                    }
                    else
                    { 
						 player->ADD_GOSSIP_ITEM( 0, "25 BOJ -> Reset Instance"                                     , GOSSIP_SENDER_MAIN, 1);
						 player->ADD_GOSSIP_ITEM( 0, "25 BOJ -> 30 Arena Pointu"                                    , GOSSIP_SENDER_MAIN, 2);
						 player->ADD_GOSSIP_ITEM( 0, "100 BOJ -> 10x Emblem of Frost"                               , GOSSIP_SENDER_MAIN, 3);
						 player->ADD_GOSSIP_ITEM( 0, "100 BOJ -> 20x Emblem of Triumph"                             , GOSSIP_SENDER_MAIN, 4);
						 player->ADD_GOSSIP_ITEM( 0, "26000 Honor Pointu -> 20 BOJ"                                 , GOSSIP_SENDER_MAIN, 5);
		      }	


						 player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
						 return true;
               }

                bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
                {

                    if (sender != GOSSIP_SENDER_MAIN)
						return true;

                         player->PlayerTalkClass->ClearMenus();

                      switch(uiAction)
                         {

                         case 1:
								if (player->HasItemCount(29434, 25, true)){
								
								player->DestroyItemCount(29434, 25, true);
								player->UnbindInstance(player->GetMapId(), player->GetDifficulty(true), true);

									_creature->MonsterWhisper("Unbind all Instances complete!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{
									_creature->MonsterWhisper("You need more Badge of Justice", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();
								}
                          break;

						 
                         case 2:
								if (player->HasItemCount(29434, 25, true)){

									player->DestroyItemCount(29434, 25, true);								
									player->ModifyArenaPoints(+30);
									_creature->MonsterWhisper("Change Succesful!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{
									_creature->MonsterWhisper("You need more Badge of Justice!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();									
								}
                          break;


                         case 3:
								if (player->HasItemCount(29434, 100, true)){

									player->DestroyItemCount(29434, 100, true);								
									player->AddItem(49426, 10);
									_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{									
									_creature->MonsterWhisper("You need more Badge of Justice!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();
								}
                          break;

                         case 4:
								if (player->HasItemCount(29434, 100, true)){

									player->DestroyItemCount(29434, 100, true);								
									player->AddItem(47241, 20);
									_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{									
									_creature->MonsterWhisper("You need more Badge of Justice!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();
								}
                          break;

                         case 5:
								if(player->GetHonorPoints() >= 26000){

									player->ModifyHonorPoints(-26000);							
									player->AddItem(29434, 20);
									_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{
									_creature->MonsterWhisper("You need more Honor!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}
                          break;


                         case 6:
								if (player->HasItemCount(100005, 10, true)){

									player->DestroyItemCount(100005, 10, true);					
									player->AddItem(29434, 1000);
									_creature->MonsterWhisper("Výmìna dokonèená!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();

								}else{
									_creature->MonsterWhisper("Nemáš dostateèný poèet Planyx Tokenù na výmìnu!", player->GetGUID());
									player->CLOSE_GOSSIP_MENU();
								}
                          break;




                         default:
                                 break;
                         }
             
                  return true;
          }
};

void AddSC_npc_change()
{
    new npc_change();
}
