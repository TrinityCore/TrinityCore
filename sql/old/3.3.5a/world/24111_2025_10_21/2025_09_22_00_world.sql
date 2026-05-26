-- Intro
DELETE FROM `areatrigger_scripts` WHERE `entry` = 4853;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4853, 'at_the_dead_scar');

DELETE FROM `spawn_group` WHERE `spawnType` = 0 AND `spawnId` IN (SELECT `guid` FROM `creature` WHERE `id` = 24895);
DELETE FROM `creature` WHERE `id` = 24895;

UPDATE `creature_template_movement` SET `Flight` = 1 WHERE `CreatureId` = 24895;

UPDATE `creature_template` SET `ScriptName` = 'npc_madrigosa' WHERE `entry` = 24895;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (46609,46610,44872,44844,44883,44884,46637,46638);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46609,0,0,31,0,3,19871,0,0,0,0,"","Group 0: Spell 'Freeze' (Effect 0) targets creature 'World Trigger (Not Immune NPC)'"),
(13,1,46610,0,0,31,0,5,188119,0,0,0,0,"","Group 0: Spell 'Freeze' (Effect 0) targets object 'Doodad_Sunwell_Ice_Barrier01'"),
(13,1,44872,0,0,31,0,3,24882,0,0,0,0,"","Group 0: Spell 'Frost Blast' (Effect 0) targets creature 'Brutallus'"),
(13,3,44844,0,0,31,0,3,24895,0,0,0,0,"","Group 0: Spell 'Fel Fireball' (Effect 0, 1) targets creature 'Madrigosa'"),
(13,1,44883,0,0,31,0,3,24882,0,0,0,0,"","Group 0: Spell 'Encapsulate' (Effect 0) targets creature 'Brutallus'"),
(13,1,44884,0,0,31,0,3,24895,0,0,0,0,"","Group 0: Spell 'Charge' (Effect 0) targets creature 'Madrigosa'"),
(13,1,46637,0,0,31,0,3,19871,0,0,0,0,"","Group 0: Spell 'Break Ice' (Effect 0) targets creature 'World Trigger (Not Immune NPC)'"),
(13,1,46638,0,0,31,0,5,188119,0,0,0,0,"","Group 0: Spell 'Break Ice' (Effect 0) targets object 'Doodad_Sunwell_Ice_Barrier01'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_brutallus_freeze',
'spell_brutallus_break_ice',
'spell_brutallus_burn_primer',
'spell_brutallus_burn_ally');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46609, 'spell_brutallus_freeze'),
(46637, 'spell_brutallus_break_ice'),
(45141, 'spell_brutallus_burn_primer'),
(45151, 'spell_brutallus_burn_ally');

UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 24882 AND `GroupID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 25224 WHERE `CreatureID` = 24882 AND `GroupID` = 2;
UPDATE `creature_text` SET `Text` = "That was fun, but I still await a true challenge!", `Language` = 0, `BroadcastTextId` = 25225 WHERE `CreatureID` = 24882 AND `GroupID` = 3;

-- Outro
UPDATE `creature_template` SET `AIName` = 'SmartAI', `flags_extra` = `flags_extra` |128 WHERE `entry` = 25703;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25703 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25703,0,0,0,60,0,100,1,7000,7000,0,0,0,11,45212,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brutallus Death Cloud - On Update - Cast 'Brutallus Death Cloud' (No Repeat)");
