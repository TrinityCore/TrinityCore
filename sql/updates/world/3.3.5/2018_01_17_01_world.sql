-- Reanimated Abomination Abilities
UPDATE `creature_template` SET `spell1` = 59564, `spell2` = 59576 WHERE `entry` = 31692;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q13264_thats_abominable';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(59576, 'spell_q13264_thats_abominable');
