-- Zul'Gurub creatures updates
UPDATE `creature_template` SET `equipment_id`=52151 WHERE `entry`=52151; -- Bloodlord Mandokir
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=14,`faction_H`=14 WHERE `entry`=52157; -- Ohgan
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction_A`=14,`faction_H`=14,`flags_extra`=128 WHERE `entry`=52324; -- Devastating Slam

DELETE FROM `creature_template_addon` WHERE `entry`=52157;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52157, 0, 0, 0x1020100, 0x1, 0, '96727');

-- Zul'Gurub is only Heroic
UPDATE `creature` SET `spawnMask`=2 WHERE `map`=859;
