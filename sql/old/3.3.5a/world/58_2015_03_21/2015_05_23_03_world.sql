--
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=6159 WHERE `entry`=240;
DELETE FROM `gossip_menu` WHERE `entry`=6159;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6159, 6157);
DELETE FROM `npc_text` WHERE `ID`=6157;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`) VALUES 
(6157, 'Ach, it''s hard enough keeping order around here without all these new troubles popping up!  I hope you have good news, $n...', 'Ach, it''s hard enough keeping order around here without all these new troubles popping up!  I hope you have good news, $n...', 42172, 0, 1, 5, 5);
