-- Gordawg SAI
SET @ENTRY := 80592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordawg - On Aggro - Say Line 0."),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordawg - On Death - Say Line 1."),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,33000,35000,11,167412,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordawg -  IC Timer - Cast Quake."),
(@ENTRY,0,3,0,0,0,100,0,29000,29000,31000,33000,11,167427,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gordawg -  IC Timer - Cast Trembling Roar.");

DELETE FROM `creature_text` WHERE `entry` = 80592;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(80592, 0, 0, 'The master commands and I obey!', 14, 0, 100, 0, 0, 46293, 83833, 'Gordawg - Yell on Aggro.'),
(80592, 1, 0, 'In death... I am free...', 12, 0, 100, 0, 0, 46294, 84566, 'Gordawg - Yell on Death');
