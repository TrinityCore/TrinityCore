-- Changed restock value from 2.5 hours (9000) to 30 mins (1800)
UPDATE `npc_vendor` SET `incrtime` = 1800 WHERE `entry` = 14860 AND `item` = 11027;
