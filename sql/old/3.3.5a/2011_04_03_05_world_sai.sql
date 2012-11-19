-- Scripting cleanup
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry` IN (29154,28961,28965);
UPDATE `creature_template` SET `AIName`= '' WHERE `entry` IN (23069,23259,23336,33229,33243,33272);

-- SAI for Gavin Gnarltree
SET @ENTRY := 225;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-10617.34,`position_y`=-1153.902,`position_z`=27.11271 WHERE `guid`=4086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - Reach wp 1 - ONESHOT_POINT'),
(@ENTRY,0,3,0,40,0,100,0,6,@ENTRY,0,0,54,50000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - Reach wp 6 - pause path'),
(@ENTRY,0,4,5,40,0,100,0,10,@ENTRY,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - Reach wp 10 - pause path'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - Reach wp 10 - STATE_WORK_MINING'),
(@ENTRY,0,6,0,56,0,100,0,10,@ENTRY,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gavin Gnarltree - waypoint 10 resumed - STATE_NONE');
-- Waypoints for Gavin Gnarltree from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-10616.74,-1150.729,28.03606, 'Gavin Gnarltree'),
(@ENTRY,2,-10609.4,-1154.94,28.2175, 'Gavin Gnarltree'),
(@ENTRY,3,-10605.3,-1157.31,30.007, 'Gavin Gnarltree'),
(@ENTRY,4,-10600.3,-1159.58,30.0602, 'Gavin Gnarltree'),
(@ENTRY,5,-10596.1,-1156.43,30.0602, 'Gavin Gnarltree'),
(@ENTRY,6,-10596.89,-1154.147,30.05965, 'Gavin Gnarltree'),
(@ENTRY,7,-10601.7,-1159.03,30.0602, 'Gavin Gnarltree'),
(@ENTRY,8,-10606,-1156.86,29.9963, 'Gavin Gnarltree'),
(@ENTRY,9,-10609.6,-1155.18,28.2269, 'Gavin Gnarltree'),
(@ENTRY,10,-10617.34,-1153.902,27.11271, 'Gavin Gnarltree');

-- SAI for Joseph Wilson
SET @ENTRY := 33589;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=8489.46,`position_y`=964.667,`position_z`=547.293 WHERE `guid`=75904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Joseph Wilson - On spawn - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Joseph Wilson - Reach wp 1 - run script'),
(@ENTRY,0,2,3,40,0,100,0,4,@ENTRY,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Joseph Wilson - Reach wp 4 - pause path'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.193953, 'Joseph Wilson - Reach wp 4 - turn to'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,22000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Joseph Wilson - Script - pause path'),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,19,33479,0,0,0,0,0,0, 'Joseph Wilson - Script - turn to'),
(@ENTRY*100,9,2,0,0,0,100,0,500,500,0,0,11,61493,0,0,0,0,0,19,33479,0,0,0,0,0,0, 'Joseph Wilson - Script - cast'),
(@ENTRY*100,9,3,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,19,33460,0,0,0,0,0,0, 'Joseph Wilson - Script - turn to'),
(@ENTRY*100,9,4,0,0,0,100,0,500,500,0,0,11,61493,0,0,0,0,0,19,33460,0,0,0,0,0,0, 'Joseph Wilson - Script - cast');
-- Waypoints for Joseph Wilson from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,8492.984,961.6198,547.2927, 'Joseph Wilson'),
(@ENTRY,2,8489.46,964.667,547.293, 'Joseph Wilson'),
(@ENTRY,3,8489.138,966.7257,547.2927, 'Joseph Wilson'),
(@ENTRY,4,8489.907,967.6441,547.2939, 'Joseph Wilson'),
(@ENTRY,5,8489.138,966.7257,547.2927, 'Joseph Wilson'),
(@ENTRY,6,8489.46,964.667,547.293, 'Joseph Wilson');

-- SAI for Thomas Partridge
SET @ENTRY := 33854;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=8480.21,`position_y`=937.883,`position_z`=547.293 WHERE `guid`=76735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.01942, 'Thomas Partridge - Reach wp 1 - turn to'),
(@ENTRY,0,3,0,40,0,100,0,5,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 5 - run script'),
(@ENTRY,0,4,0,40,0,100,0,9,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 9 - run script'),
(@ENTRY,0,5,0,40,0,100,0,13,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 13 - run script'),
(@ENTRY,0,6,0,40,0,100,0,16,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 16 - run script'),
(@ENTRY,0,7,0,40,0,100,0,20,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Reach wp 20 - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Script - pause path'),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thomas Partridge - Script - emote');
-- Waypoints for Thomas Partridge from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,8481.685,959.4879,547.2927, 'Thomas Partridge'),
(@ENTRY,2,8482.575,952.007,547.2927, 'Thomas Partridge'),
(@ENTRY,3,8479.16,931.178,547.294, 'Thomas Partridge'),
(@ENTRY,4,8480.29,928.951,547.293, 'Thomas Partridge'),
(@ENTRY,5,8481.386,929.6846,547.2927, 'Thomas Partridge'),
(@ENTRY,6,8479.16,931.178,547.294, 'Thomas Partridge'),
(@ENTRY,7,8479.08,935.109,547.293, 'Thomas Partridge'),
(@ENTRY,8,8482.33,937.765,547.294, 'Thomas Partridge'),
(@ENTRY,9,8487.458,937.033,547.2927, 'Thomas Partridge'),
(@ENTRY,10,8482.33,937.765,547.294, 'Thomas Partridge'),
(@ENTRY,11,8479.16,931.178,547.294, 'Thomas Partridge'),
(@ENTRY,12,8479.21,919.35,547.294, 'Thomas Partridge'),
(@ENTRY,13,8483.181,917.6667,547.2927, 'Thomas Partridge'),
(@ENTRY,14,8480.25,917.926,547.293, 'Thomas Partridge'),
(@ENTRY,15,8480.31,909.402,547.293, 'Thomas Partridge'),
(@ENTRY,16,8484.031,903.8014,547.2927, 'Thomas Partridge'),
(@ENTRY,17,8479.39,909.922,547.293, 'Thomas Partridge'),
(@ENTRY,18,8479.08,935.109,547.293, 'Thomas Partridge'),
(@ENTRY,19,8483.99,937.559,547.293, 'Thomas Partridge'),
(@ENTRY,20,8486.654,940.0261,547.2929, 'Thomas Partridge'),
(@ENTRY,21,8483.99,937.559,547.293, 'Thomas Partridge'),
(@ENTRY,22,8480.21,937.883,547.293, 'Thomas Partridge');

-- SAI for Brammold Deepmine
SET @ENTRY := 32509;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5771.88,`position_y`=632.803,`position_z`=661.075 WHERE `guid`=120355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Brammold Deepmine - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,2,@ENTRY,0,0,54,480000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Brammold Deepmine - Reach wp 2 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.321288, 'Brammold Deepmine - Reach wp 2 - turm to'),
(@ENTRY,0,3,4,40,0,100,0,8,@ENTRY,0,0,54,480000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Brammold Deepmine - Reach wp 8 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.692969, 'Brammold Deepmine - Reach wp 8 - turn to');
-- Waypoints for Brammold Deepmine from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5769.026,629.7931,661.0721, 'Brammold Deepmine'),
(@ENTRY,2,5770.056,625.5038,661.0721, 'Brammold Deepmine'),
(@ENTRY,3,5769.026,629.7931,661.0721, 'Brammold Deepmine'),
(@ENTRY,4,5771.88,632.803,661.075, 'Brammold Deepmine'),
(@ENTRY,5,5773.25,637.491,661.151, 'Brammold Deepmine'),
(@ENTRY,6,5759.77,648.809,650.12, 'Brammold Deepmine'),
(@ENTRY,7,5757,647.883,650.141, 'Brammold Deepmine'),
(@ENTRY,8,5753.792,635.2266,650.1417, 'Brammold Deepmine'),
(@ENTRY,9,5757,647.883,650.141, 'Brammold Deepmine'),
(@ENTRY,10,5759.77,648.809,650.12, 'Brammold Deepmine'),
(@ENTRY,11,5773.25,637.491,661.151, 'Brammold Deepmine'),
(@ENTRY,12,5771.88,632.803,661.075, 'Brammold Deepmine');

-- SAI for Emi
SET @ENTRY := 32668;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5805.625,`position_y`=692.3191,`position_z`=647.0484 WHERE `guid`=110543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Emi - On spawn - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,54,18000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Emi - Reach wp 1 - pause path'),
(@ENTRY,0,2,3,40,0,100,0,2,@ENTRY,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Emi - Reach wp 2 - pause path'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.316126, 'Emi - Reach wp 2 - turm to');
-- Waypoints for Emi from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5809.61,694.5121,647.0484, 'Emi'),
(@ENTRY,2,5805.625,692.3191,647.0484, 'Emi');
-- 0xF130007F9C00292F .go 5809.61 694.5121 647.0484

-- SAI for Colin
SET @ENTRY := 32669;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5807.146,`position_y`=683.3826,`position_z`=647.0484 WHERE `guid`=110586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Colin - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Colin - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.427974, 'Colin - Reach wp 1 - turm to'),
(@ENTRY,0,3,4,40,0,100,0,2,@ENTRY,0,0,54,28000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Colin - Reach wp 2 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.2094395, 'Colin - Reach wp 2 - turm to'),
(@ENTRY,0,5,6,40,0,100,0,3,@ENTRY,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Colin - Reach wp 3 - pause path'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.804818, 'Colin - Reach wp 3 - turm to');
-- Waypoints for Colin from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5815.523,681.2226,647.0484, 'Colin'),
(@ENTRY,2,5818.646,688.2175,647.0484, 'Colin'),
(@ENTRY,3,5807.146,683.3826,647.0484, 'Colin');
-- 0xF130007F9D00293F .go 5815.523 681.2226 647.0484
