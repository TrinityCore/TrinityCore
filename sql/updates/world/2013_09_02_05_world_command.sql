/* cs_event.cpp */

SET @id = 367;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'event';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'event activelist';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'event start';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'event stop';
