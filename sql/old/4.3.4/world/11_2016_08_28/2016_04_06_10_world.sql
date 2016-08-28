--
UPDATE `quest_template` SET `RewardCurrencyCount1`=6 WHERE `id`=12434;
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (938,1689,10101,10102,15000,17378,22906,24124,27826,28682);

DELETE FROM `item_template` WHERE `entry` IN (6295);
INSERT INTO `item_template` (entry, class, subclass, SoundOverrideSubclass, name, displayid, Quality, Flags, FlagsExtra, Unk430_1, Unk430_2, BuyCount, BuyPrice, SellPrice, InventoryType, AllowableClass, AllowableRace, ItemLevel, RequiredLevel, RequiredSkill, RequiredSkillRank, requiredspell, requiredhonorrank, RequiredCityRank, RequiredReputationFaction, RequiredReputationRank, maxcount, stackable, ContainerSlots, stat_type1, stat_value1, stat_unk1_1, stat_unk2_1, stat_type2, stat_value2, stat_unk1_2, stat_unk2_2, stat_type3, stat_value3, stat_unk1_3, stat_unk2_3, stat_type4, stat_value4, stat_unk1_4, stat_unk2_4, stat_type5, stat_value5, stat_unk1_5, stat_unk2_5, stat_type6, stat_value6, stat_unk1_6, stat_unk2_6, stat_type7, stat_value7, stat_unk1_7, stat_unk2_7, stat_type8, stat_value8, stat_unk1_8, stat_unk2_8, stat_type9, stat_value9, stat_unk1_9, stat_unk2_9, stat_type10, stat_value10, stat_unk1_10, stat_unk2_10, ScalingStatDistribution, DamageType, delay, RangedModRange, spellid_1, spelltrigger_1, spellcharges_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, PageText, LanguageID, PageMaterial, startquest, lockid, Material, sheath, RandomProperty, RandomSuffix, itemset, MaxDurability, area, Map, BagFamily, TotemCategory, socketColor_1, socketContent_1, socketColor_2, socketContent_2, socketColor_3, socketContent_3, socketBonus, GemProperties, ArmorDamageModifier, duration, ItemLimitCategory, HolidayId, StatScalingFactor, CurrencySubstitutionId, CurrencySubstitutionCount, flagsCustom, VerifiedBuild) VALUES
(6295, 15, 0, -1, "15 Pound Mud Snapper", 24701, 1, 0, 8192, 1.00677, 0.999808, 1, 48, 12, 23, -1, -1, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1000, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, "", 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15595);

DELETE FROM `reference_loot_template` WHERE `entry`=14012;
DELETE FROM `disenchant_loot_template` WHERE `entry`=67;
INSERT INTO `disenchant_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(67, 44012, 44012, 67, 0, 1, 1, 1, 1);
DELETE FROM `creature_loot_template` WHERE `reference`=43016;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(21558, 43016, 43016, 20, 0, 1, 3, 1, 1),
(21551, 43016, 43016, 20, 0, 1, 3, 1, 1),
(21582, 43016, 43016, 46, 0, 1, 3, 1, 1),
(21581, 43016, 43016, 20, 0, 1, 3, 1, 1),
(21559, 43016, 43016, 20, 0, 1, 3, 1, 1);
