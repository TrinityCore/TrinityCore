-- https://www.youtube.com/watch?v=1yKt1V5Qnk8
DELETE FROM `gossip_menu` WHERE `MenuID` = 8683 AND `TextID` = 10930;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(8683,10930,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 8683;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,8683,10930,0,0,1,0,41181,0,0,1,0,0,"","Group 0: Show gossip text 10930 if player does not have aura 'Shabby Arakkoa Disguise'"),
(14,8683,10953,0,0,1,0,41181,0,0,0,0,0,"","Group 0: Show gossip text 10953 if player does have aura 'Shabby Arakkoa Disguise'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8683;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8683,0,0,0,1,0,41181,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have aura 'Shabby Arakkoa Disguise'");
