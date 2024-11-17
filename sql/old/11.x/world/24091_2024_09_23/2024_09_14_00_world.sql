SET @CGUID := 4000138;
SET @OGUID := 4000060;

DELETE FROM `battleground_template` WHERE `ID`=708;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `Weight`, `Comment`) VALUES
(708, 4062, 4061, 1, 'Silvershard Mines');

DELETE FROM `battleground_scripts` WHERE `MapId`=727;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(727, 0, 'battleground_silvershard_mines');

DELETE FROM `serverside_spell` WHERE `Id` IN (128648, 128702, 128703, 128704, 128705, 128706, 128720, 128668, 128669, 128670, 128672, 128673, 128674);
DELETE FROM `serverside_spell_effect` WHERE `SpellId` IN (128648, 128702, 128703, 128704, 128705, 128706, 128720, 128668, 128669, 128670, 128672, 128673, 128674);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(128648, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0x1A0000, 0x400, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 5, 0, 0, 0, -1, 0, 0, 0, 'Defending Cart Aura', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128668, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement East (Horde)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128669, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement North (Horde)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128670, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement South (Horde)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128672, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement East (Alliance)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128673, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement North (Alliance)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128674, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Long Rider Achievement South (Alliance)', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128702, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Mine Cart Courier East->South', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128703, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Mine Cart Courier East->North', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128704, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Mine Cart Courier South', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128705, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Mine Cart Courier North->East', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128706, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'Mine Cart Courier North->West', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(128720, 0, 0, 0, 0, 134217856, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 34, 0, 0, 0, -1, 0, 0, 0, 'End of the Line Achievement Check', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(128648, 0, 0, 6, 226, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 0, 0, 0, 0, 30, 0),
(128668, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128669, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128670, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128672, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128673, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128674, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128702, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128703, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128704, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128705, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128706, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0),
(128720, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bg_silvershard_mines_cart_cap', 'spell_bg_silvershard_mines_capturing', 'spell_bg_silvershard_mines_capturing_switch_track', 'spell_bg_defending_cart_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(115904, 'spell_bg_silvershard_mines_cart_cap'),
(124491, 'spell_bg_silvershard_mines_capturing'),
(97372, 'spell_bg_silvershard_mines_capturing_switch_track'),
(128648, 'spell_bg_defending_cart_aura');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (7779, 7780, 7781, 7782);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(7782, 'at_battleground_buffs'),
(7779, 'at_battleground_buffs'),
(7781, 'at_battleground_buffs'),
(7780, 'at_battleground_buffs');

DELETE FROM `graveyard_zone` WHERE `ID` IN (4061, 4062);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(4062, 6126, 'Silvershard Mines - Alliance'),
(4061, 6126, 'Silvershard Mines - Horde');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (4061, 4062);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `NegativeCondition`, `Comment`) VALUES
(27, 4062, 6126, 0, 6, 469, 0, 0, 'Graveyard - Silvershard Mines - Alliance Base - Team Alliance'),
(27, 4061, 6126, 0, 6, 67, 0, 0, 'Graveyard - Silvershard Mines - Horde Base - Team Horde');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=97372 AND `ConditionTypeOrReference`=31 AND `ConditionValue2`=60283;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 97372, 0, 0, 31, 0, 3, 60283, 0, 0, 0, 0, '', 'Spell 97372 only targets creature with entry 60283');

DELETE FROM `world_state` WHERE `ID` IN (6467, 6468, 6438, 6437, 6439, 6440, 6879, 6880, 6881, 6882, 17378);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(6467, 2, '727', 'Silvershard Mines - Eastern Track Switch State'),
(6468, 1, '727', 'Silvershard Mines - Northern Track Switch State'),
(6438, 0, '727', 'Silvershard Mines - Horde Score'),
(6437, 0, '727', 'Silvershard Mines - Alliance Score'),
(6439, 0, '727', 'Silvershard Mines - East Cart Under Alliance Control'),
(6440, 0, '727', 'Silvershard Mines - East Cart Under Horde Control'),
(6879, 0, '727', 'Silvershard Mines - North Cart Under Horde Control'),
(6880, 0, '727', 'Silvershard Mines - North Cart Under Alliance Control'),
(6882, 0, '727', 'Silvershard Mines - South Cart Under Horde Control'),
(6881, 0, '727', 'Silvershard Mines - South Cart Under Alliance Control'),
(17378, 1500, '727', 'Silvershard Mines - Max score');

UPDATE `gameobject_template` SET `Data2`=9601, `Data3`=9603, `Data8`=31167, `Data9`=31166, `Data12`=2, `Data13`=9605, `Data14`=1, `Data15`=1, `Data16`=50, `Data17`=50, `Data18`=1, `Data20`=50, `Data22`=10, `Data25`=15, `Data26`=1, `VerifiedBuild`=55664 WHERE `entry`=213794; -- Mine Cart Control Point North
UPDATE `gameobject_template` SET `Data8`=32909, `Data9`=32910, `Data10`=32912, `Data11`=32912, `Data12`=2, `Data13`=6877, `Data14`=1, `Data15`=1, `Data16`=50, `Data17`=50, `Data18`=1, `Data20`=50, `Data22`=10, `Data25`=15, `Data26`=1, `VerifiedBuild`=55664 WHERE `entry`=213766; -- Mine Cart Control Point East
UPDATE `gameobject_template` SET `Data2`=9602, `Data3`=9604, `Data8`=32937, `Data9`=32938, `Data10`=32951, `Data11`=32951, `Data12`=2, `Data13`=9606, `Data14`=1, `Data15`=1, `Data16`=50, `Data17`=50, `Data18`=1, `Data20`=50, `Data22`=10, `Data25`=15, `Data26`=1, `VerifiedBuild`=55664 WHERE `entry`=213796; -- Mine Cart Control Point South
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry` IN (212942, 212940, 212941, 212939); -- Gate
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212082; -- Diamond Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212083; -- Troll Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212080; -- Waterfall Depot
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=212081; -- Lava Depot

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+29;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 212939, 727, 6126, 6126, '0', '0', 0, 853.1630859375, 158.904693603515625, 328.08172607421875, 6.251653671264648437, 0.042779445648193359, -0.02950668334960937, -0.014495849609375, 0.998543500900268554, 7200, 255, 1, 55461), -- Gate (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+1, 212941, 727, 6126, 6126, '0', '0', 0, 635.25537109375, 208.1811981201171875, 327.966217041015625, 3.498660087585449218, -0.03747749328613281, -0.02367496490478515, -0.98301601409912109, 0.178085654973983764, 7200, 255, 1, 55461), -- Gate (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+2, 212940, 727, 6126, 6126, '0', '0', 0, 830.2012939453125, 144.680389404296875, 329.08978271484375, 0.111990571022033691, -0.02431344985961914, 0.022320747375488281, 0.056479454040527343, 0.997858047485351562, 7200, 255, 1, 55461), -- Gate (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+3, 212942, 727, 6126, 6126, '0', '0', 0, 652.85565185546875, 227.672607421875, 329.00390625, 3.524521350860595703, 0.03816843032836914, 0.047303199768066406, -0.97956275939941406, 0.191735118627548217, 7200, 255, 1, 55461), -- Gate (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+4, 212305, 727, 6126, 6126, '0', '0', 0, 867.98297119140625, 131.5071258544921875, 328.98211669921875, 5.964090347290039062, -0.01038980484008789, -0.00468635559082031, -0.1589202880859375, 0.987225651741027832, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+5, 212304, 727, 6126, 6126, '0', '0', 0, 866.41827392578125, 136.7794952392578125, 328.95977783203125, 4.503678321838378906, 0.000069618225097656, -0.00759792327880859, -0.77687644958496093, 0.629607200622558593, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+6, 212307, 727, 6126, 6126, '0', '0', 0, 614.81585693359375, 231.1639862060546875, 328.99249267578125, 1.236014962196350097, -0.00774526596069335, 0.02101898193359375, 0.579163551330566406, 0.814903557300567626, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+7, 212306, 727, 6126, 6126, '0', '0', 0, 866.22216796875, 134.3291168212890625, 328.9862060546875, 1.940872073173522949, -0.00730180740356445, 0.002100944519042968, 0.825118064880371093, 0.564909219741821289, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+8, 212309, 727, 6126, 6126, '0', '0', 0, 613.97894287109375, 224.162689208984375, 328.97802734375, 2.758805274963378906, 0.006997108459472656, -0.0029611587524414, 0.981709480285644531, 0.190233334898948669, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+9, 212308, 727, 6126, 6126, '0', '0', 0, 617.40960693359375, 231.253021240234375, 328.97515869140625, 2.719236373901367187, -0.01607561111450195, 0.004109382629394531, 0.977647781372070312, 0.209593698382377624, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+10, 179905, 727, 6126, 6126, '0', '0', 0, 810.4930419921875, 36.31076431274414062, 368.24847412109375, 6.067836284637451171, 0, 0, -0.10746669769287109, 0.994208693504333496, 90, 255, 1, 55461), -- Berserk Buff (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+11, 212311, 727, 6126, 6126, '0', '0', 0, 615.1827392578125, 240.83795166015625, 328.96124267578125, 4.911244392395019531, -0.01196098327636718, 0.000443458557128906, -0.63343238830566406, 0.773705482482910156, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+12, 179904, 727, 6126, 6126, '0', '0', 0, 538.51043701171875, 396.930572509765625, 345.73956298828125, 4.059507369995117187, 0, 0, -0.896514892578125, 0.443013608455657958, 90, 255, 1, 55461), -- Food Buff (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+13, 212310, 727, 6126, 6126, '0', '0', 0, 613.2872314453125, 226.6121368408203125, 329.00750732421875, 4.76936960220336914, -0.00124883651733398, 0.007494926452636718, -0.68663692474365234, 0.72696077823638916, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+14, 179907, 727, 6126, 6126, '0', '0', 0, 789.89581298828125, 282.763885498046875, 355.06646728515625, 0.881992816925048828, 0, 0, 0.426840782165527343, 0.904326796531677246, 90, 255, 1, 55461), -- Berserk Buff (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+15, 212313, 727, 6126, 6126, '0', '0', 0, 615.861083984375, 224.8324432373046875, 328.95977783203125, 1.650866150856018066, 0.007508754730224609, 0.001162528991699218, 0.734839439392089843, 0.678198516368865966, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+16, 179906, 727, 6126, 6126, '0', '0', 0, 614.13543701171875, 120.0972213745117187, 294.65618896484375, 4.409838676452636718, 0, 0, -0.80559158325195312, 0.592471241950988769, 90, 255, 1, 55461), -- Food Buff (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+17, 212312, 727, 6126, 6126, '0', '0', 0, 615.8372802734375, 233.672607421875, 328.973297119140625, 4.907505989074707031, 0.007056713104248046, -0.00879669189453125, -0.63480949401855468, 0.772586405277252197, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+18, 212315, 727, 6126, 6126, '0', '0', 0, 615.35125732421875, 227.237213134765625, 328.986175537109375, 5.371253013610839843, 0.001028060913085937, 0.007528305053710937, -0.44030189514160156, 0.897817671298980712, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+19, 212314, 727, 6126, 6126, '0', '0', 0, 612.85968017578125, 229.4408721923828125, 328.98211669921875, 3.111219644546508789, 0.006133079528808593, -0.00960731506347656, 0.999818801879882812, 0.015244622714817523, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+20, 212081, 727, 6126, 6126, '0', '0', 0, 615.50994873046875, 79.418121337890625, 298.286712646484375, 1.654057860374450683, -0.03407955169677734, -0.02646541595458984, 0.735444068908691406, 0.67621016502380371, 7200, 255, 1, 55461), -- Lava Depot (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+21, 212080, 727, 6126, 6126, '0', '0', 0, 564.8048095703125, 337.08734130859375, 347.142730712890625, 1.571253895759582519, 0.011277198791503906, 0.006951332092285156, 0.707234382629394531, 0.706855058670043945, 7200, 255, 1, 55461), -- Waterfall Depot (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+22, 212083, 727, 6126, 6126, '0', '0', 0, 777.7376708984375, 502.31109619140625, 359.453704833984375, 0.719447970390319824, -0.01845312118530273, -0.01729774475097656, 0.351691246032714843, 0.935774266719818115, 7200, 255, 1, 55461), -- Troll Depot (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+23, 212082, 727, 6126, 6126, '0', '0', 0, 896.7935791015625, 25.2902679443359375, 364.14306640625, 3.539994239807128906, -0.00981664657592773, 0.03659820556640625, -0.9795389175415039, 0.197655469179153442, 7200, 255, 1, 55461), -- Diamond Depot (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+24, 212299, 727, 6126, 6126, '0', '0', 0, 863.1053466796875, 131.065765380859375, 328.97515869140625, 5.572046756744384765, 0.006380558013916015, 0.015316963195800781, -0.34808635711669921, 0.937315583229064941, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+25, 212298, 727, 6126, 6126, '0', '0', 0, 865.6170654296875, 130.4124755859375, 328.992523193359375, 4.088826179504394531, 0.021915435791015625, 0.004639625549316406, -0.88975906372070312, 0.455880433320999145, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+26, 212301, 727, 6126, 6126, '0', '0', 0, 868.378662109375, 134.34051513671875, 329.007537841796875, 1.338990211486816406, -0.00759649276733398, -0.00015735626220703, 0.620594024658203125, 0.784095227718353271, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+27, 212300, 727, 6126, 6126, '0', '0', 0, 868.4132080078125, 136.8855133056640625, 328.97802734375, 5.611620426177978515, -0.0039372444152832, -0.00649833679199218, -0.32950973510742187, 0.944121599197387695, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+28, 212303, 727, 6126, 6126, '0', '0', 0, 863.923583984375, 128.2986297607421875, 328.973297119140625, 1.477124452590942382, 0.009720802307128906, 0.005717277526855468, 0.673201560974121093, 0.73937302827835083, 7200, 255, 1, 55461), -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@OGUID+29, 212302, 727, 6126, 6126, '0', '0', 0, 862.1124267578125, 122.314422607421875, 328.96124267578125, 1.480865240097045898, -0.00216007232666015, -0.01177215576171875, 0.674508094787597656, 0.738170385360717773, 7200, 255, 1, 55461); -- Chair (Area: Silvershard Mines - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+29;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Gate
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Lava Depot
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Waterfall Depot
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Troll Depot
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Diamond Depot
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+28, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+29, 0, 0, 1, -0.00000004371138828, 0, 0); -- Chair

UPDATE `gameobject_template` SET `StringId` = 'bg_silvershard_mine_depot' WHERE `entry` IN (212080, 212081, 212082, 212083);

UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=55461 WHERE (`Entry`=60380 AND `DifficultyID`=0); -- 60380 (Mine Cart) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=55461 WHERE (`Entry`=60378 AND `DifficultyID`=0); -- 60378 (Mine Cart) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368, `VerifiedBuild`=55461 WHERE (`Entry`=60379 AND `DifficultyID`=0); -- 60379 (Mine Cart) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55461 WHERE (`Entry`=60145 AND `DifficultyID`=0); -- 60145 (Points Trigger) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=60140 AND `DifficultyID`=0); -- 60140 (Mine Cart) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=55461 WHERE (`Entry`=60283 AND `DifficultyID`=0); -- 60283 (Track Switch) - Floating

UPDATE `creature_template` SET `speed_walk`=5.599999904632568359, `speed_run`=2, `unit_flags2`=0, `ScriptName`='npc_bg_silvershard_mines_mine_cart_cosmetic' WHERE `entry` IN (60380, 60378, 60379); -- Mine Cart
UPDATE `creature_template` SET `unit_flags2`=67108864, `unit_flags3`=16777217, `ScriptName` = 'npc_bg_silvershard_mines_mine_cart' WHERE `entry`=60140; -- Mine Cart
UPDATE `creature_template` SET `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000 WHERE `entry`=60283; -- Track Switch

DELETE FROM `creature_template_addon` WHERE `entry` IN (62671, 62672);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(62671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '122297'), -- 62671 (BANANAS) - Hold Barrel
(62672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '122236'); -- 62672 (Harrison Jones) - Read Scroll

DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (60380,60378));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(60380, 62671, 0, 0, 'Mine Cart - BANANAS', 7, 0), -- Mine Cart - BANANAS
(60378, 62672, 0, 0, 'Mine Cart - Harrison Jones', 7, 0); -- Mine Cart - Harrison Jones

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (60283, 60380, 60378);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(60283, 124491, 0x01, 0), -- Track Switch
(60380, 46598, 0, 0), -- Track Switch
(60378, 46598, 0, 0); -- Track Switch

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 14848, 727, 6126, 6126, '0', '0', 0, 0, 2, 906.5225830078125, 7.706597328186035156, 361.860107421875, 2.000355720520019531, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Herald (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@CGUID+1, 14848, 727, 6126, 6126, '0', '0', 0, 0, 2, 593.90972900390625, 83.7725677490234375, 295.45196533203125, 0.001752360025420784, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Herald (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@CGUID+2, 60145, 727, 6126, 6126, '0', '0', 0, 0, 0, 747.77606201171875, 195.439239501953125, 319.901123046875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Points Trigger (Area: Silvershard Mines - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 14848, 727, 6126, 6126, '0', '0', 0, 0, 2, 760.64239501953125, 517.38714599609375, 357.34368896484375, 5.480351924896240234, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Herald (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@CGUID+4, 14848, 727, 6126, 6126, '0', '0', 0, 0, 2, 545.951416015625, 328.916656494140625, 347.15789794921875, 0.214559689164161682, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Herald (Area: Silvershard Mines - Difficulty: 0) CreateObject1
(@CGUID+5, 60283, 727, 6126, 6126, '0', '0', 0, 0, 0, 715.64239501953125, 100.1649322509765625, 320.284454345703125, 4.592556476593017578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Track Switch (Area: Silvershard Mines - Difficulty: 0) CreateObject1 (Auras: 120228 - Track Switch Visual (Opened))
(@CGUID+6, 60283, 727, 6126, 6126, '0', '0', 0, 0, 0, 845.55731201171875, 307.552093505859375, 347.03790283203125, 0.622477710247039794, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Track Switch (Area: Silvershard Mines - Difficulty: 0) CreateObject1 (Auras: 120228 - Track Switch Visual (Opened))
(@CGUID+7, 13117, 727, 6126, 6126, '0', '0', 0, 0, 1, 626.8836669921875, 231.08160400390625, 329.073974609375, 5.553977012634277343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Horde Spirit Guide (Area: Silvershard Mines - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+8, 13116, 727, 6126, 6126, '0', '0', 0, 0, 1, 854.2100830078125, 132.920135498046875, 329.073974609375, 2.267521858215332031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461); -- Alliance Spirit Guide (Area: Silvershard Mines - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)

UPDATE `creature` SET `StringId` = 'bg_silvershard_mines_track_switch_east' WHERE `guid` = @CGUID+5;
UPDATE `creature` SET `StringId` = 'bg_silvershard_mines_track_switch_north' WHERE `guid` = @CGUID+6;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '120228'), -- Track Switch - 120228 - Track Switch Visual (Opened)
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- Track Switch

DELETE FROM `creature_text` WHERE `CreatureID`=60140;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(60140, 1, 1, 'A %s has arrived from the center depot.', 41, 0, 100, 0, 0, 0, 60444, 3, 'Mine Cart'),
(60140, 2, 1, 'The Alliance has captured a Mine Cart!', 37, 0, 100, 0, 0, 0, 59689, 3, 'Mine Cart'),
(60140, 3, 1, 'The Horde has captured a Mine Cart!', 38, 0, 100, 0, 0, 0, 59690, 3, 'Mine Cart');

SET @PATH := 60140 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - South');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
-- (@PATH, -1, 741.8247, 200.5139, 319.5634, NULL, 0), -- Might be Spawn Position
(@PATH, 0, 738.9358, 204.10417, 319.60315, NULL, 0),
(@PATH, 1, 736.0469, 207.69444, 319.6429, NULL, 0),
(@PATH, 2, 732.5243, 213.625, 320.1088, NULL, 0),
(@PATH, 3, 730.5608, 219.11632, 320.54398, NULL, 0),
(@PATH, 4, 728.0052, 231.57639, 321.03696, NULL, 0),
(@PATH, 5, 725.6285, 236.94444, 321.03174, NULL, 0),
(@PATH, 6, 722.8368, 241.67708, 320.7483, NULL, 0),
(@PATH, 7, 720.7118, 244.52083, 321.24887, NULL, 0),
(@PATH, 8, 715.6458, 251.42361, 321.13367, NULL, 0),
(@PATH, 9, 710.8594, 261.08682, 320.8995, NULL, 0),
(@PATH, 10, 707.2899, 270.05383, 320.63297, NULL, 0),
(@PATH, 11, 703.6528, 278.1771, 320.5885, NULL, 0),
(@PATH, 12, 696.5243, 290.17883, 320.65274, NULL, 0),
(@PATH, 13, 686.26044, 301.60416, 321.03854, NULL, 0),
(@PATH, 14, 667.94965, 317.13715, 323.14688, NULL, 0),
(@PATH, 15, 660.3976, 323.90625, 324.70975, NULL, 0),
(@PATH, 16, 651.4028, 331.2066, 327.37286, NULL, 0),
(@PATH, 17, 638.68054, 342.33853, 332.27582, NULL, 0),
(@PATH, 18, 633.8316, 345.2587, 334.5666, NULL, 0),
(@PATH, 19, 626.21704, 345.49133, 337.44138, NULL, 0),
(@PATH, 20, 616.74133, 343.22397, 340.5497, NULL, 0),
(@PATH, 21, 601.7222, 340.30728, 344.57382, NULL, 0),
(@PATH, 22, 592.059, 339.27432, 346.0716, NULL, 0),
(@PATH, 23, 585.47394, 337.6736, 346.30173, NULL, 0);

SET @PATH := 60140 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - South - End');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 563.509, 337.615,  347.005, NULL, 0);

SET @PATH := 60140 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - North');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 759.32465, 198.3316, 319.53058, NULL, 0),
(@PATH, 1, 762.0156, 199.5382, 319.5831, NULL, 0),
(@PATH, 2, 765.59375, 202.52951, 319.96033, NULL, 0),
(@PATH, 3, 770.78644, 210.38194, 321.3461, NULL, 0),
(@PATH, 4, 776.9566, 222.91667, 323.30746, NULL, 0),
(@PATH, 5, 780.19617, 232.62154, 324.97916, NULL, 0),
(@PATH, 6, 783.5833, 241.64583, 327.92972, NULL, 0),
(@PATH, 7, 787.6268, 249.40105, 330.78836, NULL, 0),
(@PATH, 8, 794.5851, 259.57986, 336.81503, NULL, 0),
(@PATH, 9, 803.3455, 269.59027, 341.3372, NULL, 0),
(@PATH, 10, 816.42706, 282.56424, 344.84903, NULL, 0),
(@PATH, 11, 823.8924, 289.4271, 345.9665, NULL, 0),
(@PATH, 12, 830.2726, 294.85764, 346.55655, NULL, 0),
(@PATH, 13, 835.59204, 300.4184, 346.95596, NULL, 0);

SET @PATH := 60140 * 100 + 3;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - North - East');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 838.25696, 302.21875, 347.33386, NULL, 0),
(@PATH, 1, 843.25696, 303.46875, 347.33386, NULL, 0),
(@PATH, 2, 848.25696, 303.71875, 347.33386, NULL, 0),
(@PATH, 3, 854.00696, 303.21875, 347.33386, NULL, 0),
(@PATH, 4, 860.00696, 301.46875, 347.58386, NULL, 0),
(@PATH, 5, 863.50696, 299.96875, 347.58386, NULL, 0),
(@PATH, 6, 867.25696, 297.46875, 347.58386, NULL, 0),
(@PATH, 7, 877.25696, 287.71875, 347.58386, NULL, 0),
(@PATH, 8, 881.75696, 279.21875, 347.33386, NULL, 0),
(@PATH, 9, 885.75696, 270.46875, 346.83386, NULL, 0),
(@PATH, 10, 889.25696, 261.21875, 346.33386, NULL, 0),
(@PATH, 11, 893.50696, 248.71875, 346.08386, NULL, 0),
(@PATH, 12, 894.75696, 241.71875, 346.58386, NULL, 0),
(@PATH, 13, 897.75696, 226.46875, 350.08386, NULL, 0),
(@PATH, 14, 904.25696, 210.46875, 354.83386, NULL, 0),
(@PATH, 15, 911.50696, 178.46875, 363.83386, NULL, 0),
(@PATH, 16, 912.50696, 168.21875, 366.58386, NULL, 0),
(@PATH, 17, 912.00696, 163.21875, 366.83386, NULL, 0),
(@PATH, 18, 909.00696, 153.46875, 366.83386, NULL, 0),
(@PATH, 19, 907.00696, 149.71875, 366.83386, NULL, 0),
(@PATH, 20, 898.25696, 138.71875, 366.83386, NULL, 0),
(@PATH, 21, 888.25696, 126.21875, 366.58386, NULL, 0),
(@PATH, 22, 885.50696, 120.46875, 366.33386, NULL, 0),
(@PATH, 23, 882.75696, 109.21875, 365.83386, NULL, 0),
(@PATH, 24, 882.25696, 104.71875, 365.58386, NULL, 0),
(@PATH, 25, 883.75696, 97.21875, 365.33386, NULL, 0),
(@PATH, 26, 889.00696, 89.46875, 365.08386, NULL, 0),
(@PATH, 27, 891.00696, 82.46875, 365.08386, NULL, 0),
(@PATH, 28, 891.00696, 76.46875, 364.83386, NULL, 0),
(@PATH, 29, 890.25696, 70.96875, 365.08386, NULL, 0),
(@PATH, 30, 890.75696, 62.96875, 364.83386, NULL, 0),
(@PATH, 31, 891.75696, 56.21875, 364.58386, NULL, 0),
(@PATH, 32, 893.9219, 45.519096, 363.71173, NULL, 0);

SET @PATH := 60140 * 100 + 4;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - North - East - End');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 893.2969, 41.380196, 363.83173, NULL, 0),
(@PATH, 1, 893.2969, 37.880196, 364.08173, NULL, 0),
(@PATH, 2, 893.2969, 35.130196, 364.08173, NULL, 0),
(@PATH, 3, 893.5469, 33.130196, 364.08173, NULL, 0),
(@PATH, 4, 895.2969, 29.380196, 364.08173, NULL, 0),
(@PATH, 5, 897.1719, 25.24132, 363.95175, NULL, 0);

SET @PATH := 60140 * 100 + 5;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - North - West');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 837.74133, 303.2179, 347.39374, NULL, 0),
(@PATH, 1, 840.74133, 307.4679, 347.39374, NULL, 0),
(@PATH, 2, 844.74133, 314.2179, 347.39374, NULL, 0),
(@PATH, 3, 847.99133, 321.7179, 347.64374, NULL, 0),
(@PATH, 4, 848.74133, 326.9679, 347.39374, NULL, 0),
(@PATH, 5, 846.99133, 342.7179, 347.39374, NULL, 0),
(@PATH, 6, 843.49133, 350.9679, 347.64374, NULL, 0),
(@PATH, 7, 831.99133, 372.4679, 347.39374, NULL, 0),
(@PATH, 8, 822.49133, 397.4679, 347.14374, NULL, 0),
(@PATH, 9, 818.74133, 406.9679, 348.14374, NULL, 0),
(@PATH, 10, 817.99133, 410.4679, 348.89374, NULL, 0),
(@PATH, 11, 816.74133, 419.2179, 350.64374, NULL, 0),
(@PATH, 12, 817.24133, 422.7179, 351.39374, NULL, 0),
(@PATH, 13, 815.99133, 429.2179, 353.39374, NULL, 0),
(@PATH, 14, 814.24133, 434.7179, 355.14374, NULL, 0),
(@PATH, 15, 810.99133, 442.2179, 357.14374, NULL, 0),
(@PATH, 16, 807.49133, 457.7179, 358.89374, NULL, 0),
(@PATH, 17, 806.74133, 466.4679, 359.14374, NULL, 0),
(@PATH, 18, 803.99133, 472.9679, 359.39374, NULL, 0),
(@PATH, 19, 800.99133, 476.9679, 359.64374, NULL, 0),
(@PATH, 20, 793.74133, 485.2179, 359.64374, NULL, 0),
(@PATH, 21, 791.3906, 487.51736, 359.3315, NULL, 0);

SET @PATH := 60140 * 100 + 6;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - North - West - End');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 778.271, 502.75, 359.293, NULL, 0);

SET @PATH := 60140 * 100 + 7;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - East');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 744.5174, 183.19792, 319.54395, NULL, 0),
(@PATH, 1, 742.8542, 178.96355, 319.60175, NULL, 0),
(@PATH, 2, 739.8906, 171.5191, 319.36505, NULL, 0),
(@PATH, 3, 735.5955, 163.54341, 319.2191, NULL, 0),
(@PATH, 4, 730.4774, 155.19444, 319.13043, NULL, 0),
(@PATH, 5, 728.85767, 152.40625, 319.62506, NULL, 0),
(@PATH, 6, 723.92365, 143.10417, 319.6667, NULL, 0),
(@PATH, 7, 719.36456, 131.09375, 319.55307, NULL, 0),
(@PATH, 8, 717.6007, 122.72222, 320.09778, NULL, 0),
(@PATH, 9, 716.9514, 113.51736, 320.84427, NULL, 0);

SET @PATH := 60140 * 100 + 8;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - East - South');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 715.82294, 109.03732, 321.0153, NULL, 0),
(@PATH, 1, 713.32294, 104.28732, 320.2653, NULL, 0),
(@PATH, 2, 706.82294, 99.28732, 319.0153, NULL, 0),
(@PATH, 3, 701.82294, 97.28732, 317.7653, NULL, 0),
(@PATH, 4, 695.07294, 96.53732, 316.2653, NULL, 0),
(@PATH, 5, 686.57294, 95.53732, 314.5153, NULL, 0),
(@PATH, 6, 680.32294, 94.53732, 312.7653, NULL, 0),
(@PATH, 7, 670.32294, 90.03732, 309.5153, NULL, 0),
(@PATH, 8, 663.82294, 86.53732, 307.0153, NULL, 0),
(@PATH, 9, 660.32294, 84.53732, 305.7653, NULL, 0),
(@PATH, 10, 647.32294, 82.03732, 302.0153, NULL, 0),
(@PATH, 11, 638.57294, 81.53732, 299.5153, NULL, 0),
(@PATH, 12, 634.69446, 81.05729, 298.6863, NULL, 0);

SET @PATH := 60140 * 100 + 9;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - East - South - End');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 615.415, 79.6458, 298.101, NULL, 0);

SET @PATH := 60140 * 100 + 10;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - East - North');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 716.97485, 108.50173, 321.13733, NULL, 0),
(@PATH, 1, 719.97485, 101.50173, 321.38733, NULL, 0),
(@PATH, 2, 724.47485, 98.25173, 322.13733, NULL, 0),
(@PATH, 3, 732.72485, 94.75173, 323.88733, NULL, 0),
(@PATH, 4, 737.72485, 93.75173, 325.88733, NULL, 0),
(@PATH, 5, 744.47485, 92.25173, 328.13733, NULL, 0),
(@PATH, 6, 758.72485, 89.25173, 332.88733, NULL, 0),
(@PATH, 7, 767.22485, 86.00173, 336.13733, NULL, 0),
(@PATH, 8, 774.22485, 82.25173, 339.38733, NULL, 0),
(@PATH, 9, 784.22485, 79.50173, 342.88733, NULL, 0),
(@PATH, 10, 793.72485, 78.25173, 346.13733, NULL, 0),
(@PATH, 11, 798.22485, 77.25173, 348.13733, NULL, 0),
(@PATH, 12, 803.97485, 74.75173, 349.88733, NULL, 0),
(@PATH, 13, 807.72485, 72.25173, 351.13733, NULL, 0),
(@PATH, 14, 813.47485, 67.75173, 352.88733, NULL, 0),
(@PATH, 15, 819.97485, 64.00173, 354.88733, NULL, 0),
(@PATH, 16, 823.97485, 63.00173, 355.88733, NULL, 0),
(@PATH, 17, 829.72485, 63.00173, 357.13733, NULL, 0),
(@PATH, 18, 833.47485, 64.25173, 357.88733, NULL, 0),
(@PATH, 19, 842.22485, 70.50173, 359.88733, NULL, 0),
(@PATH, 20, 850.47485, 71.50173, 361.38733, NULL, 0),
(@PATH, 21, 859.47485, 69.00173, 362.88733, NULL, 0),
(@PATH, 22, 865.47485, 65.25173, 363.88733, NULL, 0),
(@PATH, 23, 873.47485, 58.00173, 364.63733, NULL, 0),
(@PATH, 24, 879.72485, 51.75173, 364.63733, NULL, 0),
(@PATH, 25, 885.4983, 42.98611, 363.93036, NULL, 0);

SET @PATH := 60140 * 100 + 11;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart - East - North - End');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 887.8976, 40.052082, 363.96014, NULL, 0),
(@PATH, 1, 890.1476, 37.052082, 363.96014, NULL, 0),
(@PATH, 2, 891.8976, 34.802082, 364.21014, NULL, 0),
(@PATH, 3, 893.1476, 33.302082, 364.21014, NULL, 0),
(@PATH, 4, 895.1476, 29.302082, 364.21014, NULL, 0),
(@PATH, 5, 896.7969, 25.618055, 363.98996, null, 0);

SET @PATH := 60379 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart (Cosmetic) - 1');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 735.7135, 293.2292, 398.70938, NULL, 0),
(@PATH, 1, 731.86456, 290.72745, 398.5858, NULL, 0),
(@PATH, 2, 728.0156, 288.2257, 398.4622, NULL, 0),
(@PATH, 3, 714.0347, 274.5382, 395.02786, NULL, 0),
(@PATH, 4, 706.36804, 263.4514, 393.16946, NULL, 0),
(@PATH, 5, 698.7674, 246.16145, 391.61017, NULL, 0),
(@PATH, 6, 693.3455, 230.83333, 391.1844, NULL, 0),
(@PATH, 7, 692.309, 213.23611, 390.35565, NULL, 0),
(@PATH, 8, 697.783, 197.06598, 388.44452, NULL, 0),
(@PATH, 9, 705.8802, 185.94618, 386.44757, NULL, 0),
(@PATH, 10, 722.11804, 176.19966, 380.83176, NULL, 0),
(@PATH, 11, 738.55035, 174.20486, 376.92075, NULL, 0),
(@PATH, 12, 745.15454, 174.79341, 375.73212, NULL, 0),
(@PATH, 13, 756.8698, 178.67014, 373.56097, NULL, 0),
(@PATH, 14, 760.05206, 180.32812, 373.28217, NULL, 0),
(@PATH, 15, 771.40106, 190.80035, 374.18176, NULL, 0),
(@PATH, 16, 778.2118, 199.4948, 375.7447, NULL, 0),
(@PATH, 17, 786.6476, 217.34201, 379.0099, NULL, 0),
(@PATH, 18, 790.3073, 228.7257, 379.14127, NULL, 0),
(@PATH, 19, 792.0139, 239.59029, 376.86124, NULL, 0),
(@PATH, 20, 793.3733, 245.70139, 374.7973, NULL, 0),
(@PATH, 21, 797.2743, 254.91145, 371.12878, NULL, 0),
(@PATH, 22, 800.6684, 260.34723, 368.272, NULL, 0),
(@PATH, 23, 804.48267, 263.93924, 368.13562, NULL, 0),
(@PATH, 24, 815.56946, 272.24652, 368.79605, NULL, 0),
(@PATH, 25, 823.11456, 280.97745, 370.88733, NULL, 0),
(@PATH, 26, 834.38715, 294.5087, 373.0812, NULL, 0),
(@PATH, 27, 848.27954, 307.47397, 374.22733, NULL, 0),
(@PATH, 28, 860.3802, 320.32465, 375.4498, NULL, 0),
(@PATH, 29, 871.44446, 333.64236, 376.49252, NULL, 0),
(@PATH, 30, 875.5174, 338.5434, 376.8501, NULL, 0),
(@PATH, 31, 880.76044, 342.86285, 378.05972, NULL, 0),
(@PATH, 32, 889.17365, 348.11978, 380.0994, NULL, 0),
(@PATH, 33, 893.8594, 350.12152, 381.12195, NULL, 0),
(@PATH, 34, 899.5382, 350.87326, 382.26337, NULL, 0),
(@PATH, 35, 913.4601, 352.25696, 383.08, NULL, 0),
(@PATH, 36, 928.8368, 353.97916, 383.14316, NULL, 0),
(@PATH, 37, 933.809, 354.85416, 383.23328, NULL, 0),
(@PATH, 38, 947.9757, 361.87674, 384.30017, NULL, 0),
(@PATH, 39, 957.875, 368.30728, 384.98563, NULL, 0),
(@PATH, 40, 965.8108, 372.96353, 384.33072, NULL, 0),
(@PATH, 41, 987.5052, 379.3889, 383.41644, NULL, 0),
(@PATH, 42, 1004.0208, 381.5, 383.40344, NULL, 0),
(@PATH, 43, 1013.2708, 380.30557, 382.4711, NULL, 0),
(@PATH, 44, 1026.6077, 375.3021, 380.2595, NULL, 0),
(@PATH, 45, 1032.1163, 371.1632, 379.65323, NULL, 0),
(@PATH, 46, 1037.3195, 367.58682, 379.32047, NULL, 0),
(@PATH, 47, 1041.4375, 363.4514, 379.4645, NULL, 0),
(@PATH, 48, 1048.9202, 355.4479, 379.80124, NULL, 0),
(@PATH, 49, 1053.4896, 347.11978, 379.97577, NULL, 0),
(@PATH, 50, 1058.8125, 334.93402, 380.25137, NULL, 0),
(@PATH, 51, 1064.6041, 316.09897, 380.37222, NULL, 0),
(@PATH, 52, 1063.8524, 306.75522, 379.75546, NULL, 0),
(@PATH, 53, 1062.0416, 300.1337, 378.58887, NULL, 0),
(@PATH, 54, 1059.6476, 296.14932, 377.7218, NULL, 0),
(@PATH, 55, 1045.026, 275.39758, 375.382, NULL, 0);

SET @PATH := 60379 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart (Cosmetic) - 2');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 580.17706, 305.46524, 395.6946, NULL, 0),
(@PATH, 1, 583.8715, 304.40103, 396.251, NULL, 0),
(@PATH, 2, 587.566, 303.33682, 396.8074, NULL, 0),
(@PATH, 3, 601.57465, 312.1771, 396.0683, NULL, 0),
(@PATH, 4, 618.4549, 316.8611, 394.96066, NULL, 0),
(@PATH, 5, 635.9514, 318.70486, 394.21738, NULL, 0),
(@PATH, 6, 648.25867, 318.11807, 393.31815, NULL, 0),
(@PATH, 7, 658.309, 312.55557, 390.93103, NULL, 0),
(@PATH, 8, 661.7483, 310.2396, 389.92807, NULL, 0),
(@PATH, 9, 669.8281, 299.9809, 388.26355, NULL, 0),
(@PATH, 10, 673.09375, 296.39932, 387.64984, NULL, 0),
(@PATH, 11, 678.57294, 290.21875, 386.97983, NULL, 0),
(@PATH, 12, 682.033, 286.47397, 386.33453, NULL, 0),
(@PATH, 13, 690.8507, 270.93228, 384.19302, NULL, 0),
(@PATH, 14, 702.21356, 258.717, 380.11124, NULL, 0),
(@PATH, 15, 708.0972, 255.76042, 378.24768, NULL, 0),
(@PATH, 16, 721.75, 251.1875, 374.3099, NULL, 0),
(@PATH, 17, 738.5972, 251.07986, 371.8639, NULL, 0),
(@PATH, 18, 754.90625, 252.67535, 370.3364, NULL, 0),
(@PATH, 19, 773.30206, 255.25, 369.9608, NULL, 0),
(@PATH, 20, 784.9809, 256.5521, 369.80273, NULL, 0),
(@PATH, 21, 799.65454, 261.37848, 368.89142, NULL, 0),
(@PATH, 22, 815.2309, 272.30902, 368.7668, NULL, 0),
(@PATH, 23, 823.17706, 280.9045, 370.88882, NULL, 0),
(@PATH, 24, 833.94446, 294.62674, 373.07675, NULL, 0),
(@PATH, 25, 848.4583, 307.42014, 374.23453, NULL, 0),
(@PATH, 26, 860.01044, 320.06076, 375.40463, NULL, 0),
(@PATH, 27, 874.8958, 338.64758, 376.81577, NULL, 0),
(@PATH, 28, 889.1285, 348.17883, 380.09464, NULL, 0),
(@PATH, 29, 893.93054, 349.85416, 381.11908, NULL, 0),
(@PATH, 30, 899.82465, 350.94965, 382.29288, NULL, 0),
(@PATH, 31, 913.46356, 352.2014, 383.08054, NULL, 0),
(@PATH, 32, 929.11115, 353.93402, 383.16205, NULL, 0),
(@PATH, 33, 933.67365, 354.78125, 383.21063, NULL, 0),
(@PATH, 34, 947.7917, 361.9566, 384.28598, NULL, 0),
(@PATH, 35, 957.55206, 368.69965, 385.0245, NULL, 0),
(@PATH, 36, 965.9583, 373.408, 384.33798, NULL, 0),
(@PATH, 37, 976.3715, 377.1059, 383.54767, NULL, 0),
(@PATH, 38, 996.7101, 381.62326, 383.80093, NULL, 0);

SET @PATH := 60379 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0x2, 'Battleground Silvershard Mines - Mine Cart (Cosmetic) - 3');

DELETE FROM `waypoint_path_node` WHERE `PathId` = @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1117.7551, 285.7205, 389.8406, NULL, 0),
(@PATH, 1, 1112.283, 287.04688, 390.49927, NULL, 0),
(@PATH, 2, 1106.8108, 288.37326, 391.15793, NULL, 0),
(@PATH, 3, 1085.8785, 293.11807, 392.2367, NULL, 0),
(@PATH, 4, 1069.0625, 297.52603, 391.34763, NULL, 0),
(@PATH, 5, 1048.908, 294.625, 390.70905, NULL, 0),
(@PATH, 6, 1032.3317, 289.79514, 389.98892, NULL, 0),
(@PATH, 7, 1020.8004, 285.28995, 389.7066, NULL, 0),
(@PATH, 8, 1012.1007, 281.94446, 389.90375, NULL, 0),
(@PATH, 9, 1000.3351, 271.69965, 392.6553, NULL, 0),
(@PATH, 10, 994.21356, 263.77777, 394.44055, NULL, 0),
(@PATH, 11, 975.9774, 236.66667, 395.3355, NULL, 0),
(@PATH, 12, 955.8941, 207.41493, 393.21887, NULL, 0),
(@PATH, 13, 948.24304, 192.37326, 396.24258, NULL, 0),
(@PATH, 14, 944.36285, 182.16145, 398.97665, NULL, 0),
(@PATH, 15, 941.1302, 176.33507, 400.0023, NULL, 0),
(@PATH, 16, 938.5278, 173.0868, 400.44632, NULL, 0),
(@PATH, 17, 934.0434, 168.74132, 400.6807, NULL, 0),
(@PATH, 18, 929.7205, 164.76562, 400.79932, NULL, 0),
(@PATH, 19, 906.75867, 146.71875, 402.70294, NULL, 0),
(@PATH, 20, 903.158, 142.79688, 403.11172, NULL, 0),
(@PATH, 21, 897.2917, 133.44618, 403.73123, NULL, 0),
(@PATH, 22, 891.4618, 122.44618, 403.4227, NULL, 0),
(@PATH, 23, 887.09375, 109.50521, 404.85757, NULL, 0),
(@PATH, 24, 878.2118, 96.80729, 407.5734, NULL, 0),
(@PATH, 25, 871.0018, 88.90972, 408.27496, NULL, 0),
(@PATH, 26, 860.5382, 77.55903, 407.2642, NULL, 0),
(@PATH, 27, 853.0347, 71.40104, 405.6935, NULL, 0),
(@PATH, 28, 830.0677, 57.95139, 400.13443, NULL, 0),
(@PATH, 29, 822.6893, 56.282986, 399.9273, NULL, 0),
(@PATH, 30, 813.30554, 56.605904, 400.81268, NULL, 0);
