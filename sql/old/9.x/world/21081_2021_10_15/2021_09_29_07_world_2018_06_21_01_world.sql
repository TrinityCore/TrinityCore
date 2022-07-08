-- Scarlet Crusader (28529)
DELETE FROM `creature_text` WHERE `CreatureID`=28529;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(28529,0,0,'Death stalks us! Destroy it!',12,0,100,0,0,0,28488,0,'Scarlet Crusader'),
(28529,0,1,'Begone foul demon!',12,0,100,0,0,0,28489,0,'Scarlet Crusader'),
(28529,0,2,'\'Tis the work of the Scourge!',12,0,100,0,0,0,28490,0,'Scarlet Crusader'),
(28529,0,3,'Scourge! Do not let it escape!',12,0,100,0,0,0,28491,0,'Scarlet Crusader');
DELETE FROM `smart_scripts` WHERE `entryorguid`=28529 AND `source_type`=0 and `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(28529,0,1,0,4,0,50,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scarlet Crusader - On Aggro - Say Line 0');
