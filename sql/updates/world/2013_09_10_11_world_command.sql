/* cs_reset.cpp */

SET @id = 710;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'reload';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'reload achievements';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'reload honor';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'reload level';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'reload spells';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'reload stats';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'reload talents';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'reload all';
