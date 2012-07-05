-- Add SAI for Dark Ritualist <Cult of the Damned> ID: 34734 // timings are taken from other script finds
SET @Ritualist := 34734;
UPDATE `creature_template` SET  `AIName`='SmartAI' WHERE `entry`=@Ritualist;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Ritualist;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Ritualist,0,0,0,0,0,100,0,3000,3000,8000,14000,11,32000,0,0,0,0,0,2,0,0,0,0,0,0,0,'Dark Ritualist - IC - Cast Mind Seer'),
(@Ritualist,0,1,0,0,0,100,0,8000,17300,17300,17300,11,32026,0,0,0,0,0,2,0,0,0,0,0,0,0,'Dark Ritualist - IC - Cast Pain Strike');
