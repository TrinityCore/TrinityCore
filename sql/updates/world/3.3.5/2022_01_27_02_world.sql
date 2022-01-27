-- Update Primary Keys for creature_loot_template
ALTER TABLE `creature_loot_template` DROP PRIMARY KEY, ADD PRIMARY KEY (`Entry`, `Item`, `Reference`, `GroupId`) USING BTREE;

SET @REF := 20000;
DELETE FROM `reference_loot_template` WHERE `Entry` BETWEEN @REF AND @REF + 18;
DELETE FROM `reference_loot_template` WHERE `Entry`=24072;

SET @REFGREY0 := @REF;
-- Correct ref loot for various grey level 1 to 5 Vanilla
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFGREY0, 1364, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Vest'),
(@REFGREY0, 1366, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Pants'),
(@REFGREY0, 1367, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Boots'),
(@REFGREY0, 1368, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Gloves'),
(@REFGREY0, 1369, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Belt'),
(@REFGREY0, 1370, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Leather Bracers'),
(@REFGREY0, 1372, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Ragged Cloak'),
(@REFGREY0, 1374, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Shoes'),
(@REFGREY0, 1376, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Cloak'),
(@REFGREY0, 1377, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Gloves'),
(@REFGREY0, 1378, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Pants'),
(@REFGREY0, 1380, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Robe'),
(@REFGREY0, 3363, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Belt'),
(@REFGREY0, 3365, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Frayed Bracers'),
(@REFGREY0, 2649, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Belt'),
(@REFGREY0, 2650, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Boots'),
(@REFGREY0, 2651, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Bracers'),
(@REFGREY0, 2652, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Cloak'),
(@REFGREY0, 2653, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Gloves'),
(@REFGREY0, 2654, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Pants'),
(@REFGREY0, 2656, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Flimsy Chain Vest'),
(@REFGREY0, 2210, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Battered Buckler'),
(@REFGREY0, 2211, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 0 : Bent Large Shield');

SET @REFGREY1 := @REF + 1;
-- Correct ref loot for various grey level 1 to 5 TBC
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFGREY1, 21002, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Belt'),
(@REFGREY1, 21003, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Bracers'),
(@REFGREY1, 21004, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Cloak'),
(@REFGREY1, 21005, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Gloves'),
(@REFGREY1, 21006, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Pants'),
(@REFGREY1, 21007, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Robe'),
(@REFGREY1, 21008, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Unkempt Shoes'),
(@REFGREY1, 21009, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Belt'),
(@REFGREY1, 21010, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Boots'),
(@REFGREY1, 21011, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Bracers'),
(@REFGREY1, 21012, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Gloves'),
(@REFGREY1, 21013, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Pants'),
(@REFGREY1, 21014, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Scraggy Leather Vest'),
(@REFGREY1, 21015, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Belt'),
(@REFGREY1, 21016, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Vest'),
(@REFGREY1, 21017, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Pants'),
(@REFGREY1, 21018, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Gloves'),
(@REFGREY1, 21019, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Bracers'),
(@REFGREY1, 21020, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Shoddy Chain Boots'),
(@REFGREY1, 21021, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Battered Shield'),
(@REFGREY1, 21022, 0, 0, 0, 1, 1, 1, 1, 'Grey 1-5 EXP 1 : Weather Beaten Buckler');

-- Beast Reference loot for level 1 to 5
SET @REFBEAST := @REF + 2;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFBEAST,4865,0,40,0,1,1,1,1, 'Beast 1-5 - Ruined Pelt'),
(@REFBEAST,7074,0,30,0,1,1,1,1, 'Beast 1-5 - Chipped Claw'),
(@REFBEAST,7073,0,30,0,1,1,1,1, 'Beast 1-5 - Broken Fang');

-- Boar Reference loot for level 1 to 5
SET @REFBOAR := @REF + 3;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFBOAR,4865,0,40,0,1,1,1,1, 'Boar 1-5 - Ruined Pelt'),
(@REFBOAR,7098,0,40,0,1,1,1,1, 'Boar 1-5 - Splintered Tusk'),
(@REFBOAR,117,0,20,0,1,1,1,1, 'Boar 1-5 - Tough Jerky');

-- Spider Reference loot for level 1 to 5
SET @REFSPIDER := @REF + 4;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFSPIDER,1476,0,40,0,1,1,1,1, 'Spider 1-5 - Snapped Spider Limb'),
(@REFSPIDER,7100,0,30,0,1,1,1,1, 'Spider 1-5 - Sticky Ichor'),
(@REFSPIDER,7101,0,30,0,1,1,1,1, 'Spider 1-5 - Bug Eye');

-- Bird Reference loot for level 1 to 5
SET @REFBIRD := @REF + 5;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFBIRD,7096,0,40,0,1,1,1,1, 'Bird 1-5 - Plucked Feather'),
(@REFBIRD,4757,0,30,0,1,1,1,1, 'Bird 1-5 - Cracked Egg Shells'),
(@REFBIRD,7097,0,30,0,1,1,1,1, 'Bird 1-5 - Leg Meat');

-- Scorpid Reference loot for level 1 to 5
SET @REFSCORPID := @REF + 6;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFSCORPID,4867,0,40,0,1,1,1,1, 'Scorpid 1-5 - Broken Scorpid Leg'),
(@REFSCORPID,7099,0,30,0,1,1,1,1, 'Scorpid 1-5 - Severed Pincer'),
(@REFSCORPID,7101,0,30,0,1,1,1,1, 'Scorpid 1-5 - Bug Eye');

-- Vale Moth Reference loot for level 1 to 5
SET @REFMOTH := @REF + 7;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFMOTH,25466,0,50,0,1,1,1,1, 'Vale Moth 1-5 - Broken Antenna'),
(@REFMOTH,25467,0,50,0,1,1,1,1, 'Vale Moth 1-5 - Torn Moth Wing');

-- Volatile Mutation Reference loot for level 1 to 5
SET @REFMUTATION := @REF + 8;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFMUTATION,7073,0,50,0,1,1,1,1, 'Volatile Mutation 1-5 - Broken Fang'),
(@REFMUTATION,7074,0,50,0,1,1,1,1, 'Volatile Mutation 1-5 - Chipped Claw');

-- Mutated Root Lasher Reference loot for level 1 to 5
SET @REFLASHER := @REF + 9;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFLASHER,23331,0,50,0,1,1,1,1, 'Mutated Root Lasher 1-5 - Broken Vine'),
(@REFLASHER,23332,0,50,0,1,1,1,1, 'Mutated Root Lasher 1-5 - Withered Lasher Root');

-- Mana Wyrm Reference loot for level 1 to 5
SET @REFWYRM := @REF + 10;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFWYRM,20845,0,50,0,1,1,1,1, 'Wyrm 1-5 - Torn Wyrm Scale'),
(@REFWYRM,20846,0,50,0,1,1,1,1, 'Wyrm 1-5 - Faintly Glowing Eye');

-- Lynx Reference loot for level 1 to 5
SET @REFLYNX := @REF + 11;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFLYNX,20812,0,50,0,1,1,1,1, 'Lynx 1-5 - Tattered Pelt'),
(@REFLYNX,20813,0,50,0,1,1,1,1, 'Lynx 1-5 - Lynx Tooth');

-- Tender Reference loot for level 1 to 5
SET @REFTENDER := @REF + 12;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFTENDER,20842,0,50,0,1,1,1,1, 'Tender 1-5 - Frayed Tender Vine'),
(@REFTENDER,20843,0,50,0,1,1,1,1, 'Tender 1-5 - Smashed Petal');

-- Wraith Reference loot for level 1 to 5
SET @REFWRAITH := @REF + 13;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFWRAITH,20847,0,50,0,1,1,1,1, 'Wraith 1-5 - Wraith Fragment'),
(@REFWRAITH,20848,0,50,0,1,1,1,1, 'Wraith 1-5 - Sparkling Dust');

-- *** Food Loot ***

-- Food Reference loot for level 1 to 5
SET @REFFOOD0 := @REF + 14;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD0,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD0,4536,0,67,0,1,1,1,1, 'Food 1-5 - Shiny Red Apple');

-- Food Reference loot for level 1 to 5
SET @REFFOOD1 := @REF + 15;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD1,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD1,117,0,67,0,1,1,1,1, 'Food 1-5 - Tough Jerky');

-- Food Reference loot for level 1 to 5
SET @REFFOOD2 := @REF + 16;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD2,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD2,4604,0,67,0,1,1,1,1, 'Food 1-5 - Forest Mushroom Cap');

-- Food Reference loot for level 1 to 5
SET @REFFOOD3 := @REF + 17;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD3,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD3,2070,0,67,0,1,1,1,1, 'Food 1-5 - Darnassian Bleu');

-- Food Reference loot for level 1 to 5
SET @REFFOOD4 := @REF + 18;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD4,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD4,4540,0,67,0,1,1,1,1, 'Food 1-5 - Tough Hunk of Bread');

-- *** Northshire ***

-- Update loot for Entry 69 : Diseased Timber Wolf
SET @NPC := 69;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Diseased Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Diseased Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Diseased Timber Wolf - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Diseased Timber Wolf - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,50432,0,90,1,1,0,1,1, 'Diseased Timber Wolf - Diseased Wolf Pelt');

-- Update loot for Entry 299 : Diseased Timber Wolf
SET @NPC := 299;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Diseased Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Diseased Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Diseased Timber Wolf - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Diseased Timber Wolf - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,50432,0,90,1,1,0,1,1, 'Diseased Timber Wolf - Diseased Wolf Pelt');

-- Update loot for Entry 6 : Kobold Vermin
SET @NPC := 6;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Kobold Vermin - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Kobold Vermin - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Kobold Vermin - (Small Pouch ReferenceTable)'),
(@NPC,755,0,20,0,1,0,1,1, 'Kobold Vermin - Melted Candle');

-- Update loot for Entry 257 : Kobold Worker
SET @NPC := 257;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Kobold Worker - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Kobold Worker - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Kobold Worker - (Small Pouch ReferenceTable)'),
(@NPC,755,0,20,0,1,0,1,1, 'Kobold Worker - Melted Candle');

-- Update loot for Entry 80 : Kobold Laborer
SET @NPC := 80;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Kobold Laborer - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Kobold Laborer - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Kobold Laborer - (Small Pouch ReferenceTable)'),
(@NPC,755,0,20,0,1,0,1,1, 'Kobold Laborer - Melted Candle'),
(@NPC,2055,0,2,0,1,0,1,1, 'Kobold Laborer - Small Wooden Hammer');

-- Entry 38 : Defias Thug
SET @NPC := 38;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD3,30,0,1,0,1,1, 'Defias Thug - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Defias Thug - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Defias Thug - (Small Pouch ReferenceTable)'),
(@NPC,2057,0,2,0,1,0,1,1, 'Defias Thug - Pitted Defias Shortsword'),
(@NPC,752,0,60,1,1,0,1,1, 'Defias Thug - Red Burlap Bandana');

-- Entry 103 : Garrick Padfoot
SET @NPC := 103;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD3,30,0,1,0,1,1, 'Garrick Padfoot - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Garrick Padfoot - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Garrick Padfoot - (Small Pouch ReferenceTable)'),
(@NPC,2057,0,2,0,1,0,1,1, 'Garrick Padfoot - Pitted Defias Shortsword'),
(@NPC,182,0,100,1,1,0,1,1, 'Garrick Padfoot - Garrick''s Head');

-- *** Coldridge Valley ***

-- Update loot for Entry 705 : Ragged Young Wolf
SET @NPC := 705;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Ragged Young Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Ragged Young Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Ragged Young Wolf - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Ragged Young Wolf - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,750,0,90,1,1,0,1,1, 'Ragged Young Wolf - Tough Wolf Meat');

-- Update loot for Entry 704 : Ragged Timber Wolf
SET @NPC := 704;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Ragged Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Ragged Timber Wolf - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Ragged Timber Wolf - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Ragged Timber Wolf - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,750,0,90,1,1,0,1,1, 'Ragged Timber Wolf - Tough Wolf Meat');

-- Update loot for Entry 708 : Small Crag Boar
SET @NPC := 708;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Small Crag Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Small Crag Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Small Crag Boar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Small Crag Boar - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 707 : Rockjaw Trogg
SET @NPC := 707;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Rockjaw Trogg - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Rockjaw Trogg - (Small Pouch ReferenceTable)');

-- Update loot for Entry 724 : Burly Rockjaw Trogg
SET @NPC := 724;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Burly Rockjaw Trogg - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Burly Rockjaw Trogg - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Burly Rockjaw Trogg - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,2787,0,2,0,1,0,1,1, 'Burly Rockjaw Trogg - Trogg Dagger');

-- Update loot for Entry 1718 : Rockjaw Raider
SET @NPC := 1718;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Rockjaw Raider - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Rockjaw Raider - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Rockjaw Raider - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,2054,0,2,0,1,0,1,1, 'Rockjaw Raider - Trogg Hand Axe');

-- Update loot for Entry 706 : Frostmane Troll Whelp
SET @NPC := 706;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Frostmane Troll Whelp - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Frostmane Troll Whelp - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Frostmane Troll Whelp - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,2108,0,2,0,1,0,1,1, 'Frostmane Troll Whelp - Frostmane Leather Vest');

-- Update loot for Entry 946 : Frostmane Novice
SET @NPC := 946;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Frostmane Novice - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Frostmane Novice - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Frostmane Novice - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,2110,0,2,0,1,0,1,1, 'Frostmane Novice - Light Magesmith Robe'),
(@NPC,6753,0,90,1,1,0,1,1, 'Frostmane Novice - Feather Charm');

-- Update loot for Entry 808 : Grik'nir the Cold
SET @NPC := 808;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Grik''nir the Cold - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Grik''nir the Cold - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Grik''nir the Cold - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,2109,0,2,0,1,0,1,1, 'Grik''nir the Cold - Frostmane Chain Vest'),
(@NPC,2004,0,100,1,1,0,1,1, 'Grik''nir the Cold - Grelin Whitebeard''s Journal');

-- *** Deathknell ***

-- Update loot for Entry 1509 : Ragged Scavenger
SET @NPC := 1509;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Ragged Scavenger - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Ragged Scavenger - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Ragged Scavenger - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Ragged Scavenger - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3265,0,90,1,1,0,1,1, 'Ragged Scavenger - Scavenger Paw');

-- Update loot for Entry 1513 : Mangy Duskbat
SET @NPC := 1513;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Mangy Duskbat - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Mangy Duskbat - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mangy Duskbat - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Mangy Duskbat - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3264,0,90,1,1,0,1,1, 'Mangy Duskbat - Duskbat Wing');

-- Update loot for Entry 1688 : Night Web Matriarch
SET @NPC := 1688;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSPIDER,100,0,1,0,1,1, 'Night Web Matriarch - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSPIDER,30,0,1,1,1,1, 'Night Web Matriarch - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Night Web Matriarch - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Night Web Matriarch - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3261,0,2,0,1,0,1,1, 'Webwood Matriarch - Webbed Cloak');

-- Update loot for Entry 1504 : Young Night Web Spider
SET @NPC := 1504;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSPIDER,100,0,1,0,1,1, 'Young Night Web Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSPIDER,30,0,1,1,1,1, 'Young Night Web Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Young Night Web Spider - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Young Night Web Spider - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 1505 : Night Web Spider
SET @NPC := 1505;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSPIDER,100,0,1,0,1,1, 'Night Web Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSPIDER,30,0,1,1,1,1, 'Night Web Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Night Web Spider - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Night Web Spider - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3263,0,2,0,1,0,1,1, 'Webwood Spider - Webbed Pants');

-- Update loot for Entry 1508 : Young Scavenger
SET @NPC := 1508;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Young Scavenger - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Young Scavenger - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Young Scavenger - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Young Scavenger - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3265,0,90,1,1,0,1,1, 'Young Scavenger - Scavenger Paw');

-- Update loot for Entry 1512 : Duskbat
SET @NPC := 1512;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Duskbat - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Duskbat - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Duskbat - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Duskbat - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,3264,0,90,1,1,0,1,1, 'Duskbat - Duskbat Wing');

-- Update loot for Entry 1501 : Mindless Zombie
SET @NPC := 1501;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Mindless Zombie - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Mindless Zombie - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mindless Zombie - (Small Pouch ReferenceTable)');

-- Update loot for Entry 1502 : Wretched Zombie
SET @NPC := 1502;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Wretched Zombie - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Wretched Zombie - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Wretched Zombie - (Small Pouch ReferenceTable)');

-- Update loot for Entry 1890 : Rattlecage Skeleton
SET @NPC := 1890;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Rattlecage Skeleton - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Rattlecage Skeleton - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Rattlecage Skeleton - (Small Pouch ReferenceTable)'),
(@NPC,3262,0,2,0,1,0,1,1, 'Rattlecage Skeleton - Putrid Wooden Hammer'),
(@NPC,6281,0,15,1,1,0,1,1, 'Rattlecage Skeleton - Rattlecage Skull');

-- Update loot for Entry 1916 : Stephen Bhartec
SET @NPC := 1916;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Stephen Bhartec - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Stephen Bhartec - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Stephen Bhartec - (Small Pouch ReferenceTable)'),
(@NPC,3296,0,2,0,1,0,1,1, 'Stephen Bhartec - Deadman Dagger');

-- Update loot for Entry 1917 : Daniel Ulfman
SET @NPC := 1917;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Daniel Ulfman - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Daniel Ulfman - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Daniel Ulfman - (Small Pouch ReferenceTable)'),
(@NPC,3293,0,2,0,1,0,1,1, 'Daniel Ulfman - Deadman Cleaver');

-- Update loot for Entry 1918 : Karrel Grayves
SET @NPC := 1918;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Karrel Grayves - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Karrel Grayves - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Karrel Grayves - (Small Pouch ReferenceTable)'),
(@NPC,3294,0,2,0,1,0,1,1, 'Karrel Grayves - Deadman Club');

-- Update loot for Entry 1919 : Samuel Fipps
SET @NPC := 1919;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD2,30,0,1,0,1,1, 'Samuel Fipps - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Samuel Fipps - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Samuel Fipps - (Small Pouch ReferenceTable)'),
(@NPC,3295,0,2,0,1,0,1,1, 'Samuel Fipps - Deadman Blade'),
(@NPC,16333,0,100,1,1,0,1,1, 'Samuel Fipps - Samuel''s Remains');

-- Entry 1506 : Scarlet Convert
SET @NPC := 1506;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD3,30,0,1,0,1,1, 'Scarlet Convert - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Scarlet Convert - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Scarlet Convert - (Small Pouch ReferenceTable)'),
(@NPC,2754,0,2,0,1,0,1,1, 'Scarlet Convert - Tarnished Bastard Sword'),
(@NPC,3266,0,70,1,1,0,1,1, 'Scarlet Convert - Scarlet Armband');

-- Entry 1507 : Scarlet Initiate
SET @NPC := 1507;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD3,30,0,1,0,1,1, 'Scarlet Initiate - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Scarlet Initiate - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Scarlet Initiate - (Small Pouch ReferenceTable)'),
(@NPC,3260,0,2,0,1,0,1,1, 'Scarlet Initiate - Scarlet Initiate Robes'),
(@NPC,3266,0,70,1,1,0,1,1, 'Scarlet Initiate - Scarlet Armband');

-- Entry 1667 : Meven Korgal
SET @NPC := 1667;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD3,30,0,1,0,1,1, 'Meven Korgal - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Meven Korgal - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Meven Korgal - (Small Pouch ReferenceTable)'),
(@NPC,3266,0,70,1,1,0,1,1, 'Meven Korgal - Scarlet Armband'),
(@NPC,2885,0,100,1,1,0,1,1, 'Meven Korgal - Scarlet Crusade Documents');

-- *** Shadowglen ***

-- Update loot for Entry 1984 : Young Thistle Boar
SET @NPC := 1984;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Young Thistle Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Young Thistle Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Young Thistle Boar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Young Thistle Boar - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 1985 : Thistle Boar
SET @NPC := 1985;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Thistle Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Thistle Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Thistle Boar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Thistle Boar - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 1986 : Webwood Spider
SET @NPC := 1986;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSPIDER,100,0,1,0,1,1, 'Webwood Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSPIDER,30,0,1,1,1,1, 'Webwood Spider - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Webwood Spider - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Webwood Spider - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,5166,0,90,1,1,0,1,1, 'Webwood Spider - Webwood Venom Sac'),
(@NPC,10640,0,90,1,1,0,1,1, 'Webwood Spider - Webwood Ichor');

-- Update loot for Entry 1988 : Grell
SET @NPC := 1988;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Grell - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Grell - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Grell - (Small Pouch ReferenceTable)'),
(@NPC,3297,0,90,1,1,0,1,1, 'Grell - Fel Moss'),
(@NPC,10639,0,90,1,1,0,1,1, 'Grell - Hyacinth Mushroom');

-- Update loot for Entry 1989 : Grellkin
SET @NPC := 1989;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Grellkin - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Grellkin - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,3297,0,90,1,1,0,1,1, 'Grellkin - Fel Moss'),
(@NPC,10639,0,90,1,1,0,1,1, 'Grellkin - Hyacinth Mushroom');

-- Update loot for Entry 1994 : Githyiss the Vile
SET @NPC := 1994;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSPIDER,100,0,1,0,1,1, 'Githyiss the Vile - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSPIDER,30,0,1,1,1,1, 'Githyiss the Vile - (Spider 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Githyiss the Vile - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Githyiss the Vile - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 2031 : Young Nightsaber
SET @NPC := 2031;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Young Nightsaber - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Young Nightsaber - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Young Nightsaber - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Young Nightsaber - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 2032 : Mangy Nightsaber
SET @NPC := 2032;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Mangy Nightsaber - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Mangy Nightsaber - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mangy Nightsaber - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Mangy Nightsaber - (Grey 1-5 EXP 0 ReferenceTable)');

-- *** Valley of Trials ***

-- Update loot for Entry 3098 : Mottled Boar
SET @NPC := 3098;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Mottled Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Mottled Boar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mottled Boar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Mottled Boar - (Grey 1-5 EXP 0 ReferenceTable)');

-- Update loot for Entry 3101 : Vile Familiar
SET @NPC := 3101;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Vile Familiar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Vile Familiar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Vile Familiar - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Vile Familiar - (Small Pouch ReferenceTable)'),
(@NPC,6487,0,100,1,1,0,1,1, 'Vile Familiar - Vile Familiar Head');

-- Update loot for Entry 3102 : Felstalker
SET @NPC := 3102;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Felstalker - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Felstalker - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Felstalker - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Felstalker - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,6640,0,90,1,1,0,1,1, 'Felstalker - Felstalker Hoof');

-- Update loot for Entry 3124 : Scorpid Worker
SET @NPC := 3124;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSCORPID,100,0,1,0,1,1, 'Scorpid Worker - (Scorpid 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSCORPID,30,0,1,1,1,1, 'Scorpid Worker - (Scorpid 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Scorpid Worker - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Scorpid Worker - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4862,0,90,1,1,0,1,1, 'Scorpid Worker - Scorpid Worker Tail');

-- Update loot for Entry 3281 : Sarkoth
SET @NPC := 3281;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFSCORPID,100,0,1,0,1,1, 'Sarkoth - (Scorpid 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFSCORPID,30,0,1,1,1,1, 'Sarkoth - (Scorpid 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Sarkoth - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Sarkoth - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4862,0,90,1,1,0,1,1, 'Sarkoth - Scorpid Worker Tail'),
(@NPC,4905,0,90,1,1,0,1,1, 'Sarkoth - Sarkoth''s Mangled Claw');

-- Entry 3183 : Yarrog Baneshadow
SET @NPC := 3183;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD1,30,0,1,0,1,1, 'Yarrog Baneshadow - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,1,1,1, 'Yarrog Baneshadow - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Yarrog Baneshadow - (Small Pouch ReferenceTable)'),
(@NPC,4859,0,100,1,1,0,1,1, 'Yarrog Baneshadow - Burning Blade Medallion');

-- *** Red Cloud Mesa ***

-- Update loot for Entry 2955 : Plainstrider
SET @NPC := 2955;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBIRD,100,0,1,0,1,1, 'Plainstrider - (Bird 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBIRD,30,0,1,1,1,1, 'Plainstrider - (Bird 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Plainstrider - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Plainstrider - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4739,0,90,1,1,0,1,1, 'Plainstrider - Plainstrider Meat'),
(@NPC,4740,0,90,1,1,0,1,1, 'Plainstrider - Plainstrider Feather');

-- Update loot for Entry 2961 : Mountain Cougar
SET @NPC := 2961;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBEAST,100,0,1,0,1,1, 'Mountain Cougar - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBEAST,30,0,1,1,1,1, 'Mountain Cougar - (Beast 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mountain Cougar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Mountain Cougar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4742,0,90,1,1,0,1,1, 'Mountain Cougar - Mountain Cougar Pelt');

-- Update loot for Entry 2954 : Bristleback Battleboar
SET @NPC := 2954;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Bristleback Battleboar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Bristleback Battleboar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Bristleback Battleboar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Bristleback Battleboar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4848,0,90,1,1,0,1,1, 'Bristleback Battleboar - Battleboar Snout'),
(@NPC,4849,0,90,1,1,0,1,1, 'Bristleback Battleboar - Battleboar Flank');

-- Update loot for Entry 2966 : Battleboar
SET @NPC := 2966;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBOAR,100,0,1,0,1,1, 'Battleboarr - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFBOAR,30,0,1,1,1,1, 'Battleboar - (Boar 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Battleboar - (Small Pouch ReferenceTable)'),
(@NPC,0,@REFGREY0,20,0,1,0,1,1, 'Battleboar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,4848,0,90,1,1,0,1,1, 'Battleboar - Battleboar Snout'),
(@NPC,4849,0,90,1,1,0,1,1, 'Battleboar - Battleboar Flank');

-- Update loot for Entry 2952 : Bristleback Quilboar
SET @NPC := 2952;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Bristleback Quilboar - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Bristleback Quilboar - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Bristleback Quilboar - (Small Pouch ReferenceTable)'),
(@NPC,1384,0,2,0,1,0,1,1, 'Bristleback Quilboar - Dull Blade'),
(@NPC,4770,0,90,1,1,0,1,1, 'Bristleback Quilboar - Bristleback Belt');

-- Update loot for Entry 2953 : Bristleback Shaman
SET @NPC := 2953;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Bristleback Shaman - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Bristleback Shaman - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Bristleback Shaman - (Small Pouch ReferenceTable)'),
(@NPC,1388,0,2,0,1,0,1,1, 'Bristleback Shaman - Crooked Staff'),
(@NPC,4770,0,90,1,1,0,1,1, 'Bristleback Shaman - Bristleback Belt'),
(@NPC,6634,0,15,1,1,0,1,1, 'Bristleback Shaman - Ritual Salve');

-- Update loot for Entry 3229 : "Squealer" Thornmantle
SET @NPC := 3229;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, '"Squealer" Thornmantle - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, '"Squealer" Thornmantle - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, '"Squealer" Thornmantle - (Small Pouch ReferenceTable)'),
(@NPC,4951,0,100,0,1,0,1,1, '"Squealer" Thornmantle - Squealer''s Belt');

-- Update loot for Entry 8554 : Chief Sharptusk Thornmantle
SET @NPC := 8554;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD0,30,0,1,0,1,1, 'Chief Sharptusk Thornmantle - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Chief Sharptusk Thornmantle - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Chief Sharptusk Thornmantle - (Small Pouch ReferenceTable)'),
(@NPC,10459,0,100,1,1,0,1,1, 'Chief Sharptusk Thornmantle - Chief Sharptusk Thornmantle''s Head');

-- *** Ammen Vale ***

-- Update loot for Entry 16520 : Vale Moth
SET @NPC := 16520;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFMOTH,100,0,1,0,1,1, 'Vale Moth - (Vale Moth 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Vale Moth - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Vale Moth - (Small Pouch ReferenceTable)'),
(@NPC,22889,0,90,1,1,0,1,1, 'Vale Moth - Vial of Moth Blood');

-- Update loot for Entry 16516 : Volatile Mutation
SET @NPC := 16516;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFMUTATION,100,0,1,0,1,1, 'Volatile Mutation - (Volatile Mutation 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Volatile Mutation - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Volatile Mutation - (Small Pouch ReferenceTable)');

-- Update loot for Entry 16517 : Mutated Root Lasher
SET @NPC := 16517;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFLASHER,100,0,1,0,1,1, 'Mutated Root Lasher - (Lasher 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Mutated Root Lasher - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mutated Root Lasher - (Small Pouch ReferenceTable)'),
(@NPC,23329,0,10,0,1,0,1,1, 'Mutated Root Lasher - Enriched Lasher Root'),
(@NPC,22934,0,90,1,1,0,1,1, 'Mutated Root Lasher - Lasher Sample');

-- Update loot for Entry 16518 : Nestlewood Owlkin
SET @NPC := 16518;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBIRD,100,0,1,0,1,1, 'Nestlewood Owlkin - (Bird 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFFOOD1,20,0,1,0,1,1, 'Nestlewood Owlkin - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Nestlewood Owlkin - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Nestlewood Owlkin - (Small Pouch ReferenceTable)');

-- Update loot for Entry 16537 : Mutated Owlkin
SET @NPC := 16537;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFBIRD,100,0,1,0,1,1, 'Mutated Owlkin - (Bird 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFFOOD1,20,0,1,0,1,1, 'Mutated Owlkin - (Food 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Mutated Owlkin - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mutated Owlkin - (Small Pouch ReferenceTable)');

-- Update loot for Entry 16521 : Blood Elf Scout
SET @NPC := 16521;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD4,100,0,1,0,1,1, 'Blood Elf Scout - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Blood Elf Scout - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Blood Elf Scout - (Small Pouch ReferenceTable)');

-- Update loot for Entry 16522 : Surveyor Candress
SET @NPC := 16522;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD4,100,0,1,0,1,1, 'Surveyor Candress - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Surveyor Candress - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Surveyor Candress - (Small Pouch ReferenceTable)'),
(@NPC,24414,0,100,0,1,0,1,1, 'Surveyor Candress - Blood Elf Plans');

-- *** Sunstrider Isle ***

-- Update loot for Entry 15274 : Mana Wyrm
SET @NPC := 15274;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFWYRM,100,0,1,0,1,1, 'Mana Wyrm - (Wyrm 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Mana Wyrm - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Mana Wyrm - (Small Pouch ReferenceTable)'),
(@NPC,20482,0,80,1,1,0,1,1, 'Mana Wyrm - Arcane Sliver');

-- Update loot for Entry 15366 : Springpaw Cub
SET @NPC := 15366;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFLYNX,100,0,1,0,1,1, 'Springpaw Cub - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFLYNX,30,0,1,1,1,1, 'Springpaw Cub - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Springpaw Cub - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Springpaw Cub - (Small Pouch ReferenceTable)'),
(@NPC,20797,0,80,1,1,0,1,1, 'Springpaw Cub - Lynx Collar');

-- Update loot for Entry 15372 : Springpaw Lynx
SET @NPC := 15372;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFLYNX,100,0,1,0,1,1, 'Springpaw Lynx - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFLYNX,30,0,1,1,1,1, 'Springpaw Lynx - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Springpaw Lynx - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Springpaw Lynx - (Small Pouch ReferenceTable)'),
(@NPC,20797,0,80,1,1,0,1,1, 'Springpaw Lynx - Lynx Collar');

-- Update loot for Entry 15271 : Tender
SET @NPC := 15271;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFTENDER,90,0,1,0,1,1, 'Tender - (Tender 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Tender - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Tender - (Small Pouch ReferenceTable)');

-- Update loot for Entry 15294 : Feral Tender
SET @NPC := 15294;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFTENDER,100,0,1,0,1,1, 'Feral Tender - (Tender 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Feral Tender - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Feral Tender - (Small Pouch ReferenceTable)'),
(@NPC,20482,0,80,1,1,0,1,1, 'Feral Tender - Arcane Sliver');

-- Update loot for Entry 15273 : Arcane Wraith
SET @NPC := 15273;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFWRAITH,100,0,1,0,1,1, 'Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFWRAITH,30,0,1,1,1,1, 'Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Arcane Wraith - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Arcane Wraith - (Small Pouch ReferenceTable)'),
(@NPC,20934,0,80,1,1,0,1,1, 'Arcane Wraith - Wraith Essence'),
(@NPC,20482,0,80,1,1,0,1,1, 'Arcane Wraith - Arcane Sliver');

-- Update loot for Entry 15298 : Tainted Arcane Wraith
SET @NPC := 15298;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFWRAITH,100,0,1,0,1,1, 'Tainted Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFWRAITH,30,0,1,1,1,1, 'Tainted Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Tainted Arcane Wraith - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Tainted Arcane Wraith - (Small Pouch ReferenceTable)'),
(@NPC,20483,0,100,0,1,0,1,1, 'Tainted Arcane Wraith - Tainted Arcane Sliver'),
(@NPC,20934,0,80,1,1,0,1,1, 'Tainted Arcane Wraith - Wraith Essence'),
(@NPC,20482,0,80,1,1,0,1,1, 'Tainted Arcane Wraith - Arcane Sliver');

-- Update loot for Entry 15367 : Felendren the Banished
SET @NPC := 15367;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD4,100,0,1,0,1,1, 'Felendren the Banished - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY1,30,0,1,0,1,1, 'Felendren the Banished - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Felendren the Banished - (Small Pouch ReferenceTable)'),
(@NPC,20799,0,100,1,1,0,1,1, 'Felendren the Banished - Felendren''s Head');

-- Update loot for Entry 15644 : Wretched Urchin
SET @NPC := 15644;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,0,@REFFOOD4,100,0,1,0,1,1, 'Wretched Urchin - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,0,@REFGREY0,30,0,1,0,1,1, 'Wretched Urchin - (Grey 1-5 EXP 0 ReferenceTable)'),
(@NPC,0,11111,.2,0,1,0,1,1, 'Wretched Urchin - (Small Pouch ReferenceTable)');

-- *** Northshire ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (6,257,80,38);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (103);

-- *** Coldridge Valley ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (706,707,724,946,1718);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (808);

-- *** Deathknell ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (1501,1502,1890,1916,1917,1918,1919,1506,1507);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (1667);

-- *** Shadowglen ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (1988,1989);

-- *** Valley of Trials ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (3101);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (3183);

-- *** Red Cloud Mesa ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (2952,2953,3229);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (8554);

-- *** Ammen Vale ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (16521);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (16522);

-- *** Sunstrider Isle ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (15644);
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (15367);
