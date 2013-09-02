/* cs_go.cpp */

SET @id = 371;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'go';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'go creature';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'go graveyard';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'go grid';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'go object';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'go taxinode';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'go ticket';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'go trigger';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'go xyz';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'go zonexy');
