DELETE FROM `world_custom_config` WHERE `Type` = 'bool' AND `IDInTypeGroup` = 11;
INSERT INTO `world_custom_config`(`OptionName`, `Type`, `IDInTypeGroup`, `DefaultValue`, `CustomValue`, `Description`) VALUES 
('CheckM2ObjectLoS', 'bool', 11, '1', NULL, 'Include M2 objects (trees etc.) in line of sight checks.');