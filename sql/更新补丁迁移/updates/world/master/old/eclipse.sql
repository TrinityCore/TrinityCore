DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_druid_eclipse_buff';
REPLACE INTO spell_script_names VALUES
(48517, 'spell_druid_eclipse_buff'),
(48518, 'spell_druid_eclipse_buff');

DELETE FROM `spell_proc_event` WHERE `entry` = 79577;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `procFlags`, `CustomChance`) VALUES
(79577, 127, 0x00010000, 100);