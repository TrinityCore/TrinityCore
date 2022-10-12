DELETE FROM `spell_proc_event` WHERE `entry` IN (12846);
INSERT INTO `spell_proc_event` VALUES (12846, 0, 0, 16+1+4194304, 4096, 2097152, 0, 0, 0, 0, 0, 0, 7);

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `type2`, `hitmask`, `comment`) VALUES ('108853', '118280', '12654', '1', '1', 'Inferno Blast');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `type2`, `hitmask`, `comment`) VALUES ('108853', '118280', '83853', '1', '1', 'Inferno Blast');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `type2`, `hitmask`, `comment`) VALUES ('108853', '118280', '11366', '1', '1', 'Inferno Blast');

DELETE FROM `spell_script_names` WHERE (`spell_id`='108853') AND (`ScriptName`='spell_mage_inferno_blast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='2136') AND (`ScriptName`='spell_mage_inferno_blast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('118280', 'spell_mage_inferno_blast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='118280') AND (`ScriptName`='spell_mage_inferno_blast_impact');