-- 
UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `unit_flags`=537133824 WHERE `guid` IN (103024, 103025, 103026, 103027, 103028);

DELETE FROM `creature_addon` WHERE `guid` IN (103024, 103025, 103026, 103027, 103028);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(103024, 0, 0x0, 0x1, '29266'), -- 25680 - 29266 - 29266
(103025, 0, 0x0, 0x1, '29266'), -- 25680 - 29266 - 29266
(103026, 0, 0x0, 0x1, '29266'), -- 25680 - 29266 - 29266
(103027, 0, 0x0, 0x1, '29266'), -- 25680 - 29266 - 29266
(103028, 0, 0x0, 0x1, '29266'); -- 25680 - 29266 - 29266

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=29546;

DELETE FROM `creature_template_addon` WHERE `entry` IN (24196, 29546);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(24196, 0, 0x0, 0x1, '29266'), -- 24196 - 29266
(29546, 0, 0x0, 0x1, '29266'); -- 29546 - 29266

DELETE FROM `creature_addon` WHERE `guid`=105491;
