/* cs_tele.cpp */

SET @id = 737;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'tele';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'tele add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'tele del';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'tele name';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'tele group';
