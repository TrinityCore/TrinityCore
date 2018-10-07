/*
-- Commander Gor'shak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9020;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9020 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (902000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9020,0,0,0,11,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Gor'shak - On Respawn - Add Unit Flag 'Immune to NPC'"),
(9020,0,1,0,19,0,100,0,3982,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Gor'shak - On Quest 'What Is Going On?' Taken - Store Targetlist"),
(9020,0,2,0,19,0,100,0,3982,0,0,0,0,80,902000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Gor'shak - On Quest 'What Is Going On?' Taken - Run Script"),
(9020,0,3,0,6,0,100,0,0,0,0,0,0,6,3982,0,0,0,0,0,12,1,0,0,0,0,0,0,"Commander Gor'shak - On Just Died - Fail Quest 'What Is Going On?'"),
(902000,9,0,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Gor'shak - On Script - Remove Unit Flag 'Immune to NPC'"),
(902000,9,1,0,0,0,100,0,2000,2000,0,0,0,12,8891,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Guardsman'"),
(902000,9,2,0,0,0,100,0,1000,1000,0,0,0,12,8891,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Guardsman'"),
(902000,9,3,0,0,0,100,0,1000,1000,0,0,0,12,8890,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Warden'"),
(902000,9,4,0,0,0,100,0,1000,1000,0,0,0,12,8912,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Twilight's Hammer Torturer'"),
(902000,9,5,0,0,0,100,0,20000,20000,0,0,0,12,8891,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Guardsman'"),
(902000,9,6,0,0,0,100,0,1000,1000,0,0,0,12,8891,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Guardsman'"),
(902000,9,7,0,0,0,100,0,1000,1000,0,0,0,12,8890,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Anvilrage Warden'"),
(902000,9,8,0,0,0,100,0,1000,1000,0,0,0,12,8912,3,300000,0,0,0,8,0,0,0,397.946,-203.572,-66.6304,5.0,"Commander Gor'shak - On Script - Summon Creature 'Twilight's Hammer Torturer'"),
(902000,9,9,0,0,0,100,0,10000,10000,0,0,0,15,3982,0,0,0,0,0,12,1,0,0,0,0,0,0,"Commander Gor'shak - On Script - Complete Quest 'What Is Going On?'");

-- Twilight's Hammer Torturer
DELETE FROM `smart_scripts` WHERE `entryorguid`=8912 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8912,0,2,0,54,0,100,0,0,0,0,0,0,53,1,8912,0,0,0,2,1,0,0,0,0,0,0,0,"Twilight's Hammer Torturer - Just Summoned - Start Waypoint"),
(8912,0,3,0,40,0,100,0,4,8912,0,0,0,49,0,0,0,0,0,0,19,9020,0,0,0,0,0,0,"Twilight's Hammer Torturer - On Waypoint 4 Reached - Start Attacking");

-- Anvilrage Guardsman
DELETE FROM `smart_scripts` WHERE `entryorguid`=8891 AND `source_type`=0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8891,0,3,0,54,0,100,0,0,0,0,0,0,53,1,8912,0,0,0,2,1,0,0,0,0,0,0,0,"Anvilrage Guardsman - Just Summoned - Start Waypoint"),
(8891,0,4,0,40,0,100,0,4,8912,0,0,0,49,0,0,0,0,0,0,19,9020,0,0,0,0,0,0,"Anvilrage Guardsman - On Waypoint 4 Reached - Start Attacking");

-- Anvilrage Warden
DELETE FROM `smart_scripts` WHERE `entryorguid`=8890 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8890,0,2,0,54,0,100,0,0,0,0,0,0,53,1,8912,0,0,0,2,1,0,0,0,0,0,0,0,"Anvilrage Warden - Just Summoned - Start Waypoint"),
(8890,0,3,0,40,0,100,0,4,8912,0,0,0,49,0,0,0,0,0,0,19,9020,0,0,0,0,0,0,"Anvilrage Warden - On Waypoint 4 Reached - Start Attacking");

DELETE FROM `waypoints` WHERE `entry`=8912;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(8912,1,397.946,-203.572,-66.6304,""),
(8912,2,384.623,-204.055,-68.6992,""),
(8912,3,377.427,-195.647,-70.2208,""),
(8912,4,373.97,-184.192,-70.108,"");
*/
