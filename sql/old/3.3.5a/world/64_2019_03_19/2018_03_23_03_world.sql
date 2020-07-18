-- 
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (1814603,1814604) AND `source_type`=9 AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1814603,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,19,16222,10,0,0,0,0,0,'Champion Vranesh - Script 3 - Silvermoon City Guardian say 2'),
(1814604,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,19,16222,10,0,0,0,0,0,'Champion Vranesh - Script 3 - Silvermoon City Guardian say 3');

DELETE FROM `creature_text` WHERE `CreatureID`=16222 AND `GroupID`>1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16222,2,0,"Even the Light is no match for the indomitable will of our people.",12,1,100,0,0,0,14793,0,"Silvermoon City Guardian"),
(16222,3,0,"Your power strengthens us all.",12,1,100,0,0,0,14792,0,"Silvermoon City Guardian");
