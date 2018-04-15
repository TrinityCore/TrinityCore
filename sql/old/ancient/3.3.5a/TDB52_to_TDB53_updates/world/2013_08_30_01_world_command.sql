ALTER TABLE `command` CHANGE `security` `permission` SMALLINT(5) UNSIGNED DEFAULT 0 NOT NULL;

-- Player commands
UPDATE `command` SET `permission` = 7 WHERE `permission` = 0;
-- Moderator commands
UPDATE `command` SET `permission` = 8 WHERE `permission` = 1;
-- GM commands
UPDATE `command` SET `permission` = 9 WHERE `permission` = 2;
-- administrator commands
UPDATE `command` SET `permission` = 10 WHERE `permission` = 3;
-- console commands
UPDATE `command` SET `permission` = 12 WHERE `permission` = 4;
