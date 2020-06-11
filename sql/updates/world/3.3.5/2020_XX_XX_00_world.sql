UPDATE `command` SET `name` = 'account set seclevel', `help` = 'Syntax: .account set seclevel [$accountName] #level [#realmID]

Set the security level for targeted player (can\'t be used at self) or for account $name to a level of #level on the realm #realmID.

#level may range from 0 to 3.

#realmID may be -1 for all realms.' WHERE `permission` = 228;
