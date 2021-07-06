DELETE FROM `achievement_criteria_data` WHERE `ScriptName` IN
('achievement_the_only_escape',
'achievement_elementary',
'achievement_the_abyss_will_gaze_into_you');

DELETE FROM `world_states` WHERE `ID` IN (5607, 5621, 5659);
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5607, 0, 671, 'Bastion of Twilight - Halfus Wyrmbreaker - The Only Escape'),
(5621, 0, 671, 'Bastion of Twilight - Ascendant Council - Elementary'),
(5659, 0, 671, 'Bastion of Twilight - Cho\'Gall - The Abyss Will Gate Back Into You');
