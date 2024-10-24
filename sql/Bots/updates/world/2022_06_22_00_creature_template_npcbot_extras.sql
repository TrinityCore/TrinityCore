--
SET @BOT_START = 70581;
SET @BOT_END   = 70585;

DELETE FROM `creature_template_npcbot_extras` WHERE `entry` BETWEEN @BOT_START AND @BOT_END;
INSERT INTO `creature_template_npcbot_extras` (`entry`,`class`,`race`) VALUES
('70581', '19', '13'),
('70582', '19', '13'),
('70583', '19', '13'),
('70584', '19', '13'),
('70585', '19', '13');
