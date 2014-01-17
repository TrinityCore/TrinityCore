DELETE FROM `item_loot_template` WHERE `entry` BETWEEN 51999 AND 52005;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Satchel of Helpfull Goods (level 0-25)
(51999,51964,0,1,1,1,1), -- Vigorous Belt
(51999,51968,0,1,1,1,1), -- Enumerated Wrap
(51999,51978,0,1,1,1,1), -- Earthbound Girdle
(51999,51994,25,1,1,1,1), -- Tumultuous Cloak
-- Satchel of Helpfull Goods (level 26-35)
(52000,51965,0,1,1,1,1), -- Vigorous Handguards
(52000,51973,0,1,1,1,1), -- Enumerated Handwraps
(52000,51980,0,1,1,1,1), -- Earthbound Handgrips
(52000,51996,25,1,1,1,1), -- Tumultuous Necklace
-- Satchel of Helpfull Goods (level 36-45)
(52001,51966,0,1,1,1,1), -- Vigorous Spaulders
(52001,51974,0,1,1,1,1), -- Enumerated Shoulderpads
(52001,51976,0,1,1,1,1), -- Earthbound Shoulderguards
(52001,51984,0,1,1,1,1), -- Stalwart Shoulderpads
(52001,51992,25,1,1,1,1), -- Tumultuous Ring
-- Satchel of Helpfull Goods (level 46-55)
(52002,51962,0,1,1,1,1), -- Vigorous Bracers
(52002,51963,0,1,1,1,1), -- Vigorous Stompers
(52002,51967,0,1,1,1,1), -- Enumerated Sandals
(52002,51972,0,1,1,1,1), -- Enumerated Bracers
(52002,51981,0,1,1,1,1), -- Earthbound Wristguards
(52002,51982,0,1,1,1,1), -- Earthbound Boots
(52002,51989,0,1,1,1,1), -- Stalwart Bands
(52002,51990,0,1,1,1,1), -- Stalwart Treads
-- Satchel of Helpfull Goods (level 56-60)
(52003,51959,0,1,1,1,1), -- Vigorous Belt
(52003,51971,0,1,1,1,1), -- Enumerated Belt
(52003,51977,0,1,1,1,1), -- Earthbound Girdle
(52003,51985,0,1,1,1,1), -- Stalwart Belt
(52003,51993,25,1,1,1,1), -- Turbulent Cloak
-- Satchel of Helpfull Goods (level 61-64)
(52004,51960,0,1,1,1,1), -- Vigorous Gloves
(52004,51970,0,1,1,1,1), -- Enumerated Gloves
(52004,51979,0,1,1,1,1), -- Earthbound Grips
(52004,51987,0,1,1,1,1), -- Stalwart Grips
(52004,51995,25,1,1,1,1), -- Turbulent Necklace
-- Satchel of Helpfull Goods (level 65-70)
(52005,51961,0,1,1,1,1), -- Vigorous Shoulderguards
(52005,51969,0,1,1,1,1), -- Enumerated Shoulders
(52005,51975,0,1,1,1,1), -- Earthbound Shoulders
(52005,51983,0,1,1,1,1), -- Stalwart Shoulderguards
(52005,51991,25,1,0,1,1); -- Turbulent Signet
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
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=5 AND `SourceGroup` BETWEEN 51999 AND 52005 ;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Cloth Items
(5,51999,51968,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Wrap only for clothusers'),
(5,52000,51973,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Handwraps only for clothusers'),
(5,52001,51974,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Shoulderpads only for clothusers'),
(5,52002,51967,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Sandals only for clothusers'),
(5,52002,51972,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Bracers only for clothusers'),
(5,52003,51971,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Belt only for clothusers'),
(5,52004,51970,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Gloves only for clothusers'),
(5,52005,51969,0,0,15,0,@Cloth,0,0,0,0,'','SOHG: Enumerated Shoulders only for clothusers'),
-- Leather Items
(5,51999,51964,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Vigorous Belt only for leatherusers'),
(5,52000,51965,0,0,15,0,@Leather1,0,0,0,0,'','SOHG: Vigorous Handguards only for leatherusers'),
(5,52001,51966,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Spaulders only for leatherusers'),
(5,52002,51962,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Bracers only for leatherusers'),
(5,52002,51963,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Stompers only for leatherusers'),
(5,52003,51959,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Belt only for leatherusers'),
(5,52004,51960,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Gloves only for leatherusers'),
(5,52005,51961,0,0,15,0,@Leather2,0,0,0,0,'','SOHG: Vigorous Shoulderguards only for leatherusers'),
-- Mail Items
(5,51999,51978,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Earthbound Girdle only for mail users'),
(5,52000,51980,0,0,15,0,@Mail1,0,0,0,0,'','SOHG: Earthbound Handgrips only for mail users'),
(5,52001,51976,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Shoulderguards only for mail users'),
(5,52002,51982,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Boots only for mail users'),
(5,52002,51981,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Wristguards only for mail users'),
(5,52003,51977,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Girdle only for mail users'),
(5,52004,51979,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Grips only for mail users'),
(5,52005,51975,0,0,15,0,@Mail2,0,0,0,0,'','SOHG: Earthbound Shoulders only for mail users'),
-- Plate Items
(5,52001,51984,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Shoulderpads only for plate users'),
(5,52002,51989,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Bands only for plate users'),
(5,52002,51990,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Treads only for plate users'),
(5,52003,51985,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Belt only for plate users'),
(5,52004,51987,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Grips only for plate users'),
(5,52005,51983,0,0,15,0,@Plate,0,0,0,0,'','SOHG: Stalwart Shoulderguards only for plate users');
