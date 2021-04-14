ALTER TABLE `guild_eventlog`      ADD INDEX `Idx_PlayerGuid1`(`PlayerGuid1`);
ALTER TABLE `guild_eventlog`      ADD INDEX `Idx_PlayerGuid2`(`PlayerGuid2`);
ALTER TABLE `guild_eventlog`      ADD INDEX `Idx_LogGuid`(`LogGuid`);
ALTER TABLE `guild_bank_eventlog` ADD INDEX `Idx_PlayerGuid`(`PlayerGuid`);
ALTER TABLE `guild_bank_eventlog` ADD INDEX `Idx_LogGuid`(`LogGuid`);
ALTER TABLE `guild_bank_item`     ADD INDEX `Idx_item_guid`(`item_guid`);
ALTER TABLE `guild_rank`          ADD INDEX `Idx_rid`(`rid`);
