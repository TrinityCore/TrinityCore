--
UPDATE `creature_template` SET `faction`=14 WHERE `entry`=49311;
UPDATE `creature_template` SET `unit_class`=2 WHERE `entry`=49043;
UPDATE `gameobject` SET `spawnMask` = 1 WHERE `id` = 185434 AND `map` IN (0,1);
UPDATE `creature_template` SET `maxgold` = 3360 WHERE `entry` = 37662;
UPDATE `creature_template` SET `maxgold` = 5456 WHERE `entry` = 37031;
UPDATE `creature_template` SET `maxgold` = 4747 WHERE `entry` = 37029;
UPDATE `creature_template` SET `maxgold` = 4607 WHERE `entry` = 37028;
UPDATE `creature_template` SET `maxgold` = 837154 WHERE `entry` = 36855;
UPDATE `creature_template` SET `maxgold` = 18320 WHERE `entry` = 36829;
UPDATE `creature_template` SET `maxgold` = 2673 WHERE `entry` = 36805;

