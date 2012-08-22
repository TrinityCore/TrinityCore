-- Remove dupe spawn from transport table
DELETE FROM `creature_transport` WHERE `guid`=35 AND `npc_entry`=30755;
