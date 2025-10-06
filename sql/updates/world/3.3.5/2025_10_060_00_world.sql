-- Ingvar
UPDATE `creature_template` SET `unit_flags` = 33555200, `AIName` = 'SmartAI' WHERE `entry` = 24012;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24012 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24012,0,0,0,11,0,100,0,0,0,0,0,0,11,42862,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ingvar Res Ground Visual - On Spawn - Cast 'Scourge Resurrection'"),
(24012,0,1,0,11,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ingvar Res Ground Visual - On Spawn - Delayed Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23954,23980) AND `GroupID` = 3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23954,3,0,"%s roars!",41,0,100,0,0,0,14029,0,"Ingvar the Plunderer - EMOTE_ROAR"),
(23980,3,0,"%s roars!",41,0,100,0,0,0,14029,0,"Ingvar the Plunderer - EMOTE_ROAR");

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 23954 AND `ID` = 2;
UPDATE `creature_equip_template` SET `ItemID1` = 33177 WHERE `CreatureID` = 23954 AND `ID` = 1;
UPDATE `creature` SET `equipment_id` = 1 WHERE `id` = 23954;
