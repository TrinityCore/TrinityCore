/* cs_gobject.cpp */

SET @id = 401;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'guild';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'guild create';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'guild delete';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'guild invite';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'guild uninvite';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'guild rank';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'guild rename');
