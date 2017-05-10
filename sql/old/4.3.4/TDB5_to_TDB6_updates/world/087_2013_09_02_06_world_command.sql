/* cs_gm.cpp */

SET @id = 371;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'gm';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'gm chat';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'gm fly';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'gm ingame';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'gm list';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'gm visible';
