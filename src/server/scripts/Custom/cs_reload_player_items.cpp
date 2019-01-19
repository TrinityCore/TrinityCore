#include "Chat.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "DisableMgr.h"
#include "DatabaseWorker.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ItemTemplate.h"
#include "World.h"
#include "Totem.h"
#include "DBCStores.h"
#include "SpellMgr.h"
#include "RBAC.h"
#include "WorldSession.h"
#include "Bag.h"

// Sending cache data for reloaded items
static const void SendCachePackets(Player* player, ItemTemplate* proto)
{
	if (!player || !proto)
		return;

	std::string Name = proto->Name1;
	std::string Description = proto->Description;

	LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();

	if (loc_idx >= 0)
	{
		if (ItemLocale const* il = sObjectMgr->GetItemLocale(proto->ItemId))
		{
			ObjectMgr::GetLocaleString(il->Name, loc_idx, Name);
			ObjectMgr::GetLocaleString(il->Description, loc_idx, Description);
		}
	}
	WorldPacket data(SMSG_ITEM_QUERY_SINGLE_RESPONSE, 600);
	data << proto->ItemId;
	data << proto->Class;
	data << proto->SubClass;
	data << int32(proto->SoundOverrideSubclass);
	data << Name;
	data << uint8(0x00);
	data << uint8(0x00);
	data << uint8(0x00);
	data << proto->DisplayInfoID;
	data << proto->Quality;
	data << proto->Flags;
	data << proto->Flags2;
	data << proto->BuyPrice;
	data << proto->SellPrice;
	data << proto->InventoryType;
	data << proto->AllowableClass;
	data << proto->AllowableRace;
	data << proto->ItemLevel;
	data << proto->RequiredLevel;
	data << proto->RequiredSkill;
	data << proto->RequiredSkillRank;
	data << proto->RequiredSpell;
	data << proto->RequiredHonorRank;
	data << proto->RequiredCityRank;
	data << proto->RequiredReputationFaction;
	data << proto->RequiredReputationRank;
	data << int32(proto->MaxCount);
	data << int32(proto->Stackable);
	data << proto->ContainerSlots;
	data << proto->StatsCount;
	for (uint32 i = 0; i < proto->StatsCount; ++i)
	{
		data << proto->ItemStat[i].ItemStatType;
		data << proto->ItemStat[i].ItemStatValue;
	}
	data << proto->ScalingStatDistribution;
	data << proto->ScalingStatValue;
	for (int i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
	{
		data << proto->Damage[i].DamageMin;
		data << proto->Damage[i].DamageMax;
		data << proto->Damage[i].DamageType;
	}
	data << proto->Armor;
	data << proto->HolyRes;
	data << proto->FireRes;
	data << proto->NatureRes;
	data << proto->FrostRes;
	data << proto->ShadowRes;
	data << proto->ArcaneRes;
	data << proto->Delay;
	data << proto->AmmoType;
	data << proto->RangedModRange;
	for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
	{
		SpellInfo const* spell = sSpellMgr->GetSpellInfo(proto->Spells[s].SpellId);
		if (spell)
		{
			bool db_data = proto->Spells[s].SpellCooldown >= 0 || proto->Spells[s].SpellCategoryCooldown >= 0;
			data << proto->Spells[s].SpellId;
			data << proto->Spells[s].SpellTrigger;
			data << uint32(-abs(proto->Spells[s].SpellCharges));
			if (db_data)
			{
				data << uint32(proto->Spells[s].SpellCooldown);
				data << uint32(proto->Spells[s].SpellCategory);
				data << uint32(proto->Spells[s].SpellCategoryCooldown);
			}
			else
			{
				data << uint32(spell->RecoveryTime);
				data << uint32(spell->GetCategory());
				data << uint32(spell->CategoryRecoveryTime);
			}
		}
		else
		{
			data << uint32(0);
			data << uint32(0);
			data << uint32(0);
			data << uint32(-1);
			data << uint32(0);
			data << uint32(-1);
		}
	}
	data << proto->Bonding;
	data << Description;
	data << proto->PageText;
	data << proto->LanguageID;
	data << proto->PageMaterial;
	data << proto->StartQuest;
	data << proto->LockID;
	data << int32(proto->Material);
	data << proto->Sheath;
	data << proto->RandomProperty;
	data << proto->RandomSuffix;
	data << proto->Block;
	data << proto->ItemSet;
	data << proto->MaxDurability;
	data << proto->Area;
	data << proto->Map;
	data << proto->BagFamily;
	data << proto->TotemCategory;
	for (int s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
	{
		data << proto->Socket[s].Color;
		data << proto->Socket[s].Content;
	}
	data << proto->socketBonus;
	data << proto->GemProperties;
	data << proto->RequiredDisenchantSkill;
	data << proto->ArmorDamageModifier;
	data << proto->Duration;
	data << proto->ItemLimitCategory;
	data << proto->HolidayId;

	player->GetSession()->SendPacket(&data);

	if (Item* item = player->GetItemByEntry(proto->ItemId))
		player->_ApplyItemMods(item, item->GetSlot(), true);
}

// Loading data from the database and inserting it into the ItemTemplate map
void BetterLoadItem(Player* player, std::vector<uint32> itemID)
{
	if (!player)
		return;

	std::stringstream ss;
	for (uint32 i = 0; i < itemID.size(); i++)
		ss << itemID[i] << ", ";
	std::string str = ss.str();
	str.erase(str.length()-2, 2);

	uint32 oldMSTime = getMSTime();

	//                                                 0      1       2               3              4        5        6       7          8         9        10        11           12
	QueryResult result = WorldDatabase.PQuery("SELECT entry, class, subclass, SoundOverrideSubclass, name, displayid, Quality, Flags, FlagsExtra, BuyCount, BuyPrice, SellPrice, InventoryType, "
		//                                              13              14           15          16             17               18                19              20
		"AllowableClass, AllowableRace, ItemLevel, RequiredLevel, RequiredSkill, RequiredSkillRank, requiredspell, requiredhonorrank, "
		//                                              21                      22                       23               24        25          26             27           28
		"RequiredCityRank, RequiredReputationFaction, RequiredReputationRank, maxcount, stackable, ContainerSlots, StatsCount, stat_type1, "
		//                                            29           30          31           32          33           34          35           36          37           38
		"stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, "
		//                                            39           40          41           42           43          44           45           46           47
		"stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, "
		//                                                   48                    49           50        51        52         53        54         55      56      57        58
		"ScalingStatDistribution, ScalingStatValue, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, armor, holy_res, fire_res, "
		//                                            59          60         61          62       63       64            65            66          67               68
		"nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, RangedModRange, spellid_1, spelltrigger_1, spellcharges_1, "
		//                                              69              70                71                 72                 73           74               75
		"spellppmRate_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, "
		//                                              76               77              78                  79                 80           81               82
		"spellppmRate_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, "
		//                                              83               84              85                  86                 87           88               89
		"spellppmRate_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, "
		//                                              90               91              92                  93                  94          95               96
		"spellppmRate_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, "
		//                                              97               98              99                  100                 101        102         103       104          105
		"spellppmRate_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, PageText, LanguageID, PageMaterial, "
		//                                            106       107     108      109          110            111       112     113         114       115   116     117
		"startquest, lockid, Material, sheath, RandomProperty, RandomSuffix, block, itemset, MaxDurability, area, Map, BagFamily, "
		//                                            118             119             120             121             122            123              124            125
		"TotemCategory, socketColor_1, socketContent_1, socketColor_2, socketContent_2, socketColor_3, socketContent_3, socketBonus, "
		//                                            126                 127                     128            129            130            131         132         133
		"GemProperties, RequiredDisenchantSkill, ArmorDamageModifier, duration, ItemLimitCategory, HolidayId, ScriptName, DisenchantID, "
		//                                           134        135            136
		"FoodType, minMoneyLoot, maxMoneyLoot, flagsCustom FROM item_template WHERE entry in (%s)", str);

	if (!result)
	{
		TC_LOG_INFO("server.loading", ">> Loaded 0 item templates. DB table `item_template` is empty.");
		return;
	}

	bool enforceDBCAttributes = sWorld->getBoolConfig(CONFIG_DBC_ENFORCE_ITEM_ATTRIBUTES);

	do
	{
		Field* fields = result->Fetch();

		uint32 entry = fields[0].GetUInt32();

		if (sObjectMgr->GetItemTemplateStore().find(entry) == sObjectMgr->GetItemTemplateStore().end())
		{
			ChatHandler(player->GetSession()).PSendSysMessage("Item not in Item Template store, please use the .reload item_template command first, or restart your server");
			return;
		}

		ItemTemplate* itemTemplate = const_cast<ItemTemplate*>(&sObjectMgr->GetItemTemplateStore().at(entry));

		itemTemplate->ItemId = entry;
		itemTemplate->Class = uint32(fields[1].GetUInt8());
		itemTemplate->SubClass = uint32(fields[2].GetUInt8());
		itemTemplate->SoundOverrideSubclass = int32(fields[3].GetInt8());
		itemTemplate->Name1 = fields[4].GetString();
		itemTemplate->DisplayInfoID = fields[5].GetUInt32();
		itemTemplate->Quality = uint32(fields[6].GetUInt8());
		itemTemplate->Flags = fields[7].GetUInt32();
		itemTemplate->Flags2 = fields[8].GetUInt32();
		itemTemplate->BuyCount = uint32(fields[9].GetUInt8());
		itemTemplate->BuyPrice = int32(fields[10].GetInt64());
		itemTemplate->SellPrice = fields[11].GetUInt32();
		itemTemplate->InventoryType = uint32(fields[12].GetUInt8());
		itemTemplate->AllowableClass = fields[13].GetInt32();
		itemTemplate->AllowableRace = fields[14].GetInt32();
		itemTemplate->ItemLevel = uint32(fields[15].GetUInt16());
		itemTemplate->RequiredLevel = uint32(fields[16].GetUInt8());
		itemTemplate->RequiredSkill = uint32(fields[17].GetUInt16());
		itemTemplate->RequiredSkillRank = uint32(fields[18].GetUInt16());
		itemTemplate->RequiredSpell = fields[19].GetUInt32();
		itemTemplate->RequiredHonorRank = fields[20].GetUInt32();
		itemTemplate->RequiredCityRank = fields[21].GetUInt32();
		itemTemplate->RequiredReputationFaction = uint32(fields[22].GetUInt16());
		itemTemplate->RequiredReputationRank = uint32(fields[23].GetUInt16());
		itemTemplate->MaxCount = fields[24].GetInt32();
		itemTemplate->Stackable = fields[25].GetInt32();
		itemTemplate->ContainerSlots = uint32(fields[26].GetUInt8());
		itemTemplate->StatsCount = uint32(fields[27].GetUInt8());

		if (itemTemplate->StatsCount > MAX_ITEM_PROTO_STATS)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has too large value in statscount (%u), replace by hardcoded limit (%u).", entry, itemTemplate->StatsCount, MAX_ITEM_PROTO_STATS);
			itemTemplate->StatsCount = MAX_ITEM_PROTO_STATS;
		}

		for (uint8 i = 0; i < itemTemplate->StatsCount; ++i)
		{
			itemTemplate->ItemStat[i].ItemStatType = uint32(fields[28 + i * 2].GetUInt8());
			itemTemplate->ItemStat[i].ItemStatValue = int32(fields[29 + i * 2].GetInt32());
		}

		itemTemplate->ScalingStatDistribution = uint32(fields[48].GetUInt16());
		itemTemplate->ScalingStatValue = fields[49].GetInt32();

		for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
		{
			itemTemplate->Damage[i].DamageMin = fields[50 + i * 3].GetFloat();
			itemTemplate->Damage[i].DamageMax = fields[51 + i * 3].GetFloat();
			itemTemplate->Damage[i].DamageType = uint32(fields[52 + i * 3].GetUInt8());
		}

		itemTemplate->Armor = uint32(fields[56].GetUInt16());
		itemTemplate->HolyRes = uint32(fields[57].GetUInt8());
		itemTemplate->FireRes = uint32(fields[58].GetUInt8());
		itemTemplate->NatureRes = uint32(fields[59].GetUInt8());
		itemTemplate->FrostRes = uint32(fields[60].GetUInt8());
		itemTemplate->ShadowRes = uint32(fields[61].GetUInt8());
		itemTemplate->ArcaneRes = uint32(fields[62].GetUInt8());
		itemTemplate->Delay = uint32(fields[63].GetUInt16());
		itemTemplate->AmmoType = uint32(fields[64].GetUInt8());
		itemTemplate->RangedModRange = fields[65].GetFloat();

		for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
		{
			itemTemplate->Spells[i].SpellId = fields[66 + i * 7].GetInt32();
			itemTemplate->Spells[i].SpellTrigger = uint32(fields[67 + i * 7].GetUInt8());
			itemTemplate->Spells[i].SpellCharges = int32(fields[68 + i * 7].GetInt16());
			itemTemplate->Spells[i].SpellPPMRate = fields[69 + i * 7].GetFloat();
			itemTemplate->Spells[i].SpellCooldown = fields[70 + i * 7].GetInt32();
			itemTemplate->Spells[i].SpellCategory = uint32(fields[71 + i * 7].GetUInt16());
			itemTemplate->Spells[i].SpellCategoryCooldown = fields[72 + i * 7].GetInt32();
		}

		itemTemplate->Bonding = uint32(fields[101].GetUInt8());
		itemTemplate->Description = fields[102].GetString();
		itemTemplate->PageText = fields[103].GetUInt32();
		itemTemplate->LanguageID = uint32(fields[104].GetUInt8());
		itemTemplate->PageMaterial = uint32(fields[105].GetUInt8());
		itemTemplate->StartQuest = fields[106].GetUInt32();
		itemTemplate->LockID = fields[107].GetUInt32();
		itemTemplate->Material = int32(fields[108].GetInt8());
		itemTemplate->Sheath = uint32(fields[109].GetUInt8());
		itemTemplate->RandomProperty = fields[110].GetUInt32();
		itemTemplate->RandomSuffix = fields[111].GetInt32();
		itemTemplate->Block = fields[112].GetUInt32();
		itemTemplate->ItemSet = fields[113].GetUInt32();
		itemTemplate->MaxDurability = uint32(fields[114].GetUInt16());
		itemTemplate->Area = fields[115].GetUInt32();
		itemTemplate->Map = uint32(fields[116].GetUInt16());
		itemTemplate->BagFamily = fields[117].GetUInt32();
		itemTemplate->TotemCategory = fields[118].GetUInt32();

		for (uint8 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
		{
			itemTemplate->Socket[i].Color = uint32(fields[119 + i * 2].GetUInt8());
			itemTemplate->Socket[i].Content = fields[120 + i * 2].GetUInt32();
		}

		itemTemplate->socketBonus = fields[125].GetUInt32();
		itemTemplate->GemProperties = fields[126].GetUInt32();
		itemTemplate->RequiredDisenchantSkill = uint32(fields[127].GetInt16());
		itemTemplate->ArmorDamageModifier = fields[128].GetFloat();
		itemTemplate->Duration = fields[129].GetUInt32();
		itemTemplate->ItemLimitCategory = uint32(fields[130].GetInt16());
		itemTemplate->HolidayId = fields[131].GetUInt32();
		itemTemplate->ScriptId = sObjectMgr->GetScriptId(fields[132].GetString());
		itemTemplate->DisenchantID = fields[133].GetUInt32();
		itemTemplate->FoodType = uint32(fields[134].GetUInt8());
		itemTemplate->MinMoneyLoot = fields[135].GetUInt32();
		itemTemplate->MaxMoneyLoot = fields[136].GetUInt32();
		itemTemplate->FlagsCu = fields[137].GetUInt32();

		// Checks

		ItemEntry const* dbcitem = sItemStore.LookupEntry(entry);

		if (dbcitem)
		{
			if (itemTemplate->Class != dbcitem->Class)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct class %u, must be %u .", entry, itemTemplate->Class, dbcitem->Class);
				if (enforceDBCAttributes)
					itemTemplate->Class = dbcitem->Class;
			}

			if (itemTemplate->SoundOverrideSubclass != dbcitem->SoundOverrideSubclass)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct SoundOverrideSubclass (%i), must be %i .", entry, itemTemplate->SoundOverrideSubclass, dbcitem->SoundOverrideSubclass);
				if (enforceDBCAttributes)
					itemTemplate->SoundOverrideSubclass = dbcitem->SoundOverrideSubclass;
			}
			if (itemTemplate->Material != dbcitem->Material)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct material (%i), must be %i .", entry, itemTemplate->Material, dbcitem->Material);
				if (enforceDBCAttributes)
					itemTemplate->Material = dbcitem->Material;
			}
			if (itemTemplate->InventoryType != dbcitem->InventoryType)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct inventory type (%u), must be %u .", entry, itemTemplate->InventoryType, dbcitem->InventoryType);
				if (enforceDBCAttributes)
					itemTemplate->InventoryType = dbcitem->InventoryType;
			}
			if (itemTemplate->DisplayInfoID != dbcitem->DisplayId)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct display id (%u), must be %u .", entry, itemTemplate->DisplayInfoID, dbcitem->DisplayId);
				if (enforceDBCAttributes)
					itemTemplate->DisplayInfoID = dbcitem->DisplayId;
			}
			if (itemTemplate->Sheath != dbcitem->Sheath)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have a correct sheathid (%u), must be %u .", entry, itemTemplate->Sheath, dbcitem->Sheath);
				if (enforceDBCAttributes)
					itemTemplate->Sheath = dbcitem->Sheath;
			}

		}
		else
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not exist in item.dbc! (not correct id?).", entry);

		if (itemTemplate->Class >= MAX_ITEM_CLASS)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Class value (%u)", entry, itemTemplate->Class);
			itemTemplate->Class = ITEM_CLASS_MISC;
		}

		if (itemTemplate->SubClass >= MaxItemSubclassValues[itemTemplate->Class])
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Subclass value (%u) for class %u", entry, itemTemplate->SubClass, itemTemplate->Class);
			itemTemplate->SubClass = 0;// exist for all item classes
		}

		if (itemTemplate->Quality >= MAX_ITEM_QUALITY)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Quality value (%u)", entry, itemTemplate->Quality);
			itemTemplate->Quality = ITEM_QUALITY_NORMAL;
		}

		if (itemTemplate->Flags2 & ITEM_FLAG2_FACTION_HORDE)
		{
			if (FactionEntry const* faction = sFactionStore.LookupEntry(HORDE))
				if ((itemTemplate->AllowableRace & faction->BaseRepRaceMask[0]) == 0)
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has value (%u) in `AllowableRace` races, not compatible with ITEM_FLAG2_FACTION_HORDE (%u) in Flags field, item cannot be equipped or used by these races.",
						entry, itemTemplate->AllowableRace, ITEM_FLAG2_FACTION_HORDE);

			if (itemTemplate->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE)
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has value (%u) in `Flags2` flags (ITEM_FLAG2_FACTION_ALLIANCE) and ITEM_FLAG2_FACTION_HORDE (%u) in Flags field, this is a wrong combination.",
					entry, ITEM_FLAG2_FACTION_ALLIANCE, ITEM_FLAG2_FACTION_HORDE);
		}
		else if (itemTemplate->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE)
		{
			if (FactionEntry const* faction = sFactionStore.LookupEntry(ALLIANCE))
				if ((itemTemplate->AllowableRace & faction->BaseRepRaceMask[0]) == 0)
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has value (%u) in `AllowableRace` races, not compatible with ITEM_FLAG2_FACTION_ALLIANCE (%u) in Flags field, item cannot be equipped or used by these races.",
						entry, itemTemplate->AllowableRace, ITEM_FLAG2_FACTION_ALLIANCE);
		}

		if (itemTemplate->BuyCount <= 0)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong BuyCount value (%u), set to default(1).", entry, itemTemplate->BuyCount);
			itemTemplate->BuyCount = 1;
		}

		if (itemTemplate->InventoryType >= MAX_INVTYPE)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong InventoryType value (%u)", entry, itemTemplate->InventoryType);
			itemTemplate->InventoryType = INVTYPE_NON_EQUIP;
		}

		if (itemTemplate->RequiredSkill >= MAX_SKILL_TYPE)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong RequiredSkill value (%u)", entry, itemTemplate->RequiredSkill);
			itemTemplate->RequiredSkill = 0;
		}

		{
			// can be used in equip slot, as page read use in inventory, or spell casting at use
			bool req = itemTemplate->InventoryType != INVTYPE_NON_EQUIP || itemTemplate->PageText;
			if (!req)
				for (uint8 j = 0; j < MAX_ITEM_PROTO_SPELLS; ++j)
				{
					if (itemTemplate->Spells[j].SpellId > 0)
					{
						req = true;
						break;
					}
				}

			if (req)
			{
				if (!(itemTemplate->AllowableClass & CLASSMASK_ALL_PLAYABLE))
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have any playable classes (%u) in `AllowableClass` and can't be equipped or used.", entry, itemTemplate->AllowableClass);

				if (!(itemTemplate->AllowableRace & RACEMASK_ALL_PLAYABLE))
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have any playable races (%u) in `AllowableRace` and can't be equipped or used.", entry, itemTemplate->AllowableRace);
			}
		}

		if (itemTemplate->RequiredSpell && !sSpellMgr->GetSpellInfo(itemTemplate->RequiredSpell))
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has a wrong (non-existing) spell in RequiredSpell (%u)", entry, itemTemplate->RequiredSpell);
			itemTemplate->RequiredSpell = 0;
		}

		if (itemTemplate->RequiredReputationRank >= MAX_REPUTATION_RANK)
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong reputation rank in RequiredReputationRank (%u), item can't be used.", entry, itemTemplate->RequiredReputationRank);

		if (itemTemplate->RequiredReputationFaction)
		{
			if (!sFactionStore.LookupEntry(itemTemplate->RequiredReputationFaction))
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong (not existing) faction in RequiredReputationFaction (%u)", entry, itemTemplate->RequiredReputationFaction);
				itemTemplate->RequiredReputationFaction = 0;
			}

			if (itemTemplate->RequiredReputationRank == MIN_REPUTATION_RANK)
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has min. reputation rank in RequiredReputationRank (0) but RequiredReputationFaction > 0, faction setting is useless.", entry);
		}

		if (itemTemplate->MaxCount < -1)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has too large negative in maxcount (%i), replace by value (-1) no storing limits.", entry, itemTemplate->MaxCount);
			itemTemplate->MaxCount = -1;
		}

		if (itemTemplate->Stackable == 0)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong value in stackable (%i), replace by default 1.", entry, itemTemplate->Stackable);
			itemTemplate->Stackable = 1;
		}
		else if (itemTemplate->Stackable < -1)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has too large negative in stackable (%i), replace by value (-1) no stacking limits.", entry, itemTemplate->Stackable);
			itemTemplate->Stackable = -1;
		}

		if (itemTemplate->ContainerSlots > MAX_BAG_SIZE)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has too large value in ContainerSlots (%u), replace by hardcoded limit (%u).", entry, itemTemplate->ContainerSlots, MAX_BAG_SIZE);
			itemTemplate->ContainerSlots = MAX_BAG_SIZE;
		}

		for (uint8 j = 0; j < itemTemplate->StatsCount; ++j)
		{
			// for ItemStatValue != 0
			if (itemTemplate->ItemStat[j].ItemStatValue && itemTemplate->ItemStat[j].ItemStatType >= MAX_ITEM_MOD)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong (non-existing?) stat_type%d (%u)", entry, j + 1, itemTemplate->ItemStat[j].ItemStatType);
				itemTemplate->ItemStat[j].ItemStatType = 0;
			}

			switch (itemTemplate->ItemStat[j].ItemStatType)
			{
			case ITEM_MOD_SPELL_HEALING_DONE:
			case ITEM_MOD_SPELL_DAMAGE_DONE:
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has deprecated stat_type%d (%u)", entry, j + 1, itemTemplate->ItemStat[j].ItemStatType);
				break;
			default:
				break;
			}
		}

		for (uint8 j = 0; j < MAX_ITEM_PROTO_DAMAGES; ++j)
		{
			if (itemTemplate->Damage[j].DamageType >= MAX_SPELL_SCHOOL)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong dmg_type%d (%u)", entry, j + 1, itemTemplate->Damage[j].DamageType);
				itemTemplate->Damage[j].DamageType = 0;
			}
		}

		// special format
		if ((itemTemplate->Spells[0].SpellId == 483) || (itemTemplate->Spells[0].SpellId == 55884))
		{
			// spell_1
			if (itemTemplate->Spells[0].SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong item spell trigger value in spelltrigger_%d (%u) for special learning format", entry, 0 + 1, itemTemplate->Spells[0].SpellTrigger);
				itemTemplate->Spells[0].SpellId = 0;
				itemTemplate->Spells[0].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
				itemTemplate->Spells[1].SpellId = 0;
				itemTemplate->Spells[1].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
			}

			// spell_2 have learning spell
			if (itemTemplate->Spells[1].SpellTrigger != ITEM_SPELLTRIGGER_LEARN_SPELL_ID)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong item spell trigger value in spelltrigger_%d (%u) for special learning format.", entry, 1 + 1, itemTemplate->Spells[1].SpellTrigger);
				itemTemplate->Spells[0].SpellId = 0;
				itemTemplate->Spells[1].SpellId = 0;
				itemTemplate->Spells[1].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
			}
			else if (!itemTemplate->Spells[1].SpellId)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not have an expected spell in spellid_%d in special learning format.", entry, 1 + 1);
				itemTemplate->Spells[0].SpellId = 0;
				itemTemplate->Spells[1].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
			}
			else if (itemTemplate->Spells[1].SpellId != -1)
			{
				SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemTemplate->Spells[1].SpellId);
				if (!spellInfo && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, itemTemplate->Spells[1].SpellId, nullptr))
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong (not existing) spell in spellid_%d (%d)", entry, 1 + 1, itemTemplate->Spells[1].SpellId);
					itemTemplate->Spells[0].SpellId = 0;
					itemTemplate->Spells[1].SpellId = 0;
					itemTemplate->Spells[1].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
				}
				// allowed only in special format
				else if ((itemTemplate->Spells[1].SpellId == 483) || (itemTemplate->Spells[1].SpellId == 55884))
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has broken spell in spellid_%d (%d)", entry, 1 + 1, itemTemplate->Spells[1].SpellId);
					itemTemplate->Spells[0].SpellId = 0;
					itemTemplate->Spells[1].SpellId = 0;
					itemTemplate->Spells[1].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
				}
			}

			// spell_3*, spell_4*, spell_5* is empty
			for (uint8 j = 2; j < MAX_ITEM_PROTO_SPELLS; ++j)
			{
				if (itemTemplate->Spells[j].SpellTrigger != ITEM_SPELLTRIGGER_ON_USE)
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong item spell trigger value in spelltrigger_%d (%u)", entry, j + 1, itemTemplate->Spells[j].SpellTrigger);
					itemTemplate->Spells[j].SpellId = 0;
					itemTemplate->Spells[j].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
				}
				else if (itemTemplate->Spells[j].SpellId != 0)
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong spell in spellid_%d (%d) for learning special format", entry, j + 1, itemTemplate->Spells[j].SpellId);
					itemTemplate->Spells[j].SpellId = 0;
				}
			}
		}
		// normal spell list
		else
		{
			for (uint8 j = 0; j < MAX_ITEM_PROTO_SPELLS; ++j)
			{
				if (itemTemplate->Spells[j].SpellTrigger >= MAX_ITEM_SPELLTRIGGER || itemTemplate->Spells[j].SpellTrigger == ITEM_SPELLTRIGGER_LEARN_SPELL_ID)
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong item spell trigger value in spelltrigger_%d (%u)", entry, j + 1, itemTemplate->Spells[j].SpellTrigger);
					itemTemplate->Spells[j].SpellId = 0;
					itemTemplate->Spells[j].SpellTrigger = ITEM_SPELLTRIGGER_ON_USE;
				}

				if (itemTemplate->Spells[j].SpellId && itemTemplate->Spells[j].SpellId != -1)
				{
					SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemTemplate->Spells[j].SpellId);
					if (!spellInfo && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, itemTemplate->Spells[j].SpellId, nullptr))
					{
						TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong (not existing) spell in spellid_%d (%d)", entry, j + 1, itemTemplate->Spells[j].SpellId);
						itemTemplate->Spells[j].SpellId = 0;
					}
					// allowed only in special format
					else if ((itemTemplate->Spells[j].SpellId == 483) || (itemTemplate->Spells[j].SpellId == 55884))
					{
						TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has broken spell in spellid_%d (%d)", entry, j + 1, itemTemplate->Spells[j].SpellId);
						itemTemplate->Spells[j].SpellId = 0;
					}
				}
			}
		}

		if (itemTemplate->Bonding >= MAX_BIND_TYPE)
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Bonding value (%u)", entry, itemTemplate->Bonding);

		if (itemTemplate->PageText && !sObjectMgr->GetPageText(itemTemplate->PageText))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has non existing first page (Id:%u)", entry, itemTemplate->PageText);

		if (itemTemplate->LockID && !sLockStore.LookupEntry(itemTemplate->LockID))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong LockID (%u)", entry, itemTemplate->LockID);

		if (itemTemplate->Sheath >= MAX_SHEATHETYPE)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Sheath (%u)", entry, itemTemplate->Sheath);
			itemTemplate->Sheath = SHEATHETYPE_NONE;
		}

		if (itemTemplate->RandomProperty)
		{
			// To be implemented later
			if (itemTemplate->RandomProperty == -1)
				itemTemplate->RandomProperty = 0;

			else if (!sItemRandomPropertiesStore.LookupEntry(GetItemEnchantMod(itemTemplate->RandomProperty)))
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has unknown (wrong or not listed in `item_enchantment_template`) RandomProperty (%u)", entry, itemTemplate->RandomProperty);
				itemTemplate->RandomProperty = 0;
			}
		}

		if (itemTemplate->RandomSuffix && !sItemRandomSuffixStore.LookupEntry(GetItemEnchantMod(itemTemplate->RandomSuffix)))
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong RandomSuffix (%u)", entry, itemTemplate->RandomSuffix);
			itemTemplate->RandomSuffix = 0;
		}

		if (itemTemplate->ItemSet && !sItemSetStore.LookupEntry(itemTemplate->ItemSet))
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) have wrong ItemSet (%u)", entry, itemTemplate->ItemSet);
			itemTemplate->ItemSet = 0;
		}

		if (itemTemplate->Area && !sAreaTableStore.LookupEntry(itemTemplate->Area))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Area (%u)", entry, itemTemplate->Area);

		if (itemTemplate->Map && !sMapStore.LookupEntry(itemTemplate->Map))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong Map (%u)", entry, itemTemplate->Map);

		if (itemTemplate->BagFamily)
		{
			// check bits
			for (uint32 j = 0; j < sizeof(itemTemplate->BagFamily) * 8; ++j)
			{
				uint32 mask = 1 << j;
				if ((itemTemplate->BagFamily & mask) == 0)
					continue;

				ItemBagFamilyEntry const* bf = sItemBagFamilyStore.LookupEntry(j + 1);
				if (!bf)
				{
					TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has bag family bit set not listed in ItemBagFamily.dbc, remove bit", entry);
					itemTemplate->BagFamily &= ~mask;
					continue;
				}

				if (BAG_FAMILY_MASK_CURRENCY_TOKENS & mask)
				{
					CurrencyTypesEntry const* ctEntry = sCurrencyTypesStore.LookupEntry(itemTemplate->ItemId);
					if (!ctEntry)
					{
						TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has currency bag family bit set in BagFamily but not listed in CurrencyTypes.dbc, remove bit", entry);
						itemTemplate->BagFamily &= ~mask;
					}
				}
			}
		}

		if (itemTemplate->TotemCategory && !sTotemCategoryStore.LookupEntry(itemTemplate->TotemCategory))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong TotemCategory (%u)", entry, itemTemplate->TotemCategory);

		for (uint8 j = 0; j < MAX_ITEM_PROTO_SOCKETS; ++j)
		{
			if (itemTemplate->Socket[j].Color && (itemTemplate->Socket[j].Color & SOCKET_COLOR_ALL) != itemTemplate->Socket[j].Color)
			{
				TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong socketColor_%d (%u)", entry, j + 1, itemTemplate->Socket[j].Color);
				itemTemplate->Socket[j].Color = 0;
			}
		}

		if (itemTemplate->GemProperties && !sGemPropertiesStore.LookupEntry(itemTemplate->GemProperties))
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong GemProperties (%u)", entry, itemTemplate->GemProperties);

		if (itemTemplate->FoodType >= MAX_PET_DIET)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong FoodType value (%u)", entry, itemTemplate->FoodType);
			itemTemplate->FoodType = 0;
		}

		if (itemTemplate->ItemLimitCategory && !sItemLimitCategoryStore.LookupEntry(itemTemplate->ItemLimitCategory))
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong LimitCategory value (%u)", entry, itemTemplate->ItemLimitCategory);
			itemTemplate->ItemLimitCategory = 0;
		}

		if (itemTemplate->HolidayId && !sHolidaysStore.LookupEntry(itemTemplate->HolidayId))
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry: %u) has wrong HolidayId value (%u)", entry, itemTemplate->HolidayId);
			itemTemplate->HolidayId = 0;
		}

		if (itemTemplate->FlagsCu & ITEM_FLAGS_CU_DURATION_REAL_TIME && !itemTemplate->Duration)
		{
			TC_LOG_ERROR("sql.sql", "Item (Entry %u) has flag ITEM_FLAGS_CU_DURATION_REAL_TIME but it does not have duration limit", entry);
			itemTemplate->FlagsCu &= ~ITEM_FLAGS_CU_DURATION_REAL_TIME;
		}

		SendCachePackets(player, itemTemplate);

	} while (result->NextRow());

	// Check if item templates for DBC referenced character start outfit are present
	std::set<uint32> notFoundOutfit;
	for (uint32 i = 1; i < sCharStartOutfitStore.GetNumRows(); ++i)
	{
		CharStartOutfitEntry const* entry = sCharStartOutfitStore.LookupEntry(i);
		if (!entry)
			continue;

		for (uint8 j = 0; j < MAX_OUTFIT_ITEMS; ++j)
		{
			if (entry->ItemId[j] <= 0)
				continue;

			uint32 item_id = entry->ItemId[j];

			if (!sObjectMgr->GetItemTemplate(item_id))
				notFoundOutfit.insert(item_id);
		}
	}
	for (std::set<uint32>::const_iterator itr = notFoundOutfit.begin(); itr != notFoundOutfit.end(); ++itr)
		TC_LOG_ERROR("sql.sql", "Item (Entry: %u) does not exist in `item_template` but is referenced in `CharStartOutfit.dbc`", *itr);
}


// Comand stuff
class reload_player_items_command : public CommandScript
{
public:
	reload_player_items_command() : CommandScript("reload_player_items_command") { }

	std::vector<ChatCommand> GetCommands() const
	{
		static std::vector<ChatCommand> customCommandTable =
		{
			{ "reload player items",    		rbac::RBAC_PERM_COMMAND_RELOAD_PLAYER_ITEMS, 			true,	&HandleBetterItemReload,			"" },
		};
		return customCommandTable;
	}

	static bool HandleBetterItemReload(ChatHandler * handler, const char * args)
	{
		if (!*args)
			return false;

		std::vector<uint32> ids;
		Player* player = handler->GetSession()->GetPlayer();
		Tokenizer entries(std::string(args), ' ');
		for (Tokenizer::const_iterator it = entries.begin(); it != entries.end(); ++it)
		{
			uint32 itemID = uint32(atoi(*it));

			if (player)
				if (Item* item = player->GetItemByEntry(itemID))
					player->_ApplyItemMods(item, item->GetSlot(), false);

			ids.push_back(itemID);
		}
		BetterLoadItem(player, ids);
		handler->SendGlobalGMSysMessage("Better Reloading System Used.");

		return true;
	}
};


void AddSC_reload_player_items_command()
{
	new reload_player_items_command();
}