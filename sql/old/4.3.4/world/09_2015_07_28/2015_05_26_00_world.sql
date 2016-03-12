--
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=5032 WHERE `entry`=241;
DELETE FROM `gossip_menu` WHERE `entry`=5032;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (5032, 6158);
DELETE FROM `npc_text` WHERE `ID`=6158;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`) VALUES 
(6158, 'Hey there, friend. My name''s Remy. I''m from Redridge to the east, and came here looking for business, looking for business. You got any...got any??', 'Hey there, friend. My name''s Remy. I''m from Redridge to the east, and came here looking for business, looking for business. You got any...got any??', 0, 0, 1, 0, 0);
