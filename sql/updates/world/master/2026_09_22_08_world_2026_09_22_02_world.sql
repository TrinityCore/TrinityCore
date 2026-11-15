-- Shirrak
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_shirrak_focus_fire';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32291, 'spell_shirrak_focus_fire');

UPDATE `creature_addon` SET `auras` = '33460' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 18371);

-- Maladaar
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_exarch_maladaar_stolen_soul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32346, 'spell_exarch_maladaar_stolen_soul');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19412 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1941200,1941201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19412,0,0,0,11,0,100,0,0,0,0,0,0,80,1941200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Spawn - Run Script"),
(19412,0,1,0,58,0,100,0,0,0,0,0,0,80,1941201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Waypoint Finished - Run Script"),

(1941200,9,0,0,0,0,100,0,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Set Fly On"),
(1941200,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Remove NPC Flag Questgiver"),
(1941200,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Say Line 0"),
(1941200,9,3,0,0,0,100,0,0,0,0,0,0,11,7765,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Cast 'Projection'"),
(1941200,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,155297,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Start Waypoint"),

(1941201,9,0,0,0,0,100,0,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Set Fly Off"),
(1941201,9,1,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D'ore - On Script - Add NPC Flag Questgiver");
