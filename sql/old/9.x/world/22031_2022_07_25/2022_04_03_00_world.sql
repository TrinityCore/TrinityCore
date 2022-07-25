SET @CGUID := 1050924;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 184487, 2374, 13536, 13632, '0', 17744, 0, 0, 0, -4254.1025390625, 731.263916015625, -44.8352813720703125, 5.948270320892333984, 7200, 0, 0, 29887, 0, 0, 0, 0, 0, 42979), -- E'rnee (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 184486, 2374, 13536, 13632, '0', 17744, 0, 0, 0, -4254.3662109375, 729.55902099609375, -45.0961418151855468, 0.124879881739616394, 7200, 0, 0, 29887, 0, 0, 0, 0, 0, 42979); -- Tamra (Area: -Unknown- - Difficulty: 0)

-- Creature Template
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=184486; -- Tamra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=184487; -- E'rnee

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=65064;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(65064, 669, 0, 0, 0, 0, 0, 0, 0, 42979); -- Look Who I Found!

DELETE FROM `creature_queststarter` WHERE (`id`=184486 AND `quest`=65064);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(184486, 65064); -- Look Who I Found! offered Tamra

DELETE FROM `creature_questender` WHERE (`id`=182346 AND `quest`=65064);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(182346, 65064);

DELETE FROM `phase_name` WHERE `ID` = 17744;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(17744, 'Zereth Mortis Haven Tamra & E''rnee');
