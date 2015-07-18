--
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=6159 WHERE `entry`=240;
DELETE FROM `gossip_menu` WHERE `entry`=6159;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6159, 6157);
DELETE FROM `npc_text` WHERE `ID`=6157;
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES 
(6157, 42172, 1);
