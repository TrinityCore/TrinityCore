-- Atonement
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_atonement_triggered', 'spell_pri_power_word_radiance', 'spell_pri_shadow_mend');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(194384, 'spell_pri_atonement_triggered'),
(214206, 'spell_pri_atonement_triggered'),
(194509, 'spell_pri_power_word_radiance'),
(186263, 'spell_pri_shadow_mend');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_pri_spirit_of_redemption' WHERE `ScriptName` = 'spell_priest_spirit_of_redemption';
