-- Add quest relations flag to npc 36296 "Apothecary Hummel <Crown Chemical Co.>"
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=36296;
