DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_valiona_twilight_meteorite',
'spell_valiona_blackout_damage');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86014, 'spell_valiona_twilight_meteorite'),
(92863, 'spell_valiona_twilight_meteorite'),
(92864, 'spell_valiona_twilight_meteorite'),
(92865, 'spell_valiona_twilight_meteorite'),
(86825, 'spell_valiona_blackout_damage'),
(92879, 'spell_valiona_blackout_damage'),
(92880, 'spell_valiona_blackout_damage'),
(92881, 'spell_valiona_blackout_damage');
