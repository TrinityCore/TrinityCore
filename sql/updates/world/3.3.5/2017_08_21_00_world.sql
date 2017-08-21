-- Zem Leeward
DELETE FROM `creature_text` WHERE `CreatureID`=348;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(348,0,0,'Nothing biting....',12,7,100,0,0,0,45,0,'Zem Leeward'),
(348,0,1,'Here fishy fishy. . . come to papa.',12,7,100,0,0,0,46,0,'Zem Leeward');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=348;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(348,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zem Leeward - Out of Combat - Say Line 0');
