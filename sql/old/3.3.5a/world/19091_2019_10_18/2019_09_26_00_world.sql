--
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├í','á') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├║','ú') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├¡','í') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├│','ó') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├®','é') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├▒','ñ') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├ô','Ó') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├Ü','Ú') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Name` = REPLACE(`Name`,'├ü','Á') WHERE (locale='esES' OR locale='esMX');

UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├í','á') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├║','ú') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├¡','í') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├│','ó') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├®','é') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├▒','ñ') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├ô','Ó') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├Ü','Ú') WHERE (locale='esES' OR locale='esMX');
UPDATE `item_template_locale` SET `Description` = REPLACE(`Description`,'├ü','Á') WHERE (locale='esES' OR locale='esMX');
