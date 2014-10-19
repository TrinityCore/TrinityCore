DELETE FROM `creature_template_addon` WHERE `entry`=40503;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(40503, 0, 0x0, 0x1, '75546'); -- Quicksand

UPDATE `creature_template` SET `exp`=3, `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `baseattacktime`=2000, `unit_flags`=33554496 WHERE `entry`=40503; -- Quicksand
