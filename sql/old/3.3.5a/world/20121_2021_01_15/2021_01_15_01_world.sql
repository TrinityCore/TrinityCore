-- Sniff
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 21316; -- Deathforged Infernal
UPDATE `creature_template` SET `npcflag` = 3, `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33536 WHERE `entry` = 22421; -- Skar'this the Heretic
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` = 31131; -- Containment Crystal
UPDATE `creature_template` SET `unit_flags` = 33554432+768 WHERE `entry` = 1921; -- Combat Dummy
DELETE FROM `creature_template_addon` WHERE `entry` = 1921;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(1921,'7056');

-- CreatureDifficulty
UPDATE `creature_template` SET `unit_flags` = 33554432+256 WHERE `entry` = 23968; -- Hanes Fire Trigger
UPDATE `creature_template` SET `unit_flags` = 33554432+256 WHERE `entry` = 23310; -- Fel Portal Alarm
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 22073; -- Marcus Auralion
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 22941; -- Mog'dorg the Wizened
