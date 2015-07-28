DELETE FROM `gameobject_template` WHERE `entry` IN (207164, 207365, 206579, 206578, 205887, 205884);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(207164, 5, 6848, 'Uldum_BeetleShrine', '', '', '', 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207365, 8, 10152, 'Torch', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.470001, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(206579, 10, 10097, 'Neferset Frond', '', '', '', 1634, 27922, 0, 3000, 0, 0, 0, 0, 0, 0, 88525, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(206578, 6, 10096, 'Plant Trap', '', '', '', 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205887, 3, 10079, 'Watcher Head', '', 'Extricating', '', 93, 34759, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47578, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.6, 61977, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(205884, 3, 10079, 'Watcher Head', '', 'Extricating', '', 93, 34757, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47578, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.6, 61044, 0, 0, 0, 0, 0, 0, 15595); -- -Unknown-

UPDATE `gameobject_template` SET `name`='Statue Debris 00', `WDBVerified`=15595 WHERE `entry`=205883; -- -Unknown-
UPDATE `gameobject_template` SET `castBarCaption`='Extricating' WHERE `entry`=205889; -- -Unknown-
