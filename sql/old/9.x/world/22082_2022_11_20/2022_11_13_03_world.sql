SET @CGUID := 651627;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 201.34375, 6427.70068359375, -52.8035430908203125, 1.627967476844787597, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+1, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 178.296875, 6429.00439453125, -53.117218017578125, 5.730798721313476562, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+2, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 169.59722900390625, 6457.39501953125, -53.1121978759765625, 4.720047473907470703, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+3, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 223.828125, 6430.56689453125, -53.1133956909179687, 3.89932107925415039, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+4, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 195.4791717529296875, 6464.32470703125, -53.694488525390625, 5.199088096618652343, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+5, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 189.5052032470703125, 6448.7275390625, -53.694488525390625, 0.208793431520462036, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+6, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 212.17535400390625, 6430.4462890625, -52.8035430908203125, 2.148544073104858398, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+7, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 180.765625, 6463.3125, -52.8041915893554687, 5.776860237121582031, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547), -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)
(@CGUID+8, 107279, 1220, 7334, 7358, '0', 6496, 0, 0, 0, 177.0434112548828125, 6450.49853515625, -52.8036956787109375, 0.040167924016714096, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46547); -- Wand Target (Area: Nar'thalas Academy - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+1, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+2, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+3, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+4, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+5, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+6, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+7, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- Wand Target
(@CGUID+8, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''); -- Wand Target

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048, `unit_flags3`=1, `VerifiedBuild`=46547 WHERE `entry`=107279; -- Wand Target

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46547 WHERE `ID` = 42370;

UPDATE `quest_poi` SET `VerifiedBuild`=46547 WHERE (`QuestID`=42370 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=42370 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42370 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46547 WHERE (`QuestID`=42370 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=42370 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42370 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=46547 WHERE `ID` = 42370;

DELETE FROM `creature_queststarter` WHERE (`id`=89661 AND `quest`=42370);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(89661, 42370, 46547); -- Wanding 101 offered Instructor Nidriel

UPDATE `creature_questender` SET `VerifiedBuild`=46547 WHERE `id`=89661 AND `quest` = 42370;

UPDATE `quest_template` SET `VerifiedBuild`=46547 WHERE `ID`=42370; -- Wanding 101

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 6496;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(6496, 'Cosmetic - See Wand Target at Nar\'thalas Academy');

DELETE FROM `phase_area` WHERE `AreaId` = 7358 AND `PhaseId` = 6496;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7358, 6496, 'See Wand Target at Nar\'thalas Academy');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 6496 AND `SourceEntry` = 7358);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 6496, 7358, 0, 0, 47, 0, 42370, 8, 0, 0, 'Apply Phase 6496 if Quest 42370 is in progress');
