--
SET @BOT_START = 70661;
SET @BOT_END   = 70666;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @BOT_START AND @BOT_END;

INSERT INTO `npc_text` (`ID`,`text0_0`,`VerifiedBuild`) VALUES
(@BOT_START+0, "Bot gear bank...", -1),
(@BOT_START+1, "Deposit items...", -1),
(@BOT_START+2, "Withdraw items...", -1),
(@BOT_START+3, "Bank is empty", -1),
(@BOT_START+4, "Previous page", -1),
(@BOT_START+5, "Next page", -1);
