-- 
DELETE FROM `gossip_menu` WHERE `MenuID` IN (55000, 54000);
UPDATE `creature_template` SET `gossip_menu_id`=10274 WHERE `entry`=29319;
UPDATE `creature_template` SET `gossip_menu_id`=10273 WHERE `entry`=29327;
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (10160, 10273,10274, 54000, 55000);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(10160, 0, 0, "The Alliance Quarter", 32103, 1, 1, 10054, 129),
(10160, 1, 0, "The Horde Quarter", 32104, 1, 1, 10053, 130),
(10273, 0, 0, "Lift the frost leopard's tail to check if it's a male or a female.", 33190, 1, 1, 0, 0),
(10274, 0, 0, "Lift the icepaw bear's tail to check if it's a male or a female.", 33194, 1, 1, 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (55000,54000,10273,10274);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10273,0,0,9,13549,0,0,0,'',"Only show gossip if player is on quest Tails Up"),
(15,10274,0,0,9,13549,0,0,0,'',"Only show gossip if player is on quest Tails Up");

UPDATE `smart_scripts` SET `event_param1`=10274 WHERE `entryorguid`=29319 AND `source_type`=0 AND `id`=3; 
UPDATE `smart_scripts` SET `event_param1`=10273 WHERE `entryorguid`=29327 AND `source_type`=0 AND `id`=3; 

DELETE FROM `npc_text` WHERE `ID` IN (12568, 13944);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(12568,"Here you are, $n.$b$bDo be more careful, won't you?","",25370,0,1,0,0,0,0,0,0),
(13944,"","You must defeat Prince Sandoval. It is your only hope for survival, $c.",32011,0,1,0,0,0,0,0,0);
