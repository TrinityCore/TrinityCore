-- Stratholme - Baron Rivendare - Set position for each Raise Dead spell (1-6)
DELETE FROM `spell_target_position` WHERE `ID` IN (17475, 17476, 17477, 17478, 17479, 17480);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(17475, 0, 329, 4017.403809, -3339.703369, 115.057655, 5.487860, 0),
(17476, 0, 329, 4013.189209, -3351.808350, 115.052254, 0.134280, 0),
(17477, 0, 329, 4017.738037, -3363.478016, 115.057274, 0.723313, 0),
(17478, 0, 329, 4048.877197, -3363.223633, 115.054253, 3.627735, 0),
(17479, 0, 329, 4051.777588, -3350.893311, 115.055351, 3.066176, 0),
(17480, 0, 329, 4048.375977, -3339.966309, 115.055222, 2.457497, 0);

-- Stratholme - Baron Rivendare - Add missing emotes
DELETE FROM `creature_text` WHERE `CreatureID` IN (10440);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10440, 0, 0, '%s raises an undead servant back to life!'      , 16, 0, 0, 0, 0, 0, 6511, 0, 'Baron Rivendare - EMOTE_RAISE_DEAD'),
(10440, 1, 0, '%s attempts to cast Death Pact on his servants!', 16, 0, 0, 0, 0, 0, 6512, 0, 'Baron Rivendare - EMOTE_DEATH_PACT');
