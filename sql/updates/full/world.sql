CREATE TABLE `game_event_battleground_holiday` (
 `event` int(10) unsigned NOT NULL,
 `bgflag` int(10) unsigned NOT NULL default '0',
 PRIMARY KEY  (`event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_disabled`;
CREATE TABLE `spell_disabled` (
  `entry` int(11) unsigned NOT NULL default '0' COMMENT 'Spell entry',
  `disable_mask` int(8) unsigned NOT NULL default '0',
  `comment` varchar(64) NOT NULL default '',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Disabled Spell System';

ALTER TABLE arena_team_member CHANGE played_week games_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wons_week wins_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE played_season games_season int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wons_season wins_season int(10) unsigned NOT NULL default '0';

TRUNCATE  TABLE playercreateinfo_item;

ALTER TABLE `guild_member` DROP INDEX `guid_key` ,
ADD UNIQUE `guid_key` ( `guid` );

ALTER TABLE characters
  CHANGE COLUMN gmstate extra_flags int(11) unsigned NOT NULL default '0';
  
ALTER TABLE `quest_template`
    ADD `RewHonorableKills` mediumint(9) unsigned NOT NULL default '0' AFTER `RewRepValue5`;
	
ALTER TABLE event_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE gameobject_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE quest_end_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE quest_start_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE spell_scripts
  DROP datatext,
  ADD COLUMN dataint int(11) NOT NULL default '0' AFTER datalong2; 

ALTER TABLE creature_movement
  DROP `text1`,
  DROP `text2`,
  DROP `text3`,
  DROP `text4`,
  DROP `text5`,
  ADD COLUMN textid1 int(11) NOT NULL default '0' AFTER waittime,
  ADD COLUMN textid2 int(11) NOT NULL default '0' AFTER textid1,
  ADD COLUMN textid3 int(11) NOT NULL default '0' AFTER textid2,
  ADD COLUMN textid4 int(11) NOT NULL default '0' AFTER textid3,
  ADD COLUMN textid5 int(11) NOT NULL default '0' AFTER textid4;	
	
ALTER TABLE `npc_option`
  CHANGE COLUMN `id` `id` mediumint(8) unsigned NOT NULL default '0',
  CHANGE COLUMN `gossip_id` `gossip_id` mediumint(8) unsigned NOT NULL default '0',
  CHANGE COLUMN `action` `action` mediumint(8) unsigned NOT NULL default '0',
  ADD COLUMN `box_money` int(10) unsigned NOT NULL default '0' AFTER `action`,
  ADD COLUMN `coded` tinyint(3) unsigned NOT NULL default '0' AFTER `box_money`,
  ADD COLUMN `box_text` text AFTER `option_text`;

CREATE TABLE `locales_npc_option` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `option_text_loc1` text,
  `option_text_loc2` text,
  `option_text_loc3` text,
  `option_text_loc4` text,
  `option_text_loc5` text,
  `option_text_loc6` text,
  `option_text_loc7` text,
  `option_text_loc8` text,
  `box_text_loc1` text,
  `box_text_loc2` text,
  `box_text_loc3` text,
  `box_text_loc4` text,
  `box_text_loc5` text,
  `box_text_loc6` text,
  `box_text_loc7` text,
  `box_text_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `creature_template`
  CHANGE COLUMN `flags` `unit_flags` int(10) unsigned NOT NULL default '0',
  CHANGE COLUMN `flag1` `type_flags` int(10) unsigned NOT NULL default '0';

  DELETE FROM `command` WHERE name IN ('possess', 'unpossess');
INSERT INTO `command` (name,security,help) VALUES
('possess',3,'Syntax: .possess\r\n\r\nPossesses indefinitely the selected creature.'),
('unpossess',3,'Syntax: .unpossess\r\n\r\nIf you are possessed, unpossesses yourself; otherwise unpossesses current possessed target.');

  
  
DELETE FROM command WHERE name = 'reload all_locales';
INSERT INTO `command` VALUES
('reload all_locales',3,'Syntax: .reload all_locales\r\n\r\nReload all `locales_*` tables with reload support added and that can be _safe_ reloaded.');

delete from `command` where `name` IN ('senditems','sendmail');
insert into `command` (`name`, `security`, `help`) values
('senditems',3,'Syntax: .senditems #playername "#subject" "#text" itemid1[:count1] itemid2[:count2] ... itemidN[:countN]\r\n\r\nSend a mail to a player. Subject and mail text must be in "". If for itemid not provided related count values then expected 1, if count > max items in stack then items will be send in required amount stacks. All stacks amount in mail limited to 12.'),
('sendmail',1,'Syntax: .sendmail #playername "#subject" "#text"\r\n\r\nSend a mail to a player. Subject and mail text must be in "".');
 
 DELETE FROM `command` WHERE name IN ('bindsight', 'unbindsight');
INSERT INTO `command` (name,security,help) VALUES
('bindsight',3,'Syntax: .bindsight\r\n\r\nBinds vision to the selected unit indefinitely. Cannot be used while currently possessing a target.'),
('unbindsight',3,'Syntax: .unbindsight\r\n\r\nRemoves bound vision. Cannot be used while currently possessing a target.');

  
DELETE FROM trinity_string WHERE entry IN (453);
  
-- add lang strings
DELETE FROM trinity_string WHERE entry BETWEEN 1000 AND 1006;
INSERT INTO trinity_string VALUES
(1000,'You froze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1001,'It might be amusing but no... you cant freeze yourself!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1002,'Invalid input check the name of target.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1003,'You unfroze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1004,'There are no frozen players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1005,'Following players are frozen on the server:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1006,'- %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- add commands
DELETE FROM `command` WHERE `name` = 'freeze' or `name` = 'unfreeze' or name = 'listfreeze';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('freeze','2','Syntax: .freeze (#player)\r\n\"Freezes\" #player and disables his chat. When using this without #name it will freeze your target.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('unfreeze','2','Syntax: .unfreeze (#player)\r\n\"Unfreezes\" #player and enables his chat again. When using this without #name it will unfreeze your target.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('listfreeze','1','Syntax: .listfreeze\r\n\r\nSearch and output all frozen players.');

-- Add/Edit/Move lang strings
DELETE FROM `trinity_string` WHERE `entry` IN (25,52,54,55,56,171,401,413,438,593,594,595,596,597,598,599,614,615,636,637,638,809,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1100,1101,1102,1103,1104,1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118);
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '667' AND '687';
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '711' AND '716';
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '730' AND '747';
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '5000' AND '5006';
INSERT INTO trinity_string VALUES
('25','Password not changed (unknown error)!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('52', 'Invaid item count (%u) for item %u', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('54','The new passwords do not match',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('55','Your password can\'t be longer than 16 characters (client limit), password not changed!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('56','Current Message of the day: \r\n%s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(171,'You are being teleported by server console command.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(401,'You change security level of account %s to %i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(413,'Account not exist: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(438,'Found items %u: %u ( inventory %u mail %u auction %u guild %u)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(593,'Currently Banned Accounts:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(594,'|    Account    |   BanDate    |   UnbanDate  |  Banned By    |   Ban Reason  |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(595,'Currently Banned IPs:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(596,'|      IP       |   BanDate    |   UnbanDate  |  Banned By    |   Ban Reason  |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(597,'Current gamemasters:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(598,'|    Account    |  GM  |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(599,'No gamemasters.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('614', 'The Alliance flag has been respawned!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('615', 'The Horde flag has been respawned!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('636', 'The Battle for Eye of the Storm begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('637', 'The Battle for Eye of the Storm begins in 30 seconds.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('638', 'The Battle for Eye of the Storm has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('667', 'The Alliance has taken control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('668', 'The Horde has taken control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('669', 'The Alliance has taken control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('670', 'The Horde has taken control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('671', 'The Alliance has taken control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('672', 'The Horde has taken control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('673', 'The Alliance has taken control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('674', 'The Horde has taken control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('675', 'The Alliance has lost control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('676', 'The Horde has lost control of the Mage Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('677', 'The Alliance has lost control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('678', 'The Horde has lost control of the Draenei Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('679', 'The Alliance has lost control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('680', 'The Horde has lost control of the Blood Elf Tower!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('681', 'The Alliance has lost control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('682', 'The Horde has lost control of the Fel Reaver Ruins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('683', '$N has taken the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('684', 'The Alliance has captured the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('685', 'The Horde has captured the flag!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('686', 'The Flag has been dropped!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('687', 'The flag has been reset', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('711', 'Your group is too large for this battleground. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('712', 'Your group is too large for this arena. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('713', 'You must be level %u to join an arena team!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('714', '%s is not high enough level to join your team', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('715', 'You don\'t meet Battleground level requirements', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('716', 'Your arena team is full, %s cannot join it.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('730', 'Your group has members not in your arena team. Please regroup to join.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('731', 'Your group does not have enough players to join this match.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('732', 'The Gold Team wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('733', 'The Green Team wins!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('734', 'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('735', 'Your group has an offline member. Please remove him before joining.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('736', 'Your group has players from the opposing faction. You can\'t join the battleground as a group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('737', 'Your group has players from different battleground brakets. You can\'t join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('738', 'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('739', 'Someone in your party is Deserter. You can\'t join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('740', 'Someone in your party is already in three battleground queues. You cannot join as group.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('741', 'You cannot teleport to a battleground or arena map.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('742', 'You cannot summon players to a battleground or arena map.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('743', 'You must be in GM mode to teleport to a player in a battleground.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('744', 'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('745', 'Arena testing turned %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('746','|cffff0000[Automatic]:|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('747','|cffffff00[|c1f40af20Announce by|r |cffff0000%s|cffffff00]:|r %s|r', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
('809','Account for character %s not found',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1000','Exiting daemon...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1001','Account deleted: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1002','Account %s NOT deleted (probably sql file format was updated)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1003','Account %s NOT deleted (unknown error)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1004','Account created: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
('1005','Account name can\'t be longer than 16 characters (client limit), account not created!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1006,'Account with this name already exist!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1007,'Account %s NOT created (probably sql file format was updated)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1008,'Account %s NOT created (unknown error)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1009,'Player %s (Guid: %u) Account %s (Id: %u) deleted.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1010,'|    Account    |       Character      |       IP        | GM | TBC |',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1011,'|<Error>        | %20s |<Error>          |<Er>|<Err>|',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1100,'Account %s (Id: %u) have up to %u expansion allowed now.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1101,'Message of the day changed to:\r\n%s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1102,'Message sent to %s: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1103,'%d - %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1104,'%d - %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1105,'%d - %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1106,'%d - %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1107,'%d - %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1108,'%d - %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1109,'%d - %s %s %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1110,'%d - %s X:%f Y:%f Z:%f MapId:%d',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1111,'%d - %s X:%f Y:%f Z:%f MapId:%d',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1112,'Failed to open file: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1113,'Account %s (%u) have max amount allowed characters (client limit)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1114,'Dump file has broken data!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1115,'Invalid character name!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1116,'Invalid character guid!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1117,'Character guid %u in use!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1118,'%d - guild: %s (guid: %u) %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5000,'You froze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5001,'It might be amusing but no... you cant freeze yourself!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5002,'Invalid input check the name of target.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5003,'You unfroze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5004,'There are no frozen players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5005,'Following players are frozen on the server:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5006,'- %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


-- cleanup command syntax
DELETE FROM command WHERE name IN (
  'gm ingame','gm online',
  'ban','ban account','ban character','ban ip',
  'baninfo','baninfo account','baninfo character','baninfo ip','pdump load',
  'banlist','banlist account','banlist character','banlist ip','help','transport',
  'unban','unban account','unban character','unban ip','list item','pdump write',
  'acct','account','account create','account delete','account onlinelist',
  'account set addon','account set gmlevel','account set password',
  'chardelete','gm list','gm online','sendmessage','server corpses','server exit','server motd',
  'server set loglevel','server set motd','security'

);

INSERT INTO command VALUES
('gm ingame',0,'Syntax: .gm ingame\r\n\r\nDisplay a list of available in game Game Masters.'),
('ban account',3,'Syntax is: ban account $Name $bantime $reason\r\nBan account kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban character',3,'Syntax is: ban character $Name $bantime $reason\r\nBan account and kick player.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('ban ip',3,'Syntax is: ban ip $Ip $bantime $reason\r\nBan IP.\r\n$bantime: negative value leads to permban, otherwise use a timestring like \"4d20h3s\".'),
('baninfo account',3,'Syntax is: baninfo account\r\nWatch full information about a specific ban.'),
('baninfo character',3,'Syntax is: baninfo character\r\nWatch full information about a specific ban.'),
('baninfo ip',3,'Syntax is: baninfo ip\r\nWatch full information about a specific ban.'),
('banlist account',3,'Syntax is: banlist account [$Name]\r\nSearches the banlist for a account name pattern or show full list account bans.'),
('banlist character',3,'Syntax is: banlist character $Name\r\nSearches the banlist for a character name pattern. Pattern required.'),
('banlist ip',3,'Syntax is: banlist ip [$Ip]\r\nSearches the banlist for a IP pattern or show full list of IP bans.'),
('unban account',3,'Syntax is: unban account $Name\r\nUnban accounts for account name pattern.'),
('unban character',3,'Syntax is: unban character $Name\r\nUnban accounts for character name pattern.'),
('unban ip',3,'Syntax is: unban ip $Ip\r\nUnban accounts for IP pattern.'),
('pdump write',3,'Syntax is: pdump write $filename $playerNameOrGUID\r\nWrite character dump with name/guid $playerNameOrGUID to file $filename.'),
('pdump load',3,'Syntax is: pdump load $filename $account [$newname] [$newguid]\r\nLoad character dump from dump file into character list of $account with saved or $newname, with saved (or first free) or $newguid guid.'),
('list item',3,'Syntax: .list item #item_id [#max_count]\r\n\r\nOutput items with item id #item_id found in all character inventories, mails, auctions, and guild banks. Output item guids, item owner guid, owner account and owner name (guild name and guid in case guild bank). Will be output maximum #max_count items. If #max_count not provided use 10 as default value.'),
('help',0,'Syntax: .help [$command]\r\n\r\nDisplay usage instructions for the given $command. If no $command provided show list available commands.'),
('account',0,'Syntax: .account\r\n\r\nDisplay the access level of your account.'),
('account create',4,'Syntax: .account create $account $password\r\n\r\nCreate account and set password to it.'),
('account delete',4,'Syntax: .account delete $account\r\n\r\nDelete account with all characters.'),
('account onlinelist',4,'Syntax: .account onlinelist\r\n\r\nShow list of online accounts.'),
('account set addon',3,'Syntax: .account set addon [$account] #addon\r\n\r\nSet user (posible targeted) expansion addon level allowed. Addon values: 0 - normal, 1 - tbc, 2 - wotlk.'),
('account set gmlevel',4,'Syntax: .account set gmlevel [$account] #level\r\n\r\nSet the security level for targeted player (can''t be used at self) or for account $name to a level of #level.\r\n\r\n#level may range from 0 to 3.'),
('account set password',4,'Syntax: .account set password $account $password $password\r\n\r\nSet password for account.'),
('chardelete',4,'Syntax: .chardelete $charactername\r\n\r\nDelete character.'),
('gm list',3,'Syntax: .gm list\r\n\r\nDisplay a list of all Game Masters accounts and security levels.'),
('gm online',0,'Syntax: .gm online\r\n\r\nDisplay a list of available Game Masters.'),
('sendmessage',3,'Syntax: .sendmessage $playername $message\r\n\r\nSend screen message to player from ADMINISTRATOR.'),
('server corpses',2,'Syntax: .server corpses\r\n\r\nTriggering corpses expire check in world.'),
('server exit',4,'Syntax: .server exit\r\n\r\nTerminate Trinity NOW.'),
('server motd',0,'Syntax: .server motd\r\n\r\nShow server Message of the day.'),
('server set loglevel',4,'Syntax: .server set loglevel #level\r\n\r\nSet server log level (0 - errors only, 1 - basic, 2 - detail, 3 - debug).'),
('server set motd',3,'Syntax: .server set motd $MOTD\r\n\r\nSet server Message of the day.');

DELETE FROM command WHERE name IN ('npc follow','npc unfollow','waterwalk','repairitems');

INSERT INTO command VALUES
('repairitems',2,'Syntax: .repairitems\r\n\r\nRepair all selected player''s items.'),
('npc follow',2,'Syntax: .npc follow\r\n\r\nSelected creature start follow you until death/fight/etc.'),
('npc unfollow',2,'Syntax: .npc unfollow\r\n\r\nSelected creature (non pet) stop follow you.'),
('waterwalk',2,'Syntax: .waterwalk on/off\r\n\r\nSet on/off waterwalk state for selected player or self if no player selected.');

DELETE FROM trinity_string WHERE entry IN (171,172,336,337,338,339,340,341,342,5007,5008);

INSERT INTO trinity_string VALUES
(172,'server console command',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(336,'You repair all %s''s items.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(337,'All your items repaired by %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(338,'You set waterwalk mode %s for %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(339,'Your waterwalk mode set to %s by %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(340,'%s is now following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(341,'%s is not following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(342,'%s is now not following you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(810,'You must be in a raid group to enter the instance %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(811,'You cannot enter %s while in a ghost mode!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM trinity_string WHERE entry IN (57,58,5009);

INSERT INTO trinity_string VALUES
(57,'Using World DB: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(58,'Using script library: %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(5009,'Sound %u Played to server',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM `command` WHERE name IN ('pet create','pet learn','pet unlearn','pet tp','gobject activate','playall');
INSERT INTO `command` (name,security,help) VALUES
('pet create',2,'Syntax: .pet create\r\n\r\nCreates a pet of the selected creature.'),
('pet learn',2,'Syntax: .pet learn\r\n\r\nLearn #spellid to pet.'),
('pet unlearn',2,'Syntax: .pet unlean\r\n\r\nunLearn #spellid to pet.'),
('pet tp',2,'Syntax: .pet tp #\r\n\r\nChange pet\'s amount of training points.'),
('modify gender',2,'Syntax: .modify gender\r\n\r\n.modify gender #male/female - Turns selected player into a male or female'),
('gobject activate',2,'Syntax: .gobject activate #guid\r\n\r\nActivates an object like a door or a button.'),
('playall',2,'Syntax: .playall #soundid\r\n\r\nPlayer a sound to whole server.');

DELETE FROM trinity_string WHERE entry IN (1119,1120,1121);

INSERT INTO trinity_string VALUES
(1119,'You must use male or female as gender.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1120,'You change gender of %s to %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1121,'Your gender changed to %s by %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


DELETE FROM command WHERE name IN ('modify gender');

INSERT INTO command VALUES
('modify gender',2,'Syntax: .modify gender male/female\r\n\r\nChange gender of selected player.');


delete from `command` where `name` IN ('senditems','sendmail');
insert into `command` (`name`, `security`, `help`) values
('senditems',3,'Syntax: .senditems #playername "#subject" "#text" itemid1[:count1] itemid2[:count2] ... itemidN[:countN]\r\n\r\nSend a mail to a player. Subject and mail text must be in "". If for itemid not provided related count values then expected 1, if count > max items in stack then items will be send in required amount stacks. All stacks amount in mail limited to 12.'),
('sendmail',1,'Syntax: .sendmail #playername "#subject" "#text"\r\n\r\nSend a mail to a player. Subject and mail text must be in "".');


delete from `command` where `name` = 'sendmoney';
insert into `command` (`name`, `security`, `help`) values
('sendmoney',3,'Syntax: .sendmoney #playername "#subject" "#text" #money\r\n\r\nSend mail with money to a player. Subject and mail text must be in "".');


DELETE FROM trinity_string WHERE entry IN (453);


DROP TABLE IF EXISTS `db_script_string`;
CREATE TABLE `db_script_string` (
  `entry` int(11) unsigned NOT NULL default '0',
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


DELETE FROM `command` WHERE `name` IN (
  'server exit',
  'server idleshutdown',
  'server idleshutdown cancel',
  'server idlerestart',
  'server idlerestart cancel',
  'server restart',
  'server restart cancel',
  'server shutdown',
  'server shutdown cancel'
);

INSERT INTO `command` (`name`, `security`, `help`) VALUES
('server exit',4,'Syntax: .server exit\r\n\r\nTerminate mangosd NOW. Exit code 0.'),
('server idleshutdown',3,'Syntax: .server idleshutdown #delay [#exist_code]\r\n\r\nShut the server down after #delay seconds if no active connections are present (no players). Use #exist_code or 0 as program exist code.'),
('server idleshutdown cancel',3,'Syntax: .server idleshutdown cancel\r\n\r\nCancel the restart/shutdown timer if any.'),
('server idlerestart',3,'Syntax: .server idlerestart #delay\r\n\r\nRestart the server after #delay seconds if no active connections are present (no players). Use #exist_code or 2 as program exist code.'),
('server idlerestart cancel',3,'Syntax: .server idlerestart cancel\r\n\r\nCancel the restart/shutdown timer if any.'),
('server restart',3,'Syntax: .server restart #delay\r\n\r\nRestart the server after #delay seconds. Use #exist_code or 2 as program exist code.'),
('server restart cancel',3,'Syntax: .server restart cancel\r\n\r\nCancel the restart/shutdown timer if any.'),
('server shutdown',3,'Syntax: .server shutdown #delay [#exist_code]\r\n\r\nShut the server down after #delay seconds. Use #exist_code or 0 as program exist code.'),
('server shutdown cancel',3,'Syntax: .server shutdown cancel\r\n\r\nCancel the restart/shutdown timer if any.');

DELETE FROM trinity_string WHERE entry IN (251);
INSERT INTO trinity_string VALUES
(251,'Text%d (ID: %i): %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 770 AND 787;
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES
(770,'Your group has members not in your arena team. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(771,'Your group does not have enough players to join this match.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(772,'The Gold Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(773,'The Green Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(774,'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(775,'Your group has an offline member. Please remove him before joining.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(776,'Your group has players from the opposing faction. You can\'t join the battleground as a group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(777,'Your group has players from different battleground brakets. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(778,'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(779,'Someone in your party is Deserter. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(780,'Someone in your party is already in three battleground queues. You cannot join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(781,'You cannot teleport to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(782,'You cannot summon players to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(783,'You must be in GM mode to teleport to a player in a battleground.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(784,'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(785,'Arena testing turned %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(786,'|cffff0000[Automatic]:|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(787,'|cffffff00[|c1f40af20Announce by|r |cffff0000%s|cffffff00]:|r %s|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);