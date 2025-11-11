--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kurinnaxx_sand_trap';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26524, 'spell_kurinnaxx_sand_trap');

-- Should be disturbed instead (activate object action)
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 180647;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 180647 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(180647,1,0,0,60,0,100,1,4500,4500,0,0,0,11,25656,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Trap - On Update - Cast 'Sand Trap' (No Repeat)"),
(180647,1,1,0,60,0,100,1,4500,4500,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Trap - On Update - Despawn (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 15348;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15348,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Kurinnaxx EMOTE_FRENZY");

UPDATE `creature_text` SET `TextRange` = 3 WHERE `CreatureID` = 15339 AND `GroupID` = 5;
