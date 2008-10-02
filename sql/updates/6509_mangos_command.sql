DELETE IGNORE FROM `command` WHERE `name` = 'learn all_recipes';
INSERT IGNORE INTO `command` (`name`,`security`,`help`) VALUES
('learn all_recipes',2,'Syntax: .learn all_recipes [$profession]\r\rLearns all recipes of specified profession and sets skill level to max.\rExample: .learn all_recipes enchanting');
