--
UPDATE `creature_template` SET `faction_A`=1216, `faction_H`=1216 WHERE `entry` IN (13087,22731,31948);
UPDATE `creature_template` SET `faction_A`=59, `faction_H`=59 WHERE `entry` IN (13081,22746,32017);
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN (34606,34649,33670,34109,33651,34108,33515,34175,33432,34106);
UPDATE `creature_template` SET `faction_A`=103, `faction_H`=103 WHERE `entry` IN (31218,31541,30882,31539,30858,31546);
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE `entry` IN (31118,31491);
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16 WHERE `entry` IN (29829,30926);
UPDATE `command` SET `name`='reload broadcast_text' WHERE `name`='broadcast_text';
