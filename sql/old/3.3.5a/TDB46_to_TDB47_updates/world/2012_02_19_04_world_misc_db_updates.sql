-- Horde Orphan should not have weapons
UPDATE `creature_template` SET `equipment_id`=0 WHERE `entry`=14499;
-- Tog'thar Gossip
UPDATE `creature_template` SET `gossip_menu_id`=264 WHERE `entry`=2238;
DELETE FROM `gossip_menu` WHERE `entry`=264 AND `text_id`=761;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (264,761);
-- Cosmetic Silkwing should have InhabitType 4
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=21840;
-- Leoroxx
UPDATE `creature_template` SET `gossip_menu_id`=8511 WHERE `entry`=22004;
DELETE FROM `gossip_menu` WHERE `entry`=8511 AND `text_id`=10645;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8511,10645);
-- Spiritcaller Dohgar
UPDATE `creature_template` SET `gossip_menu_id`=8513 WHERE `entry`=22312;
DELETE FROM `gossip_menu` WHERE `entry`=8513 AND `text_id`=10647;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8513,10647);
-- Ogrin <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=22468;
-- Wanted Poster "Blade's Edge Mountains"
DELETE FROM `gossip_menu` WHERE `entry`=8242 AND `text_id`=10257;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8242,10257);
