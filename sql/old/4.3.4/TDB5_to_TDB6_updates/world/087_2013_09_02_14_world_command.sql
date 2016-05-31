/* cs_list.cpp */

SET @id = 436;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'list';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'list creature';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'list item';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'list object';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'list auras';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'list mail';
