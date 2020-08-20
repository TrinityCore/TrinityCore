--
ALTER TABLE `quest_greeting_locale` DROP PRIMARY KEY;
ALTER TABLE `quest_greeting_locale` ADD PRIMARY KEY( `ID`, `Type`, `locale`);
