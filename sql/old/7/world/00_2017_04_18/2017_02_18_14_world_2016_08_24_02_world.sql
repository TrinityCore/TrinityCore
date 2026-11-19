-- fix random incorrect unit flag on dragonkin type
UPDATE `creature_template` SET `unit_flags`=(`unit_flags`&~(0x100|0x200|0x2000000)) WHERE `entry`=31403;
