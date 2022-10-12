DELETE FROM `spell_proc_event` WHERE `entry` IN (114925);
INSERT INTO `spell_proc_event` VALUES (114925, 0, 0, 1, 268435456+128, 0, 0, 0, 0, 0, 0, 0, 7);

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('114925', '104317', '20', 'Demonic Calling');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('104317', '-114925', 'Demonic Calling');

DELETE FROM `spell_script_names` WHERE (`spell_id`='103964') AND (`ScriptName`='spell_warl_demonic_call');
DELETE FROM `spell_script_names` WHERE (`spell_id`='686') AND (`ScriptName`='spell_warl_demonic_call');
DELETE FROM `spell_script_names` WHERE (`spell_id`='6353') AND (`ScriptName`='spell_warl_demonic_call');