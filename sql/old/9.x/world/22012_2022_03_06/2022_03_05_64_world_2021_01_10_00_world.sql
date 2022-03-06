--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 0x00000080 WHERE `entry` = 30407;

UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 20561;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768, `dynamicflags` = 0 WHERE `entry` = 20561;

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` BETWEEN 24874 AND 24877;
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` BETWEEN 5772 AND 5773;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 0x00000080 WHERE `entry` IN (24284,36208);
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 26688;
