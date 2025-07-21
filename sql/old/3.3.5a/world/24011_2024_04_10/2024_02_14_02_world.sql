-- Add repair flag Quartermaster Vaskess
UPDATE `creature_template` SET `npcflag`=`npcflag`|4096 WHERE `entry` = 31115;
