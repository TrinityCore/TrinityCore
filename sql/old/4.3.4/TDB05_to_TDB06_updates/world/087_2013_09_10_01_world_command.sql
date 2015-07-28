/* cs_group.cpp */

SET @id = 472;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0  WHERE `name` = 'group';
UPDATE `command` SET `permission` = @id+1  WHERE `name` = 'group leader';
UPDATE `command` SET `permission` = @id+2  WHERE `name` = 'group disband';
UPDATE `command` SET `permission` = @id+3  WHERE `name` = 'group remove';
UPDATE `command` SET `permission` = @id+4  WHERE `name` = 'group join';
UPDATE `command` SET `permission` = @id+5  WHERE `name` = 'group list';

UPDATE `command` SET `permission` = @id+6, `name` = 'group summon', `help` =
'Syntax: .group summon [$charactername]\r\n\r\nTeleport the given character and his group to you. Teleported only online characters but original selected group member can be offline.'
WHERE `name` = 'groupsummon';
