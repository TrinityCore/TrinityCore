-- 
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5187, 5190);
INSERT INTO `areatrigger_scripts` VALUES
(5187, "SmartTrigger"),
(5190, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5187, 5190) AND `source_type`=2;
INSERT INTO `smart_scripts` VALUES
(5187, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 6150.7563, -1071.3817, 402.7154, 2.1916, "Areatrigger - On Trigger - Teleport"),
(5190, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 6314.1860, -1758.2946, 457.0714, 1.6787, "Areatrigger - On Trigger - Teleport");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceId`=2 AND SourceEntry IN (5187, 5190);
INSERT INTO `conditions` VALUES
(22, 1, 5187, 2, 0, 8, 0, 12821, 0, 0, 0, 0, 0, "", "Event requires quest rewarded"),
(22, 1, 5190, 2, 0, 8, 0, 12821, 0, 0, 0, 0, 0, "", "Event requires quest rewarded");
