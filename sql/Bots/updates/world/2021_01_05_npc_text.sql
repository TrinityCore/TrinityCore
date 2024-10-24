--
SET @LOCALIZED_STRINGS_START = 70634;
SET @LOCALIZED_STRINGS_END   = 70640;

DELETE FROM `npc_text` WHERE ID BETWEEN @LOCALIZED_STRINGS_START and @LOCALIZED_STRINGS_END;
INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
('70634','Looting','-1'),
('70635','|cff9d9d9dPoor|r','-1'),
('70636','|cffffffffCommon|r','-1'),
('70637','|cff1eff00Uncommon|r','-1'),
('70638','|cff0070ddRare|r','-1'),
('70639','|cffa335eeEpic|r','-1'),
('70640','|cffff8000Legendary|r','-1');
