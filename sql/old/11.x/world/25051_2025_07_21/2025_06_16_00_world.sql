-- Spelltarget pos.
DELETE FROM `spell_target_position` WHERE (`ID`=18960 AND `EffectIndex`=1 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(18960, 1, 0, 1, 7995.56005859375, -2679.75, 512.489990234375, 61265); -- Spell: 18960 (Teleport: Moonglade) Effect 1: 252 (SPELL_EFFECT_TELEPORT_UNITS)
