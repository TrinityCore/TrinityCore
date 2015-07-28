/* cs_deserter.cpp */

SET @id = 341;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'deserter';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'deserter bg';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'deserter bg add';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'deserter bg remove';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'deserter instance';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'deserter instance add';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'deserter instance remove';
