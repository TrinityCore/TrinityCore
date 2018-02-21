 -- Zar'jira
UPDATE `creature_template` SET `minlevel`=5,`maxlevel`=5 WHERE `entry` IN (38306);

-- Wildmane Cat (1)
SET @ENTRY := 38046;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,50222,0,100,1,1,0,1,1, 'Wildmane Cat Pelt'),
(@ENTRY,62391,0,95,0,1,1,1,1, 'Cat Hair'),
(@ENTRY,4813,0,5,0,1,1,1,1, 'Small Leather Collar');

-- Docile Island Boar (2)
SET @ENTRY := 38141;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,117,0,100,0,1,1,1,1, 'Tough Jerky');

-- Pygmy Surf Crawler (2-3)
SET @ENTRY := 39004;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,52080,0,100,1,1,0,1,1, 'Fresh Crawler Meat'),
(@ENTRY,62514,0,100,0,1,1,1,1, 'Cracked Pincer');

-- Bloodtalon Raptor (2-3)
SET @ENTRY := 37956;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,62512,0,90,0,1,1,1,1, 'Small Animal Bone'),
(@ENTRY,4877,0,10,0,1,1,1,1, 'Stone Arrowhead');

-- Corrupted Bloodtalon (2-3)
SET @ENTRY := 37961;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=0, `maxgold`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,62512,0,90,0,1,1,1,1, 'Small Animal Bone'),
(@ENTRY,4877,0,10,0,1,1,1,1, 'Stone Arrowhead');

-- Naj'tess <Consort of the Sea Witch> (3)
SET @ENTRY := 50018;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=1, `maxgold`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,62512,0,100,1,1,0,1,1, 'Naj''tess'' Orb of Corruption');

-- Spitescale Wavethrasher (4)
SET @ENTRY := 38300;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=1, `maxgold`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,5523,0,75,0,1,1,1,1, 'Small Barnacled Clam');

-- Spitescale Siren (4)
SET @ENTRY := 38301;
UPDATE `creature_template` SET `lootid`=@ENTRY, `mingold`=1, `maxgold`=5 WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,5523,0,75,0,1,1,1,1, 'Small Barnacled Clam');
