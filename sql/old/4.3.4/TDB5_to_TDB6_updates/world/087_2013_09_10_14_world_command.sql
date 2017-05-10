/* cs_ticket.cpp */

SET @id = 742;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'ticket';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'ticket assign';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'ticket close';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'ticket closedlist';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'ticket comment';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'ticket complete';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'ticket delete';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'ticket escalate';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'ticket escalatedlist';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'ticket list';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'ticket onlinelist';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'ticket reset';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'ticket response';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'ticket response append';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'ticket response appendln';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'ticket togglesystem';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'ticket unassign';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'ticket viewid';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'ticket viewname';
