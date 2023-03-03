INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('146193', 'spell_endurance_of_niuzao');

DELETE FROM `spell_bonus_data` WHERE (`entry`='148008');
INSERT INTO `spell_bonus_data` (`entry`, `comments`) VALUES ('148008', 'Essence of Yulon');

INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `comment`) VALUES ('146197', '-148008', 'Essence of Yulon');
INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `comment`) VALUES ('146199', '-148009', 'Spirit of Chi-Ji');
INSERT INTO `spell_proc_check` (`entry`, `checkspell`, `comment`) VALUES ('146195', '-147891', 'Flurry of Xuen');