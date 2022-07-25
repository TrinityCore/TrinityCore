--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23720 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2372000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23720,0,0,0,11,0,100,0,0,0,0,0,0,32,0,0,0,0,0,0,20,186287,5,0,0,0,0,0,0,"Theramore Prisoner - On Respawn - Reset Closest Gameobject 'Blackhoof Cage'"),
(23720,0,1,0,38,0,100,0,1,1,0,0,0,80,2372000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theramore Prisoner - On Data Set 1 1 - Run Script"),
(23720,0,2,0,34,0,100,0,8,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Theramore Prisoner - On Reached Point 0 - Delayed Despawn"),

(2372000,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Theramore Prisoner - On Script - Say Line 0"),
(2372000,9,1,0,0,0,100,0,2000,2000,0,0,0,33,23720,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Theramore Prisoner - On Script - Quest Credit 'Prisoners of the Grimtotems'"),
-- It's not even close to Move Foward
(2372000,9,2,0,0,0,100,0,1000,1000,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,0,20,0,0,"Theramore Prisoner - On Script - Move Foward");

UPDATE `creature_text` SET `Emote` = 2 WHERE `CreatureID` = 23720 AND `GroupID` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 186287 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18628700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(186287,1,0,1,70,0,100,0,2,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blackhoof Cage - On State Changed - Store Targetlist"),
(186287,1,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,23720,5,0,0,0,0,0,0,"Blackhoof Cage - On State Changed - Send Target 1 (Theramore Prisoner)"),
(186287,1,2,0,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,23720,5,0,0,0,0,0,0,"Blackhoof Cage - On State Changed - Set Data 1 1 (Theramore Prisoner)");

DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` IN (SELECT `guid` FROM `creature` WHERE `id` = 23720);
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 23720; -- Less than one minute
