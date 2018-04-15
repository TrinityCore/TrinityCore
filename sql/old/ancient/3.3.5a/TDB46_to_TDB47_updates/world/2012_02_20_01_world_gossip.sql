-- Fix error in Scourge Deathspeaker SAI
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=27615 AND `id`=14;
-- Fix up Keeper Remulos SAI
UPDATE `smart_scripts` SET `id`=3 WHERE `entryorguid`=11832 AND `id`=4;
-- Spiritcaller Dohgar
UPDATE `creature_template` SET `gossip_menu_id`=8513 WHERE `entry`=22312;
DELETE FROM `gossip_menu` WHERE `entry`=8513 AND `text_id`=10647;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8513,10647);
