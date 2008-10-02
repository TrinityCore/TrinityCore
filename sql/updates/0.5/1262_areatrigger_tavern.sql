ALTER TABLE `areatrigger_tavern` 
    CHANGE `triggerid` `id` int(11) unsigned NOT NULL default '0' ,
    CHANGE `Triggername` `name` text ,
    DROP KEY `acct`,
    DROP PRIMARY KEY ,
    ADD PRIMARY KEY (`id`) ;
