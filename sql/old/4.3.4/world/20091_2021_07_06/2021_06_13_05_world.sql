DELETE FROM `achievement_criteria_data` WHERE `ScriptName` IN
('achievement_sun_of_a',
'achievement_i_hate_that_song');

DELETE FROM `world_states` WHERE `ID` IN (5638, 5653, 5639);
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5638, 0, 644, 'Halls of Origination - Temple Guardian Anhuur - I Hate That Song'),
(5653, 0, 644, 'Halls of Origination - Vault of Lights - Faster Than The Speed Of Light'),
(5639, 0, 644, 'Halls of Origination - Rajh - Sun of a...');
