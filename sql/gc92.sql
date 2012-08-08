-- hand of sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 6940;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(6940, 'spell_pal_hand_of_sacrifice');

-- divine sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 64205;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(64205, 'spell_pal_divine_sacrifice');

-- righteous defense scriptname
DELETE FROM spell_script_names WHERE spell_id = 31789;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(31789, 'spell_pal_righteous_defense');

-- making the Four Horsemen chest lootable
UPDATE gameobject_template SET flags = flags & ~16 WHERE entry = 193426;

-- firebomb scriptname and modelid (ToC Gormok encounter)
UPDATE creature_template SET ScriptName = "npc_firebomb" WHERE entry = 34854;
UPDATE creature_template SET modelid1 = 11686, modelid2 = 0 WHERE entry = 34854;

-- frost sphere model change
UPDATE creature_template SET modelid1 = 11686 WHERE entry IN(34606, 34649);

-- Twin waypoints
DELETE FROM waypoint_data WHERE id IN (34496, 34497);
INSERT INTO waypoint_data (id, point, position_x, position_y, position_z, move_flag) VALUES
(34496, 1, 553.5, 180.5, 395.14, 1),
(34496, 2, 545.5, 170, 395.14, 1),
(34496, 3, 546, 169, 395.14, 1),
(34497, 1, 573.5, 180.5, 395.14, 1),
(34497, 2, 585.5, 170, 395.14, 1),
(34497, 3, 585, 169, 395.14, 1);
