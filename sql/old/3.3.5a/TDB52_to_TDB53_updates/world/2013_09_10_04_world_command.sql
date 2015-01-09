/* cs_send.cpp */

SET @id = 483;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0  WHERE `name` = 'send';
UPDATE `command` SET `permission` = @id+1  WHERE `name` = 'send items';
UPDATE `command` SET `permission` = @id+2  WHERE `name` = 'send mail';
UPDATE `command` SET `permission` = @id+3  WHERE `name` = 'send message';
UPDATE `command` SET `permission` = @id+4  WHERE `name` = 'send money';
