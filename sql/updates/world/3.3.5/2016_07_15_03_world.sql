--
DELETE FROM `spell_target_position` WHERE `ID`=42200;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(42200, 0, 1, 5010.165039, -4554.938965, 852.146362, 0.883979, 0);

DELETE FROM `spell_area` WHERE `spell`=42202;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(42202, 616, 0, 0, 0, 0, 2, 1, 64, 11);
