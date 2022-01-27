-- https://www.youtube.com/watch?v=eNE7023Vdng
UPDATE `smart_scripts` SET `link` = 0, `event_flags` = 0, `action_type` = 80, `action_param1` = 1239600, `action_param2` = 1, `target_type` = 1, `target_param1` = 0, `comment` = "Doomguard Commander - On Spellhit 'Crystal Prison Dummy DND' - Run Script" WHERE `entryorguid` = 12396 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 12396 AND `source_type` = 0 AND `id` IN (5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1239600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1239600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Doomguard Commander - On Script - Say Line 0"),
(1239600,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Doomguard Commander - On Script - Set Reactstate Passive"),
(1239600,9,2,0,0,0,100,0,0,0,0,0,0,11,23020,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Doomguard Commander - On Script - Cast 'Crystal Imprisonment'"),
(1239600,9,3,0,0,0,100,0,2000,2000,0,0,0,11,23022,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Doomguard Commander - On Script - Cast 'Crystal Prison Conjure DND'"),
(1239600,9,4,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Doomguard Commander - On Script - Despawn (0)");

DELETE FROM `creature_text` WHERE `CreatureID` = 12396;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(12396,0,0,"A sacrifice will be due if I am ever called upon, mortal...",12,8,100,0,0,0,9590,0,"Doomguard Commander");
