UPDATE `creature_template` SET `ScriptName` = 'boss_razorscale_controller' WHERE `entry` = 33233;
UPDATE `creature_template` SET `ScriptName` = 'boss_razorscale' WHERE `entry` = 33186;
UPDATE `creature_template` SET `ScriptName` = 'npc_darkrune_watcher' WHERE `entry` = 33453;
UPDATE `creature_template` SET `ScriptName` = 'npc_darkrune_sentinel' WHERE `entry` = 33846;
UPDATE `creature_template` SET `ScriptName` = 'npc_darkrune_guardian' WHERE `entry` = 33388;
UPDATE `creature_template` SET `ScriptName` = 'npc_devouring_flame' WHERE `entry` = 34188;
UPDATE `creature_template` SET `ScriptName` = 'npc_expedition_commander' WHERE `entry` = 33210;
UPDATE `creature_template` SET `ScriptName` = 'npc_mole_machine_trigger' WHERE `entry` IN (33282, 33245);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry` IN (33210,33287,33259,33233);
