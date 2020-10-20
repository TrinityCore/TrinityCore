DELETE FROM `hotfix_data` WHERE (`VerifiedBuild`>0) AND (`Id` = 57431) AND (`TableHash` = 666345498) AND (`RecordId` = 324156);
DELETE FROM `hotfix_data` WHERE (`VerifiedBuild`>0) AND (`Id` = 57431) AND (`TableHash` = 666345498) AND (`RecordId` = 324155);
DELETE FROM `hotfix_data` WHERE (`VerifiedBuild`>0) AND (`Id` = 57431) AND (`TableHash` = 666345498) AND (`RecordId` = 324154);
DELETE FROM `hotfix_data` WHERE (`VerifiedBuild`>0) AND (`Id` = 57422) AND (`TableHash` = 3322146344) AND (`RecordId` = 387563);
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`, `VerifiedBuild`) VALUES
(57431, 666345498, 324156, 0, 35662),
(57431, 666345498, 324155, 0, 35662),
(57431, 666345498, 324154, 0, 35662),
(57422, 3322146344, 387563, 0, 35662);

DELETE FROM `spell_x_spell_visual` WHERE `VerifiedBuild`>0 AND `ID` IN (306736, 288388, 287082, 287070, 286200, 285863, 285861, 285855, 285852, 285847, 285846, 285765, 285764, 285754, 285728, 285546, 285487, 285410, 285321, 285305, 285276, 285273, 285271, 285264, 285263, 285262, 285260, 285233, 285171, 285170, 285094, 285093, 285092, 285091, 285090, 285089, 285088, 285087, 285086, 285085, 285084, 285083, 284522, 282785, 281723, 279872, 279245, 276669, 274850, 273883, 273075, 273074, 266870, 261474, 261126, 261098, 261097, 261095, 123709);

DELETE FROM `spell_x_spell_visual` WHERE `VerifiedBuild`>0 AND `ID` IN (324156, 324155, 324154);
INSERT INTO `spell_x_spell_visual` (`ID`, `DifficultyID`, `SpellVisualID`, `Probability`, `Flags`, `Priority`, `SpellIconFileID`, `ActiveIconFileID`, `ViewerUnitConditionID`, `ViewerPlayerConditionID`, `CasterUnitConditionID`, `CasterPlayerConditionID`, `SpellID`, `VerifiedBuild`) VALUES
(324156, 0, 30846, 1, 0, 0, 0, 0, 0, 0, 0, 0, 139156, 35662),
(324155, 0, 30846, 1, 0, 0, 0, 0, 0, 0, 0, 0, 139155, 35662),
(324154, 0, 30846, 1, 0, 0, 0, 0, 0, 0, 0, 0, 139154, 35662);

DELETE FROM `spell_misc` WHERE `VerifiedBuild`>0 AND `ID` = 387563;
INSERT INTO `spell_misc` (`ID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `DifficultyID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `Speed`, `LaunchDelay`, `MinDuration`, `SpellIconFileDataID`, `ActiveIconFileDataID`, `ContentTuningID`, `SpellID`, `VerifiedBuild`) VALUES
(387563, 603979776, 0, 0, 1064960, 0, 4, 0, 0, 0, 0, 8192, 0, 0, 0, 0, 1, 562, 1, 1, 0, 0, 0, 3192688, 0, 0, 313015, 35662);
