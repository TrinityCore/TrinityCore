//#pragma once

//DESATIVADO#include "../Action.h"

//DESATIVADOnamespace ai
//DESATIVADO{
  //DESATIVADO  class InviteToGroupAction : public Action
 //DESATIVADO   {
 //DESATIVADO   public:
  //DESATIVADO      InviteToGroupAction(PlayerbotAI* ai) : Action(ai, "invite") {}

  //DESATIVADO      virtual bool Execute(Event event)
  //DESATIVADO      {
   //DESATIVADO         Player* master = event.getOwner();
   //DESATIVADO         if (!master)
   //DESATIVADO             return false;
//DESATIVADO
   //DESATIVADO         WorldPacket p;
//DESATIVADO            uint32 roles_mask = 0;
//DESATIVADO            p << master->GetName();
 //DESATIVADO           p << roles_mask;
//DESATIVADO            bot->GetSession()->HandleGroupInviteOpcode(p);
//DESATIVADO
  //DESATIVADO          return true;
 //DESATIVADO       }
//DESATIVADO    };
//DESATIVADO
//DESATIVADO}
