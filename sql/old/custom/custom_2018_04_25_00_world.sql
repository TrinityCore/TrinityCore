DELETE FROM `creature_template_addon` WHERE `entry`= 43499;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(43499, '81298');

UPDATE `creature_template` SET `unit_flags`= 33554440 WHERE `entry`= 43499;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_consecration';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26573, 'spell_pal_consecration');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (26573, 81297);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(81297, 0.04, 0, 0.04, 0, 'Paladin - Consecration');
