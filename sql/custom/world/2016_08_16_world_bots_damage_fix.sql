SET @BOT_START = 70001;
SET @BOT_END   = 71000;

UPDATE `creature_template` SET `minlevel`= 1 WHERE entry BETWEEN @BOT_START AND @BOT_END;