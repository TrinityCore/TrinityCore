ALTER TABLE `npc_trainer` 
    DROP PRIMARY KEY,
    DROP `rowid`,
    ADD UNIQUE KEY `entry_spell` (`entry`,`spell`);
