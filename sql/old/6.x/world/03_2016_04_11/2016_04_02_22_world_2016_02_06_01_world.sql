-- 
-- Stinky + Precious - Knockbackimmunity
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40000000 WHERE `entry` IN (37025, 38064, 37217, 38103);
