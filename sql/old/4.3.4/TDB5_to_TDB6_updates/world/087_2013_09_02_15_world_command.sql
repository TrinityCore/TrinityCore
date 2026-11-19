/* cs_lookup.cpp */

SET @id = 442;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'lookup';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'lookup area';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'lookup creature';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'lookup event';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'lookup faction';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'lookup item';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'lookup itemset';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'lookup object';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'lookup quest';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'lookup player';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'lookup player ip';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'lookup player account';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'lookup player email';
UPDATE `command` SET `permission` = @id+13 WHERE `name` = 'lookup skill';
UPDATE `command` SET `permission` = @id+14 WHERE `name` = 'lookup spell';
UPDATE `command` SET `permission` = @id+15 WHERE `name` = 'lookup spell id';
UPDATE `command` SET `permission` = @id+16 WHERE `name` = 'lookup taxinode';
UPDATE `command` SET `permission` = @id+17 WHERE `name` = 'lookup tele';
UPDATE `command` SET `permission` = @id+18 WHERE `name` = 'lookup title';
UPDATE `command` SET `permission` = @id+19 WHERE `name` = 'lookup map';
