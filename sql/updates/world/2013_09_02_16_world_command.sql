/* cs_message.cpp */

SET @id = 458;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'announce';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'channel';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'channel set';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'channel set ownership';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'gmannounce';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'gmnameannounce';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'gmnotify';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'nameannounce';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'notify';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'whispers');
