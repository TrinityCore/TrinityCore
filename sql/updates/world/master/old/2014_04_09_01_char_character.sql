ALTER TABLE  `characters` CHANGE  `currentpetslot`  `currentpetnumber` INT( 11 ) NOT NULL;
update `characters` set `currentpetnumber` = 0;