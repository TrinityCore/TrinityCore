-- Remove Manual: Netherweave Bandage & and Manual: Heavy Netherweave Bandage from vendors (Patch 3.1.0)
DELETE FROM npc_vendor WHERE item IN (21992,21991);
-- Update reqskillvalue for Netherweave Bandage & Heavy Netherweave Bandage (Patch 3.1.0)
UPDATE npc_trainer SET reqskillvalue=300 WHERE spell=27032;
UPDATE npc_trainer SET reqskillvalue=330 WHERE spell=27033;
