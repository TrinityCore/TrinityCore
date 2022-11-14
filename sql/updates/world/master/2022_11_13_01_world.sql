SET @CGUID := 651620;
SET @OGUID := 400487;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 106990, 1220, 7334, 7345, '0', 0, 0, 0, 1, -694.20489501953125, 5504.994140625, -10.7102737426757812, 4.375872611999511718, 120, 0, 0, 15692, 0, 0, 0, 0, 0, 46597), -- Chief Bitterbrine (Area: Mak'rana - Difficulty: 0)
(@CGUID+1, 89284, 1220, 7334, 7345, '0', 0, 0, 0, 1, -671.515625, 5526.671875, -7.65567493438720703, 1.821594715118408203, 120, 0, 0, 3923, 1534, 0, 0, 0, 0, 46597), -- Bitterbrine Saltcaster (Area: Mak'rana - Difficulty: 0)
(@CGUID+2, 89283, 1220, 7334, 7345, '0', 0, 0, 0, 1, -691.75347900390625, 5516.6181640625, 7.172315597534179687, 1.078014016151428222, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Bitterbrine Venomer (Area: Mak'rana - Difficulty: 0) (Auras: )
(@CGUID+3, 89284, 1220, 7334, 7345, '0', 0, 0, 0, 1, -678.88543701171875, 5533.77099609375, 4.204445838928222656, 2.053150177001953125, 120, 0, 0, 3923, 1534, 0, 0, 0, 0, 46597), -- Bitterbrine Saltcaster (Area: Mak'rana - Difficulty: 0)
(@CGUID+4, 89283, 1220, 7334, 7345, '0', 0, 0, 0, 1, -682.16839599609375, 5567.0693359375, 1.609409451484680175, 0.244694411754608154, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46597), -- Bitterbrine Venomer (Area: Mak'rana - Difficulty: 0) (Auras: )
(@CGUID+5, 89283, 1220, 7334, 7345, '0', 0, 0, 0, 1, -679.7586669921875, 5567.40966796875, 1.751736164093017578, 3.251716375350952148, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46597); -- Bitterbrine Venomer (Area: Mak'rana - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''), -- Chief Bitterbrine
(@CGUID+1, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Bitterbrine Saltcaster
(@CGUID+2, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Bitterbrine Venomer
(@CGUID+3, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''), -- Bitterbrine Saltcaster
(@CGUID+4, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bitterbrine Venomer
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Bitterbrine Venomer

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=89013; -- Azsuna Lion Seal
UPDATE `creature_template` SET `VerifiedBuild`=46597 WHERE `entry` IN (106990, 89013);

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 239328, 1220, 7334, 7345, '0', 0, 0, -694.9913330078125, 5502.91943359375, -10.4494905471801757, 1.120767593383789062, 0.037332534790039062, 0.0028228759765625, 0.531628608703613281, 0.846149682998657226, 120, 255, 1, 46597); -- Captain's Foot Locker (Area: Mak'rana - Difficulty: 0)

UPDATE `gameobject_template` SET `ContentTuningId`=331, `VerifiedBuild`=46597 WHERE `entry`=239328; -- Captain's Foot Locker
