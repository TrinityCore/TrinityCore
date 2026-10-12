--
DELETE FROM `spell_script_names` WHERE
(`spell_id` = 33525 AND `ScriptName` = "spell_gruul_ground_slam") OR
(`spell_id` = 33965 AND `ScriptName` = "spell_gruul_look_around") OR
(`spell_id` = 33812 AND `ScriptName` = "spell_gruul_hurtful_strike_primer");
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33525,"spell_gruul_ground_slam"),
(33965,"spell_gruul_look_around"),
(33812,"spell_gruul_hurtful_strike_primer");

UPDATE `creature_text` SET `Text` = "%s roars!", `Type` = 16, `Sound` = 0, `BroadcastTextId` = 14029, `comment` = "gruul EMOTE_ROAR" WHERE `CreatureID` = 19044 AND `GroupID` = 4 AND `ID` = 0;
UPDATE `creature_text` SET `TextRange` = 3 WHERE `CreatureID` = 19044;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 19198;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19198 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19198,0,0,0,60,0,100,1,0,0,0,0,0,11,33496,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invisible Tractor Beam Source - On Update - Cast 'Tractor Beam Creator' (No Repeat)"),
(19198,0,1,0,60,0,100,1,500,500,0,0,0,11,33497,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Invisible Tractor Beam Source - On Update - Cast 'Tractor Beam' (No Repeat)"),
(19198,0,2,0,60,0,100,1,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Invisible Tractor Beam Source - On Update - Despawn Instant (No Repeat)");
