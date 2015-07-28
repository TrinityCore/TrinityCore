/* cs_server.cpp */

SET @id = 718;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'server';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'server corpses';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'server exit';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'server idlerestart';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'server idlerestart cancel';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'server idleshutdown';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'server idleshutdown cancel';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'server info';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'server plimit';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'server restart';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'server restart cancel';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'server set';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'server set closed';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'server set difftime';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'server set loglevel';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'server set motd';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'server shutdown';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'server shutdown cancel';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'server motd';
