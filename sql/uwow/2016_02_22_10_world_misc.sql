DELETE FROM `spell_proc_event` WHERE `entry` IN (44448);
INSERT INTO `spell_proc_event` VALUES (44448, 4, 3, 0, 0, 0, 0, 0, 0x00000C02, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (119032);
INSERT INTO `spell_proc_event` VALUES (119032, 0, 0, 0, 0, 0, 0, 0x000A22A8, 0, 0, 0, 0, 7);

UPDATE `areatrigger_actions` SET `aura`='-116014' WHERE (`entry`='304') AND (`id`='0');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `resizeType`, `count`, `maxcount`, `comments`) VALUES ('15290', '56', '1', '6', '15', 'Объятия вампира');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('15286', 'spell_pri_vampiric_embrace');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `comments`) VALUES ('15290', '56', '16', 'Объятия вампира');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('146200', 'spell_gen_spirit_of_chi_ji');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `resizeType`, `count`, `comments`) VALUES ('148009', '31', '1', '5', 'Spirit of Chi-Ji');
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `comments`) VALUES ('148009', '31', '16', 'Spirit of Chi-Ji');