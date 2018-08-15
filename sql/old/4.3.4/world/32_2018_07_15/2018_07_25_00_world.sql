DELETE FROM `creature_equip_template` WHERE `CreatureID`= 1976 AND `ID`= 2;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(1976, 2, 1902, 0, 0); -- Stormwind City Patroller

UPDATE `creature_addon` SET `bytes2`=256 WHERE `guid`=313937;
UPDATE `waypoint_data` SET `action`=9 WHERE `id`=3139370 AND `point`=9;
DELETE FROM `waypoint_scripts` WHERE `id`=9;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(9, 7, 31, 2, 0, 0, 0, 0, 0, 0, 950),
(9, 9, 1, 234, 0, 0, 0, 0, 0, 0, 951),
(9, 14, 1, 0, 0, 0, 0, 0, 0, 0, 952),
(9, 16, 31, 1, 0, 0, 0, 0, 0, 0, 953);
