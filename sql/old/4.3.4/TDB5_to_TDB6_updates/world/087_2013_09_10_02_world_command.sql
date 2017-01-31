/* cs_pet.cpp */

SET @id = 479;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0  WHERE `name` = 'pet';
UPDATE `command` SET `permission` = @id+1  WHERE `name` = 'pet create';
UPDATE `command` SET `permission` = @id+2  WHERE `name` = 'pet learn';
UPDATE `command` SET `permission` = @id+3  WHERE `name` = 'pet unlearn';
