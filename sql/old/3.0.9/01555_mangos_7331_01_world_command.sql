/*ALTER TABLE db_version CHANGE COLUMN required_7312_01_mangos_mangos_string required_7331_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` = 'account set addon';
DELETE FROM `command` WHERE `name` = 'ban account';
DELETE FROM `command` WHERE `name` = 'ban character';
DELETE FROM `command` WHERE `name` = 'ban ip';
DELETE FROM `command` WHERE `name` = 'baninfo account';
DELETE FROM `command` WHERE `name` = 'baninfo character';
DELETE FROM `command` WHERE `name` = 'baninfo ip';
DELETE FROM `command` WHERE `name` = 'banlist account';
DELETE FROM `command` WHERE `name` = 'banlist character';
DELETE FROM `command` WHERE `name` = 'banlist ip';
DELETE FROM `command` WHERE `name` = 'gm fly';
/* next command deleted even in case it has been already corrected (trailing space) */
DELETE FROM `command` WHERE `name` = 'gobject near ';
DELETE FROM `command` WHERE `name` = 'gobject near';

DELETE FROM `command` WHERE `name` = 'lookup player account';
DELETE FROM `command` WHERE `name` = 'lookup player ip';
DELETE FROM `command` WHERE `name` = 'lookup player email';
DELETE FROM `command` WHERE `name` = 'modify money';
DELETE FROM `command` WHERE `name` = 'modify mount';
DELETE FROM `command` WHERE `name` = 'modify speed';
DELETE FROM `command` WHERE `name` = 'modify titles';
DELETE FROM `command` WHERE `name` = 'pdump write';
DELETE FROM `command` WHERE `name` = 'pdump load';
DELETE FROM `command` WHERE `name` = 'reset honor';
DELETE FROM `command` WHERE `name` = 'reset level';
DELETE FROM `command` WHERE `name` = 'reset spells';
DELETE FROM `command` WHERE `name` = 'reset stats';
DELETE FROM `command` WHERE `name` = 'reset talents';
DELETE FROM `command` WHERE `name` = 'unban account';
DELETE FROM `command` WHERE `name` = 'unban character';
DELETE FROM `command` WHERE `name` = 'unban ip';

INSERT INTO `command` VALUES
('account set addon',3,'Syntax: .account set addon [$account] #addon\r\n\r\nSet user (possible targeted) expansion addon level allowed. Addon values: 0 - normal, 1 - tbc, 2 - wotlk.'),
('ban account',3,'Syntax: .ban account $Name $bantime $reason\r\nBan account kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban character',3,'Syntax: .ban character $Name $bantime $reason\r\nBan account and kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban ip',3,'Syntax: .ban ip $Ip $bantime $reason\r\nBan IP.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('baninfo account',3,'Syntax: .baninfo account\r\nWatch full information about a specific ban.'),
('baninfo character',3,'Syntax: .baninfo character\r\nWatch full information about a specific ban.'),
('baninfo ip',3,'Syntax: .baninfo ip\r\nWatch full information about a specific ban.'),
('banlist account',3,'Syntax: .banlist account [$Name]\r\nSearches the banlist for a account name pattern or show full list account bans.'),
('banlist character',3,'Syntax: .banlist character $Name\r\nSearches the banlist for a character name pattern. Pattern required.'),
('banlist ip',3,'Syntax: .banlist ip [$Ip]\r\nSearches the banlist for a IP pattern or show full list of IP bans.'),
('gm fly',3,'Syntax: .gm fly [on/off]\r\nEnable/disable gm fly mode.'),
('gobject near',3,'Syntax: .gobject near  [#distance]\r\n\r\nOutput gameobjects at distance #distance from player. Output gameobject guids and coordinates sorted by distance from character. If #distance not provided use 10 as default value.'),
('lookup player account',2,'Syntax: .lookup player account $account ($limit) \r\n\r\n Searchs players, which account username is $account with optional parametr $limit of results.'),
('lookup player ip',2,'Syntax: .lookup player ip $ip ($limit) \r\n\r\n Searchs players, which account ast_ip is $ip with optional parametr $limit of results.'),
('lookup player email',2,'Syntax: .lookup player email $email ($limit) \r\n\r\n Searchs players, which account email is $email with optional parametr $limit of results.'),
('modify money',1,'Syntax: .modify money #money\r\n.money #money\r\n\r\nAdd or remove money to the selected player. If no player is selected, modify your money.\r\n\r\n #gold can be negative to remove money.'),
('modify mount',1,'Syntax: .modify mount #id #speed\r\nDisplay selected player as mounted at #id creature and set speed to #speed value.'),
('modify speed',1,'Syntax: .modify speed #rate\r\n.speed #rate\r\n\r\nModify the running speed of the selected player to \"normal base run speed\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 10.'),
('modify titles',1,'Syntax: .modify titles #mask\r\n\r\nAllows user to use all titles from #mask.\r\n\r\n #mask=0 disables the title-choose-field'),
('pdump write',3,'Syntax: .pdump write $filename $playerNameOrGUID\r\nWrite character dump with name/guid $playerNameOrGUID to file $filename.'),
('pdump load',3,'Syntax: .pdump load $filename $account [$newname] [$newguid]\r\nLoad character dump from dump file into character list of $account with saved or $newname, with saved (or first free) or $newguid guid.'),
('reset honor',3,'Syntax: .reset honor [Playername]\r\n  Reset all honor data for targeted character.'),
('reset level',3,'Syntax: .reset level [Playername]\r\n  Reset level to 1 including reset stats and talents.  Equipped items with greater level requirement can be lost.'),
('reset spells',3,'Syntax: .reset spells [Playername]\r\n  Removes all non-original spells from spellbook.\r\n. Playername can be name of offline character.'),
('reset stats',3,'Syntax: .reset stats [Playername]\r\n  Resets(recalculate) all stats of the targeted player to their original VALUESat current level.'),
('reset talents',3,'Syntax: .reset talents [Playername]\r\n  Removes all talents of the targeted player. Playername can be name of offline character.'),
('unban account',3,'Syntax: .unban account $Name\r\nUnban accounts for account name pattern.'),
('unban character',3,'Syntax: .unban character $Name\r\nUnban accounts for character name pattern.'),
('unban ip',3,'Syntax : .unban ip $Ip\r\nUnban accounts for IP pattern.');
