//correction donate cost
DELETE FROM itemextendedcost_db2 WHERE ID > 5049;
DELETE FROM npc_vendor WHERE ExtendedCost > 5049;

UPDATE npc_vendor SET ExtendedCost = ExtendedCost + 10000 WHERE ExtendedCost > 4999;
UPDATE itemextendedcost_db2 SET ID = ID + 10000 WHERE ID > 4999;
