/* cs_honor.cpp */

SET @id = 408;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'honor';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'honor add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'honor add kill';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'honor update';
