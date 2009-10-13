
UPDATE `creature_template` SET `ScriptName`='boss_drakkari_colossus' WHERE `entry`=29307;
UPDATE `creature_template` SET `ScriptName`='boss_drakkari_elemental' WHERE `entry`=29573;
UPDATE `creature_template` SET `ScriptName`='npc_living_mojo' WHERE `entry`=29830;

DELETE FROM `creature_ai_scripts` WHERE `id` = 1650612;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
(1650612, 16506, 6, 0, 100, 0, 0, 0, 0, 0, 11, 28732, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Naxxramas Worshipper - Widow Embrace');
