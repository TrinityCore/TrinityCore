DELETE FROM `creature_template_difficulty` WHERE (`Entry`=232536 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(232536, 0, 0, 1, 1, 0, 0x0, 0); -- Timbered Air Snakelet

DELETE FROM `creature_template` WHERE `entry`=232536;
INSERT INTO `creature_template` (`entry`, `Civilian`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `Classification`, `family`, `type`, `PetSpellDataId`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(232536, 1, 0, 0, 'Timbered Air Snakelet', NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0, 0, 12, 0, 0, 121, 58558); -- Timbered Air Snakelet

DELETE FROM `creature_template_model` WHERE (`CreatureID`=232536 AND `Idx`=0);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(232536, 0, 123452, 1, 1, 58558); -- Timbered Air Snakelet
