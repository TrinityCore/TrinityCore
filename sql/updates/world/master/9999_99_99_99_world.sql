-- 
ALTER TABLE `creature_addon` ADD COLUMN `noNPCDamageBelowHealthPct` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `auras`;
ALTER TABLE `creature_template_addon` ADD COLUMN `noNPCDamageBelowHealthPct` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `auras`;

-- transition from old sparring
DELETE FROM `creature_template_addon` WHERE `entry` IN(32882,32883,32885,32886,32907,32908);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `noNPCDamageBelowHealthPct`) VALUES
(32882, 1, 100),
(32883, 1, 100),
(32885, 1, 100),
(32907, 1, 100),
(32908, 1, 100);

-- fix overridden data of existing creatures
UPDATE `creature_addon` SET `noNPCDamageBelowHealthPct`=85 WHERE `guid`=454966;
