-- Blackrock Worg
SET @ENTRY := 49871;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,62328,0,90,0,1,0,1,1, 'Shed Fur'),
(@ENTRY,3300,0,10,0,1,0,1,1, 'Rabbits Foot');

-- Gug Fatcandle
SET @ENTRY := 62;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=1, `maxgold`=8 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,56147,0,100,0,1,0,1,1, 'Fatcandle Bag');

-- Blackrock Invader
SET @ENTRY := 42937;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=1, `maxgold`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,58361,0,100,1,1,0,1,1, 'Blackrock Orc Weapon'),
(@ENTRY,117,0,1,0,1,1,1,1, 'Tough Jerky');

-- Kurtok the Slayer
SET @ENTRY := 42938;
UPDATE `creature_template` SET `lootid`=0, `mingold`=1, `maxgold`=5 WHERE `entry`=@ENTRY;
