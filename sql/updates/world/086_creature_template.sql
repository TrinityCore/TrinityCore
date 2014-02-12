-- UPDATE flags extra (adds +64) to prevent XP boost for players in Azshara, they can simply run throught invisible stalkers and get up XP and levels
UPDATE `creature_template` SET `flags_extra`=192 WHERE `entry`=12999;
