-- Loot for Murloc Spearhunter & Murloc Watershaper
SET @ID := 150228;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=2, GoldMax=13 WHERE `Entry` IN (@ID,@ID+1);
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,170549,0,100,1,1,0,1,1,'Murloc Spearhunter/Watershaper - First Aid Kit (Quest item)'),
(@ID,779,0,20,0,1,0,1,1,'Murloc Spearhunter/Watershaper - Shiny Seashell'),
(@ID,174791,0,20,0,1,1,1,1,'Murloc Spearhunter/Watershaper - Stitched Cloth Shoes'),
(@ID,174792,0,20,0,1,2,1,1,'Murloc Spearhunter/Watershaper - Stitched Leather Boots'),
(@ID,174793,0,20,0,1,3,1,1,'Murloc Spearhunter/Watershaper - Linked Mail Boots'),
(@ID,174794,0,20,0,1,4,1,1,'Murloc Spearhunter/Watershaper - Dented Plate Boots');

-- Conditions for class loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,174791,0,0,15,0,400,0,0,0,0,0,'','Item drops for cloth wearer'),
(1,@ID,174791,0,0,47,0,58883,64,0,1,0,0,'','Item drops if quest 58883 is not rewarded'),
(1,@ID,174792,0,0,15,0,3592,0,0,0,0,0,'','Item drops for leather wearer'),
(1,@ID,174792,0,0,47,0,58883,64,0,1,0,0,'','Item drops if quest 58883 is not rewarded'),
(1,@ID,174793,0,0,15,0,4168,0,0,0,0,0,'','Item drops for mail wearer'),
(1,@ID,174793,0,0,47,0,58883,64,0,1,0,0,'','Item drops if quest 58883 is not rewarded'),
(1,@ID,174794,0,0,15,0,35,0,0,0,0,0,'','Item drops for plate wearer'),
(1,@ID,174794,0,0,47,0,58883,64,0,1,0,0,'','Item drops if quest 58883 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=58883;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(58883,2,1,1,1,1024, '[Hidden Tracker] Murloc Hideaway Boots Dropped');

-- Loot for Coastal Goat
SET @ID := 161130;
UPDATE `creature_template_difficulty` SET `LootID`=@ID WHERE `Entry`=@ID;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,174072,0,100,1,1,0,1,1,'Coastal Goat - Raw Meat (Quest item)'),
(@ID,4865,0,55,0,1,1,1,1,'Coastal Goat - Ruined Pelt'),
(@ID,5118,0,45,0,1,1,1,1,'Coastal Goat - Large Flat Tooth');

-- Loot for Prickly Porcupine
SET @ID := 161131;
UPDATE `creature_template_difficulty` SET `LootID`=@ID WHERE `Entry`=@ID;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,174072,0,100,1,1,0,1,1,'Prickly Porcupine - Raw Meat (Quest item)'),
(@ID,3299,0,70,0,1,1,1,1,'Prickly Porcupine - Fractured Canine'),
(@ID,3301,0,30,0,1,1,1,1,'Prickly Porcupine - Sharp Canine');

-- Loot for Coastal Albatross
SET @ID := 161133;
UPDATE `creature_template_difficulty` SET `LootID`=@ID WHERE `Entry`=@ID;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,174072,0,100,1,1,0,1,1,'Coastal Albatross - Raw Meat (Quest item)'),
(@ID,4776,0,55,0,1,1,1,1,'Coastal Albatross - Ruffled Feather'),
(@ID,4775,0,45,0,1,1,1,1,'Coastal Albatross - Cracked Bill');

-- Loot for Wandering Boar
SET @ID := 164826;
UPDATE `creature_template_difficulty` SET `LootID`=@ID WHERE `Entry`=@ID;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,771,0,55,0,1,1,1,1,'Wandering Boar - Chipped Boar Tusk'),
(@ID,2295,0,45,0,1,1,1,1,'Wandering Boar - Large Boar Tusk');

-- Loot for Sharpbeak Hawk
SET @ID := 164827;
UPDATE `creature_template_difficulty` SET `LootID`=@ID WHERE `Entry`=@ID;
DELETE FROM `creature_loot_template` WHERE `Entry`=@ID;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,4776,0,55,0,1,1,1,1,'Sharpbeak Hawk - Ruffled Feather'),
(@ID,4775,0,45,0,1,1,1,1,'Sharpbeak Hawk - Cracked Bill');
