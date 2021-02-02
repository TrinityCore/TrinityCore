DELETE FROM `spell_script_names` WHERE `spell_id` IN (33110, 33076, 41635, 155793);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
  (33076, 'spell_pri_prayer_of_mending'),
  (41635, 'spell_pri_prayer_of_mending_aura'),
  (155793, 'spell_pri_prayer_of_mending_jump');
