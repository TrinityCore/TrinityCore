--
UPDATE `creature` SET `position_x`=5832.238, `position_y`=564.013611, `position_z`=651.771301, `Orientation`=2.596493 WHERE `guid`=105661;
UPDATE `creature_addon` SET `auras`=60191 WHERE `guid` IN (105661, 103039);
DELETE FROM `creature_addon` WHERE `guid` IN (115295, 48251,48252,48253);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES 
(115295,65536,1,60191),
(48251,65536,1,60190),
(48252,65536,1,60190),
(48253,65536,1,60190);

DELETE FROM `creature` WHERE `guid` IN (48251,48252,48253);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `Orientation`, `spawntimesecs`) VALUES
(48251, 31851, 571, 1, 1, 5832.240, 564.0139, 651.77099, 2.596490,300),
(48252, 32335, 571, 1, 1, 5833.799, 567.3480, 651.92498, 2.460910,300),
(48253, 32206, 571, 1, 1, 5836.709, 570.0759, 652.10797, 2.146750,300);
