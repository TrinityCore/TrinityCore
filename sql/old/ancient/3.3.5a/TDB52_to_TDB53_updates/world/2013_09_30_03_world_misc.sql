DELETE FROM `command` WHERE `permission` BETWEEN 200 AND 216;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('rbac account list',   202, 'Syntax: rbac account list [$account]\n\nView permissions of selected player or given account\nNote: Only those that affect current realm'),
('rbac account grant',  203, 'Syntax: rbac account grant [$account] #id [#realmId]\n\nGrant a permission to selected player or given account.\n\n#reamID may be -1 for all realms.'),
('rbac account deny',   204, 'Syntax: rbac account deny [$account] #id [#realmId]\n\nDeny a permission to selected player or given account.\n\n#reamID may be -1 for all realms.'),
('rbac account revoke', 205, 'Syntax: rbac account revoke [$account] #id\n\nRemove a permission from an account\n\nNote: Removes the permission from granted or denied permissions'),
('rbac list',           206, 'Syntax: rbac list [$id]\n\nView list of all permissions. If $id is given will show only info for that permission.');
