DELETE FROM `spell_x_spell_visual` WHERE `ID` IN (288388) AND `VerifiedBuild` > 0;
INSERT INTO `spell_x_spell_visual` (`ID`, `DifficultyID`, `SpellVisualID`, `Probability`, `Flags`, `Priority`, `SpellIconFileID`, `ActiveIconFileID`, `ViewerUnitConditionID`, `ViewerPlayerConditionID`, `CasterUnitConditionID`, `CasterPlayerConditionID`, `SpellID`, `VerifiedBuild`) VALUES 
(288388, 0, 97590, 1, 0, 0, 0, 0, 0, 0, 0, 0, 326390, 34963);

DELETE FROM `spell_power` WHERE `ID` IN (191881, 74) AND `VerifiedBuild` > 0;
INSERT INTO `spell_power` (`ID`, `OrderIndex`, `ManaCost`, `ManaCostPerLevel`, `ManaPerSecond`, `PowerDisplayID`, `AltPowerBarID`, `PowerCostPct`, `PowerCostMaxPct`, `PowerPctPerSecond`, `PowerType`, `RequiredAuraSpellID`, `OptionalCost`, `SpellID`, `VerifiedBuild`) VALUES 
(191881, 0, 0, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0, 264178, 34963),
(74, 0, 0, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0, 686, 34963);

DELETE FROM `spell_misc` WHERE `ID` IN (400993) AND `VerifiedBuild` > 0;
INSERT INTO `spell_misc` (`ID`, `Attributes1`, `Attributes2`, `Attributes3`, `Attributes4`, `Attributes5`, `Attributes6`, `Attributes7`, `Attributes8`, `Attributes9`, `Attributes10`, `Attributes11`, `Attributes12`, `Attributes13`, `Attributes14`, `DifficultyID`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `Speed`, `LaunchDelay`, `MinDuration`, `SpellIconFileDataID`, `ActiveIconFileDataID`, `ContentTuningID`, `SpellID`, `VerifiedBuild`) VALUES 
(400993, 269582608, 0, 0, 0, 0, 0, 131072, 0, 4096, 0, 0, 0, 0, 0, 0, 16, 21, 1, 1, 0, 0, 0, 2843118, 0, 0, 326390, 34963);

DELETE FROM `sound_kit` WHERE `ID` IN (155029, 155028, 155026, 155025, 155024, 155023, 155022, 155021, 155020, 155019, 155018, 155017, 155016) AND `VerifiedBuild` > 0;
INSERT INTO `sound_kit` (`ID`, `SoundType`, `VolumeFloat`, `Flags`, `MinDistance`, `DistanceCutoff`, `EAXDef`, `SoundKitAdvancedID`, `VolumeVariationPlus`, `VolumeVariationMinus`, `PitchVariationPlus`, `PitchVariationMinus`, `DialogType`, `PitchAdjust`, `BusOverwriteID`, `MaxInstances`, `VerifiedBuild`) VALUES 
(155029, 1, 0.501187, 0, 8, 45, 0, 117936, 0.148154, 0.0984288, 0.0717735, 0.072341, 0, -0.159104, 0, 0, 34963),
(155028, 1, 0.891251, 0, 8, 45, 0, 117935, 0, 0, 0, 0, 0, 0.781798, 0, 0, 34963),
(155026, 10, 0.0398107, 1024, 8, 45, 0, 117933, 0, 0.25, 0.103179, 0.0987496, 0, 0.681794, 0, 1, 34963),
(155025, 3, 0.0630957, 0, 8, 45, 0, 117932, 0.1, 0.1, 0, 0.1, 0, 0, 0, 1, 34963),
(155024, 10, 0.501187, 0, 8, 45, 0, 117931, 0, 0.5, 0.122462, 0.109101, 0, -0.292893, 0, 0, 34963),
(155023, 10, 0.316228, 0, 8, 45, 0, 117930, 0, 0, 0.122462, 0.109101, 0, 0, 0, 0, 34963),
(155022, 10, 0.15, 0, 8, 45, 0, 117929, 0, 0.5, 0.4, 0, 0, 0.15, 0, 1, 34963),
(155021, 27, 0.0562341, 512, 8, 45, 2, 117928, 0, 0.25, 0, 0, 0, 0.1, 0, 0, 34963),
(155020, 10, 0.398107, 0, 8, 45, 0, 117927, 0, 0, 0.0594631, 0.2063, 0, 0, 0, 0, 34963),
(155019, 1, 0.501187, 0, 8, 45, 0, 117926, 0.148154, 0.0984288, 0.0717735, 0.072341, 0, -0.159104, 0, 0, 34963),
(155018, 1, 0.251189, 0, 8, 45, 0, 117925, 0, 0, 0.0472941, 0.0506579, 0, 0, 0, 0, 34963),
(155017, 10, 0.6, 0, 8, 45, 0, 117924, 0, 0, 0, 0, 0, 0, 0, 0, 34963),
(155016, 10, 0.398107, 0, 8, 45, 0, 117923, 0, 0, 0, 0, 0, 0, 0, 0, 34963);

DELETE FROM `tact_key` WHERE `ID` IN (249) AND `VerifiedBuild` > 0;
INSERT INTO `tact_key` (`ID`, `Key1`, `Key2`, `Key3`, `Key4`, `Key5`, `Key6`, `Key7`, `Key8`, `Key9`, `Key10`, `Key11`, `Key12`, `Key13`, `Key14`, `Key15`, `Key16`, `VerifiedBuild`) VALUES 
(249, 82, 4, 33, 193, 7, 13, 147, 12, 4, 85, 22, 210, 49, 201, 212, 66, 34963);

DELETE FROM `spell_interrupts` WHERE `ID` IN (148235) AND `VerifiedBuild` > 0;
INSERT INTO `spell_interrupts` (`ID`, `DifficultyID`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `SpellID`, `VerifiedBuild`) VALUES 
(148235, 0, 31, 0, 0, 0, 0, 326390, 34963);

DELETE FROM `spell_categories` WHERE `ID` IN (91992) AND `VerifiedBuild` > 0;
INSERT INTO `spell_categories` (`ID`, `DifficultyID`, `Category`, `DefenseType`, `DispelType`, `Mechanic`, `PreventionType`, `StartRecoveryCategory`, `ChargeCategory`, `SpellID`, `VerifiedBuild`) VALUES 
(91992, 0, 0, 0, 0, 21, 0, 330, 0, 326390, 34963);

DELETE FROM `spell_visual_kit` WHERE `ID` IN (128874) AND `VerifiedBuild` > 0;
INSERT INTO `spell_visual_kit` (`ID`, `FallbackPriority`, `FallbackSpellVisualKitId`, `DelayMin`, `DelayMax`, `Flags1`, `Flags2`, `VerifiedBuild`) VALUES 
(128874, 0, 0, 0, 0, 0, 0, 34963);

DELETE FROM `spell_effect` WHERE `ID` IN (817374) AND `VerifiedBuild` > 0;
INSERT INTO `spell_effect` (`ID`, `EffectAura`, `DifficultyID`, `EffectIndex`, `Effect`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`, `SpellID`, `VerifiedBuild`) VALUES 
(817374, 78, 0, 0, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 31698, 229, 0, 0, 0, 0, 0, 0, 1, 0, 326390, 34963);

DELETE FROM `creature_display_info` WHERE `ID` IN (96554) AND `VerifiedBuild` > 0;
INSERT INTO `creature_display_info` (`ID`, `ModelID`, `SoundID`, `SizeClass`, `CreatureModelScale`, `CreatureModelAlpha`, `BloodID`, `ExtendedDisplayInfoID`, `NPCSoundID`, `ParticleColorID`, `PortraitCreatureDisplayInfoID`, `PortraitTextureFileDataID`, `ObjectEffectPackageID`, `AnimReplacementSetID`, `Flags`, `StateSpellVisualKitID`, `PlayerOverrideScale`, `PetInstanceScale`, `UnarmedWeaponType`, `MountPoofSpellVisualKitID`, `DissolveEffectID`, `Gender`, `DissolveOutEffectID`, `CreatureModelMinLod`, `TextureVariationFileDataID1`, `TextureVariationFileDataID2`, `TextureVariationFileDataID3`, `VerifiedBuild`) VALUES 
(96554, 12308, 0, 1, 1, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 2, 0, 0, 2843115, 0, 0, 34963);

DELETE FROM `curve` WHERE `ID` IN (17561) AND `VerifiedBuild` > 0;
INSERT INTO `curve` (`ID`, `Type`, `Flags`, `VerifiedBuild`) VALUES 
(17561, 0, 0, 34963);

DELETE FROM `hotfix_data` WHERE `Id` = 56456 AND `TableHash` = 3386943305 AND `RecordId` = 179705;

DELETE FROM `hotfix_data` WHERE `Id` = 56851 AND `TableHash` = 3386943305 AND `RecordId` = 179705;
DELETE FROM `hotfix_data` WHERE `Id` = 56847 AND `TableHash` = 2712461791 AND `RecordId` = 191881;
DELETE FROM `hotfix_data` WHERE `Id` = 56847 AND `TableHash` = 2712461791 AND `RecordId` = 74;
DELETE FROM `hotfix_data` WHERE `Id` = 56847 AND `TableHash` = 2124448848 AND `RecordId` = 191881;
DELETE FROM `hotfix_data` WHERE `Id` = 56847 AND `TableHash` = 2124448848 AND `RecordId` = 74;
DELETE FROM `hotfix_data` WHERE `Id` = 56585 AND `TableHash` = 3821385681 AND `RecordId` = 550;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 4282664694 AND `RecordId` = 44774;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 4146370265 AND `RecordId` = 97590;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 4102286043 AND `RecordId` = 128874;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 4030871717 AND `RecordId` = 817374;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3776013982 AND `RecordId` = 326390;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3744420815 AND `RecordId` = 249;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3689412649 AND `RecordId` = 91992;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3425193231 AND `RecordId` = 230583;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3425193231 AND `RecordId` = 230582;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3425193231 AND `RecordId` = 230581;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3322146344 AND `RecordId` = 400993;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474862;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474861;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474860;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474859;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474858;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474857;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474856;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474855;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474854;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474853;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474852;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474851;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474850;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474849;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474848;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474847;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474846;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474845;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474844;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474843;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474842;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474841;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474840;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474839;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474838;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474837;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474836;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474835;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474834;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474833;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474832;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474831;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474830;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474829;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474828;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474827;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474826;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474825;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474824;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474823;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474822;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474821;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474820;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474819;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474818;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474817;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474816;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474815;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474814;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474813;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474812;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474811;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474810;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474809;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474808;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474807;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474806;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474805;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474804;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474803;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474802;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474801;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474800;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474799;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474798;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3266400455 AND `RecordId` = 474797;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117936;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117935;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117934;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117933;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117932;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117931;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117930;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117929;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117928;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117927;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117926;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117925;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117924;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3232102598 AND `RecordId` = 117923;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 3218799089 AND `RecordId` = 96554;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2948698321 AND `RecordId` = 249;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1058;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1057;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1056;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1050;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1049;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2930840720 AND `RecordId` = 1048;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2533050585 AND `RecordId` = 360;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2533050585 AND `RecordId` = 356;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2533050585 AND `RecordId` = 355;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2533050585 AND `RecordId` = 354;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2524150337 AND `RecordId` = 1346;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2445379776 AND `RecordId` = 6802;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2137612197 AND `RecordId` = 12308;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 2030087241 AND `RecordId` = 1316;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58186;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58185;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58184;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58183;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58182;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58181;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58180;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1880017466 AND `RecordId` = 58179;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1720692227 AND `RecordId` = 148235;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1442854927 AND `RecordId` = 181;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2302;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2301;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2300;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2299;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2298;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2297;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2296;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2295;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2294;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1387041889 AND `RecordId` = 2293;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1272569722 AND `RecordId` = 17561;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1187407512 AND `RecordId` = 326390;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1181150530 AND `RecordId` = 320729;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 1181150530 AND `RecordId` = 320728;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155029;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155028;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155027;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155026;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155025;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155024;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155023;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155022;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155021;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155020;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155019;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155018;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155017;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 908293937 AND `RecordId` = 155016;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 859088734 AND `RecordId` = 373349;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4005;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4004;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4003;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4002;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4001;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 4000;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 3999;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 736158310 AND `RecordId` = 3998;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 666345498 AND `RecordId` = 288388;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 501138918 AND `RecordId` = 108940;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 21457424 AND `RecordId` = 354;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 21457424 AND `RecordId` = 350;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 21457424 AND `RecordId` = 349;
DELETE FROM `hotfix_data` WHERE `Id` = 56262 AND `TableHash` = 21457424 AND `RecordId` = 348;
INSERT INTO `hotfix_data` (`Id`, `TableHash`, `RecordId`, `Deleted`, `VerifiedBuild`) VALUES 
(56851, 3386943305, 179705, 0, 34963),
(56847, 2712461791, 191881, 0, 34963),
(56847, 2712461791, 74, 0, 34963),
(56847, 2124448848, 191881, 1, 34963),
(56847, 2124448848, 74, 1, 34963),
(56585, 3821385681, 550, 0, 34963),
(56262, 4282664694, 44774, 0, 34963),
(56262, 4146370265, 97590, 0, 34963),
(56262, 4102286043, 128874, 0, 34963),
(56262, 4030871717, 817374, 0, 34963),
(56262, 3776013982, 326390, 0, 34963),
(56262, 3744420815, 249, 0, 34963),
(56262, 3689412649, 91992, 0, 34963),
(56262, 3425193231, 230583, 0, 34963),
(56262, 3425193231, 230582, 0, 34963),
(56262, 3425193231, 230581, 0, 34963),
(56262, 3322146344, 400993, 0, 34963),
(56262, 3266400455, 474862, 0, 34963),
(56262, 3266400455, 474861, 0, 34963),
(56262, 3266400455, 474860, 0, 34963),
(56262, 3266400455, 474859, 0, 34963),
(56262, 3266400455, 474858, 1, 34963),
(56262, 3266400455, 474857, 1, 34963),
(56262, 3266400455, 474856, 0, 34963),
(56262, 3266400455, 474855, 0, 34963),
(56262, 3266400455, 474854, 0, 34963),
(56262, 3266400455, 474853, 0, 34963),
(56262, 3266400455, 474852, 0, 34963),
(56262, 3266400455, 474851, 0, 34963),
(56262, 3266400455, 474850, 0, 34963),
(56262, 3266400455, 474849, 0, 34963),
(56262, 3266400455, 474848, 0, 34963),
(56262, 3266400455, 474847, 0, 34963),
(56262, 3266400455, 474846, 0, 34963),
(56262, 3266400455, 474845, 0, 34963),
(56262, 3266400455, 474844, 0, 34963),
(56262, 3266400455, 474843, 0, 34963),
(56262, 3266400455, 474842, 0, 34963),
(56262, 3266400455, 474841, 0, 34963),
(56262, 3266400455, 474840, 0, 34963),
(56262, 3266400455, 474839, 0, 34963),
(56262, 3266400455, 474838, 0, 34963),
(56262, 3266400455, 474837, 0, 34963),
(56262, 3266400455, 474836, 0, 34963),
(56262, 3266400455, 474835, 0, 34963),
(56262, 3266400455, 474834, 0, 34963),
(56262, 3266400455, 474833, 0, 34963),
(56262, 3266400455, 474832, 0, 34963),
(56262, 3266400455, 474831, 0, 34963),
(56262, 3266400455, 474830, 0, 34963),
(56262, 3266400455, 474829, 0, 34963),
(56262, 3266400455, 474828, 0, 34963),
(56262, 3266400455, 474827, 0, 34963),
(56262, 3266400455, 474826, 0, 34963),
(56262, 3266400455, 474825, 0, 34963),
(56262, 3266400455, 474824, 0, 34963),
(56262, 3266400455, 474823, 0, 34963),
(56262, 3266400455, 474822, 0, 34963),
(56262, 3266400455, 474821, 0, 34963),
(56262, 3266400455, 474820, 0, 34963),
(56262, 3266400455, 474819, 0, 34963),
(56262, 3266400455, 474818, 0, 34963),
(56262, 3266400455, 474817, 0, 34963),
(56262, 3266400455, 474816, 1, 34963),
(56262, 3266400455, 474815, 1, 34963),
(56262, 3266400455, 474814, 0, 34963),
(56262, 3266400455, 474813, 0, 34963),
(56262, 3266400455, 474812, 0, 34963),
(56262, 3266400455, 474811, 0, 34963),
(56262, 3266400455, 474810, 0, 34963),
(56262, 3266400455, 474809, 0, 34963),
(56262, 3266400455, 474808, 0, 34963),
(56262, 3266400455, 474807, 0, 34963),
(56262, 3266400455, 474806, 0, 34963),
(56262, 3266400455, 474805, 0, 34963),
(56262, 3266400455, 474804, 0, 34963),
(56262, 3266400455, 474803, 0, 34963),
(56262, 3266400455, 474802, 0, 34963),
(56262, 3266400455, 474801, 0, 34963),
(56262, 3266400455, 474800, 0, 34963),
(56262, 3266400455, 474799, 0, 34963),
(56262, 3266400455, 474798, 0, 34963),
(56262, 3266400455, 474797, 0, 34963),
(56262, 3232102598, 117936, 0, 34963),
(56262, 3232102598, 117935, 0, 34963),
(56262, 3232102598, 117934, 1, 34963),
(56262, 3232102598, 117933, 0, 34963),
(56262, 3232102598, 117932, 0, 34963),
(56262, 3232102598, 117931, 0, 34963),
(56262, 3232102598, 117930, 0, 34963),
(56262, 3232102598, 117929, 0, 34963),
(56262, 3232102598, 117928, 0, 34963),
(56262, 3232102598, 117927, 0, 34963),
(56262, 3232102598, 117926, 0, 34963),
(56262, 3232102598, 117925, 0, 34963),
(56262, 3232102598, 117924, 0, 34963),
(56262, 3232102598, 117923, 0, 34963),
(56262, 3218799089, 96554, 0, 34963),
(56262, 2948698321, 249, 0, 34963),
(56262, 2930840720, 1058, 0, 34963),
(56262, 2930840720, 1057, 0, 34963),
(56262, 2930840720, 1056, 0, 34963),
(56262, 2930840720, 1050, 0, 34963),
(56262, 2930840720, 1049, 0, 34963),
(56262, 2930840720, 1048, 0, 34963),
(56262, 2533050585, 360, 0, 34963),
(56262, 2533050585, 356, 0, 34963),
(56262, 2533050585, 355, 0, 34963),
(56262, 2533050585, 354, 0, 34963),
(56262, 2524150337, 1346, 0, 34963),
(56262, 2445379776, 6802, 0, 34963),
(56262, 2137612197, 12308, 0, 34963),
(56262, 2030087241, 1316, 0, 34963),
(56262, 1880017466, 58186, 0, 34963),
(56262, 1880017466, 58185, 0, 34963),
(56262, 1880017466, 58184, 0, 34963),
(56262, 1880017466, 58183, 0, 34963),
(56262, 1880017466, 58182, 0, 34963),
(56262, 1880017466, 58181, 0, 34963),
(56262, 1880017466, 58180, 0, 34963),
(56262, 1880017466, 58179, 0, 34963),
(56262, 1720692227, 148235, 0, 34963),
(56262, 1442854927, 181, 0, 34963),
(56262, 1387041889, 2302, 0, 34963),
(56262, 1387041889, 2301, 0, 34963),
(56262, 1387041889, 2300, 0, 34963),
(56262, 1387041889, 2299, 0, 34963),
(56262, 1387041889, 2298, 0, 34963),
(56262, 1387041889, 2297, 0, 34963),
(56262, 1387041889, 2296, 0, 34963),
(56262, 1387041889, 2295, 0, 34963),
(56262, 1387041889, 2294, 0, 34963),
(56262, 1387041889, 2293, 0, 34963),
(56262, 1272569722, 17561, 0, 34963),
(56262, 1187407512, 326390, 0, 34963),
(56262, 1181150530, 320729, 0, 34963),
(56262, 1181150530, 320728, 0, 34963),
(56262, 908293937, 155029, 0, 34963),
(56262, 908293937, 155028, 0, 34963),
(56262, 908293937, 155027, 1, 34963),
(56262, 908293937, 155026, 0, 34963),
(56262, 908293937, 155025, 0, 34963),
(56262, 908293937, 155024, 0, 34963),
(56262, 908293937, 155023, 0, 34963),
(56262, 908293937, 155022, 0, 34963),
(56262, 908293937, 155021, 0, 34963),
(56262, 908293937, 155020, 0, 34963),
(56262, 908293937, 155019, 0, 34963),
(56262, 908293937, 155018, 0, 34963),
(56262, 908293937, 155017, 0, 34963),
(56262, 908293937, 155016, 0, 34963),
(56262, 859088734, 373349, 0, 34963),
(56262, 736158310, 4005, 0, 34963),
(56262, 736158310, 4004, 0, 34963),
(56262, 736158310, 4003, 0, 34963),
(56262, 736158310, 4002, 1, 34963),
(56262, 736158310, 4001, 0, 34963),
(56262, 736158310, 4000, 0, 34963),
(56262, 736158310, 3999, 0, 34963),
(56262, 736158310, 3998, 0, 34963),
(56262, 666345498, 288388, 0, 34963),
(56262, 501138918, 108940, 0, 34963),
(56262, 21457424, 354, 0, 34963),
(56262, 21457424, 350, 0, 34963),
(56262, 21457424, 349, 0, 34963),
(56262, 21457424, 348, 0, 34963);

DELETE FROM `curve_point` WHERE `ID` IN (58186, 58185, 58184, 58183, 58182, 58181, 58180, 58179) AND `VerifiedBuild` > 0;
INSERT INTO `curve_point` (`ID`, `PosX`, `PosY`, `CurveID`, `OrderIndex`, `VerifiedBuild`) VALUES 
(58186, 1, 0, 17561, 7, 34963),
(58185, 0.75, -3, 17561, 6, 34963),
(58184, 0.5, -6, 17561, 5, 34963),
(58183, 0.316364, -16.6845, 17561, 4, 34963),
(58182, 0.210909, -23.5294, 17561, 3, 34963),
(58181, 0.163636, -31.6578, 17561, 2, 34963),
(58180, 0.116364, -44.0642, 17561, 1, 34963),
(58179, 0, -80, 17561, 0, 34963);

DELETE FROM `creature_model_data` WHERE `ID` IN (12308) AND `VerifiedBuild` > 0;
INSERT INTO `creature_model_data` (`ID`, `GeoBox1`, `GeoBox2`, `GeoBox3`, `GeoBox4`, `GeoBox5`, `GeoBox6`, `Flags`, `FileDataID`, `BloodID`, `FootprintTextureID`, `FootprintTextureLength`, `FootprintTextureWidth`, `FootprintParticleScale`, `FoleyMaterialID`, `FootstepCameraEffectID`, `DeathThudCameraEffectID`, `SoundID`, `SizeClass`, `CollisionWidth`, `CollisionHeight`, `WorldEffectScale`, `CreatureGeosetDataID`, `HoverHeight`, `AttachedEffectScale`, `ModelScale`, `MissileCollisionRadius`, `MissileCollisionPush`, `MissileCollisionRaise`, `MountHeight`, `OverrideLootEffectScale`, `OverrideNameScale`, `OverrideSelectionRadius`, `TamedPetBaseScale`, `Unknown820_1`, `Unknown820_2`, `Unknown820_31`, `Unknown820_32`, `VerifiedBuild`) VALUES 
(12308, -7.76995, -6.16651, -4.44444, 4.44444, 3.73557, 4.44444, 4096, 2843110, 19, 5, 32, 24, 1, 0, 0, 0, 6802, 0, 0.611111, 2.03128, 1, 0, 0, 1, 1, 0, 0, 0, 3.16283, 0, 0, 0, 1, 0, 1, 1, 1, 34963);

DELETE FROM `skill_line_ability` WHERE `ID` IN (44774) AND `VerifiedBuild` > 0;
INSERT INTO `skill_line_ability` (`RaceMask`, `ID`, `SkillLine`, `Spell`, `MinSkillLineRank`, `ClassMask`, `SupercedesSpell`, `AcquireMethod`, `TrivialSkillLineRankHigh`, `TrivialSkillLineRankLow`, `Flags`, `NumSkillUps`, `UniqueBit`, `TradeSkillCategoryID`, `SkillupSkillLineID`, `VerifiedBuild`) VALUES 
(0, 44774, 777, 326390, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 34963);

DELETE FROM `mount_x_display` WHERE `ID` IN (1316) AND `VerifiedBuild` > 0;
INSERT INTO `mount_x_display` (`ID`, `CreatureDisplayInfoID`, `PlayerConditionID`, `MountID`, `VerifiedBuild`) VALUES 
(1316, 96554, 0, 1346, 34963);

DELETE FROM `spell_levels` WHERE `ID` IN (108940) AND `VerifiedBuild` > 0;
INSERT INTO `spell_levels` (`ID`, `DifficultyID`, `BaseLevel`, `MaxLevel`, `SpellLevel`, `MaxPassiveAuraLevel`, `SpellID`, `VerifiedBuild`) VALUES 
(108940, 0, 0, 0, 1, 0, 326390, 34963);

DELETE FROM `mount` WHERE `ID` IN (1346) AND `VerifiedBuild` > 0;
INSERT INTO `mount` (`Name`, `SourceText`, `Description`, `ID`, `MountTypeID`, `Flags`, `SourceTypeEnum`, `SourceSpellID`, `PlayerConditionID`, `MountFlyRideHeight`, `UiModelSceneID`, `MountSpecialRiderAnimKitID`, `MountSpecialSpellVisualKitID`, `VerifiedBuild`) VALUES 
('Steamscale Incinerator', '|cFFFFD200In-Game Shop|r|n', 'A mad gnomish inventor had a dream to ride a dragon, so he created this metal monstrosity. He powered it with a trapped demon, in order to create \"an authentic dragon soul,\" and did not survive its activation.', 1346, 248, 128, 9, 326390, 0, 0, 354, 0, 0, 34963);

UPDATE hotfix_blob SET `Blob` = 0x077B7B100013030000084589404A00000000040003002B110020002119000100000000000059690200 WHERE (`TableHash` = 3386943305) AND (`RecordId` = 179705) AND (`locale` = 'enUS');

DELETE FROM `hotfix_blob` WHERE `TableHash` = 4146370265 AND `RecordId` = 97590 AND `locale` = 'enUS'; 
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3776013982 AND `RecordId` = 326390 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3425193231 AND `RecordId` = 230583 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3425193231 AND `RecordId` = 230582 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3425193231 AND `RecordId` = 230581 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474862 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474861 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474860 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474859 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474856 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474855 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474854 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474853 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474852 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474851 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474850 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474849 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474848 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474847 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474846 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474845 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474844 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474843 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474842 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474841 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474840 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474839 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474838 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474837 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474836 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474835 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474834 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474833 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474832 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474831 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474830 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474829 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474828 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474827 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474826 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474825 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474824 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474823 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474822 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474821 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474820 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474819 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474818 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474817 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474814 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474813 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474812 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474811 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474810 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474809 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474808 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474807 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474806 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474805 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474804 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474803 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474802 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474801 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474800 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474799 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474798 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3266400455 AND `RecordId` = 474797 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117936 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117935 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117933 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117932 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117931 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117930 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117929 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117928 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117927 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117926 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117925 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117924 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 3232102598 AND `RecordId` = 117923 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2948698321 AND `RecordId` = 249 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1058 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1057 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1056 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1050 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1049 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2930840720 AND `RecordId` = 1048 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2533050585 AND `RecordId` = 360 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2533050585 AND `RecordId` = 356 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2533050585 AND `RecordId` = 355 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2533050585 AND `RecordId` = 354 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 2445379776 AND `RecordId` = 6802 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1442854927 AND `RecordId` = 181 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2302 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2301 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2300 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2299 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2298 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2297 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2296 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2295 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2294 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1387041889 AND `RecordId` = 2293 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1181150530 AND `RecordId` = 320729 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 1181150530 AND `RecordId` = 320728 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 859088734 AND `RecordId` = 373349 AND `locale` = 'enUS'; 
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 4005 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 4004 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 4003 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 4001 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 4000 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 3999 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 736158310 AND `RecordId` = 3998 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 21457424 AND `RecordId` = 354 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 21457424 AND `RecordId` = 350 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 21457424 AND `RecordId` = 349 AND `locale` = 'enUS';
DELETE FROM `hotfix_blob` WHERE `TableHash` = 21457424 AND `RecordId` = 348 AND `locale` = 'enUS';
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES 
(4146370265, 97590, 'enUS', 0x0000000000000000000000000000000000000000000000000000000000000000FF140000000000000000000000000000000000000000000000000000000000000000, 34963),
(3776013982, 326390, 'enUS', 0x0053756D6D6F6E7320616E64206469736D69737365732074686973206D6F756E742E00243F6A31675B496E637265617365732067726F756E6420737065656420627920246A3167252E205D5B5D243F6A31665B496E6372656173657320666C6967687420737065656420627920246A3166252E205D5B5D243F6A31735B496E63726561736573207377696D20737065656420627920246A3173252E205D5B5D00, 34963),
(3425193231, 230583, 'enUS', 0x080000000D00000000000000000000000000000000000000020000003F4C0000367D0100, 34963),
(3425193231, 230582, 'enUS', 0x030000000D00000000000000000000000000000000000000010000006AF70100367D0100, 34963),
(3425193231, 230581, 'enUS', 0x0100000002000000000000000000000000000000000000000100000066010000367D0100, 34963),
(3266400455, 474862, 'enUS', 0x955D0200BF0E2500010000803F, 34963),
(3266400455, 474861, 'enUS', 0x955D0200C00E2500010000803F, 34963),
(3266400455, 474860, 'enUS', 0x955D0200C10E2500010000803F, 34963),
(3266400455, 474859, 'enUS', 0x945D020073742C00010000803F, 34963),
(3266400455, 474856, 'enUS', 0x8D5D0200FEA30800010000803F, 34963),
(3266400455, 474855, 'enUS', 0x925D020093420C00010000803F, 34963),
(3266400455, 474854, 'enUS', 0x925D020095420C00010000803F, 34963),
(3266400455, 474853, 'enUS', 0x925D020097420C00010000803F, 34963),
(3266400455, 474852, 'enUS', 0x925D020099420C00010000803F, 34963),
(3266400455, 474851, 'enUS', 0x925D02009B420C00010000803F, 34963),
(3266400455, 474850, 'enUS', 0x925D02009D420C00010000803F, 34963),
(3266400455, 474849, 'enUS', 0x925D02009F420C00010000803F, 34963),
(3266400455, 474848, 'enUS', 0x925D0200A1420C00010000803F, 34963),
(3266400455, 474847, 'enUS', 0x925D0200A3420C00010000803F, 34963),
(3266400455, 474846, 'enUS', 0x925D0200A5420C00010000803F, 34963),
(3266400455, 474845, 'enUS', 0x915D0200EFA30D00010000803F, 34963),
(3266400455, 474844, 'enUS', 0x915D0200F1A30D00010000803F, 34963),
(3266400455, 474843, 'enUS', 0x915D0200F3A30D00010000803F, 34963),
(3266400455, 474842, 'enUS', 0x915D0200F5A30D00010000803F, 34963),
(3266400455, 474841, 'enUS', 0x915D0200F7A30D00010000803F, 34963),
(3266400455, 474840, 'enUS', 0x915D0200F9A30D00010000803F, 34963),
(3266400455, 474839, 'enUS', 0x915D0200FBA30D00010000803F, 34963),
(3266400455, 474838, 'enUS', 0x915D0200FDA30D00010000803F, 34963),
(3266400455, 474837, 'enUS', 0x905D0200A9002E00010000803F, 34963),
(3266400455, 474836, 'enUS', 0x905D0200AA002E00010000803F, 34963),
(3266400455, 474835, 'enUS', 0x905D0200AB002E00010000803F, 34963),
(3266400455, 474834, 'enUS', 0x905D0200AC002E00010000803F, 34963),
(3266400455, 474833, 'enUS', 0x905D0200AD002E00010000803F, 34963),
(3266400455, 474832, 'enUS', 0x905D0200AE002E00010000803F, 34963),
(3266400455, 474831, 'enUS', 0x905D0200AF002E00010000803F, 34963),
(3266400455, 474830, 'enUS', 0x905D0200B0002E00010000803F, 34963),
(3266400455, 474829, 'enUS', 0x905D0200B1002E00010000803F, 34963),
(3266400455, 474828, 'enUS', 0x8F5D0200CB572C00010000803F, 34963),
(3266400455, 474827, 'enUS', 0x8F5D0200CE572C00010000803F, 34963),
(3266400455, 474826, 'enUS', 0x8E5D020072D31700010000803F, 34963),
(3266400455, 474825, 'enUS', 0x8E5D020073D31700010000803F, 34963),
(3266400455, 474824, 'enUS', 0x8E5D020074D31700010000803F, 34963),
(3266400455, 474823, 'enUS', 0x8E5D020075D31700010000803F, 34963),
(3266400455, 474822, 'enUS', 0x8E5D020076D31700010000803F, 34963),
(3266400455, 474821, 'enUS', 0x8E5D020077D31700010000803F, 34963),
(3266400455, 474820, 'enUS', 0x8E5D020078D31700010000803F, 34963),
(3266400455, 474819, 'enUS', 0x8E5D020079D31700010000803F, 34963),
(3266400455, 474818, 'enUS', 0x8E5D02007AD31700010000803F, 34963),
(3266400455, 474817, 'enUS', 0x8E5D02007BD31700010000803F, 34963),
(3266400455, 474814, 'enUS', 0x8C5D0200CB572C00010000803F, 34963),
(3266400455, 474813, 'enUS', 0x8C5D0200CE572C00010000803F, 34963),
(3266400455, 474812, 'enUS', 0x8B5D0200BD0E2500010000803F, 34963),
(3266400455, 474811, 'enUS', 0x8B5D0200BC0E2500010000803F, 34963),
(3266400455, 474810, 'enUS', 0x8A5D0200FB5E1600010000803F, 34963),
(3266400455, 474809, 'enUS', 0x8A5D0200FC5E1600010000803F, 34963),
(3266400455, 474808, 'enUS', 0x895D02000F5F1600010000803F, 34963),
(3266400455, 474807, 'enUS', 0x895D02000E5F1600010000803F, 34963),
(3266400455, 474806, 'enUS', 0x895D02000D5F1600010000803F, 34963),
(3266400455, 474805, 'enUS', 0x895D02000C5F1600010000803F, 34963),
(3266400455, 474804, 'enUS', 0x895D02000B5F1600010000803F, 34963),
(3266400455, 474803, 'enUS', 0x895D02000A5F1600010000803F, 34963),
(3266400455, 474802, 'enUS', 0x895D0200095F1600010000803F, 34963),
(3266400455, 474801, 'enUS', 0x885D0200E85E1600010000803F, 34963),
(3266400455, 474800, 'enUS', 0x885D0200E75E1600010000803F, 34963),
(3266400455, 474799, 'enUS', 0x885D0200E65E1600010000803F, 34963),
(3266400455, 474798, 'enUS', 0x885D0200E55E1600010000803F, 34963),
(3266400455, 474797, 'enUS', 0x885D0200E45E1600010000803F, 34963),
(3232102598, 117936, 'enUS', 0xB0CC0100955D02000000A040000000410000000000000000000000000000000000000000020000000000000000D0070000D0070000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F00000000CDCCCC3D00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117935, 'enUS', 0xAFCC0100945D02000000A040000000410000000000000000000000000000000000000000020000000000000000DC050000DC050000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000007017000000000000000000000001F4010000F401000099440000FFFFFFFFFFFFFFFF580C00000000803F00000000CDCCCC3D00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117933, 'enUS', 0xADCC0100925D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117932, 'enUS', 0xACCC0100915D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117931, 'enUS', 0xABCC0100905D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117930, 'enUS', 0xAACC01008F5D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F00000000CDCCCC3D00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117929, 'enUS', 0xA9CC01008E5D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117928, 'enUS', 0xA8CC01008D5D02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000344300008743000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117927, 'enUS', 0xA7CC01008C5D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F00000000CDCCCC3D00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117926, 'enUS', 0xA6CC01008B5D02000000A040000000410000000000000000000000000000000000000000020000000000000000DC050000DC050000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F00000000CDCCCC3D00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117925, 'enUS', 0xA5CC01008A5D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117924, 'enUS', 0xA4CC0100895D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(3232102598, 117923, 'enUS', 0xA3CC0100885D02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 34963),
(2948698321, 249, 'enUS', 0xD6968DCA7ACF9DD1, 34963),
(2930840720, 1058, 'enUS', 0x706C617965722D7269646572000000000000000000000000002204000000AA0000000000000000000000000000000000000062010000, 34963),
(2930840720, 1057, 'enUS', 0x77726170706564000000000000000000000000BF2104000000010000000000000000000000000000000000000062010000, 34963),
(2930840720, 1056, 'enUS', 0x756E77726170706564000000000000000000000000002004000009060000000000000000000000000000000000803E62010000, 34963),
(2930840720, 1050, 'enUS', 0x6974656D003333534000000000000040401A0400000FA5000000D1537B400000000000000000713D0A3F5E010000, 34963),
(2930840720, 1049, 'enUS', 0x6974656D0000000000000000000000C0BF190400000FA9000000368D27C000000000000000003D0A573E5D010000, 34963),
(2930840720, 1048, 'enUS', 0x6974656D009A9999BE000000000000C0BF180400000FB5000000368D27C00000000000000000AE47613E5C010000, 34963),
(2533050585, 360, 'enUS', 0x7072696D6172790000000000000000000000804000000000000000000000C0BF680100000100368D27400000000000000000C2B8323E000000000000000000006041000000410000904162010000, 34963),
(2533050585, 356, 'enUS', 0x7072696D6172790000000000000000009A99993E000000000000000000000000640100000100F366DF3F00000000000000000000000000000000000000000000004100000041000000415E010000, 34963),
(2533050585, 355, 'enUS', 0x7072696D6172790000000000000000000000403F000000000000000000000000630100000100920A863F00000000000000000000000000000000000000000000004100000041000000415D010000, 34963),
(2533050585, 354, 'enUS', 0x7072696D61727900000000000000000000000000000000000000000000000000620100000100920A863F00000000000000000000000000000000000000000000004100000041000000415C010000, 34963),
(2445379776, 6802, 'enUS', 0x4C2001004D200100895D0200895D020000000000522001000000000000000000FE010000502001008E5D020000000000512001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000F0410000704204000000004044000040440000404400008A5D02000000000000000000000000000000000000000000, 34963),
(1442854927, 181, 'enUS', 0x000000000200000000000000000000000000803F000040400000803F, 34963),
(1387041889, 2302, 'enUS', 0xFE010A4E7C000000000000, 34963),
(1387041889, 2301, 'enUS', 0xFE0109915D020026040000, 34963),
(1387041889, 2300, 'enUS', 0xFE0108915D020025040000, 34963),
(1387041889, 2299, 'enUS', 0xFE0107915D020024040000, 34963),
(1387041889, 2298, 'enUS', 0xFE0106915D020023040000, 34963),
(1387041889, 2297, 'enUS', 0xFE0105915D020022040000, 34963),
(1387041889, 2296, 'enUS', 0xFE0104915D020021040000, 34963),
(1387041889, 2295, 'enUS', 0xFE0103915D020020040000, 34963),
(1387041889, 2294, 'enUS', 0xFE0102915D02001F040000, 34963),
(1387041889, 2293, 'enUS', 0xFE0101915D02001E040000, 34963),
(1181150530, 320729, 'enUS', 0x05000000885D02006AF70100, 34963),
(1181150530, 320728, 'enUS', 0x0600000065B205006AF70100, 34963),
(859088734, 373349, 'enUS', 0xFFFFFFFF360000000000, 34963),
(736158310, 4005, 'enUS', 0x955D02008A5D0200, 34963),
(736158310, 4004, 'enUS', 0x945D02008A5D0200, 34963),
(736158310, 4003, 'enUS', 0x925D0200915D0200, 34963),
(736158310, 4001, 'enUS', 0x905D02008E5D0200, 34963),
(736158310, 4000, 'enUS', 0x8F5D0200885D0200, 34963),
(736158310, 3999, 'enUS', 0x8B5D02008A5D0200, 34963),
(736158310, 3998, 'enUS', 0x8C5D02008A5D0200, 34963),
(21457424, 354, 'enUS', 0x0000, 34963),
(21457424, 350, 'enUS', 0x0200, 34963),
(21457424, 349, 'enUS', 0x0200, 34963),
(21457424, 348, 'enUS', 0x0200, 34963);

DELETE FROM `mail_template` WHERE `ID` IN (550) AND `VerifiedBuild` > 0;
INSERT INTO `mail_template` (`ID`, `Body`, `VerifiedBuild`) VALUES 
(550, 'In order to reactivate your account using gold, we withdrew some uncollected money from your mail. Because of this, you may notice less money in the mail than you expected. Don''t be alarmed, as no money was lost.\nThanks, and welcome back to Azeroth!\n- The WoW Dev Team', 34963);

DELETE FROM `spell_name` WHERE `ID` IN (326390) AND `VerifiedBuild` > 0;
INSERT INTO `spell_name` (`ID`, `Name`, `VerifiedBuild`) VALUES 
(326390, 'Steamscale Incinerator', 34963);
