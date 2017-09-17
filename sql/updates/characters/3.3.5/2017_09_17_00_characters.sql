CREATE TABLE IF NOT EXISTS `feedback_system` (
  `playerSubject` tinytext,
  `playerName` varchar(50) DEFAULT NULL,
  `playerGUID` int(11) DEFAULT NULL,
  `playerFeedBack` longtext,
  `Date` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;