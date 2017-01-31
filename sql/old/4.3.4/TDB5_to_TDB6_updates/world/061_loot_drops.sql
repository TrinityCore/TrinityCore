-- Vendor Sognar Cliffbeard needs to sell Bag o' Sheep Innards
DELETE FROM npc_vendor WHERE entry = 5124 AND item = 69984;
INSERT INTO npc_vendor (entry, slot, item, maxcount, incrtime, ExtendedCost, type) VALUES 
(5124, 13, 69984, 0, 0, 0, 1);
