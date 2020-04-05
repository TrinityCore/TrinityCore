-- 
DELETE FROM `areatrigger_scripts` WHERE  `entry` IN (5628,5629,5630,5631);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5628, "SmartTrigger"), (5629, "SmartTrigger"), (5630, "SmartTrigger"), (5631, "SmartTrigger");
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5628,5629,5630,5631) AND `source_type` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (37230) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`,`target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5628, 2, 0, 0, 46, 0, 100, 0, 5628, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 45828, 37230, 0, 0, 0, 0, 0, 0,'On Trigger - Set Data'),
(5629, 2, 0, 0, 46, 0, 100, 0, 5629, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 45827, 37230, 0, 0, 0, 0, 0, 0,'On Trigger - Set Data'),
(5630, 2, 0, 0, 46, 0, 100, 0, 5630, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 45829, 37230, 0, 0, 0, 0, 0, 0,'On Trigger - Set Data'),
(5631, 2, 0, 0, 46, 0, 100, 0, 5631, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 45830, 37230, 0, 0, 0, 0, 0, 0,'On Trigger - Set Data'),
(37230, 0, 0, 0, 25, 0, 100, 542, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - on Reset - Set invisible"),
(37230, 0, 1, 2, 38, 0, 100, 543, 1, 1, 5000, 5000, 1, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - On data set - SET visible"),
(37230, 0, 2, 0, 61, 0, 100, 543, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 80, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - On data set - Start Attack"),
(37230, 0, 3, 0, 4, 0, 100, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - On aggro - Say text"),
(37230, 0, 4, 0, 33, 0, 100, 543, 100, 30000, 0, 0, 0, 91, 2, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - On target damaged - Remove Flag Hover"),
(37230, 0, 5, 0, 0, 0, 100, 30, 10000, 13000, 13000, 16000, 0, 11, 70362, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - IC - Cast Blizzard"),
(37230, 0, 6, 0, 0, 0, 100, 30, 8000, 10000, 3000, 6000, 0, 11, 70361, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - IC - Cast Cleave"),
(37230, 0, 7, 0, 0, 0, 100, 30, 13000, 15000, 6000, 9000, 0, 11, 70116, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Spire Frostwyrm - IC - Cast Frost Breath");
