DROP TABLE IF EXISTS `gossip_menu_option_addon`;
CREATE TABLE `gossip_menu_option_addon` (
    MenuID INT UNSIGNED NOT NULL,
    OptionID INT UNSIGNED NOT NULL,
    DefaultAction TINYINT NOT NULL DEFAULT 0,
    PRIMARY KEY (MenuID, OptionID)
) ENGINE = INNODB;
