DELETE FROM `command` WHERE `name` = 'account email';
DELETE FROM `command` WHERE `name` = 'account set sec email';
DELETE FROM `command` WHERE `name` = 'account set sec regmail';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('account email', 263, 'Syntax: .account email $oldemail $currentpassword $newemail $newemailconfirmation\r\n\r\n Change your account email. You may need to check the actual security mode to see if email input is necessary for password change'),
('account set sec email', 265, 'Syntax: .account set sec email $accountname $email $emailconfirmation\r\n\r\nSet the email for entered player account.'),
('account set sec regmail', 266, 'Syntax: .account set sec regmail $account $regmail $regmailconfirmation\r\n\r\nSets the regmail for entered player account.');

/* cs_cast.cpp */

SET @id = 267;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'cast';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'cast back';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'cast dist';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'cast self';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'cast target';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'cast dest';

/* cs_go.cpp */

SET @id = 377;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'go';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'go creature';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'go graveyard';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'go grid';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'go object';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'go taxinode';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'go ticket';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'go trigger';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'go xyz';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'go zonexy';

/* cs_gobject.cpp */

SET @id = 387;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'gobject';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'gobject activate';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'gobject add';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'gobject add temp';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'gobject delete';
UPDATE `command` SET `permission` = @id+5 WHERE `name` = 'gobject info';
UPDATE `command` SET `permission` = @id+6 WHERE `name` = 'gobject move';
UPDATE `command` SET `permission` = @id+7 WHERE `name` = 'gobject near';
UPDATE `command` SET `permission` = @id+8 WHERE `name` = 'gobject set';
UPDATE `command` SET `permission` = @id+9 WHERE `name` = 'gobject set phase';
UPDATE `command` SET `permission` = @id+10 WHERE `name` = 'gobject set state';
UPDATE `command` SET `permission` = @id+11 WHERE `name` = 'gobject target';
UPDATE `command` SET `permission` = @id+12 WHERE `name` = 'gobject turn';

/* cs_instance.cpp */

SET @id = 412;

-- Update command table with new RBAC permissions
UPDATE `command` SET `permission` = @id+0 WHERE `name` = 'instance';
UPDATE `command` SET `permission` = @id+1 WHERE `name` = 'instance listbinds';
UPDATE `command` SET `permission` = @id+2 WHERE `name` = 'instance unbind';
UPDATE `command` SET `permission` = @id+3 WHERE `name` = 'instance stats';
UPDATE `command` SET `permission` = @id+4 WHERE `name` = 'instance savedata';
