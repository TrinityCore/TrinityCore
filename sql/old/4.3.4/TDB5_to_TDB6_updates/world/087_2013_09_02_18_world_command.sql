/* cs_character.cpp */

SET @id = 273;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0  WHERE `name` = 'character';
UPDATE `command` SET `permission` = @id+1  WHERE `name` = 'character customize';
UPDATE `command` SET `permission` = @id+2  WHERE `name` = 'character changefaction';
UPDATE `command` SET `permission` = @id+3  WHERE `name` = 'character changerace';
UPDATE `command` SET `permission` = @id+4  WHERE `name` = 'character deleted';
UPDATE `command` SET `permission` = @id+5  WHERE `name` = 'character deleted delete';
UPDATE `command` SET `permission` = @id+6  WHERE `name` = 'character deleted list';
UPDATE `command` SET `permission` = @id+7  WHERE `name` = 'character deleted restore';
UPDATE `command` SET `permission` = @id+8  WHERE `name` = 'character deleted old';
UPDATE `command` SET `permission` = @id+9  WHERE `name` = 'character erase';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'character level';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'character rename';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'character reputation';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'character titles';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'levelup';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'pdump';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'pdump load';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'pdump write';
