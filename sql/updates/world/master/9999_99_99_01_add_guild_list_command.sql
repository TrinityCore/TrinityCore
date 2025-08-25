-- 9999_99_99_01_add_guild_list_command.sql
INSERT INTO `command` (`name`, `help`)
VALUES ('guild list', 'Syntax: .guild list.  Lists every guild: ID | Name | GM | Created | Members | Bank gold')
ON DUPLICATE KEY UPDATE `help` = VALUES(`help`);
