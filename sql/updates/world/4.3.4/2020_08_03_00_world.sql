ALTER TABLE `gossip_menu_option_locale`
    CHANGE `MenuID` `MenuID` int(11) unsigned NOT NULL DEFAULT '0',
    CHANGE `OptionID` `OptionID` int(11) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `gossip_menu`
    CHANGE `MenuID` `MenuID` int(11) unsigned NOT NULL DEFAULT '0',
    CHANGE `TextID` `TextID` int(11) unsigned NOT NULL DEFAULT '0';
