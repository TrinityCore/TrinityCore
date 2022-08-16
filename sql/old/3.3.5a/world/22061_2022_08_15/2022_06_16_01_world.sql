--
DELETE FROM `spell_scripts` WHERE `id` = 55818;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 55818;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_storm_peaks_call_of_earth';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(55512,'spell_storm_peaks_call_of_earth');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29375,29503) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29375,0,0,0,0,0,100,0,0,10000,20000,25000,0,11,57741,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stormforged Iron Giant - In Combat - Cast 'Shockwave'"),
(29375,0,1,0,8,0,100,0,55818,0,0,0,0,11,55512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stormforged Iron Giant - On Spellhit 'Hurl Boulder' - Cast 'Call of Earth'"),

(29503,0,0,0,0,0,100,0,0,10000,20000,25000,0,11,57801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fjorn - In Combat - Cast 'Flame Breath'"),
(29503,0,1,0,8,0,100,0,55818,0,0,0,0,11,55512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fjorn - On Spellhit 'Hurl Boulder' - Cast 'Call of Earth'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 55818;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,55818,0,0,31,1,3,29375,0,0,0,0,"","Group 0: Spell 'Hurl Boulder' targets creature 'Stormforged Iron Giant'"),
(17,0,55818,0,1,31,1,3,29503,0,0,0,0,"","Group 1: Spell 'Hurl Boulder' targets creature 'Fjorn'");
