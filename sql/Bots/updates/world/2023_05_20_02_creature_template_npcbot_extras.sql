--
SET @BOT_START = 70587;
SET @BOT_END   = 70595;

DELETE FROM `creature_template_npcbot_extras` WHERE `entry` BETWEEN @BOT_START AND @BOT_END;
INSERT INTO `creature_template_npcbot_extras` (`entry`,`class`,`race`) VALUES
('70587', '20', '15'),
('70588', '20', '15'),
('70589', '20', '15'),
('70590', '20', '15'),
('70591', '20', '15'),
('70592', '0', '15'),
('70593', '0', '15'),
('70594', '0', '15'),
('70595', '0', '15');
