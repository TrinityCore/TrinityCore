ALTER TABLE `character` CHANGE `honor` `highest_rank` INT( 11 ) DEFAULT '0' NOT NULL ,
CHANGE `last_week_honor` `standing` INT( 11 ) DEFAULT '0' NOT NULL ;
ALTER TABLE `character` ADD `rating` FLOAT( 11 ) DEFAULT '0' NOT NULL AFTER `standing` ;