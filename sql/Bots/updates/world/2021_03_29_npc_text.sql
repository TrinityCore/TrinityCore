--
SET @LOCALIZED_STRINGS_START = 70641;
SET @LOCALIZED_STRINGS_END   = 70644;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70641','Engage behavior','-1'),
('70642','Delay attack by','-1'),
('70643','Delay healing by','-1'),
('70644','s','-1');
