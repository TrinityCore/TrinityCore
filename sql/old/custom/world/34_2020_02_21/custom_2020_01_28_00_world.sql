DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_magmaw_eject_passenger_1',
'spell_magmaw_eject_passenger_3',
'spell_gen_eject_passenger') AND `spell_id` IN (95204, 77946);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95204, 'spell_gen_eject_passenger'),
(77946, 'spell_gen_eject_passenger');

UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry` IN (41620, 41789);
