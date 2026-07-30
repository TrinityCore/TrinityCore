UPDATE `creature_template` SET `gossip_menu_id`=7169 WHERE `entry`=16237;
UPDATE `gossip_menu` SET `MenuID`=7169 WHERE `MenuID`=57031;
UPDATE `conditions` SET `SourceGroup`=7169 WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=57031;
