DELETE FROM `trinity_string` WHERE `entry` in (2017,2022,2023,2024);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(2017, '|cffaaffaaTicket|r:|cffaaccff %d.|r '),
(2022, '|cff00ff00Ticket Message|r: [%s]|r'),
(2023, '|cff00ff00GM Comment|r: [%s]|r'),
(2024, '|cff00ccff%s|r |cff00ff00Added comment|r: [%s]|r');
