-- Inconspicuous Mine Car
UPDATE `gameobject` SET `position_x`=2391.736,`position_y`=-5898.792,`position_z`=109.3904,`orientation`=0.6981314,`rotation3`=0.9396927 WHERE `guid`=65890 AND `id`=190767;
-- Mine Car
UPDATE `creature_template` SET `minlevel`=56,`maxlevel`=56 WHERE `entry` = 28817;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28817;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28817;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28817,0,0,0,54,0,100,0,0,0,0,0,0,3,0,25703,0,0,0,0,1,0,0,0,0,0,0,0,0,'Mine Car - On spawned - Set model'),
(28817,0,1,0,27,0,100,0,0,0,0,0,0,11,52464,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Mine Car - On passenger boarded - Cast spell \'Summon Scarlet Miner\''),
(28817,0,2,0,8,0,100,1,52595,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Mine Car - On spell hit - Set follow'),
(28817,0,3,0,28,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,28841,9,0,0,0,0,0,0,'Mine Car - On passenger removed - Despawn \'Scarlet Miner\'');
-- Summon Scarlet Miner
UPDATE `spell_target_position` SET `PositionX`=2384.13,`PositionY`=-5900.07,`PositionZ`=108.0813 WHERE `ID`=52464;
UPDATE `spell_target_position` SET `PositionX`=2389.58,`PositionY`=-5901.18,`PositionZ`=108.9380 WHERE `ID`=52462;

-- Scarlet Miner
DELETE FROM `waypoints` WHERE `entry` IN (2884100,2884101);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2884100,1, 2376.892, -5906.246, 108.5153,'Scarlet Miner'),
(2884100,2, 2354.759, -5905.348, 104.9017,'Scarlet Miner'),
(2884100,3, 2331.889, -5903.588, 100.0160,'Scarlet Miner'),
(2884100,4, 2308.977, -5905.764, 90.91159,'Scarlet Miner'),
(2884100,5, 2298.572, -5914.677, 84.70060,'Scarlet Miner'),
(2884100,6, 2291.055, -5934.960, 70.15641,'Scarlet Miner'),
(2884100,7, 2282.350, -5954.375, 57.76657,'Scarlet Miner'),
(2884100,8, 2275.099, -5964.198, 51.61853,'Scarlet Miner'),
(2884100,9, 2260.797, -5972.555, 43.49573,'Scarlet Miner'),
(2884100,10, 2245.771, -5980.806, 34.91277,'Scarlet Miner'),
(2884100,11, 2236.629, -5991.123, 29.03914,'Scarlet Miner'),
(2884100,12, 2197.551, -6068.021, 4.954395,'Scarlet Miner'),
(2884100,13, 2183.802, -6092.537, 1.664639,'Scarlet Miner'),
(2884100,14, 2178.071, -6118.517, 1.298641,'Scarlet Miner'),
(2884100,15, 2173.443, -6140.669, 1.102578,'Scarlet Miner'),
(2884100,16, 2167.344, -6150.516, 1.348482,'Scarlet Miner'),
(2884100,17, 2156.898, -6155.389, 1.925997,'Scarlet Miner'),
(2884100,18, 2141.903, -6161.750, 1.179094,'Scarlet Miner'),
(2884100,19, 2137.161, -6163.067, 1.066367,'Scarlet Miner'),
(2884100,20, 2131.983, -6170.813, 2.067344,'Scarlet Miner'),
(2884100,21, 2126.371, -6179.504, 8.487098,'Scarlet Miner'),
(2884100,22, 2122.159, -6186.258, 13.99542,'Scarlet Miner'),
(2884100,23, 2115.892, -6196.246, 13.67582,'Scarlet Miner'),
(2884101,1, 2376.892, -5906.246, 108.515,'Scarlet Miner'),
(2884101,2, 2354.759, -5905.348, 104.901,'Scarlet Miner'),
(2884101,3, 2331.889, -5903.588, 100.016,'Scarlet Miner'),
(2884101,4, 2308.977, -5905.764, 90.9115,'Scarlet Miner'),
(2884101,5, 2298.572, -5914.677, 84.7006,'Scarlet Miner'),
(2884101,6, 2291.055, -5934.960, 70.1564,'Scarlet Miner'),
(2884101,7, 2282.350, -5954.375, 57.7665,'Scarlet Miner'),
(2884101,8, 2275.099, -5964.198, 51.6185,'Scarlet Miner'),
(2884101,9, 2260.797, -5972.555, 43.4957,'Scarlet Miner'),
(2884101,10, 2245.771, -5980.806, 34.9127,'Scarlet Miner'),
(2884101,11, 2236.629, -5991.123, 29.0391,'Scarlet Miner'),
(2884101,12, 2197.551, -6068.021, 4.95439,'Scarlet Miner'),
(2884101,13, 2183.802, -6092.537, 1.66463,'Scarlet Miner'),
(2884101,14, 2178.071, -6118.517, 1.29864,'Scarlet Miner'),
(2884101,15, 2173.443, -6140.669, 1.10257,'Scarlet Miner'),
(2884101,16, 2176.981, -6153.453, 1.64646,'Scarlet Miner'),
(2884101,17, 2185.705, -6165.262, 1.09934,'Scarlet Miner'),
(2884101,18, 2199.173, -6167.276, 1.05963,'Scarlet Miner'),
(2884101,19, 2220.801, -6165.641, 1.25961,'Scarlet Miner'),
(2884101,20, 2250.129, -6162.287, 0.91468,'Scarlet Miner'),
(2884101,21, 2262.414, -6163.124, 1.49738,'Scarlet Miner'),
(2884101,22, 2268.944, -6167.533, 1.26519,'Scarlet Miner'),
(2884101,23, 2269.859, -6174.558, 5.10841,'Scarlet Miner'),
(2884101,24, 2270.228, -6180.257, 8.81259,'Scarlet Miner'),
(2884101,25, 2270.822, -6184.768, 12.4218,'Scarlet Miner'),
(2884101,26, 2271.095, -6187.314, 13.9912,'Scarlet Miner'),
(2884101,27, 2273.838, -6196.402, 13.65775,'Scarlet Miner');

UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2884100,2884101,2884102);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28841,0,0,1,54,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - On just summoned - Set Run off'),
(28841,0,1,0,61,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,2386.673,-5900.587,108.5761,0,'Scarlet Miner - On just summoned - Move'),
(28841,0,2,3,34,0,100,0,8,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - On movement inform - Set orientation'),
(28841,0,3,4,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Say line 0'),
(28841,0,4,0,61,0,100,0,0,0,0,0,0,87,2884100,2884101,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Random action list'),
(28841,0,5,0,58,0,100,0,0,0,0,0,0,80,2884102,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - On WP ended - Action list 2'),
(2884100,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Cast spell \'Drag Mine Cart\''),
(2884100,9,1,0,61,0,100,0,0,0,0,0,0,53,1,2884100,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Start WP'),
(2884101,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Cast spell \'Drag Mine Cart\''),
(2884101,9,1,0,0,0,100,0,0,0,0,0,0,53,1,2884101,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Start WP'),
(2884102,9,0,0,0,0,100,0,4000,4000,0,0,0,28,52595,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Remove aura'),
(2884102,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Set orientation'),
(2884102,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Say line 1'),
(2884102,9,3,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn \'Mine Car\''),
(2884102,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn self');
