-- Update command table and remove obsolete permissions (0 = non existent permission)
UPDATE `command` SET `permission` = 0 WHERE `permission` IN (7, 8, 9, 10, 12);
