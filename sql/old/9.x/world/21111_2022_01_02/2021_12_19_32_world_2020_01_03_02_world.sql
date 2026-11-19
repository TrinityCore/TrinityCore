-- 
UPDATE `creature_template` SET `gossip_menu_id`=344 WHERE `entry` IN (11106,6746,9501,7737);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21215) AND `TextID` IN (822);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21215);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN(21215);
UPDATE `smart_scripts` SET `event_param1`=344, `event_param2`=2 WHERE `entryorguid`=6746 AND `source_type`=0 AND `id`=0;
