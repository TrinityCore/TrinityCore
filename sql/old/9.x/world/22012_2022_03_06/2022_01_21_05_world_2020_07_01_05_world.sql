DELETE FROM `gossip_menu` WHERE `MenuID`=5747 AND `TextID`=6926;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(5747, 6926);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5747 AND `SourceEntry` IN (6926, 6925);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (7483, 7484, 7485);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 5747, 6926, 0, 0, 8, 0, 7481, 0, 0, 0, 0, 0, "", "Gossip Text 6926 requires quest 'Elven Legends' (Horde) rewarded OR"),
(14, 5747, 6926, 0, 1, 8, 0, 7482, 0, 0, 0, 0, 0, "", "Gossip Text 6926 requires quest 'Elven Legends' (Alliance) rewarded "),
(19, 0, 7483, 0, 0, 8, 0, 7481, 0, 0, 0, 0, 0, "", "Quest 'Libram of Rapidity' is available if player has quest 'Elven Legends' (Horde) rewarded OR"),
(19, 0, 7483, 0, 1, 8, 0, 7482, 0, 0, 0, 0, 0, "", "Quest 'Libram of Rapidity' is available if player has quest 'Elven Legends' (Alliance) rewarded"),
(19, 0, 7484, 0, 0, 8, 0, 7481, 0, 0, 0, 0, 0, "", "Quest 'Libram of Focus' is available if player has quest 'Elven Legends' (Horde) rewarded OR"),
(19, 0, 7484, 0, 1, 8, 0, 7482, 0, 0, 0, 0, 0, "", "Quest 'Libram of Focus' is available if player has quest 'Elven Legends' (Alliance) rewarded"),
(19, 0, 7485, 0, 0, 8, 0, 7481, 0, 0, 0, 0, 0, "", "Quest 'Libram of Protection' is available if player has quest 'Elven Legends' (Horde) rewarded OR"),
(19, 0, 7485, 0, 1, 8, 0, 7482, 0, 0, 0, 0, 0, "", "Quest 'Libram of Protection' is available if player has quest 'Elven Legends' (Alliance) rewarded");
