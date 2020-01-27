-- Inconspicuous Mine Car
UPDATE `gameobject` SET `position_x`=2391.736,`position_y`=-5898.792,`position_z`=109.3904,`orientation`=0.6981314,`rotation3`=0.9396927 WHERE `guid`=65890 AND `id`=190767;
-- Mine Car
UPDATE `creature_template` SET `minlevel`=56,`maxlevel`=56 WHERE `entry` = 28817;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28817;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28817;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28817,0,0,0,54,0,100,0,0,0,0,0,0,3,0,25703,0,0,0,0,1,0,0,0,0,0,0,0,0,'Mine Car - On spawned - Set model'),
(28817,0,1,2,27,0,100,0,0,0,0,0,0,11,52464,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Mine Car - On passenger boarded - Cast spell \'Summon Scarlet Miner\''),
(28817,0,2,0,61,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,19,28841,5,0,0,0,0,0,0,'Mine Car - Linked event - Set follow'),
(28817,0,3,0,28,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,28841,5,0,0,0,0,0,0,'Mine Car - On passenger removed - Despawn \'Scarlet Miner\'');
-- Summon Scarlet Miner
UPDATE `spell_target_position` SET `PositionX`=2384.13,`PositionY`=-5900.07,`PositionZ`=108.0813 WHERE `ID`=52464;

-- Scarlet Miner
DELETE FROM `waypoints` WHERE `entry` IN (2884100,2884101);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2884100,1,2376.892,-5906.246,108.6758,'Scarlet Miner'),
(2884100,2,2340.142,-5903.496,102.4258,'Scarlet Miner'),
(2884100,3,2306.392,-5904.746,90.67581,'Scarlet Miner'),
(2884100,4,2292.642,-5917.746,82.42581,'Scarlet Miner'),
(2884100,5,2285.642,-5943.496,64.17581,'Scarlet Miner'),
(2884100,6,2271.892,-5968.496,49.67582,'Scarlet Miner'),
(2884100,7,2248.142,-5978.496,36.92582,'Scarlet Miner'),
(2884100,8,2234.642,-5996.996,25.92582,'Scarlet Miner'),
(2884100,9,2223.392,-6014.996,11.67582,'Scarlet Miner'),
(2884100,10,2216.142,-6035.996,7.425816,'Scarlet Miner'),
(2884100,11,2195.392,-6061.246,6.175816,'Scarlet Miner'),
(2884100,12,2184.392,-6091.996,2.175816,'Scarlet Miner'),
(2884100,13,2179.642,-6120.246,1.675816,'Scarlet Miner'),
(2884100,14,2175.392,-6142.996,1.425816,'Scarlet Miner'),
(2884100,15,2167.892,-6159.496,1.925816,'Scarlet Miner'),
(2884100,16,2149.392,-6161.496,1.675816,'Scarlet Miner'),
(2884100,17,2134.892,-6166.246,0.9258156,'Scarlet Miner'),
(2884100,18,2130.892,-6173.246,4.175816,'Scarlet Miner'),
(2884100,19,2125.892,-6180.746,10.17582,'Scarlet Miner'),
(2884100,20,2123.392,-6184.746,13.92582,'Scarlet Miner'),
(2884100,21,2115.892,-6196.246,13.67582,'Scarlet Miner'),
(2884101,1,2376.838,-5906.152,108.6577,'Scarlet Miner'),
(2884101,2,2340.088,-5903.402,102.6577,'Scarlet Miner'),
(2884101,3,2306.838,-5904.902,90.65775,'Scarlet Miner'),
(2884101,4,2292.838,-5917.746,82.40775,'Scarlet Miner'),
(2884101,5,2285.642,-5917.652,64.15775,'Scarlet Miner'),
(2884101,6,2272.088,-5968.402,49.90775,'Scarlet Miner'),
(2884101,7,2248.338,-5978.402,36.90775,'Scarlet Miner'),
(2884101,8,2234.838,-5996.902,25.90775,'Scarlet Miner'),
(2884101,9,2223.588,-6015.152,11.65775,'Scarlet Miner'),
(2884101,10,2216.088,-6035.902,7.407745,'Scarlet Miner'),
(2884101,11,2195.088,-6059.402,6.407745,'Scarlet Miner'),
(2884101,12,2184.838,-6087.152,3.157745,'Scarlet Miner'),
(2884101,13,2180.588,-6149.402,1.657745,'Scarlet Miner'),
(2884101,14,2177.588,-6149.402,1.907745,'Scarlet Miner'),
(2884101,15,2188.838,-6170.402,1.157745,'Scarlet Miner'),
(2884101,16,2213.088,-6165.402,1.157745,'Scarlet Miner'),
(2884101,17,2241.838,-6160.402,1.907745,'Scarlet Miner'),
(2884101,18,2269.088,-6163.402,2.157745,'Scarlet Miner'),
(2884101,19,2269.588,-6168.902,2.407745,'Scarlet Miner'),
(2884101,20,2270.088,-6174.652,5.907745,'Scarlet Miner'),
(2884101,21,2270.588,-6180.902,9.907745,'Scarlet Miner'),
(2884101,22,2271.088,-6186.152,14.15775,'Scarlet Miner'),
(2884101,23,2273.838,-6196.402,13.65775,'Scarlet Miner');
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=28841;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (2884100,2884101,2884102);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28841,0,0,0,54,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,2386.673,-5900.587,108.5761,0,'Scarlet Miner - On just summoned - Move'),
(28841,0,1,2,34,0,100,0,8,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - On movement inform - Set orientation'),
(28841,0,2,3,61,0,100,0,8,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Say line 0'),
(28841,0,3,0,61,0,100,0,0,0,0,0,0,87,2884100,2884101,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Linked event - Random action list'),
(28841,0,4,0,58,0,100,0,0,0,0,0,0,80,2884102,0,1,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - On WP ended - Action list 2'),
(2884100,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Cast spell \'Drag Mine Cart\''),
(2884100,9,1,0,61,0,100,0,0,0,0,0,0,53,1,2884100,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 0 - Start WP'),
(2884101,9,0,0,0,0,100,0,4000,4000,0,0,0,11,52595,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Cast spell \'Drag Mine Cart\''),
(2884101,9,1,0,0,0,100,0,0,0,0,0,0,53,1,2884101,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 1 - Start WP'),
(2884102,9,0,0,0,0,100,0,4000,4000,0,0,0,28,52595,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Remove aura'),
(2884102,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Set orientation'),
(2884102,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Say line 1'),
(2884102,9,3,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,23,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn \'Mine Car\''),
(2884102,9,4,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Scarlet Miner - Action list 2 - Despawn self');
