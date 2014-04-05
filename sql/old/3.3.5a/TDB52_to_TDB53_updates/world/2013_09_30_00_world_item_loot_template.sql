SET @Reference := 10036;  -- Needs 26 reference loot template entries
DELETE FROM `item_loot_template` WHERE `entry` BETWEEN 51999 AND 52005;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Satchel of Helpfull Goods (level 0-25)
(51999,1,100,1,1,-@Reference,1),  -- Cloth
(51999,2,100,1,2,-@Reference-1,1),  -- Leather
(51999,3,100,1,3,-@Reference-2,1),  -- Mail
-- Satchel of Helpfull Goods (level 26-35)
(52000,1,100,1,1,-@Reference-3,1),  -- Cloth
(52000,2,100,1,2,-@Reference-4,1),  -- Leather
(52000,3,100,1,3,-@Reference-5,1),  -- Mail
-- Satchel of Helpfull Goods (level 36-45)
(52001,1,100,1,1,-@Reference-6,1),  -- Cloth
(52001,2,100,1,2,-@Reference-7,1),  -- Leather
(52001,3,100,1,3,-@Reference-8,1),  -- Mail
(52001,4,100,1,4,-@Reference-9,1),  -- Plate
-- Satchel of Helpfull Goods (level 46-55)
(52002,1,100,1,1,-@Reference-10,1), -- Cloth
(52002,2,100,1,2,-@Reference-11,1), -- Leather
(52002,3,100,1,3,-@Reference-12,1), -- Mail
(52002,4,100,1,4,-@Reference-13,1), -- Plate
-- Satchel of Helpfull Goods (level 56-60)
(52003,1,100,1,1,-@Reference-14,1), -- Cloth
(52003,2,100,1,2,-@Reference-15,1), -- leather
(52003,3,100,1,3,-@Reference-16,1), -- Mail
(52003,4,100,1,4,-@Reference-17,1), -- Plate
-- Satchel of Helpfull Goods (level 61-64)
(52004,1,100,1,1,-@Reference-18,1), -- Cloth
(52004,2,100,1,2,-@Reference-19,1), -- leather
(52004,3,100,1,3,-@Reference-20,1), -- mail
(52004,4,100,1,4,-@Reference-21,1), -- plate
-- Satchel of Helpfull Goods (level 65-70)
(52005,1,100,1,1,-@Reference-22,1),  -- Cloth
(52005,2,100,1,2,-@Reference-23,1),  -- leather
(52005,3,100,1,3,-@Reference-24,1),  -- mail
(52005,4,100,1,4,-@Reference-25,1);  -- plate
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @Reference AND @Reference+25;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Satchel of Helpfull Goods (level 0-25)
(@Reference,51968,0,1,1,1,1), -- Enumerated Wrap
(@Reference,51994,0,1,1,1,1), -- Tumultuous Cloak
(@Reference+1,51964,0,1,2,1,1), -- Vigorous Belt
(@Reference+1,51994,0,1,2,1,1), -- Tumultuous Cloak
(@Reference+2,51978,0,1,3,1,1), -- Earthbound Girdle
(@Reference+2,51994,0,1,3,1,1), -- Tumultuous Cloak
-- Satchel of Helpfull Goods (level 26-35)
(@Reference+3,51973,0,1,1,1,1), -- Enumerated Handwraps
(@Reference+3,51996,0,1,1,1,1), -- Tumultuous Necklace
(@Reference+4,51965,0,1,2,1,1), -- Vigorous Handguards
(@Reference+4,51996,0,1,2,1,1), -- Tumultuous Necklace
(@Reference+5,51980,0,1,3,1,1), -- Earthbound Handgrips
(@Reference+5,51996,0,1,3,1,1), -- Tumultuous Necklace
-- Satchel of Helpfull Goods (level 36-45)
(@Reference+6,51974,0,1,1,1,1), -- Enumerated Shoulderpads
(@Reference+6,51992,0,1,1,1,1), -- Tumultuous Ring
(@Reference+7,51966,0,1,2,1,1), -- Vigorous Spaulders
(@Reference+7,51992,0,1,2,1,1), -- Tumultuous Ring
(@Reference+8,51976,0,1,3,1,1), -- Earthbound Shoulderguards
(@Reference+8,51992,0,1,3,1,1), -- Tumultuous Ring
(@Reference+9,51984,0,1,4,1,1), -- Stalwart Shoulderpads
(@Reference+9,51992,0,1,4,1,1), -- Tumultuous Ring
-- Satchel of Helpfull Goods (level 46-55)
(@Reference+10,51967,0,1,1,1,1), -- Enumerated Sandals
(@Reference+10,51972,0,1,1,1,1), -- Enumerated Bracers
(@Reference+11,51962,0,1,2,1,1), -- Vigorous Bracers
(@Reference+11,51963,0,1,2,1,1), -- Vigorous Stompers
(@Reference+12,51981,0,1,3,1,1), -- Earthbound Wristguards
(@Reference+12,51982,0,1,3,1,1), -- Earthbound Boots
(@Reference+13,51989,0,1,4,1,1), -- Stalwart Bands
(@Reference+13,51990,0,1,4,1,1), -- Stalwart Treads
-- Satchel of Helpfull Goods (level 56-60)
(@Reference+14,51971,0,1,1,1,1), -- Enumerated Belt
(@Reference+14,51993,0,1,1,1,1), -- Turbulent Cloak
(@Reference+15,51959,0,1,2,1,1), -- Vigorous Belt
(@Reference+15,51993,0,1,2,1,1), -- Turbulent Cloak
(@Reference+16,51977,0,1,3,1,1), -- Earthbound Girdle
(@Reference+16,51993,0,1,3,1,1), -- Turbulent Cloak
(@Reference+17,51985,0,1,4,1,1), -- Stalwart Belt
(@Reference+17,51993,0,1,4,1,1), -- Turbulent Cloak
-- Satchel of Helpfull Goods (level 61-64)
(@Reference+18,51970,0,1,1,1,1), -- Enumerated Gloves
(@Reference+18,51995,0,1,1,1,1), -- Turbulent Necklace
(@Reference+19,51960,0,1,2,1,1), -- Vigorous Gloves
(@Reference+19,51995,0,1,2,1,1), -- Turbulent Necklace
(@Reference+20,51979,0,1,3,1,1), -- Earthbound Grips
(@Reference+20,51995,0,1,3,1,1), -- Turbulent Necklace
(@Reference+21,51987,0,1,4,1,1), -- Stalwart Grips
(@Reference+21,51995,0,1,4,1,1), -- Turbulent Necklace
-- Satchel of Helpfull Goods (level 65-70)
(@Reference+22,51961,0,1,1,1,1), -- Vigorous Shoulderguards
(@Reference+22,51991,0,1,1,1,1), -- Turbulent Signet
(@Reference+23,51969,0,1,2,1,1), -- Enumerated Shoulders
(@Reference+23,51991,0,1,2,1,1), -- Turbulent Signet
(@Reference+24,51975,0,1,3,1,1), -- Earthbound Shoulders
(@Reference+24,51991,0,1,3,1,1), -- Turbulent Signet
(@Reference+25,51983,0,1,4,1,1), -- Stalwart Shoulderguards
(@Reference+25,51991,0,1,4,1,1); -- Turbulent Signet

-- -------------------------------------------------------------------
-- Set some Parameters
-- -------------------------------------------------------------------
SET @Cloth := 400; -- Class Bitmask: 16 (Priest) +128 (Mage) +256 (Warlock)
SET @Leather1 := 1100; -- Class Bitmask: 4 (Hunter) +8 (Rogue) +64 (Shaman) +1024 (Druid)
SET @Leather2 := 1032; -- Class Bitmask: 8 (Rogue) +1024 (Druid)
SET @Mail1 := 3; -- Class Bitmask: 1 (Warrior) +2 (Paladin)
SET @Mail2 := 68; -- Class Bitmask: 4 (Hunter) +8 (Shaman)
SET @Plate := 35; -- Class Bitmask: 1 (Warrior) +2 (Paladin) +32 (DeathKnight)
-- Add conditions to make sure everyone gets beneficial loot for their class
-- -------------------------------------------------------------------
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=5 AND `SourceGroup` BETWEEN 51999 AND 52005;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup` BETWEEN @Reference AND @Reference+25;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Cloth Items
(10,@Reference,51968,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Wrap only for clothusers'),
(10,@Reference,51994,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Tumultuous Cloak only for clothusers'),
(10,@Reference+3,51973,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Handwraps only for clothusers'),
(10,@Reference+3,51996,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Tumultuous Necklace only for clothusers'),
(10,@Reference+6,51974,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Shoulderpads only for clothusers'),
(10,@Reference+6,51992,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Tumultuous Ring only for clothusers'),
(10,@Reference+10,51967,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Sandals only for clothusers'),
(10,@Reference+10,51972,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Bracers only for clothusers'),
(10,@Reference+14,51971,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Belt only for clothusers'),
(10,@Reference+14,51993,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Turbulent Cloak only for clothusers'),
(10,@Reference+18,51970,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Gloves only for clothusers'),
(10,@Reference+18,51995,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Turbulent Necklace only for clothusers'),
(10,@Reference+22,51969,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Shoulders only for clothusers'),
(10,@Reference+22,51991,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Turbulent Signet only for clothusers'),
-- Leather Items
(10,@Reference+1,51964,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Vigorous Belt only for leatherusers'),
(10,@Reference+1,51994,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Tumultuous Cloak only for leatherusers'),
(10,@Reference+4,51965,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Vigorous Handguards only for leatherusers'),
(10,@Reference+4,51996,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Tumultuous Necklace only for leatherusers'),
(10,@Reference+7,51966,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Spaulders only for leatherusers'),
(10,@Reference+7,51992,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Tumultuous ring only for leatherusers'),
(10,@Reference+11,51962,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Bracers only for leatherusers'),
(10,@Reference+11,51963,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Stompers only for leatherusers'),
(10,@Reference+15,51959,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Belt only for leatherusers'),
(10,@Reference+15,51993,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Turbulent Cloak only for leatherusers'),
(10,@Reference+19,51960,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Gloves only for leatherusers'),
(10,@Reference+19,51995,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Turbulent Necklace only for leatherusers'),
(10,@Reference+23,51961,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Shoulderguards only for leatherusers'),
(10,@Reference+23,51991,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Turbulent Signet only for leatherusers'),
-- Mail Items
(10,@Reference+2,51978,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Earthbound Girdle only for mail users'),
(10,@Reference+2,51994,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Tumultuous Cloak only for mail users'),
(10,@Reference+5,51980,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Earthbound Handgrips only for mail users'),
(10,@Reference+5,51996,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Tumultuous Necklace only for Mail users'),
(10,@Reference+8,51976,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Shoulderguards only for mail users'),
(10,@Reference+8,51992,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Tumultuous Ring only for mail users'),
(10,@Reference+12,51982,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Boots only for mail users'),
(10,@Reference+12,51981,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Wristguards only for mail users'),
(10,@Reference+16,51977,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Girdle only for mail users'),
(10,@Reference+16,51993,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Turbulent Cloak only for mail users'),
(10,@Reference+20,51979,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Grips only for mail users'),
(10,@Reference+20,51995,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Turbulent Necklace only for mail users'),
(10,@Reference+24,51975,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Shoulders only for mail users'),
(10,@Reference+24,51991,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Turbulent Signet only for Mail users'),
-- Plate Items
(10,@Reference+9,51984,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Shoulderpads only for plate users'),
(10,@Reference+9,51992,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Tumultuous Ring only for plate users'),
(10,@Reference+13,51989,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Bands only for plate users'),
(10,@Reference+13,51990,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Treads only for plate users'),
(10,@Reference+17,51985,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Belt only for plate users'),
(10,@Reference+17,51993,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Turbulent Cloak only for plate users'),
(10,@Reference+21,51987,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Grips only for plate users'),
(10,@Reference+21,51995,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Turbulent Necklace only for plate users'),
(10,@Reference+25,51983,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Shoulderguards only for plate users'),
(10,@Reference+25,51991,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Turbulent Signet only for plate users');
