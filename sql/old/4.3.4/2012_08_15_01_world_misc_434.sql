ALTER TABLE `quest_poi` DROP INDEX `idx`;
ALTER TABLE `game_event_npc_vendor` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`guid`, `item`, `ExtendedCost`, `type`);
ALTER TABLE `npc_vendor` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`entry`, `item`, `ExtendedCost`, `type`);
