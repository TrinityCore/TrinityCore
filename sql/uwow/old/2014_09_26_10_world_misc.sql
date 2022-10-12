DELETE FROM `spell_script_names` WHERE (`spell_id`='115203') AND (`ScriptName`='spell_monk_healing_elixirs');
DELETE FROM `spell_script_names` WHERE (`spell_id`='115288') AND (`ScriptName`='spell_monk_healing_elixirs');
DELETE FROM `spell_script_names` WHERE (`spell_id`='115399') AND (`ScriptName`='spell_monk_healing_elixirs');
DELETE FROM `spell_script_names` WHERE (`spell_id`='116680') AND (`ScriptName`='spell_monk_healing_elixirs');
DELETE FROM `spell_script_names` WHERE (`spell_id`='115294') AND (`ScriptName`='spell_monk_healing_elixirs');
DELETE FROM `spell_script_names` WHERE (`spell_id`='116740') AND (`ScriptName`='spell_monk_healing_elixirs');

DELETE FROM `spell_proc_check` WHERE `entry` IN (122280);

DELETE FROM `spell_proc_event` WHERE `entry` IN (122280);
INSERT INTO `spell_proc_event` VALUES (122280, 0, 0, 0, 0, 0, 0, 0, 0x00000003, 0, 100, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (134563);
INSERT INTO `spell_proc_event` VALUES (134563, 0, 0, 0, 2097152, 0, 0, 0, 0, 0, 100, 0, 7);

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('122281', '-134563', 'Healing Elixirs');