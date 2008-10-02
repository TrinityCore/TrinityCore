ALTER TABLE `npc_vendor` 
    DROP PRIMARY KEY,
    DROP KEY `vendor_id` ,
    DROP `index_id`,
    CHANGE `entry`    `entry`    int(11) unsigned NOT NULL default '0',
    CHANGE `itemguid` `item`     int(11) unsigned NOT NULL default '0',
    CHANGE `amount`   `buycount` int(11) unsigned NOT NULL default '1',
    ADD               `maxcount` int(11) unsigned NOT NULL default '0',
    ADD               `incrtime` int(11) unsigned NOT NULL default '0';
