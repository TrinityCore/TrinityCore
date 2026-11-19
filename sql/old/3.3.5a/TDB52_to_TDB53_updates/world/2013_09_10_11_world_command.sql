/* cs_reset.cpp */

SET @id = 710;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'reset';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'reset achievements';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'reset honor';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'reset level';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'reset spells';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'reset stats';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'reset talents';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'reset all';
