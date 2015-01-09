DELETE FROM `command` WHERE `name` = 'guild rename';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('guild rename', 3, 'Syntax: .guild rename "$GuildName" "$NewGuildName" \n\n Rename a guild named $GuildName with $NewGuildName. Guild name and new guild name must in quotes.');

SET @ENTRY1 := 96;
SET @ENTRY2 := 97;
DELETE FROM `trinity_string` WHERE `entry` IN (@ENTRY1, @ENTRY2);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@ENTRY1, 'The guild name \'%s\' is already taken'),
(@ENTRY2, 'Changed guild name \'%s\' to \'%s\'');
