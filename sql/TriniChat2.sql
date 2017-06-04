/*
* Table structure for irc_commands
*/
DROP TABLE IF EXISTS `irc_commands`;
CREATE TABLE `irc_commands` (
  `Command` varchar(10) NOT NULL default '',
  `Description` varchar(350) default NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`Command`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='IRC Module System';

/*
* Records
*/
INSERT INTO `irc_commands` VALUES
('acct', '[acct <Player> <(un)lock/email/pass/rename/gmlevel>] : Perform Action To <Player> Account.', '3'),
('ban', '[ban <Player/IP> <ip/acct/unban/reason>] : Ban/Unban <Player>', '3'),
('chan', '[chan <op/deop/voice/devoice> <*IRC Nick*>] : Set Mode On Yourself, If <IRC Nick> Is Specified Then Set mode On Nick.', '3'),
('char', '[char <Player> <mailcheat/taxicheat/maxskill/setskill/combatstop/quest/mod>] : Perform Action To Character.', '3'),
('fun', '[fun <Player> <Sound/Say>] : Do Selected Fun Action To <Player>.', '3'),
('help', '[help Command] : Use No Paramaters For List Of Available Commands.', '0'),
('inchan', '[inchan <Channel>] : Display Users In Selected In Game <Channel>', '0'),
('info', '[info] : Display Server Info. (Number Of Players Online/Max Since Last Restart/Uptime)', '0'),
('item', '[item <Player> <add> <ItemID/[ItemName]> <Amount>] : Additem To <Player>, Use <ItemID> Or <[Exact Item Name]>.', '3'),
('jail', '[jail <Player> <release/Reason>] : Jail Selected <Player> For <Reason>. Using release As <Reason> Releases Player.', '3'),
('kick', '[kick <Player> <Reason>] : Kick <Player> For <Reason>.', '3'),
('kill', '[kill <Player> <Reason>] : Kill <Player> For <Reason>.', '3'),
('level', '[level <Player> <NewLevel>] : Level <Player> To <NewLevel>. *Can Be Done Offline*', '3'),
('login', '[login <UserName> <Password>] : Login To TriniChat Admin Mode.  (Must Be Done In A PM)', '0'),
('logout', '[logout] : Logout Of TriniChat Admin Mode.', '0'),
('lookup', '[lookup <acct/char/creature/faction/go/item/quest/skill/spell/tele> <ID/Name>] : ', '3'),
('money', '[money <Player> <(-)Money>] : Give Money To <Player>, Use - To Take Money. *Can Be Done Offline*', '3'),
('mute', '[mute <Player> <release/TimeInMins> <Reason>] : Mute Player For Reason, For <TimeInMins>. Using release As Time Releases Player. *Can Be Done Offline*', '3'),
('online', '[online] : Display All Users Logged In Game.', '0'),
('pm', '[pm <Player> <Message>] : Whisper <Player> In WoW <Message>.', '3'),
('reload', '[reload] : Reload TriniChat Config Options And Security Level From DataBase.', '3'),
('restart', '[restart] : Restart TriniChat, NOT Trinity Core World Server Itself. Forces Reconnection To IRC Server.', '3'),
('revive', '[revive <Player>] : Revive <Player>.', '3'),
('saveall', '[saveall] : Forces Trinity Core To Save All Players.', '3'),
('server', '[server setmotd [<motd>]/flusharenapoints]', '3'),
('shutdown', '[shutdown <TimeInSeconds>] : Shuts The Server Down In <TimeInSeconds>, Use 0 For Immediate Shut Down', '3'),
('spell', '[spell <Player> <Cast/Learn/UnLearn> <SpellID>] : Make <Player> <Learn> Or <UnLearn> A Spell, Or <Cast> A Spell On A <Player>.', '3'),
('sysmsg', '[sysmsg <a/n/e/add/del/list> <Message>] : Broadcasts A System Message. (a-Broadcast System Message)(n-Broadcast Notify Message)(e-Event Message)', '3'),
('tele', '[tele <Player> <l/c/r/to/cr/go/homebind> <Loc.Name/MAPID X Y Z/Recall/Player/Creature GUID/Gameobject GUID>] : Teleport Player To Location, Coords, Recall Location, Another Player, Creature or Gameobject. (l-Location)(c-Coords)', '3'),
('top', '[top <accttime/chartime/money> <limit>] : Display top stats for given option. Only GM Higher Than Config Option Can Use Limit.', '3'),
('who', '[who] : Displays Users Currently Logged In To TriniChat.', '1');

/*
* Table structure for irc_inchan
*/
DROP TABLE IF EXISTS `irc_inchan`;
CREATE TABLE `irc_inchan` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `name` varchar(12) NOT NULL default '',
  `channel` varchar(15) NOT NULL default '',
  PRIMARY KEY  (`guid`,`channel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='IRC Module System';

/*
* Records
*/
/*
* Table structure for irc_autoannounce
*/
DROP TABLE IF EXISTS `irc_autoannounce`;
CREATE TABLE `irc_autoannounce` (
  `id` int(11) NOT NULL auto_increment,
  `message` longtext NOT NULL,
  `addedby` varchar(12) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COMMENT='IRC Module System';

/*
* Records
*/
INSERT INTO `irc_autoannounce` VALUES ('1', 'Welcome to IRC Channel', '');

DELETE FROM `trinity_string` WHERE entry IN (6620,6621,6622);
INSERT INTO `trinity_string` VALUES ('6620', '|cffff0000[System Message]: %s|r', null, null, null, null, null, null, null, null);
INSERT INTO `trinity_string` VALUES ('6621', '|cffff0000[Server Event]: %s|r', null, null, null, null, null, null, null, null);
INSERT INTO `trinity_string` VALUES ('6622', '|cffff0000[Automatic]: %s|r', null, null, null, null, null, null, null, null);
