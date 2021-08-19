DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_prayer_of_mending_heal','spell_pri_prayer_of_mending','spell_pri_prayer_of_mending_aura','spell_pri_prayer_of_mending_jump');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(33076, 'spell_pri_prayer_of_mending'),
(41635, 'spell_pri_prayer_of_mending_aura'),
(155793, 'spell_pri_prayer_of_mending_jump');
