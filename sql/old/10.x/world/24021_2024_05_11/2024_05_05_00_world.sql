-- Template
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_armsmaster_harlan' WHERE `entry` = 58632;
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=58632; -- Armsmaster Harlan

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=58998;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(58998, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113959'); -- 58998 (Scarlet Defender) - Heavy Armor

-- Instance
DELETE FROM `instance_template` WHERE `map` = 1001;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1001, 0, 'instance_scarlet_halls');

DELETE FROM `serverside_spell` WHERE `Id`=128930;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES 
(128930, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, '[DNT] Eject Spirits of Redemption', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=128930;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(128930, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Script Names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (111216, 111394, 112953, 113959, 111755, 111756, 128930);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(111216, 'spell_harlan_blades_of_light'),
(111394, 'spell_harlan_blades_of_light_selector'),
(112953, 'spell_harlan_leave_vehicle'),
(113959, 'spell_scarlet_defender_heavy_armor'),
(128930, 'spell_eject_spirits_of_redemption');

-- Spelltarget Pos.
DELETE FROM `spell_target_position` WHERE `ID` IN (111755, 111756);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(111755, 0, 1001, 1182.020, 447.325, 11.98933, NULL, 0),
(111756, 0, 1001, 1181.833, 440.649, 11.98763, NULL, 0);

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (111394));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 111394, 0, 0, 31, 0, 4, 0, 0, '', 0, 'Potential target of the spell is player'),
(13, 1, 111394, 0, 1, 31, 0, 3, 58998, 0, '', 0, 'Potential target of the spell is creature, entry is Scarlet Defender (58998)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (112955));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 112955, 0, 0, 31, 0, 3, 58632, 0, '', 0, 'Potential target of the spell is creature, entry is Armsmaster Harlan (58632)');

-- Creature text
DELETE FROM `creature_text` WHERE `CreatureID` = 58632;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(58632, 0, 0, 'Ah-hah! Another chance to test my might.', 14, 0, 100, 0, 0, 29428, 65557, 0, 'Armsmaster Harlan'), -- BroadcastTextID: 65557 - 170997
(58632, 1, 0, 'On your guard!', 14, 0, 100, 0, 0, 29426, 65559, 0, 'Armsmaster Harlan'), -- BroadcastTextID: 33752 - 33756 - 35825 - 65559 - 170996
(58632, 2, 0, '|TInterface\\Icons\\ability_warrior_battleshout.blp:20|tArmsmaster Harlan calls on two of his allies to join the fight!', 41, 0, 100, 0, 0, 0, 65526, 0, 'Armsmaster Harlan'),
(58632, 3, 0, '|TInterface\\Icons\\inv_weapon_halberd_05.blp:20|tArmsmaster Harlan casts |cFFFF0000|Hspell:111216|h[Blades of Light]|h|r!', 41, 0, 100, 0, 0, 0, 65527, 0, 'Armsmaster Harlan'),
(58632, 4, 0, 'Bested... by the likes of...', 14, 0, 100, 0, 0, 29427, 65560, 0, 'Armsmaster Harlan to Player'); -- BroadcastTextID: 65560 - 170995

-- NPC spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 58632;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(58632, 112955, 0, 0);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=211, `StaticFlags1`=268435456, `VerifiedBuild`=54205 WHERE (`Entry`=58632 AND `DifficultyID`=1); -- Armsmaster Harlan

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (66091,59372,59373,59150,59198,59240,59155,59209,59241,59293,58725,58726,65546,65547,58632,58756,58685,58676,58684,58683,59302,59299,59303,59309,59683,59191,59175,54030,60908,59163,64764,58898,65379,58727,58674,58701,58876));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(66091, 2, 5, 5, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Referee
(59372, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Scholar
(59373, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Pupil
(59150, 2, 2, 2, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Flameweaver Koegler
(59198, 2, 0, 0, 1186, 536870912, 0, 0, 0, 0, 0, 0, 0, 54205), -- Dragon Breath Target
(59240, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Hall Guardian
(59155, 2, 0, 0, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Book Case
(59209, 2, 0, 0, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Books
(59241, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Treasurer
(59293, 2, 0, 0, 1186, 805306624, 0, 33554432, 0, 0, 0, 0, 0, 54205), -- Scarlet Cannoneer
(58725, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Cannons
(58726, 2, 0, 0, 1186, 805306624, 0, 33554432, 0, 0, 0, 0, 0, 54205), -- Scarlet Cannon
(65546, 2, 0, 0, 996, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Sekrit
(65547, 2, 0, 0, 996, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Sekret
(58632, 2, 2, 2, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Armsmaster Harlan
(58756, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Evoker
(58685, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Evangelist
(58676, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Defender
(58684, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Scourge Hewer
(58683, 2, 0, 0, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Scarlet Myrmidon
(59302, 2, 0, 0, 1186, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 54205), -- Sergeant Verdone
(59299, 2, 0, 0, 1186, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 54205), -- Scarlet Guardian
(59303, 2, 2, 2, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Houndmaster Braun
(59309, 2, 0, 0, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Obedient Hound
(59683, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Exploding Shot Stalker
(59191, 2, 1, 1, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Commander Lindon
(59175, 2, 0, 0, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Master Archer
(54030, 2, 0, 0, 181, 536870912, 0, 0, 0, 0, 0, 0, 0, 54205), -- Invisible Stalker
(60908, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Archery Target Base
(59163, 2, 0, 0, 1186, 0, 0, 33554432, 0, 0, 0, 0, 0, 54205), -- Reinforced Archery Target
(64764, 2, 1, 1, 1186, 268435456, 0, 0, 0, 0, 0, 0, 0, 54205), -- Hooded Crusader
(58898, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Vigilant Watchman
(65379, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Bucket of Meaty Dog Food
(58727, 2, 0, 0, 1186, 536871168, 0, 0, 0, 0, 0, 0, 0, 54205), -- Chained Dog Target
(58674, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Angry Hound
(58701, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205), -- Stake
(58876, 2, 0, 0, 1186, 0, 0, 0, 0, 0, 0, 0, 0, 54205); -- Starving Hound

-- Path for Armsmaster Harlan
SET @ENTRY := 58632;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Armsmaster Harlan - Blades of Light Path Left');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1210.14, 443.6163, 0.9878225, NULL, 0),
(@PATH, 1, 1205.706, 454.0305, 0.9878197, NULL, 0),
(@PATH, 2, 1208.05, 450.271, 0.9878197, NULL, 0),
(@PATH, 3, 1207.03, 452.5631, 1.087024, NULL, 0),
(@PATH, 4, 1206.861, 444.0269, 0.9878179, NULL, 0),
(@PATH, 5, 1193.708, 443.4705, 2.058222, NULL, 0),
(@PATH, 6, 1205.986, 431.2205, 2.101642, NULL, 0),
(@PATH, 7, 1214.609, 433.9097, 4.82716, NULL, 0),
(@PATH, 8, 1221.668, 443.4757, 7.08157, NULL, 0),
(@PATH, 9, 1215, 460.9097, 7.081536, NULL, 0),
(@PATH, 10, 1196.886, 461.2072, 9.18631, NULL, 0),
(@PATH, 11, 1186.648, 447.3125, 12.17532, NULL, 0),
(@PATH, 12, 1177.415, 443.8142, 13.98537, NULL, 0),
(@PATH, 13, 1186.889, 440.776, 12.09889, NULL, 0),
(@PATH, 14, 1197.804, 426.4445, 9.00577, NULL, 0),
(@PATH, 15, 1207.034, 424.562, 7.081643, NULL, 0),
(@PATH, 16, 1222.688, 439.9175, 7.081566, NULL, 0),
(@PATH, 17, 1219.642, 447.5649, 7.081594, NULL, 0),
(@PATH, 18, 1211.156, 455.7188, 3.721778, NULL, 0),
(@PATH, 19, 1200.948, 444.0017, 2.015597, NULL, 0);

SET @ENTRY := 58632;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Armsmaster Harlan - Blades of Light Path Right');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1201.622, 447.4277, 0.9878227, NULL, 0),
(@PATH, 1, 1198.307, 446.7369, 0.9878202, NULL, 0),
(@PATH, 2, 1200.896, 440.3603, 1.013452, NULL, 0),
(@PATH, 3, 1202.697, 432.1492, 1.07209, NULL, 0),
(@PATH, 4, 1201.674, 436.79, 0.9878197, NULL, 0),
(@PATH, 5, 1206.789, 443.8733, 0.9878235, NULL, 0),
(@PATH, 6, 1193.938, 443.8958, 2.053352, NULL, 0),
(@PATH, 7, 1205.161, 456.7049, 2.083267, NULL, 0),
(@PATH, 8, 1212.862, 454.9352, 4.150019, NULL, 0),
(@PATH, 9, 1224.649, 437.8368, 7.109349, NULL, 0),
(@PATH, 10, 1217.377, 427.7413, 7.081546, NULL, 0),
(@PATH, 11, 1199.389, 425.0538, 8.667348, NULL, 0),
(@PATH, 12, 1186.738, 439.9496, 12.10881, NULL, 0),
(@PATH, 13, 1177.432, 444.1267, 13.98004, NULL, 0),
(@PATH, 14, 1187.255, 447.8455, 12.17532, NULL, 0),
(@PATH, 15, 1191.906, 457.6354, 10.33337, NULL, 0),
(@PATH, 16, 1208.694, 463.2535, 7.081545, NULL, 0),
(@PATH, 17, 1219.986, 457.5608, 7.081551, NULL, 0),
(@PATH, 18, 1219.328, 441.2535, 7.081581, NULL, 0),
(@PATH, 19, 1205.826, 429.7535, 2.155848, NULL, 0),
(@PATH, 20, 1198.332, 440.2205, 1.98782, NULL, 0),
(@PATH, 21, 1200.79, 443.9236, 1.98782, NULL, 0);
