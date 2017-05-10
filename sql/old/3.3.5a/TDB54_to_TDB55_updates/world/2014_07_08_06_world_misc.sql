-- Corporal Thund Splithoof SAI
SET @ENTRY := 7750;
SET @QUEST := 2701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,@QUEST,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corporal Thund Splithoof - On Quest Complete - Forced Despawn"),
(@ENTRY,0,1,2,19,0,100,0,@QUEST,0,0,0,70,0,0,0,0,0,0,14,44733,141980,0,0,0,0,0,"Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox (GO)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,14,44732,141981,0,0,0,0,0,"Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox Particles (GO)");

UPDATE `conditions` SET `ConditionTypeOrReference`=28 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=840 AND `SourceEntry`=2 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=2702 AND `ConditionValue2`=0 AND `ConditionValue3`=0;

-- Modifying condition for Gossip on Fallen Hero of the Horde to spawn Corporal Thund Splithoof so condition is met on condition 28 Quest complete instead of 9 quest taken
-- reason for this change is that this quest is completed as soon as taken and condition taken is not met here as core sees the quest has complete as soon as it is taken by player
