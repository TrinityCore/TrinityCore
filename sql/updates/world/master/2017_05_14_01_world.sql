DROP TABLE IF EXISTS `conversation_template`;
CREATE TABLE `conversation_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `FirstLineId` INT (10) UNSIGNED NOT NULL,
  `LastLineEndTime` INT (10) UNSIGNED NOT NULL,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_actor_template`;
CREATE TABLE `conversation_actor_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `CreatureId` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `CreatureModelId` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_line_template`;
CREATE TABLE `conversation_line_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `StartTime` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `UiCameraID` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `ActorIdx` SMALLINT (5) UNSIGNED NOT NULL DEFAULT 0,
  `Unk` SMALLINT (5) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_actors`;
CREATE TABLE `conversation_actors` (
  `ConversationId` INT (10) UNSIGNED NOT NULL,
  `ConversationActorId` INT (10) UNSIGNED NOT NULL,
  `Idx` SMALLINT (5) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`ConversationId`, `ConversationActorId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DELETE FROM `command` WHERE `name` IN ('debug conversation', 'reload conversation_template');
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('debug conversation', 854, 'Syntax: .debug conversation $conversationId\r\nPlay given conversation.'),
('reload conversation_template', 853, 'Syntax: .reload conversation_template\r\nReload conversation tables.');
