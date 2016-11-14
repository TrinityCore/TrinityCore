CREATE TABLE IF NOT EXISTS `conversation_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `LastLineDuration` INT (10) UNSIGNED NOT NULL,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `conversation_actor_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `CreatureId` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk1` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk2` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk3` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk4` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `conversation_line_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `Unk1` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk2` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk3` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `conversation_actors` (
  `ConversationId` INT (10) UNSIGNED NOT NULL,
  `ConversationActorId` INT (10) UNSIGNED NOT NULL,
  `Idx` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`ConversationId`, `ConversationActorId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `conversation_lines` (
  `ConversationId` INT (10) UNSIGNED NOT NULL,
  `ConversationLineId` INT (10) NOT NULL,
  `Idx` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) NOT NULL DEFAULT 0,
  PRIMARY KEY (`ConversationId`, `ConversationLineId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


DELETE FROM conversation_actor_template WHERE Id IN (49825, 50124);
INSERT INTO `conversation_actor_template`(`Id`,`CreatureId`,`Unk1`,`Unk2`,`Unk3`,`Unk4`,`VerifiedBuild`) VALUES
(49825, 93221, 65308, 0, 1, 0, 22624),
(50124, 98075, 21135, 0, 1, 0, 22624);

DELETE FROM conversation_actors WHERE ConversationId IN (705, 1025);
INSERT INTO `conversation_actors`(`ConversationId`,`ConversationActorId`,`Idx`,`VerifiedBuild`) VALUES
(705, 50124, 0, 22624),
(1025, 49825, 0, 22624);

DELETE FROM conversation_line_template WHERE Id IN (1445, 1446, 1683, 1684);
INSERT INTO `conversation_line_template`(`Id`,`Unk1`,`Unk2`,`Unk3`,`VerifiedBuild`) VALUES
(1445, 0, 254, 0, 22624),
(1446, 4924, 254, 540016640, 22624),
(1683, 0, 296, 0, 22624),
(1684, 6151, 296, 0, 22624);
  
DELETE FROM conversation_lines WHERE ConversationId IN (705, 1025);
INSERT INTO `conversation_lines`(`ConversationId`,`ConversationLineId`,`Idx`,`VerifiedBuild`) VALUES
(705, 1683, 0, 22624),
(705, 1684, 1, 22624),
(1025, 1445, 0, 22624),
(1025, 1446, 1, 22624);

DELETE FROM conversation_template WHERE Id IN (705, 1025);
INSERT INTO `conversation_template`(`Id`,`LastLineDuration`,`VerifiedBuild`) VALUES
(705, 6544, 22624),
(1025, 3458, 22624);
