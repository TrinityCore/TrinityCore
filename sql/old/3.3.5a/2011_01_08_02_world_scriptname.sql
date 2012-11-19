DELETE FROM spell_script_names WHERE spell_id IN (66630,66637,66656);
INSERT INTO spell_script_names (spell_id,ScriptName) VALUES
(66630,'spell_gen_gunship_portal'),
(66637,'spell_gen_gunship_portal'),
(66656,'spell_gen_parachute_ic');

-- Achievement Mine
DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (12062,12063,12064,12065);
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES
(12062,11,'achievement_bg_control_all_nodes'),
(12063,11,'achievement_bg_control_all_nodes'),
(12064,11,'achievement_bg_control_all_nodes'),
(12065,11,'achievement_bg_control_all_nodes');

-- Achievement Four Car Garage
UPDATE `creature_template` SET `ScriptName`='npc_four_car_garage' WHERE `entry` IN (34802,34793,34775,35069,34776);

-- Achievement Glaive Grave
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12183;
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES (12183,11,'achievement_bg_ic_glaive_grave');

-- Achievement Mowed Down
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=12068;
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES (12068,11,'achievement_bg_ic_mowed_down');

-- Achievement Resource Glut
DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (12060,12061);
INSERT INTO `achievement_criteria_data` (criteria_id,type,ScriptName) VALUES
(12060,11,'achievement_bg_ic_resource_glut'),
(12061,11,'achievement_bg_ic_resource_glut');