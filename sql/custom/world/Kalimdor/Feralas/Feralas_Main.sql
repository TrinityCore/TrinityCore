-- Feralas Fixes

-- NPC: 54533 Prince Lakma <The Last Chimaerok>

UPDATE creature_template_difficulty SET ContentTuningID = 22, `LootID` = 54533, StaticFlags1 = StaticFlags1 | 0x20000000 WHERE Entry = 54533;
