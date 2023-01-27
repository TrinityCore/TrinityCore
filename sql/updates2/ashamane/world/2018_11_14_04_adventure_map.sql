DROP TABLE IF EXISTS `adventure_map_ui`;
CREATE TABLE `adventure_map_ui`(
    `creatureId` INT(10) UNSIGNED NOT NULL,
    `uiMapId` INT(10) UNSIGNED NOT NULL,
    PRIMARY KEY (`creatureId`)
); 

INSERT INTO adventure_map_ui VALUES
(139522, 1014),
(144635, 1011);

UPDATE creature_template SET npcflag = 1 WHERE entry = 139522;
UPDATE `gossip_menu_option` SET OptionType = 21 WHERE MenuId IN (18747, 22725, 22445) AND OptionIndex = 0;
