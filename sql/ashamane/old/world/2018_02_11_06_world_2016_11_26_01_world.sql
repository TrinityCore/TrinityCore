-- Fixed speed for Supremus
UPDATE `creature_template` SET `speed_walk`=2.4, `speed_run`=2.14286 WHERE `entry`=22898;
-- Added unit_flag UNIT_FLAG_NOT_SELECTABLE in Supremus Volcano
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432 WHERE `entry`=23085;
-- Updated script name of creature Molten Flame
UPDATE `creature_template` SET `ScriptName`='npc_molten_flame' WHERE `entry`=23095;
