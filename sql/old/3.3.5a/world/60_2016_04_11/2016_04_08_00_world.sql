SET @CGUID := 78642;

DELETE FROM `creature` WHERE  `id` IN(17417,17418,17404,17405);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 17417, 530, 1, 1, 214.6568, 4122.551, 79.8511, 2.251475, 120, 0, 0), -- 17417 (Area: 0) (possible waypoints or random movement)
(@CGUID+1, 17417, 530, 1, 1, 216.0346, 4125.61, 80.22345, 2.251475, 120, 0, 0), -- 17417 (Area: 0) (possible waypoints or random movement)
(@CGUID+2, 17404, 530, 1, 1, 211.6765, 4126.361, 79.04578, 2.391101, 120, 0, 0), -- 17404 (Area: 0) (possible waypoints or random movement)
(@CGUID+3, 17418, 530, 1, 1, 261.5179, 4106.813, 93.315, 2.663978, 120, 0, 0), -- 17418 (Area: 0)
(@CGUID+4, 17418, 530, 1, 1, 260.6302, 4103.529, 93.33371, 2.60972, 120, 0, 0), -- 17418 (Area: 0)
(@CGUID+5, 17405, 530, 1, 1, 230.5075, 4118.714, 83.56195, 2.949606, 120, 0, 0); -- 17405 (Area: 0) (possible waypoints or random movement)

UPDATE `creature` SET `equipment_id`=1 WHERE `id` IN(17417,17418,17404,17405);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(17413,17417,17404,17418,17405);

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(17413,17417,17404,17418,17405) AND `source_type`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(1740400,1740500) AND `source_type`=9;


DELETE FROM `smart_scripts` WHERE `entryorguid`IN(-@CGUID-0,-@CGUID-1,-@CGUID-2,-@CGUID-3,-@CGUID-4,-@CGUID-5) AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-@CGUID-0, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Respawn - Set Immune'),
(-@CGUID-0, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Respawn - Set Invisible'),
(-@CGUID-0, 0, 1, 2, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Data Set - Set Immune'),
(-@CGUID-0, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Data Set - Set visible'),
(-@CGUID-0, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1741700, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Respawn - Start WP'),
(-@CGUID-0, 0, 4, 5, 40, 0, 100, 0, 2, 1741700, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Reached WP3 - Pause WP'),
(-@CGUID-0, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 11, 30460, 2, 0, 0, 0, 0, 19, 17404, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Reached WP3 - Cast Kick'),
(-@CGUID-0, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 17404, 0, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Reached WP3 - Set Data on Sedei'),
(-@CGUID-0, 0, 7, 8, 40, 0, 100, 0, 5, 1741700, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+3, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (1) - On Reached WP6 - Start Attack'),
(-@CGUID-0, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @CGUID+3, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Reached WP12 - Start Attack'),
(-@CGUID-0, 0, 9, 0, 0, 0, 100, 1, 3000, 3000, 0, 0, 45, 4, 4, 0, 0, 0, 0, 10, @CGUID+3, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (2) - IC - Set Data'),

(-@CGUID-1, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Respawn - Set Immune'),
(-@CGUID-1, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Respawn - Set Invisible'),
(-@CGUID-1, 0, 1, 2, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Data Set - Set Immune'),
(-@CGUID-1, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Data Set - Set visible'),
(-@CGUID-1, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1741701, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Respawn - Start WP'),
(-@CGUID-1, 0, 4, 5, 40, 0, 100, 0, 3, 1741701, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Reached WP9 - Pause WP'),
(-@CGUID-1, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Reached WP9 - Say'),
(-@CGUID-1, 0, 6, 7, 40, 0, 100, 0, 10, 1741701, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, @CGUID+4, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Reached WP12 - Start Attack'),
(-@CGUID-1, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, @CGUID+4, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (2) - On Reached WP12 - Start Attack'),
(-@CGUID-1, 0, 8, 0, 0, 0, 100, 1, 3000, 3000, 0, 0, 45, 4, 4, 0, 0, 0, 0, 10, @CGUID+4, 17418, 0, 0, 0, 0, 0, 'Mag har Escort (2) - IC - Set Data'),

(-@CGUID-2, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Respawn - Set Immune'),
(-@CGUID-2, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Respawn - Set Invisible'),
(-@CGUID-2, 0, 1, 2, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Data Set - Set Immune'),
(-@CGUID-2, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Data Set - Set visible'),
(-@CGUID-2, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 17404, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Respawn - Start WP'),
(-@CGUID-2, 0, 4, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 1740400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Data Set - Run Script'),
(-@CGUID-2, 0, 5, 0, 40, 0, 100, 0, 3, 17404, 0, 0, 54, 21000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Reached WP3 - Pause WP'),
(-@CGUID-2, 0, 6, 0, 40, 0, 100, 0, 5, 17404, 0, 0, 54, 18000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - On Reached WP5 - Pause WP'),

(-@CGUID-3, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (1) - On Respawn - Set Immune'),
(-@CGUID-3, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (1) - On Respawn - Set Invisible'),
(-@CGUID-3, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (1) - On Data Set - Set Immune'),
(-@CGUID-3, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (1) - On Data Set - Set visible'),
(-@CGUID-3, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17417, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (1) - On Data Set - Start Attack'),

(-@CGUID-4, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (2) - On Respawn - Set Immune'),
(-@CGUID-4, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (2) - On Respawn - Set Invisible'),
(-@CGUID-4, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (2) - On Data Set - Set Immune'),
(-@CGUID-4, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (2) - On Data Set - Set visible'),
(-@CGUID-4, 0, 5, 0, 38, 0, 100, 0, 3, 3, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17417, 0, 0, 0, 0, 0, 0, 'Laughing Skull Ambusher (2) - On Data Set - Start Attack'),

(-@CGUID-5, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Respawn - Set Immune'),
(-@CGUID-5, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Respawn - Set Invisible'),
(-@CGUID-5, 0, 1, 2, 38, 0, 100, 1, 1, 1, 0, 0, 19, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Data Set - Set Immune'),
(-@CGUID-5, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Data Set - Set visible'),
(-@CGUID-5, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 17405, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Respawn - Start WP'),
(-@CGUID-5, 0, 4, 0, 40, 0, 100, 0, 3, 17405, 0, 0, 80, 1740500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - On Reached WP3 - Run Script'),

(1740400, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+3, 17418, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Set Data'),
(1740400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+4, 17418, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),
(1740400, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),
(1740400, 9, 3, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),
(1740400, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),
(1740400, 9, 5, 0, 0, 0, 100, 0, 18000, 18000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),
(1740400, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+5, 17405, 0, 0, 0, 0, 0, 'Vindicator Sedai - Script - Say'),

(1740500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 30462, 2, 0, 0, 0, 0, 19, 17404, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Cast Execute Sedei'),
(1740500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Say'),
(1740500, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, @CGUID+0, 17417, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn Mag har Escort'),
(1740500, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, @CGUID+1, 17417, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn Mag har Escort'),
(1740500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, @CGUID+2, 17404, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn Vindicator Sedai'),
(1740500, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, @CGUID+3, 17418, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn Laughing Skull Ambusher'),
(1740500, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, @CGUID+4, 17418, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn'),
(1740500, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Krun Spinebreaker - Script - Despawn'),

(17413, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+0, 17417, 0, 0, 0, 0, 0, 'Sedai Quest Credit Marker - On Just Summoned - Set Data on Mag har Escort'),
(17413, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+1, 17417, 0, 0, 0, 0, 0, 'Sedai Quest Credit Marker - On Just Summoned - Set Data on Mag har Escort'),
(17413, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @CGUID+2, 17404, 0, 0, 0, 0, 0, 'Sedai Quest Credit Marker - On Just Summoned - Set Data on Vindicator Sedei');


DELETE FROM `waypoints` WHERE `entry`IN(17404,17405,1741700,1741701,1741800,1741801);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(1741700, 1, 206.7916, 4132.612, 77.49819, 'Mag har Escort (1)'),
(1741700, 2, 199.061, 4142.329, 75.17587, 'Mag har Escort (1)'), -- Kick
(1741700, 3, 203.75, 4134.571, 76.52649, 'Mag har Escort (1)'), 
(1741700, 4, 211.582, 4128.351, 79.12319, 'Mag har Escort (1)'), 
(1741700, 5, 219.5054, 4125.231, 80.99819, 'Mag har Escort (1)'), 
(1741701, 1, 206.2685, 4128.42, 77.62319, 'Mag har Escort (2)'), 
(1741701, 2, 200.5664, 4136.248, 75.65149, 'Mag har Escort (2)'),
(1741701, 3, 196.179, 4141.198, 74.30087, 'Mag har Escort (2)'), -- say
(1741701, 4, 203.9766, 4138.813, 76.40149, 'Mag har Escort (2)'),
(1741701, 5, 206.5171, 4135.979, 77.40149, 'Mag har Escort (2)'), 
(1741701, 6, 209.2334, 4134.047, 78.15149, 'Mag har Escort (2)'), 
(1741701, 7, 209.2334, 4134.047, 78.15149, 'Mag har Escort (2)'), 
(1741701, 8, 211.4904, 4132.254, 79.12319, 'Mag har Escort (2)'), 
(1741701, 9, 214.5568, 4129.819, 79.74819, 'Mag har Escort (2)'), 
(1741701, 10, 219.3728, 4128.506, 81.12319, 'Mag har Escort (2)'), 
(17404, 1, 204.9158, 4134.23, 76.90149, 'Vindicator Sedai'),
(17404, 2, 200.7516, 4138.94, 75.52649, 'Vindicator Sedai'),
(17404, 3, 196.6698, 4143.903, 74.30087, 'Vindicator Sedai'), -- Event
(17404, 4, 201.4514, 4139.023, 75.90149, 'Vindicator Sedai'),
(17404, 5, 202.2026, 4138.024, 76.15149, 'Vindicator Sedai'),
(17404, 6, 198.0219, 4143.623, 74.92587, 'Vindicator Sedai'),
(17404, 7, 192.3438, 4150.61, 73.67587, 'Vindicator Sedai'),
(17405, 1, 213.5774, 4129.949, 79.74819, 'Krun Spinebreaker'),
(17405, 2, 203.9323, 4137.877, 76.40149, 'Krun Spinebreaker'),
(17405, 3, 193.1504, 4149.705, 73.80087, 'Krun Spinebreaker'); -- Assasinate


DELETE FROM `creature_text` WHERE `entry`IN(17417,17404,17405);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(17417, 0, 0, 'Do not return, draenei scum.  Next time we won''t spare your life, unarmed or not!', 12, 0, 100, 0, 0, 0, 13986, 0, 'Mag har Escort'), -- 21:04:49.000
(17404, 0, 0, 'I''ve failed... peace is impossible.', 12, 0, 100, 0, 0, 0, 13982, 0, 'Vindicator Sedai'), -- 21:04:58.000
(17404, 1, 0, 'What in the Light''s name...?', 12, 0, 100, 0, 0, 0, 13983, 0, 'Vindicator Sedai'), -- 21:05:13.000
(17404, 2, 0, 'Fel orcs!', 12, 0, 100, 0, 0, 0, 13984, 0, 'Vindicator Sedai'), -- 21:05:18.000
(17404, 3, 0, 'The cycle of bloodshed is unending... Is there nothing I can do?', 12, 0, 100, 0, 0, 0, 13985, 0, 'Vindicator Sedai'), -- 21:05:36.000
(17405, 0, 0, 'You can die!', 12, 0, 100, 0, 0, 0, 13988, 0, 'Krun Spinebreaer'); -- 21:05:48.000
