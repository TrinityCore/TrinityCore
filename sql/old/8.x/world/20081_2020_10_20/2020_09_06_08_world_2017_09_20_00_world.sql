-- Fix Coldflame npc flying bug, sniff confirmed
UPDATE `creature_template` SET `InhabitType`=1 WHERE `entry`=36672;
