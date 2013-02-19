/*ALTER TABLE db_version CHANGE COLUMN required_7886_01_mangos_petcreateinfo_spell required_7893_01_mangos_command bit;*/

DELETE FROM `command` WHERE `name` IN ('guild create','guild delete','guild invite');
INSERT INTO `command` VALUES
('guild create',2,'Syntax: .guild create [$GuildLeaderName] "$GuildName"\r\n\r\nCreate a guild named $GuildName with the player $GuildLeaderName (or selected) as leader.  Guild name must in quotes.'),
('guild invite',2,'Syntax: .guild invite [$CharacterName] "$GuildName"\r\n\r\nAdd player $CharacterName (or selected) into a guild $GuildName. Guild name must in quotes.'),
('guild delete',2,'Syntax: .guild delete "$GuildName"\r\n\r\nDelete guild $GuildName. Guild name must in quotes.');
