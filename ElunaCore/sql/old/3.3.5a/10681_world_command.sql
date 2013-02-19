DELETE FROM `command` WHERE `name` IN ('reload access_requirement','reload achievement_criteria_data','reload achievement_reward','reload all achievement','reload all area','reload all eventai','reload auctions','reload mail_level_reward','reload smart_scripts');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload access_requirement',3,'Syntax: .reload access_requirement\nReload access_requirement table.'),
('reload achievement_criteria_data',3,'Syntax: .reload achievement_criteria_data\nReload achievement_criteria_data table.'),
('reload achievement_reward',3,'Syntax: .reload achievement_reward\nReload achievement_reward table.'),
('reload all achievement',3,'Syntax: .reload all achievement\r\n\r\nReload achievement_reward, achievement_criteria_data tables.'),
('reload all area',3,'Syntax: .reload all area\r\n\r\nReload areatrigger_teleport, areatrigger_tavern, game_graveyard_zone tables.'),
('reload all eventai',3,'Syntax: .reload all eventai\r\n\r\nReload creature_ai_scripts, creature_ai_summons, creature_ai_texts tables.'),
('reload auctions',3,'Syntax: .reload auctions\nReload dynamic data tables from the database.'),
('reload mail_level_reward',3,'Syntax: .reload mail_level_reward\nReload mail_level_reward table.'),
('reload smart_scripts',3,'Syntax: .reload smart_scripts\nReload smart_scripts table.');
