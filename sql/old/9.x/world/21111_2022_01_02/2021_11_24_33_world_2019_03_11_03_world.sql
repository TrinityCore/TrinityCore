-- 
DELETE FROM `creature` WHERE `guid` IN (78933) AND `id`=22484;
DELETE FROM `creature_addon` WHERE `guid` IN (78933);

DELETE FROM `creature_text` WHERE `CreatureID` = 22484;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(22484, 0, 0, "%s gathers the warp chaser's blood.", 16, 0, 100, 0, 0, 0, '	Zeppit', 20371);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22484 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2248400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22484, 0, 0, 0, 38, 0, 100, 0, 1, 1, 4000, 4000, 69, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zeppit - On data set - Move to position'),
(22484, 0, 1, 0, 34, 0, 100, 0, 8, 1, 0, 0, 80, 2248400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zeppit - On data set - Action list'),
(2248400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Zeppit - Action list - Say text'),
(2248400, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 39244, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Zeppit - Action list - Cast spell'),
(2248400, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Zeppit - Action list - Follow');
UPDATE `smart_scripts` SET `target_type`=11, `target_param2`=30 WHERE `entryorguid`=18884 AND `source_type`=0 AND `id`=3;
