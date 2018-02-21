--
SET @CGUID := 97946;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-(@CGUID+14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+14), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 44886, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Abdul Relay - Out of Combat - Cast 'Storm's Fury Staff'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44886;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 44886, 0, 0, 31, 0, 3, 24902, 0, 0, 0, 0, "", "Spell Storm's Fury Staff hits Abdul Relay");

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0 , 24902, 571, 0, 0, 1, 0, 0, 0, 510.8039, -3532.589, 28.1855, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+1 , 24902, 571, 0, 0, 1, 0, 0, 0, 535.8403, -3536.107, 2.473374, 0.5759587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+2 , 24902, 571, 0, 0, 1, 0, 0, 0, 512.513, -3522.554, 40.32723, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+3 , 24902, 571, 0, 0, 1, 0, 0, 0, 514.409, -3533.298, 20.05545, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+4 , 24902, 571, 0, 0, 1, 0, 0, 0, 514.2958, -3521.107, 29.82574, 4.904375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+5 , 24902, 571, 0, 0, 1, 0, 0, 0, 527.897, -3537.73, 14.98895, 4.101524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+6 , 24902, 571, 0, 0, 1, 0, 0, 0, 539.5877, -3539.771, 34.46379, 4.852015, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+7 , 24902, 571, 0, 0, 1, 0, 0, 0, 547.0693, -3542.579, 6.492011, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+8 , 24902, 571, 0, 0, 1, 0, 0, 0, 512.8201, -3538.38, 14.82322, 3.944444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+9 , 24902, 571, 0, 0, 1, 0, 0, 0, 507.9665, -3525.262, 9.635133, 0.2617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+10, 24902, 571, 0, 0, 1, 0, 0, 0, 542.0742, -3540.15, 25.22961, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+11, 24902, 571, 0, 0, 1, 0, 0, 0, 533.3746, -3540.956, 9.142557, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+12, 24902, 571, 0, 0, 1, 0, 0, 0, 544.321, -3534.353, 26.10088, 5.689773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+13, 24902, 571, 0, 0, 1, 0, 0, 0, 503.9806, -3535.368, 15.09825, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+14, 24902, 571, 0, 0, 1, 0, 0, 0, 502.7896, -3529.978, 1.876146, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+15, 24902, 571, 0, 0, 1, 0, 0, 0, 526.3058, -3531.612, 9.310692, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+16, 24902, 571, 0, 0, 1, 0, 0, 0, 540.0841, -3546.888, 18.9302, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+17, 24902, 571, 0, 0, 1, 0, 0, 0, 507.8998, -3537.92, 37.27644, 5.462881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+18, 24902, 571, 0, 0, 1, 0, 0, 0, 544.1791, -3536.342, 18.80007, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+19, 24902, 571, 0, 0, 1, 0, 0, 0, 518.9478, -3528.174, 2.6956, 0.5061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(@CGUID+20, 24902, 571, 0, 0, 1, 0, 0, 0, 507.2344, -3540.39, 17.92135, 1.151917, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340);
