UPDATE `creature_template` SET `npcflag`=`npcflag`|16 WHERE `entry` IN (SELECT `entry` FROM `npc_trainer` WHERE `entry` < 200000);
