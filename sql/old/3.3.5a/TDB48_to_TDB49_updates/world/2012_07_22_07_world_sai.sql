-- Add SAI for Liquid Pyrite ID: 33189 - remove auras to prevent exploit after used, also despawn
SET @Pyrite := 33189;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Pyrite;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Pyrite;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Pyrite,0,0,1,8,0,100,0,67390,0,0,0,28,62494,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pyrite - On hit by spell Ride Vehicle - Remove auras from Liquid Pyrite'),
(@Pyrite,0,1,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pyrite - Linked with previous event - Despawn in 15 sec');
