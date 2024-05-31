-- Creature
UPDATE `creature` SET `PhaseId` = 0 WHERE `id` = 54130 AND `PhaseId` = 629;
UPDATE `creature_template` SET `StringId`='npc_min_dimwind', `VerifiedBuild`=53040 WHERE `entry`=54855;
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `ScriptName`='npc_min_dimwind_summon' WHERE `entry`=56503; -- Min Dimwind
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (54785,54855)); -- Min Dimwind
UPDATE `creature_template_addon` SET `auras`='109005' WHERE `entry`=56503; -- Min Dimwind - Min Dimwind Guardian Aura (SERVERSIDE)

UPDATE `creature` SET `ScriptName`='npc_amberleaf_scamp', `StringId`='npc_amberleaf_scamp_1', `VerifiedBuild`=53040 WHERE `guid`=450251;
UPDATE `creature` SET `ScriptName`='npc_amberleaf_scamp', `StringId`='npc_amberleaf_scamp_2', `VerifiedBuild`=53040 WHERE `guid`=450268;
UPDATE `creature` SET `ScriptName`='npc_amberleaf_scamp', `StringId`='npc_amberleaf_scamp_3', `VerifiedBuild`=53040 WHERE `guid`=450248;
UPDATE `creature` SET `ScriptName`='npc_amberleaf_scamp', `StringId`='npc_amberleaf_scamp_4', `VerifiedBuild`=53040 WHERE `guid`=450245;
UPDATE `creature` SET `ScriptName`='npc_amberleaf_scamp', `StringId`='npc_amberleaf_scamp_5', `VerifiedBuild`=53040 WHERE `guid`=450247;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=106205;
INSERT INTO `conditions` VALUES
(13, 1, 106205, 0, 0, 31, 0, 3, 54855, 0, '', 0, 0, 0, '', 'Spell \'Summon Cart Driver\' can only hit Min Dimwind');

-- Missing Aysa Cloudsinger stuff
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=53584 WHERE (`Entry`=54567 AND `DifficultyID`=0); -- Aysa Cloudsinger

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=54567 AND `MenuID`=13037);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(54567, 13037, 53584); -- Aysa Cloudsinger

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=13037;
INSERT INTO `conditions` VALUES (14, 13037, 0, 0, 0, 47, 0, 29419, 2 | 64, 0, '', 0, 0, 0, '', 'Aysa Cloudsinger - Show Gossip Menu 13037 if Quest 29419 is complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14672;
INSERT INTO `conditions` VALUES (14, 14672, 0, 0, 0, 47, 0, 29419, 2 | 64, 0, '', 1, 0, 0, '', 'Aysa Cloudsinger - Show Gossip Menu 14672 if Quest 29419 is not complete | rewarded');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (54130, 56503) AND `GroupId` IN (0, 1, 2, 3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54130, 0, 0, 'Look out! Its friendses are coming!', 14, 0, 100, 2, 0, 0, 56473, 0, 'Amberleaf Scamp to Player'),
(54130, 1, 0, 'Run away!', 14, 0, 100, 2, 0, 0, 56474, 0, 'Amberleaf Scamp to Player'),
(56503, 0, 0, 'Master Shang has trained you well. Thank you, friend!', 12, 0, 100, 2, 0, 0, 53265, 0, 'Min Dimwind to Player'),
(56503, 1, 0, 'I couldn\'t have fought them off alone. Now, if you\'ll excuse me, I should go find my cart.', 12, 0, 100, 1, 0, 0, 56452, 0, 'Min Dimwind to Player'),
(56503, 2, 0, 'Cart!', 14, 0, 100, 22, 0, 0, 56453, 0, 'Min Dimwind to Player'),
(56503, 3, 0, 'Hello, cart. Still upside-downed, I see.', 12, 0, 100, 1, 0, 0, 56454, 0, 'Min Dimwind to Player');

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 5825 AND `PhaseId` IN (629, 630);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5825, 629, 'See Min Dimwind captured at The Dawning Valley'),
(5825, 630, 'See Min Dimwind freed at The Dawning Valley');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=629 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 629, 0, 0, 0, 47, 0, 29419, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 629 if quest 29419 is not complete | rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=630 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 630, 0, 0, 0, 1, 0, 106205, 0, 0, 1, 0, 0, '', 'Apply Phase 630 if has no aura 106205'),
(26, 630, 0, 0, 0, 47, 0, 29419, 2 | 64, 0, 0, 0, 0, '', 'Apply Phase 630 if Quest 29419 is complete | rewarded');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=6958;
INSERT INTO `areatrigger_scripts` VALUES
(6958, 'at_min_dimwind_captured');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID`=252090;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(252090, NULL, NULL, NULL, 1, 1);

UPDATE `quest_template_locale` SET `QuestDescription`='Mi conductor salió corriendo tras los duendes, después de que nos atacaran. No creo que le hagan daño, pero lo necesito de vuelta para que me ayude a limpiar este desastre.$b$bLos siguió hacia los riscos del norte. Si vas en esa dirección, no tardarás en encontrarlo.', `VerifiedBuild`=53584 WHERE (`ID`=29419 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogDescription`='Recupera 6 suministros de entrenamiento de malandrines Hojámbar.', `QuestDescription`='Unos malandrines Hojámbar asaltaron mi carro y se llevaron casi todos los suministros de entrenamiento que traía. Siempre nos han dado problemas, pero nunca los había visto tan agresivos. No sé qué les ha pasado.$b$bTe lo ruego, ayúdame a recuperar mis suministros.', `VerifiedBuild`=53584 WHERE (`ID`=29424 AND `locale`='esES');

-- Serverside spells
DELETE FROM `serverside_spell` WHERE `Id`=109005 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(109005, 0, 0, 0, 0, 0x29800180, 0x420, 0x10484005, 0x10130200,	0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Min Dimwind Guardian Aura', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=109005 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(109005, 0, 0, 119, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell` WHERE `Id`=106231 AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(106231, 0, 0, 0, 0, 0x29800180, 0x420, 0x10484005, 0x10130200, 0x800080, 0x60008, 0x1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 0, 0, 0, -1, 0, 0, 0, 'Escort Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=106231 AND `EffectIndex`=0 AND `DifficultyID`=0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(106231, 0, 0, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54855, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Waypoint
SET @ENTRY := 56503;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Min Dimwind - The Missing Driver quest Path (Run)');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1398.465, 3547.49, 90.54716, NULL, 2151),
(@PATH, 1, 1379.332, 3566.672, 91.59061, NULL, 0),
(@PATH, 2, 1375.625, 3574.563, 92.0024, NULL, 0),
(@PATH, 3, 1374.854, 3583.098, 91.44274, NULL, 2452),
(@PATH, 4, 1350.017, 3582.917, 90.40493, NULL, 0),
(@PATH, 5, 1343.707, 3578.441, 91.90857, NULL, 0),
(@PATH, 6, 1335.036, 3568.839, 92.75056, NULL, 0),
(@PATH, 7, 1327.979, 3558.321, 95.62209, NULL, 0),
(@PATH, 8, 1323.058, 3544.156, 98.3161, NULL, 0),
(@PATH, 9, 1315.585, 3536.41, 99.88802, NULL, 0),
(@PATH, 10, 1306.488, 3529.573, 99.48459, NULL, 0),
(@PATH, 11, 1298.543, 3526.758, 98.71962, NULL, 2258);

SET @ENTRY := 56503;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Min Dimwind - The Missing Driver quest Path (Walk)');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1295.491, 3518.463, 100.586, NULL, 0),
(@PATH, 1, 1291.623, 3517.362, 100.1056, NULL, 0),
(@PATH, 2, 1288.08, 3518.94, 98.69194, NULL, 0),
(@PATH, 3, 1286.559, 3522.084, 97.63205, NULL, 0);
