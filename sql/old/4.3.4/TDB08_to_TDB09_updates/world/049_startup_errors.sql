--
DELETE FROM `npc_vendor` WHERE `item`=90427; -- MoP only
UPDATE `creature_template` SET `npcflag`=131 WHERE `entry` IN (24468,24510,27478);
