-- 
DELETE FROM `gossip_menu` WHERE `MenuID` IN (9254,9255,9258,9259,9260);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(9254, 12524, 0),
(9255, 12524, 0),
(9258, 12524, 0),
(9259, 12568, 26365),
(9260, 12571, 0),
(9260, 12572, 0);

UPDATE `gameobject_template` SET `data3`=9254 WHERE `entry`=188134; -- 9258
UPDATE `gameobject_template` SET `data3`=9255 WHERE `entry`=188135; -- 9259
UPDATE `gameobject_template` SET `data3`=9258 WHERE `entry`=188139; -- 9260
UPDATE `gameobject_template` SET `data2`=2 WHERE `entry`=181376;
UPDATE `gameobject_template` SET `data10`=28859, `data12`=181290 WHERE `entry`=181288;

DELETE FROM `gameobject_template` WHERE `entry` IN (188130);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `size`, `name`, `data1`, `data2`, `data3`, `data6`, `VerifiedBuild`) VALUES
(188130, 2, 7666, 1, 'Ice Stone', 0, 3, 9251, -1, 11723);
 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (9254,9255,9258,9259,9260);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9254, 0, 0, "Lay your hand on the Ice Stone.", 25218, 1, 1, 0, 0, 0, 0, "", 0, 0),
(9255, 0, 0, "Lay your hand on the Ice Stone.", 25218, 1, 1, 0, 0, 0, 0, "", 0, 0),
(9258, 0, 0, "Lay your hand on the Ice Stone.", 25218, 1, 1, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9254,9255,9258,9259,9260);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9254,0,0,0,9,0,11947,0,0,0,0,'','Ice Stone - For Gossip player must have Striking back /Desolace/'),
(15,9255,0,0,0,9,0,11947,0,0,0,0,'','Ice Stone - For Gossip player must have Striking back /Desolace/'),
(15,9258,0,0,0,9,0,11947,0,0,0,0,'','Ice Stone - For Gossip player must have Striking back /Desolace/');

UPDATE `smart_scripts` SET `event_param1`=9254 WHERE `entryorguid` IN (188134) AND `source_type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=9255 WHERE `entryorguid` IN (188135) AND `source_type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=9258 WHERE `entryorguid` IN (188139) AND `source_type`=1 AND `id`=0;
