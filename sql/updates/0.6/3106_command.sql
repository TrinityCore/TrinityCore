UPDATE `command` SET `help` = 'Syntax: .banaccount $name\r\n\r\nBan account $name (can be viewed by players by using the .pinfo command) and kick affected players currently logged in.' WHERE `name` = 'banaccount';
UPDATE `command` SET `help` = 'Syntax: .banip #ip\r\n\r\nBans logging into the server from computers with the provided IP address, and kicks all affected players.' WHERE `name` = 'banip';
UPDATE `command` SET `help` = 'Syntax: .unbanaccount $name\r\n\r\nUnban account $name.' WHERE `name` = 'unbanaccount';
UPDATE `command` SET `help` = 'Syntax: .unbanip #ip\r\n\r\nUnban the provided IP address from the server.' WHERE `name` = 'unbanip';
UPDATE `command` SET `help` = 'Syntax: .kick [$charactername]\r\n\r\nKick the given character name from the world. If no character name is provided then the selected player (except for yourself) will be kicked.' WHERE `name` = 'kick';
