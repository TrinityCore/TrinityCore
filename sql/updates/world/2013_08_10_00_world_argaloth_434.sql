DELETE FROM `spell_script_names` WHERE `spell_id` IN (88954,95173,88942,95172);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(88954,'spell_argaloth_consuming_darkness'),
(95173,'spell_argaloth_consuming_darkness'),
(88942,'spell_argaloth_meteor_slash'),
(95172,'spell_argaloth_meteor_slash');

UPDATE `creature_template` SET `ScriptName`='boss_pit_lord_argaloth' WHERE `entry`=47120;
UPDATE `creature_template` SET `faction_A`=85,`faction_H`=85,`faction_A`=16,`faction_H`=16,`flags_extra`=128 WHERE `entry`=47829;

DELETE FROM `creature_template_addon` WHERE `entry`=47829;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(47829, 0, 0x0, 0x1, '88999');
