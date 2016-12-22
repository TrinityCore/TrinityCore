-- Server-side Spell (Hotfix DB)
SET @MISCID := 500000;
SET @EFFECTID := 600000;
SET @INTERRUPTID := 100000;
DELETE FROM `spell` WHERE  `ID` IN (184561, 184562, 184563, 204711, 204712, 204714, 204715, 196030, 198253);
INSERT INTO `spell` (`Name`, `NameSubtext`, `Description`, `AuraDescription`, `MiscID`, `ID`, `DescriptionVariablesID`, `VerifiedBuild`) VALUES 
('Enter the Illidari: Ashtongue - Legion Gateway Kill Credit', NULL, NULL, NULL, @MISCID, 184561, 0, 0),
('Enter the Illidari: Coilskar - Legion Gateway Kill Credit', NULL, NULL, NULL, @MISCID+1, 184562, 0, 0),
('Enter the Illidari: Coilskar - Legion Gateway Kill Credit', NULL, NULL, NULL, @MISCID+2, 184563, 0, 0),
('Set Them Free: Cyana Nightglaive Freed Kill Credit', NULL, NULL, NULL, @MISCID+3, 204711, 0, 0),
('Set Them Free: Belath Dawnblade Freed Kill Credit', NULL, NULL, NULL, @MISCID+4, 204712, 0, 0),
('Set Them Free: Izal Whitemoon Freed Kill Credit', NULL, NULL, NULL, @MISCID+5, 204714, 0, 0),
('Set Them Free: Mannethrel Darkstar Freed Kill Credit', NULL, NULL, NULL, @MISCID+6, 204715, 0, 0),
('Start: Quest Invis', NULL, NULL, NULL, @MISCID+7, 196030, 0, 0),
('Meeting With The Queen: Ritual Completed Kill Credit', NULL, NULL, NULL, @MISCID+8, 198253, 0, 0);
DELETE FROM `spell_misc` WHERE  `ID` BETWEEN @MISCID AND @MISCID+8;
INSERT INTO `spell_misc` (`ID`, `Attributes`, `AttributesEx`, `AttributesExB`, `AttributesExC`, `AttributesExD`, `AttributesExE`, `AttributesExF`, `AttributesExG`, `AttributesExH`, `AttributesExI`, `AttributesExJ`, `AttributesExK`, `AttributesExL`, `AttributesExM`, `Speed`, `MultistrikeSpeedMod`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SpellIconID`, `ActiveIconID`, `SchoolMask`, `VerifiedBuild`) VALUES 
(@MISCID, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+1, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+2, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+3, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+4, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+5, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+6, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(@MISCID+7, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 1, 0),
(@MISCID+8, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 1, 0);
DELETE FROM `spell_effect` WHERE  `SpellID` IN (184561, 184562, 184563, 204711, 204712, 204714, 204715, 196030, 198253);
INSERT INTO `spell_effect` (`EffectAmplitude`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `EffectPosFacing`, `BonusCoefficientFromAP`, `ID`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAuraPeriod`, `EffectBasePoints`, `EffectChainTargets`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectTriggerSpell`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `EffectIndex`, `EffectAttributes`, `VerifiedBuild`) VALUES 
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID, 0, 90, 0, 0, 1, 0, 0, 0, 0, 88872, 0, 0, 0, 0, 1, 0, 184561, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+1, 0, 90, 0, 0, 1, 0, 0, 0, 0, 94406, 0, 0, 0, 0, 1, 0, 184562, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+2, 0, 90, 0, 0, 1, 0, 0, 0, 0, 94407, 0, 0, 0, 0, 1, 0, 184563, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+3, 0, 90, 0, 0, 1, 0, 0, 0, 0, 94377, 0, 0, 0, 0, 1, 0, 204711, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+4, 0, 90, 0, 0, 1, 0, 0, 0, 0, 94400, 0, 0, 0, 0, 1, 0, 204712, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+5, 0, 90, 0, 0, 1, 0, 0, 0, 0, 93117, 0, 0, 0, 0, 1, 0, 204714, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+6, 0, 90, 0, 0, 1, 0, 0, 0, 0, 93230, 0, 0, 0, 0, 1, 0, 204715, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+7, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 196030, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+8, 0, 90, 0, 0, 1, 0, 0, 0, 0, 100722, 0, 0, 0, 0, 1, 0, 198253, 0, 0, 0);
DELETE FROM `spell_interrupts` WHERE `SpellID` IN (196030);
INSERT INTO `spell_interrupts` (`ID`, `SpellID`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `InterruptFlags`, `DifficultyID`, `VerifiedBuild`) VALUES 
(@INTERRUPTID, 196030, 40, 0, 0, 0, 23, 0, 0);
