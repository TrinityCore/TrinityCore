DELETE FROM `Kitron_string` WHERE `entry` IN (1131,1132,1133);
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES
(1131, 'The following characters match your query:'),
(1132, 'Currently Banned Characters:'),
(1133, '|   Character   |   BanDate    |   UnbanDate  |  Banned By    |   Ban Reason  |');
