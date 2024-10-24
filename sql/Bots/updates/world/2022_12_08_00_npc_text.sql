--
SET @BOT_START = 70659;
SET @BOT_END   = 70659;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @BOT_START AND @BOT_END AND `ID` != 70100;

INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(@BOT_START+0, "DISABLE combat positioning", -1);
