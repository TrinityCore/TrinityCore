DELETE FROM `creature_template_addon` WHERE `entry` IN (41194, 41144);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(41194, 0, 0x3000000, 0x1, '77137 77119 77121'), -- Omega Stance - Omega Stance Stalker Visual - Omega Stance Grow Effect - Omega Stance Spider Trigger
(41144, 0, 0x0, 0x1, ''); -- Alpha Beam

UPDATE `creature_template` SET `exp`=3, `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `baseattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=41144; -- Alpha Beam
UPDATE `creature_template` SET `exp`=3, `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `baseattacktime`=2000, `unit_flags`=33554432 WHERE `entry`=41194; -- Omega Stance

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (41194, 41144);
