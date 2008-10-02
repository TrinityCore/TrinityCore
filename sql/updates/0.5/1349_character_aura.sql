ALTER TABLE `character_aura` 
    DROP KEY `guid` ,
    ADD PRIMARY KEY (`guid`,`spell`) ; 
