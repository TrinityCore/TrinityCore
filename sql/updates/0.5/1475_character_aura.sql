ALTER TABLE `character_aura` 
    DROP PRIMARY KEY ,
    ADD PRIMARY KEY (`guid`,`spell`,`effect_index`) ;
