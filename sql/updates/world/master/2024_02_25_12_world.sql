-- Kurtok the Slayer SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=42938;
DELETE FROM `smart_scripts` WHERE `entryorguid`=42938 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(42938,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kurtok the Slayer - On Aggro - Say text 0'),
(42938,0,1,0,6,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Kurtok the Slayer - On Death - Say text 1');

DELETE FROM `creature_text` WHERE `CreatureID`=42938;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(42938, 0, 0, 'Alliance weakling, your lands will burn!', 12, 0, 100, 5, 0, 0, 0, 0, 'Kurtok the Slayer'),
(42938, 1, 0, 'The Blackrock Clan will end you...', 12, 0, 100, 0, 0, 0, 0, 0, 'Kurtok the Slayer');
