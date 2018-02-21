/* creature */
SET @CGUID := 251569; -- Set necessary
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0,42560,0,40,109,1,169,0,0,0,-9855.52,1277.67,40.8733,5.64321,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+1,42403,0,40,109,1,169,0,0,0,-9854.61,1277.01,40.8672,5.54896,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+2,42386,0,40,109,1,169,0,32826,0,-9859.24,1279.61,41.0337,5.58039,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+3,42384,0,40,109,1,169,0,32819,0,-9861.03,1276.97,40.7707,0.110977,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+4,42384,0,40,109,1,169,0,32818,0,-9851.09,1273.94,41.0974,2.4279,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+5,42559,0,40,109,1,169,0,0,0,-9852.11,1274.83,41.0164,5.54593,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+6,42559,0,40,109,1,169,0,0,0,-9859.83,1276.11,40.7818,2.44651,120,0,0,0,0,0,0,0,0,'',18019),
(@CGUID+7,42558,0,40,109,1,169,0,0,0,-9854.99,1275.83,40.9068,1.43605,120,0,0,2865,0,0,0,0,0,'',18019);

UPDATE `creature` SET `spawndist` = 3 , `MovementType` = 1 WHERE `guid` = 276241;
UPDATE `creature` SET `spawndist` = 3 , `MovementType` = 1 WHERE `guid` = 276239;
UPDATE `creature` SET `spawndist` = 3 , `MovementType` = 1 WHERE `guid` = 276262;
UPDATE `creature` SET `spawndist` = 3 , `MovementType` = 1 WHERE `guid` = 276256;

/* creature addon */
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0,0,0,65536,0,0,0,0,0,29266),
(@CGUID+2,0,0,0,0,430,0,0,0,NULL),
(@CGUID+3,0,0,0,0,430,0,0,0,NULL),
(@CGUID+4,0,0,0,0,430,0,0,0,NULL),
(@CGUID+7,0,0,8,0,0,0,0,0,NULL);

DELETE FROM `creature_addon` WHERE `guid` IN (349939, 349940, 349978, 349979, 349980, 349981, 349982, 349983);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(349939,0,0,0,1,333,0,0,0,NULL),
(349940,0,0,0,1,333,0,0,0,NULL),
(349978,0,0,0,1,333,0,0,0,NULL),
(349979,0,0,0,1,333,0,0,0,NULL),
(349980,0,0,0,1,333,0,0,0,NULL),
(349981,0,0,0,1,333,0,0,0,NULL),
(349982,0,0,0,1,333,0,0,0,NULL),
(349983,0,0,0,1,333,0,0,0,NULL);

/* quest template addon */
DELETE FROM `quest_template_addon` WHERE `ID` IN (26209, 26213, 26214, 26215, 26229, 26230, 26241, 26270, 26237, 26286, 26289, 26292, 26287, 26236, 26266);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(26209,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
(26215,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
(26213,0,0,0,26209,26215,-26213,0,0,0,0,0,0,0,0,0,0),
(26214,0,0,0,26209,26215,-26213,0,0,0,0,0,0,0,0,0,0),
(26229,0,0,0,26215,0,0,0,0,0,0,0,0,0,0,0,0),
(26230,0,0,0,26215,0,0,0,0,0,0,0,0,0,0,0,0),
(26241,0,0,0,26236,0,0,0,0,0,0,0,0,0,0,0,0),
(26270,0,0,0,26241,0,0,0,0,0,0,0,0,0,0,0,0),
(26237,0,0,0,26236,0,0,0,0,0,0,0,0,0,0,0,0),
(26286,0,0,0,26266,0,0,0,0,0,0,0,0,0,0,0,0),
(26289,0,0,0,26286,0,0,0,0,0,0,0,0,0,0,0,0),
(26292,0,0,0,26291,0,0,0,0,0,0,0,0,0,0,0,0),
(26287,0,0,0,26266,0,0,0,0,0,0,0,0,0,0,0,0),
(26236,0,0,0,26232,0,0,0,0,0,0,0,0,0,0,0,0),
(26266,0,0,0,26270,0,0,0,0,0,0,0,0,0,0,1,0);

/* creature loot template */
DELETE FROM `creature_loot_template` WHERE `Entry`=114 AND `Item`=57935;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(114,57935,0,8.75,0,1,0,1,1,NULL);
UPDATE `creature_loot_template` SET `QuestRequired` = 1 WHERE `Entry` = 42677 AND `Item` = 58118;
