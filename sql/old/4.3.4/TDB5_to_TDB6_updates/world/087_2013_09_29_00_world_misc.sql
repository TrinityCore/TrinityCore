DELETE FROM `trinity_string` WHERE `entry` IN (65, 66, 67, 68, 69, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 93, 94);
UPDATE `trinity_string` SET `entry` = 65 WHERE `entry` = 90;
UPDATE `trinity_string` SET `entry` = 66 WHERE `entry` = 91;
UPDATE `trinity_string` SET `entry` = 68 WHERE `entry` = 95;
UPDATE `trinity_string` SET `entry` = `entry` - 10 WHERE `entry` BETWEEN 82 AND 89;

INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(67, 'Account %u (%s) inherited permissions by sec level %u:'),
(69, 'Linked permissions:');

DELETE FROM `command` WHERE `permission` BETWEEN 200 AND 213;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('.rbac account list',   202, 'Syntax: rbac account list [$account]\n\nView permissions of selected player or given account\nNote: Only those that affect current realm'),
('.rbac account grant',  203, 'Syntax: rbac account grant [$account] #id [#realmId]\n\nGrant a permission to selected player or given account.\n\n#reamID may be -1 for all realms.'),
('.rbac account deny',   204, 'Syntax: rbac account deny [$account] #id [#realmId]\n\nDeny a permission to selected player or given account.\n\n#reamID may be -1 for all realms.'),
('.rbac account revoke', 205, 'Syntax: rbac account revoke [$account] #id\n\nRemove a permission from an account\n\nNote: Removes the permission from granted or denied permissions'),
('.rbac list',           206, 'Syntax: rbac list [$id]\n\nView list of all permissions. If $id is given will show only info for that permission.');
