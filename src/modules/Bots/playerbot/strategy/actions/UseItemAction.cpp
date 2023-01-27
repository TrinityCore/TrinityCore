#include "botpch.h"
#include "../../playerbot.h"
#include "UseItemAction.h"

#include "../../PlayerbotAIConfig.h"
#include "DBCStore.h"
#include "../../ServerFacade.h"
using namespace ai;

bool UseItemAction::Execute(Event event)
{
   string name = event.getParam();
   if (name.empty())
      name = getName();

   list<Item*> items = AI_VALUE2(list<Item*>, "inventory items", name);
   list<ObjectGuid> gos = chat->parseGameobjects(name);

   if (gos.empty())
   {
      if (items.size() > 1)
      {
         list<Item*>::iterator i = items.begin();
         Item* itemTarget = *i++;
         Item* item = *i;
         return UseItemOnItem(item, itemTarget);
      }
      else if (!items.empty())
         return UseItemAuto(*items.begin());
   }
   else
   {
      if (items.empty())
         return UseGameObject(*gos.begin());
      else
         return UseItemOnGameObject(*items.begin(), *gos.begin());
   }

   ai->TellMaster("No items (or game objects) available");
   return false;
}

bool UseItemAction::UseGameObject(ObjectGuid guid)
{
    GameObject* go = ai->GetGameObject(guid);
    if (!go || !sServerFacade.isSpawned(go)
#ifdef CMANGOS
        || go->IsInUse() 
#endif
        || go->GetGoState() != GO_STATE_READY)
        return false;

   go->Use(bot);
   ostringstream out; out << "Using " << chat->formatGameobject(go);
   ai->TellMasterNoFacing(out.str());
   return true;
}

bool UseItemAction::UseItemAuto(Item* item)
{
   return UseItem(item, ObjectGuid(), NULL);
}

bool UseItemAction::UseItemOnGameObject(Item* item, ObjectGuid go)
{
   return UseItem(item, go, NULL);
}

bool UseItemAction::UseItemOnItem(Item* item, Item* itemTarget)
{
   return UseItem(item, ObjectGuid(), itemTarget);
}

bool UseItemAction::UseItem(Item* item, ObjectGuid goGuid, Item* itemTarget)
{
   if (bot->CanUseItem(item) != EQUIP_ERR_OK)
      return false;

   if (bot->IsNonMeleeSpellCasted(true))
      return false;

   uint8 bagIndex = item->GetBagSlot();
   uint8 slot = item->GetSlot();
   uint8 spell_index = 0;
   uint8 cast_count = 1;
   uint64 item_guid = item->GetObjectGuid().GetRawValue();
   uint32 glyphIndex = 0;
   uint8 unk_flags = 0;
#ifdef MANGOSBOT_ZERO
   uint16 targetFlag = TARGET_FLAG_SELF;
#endif
#ifdef MANGOSBOT_ONE
   uint32 targetFlag = TARGET_FLAG_SELF;
#endif

   WorldPacket packet(CMSG_USE_ITEM);
   packet << bagIndex << slot << spell_index;
#ifdef MANGOSBOT_ONE
   packet << cast_count << item_guid;
#endif

   bool targetSelected = false;
   ostringstream out; out << "Using " << chat->formatItem(item->GetProto());
   if (item->GetProto()->Stackable)
   {
      uint32 count = item->GetCount();
      if (count > 1)
         out << " (" << count << " available) ";
      else
         out << " (the last one!)";
   }

   if (goGuid)
   {
      GameObject* go = ai->GetGameObject(goGuid);
      if (!go || !sServerFacade.isSpawned(go))
         return false;

      targetFlag = TARGET_FLAG_OBJECT;
      packet << targetFlag;
      packet.appendPackGUID(goGuid.GetRawValue());
      out << " on " << chat->formatGameobject(go);
      targetSelected = true;
   }

   if (itemTarget)
   {
#ifdef MANGOSBOT_ONE
      if (item->GetProto()->Class == ITEM_CLASS_GEM)
      {
         bool fit = SocketItem(itemTarget, item) || SocketItem(itemTarget, item, true);
         if (!fit)
            ai->TellMaster("Socket does not fit");
         return fit;
      }
      else
      {
#endif
      targetFlag = TARGET_FLAG_ITEM;
      packet << targetFlag;
      packet.appendPackGUID(itemTarget->GetObjectGuid());
      out << " on " << chat->formatItem(itemTarget->GetProto());
      targetSelected = true;
#ifdef MANGOSBOT_ONE
      }
#endif
   }

   Player* master = GetMaster();
   if (!targetSelected && item->GetProto()->Class != ITEM_CLASS_CONSUMABLE && master)
   {
      ObjectGuid masterSelection = master->GetSelectionGuid();
      if (masterSelection)
      {
         Unit* unit = ai->GetUnit(masterSelection);
         if (unit)
         {
            targetFlag = TARGET_FLAG_UNIT;
            packet << targetFlag << masterSelection.WriteAsPacked();
            out << " on " << unit->GetName();
            targetSelected = true;
         }
      }
   }

   if (uint32 questid = item->GetProto()->StartQuest)
   {
      Quest const* qInfo = sObjectMgr.GetQuestTemplate(questid);
      if (qInfo)
      {
         WorldPacket packet(CMSG_QUESTGIVER_ACCEPT_QUEST, 8 + 4 + 4);
         packet << item_guid;
         packet << questid;
         packet << uint32(0);
         bot->GetSession()->HandleQuestgiverAcceptQuestOpcode(packet);
         ostringstream out; out << "Got quest " << chat->formatQuest(qInfo);
         ai->TellMasterNoFacing(out.str());
         return true;
      }
   }

   MotionMaster &mm = *bot->GetMotionMaster();
   mm.Clear();
   bot->clearUnitState(UNIT_STAT_CHASE);
   bot->clearUnitState(UNIT_STAT_FOLLOW);

   if (sServerFacade.isMoving(bot))
      return false;

   for (int i = 0; i < MAX_ITEM_PROTO_SPELLS; i++)
   {
      uint32 spellId = item->GetProto()->Spells[i].SpellId;
      if (!spellId)
         continue;

      if (!ai->CanCastSpell(spellId, bot, false))
         continue;

      const SpellEntry* const pSpellInfo = sServerFacade.LookupSpellInfo(spellId);
      if (pSpellInfo->Targets & TARGET_FLAG_ITEM)
      {
         Item* itemForSpell = AI_VALUE2(Item*, "item for spell", spellId);
         if (!itemForSpell)
            continue;

         if (itemForSpell->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
            continue;

         if (bot->GetTrader())
         {
            if (selfOnly)
               return false;

            targetFlag = TARGET_FLAG_TRADE_ITEM;
            packet << targetFlag << (uint8)1 << (uint64)TRADE_SLOT_NONTRADED;
            targetSelected = true;
            out << " on traded item";
         }
         else
         {
            targetFlag = TARGET_FLAG_ITEM;
            packet << targetFlag;
            packet.appendPackGUID(itemForSpell->GetObjectGuid());
            targetSelected = true;
            out << " on " << chat->formatItem(itemForSpell->GetProto());
         }

         Spell *spell = new Spell(bot, pSpellInfo, false);
         ai->WaitForSpellCast(spell);
         delete spell;
      }
      break;
   }

   if (!targetSelected)
   {
      targetFlag = TARGET_FLAG_SELF;
      packet << targetFlag;
      packet.appendPackGUID(bot->GetObjectGuid());
      targetSelected = true;
      out << " on self";
   }

   ItemPrototype const* proto = item->GetProto();
   if (proto->Class == ITEM_CLASS_CONSUMABLE && (proto->SubClass == ITEM_SUBCLASS_FOOD || proto->SubClass == ITEM_SUBCLASS_CONSUMABLE) &&
      (proto->Spells[0].SpellCategory == 11 || proto->Spells[0].SpellCategory == 59))
   {
      if (sServerFacade.IsInCombat(bot))
         return false;

      bot->addUnitState(UNIT_STAND_STATE_SIT);
      ai->InterruptSpell();
      ai->SetNextCheckDelay(30000);
   }
   else
   {
      ai->SetNextCheckDelay(sPlayerbotAIConfig.globalCoolDown);
   }

   ai->TellMasterNoFacing(out.str());
   bot->GetSession()->HandleUseItemOpcode(packet);
   return true;
}

#ifdef MANGOSBOT_ONE
bool UseItemAction::SocketItem(Item* item, Item* gem, bool replace)
{
   WorldPacket* const packet = new WorldPacket(CMSG_SOCKET_GEMS);
   *packet << item->GetObjectGuid();

   bool fits = false;
   for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT + MAX_GEM_SOCKETS; ++enchant_slot)
   {
      uint8 SocketColor = item->GetProto()->Socket[enchant_slot - SOCK_ENCHANTMENT_SLOT].Color;
      GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gem->GetProto()->GemProperties);
      if (gemProperty && (gemProperty->color & SocketColor))
      {
         if (fits)
         {
            *packet << ObjectGuid();
            continue;
         }

         uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(enchant_slot));
         if (!enchant_id)
         {
            *packet << gem->GetObjectGuid();
            fits = true;
            continue;
         }

         SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
         if (!enchantEntry || !enchantEntry->GemID)
         {
            *packet << gem->GetObjectGuid();
            fits = true;
            continue;
         }

         if (replace && enchantEntry->GemID != gem->GetProto()->ItemId)
         {
            *packet << gem->GetObjectGuid();
            fits = true;
            continue;
         }

      }

      *packet << ObjectGuid();
   }

   if (fits)
   {
      ostringstream out; out << "Socketing " << chat->formatItem(item->GetProto());
      out << " with " << chat->formatItem(gem->GetProto());
      ai->TellMaster(out);

      bot->GetSession()->HandleSocketOpcode(*packet);
   }
   return fits;
}
#endif

bool UseItemAction::isPossible()
{
   return getName() == "use" || AI_VALUE2(uint8, "item count", getName()) > 0;
}

bool UseSpellItemAction::isUseful()
{
   return AI_VALUE2(bool, "spell cast useful", getName());
}