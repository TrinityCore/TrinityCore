/* cs_disable.cpp */

SET @id = 348;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'disable';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'disable add';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'disable add achievement_criteria';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'disable add battleground';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'disable add map';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'disable add mmap';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'disable add outdoorpvp';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'disable add quest';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'disable add spell';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'disable add vmap';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'disable remove';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'disable remove achievement_criteria';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'disable remove battleground';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'disable remove map';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'disable remove mmap';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'disable remove outdoorpvp';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'disable remove quest';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'disable remove spell';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'disable remove vmap';
