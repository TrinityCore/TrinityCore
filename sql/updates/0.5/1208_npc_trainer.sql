ALTER TABLE `npc_trainer` CHANGE `guid` `entry` INT( 11 ) NOT NULL DEFAULT '0' ;

ALTER TABLE `npc_trainer`
ADD `reqskill` INT( 11 ) DEFAULT '0' NOT NULL ,
ADD `reqskillvalue` INT( 11 ) DEFAULT '0' NOT NULL ;

