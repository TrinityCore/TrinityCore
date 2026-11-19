DELETE FROM `creature_template_addon` WHERE `entry`=17940;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17940,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17940);

DELETE FROM `creature_template_addon` WHERE `entry`=17957;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17957,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17957);

DELETE FROM `creature_template_addon` WHERE `entry`=17958;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17958,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17958);

DELETE FROM `creature_template_addon` WHERE `entry`=17959;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17959,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17959);

DELETE FROM `creature_template_addon` WHERE `entry`=17961;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17961,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17961);

DELETE FROM `creature_template_addon` WHERE `entry`=17962;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`) VALUES (17962,1);
UPDATE `creature_addon` SET `bytes2`=1 WHERE guid IN (SELECT guid FROM creature WHERE id = 17962);
