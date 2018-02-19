--
ALTER TABLE `npc_text_locale`
DROP PRIMARY KEY,
ADD PRIMARY KEY (`ID`, `Locale`);
