SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for IRC_Commands
-- ----------------------------
DROP TABLE IF EXISTS `IRC_Commands`;
CREATE TABLE `IRC_Commands` (
  `Command` varchar(10) NOT NULL default '',
  `Description` varchar(150) NOT NULL default '',
  `gmlevel` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`Command`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='IRC Module System';

-- ----------------------------
-- Records
-- ----------------------------
INSERT INTO `IRC_Commands` VALUES ('acct', '[acct <Player> <(un)lock/mail/pass/rename>] : Perform Action To <Player> Account.', '3');
INSERT INTO `IRC_Commands` VALUES ('ban', '[ban <Player/IP> <ip/acct/unban/reason>] : Ban/Unban <Player>', '3');
INSERT INTO `IRC_Commands` VALUES ('chan', '[chan <op/deop/voice/devoice> <*IRC Nick*>] : Set Mode On Yourself, If <IRC Nick> Is Specified Then Set mode On Nick.', '3');
INSERT INTO `IRC_Commands` VALUES ('char', '[char <Player> <mailcheat/taxicheat/maxskill/setskill>] : Perform Action To Character.', '3');
INSERT INTO `IRC_Commands` VALUES ('fun', '[fun <Player> <Sound/Say>] : Do Selected Fun Action To <Player>.', '3');
INSERT INTO `IRC_Commands` VALUES ('help', '[help Command] : Use No Paramaters For List Of Available Commands.', '0');
INSERT INTO `IRC_Commands` VALUES ('inchan', '[inchan <Channel>] : Display Users In Selected In Game <Channel>', '0');
INSERT INTO `IRC_Commands` VALUES ('info', '[info] : Display Server Info. (Number Of Players Online/Max Since Last Restart/Uptime)', '0');
INSERT INTO `IRC_Commands` VALUES ('item', '[item <Player> <add> <ItemID/[ItemName]> <Amount>] : Additem To <Player>, Use <ItemID> Or <[Exact Item Name]>.', '3');
INSERT INTO `IRC_Commands` VALUES ('jail', '[jail <Player> <release/Reason>] : Jail Selected <Player> For <Reason>. Using release As <Reason> Releases Player.', '3');
INSERT INTO `IRC_Commands` VALUES ('kick', '[kick <Player> <Reason>] : Kick <Player> For <Reason>.', '3');
INSERT INTO `IRC_Commands` VALUES ('kill', '[kill <Player> <Reason>] : Kill <Player> For <Reason>.', '3');
INSERT INTO `IRC_Commands` VALUES ('level', '[level <Player> <NewLevel>] : Level <Player> To <NewLevel>. *Can Be Done Offline*', '3');
INSERT INTO `IRC_Commands` VALUES ('lookup', '[lookup <acct/char/creature/faction/go/item/quest/skill/spell/tele> <ID/Name>] : ', '3');
INSERT INTO `IRC_Commands` VALUES ('login', '[login <UserName> <Password>] : Login To MangChat Admin Mode.  (Must Be Done In A PM)', '0');
INSERT INTO `IRC_Commands` VALUES ('logout', '[logout] : Logout Of MangChat Admin Mode.', '0');
INSERT INTO `IRC_Commands` VALUES ('money', '[money <Player> <(-)Money>] : Give Money To <Player>, Use - To Take Money. *Can Be Done Offline*', '3');
INSERT INTO `IRC_Commands` VALUES ('mute', '[mute <Player> <release/TimeInMins> <Reason>] : Mute Player For Reason, For <TimeInMins>. Using release As Time Releases Player. *Can Be Done Offline*', '3');
INSERT INTO `IRC_Commands` VALUES ('online', '[online] : Display All Users Logged In Game.', '0');
INSERT INTO `IRC_Commands` VALUES ('pm', '[pm <Player> <Message>] : Whisper <Player> In WoW <Message>.', '3');
INSERT INTO `IRC_Commands` VALUES ('reload', '[reload] : Reload MangChat Config Options And Security Level From DataBase.', '3');
INSERT INTO `IRC_Commands` VALUES ('restart', '[restart] : Restart MangChat, NOT MaNGOS World Server Itself. Forces Reconnection To IRC Server.', '3');
INSERT INTO `IRC_Commands` VALUES ('revive', '[revive <Player>] : Revive <Player>.', '3');
INSERT INTO `IRC_Commands` VALUES ('saveall', '[saveall] : Forces MaNGOS To Save All Players.', '3');
INSERT INTO `IRC_Commands` VALUES ('shutdown', '[shutdown <TimeInSeconds>] : Shuts The Server Down In <TimeInSeconds>, Use 0 For Immediate Shut Down', '3');
INSERT INTO `IRC_Commands` VALUES ('spell', '[spell <Player> <Cast/Learn/UnLearn> <SpellID>] : Make <Player> <Learn> Or <UnLearn> A Spell, Or <Cast> A Spell On A <Player>.', '3');
INSERT INTO `IRC_Commands` VALUES ('sysmsg', '[sysmsg <a/n/e/add/del/list> <Message>] : Broadcasts A System Message. (a-Broadcast System Message)(n-Broadcast Notify Message)(e-Event Message)', '3');
INSERT INTO `IRC_Commands` VALUES ('tele', '[tele <Player> <l/c/r/to> <Loc.Name/MAPID X Y Z/Recall/Player>] : Teleport Player To Location, Coords, Or Another Player. (l-Location)(c-Coords)', '3');
INSERT INTO `IRC_Commands` VALUES ('top', '[top <accttime/chartime/money> <limit>] : Display top stats for given option. Only GM Higher Than Config Option Can Use Limit.', '3');
INSERT INTO `IRC_Commands` VALUES ('who', '[who] : Displays Users Currently Logged In To MangChat.', '1');

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for IRC_Inchan
-- ----------------------------
DROP TABLE IF EXISTS `IRC_Inchan`;
CREATE TABLE `IRC_Inchan` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `name` varchar(12) NOT NULL default '',
  `channel` varchar(15) NOT NULL default '',
  PRIMARY KEY  (`guid`,`channel`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='IRC Module System';

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for IRC_AutoAnnounce
-- ----------------------------
DROP TABLE IF EXISTS `IRC_AutoAnnounce`;
CREATE TABLE `IRC_AutoAnnounce` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `message` longtext NOT NULL,
  `addedby` varchar(12) NOT NULL default '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='IRC Module System';

-- Add ircpm command.
insert into `command` (`name`, `security`, `help`) values ('ircpm', 0, 'Syntax: .ircpm <user> <text>\n\nSends a PM with <text> to <user> on IRC.');

-- Add auto announce string.
insert into `mangos_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) values('746','|cffff0000[Automatic]:|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
