-- NAXXANAR
-- AREATRIGGER-ID
-- SKY
-- 5338 roof
-- 5339 upper chamber
-- 5340 upper platform
-- 5334 lower platform
-- 5332 ground
-- GROUND
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5332,5334,5340,5339,5338);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5332, "SmartTrigger"),
(5334, "SmartTrigger"),
(5340, "SmartTrigger"),
(5339, "SmartTrigger"),
(5338, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryorguid` IN (5332,5334,5340,5339,5338);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5332, 2, 0, 0, 46, 0, 100, 0, 5332, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3733.68, 3563.25, 290.812, 3.6651, "Areatrigger - On Trigger - Teleport player"),
(5334, 2, 0, 0, 46, 0, 100, 0, 5334, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3802.38, 3585.95,  49.576,    0.0, "Areatrigger - On Trigger - Teleport player"),
(5340, 2, 0, 0, 46, 0, 100, 0, 5340, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3687.91, 3577.28, 473.342,    0.0, "Areatrigger - On Trigger - Teleport player"),
(5340, 2, 1, 0, 46, 0, 100, 0, 5340, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3744.80, 3570.65, 341.66,     0.6, "Areatrigger - On Trigger - Teleport player"),
(5339, 2, 0, 0, 46, 0, 100, 0, 5339, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3733.68, 3563.25, 290.812, 3.6651, "Areatrigger - On Trigger - Teleport player"),
(5338, 2, 0, 0, 46, 0, 100, 0, 5338, 0, 0, 0, 0, 62, 571, 0, 0, 0, 0, 0, 7, 0, 0, 0, 3733.68, 3563.25, 290.812, 3.6651, "Areatrigger - On Trigger - Teleport player");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (5332,5334,5340,5339,5338);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 5332, 2, 0, 8, 0, 12019, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Breaking Through turned in OR"),
(22, 1, 5332, 2, 1, 9, 0, 12019, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Breaking Through in the log OR"),
(22, 1, 5332, 2, 2,28, 0, 12019, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Breaking Through completed OR"),
(22, 1, 5332, 2, 3, 8, 0, 11898, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Last Rites turned in OR"),
(22, 1, 5332, 2, 4, 9, 0, 11898, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Last Rites in the log OR"),
(22, 1, 5332, 2, 5,28, 0, 11898, 0, 0, 0, 0, 0, "", "SAI areatrigger 5332 requires quest Last Rites completed OR"),
(22, 1, 5340, 2, 0, 6, 0, 469, 0, 0, 0, 0, 0, "", "SAI areatrigger 5340.0 triggers only if player is alliance"),
(22, 2, 5340, 2, 0, 6, 0,  67, 0, 0, 0, 0, 0, "", "SAI areatrigger 5340.1 triggers only if player is horde");

-- VOLTARUS
-- BUNNY-GUID AREATRIGGER-ID SPELL-ID
-- SKY
-- 114831 5080 52089
-- 114830 5079 52676
-- 114829 5061 52239
-- 114832 5051 52089
-- GROUND

-- Drakuramas Teleport Bunnies should not move or spawn of center
UPDATE creature
SET spawndist = 0, MovementType = 0
WHERE id = 28617;

DELETE FROM `areatrigger_teleport` WHERE `ID` IN (5051, 5061, 5079, 5080);
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5051, 5061, 5079, 5080);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5051, "SmartTrigger"),
(5061, "SmartTrigger"),
(5079, "SmartTrigger"),
(5080, "SmartTrigger");

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryorguid` IN (5051, 5061, 5079, 5080);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5051, 2, 0, 0, 46, 0, 100, 0, 5051, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 114832, 28617, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Set Data 1 1"),
(5061, 2, 0, 0, 46, 0, 100, 0, 5061, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 114829, 28617, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Set Data 1 1"),
(5079, 2, 0, 0, 46, 0, 100, 0, 5079, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 114830, 28617, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Set Data 1 1"),
(5080, 2, 0, 0, 46, 0, 100, 0, 5080, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 114831, 28617, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Set Data 1 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (5051, 5061, 5079, 5080);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 5051, 2, 0, 1, 0, 51966, 0, 0, 0, 0, 0, "", "SAI areatrigger 5051 triggers only if player has aura Scourge Disguise"),
(22, 1, 5061, 2, 0, 1, 0, 51966, 0, 0, 0, 0, 0, "", "SAI areatrigger 5061 triggers only if player has aura Scourge Disguise"),
(22, 1, 5079, 2, 0, 1, 0, 51966, 0, 0, 0, 0, 0, "", "SAI areatrigger 5079 triggers only if player has aura Scourge Disguise"),
(22, 1, 5079, 2, 0, 2, 0, 39319, 1, 0, 0, 0, 0, "", "SAI areatrigger 5079 triggers only if player has item Scepter of Domination"),
(22, 1, 5080, 2, 0, 1, 0, 51966, 0, 0, 0, 0, 0, "", "SAI areatrigger 5080 triggers only if player has aura Scourge Disguise");

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (-114832, -114829, -114830, -114831);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-114832, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 11, 52089, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, "Drakuramas Teleport Bunny 01 - On Data Set 1 1 - Cast 'Drakuramas Teleport Script 01'"),
(-114829, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 11, 52239, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, "Drakuramas Teleport Bunny 01 - On Data Set 1 1 - Cast 'Drakuramas Teleport Script 02'"),
(-114830, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 11, 52676, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, "Drakuramas Teleport Bunny 01 - On Data Set 1 1 - Cast 'Drakuramas Teleport Script 03'"),
(-114831, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 11, 52089, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, "Drakuramas Teleport Bunny 01 - On Data Set 1 1 - Cast 'Drakuramas Teleport Script 01'");

