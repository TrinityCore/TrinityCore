--
UPDATE `waypoints` SET `position_z`=489.640110 WHERE `entry`=15491 AND `pointid`=3;
UPDATE `creature_template` SET `InhabitType`=6 WHERE `entry`=15491;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15491 AND `source_type`=0 AND `id`>38;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15491,0,39,0,40,0,100,0,3,15491,0,0,91,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Eranikus, Tyrant of the Dream - On Waypoint 3 Reached - Remove Flag Hover"),
(15491,0,40,0,54,0,100,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eranikus, Tyrant of the Dream - On Just summoned - Set unitflag"),
(15491,0,41,0,40,0,100,0,4,15491,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eranikus, Tyrant of the Dream - On Waypoint 4 Reached - Remove unitflag");
