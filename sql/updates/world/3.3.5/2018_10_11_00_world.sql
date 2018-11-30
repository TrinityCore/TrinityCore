-- 
DELETE FROM `spell_target_position` WHERE (`ID`=57515 AND `EffectIndex`=1) OR (`ID`=65138 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(57515, 1, 1, 7845.03, -2222.38, 469.268, 26899), -- Spell: Waking from a Fitful Dream Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(65138, 0, 571, 4042.93, 7097.24, 171, 26365); -- Spell: Summon Keristrasza Vehicle Efffect: 28 (SPELL_EFFECT_SUMMON)
