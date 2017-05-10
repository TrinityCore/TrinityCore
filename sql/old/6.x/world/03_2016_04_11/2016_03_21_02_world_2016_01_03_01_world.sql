-- 
-- Sergeant Kan'ren, Wretched Captive and Novice Ranger SAI
SET @Sergeant := 16924;
SET @Captive := 16916;
SET @Ranger := 16923;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` in (@Sergeant, @Captive, @Ranger);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Sergeant, @Ranger, @Captive) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Sergeant*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Sergeant,0,0,0,1,0,100,0,60000,100000,100000,120000,80,@Sergeant*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Kan'ren - Out of Combat - Action list"),
(@Sergeant*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Kan'ren - Action list - Say Line 0"),
(@Sergeant*100,9,1,0,0,0,100,0,5000,5000,0,0,5,18,0,0,0,0,0,19,@Captive,10,0,0,0,0,0,"Sergeant Kan'ren - Action list - Captive Play Emote 18"),
(@Sergeant*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@Captive,10,0,0,0,0,0,"Sergeant Kan'ren - Action list - Captive Say Line 0"),
(@Sergeant*100,9,3,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Kan'ren - Action list - Say Line 1"),
(@Captive,0,0,0,1,0,100,0,14000,14000,14000,14000,5,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Captive - Out of Combat - Play Emote 20"),
(@Ranger,0,0,0,1,0,100,0,50000,70000,70000,80000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - Out of Combat - Say text");

UPDATE `creature` SET `movementtype`=0 WHERE `guid`=58691;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=58691;
DELETE FROM `waypoint_data` WHERE `id`=586910;
DELETE FROM `waypoint_scripts` WHERE `id` IN (66, 67, 68, 69, 70);

DELETE FROM `creature_text` WHERE `entry`=@Ranger;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@Ranger,0,0, 'I might just have to go hunting for that Wretched beast now that there''s a bounty on his head.',12,1,100,0,0,0, 'Ranger', 12832);
