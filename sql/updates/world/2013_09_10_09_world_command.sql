/* cs_npc.cpp */

SET @id = 602;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'quest';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'quest add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'quest complete';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'quest remove';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'quest reward';
