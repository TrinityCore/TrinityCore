-- Warden Moi'bff Jill SAI
SET @ID := 18408;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,34,0,100,0,2,2,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Reached Point 2 - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,20,182393,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Script - Set Orientation Closest Gameobject 'Telaar Bulletin Board'"),
(@ID*100+0,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Script - Set Emote State 234"),
(@ID*100+0,9,3,0,0,0,100,0,15000,15000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Script - Set Emote State 0"),
(@ID*100+0,9,4,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warden Moi'bff Jill - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"New posting going up! Adventurers and heroes, gather round the bulletin board!",12,7,100,0,0,0,15373,0,"Warden Moi'bff Jill"),
(@ID,1,0,"That should get Telaar the assistance it needs!",12,7,100,5,0,0,15374,0,"Warden Moi'bff Jill");

DELETE FROM `waypoint_data` WHERE `id` = 658000;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(658000,1,-2568.978,7271.639,15.4864,4.69494,120000,0,0,0,0),
(658000,2,-2565.826,7274.235,15.5482,0,0,0,0,0,0),
(658000,3,-2565.826,7274.235,15.5482,0,23000,0,0,0,0);

-- Old script
DELETE FROM `waypoint_scripts` WHERE `id` = 112;
