/* cs_cheat.cpp */

SET @id = 291;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'cheat';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'cheat casttime';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'cheat cooldown';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'cheat explore';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'cheat god';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'cheat power';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'cheat status';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'cheat taxi';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'cheat waterwalk';
