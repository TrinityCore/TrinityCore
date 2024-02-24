UPDATE `areatrigger_template` SET `VerifiedBuild`=53040 WHERE (`Id`=5802 AND `IsCustom`=0);
UPDATE `areatrigger_create_properties` SET `VerifiedBuild`=53040 WHERE (`Id`=1489 AND `IsCustom`=0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=5802 AND `IsCustom`=0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES 
(5802, 0, 1, 81782, 1);
