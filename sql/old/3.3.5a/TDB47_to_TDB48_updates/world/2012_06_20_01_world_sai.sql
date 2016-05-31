-- Razormaw SAI fixes quest 9689
SET @ENTRY  := 17592;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES (@ENTRY,50331648,1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,7000,9000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Razormaw - Combat - Cast Swipe'),
(@ENTRY,0,1,0,0,0,100,0,26000,30000,26000,30000,11,8873,0,0,0,0,0,1,0,0,0,0,0,0,0,'Razormaw - Combat - Cast Flame Breath'),
(@ENTRY,0,2,0,0,0,50,0,12000,12000,12000,12000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Razormaw - Combat - Cast Terrifying Roar'),
(@ENTRY,0,3,0,11,0,100,0,0,0,0,0,53,1,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,'Razormaw - On spawn - Load Path'),
(@ENTRY,0,4,0,40,0,100,0,10,@ENTRY,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Razormaw - On Reach waypoint - Remove unitflag');
-- Waypoints for Razormaw
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-1045.958,-12583.85,111.7434, 'Razormaw'),
(@ENTRY,2,-1045.115,-12583.31,111.7434, 'Razormaw'),
(@ENTRY,3,-1213.006,-12663.19,200.4278, 'Razormaw'),
(@ENTRY,4,-1204.485,-12626.66,200.4278, 'Razormaw'),
(@ENTRY,5,-1204.906,-12599.65,188.7889, 'Razormaw'),
(@ENTRY,6,-1206.845,-12579.84,173.2892, 'Razormaw'),
(@ENTRY,7,-1203.169,-12555.49,160.956, 'Razormaw'),
(@ENTRY,8,-1201.284,-12529.25,134.3167, 'Razormaw'),
(@ENTRY,9,-1204.178,-12483.84,115.039, 'Razormaw'),
(@ENTRY,10,-1204.349,-12465.61,104.7762, 'Razormaw'),
(@ENTRY,11,-1205.651,-12460.52,97.53908, 'Razormaw');
