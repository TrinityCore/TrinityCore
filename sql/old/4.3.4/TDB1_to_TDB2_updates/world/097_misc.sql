-- Fix auctionner flag of Auctioneer Hesse
UPDATE `creature_template` SET `npcflag`=2097152 WHERE `entry`=43695;

-- Deleted non-existant spell group
DELETE FROM `spell_group` WHERE `spell_id` IN (21183, 30708);

-- Fix gossip menu of Darkmoon Faire Mystic Mage
DELETE FROM `gossip_menu` WHERE `entry`=12992 AND `text_id`=18269;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12992, 18269); -- 54334
