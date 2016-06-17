SET @OGUID:=6362;
SET @CGUID:=78301;
SET @Event:=2;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 180796, 0, 1, 1, -3826.189, -771.3663, 8.083211, 2.146753, 0, 0, 0, 1, 120, 255, 1), -- 180796 (Area: 150)
(@OGUID+1, 180797, 0, 1, 1, -3825.66, -770.9445, 8.083211, 5.270896, 0, 0, 0, 1, 120, 255, 1), -- 180797 (Area: 150)
(@OGUID+2, 178746, 0, 1, 1, -3822.936, -769.4861, 8.083211, 1.518436, 0, 0, 0, 1, 120, 255, 1); -- 178746 (Area: 150)

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2 AND `eventEntry`=@Event;
INSERT INTO `game_event_gameobject` SELECT @Event, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+2;

-- Add spawns Pat's Snowcloud Guy & Wonderform Operator <Smokywood Pastures>
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUES 
(@CGUID+0, 15730, 0, 2051.343, 272.4555, 57.25123, 0, 120, 0), -- 15730 (Area: 159) (Auras: 26000 - 26000)
(@CGUID+1, 15730, 0, 2051.359, 272.4567, 57.25214, 0, 120, 0), -- 15730 (Area: 159) (Auras: 26000 - 26000)
(@CGUID+2, 15730, 0, -5049.26, -818.5426, 495.3753, 0, 120, 0), -- 15730 (Area: 809) (Auras: 26000 - 26000)
(@CGUID+3, 15730, 0, -5049.293, -818.5344, 495.3785, 0, 120, 0), -- 15730 (Area: 809) (Auras: 26000 - 26000)
(@CGUID+4, 15730, 0, -8823.889, 540.5417, 96.89484, 5.951573, 120, 0), -- 15730 (Area: 5148) (Auras: 26000 - 26000)
(@CGUID+5, 15730, 0, -8823.89, 540.528, 96.89533, 2.443461, 120, 0), -- 15730 (Area: 5148) (Auras: 26000 - 26000)
(@CGUID+6, 15730, 0, -14294.22, 516.1476, 9.037167, 5.340707, 120, 0), -- 15730 (Area: 35) (Auras: 26000 - 26000)
(@CGUID+7, 15730, 0, -14294.3, 516.146, 9.037253, 1.815142, 120, 0), -- 15730 (Area: 35) (Auras: 26000 - 26000)
(@CGUID+8, 15730, 0, -3826.132, -771.75, 8.083211, 0.1396263, 120, 0), -- 15730 (Area: 150) (Auras: 26000 - 26000)
(@CGUID+9, 15730, 0, -3826.108, -771.7864, 8.083211, 3.665191, 120, 0), -- 15730 (Area: 150) (Auras: 26000 - 26000)
(@CGUID+10, 15732, 0, -3821.368, -768.9375, 8.083211, 1.745329, 120, 0); -- 15732 (Area: 150)

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10 AND `eventEntry`=@Event;
INSERT INTO `game_event_creature` SELECT @Event, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+10;

