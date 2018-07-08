DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryorguid` IN (5051, 5061, 5079, 5080);
DELETE FROM `areatrigger_teleport` WHERE `ID` IN (5051, 5061, 5079, 5080);
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5051, 5061, 5079, 5080);

INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5051, "at_voltarus"),
(5061, "at_voltarus"),
(5079, "at_voltarus"),
(5080, "at_voltarus");

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5332,5334,5338,5339,5340);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5332, "at_naxxanar"),
(5334, "at_naxxanar"),
(5338, "at_naxxanar"),
(5339, "at_naxxanar"),
(5340, "at_naxxanar");

