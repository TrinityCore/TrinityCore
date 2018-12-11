SET @MISCID := 501000;
SET @EFFECTID := 501000;
SET @INTERRUPTID := 501000;

DELETE FROM `spell_name` WHERE  `ID` IN (184561, 184562, 184563, 204711, 204712, 204714, 204715, 196030, 198253, 191095);
INSERT INTO `spell_name` (`ID`, `Name`, `VerifiedBuild`) VALUES 
(184561, 'Enter the Illidari: Ashtongue - Legion Gateway Kill Credit', 0),
(184562, 'Enter the Illidari: Coilskar - Legion Gateway Kill Credit', 0),
(184563, 'Enter the Illidari: Coilskar - Legion Gateway Kill Credit', 0),
(204711, 'Set Them Free: Cyana Nightglaive Freed Kill Credit', 0),
(204712, 'Set Them Free: Belath Dawnblade Freed Kill Credit', 0),
(204714, 'Set Them Free: Izal Whitemoon Freed Kill Credit', 0),
(204715, 'Set Them Free: Mannethrel Darkstar Freed Kill Credit', 0),
(196030, 'Start: Quest Invis', 0),
(198253, 'Meeting With The Queen: Ritual Completed Kill Credit', 0),
(191095, 'Give Me Sight Beyond Sight: Periodic Trigger Aura', 0);

DELETE FROM `spell_misc` WHERE  `ID` BETWEEN @MISCID AND @MISCID+9;
INSERT INTO `spell_misc` (`SpellID`, `ID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `Speed`, `LaunchDelay`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SpellIconFileDataID`, `ActiveIconFileDataID`, `SchoolMask`, `VerifiedBuild`) VALUES
(184561, @MISCID, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(184562, @MISCID+1, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(184563, @MISCID+2, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(204711, @MISCID+3, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(204712, @MISCID+4, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(204714, @MISCID+5, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(204715, @MISCID+6, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0),
(196030, @MISCID+7, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 1, 0),
(198253, @MISCID+8, 696254848, 1056, 273170437, 269681408, 8388736, 393224, 4608, 0, 0, 1048576, 0, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 1, 0),
(191095, @MISCID+9, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21, 1, 1, 0, 1, 0);


DELETE FROM `spell_effect` WHERE  `SpellID` IN (184561, 184562, 184563, 204711, 204712, 204714, 204715, 196030, 198253, 191095);
INSERT INTO `spell_effect` (`EffectAmplitude`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectPointsPerResource`, `EffectRealPointsPerLevel`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `EffectPosFacing`, `BonusCoefficientFromAP`, `ID`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAuraPeriod`, `EffectBasePoints`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectTriggerSpell`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `EffectIndex`, `EffectAttributes`, `VerifiedBuild`) VALUES 
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID, 0, 90, 0, 0, 1, 0, 0, 0, 88872, 0, 0, 0, 0, 1, 0, 184561, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+1, 0, 90, 0, 0, 1, 0, 0, 0, 94406, 0, 0, 0, 0, 1, 0, 184562, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+2, 0, 90, 0, 0, 1, 0, 0, 0, 94407, 0, 0, 0, 0, 1, 0, 184563, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+3, 0, 90, 0, 0, 1, 0, 0, 0, 94377, 0, 0, 0, 0, 1, 0, 204711, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+4, 0, 90, 0, 0, 1, 0, 0, 0, 94400, 0, 0, 0, 0, 1, 0, 204712, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+5, 0, 90, 0, 0, 1, 0, 0, 0, 93117, 0, 0, 0, 0, 1, 0, 204714, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+6, 0, 90, 0, 0, 1, 0, 0, 0, 93230, 0, 0, 0, 0, 1, 0, 204715, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+7, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 196030, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+8, 0, 90, 0, 0, 1, 0, 0, 0, 100722, 0, 0, 0, 0, 1, 0, 198253, 0, 0, 0),
(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, @EFFECTID+9, 0, 6, 226, 1500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 191095, 0, 0, 0);

DELETE FROM `spell_interrupts` WHERE `SpellID` IN (196030);
INSERT INTO `spell_interrupts` (`ID`, `SpellID`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `InterruptFlags`, `DifficultyID`, `VerifiedBuild`) VALUES 
(@INTERRUPTID, 196030, 40, 0, 0, 0, 23, 0, 0);