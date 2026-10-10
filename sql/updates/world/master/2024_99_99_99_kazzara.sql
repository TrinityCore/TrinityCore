-- Creature
UPDATE `creature_addon` SET `auras`="" WHERE `guid`=9003979;
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=250, `unit_flags`=33554432, `unit_flags2`=34816, `unit_flags3`=524288, `ScriptName`='npc_dread_rift' WHERE `entry`=203832; -- Dread Rift
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=250, `unit_flags`=33554944, `unit_flags2`=2097152, `unit_flags3`=27787264, `ScriptName`='npc_ray_of_anguish' WHERE `entry`=202167; -- Ray of Anguish

DELETE FROM `creature_template_addon` WHERE `entry` = 202167;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(202167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '402219'); -- 202167 (Ray of Anguish) - Ray of Anguish

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (28185, 28466, 28022, 28429, 28035);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(28466, 0, 32636, 0, 2, 0, 65212, 65213, 0, -1, 0, 0, NULL, 0, 600000, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_kazzara_dread_rift', 49679), -- Spell: 407046 (Dread Rift)
(28185, 0, 32079, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 600, 0, 300, 300, 0, 0, 0, 0, 0, 0, 'at_kazzara_wings_of_extinction', 49679), -- Spell: 403326 (Wings of Extinction)
(28022, 0, 31941, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 4, 0.75, 0.75, 10, 10, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_kazzara_ray_of_anguish', 49679), -- Spell: 402219 (Ray of Anguish)
(28429, 0, 32313, 0, 16, 0, 0, 0, 0, -1, 0, 0, NULL, 6138, 5000, 4, 3, 3, 10, 10, 0.300000011920928955, 0.300000011920928955, 0, 0, '', 49679), -- Spell: 406303 (Ray of Anguish)
(28035, 0, 32577, 0, 2, 0, 64997, 0, 0, -1, 0, 548, NULL, 0, 7000, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_kazzara_molten_scar', 49679); -- Spell: 402421 (Molten Scar)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (32079, 32636, 31941, 32313, 31951));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(32079, 0, 0, 49679),
(32636, 0, 0, 49679),
(31941, 0, 0, 49679),
(32313, 0, 0, 49679),
(31951, 0, 0, 50000);

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`IN (402538, 402547, 404744, 404743, 406525, 406517, 407196, 402260, 401328, 401331, 401335);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(402538, 'spell_kazzara_energize'),
(402547, 'spell_kazzara_hellbeam_consume_energy'),
(404744, 'spell_kazzara_terror_claws'),
(404743, 'spell_kazzara_terror_claws_periodic'),
(406525, 'spell_kazzara_dread_rift'),
(406517, 'spell_kazzara_dread_rift_player_select'),
(407196, 'spell_kazzara_dread_rifts'),
(402260, 'spell_kazzara_ray_of_anguish_trigger'),
(401328, 'spell_kazzara_hellsteel_carnage'),
(401331, 'spell_kazzara_hellsteel_carnage'),
(401335, 'spell_kazzara_hellsteel_carnage');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=407068;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 407068, 0, 0, 51, 0, 5, 203832, 0, 0, 0, 0, '', 'Spell \'Rays of Anguish\' can only hit Dread Rifts');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (201261, 202167);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(201261, 0, 0, 'Your entrails will shine my armor!', 14, 0, 100, 0, 0, 223200, 238513, 0, 'Kazzara, the Hellforged'),
(201261, 1, 0, 'Your existence ends.', 14, 0, 50, 0, 0, 223211, 238533, 0, 'Kazzara, the Hellforged'),
(201261, 1, 1, 'Cleansing flame!', 14, 0, 50, 0, 0, 223210, 238532, 0, 'Kazzara, the Hellforged'),
(201261, 2, 0, 'My beautiful armor!', 14, 0, 100, 0, 0, 223205, 238519, 0, 'Kazzara, the Hellforged'),
(201261, 3, 0, 'Anguish and sorrow.', 14, 0, 100, 0, 0, 223215, 238537, 0, 'Kazzara, the Hellforged'),
(201261, 4, 0, 'Torment!', 14, 0, 100, 0, 0, 223208, 238528, 0, 'Kazzara, the Hellforged to Player'),
(201261, 5, 0, '|TInterface\\ICONS\\Ability_Warlock_ShadowFlame.blp:20|t %s begins casting |cFFFF0000|Hspell:400430|h[Hellbeam]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Kazzara, the Hellforged to Player'),
(201261, 6, 0, 'Surrender to terror!', 14, 0, 100, 0, 0, 223212, 238534, 0, 'Kazzara, the Hellforged to Player'),
(201261, 7, 0, 'I will peel your flesh from bone!', 14, 0, 100, 0, 0, 223206, 238520, 0, 'Kazzara, the Hellforged'),
(201261, 8, 0, 'My flesh splits, but your agony will be greater!', 14, 0, 100, 0, 0, 223207, 238523, 0, 'Kazzara, the Hellforged'),
(201261, 9, 0, 'Such sweet suffering.', 14, 0, 50, 0, 0, 223201, 238515, 0, 'Kazzara, the Hellforged to Player'),
(201261, 9, 1, 'Your cries are delicious.', 14, 0, 50, 0, 0, 223202, 238516, 0, 'Kazzara, the Hellforged to Player'),
(201261, 10, 0, 'I... am... broken?', 14, 0, 100, 0, 0, 223204, 238518, 0, 'Kazzara, the Hellforged to Player'),
(202167, 0, 0, '|TInterface\\ICONS\\Ability_Mage_FireStarter.blp:20|t Hunted by a |cFFFF0000|Hspell:402253|h[Ray of Anguish]|h|r!', 42, 0, 100, 0, 0, 0, 0, 0, 'Ray of Anguish to Player');
