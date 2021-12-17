-- Sjonnir
UPDATE `creature_text` SET `Type` = 14, `Sound` = 14181 WHERE `CreatureID` = 27978 AND `GroupID` = 1 AND `ID` = 2;
DELETE FROM `creature_text` WHERE `CreatureID` = 27978 AND `GroupID` = 3;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27978,3,0,"%s goes into a frenzy!",16,0,100,0,0,0,1191,0,"Sjonnir EMOTE_FRENZY");

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (50792,50801);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(50792,50792,59859,0,0),
(50801,50801,59858,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (50790,50791,50793,50794,50802,50803,50825,50826);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,50790,0,0,31,0,3,22515,126813,0,0,0,"","Group 0: Spell 'Summon Iron Dwarf' (Effect 1) targets creature 'World Trigger'"),
(13,2,50790,0,0,31,0,5,192163,0,0,0,0,"","Group 0: Spell 'Summon Iron Dwarf' (Effect 2) targets object 'Left Pipe'"),

(13,1,50791,0,0,31,0,3,22515,126812,0,0,0,"","Group 0: Spell 'Summon Iron Dwarf' (Effect 1) targets creature 'World Trigger'"),
(13,2,50791,0,0,31,0,5,192164,0,0,0,0,"","Group 0: Spell 'Summon Iron Dwarf' (Effect 2) targets object 'Right Pipe'"),

(13,1,50793,0,0,31,0,3,22515,126813,0,0,0,"","Group 0: Spell 'Summon Iron Trogg' (Effect 1) targets creature 'World Trigger'"),
(13,1,50794,0,0,31,0,3,22515,126812,0,0,0,"","Group 0: Spell 'Summon Iron Trogg' (Effect 1) targets creature 'World Trigger'"),

(13,1,50802,0,0,31,0,3,22515,126813,0,0,0,"","Group 0: Spell 'Summon Malformed Ooze' (Effect 1) targets creature 'World Trigger'"),
(13,2,50802,0,0,31,0,5,192163,0,0,0,0,"","Group 0: Spell 'Summon Malformed Ooze' (Effect 2) targets object 'Left Pipe'"),

(13,1,50803,0,0,31,0,3,22515,126812,0,0,0,"","Group 0: Spell 'Summon Malformed Ooze' (Effect 1) targets creature 'World Trigger'"),
(13,2,50803,0,0,31,0,5,192164,0,0,0,0,"","Group 0: Spell 'Summon Malformed Ooze' (Effect 2) targets object 'Right Pipe'"),

(13,1,50825,0,0,31,0,3,22515,126813,0,0,0,"","Group 0: Spell 'Summon Earthen Dwarf' (Effect 1) targets creature 'World Trigger'"),
(13,2,50825,0,0,31,0,5,192163,0,0,0,0,"","Group 0: Spell 'Summon Earthen Dwarf' (Effect 2) targets object 'Left Pipe'"),

(13,1,50826,0,0,31,0,3,22515,126812,0,0,0,"","Group 0: Spell 'Summon Earthen Dwarf' (Effect 1) targets creature 'World Trigger'"),
(13,2,50826,0,0,31,0,5,192164,0,0,0,0,"","Group 0: Spell 'Summon Earthen Dwarf' (Effect 2) targets object 'Right Pipe'");

DELETE FROM `spell_script_names` WHERE
(`spell_id` = 50789 AND `ScriptName` = 'spell_sjonnir_periodic_summon_iron_dwarf') OR
(`spell_id` = 50792 AND `ScriptName` = 'spell_sjonnir_periodic_summon_iron_trogg') OR
(`spell_id` = 59859 AND `ScriptName` = 'spell_sjonnir_periodic_summon_iron_trogg') OR
(`spell_id` = 50801 AND `ScriptName` = 'spell_sjonnir_periodic_summon_malformed_ooze') OR
(`spell_id` = 59858 AND `ScriptName` = 'spell_sjonnir_periodic_summon_malformed_ooze') OR
(`spell_id` = 50824 AND `ScriptName` = 'spell_sjonnir_periodic_summon_earthen_dwarf');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50789,'spell_sjonnir_periodic_summon_iron_dwarf'),
(50792,'spell_sjonnir_periodic_summon_iron_trogg'),
(59859,'spell_sjonnir_periodic_summon_iron_trogg'),
(50801,'spell_sjonnir_periodic_summon_malformed_ooze'),
(59858,'spell_sjonnir_periodic_summon_malformed_ooze'),
(50824,'spell_sjonnir_periodic_summon_earthen_dwarf');

-- Iron Sludge
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (50838);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(50838,50838,59853,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 50777 AND `ScriptName` = 'spell_sjonnir_iron_sludge_spawn_visual';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50777,'spell_sjonnir_iron_sludge_spawn_visual');

-- Malformed Ooze
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 0.571429 WHERE `entry` IN (27981,31388);
UPDATE `creature_template` SET `maxlevel` = 79 WHERE `entry` = 27981;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (50742,50747);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,50742,0,0,31,0,3,27981,0,0,0,0,"","Group 0: Spell 'Ooze Combine' (Effect 1) targets creature 'Malformed Ooze'"),
-- Prevents one creature get targeted by more than one creature
(13,1,50742,0,0,1,0,50741,0,0,0,0,0,"","Group 0: Spell 'Ooze Combine' (Effect 1) requires aura 'Ooze Combine' on target"),

(13,7,50747,0,0,31,0,3,27981,0,0,0,0,"","Group 0: Spell 'Summon Iron Sludge' (Effect 1 & 2 & 3) targets creature 'Malformed Ooze'"),
-- Check again target
(13,7,50747,0,0,1,0,50741,0,0,1,0,0,"","Group 0: Spell 'Summon Iron Sludge' (Effect 1 & 2 & 3) targets creature without aura 'Ooze Combine'");

-- Earthen Dwarf
UPDATE `creature_template` SET `speed_run` = 0.99206284114, `DamageModifier` = 2 WHERE `entry` = 27980;
UPDATE `creature_template` SET `speed_run` = 0.99206284114, `DamageModifier` = 2 WHERE `entry` = 31391;

-- Forged Iron Dwarf
UPDATE `creature_template` SET `speed_run` = 0.99206284114 WHERE `entry` IN (27982,31394);
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27982;

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (50895);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(50895,50895,59851,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27982 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27982,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forged Iron Dwarf - On AI Initialize - Set Corpse Delay"),
(27982,0,1,0,0,0,100,0,10000,10000,6000,6000,0,11,50895,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Forged Iron Dwarf - In Combat - Cast 'Lightning Tether'");

-- Forged Iron Trogg
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27979;

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (50900);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`, `spellid2`, `spellid3`) VALUES
(50900,50900,59852,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27979 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27979,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forged Iron Trogg - On AI Initialize - Set Corpse Delay"),
(27979,0,1,0,0,0,100,0,3000,5000,3000,5000,0,11,50900,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Forged Iron Trogg - In Combat - Cast 'Lightning Shock'");
