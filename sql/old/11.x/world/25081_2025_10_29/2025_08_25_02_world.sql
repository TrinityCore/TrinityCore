--
DELETE FROM `command` WHERE `name`='guild list';
INSERT INTO `command` (`name`, `help`) VALUES
('guild list','Syntax: .guild list.  Lists every guild: ID | Name | Leader | Creation date | Members | Bank gold');

-- Strings for .guild list output
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1219 AND 1222;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
-- Title
(1219,'%s=== Guild list ===%s'),
-- Header (6 string args for labels)
(1220,'%s  ID   |           Name           |      Leader      |    Creation date    | Members | Bank gold%s'),
-- Row (id, name, gm, created, members, bankGold)
(1221,'%6u | %-24.24s | %-16.16s | %-19s | %7u | %10u'),
-- Total
(1222,'%sTotal guilds: %u%s');
