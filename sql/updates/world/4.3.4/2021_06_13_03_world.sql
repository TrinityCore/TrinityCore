DELETE FROM `achievement_criteria_data` WHERE `ScriptName` IN
('achievement_parasite_evening',
'achievement_full_of_sound_and_fury',
'achievement_keeping_it_in_the_family',
'achievement_silence_is_golden');

DELETE FROM `world_states` WHERE `ID` IN (5640, 5643, 5652, 5655);
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5640, 0, 669, 'Blackwing Descent - Magmaw - Parasite Evening'),
(5643, 0, 669, 'Blackwing Descent - Chimaeron - Full of Sound and Fury'),
(5652, 1, 669, 'Blackwing Descent - Nefarian\'s End - Keeping it in the Family'),
(5655, 0, 669, 'Blackwing Descent - Atramedes - Silence is Golden');
