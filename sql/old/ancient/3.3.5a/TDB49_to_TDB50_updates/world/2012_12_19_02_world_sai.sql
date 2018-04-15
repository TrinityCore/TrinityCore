SET @SASHA := 26935;
SET @HORSE := 27626;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@SASHA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SASHA,0,0,3,38,1,100,0,0,1,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 1 (phase 1) - Say line'),
(@SASHA,0,1,3,38,1,100,0,0,2,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 2 (phase 1) - Say line'),
(@SASHA,0,2,3,38,1,100,0,0,3,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 3 (phase 1) - Say line'),
(@SASHA,0,3,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Linked with events 0,1,2 - Set data 0 0'),
(@SASHA,0,4,5,38,0,100,0,0,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Set event phase 0'),
(@SASHA,0,5,0,61,0,100,0,0,0,0,0,80,@SASHA*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Run script'),
(@SASHA,0,6,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On reset - Set event phase 1'),
(@SASHA,0,7,0,54,0,100,0,0,0,0,0,53,1,@SASHA,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Just summoned - Start WP movement'),
(@SASHA,0,8,9,40,0,100,0,4,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Set unit_field_bytes1 (kneel)'),
(@SASHA,0,9,0,61,0,100,0,0,0,0,0,80,@SASHA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Run script');

DELETE FROM `waypoints` WHERE `entry`=@HORSE AND `pointid`=19;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@HORSE,19,4056.67,-4143.688,211.3766,'');
