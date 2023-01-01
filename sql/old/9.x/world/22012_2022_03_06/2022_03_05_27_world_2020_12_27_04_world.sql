--
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` BETWEEN 57995 AND 57999; -- Portal 1-5 Ready
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 58019; -- Portal Ready Primer
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 58011; -- Portal Channel Trigger
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 58014; -- Close Portal Trigger
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 58018; -- Close Portal Effect
UPDATE `serverside_spell` SET `ProcChance` = 101 WHERE `Id` = 58002; -- Summon Portal

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (57995,57996,57997,57998,57999,58019,58011,58014,58018,58002);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `Effect`, `EffectChainAmplitude`, `EffectRadiusIndex1`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(57995, 0, 77, 1, 0, 1, 0),
(57996, 0, 77, 1, 0, 1, 0),
(57997, 0, 77, 1, 0, 1, 0),
(57998, 0, 77, 1, 0, 1, 0),
(57999, 0, 77, 1, 0, 1, 0),
(58019, 0, 77, 1, 28, 22, 7),
(58011, 0, 77, 1, 0, 1, 0),
(58014, 0, 77, 1, 0, 1, 0),
(58018, 0, 77, 1, 0, 25, 0),
(58002, 0,  3, 1, 36, 1, 0);
