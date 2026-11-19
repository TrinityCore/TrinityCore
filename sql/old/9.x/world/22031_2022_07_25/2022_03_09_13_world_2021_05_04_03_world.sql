-- Event in Laj's room adjustments
UPDATE `creature` SET `position_x` = -161.205612182617187, `position_y` = 391.8802490234375, `position_z` = -17.6448993682861328, `orientation` = 1.954768776893615722, `VerifiedBuild` = 14007, `unit_flags` = 33587264, `spawntimesecs` = 86400 WHERE `guid` = 127349 AND `id` = 17993;
UPDATE `creature` SET `position_x` = -166.66375732421875, `position_y` = 391.7630615234375, `position_z` = -17.6138515472412109, `orientation` = 1.326450228691101074, `VerifiedBuild` = 14007, `unit_flags` = 33587264, `spawntimesecs` = 86400 WHERE `guid` = 127350 AND `id` = 17993;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-127349,-127350) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Not sure when timer starts
(-127349,0,0,0,37,0,100,0,0,0,0,0,0,116,18,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On AI Initialize - Set Corpse Delay"),
(-127349,0,1,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On AI Initialize - Set Faction 190"),
(-127349,0,2,3,10,0,100,1,1,90,0,0,0,53,1,1799300,0,0,0,2,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - Out of Combat LoS - Start Waypoint (No Repeat)"),
(-127349,0,3,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On Link - Say Line 1"),
(-127349,0,4,0,40,0,100,0,2,1799300,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On Waypoint 2 Reached - Cast 'Suicide'"),

(-127350,0,0,0,37,0,100,0,0,0,0,0,0,116,18,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On AI Initialize - Set Corpse Delay"),
(-127350,0,1,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On AI Initialize - Set Faction 190"),
(-127350,0,2,3,10,0,100,1,1,90,0,0,0,53,1,1799301,0,0,0,2,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - Out of Combat LoS - Start Waypoint (No Repeat)"),
(-127350,0,3,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On Link - Say Line 0"),
(-127350,0,4,0,40,0,100,0,1,1799301,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Protector - On Waypoint 1 Reached - Cast 'Suicide'");

DELETE FROM `waypoints` WHERE `entry` IN (1799300,1799301);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(1799300,1,-162.18033,409.83426,-17.638655,0,0,"Bloodwarder Protector"),
(1799300,2,-162.64375,427.75867,-17.793741,0,0,"Bloodwarder Protector"),
(1799301,1,-171.43996,422.89474,-17.744621,0,0,"Bloodwarder Protector");

-- Sunseeker Gene-Splicer in Laj's room
UPDATE `creature_addon` SET `bytes1` = 7, `bytes2` = 1, `auras` = "" WHERE `guid` IN (127292,127293,127337,127340,127341,127342,127343,127344,127345,127346,127347,127348);
UPDATE `creature` SET `unit_flags` = 33587264 WHERE `guid` IN (127292,127293,127337,127340,127341,127342,127343,127344,127345,127346,127347,127348) AND `id` = 19507;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-127292,-127293,-127337,-127340,-127341,-127342,-127343,-127344,-127345,-127346,-127347,-127348) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-127292,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127293,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127337,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127340,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127341,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127342,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127343,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127344,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127345,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127346,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127347,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190"),
(-127348,0,0,0,37,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - On AI Initialize - Set Faction 190");
