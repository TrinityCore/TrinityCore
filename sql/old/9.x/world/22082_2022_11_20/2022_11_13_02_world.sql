SET @CGUID := 651626;
SET @PATH := (@CGUID+0) * 10;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 91166, 1220, 7334, 7571, '0', 4517, 0, 0, 0, -448.9392, 5728.049, 35.15217, 1.336238861083984375, 120, 0, 0, 3138, 3801, 2, 0, 0, 0, 46597); -- Daglop (Area: Olivian Veil - Difficulty: 0) (Auras: 180986 - Phase Shift)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, @PATH, 0, 0, 1, 0, 0, 0, 0, 0, '180986'); -- Daglop - 180986 - Phase Shift

DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -448.9392, 5728.049, 35.15217, 0),
(@PATH, 1, -449.1962, 5745.663, 34.99242, 0),
(@PATH, 2, -440.3767, 5755.994, 37.45763, 0),
(@PATH, 3, -438.3281, 5766.583, 39.31371, 0),
(@PATH, 4, -436.6059, 5775.816, 39.49709, 0),
(@PATH, 5, -430.7379, 5785.602, 40.14935, 0),
(@PATH, 6, -423.4653, 5794.808, 40.39935, 0),
(@PATH, 7, -421.5833, 5805.992, 40.70333, 0),
(@PATH, 8, -423.4653, 5794.808, 40.39935, 0),
(@PATH, 9, -430.7379, 5785.602, 40.14935, 0),
(@PATH, 10, -436.6059, 5775.816, 39.49709, 0),
(@PATH, 11, -438.3281, 5766.583, 39.31371, 0),
(@PATH, 12, -440.3767, 5755.994, 37.45763, 0),
(@PATH, 13, -449.1962, 5745.663, 34.99242, 0),
(@PATH, 14, -448.9392, 5728.049, 35.15217, 0),
(@PATH, 15, -452.3142, 5713.975, 34.36396, 0),
(@PATH, 16, -451.7708, 5706.871, 34.14607, 0),
(@PATH, 17, -454.382, 5691.95, 31.50987, 0),
(@PATH, 18, -454.1389, 5675.167, 31.05491, 0),
(@PATH, 19, -452.6806, 5665.479, 30.8032, 0),
(@PATH, 20, -450.9496, 5655.935, 30.43857, 0),
(@PATH, 21, -452.6806, 5665.479, 30.8032, 0),
(@PATH, 22, -454.1389, 5675.167, 31.05491, 0),
(@PATH, 23, -454.382, 5691.95, 31.50987, 0),
(@PATH, 24, -451.8047, 5706.729, 34.15913, 0),
(@PATH, 25, -452.3142, 5713.975, 34.36396, 0);

DELETE FROM `creature_queststarter` WHERE (`id`=91166 AND `quest` IN (38232,38460));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(91166, 38232, 46597), -- Minion! Kill Them! offered Daglop
(91166, 38460, 46597); -- Let's Make A Deal offered Daglop

UPDATE `creature_questender` SET `VerifiedBuild`=46597 WHERE (`id`=91166 AND `quest`=38460);
UPDATE `creature_template` SET `gossip_menu_id`=18348, `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46597 WHERE `entry`=91166; -- Daglop

UPDATE `quest_poi_points` SET `VerifiedBuild`=46597 WHERE (`QuestID`=38232 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=7) OR
(`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=2) OR
(`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=38232 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=3) OR 
(`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=38232 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=7) OR
(`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=2) OR
(`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=38232 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38232 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38232 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=38460 AND `Idx1`=2 AND `Idx2`=0) OR
(`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=7) OR
(`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=2) OR
(`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=38460 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38460 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_poi` SET `VerifiedBuild`=46597 WHERE (`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=2) OR
(`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38232 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=38460 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38460 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38460 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_details` SET `VerifiedBuild`=46597 WHERE `ID` IN (38232, 38460);

UPDATE `quest_template` SET `VerifiedBuild`=46597 WHERE `ID`=38232; -- Minion! Kill Them!
UPDATE `quest_template` SET `VerifiedBuild`=46597 WHERE `ID`=38460; -- Let's Make A Deal

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46597 WHERE `ID`=38460;

DELETE FROM `phase_name` WHERE `ID` = 4517;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4517, 'Cosmetic - See Daglop at Olivian Veil');

DELETE FROM `phase_area` WHERE `AreaId` IN (7571, 7633, 7554) AND `PhaseId` = 4517;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7571, 4517, 'See Daglop at Olivian Veil'), -- Olivian Veil
(7633, 4517, 'See Daglop at Olivian Veil'), -- The Ruined Sanctum
(7554, 4517, 'See Daglop at Olivian Veil'); -- Garden of Elune

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4517 AND `SourceEntry` IN (7571, 7633, 7554));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4517, 7571, 0, 0, 47, 0, 38232, 8 | 2 | 64, 0, 1, 'Apply Phase 4517 if Quest 38232 is completed | rewarded'),
(26, 4517, 7571, 0, 1, 47, 0, 38237, 2 | 64, 0, 0, 'Apply Phase 4517 if Quest 38237 is completed | rewarded'),
(26, 4517, 7633, 0, 0, 47, 0, 38232, 8 | 2 | 64, 0, 1, 'Apply Phase 4517 if Quest 38232 is completed | rewarded'),
(26, 4517, 7633, 0, 1, 47, 0, 38237, 2 | 64, 0, 0, 'Apply Phase 4517 if Quest 38237 is completed | rewarded'),
(26, 4517, 7554, 0, 0, 47, 0, 38232, 8 | 2 | 64, 0, 1, 'Apply Phase 4517 if Quest 38232 is completed | rewarded'),
(26, 4517, 7554, 0, 1, 47, 0, 38237, 2 | 64, 0, 0, 'Apply Phase 4517 if Quest 38237 is completed | rewarded');
