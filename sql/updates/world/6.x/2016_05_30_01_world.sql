--
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE entry IN (SELECT `entry` FROM `npc_vendor`);
