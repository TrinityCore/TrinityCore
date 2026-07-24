-- Kalec
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 24844;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 24848;
UPDATE `waypoint_data` SET `orientation` = NULL WHERE `id` = 248440 AND `point` = 8;
UPDATE `waypoint_data` SET `move_type` = 1 WHERE `id` = 248440;

-- Vexallus
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_vexallus_clear_energy_feedback',
'spell_vexallus_energy_feedback');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47108, 'spell_vexallus_clear_energy_feedback'),
(44328, 'spell_vexallus_energy_feedback');

DELETE FROM `creature_text` WHERE `CreatureID` = 24744 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24744,5,0,"Vexallus overloads!",41,0,100,0,0,0,23781,0,"vexallus EMOTE_OVERLOAD");
