--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (7389, 7398, 7400);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7399 AND `SourceEntry` IN (8865, 8892);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7398, 8862, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Show gossip text 8862 if quest A Small Start is rewarded"),
(14, 7398, 8862, 0, 0, 8, 0, 9537, 0, 0, 1, 0, 0, "", "Show gossip text 8862 if quest Show Gnomercy is not rewarded"),
(14, 7398, 8862, 0, 0, 16, 0, 1024, 0, 0, 0, 0, 0, "", "Show gossip text 8862 if player is Draenei"),
(14, 7398, 8863, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Show gossip text 8862 if quest A Small Start is rewarded"),
(14, 7398, 8863, 0, 0, 8, 0, 9537, 0, 0, 1, 0, 0, "", "Show gossip text 8862 if quest Show Gnomercy is not rewarded"),
(14, 7398, 8863, 0, 0, 16, 0, 1024, 0, 0, 1, 0, 0, "", "Show gossip text 8862 if player is not Draenei"),
(14, 7398, 8893, 0, 0, 8, 0, 9537, 0, 0, 0, 0, 0, "", "Show gossip text 8893 if quest Show Gnomercy is rewarded"),
(14, 7399, 8865, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Show gossip text 8865 if quest A Small Start is rewarded"),
(14, 7399, 8865, 0, 0, 8, 0, 9537, 0, 0, 1, 0, 0, "", "Show gossip text 8865 if quest Show Gnomercy is not rewarded"),
(14, 7399, 8892, 0, 0, 8, 0, 9537, 0, 0, 0, 0, 0, "", "Show gossip text 8892 if quest Show Gnomercy is rewarded"),
(14, 7400, 8868, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Show gossip text 8868 if quest A Small Start is rewarded"),
(14, 7400, 8868, 0, 0, 8, 0, 9537, 0, 0, 1, 0, 0, "", "Show gossip text 8868 if quest Show Gnomercy is not rewarded"),
(14, 7400, 8892, 0, 0, 8, 0, 9537, 0, 0, 0, 0, 0, "", "Show gossip text 8892 if quest Show Gnomercy is rewarded"),
(14, 7389, 8893, 0, 0, 8, 0, 9537, 0, 0, 0, 0, 0, "", "Show gossip text 8893 if quest Show Gnomercy is rewarded");

DELETE FROM `gossip_menu` WHERE `MenuID` IN (7389, 7398, 7399, 7400) AND `TextID` IN (8863, 8892, 8893);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7389, 8893, 41812),
(7398, 8863, 41812),
(7398, 8893, 41812),
(7399, 8892, 41812),
(7400, 8892, 41812);
