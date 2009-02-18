DELETE FROM `trinity_string`WHERE `entry` in ('6613', '6614', '6615');
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES ('6613','|cfff00000[GM Announcement]: %s|r');
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES ('6614','Notification to GM\'s - ');
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES ('6615','|cffffff00[|c1f40af20GM Announce by|r |cffff0000%s|cffffff00]:|r %s|r');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('gmnotify', 2, 'Syntax: .gmnotify $notification\r\nDisplays a notification on the screen of all online GM\'s.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('gmnameannounce', 2, 'Syntax: .gmnameannounce $announcement.\r\nSend an announcement to all online GM\'s, displaying the name of the sender.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('gmannounce', 4, 'Syntax: .gmannounce $announcement\r\nSend an announcement to online Gamemasters.');

