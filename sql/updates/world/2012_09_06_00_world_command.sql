DELETE FROM `command` WHERE `name`='mmap' OR `name` LIKE 'mmap%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES 
('mmap', 3, 'Syntax: Syntax: .mmaps $subcommand Type .mmaps to see the list of possible subcommands or .help mmaps $subcommand to see info on subcommands'),
('mmap path', 3, 'Syntax: .mmap path to calculate and show a path to current select unit'),
('mmap loc', 3, 'Syntax: .mmap loc to print on which tile one is'),
('mmap loadedtiles', 3, 'Syntax: .mmap loadedtiles to show which tiles are currently loaded'),
('mmap stats', 3, 'Syntax: .mmap stats to show information about current state of mmaps'),
('mmap testarea', 3, 'Syntax: .mmap testarea to calculate paths for all nearby npcs to player');

