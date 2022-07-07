-- 
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (10162,25754,23143,31115);
UPDATE `creature_template` SET `gossip_menu_id`=8310, `npcflag`=`npcflag`|1 WHERE `entry` IN (20977,21602);
