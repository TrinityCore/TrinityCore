/* cs_learn.cpp */

SET @id = 417;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'learn';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'learn all';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'learn all my';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'learn all my class';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'learn all my pettalents';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'learn all my spells';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'learn all my talents';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'learn all gm';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'learn all crafts';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'learn all default';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'learn all lang';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'learn all recipes';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'unlearn');
