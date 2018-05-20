DELETE FROM `spell_bonus_data` WHERE `entry` IN (53600, 35395, 879);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(53600, 0, 0, 0.1, 0, 'Paladin - Shield of the Righteous'),
(35395, 0, 0, 0.0, 0, 'Paladin - Crusader Strike'),
(879, 0, 0, 0, 0, 'Paladin - Exorcism');

-- Holy Wrath
UPDATE `spell_bonus_data` SET `direct_bonus`= 0.61, `dot_bonus`= 0, `ap_bonus`= 0, `ap_dot_bonus`= 0 WHERE `entry`= 2812;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_exorcism';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(879, 'spell_pal_exorcism');
