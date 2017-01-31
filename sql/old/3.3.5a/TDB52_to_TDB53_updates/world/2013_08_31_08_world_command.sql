/* cs_bf.cpp */

SET @id = 257;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'bf';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'bf start';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'bf stop';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'bf switch';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'bf timer';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'bf enabled';

