SET @CGUID := 396707;
SET @OGUID := 253206;
SET @EVENT := 52;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=15746; -- Great-father Winter's Helper

DELETE FROM `creature_template_addon` WHERE `entry`=15746;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(15746, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 15746 (Great-father Winter's Helper)

DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=1 AND `Entry`=15746;

-- Quests
DELETE FROM `quest_poi` WHERE (`QuestID`=6962 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=6962 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(6962, 0, 1, 32, 0, 0, 1, 85, 0, 0, 0, 0, 0, 109268, 0, 47213), -- Treats for Great-father Winter
(6962, 0, 0, -1, 0, 0, 1, 85, 0, 1, 0, 0, 0, 0, 0, 47213); -- Treats for Great-father Winter

UPDATE `quest_offer_reward` SET `VerifiedBuild`=47213 WHERE `ID` IN (6964, 6961);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `RewardText`='Oh, ho hello there! You can only be here for one reason: to open your Winter Veil presents.$b$bNow, don''t you worry, Great-father Winter hasn''t forgotten about his favorite $r $c. Look under the tree and you''ll find your gifts.$b$bDuring this season of giving, perhaps your friends would also enjoy receiving some of Smokywood Pastures'' excellent products?', `VerifiedBuild`=47213 WHERE `ID`=8828; -- Winter's Presents
UPDATE `quest_offer_reward` SET `RewardText`='You''re quite the helper to ol'' Great-father Winter there, $n.  Have a great Feast of Winter Veil.$B$BHere''s a little something... you know, for the effort.', `VerifiedBuild`=47213 WHERE `ID`=6962; -- Treats for Great-father Winter

UPDATE `creature_questender` SET `VerifiedBuild`=47213 WHERE (`id`=13445 AND `quest` IN (8828,6962)) OR (`id`=13417 AND `quest`=6964);

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 15746, 1, 1637, 5170, '0', 0, 0, 0, 0, 1572.1336669921875, -4369.05224609375, 19.89780616760253906, 4.328416347503662109, 120, 0, 0, 118565, 0, 0, 0, 0, 0, 47213); -- Great-father Winter's Helper (Area: Valley of Strength - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180743, 1, 1637, 5170, '0', 0, 0, 1573.314208984375, -4367.90087890625, 20.13355636596679687, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 47213), -- Carefully Wrapped Present (Area: Valley of Strength - Difficulty: 0)
(@OGUID+1, 180746, 1, 1637, 5170, '0', 0, 0, 1574.9010009765625, -4365.375, 20.49316215515136718, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 47213), -- Gently Shaken Gift (Area: Valley of Strength - Difficulty: 0)
(@OGUID+2, 180747, 1, 1637, 5170, '0', 0, 0, 1574.7899169921875, -4371.5224609375, 20.02180862426757812, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 47213), -- Gaily Wrapped Present (Area: Valley of Strength - Difficulty: 0)
(@OGUID+3, 180748, 1, 1637, 5170, '0', 0, 0, 1578.1771240234375, -4365.37841796875, 20.69092750549316406, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 120, 255, 1, 47213), -- Ticking Present (Area: Valley of Strength - Difficulty: 0)
(@OGUID+4, 180793, 1, 1637, 5170, '0', 0, 0, 1578.4617919921875, -4372.29345703125, 20.30743980407714843, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 47213), -- Festive Gift (Area: Valley of Strength - Difficulty: 0)
(@OGUID+5, 187236, 1, 1637, 5170, '0', 0, 0, 1580.642333984375, -4369.59033203125, 20.9252777099609375, 0.014022941701114177, 0, 0, 0.00701141357421875, 0.999975383281707763, 120, 255, 1, 47213); -- Winter Veil Gift (Area: Valley of Strength - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5);
