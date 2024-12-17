-- *** Sunstrider Isle ***

SET @REF := 1059;
DELETE FROM `reference_loot_template` WHERE `Entry` BETWEEN @REF AND @REF + 4;

-- Food Reference loot for level 1 to 5
SET @REFFOOD4 := @REF;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD4,159,0,33,0,1,1,1,1, 'Food 1-5 - Refreshing Spring Water'),
(@REFFOOD4,4540,0,67,0,1,1,1,1, 'Food 1-5 - Tough Hunk of Bread');

-- Mana Wyrm Reference loot for level 1 to 5
SET @REFWYRM := @REF + 1;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFWYRM,20845,0,50,0,1,1,1,1, 'Wyrm 1-5 - Torn Wyrm Scale'),
(@REFWYRM,20846,0,50,0,1,1,1,1, 'Wyrm 1-5 - Faintly Glowing Eye');

-- Lynx Reference loot for level 1 to 5
SET @REFLYNX := @REF + 2;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFLYNX,20812,0,50,0,1,1,1,1, 'Lynx 1-5 - Tattered Pelt'),
(@REFLYNX,20813,0,50,0,1,1,1,1, 'Lynx 1-5 - Lynx Tooth');

-- Tender Reference loot for level 1 to 5
SET @REFTENDER := @REF + 3;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFTENDER,20842,0,50,0,1,1,1,1, 'Tender 1-5 - Frayed Tender Vine'),
(@REFTENDER,20843,0,50,0,1,1,1,1, 'Tender 1-5 - Smashed Petal');

-- Wraith Reference loot for level 1 to 5
SET @REFWRAITH := @REF + 4;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFWRAITH,20847,0,50,0,1,1,1,1, 'Wraith 1-5 - Wraith Fragment'),
(@REFWRAITH,20848,0,50,0,1,1,1,1, 'Wraith 1-5 - Sparkling Dust');

-- Update loot for Entry 15274 : Mana Wyrm
SET @NPC := 15274;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFWYRM,@REFWYRM,100,0,1,0,1,1, 'Mana Wyrm - (Wyrm 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Mana Wyrm - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Mana Wyrm - (Small Pouch ReferenceTable)'),
(@NPC,20482,0,80,1,1,0,1,1, 'Mana Wyrm - Arcane Sliver');

-- Update loot for Entry 15366 : Springpaw Cub
SET @NPC := 15366;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFLYNX,@REFLYNX,100,0,1,0,1,1, 'Springpaw Cub - (Lynx 1-5 EXP 1 ReferenceTable)'),
-- (@NPC,@REFLYNX,@REFLYNX,30,0,1,1,1,1, 'Springpaw Cub - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Springpaw Cub - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Springpaw Cub - (Small Pouch ReferenceTable)'),
(@NPC,20797,0,80,1,1,0,1,1, 'Springpaw Cub - Lynx Collar');

-- Update loot for Entry 15372 : Springpaw Lynx
SET @NPC := 15372;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFLYNX,@REFLYNX,100,0,1,0,1,1, 'Springpaw Lynx - (Lynx 1-5 EXP 1 ReferenceTable)'),
-- (@NPC,@REFLYNX,@REFLYNX,30,0,1,1,1,1, 'Springpaw Lynx - (Lynx 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Springpaw Lynx - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Springpaw Lynx - (Small Pouch ReferenceTable)'),
(@NPC,20797,0,80,1,1,0,1,1, 'Springpaw Lynx - Lynx Collar');

-- Update loot for Entry 15271 : Tender
SET @NPC := 15271;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFTENDER,@REFTENDER,90,0,1,0,1,1, 'Tender - (Tender 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Tender - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Tender - (Small Pouch ReferenceTable)');

-- Update loot for Entry 15294 : Feral Tender
SET @NPC := 15294;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFTENDER,@REFTENDER,100,0,1,0,1,1, 'Feral Tender - (Tender 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Feral Tender - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Feral Tender - (Small Pouch ReferenceTable)'),
(@NPC,20482,0,80,1,1,0,1,1, 'Feral Tender - Arcane Sliver');

-- Update loot for Entry 15273 : Arcane Wraith
SET @NPC := 15273;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFWRAITH,@REFWRAITH,100,0,1,0,1,1, 'Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
-- (@NPC,@REFWRAITH,@REFWRAITH,30,0,1,1,1,1, 'Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Arcane Wraith - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Arcane Wraith - (Small Pouch ReferenceTable)'),
(@NPC,20934,0,80,1,1,0,1,1, 'Arcane Wraith - Wraith Essence'),
(@NPC,20482,0,80,1,1,0,1,1, 'Arcane Wraith - Arcane Sliver');

-- Update loot for Entry 15298 : Tainted Arcane Wraith
SET @NPC := 15298;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFWRAITH,@REFWRAITH,100,0,1,0,1,1, 'Tainted Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
-- (@NPC,@REFWRAITH,@REFWRAITH,30,0,1,1,1,1, 'Tainted Arcane Wraith - (Wraith 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Tainted Arcane Wraith - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Tainted Arcane Wraith - (Small Pouch ReferenceTable)'),
(@NPC,20483,0,100,0,1,0,1,1, 'Tainted Arcane Wraith - Tainted Arcane Sliver'),
(@NPC,20934,0,80,1,1,0,1,1, 'Tainted Arcane Wraith - Wraith Essence'),
(@NPC,20482,0,80,1,1,0,1,1, 'Tainted Arcane Wraith - Arcane Sliver');

-- Update loot for Entry 15367 : Felendren the Banished
SET @NPC := 15367;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFFOOD4,@REFFOOD4,100,0,1,0,1,1, 'Felendren the Banished - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Felendren the Banished - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Felendren the Banished - (Small Pouch ReferenceTable)'),
(@NPC,20799,0,100,1,1,0,1,1, 'Felendren the Banished - Felendren''s Head');

-- Update loot for Entry 15644 : Wretched Urchin
SET @NPC := 15644;
DELETE FROM `creature_loot_template` WHERE `Entry`=@NPC;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@NPC,@REFFOOD4,@REFFOOD4,100,0,1,0,1,1, 'Wretched Urchin - (Food 1-5 EXP 1 ReferenceTable)'),
(@NPC,1057,1057,30,0,1,0,1,1, 'Wretched Urchin - (Grey 1-5 EXP 1 ReferenceTable)'),
(@NPC,11111,11111,.2,0,1,0,1,1, 'Wretched Urchin - (Small Pouch ReferenceTable)');

-- *** Sunstrider Isle ***
UPDATE `creature_template` SET `mingold`=1, `maxgold`=7 WHERE `entry` IN (15367);
DELETE FROM `reference_loot_template` WHERE `Entry`=24072;
