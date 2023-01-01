-- 
-- Mist
DELETE FROM `smart_scripts` WHERE `entryorguid`=356801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(356801,9,0,0,0,0,100,0,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Set Root On"),
(356801,9,1,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,3519,0,0,0,0,0,0,0,"Mist - On Script - Set Data to Sentinel Arynia Cloudsbreak"),
(356801,9,2,0,0,0,100,0,1000,1000,0,0,0,15,938,0,0,0,0,0,12,0,0,0,0,0,0,0,0,"Mist - On Script - Complete Quest 'Mist'"),
(356801,9,3,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Say Line 0"),
(356801,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Despawn");

-- Sentinel Arynia Cloudsbreak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3519 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=351900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3519,0,0,0,38,0,100,0,1,1,0,0,0,80,351900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Data Set - Run Sript"),
(351900,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,3568,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Orientation"),
(351900,9,1,0,0,0,100,0,1000,1000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Flag Standstate 'Kneel'"),
(351900,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Say Line 0"),
(351900,9,3,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Remove Flag Standstate 'Kneel'"),
(351900,9,4,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Orientation");
