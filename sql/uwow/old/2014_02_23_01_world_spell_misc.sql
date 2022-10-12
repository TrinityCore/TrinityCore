INSERT INTO `spell_proc_check` (`entry`, `entry2`, `checkspell`, `hastalent`, `chance`, `target`, `comment`) VALUES ('2094', '1776', '-89775', '108216', '100', '1', 'Dirty Tricks - (Hemo)');
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `checkspell`, `hastalent`, `chance`, `target`, `comment`) VALUES ('2094', '1776', '-703', '108216', '100', '1', 'Dirty Tricks - (Garrote)');
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `checkspell`, `hastalent`, `chance`, `target`, `comment`) VALUES ('2094', '1776', '-1943', '108216', '100', '1', 'Dirty Tricks - (Rupture)');
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `checkspell`, `hastalent`, `chance`, `target`, `comment`) VALUES ('2094', '1776', '-2818', '108216', '100', '1', 'Dirty Tricks - (Deadly Poison)');

DELETE FROM `spell_proc_event` WHERE `entry` IN (6770);
INSERT INTO `spell_proc_event` VALUES (6770, 0, 0, 0, 0, 0, 0, 0x000A22A8, 0, 0, 100, 0, 7);