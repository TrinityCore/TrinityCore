--
SET @BOT_START = 70660;
SET @BOT_END   = 70660;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @BOT_START AND @BOT_END;

INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(@BOT_START+0, "Priority target", -1);
