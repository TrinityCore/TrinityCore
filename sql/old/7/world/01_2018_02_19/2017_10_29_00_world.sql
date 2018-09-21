-- #### Gameobject Loot for Panrarian start zone ####

-- Loose Dogwood Root Entry: 209326
SET @ENTRY := 40266;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,72111,0,100,1,1,0,1,1, 'Dry Dogwood Root');

-- Hard Tearwood Reed Entry: 209507
SET @ENTRY := 40379;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,73178,0,100,1,1,0,1,1, 'Hard Tearwood Reed');

-- Uprooted Turnip Entry: 209639 & 209640
SET @ENTRY := 40442;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74295,0,100,1,1,0,1,1, 'Uprooted Turnip');

-- Stolen Carrot Entry: 209641
SET @ENTRY := 40443;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74296,0,100,1,1,0,1,1, 'Stolen Carrot');

-- Pilfered Pumpkin Entry: 209642, 209643, 209644, & 209645
SET @ENTRY := 40444;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74297,0,100,1,1,0,1,1, 'Pilfered Pumpkin');

-- Discarded Wood Planks Entry: 209646
SET @ENTRY := 40446;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74301,0,100,1,1,0,2,2, 'Discarded Wood Planks');

-- Dai-Lo Recess Mallet Entry: 214406
SET @ENTRY := 40445;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74298,0,100,1,1,0,1,1, 'Dai-Lo Recess Mallet');

-- Abandoned Stone Blocks Entry: 209665
SET @ENTRY := 40458;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74624,0,100,1,1,0,2,2, 'Abandoned Stone Blocks');

-- Stolen Fireworks Entry: 209669
SET @ENTRY := 40459;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74631,0,100,1,1,0,1,1, 'Stolen Fireworks Bundle');

-- Kun-Pai Ritual Charm Entry: 209671, 209774
SET @ENTRY := 40461;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74634,0,100,1,1,0,1,1, 'Kun-Pai Ritual Charm');

-- Broken Bamboo Stalk Entry: 211394,211397,211398,211399,211400,211401
SET @ENTRY := 41543;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,80806,0,100,1,1,0,1,1, 'Broken Bamboo Stalk');

-- Explosive Bundle Entry: 209792
SET @ENTRY := 40473;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74955,0,100,1,1,0,1,1, 'Packed Explosion Charge');

-- Alliance Medical Crate Entry: 209793
SET @ENTRY := 40474;
DELETE FROM `gameobject_loot_template` WHERE `Entry`=@ENTRY;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ENTRY,74958,0,100,1,1,0,1,1, 'Alliance Medical Supplies');
