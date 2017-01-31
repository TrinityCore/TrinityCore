-- Malygos 25 mode
UPDATE `creature_template` SET `difficulty_entry_1`=31734 WHERE `entry`=28859;
UPDATE `creature_template` SET `speed_walk`=4, `speed_run`=2.85714, `unit_class`=2, `InhabitType`=5, `flags_extra`=`flags_extra`|1 WHERE `entry`=31734;
