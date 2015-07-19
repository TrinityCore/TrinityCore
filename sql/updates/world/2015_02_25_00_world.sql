--
DELETE FROM `gossip_menu` WHERE `entry`=9821 AND `text_id`=13557; 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9821,13557);
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=9977;

DELETE FROM `gossip_menu` WHERE `entry`=4841 AND `text_id`=5894;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4841,5894);
UPDATE `creature_template` SET `gossip_menu_id`=4841 WHERE `entry`=12997;

DELETE FROM `gossip_menu` WHERE `entry`=4845 AND `text_id`=5920;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (4845,5920);
UPDATE `creature_template` SET `gossip_menu_id`=4845 WHERE `entry`=13018;

DELETE FROM `gossip_menu` WHERE `entry`=10631 AND `text_id`=14724;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10631,14724);
UPDATE `creature_template` SET `gossip_menu_id`=10631 WHERE `entry`=35073;

DELETE FROM `gossip_menu` WHERE `entry`=3501 AND `text_id`=4253; 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3501,4253);
UPDATE `creature_template` SET `gossip_menu_id`=3501 WHERE `entry`=1694;

UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=13076;

DELETE FROM `gossip_menu` WHERE `entry`=9027 AND `text_id` IN (12198); 
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9027,12198);
