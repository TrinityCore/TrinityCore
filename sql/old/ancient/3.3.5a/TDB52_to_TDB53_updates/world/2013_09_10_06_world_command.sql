/* cs_mmaps.cpp */

SET @id = 536;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'mmap';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'mmap loadedtiles';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'mmap loc';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'mmap path';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'mmap stats';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'mmap testarea';
