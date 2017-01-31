-- Splinter Fist Warrior SAI
SET @ENTRY := 212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,30000,30000,11,78828,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - In Combat - Cast 'Bladestorm'"),
(@ENTRY,0,2,3,0,0,100,0,14000,14000,30000,30000,11,35856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Warrior - In Combat - Cast 'Stun'"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Warrior - In Combat - Say 1");
DELETE FROM `creature_text` WHERE `entry`=212 AND `groupid`=1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(212, 1, 0, 'Me not feel so good.', 12, 0, 100, 0, 0, 0, 43512, 'Splinter Fist Warrior');
