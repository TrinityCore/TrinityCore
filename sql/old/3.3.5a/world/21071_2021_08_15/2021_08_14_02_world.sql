--
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73, `exp` = 1 WHERE `entry` = 28521;
UPDATE `creature_template` SET `type` = 10 WHERE `entry` IN (21861,28535,28536,28537,28539,28540);
UPDATE `creature_template` SET `family` = 0 WHERE `entry` IN (28535,28536,28537,28539,28540);
