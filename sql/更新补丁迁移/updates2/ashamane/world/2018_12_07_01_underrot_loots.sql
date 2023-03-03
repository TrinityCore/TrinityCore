DELETE FROM `creature_loot_template` WHERE `entry` = '131817';
DELETE FROM `reference_loot_template` WHERE `entry` = '131817';

DELETE FROM `creature_loot_template` WHERE `entry` = '131318';
DELETE FROM `reference_loot_template` WHERE `entry` = '131318';

DELETE FROM `creature_loot_template` WHERE `entry` = '133007';
DELETE FROM `reference_loot_template` WHERE `entry` = '133007';

DELETE FROM `creature_loot_template` WHERE `entry` = '131383';
DELETE FROM `reference_loot_template` WHERE `entry` = '131383';

UPDATE creature SET spawntimesecs = 86400 WHERE map = 1841;
