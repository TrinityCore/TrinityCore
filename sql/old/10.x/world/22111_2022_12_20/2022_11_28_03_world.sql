SET @CGUID := 651836;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 107407, 1220, 7334, 7360, '0', 6893, 0, 0, 0, 465.526031494140625, 6507.27685546875, 39.24222183227539062, 0.166833728551864624, 120, 0, 0, 5647, 0, 0, 0, 0, 0, 46702), -- Haterunner (Area: Llothien Highlands - Difficulty: 0)
(@CGUID+1, 106914, 1220, 7334, 7360, '0', 6893, 0, 0, 0, 453.4600830078125, 6509.20751953125, 40.34196090698242187, 5.556643962860107421, 120, 0, 0, 22590, 3801, 0, 0, 0, 0, 46702), -- Tehd Shoemaker (Area: Llothien Highlands - Difficulty: 0) (Auras: 79934 - Demon Armor)
(@CGUID+2, 106915, 1220, 7334, 7360, '0', 6893, 0, 0, 1, 455.854156494140625, 6505.94970703125, 40.3865203857421875, 2.510084152221679687, 120, 0, 0, 28235, 0, 0, 0, 0, 0, 46702); -- Marius Felbane (Area: Llothien Highlands - Difficulty: 0) (Auras: 42459 - Dual Wield)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '42459'); -- Marius Felbane - 42459 - Dual Wield

UPDATE `creature_template` SET `gossip_menu_id`=19649, `VerifiedBuild`=46702 WHERE `entry`=106915; -- Marius Felbane
UPDATE `creature_template` SET `gossip_menu_id`=19648, `AIName`= 'SmartAI', `VerifiedBuild`=46702 WHERE `entry`=106914; -- Tehd Shoemaker

DELETE FROM `creature_queststarter` WHERE (`id`=106914 AND `quest`=42238) OR (`id`=106915 AND `quest`=42372);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(106914, 42238, 46702), -- Missing Demon offered Tehd Shoemaker
(106915, 42372, 46702); -- Felblaze Ingress offered Marius Felbane

UPDATE `quest_poi` SET `VerifiedBuild`=46702 WHERE (`QuestID`=42238 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42238 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42372 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42372 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46702 WHERE (`QuestID`=42238 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42238 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42372 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42372 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=46702 WHERE `ID` IN (42238, 42372);

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46702 WHERE `ID`=42372;
UPDATE `creature_questender` SET `VerifiedBuild`=46702 WHERE (`id`=107244 AND `quest`=42372);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 6893;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6893, 'Cosmetic - See Haterunner, Tehd Shoemaker and Marius Felbane at Llothien Highlands');

DELETE FROM `phase_area` WHERE `AreaId` IN (7340, 7360) AND `PhaseId` = 6893;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7360, 6893, 'See Haterunner, Tehd Shoemaker and Marius Felbane at Llothien Highlands'),
(7340, 6893, 'See Haterunner, Tehd Shoemaker and Marius Felbane at Llothien Highlands');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 6893 AND `SourceEntry` IN (7360, 7340);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 6893, 7360, 0, 0, 47, 0, 42372, 64, 0, 1, 'Apply Phase 6893 if Quest 42372 is not rewarded'),
(26, 6893, 7340, 0, 0, 47, 0, 42372, 64, 0, 1, 'Apply Phase 6893 if Quest 42372 is not rewarded');

DELETE FROM `smart_scripts` WHERE `entryorguid`=106914 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(106914, 0, 1, 0, 1, 0, 100, 0, 0, 0, 1860000, 2100000, 0, '', 11, 79934, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tehd Shoemaker - OOC beweteen - Cast Demon Armor');
