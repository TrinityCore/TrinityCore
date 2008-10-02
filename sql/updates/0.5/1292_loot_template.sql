ALTER TABLE `loot_template`
    CHANGE `itemid`        `item`   int(11) unsigned NOT NULL default '0' , 
    CHANGE `percentchance` `chance` float            NOT NULL default '100' , 
    DROP KEY `i_creature_loot_creatureid` ,
    DROP KEY `creatureloot_index` ,
    ADD PRIMARY KEY (`entry`,`item`) ;
