-- Decrease Wood Frog Box restock time
UPDATE `npc_vendor` SET `incrtime`=1800 WHERE `entry`=14860 AND `item`=11027;
