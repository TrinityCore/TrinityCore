-- Totems and mini-pets shouldn't have loot
UPDATE `creature_template` SET `lootid` = 0, `skinloot` = 0 WHERE `entry` IN (2992,7484,7543,7560,13916);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (2992,7484);
-- minlevel shouldn't be > maxlevel
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72 WHERE `entry` = 20572;
UPDATE `creature_template` SET `minlevel` = 68, `maxlevel` = 69 WHERE `entry` = 21587;
-- These NPCs shouldn't have loot
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (3680,3891,16836,17079,17080,17917,18201,20627);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (3680,3891,16836,17079,17080,17917,18201);
UPDATE `creature_template` SET `mingold` = 0, `maxgold` = 0 WHERE `entry` = 18201;
