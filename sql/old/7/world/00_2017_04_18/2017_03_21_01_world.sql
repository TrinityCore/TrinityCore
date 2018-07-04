DROP TABLE IF EXISTS `quest_request_items_locale`;
CREATE TABLE `quest_request_items_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `CompletionText` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
);
