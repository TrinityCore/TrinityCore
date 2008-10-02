DELETE FROM command WHERE name IN ('createguild','guild create','guild delete','guild invite','guild rank','guild uninvite');

INSERT INTO `command` VALUES 
('guild create',2,'Syntax: .guild create $GuildLeaderName $GuildName\r\n\r\nCreate a guild named $GuildName with the player $GuildLeaderName as leader.'),
('guild delete',2,'Syntax: .guild delete $GuildName\r\n\r\nDelete guild $GuildName.'),
('guild invite',2,'Syntax: .guild invite $CharacterName $GuildName\r\n\r\nAdd $CharacterName into a guild $GuildName.'),
('guild rank',2,'Syntax: .guild rank $CharacterName #Rank\r\n\r\nSet for $CharacterName rank #Rank in a guild.'),
('guild uninvite',2,'Syntax: .guild uninvite $CharacterName\r\n\r\nRemove $CharacterName from a guild.');
