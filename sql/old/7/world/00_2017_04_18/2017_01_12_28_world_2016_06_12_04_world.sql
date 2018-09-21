-- 
-- Set CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ on Iron Sentinel Credit & Iron Dwarf Assailant & Corpulent Horror Credit
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2097152 WHERE `entry` IN (30296,30297,30696);
