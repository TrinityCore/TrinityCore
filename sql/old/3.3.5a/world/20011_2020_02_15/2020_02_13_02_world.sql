-- 
UPDATE `smart_scripts` SET `event_param1`=9181, `link`=0 WHERE `entryorguid` IN (25590) AND `source_type`=0 AND `id`=0; 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25590) AND `source_type`=0 AND `id`=1; 
DELETE FROM `gossip_menu_option` WHERE `MenuID`=9182 AND `OptionID`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN(9182,9181);
UPDATE `conditions` SET `ConditionTypeOrReference`=47, `ConditionValue2`=66 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9171 AND `SourceEntry`=1;
