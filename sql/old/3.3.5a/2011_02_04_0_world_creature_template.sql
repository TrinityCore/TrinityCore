-- Remove XP at kill from Flesh Eating Worm
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry`=2462;
