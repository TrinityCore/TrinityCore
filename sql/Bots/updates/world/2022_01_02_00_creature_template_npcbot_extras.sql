--
SET @BOT_START = 70575;
SET @BOT_END   = 70580;

DELETE FROM `creature_template_npcbot_extras` WHERE `entry` BETWEEN @BOT_START AND @BOT_END;
INSERT INTO `creature_template_npcbot_extras` (`entry`,`class`,`race`) VALUES
('70575', '18', '1'),
('70576', '18', '1'),
('70577', '18', '1'),
('70578', '18', '1'),
('70579', '18', '1'),
('70580', '0', '15');
