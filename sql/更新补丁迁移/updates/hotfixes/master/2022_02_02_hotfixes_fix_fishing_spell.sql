/*
**************************
*    BfaCore Reforged    *
**************************
*/

-- Learn Fishing and Fishing skills
DELETE FROM `spell_effect` WHERE `ID`IN (721957,721958);
INSERT INTO `spell_effect` (`ID`, `EffectAura`, `DifficultyID`, `EffectIndex`, `Effect`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES
(721957, 0, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 271990, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 271617, 35662),
(721958, 0, 0, 1, 36, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 131474, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 271617, 35662);

DELETE FROM `hotfix_data` WHERE `RecordId` IN (721957,721958);
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`, `VerifiedBuild`) VALUES
(271617, 4030871717, 721957, 0, 35662),
(271617, 4030871717, 721958, 0, 35662);
