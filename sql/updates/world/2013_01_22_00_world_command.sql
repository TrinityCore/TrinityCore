DELETE FROM `command` WHERE `name`='mmap' OR `name` LIKE 'mmap%';
DELETE FROM `command` WHERE `name` LIKE 'disable add mmap' OR `name` LIKE 'disable remove mmap';
INSERT INTO `command` (`name`, `security`, `help`) VALUES 
('mmap', 3, 'Syntax: Syntax: .mmaps $subcommand Type .mmaps to see the list of possible subcommands or .help mmaps $subcommand to see info on subcommands'),
('mmap path', 3, 'Syntax: .mmap path to calculate and show a path to current select unit'),
('mmap loc', 3, 'Syntax: .mmap loc to print on which tile one is'),
('mmap loadedtiles', 3, 'Syntax: .mmap loadedtiles to show which tiles are currently loaded'),
('mmap stats', 3, 'Syntax: .mmap stats to show information about current state of mmaps'),
('mmap testarea', 3, 'Syntax: .mmap testarea to calculate paths for all nearby npcs to player'),
('disable add mmap', '3', 'Syntax: .disable add mmap $entry $flag $comment'),
('disable remove mmap', '3', 'Syntax: .disable remove mmap $entry');
