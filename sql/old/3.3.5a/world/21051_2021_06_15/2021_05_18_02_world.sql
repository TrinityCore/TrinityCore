-- Irradiated Burrower, ACID
DELETE FROM `smart_scripts` WHERE `entryorguid` = 6206 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6206,0,0,0,0,0,100,0,1100,4800,182900,184500,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Burrower - In Combat - Cast 'Defensive Stance'"),
-- This spell is broken, don't wanna change to another
(6206,0,1,0,0,0,100,0,5000,8000,6100,9700,0,11,7405,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Caverndeep Burrower - In Combat - Cast 'Sunder Armor'"),
(6206,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Caverndeep Burrower - Between 0-15% Health - Flee For Assist (No Repeat)"),
(6206,0,3,0,8,0,100,0,9798,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caverndeep Burrower - On Spellhit 'Radiation' - Say Line 0");

-- Irradiated Pillager, ACID & sniffs
DELETE FROM `smart_scripts` WHERE `entryorguid` = 6329 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6329,0,0,0,0,0,100,0,0,0,3600,7200,0,11,9771,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Irradiated Pillager - In Combat CMC - Cast 'Radiation Bolt'"),
(6329,0,1,2,2,0,100,1,0,50,0,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - Between 0-50% Health - Cast 'Frenzy' (No Repeat)"),
(6329,0,2,0,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Link - Say Line 1"),
(6329,0,3,4,6,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Death - Say Line 0"),
(6329,0,4,0,61,0,100,0,0,0,0,0,0,11,9798,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Pillager - On Link - Cast 'Radiation'");

DELETE FROM `creature_text` WHERE `CreatureID` = 6329 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(6329,1,0,"%s goes into a frenzy!",16,0,100,0,0,0,1191,0,"Irradiated Pillager");

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 6329) AND `path_id` = 0;
UPDATE `creature_addon` SET `bytes2` = 1, `auras` = "9769" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 6329);
DELETE FROM `creature_template_addon` WHERE `entry` = 6329;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(6329,0,0,0,1,0,0,"9769");
