SET @EVENTID := 89;
SET @CGUID := 10800000;

DELETE FROM `game_event` WHERE `eventEntry`=@EVENTID+0;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `holidayStage`, `description`, `world_event`, `announce`) VALUES 
(@EVENTID+0, '2024-10-23 06:00:00', '2025-01-08 06:00:00', 525600, 10080, 0, 0, 'WoW''s 20th Anniversary', 0, 2);

DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENTID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENTID+0, @CGUID+0),
(@EVENTID+0, @CGUID+1);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 167749, 1, 1519, 10523, '0', 0, 0, 0, 0, -8457.6806640625, -4500.56982421875, 8.886342048645019531, 2.302304744720458984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Doomwalker (Area: Wizard's Sanctum - Difficulty: 0) CreateObject1
(@CGUID+1, 121818, 0, 41, 0, 0, '0', 3146, 0, 1, -11781.095703125, -2378.037109375, -6.59761428833007812, 4.975621223449707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Lord Kazzak (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )

SET @ENTRY := 167749;
SET @PATH := @ENTRY * 100;
UPDATE `creature` SET `position_x`= -8502.323, `position_y`= -4474.172, `position_z`= 11.24166, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- 167749 (Doomwalker)
