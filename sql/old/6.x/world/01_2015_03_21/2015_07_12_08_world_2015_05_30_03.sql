--
UPDATE `npc_text` SET `BroadcastTextID0`=8703 WHERE `id`=6158;
DELETE FROM `gossip_menu` WHERE `entry`=5032;
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=241; 

UPDATE `creature_template` SET `gossip_menu_id`=11611 WHERE `entry`=240;
DELETE FROM `gossip_menu` WHERE `entry`=6159;
DELETE FROM `npc_text` WHERE `ID`=6157;
