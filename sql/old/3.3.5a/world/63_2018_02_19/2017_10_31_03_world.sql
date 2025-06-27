-- 
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=17375;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=181714;
DELETE FROM `smart_scripts` WHERE `entryorguid` =181714 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =17375 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18171400,1737500) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181714, 1, 0 ,0,70, 0, 100, 0, 2, 0, 0,0,80,18171400,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Bristlelimb Cage - On State Changed - Run Script'),
(181714, 1, 1 ,0,38, 0, 100, 0, 1, 1, 0,0,32,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Bristlelimb Cage - On Data Set - Reset GO'),
(17375, 0, 0 ,0,38, 0, 100, 0, 1, 1, 0,0,80,1737500,2,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Stillpine Captive - On Data Set - Run Script'),
(17375, 0, 1 ,0,11, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,20,181714,5,0,0, 0, 0, 0, 'Stillpine Captive - ON respawn - Set data'),
(1737500, 9, 0 ,0,0, 0, 100, 0, 1000, 1000, 0,0,1,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Stillpine Captive - On Script - Say'),
(1737500, 9, 1 ,0,0, 0, 100, 0, 0, 0, 0,0,33,17375,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Stillpine Captive - On Script - Kill Credit'),
(1737500, 9, 2 ,0,0, 0, 100, 0, 4000, 4000, 0,0,114,0,0,0,0,0,0,1,0,0,0,0, 30, 0, 0, 'Stillpine Captive - On Script - Move Foward'),
(1737500, 9, 3 ,0,0, 0, 100, 0, 4000, 4000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Stillpine Captive - On Script - Despawn after 5 seconds'),
(18171400, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Bristlelimb Cage - On State Changed - Store Targetlist'),
(18171400, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,19,17375,5,0,0, 0, 0, 0, 'Bristlelimb Cage - Script - Send Targetlist'),
(18171400, 9, 2 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,19,17375,5,0,0, 0, 0, 0, 'Bristlelimb Cage - Script - Set Data');
