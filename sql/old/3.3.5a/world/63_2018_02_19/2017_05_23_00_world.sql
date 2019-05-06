-- correct typo in account set gmlevel command help
UPDATE `command` SET `help`="Syntax: .account set gmlevel [$account] #level [#realmID]\r\n\r\nSet the security level for targeted player (can't be used at self) or for account $name to a level of #level on the realm #realmID.\r\n\r\n#level may range from 0 to 3.\r\n\r\n#realmID may be -1 for all realms." WHERE `name`='account set gmlevel';
