--
UPDATE `creature_template` SET `ScriptName` = 'boss_celebras_the_cursed' WHERE `entry` = 12225;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_noxxion_summon_spawns';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(21708, 'spell_noxxion_summon_spawns');
