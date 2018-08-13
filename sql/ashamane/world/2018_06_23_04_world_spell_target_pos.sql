DELETE FROM `spell_target_position` WHERE (`ID`=176247 AND `EffectIndex`=0) OR (`ID`=224873 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(176247, 0, 1116, 3744.33, -4055.88, 46.549, 26822), -- Spell: Portal: Stormshield Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(224873, 0, 1220, -828.72, 4371.78, 738.64, 26822); -- Spell: Portal: Dalaran - Broken Isles Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `PositionX`=3744.33, `PositionY`=-4055.88, `PositionZ`=46.55, `VerifiedBuild`=26822 WHERE (`ID`=176248 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26822 WHERE (`ID`=224869 AND `EffectIndex`=0);
