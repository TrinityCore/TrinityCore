DELETE FROM `command` WHERE `name` IN ('account set gmlevel','account set seclevel');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('account set gmlevel', 228, 'Syntax: .account set gmlevel [$accountName] #level [#realmID]

Set the security level for targeted player (can\'t be used at self) or for account $accountName to a level of #level on the realm #realmID.

#level may range from 0 to 3.

#realmID - Default: -1 for all realms.

Note: this command will be removed soon. Use \'account set seclevel\' instead.'),

('account set seclevel', 228, 'Syntax: .account set seclevel [$accountName] #level [#realmID]

Set the security level for targeted player (can\'t be used at self) or for account $accountName to a level of #level on the realm #realmID.

#level may range from 0 to 3.

#realmID - Default: -1 for all realms.');
