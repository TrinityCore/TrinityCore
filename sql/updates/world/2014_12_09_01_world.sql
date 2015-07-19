SET @CGUID := 75045;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18 AND `id` IN(31328,31330,31310,31313);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 31328, 571, 1, 2,4897.725, 1335.234, 231.006, 5.068347, 120, 0, 0), -- 31328 (Area: 4171)
(@CGUID+1, 31330, 571, 1, 2,4939.318, 1323.521, 235.045, 4.453136, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+2, 31313, 571, 1, 2,4664.651, 1447.415, 170.8568, 3.301515, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+3, 31310, 571, 1, 2,4702.17, 1552.966, 249.4346, 2.188437, 120, 5, 1), -- 31310 (Area: 4171) (possible waypoints or random movement)
(@CGUID+4, 31313, 571, 1, 2,4702.964, 1557.946, 247.5312, 1.604996, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+5, 31310, 571, 1, 2,4648.25, 1422.38, 170.9548, 1.993341, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+6, 31330, 571, 1, 2,4806.307, 1318.516, 168.6461, 1.844061, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+7, 31328, 571, 1, 2,4793.399, 1329.59, 170.9456, 2.494735, 120, 0, 0), -- 31328 (Area: 4171)
(@CGUID+8, 31330, 571, 1, 2,4800.977, 1323.843, 170.5469, 2.492624, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+9, 31330, 571, 1, 2,4928.894, 1297.723, 230.3787, 4.188883, 120, 5, 1), -- 31330 (Area: 4171) (possible waypoints or random movement)
(@CGUID+10, 31330, 571, 1, 2,4901.572, 1317.947, 229.5681, 5.172978, 120, 5, 1), -- 31330 (Area: 4171) (possible waypoints or random movement)
(@CGUID+11, 31330, 571, 1, 2,4897.755, 1335.152, 231.0011, 5.068347, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+12, 31310, 571, 1, 2,4701.083, 1410.821, 172.1171, 4.542583, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+13, 31310, 571, 1, 2,4714.932, 1432.092, 174.4268, 5.404375, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+14, 31330, 571, 1, 2,4767.026, 1300.882, 159.1799, 3.967742, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+15, 31330, 571, 1, 2,4783.351, 1313.886, 165.2287, 3.801694, 120, 0, 0), -- 31330 (Area: 4171)
(@CGUID+16, 31310, 571, 1, 2,4726.307, 1305.983, 152.4278, 4.304676, 120, 0, 0), -- 31310 (Area: 4171)
(@CGUID+17, 31313, 571, 1, 2,4709.668, 1412.268, 174.0422, 5.927182, 120, 0, 0), -- 31313 (Area: 4171)
(@CGUID+18, 31310, 571, 1, 2,4709.66, 1415.296, 174.3237, 5.371386, 120, 0, 0); -- 31310 (Area: 4171)

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(31310,31313,31328,31330);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(31310,31313,31328,31330)  AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(3131000,3131001,3131002,3131003,3131004,3131005,3131006,3131007,3131008)  AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31313,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Run On'),
(31313,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Random Movement'),
(31313,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31313,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131005,3131006,3131007,3131008,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - OOC - Run Random Script'),
(31330,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Run On'),
(31330,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Random Movement'),
(31330,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31330,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131005,3131006,3131007,3131008,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - OOC - Run Random Script'),
(31310,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Run On'),
(31310,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Set Random Movement'),
(31310,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31310,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131000,3131001,3131002,3131003,3131004,0,1,0,0,0,0,0,0,0,'Fleeing Alliance Soldier - OOC - Run Random Script'),
(31328,0,0,1,11,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Run On'),
(31328,0,1,2,61,0,100,0,0,0,0,0,89,30,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Set Random Movement'),
(31328,0,2,0,61,0,100,0,0,0,0,0,11,52385,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - On Spawn - Cast Cosmetic - Periodic Cower'),
(31328,0,3,0,1,0,100,0,0,3000,1000,3000,87,3131000,3131001,3131002,3131003,3131004,0,1,0,0,0,0,0,0,0,'Fleeing Horde Soldier - OOC - Run Random Script'),

(3131000,9,0,0,0,0,100,0,0,0,0,0,4,14994,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 1 - Play Sound 14994'),
(3131001,9,0,0,0,0,100,0,0,0,0,0,4,14991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 2 - Play Sound 14991'),
(3131002,9,0,0,0,0,100,0,0,0,0,0,4,14993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 3 - Play Sound 14993'),
(3131003,9,0,0,0,0,100,0,0,0,0,0,4,14992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 4 - Play Sound 14992'),
(3131004,9,0,0,0,0,100,0,0,0,0,0,4,15005,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 5 - Play Sound 15005'),
(3131005,9,0,0,0,0,100,0,0,0,0,0,4,14990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 6 - Play Sound 14990'),
(3131006,9,0,0,0,0,100,0,0,0,0,0,4,14988,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 7 - Play Sound 14988'),
(3131007,9,0,0,0,0,100,0,0,0,0,0,4,14989,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 8 - Play Sound 14989'),
(3131008,9,0,0,0,0,100,0,0,0,0,0,4,14987,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fleeing Soldier - Script 9 - Play Sound 14987');
