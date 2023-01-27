DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_druid_heart_of_the_wild';
REPLACE INTO spell_script_names VALUE
(108291, 'spell_druid_heart_of_the_wild'),
(108292, 'spell_druid_heart_of_the_wild'),
(108293, 'spell_druid_heart_of_the_wild'),
(108294, 'spell_druid_heart_of_the_wild');

DELETE FROM `spell_learn_spell` WHERE `entry` = 108288;
INSERT INTO `spell_learn_spell` VALUE
(108288, 17005, 0);