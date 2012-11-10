SET @GMlevel : = 0; 

REPLACE INTO `command` VALUES ('mmap', @GMlevel, 'Syntax: Syntax: .mmaps $subcommand Type .mmaps to see the list of possible subcommands or .help mmaps $subcommand to see info on subcommands');
REPLACE INTO `command` VALUES ('mmap path', @GMlevel, 'Syntax: .mmap path to calculate and show a path to current select unit');
REPLACE INTO `command` VALUES ('mmap loc', @GMlevel, 'Syntax: .mmap loc to print on which tile one is');
REPLACE INTO `command` VALUES ('mmap loadedtiles', @GMlevel, 'Syntax: .mmap loadedtiles to show which tiles are currently loaded');
REPLACE INTO `command` VALUES ('mmap stats', @GMlevel, 'Syntax: .mmap stats to show information about current state of mmaps');
REPLACE INTO `command` VALUES ('mmap testarea', @GMlevel, 'Syntax: .mmap testarea to calculate paths for all nearby npcs to player');
