UPDATE `command` SET `help` = 'Syntax: .saveall\r\n\r\nSave all characters in game.' WHERE `name` = 'saveall'; 
UPDATE `command` SET `help` = 'Syntax: .recall $place\r\n\r\nTeleport you to various towns around the world. $place defines the target location. Available places include sunr, thun, cross, orgr, neth, thel, storm, iron, under, and darn.' WHERE `name` = 'recall';
UPDATE `command` SET `help` = 'Syntax: .createguild $GuildName $GuildLeaderName\r\n\r\nCreate a guild named $GuildName with the player $GuildLeaderName as leader.' WHERE `name` = 'createguild';


