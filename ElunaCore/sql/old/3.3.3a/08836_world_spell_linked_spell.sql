-- Make the Ardent Defender heal (66235) trigger the visuals (66233)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66235;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (66235,66233,0, 'Ardent Defender Visuals');
