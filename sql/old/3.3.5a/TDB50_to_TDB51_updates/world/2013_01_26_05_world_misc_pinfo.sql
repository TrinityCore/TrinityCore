DELETE FROM `trinity_string` WHERE `entry`=749;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(749, 'Guild: %s (%u) Rank: %s Note: %s OffNote: %s');

UPDATE `command` SET `help`='Syntax: .pinfo [$player_name/#GUID]\r\n\r\nOutput account information and guild information for selected player or player find by $player_name or #GUID.' WHERE `name`='pinfo';
