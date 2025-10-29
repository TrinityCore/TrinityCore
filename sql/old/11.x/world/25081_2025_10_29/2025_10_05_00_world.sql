SET @ATSPAWN := 271;
SET @ATID := 174;
SET @ATPROP := 167;

-- Creature
UPDATE `creature_template_addon` SET `auras`='160758' WHERE `entry`=134060; -- 134060 (Lord Stormsong) - Mod Scale 140%
UPDATE `creature_template` SET `ScriptName`='boss_lord_stormsong' WHERE `entry`=134060;
UPDATE `creature_template` SET `ScriptName`='boss_lord_stormsong_brother_pike' WHERE `entry`=139970;
UPDATE `creature_template` SET `ScriptName`='boss_lord_stormsong_rexxar' WHERE `entry`=139971;
UPDATE `creature_template` SET `ScriptName`='boss_lord_stormsong_ancient_mindbender' WHERE `entry`=137051;
UPDATE `creature_template` SET `faction`=14, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x1280000, `AIName`='SmartAI' WHERE `entry`=137036; -- Awoken Void

DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (137036, 134060, 137051, 82347);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`, `LootID`, `PickPocketLootID`, `SkinLootID`, `GoldMin`, `GoldMax`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(137036, 0, 0, 0, 500, 0, 1, 1, 1, 1, 143479, 1610612752, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137036, 1, 0, 0, 500, 7, 1, 1, 1, 1, 143479, 1610612752, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137036, 2, 0, 0, 501, 7, 1, 1, 1, 1, 158853, 1610612752, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137036, 23, 0, 0, 502, 7, 1, 1, 1, 1, 158854, 1610612752, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(134060, 0, 2, 2, 500, 7, 35, 55, 1, 1, 140110, 2097224, 129, 0, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 63305),
(134060, 1, 2, 2, 500, 7, 35, 55, 1, 1, 140110, 2097224, 129, 0, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 63305),
(134060, 2, 2, 2, 501, 7, 35, 55.3403, 1, 1, 144314, 2097224, 129, 0, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 63305),
(134060, 23, 2, 2, 502, 7, 35, 55.3403, 1, 1, 144315, 2097224, 129, 0, 0, 0, 0, 0, 0, 268435456, 0, 0, 0, 0, 0, 0, 0, 63305),
(137051, 0, 0, 0, 500, 7, 3, 1, 1, 1, 143496, 2097224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137051, 1, 0, 0, 500, 7, 3, 1, 1, 1, 143496, 2097224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137051, 2, 0, 0, 501, 7, 3, 1, 1, 1, 144310, 2097224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(137051, 23, 0, 0, 502, 7, 3, 1, 1, 1, 144311, 2097224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63305),
(82347, 0, 0, 0, 181, 10, 0.01, 1, 1, 1, 80443, 0, 0, 0, 0, 0, 0, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 63305),
(82347, 1, 0, 0, 181, 10, 0.01, 1, 1, 1, 80443, 0, 0, 0, 0, 0, 0, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 63305),
(82347, 2, 0, 0, 181, 10, 1, 1, 1, 1, 80443, 0, 0, 0, 0, 0, 0, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 63305),
(82347, 23, 0, 0, 181, 9, 0.01, 1, 1, 1, 80443, 0, 0, 0, 0, 0, 0, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 63305);

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (13289));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(13289, 0, 17892, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 1.5, 1.5, 4, 4, 1, 1, 0, 0, 'at_lord_stormsong_waken_the_void', 63305); -- Spell: 269094 (Waken the Void)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (17892));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(17892, 0, 63305);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWN;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWN, @ATPROP, 1, 1864, '1,2,23,8', 3578.1179, -1450.8363, 156.6917, 2.635109, 0, 0, 0, 'at_lord_stormsong_intro', 'Shrine of the Storm - Lord Stormsong intro', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROP AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATPROP, 1, @ATID, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 20, 10, 5, 20, 10, 5, 0, 0, '', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID, 1, 1, 0, 0, 0);

-- Spells
DELETE FROM `serverside_spell` WHERE `Id` = 269396;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(269396, 0, 0, 0, 0, 0x29240180, 0x000004A8, 0x10484004, 0x00070000, 0x00800080, 0x00060008, 0x00001000, 0x00000040, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, -1, 0, 0, 'Lord Stormsong Gain Energy', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` = 269396;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(269396, 0, 0, 6, 226, 0, 0, 1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`IN ('spell_lord_stormsong_release_void_missile', 'spell_lord_stormsong_release_void', 'spell_lord_stormsong_ancient_mindbender', 'spell_lord_stormsong_energize', 'spell_lord_stormsong_fixate', 'spell_lord_stormsong_surrender_to_the_void', 'spell_lord_stormsong_disciple_of_the_vol_zith', 'spell_lord_stormsong_waken_the_void_missile');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(269131, 'spell_lord_stormsong_ancient_mindbender'),
(269396, 'spell_lord_stormsong_energize'),
(269103, 'spell_lord_stormsong_fixate'),
(274711, 'spell_lord_stormsong_release_void'),
(274710, 'spell_lord_stormsong_release_void_missile'),
(269242, 'spell_lord_stormsong_surrender_to_the_void'),
(269289, 'spell_lord_stormsong_disciple_of_the_vol_zith'),
(269021, 'spell_lord_stormsong_waken_the_void_missile');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 134060;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(134060, 0, 0, '|TInterface\\Icons\\Spell_shadow_mindflay.blp:20|tAn |cFFFF0000|Hspell:269131|h[Ancient Mindbender]|h|r attaches to |cFFFF0000$n|r!', 41, 0, 100, 0, 0, 0, 152885, 0, 'Lord Stormsong to Player');

-- Sai
DELETE FROM `smart_scripts` WHERE `entryorguid`=137036 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(137036, 0, 0, 1, '', 54, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 269021, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Awoken Void - On summoned - Self: Cast spell 269021'),
(137036, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Awoken Void - On linked - Set Reactstate React Passive');

-- Conversation
DELETE FROM `conversation_actors` WHERE (`ConversationId`=8767 AND `Idx` = 0) OR (`ConversationId`=8766 AND `Idx` = 0) OR (`ConversationId`=8751 AND `Idx` IN (1,0)) OR (`ConversationId`=8749 AND `Idx` IN (1,0)) OR (`ConversationId`=8750 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`)  VALUES
(8767, 65085, 0, 0, 139971, 0, 0, 0, 63305), -- Full: 0x2016D4E90088B0C00058DC00005ACAFC Creature/0 R1461/S22748 Map: 1864 (Shrine of the Storm) Entry: 139971 (Rexxar) Low: 5950204
(8766, 65078, 0, 0, 139970, 0, 0, 0, 63305), -- Full: 0x20424CE90088B0800029BA000057ECD7 Creature/0 R4243/S10682 Map: 1864 (Shrine of the Storm) Entry: 139970 (Brother Pike) Low: 5762263
(8751, 65085, 0, 1, 139971, 0, 0, 0, 63305), -- Full: 0x2016D4E90088B0C00058DC00005ACAFC Creature/0 R1461/S22748 Map: 1864 (Shrine of the Storm) Entry: 139971 (Rexxar) Low: 5950204
(8751, 62882, 7000893, 0, 0, 0, 0, 0, 63305), -- Full: 0x2016D4E90082EB000058DC00005AC3A6 Creature/0 R1461/S22748 Map: 1864 (Shrine of the Storm) Entry: 134060 (Lord Stormsong) Low: 5948326
(8749, 65076, 7000896, 1, 0, 0, 0, 0, 63305), -- Full: 0x202FD4E90088AEC0003F4E000052B167 Creature/0 R3061/S16206 Map: 1864 (Shrine of the Storm) Entry: 139963 (Queen Azshara) Low: 5419367
(8749, 62882, 7000893, 0, 0, 0, 0, 0, 63305), -- Full: 0x202FD4E90082EB00003F4E000052B167 Creature/0 R3061/S16206 Map: 1864 (Shrine of the Storm) Entry: 134060 (Lord Stormsong) Low: 5419367
(8750, 62882, 7000893, 1, 0, 0, 0, 0, 63305), -- Full: 0x202FD4E90082EB00003F4E000052B167 Creature/0 R3061/S16206 Map: 1864 (Shrine of the Storm) Entry: 134060 (Lord Stormsong) Low: 5419367
(8750, 65078, 0, 0, 139970, 0, 0, 0, 63305); -- Full: 0x202FD4E90088B080003F4E000052B241 Creature/0 R3061/S16206 Map: 1864 (Shrine of the Storm) Entry: 139970 (Brother Pike) Low: 5419585

DELETE FROM `conversation_line_template` WHERE `Id` IN (19655, 19654, 19653, 19652, 19651, 19650, 19598, 19597, 19612, 19611, 19610, 19609, 19608, 19607, 19606, 19605);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(19655, 0, 0, 0, 0, 63305),
(19654, 0, 0, 0, 0, 63305),
(19653, 0, 0, 0, 0, 63305),
(19652, 0, 0, 0, 0, 63305),
(19651, 0, 0, 0, 0, 63305),
(19650, 0, 0, 0, 0, 63305),
(19598, 0, 1, 0, 0, 63305),
(19597, 0, 0, 0, 0, 63305),
(19612, 0, 1, 0, 0, 63305),
(19611, 0, 1, 0, 0, 63305),
(19610, 0, 0, 0, 0, 63305),
(19609, 0, 1, 0, 1, 63305),
(19608, 0, 0, 0, 0, 63305),
(19607, 0, 1, 0, 0, 63305),
(19606, 0, 1, 0, 1, 63305),
(19605, 0, 0, 0, 1, 63305);

DELETE FROM `conversation_template` WHERE `Id` IN (8750, 8749, 8767, 8766, 8751);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(8750, 19605, 0, 'conversation_lord_stormsong_brother_pike_intro_outro', 63305),
(8767, 19653, 0, 'conversation_lord_stormsong_rexxar_outro', 63305),
(8766, 19650, 0, 'conversation_lord_stormsong_brother_pike_intro_outro', 63305),
(8751, 19610, 0, 'conversation_lord_stormsong_rexxar_intro', 63305),
(8749, 19597, 0, '', 63305);

-- Waypoints
SET @ENTRY := 139970;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Brother Pike/Rexxar - Lord Stormsong intro path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3610.2056, -1374.7302, 160.579, NULL, 0),
(@PATH, 1, 3608.8958, -1378.4115, 160.57855, NULL, 0),
(@PATH, 2, 3607.586, -1382.0928, 160.57811, NULL, 0),
(@PATH, 3, 3606.2456, -1385.8595, 160.0007, NULL, 0),
(@PATH, 4, 3604.7078, -1390.1816, 159.93288, NULL, 0),
(@PATH, 5, 3603.3623, -1393.9633, 159.97807, NULL, 0),
(@PATH, 6, 3602.0173, -1397.743, 159.97806, NULL, 0),
(@PATH, 7, 3595.3533, -1411.257, 159.97807, NULL, 0),
(@PATH, 8, 3587.605, -1425.5087, 160.00375, NULL, 0),
(@PATH, 9, 3579.908, -1436.9341, 159.97806, NULL, 0),
(@PATH, 10, 3561.501, -1465.5017, 153.70235, NULL, 0),
(@PATH, 11, 3557.8325, -1476.3142, 153.37808, NULL, 0);

SET @ENTRY := 139970;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Brother Pike/Rexxar - Lord Stormsong outro path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3546.2266, -1492.658, 153.37653, NULL, 0),
(@PATH, 1, 3542.8281, -1499.783, 154.04007, NULL, 0),
(@PATH, 2, 3539.2778, -1512.4166, 153.60727, NULL, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=274646;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 274646, 0, 0, 51, 0, 5, 139970, 0, '', 0, 0, 0, '', 'Spell \'Dark Binding\' can only hit \'Brother Pike\''),
(13, 2, 274646, 0, 0, 51, 0, 5, 139970, 0, '', 0, 0, 0, '', 'Spell \'Dark Binding\' can only hit \'Brother Pike\''),
(13, 1, 274646, 0, 1, 51, 0, 5, 139971, 0, '', 0, 0, 0, '', 'Spell \'Dark Binding\' can only hit \'Rexxar\''),
(13, 2, 274646, 0, 1, 51, 0, 5, 139971, 0, '', 0, 0, 0, '', 'Spell \'Dark Binding\' can only hit \'Rexxar\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=269242;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 269242, 0, 0, 51, 0, 5, 134060, 0, '', 0, 0, 0, '', 'Spell \'Surrender to the Void\' can only hit \'Lord Stormsong\'');
