REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(183790, 'areatrigger_black_hole'),
(153072, 'areatrigger_void_devestation');

UPDATE `creature_template` SET `ScriptName`='boss_nerzul' WHERE  `entry`=76407;
UPDATE `creature_template` SET `ScriptName`='boss_nhalish' WHERE  `entry`=75829;
UPDATE `creature_template` SET `ScriptName`='boss_hymdall' WHERE  `entry`=94960;
UPDATE `creature_template` SET `ScriptName`='npc_earthen_ring_flamecaller' WHERE  `entry`=25754;
UPDATE `creature_template` SET `ScriptName`='npc_hymdall_dancing_blade' WHERE  `entry`=121247;
UPDATE `creature_template` SET `ScriptName`='npc_lumbering_oaf' WHERE  `entry`=40906;
UPDATE `gameobject_template` SET `ScriptName`='toxic_eggs_go' WHERE  `entry`=234113;

