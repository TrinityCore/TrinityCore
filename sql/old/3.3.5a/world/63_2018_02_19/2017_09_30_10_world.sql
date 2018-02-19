-- Fix gossip for NPC Gjonner the Merciless
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=31154;
