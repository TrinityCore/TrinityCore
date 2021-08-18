-- Texts 2353 & 2351 are not used on retail so removed
DELETE FROM `creature_text` WHERE `CreatureID` IN (6172,6177) AND `GroupID` = 1;
DELETE FROM `spell_script_names` WHERE `spell_id` = 8593 AND `ScriptName` = 'spell_symbol_of_life_dummy';
UPDATE `creature_template` SET `unit_flags` = 768, `unit_flags2` = 0 WHERE `entry` IN (6172,6177);
UPDATE `creature_template_addon` SET `bytes1` = 7 WHERE `entry` IN (6172,6177);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6172,6177) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (617200,617700) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6172,0,0,0,25,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Reset - Remove NPC Flag Questgiver"),
(6172,0,1,0,8,0,100,0,8593,0,0,0,0,80,617200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Spellhit 'Symbol of Life' - Run Script"),

(617200,9,0,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Remove Flag Standstate Dead"),
(617200,9,1,0,0,0,100,0,0,0,0,0,0,11,25155,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Cast 'Quest - Self Healing from resurrect'"),
(617200,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Set Orientation Invoker"),
(617200,9,3,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Add NPC Flag Questgiver"),
(617200,9,4,0,0,0,100,0,2000,2000,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Say Line 0"),
(617200,9,5,0,0,0,100,0,120000,120000,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Henze Faulk - On Script - Evade"),

(6177,0,0,0,25,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Reset - Remove NPC Flag Questgiver"),
(6177,0,1,0,8,0,100,0,8593,0,0,0,0,80,617700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Spellhit 'Symbol of Life' - Run Script"),

(617700,9,0,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Remove Flag Standstate Dead"),
(617700,9,1,0,0,0,100,0,0,0,0,0,0,11,25155,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Cast 'Quest - Self Healing from resurrect'"),
(617700,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Set Orientation Invoker"),
(617700,9,3,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Add NPC Flag Questgiver"),
(617700,9,4,0,0,0,100,0,2000,2000,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Say Line 0"),
(617700,9,5,0,0,0,100,0,120000,120000,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Narm Faulk - On Script - Evade");
