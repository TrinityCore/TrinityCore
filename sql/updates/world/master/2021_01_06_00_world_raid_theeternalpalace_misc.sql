-- Instance Template
replace INTO `instance_template` (`map`, `parent`, `script`, `allowMount`, `insideResurrection`) VALUES ('2164', '0', 'bfa_instance_the_eternal_palace', '0', '0');

-- Acces to instance
replace INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES ('2164', '120', '120', '0', '0', '0', '0', '0', '0', NULL, 'The Eternal Palace Raid');

-- Ingame Teleport command
replace INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES ('3077', '299.44', '167.97', '1450.28', '0', '2164', 'EternalPalaceRaid');
