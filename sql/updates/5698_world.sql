UPDATE `creature_template` SET `ScriptName`='mob_nerubar_victim' WHERE `entry`=25284;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=25669;
INSERT INTO `creature_ai_scripts`
(`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
(2566901, 25669, 10, 0, 100, 3, 1, 20, 2000, 2000, 33, 25669, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Scout Warsong Granary - Killed Moster at LOS'),(2567101, 25671, 10, 0, 100, 3, 1, 20, 2000, 2000, 33, 25671, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Scout Torp''s Farm - Killed Moster at LOS'),(2567201, 25672, 10, 0, 100, 3, 1, 20, 2000, 2000, 33, 25672, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Scout Warsong Slaughterhouse - Killed Moster at LOS');