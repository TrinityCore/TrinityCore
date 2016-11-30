DROP TABLE IF EXISTS `conversation_template`;
CREATE TABLE `conversation_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `FirstLineId` INT (10) UNSIGNED NOT NULL,
  `LastLineDuration` INT (10) UNSIGNED NOT NULL,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_actor_template`;
CREATE TABLE `conversation_actor_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `CreatureId` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk1` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk2` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk3` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk4` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_line_template`;
CREATE TABLE `conversation_line_template` (
  `Id` INT (10) UNSIGNED NOT NULL,
  `PreviousLineDuration` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk2` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `Unk3` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `conversation_actors`;
CREATE TABLE `conversation_actors` (
  `ConversationId` INT (10) UNSIGNED NOT NULL,
  `ConversationActorId` INT (10) UNSIGNED NOT NULL,
  `Idx` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT (10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`ConversationId`, `ConversationActorId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


INSERT INTO `conversation_actor_template`(`Id`,`CreatureId`,`Unk1`,`Unk2`,`Unk3`,`Unk4`,`VerifiedBuild`) VALUES
(49825, 93221, 65308, 0, 1, 0, 22624),
(50124, 98075, 21135, 0, 1, 0, 22624);

INSERT INTO `conversation_actors`(`ConversationId`,`ConversationActorId`,`Idx`,`VerifiedBuild`) VALUES
(705, 50124, 0, 22624),
(1025, 49825, 0, 22624);

INSERT INTO `conversation_line_template`(`Id`,`PreviousLineDuration`,`Unk2`,`Unk3`,`VerifiedBuild`) VALUES
(1445, 0, 254, 0, 22624),
(1446, 4924, 254, 540016640, 22624),
(1683, 0, 296, 0, 22624),
(1684, 6151, 296, 0, 22624);

INSERT INTO `conversation_template`(`Id`,`FirstLineId`,`LastLineDuration`,`VerifiedBuild`) VALUES
(705, 1445, 6544, 22624),
(1025, 1683, 3458, 22624);
