--
DELETE FROM npc_text WHERE ID=773;
INSERT INTO npc_text (ID, text0_0) VALUES 
(773, "$C, eh? I am Krazek, Baron Revilgaz's secretary. I know everything about the goings on in this jungle and beyond. Perhaps you'd be interested in knowing the going price on oil in Ratchet? No? Looking for work, maybe? I can help you there.");

UPDATE `creature_template` SET `gossip_menu_id`=773 WHERE `entry`=773;
DELETE FROM `gossip_menu` WHERE `entry`=773;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(773, 773, 0);

DELETE FROM npc_text WHERE ID=737;
INSERT INTO npc_text (ID, text0_0) VALUES 
(737, "Well, hello there. You seem like you wouldn't be opposed to making some coin, hm? I can tell from the look in your eyes. I am Mogul Kebok, overseer of operations in Azeroth, and if it is riches you seek, perhaps I can make arrangements.");

UPDATE `creature_template` SET `gossip_menu_id`=737 WHERE `entry`=737;
DELETE FROM `gossip_menu` WHERE `entry`=737;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(737, 737, 0);

DELETE FROM npc_text WHERE ID=2505;
INSERT INTO npc_text (ID, text0_0) VALUES 
(2505, "Oy!  You here for a game of knuckles?");

UPDATE `creature_template` SET `gossip_menu_id`=2502 WHERE `entry`=2501;
DELETE FROM `gossip_menu` WHERE `entry`=2502;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(2502, 2505, 0);

DELETE FROM npc_text WHERE ID=733;
INSERT INTO npc_text (ID, text0_0) VALUES 
(733, "You watch where you step around here, $Glad:lass;.  You might not be a part of our outfit, but that doesn't mean I won't take a cane to you if you fall out of line!");

UPDATE `creature_template` SET `gossip_menu_id`=733 WHERE `entry`=733;
DELETE FROM `gossip_menu` WHERE `entry`=733;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(733, 733, 0);

DELETE FROM npc_text WHERE ID=2498;
INSERT INTO npc_text (ID, text0_0) VALUES 
(2498, "What what?!?  We all have profit to make... and we won't do it by standing idle.");

UPDATE `creature_template` SET `gossip_menu_id`=2498 WHERE `entry`=2498;
DELETE FROM `gossip_menu` WHERE `entry`=2498;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(2498, 2498, 0);
