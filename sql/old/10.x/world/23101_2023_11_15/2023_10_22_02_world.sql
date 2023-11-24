-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName`='npc_innkeeper';

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(344,348,349,441,1290,1293,1294,1296,1297,1581,6525,6620,7173,7288,7301,7324,7468,7481,7855,9123) AND `SourceEntry` IN(0, 2);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=344 AND `OptionID` IN(2, 3)) OR (`MenuID`=348 AND `OptionID`=2) OR (`MenuID`=349 AND `OptionID` IN(2, 3)) OR (`MenuID`=441 AND `OptionID` IN(2, 4)) OR (`MenuID`=6620 AND `OptionID`=2) OR (`MenuID`=7173 AND `OptionID` IN(2, 3)) OR (`MenuID`=7288 AND `OptionID` IN(2, 3)) OR (`MenuID`=7301 AND `OptionID`=2) OR (`MenuID`=7324 AND `OptionID`=2) OR (`MenuID`=7481 AND `OptionID`=2) OR (`MenuID`=7855 AND `OptionID`=2) OR (`MenuID`=9123 AND `OptionID` IN(2, 3));
