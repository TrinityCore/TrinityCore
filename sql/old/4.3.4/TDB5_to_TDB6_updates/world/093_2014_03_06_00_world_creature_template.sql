-- Fix Missing 'gossip' flag (1) so player can choose trainer or vendor window,
--  current flag (208) only allowed vendor window to appear
UPDATE `creature_template` SET `npcflag`=209 WHERE entry=33674;
