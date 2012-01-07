-- Update npc_text from sniff
UPDATE `npc_text` SET `prob0`=1,`text0_0`='I wandered for the rest of my natural life in search of knowledge, seeing more wonder and meeting more strange and mysterious races than any of my people before me. I travelled across the length and breadth of ancient Kalimdor until there was no more to see, no new lands across the horizon.$B$BYet... there was still so much I did not know as I felt my final journey approaching and I wept for the things I would never know.$B$BAs I fell, my life at an end, that is when they found me.',`WDBVerified`=14545 WHERE `ID`=14121;
UPDATE `npc_text` SET `prob0`=1,`text0_0`='The bronze dragonflight. They snatched me from the brink of death and took me before their master, Nozdormu. He said they had been watching me and wanted me to continue my hunt. He granted me immortality as a watcher, tasked to bear witness to the history of Azeroth as one of his agents.$B$BI am Xarantaur the Witness, and it is my duty to preserve the true history of Azeroth lest it be forgotten.',`WDBVerified`=14545 WHERE `ID`=14122;

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=10217 AND `text_id`=14204;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10217,14204);
DELETE FROM `gossip_menu` WHERE `entry`=10174 AND `text_id`=14118;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10174,14118);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=10217 WHERE `entry`=30824;
UPDATE `creature_template` SET `gossip_menu_id`=10038 WHERE `entry`=31261;
UPDATE `creature_template` SET `gossip_menu_id`=10174 WHERE `entry`=30825;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10026,10174) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10026,0,0, 'Take me to the ship.',1,1,0,0,0,0, ''),
(10174,0,1, 'I want to browse your goods.',3,128,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9806 AND `text_id`=13525;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9806,13525);
DELETE FROM `gossip_menu` WHERE `entry`=9807 AND `text_id`=13526;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9807,13526);
DELETE FROM `gossip_menu` WHERE `entry`=9808 AND `text_id`=13527;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9808,13527);
DELETE FROM `gossip_menu` WHERE `entry`=9809 AND `text_id`=13528;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9809,13528);
DELETE FROM `gossip_menu` WHERE `entry`=9810 AND `text_id`=13529;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9810,13529);
DELETE FROM `gossip_menu` WHERE `entry`=9811 AND `text_id`=13530;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9811,13530);
DELETE FROM `gossip_menu` WHERE `entry`=9812 AND `text_id`=13531;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9812,13531);
DELETE FROM `gossip_menu` WHERE `entry`=9813 AND `text_id`=13534;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9813,13534);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9806 WHERE `entry`=29344;
UPDATE `creature_template` SET `gossip_menu_id`=9813 WHERE `entry`=29396;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9806,9807,9808,9809,9810,9811,9812) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9808,9809,9810,9811,9812) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9806,0,0, 'Lord-Commander, I would hear your tale.',1,1,9807,0,0,0, ''),
(9807,0,0, '<You nod slightly but do not complete the motion as the lord-commander narrows his eyes before he continues.>',1,1,9808,0,0,0, ''),
(9808,0,0, 'I thought that they now called themselves the Scarlet Onslaught?',1,1,9809,0,0,0, ''),
(9808,1,0, 'Lord-Commander, would you repeat what you said before?',1,1,9807,0,0,0, ''),
(9809,0,0, 'Where did the grand admiral go?',1,1,9810,0,0,0, ''),
(9809,1,0, 'Lord-Commander, would you repeat what you said before?',1,1,9808,0,0,0, ''),
(9810,0,0, 'That''s fine. When do I start?',1,1,9811,0,0,0, ''),
(9810,1,0, 'Lord-Commander, would you repeat what you said before?',1,1,9809,0,0,0, ''),
(9811,0,0, 'Let''s finish this!',1,1,9812,0,0,0, ''),
(9811,1,0, 'Lord-Commander, would you repeat what you said before?',1,1,9810,0,0,0, ''),
(9812,0,0, 'That''s quite a tale, lord-commander.',1,1,0,0,0,0, ''),
(9812,1,0, 'Lord-Commander, would you repeat what you said before?',1,1,9811,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9168 AND `text_id`=12427;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9168,12427);
DELETE FROM `gossip_menu` WHERE `entry`=9184 AND `text_id`=12472;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9184,12472);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9168 WHERE `entry`=25504;
UPDATE `creature_template` SET `gossip_menu_id`=9184 WHERE `entry`=25379;
UPDATE `creature_template` SET `gossip_menu_id`=348 WHERE `entry`=25278;
