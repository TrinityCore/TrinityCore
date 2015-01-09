DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (49555, 49380, 49381);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49555, 49555, 59807),
(49380, 49380, 59803),
(49381, 49381, 59805);

UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=27724;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (27709,27753,27754));
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(127478, 0, 0x0, 0x1, '31261'),
(127479, 0, 0x0, 0x1, '31261'),
(127517, 0, 0x0, 0x1, '31261'),
(127518, 0, 0x0, 0x1, '31261'),
(127519, 0, 0x0, 0x1, '31261'),
(127528, 0, 0x0, 0x1, '31261'),
(127539, 0, 0x0, 0x1, '31261');

DELETE FROM `creature` WHERE `guid` > 127479 AND `guid` < 127489;
DELETE FROM `creature` WHERE `guid` > 127519 AND `guid` < 127539 AND `guid` != 127528;

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (27709,27753,27754);

UPDATE `creature_template` SET `faction_A`=1693, `faction_H`=1693, `unit_flags`=768, `InhabitType`=5 WHERE `entry` IN (27709,27753,27754);
UPDATE `creature_template` SET `ScriptName` = 'npc_drakkari_invader' WHERE `entry` IN (27709,27753,27754);

DELETE FROM `creature_template_addon` WHERE `entry` IN (27709,27753,27754);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(27709, 26751, 0x0, 0x1, NULL),
(27753, 26751, 0x0, 0x1, NULL),
(27754, 26751, 0x0, 0x1, NULL);
