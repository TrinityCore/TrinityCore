-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID`=5349 AND `OptionID`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5349 AND `SourceEntry`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=13716 AND `source_type`=0 AND id=22;
