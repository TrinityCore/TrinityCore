DELETE FROM `game_event` WHERE `eventEntry`=70;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`, `announce`) VALUES
(70, '2016-09-20 01:01:00', '2020-12-31 06:00:00', 525600, 4320, 0, 'Brewfest Building (Iron Forge)', 0, 2);

SET @OGUID:=66860;
SET @Event:=70;

-- Add missing objects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 186737, 0, 1, 1, -5188.76, -594.4157, 397.1762, -1.186823, 0, 0, -0.5591927, 0.8290377, 120, 255, 1, 12340), -- 186737 (Area: 0)
(@OGUID+1, 186737, 0, 1, 1, -5140.782, -578.3196, 397.1762, -2.35619, 0, 0, -0.9238787, 0.3826855, 120, 255, 1, 12340), -- 186737 (Area: 0)
(@OGUID+2, 186737, 0, 1, 1, -5155.752, -635.502, 397.1766, 1.797689, 0, 0, 0.782608, 0.6225148, 120, 255, 1, 12340), -- 186737 (Area: 0)
(@OGUID+3, 186717, 0, 1, 1, -5209.837, -459.3629, 386.537, 2.565632, 0, 0, 0.9588194, 0.2840165, 120, 255, 1, 12340), -- 186717 (Area: 0)
(@OGUID+4, 186717, 0, 1, 1, -5226.539, -479.0257, 386.5343, 2.234018, 0, 0, 0.8987932, 0.4383728, 120, 255, 1, 12340), -- 186717 (Area: 0)
(@OGUID+5, 186717, 0, 1, 1, -5233.375, -482.2638, 386.337, 1.919862, 0, 0, 0.8191519, 0.5735767, 120, 255, 1, 12340), -- 186717 (Area: 0)
(@OGUID+6, 186717, 0, 1, 1, -5206.924, -452.2431, 386.8079, 3.019413, 0, 0, 0.9981346, 0.06105176, 120, 255, 1, 12340), -- 186717 (Area: 0)
(@OGUID+7, 180052, 0, 1, 1, -5175.3, -625.1653, 397.1762, 2.91469, 0, 0, 0.9935713, 0.1132084, 120, 255, 1, 12340), -- 180052 (Area: 0)
(@OGUID+8, 186217, 0, 1, 1, -5208.209, -456.0722, 386.7465, 2.705255, 0, 0, 0.9762955, 0.2164421, 120, 255, 1, 12340), -- 186217 (Area: 0)
(@OGUID+9, 186217, 0, 1, 1, -5230.03, -480.2934, 386.3998, 2.129301, 0, 0, 0.8746195, 0.4848101, 120, 255, 1, 12340), -- 186217 (Area: 0)
(@OGUID+10, 180026, 0, 1, 1, -5208.103, -455.9601, 386.5149, -2.984498, 0, 0, -0.9969168, 0.07846643, 120, 255, 1, 12340), -- 180026 (Area: 0)
(@OGUID+11, 180026, 0, 1, 1, -5229.858, -480.2882, 386.3633, 2.687807, 0, 0, 0.97437, 0.2249513, 120, 255, 1, 12340); -- 180026 (Area: 0)

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11 AND `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` SELECT @Event, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+11;
