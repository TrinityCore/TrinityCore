-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8118 AND `text_id`=10054;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8118,10054);
DELETE FROM `gossip_menu` WHERE `entry`=8119 AND `text_id`=10056;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8119,10056);
DELETE FROM `gossip_menu` WHERE `entry`=8083 AND `text_id`=9993;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8083,9993);
DELETE FROM `gossip_menu` WHERE `entry`=8576 AND `text_id`=10752;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8576,10752);
-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8646 WHERE `entry`=19539;
UPDATE `creature_template` SET `gossip_menu_id`=8118 WHERE `entry`=20470;
UPDATE `creature_template` SET `gossip_menu_id`=8119 WHERE `entry`=20471;
UPDATE `creature_template` SET `gossip_menu_id`=8083 WHERE `entry`=20084;
UPDATE `creature_template` SET `gossip_menu_id`=8576 WHERE `entry`=22899;
-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7982) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7982,7818) AND `id` IN (1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7982,0,5, 'Make this inn your home.',8,65536,0,0,0,0,0, ''),
(7982,1,1, 'I want to browse your goods.',3,128,0,0,0,0,0, ''),
(7818,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, '');
-- SAI for Karaaz,Dealer Aljaan,Dealer Digriz (Netherstorm)
SET @ENTRY := 21878;
UPDATE creature_template SET AIName='SmartAI' WHERE entry IN (20242,19533,19534);
DELETE FROM smart_scripts WHERE source_type=0 AND entryorguid IN (20242,19533,19534);
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(20242,0,0,0,1,0,100,0,1000,30000,60000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Karaaz - OOC - Say Text 0'),
(19533,0,0,0,1,0,100,0,1000,30000,60000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dealer Aljaan - OOC - Say Text 0'),
(19534,0,0,0,1,0,100,0,1000,30000,60000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dealer Digriz - OOC - Say Text 0');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (20242,19533,19534) AND `groupid` IN (0);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20242,0,0, 'The best selection of smuggled goods is available right here, $N.  Great for the whole family!  Avoid goblin taxation and naaru prohibition - the Consortium is here to fill your every shopping need!',12,0,100,1,0,0, 'Karaaz'),
(19533,0,0, 'A tradesman, perhaps? You need look no further than I for supplies. My prices are quite fair, friend. These items were difficult to acquire, but what does the source matter, eh? You''ll have what you need.',12,0,100,1,0,0, 'Dealer Aljaan'),
(19534,0,0, 'The creatures of this place are strong, wayfarer. You''ll need ample ammunition if you hope to survive. You''re in luck - I am well-stocked with fine arrows, bullets, and throwing weapons. The price is reasonable, considering circumstances.',12,0,100,1,0,0, 'Dealer Digriz');
