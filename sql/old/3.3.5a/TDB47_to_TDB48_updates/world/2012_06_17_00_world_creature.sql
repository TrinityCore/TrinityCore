-- Fix Storm Totem flags
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=26048;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`&~16777216 WHERE `entry`=26048;
