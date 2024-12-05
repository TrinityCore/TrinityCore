--
SET @GREYREF := 1056;
SET @FOODREF := 1058;
DELETE FROM `reference_loot_template` WHERE `Entry` BETWEEN @GREYREF AND @GREYREF + 1;
DELETE FROM `reference_loot_template` WHERE `Entry` = @FOODREF;
SET @REFGREY0 := @GREYREF;
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

SET @REFGREY1 := @GREYREF + 1;
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

-- Food Reference loot for Entry 2843 : Battered Chest
SET @REFFOOD := @FOODREF;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFFOOD,159,0,20,0,1,1,1,1, 'Battered Chest (2943) - Refreshing Spring Water'),
(@REFFOOD,4540,0,10,0,1,1,1,1, 'Battered Chest (2943) - Tough Hunk of Bread'),
(@REFFOOD,2070,0,10,0,1,1,1,1, 'Battered Chest (2943) - Darnassian Bleu'),
(@REFFOOD,117,0,10,0,1,1,1,1, 'Battered Chest (2943) - Tough Jerky'),
(@REFFOOD,4536,0,10,0,1,1,1,1, 'Battered Chest (2943) - Shiny Red Apple');

-- Update loot for Entry 2843 : Battered Chest
SET @OBJECT := 2265;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@OBJECT;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@OBJECT,@REFFOOD,@REFFOOD,100,0,1,0,1,2, 'Battered Chest - (Food Battered Chest (2943) ReferenceTable)'),
(@OBJECT,@REFGREY0,@REFGREY0,100,0,1,0,1,1, 'Battered Chest - (Grey 1-5 EXP 0 ReferenceTable)');

UPDATE `gameobject_template_addon` SET `mingold`=1, `maxgold`=20 WHERE `entry` = 2843;
