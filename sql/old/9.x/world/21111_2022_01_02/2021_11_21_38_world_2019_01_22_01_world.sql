-- 
DELETE FROM `gameobject` WHERE `guid` IN (7078);

DELETE FROM `creature_text` WHERE `CreatureID`=21188;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21188,0,0,"Excellent news, Tooki! We're saved!",12,0,100,0,0,0,18805,0,'thadok'),
(21188,1,0,"It's time to celebrate, I think...",12,0,100,0,0,0,18807,0,'thadok'),
(21188,2,0,"%s places a keg on the ground.",16,0,100,0,0,0,18808,0,'thadok'),
(21188,3,0,"Listen up, you lot! Our worries are over! FREE BOOZE FOR EVERYONE!",12,0,100,0,0,0,18809,0,'thadok');

DELETE FROM `smart_scripts` WHERE `entryorguid`=18447 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18447,0,1,0,20,0,100,0,10447,0,0,0,45,1,1,0,0,0,0,19,21188,20,0,0,0,0,0, 'Toki - On quest 10447 rewarded - Set data');

UPDATE `creature` SET `position_x`=-2660.596680, `position_y`=4398.262695, `position_z`=36.745258, `orientation`= 5.546348 WHERE `guid`=74300; 
 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=21188;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21188 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2118800,2118801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21188,0,0,0,38,0,100,0,1,1,75000,75000,80,2118800,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - On data set - action list'),
(2118800,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - action list - say text'),
(2118800,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - action list - say text'),
(2118800,9,2,0,0,0,100,0,2000,2000,0,0,53,0,21188,0,0,0,1,1,0,0,0,0,0,0,0, 'thadok - action list - start wp'),
(21188,0,1,0,40,0,100,0,4,21188,0,0,80,2118801,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - on wp reached - action list'),
(2118801,9,0,0,0,0,100,0,0,0,0,0,50,184685,60,1,0,0,0,8,0,0,0,-2668.07, 4423.7, 37.0967, 6.25323, 'thadok - action list - summon gob'),
(2118801,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - action list - say text'),
(2118801,9,2,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - action list - say text'),
(2118801,9,3,0,0,0,100,0,57000,57000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'thadok - action list - set run off'),
(2118801,9,4,0,0,0,100,0,1000,1000,0,0,69,1,0,0,0,0,0,8,0,0,0,-2660.596680,4398.262695,36.745258,5.546348, 'thadok - action list - move to pos'),
(21188,0,2,0,34,0,100,0,8,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.546348, 'thadok - On mov inform - Set orientation');


DELETE FROM `waypoints` WHERE `entry`=21188;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(21188,1,-2661.372, 4406.079, 36.254,""),
(21188,2,-2663.946, 4416.340, 36.078,""),
(21188,3,-2665.697, 4422.351, 36.910,""),
(21188,4,-2667.849, 4422.076, 37.022,"");
