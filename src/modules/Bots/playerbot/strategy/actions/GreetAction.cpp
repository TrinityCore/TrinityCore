#include "botpch.h"
#include "../../playerbot.h"
#include "GreetAction.h"
#include "../../playerbotAI.h"
#include "../../PlayerbotAIConfig.h"
#include "../../ServerFacade.h"
using namespace ai;

GreetAction::GreetAction(PlayerbotAI* ai) : Action(ai, "greet")
{
}

bool GreetAction::Execute(Event event)
{
    ObjectGuid guid = AI_VALUE(ObjectGuid, "new player nearby");
    if (!guid || !guid.IsPlayer()) return false;

    Player* player = dynamic_cast<Player*>(ai->GetUnit(guid));
    if (!player) return false;

    if (!sServerFacade.IsInFront(bot, player, sPlayerbotAIConfig.sightDistance, CAST_ANGLE_IN_FRONT))
        sServerFacade.SetFacingTo(bot, player);

    ObjectGuid oldSel = bot->GetSelectionGuid();
    bot->SetSelectionGuid(guid);
    bot->HandleEmote(EMOTE_ONESHOT_WAVE);
    ai->PlaySound(TEXTEMOTE_HELLO);
    bot->SetSelectionGuid(oldSel);

    set<ObjectGuid>& alreadySeenPlayers = ai->GetAiObjectContext()->GetValue<set<ObjectGuid>& >("already seen players")->Get();
    alreadySeenPlayers.insert(guid);

    list<ObjectGuid> nearestPlayers = ai->GetAiObjectContext()->GetValue<list<ObjectGuid> >("nearest friendly players")->Get();
    for (list<ObjectGuid>::iterator i = nearestPlayers.begin(); i != nearestPlayers.end(); ++i) {
        alreadySeenPlayers.insert(*i);
    }
    return true;
}

ImbueWithPoisonAction::ImbueWithPoisonAction(PlayerbotAI* ai) : Action(ai, "apply poison")
{
}

bool ImbueWithPoisonAction::Execute(Event event)
   {
#ifdef CMANGOS
      if (bot->isInCombat())
#endif
#ifdef MANGOS
      if (bot->IsInCombat())
#endif
		  return false;

      // remove stealth
      if (bot->HasAura(SPELL_AURA_MOD_STEALTH))
         bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

      // hp check
      if (bot->getStandState() != UNIT_STAND_STATE_STAND)
         bot->SetStandState(UNIT_STAND_STATE_STAND);


      // Search and apply poison to weapons
      // Mainhand ...
      Item * poison, *weapon;
      weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
      if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
      {
         poison = ai->FindConsumable(INSTANT_POISON_DISPLAYID);
         if (!poison)
            poison = ai->FindConsumable(DEADLY_POISON_DISPLAYID);
         if (!poison)
            poison = ai->FindConsumable(WOUND_POISON_DISPLAYID);
         if (poison)
         {
            ai->ImbueItem(poison, EQUIPMENT_SLOT_MAINHAND);
            ai->SetNextCheckDelay(5);
         }
      }
      //... and offhand
      weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
      if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
      {
         poison = ai->FindConsumable(DEADLY_POISON_DISPLAYID);
         if (!poison)
            poison = ai->FindConsumable(WOUND_POISON_DISPLAYID);
         if (!poison)
            poison = ai->FindConsumable(INSTANT_POISON_DISPLAYID);
         if (poison)
         {
            ai->ImbueItem(poison, EQUIPMENT_SLOT_OFFHAND);
            ai->SetNextCheckDelay(5);
         }
      }

   }

// Search and apply stone to weapons
ImbueWithStoneAction::ImbueWithStoneAction(PlayerbotAI* ai) : Action(ai, "apply stone")
{
}

bool ImbueWithStoneAction::Execute(Event event)
{
#ifdef CMANGOS
   if (bot->isInCombat())
#endif
#ifdef MANGOS
   if (bot->IsInCombat())
#endif
      return false;

   // remove stealth
   if (bot->HasAura(SPELL_AURA_MOD_STEALTH))
      bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

   // hp check
   if (bot->getStandState() != UNIT_STAND_STATE_STAND)
      bot->SetStandState(UNIT_STAND_STATE_STAND);


   // Search and apply stone to weapons
   // Mainhand ...
   Item * stone, *weapon;
   weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
   if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
   {
      stone = ai->FindStoneFor(weapon);
      if (stone)
      {
         ai->ImbueItem(stone, EQUIPMENT_SLOT_MAINHAND);
         ai->SetNextCheckDelay(5);
      }
   }
   //... and offhand
   weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
   if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
   {
      stone = ai->FindStoneFor(weapon);
      if (stone)
      {
         ai->ImbueItem(stone, EQUIPMENT_SLOT_OFFHAND);
         ai->SetNextCheckDelay(5);
      }
   }

}

// Search and apply oil to weapons
ImbueWithOilAction::ImbueWithOilAction(PlayerbotAI* ai) : Action(ai, "apply oil")
{
}

bool ImbueWithOilAction::Execute(Event event)
{
#ifdef CMANGOS
   if (bot->isInCombat())
#endif
#ifdef MANGOS
   if (bot->IsInCombat())
#endif
      return false;

   // remove stealth
   if (bot->HasAura(SPELL_AURA_MOD_STEALTH))
      bot->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

   // hp check
   if (bot->getStandState() != UNIT_STAND_STATE_STAND)
      bot->SetStandState(UNIT_STAND_STATE_STAND);


   // Search and apply oil to weapons

   Item * oil, *weapon;
   weapon = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
   if (weapon && weapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT) == 0)
   {
      oil = ai->FindOilFor(weapon);
      if (oil)
      {
         ai->ImbueItem(oil, EQUIPMENT_SLOT_MAINHAND);
         ai->SetNextCheckDelay(5);
      }
   }
}

TryEmergencyAction::TryEmergencyAction(PlayerbotAI* ai) : Action(ai, "try emegency")
{
}

bool TryEmergencyAction::Execute(Event event)
{
   // Do not use consumable if bot can heal self
   if ((ai->IsHeal(bot)) && (ai->GetManaPercent() > 20))
      return false;

   // If bot does not have aggro: use bandage instead of potion/stone/crystal
   if ((!AI_VALUE(uint8, "my attacker count") >=1) && !bot->HasAura(11196)) // Recently bandaged
   {
      Item* bandage = ai->FindBandage();
      if (bandage)
      {
         ai->SetNextCheckDelay(8);
         ai->ImbueItem(bandage, bot);
      }
   }

   // Else loop over the list of health consumable to pick one
   Item* healthItem;
   for (uint8 i = 0; i < countof(uPriorizedHealingItemIds); ++i)
   {
      healthItem = ai->FindConsumable(uPriorizedHealingItemIds[i]);
      if (healthItem)
      {
         ai->ImbueItem(healthItem);
      }
   }
}
