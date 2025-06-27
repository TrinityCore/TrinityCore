-- 
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=15664;
UPDATE `smart_scripts` SET `event_param1`=6763 WHERE `entryorguid` IN (15664) AND `source_type`=0 AND `id` IN (0,1);
UPDATE `conditions` SET `SourceGroup`=6763 WHERE `SourceTypeOrReferenceId`=15 AND `ConditionTypeOrReference`=2 AND `ConditionValue1`=21211;
DELETE FROM `gossip_menu` WHERE `MenuID`=21251 AND `TextID`=8076;
DELETE FROM `gossip_menu` WHERE `MenuID`=21252 AND `TextID`=8077;
UPDATE `creature_template` SET `gossip_menu_id`=6763 WHERE `entry`=15664;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21251,6763);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`) VALUES
(6763, 0, 0, 'Sprinkle some of the reindeer dust onto Metzen.', 0, 1, 1, 6761);

DELETE FROM `spell_scripts` WHERE `id`=25952;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(25952,0,0,18,0,0,0,0,0,0,0);
