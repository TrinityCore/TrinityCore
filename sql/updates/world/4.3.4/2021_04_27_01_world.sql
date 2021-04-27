DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_brc_furious_swipe_dummy',
'spell_brc_furious_swipe');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80340, 'spell_brc_furious_swipe_dummy'),
(80206, 'spell_brc_furious_swipe');

DELETE FROM `spell_custom_attr` WHERE `entry`= 80206;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(80206, 0x4);
