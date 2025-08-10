-- Loot for Quilboar Warrior & Quilboar Geomancer
SET @ID := 150237;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID,@ID+1);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,771,0,20,0,1,1,1,1,'Quilboar Warrior/Geomancer - Chipped Boar Tusk'),
(@ID,174811,0,20,0,1,2,1,1,'Quilboar Warrior/Geomancer - Stitched Cloth Tunic'),
(@ID,174812,0,20,0,1,3,1,1,'Quilboar Warrior/Geomancer - Stitched Leather Tunic'),
(@ID,174813,0,20,0,1,4,1,1,'Quilboar Warrior/Geomancer - Linked Mail Hauberk'),
(@ID,174814,0,20,0,1,5,1,1,'Quilboar Warrior/Geomancer - Dented Chestplate'),
(@ID,0,10100,15,0,1,6,1,1,'Quilboar Warrior/Geomancer - Poor Quality Table Level 1 to 5');

-- Conditions for class loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,174811,0,0,15,0,400,0,0,0,0,0,'','Item drops for cloth wearer'),
(1,@ID,174811,0,0,47,0,58904,64,0,1,0,0,'','Item drops if quest 58904 is not rewarded'),
(1,@ID,174812,0,0,15,0,3592,0,0,0,0,0,'','Item drops for leather wearer'),
(1,@ID,174812,0,0,47,0,58904,64,0,1,0,0,'','Item drops if quest 58904 is not rewarded'),
(1,@ID,174813,0,0,15,0,4168,0,0,0,0,0,'','Item drops for mail wearer'),
(1,@ID,174813,0,0,47,0,58904,64,0,1,0,0,'','Item drops if quest 58904 is not rewarded'),
(1,@ID,174814,0,0,15,0,35,0,0,0,0,0,'','Item drops for plate wearer'),
(1,@ID,174814,0,0,47,0,58904,64,0,1,0,0,'','Item drops if quest 58904 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=58904;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(58904,2,1,1,1,1024, '[Hidden Tracker] Quilboar Briarpatch Chestpiece Dropped');

-- Loot for Geolord Grek'og
SET @ID := 150237;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,771,0,100,0,1,0,1,1,'Geolord Grek''og - Chipped Boar Tusk');

-- Loot for Ogre Overseer
SET @ID := 156676;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,11847,0,100,0,1,0,1,1,'Ogre Overseer - Battered Cloak'),
(@ID,174790,0,100,0,1,1,1,1,'Ogre Overseer - Overseer''s Mandate');

-- Conditions for loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,11847,0,0,47,0,56051,64,0,1,0,0,'','Item drops if quest 56051 is not rewarded'),
(1,@ID,174790,0,0,47,0,56051,64,0,1,0,0,'','Item drops if quest 56051 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=56051;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(56051,2,1,1,1,1024, '[Hidden Tracker] Ogre Overseer Briarpatch Cloak/Mandate Dropped');
