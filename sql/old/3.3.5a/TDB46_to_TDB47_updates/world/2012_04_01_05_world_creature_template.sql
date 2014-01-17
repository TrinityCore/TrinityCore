-- CREATURE_FLAG_EXTRA_NO_XP_AT_KILL
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry`=21267; -- Mana Beast
