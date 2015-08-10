--
SET @ENTRY := 44794;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,5143,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,1,0,8,0,100,0,100,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,2,0,8,0,100,0,2098,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY,0,3,0,8,0,100,0,56641,0,0,0,33,44175,0,0,0,0,0,7,0,0,0,0,0,0,0,"Training Dummy - On spell hit - Credit kill"),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 348, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Training Dummy - On spellHit - CreditKill'),
(@ENTRY, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Training Dummy - On Death - Respawn');
