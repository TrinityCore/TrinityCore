-- 
SET @ATID := 66;
SET @ATSPAWNID := 68;
SET @ATCP := 54;

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATSPAWNID+0, @ATCP+0, 1, 1492, '1,2,8,23', 7380.5766, 7289.9389, 43.8447, 2.8720, 1, 0, 0, NULL, 'at_ymiron_the_fallen_king_activation', 'Maw of Souls - Ymiron Activation Trigger', 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATCP+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 35, 35, 5, 5, 0, 0, 0, 0, '', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0);

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (35642,96759,97099,98246,98363,98693,98761,98989,99033,99307,99800,99801,99803,100188,100359,100360,100839,101502,101504,101814,102306,114288,114289));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(35642, 23, 0, 0, 391, 9, 3, 1, 43668, 0, 0, 52129), -- Jeeves
(96759, 23, 2, 2, 629, 6, 249.600006103515625, 1, 115330, 2097260, 128, 52129), -- Helya
(97099, 23, 0, 0, 1155, 6, 1, 1, 97598, 1024, 0, 52129), -- Swirling Pool
(98246, 23, 2, 2, 629, 6, 0.899999976158142089, 1, 117106, 2097224, 128, 52129), -- Risen Warrior
(98363, 23, 1, 1, 629, 6, 4, 1, 115313, 104, 128, 52129), -- Grasping Tentacle
(98693, 23, 1, 1, 629, 6, 1.299999952316284179, 1, 115320, 2097224, 128, 52129), -- Shackled Servitor
(98761, 23, 0, 0, 629, 6, 0.5, 1, 115333, 2097224, 128, 52129), -- Soul Fragment
(98989, 23, 0, 0, 1155, 6, 1, 1, 99495, 1024, 0, 52129), -- Cosmic Scythe
(99033, 23, 1, 1, 629, 6, 5.5, 1, 115321, 270532680, 0, 52129), -- Helarjar Mistcaller
(99307, 23, 1, 1, 629, 6, 16, 1, 115338, 270532712, 0, 52129), -- Skjal
(99800, 23, 2, 2, 1155, 6, 1, 1, 100308, 0, 128, 52129), -- Grasping Tentacle
(99801, 23, 1, 1, 629, 6, 4, 1, 115322, 2097256, 128, 52129), -- Destructor Tentacle
(99803, 23, 2, 2, 1155, 6, 1, 1, 100311, 0, 128, 52129), -- Destructor Tentacle
(100188, 23, 1, 1, 1155, 6, 1, 1, 100697, 0, 128, 52129), -- Piercing Tentacle
(100359, 23, 2, 2, 1155, 6, 1, 1, 100869, 0, 128, 52129), -- Grasping Tentacle
(100360, 23, 1, 1, 629, 6, 4, 1, 115334, 104, 128, 52129), -- Grasping Tentacle
(100839, 23, 0, 0, 1155, 6, 1, 1, 101356, 1024, 0, 52129), -- Cosmic Scythe
(101502, 23, 0, 0, 1155, 6, 1, 1, 102076, 0, 0, 52129), -- Helya's Tentacle
(101504, 23, 2, 2, 1155, 6, 1, 1, 102078, 0, 0, 52129), -- Grasping Tentacle
(101814, 23, 2, 2, 1155, 6, 1, 1, 102424, 0, 0, 52129), -- Grasping Tentacle
(102306, 23, 0, 0, 1155, 6, 1, 1, 103079, 1024, 0, 52129), -- Swirling Pool
(114288, 23, 0, 0, 629, 6, 1.10000002384185791, 0.065200001001358032, 117625, 2097224, 0, 52129), -- Skeletal Warrior
(114289, 23, 0, 0, 629, 6, 0.75, 1, 117628, 270532680, 0, 52129); -- Skeletal Sorcerer

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52129 WHERE (`DifficultyID`=23 AND `Entry` IN (32641,32642,97208,98291,101013,102108,102325,102326,102327,102742,102769,102830,102894,102896,103115,104906,111374,120652));
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=115314, `VerifiedBuild`=52129 WHERE (`Entry`=96754 AND `DifficultyID`=23); -- Harbaron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `ManaModifier`=0.000350554008036851, `CreatureDifficultyID`=115318, `VerifiedBuild`=52129 WHERE (`Entry`=96756 AND `DifficultyID`=23); -- Ymiron, the Fallen King
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115311, `VerifiedBuild`=52129 WHERE (`Entry`=97043 AND `DifficultyID`=23); -- Seacursed Slaver
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115312, `VerifiedBuild`=52129 WHERE (`Entry`=97097 AND `DifficultyID`=23); -- Helarjar Champion
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115331, `TypeFlags`=2097224, `VerifiedBuild`=52129 WHERE (`Entry`=97119 AND `DifficultyID`=23); -- Shroud Hound
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115325, `TypeFlags`=2097224, `VerifiedBuild`=52129 WHERE (`Entry`=97163 AND `DifficultyID`=23); -- Cursed Falke
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115324, `VerifiedBuild`=52129 WHERE (`Entry`=97182 AND `DifficultyID`=23); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115327, `VerifiedBuild`=52129 WHERE (`Entry`=97185 AND `DifficultyID`=23); -- The Grimewalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=115332, `VerifiedBuild`=52129 WHERE (`Entry`=97200 AND `DifficultyID`=23); -- Seacursed Soulkeeper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115336, `VerifiedBuild`=52129 WHERE (`Entry`=97365 AND `DifficultyID`=23); -- Seacursed Mistmender
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115317, `VerifiedBuild`=52129 WHERE (`Entry`=98919 AND `DifficultyID`=23); -- Seacursed Swiftblade
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115329, `VerifiedBuild`=52129 WHERE (`Entry`=98973 AND `DifficultyID`=23); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115316, `VerifiedBuild`=52129 WHERE (`Entry`=99188 AND `DifficultyID`=23); -- Waterlogged Soul Guard
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115335, `VerifiedBuild`=52129 WHERE (`Entry`=102104 AND `DifficultyID`=23); -- Enslaved Shieldmaiden
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=115315, `VerifiedBuild`=52129 WHERE (`Entry`=102375 AND `DifficultyID`=23); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=52129 WHERE (`Entry`=111221 AND `DifficultyID`=23); -- Xal'atath
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=52129 WHERE (`Entry`=111833 AND `DifficultyID`=23); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=118183, `VerifiedBuild`=52129 WHERE (`Entry`=114712 AND `DifficultyID`=23); -- Runecarver Slave
UPDATE `creature_template_difficulty` SET `ContentTuningID`=877, `VerifiedBuild`=52129 WHERE (`Entry`=188142 AND `DifficultyID`=23); -- Motion Sick Peon's Soul

UPDATE `creature_model_info` SET `VerifiedBuild`=52129 WHERE `DisplayID` IN (30076, 66346, 66348, 66681, 66345, 66238, 66121, 70528, 66688, 64208, 66852, 26725, 66184, 106378, 67556, 30710, 70529, 66102, 66181, 67179, 66183, 66103, 65823, 64467, 64200, 28120, 28118, 65214, 67001, 65079, 21342, 66119, 25801, 27824, 66091, 11686, 16925, 66090, 25630);
UPDATE `creature_model_info` SET `BoundingRadius`=10.46424579620361328, `VerifiedBuild`=52129 WHERE `DisplayID`=65778;
UPDATE `creature_model_info` SET `BoundingRadius`=52.32122802734375, `VerifiedBuild`=52129 WHERE `DisplayID`=66680;
UPDATE `creature_model_info` SET `BoundingRadius`=13.0803070068359375, `VerifiedBuild`=52129 WHERE `DisplayID`=66618;
UPDATE `creature_model_info` SET `BoundingRadius`=31.39273834228515625, `VerifiedBuild`=52129 WHERE `DisplayID`=67211;

DELETE FROM `areatrigger_create_properties_orbit` WHERE (`AreaTriggerCreatePropertiesId`=5838 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties_orbit` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `StartDelay`, `CircleRadius`, `BlendFromRadius`, `InitialAngle`, `ZOffset`, `CounterClockwise`, `CanLoop`, `VerifiedBuild`) VALUES
(5838, 0, 0, 0, 0, 0, 0, 0, 1, 52129); -- Spell: 193465 (Bane)

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (5838));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(5838, 0, 10407, 0, 0, 0, 0, 0, 0, -1, 0, 26, 11863, 21000, 0, 2, 2, 0, 0, 0, 0, 0, 0, 52129); -- Spell: 193465 (Bane)

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_ymiron_the_fallen_king_bane' WHERE `Id`=5838 AND `IsCustom`=0;

UPDATE `areatrigger_template` SET `Flags`=0, `VerifiedBuild`=52129 WHERE (`Id`=10407 AND `IsCustom`=0);

-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

DELETE FROM `instance_template` WHERE `map`=1492;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1492, 0, 'instance_maw_of_souls');

UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_ymiron_the_fallen_king' WHERE `entry`=96756;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_risen_warrior' WHERE `entry`=98246;
UPDATE `creature_template_addon` SET `auras`='342788' WHERE `entry`=96756; -- remove kneeling from template
UPDATE `creature` SET `equipment_id`=-1 WHERE `guid`=650507; -- add weapon to ymiron

UPDATE `creature_template` SET `faction`=16, `speed_run`=0.857142865657806396, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=98246; -- Risen Warrior

DELETE FROM `creature_template_addon` WHERE `entry`=98246;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(98246, '123978');

SET @PATHID := 9675600;
DELETE FROM `waypoint_path` WHERE `PathId` BETWEEN @PATHID+0 AND @PATHID+1;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID+0, 0, 0, NULL, 'Ymiron - Intro Path towards Runecarver Slaves'),
(@PATHID+1, 0, 0, NULL, 'Ymiron - Intro Path away from Runecarver Slaves');

DELETE FROM `waypoint_path_node` WHERE `PathId` BETWEEN @PATHID+0 AND @PATHID+1;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID+0, 0, 7400.461, 7288.4614, 44.063484, NULL, 0),
(@PATHID+0, 1, 7398.961, 7291.4614, 44.063484, NULL, 0),
(@PATHID+0, 2, 7394.7075, 7295.432, 43.7841, NULL, 0),
(@PATHID+1, 0, 7397.9185, 7286.777, 43.79471, NULL, 0),
(@PATHID+1, 1, 7398.374, 7277.1206, 43.792637, 5.724679946899414062, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (243029));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 0x1|0x2|0x4, 243029, 0, 0, 51, 0, 5, 114712, 0, '', 0, 'Potential target of the spell is creature, entry is Runecarver Slave (114712)');

DELETE FROM `serverside_spell` WHERE `Id`=193510;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(193510, 0, 0, 0, 0, 0x100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, -1, 0, 0, 0, 'Arise, Fallen', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=193510;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(193510, 0, 0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN(167922, 193460, 243029, 193566);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(167922, 'spell_ymiron_the_fallen_king_power_periodic'),
(193460, 'spell_ymiron_the_fallen_king_bane_periodic'),
(243029, 'spell_ymiron_the_fallen_king_soul_siphon'),
(193566, 'spell_ymiron_the_fallen_king_arise_fallen_selector');

DELETE FROM `creature_text` WHERE `CreatureID`=96756;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96756, 0, 0, 'Your souls will drift for eternity in the tides of the underworld!', 14, 0, 100, 0, 0, 54404, 102193, 0, 'Ymiron, the Fallen King to Player'),
(96756, 1, 0, 'Another drop in the sea of souls!', 14, 0, 100, 66, 0, 54367, 102185, 0, 'Ymiron, the Fallen King to Player'),
(96756, 2, 0, 'Mortals... I fell to your wretched kind once before. It WILL NOT happen again!', 14, 0, 100, 0, 0, 54403, 102191, 0, 'Ymiron, the Fallen King to Player'),
(96756, 3, 0, 'FLEE, COWARDS!', 14, 0, 100, 0, 0, 54360, 102175, 0, 'Ymiron, the Fallen King'),
(96756, 3, 1, 'COWER BEFORE ME!', 14, 0, 100, 0, 0, 54359, 102174, 0, 'Ymiron, the Fallen King'),
(96756, 3, 2, 'CRAVEN MAGGOTS!', 14, 0, 100, 0, 0, 54361, 102176, 0, 'Ymiron, the Fallen King'),
(96756, 4, 0, 'Know the bitter chill of death as I have!', 14, 0, 100, 0, 0, 54362, 102177, 0, 'Ymiron, the Fallen King'),
(96756, 4, 1, 'The winds of the frozen north still howl in these veins!', 14, 0, 100, 0, 0, 54364, 102178, 0, 'Ymiron, the Fallen King'),
(96756, 5, 0, 'The shadows of the underworld bend to me!', 14, 0, 100, 0, 0, 54357, 102171, 0, 'Ymiron, the Fallen King'),
(96756, 6, 0, 'The shadows of Helheim cut deeper than steel!', 14, 0, 100, 0, 0, 54358, 102173, 0, 'Ymiron, the Fallen King'),
(96756, 7, 0, 'Not... again... HARBARON! CAST THEIR SOULS INTO THE TIDES!', 14, 0, 100, 0, 0, 54366, 102182, 0, 'Ymiron, the Fallen King to Player');
