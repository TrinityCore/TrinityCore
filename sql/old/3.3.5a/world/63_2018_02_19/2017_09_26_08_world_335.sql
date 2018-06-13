-- Fix gossip menu for Aurora Skycaller
DELETE FROM `gossip_menu` WHERE `MenuID` IN (4743, 4744, 4745);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4743,5795,0),
(4743,5816,0),
(4743,5817,0),
(4743,5818,0),
(4744,5796,0),
(4745,5797,0);

UPDATE `gossip_menu_option` SET `ActionMenuID`=4744 WHERE `MenuID`=4743 AND `OptionID`=0;
UPDATE `gossip_menu_option` SET `ActionMenuID`=4745 WHERE `MenuID`=4743 AND `OptionID`=1;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 4743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,4743,5816,0,0,8,0,5245,0,0,1,0,0,'',"Aurora Skycaller - Show Gossip Menu Text 5816 if Quest 5245 is NOT rewarded"),
(14,4743,5795,0,0,6,0,67,0,0,0,0,0,'',"Aurora Skycaller - Show Gossip Menu Text 5795 if Player is Horde"),
(14,4743,5817,0,0,8,0,5245,0,0,0,0,0,'',"Aurora Skycaller - Show Gossip Menu Text 5817 if Quest 5245 is rewarded"),
(14,4743,5818,0,0,8,0,5247,0,0,0,0,0,'',"Aurora Skycaller - Show Gossip Menu Text 5818 if Quest 5247 is rewarded");
UPDATE `gossip_menu_option` SET `ActionMenuID`=3623 WHERE `MenuID`=3624;
