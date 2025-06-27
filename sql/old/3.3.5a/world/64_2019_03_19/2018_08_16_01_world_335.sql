--
UPDATE `gossip_menu_option` SET `OptionText`='How do I use the cannon?', `OptionBroadcastTextID`= 10769 WHERE `MenuID`= 6575;
UPDATE `gossip_menu_option` SET `OptionText`='Tonks?', `OptionBroadcastTextID`= 11934 WHERE `MenuID`= 6581 AND `OptionID`= 0;
UPDATE `gossip_menu_option` SET `OptionText`='Cannon?', `OptionBroadcastTextID`= 11936 WHERE `MenuID`= 6581 AND `OptionID`= 1;
UPDATE `gossip_menu_option` SET `OptionText`='Attractions?',`OptionBroadcastTextID`= 10779 WHERE `MenuID`= 6582 AND `OptionID`= 3;

DELETE FROM `gossip_menu` WHERE `MenuID`=7095 AND `TextID` IN (11743,8348);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7095,11743,0),(7095,8348,0);

DELETE FROM `npc_text` WHERE `ID`=8348;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`) VALUES
(8348,"","The Blastenheimer 5000 Ultra Cannon is a state-of-the-art single person projectile device. Delivering its payload at near the speed of a dragon, the cannon is the pride and joy of the Blastenheimer family, world renown for their aeronautical and combustible feats!$B$BIf you'd like to be launched through the skies to fly free as a bird, seek out Maxima Blastenheimer on the east end of the faire. I hear that she's placed a target ring way over on Crystal Lake for you to aim for as you sail through the air!",11937,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7095;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7095,8348,0,0,22,0,0,0,0,0,0,0,"","Show text 8348 on map 0"),
(14,7095,8349,0,0,22,0,1,0,0,0,0,0,"","Show text 8349 on map 1"),
(14,7095,11743,0,0,22,0,530,0,0,0,0,0,"","Show text 11743 on map 530");
