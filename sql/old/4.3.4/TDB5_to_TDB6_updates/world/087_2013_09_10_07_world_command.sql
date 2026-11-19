/* cs_modify.cpp */

SET @id = 542;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'morph';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'demorph';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'modify';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'modify arenapoints';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'modify bit';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'modify drunk';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'modify energy';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'modify faction';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'modify gender';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'modify honor';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'modify hp';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'modify mana';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'modify money';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'modify mount';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'modify phase';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'modify rage';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'modify reputation';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'modify runicpower';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'modify scale';
UPDATE `command` SET `permission` = @id+19 WHERE `name` = 'modify speed';
UPDATE `command` SET `permission` = @id+20 WHERE `name` = 'modify speed all';
UPDATE `command` SET `permission` = @id+21 WHERE `name` = 'modify speed backwalk';
UPDATE `command` SET `permission` = @id+22 WHERE `name` = 'modify speed fly';
UPDATE `command` SET `permission` = @id+23 WHERE `name` = 'modify speed walk';
UPDATE `command` SET `permission` = @id+24 WHERE `name` = 'modify speed swim';
UPDATE `command` SET `permission` = @id+25 WHERE `name` = 'modify spell';
UPDATE `command` SET `permission` = @id+26 WHERE `name` = 'modify standstate';
UPDATE `command` SET `permission` = @id+27 WHERE `name` = 'modify talentpoints';
