-- Add one spell_target_position for future need (The Purification of Quel'Delar)
DELETE FROM `spell_target_position` WHERE `ID`=70746;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(70746, 0, 580, 1766.94, 683.09, 71.2, 2.268928, 15354);
