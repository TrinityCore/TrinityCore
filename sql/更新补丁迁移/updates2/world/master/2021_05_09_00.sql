INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (99846, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (171576, '0', '99846', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100714, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (172942, '0', '100714', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);


INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100708, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (173065, '0', '100708', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100713, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (173324, '0', '100713', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

DELETE FROM `creature_template` WHERE `entry`=160737;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES (160737, 0, 0, 0, 0, 0, 'Combat Dummy', 'Combat Dummy', '', NULL, NULL, 0, 1, 3, 0, 0, 0, 2643, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 1, 33554688, 67110912, 16, 0, 0, 0, 9, 0, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 'npc_combat_dummy', 36949);

INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100710, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (173618, '0', '100710', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100928, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (173851, '0', '100928', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

INSERT INTO `creature_model_info` (DisplayID, BoundingRadius, CombatReach, DisplayID_Other_Gender) VALUES (100929, '1', '1', '0') ON DUPLICATE KEY UPDATE BoundingRadius = VALUES(BoundingRadius), CombatReach = VALUES(CombatReach), DisplayID_Other_Gender = VALUES(DisplayID_Other_Gender);

INSERT INTO `creature_template_model` (CreatureID, Idx, CreatureDisplayID, DisplayScale, Probability) VALUES (173988, '0', '100929', '1', '1') ON DUPLICATE KEY UPDATE Idx = VALUES(Idx), CreatureDisplayID = VALUES(CreatureDisplayID), DisplayScale = VALUES(DisplayScale), Probability = VALUES(Probability);

DELETE FROM `areatrigger_template` WHERE `Id` IN (7020, 20457, 21666, 21633, 21428, 21449, 21646);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(7020, 0, 1, 0, 3, 3, 0, 0, 0, 0, 38134),
(20457, 4, 1, 0, 1, 1, 7, 7, 3, 3, 38134),
(21666, 0, 1, 0, 3, 3, 0, 0, 0, 0, 38134),
(21633, 0, 1, 4, 5, 5, 0, 0, 0, 0, 38134),
(21428, 0, 1, 0, 9, 9, 0, 0, 0, 0, 38134),
(21449, 0, 1, 0, 3, 3, 0, 0, 0, 0, 38134),
(21646, 0, 1, 0, 8, 8, 0, 0, 0, 0, 38134);



UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `Type`=0 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17536;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=19244;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17903;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16587;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16587;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16587;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16587;
UPDATE `areatrigger_template` SET `Data0`=1, `Data1`=1 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Data0`=1, `Data1`=1 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Data0`=1, `Data1`=1 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `Data0`=12, `Data1`=12, `VerifiedBuild`=38134 WHERE `Id`=19401;
UPDATE `areatrigger_template` SET `Data0`=12, `Data1`=12, `VerifiedBuild`=38134 WHERE `Id`=19401;
UPDATE `areatrigger_template` SET `Data0`=12, `Data1`=12, `VerifiedBuild`=38134 WHERE `Id`=19401;
UPDATE `areatrigger_template` SET `Data0`=12, `Data1`=12, `VerifiedBuild`=38134 WHERE `Id`=19401;

DELETE FROM `areatrigger_template_polygon_vertices` WHERE (`AreaTriggerId`=19244 AND `Idx` IN (3,2,1,0));
INSERT INTO `areatrigger_template_polygon_vertices` (`AreaTriggerId`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(19244, 3, 60, 62, NULL, NULL, 38134),
(19244, 2, 62, -62, NULL, NULL, 38134),
(19244, 1, 0, -2, NULL, NULL, 38134),
(19244, 0, 0, 2, NULL, NULL, 38134);


DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=17903) OR (`SpellMiscId`=16606 AND `AreaTriggerId`=0) OR (`SpellMiscId`=16071 AND `AreaTriggerId`=20457) OR (`SpellMiscId`=17430 AND `AreaTriggerId`=21666) OR (`SpellMiscId`=17391 AND `AreaTriggerId`=21633) OR (`SpellMiscId`=17121 AND `AreaTriggerId`=21428) OR (`SpellMiscId`=17165 AND `AreaTriggerId`=21449) OR (`SpellMiscId`=17406 AND `AreaTriggerId`=21646);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(16606, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 38134), -- SpellId : 295833
(16071, 20457, 0, 0, 0, 9583, 0, 0, 0, 3171, 40000, 38134), -- SpellId : 290516
(17430, 21666, 0, 0, 0, 0, 0, 0, 82, 0, 24000, 38134), -- SpellId : 303611
(17391, 21633, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 303082
(17121, 21428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 300926
(17165, 21449, 0, 0, 0, 0, 0, 0, 351, 0, 16000, 38134), -- SpellId : 301154
(17406, 21646, 0, 0, 0, 0, 0, 0, 345, 0, 30000, 38134); -- SpellId : 303319



UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12892 AND `AreaTriggerId`=17536); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14560 AND `AreaTriggerId`=19244); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11895 AND `AreaTriggerId`=16587); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11895 AND `AreaTriggerId`=16587); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11895 AND `AreaTriggerId`=16587); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=11895 AND `AreaTriggerId`=16587); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2500 WHERE (`SpellMiscId`=16868 AND `AreaTriggerId`=21220); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14744 AND `AreaTriggerId`=19401); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14744 AND `AreaTriggerId`=19401); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14744 AND `AreaTriggerId`=19401); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14744 AND `AreaTriggerId`=19401); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0

UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=11322 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=11322 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=11481 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=11481 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=11320 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (20265, 28072, 28071, 28070, 28069, 27715, 25478, 25477, 28237, 28240, 28007, 28006, 27178, 21085, 27488, 19661, 28005, 28004, 28003, 29838, 28617, 28610, 28028, 28026, 20353, 28232, 28231, 28230, 21086, 21604, 20267, 27771, 27770, 27173, 27464, 20355, 29839, 27167, 19662);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(20265, 0, 82, 1, 0, 38134),
(28072, 12150, 0, 1, 0, 38134),
(28071, 6900, 0, 0, 0, 38134),
(28070, 1800, 0, 1, 0, 38134),
(28069, 0, 0, 0, 0, 38134),
(27715, 0, 99, 0, 0, 38134),
(25478, 5063, 0, 0, 0, 38134),
(25477, 0, 0, 0, 0, 38134),
(28237, 3000, 0, 1, 0, 38134),
(28240, 0, 0, 0, 0, 38134),
(28007, 3350, 0, 0, 0, 38134),
(28006, 0, 0, 0, 0, 38134),
(27178, 0, 1251, 0, 0, 38134),
(21085, 0, 82, 0, 0, 38134),
(27488, 0, 99, 0, 0, 38134),
(19661, 0, 84, 0, 0, 38134),
(28005, 9500, 0, 0, 0, 38134),
(28004, 5700, 0, 0, 0, 38134),
(28003, 0, 0, 0, 0, 38134),
(29838, 0, 1108, 0, 0, 38134),
(28617, 0, 0, 0, 0, 38134),
(28610, 0, 0, 0, 0, 38134),
(28028, 3750, 0, 0, 0, 38134),
(28026, 0, 0, 0, 0, 38134),
(20353, 0, 82, 1, 0, 38134),
(28232, 10200, 0, 0, 0, 38134),
(28231, 6900, 0, 0, 0, 38134),
(28230, 0, 0, 0, 0, 38134),
(21086, 0, 82, 0, 0, 38134),
(21604, 0, 82, 1, 0, 38134),
(20267, 0, 82, 1, 0, 38134),
(27771, 4100, 0, 0, 0, 38134),
(27770, 0, 0, 0, 0, 38134),
(27173, 0, 1251, 0, 0, 38134),
(27464, 0, 99, 0, 0, 38134),
(20355, 0, 82, 1, 0, 38134),
(29839, 0, 1108, 0, 0, 38134),
(27167, 0, 1251, 0, 0, 38134),
(19662, 0, 84, 0, 0, 38134);

UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=27624;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=27624;

UPDATE `conversation_template` SET `LastLineEndTime`=7477, `VerifiedBuild`=38134 WHERE `Id`=11481;
UPDATE `conversation_template` SET `FirstLineID`=27178, `LastLineEndTime`=9765, `VerifiedBuild`=38134 WHERE `Id`=11322;
UPDATE `conversation_template` SET `FirstLineID`=27178, `LastLineEndTime`=9765, `VerifiedBuild`=38134 WHERE `Id`=11322;
UPDATE `conversation_template` SET `FirstLineID`=27167, `LastLineEndTime`=7475, `VerifiedBuild`=38134 WHERE `Id`=11320;
UPDATE `conversation_template` SET `LastLineEndTime`=7477, `VerifiedBuild`=38134 WHERE `Id`=11481;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (294195 /*Fardo de dinamita*/, 280619 /*Cofre reforzado con hierro antiguo*/, 328429 /*Depósito de jalea grande*/, 358375 /*Parche de nieve*/, 326419 /*Cofre arcano*/, 330173 /*Santuario funerario ankoano*/, 329895 /*Caída lenta*/, 326407 /*Cofre arcano*/, 327542 /*Bastón destrozado*/, 327514 /*Pilón de recuerdos*/, 329614 /*Runa del vacío*/, 326015 /*Ícono de Azshara*/, 326595 /*Diario de Arylina*/, 320935 /*Santuario arcaico*/, 325853 /*Estantería vacía*/, 329740 /*Cuaderno altonato antiguo*/, 326404 /*Cofre arcano*/, 326403 /*Cofre arcano*/, 329738 /*Diario altonato antiguo*/, 326216 /*Tridente de azerita*/, 322021 /*Aguas infestadas de anguilas*/, 330194 /*Cristal prismático*/, 325759 /*Almeja insuflada con maná*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(294195, 0, 262145, 0, 0), -- Fardo de dinamita
(280619, 0, 0, 2437, 0), -- Cofre reforzado con hierro antiguo
(328429, 0, 286720, 12713, 0), -- Depósito de jalea grande
(358375, 94, 0, 0, 0), -- Parche de nieve
(326419, 0, 2121728, 2437, 0), -- Cofre arcano
(330173, 0, 262144, 0, 0), -- Santuario funerario ankoano
(329895, 0, 0, 0, 9192), -- Caída lenta
(326407, 0, 2121728, 2437, 0), -- Cofre arcano
(327542, 0, 4, 0, 0), -- Bastón destrozado
(327514, 0, 262144, 0, 0), -- Pilón de recuerdos
(329614, 0, 0, 0, 16736), -- Runa del vacío
(326015, 0, 262148, 0, 0), -- Ícono de Azshara
(326595, 0, 2113540, 0, 0), -- Diario de Arylina
(320935, 0, 1, 0, 0), -- Santuario arcaico
(325853, 0, 4, 0, 0), -- Estantería vacía
(329740, 0, 4, 0, 0), -- Cuaderno altonato antiguo
(326404, 0, 2121728, 2437, 0), -- Cofre arcano
(326403, 0, 2121728, 2437, 0), -- Cofre arcano
(329738, 0, 4, 0, 0), -- Diario altonato antiguo
(326216, 0, 4, 0, 0), -- Tridente de azerita
(322021, 0, 32, 0, 0), -- Aguas infestadas de anguilas
(330194, 0, 0, 569, 0), -- Cristal prismático
(325759, 0, 2113540, 0, 0); -- Almeja insuflada con maná

UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=286952; -- Cofre cubierto de liquen
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=281887; -- Poción apestosa
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=281888; -- Olla de baba viscosa
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291258; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2784 WHERE `entry`=297071; -- Bolsa de monedas pequeña
UPDATE `gameobject_template_addon` SET `WorldEffectID`=520 WHERE `entry`=291078; -- Frasco mareaférrea
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291266; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=11129 WHERE `entry`=280586; -- Huevo quebrado
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298909; -- Cuero reforzado
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298914; -- Colgante de caparazones arcoíris
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=6714 WHERE `entry`=291043; -- Círculo ritual
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=284448; -- Cofre de erudito oculto
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291254; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `faction`=16 WHERE `entry`=187376; -- NPC Fishing Bobber
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=299009; -- Planta nerviosa
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291255; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=289538; -- Mareaqua hedionda
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=11674 WHERE `entry`=325418; -- Caldero hirviente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=289537; -- Mareaqua hedionda
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=16736 WHERE `entry`=288522; -- Relámpago del Vacío
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=289536; -- Incensario de ritual
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=9882 WHERE `entry`=292787; -- Bridge Visual
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298910; -- Plantilla de paso ligero
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298915; -- Dosis de capacidad
UPDATE `gameobject_template_addon` SET `flags`=278528, `WorldEffectID`=2437 WHERE `entry`=291244; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298911; -- Blindaje de acero plegado
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=299008; -- Magnetita cargada
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10427 WHERE `entry`=298912; -- Púas con resortes
UPDATE `gameobject_template_addon` SET `flags`=8192, `WorldEffectID`=2437 WHERE `entry`=326416; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326410; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326406; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326405; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326408; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=325420; -- Montón de pergaminos
UPDATE `gameobject_template_addon` SET `WorldEffectID`=12249 WHERE `entry`=325869; -- Tonel vacío
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=327221; -- Tonel de bayalgas
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=326239; -- Huevo de las profundidades
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=322791; -- Bayalga
UPDATE `gameobject_template_addon` SET `flags`=4, `AIAnimKitID`=5061 WHERE `entry`=327543; -- Esfera rajada
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=322803; -- Bayalga
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2100 WHERE `entry`=327439; -- Tallo marino expansible
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326402; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326401; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=329784; -- Pilón arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326396; -- Baúl arcano reluciente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=326704; -- Dispositivo arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=328376; -- Pilón arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326397; -- Baúl arcano reluciente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=326590; -- Dispositivo arcano
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=327158; -- Almeja neptuliana
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=11129 WHERE `entry`=329907; -- Altar de la Maretista
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326395; -- Baúl arcano reluciente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=328360; -- Pilón arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326398; -- Baúl arcano reluciente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=326589; -- Dispositivo arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=326706; -- Dispositivo arcano
UPDATE `gameobject_template_addon` SET `flags`=8192, `WorldEffectID`=2437 WHERE `entry`=326412; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8971 WHERE `entry`=332221; -- Pilón arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326411; -- Cofre arcano
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=326413; -- Cofre arcano

DELETE FROM `creature_template_locale` WHERE (`entry`=162875 AND `locale`='esMX');
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(162875, 'esMX', 'Devmorta', NULL, NULL, NULL, 38134);



UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=147550 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138931 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134752 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130786 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131004 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135401 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141349 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141348 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140003 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140002 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138221 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135800 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Targeting Bunny', `VerifiedBuild`=38134 WHERE (`entry`=137731 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140015 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130694 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130190 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141482 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140016 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140014 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140013 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140012 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140011 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140008 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140007 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140005 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140001 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139999 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130189 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140018 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140010 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140009 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140006 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140004 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139996 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139994 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137621 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129749 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131272 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Targeting Bunny', `VerifiedBuild`=38134 WHERE (`entry`=137730 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134426 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129753 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143221 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137094 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135947 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137104 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131709 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130453 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131496 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=147010 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=147009 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=147008 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131656 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=144478 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134963 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130452 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129884 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129870 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129869 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135939 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135940 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129906 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135684 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130075 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134425 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132160 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130897 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135774 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132123 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129750 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132207 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132161 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129806 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Thornshaping Bunny', `VerifiedBuild`=38134 WHERE (`entry`=133203 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132226 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133940 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130073 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143035 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141239 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140595 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142400 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141586 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138757 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=58237 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134968 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138755 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134832 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138739 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140021 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135171 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136670 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136669 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136668 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134720 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137024 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135600 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137041 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136712 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140577 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135389 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136706 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136740 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137049 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136711 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136165 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134967 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136708 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136768 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136707 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137042 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143592 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135367 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137044 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143914 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139984 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138379 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136709 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135783 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134937 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134930 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134928 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139981 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139978 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=92164 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138378 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135386 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134969 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=61143 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=6271 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135371 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135369 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134666 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134636 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141855 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141854 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141853 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138167 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134688 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138789 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138170 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138168 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136743 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138212 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140666 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142113 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140464 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140209 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135407 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135236 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139298 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135526 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142610 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127947 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142088 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139623 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139704 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139637 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139635 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138924 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138735 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136239 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136914 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142390 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138963 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131697 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135662 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126677 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135125 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142600 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142586 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140551 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138210 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131338 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131337 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131014 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131001 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131003 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139517 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139516 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138193 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135405 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131342 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131314 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130824 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131301 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=112192 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131344 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131343 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141263 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141222 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131313 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131141 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140518 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131114 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130867 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131778 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131335 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130744 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131277 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131085 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131409 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130823 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=123236 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131084 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130822 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129980 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129972 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137464 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139379 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137944 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137943 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137130 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134830 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138938 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138095 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137505 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133953 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137542 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137110 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130809 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137105 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137576 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138092 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138451 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137977 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137971 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138093 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137975 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137974 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137972 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135793 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137065 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137968 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137318 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137080 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135794 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137668 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137667 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137664 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137504 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137500 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137235 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136149 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135795 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138453 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137659 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135848 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143218 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138546 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138793 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137967 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138521 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='General Purpose Bunny RMV', `VerifiedBuild`=38134 WHERE (`entry`=133405 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141901 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142394 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150584 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141994 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141984 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135391 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131361 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126578 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141995 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139846 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139845 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139844 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139843 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131360 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137936 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136015 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143302 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143281 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138038 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150577 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143495 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143289 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138048 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137915 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=144502 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143593 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143293 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143287 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Lumber Bunny', `VerifiedBuild`=38134 WHERE (`entry`=142395 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138903 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138108 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138104 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137911 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143032 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138905 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Return to Zuldazar Kill Credit', `VerifiedBuild`=38134 WHERE (`entry`=139520 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138886 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138111 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138097 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138096 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138032 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138027 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135981 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=98961 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=98960 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136222 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136196 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142455 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136007 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136498 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136313 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135985 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135418 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135689 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135415 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135457 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135585 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139526 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135813 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135812 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135785 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135814 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135593 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135511 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130554 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142198 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130006 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134450 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142199 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130116 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136591 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136439 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139177 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138134 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130094 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141006 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141008 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141002 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141007 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143038 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142634 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142609 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142196 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134747 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134723 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134721 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134696 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134631 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134623 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131376 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139968 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131857 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139973 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139571 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131862 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139803 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132619 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132163 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136337 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136157 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134417 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134139 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136186 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134173 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136188 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134137 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136347 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141585 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136249 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141587 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143143 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142550 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141050 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141048 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141047 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141046 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139800 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139799 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139796 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137693 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137691 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135937 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143031 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142462 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141177 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131401 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142463 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142579 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142528 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137189 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137726 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136053 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137789 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137037 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142540 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137212 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=95464 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137215 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137202 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137188 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142515 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='FX Stalker', `VerifiedBuild`=38134 WHERE (`entry`=149374 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129978 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130531 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142582 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151187 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130039 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139209 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145696 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142601 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=128625 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141985 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141975 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137763 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=132007 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142578 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142576 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142630 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142620 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142577 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130768 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=120822 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134350 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134349 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143219 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155559 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='FX Stalker', `VerifiedBuild`=38134 WHERE (`entry`=146234 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155558 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153393 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131663 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131793 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142060 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134824 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142170 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Large AOI Bunny - GJC', `VerifiedBuild`=38134 WHERE (`entry`=73985 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142195 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142184 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=136422 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131387 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130819 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143034 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142183 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142168 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131412 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131404 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145239 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143033 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142194 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134377 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142175 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134316 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131693 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141716 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141696 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141059 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141798 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141769 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141483 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141353 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134704 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=130005 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141064 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141641 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141098 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141123 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141090 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139790 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142454 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142172 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141315 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131381 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143361 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131600 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138081 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137987 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141313 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138014 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138009 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138008 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138007 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138006 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138005 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137988 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137985 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134359 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143041 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141518 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141512 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141506 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141479 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127739 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149027 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126569 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139280 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129670 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129724 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149025 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134308 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133285 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126709 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126708 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127626 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=124845 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129768 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129745 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129624 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133459 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139624 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139434 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137367 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137369 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133264 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133210 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134776 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Name`='Hank Mount Horsey Kill Credit', `VerifiedBuild`=38134 WHERE (`entry`=133659 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133309 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=133187 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129616 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126455 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126496 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126824 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=158148 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=158221 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129627 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127636 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143036 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139089 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126530 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141991 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `Title`='PVP Healing', `VerifiedBuild`=38134 WHERE (`entry`=131998 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140904 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=161565 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143572 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142773 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143574 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142611 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142564 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143718 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142770 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142764 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142754 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142607 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126582 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126581 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=148904 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=144029 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142882 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142881 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142605 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141066 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=123210 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142759 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142777 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142774 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142885 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=144493 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142886 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142884 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143559 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143336 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143847 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143560 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142767 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142603 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142602 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142119 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141771 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141698 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=88696 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142608 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140640 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=138041 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=88697 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=144002 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142784 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142778 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142771 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142760 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142775 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142772 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=125004 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141009 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=135889 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=124883 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141001 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126640 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140944 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=127193 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=126583 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=123641 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=140936 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=124238 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143040 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143248 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143259 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=143242 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=139375 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129001 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150208 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150493 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=129940 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154245 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154915 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153833 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154714 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151332 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151618 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151381 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154208 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150369 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145740 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150361 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151614 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150363 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150362 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149913 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153042 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149911 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151671 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151848 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152529 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151849 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151294 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155822 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151352 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151354 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153839 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153772 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153364 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152971 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152084 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151617 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154940 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=114281 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153902 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153900 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150349 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=6491 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153147 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154936 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153055 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153027 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151946 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152607 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154082 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152915 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=148475 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153999 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152674 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153685 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152676 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153998 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150903 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155890 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152558 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154702 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152411 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=148392 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145346 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152413 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152889 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154907 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152412 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=148391 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152516 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151198 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151750 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152786 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154235 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151218 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154912 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152689 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152534 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=156262 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152688 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152690 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150568 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152717 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153025 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154530 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154247 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153524 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152565 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152737 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153863 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152066 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155907 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154182 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154105 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153777 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154143 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154422 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152356 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154911 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154234 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152366 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152379 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152358 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154624 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152363 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154860 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151557 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154865 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154670 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154864 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154863 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154522 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152357 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155636 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155807 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155611 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155606 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152532 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154459 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152362 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152244 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145339 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154875 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154686 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152577 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152262 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151423 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151545 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152888 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152151 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152122 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154243 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153819 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152984 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153757 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154599 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154366 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154601 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152919 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155361 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149720 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155635 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155210 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155078 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154548 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154547 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154528 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154595 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151310 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154509 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152716 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152071 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154514 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152070 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152931 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152069 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152164 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152161 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152297 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152562 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149722 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154574 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154285 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152893 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155886 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152494 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152203 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154092 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153687 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153684 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152463 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151782 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152116 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155844 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154075 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152968 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145343 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153893 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155585 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152813 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153843 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154990 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153472 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152822 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149709 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154287 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154064 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=111345 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154751 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151789 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151786 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153329 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152787 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155727 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154902 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154074 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152819 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152724 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151774 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145333 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154680 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154683 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154992 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153078 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153895 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152962 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154239 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153334 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153080 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154913 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152462 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153814 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153812 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155590 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153804 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152460 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152461 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153655 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154132 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154919 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152879 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155878 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152906 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153654 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152882 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154312 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154311 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154310 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154706 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152744 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153963 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=149752 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154707 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153936 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153959 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154910 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152641 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152635 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154921 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155880 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155879 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=46303 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=46290 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=46288 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=46286 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153884 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153842 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153753 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153250 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=156110 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=156111 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155610 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153758 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153872 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152624 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152273 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152989 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152985 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152990 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152274 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153818 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152275 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154916 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=80554 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152541 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=141620 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142690 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=142709 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152544 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152543 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154246 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154238 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=155613 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153764 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154569 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153762 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153504 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153778 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=131071 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152812 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154194 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153537 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152684 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=154681 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=153263 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=134346 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152687 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152686 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152917 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=150819 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152683 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152685 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152881 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=145326 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152878 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=137109 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152710 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=152711 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=151534 AND `locale`='esMX');

SET NAMES 'latin1';
SET NAMES 'utf8';
DELETE FROM `quest_template_locale` WHERE (`ID`=57301 AND `locale`='esMX');
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(57301, 'esMX', 'Pócimas perversas', 'Lleva cualquier combinación de pegote mefítico, aceite viscoso o moco miscible a la Poza de monstruosidades mezcladas.', 'Fui testigo de tu éxito con la poza de pociones y creo que podrías ayudar. ¡En esta poza más grande, creamos mezclas más peligrosas!\n\nHay tres ingredientes purulentos que mezclamos en diferentes combinaciones para crear criaturas violentas. Cuando se hayan agregado suficientes ingredientes a la poza, ¡la mezcla cobrará forma y emergerá una criatura!\n\nTrae cualquier combinación de estos ingredientes: pegote mefítico, aceite viscoso o moco miscible a la Poza de monstruosidades mezcladas.', '', '', '', '', '', '', 38134);

UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=57333 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56118 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56095 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56309 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56422 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56321 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56239 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=26546 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=26035 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=56561 AND `locale`='esMX');

SET NAMES 'latin1';
SET NAMES 'utf8';
DELETE FROM `quest_objectives_locale` WHERE (`locale`='esMX' AND `ID` IN (409173,392087));
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(409173, 'esMX', 57301, 0, 'Ingredientes purulentos arrojados a la poza de monstruosidades mezcladas', 38134),
(392087, 'esMX', 57301, 3, 'Ingredientes purulentos obtenidos de las babas', 38134);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=392150 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390467 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390273 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390206 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390203 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390200 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390199 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390676 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390675 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390674 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=390568 AND `locale`='esMX');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=266187 AND `locale`='esMX');

DELETE FROM `quest_greeting_locale` WHERE (`ID`=154143 AND `Type`=0 AND `locale`='esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(154143, 0, 'esMX', 'Hola, $r. ¿Me harías un favor?', 38134);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='esMX' AND `ID` IN (55683,55625,55719));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(55683, 'esMX', '¿Donde dejé ese diario?', 38134),
(55625, 'esMX', 'Debemos aprovechar toda ventaja en nuestra lucha contra los nagas.', 38134),
(55719, 'esMX', '¿Qué me has traído hoy?', 38134);

DELETE FROM `page_text_locale` WHERE (`ID`=7986 AND `locale`='esMX');
INSERT INTO `page_text_locale` (`ID`, `Text`, `locale`, `VerifiedBuild`) VALUES
(7986, 'Aquí descansa el buscador Anewa, del clan Cuchilla marina\n\nIntentó encontrar respuestas a preguntas que aún no se habían hecho\n\nY asesinó a lo desconocido con la cuchilla de la sabiduría', 'esMX', 38134);

DELETE FROM `playerchoice_response_locale` WHERE (`ChoiceId`=612 AND `ResponseId` IN (2283,2282,2254));
INSERT INTO `playerchoice_response_locale` (`ChoiceId`, `ResponseId`, `Locale`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES
(612, 2283, 'esMX', 'Esgrimidor Inowari', '', '|cffff0000Ya has elegido a otro aliado para el día de hoy.|r', 'Reclutar al esgrimidor Inowari', 'El esgrimidor Inowari es uno de los guerreros más habilidosos de Cuchilla marina.\n\n', '', 38134),
(612, 2282, 'esMX', 'Cazador Akana', '', '|cffff0000Ya has elegido a otro aliado para el día de hoy.|r', 'Reclutar al cazador Akana', 'Akana es un cazador aguerrido con excelentes habilidades de supervivencia.\n\n', '', 38134),
(612, 2254, 'esMX', 'Clarividente Ori', '', '|cffff0000El clarividente Ori ya está siguiéndote.|r', 'Reclutar al clarividente Ori', 'El clarividente Ori es un chamán poderoso que controla los elementos.\n\n', '', 38134);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (50601 /*-Unknown-*/, 55801 /*-Unknown-*/, 55719 /*-Unknown-*/, 55683 /*-Unknown-*/, 56422 /*-Unknown-*/, 56321 /*-Unknown-*/, 56304 /*-Unknown-*/, 55625 /*-Unknown-*/, 56119 /*-Unknown-*/, 56561 /*-Unknown-*/, 55786 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50601, 0, 0, 0, 0, 0, 0, 0, 0, 'Las mareas predijeron tus triunfos. Gracias.', 38134), -- -Unknown-
(55801, 0, 0, 0, 0, 0, 0, 0, 0, 'Gracias por tu aporte.', 38134), -- -Unknown-
(55719, 0, 0, 0, 0, 0, 0, 0, 0, 'Gracias por tu aporte.', 38134), -- -Unknown-
(55683, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah… ya recuerdo todo. Pasó hace tanto tiempo. Creo que llegó la hora de que descanse…', 38134), -- -Unknown-
(56422, 1, 0, 0, 0, 0, 0, 0, 0, 'Gracias, $n.\n\nGracias a tus esfuerzos, recuperamos un poco de la paz mental que habíamos perdido hace tanto.\n\nMi padre y yo estamos a tu servicio.', 38134), -- -Unknown-
(56321, 1, 0, 0, 0, 0, 0, 0, 0, 'Gracias, $n. Mi padre y yo siempre estaremos agradecidos por lo que hiciste.', 38134), -- -Unknown-
(56304, 1, 0, 0, 0, 0, 0, 0, 0, '$n, esa taumaturga umbría naga está torturando a Corin. \n\n¡Tenemos que hacer algo!', 38134), -- -Unknown-
(55625, 0, 0, 0, 0, 0, 0, 0, 0, 'Bien hecho. Siento una energía poderosa que emana del interior de esas perlas.', 38134), -- -Unknown-
(56119, 0, 0, 0, 0, 0, 0, 0, 0, 'Que las bendiciones de Neptulon abunden, $gamigo:amiga;.', 38134), -- -Unknown-
(56561, 1, 1, 0, 0, 0, 0, 0, 0, 'He visto estos cristales en un par de lugares, a menudo con una baba de aspecto raro a su alrededor. Tiene que haber algún vínculo entre baba y cristal, pero todavía no lo descubrí.\n\nComo sea, el único uso que les he encontrado a estos cristales es hacer que criaturas diminutas me sigan durante un rato.\n\nLo siento, no es muy útil. Aquí tienes tu cristal. Cuéntame si descubres algo más.', 38134), -- -Unknown-
(55786, 0, 0, 0, 0, 0, 0, 0, 0, 'Gracias por tu aporte.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=56561 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(56561, 0, 0, -1, 0, 0, 1718, 1355, 0, 0, 0, 0, 0, 1777762, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52452 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52452 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52309 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52309 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=4 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=3 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56422 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56422 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=8 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=7 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=6 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=5 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=4 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=3 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=2 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=6 AND `Idx1`=13); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=5 AND `Idx1`=12); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=4 AND `Idx1`=11); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=3 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=2 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=1 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=6 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=5 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=4 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=3 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=56561 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(56561, 0, 0, 1275, -19, -336, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52982 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51854 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51806 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52452 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52452 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52309 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52309 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55892 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56422 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56422 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56321 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55683 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56304 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55970 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55625 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=13 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=12 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=11 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55898 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57334 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56056 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`ID`=154143 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(154143, 0, 1, 0, 'Hola, $r. ¿Me harías un favor?', 38134); -- 154143


DELETE FROM `quest_details` WHERE `ID` IN (56239 /*-Unknown-*/, 56309 /*-Unknown-*/, 56422 /*-Unknown-*/, 56321 /*-Unknown-*/, 55683 /*-Unknown-*/, 56304 /*-Unknown-*/, 55625 /*-Unknown-*/, 56561 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(56239, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(56309, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(56422, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(56321, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55683, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(56304, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55625, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(56561, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (55719 /*-Unknown-*/, 55625 /*-Unknown-*/, 55683 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(55719, 0, 0, 0, 0, '¿Qué me has traído hoy?', 38134), -- -Unknown-
(55625, 0, 0, 0, 0, 'Debemos aprovechar toda ventaja en nuestra lucha contra los nagas.', 0), -- -Unknown-
(55683, 0, 0, 0, 0, '¿Donde dejé ese diario?', 0); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (345123,302726));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(345123, 0, 1643, 3356.820068359375, 1358.72998046875, 42.04000091552734375, 38134), -- Spell: 345123 (Cancel Shark Form) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(302726, 0, 1718, 717.5999755859375, 50.29999923706054687, -189.399993896484375, 38134); -- Spell: 302726 (Return to Hydraxis) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=265417 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (147550 /*147550 (Cosechador)*/, 147008 /*147008 (Marlowe Lexvold)*/, 147009 /*147009 (Mozo de labranza reparado)*/, 147010 /*147010 (Mozo de labranza arruinado)*/, 138963 /*138963 (Madre del nido Acada)*/, 142390 /*142390 (Cachorro de Tierras Altas)*/, 135662 /*135662 (Huevo)*/, 150584 /*150584 (Trituradora saboteada) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 143281 /*143281 (Scott Archeron)*/, 138048 /*138048 (Muñeco de entrenamiento) - Training Dummy Marker*/, 138038 /*138038 (Wooden "Horse")*/, 143289 /*143289 (Lohk Tótem Celestial)*/, 141006 /*141006 (Dead Deckhand Leonard)*/, 141007 /*141007 (Corrupted Slime)*/, 141008 /*141008 (Reanimated Kraken Tentacle)*/, 141048 /*141048 (Lesser Twisted Current)*/, 141050 /*141050 (Mind Warper)*/, 141047 /*141047 (Lesser Charged Gale)*/, 149374 /*149374 (FX Stalker) - [DNT] Ship Blessing*/, 151187 /*151187 (Acechador de efectos especiales) - [DNT] Ship Blessing*/, 145696 /*145696 (Shrine View)*/, 141975 /*141975 (Trozo de azerita)*/, 132007 /*132007 (Tormenta de vendavales)*/, 139988 /*139988*/, 155559 /*155559 (Obrera mielomo)*/, 155558 /*155558 (Cosechadora mielomo)*/, 153393 /*153393 (Barry)*/, 143033 /*143033 (Freshwater Crawler)*/, 145239 /*145239 (Vigía de las mareas inerte) - Inert Golem Stun*/, 141518 /*141518 (Burly Jr.)*/, 141512 /*141512 (Pokey)*/, 141506 /*141506 (Timbo)*/, 149027 /*149027 (Madera llevada)*/, 149025 /*149025 (Madera pesada)*/, 158148 /*158148 (Telecóptero) - Rope Beam*/, 158221 /*158221 (Pertrechos kultiranos) - Ride Vehicle Hardcoded*/, 161565 /*161565 (Bragni)*/, 148904 /*148904 (Miles)*/, 150208 /*150208 (Maestro manitas Sobrechispa) - Read Scroll*/, 150493 /*150493 (Gina Cableado) - Taking Notes*/, 154915 /*154915 (Elderspawn of Nalaada)*/, 153833 /*153833 (Exploradora Nuevil) - Ready with Bucket*/, 151617 /*151617 (Fertile Soil)*/, 154940 /*154940 (Blob Bunny)*/, 150349 /*150349 (Blood Pool)*/, 151218 /*151218 (Baba voraz) - Well Fed*/, 154105 /*154105 (Profesora Elryna)*/, 152360 /*152360*/, 153777 /*153777 (Cando Mikaleta)*/, 154143 /*154143 (Coleccionista Tojo)*/, 154624 /*154624 (Sable de la noche espectral) - Stealth*/, 154522 /*154522 (Shandris Plumaluna)*/, 154864 /*154864 (Traficante de dijes Rentala)*/, 154875 /*154875 (Vanesh Vinatero)*/, 154686 /*154686 (Tynala "Dedos ágiles")*/, 151423 /*151423 (Agente altonato)*/, 154601 /*154601 (Kelya Puestaluna)*/, 154547 /*154547 (Corin Puestaluna) - [DNT] Ellen Shadow State*/, 154528 /*154528 (Eranor Birtris) - Dual Wield*/, 154509 /*154509 (Varel Cantopan)*/, 152416 /*152416 (Allseer Oma'kil)*/, 154574 /*154574 (Kelya Puestaluna)*/, 152756 /*152756 - Feeding Frenzy*/, 155844 /*155844 (Aprendiz Anako) - Stealth*/, 153893 /*153893 (Cosechador zoatroide) - Carrying Egg*/, 155585 /*155585 (Zoatroide inferior)*/, 153472 /*153472 (Cautivo tocado por el Vacío) - Set Health (Random 15%-55%), Void-Touched*/, 149709 /*149709 (Cautivo aleta negra)*/, 153315 /*153315 - Binding, Commanding, Affix Controller*/, 153329 /*153329 (Lady Zharessa) - Tidestone Link*/, 153814 /*153814 (Guillotina cantaespín)*/, 155880 /*155880 (Epicus Maximus)*/, 153753 /*153753 (Esclavista zanj'ir)*/, 153872 /*153872 (Renacuajo sangraleta) - Ride Vehicle Hardcoded*/, 153758 /*153758 (Recolector de renacuajos)*/, 152542 /*152542*/, 154569 /*154569 (Ancla de algas)*/, 152553 /*152553*/, 153263 /*153263 (Kritch) - Spiked Carapace*/, 152682 /*152682 (Prince Vortran)*/, 152709 /*152709*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(147550, 0, 0, 7, 1, 0, 0, 0, 0, ''), -- 147550 (Cosechador)
(147008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147008 (Marlowe Lexvold)
(147009, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147009 (Mozo de labranza reparado)
(147010, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147010 (Mozo de labranza arruinado)
(138963, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 138963 (Madre del nido Acada)
(142390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 142390 (Cachorro de Tierras Altas)
(135662, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 135662 (Huevo)
(150584, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 150584 (Trituradora saboteada) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(143281, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 143281 (Scott Archeron)
(138048, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 138048 (Muñeco de entrenamiento) - Training Dummy Marker
(138038, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 138038 (Wooden "Horse")
(143289, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 143289 (Lohk Tótem Celestial)
(141006, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141006 (Dead Deckhand Leonard)
(141007, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141007 (Corrupted Slime)
(141008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141008 (Reanimated Kraken Tentacle)
(141048, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141048 (Lesser Twisted Current)
(141050, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141050 (Mind Warper)
(141047, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141047 (Lesser Charged Gale)
(149374, 0, 0, 0, 1, 0, 0, 0, 0, '292845'), -- 149374 (FX Stalker) - [DNT] Ship Blessing
(151187, 0, 0, 0, 1, 0, 0, 0, 0, '292845'), -- 151187 (Acechador de efectos especiales) - [DNT] Ship Blessing
(145696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145696 (Shrine View)
(141975, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141975 (Trozo de azerita)
(132007, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132007 (Tormenta de vendavales)
(139988, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 139988
(155559, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 155559 (Obrera mielomo)
(155558, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 155558 (Cosechadora mielomo)
(153393, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 153393 (Barry)
(143033, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 143033 (Freshwater Crawler)
(145239, 0, 0, 0, 1, 0, 7016, 0, 0, '282764'), -- 145239 (Vigía de las mareas inerte) - Inert Golem Stun
(141518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141518 (Burly Jr.)
(141512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141512 (Pokey)
(141506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141506 (Timbo)
(149027, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 149027 (Madera llevada)
(149025, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 149025 (Madera pesada)
(158148, 0, 0, 50331648, 1, 0, 0, 0, 0, '308574'), -- 158148 (Telecóptero) - Rope Beam
(158221, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 158221 (Pertrechos kultiranos) - Ride Vehicle Hardcoded
(161565, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161565 (Bragni)
(148904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 148904 (Miles)
(150208, 0, 0, 0, 1, 0, 0, 0, 0, '212171'), -- 150208 (Maestro manitas Sobrechispa) - Read Scroll
(150493, 0, 0, 0, 0, 0, 0, 0, 0, '298877'), -- 150493 (Gina Cableado) - Taking Notes
(154915, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154915 (Elderspawn of Nalaada)
(153833, 0, 0, 0, 1, 0, 0, 0, 0, '298711'), -- 153833 (Exploradora Nuevil) - Ready with Bucket
(151617, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 151617 (Fertile Soil)
(154940, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154940 (Blob Bunny)
(150349, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 150349 (Blood Pool)
(151218, 0, 0, 0, 1, 0, 0, 0, 0, '293778'), -- 151218 (Baba voraz) - Well Fed
(154105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154105 (Profesora Elryna)
(152360, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 152360
(153777, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 153777 (Cando Mikaleta)
(154143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154143 (Coleccionista Tojo)
(154624, 0, 0, 0, 1, 0, 0, 0, 0, '30831'), -- 154624 (Sable de la noche espectral) - Stealth
(154522, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154522 (Shandris Plumaluna)
(154864, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154864 (Traficante de dijes Rentala)
(154875, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154875 (Vanesh Vinatero)
(154686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154686 (Tynala "Dedos ágiles")
(151423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 151423 (Agente altonato)
(154601, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154601 (Kelya Puestaluna)
(154547, 0, 0, 0, 1, 0, 0, 0, 0, '301675'), -- 154547 (Corin Puestaluna) - [DNT] Ellen Shadow State
(154528, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 154528 (Eranor Birtris) - Dual Wield
(154509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154509 (Varel Cantopan)
(152416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152416 (Allseer Oma'kil)
(154574, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154574 (Kelya Puestaluna)
(152756, 0, 0, 0, 1, 0, 0, 0, 0, '297896'), -- 152756 - Feeding Frenzy
(155844, 0, 0, 131080, 1, 0, 0, 0, 0, '192113'), -- 155844 (Aprendiz Anako) - Stealth
(153893, 0, 0, 50331648, 1, 0, 0, 0, 0, '298895'), -- 153893 (Cosechador zoatroide) - Carrying Egg
(155585, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 155585 (Zoatroide inferior)
(153472, 0, 0, 0, 1, 0, 17026, 0, 0, '244971 299171'), -- 153472 (Cautivo tocado por el Vacío) - Set Health (Random 15%-55%), Void-Touched
(149709, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 149709 (Cautivo aleta negra)
(153315, 0, 0, 0, 1, 0, 0, 0, 0, '300416 300421 300383'), -- 153315 - Binding, Commanding, Affix Controller
(153329, 0, 0, 0, 1, 0, 0, 0, 0, '298294'), -- 153329 (Lady Zharessa) - Tidestone Link
(153814, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 153814 (Guillotina cantaespín)
(155880, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 155880 (Epicus Maximus)
(153753, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 153753 (Esclavista zanj'ir)
(153872, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 153872 (Renacuajo sangraleta) - Ride Vehicle Hardcoded
(153758, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 153758 (Recolector de renacuajos)
(152542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152542
(154569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154569 (Ancla de algas)
(152553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152553
(153263, 0, 0, 0, 1, 0, 0, 0, 0, '298909'), -- 153263 (Kritch) - Spiked Carapace
(152682, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 152682 (Prince Vortran)
(152709, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 152709

UPDATE `creature_template_addon` SET `aiAnimKit`=16228 WHERE `entry`=141349; -- 141349 (Henovalente)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=138221; -- 138221 ("Canalla" Buck)
UPDATE `creature_template_addon` SET `aiAnimKit`=16734 WHERE `entry`=139999; -- 139999 (Kyle Pataronson)
UPDATE `creature_template_addon` SET `aiAnimKit`=15451 WHERE `entry`=140005; -- 140005 (Damargat)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=141482; -- 141482 (Ciudadana de Presabrenna)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='162084' WHERE `entry`=131272; -- 131272 (Aldeano de Presabrenna)
UPDATE `creature_template_addon` SET `auras`='136133' WHERE `entry`=129753; -- 129753 (Rebanacabezas sanguinario)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=134426; -- 134426 (Técnico zapador)
UPDATE `creature_template_addon` SET `aiAnimKit`=11111 WHERE `entry`=135947; -- 135947 (Anillo de champiñones extraños)
UPDATE `creature_template_addon` SET `mount`=29283 WHERE `entry`=137104; -- 137104 (Asaltante orco)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=131709; -- 131709 (Mozo de labranza mecanizado)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=130452; -- 130452 (Perro guardián fiel)
UPDATE `creature_template_addon` SET `mount`=81145, `bytes1`=0, `auras`='' WHERE `entry`=129750; -- 129750 (Hostigador zarzalomo)
UPDATE `creature_template_addon` SET `aiAnimKit`=8297, `auras`='55474' WHERE `entry`=58237; -- 58237 (Pellizcos)
UPDATE `creature_template_addon` SET `aiAnimKit`=14435 WHERE `entry`=136165; -- 136165 (Trabajador)
UPDATE `creature_template_addon` SET `auras`='172032' WHERE `entry`=137042; -- 137042 (Beatriz Rupert)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='207221' WHERE `entry`=135389; -- 135389 (Ron Haribull)
UPDATE `creature_template_addon` SET `bytes2`=1, `aiAnimKit`=15396, `auras`='' WHERE `entry`=135783; -- 135783 (Cazatesoros)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=135369; -- 135369 (Forzuda de La Rivera Muerta)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=134636; -- 134636 (Cazatesoros)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='' WHERE `entry`=134666; -- 134666 (Cazatesoros)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=141853; -- 141853 (Rebecca Barnes)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=141854; -- 141854 (Jonathon Barnes)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=141855; -- 141855 (Susanna Barnes)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=134688; -- 134688 (Cazatesoros)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=138168; -- 138168 (Irontide Coin Hauler)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=138789; -- 138789 (Irontide Pillager)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=136743; -- 136743 (Cazatesoros)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135236; -- 135236 (Guardián hurgafango)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=139704; -- 139704 (Kaela Godwin)
UPDATE `creature_template_addon` SET `auras`='162907' WHERE `entry`=139637; -- 139637 (Cazadora agotada)
UPDATE `creature_template_addon` SET `aiAnimKit`=3228 WHERE `entry`=139635; -- 139635 (Matthew Gandorian)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=138924; -- 138924 (Holger Nash)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='266099' WHERE `entry`=131697; -- 131697 (Oso pardo de las Tierras Altas)
UPDATE `creature_template_addon` SET `auras`='270996' WHERE `entry`=137744; -- 137744
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142600; -- 142600 (Refugiado de Brisamarina)
UPDATE `creature_template_addon` SET `aiAnimKit`=14592 WHERE `entry`=131342; -- 131342 (Jameson)
UPDATE `creature_template_addon` SET `auras`='260032' WHERE `entry`=131301; -- 131301 (Spell Bunny)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145362' WHERE `entry`=131141; -- 131141 (Guardián escamoso zeth'jir)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=140518; -- 140518 (Aldeano de Brisamarina)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='264427' WHERE `entry`=131409; -- 131409 (Soldado del batallón varado)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=137649; -- 137649
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=137972; -- 137972 (Mebbo)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137235; -- 137235 (Charco de aceite)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=137500; -- 137500 (Propagador de incendios de Ventura y Cía.)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='154470' WHERE `entry`=136149; -- 136149 (Matriarca hidrocoraza)
UPDATE `creature_template_addon` SET `auras`='246529' WHERE `entry`=137659; -- 137659 (Bakuta Durazón)
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='154470' WHERE `entry`=131361; -- 131361 (Guardia del batallón)
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='154470' WHERE `entry`=135391; -- 135391 (Trabajador de La Rivera Muerta)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=139844; -- 139844 (Ingeniero goblin)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=139846; -- 139846 (Chamán marchito)
UPDATE `creature_template_addon` SET `mount`=0, `bytes1`=262144, `bytes2`=1, `auras`='154470' WHERE `entry`=131360; -- 131360 (Guardia del batallón)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=138032; -- 138032 (Peón)
UPDATE `creature_template_addon` SET `auras`='140387' WHERE `entry`=136196; -- 136196 (Peón guerracolmillo)
UPDATE `creature_template_addon` SET `aiAnimKit`=15351 WHERE `entry`=135585; -- 135585 (Ascendiente ahogado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135785; -- 135785 (Presagista ahogado)
UPDATE `creature_template_addon` SET `auras`='159474' WHERE `entry`=135814; -- 135814 (Degollador velado)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='266301 145953' WHERE `entry`=135511; -- 135511 (Jerarca ahogado)
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='154470' WHERE `entry`=130006; -- 130006 (Partidario de Canto Tormenta)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=139571; -- 139571 (Martillador tronaforjado)
UPDATE `creature_template_addon` SET `auras`='269618 274456' WHERE `entry`=132163; -- 132163 (Guardián de la marea Pontus)
UPDATE `creature_template_addon` SET `auras`='281206' WHERE `entry`=134173; -- 134173 (Gota animada)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=136186; -- 136186 (Espiritualista maresabia)
UPDATE `creature_template_addon` SET `auras`='123168' WHERE `entry`=141585; -- 141585 (Piojo marino)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=136249; -- 136249 (Elemental guardián)
UPDATE `creature_template_addon` SET `auras`='281206' WHERE `entry`=136347; -- 136347 (Maresabio iniciado)
UPDATE `creature_template_addon` SET `auras`='274649' WHERE `entry`=139800; -- 139800 (Aprendiz clamavendavales)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='244807' WHERE `entry`=136053; -- 136053 (Samuel Williams)
UPDATE `creature_template_addon` SET `aiAnimKit`=15351 WHERE `entry`=137037; -- 137037 (Maresabio despierto)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=130531; -- 130531 (Carpintero de barcos traidor)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='274046' WHERE `entry`=130039; -- 130039 (Cañonero salbrío)
UPDATE `creature_template_addon` SET `auras`='301635' WHERE `entry`=146234; -- 146234 (FX Stalker)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='266099' WHERE `entry`=131387; -- 131387 (Zorro colacobre)
UPDATE `creature_template_addon` SET `aiAnimKit`=15110 WHERE `entry`=131404; -- 131404 (Capataz Scripps)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=134377; -- 134377 (Halieto picosuave)
UPDATE `creature_template_addon` SET `aiAnimKit`=1320 WHERE `entry`=141483; -- 141483 (Ciudadana de Presabrenna)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=141090; -- 141090 (Mill Worker)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=131600; -- 131600 (Halcón de las Tierras Altas)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=143361; -- 143361 (Hurón travieso)
UPDATE `creature_template_addon` SET `mount`=85668 WHERE `entry`=137987; -- 137987 (Inspector Canto Tormenta)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=141313; -- 141313 (Cabra de Crestalina)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=134359; -- 134359 (Castor dientudo)
UPDATE `creature_template_addon` SET `auras`='244863' WHERE `entry`=138007; -- 138007 (Pescadero puntanzuelo)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=137985; -- 137985 (Centinela de Canto Tormenta)
UPDATE `creature_template_addon` SET `auras`='115385' WHERE `entry`=133285; -- 133285 (Cazador del lecho)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=133264; -- 133264 (Inspector de Vadoarlén)
UPDATE `creature_template_addon` SET `aiAnimKit`=14323 WHERE `entry`=129616; -- 129616 (Marlowe Algerson)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=143700; -- 143700
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=257 WHERE `entry`=133309; -- 133309 (Trabajador de Vadoarlén)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=127636; -- 127636 (Búho de Tiragarde)
UPDATE `creature_template_addon` SET `mount`=82961 WHERE `entry`=139089; -- 139089 (Guardia de Vadoarlén)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=142886; -- 142886 (Joey "Salado" Birdman)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=141771; -- 141771 (Marinero de cubierta de Aspafresno)
UPDATE `creature_template_addon` SET `bytes1`=6 WHERE `entry`=135604; -- 135604
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=124883; -- 124883 (Carretilla kultirana)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135112; -- 135112
UPDATE `creature_template_addon` SET `aiAnimKit`=6644 WHERE `entry`=123641; -- 123641 (Trabajador de Boralus)
UPDATE `creature_template_addon` SET `auras`='244807 174714' WHERE `entry`=140906; -- 140906
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=135792; -- 135792 (Boralus Worker)
UPDATE `creature_template_addon` SET `auras`='266042' WHERE `entry`=135603; -- 135603 (Boralus Civilian)
UPDATE `creature_template_addon` SET `aiAnimKit`=13903 WHERE `entry`=143248; -- 143248 (Rebecca Lin)
UPDATE `creature_template_addon` SET `auras`='163005' WHERE `entry`=143870; -- 143870
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=143420; -- 143420
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=147972; -- 147972
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=135678; -- 135678
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=140350; -- 140350
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=0 WHERE `entry`=135509; -- 135509
UPDATE `creature_template_addon` SET `bytes2`=0, `aiAnimKit`=0 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=0 WHERE `entry`=123642; -- 123642 (Boralus Citizen)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=140313; -- 140313
UPDATE `creature_template_addon` SET `bytes1`=8, `auras`='' WHERE `entry`=142457; -- 142457
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=256 WHERE `entry`=133325; -- 133325
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142459; -- 142459
UPDATE `creature_template_addon` SET `bytes1`=7 WHERE `entry`=152084; -- 152084 (Mrrl)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=152915; -- 152915 (Neófita azsh'ari)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=148475; -- 148475 (Vidente aleta negra)
UPDATE `creature_template_addon` SET `aiAnimKit`=1343 WHERE `entry`=150903; -- 150903 (Luxaleta errante)
UPDATE `creature_template_addon` SET `aiAnimKit`=4397 WHERE `entry`=155890; -- 155890 (Escondite de Poen)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=152689; -- 152689 (Gigante de mar capturado)
UPDATE `creature_template_addon` SET `aiAnimKit`=9768 WHERE `entry`=152690; -- 152690 (Caparazón profundo capturado)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='152209' WHERE `entry`=154182; -- 154182 (Boca de dragón destruido)
UPDATE `creature_template_addon` SET `aiAnimKit`=730 WHERE `entry`=152366; -- 152366 (Cadáver de trillanodonte fresco)
UPDATE `creature_template_addon` SET `aiAnimKit`=730 WHERE `entry`=152379; -- 152379 (Cadáver de mantarraya sondeadora fresco)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=154863; -- 154863 (Hipogrifo fantasma)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=152244; -- 152244 (Tirador certero altonato)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=152362; -- 152362 (Devastador boca de dragón)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=152070; -- 152070 (Guardián altonato)
UPDATE `creature_template_addon` SET `auras`='295140' WHERE `entry`=152164; -- 152164 (Elemental frenético)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=149722; -- 149722 (Noble altonato)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=152893; -- 152893 (Eco altonato)
UPDATE `creature_template_addon` SET `aiAnimKit`=15056 WHERE `entry`=154990; -- 154990 (Mano de la oscuridad)
UPDATE `creature_template_addon` SET `aiAnimKit`=11333 WHERE `entry`=154064; -- 154064 (Axol Marnegro)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111345; -- 111345 (Conejito genérico)
UPDATE `creature_template_addon` SET `aiAnimKit`=13792 WHERE `entry`=154902; -- 154902 (Núcleo de poder del Vacío)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=145333; -- 145333 (Aprendiza shirakess)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=152462; -- 152462 (Emboscador cantaespín)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=153332; -- 153332
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=153812; -- 153812 (Acechador cantaespín)
UPDATE `creature_template_addon` SET `auras`='302302' WHERE `entry`=153804; -- 153804 (Encargado cantaespín)
UPDATE `creature_template_addon` SET `auras`='302302' WHERE `entry`=152460; -- 152460 (Cortador cantaespín)
UPDATE `creature_template_addon` SET `auras`='302302' WHERE `entry`=152461; -- 152461 (Cangrejo cantaespín)
UPDATE `creature_template_addon` SET `bytes1`=33554432, `auras`='299145' WHERE `entry`=152744; -- 152744 (Rompementes ancestro)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=153963; -- 153963 (Aletino esclavo mental)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='299814' WHERE `entry`=152274; -- 152274 (Múrloc sangraleta)
UPDATE `creature_template_addon` SET `aiAnimKit`=10965, `auras`='' WHERE `entry`=153545; -- 153545
UPDATE `creature_template_addon` SET `mount`=90763 WHERE `entry`=156265; -- 156265
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=152812; -- 152812 (Zoatroide)
UPDATE `creature_template_addon` SET `auras`='79865' WHERE `entry`=155761; -- 155761
UPDATE `creature_template_addon` SET `auras`='297990' WHERE `entry`=153333; -- 153333
UPDATE `creature_template_addon` SET `auras`='300931' WHERE `entry`=152710; -- 152710 (Oráculo de las profundidades necroaleta)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=0, `auras`='' WHERE `entry`=152884; -- 152884
UPDATE `creature_template_addon` SET `auras`='303477' WHERE `entry`=152671; -- 152671


UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=147550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=135401 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135800 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140015 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130190 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140005 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141482 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130189 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140013 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140011 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140016 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140010 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140018 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131272 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129749 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129753 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134426 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=143221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137094 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=135947 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137104 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130453 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=691, `VerifiedBuild`=38134 WHERE (`Entry`=147008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=147009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=147010 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=134963 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=144478 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130452 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135939 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134425 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132160 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130897 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132123 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132161 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132207 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129806 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=133203 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130073 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=133940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143035 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140595 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141586 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138739 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135171 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=134832 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138755 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136669 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137024 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136712 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=135600 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140577 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137041 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134967 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143592 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136708 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136165 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135389 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137049 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135367 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134937 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134930 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143914 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139981 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=61143 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134969 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135386 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=6271 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=135371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=135369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141853 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141855 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138167 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138168 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=135407 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135236 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139298 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142088 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139623 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138735 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139637 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139635 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136914 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138963 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142390 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135125 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142600 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=142586 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131337 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131338 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=138193 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=131342 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135405 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131314 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=773, `VerifiedBuild`=38134 WHERE (`Entry`=112192 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131301 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=131344 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141263 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141222 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=140518 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131778 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=131335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=131277 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131085 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=123236 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131409 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130823 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129980 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129972 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137944 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138938 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138095 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137505 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137110 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137576 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=137649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138092 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=137972 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=137974 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=137975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137971 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137065 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=137318 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137658 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135794 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137235 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137500 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136149 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137504 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=138453 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135848 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138546 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=143218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=137967 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=133405 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131361 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=150584 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126578 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141995 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139844 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139846 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131360 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143281 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138038 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143289 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=142455 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136498 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135457 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135785 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135814 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135511 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134450 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136439 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136591 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130094 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143038 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134721 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=142609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=134696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134723 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134631 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134747 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134623 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139973 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132163 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132619 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136337 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136157 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=134139 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=134417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=134173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=134137 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=136186 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=136188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141587 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=136249 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=136347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143143 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141046 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141047 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=139799 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=1223, `VerifiedBuild`=38134 WHERE (`Entry`=139800 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=137693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=135937 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141175 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142463 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142579 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142528 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137189 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137726 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137037 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=95464 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137215 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137202 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142515 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=129978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=149374 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142582 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130531 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=151187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=139209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=375, `VerifiedBuild`=38134 WHERE (`Entry`=145696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142601 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=141985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=141975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=137763 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=132007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142576 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142578 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142630 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142620 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142577 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=134350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=143219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=789, `VerifiedBuild`=38134 WHERE (`Entry`=155559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=155558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131663 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=789, `VerifiedBuild`=38134 WHERE (`Entry`=153393 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=142060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=73985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142184 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130819 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131387 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=142183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143034 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131404 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143033 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=708, `VerifiedBuild`=38134 WHERE (`Entry`=145239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142194 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142175 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134316 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141059 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141716 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141353 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141483 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141798 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141769 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=134704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=130005 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141064 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141123 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=139790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141315 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131600 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143361 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138081 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138005 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134359 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138006 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=138014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143041 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141479 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141518 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141512 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141506 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127739 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=149027 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126569 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139280 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129724 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=149025 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126708 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=124845 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129768 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129745 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=139624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137367 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133264 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=133210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134776 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126455 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129616 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133309 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=158148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=158221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129627 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=139089 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141991 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=131998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=140904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143718 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142754 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126581 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=126582 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142607 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142764 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142773 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142770 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=161565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142881 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142605 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=123210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142886 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142759 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=144493 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142885 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141771 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142767 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=755, `VerifiedBuild`=38134 WHERE (`Entry`=88696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143847 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142119 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142602 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143560 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142603 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=802, `VerifiedBuild`=38134 WHERE (`Entry`=138041 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=40, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=755, `VerifiedBuild`=38134 WHERE (`Entry`=88697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142760 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142778 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142771 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=140640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142608 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=125004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142772 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=135889 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=124883 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=141001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127193 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=140944 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126583 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=123641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=140936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=124238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143259 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=139375 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143242 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129001 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=713, `VerifiedBuild`=38134 WHERE (`Entry`=150208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=129940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=713, `VerifiedBuild`=38134 WHERE (`Entry`=150493 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151332 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151618 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=691, `VerifiedBuild`=38134 WHERE (`Entry`=145740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150361 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150362 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=149913 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=149911 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151671 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151848 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=691, `VerifiedBuild`=38134 WHERE (`Entry`=152529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151849 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151352 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153839 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=153772 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153364 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152971 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151617 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=154940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153900 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153147 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153027 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=152607 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154082 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=148475 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153896 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=150903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155890 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152411 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151719 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=145346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=148392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=152889 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=154907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=148391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151198 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154235 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151218 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154912 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=156262 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=150568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152717 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153025 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=154530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153524 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154247 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=153863 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=155907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154182 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154105 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152360 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=740, `VerifiedBuild`=38134 WHERE (`Entry`=154143 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152356 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=154234 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154911 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152358 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151557 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154865 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154863 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154864 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152357 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155807 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152532 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=154459 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152244 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=145339 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152362 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152262 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=152888 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153819 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152984 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154243 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=153757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154599 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154601 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155361 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155635 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=155210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154548 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154528 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=154595 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154509 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152716 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152397 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152069 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152164 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152161 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152297 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=149722 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154574 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155886 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152494 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152756 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152203 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154092 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151782 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152463 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155844 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152968 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=145343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153843 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153472 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=149709 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154064 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153315 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153329 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152787 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=152819 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=145333 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155727 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152724 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151774 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=5, `LevelScalingDeltaMax`=5, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153895 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152962 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153334 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154239 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=2 WHERE (`Entry`=145324 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154913 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152462 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153814 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155590 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152461 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154132 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154919 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152879 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155878 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154310 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153658 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154706 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153963 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=149752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=154707 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153959 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154910 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154921 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=54, `VerifiedBuild`=38134 WHERE (`Entry`=46303 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=46288 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=46290 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=46286 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155880 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155879 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153842 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153753 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153250 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=156110 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=156111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=155610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=153872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152273 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152989 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=152990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152274 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153818 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152275 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMin`=24, `LevelScalingDeltaMax`=24, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=154916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=40, `LevelScalingDeltaMax`=0, `ContentTuningID`=67, `VerifiedBuild`=38134 WHERE (`Entry`=152890 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152544 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154246 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153764 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154569 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=153762 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=153778 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=154194 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153537 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=153263 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=150819 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=145326 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152881 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152878 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=151534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152711 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=690, `VerifiedBuild`=38134 WHERE (`Entry`=152709 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81485;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=81712;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87342;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88683;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87217;
UPDATE `creature_model_info` SET `BoundingRadius`=1.240441441535949707, `CombatReach`=0.60000002384185791 WHERE `DisplayID`=81218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81370;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85773;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83296;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166421815752983093, `CombatReach`=0.60000002384185791 WHERE `DisplayID`=76482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81350;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81349;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=84064;
UPDATE `creature_model_info` SET `BoundingRadius`=0.332843631505966186, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=86543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895694732666015, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=84065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81369;
UPDATE `creature_model_info` SET `BoundingRadius`=0.235764175653457641, `CombatReach`=0.85000002384185791 WHERE `DisplayID`=72178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369618415832519, `VerifiedBuild`=38134 WHERE `DisplayID`=74789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369678020477294, `VerifiedBuild`=38134 WHERE `DisplayID`=86545;
UPDATE `creature_model_info` SET `BoundingRadius`=0.180290251970291137, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=72186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84464;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895739436149597, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=86546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=40905;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369618415832519, `VerifiedBuild`=38134 WHERE `DisplayID`=74486;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369678020477294, `VerifiedBuild`=38134 WHERE `DisplayID`=88674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895739436149597, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=86548;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84568;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85150;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=86531;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85152;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85145;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85149;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `VerifiedBuild`=38134 WHERE `DisplayID`=88695;
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765132904052734, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=83595;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85151;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `VerifiedBuild`=38134 WHERE `DisplayID`=88698;
UPDATE `creature_model_info` SET `BoundingRadius`=1.597905278205871582, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=4652;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=89475;
UPDATE `creature_model_info` SET `BoundingRadius`=1.462939262390136718, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=85208;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81987;
UPDATE `creature_model_info` SET `BoundingRadius`=0.168620049953460693, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=304;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84014;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=1964;
UPDATE `creature_model_info` SET `BoundingRadius`=3.124989748001098632, `CombatReach`=2 WHERE `DisplayID`=52738;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88566;
UPDATE `creature_model_info` SET `BoundingRadius`=1.817795515060424804, `CombatReach`=1.666666746139526367, `VerifiedBuild`=38134 WHERE `DisplayID`=81658;
UPDATE `creature_model_info` SET `BoundingRadius`=2.272244453430175781, `CombatReach`=2.083333492279052734, `VerifiedBuild`=38134 WHERE `DisplayID`=81688;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85206;
UPDATE `creature_model_info` SET `BoundingRadius`=1.148412346839904785, `VerifiedBuild`=38134 WHERE `DisplayID`=69;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `VerifiedBuild`=38134 WHERE `DisplayID`=85207;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88474;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84246;
UPDATE `creature_model_info` SET `BoundingRadius`=1.278324246406555175, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=88563;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82312;
UPDATE `creature_model_info` SET `BoundingRadius`=3.76745772361755371, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=86974;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88564;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88472;
UPDATE `creature_model_info` SET `BoundingRadius`=1.947340369224548339, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=87178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.15329095721244812, `VerifiedBuild`=38134 WHERE `DisplayID`=88469;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84626;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88470;
UPDATE `creature_model_info` SET `BoundingRadius`=1.866102457046508789, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=2305;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79091;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83799;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81713;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84241;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84401;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88312;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81374;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84661;
UPDATE `creature_model_info` SET `BoundingRadius`=0.724757254123687744, `CombatReach`=1.574999928474426269 WHERE `DisplayID`=79072;
UPDATE `creature_model_info` SET `BoundingRadius`=0.187199994921684265, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=84020;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79070;
UPDATE `creature_model_info` SET `BoundingRadius`=1.118828415870666503, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=6888;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83902;
UPDATE `creature_model_info` SET `BoundingRadius`=0.321299970149993896, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=88315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88517;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=83823;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84324;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85039;
UPDATE `creature_model_info` SET `BoundingRadius`=0.321299970149993896, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84017;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30212;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=221;
UPDATE `creature_model_info` SET `BoundingRadius`=0.191469371318817138, `VerifiedBuild`=38134 WHERE `DisplayID`=77053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=83993;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20000004768371582, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=39100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166933000087738037, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=43517;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=88501;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85049;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88310;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85059;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81373;
UPDATE `creature_model_info` SET `BoundingRadius`=0.166933000087738037, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=23949;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83998;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88506;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84660;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88504;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88518;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88479;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84685;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759269535541534423, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86071;
UPDATE `creature_model_info` SET `BoundingRadius`=0.191469371318817138, `VerifiedBuild`=38134 WHERE `DisplayID`=77044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88480;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84018;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167159661650657653, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=76516;
UPDATE `creature_model_info` SET `BoundingRadius`=0.695363521575927734, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=53092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.187199994921684265, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=84016;
UPDATE `creature_model_info` SET `BoundingRadius`=0.181832239031791687, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=85067;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84243;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84686;
UPDATE `creature_model_info` SET `BoundingRadius`=0.321299970149993896, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84239;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84238;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759269535541534423, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=83806;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87389;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81151;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83811;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84400;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83809;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82339;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85822;
UPDATE `creature_model_info` SET `BoundingRadius`=1.65618598461151123, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82340;
UPDATE `creature_model_info` SET `BoundingRadius`=1.10000002384185791, `CombatReach`=4.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86970;
UPDATE `creature_model_info` SET `BoundingRadius`=1.65618598461151123, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82338;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934719264507293701, `CombatReach`=1.154999971389770507, `VerifiedBuild`=38134 WHERE `DisplayID`=80402;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934719264507293701, `CombatReach`=1.154999971389770507 WHERE `DisplayID`=80322;
UPDATE `creature_model_info` SET `BoundingRadius`=0.286458432674407958, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=42859;
UPDATE `creature_model_info` SET `BoundingRadius`=1.301999926567077636, `CombatReach`=4.199999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=86895;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=3.415513038635253906, `CombatReach`=4.375, `VerifiedBuild`=38134 WHERE `DisplayID`=86218;
UPDATE `creature_model_info` SET `BoundingRadius`=0.490500271320343017, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76860;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84294;
UPDATE `creature_model_info` SET `BoundingRadius`=0.40299999713897705, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=85524;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86446;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=5572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83979;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83813;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86456;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.774999976158142089, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84725;
UPDATE `creature_model_info` SET `BoundingRadius`=3.732204914093017578, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=507;
UPDATE `creature_model_info` SET `BoundingRadius`=0.180000007152557373, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=87633;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5625, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=80256;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64495;
UPDATE `creature_model_info` SET `BoundingRadius`=2.123496532440185546, `CombatReach`=1.399999976158142089 WHERE `DisplayID`=72014;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67453;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32313;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81364;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88624;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81754;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81710;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85772;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=72183;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85766;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81756;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81715;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86708;
UPDATE `creature_model_info` SET `BoundingRadius`=2.146073341369628906, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=84037;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81718;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81716;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81724;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81766;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81720;
UPDATE `creature_model_info` SET `BoundingRadius`=1.648991703987121582, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=37370;
UPDATE `creature_model_info` SET `BoundingRadius`=0.948167622089385986, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=81433;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81719;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=81781;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86707;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86710;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81721;
UPDATE `creature_model_info` SET `BoundingRadius`=0.330480009317398071, `CombatReach`=1.620000123977661132, `VerifiedBuild`=38134 WHERE `DisplayID`=81783;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81714;
UPDATE `creature_model_info` SET `BoundingRadius`=4.282311916351318359, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=66815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81723;
UPDATE `creature_model_info` SET `BoundingRadius`=2.146073341369628906, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=29220;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81717;
UPDATE `creature_model_info` SET `BoundingRadius`=1.094039678573608398, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=31926;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=68679;
UPDATE `creature_model_info` SET `BoundingRadius`=0.911699652671813964, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=81432;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3921;
UPDATE `creature_model_info` SET `BoundingRadius`=0.226335421204566955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=71056;
UPDATE `creature_model_info` SET `BoundingRadius`=0.750786304473876953, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=82010;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=3908;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36992;
UPDATE `creature_model_info` SET `BoundingRadius`=0.842175483703613281, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=85414;
UPDATE `creature_model_info` SET `BoundingRadius`=1.800509214401245117, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=2598;
UPDATE `creature_model_info` SET `BoundingRadius`=0.857899487018585205, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86369;
UPDATE `creature_model_info` SET `BoundingRadius`=5.708419322967529296, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=85878;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=7238;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372094929218292236, `CombatReach`=0.349999994039535522, `VerifiedBuild`=38134 WHERE `DisplayID`=80365;
UPDATE `creature_model_info` SET `BoundingRadius`=0.857899487018585205, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86370;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=48318;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84240;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=85119;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77695;
UPDATE `creature_model_info` SET `BoundingRadius`=0.900000035762786865, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45883;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=4100;
UPDATE `creature_model_info` SET `BoundingRadius`=1.909722805023193359, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=83881;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85323;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=67535;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84293;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=86179;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84295;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=86533;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86397;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84296;
UPDATE `creature_model_info` SET `BoundingRadius`=1.275168180465698242, `CombatReach`=0.900000035762786865 WHERE `DisplayID`=1157;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83769;
UPDATE `creature_model_info` SET `BoundingRadius`=9.488919258117675781, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84851;
UPDATE `creature_model_info` SET `BoundingRadius`=3.225205183029174804, `CombatReach`=3.85000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=14701;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=87558;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83797;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83770;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=9829;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35424;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=35857;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84222;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=23183;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84396;
UPDATE `creature_model_info` SET `BoundingRadius`=0.297600001096725463, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=48625;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81784;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83768;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82890;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82892;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=87908;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=60855;
UPDATE `creature_model_info` SET `BoundingRadius`=0.794200003147125244, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=87856;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.297600001096725463, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=85634;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10038;
UPDATE `creature_model_info` SET `BoundingRadius`=0.490500271320343017, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76880;
UPDATE `creature_model_info` SET `BoundingRadius`=1.101600050926208496, `CombatReach`=5.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=80996;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381944209337234497, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=84517;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84355;
UPDATE `creature_model_info` SET `BoundingRadius`=2.900218009948730468, `CombatReach`=4.5 WHERE `DisplayID`=27849;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79041;
UPDATE `creature_model_info` SET `BoundingRadius`=0.601308226585388183, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=88700;
UPDATE `creature_model_info` SET `BoundingRadius`=0.546643853187561035, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88701;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84319;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79040;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88429;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.354190200567245483, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83643;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68093;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=52520;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68091;
UPDATE `creature_model_info` SET `BoundingRadius`=0.421299993991851806, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=68090;
UPDATE `creature_model_info` SET `BoundingRadius`=1.119720697402954101, `CombatReach`=2.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=982;
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983892440795898, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79404;
UPDATE `creature_model_info` SET `BoundingRadius`=0.149352252483367919, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=81663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216999992728233337, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=71828;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87006;
UPDATE `creature_model_info` SET `BoundingRadius`=2.637220382690429687, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=87014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=82001;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81203;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88681;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83273;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88680;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88625;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81202;
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983892440795898, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86175;
UPDATE `creature_model_info` SET `BoundingRadius`=1.477414846420288085, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=85042;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86306;
UPDATE `creature_model_info` SET `BoundingRadius`=2.101711750030517578, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.689460277557373046, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=85041;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `VerifiedBuild`=38134 WHERE `DisplayID`=88697;
UPDATE `creature_model_info` SET `BoundingRadius`=1.072822093963623046, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86349;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86308;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81283;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82103;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=81288;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86311;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81282;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88677;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88682;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88676;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=40075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84417;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84416;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84716;
UPDATE `creature_model_info` SET `BoundingRadius`=0.259999990463256835, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=79043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84637;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88636;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83304;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84638;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81779;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84714;
UPDATE `creature_model_info` SET `BoundingRadius`=0.213244944810867309, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=12191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.191409915685653686, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=74845;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164 WHERE `DisplayID`=83302;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.244999989867210388, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=86699;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82884;
UPDATE `creature_model_info` SET `BoundingRadius`=0.675633966922760009, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=87024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759269535541534423, `CombatReach`=1.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=84337;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164 WHERE `DisplayID`=83301;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=7763;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85203;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87142;
UPDATE `creature_model_info` SET `BoundingRadius`=3.625401735305786132, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=75702;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87143;
UPDATE `creature_model_info` SET `BoundingRadius`=1.399999976158142089, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=32024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85470;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85467;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85468;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88523;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85471;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88679;
UPDATE `creature_model_info` SET `BoundingRadius`=0.655972659587860107, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=85200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.491979449987411499, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=84083;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85204;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=85192;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32454;
UPDATE `creature_model_info` SET `BoundingRadius`=29.4013824462890625, `CombatReach`=5.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=32453;
UPDATE `creature_model_info` SET `BoundingRadius`=0.984943270683288574, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85040;
UPDATE `creature_model_info` SET `BoundingRadius`=0.984943270683288574, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85046;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86312;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86307;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599132537841796, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=85664;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `VerifiedBuild`=38134 WHERE `DisplayID`=31773;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75 WHERE `DisplayID`=87603;
UPDATE `creature_model_info` SET `BoundingRadius`=1.143827557563781738, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=85008;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85649;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82550;
UPDATE `creature_model_info` SET `BoundingRadius`=3.461216926574707031, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=33826;
UPDATE `creature_model_info` SET `BoundingRadius`=1.061711072921752929, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=83292;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88739;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=32455;
UPDATE `creature_model_info` SET `BoundingRadius`=0.342784821987152099, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=41463;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83548;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83547;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=87763;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=81966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=81964;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=57554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91805;
UPDATE `creature_model_info` SET `BoundingRadius`=0.191469371318817138, `VerifiedBuild`=38134 WHERE `DisplayID`=77050;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=88623;
UPDATE `creature_model_info` SET `BoundingRadius`=1.267880558967590332, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=57795;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=0.518964529037475585, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=30257;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70448;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75343;
UPDATE `creature_model_info` SET `BoundingRadius`=0.862806320190429687, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=81809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81198;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87370;
UPDATE `creature_model_info` SET `BoundingRadius`=1.32942509651184082, `CombatReach`=1.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=81269;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87590;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82003;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=75383;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87420;
UPDATE `creature_model_info` SET `BoundingRadius`=4.464169979095458984, `CombatReach`=5.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=40806;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77484;
UPDATE `creature_model_info` SET `BoundingRadius`=0.597794711589813232, `CombatReach`=0.660000026226043701, `VerifiedBuild`=38134 WHERE `DisplayID`=87421;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87218;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87344;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87456;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83820;
UPDATE `creature_model_info` SET `BoundingRadius`=0.647762596607208251, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=83698;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83808;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=80287;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81368;
UPDATE `creature_model_info` SET `BoundingRadius`=0.704809427261352539, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=87074;
UPDATE `creature_model_info` SET `BoundingRadius`=1.111697077751159667, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=63607;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81362;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75344;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.647762596607208251, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=83697;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84339;
UPDATE `creature_model_info` SET `BoundingRadius`=0.647762596607208251, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=83696;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82739;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82738;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82734;
UPDATE `creature_model_info` SET `BoundingRadius`=0.228800013661384582, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=81355;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85675;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81205;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85672;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85674;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78633;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81694;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64814;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81152;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85673;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82956;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85676;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85671;
UPDATE `creature_model_info` SET `BoundingRadius`=0.808565735816955566, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=86806;
UPDATE `creature_model_info` SET `BoundingRadius`=0.808565735816955566, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=86805;
UPDATE `creature_model_info` SET `BoundingRadius`=0.808565735816955566, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=86803;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79559;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79558;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383581817150115966, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78835;
UPDATE `creature_model_info` SET `BoundingRadius`=2.312455654144287109, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=45092;
UPDATE `creature_model_info` SET `BoundingRadius`=1.387473464012145996, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=79058;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80778;
UPDATE `creature_model_info` SET `BoundingRadius`=0.433400630950927734, `VerifiedBuild`=38134 WHERE `DisplayID`=70449;
UPDATE `creature_model_info` SET `BoundingRadius`=1.387473464012145996, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=79059;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759995520114898681, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=39726;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45491;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76858;
UPDATE `creature_model_info` SET `BoundingRadius`=0.596406757831573486, `CombatReach`=0.82500004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=80854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80751;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82954;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82955;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81744;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86287;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=47165;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85230;
UPDATE `creature_model_info` SET `BoundingRadius`=0.759269535541534423, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85232;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78195;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78193;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82780;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83866;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80747;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81745;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81746;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84086;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42744;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=92705;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78967;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64329;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42408;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81748;
UPDATE `creature_model_info` SET `BoundingRadius`=0.984943270683288574, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85045;
UPDATE `creature_model_info` SET `BoundingRadius`=2.296455860137939453, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=78928;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85348;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87678;
UPDATE `creature_model_info` SET `BoundingRadius`=2.392141342163085937, `CombatReach`=3.125, `VerifiedBuild`=38134 WHERE `DisplayID`=21936;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87924;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80846;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85214;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87687;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87909;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87928;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88073;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=94595;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87910;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87689;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87817;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78806;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87030;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88190;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=87182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87686;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87925;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88079;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88074;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87891;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88192;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61019;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88054;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=38626;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87685;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87684;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=61020;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88081;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87926;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88070;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86849;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87688;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78475;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88075;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88072;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78478;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80752;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87017;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85246;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81321;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88548;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78223;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75328;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75330;
UPDATE `creature_model_info` SET `BoundingRadius`=0.154382228851318359, `VerifiedBuild`=38134 WHERE `DisplayID`=75340;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88621;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79313;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78480;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83985;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78479;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78632;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84091;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80857;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82950;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82813;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86640;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87793;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=25073;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87792;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.34312865138053894, `CombatReach`=1.552500009536743164 WHERE `DisplayID`=83057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=82019;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=90661;
UPDATE `creature_model_info` SET `BoundingRadius`=1.180964350700378417, `CombatReach`=1.949999928474426269 WHERE `DisplayID`=82148;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=90788;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91524;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89128;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90192;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90729;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86470;
UPDATE `creature_model_info` SET `BoundingRadius`=0.720000028610229492, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=79153;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90932;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=48173;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4765;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4763;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=74005;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91650;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86462;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.89310389757156372, `CombatReach`=0.75 WHERE `DisplayID`=5561;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55913;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88619;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90958;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92561;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90702;
UPDATE `creature_model_info` SET `BoundingRadius`=1.462721943855285644, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=91241;
UPDATE `creature_model_info` SET `BoundingRadius`=4.211787700653076171, `CombatReach`=6, `VerifiedBuild`=38134 WHERE `DisplayID`=67258;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92456;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91519;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=0.5 WHERE `DisplayID`=60862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=0.5 WHERE `DisplayID`=81376;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90703;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90905;
UPDATE `creature_model_info` SET `BoundingRadius`=0.392066627740859985, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91652;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=92010;
UPDATE `creature_model_info` SET `BoundingRadius`=1.13358008861541748, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=90767;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81479;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3687286376953125, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=87364;
UPDATE `creature_model_info` SET `BoundingRadius`=1.202421903610229492, `CombatReach`=2.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=867;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2836;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77912;
UPDATE `creature_model_info` SET `BoundingRadius`=1.724785566329956054, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=90731;
UPDATE `creature_model_info` SET `BoundingRadius`=0.871984720230102539, `CombatReach`=1 WHERE `DisplayID`=90769;
UPDATE `creature_model_info` SET `BoundingRadius`=0.348793894052505493, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=90768;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77911;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.384999990463256835, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=92118;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92163;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91193;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=8783;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92166;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92164;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=92165;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91517;
UPDATE `creature_model_info` SET `BoundingRadius`=5.054145336151123046, `CombatReach`=7.200000286102294921 WHERE `DisplayID`=66811;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91393;
UPDATE `creature_model_info` SET `BoundingRadius`=0.871984720230102539, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=90765;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91400;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90762;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92650;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91398;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=92169;
UPDATE `creature_model_info` SET `BoundingRadius`=0.291572213172912597, `VerifiedBuild`=38134 WHERE `DisplayID`=92136;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91141;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91188;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91165;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91187;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90938;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91259;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91371;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=915;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67541;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91646;
UPDATE `creature_model_info` SET `BoundingRadius`=1.094039678573608398, `CombatReach`=1.5 WHERE `DisplayID`=91648;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=92102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=92100;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90487;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90484;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69610;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90486;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90533;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90485;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90483;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90532;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90491;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90493;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91479;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90488;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91370;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=39769;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10702;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91242;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91372;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91943;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91522;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90531;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92376;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90017;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90490;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92576;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=90944;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88870;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91883;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91885;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76258;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91965;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=74313;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=74319;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90852;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91369;
UPDATE `creature_model_info` SET `BoundingRadius`=2.779398918151855468, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=91294;
UPDATE `creature_model_info` SET `BoundingRadius`=3.186581373214721679, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91523;
UPDATE `creature_model_info` SET `BoundingRadius`=0.930000007152557373, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91766;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92173;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92132;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85054;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92504;
UPDATE `creature_model_info` SET `BoundingRadius`=1.279881715774536132, `CombatReach`=0.875, `VerifiedBuild`=38134 WHERE `DisplayID`=92133;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92131;
UPDATE `creature_model_info` SET `BoundingRadius`=4.00499582290649414, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=60652;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91926;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91720;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91927;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68973;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91721;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91021;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91029;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91025;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91866;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91864;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91863;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91028;
UPDATE `creature_model_info` SET `BoundingRadius`=2.627293348312377929, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91868;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91865;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91862;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91258;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92649;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92656;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91023;
UPDATE `creature_model_info` SET `BoundingRadius`=3.065819263458251953, `CombatReach`=3.75 WHERE `DisplayID`=29219;
UPDATE `creature_model_info` SET `BoundingRadius`=4.37882232666015625, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91870;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90988;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91924;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91101;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91092;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91100;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91022;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91091;
UPDATE `creature_model_info` SET `BoundingRadius`=1.539058923721313476, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=91257;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90763;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88872;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35017;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28468;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35010;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35009;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5305;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=22984;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72659;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=188;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=441;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92615;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92640;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=92685;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300864368677139282, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=91099;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.871984720230102539, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=90764;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91377;
UPDATE `creature_model_info` SET `BoundingRadius`=0.146379128098487854, `CombatReach`=0.1875 WHERE `DisplayID`=91487;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91095;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91235;
UPDATE `creature_model_info` SET `BoundingRadius`=0.522953331470489501, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=92161;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=55828;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875231742858886718, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=91572;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90034;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599132537841796, `CombatReach`=1.75 WHERE `DisplayID`=75374;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92642;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92646;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=91612;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91902;
UPDATE `creature_model_info` SET `BoundingRadius`=2.503405094146728515, `CombatReach`=2.5 WHERE `DisplayID`=65628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=2 WHERE `DisplayID`=31994;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=50760;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91638;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=8714;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.5 WHERE `DisplayID`=90522;
UPDATE `creature_model_info` SET `BoundingRadius`=0.360569238662719726, `CombatReach`=1.5 WHERE `DisplayID`=91110;
UPDATE `creature_model_info` SET `BoundingRadius`=3.656804800033569335, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=91240;
UPDATE `creature_model_info` SET `BoundingRadius`=0.068199999630451202, `CombatReach`=0.659999966621398925 WHERE `DisplayID`=90514;
UPDATE `creature_model_info` SET `BoundingRadius`=0.074400000274181365, `CombatReach`=0.719999969005584716 WHERE `DisplayID`=90512;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3 WHERE `DisplayID`=86646;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35043;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36060;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91649;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5187;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=50613;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91647;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58886;
UPDATE `creature_model_info` SET `BoundingRadius`=4.825957298278808593, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=65631;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91568;
UPDATE `creature_model_info` SET `BoundingRadius`=1.19080519676208496, `CombatReach`=1 WHERE `DisplayID`=4907;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=31539;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34352;
UPDATE `creature_model_info` SET `BoundingRadius`=0.500400006771087646, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=86464;
UPDATE `creature_model_info` SET `BoundingRadius`=2.299714088439941406, `CombatReach`=1.5 WHERE `DisplayID`=90733;
UPDATE `creature_model_info` SET `BoundingRadius`=0.750786304473876953, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=78242;


UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Pack
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=137658 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Pack
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=155902 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (147008,135391,143281,143289,141006,161565,153777,154522,151423,154528,154509,153315,153753)) OR (`ID`=3 AND `CreatureID` IN (138032,151534)) OR (`ID`=2 AND `CreatureID`=138032);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(147008, 1, 154988, 0, 0, 0, 0, 0, 0, 0, 0), -- Marlowe Lexvold
(135391, 1, 161122, 0, 0, 0, 0, 0, 0, 0, 0), -- Trabajador de La Rivera Muerta
(143281, 1, 70227, 0, 0, 0, 0, 0, 0, 0, 0), -- Scott Archeron
(138032, 3, 46089, 0, 0, 0, 0, 0, 0, 0, 0), -- Peón
(143289, 1, 61404, 0, 0, 0, 0, 0, 163524, 0, 0), -- Lohk Tótem Celestial
(138032, 2, 109579, 0, 0, 0, 0, 0, 0, 0, 0), -- Peón
(141006, 1, 3362, 0, 0, 0, 0, 0, 0, 0, 0), -- Dead Deckhand Leonard
(161565, 1, 155768, 0, 0, 155768, 0, 0, 0, 0, 0), -- Bragni
(153777, 1, 168165, 0, 0, 0, 0, 0, 0, 0, 0), -- Cando Mikaleta
(154522, 1, 45078, 0, 0, 0, 0, 0, 55048, 0, 0), -- Shandris Plumaluna
(151423, 1, 158650, 0, 0, 0, 0, 0, 0, 0, 0), -- Agente altonato
(154528, 1, 166269, 0, 0, 80580, 0, 0, 0, 0, 0), -- Eranor Birtris
(154509, 1, 25646, 0, 0, 0, 0, 0, 0, 0, 0), -- Varel Cantopan
(153315, 1, 167877, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(153753, 1, 128196, 0, 0, 0, 0, 0, 0, 0, 0), -- Esclavista zanj'ir
(151534, 3, 1908, 0, 0, 0, 0, 0, 0, 0, 0); -- Carroñero necroaleta

UPDATE `creature_equip_template` SET `ItemID1`=155780, `ItemID2`=155825 WHERE (`CreatureID`=132163 AND `ID`=1); -- Guardián de la marea Pontus
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=143572 AND `ID`=1); -- Matt Ferguson
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=143263 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=31824 WHERE (`CreatureID`=135678 AND `ID`=3); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=135678 AND `ID`=2); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=1906 WHERE (`CreatureID`=135678 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2200, `ItemID2`=52359 WHERE (`CreatureID`=152915 AND `ID`=2); -- Neófita azsh'ari
UPDATE `creature_equip_template` SET `ItemID1`=0, `ItemID2`=0 WHERE (`CreatureID`=152915 AND `ID`=1); -- Neófita azsh'ari
UPDATE `creature_equip_template` SET `ItemID1`=169084 WHERE (`CreatureID`=145324 AND `ID`=3); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=169022 WHERE (`CreatureID`=145324 AND `ID`=2); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=166998 WHERE (`CreatureID`=153250 AND `ID`=1); -- Acaparador Moarrgl
UPDATE `creature_equip_template` SET `ItemID1`=166994 WHERE (`CreatureID`=152274 AND `ID`=4); -- Múrloc sangraleta
UPDATE `creature_equip_template` SET `ItemID1`=166998 WHERE (`CreatureID`=152274 AND `ID`=3); -- Múrloc sangraleta
UPDATE `creature_equip_template` SET `ItemID1`=166995 WHERE (`CreatureID`=152274 AND `ID`=2); -- Múrloc sangraleta
UPDATE `creature_equip_template` SET `ItemID1`=60765 WHERE (`CreatureID`=152274 AND `ID`=1); -- Múrloc sangraleta
UPDATE `creature_equip_template` SET `ItemID1`=6680 WHERE (`CreatureID`=151534 AND `ID`=2); -- Carroñero necroaleta
UPDATE `creature_equip_template` SET `ItemID1`=166996 WHERE (`CreatureID`=151534 AND `ID`=1); -- Carroñero necroaleta

DELETE FROM `gossip_menu` WHERE (`MenuId`=24215 AND `TextId`=37924) OR (`MenuId`=24111 AND `TextId`=37768) OR (`MenuId`=24414 AND `TextId`=38315) OR (`MenuId`=24114 AND `TextId`=37781);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(24215, 37924, 38134), -- 153757 (Kelya Puestaluna)
(24111, 37768, 38134), -- 149722 (Noble altonato)
(24414, 38315, 38134), -- 152716 (Arylina)
(24114, 37781, 38134); -- 152407

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21917 AND `TextId`=33511); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21917 AND `TextId`=33511); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21917 AND `TextId`=33511); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21917 AND `TextId`=33511); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22339 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24217 AND `TextId`=37926); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=24215 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(24215, 0, 2, 'Muéstrame adónde puedo ir volando.', 0, 38134);



UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0 WHERE `entry`=138931; -- Poppers
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147550; -- Cosechador
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134752; -- Alcaldesa Roz
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=129, `RangeAttackTime`=0 WHERE `entry`=130786; -- Hobbs
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131004; -- Escudero Augusto III
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=135401; -- Lidiador de Estela de la Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141349; -- Henovalente
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141348; -- Dirk
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140002; -- Oby Joe
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138221; -- "Canalla" Buck
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135800; -- Hermana Lilyana
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140003; -- Jack
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137731; -- Targeting Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130694; -- Alcaldesa Roz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140015; -- Zach Ronrón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130190; -- Sargento Calvin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139999; -- Kyle Pataronson
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140005; -- Damargat
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140001; -- Kristy Miauret
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141482; -- Ciudadana de Presabrenna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130189; -- Defensor de Presabrenna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140012; -- Gary Gatner
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140013; -- Sara Miauns
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140014; -- Kevo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140007; -- Vick Garrín
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140008; -- Julión Juguetón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140011; -- Sarah Feral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140016; -- Collin Vomiti
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139994; -- Jim Wick
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137621; -- Jinete del viento bombardero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140009; -- Will Peludín
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140006; -- Grrin Miador
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139996; -- Paul Gatozarez
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140010; -- Josh Miauvarro
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140004; -- Colin Volgato
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140018; -- Jestray Pataswede
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131272; -- Aldeano de Presabrenna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129749; -- Bruto arrasador
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129753; -- Rebanacabezas sanguinario
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137730; -- Targeting Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134426; -- Técnico zapador
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143221; -- Crisopa violeta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137094; -- Granjero Max
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135947; -- Anillo de champiñones extraños
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137104; -- Asaltante orco
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=131709; -- Mozo de labranza mecanizado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130453; -- Humphrey
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131496; -- Capataz Hojacurva
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147008; -- Marlowe Lexvold
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33536 WHERE `entry`=147009; -- Mozo de labranza reparado
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33536 WHERE `entry`=147010; -- Mozo de labranza arruinado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131656; -- Maestro de canes Archibald
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=134963; -- Karla Buentiempo
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=144478; -- Pollo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=130452; -- Perro guardián fiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129884; -- Tierra temblorosa
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=129870; -- Maestro de jabalíes zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135939; -- Hablavides Ratha
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=129869; -- Comerraíces hambriento
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135940; -- Zarzas trepadoras
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=129906; -- Tunelador zarzalomo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=135684; -- Earthen Thrall
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=130075; -- Briarback Geomancer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=134425; -- Hulking Kraulguard
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132160; -- Maestra de las enredaderas Smagh
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130897; -- Capitán Espinafilada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135774; -- Sirviente vinculado a la tierra
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132123; -- Cosechador descompuesto
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129750; -- Hostigador zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132161; -- Maestra de las enredaderas Orgsteen
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=132207; -- Cápsula de zarzas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129806; -- Espinas enredadoras
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132226; -- Guardahorado zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133203; -- Thornshaping Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=130073; -- Briarback Lookout
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133940; -- Refuerzos zarzalomo
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143035; -- Valley Chicken
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141239; -- Osca el Ensangrentado
UPDATE `creature_template` SET `minlevel`=50, `faction`=3012, `RangeAttackTime`=0 WHERE `entry`=140595; -- Cazador Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142400; -- Carroñero del campo
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141586; -- Pollo del valle
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138757; -- Trabajadora
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=58237; -- Pellizcos
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134968; -- Felicity Noel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138739; -- Defensor de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135171; -- Madrug-A
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=134832; -- Malorian Buenviento
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138755; -- Irontide Slaver
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140021; -- Roselyn Gilbert
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136668; -- Anna Dutswin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136669; -- Terrance Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136670; -- Philip Haribul
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134720; -- Leo Shealds
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137024; -- Moxi Ganzúa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136712; -- Beau Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135600; -- Emma Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140577; -- Rupert Haribull
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137041; -- Emilia Bellocq
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134967; -- Pedro el Raro
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136768; -- Doty Haribull
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143592; -- Milford
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136708; -- Beuford Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136707; -- Eddie Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136740; -- Mordeki Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136165; -- Trabajador
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136711; -- Taddie Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136706; -- Becky Haribull
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137042; -- Beatriz Rupert
UPDATE `creature_template` SET `minlevel`=50, `faction`=3014, `RangeAttackTime`=0 WHERE `entry`=135389; -- Ron Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137049; -- Dardo Dosdedos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137044; -- Hannah Steel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135367; -- Grettle Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134937; -- Andy Nariz de pinza
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139984; -- Alexandria Reece
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3014, `RangeAttackTime`=0 WHERE `entry`=135783; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134930; -- Trabajador de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136709; -- Elmo Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134928; -- Trabajadora de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143914; -- Gilly Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138379; -- Kimberly Haribull
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139981; -- Cleo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139978; -- Venus
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0, `unit_flags`=33554944, `unit_flags2`=67110912 WHERE `entry`=61143; -- Mouse
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `npcflag`=1, `RangeAttackTime`=0 WHERE `entry`=134969; -- Tess Tomalin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138378; -- Peludín
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135386; -- Calik el Flacucho
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0, `unit_flags`=33554432, `unit_flags2`=67110912 WHERE `entry`=6271; -- Ratón
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=135371; -- Forzudo de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=135369; -- Forzuda de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=134636; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134666; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0 WHERE `entry`=141853; -- Rebecca Barnes
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141854; -- Jonathon Barnes
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141855; -- Susanna Barnes
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138167; -- Irontide Trickshot
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3012, `RangeAttackTime`=0 WHERE `entry`=134688; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138168; -- Irontide Coin Hauler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138789; -- Irontide Pillager
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136743; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138170; -- Irontide Cutthroat
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138212; -- Bravucón mareaférrea
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140666; -- Triturador mareaférrea
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142113; -- Cucaracha
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140464; -- Loro domesticado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140209; -- Guardia del ron dingue
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=135407; -- Tortuga hidrocoraza
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135236; -- Guardián hurgafango
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135526; -- Raymond
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=139298; -- Pinku'shon
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142610; -- Mula de carga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142088; -- Torbellino alado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139623; -- Miliciano herido
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138735; -- Felecia Gladstone
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139704; -- Kaela Godwin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139637; -- Cazadora agotada
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139635; -- Matthew Gandorian
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138924; -- Holger Nash
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142984; -- Jimmy Roarke
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136239; -- Piedra monolítica
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136914; -- Albatros picocéano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=138963; -- Madre del nido Acada
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=142390; -- Cachorro de Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=131697; -- Oso pardo de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `RangeAttackTime`=0, `unit_flags`=33555200, `dynamicflags`=0 WHERE `entry`=135662; -- Huevo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126677; -- Mantarraya comelino
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135125; -- Cataluchador zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142600; -- Refugiado de Brisamarina
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142586; -- Ingeniero de control de calidad Cole
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140551; -- Oficial Reynald
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139992; -- Kiki Castillo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131014; -- Rikal
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131337; -- Caballo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131338; -- Caballo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131001; -- Teniente Harris
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138210; -- Sargento segunda Cotner
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131003; -- Especialista Wembley
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139516; -- Samantha
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139517; -- Maxine
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=138193; -- Misty Koret
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131342; -- Jameson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135405; -- Bruto zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131314; -- Señor de las Mareas zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130824; -- Clamamares zeth'jir
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `RangeAttackTime`=0 WHERE `entry`=112192; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `RangeAttackTime`=0 WHERE `entry`=131301; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131343; -- William
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131344; -- Charlie
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131141; -- Guardián escamoso zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141263; -- Atacante zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131313; -- Clamamares zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=141222; -- Soldado del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131114; -- Obrero del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130867; -- Soldado del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140518; -- Aldeano de Brisamarina
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131778; -- Resaca zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131335; -- Soldado del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131277; -- Soldado del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131085; -- Señor de las Mareas zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123236; -- Cangrejo pasoveloz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131409; -- Soldado del batallón varado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130823; -- Doncella de las mareas zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129980; -- Anguila abisal
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129972; -- Shoalbreach Lance
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130822; -- Encantadora zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131084; -- Guardián de la marea zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137464; -- Andarríos arenero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137943; -- Gurtuk Durazón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137944; -- Anguila costera espinosa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139379; -- Emisaria zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134830; -- Koja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138938; -- Seabreaker Skoloth
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138095; -- Propagador de incendios de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137505; -- Mecánico de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137542; -- Mero sobrealimentado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137110; -- Propagador de incendios de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130809; -- Makrura caparasal
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137576; -- Conscriptos de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137649; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138092; -- Propagador de incendios de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137977; -- Soola Durazón
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138451; -- Maestro de cangrejos Daijo
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=137972; -- Mebbo
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=137974; -- Jande
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=137975; -- Oooki
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138093; -- Propagador de incendios de Ventura y Cía.
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135793; -- Coleccionista Tojo
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=137971; -- Trained Crab
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137065; -- Petrolero de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137968; -- Meekoo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=137318; -- Pergamino de vuelo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137658; -- Zooka
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135794; -- Foliosagaz Nola
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137080; -- Bote de aceite de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137668; -- Okada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137664; -- Tooka Durazón
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137667; -- Peachy
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137235; -- Charco de aceite
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135795; -- Toki
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137500; -- Propagador de incendios de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166656, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=136149; -- Matriarca hidrocoraza
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137504; -- Corresponsal de Ventura y Cía.
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=138453; -- Winkle
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137659; -- Bakuta Durazón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135848; -- Mena de pólvora negra
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138546; -- Excavador de minas
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143218; -- Papilio
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138793; -- Capataz Burlok
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138521; -- Técnico de minas
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `RangeAttackTime`=0 WHERE `entry`=137967; -- Acechador de túnel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=133405; -- General Purpose Bunny RMV
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141901; -- Abeja zumbadora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=142394; -- Torre de asedio
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141984; -- Belisangre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141994; -- Carnicero renegado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=131361; -- Guardia del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135391; -- Trabajador de La Rivera Muerta
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=150584; -- Trituradora saboteada
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126578; -- Merodeador de las profundidades
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141995; -- Cirujano renegado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=139844; -- Ingeniero goblin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=139846; -- Chamán marchito
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=131360; -- Guardia del batallón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143281; -- Scott Archeron
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138048; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=138038; -- Wooden "Horse"
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143289; -- Lohk Tótem Celestial
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=138032; -- Peón
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=138097; -- Muka Rompetormentas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142455; -- Bronco de la ribera
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136007; -- Imagen de Lord Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=136498; -- Taelia
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135985; -- Hablaolas Reid
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136313; -- Jerarca ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135418; -- Degollador velado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=135689; -- Garra inerte
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=135415; -- Umbral Hulk
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135457; -- Tempestad encantada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135585; -- Ascendiente ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135813; -- Jerarca ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135812; -- Guardián de la marea potenciado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33554432 WHERE `entry`=139526; -- Tormenta del vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135785; -- Presagista ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135814; -- Degollador velado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135593; -- Faro olvidado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135511; -- Jerarca ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130554; -- Guardián de la marea potenciado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142198; -- Zorro tocado por el Vacío
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130006; -- Partidario de Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134450; -- Can de sangre resucitado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130116; -- Mareasangre rabioso
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136439; -- Sabléfilo renegado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136591; -- Oso pardo de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139177; -- Marinero quebradizo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130094; -- Clamamares maresabio
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141006; -- Dead Deckhand Leonard
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141007; -- Corrupted Slime
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141002; -- Ellie Vern
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141008; -- Reanimated Kraken Tentacle
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131376; -- Abeja de la miel
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143038; -- Honey Bee
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134721; -- Revolucionario inquebrantable
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142634; -- Hermana Alison
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142609; -- Empleado Gareth
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=134696; -- Marla Paso Veloz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=134723; -- Tirador Corazón Veraz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134631; -- Marinero quebradizo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134747; -- Maresabio desertor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134623; -- Taelia
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139968; -- Saltamareas corrupto
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131857; -- Cañón barrilmarino
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139973; -- Saltamareas joven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=139571; -- Martillador tronaforjado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131862; -- Municiones tronaformadas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139803; -- Cañonero asesinado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132163; -- Guardián de la marea Pontus
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132619; -- Carpintero de barcos masacrado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136337; -- Guardián de la marea renegado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136157; -- Maresabio desertor
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134139; -- Templario del santuario
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600 WHERE `entry`=134417; -- Ritualista de las profundidades marinas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=134173; -- Gota animada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600 WHERE `entry`=134137; -- Beato
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600 WHERE `entry`=136186; -- Espiritualista maresabia
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136188; -- Alma esclava
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141585; -- Piojo marino
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141587; -- Rata
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600, `dynamicflags`=0 WHERE `entry`=136249; -- Elemental guardián
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=136347; -- Maresabio iniciado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143143; -- Hermano Wharris
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141048; -- Lesser Twisted Current
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141050; -- Mind Warper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=141046; -- Leana Darkwind
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141047; -- Lesser Charged Gale
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600, `dynamicflags`=0 WHERE `entry`=139799; -- Aprendiz Celaférreo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137691; -- Hermano Pike
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33600, `dynamicflags`=0 WHERE `entry`=139800; -- Aprendiz clamavendavales
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=137693; -- Corazón de vendaval
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142550; -- Gota animada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=135937; -- Guardián de las mareas
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143031; -- Shadowback Crawler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `RangeAttackTime`=0, `unit_flags`=33552 WHERE `entry`=142462; -- Marinera fascinada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=141177; -- Marinero fascinado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141175; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `RangeAttackTime`=0, `unit_flags`=33552 WHERE `entry`=142463; -- Marinero fascinado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142579; -- Hundidor caparapico
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142528; -- Reptador sombralomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137189; -- Vendaval cargado
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=136053; -- Samuel Williams
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137726; -- Conscripto despierto
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137037; -- Maresabio despierto
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137789; -- Zelote abisal
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142540; -- Buccino sombrío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137212; -- Profeta abisal
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=95464; -- Conejito AOI gigante - GJC [SOLO EN INSTANCIAS]
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137215; -- Zelote abisal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137202; -- Guardacasco caído
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137188; -- Corriente retorcida
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142515; -- Gaviota espuma de mar
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129978; -- Leviatán retorcido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=149374; -- FX Stalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142582; -- Saltamareas nariz de botella
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130531; -- Carpintero de barcos traidor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=151187; -- Acechador de efectos especiales
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130039; -- Cañonero salbrío
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139209; -- Tornado
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=145696; -- Shrine View
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142601; -- Sombriescamas aguahonda
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141985; -- Heraldo Zaxuthril
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141975; -- Trozo de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137763; -- Sacudidor coral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132007; -- Tormenta de vendavales
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142576; -- Inundación desatada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142578; -- Gota viva
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142630; -- Tortuga marina lomoescamas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142620; -- Cazador del la Gran Cala
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142577; -- Carroñero de caparazón duro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=139988; -- -Unknown-
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=134350; -- Cabra bebé
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=134349; -- Cabra montesa
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143219; -- Gracia de la Reina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3154, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=155559; -- Obrera mielomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3153, `BaseAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=155558; -- Cosechadora mielomo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131663; -- Miel fluida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=153393; -- Barry
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131793; -- Ancel Mildenhall
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134824; -- Enjambrista entrenado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=142060; -- Custodio de la colonia
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142170; -- Rata empapada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `RangeAttackTime`=0 WHERE `entry`=73985; -- Large AOI Bunny - GJC
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142184; -- Cervato de la ribera
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142195; -- Venado de la ribera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130819; -- Obrero agotado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131387; -- Zorro colacobre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142183; -- Cierva de la ribera
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143034; -- Vale Marmot
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131404; -- Capataz Scripps
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131412; -- Obrero encadenado
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=143033; -- Freshwater Crawler
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=145239; -- Vigía de las mareas inerte
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142194; -- Gaviota asustadiza
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134377; -- Halieto picosuave
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142175; -- Reptador de agua fresca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131693; -- Ermita de agua fresca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134316; -- Grulla de Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141059; -- Ceñogrís el Mentecato
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141696; -- Matriarca quijapétrea
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=141716; -- Cría quijapétrea
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141353; -- Empleado Ebert
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141483; -- Ciudadana de Presabrenna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141798; -- Worley
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141769; -- Marilyn Hood
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=134704; -- Anna Animacélica
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=130005; -- Conscripto de Estela de la Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141064; -- Liebre de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141641; -- Saurolisco quijapétrea
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141098; -- Explosión de madera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141123; -- Forzatormenta desatado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139790; -- Cuernodigno de Tierras Altas
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=141090; -- Mill Worker
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141315; -- Oveja
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131381; -- Liebre de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131600; -- Halcón de las Tierras Altas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143361; -- Hurón travieso
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138081; -- Mozo de labranza de Mildenhall
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137987; -- Inspector Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141313; -- Cabra de Crestalina
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137988; -- Comerciante de Tiragarde
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138005; -- Mula de comerciante
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134359; -- Castor dientudo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138008; -- Retador rabalero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138009; -- Grifo rabalero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138007; -- Pescadero puntanzuelo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138006; -- Caballo de carga puntanzuelo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138014; -- Leñador de Algerson
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137985; -- Centinela de Canto Tormenta
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143041; -- Inland Croaker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141479; -- Burly
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141518; -- Burly Jr.
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141512; -- Pokey
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141506; -- Timbo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127739; -- Cazador kultirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=149027; -- Madera llevada
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126569; -- Croador del continente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=139280; -- Sythian el Raudo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129670; -- Lyssa Xiloceladora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129724; -- Castor mascatroncos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=149025; -- Madera pesada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134308; -- Guardia forestal Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126708; -- Venado pezuñanoble
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126709; -- Cierva pezuñanoble
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133285; -- Cazador del lecho
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127626; -- Mordedor de agua fresca
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124845; -- Caballo kultirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129768; -- Invasor xilorrama
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=129745; -- Leñador enredado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129624; -- Rondador xilocolmillo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133459; -- Caballo de carga de Canto Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139434; -- Paracaidista Ort
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139624; -- Gran dracoleón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137367; -- Lindel el Ladrón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137369; -- Boris el silencioso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133264; -- Inspector de Vadoarlén
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=133210; -- Mariah McKee
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134776; -- Davey Atigrado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126455; -- Zorro Trotarriscos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129616; -- Marlowe Algerson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133187; -- Amarradero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133309; -- Trabajador de Vadoarlén
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=133659; -- Hank Mount Horsey Kill Credit
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126496; -- Cazarratones errante
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126824; -- Ardilla roja
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags3`=1, `VehicleId`=6889, `HoverHeight`=5 WHERE `entry`=158148; -- Telecóptero
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912, `unit_flags3`=32769 WHERE `entry`=158221; -- Pertrechos kultiranos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127636; -- Búho de Tiragarde
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=129627; -- Leñador de Algerson
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126530; -- Buccino del bajío
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=139089; -- Guardia de Vadoarlén
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141991; -- Saltamareas de Tiragarde
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=126434; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131998; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140904; -- Daniel Poole
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142564; -- Leedan Gustaf
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143718; -- Sacudidor sobrealimentado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142754; -- Mark Waligora
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=126581; -- Roughneck Rider
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=126582; -- Roughneck Rider
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142607; -- Charlotte Moore
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143572; -- Matt Ferguson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142764; -- "Juego limpio" JJ
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142773; -- Empleado Arboleda de Luz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142770; -- Kevin Tack
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161565; -- Bragni
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143574; -- Sarah Chispirruedas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142611; -- Cathy Lee
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142881; -- Martillo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142882; -- Bruto
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141066; -- Jay el Bardo de la Taberna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144029; -- Industrial de Aspafresno
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148904; -- Miles
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142605; -- Chris Pyle
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123210; -- Gaviota brisamarina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=142886; -- Joey "Salado" Birdman
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142759; -- Mónica Winters
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142777; -- Director Langton
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142774; -- Bodeguero Hinz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142884; -- Petey el maligno
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=144493; -- 7th Legion Marine
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142885; -- Bennie "Campeón" Watkins
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143336; -- Corsario contratado
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0 WHERE `entry`=143559; -- Gran mariscal Hojatemblorosa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141771; -- Marinero de cubierta de Aspafresno
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142767; -- Camarero Donlyuk
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=88696; -- Oficial Rumsfeld
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143847; -- Vidente marina Cristal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142119; -- Meeshers
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0 WHERE `entry`=141698; -- Kort Ceefer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142602; -- Rebecca Carmine
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0 WHERE `entry`=143560; -- Mariscal Gabriel
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142603; -- Colton Carmine
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144002; -- Maddie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138041; -- Hermandad de duelistas
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=88697; -- Oficial Mena de Hierro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142784; -- Drewdil Cervecero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142760; -- Camarera Aspen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142778; -- Riley Sullivander
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142771; -- Chef Patrick
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140640; -- Comandante Langton
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142608; -- Cahoots McBotas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125004; -- Noble kultirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142775; -- Camarero Vince
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142772; -- Organizador Graves
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135889; -- Obrero de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141009; -- Coronel Tenders
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124883; -- Carretilla kultirana
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=141001; -- Pollo de ciudad
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126640; -- Pollo majestuoso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127193; -- Comerciante de Boralus
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=140944; -- Kul Tiran Criminal
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126583; -- Liebre asustadiza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123641; -- Trabajador de Boralus
UPDATE `creature_template` SET `minlevel`=115, `maxlevel`=115, `RangeAttackTime`=0 WHERE `entry`=140936; -- Kul Tiran Executioner
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143040; -- Shack Crab
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124238; -- Pack Mule
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143259; -- Kayleigh Calder
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139375; -- Franklin el Borracho
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143248; -- Rebecca Lin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143242; -- Lewis Villamar
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135614; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=153932; -- Genn Greymane
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=138704; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135612; -- -Unknown-
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=140348; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129001; -- Grifo salvaje
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=122370; -- Cyrus Crestfall
UPDATE `creature_template` SET `minlevel`=50, `faction`=875, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=150208; -- Maestro manitas Sobrechispa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129940; -- Roko
UPDATE `creature_template` SET `gossip_menu_id`=22339 WHERE `entry`=124725; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=875, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=150493; -- Gina Cableado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2968, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=177193; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154245; -- Aprendiz Unato
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154915; -- Elderspawn of Nalaada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153833; -- Exploradora Nuevil
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154714; -- Bloodseeker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=151332; -- Cangrejo vibrante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=151381; -- Diente de tiburón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3148, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151618; -- Asme Perla Marina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33587520, `unit_flags2`=2048 WHERE `entry`=152567; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154208; -- Jonah Bajamar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145740; -- Tinitoa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=150369; -- Caparazón profundo esclavo mental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=150361; -- Aletina esclava mental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=150362; -- Aletino esclavo mental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2938, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=149913; -- Pez espinoso de cueva
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=150363; -- Gigante de mar esclavo mental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3148, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151614; -- Nevin Corazón de las Mareas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3148, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=149911; -- Pronk aliado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153042; -- Jowana Ronropez
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151671; -- Lenu Branquen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1695, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151848; -- Lor'themar Theron
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=152529; -- Caminaespíritus Ussoh
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=151849; -- Primera Arcanista Thalyssra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=151294; -- Bailarín cromático
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3148, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151352; -- Lily Bopip
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155822; -- Gormson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=151354; -- Shep
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_walk`=1.399999976158142089, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153839; -- Fathom Ray
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153772; -- Iina Branquiazul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153364; -- Explorador Marlin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2275, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152971; -- Inquisidor Ithriza
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=2 WHERE `entry`=152084; -- Mrrl
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67110912 WHERE `entry`=151617; -- Fertile Soil
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=154940; -- Blob Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153900; -- Sardina Lauray
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=153902; -- Tucel
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=150349; -- Blood Pool
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=6491; -- Ángel de la Resurrección
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=153147; -- Aprendiz Ukaro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=154936; -- Mordisqueador hambriento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=153055; -- Bruja de la tormenta azsh'ari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=153027; -- Defensor zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=151946; -- Baluarte zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=152607; -- FX Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=154082; -- Dispositivo arcano averiado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152915; -- Neófita azsh'ari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=148475; -- Vidente aleta negra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153999; -- Furiamarea desatada
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=152675; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152674; -- Manantial restaurador
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153896; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152676; -- Agua viviente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153685; -- Mari Lazaraleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153998; -- Marea brotamanantial
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_walk`=0.400000005960464477, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=150903; -- Luxaleta errante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=155890; -- Escondite de Poen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152558; -- Trotaarrecifes con percebes
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=16779264 WHERE `entry`=154702; -- Sandclaw Sunshell
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=129, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152411; -- Vidente kil'karrok
UPDATE `creature_template` SET `minlevel`=122, `maxlevel`=122, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=69208064 WHERE `entry`=151719; -- Voice in the Deeps
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=145346; -- Kil'karrok Commander
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=129, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=148392; -- Makrura kil'karrok
UPDATE `creature_template` SET `minlevel`=121, `maxlevel`=121, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=152414; -- Elder Unu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=129, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=152413; -- Garramartillo kil'karrok
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=60, `maxlevel`=60, `faction`=1732, `npcflag`=8193, `BaseAttackTime`=1700, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152889; -- Hirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=129, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152412; -- Chamán de mareas kil'karrok
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2142, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154907; -- Centinela ankoano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=129, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=148391; -- Carroñero kil'karrok
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=152516; -- Juice Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=151198; -- Gniden
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151750; -- Azotador coralino
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=152786; -- Oben Aletarena
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=154235; -- Cosechador Akaro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=151218; -- Baba voraz
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154912; -- Silence
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=152689; -- Gigante de mar capturado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=152534; -- Controlador impiadoso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3157, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=156262; -- Protector desencadenado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=152688; -- Aletino capturado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=152690; -- Caparazón profundo capturado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33587520, `unit_flags2`=2048 WHERE `entry`=152566; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=150568; -- Trotaarrecifes profundo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152 WHERE `entry`=152717; -- Fugitiva aletina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153025; -- Emorneth
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=154530; -- Luciérnaga acuática
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153524; -- Explorador Kleda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154247; -- Aprendiz Utapo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=152565; -- Trotaarrecifes de plataforma marina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152737; -- Rastreador Ikuto
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153863; -- Ekka Escarmesí
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=152066; -- Primera Arcanista Thalyssra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2773, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155907; -- Defensor desencadenado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154182; -- Boca de dragón destruido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154105; -- Profesora Elryna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152360; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153777; -- Cando Mikaleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2968, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=154143; -- Coleccionista Tojo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154422; -- Matriarca boca de dragón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152356; -- Boca de dragón venenoso
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=154234; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154911; -- Chomp
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=152366; -- Cadáver de trillanodonte fresco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=152379; -- Cadáver de mantarraya sondeadora fresco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152358; -- Terrofauces boca de dragón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152363; -- Boca de dragón salvaje
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1886, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154624; -- Sable de la noche espectral
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=154860; -- Feylana la domadora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `BaseAttackTime`=1333, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151557; -- Conjurador kaldorei
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154670; -- Sanya la Llorona
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=154865; -- Talaren Lingoargenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1886, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154863; -- Hipogrifo fantasma
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=80, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154522; -- Shandris Plumaluna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=154864; -- Traficante de dijes Rentala
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=152357; -- Cazador boca de dragón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=155636; -- Ciudadano altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=155807; -- Quel'dorei enloquecido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1927, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152532; -- Shirelle McFadden
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155611; -- Drell Bracken
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155606; -- Kramp't
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154459; -- Horde Vanguard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152244; -- Tirador certero altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145339; -- Boquilla
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2952, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152362; -- Devastador boca de dragón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152262; -- Tejehechizos altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `npcflag`=640, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=154875; -- Vanesh Vinatero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=154686; -- Tynala "Dedos ágiles"
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151423; -- Agente altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3146, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155902; -- Artesano Ironai
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=151545; -- Refugiado de Ara-Hinam
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=60, `maxlevel`=60, `faction`=1732, `npcflag`=8193, `BaseAttackTime`=1700, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152888; -- Orise
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152151; -- Portavoz shirakess
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152122; -- Profanador abisal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153819; -- Explorador escamapúas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2275, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152984; -- Haggronar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154243; -- Aprendiz Aonari
UPDATE `creature_template` SET `gossip_menu_id`=24215, `minlevel`=60, `maxlevel`=60, `faction`=3016, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153757; -- Kelya Puestaluna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3016, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154599; -- Corin Puestaluna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=154366; -- InvisBunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3016, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154601; -- Kelya Puestaluna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152919; -- Elementalista azsh'ari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3016, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=155361; -- Guardia de honor de Elun'alor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155635; -- Ciudadano altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=154547; -- Corin Puestaluna
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=155210; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154548; -- Taumaturga umbría Vixtris
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=155078; -- Espíritu disconforme
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=154528; -- Eranor Birtris
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=154595; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=154509; -- Varel Cantopan
UPDATE `creature_template` SET `gossip_menu_id`=24414, `minlevel`=50, `maxlevel`=50, `faction`=3016, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152716; -- Arylina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152071; -- Erudita altonata
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152070; -- Guardián altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33587520, `unit_flags2`=2099200 WHERE `entry`=152397; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152931; -- Aristócrata gregario
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152069; -- Mago altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152164; -- Elemental frenético
UPDATE `creature_template` SET `minlevel`=121, `maxlevel`=121, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=152416; -- Allseer Oma'kil
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152161; -- Alma enloquecida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `BaseAttackTime`=2000, `unit_flags2`=32768, `unit_flags3`=1 WHERE `entry`=152297; -- Flor de hondocoral
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152562; -- Trotaarrecifes decolorado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2757, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=149722; -- Noble altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3016, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154574; -- Kelya Puestaluna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154285; -- Altonato vengativo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=634, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152893; -- Eco altonato
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=155886; -- Lugar de Neri
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3016, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152494; -- Elycina Llamaestrellas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152756; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=152203; -- Lady Silazsi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154092; -- Cría de espiral profundo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153684; -- Aletandrua Branqui
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=151782; -- Baba voraz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=1500, `unit_flags2`=16779264 WHERE `entry`=152463; -- Moraprofundo cantaespín
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=94, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `dynamicflags`=128 WHERE `entry`=153687; -- Huevo de Espiral Profundo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=2.25 WHERE `entry`=152116; -- Ojo del corruptor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=155844; -- Aprendiz Anako
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=154075; -- Rastreador Kenji
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2275, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=152968; -- Gler'thogg
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145343; -- Serpiente espiral profundo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=1 WHERE `entry`=153893; -- Cosechador zoatroide
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=155585; -- Zoatroide inferior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152813; -- Zoatroide inferior
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153843; -- Retuercevacíos shirakess
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2099200 WHERE `entry`=154990; -- Mano de la oscuridad
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=153472; -- Cautivo tocado por el Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=149709; -- Cautivo aleta negra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152822; -- Aleta negra quebrado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=154287; -- Presencia inadvertida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=154064; -- Axol Marnegro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=153315; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=768 WHERE `entry`=154751; -- Trotaarrecifes torturado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=151789; -- Pearl Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=151786; -- Trotaarrecifes petrificado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2205, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=104859648, `unit_flags3`=1 WHERE `entry`=153329; -- Lady Zharessa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=152787; -- Moris Criz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=154902; -- Núcleo de poder del Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=152819; -- FX Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145333; -- Aprendiza shirakess
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=71305216 WHERE `entry`=155727; -- Leviatán fascinado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152724; -- Subyugador shirakess
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=154074; -- Orbe del Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67141632, `unit_flags3`=1 WHERE `entry`=151774; -- Pearl Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=67584 WHERE `entry`=154683; -- Rehén nazjatari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=102, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67176448, `unit_flags3`=1, `dynamicflags`=128, `VehicleId`=6768 WHERE `entry`=154680; -- Prisión acuática
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=4720640 WHERE `entry`=154992; -- Testigo oscuro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=153078; -- Mano de Azshara
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153895; -- Pez gallo abisal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2275, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152962; -- Comandante Sarj'eth
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=153334; -- Elemental del abismo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=154239; -- Rastreador Otaru
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=153080; -- Voz de la reina
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154913; -- Shadowspike Lurker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=152462; -- Emboscador cantaespín
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153814; -- Guillotina cantaespín
UPDATE `creature_template` SET `unit_flags`=536904512, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=153332; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153812; -- Acechador cantaespín
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=155590; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153804; -- Encargado cantaespín
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1363, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=152460; -- Cortador cantaespín
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152461; -- Cangrejo cantaespín
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153655; -- Guardián de las mareas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=154132; -- Crujefauces mareal
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154919; -- Voltgorger
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2275, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152879; -- Lady Naz'jess
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=71305216 WHERE `entry`=155878; -- Karybon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152906; -- Centurión zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153654; -- Guardián Scamavolt
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152882; -- Señor de las mareas zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33554432 WHERE `entry`=154312; -- Guardián escamoso zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33554432 WHERE `entry`=154310; -- Camorrista zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=154311; -- Mirmidón zanj'ir
UPDATE `creature_template` SET `minlevel`=122, `maxlevel`=122, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=153658; -- Shiz'narasz the Consumer
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=16779264 WHERE `entry`=154706; -- Chitterspine Skitterling
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33588032, `unit_flags2`=2099200 WHERE `entry`=152744; -- Rompementes ancestro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=6723 WHERE `entry`=153963; -- Aletino esclavo mental
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=149752; -- Spell Bunny
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=16779264 WHERE `entry`=154707; -- Quelípedo cantaespín
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=153936; -- Sobrestante Hajeer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432 WHERE `entry`=153959; -- Boca de dragón salvaje
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154910; -- Prince Wiggletail
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154921; -- Giant Opaline Conch
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=1073743872 WHERE `entry`=46303; -- CAÑERO
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872 WHERE `entry`=46288; -- Objetivo de láser
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=1073743872 WHERE `entry`=46290; -- Cañón de láser
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags2`=1073743872 WHERE `entry`=46286; -- Cohete
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=71305216, `VehicleId`=6815 WHERE `entry`=155880; -- Epicus Maximus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=33588032, `unit_flags2`=71305216, `VehicleId`=1177 WHERE `entry`=155879; -- Y un dinosaurio
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=3, `BaseAttackTime`=1700, `unit_flags`=32768, `unit_flags2`=16779264 WHERE `entry`=153884; -- Rey Mrgl-Mrgl
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=153842; -- Mgglurky
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=153753; -- Esclavista zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=18, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=153250; -- Acaparador Moarrgl
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=156110; -- Parroquiano múrloc
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156111; -- Glargh
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=4196352 WHERE `entry`=155610; -- Tiburón ballena
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=153872; -- Renacuajo sangraleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags3`=1, `VehicleId`=6747 WHERE `entry`=153758; -- Recolector de renacuajos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=152624; -- Rey Gakula
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33587520, `unit_flags2`=2048 WHERE `entry`=152568; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=18, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=152273; -- Clamamareas sangraleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=152989; -- Dexter
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=152985; -- Dani Branquiazul
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=152990; -- Valvabrillo pequeño
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=18, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152274; -- Múrloc sangraleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=153818; -- Cangrejo tenazario
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `speed_walk`=0.800000011920928955, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152275; -- Renacuajo sangraleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152542; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=25, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154916; -- Ravenous Scalespawn
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=152890; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2832, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152541; -- Merodeador crestacieno
UPDATE `creature_template` SET `unit_flags2`=34816 WHERE `entry`=153545; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2832, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152544; -- Trinchero de escamas del Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2832, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=152543; -- Hidra de escamas del Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=154238; -- Rastreador Akatani
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3144, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=154246; -- Aprendiz Inari
UPDATE `creature_template` SET `gossip_menu_id`=24114 WHERE `entry`=152407; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2773, `BaseAttackTime`=1000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153764; -- Arrugaleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=34816, `unit_flags3`=1 WHERE `entry`=154569; -- Ancla de algas
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153762; -- Dren Nautilan
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=60, `maxlevel`=60, `faction`=1732, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153778; -- Azuku
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=153296; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152812; -- Zoatroide
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=152067; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2938, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152553; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=24217 WHERE `entry`=153811; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=150101; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=151000; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=155940; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=151763; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=154640; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=154653; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=150087; -- Genn Greymane
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154194; -- Guardiaescamas zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3123, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=153537; -- Rlgmrr
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152684; -- Bola de relámpagos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=153263; -- Kritch
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152686; -- Vórtice atronador
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152687; -- Soldado rafagoso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152917; -- Alzatormentas azsh'ari
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=150819; -- Shipwrecked Soldier
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152683; -- Tempestad iracunda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=152685; -- Viento feroz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145326; -- Convocadora azsh'ari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152881; -- Guardián escamoso zanj'ir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=4196352 WHERE `entry`=152681; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=121, `maxlevel`=121, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=152682; -- Prince Vortran
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3124, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=152878; -- Refugiado perdido en las mareas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152710; -- Oráculo de las profundidades necroaleta
UPDATE `creature_template` SET `VehicleId`=6828 WHERE `entry`=156107; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=151534; -- Carroñero necroaleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152711; -- Atracador necroaleta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=152709; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=152884; -- -Unknown-

UPDATE `quest_template` SET `RewardMoney`=386100, `RewardBonusMoney`=92600, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=57301; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=57333; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56118; -- -Unknown-
UPDATE `quest_template` SET `QuestType`=2, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56095; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=56309; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56422; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56321; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=56239; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26546; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=26035; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56561; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409173; -- 409173
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392087; -- 392087
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392164; -- 392164
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=392150; -- 392150
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390467; -- 390467
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390273; -- 390273
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390206; -- 390206
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390203; -- 390203
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390200; -- 390200
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390199; -- 390199
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390676; -- 390676
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390675; -- 390675
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390674; -- 390674
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390568; -- 390568
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=266187; -- 266187
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=266741; -- 266741
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=266740; -- 266740


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=7);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=6);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392087 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392164 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390273 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390199 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390199 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390199 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390675 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390568 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390568 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56422 AND `Idx`=0);

UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=140005 AND `Idx`=0); -- Damargat
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=140006 AND `Idx`=0); -- Grrin Miador
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143221 AND `Idx`=0); -- Crisopa violeta
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=147010 AND `Idx`=0); -- Mozo de labranza arruinado
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=147009 AND `Idx`=0); -- Mozo de labranza reparado
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=144478 AND `Idx`=0); -- Pollo
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=135939 AND `Idx`=0); -- Hablavides Ratha
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=135940 AND `Idx`=0); -- Zarzas trepadoras
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=132160 AND `Idx`=0); -- Maestra de las enredaderas Smagh
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=135774 AND `Idx`=0); -- Sirviente vinculado a la tierra
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=132161 AND `Idx`=0); -- Maestra de las enredaderas Orgsteen
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143592 AND `Idx`=0); -- Milford
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=143914 AND `Idx`=0); -- Gilly Haribull
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=138168 AND `Idx`=0); -- Irontide Coin Hauler
UPDATE `creature_template_model` SET `DisplayScale`=1.049999952316284179 WHERE (`CreatureID`=138212 AND `Idx`=0); -- Bravucón mareaférrea
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=140666 AND `Idx`=0); -- Triturador mareaférrea
UPDATE `creature_template_model` SET `DisplayScale`=1.049999952316284179 WHERE (`CreatureID`=140209 AND `Idx`=0); -- Guardia del ron dingue
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=135526 AND `Idx`=0); -- Raymond
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=142088 AND `Idx`=0); -- Torbellino alado
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=136239 AND `Idx`=0); -- Piedra monolítica
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=131344 AND `Idx`=0); -- Charlie
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137464 AND `Idx`=0); -- Andarríos arenero
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=138938 AND `Idx`=0); -- Seabreaker Skoloth
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143218 AND `Idx`=0); -- Papilio
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=138793 AND `Idx`=0); -- Capataz Burlok
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=137967 AND `Idx`=0); -- Acechador de túnel
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142394 AND `Idx`=0); -- Torre de asedio
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=141994 AND `Idx`=0); -- Carnicero renegado
UPDATE `creature_template_model` SET `Probability`=0.75 WHERE (`CreatureID`=126578 AND `Idx`=0); -- Merodeador de las profundidades
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=141995 AND `Idx`=0); -- Cirujano renegado
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `Probability`=0 WHERE (`CreatureID`=143281 AND `Idx`=0); -- Scott Archeron
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `Probability`=0 WHERE (`CreatureID`=143289 AND `Idx`=0); -- Lohk Tótem Celestial
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=135985 AND `Idx`=0); -- Hablaolas Reid
UPDATE `creature_template_model` SET `DisplayScale`=2.25 WHERE (`CreatureID`=135415 AND `Idx`=0); -- Umbral Hulk
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=135457 AND `Idx`=0); -- Tempestad encantada
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=135785 AND `Idx`=0); -- Presagista ahogado
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=142198 AND `Idx`=0); -- Zorro tocado por el Vacío
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=141006 AND `Idx`=0); -- Dead Deckhand Leonard
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=141007 AND `Idx`=0); -- Corrupted Slime
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=139968 AND `Idx`=0); -- Saltamareas corrupto
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=139973 AND `Idx`=0); -- Saltamareas joven
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=139571 AND `Idx`=0); -- Martillador tronaforjado
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=131862 AND `Idx`=0); -- Municiones tronaformadas
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=141050 AND `Idx`=0); -- Mind Warper
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=141048 AND `Idx`=0); -- Lesser Twisted Current
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=141047 AND `Idx`=0); -- Lesser Charged Gale
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=137189 AND `Idx`=0); -- Vendaval cargado
UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=142540 AND `Idx`=0); -- Buccino sombrío
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=137212 AND `Idx`=0); -- Profeta abisal
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=137215 AND `Idx`=0); -- Zelote abisal
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582, `Probability`=0 WHERE (`CreatureID`=137202 AND `Idx`=0); -- Guardacasco caído
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=137188 AND `Idx`=0); -- Corriente retorcida
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=129978 AND `Idx`=0); -- Leviatán retorcido
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=141985 AND `Idx`=0); -- Heraldo Zaxuthril
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=142577 AND `Idx`=0); -- Carroñero de caparazón duro
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143219 AND `Idx`=0); -- Gracia de la Reina
UPDATE `creature_template_model` SET `DisplayScale`=2.5 WHERE (`CreatureID`=155559 AND `Idx`=0); -- Obrera mielomo
UPDATE `creature_template_model` SET `DisplayScale`=1.75 WHERE (`CreatureID`=155558 AND `Idx`=0); -- Cosechadora mielomo
UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=142175 AND `Idx`=0); -- Reptador de agua fresca
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=141059 AND `Idx`=0); -- Ceñogrís el Mentecato
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=141798 AND `Idx`=0); -- Worley
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=141641 AND `Idx`=0); -- Saurolisco quijapétrea
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=143361 AND `Idx`=0); -- Hurón travieso
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=139280 AND `Idx`=0); -- Sythian el Raudo
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=139624 AND `Idx`=0); -- Gran dracoleón
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=137369 AND `Idx`=0); -- Boris el silencioso
UPDATE `creature_template_model` SET `Probability`=0.25 WHERE (`CreatureID`=126496 AND `Idx`=0); -- Cazarratones errante
UPDATE `creature_template_model` SET `CreatureDisplayID`=84201 WHERE (`CreatureID`=158221 AND `Idx`=0); -- Pertrechos kultiranos
UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=126530 AND `Idx`=0); -- Buccino del bajío
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791, `Probability`=0 WHERE (`CreatureID`=140904 AND `Idx`=0); -- Daniel Poole
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=143718 AND `Idx`=0); -- Sacudidor sobrealimentado
UPDATE `creature_template_model` SET `Probability`=3 WHERE (`CreatureID`=143559 AND `Idx`=0); -- Gran mariscal Hojatemblorosa
UPDATE `creature_template_model` SET `Probability`=3 WHERE (`CreatureID`=143560 AND `Idx`=0); -- Mariscal Gabriel
UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=126640 AND `Idx`=0); -- Pollo majestuoso
UPDATE `creature_template_model` SET `Probability`=0.5 WHERE (`CreatureID`=126583 AND `Idx`=0); -- Liebre asustadiza
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143248 AND `Idx`=0); -- Rebecca Lin
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143259 AND `Idx`=0); -- Kayleigh Calder
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143242 AND `Idx`=0); -- Lewis Villamar
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=150208 AND `Idx`=0); -- Maestro manitas Sobrechispa
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=154915 AND `Idx`=0); -- Elderspawn of Nalaada
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=151617 AND `Idx`=0); -- Fertile Soil
UPDATE `creature_template_model` SET `CreatureDisplayID`=91141 WHERE (`CreatureID`=151423 AND `Idx`=0); -- Agente altonato
UPDATE `creature_template_model` SET `CreatureDisplayID`=5561, `Probability`=0 WHERE (`CreatureID`=154681 AND `Idx`=0); -- Orbe de los ahogados

DELETE FROM `gameobject_template` WHERE `entry` IN (294195 /*Fardo de dinamita*/, 326595 /*Diario de Arylina*/, 325759 /*Almeja insuflada con maná*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `IconName`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(294195, 10, 9539, 'questinteract', '', 1, 93, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 278791, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 63218, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 188, 38134), -- Fardo de dinamita
(326595, 3, 34062, 'questinteract', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96551, 0, 0, 0, 690, 38134), -- Diario de Arylina
(325759, 3, 33142, 'questinteract', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95778, 0, 0, 0, 690, 38134); -- Almeja insuflada con maná

UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296249; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293498; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296592; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296250; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296621; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296620; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296593; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296248; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296247; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296246; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296245; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295814; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295813; -- Taburete
UPDATE `gameobject_template` SET `type`=5, `Data0`=0, `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=295812; -- Taburete
UPDATE `gameobject_template` SET `type`=5, `Data0`=0, `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=295811; -- Taburete
UPDATE `gameobject_template` SET `type`=5, `Data0`=0, `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=295810; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294461; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296595; -- Mecedora
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296594; -- Mecedora
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296615; -- Mecedora
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295805; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278425; -- Saco de maíz
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296864; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295784; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295783; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295782; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296868; -- Taburete
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=286952; -- Cofre cubierto de liquen
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296862; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294209; -- Estufa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281892; -- [DNT] Toolbox
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281158; -- Herramientas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296866; -- Taburete
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=281887; -- Poción apestosa
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=281888; -- Olla de baba viscosa
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=291258; -- Cofre del tesoro pequeño
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=282448; -- Cartel "Se busca"
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295781; -- Estufa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296867; -- Taburete
UPDATE `gameobject_template` SET `Data1`=76261, `VerifiedBuild`=38134 WHERE `entry`=276621; -- Depósito rico en monalita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291052; -- Escombros interesantes
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291051; -- Escombros interesantes
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76260, `VerifiedBuild`=38134 WHERE `entry`=276620; -- Veta de plata de tormenta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295807; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295806; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295809; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295808; -- Silla
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=297071; -- Bolsa de monedas pequeña
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291077; -- Cofre cerrado de la Rivera Muerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291076; -- Montón de oro de la Rivera Muerta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=207253; -- BBQ goblin 01
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295731; -- Fuego
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=291078; -- Frasco mareaférrea
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295732; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295734; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295733; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295721; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295724; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280664; -- Muñeco de entrenamiento
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=287072; -- Desastre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295722; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295723; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296885; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295730; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295729; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295728; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295727; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295726; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295725; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296884; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295804; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295803; -- Taburete
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=293985; -- Se busca: Belisangre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296726; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296725; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296221; -- Hoguera
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=280619; -- Cofre reforzado con hierro antiguo
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=291089; -- Nido de Acada
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=291266; -- Cofre del tesoro pequeño
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=290127; -- Cofre tortollano
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=291136; -- Bidón de aceite
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279614; -- Jaula naga
UPDATE `gameobject_template` SET `displayId`=54482, `VerifiedBuild`=38134 WHERE `entry`=280035; -- Rifle
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280031; -- Paquete de lienzos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279587; -- Expositor de armas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295047; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295044; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295045; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296233; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293781; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293780; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293779; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295059; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295058; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293782; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295046; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279595; -- Sacos pesados
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=279594; -- Cargamento envuelto
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=281879; -- Trampa explosiva animada
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280033; -- Municiones
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280032; -- Bala de cañón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280028; -- Tonel de pólvora
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=292807; -- Estandarte zeth'jir
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=292813; -- Expositor de armas zeth'jir
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=281832; -- Faro de la marea
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280586; -- Huevo quebrado
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=290128; -- Cofre tortollano
UPDATE `gameobject_template` SET `ContentTuningId`=1228, `VerifiedBuild`=38134 WHERE `entry`=278677; -- Tablero de Hearthstone
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296727; -- Parrilla
UPDATE `gameobject_template` SET `ContentTuningId`=464, `VerifiedBuild`=38134 WHERE `entry`=291148; -- Bidón de aceite
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303015; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303014; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296906; -- Pergamino maresabio antiguo
UPDATE `gameobject_template` SET `ContentTuningId`=789, `VerifiedBuild`=38134 WHERE `entry`=328429; -- Depósito de jalea grande
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292836; -- Piedra de brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292834; -- Llama abisal
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=292828; -- Ícono abisal
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=301544; -- Muro de colisión
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=38134 WHERE `entry`=241914; -- Mesa ensangrentada
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298909; -- Cuero reforzado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298914; -- Colgante de caparazones arcoíris
UPDATE `gameobject_template` SET `ContentTuningId`=691, `VerifiedBuild`=38134 WHERE `entry`=322090; -- Dispositivo auditivo de la IV:7
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296905; -- Pergamino maresabio antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291043; -- Círculo ritual
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=291254; -- Cofre del tesoro pequeño
UPDATE `gameobject_template` SET `Data1`=0, `Data19`=2, `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=284448; -- Cofre de erudito oculto
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296591; -- Estufa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295117; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295116; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294274; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294273; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294272; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294268; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294267; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294266; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294265; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294264; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294263; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294262; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294261; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294260; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294259; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294258; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294257; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294256; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294255; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294254; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295124; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295123; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295122; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=284463; -- Sangre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=284453; -- Sangre
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=284472; -- Baúl
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296619; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296059; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=284465; -- Sombra residual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=284464; -- Charco sombrío
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=291132; -- Hueso
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296877; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294713; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294712; -- Estufa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294711; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=187376; -- NPC Fishing Bobber
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296845; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280587; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296853; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296848; -- Forja
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296844; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296843; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296842; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292545; -- Expositor de armas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=299009; -- Planta nerviosa
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=282256; -- Vacío
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280917; -- Vacío
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280912; -- Rueda de carreta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=280915; -- Vacío
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=282255; -- Vacío
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=291255; -- Cofre del tesoro pequeño
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=289538; -- Mareaqua hedionda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=301122; -- Pergamino maresabio antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296908; -- Pergamino maresabio antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=290414; -- Roca de encuentro
UPDATE `gameobject_template` SET `ContentTuningId`=708, `VerifiedBuild`=38134 WHERE `entry`=325418; -- Caldero hirviente
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=289574; -- Charco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288590; -- Tentáculo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288589; -- Tentáculo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288517; -- Charco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288430; -- Pergamino de las mareas
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=289537; -- Mareaqua hedionda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288522; -- Relámpago del Vacío
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=289536; -- Incensario de ritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292787; -- Bridge Visual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298910; -- Plantilla de paso ligero
UPDATE `gameobject_template` SET `Data1`=77461, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=278406; -- Banco de biajaibas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298915; -- Dosis de capacidad
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=291244; -- Cofre del tesoro pequeño
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298911; -- Blindaje de acero plegado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=299008; -- Magnetita cargada
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295799; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295798; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=298912; -- Púas con resortes
UPDATE `gameobject_template` SET `type`=5, `Data0`=0, `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=295800; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=296878; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278907; -- Ancla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278855; -- LOS HEREJES MORIRÁN
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=278506; -- Pila de troncos
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=293501; -- Forja
UPDATE `gameobject_template` SET `ContentTuningId`=188, `VerifiedBuild`=38134 WHERE `entry`=293500; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=290440; -- Barril de hidromiel
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294893; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294892; -- Silla
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76256, `VerifiedBuild`=38134 WHERE `entry`=276619; -- Veta de monalita
UPDATE `gameobject_template` SET `Data1`=77460, `VerifiedBuild`=38134 WHERE `entry`=278399; -- Banco de siluros del Mare Magnum
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294921; -- Hoguera
UPDATE `gameobject_template` SET `Data1`=77465, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=278402; -- Banco de percas de Tiragarde
UPDATE `gameobject_template` SET `Data1`=76248, `VerifiedBuild`=38134 WHERE `entry`=276617; -- Depósito de plata de tormenta
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=281420; -- Hoguera
UPDATE `gameobject_template` SET `Data1`=0, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281909; -- Hacha abandonada
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294927; -- Hoguera
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76062, `VerifiedBuild`=38134 WHERE `entry`=276234; -- Brote de río
UPDATE `gameobject_template` SET `IconName`='', `ContentTuningId`=186, `VerifiedBuild`=38134 WHERE `entry`=287404; -- Nido del lecho
UPDATE `gameobject_template` SET `IconName`='', `Data1`=76067, `ContentTuningId`=292, `VerifiedBuild`=38134 WHERE `entry`=281079; -- Musgo estelar
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294959; -- Brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294926; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294937; -- Silla
UPDATE `gameobject_template` SET `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=288641; -- SE BUSCA: Ladrones de grifos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294924; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294835; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294936; -- Silla
UPDATE `gameobject_template` SET `Data8`=1, `ContentTuningId`=189, `VerifiedBuild`=38134 WHERE `entry`=281230; -- Invitación formal
UPDATE `gameobject_template` SET `Data1`=76244, `VerifiedBuild`=38134 WHERE `entry`=276616; -- Depósito de monalita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303085; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294946; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295028; -- Banco
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=303010; -- Taburete
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=303012; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295765; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=303011; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295766; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=303013; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295470; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295759; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295461; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303005; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295758; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295776; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295775; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295774; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295773; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295770; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295769; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295768; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295767; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295763; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295762; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295761; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295760; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295757; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295756; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294903; -- Silla
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=38134 WHERE `entry`=297905; -- Cancionero de Jay
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295720; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295402; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295401; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294253; -- Fuego
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294248; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294247; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294246; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294245; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294244; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294243; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294242; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294241; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294240; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294239; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302995; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295777; -- Fuego
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295764; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295021; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=316675; -- Buzón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302998; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295719; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294904; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295718; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303007; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295467; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295717; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=301132; -- Olla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302996; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303009; -- Fuego
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303008; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303006; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303001; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302997; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295772; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295771; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295755; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295754; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295753; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294902; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294238; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294237; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303004; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302994; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295473; -- Taburete
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295471; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303003; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303002; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=303000; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=302999; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=301133; -- Olla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295487; -- Taburete
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295462; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294961; -- Brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294858; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295476; -- Taburete
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295486; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295415; -- Taburete
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295020; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294847; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294977; -- Brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294973; -- Brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294906; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294857; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294856; -- Silla
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295025; -- Banco
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295023; -- Banco
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295022; -- Banco
UPDATE `gameobject_template` SET `Data1`=2, `VerifiedBuild`=38134 WHERE `entry`=295024; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294905; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=294807; -- Silla
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295057; -- Fuego
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295049; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295048; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295052; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=295050; -- Taburete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=358375; -- Parche de nieve
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=321795; -- Cajón gnómico
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=321760; -- Paquete
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=321797; -- Caja de pergaminos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326130; -- Premio de diente de tiburón
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327203; -- Diario de Neri
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329796; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329801; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329800; -- Fogata
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329795; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329797; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329794; -- Banco
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326416; -- Cofre arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326419; -- Cofre arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326410; -- Cofre arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330173; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329642; -- Guijarro de entrada al antro
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=334100; -- Alijo arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=322533; -- Tomo de los elementos de Mardivas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327164; -- Almeja neptuliana
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325894; -- Alijo arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326406; -- Cofre arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326648; -- Perla imbuida
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=329895; -- Caída lenta
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330174; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325790; -- Caparazón decolorado
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326723; -- Santuario de Utama
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326408; -- Cofre arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326405; -- Cofre arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325420; -- Montón de pergaminos
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325869; -- Tonel vacío
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=325858; -- Brasero
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=322779; -- Popote gigante
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327226; -- Bayalga
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327225; -- Bayalga
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327221; -- Tonel de bayalgas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=325865; -- Guijarro de tonel
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327612; -- Bocado de carne
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326407; -- Cofre arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326240; -- Huevo de las profundidades eclosionado
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326239; -- Huevo de las profundidades
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332219; -- Suministros recuperados
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=216829; -- Saco de dormir
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327542; -- Bastón destrozado
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327543; -- Esfera rajada
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=322803; -- Bayalga
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=322791; -- Bayalga
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327514; -- Pilón de recuerdos
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327408; -- Pilón de recuerdos
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327439; -- Tallo marino expansible
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327583; -- Cofre anegado
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327426; -- Pilón de recuerdos
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327432; -- Pilón de recuerdos
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330178; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330176; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326402; -- Cofre arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327420; -- Yunque
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327419; -- Expositor de armas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=292865; -- Horde Crate (Scale 0.5)
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327592; -- Candado encantado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327619; -- Diario preservado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329614; -- Runa del vacío
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326015; -- Ícono de Azshara
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=325631; -- Cristal de comunicación
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327677; -- Mesa arruinada
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327628; -- Tarro de Corin
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327589; -- Dispositivo arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327676; -- Buzón
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325896; -- Cofre prístino
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325895; -- PULSAR EN CASO DE EMERGENCIA TELEMÁNTICA - O.
UPDATE `gameobject_template` SET `IconName`='quest', `unk1`='', `size`=1, `Data1`=22919, `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325853; -- Estantería vacía
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326401; -- Cofre arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=329740; -- Cuaderno altonato antiguo
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327613; -- Batidora arruinada
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327590; -- Huevo fosilizado
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327675; -- Olla de cocinero
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326404; -- Cofre arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=320935; -- Santuario arcaico
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326403; -- Cofre arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=205126; -- G_Book 01 Green
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=329738; -- Diario altonato antiguo
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=329784; -- Pilón arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332298; -- Cojín
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332296; -- Flores de coral verde
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332297; -- Flores de coral verde
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326650; -- Taza
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326125; -- Brasero diminuto
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=316816; -- Pelota
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288199; -- Botella de hidromiel
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326396; -- Baúl arcano reluciente
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325789; -- Escombros
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=245286; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327433; -- Espécimen inalterado
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332571; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326704; -- Dispositivo arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332574; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332575; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327257; -- Pergamino de los shirakess
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326721; -- Página del diario de Mardivas
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326026; -- Alijo del Vacío
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=328376; -- Pilón arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332568; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326397; -- Baúl arcano reluciente
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332573; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332569; -- Estatuilla de gato cristalina
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326590; -- Dispositivo arcano
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327158; -- Almeja neptuliana
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329907; -- Altar de la Maretista
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326057; -- Maretista de Golganneth
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=325892; -- Antorcha de luz profunda
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326724; -- Faro cantaespín
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=321756; -- Roca
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326395; -- Baúl arcano reluciente
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=328360; -- Pilón arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327268; -- Bastón de azerita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327267; -- Lanza de azerita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327266; -- Expositor de armas de azerita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327265; -- Expositor de armas de azerita
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326611; -- Tridente de azerita
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326216; -- Tridente de azerita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326720; -- Página del diario de Mardivas
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326148; -- Planes de ataque nagas
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=327132; -- Baúl arcano reluciente
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326398; -- Baúl arcano reluciente
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=322021; -- Aguas infestadas de anguilas
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326589; -- Dispositivo arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327185; -- Poste de cerca
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326706; -- Dispositivo arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332564; -- Jarra vacía
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332563; -- Jarra vacía
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326412; -- Cofre arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327434; -- Restos
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=326096; -- Molusco misterioso
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330194; -- Cristal prismático
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330159; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332218; -- Saco de dormir
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=332215; -- Barril
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=330180; -- Santuario funerario ankoano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293010; -- Caparazón
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=293009; -- Caparazón
UPDATE `gameobject_template` SET `ContentTuningId`=617, `VerifiedBuild`=38134 WHERE `entry`=267026; -- Escudo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=288149; -- Piedras misteriosas
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329799; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329790; -- Banco
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=329789; -- Banco
UPDATE `gameobject_template` SET `ContentTuningId`=690, `VerifiedBuild`=38134 WHERE `entry`=332221; -- Pilón arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326411; -- Cofre arcano
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=38134 WHERE `entry`=326413; -- Cofre arcano
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326614; -- Guijarro de entrada de la caverna

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (326595,325759));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(326595, 0, 168238, 38134), -- Diario de Arylina
(325759, 0, 168158, 38134); -- Almeja insuflada con maná

UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=290127 AND `Idx`=0); -- Cofre tortollano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=281832 AND `Idx`=0); -- Faro de la marea
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=290128 AND `Idx`=0); -- Cofre tortollano
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=281909 AND `Idx`=0); -- Hacha abandonada
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=326648 AND `Idx`=0); -- Perla imbuida
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=325420 AND `Idx`=0); -- Montón de pergaminos
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327221 AND `Idx`=0); -- Tonel de bayalgas
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=326239 AND `Idx`=0); -- Huevo de las profundidades
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327542 AND `Idx`=0); -- Bastón destrozado
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327543 AND `Idx`=0); -- Esfera rajada
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=322803 AND `Idx`=0); -- Bayalga
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=322791 AND `Idx`=0); -- Bayalga
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327583 AND `Idx`=0); -- Cofre anegado
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327257 AND `Idx`=0); -- Pergamino de los shirakess
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=327158 AND `Idx`=0); -- Almeja neptuliana
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=326611 AND `Idx`=0); -- Tridente de azerita
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=326216 AND `Idx`=0); -- Tridente de azerita


UPDATE `playerchoice_response` SET `ResponseIdentifier`=300 WHERE (`ChoiceId`=612 AND `ResponseId`=2283 AND `Index`=2);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=299 WHERE (`ChoiceId`=612 AND `ResponseId`=2282 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=298 WHERE (`ChoiceId`=612 AND `ResponseId`=2254 AND `Index`=0);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=285 WHERE (`ChoiceId`=612 AND `ResponseId`=2283 AND `Index`=2);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=284 WHERE (`ChoiceId`=612 AND `ResponseId`=2282 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=283 WHERE (`ChoiceId`=612 AND `ResponseId`=2254 AND `Index`=0);


UPDATE `page_text` SET `Text`='Aquí descansa el buscador Anewa, del clan Cuchilla marina\n\nIntentó encontrar respuestas a preguntas que aún no se habían hecho\n\nY asesinó a lo desconocido con la cuchilla de la sabiduría', `VerifiedBuild`=38134 WHERE `ID`=7986; -- 7986

DELETE FROM `npc_text` WHERE `ID` IN (37924 /*37924*/, 38315 /*38315*/, 37768 /*37768*/, 37781 /*37781*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(37924, 1, 0, 0, 0, 0, 0, 0, 0, 174681, 0, 0, 0, 0, 0, 0, 0, 38134), -- 37924
(38315, 1, 0, 0, 0, 0, 0, 0, 0, 177477, 0, 0, 0, 0, 0, 0, 0, 38134), -- 38315
(37768, 1, 1, 1, 1, 1, 0, 0, 0, 172596, 172597, 172599, 172600, 172601, 0, 0, 0, 38134), -- 37768
(37781, 1, 0, 0, 0, 0, 0, 0, 0, 172691, 0, 0, 0, 0, 0, 0, 0, 38134); -- 37781


UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=14127; -- 14127
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33511; -- 33511
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34299; -- 34299
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=37926; -- 37926

DELETE FROM `world_quest` WHERE `id` IN (55892 /*55892*/, 61565 /*61565*/, 58975 /*58975*/, 55970 /*55970*/, 60899 /*60899*/, 61539 /*61539*/, 54562 /*54562*/, 61136 /*61136*/, 60657 /*60657*/, 60384 /*60384*/, 61125 /*61125*/, 62286 /*62286*/, 51917 /*51917*/, 59804 /*59804*/, 62288 /*62288*/, 60991 /*60991*/, 61885 /*61885*/, 61346 /*61346*/, 60770 /*60770*/, 50936 /*50936*/, 54368 /*54368*/, 61815 /*61815*/, 61708 /*61708*/, 59234 /*59234*/, 60414 /*60414*/, 57328 /*57328*/, 57637 /*57637*/, 53963 /*53963*/, 51429 /*51429*/, 55340 /*55340*/, 62209 /*62209*/, 61868 /*61868*/, 59703 /*59703*/, 55215 /*55215*/, 56056 /*56056*/, 63044 /*63044*/, 61947 /*61947*/, 54620 /*54620*/, 60992 /*60992*/, 60990 /*60990*/, 59578 /*59578*/, 54600 /*54600*/, 54573 /*54573*/, 60654 /*60654*/, 58993 /*58993*/, 59717 /*59717*/, 61728 /*61728*/, 62210 /*62210*/, 59183 /*59183*/, 60574 /*60574*/, 57333 /*57333*/, 62241 /*62241*/, 62211 /*62211*/, 56648 /*56648*/, 54623 /*54623*/, 55304 /*55304*/, 61140 /*61140*/, 59019 /*59019*/, 45923 /*45923*/, 59230 /*59230*/, 59680 /*59680*/, 61784 /*61784*/, 58918 /*58918*/, 59441 /*59441*/, 54364 /*54364*/, 61540 /*61540*/, 60420 /*60420*/, 61124 /*61124*/, 60659 /*60659*/, 59827 /*59827*/, 45804 /*45804*/, 59599 /*59599*/, 62539 /*62539*/, 51854 /*51854*/, 52452 /*52452*/, 55846 /*55846*/, 55801 /*55801*/, 55719 /*55719*/, 55683 /*55683*/, 55625 /*55625*/, 54507 /*54507*/, 54665 /*54665*/, 54650 /*54650*/, 54662 /*54662*/, 56119 /*56119*/, 54449 /*54449*/, 53701 /*53701*/, 55898 /*55898*/, 55786 /*55786*/, 57334 /*57334*/, 57330 /*57330*/, 55982 /*55982*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(55892, 259200, 17584, 1), -- 55892
(61565, 86400, 19864, 1), -- 61565
(58975, 86400, 19451, 1), -- 58975
(55970, 86400, 17618, 1), -- 55970
(60899, 86400, 19523, 1), -- 60899
(61539, 86400, 19839, 1), -- 61539
(54562, 86400, 16876, 1), -- 54562
(61136, 86400, 19719, 1), -- 61136
(60657, 86400, 19426, 1), -- 60657
(60384, 259200, 19321, 1), -- 60384
(61125, 86400, 19718, 1), -- 61125
(62286, 604800, 20082, 3), -- 62286
(51917, 86400, 15578, 1), -- 51917
(59804, 86400, 19103, 1), -- 59804
(62288, 604800, 20083, 2), -- 62288
(60991, 86400, 19717, 1), -- 60991
(61885, 86400, 19965, 1), -- 61885
(61346, 86400, 19736, 1), -- 61346
(60770, 86400, 19457, 1), -- 60770
(50936, 86400, 14996, 1), -- 50936
(54368, 86400, 16760, 1), -- 54368
(61815, 604800, 19923, 3), -- 61815
(61708, 86400, 18289, 3), -- 61708
(59234, 86400, 18433, 1), -- 59234
(60414, 259200, 19329, 1), -- 60414
(57328, 86400, 19063, 1), -- 57328
(57637, 10281600, 13529, 1), -- 57637
(53963, 86400, 16483, 1), -- 53963
(51429, 86400, 15225, 1), -- 51429
(55340, 86400, 17280, 1), -- 55340
(62209, 86400, 20173, 1), -- 62209
(61868, 86400, 19956, 1), -- 61868
(59703, 86400, 18430, 2), -- 59703
(55215, 86400, 17211, 1), -- 55215
(56056, 604800, 17431, 1), -- 56056
(63044, 86400, 20279, 1), -- 63044
(61947, 86400, 19976, 1), -- 61947
(54620, 86400, 16908, 1), -- 54620
(60992, 86400, 19725, 1), -- 60992
(60990, 86400, 19721, 1), -- 60990
(59578, 86400, 18987, 1), -- 59578
(54600, 86400, 16890, 1), -- 54600
(54573, 86400, 16865, 1), -- 54573
(60654, 86400, 19423, 1), -- 60654
(58993, 86400, 19366, 2), -- 58993
(59717, 86400, 19020, 2), -- 59717
(61728, 86400, 19918, 1), -- 61728
(62210, 86400, 20174, 1), -- 62210
(59183, 86400, 19727, 1), -- 59183
(60574, 86400, 19374, 1), -- 60574
(57333, 43200, 18140, 1), -- 57333
(62241, 86400, 20060, 1), -- 62241
(62211, 86400, 20172, 1), -- 62211
(56648, 604800, 17934, 1), -- 56648
(54623, 86400, 16911, 1), -- 54623
(55304, 86400, 17262, 1), -- 55304
(61140, 86400, 20175, 1), -- 61140
(59019, 604800, 17934, 1), -- 59019
(45923, 21600, 13015, 1), -- 45923
(59230, 86400, 19726, 1), -- 59230
(59680, 86400, 19002, 1), -- 59680
(61784, 86400, 19942, 1), -- 61784
(58918, 86400, 19723, 1), -- 58918
(59441, 86400, 19721, 1), -- 59441
(54364, 86400, 16765, 1), -- 54364
(61540, 86400, 19841, 1), -- 61540
(60420, 259200, 19333, 1), -- 60420
(61124, 86400, 19720, 1), -- 61124
(60659, 86400, 19428, 1), -- 60659
(59827, 86400, 17592, 2), -- 59827
(45804, 21600, 13004, 1), -- 45804
(59599, 86400, 18972, 1), -- 59599
(62539, 86400, 20154, 1), -- 62539
(51854, 86400, 15541, 1), -- 51854
(52452, 86400, 15757, 1), -- 52452
(55846, 86400, 17857, 1), -- 55846
(55801, 86400, 17480, 1), -- 55801
(55719, 86400, 17441, 1), -- 55719
(55683, 86400, 17871, 1), -- 55683
(55625, 86400, 17878, 1), -- 55625
(54507, 25200, 16290, 1), -- 54507
(54665, 25200, 16290, 1), -- 54665
(54650, 25200, 16290, 1), -- 54650
(54662, 25200, 16290, 1), -- 54662
(56119, 259200, 17719, 1), -- 56119
(54449, 25200, 16290, 1), -- 54449
(53701, 25200, 16290, 1), -- 53701
(55898, 86400, 17581, 1), -- 55898
(55786, 86400, 17459, 1), -- 55786
(57334, 43200, 18136, 1), -- 57334
(57330, 43200, 18134, 1), -- 57330
(55982, 86400, 17630, 1); -- 55982

UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=46261; -- 46261
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44759; -- 44759
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=50316; -- 50316
UPDATE `world_quest` SET `duration`=10281600 WHERE `id`=47523; -- 47523
UPDATE `world_quest` SET `variable`=13004 WHERE `id`=44730; -- 44730

