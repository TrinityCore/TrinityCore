-- 
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=128 WHERE `entry`=13436;
DELETE FROM `gossip_menu` WHERE `MenuID`=21198 AND `TextID`=68;
