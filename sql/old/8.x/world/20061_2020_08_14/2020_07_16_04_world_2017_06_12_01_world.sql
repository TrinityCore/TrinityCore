--
DELETE FROM `trinity_string` WHERE `entry` IN (1185,1186,1187);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
  (1193, '%s is not in a raid group!'),
  (1194, '%s %s has raid role \'%s\'.'),
  (1195, 'The raid leader cannot be set as an assistant!');
  
DELETE FROM `command` WHERE `name` LIKE 'group set%';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('group set leader', 473, "Syntax: .group set leader [$characterName]

Sets the given character (or selected) as his group's leader. Alias for '.group leader'."),
('group set assistant', 862, "Syntax: .group set assistant [$characterName]

Toggles the given character's assistant state in his raid group."),
('group set maintank', 863, "Syntax: .group set maintank [$characterName]

Toggles the given character's main tank flag in his raid group."),
('group set mainassist', 864, "Syntax: .group set mainassist [$characterName]

Toggles the given character's main assist flag in his raid group.");