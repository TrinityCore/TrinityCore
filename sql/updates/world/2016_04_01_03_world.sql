--
INSERT INTO `quest_template_addon` (`ID`,`ProvidedItemCount`) (SELECT `quest_template`.`ID`,1 FROM `quest_template` WHERE `StartItem`!=0 AND `ID` NOT IN (SELECT `ID` FROM `quest_template_addon`));
