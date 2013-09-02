/* cs_lfg.cpp */

SET @id = 430;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'lfg';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'lfg player';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'lfg group';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'lfg queue';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'lfg clean';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'lfg options');
