ALTER TABLE `character_inventory` 
    DROP KEY `idx_guid` ,
    ADD PRIMARY KEY  (`guid`,`bag`,`slot`) ; 
