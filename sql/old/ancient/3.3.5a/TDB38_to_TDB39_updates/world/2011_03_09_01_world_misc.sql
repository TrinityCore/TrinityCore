-- SrcItemCount is not a WDB field (0/1).
UPDATE `quest_template` SET `SrcItemCount` = 1 WHERE `SrcItemId` != 0 AND `SrcItemCount` = 0;

-- Missing items
DELETE FROM `item_template` WHERE `entry` IN (52274,52275,52276,52344,52562,52563,52565,52706,52707,52729,52835,53048,54516) AND `WDBVerified` < 0;
INSERT INTO `item_template` (`entry`,`class`,`subclass`,`unk0`,`name`,`displayid`,`Quality`,`Flags`,`FlagsExtra`,`BuyCount`,`BuyPrice`,`SellPrice`,`InventoryType`,`AllowableClass`,`AllowableRace`,`ItemLevel`,`RequiredLevel`,`RequiredSkill`,`RequiredSkillRank`,`requiredspell`,`requiredhonorrank`,`RequiredCityRank`,`RequiredReputationFaction`,`RequiredReputationRank`,`maxcount`,`stackable`,`ContainerSlots`,`StatsCount`,`stat_type1`,`stat_value1`,`stat_type2`,`stat_value2`,`stat_type3`,`stat_value3`,`stat_type4`,`stat_value4`,`stat_type5`,`stat_value5`,`stat_type6`,`stat_value6`,`stat_type7`,`stat_value7`,`stat_type8`,`stat_value8`,`stat_type9`,`stat_value9`,`stat_type10`,`stat_value10`,`ScalingStatDistribution`,`ScalingStatValue`,`dmg_min1`,`dmg_max1`,`dmg_type1`,`dmg_min2`,`dmg_max2`,`dmg_type2`,`armor`,`holy_res`,`fire_res`,`nature_res`,`frost_res`,`shadow_res`,`arcane_res`,`delay`,`ammo_type`,`RangedModRange`,`spellid_1`,`spelltrigger_1`,`spellcharges_1`,`spellppmRate_1`,`spellcooldown_1`,`spellcategory_1`,`spellcategorycooldown_1`,`spellid_2`,`spelltrigger_2`,`spellcharges_2`,`spellppmRate_2`,`spellcooldown_2`,`spellcategory_2`,`spellcategorycooldown_2`,`spellid_3`,`spelltrigger_3`,`spellcharges_3`,`spellppmRate_3`,`spellcooldown_3`,`spellcategory_3`,`spellcategorycooldown_3`,`spellid_4`,`spelltrigger_4`,`spellcharges_4`,`spellppmRate_4`,`spellcooldown_4`,`spellcategory_4`,`spellcategorycooldown_4`,`spellid_5`,`spelltrigger_5`,`spellcharges_5`,`spellppmRate_5`,`spellcooldown_5`,`spellcategory_5`,`spellcategorycooldown_5`,`bonding`,`description`,`PageText`,`LanguageID`,`PageMaterial`,`startquest`,`lockid`,`Material`,`sheath`,`RandomProperty`,`RandomSuffix`,`block`,`itemset`,`MaxDurability`,`area`,`Map`,`BagFamily`,`TotemCategory`,`socketColor_1`,`socketContent_1`,`socketColor_2`,`socketContent_2`,`socketColor_3`,`socketContent_3`,`socketBonus`,`GemProperties`,`RequiredDisenchantSkill`,`ArmorDamageModifier`,`Duration`,`ItemLimitCategory`,`HolidayId`,`ScriptName`,`DisenchantID`,`FoodType`,`minMoneyLoot`,`maxMoneyLoot`,`WDBVerified`) VALUES
(52274,15,0,-1,'Earthen Ring Supplies',21202,1,4,0,1,0,0,0,-1,-1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52275,12,0,-1,'Tablets of the Earth',11185,1,198656,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52276,12,0,-1,'Tablets of Fire',11185,1,133120,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52344,15,0,-1,'Earthen Ring Supplies',21202,1,4,0,1,0,0,0,-1,-1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52562,12,0,-1,'Elemental Fire for the Soul',34752,1,131072,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',3611,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52563,12,0,-1,'What Does ''The End of All Things'' Mean for Me?',34751,1,196608,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',3612,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52565,12,0,-1,'Finding Security and Comfort in a Doomed World',45202,1,131072,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',3613,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52706,12,0,-1,'Warning Poster',65893,1,64,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,74033,0,0,0,1500,0,-1,0,5,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52707,12,0,-1,'Warning Poster',65893,1,64,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,74098,0,0,0,1500,0,-1,0,5,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52729,4,1,-1,'Recruit''s Robe',65920,1,0,0,1,0,0,20,-1,-1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,74267,1,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,4,0,0,0,0,0,55,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(52835,12,0,-1,'Elemental Devices',23712,1,0,0,1,0,0,0,-1,-1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'Small, portable devices housing powerful elementals.',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(53048,4,0,-1,'Doomsday Message',34752,1,0,0,1,0,0,16,-1,-1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,74491,0,0,0,1500,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,4,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340),
(54516,15,0,-1,'Loot-Filled Pumpkin',67153,3,4,0,1,0,0,0,-1,-1,80,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,'',0,0,0,0,-12340);

-- Spells placeholders
DELETE FROM `spell_dbc` WHERE `Id` IN (38758,38788,46251,45140,45144,45148);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(38758, '[PH] Quest reward: Exorcising the Trees'),
(38788, '[PH] Quest reward: Spirit Calling'),
(46251, '[PH] Quest reward: Blood for Blood'),
(45140, '[PH] Quest reward: Making Ready / Don''t Stop Now....'),
(45144, '[PH] Quest reward: Disrupt the Greengill Coast'),
(45148, '[PH] Quest reward: Ata''mal Armaments');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=10850; -- Exorcising the Trees
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=10853; -- Spirit Calling
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11466; -- Jack Likes His Drink
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11515; -- Blood for Blood
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11535; -- Making Ready (available before phase 3b in Isle of Quel'danas)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11536; -- Don't Stop Now.... (available after phase 3b in Isle of Quel'danas)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11541; -- Disrupt the Greengill Coast (available after phase 4 in Isle of Quel'danas)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=11544; -- Ata'mal Armaments (available after phase 3b in Isle of Quel'danas)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=12616; -- Chamber of Secrets (world event: Scourge Invasion)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=12734; -- Rejek: First Blood
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=24869; -- Deprogramming (ICC)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=24879; -- Blood Quickening (ICC)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=24916; -- Jaina's Locket (ICC)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=24918; -- Sylvanas' Vengeance (ICC)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=24919; -- The Lightbringer's Redemption (ICC)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25055; -- Subduing the Elements (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25092; -- Subduing the Elements (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25180; -- Tablets of the Earth (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25181; -- Tablets of Fire (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25228; -- Prophecies Of Doom (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25253; -- Prophecies Of Doom (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25254; -- Signs Of The Times (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25282; -- Signs Of The Times (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25347; -- The Doomsday Plan (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25351; -- Alert Our Leaders (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25380; -- Spreading The Word (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25415; -- Spreading The Word (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25417; -- The Doomsday Plan (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25425; -- Warn King Wrynn (world event: Elemental Unrest)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25212; -- Vent Horizon (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25229; -- A Few Good Gnomes (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25283; -- Prepping the Speech (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25286; -- Words for Delivery (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25287; -- Words for Delivery (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25393; -- Operation: Gnomeregan (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25500; -- Words for Delivery (world event: Operation: Gnomeregan)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25444; -- Da Perfect Spies (world event: Zalazane's Fall)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25445; -- Zalazane's Fall (world event: Zalazane's Fall)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25446; -- Frogs Away! (world event: Zalazane's Fall)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25461; -- Trollin' For Volunteers (world event: Zalazane's Fall)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25480; -- Dance Of De Spirits (world event: Zalazane's Fall)
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25482; -- World Event Dungeon - Headless Horseman
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25483; -- World Event Dungeon - Coren Direbrew
-- DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=25485; -- World Event Dungeon - Hummel (missing item)
