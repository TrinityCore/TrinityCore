update creature_template set speed=1 where speed=0;
alter table `creature_template` change `speed` `speed` float  DEFAULT '1' NULL;
