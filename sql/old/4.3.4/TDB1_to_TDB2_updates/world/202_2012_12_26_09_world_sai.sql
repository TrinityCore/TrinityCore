-- SAI for Razormaw Matriarch
SET @ENTRY := 1140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,39,20,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Razormaw Matriarch - HP@30% - Call for help'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Razormaw Matriarch - HP@30% - Say text'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Razormaw Matriarch - HP@15% - Cast Fatal Bite'),
(@ENTRY,0,3,0,0,0,90,0,1900,3800,10200,18300,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Razormaw Matriarch - Combat - Cast Rend Flesh');

-- SAI for Unseen Servant
SET @ENTRY := 8538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,2,0,100,1,0,40,0,0,39,25,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Unseen Servant - HP@40% - Call for help'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Unseen Servant - HP@40% - Say text'),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Unseen Servant - On Spawn - Cast Stealth');

-- SAI for Eyeless Watcher
SET @ENTRY := 8539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,2,0,100,1,0,40,0,0,39,25,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Eyeless Watcher - HP@40% - Call for help'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Eyeless Watcher - HP@40% - Say text'),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Eyeless Watcher - On Spawn - Cast Stealth');

-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_text` WHERE `entry` IN (1140,8538,8539);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1140,0,0, '%s lets out a high pitched screech, calling for help!',16,0,100,0,0,0, 'Razormaw Matriarch - Call for help Say'),
(8538,0,0, '%s lets out a high pitched screech, calling for help!',16,0,100,0,0,0, 'Unseen Servant - Call for help Say'),
(8539,0,0, '%s lets out a high pitched screech, calling for help!',16,0,100,0,0,0, 'Eyeless Watcher - Call for help Say');
