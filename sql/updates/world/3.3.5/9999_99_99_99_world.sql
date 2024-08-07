-- Scripts
UPDATE `creature_template`
SET `ScriptName` = CASE
    WHEN `entry` = 16816 THEN 'npc_echo_of_medivh'
    WHEN `entry` IN (17211, 17469, 21160, 21664, 21682, 21683, 21726, 21747, 21748, 21750) THEN 'npc_chess_piece_generic'
    WHEN `entry` IN (21684, 21752) THEN 'npc_chess_piece_king'
    WHEN `entry` IN (17208, 17305, 22519, 22520) THEN 'npc_chess_move_trigger'
END
WHERE `entry` IN (16816, 17211, 17469, 21160, 21664, 21682, 21683, 21726, 21747, 21748, 21750, 21684, 21752, 17208, 17305, 22519, 22520);

-- Chess piece spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (37474, 37476, 37406, 37413, 37427, 37428, 37453, 37454, 37459, 37461, 37471, 37472, 37498, 37502, 30284);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(37474, 'spell_king_primary'),
(37476, 'spell_king_primary'),
(37406, 'spell_chess'),
(37413, 'spell_chess'),
(37427, 'spell_chess'),
(37428, 'spell_chess'),
(37453, 'spell_chess'),
(37454, 'spell_chess'),
(37459, 'spell_chess'),
(37461, 'spell_chess'),
(37471, 'spell_chess'),
(37472, 'spell_chess'),
(37498, 'spell_chess'),
(37502, 'spell_chess'),
(30284, 'spell_change_facing');

-- Helper spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (30019, 30253, 37144, 37146, 37148, 37151, 37152, 37153, 30543, 39401);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(30019, 'spell_control_piece'),
(30253, 'spell_move_to_square'),
(37144, 'spell_piece_move'),
(37146, 'spell_piece_move'),
(37148, 'spell_piece_move'),
(37151, 'spell_piece_move'),
(37152, 'spell_piece_move'),
(37153, 'spell_piece_move'),
(30543, 'spell_move_cooldown'),
(39401, 'spell_game_over');

-- Medivh spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (39338, 39342, 39341, 39344, 39334, 39335);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(39338, 'spell_hand_of_medivh'),
(39342, 'spell_hand_of_medivh'),
(39341, 'spell_fury_of_medivh'),
(39344, 'spell_fury_of_medivh'),
(39334, 'spell_heal_of_medivh'),
(39335, 'spell_heal_of_medivh');

-- Extra flags (was originally 66)

UPDATE `creature_template`
SET `flags_extra` = CASE
    WHEN `entry` IN (17211, 17469, 21664, 21682, 21683, 21726, 21747, 21748, 21750, 21684, 21752) THEN 64
    WHEN `entry` = 21160 THEN 0 -- Initially, two
    WHEN `entry` = 22521 THEN 128 -- For only the GMs to see
END
WHERE `entry` IN (17211, 17469, 21160, 21664, 21682, 21683, 21726, 21747, 21748, 21750, 21684, 21752, 22521);

-- Creature spells
DELETE FROM `creature_template_spell` WHERE `CreatureID` IN (17211, 17469, 21160, 21664, 21682, 21683, 21726, 21747, 21748, 21750, 21684, 21752);

-- Creature spells

INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES 
(17211, 0, 37146, 12340), (17211, 1, 30284, 12340), (17211, 2, 37406, 12340), (17211, 3, 37414, 12340),
(17469, 0, 37146, 12340), (17469, 1, 30284, 12340), (17469, 2, 37413, 12340), (17469, 3, 37416, 12340),
(21160, 0, 37151, 12340), (21160, 1, 30284, 12340), (21160, 2, 37427, 12340), (21160, 3, 37432, 12340),
(21664, 0, 37144, 12340), (21664, 1, 30284, 12340), (21664, 2, 37453, 12340), (21664, 3, 37498, 12340),
(21682, 0, 37152, 12340), (21682, 1, 30284, 12340), (21682, 2, 37455, 12340), (21682, 3, 37459, 12340),
(21683, 0, 37148, 12340), (21683, 1, 30284, 12340), (21683, 2, 37462, 12340), (21683, 3, 37465, 12340),
(21726, 0, 37151, 12340), (21726, 1, 30284, 12340), (21726, 2, 37428, 12340), (21726, 3, 37434, 12340),
(21747, 0, 37152, 12340), (21747, 1, 30284, 12340), (21747, 2, 37456, 12340), (21747, 3, 37461, 12340),
(21748, 0, 37144, 12340), (21748, 1, 30284, 12340), (21748, 2, 37454, 12340), (21748, 3, 37502, 12340),
(21750, 0, 37148, 12340), (21750, 1, 30284, 12340), (21750, 2, 37463, 12340), (21750, 3, 37469, 12340),
(21684, 0, 37153, 12340), (21684, 1, 30284, 12340), (21684, 2, 37474, 12340), (21684, 3, 37471, 12340),
(21752, 0, 37153, 12340), (21752, 1, 30284, 12340), (21752, 2, 37476, 12340), (21752, 3, 37472, 12340);


-- Chess piece positions (Changed the position to match the position of the chess square)

-- FOOTMAN
UPDATE `creature` SET `position_x`=-11103.9, `position_y`=-1869.61, `position_z`=220.751, `orientation`=0.698132 WHERE `guid`=76027;
UPDATE `creature` SET `position_x`=-11100.2, `position_y`=-1874.09, `position_z`=220.751, `orientation`=0.645772 WHERE `guid`=76025;
UPDATE `creature` SET `position_x`=-11096.9, `position_y`=-1878.59, `position_z`=220.751, `orientation`=0.663225 WHERE `guid`=76023;
UPDATE `creature` SET `position_x`=-11093.2, `position_y`=-1882.83, `position_z`=220.751, `orientation`=0.663225 WHERE `guid`=76022;
UPDATE `creature` SET `position_x`=-11089.7, `position_y`=-1887.13, `position_z`=220.751, `orientation`=0.715585 WHERE `guid`=76021;
UPDATE `creature` SET `position_x`=-11086.3, `position_y`=-1891.52, `position_z`=220.751, `orientation`=0.645772 WHERE `guid`=76031;
UPDATE `creature` SET `position_x`=-11082.9, `position_y`=-1895.98, `position_z`=220.751, `orientation`=0.663225 WHERE `guid`=76029;
UPDATE `creature` SET `position_x`=-11079,   `position_y`=-1900.4,  `position_z`=220.75,  `orientation`=0.663225 WHERE `guid`=76026;

-- GRUNT
UPDATE `creature` SET `position_x`=-11082.1, `position_y`=-1852.36, `position_z`=220.751, `orientation`=3.80482 WHERE `guid`=76036;
UPDATE `creature` SET `position_x`=-11078.5, `position_y`=-1856.74, `position_z`=220.751, `orientation`=3.89208 WHERE `guid`=76033;
UPDATE `creature` SET `position_x`=-11075.1, `position_y`=-1861.15, `position_z`=220.751, `orientation`=3.735   WHERE `guid`=76032;
UPDATE `creature` SET `position_x`=-11071.6, `position_y`=-1865.49, `position_z`=220.751, `orientation`=3.82227 WHERE `guid`=76030;
UPDATE `creature` SET `position_x`=-11068.3, `position_y`=-1869.97, `position_z`=220.751, `orientation`=3.89208 WHERE `guid`=76028;
UPDATE `creature` SET `position_x`=-11064.8, `position_y`=-1874.16, `position_z`=220.751, `orientation`=3.83972 WHERE `guid`=76020;
UPDATE `creature` SET `position_x`=-11061.1, `position_y`=-1878.73, `position_z`=220.751, `orientation`=3.90954 WHERE `guid`=76040;
UPDATE `creature` SET `position_x`=-11057.7, `position_y`=-1883.02, `position_z`=220.751, `orientation`=3.80482 WHERE `guid`=76035;

-- WATER_ELEMENTAL
UPDATE `creature` SET `position_x`=-11108.1, `position_y`=-1873,    `position_z`=220.751, `orientation`=0.715585 WHERE `guid`=76045;
UPDATE `creature` SET `position_x`=-11083.7, `position_y`=-1903.79, `position_z`=220.75,  `orientation`=0.663225 WHERE `guid`=76024;

-- HUMAN_CHARGER
UPDATE `creature` SET `position_x`=-11104.5, `position_y`=-1877.59, `position_z`=220.751, `orientation`=0.680678 WHERE `guid`=76019;
UPDATE `creature` SET `position_x`=-11087.2, `position_y`=-1899.45, `position_z`=220.751, `orientation`=0.733038 WHERE `guid`=76018;

-- HUMAN_CLERIC
UPDATE `creature` SET `position_x`=-11101.1, `position_y`=-1881.79, `position_z`=220.751, `orientation`=0.663225 WHERE `guid`=76046;
UPDATE `creature` SET `position_x`=-11090.6, `position_y`=-1895.09, `position_z`=220.751, `orientation`=0.628318 WHERE `guid`=76048;

-- HUMAN_CONJURER
UPDATE `creature` SET `position_x`=-11097.7, `position_y`=-1886.26, `position_z`=220.751, `orientation`=0.785398 WHERE `guid`=76047;

-- SUMMONED_DAEMON
UPDATE `creature` SET `position_x`=-11077.7, `position_y`=-1848.77, `position_z`=220.751, `orientation`=3.90954  WHERE `guid`=76039;
UPDATE `creature` SET `position_x`=-11053.4, `position_y`=-1879.78, `position_z`=220.751, `orientation`=4.01426  WHERE `guid`=76034;

-- ORC_NECROLYTE
UPDATE `creature` SET `position_x`=-11070.7, `position_y`=-1857.74, `position_z`=220.751, `orientation`=3.83972  WHERE `guid`=76041;
UPDATE `creature` SET `position_x`=-11060.4, `position_y`=-1870.95, `position_z`=220.667, `orientation`=3.85404  WHERE `guid`=76037;

-- ORC_WOLF
UPDATE `creature` SET `position_x`=-11074.2, `position_y`=-1853.42, `position_z`=220.751, `orientation`=3.735    WHERE `guid`=76042;
UPDATE `creature` SET `position_x`=-11056.8, `position_y`=-1875.3,  `position_z`=220.751, `orientation`=3.66519  WHERE `guid`=76038;

-- ORC_WARLOCK
UPDATE `creature` SET `position_x`=-11067.3, `position_y`=-1862.07, `position_z`=220.751, `orientation`=3.83972  WHERE `guid`=76043;

-- KING_LLANE
UPDATE `creature` SET `position_x`=-11094,   `position_y`=-1890.54, `position_z`=220.751, `orientation`=0.698132 WHERE `guid`=76049;

-- WARCHIEF_BLACKHAND
UPDATE `creature` SET `position_x`=-11063.7, `position_y`=-1866.28, `position_z`=220.668, `orientation`=3.89208  WHERE `guid`=76044;
