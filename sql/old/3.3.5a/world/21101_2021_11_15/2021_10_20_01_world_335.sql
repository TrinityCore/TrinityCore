--
ALTER TABLE `gossip_menu` MODIFY COLUMN `VerifiedBuild` int(11) NOT NULL DEFAULT '0';

DELETE FROM `gossip_menu` WHERE `MenuID`=6570 AND `TextID`=7868;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6570, 7868, 40120);

UPDATE `npc_text` SET `text0_0` = "If you have not spoken to Magistrix Erona at the Sunspire, I recommend you do so immediately.  There are pressing matters to attend to, and she - as do we all - need your help!", `BroadcastTextID0` = 10999, `Probability0` = 1, `Emote0_0` = 1 WHERE `ID` = 7868;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 6570;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- https://www.youtube.com/watch?v=-XwbG31YBfk&t=1394s both 7785 & 7868 probably are wrong
(14,6570,7785,0,0,47,0,8327,74,0,0,0,0,'',"Group 0: Show gossip text 7785 if quest 'Report to Lanthan Perilon' is taken or completed or rewarded"),
(14,6570,7868,0,0,47,0,8327,1,0,0,0,0,'',"Group 0: Show gossip text 7868 if quest 'Report to Lanthan Perilon' is not taken"),
(14,6570,7869,0,0,8,0,8335,0,0,0,0,0,'',"Group 0: Show gossip text 7869 if quest 'Felendren the Banished' is rewarded");
