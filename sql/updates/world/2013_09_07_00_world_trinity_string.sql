DELETE FROM `trinity_string` WHERE `entry` IN (882, 883);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(882,'No° %u has guid: %u'),
(883,'This creature was spawned %u times.');

UPDATE `command` SET `help`='Syntax: .npc info [count]\r\n\r\nDisplay a list of details for the selected creature.\r\n\r\nThe list includes:\r\n- GUID, Faction, NPC flags, Entry ID, Model ID,\r\n- Level,\r\n- Health (current/maximum),\r\n\r\n- Field flags, dynamic flags, faction template, \r\n- Position information,\r\n- and the creature type, e.g. if the creature is a vendor.\r\n- Adding count as argument counts and prints the number of spawns with each guid.' WHERE `name`='npc info';
