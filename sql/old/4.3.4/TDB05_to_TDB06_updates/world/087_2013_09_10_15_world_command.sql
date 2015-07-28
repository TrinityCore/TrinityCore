/* cs_titles.cpp & cs_wp.cpp */

SET @id = 761;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'titles';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'titles add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'titles current';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'titles remove';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'titles set';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'titles set mask';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'wp';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'wp add';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'wp event';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'wp load';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'wp modify';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'wp unload';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'wp reload';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'wp show';
