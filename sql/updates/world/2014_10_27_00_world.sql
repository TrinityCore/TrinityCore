DROP TABLE IF EXISTS `phase_definitions`;
DROP TABLE IF EXISTS `phase_info`;
DROP TABLE IF EXISTS `terrain_phase_info`;
DROP TABLE IF EXISTS `terrain_map_info`;

CREATE TABLE `terrain_phase_info`(  
  `id` INT(10) NOT NULL,
  `terrainswapmap` INT(10) NOT NULL,
  `comment` VARCHAR(255),
  PRIMARY KEY (`id`, `terrainswapmap`)
);

CREATE TABLE `terrain_map_info`(
  `mapid` INT(10) NOT NULL,
  `terrainswapmap` INT(10) NOT NULL,
  `comment` VARCHAR(255),
  PRIMARY KEY (`mapid`, `terrainswapmap`)
);

