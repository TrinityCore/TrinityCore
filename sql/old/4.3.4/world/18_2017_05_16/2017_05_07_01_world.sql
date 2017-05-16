--
ALTER TABLE `npc_text_locale`
DROP PRIMARY KEY,
ADD PRIMARY KEY (`ID`, `Locale`);

ALTER TABLE `gossip_menu_option_locale`
DROP PRIMARY KEY,
ADD PRIMARY KEY (`MenuID`, `OptionID`, `Locale`);
