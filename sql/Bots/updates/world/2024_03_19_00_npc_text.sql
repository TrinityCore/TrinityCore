--
SET @LOCALIZED_STRINGS_START = 70674;
SET @LOCALIZED_STRINGS_END   = 70684;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(70674,'I need a portal','-1'),
(70675,'Stormwind','-1'),
(70676,'Ironforge','-1'),
(70677,'Darnassus','-1'),
(70678,'Exodar','-1'),
(70679,'Orgrimmar','-1'),
(70680,'Undercity','-1'),
(70681,'Thunder Bluff','-1'),
(70682,'Silvermoon','-1'),
(70683,'Shattrath','-1'),
(70684,'Dalaran','-1');
