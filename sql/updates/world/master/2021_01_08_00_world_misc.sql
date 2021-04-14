UPDATE access_requirement SET level_min = 121 WHERE mapId = 649;
UPDATE `lfg_dungeon_template` SET `name`='Scarlet Monastery', `position_x`='1124.64', `position_y`='512.466', `orientation`='0.986' WHERE (`dungeonId`='164');
REPLACE INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES ('2', '649', '12', 'ToC');
UPDATE `lfg_dungeon_template` SET `position_x`='837.288', `position_y`='609.866', `position_z`='12.813', `orientation`='4.684' WHERE (`dungeonId`='473');
