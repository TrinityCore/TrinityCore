/* ALTER TABLE db_version CHANGE COLUMN required_7839_01_mangos_mangos_string required_7839_02_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN (
   'baninfo account','baninfo character','baninfo ip','goname','groupgo',
   'guild create','guild invite','guild rank','guild uninvite','mute',
   'namego','tele name','unmute'
);

INSERT INTO `command` VALUES
('baninfo account',3,'Syntax: .baninfo account $accountid\r\nWatch full information about a specific ban.'),
('baninfo character',3,'Syntax: .baninfo character $charactername \r\nWatch full information about a specific ban.'),
('baninfo ip',3,'Syntax: .baninfo ip $ip\r\nWatch full information about a specific ban.'),
('goname',1,'Syntax: .goname [$charactername]\r\n\r\nTeleport to the given character. Either specify the character name or click on the character\'s portrait, e.g. when you are in a group. Character can be offline.'),
('groupgo',1,'Syntax: .groupgo [$charactername]\r\n\r\nTeleport the given character and his group to you. Teleported only online characters but original selected group member can be offline.'),
('guild create',2,'Syntax: .guild create [$GuildLeaderName] $GuildName\r\n\r\nCreate a guild named $GuildName with the player $GuildLeaderName (or selected) as leader.'),
('guild invite',2,'Syntax: .guild invite [$CharacterName] $GuildName\r\n\r\nAdd player $CharacterName (or selected) into a guild $GuildName.'),
('guild rank',2,'Syntax: .guild rank [$CharacterName] #Rank\r\n\r\nSet for player $CharacterName (or selected) rank #Rank in a guild.'),
('guild uninvite',2,'Syntax: .guild uninvite [$CharacterName]\r\n\r\nRemove player $CharacterName (or selected) from a guild.'),
('mute',1,'Syntax: .mute [$playerName] $timeInMinutes\r\n\r\nDisible chat messaging for any character from account of character $playerName (or currently selected) at $timeInMinutes minutes. Player can be offline.'),
('namego',1,'Syntax: .namego [$charactername]\r\n\r\nTeleport the given character to you. Character can be offline.'),
('tele name',1,'Syntax: .tele name [#playername] #location\r\n\r\nTeleport the given character to a given location. Character can be offline.'),
('unmute',1,'Syntax: .unmute [$playerName]\r\n\r\nRestore chat messaging for any character from account of character $playerName (or selected). Character can be ofline.');