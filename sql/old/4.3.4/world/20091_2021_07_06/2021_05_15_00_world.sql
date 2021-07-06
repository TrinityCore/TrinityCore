ALTER TABLE `npc_vendor` 
    ADD COLUMN `PlayerConditionID` int(10) NOT NULL DEFAULT 0 AFTER `type`;
    