SET @CGUID := 52390;

UPDATE `smart_scripts` SET `event_type`=7 WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=17 AND `link`=18;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=16 AND `link`=17;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=8 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=1, `event_param3`=60000, `event_param4`=90000 WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `event_type`=4 WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=3 AND `link`=4;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28083 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=11832 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=1183201 AND `source_type`=9 AND `id`=0 AND `link`=0;

DELETE FROM `creature_template_addon` WHERE `entry` IN(19698,23383,19671);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(19698, 0, 0x10008, 0x1, ''), -- 19698
(23383, 0, 0x0, 0x1, ''), -- 23383
(19671, 0, 0x0, 0x101, ''); -- 19671

DELETE FROM `creature` WHERE `id` IN(19698,23383);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 19698, 530, 1, 1,  -3345.276, 5189.063, -100.9659, 5.77704, 120, 0, 0), -- 19698 (Area: 3519)
(@CGUID+1, 23383, 530, 1, 1,  -3664.54, 3389.79, 312.952, 2.356194, 120, 0, 0); -- 23383 (Area: 3519)

DELETE FROM `event_scripts` WHERE `id`=17209 AND `command`=8;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(17209, 1, 8, 27995, 1, 0, 0, 0, 0, 0);
