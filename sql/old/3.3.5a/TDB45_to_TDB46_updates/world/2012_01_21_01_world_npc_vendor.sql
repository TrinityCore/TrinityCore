-- Remove old one that still required reputation even after you bought it
DELETE FROM `npc_vendor` WHERE `entry`=32538 and`item`=50367 and`ExtendedCost`=0;

-- Commit for new one
DELETE FROM `npc_vendor` WHERE `entry`=32538 and`item`=44149 and`ExtendedCost`=0;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES (32538,0,44149,0,0,0);
