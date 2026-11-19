-- DB/Creature: Add flag guard Deathguard Elite
-- creature is a guard (Will ignore feign death and vanish)
UPDATE `creature_template` SET `flags_extra`=32768 WHERE `entry`=7980;
