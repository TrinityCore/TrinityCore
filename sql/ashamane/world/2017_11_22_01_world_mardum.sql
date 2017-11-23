UPDATE creature SET PhaseId = 50 WHERE guid = 20540934;
UPDATE creature SET PhaseId = 50 WHERE guid = 20540920;
UPDATE creature SET PhaseId = 50 WHERE guid = 20540933;
UPDATE creature SET PhaseId = 50 WHERE guid = 20540930;
UPDATE creature SET PhaseId = 50 WHERE guid = 20540935;
UPDATE creature SET PhaseId = 50 WHERE guid = 20540919;

UPDATE creature SET PhaseId = 170 WHERE guid = 20540916;
UPDATE creature SET PhaseId = 170 WHERE guid = 20540932;
UPDATE creature SET PhaseId = 170 WHERE guid = 20540915;
UPDATE creature SET PhaseId = 170 WHERE guid = 20540918;
UPDATE creature SET PhaseId = 170 WHERE guid = 20540931;
UPDATE creature SET PhaseId = 170 WHERE guid = 20540917;

DELETE FROM creature_addon WHERE guid IN (SELECT guid FROM creature WHERE id = 97594);
DELETE FROM  creature_template_addon WHERE entry = 97594;

UPDATE creature SET PhaseId = 171 WHERE guid = 20541081;
UPDATE creature SET PhaseId = 171 WHERE guid = 20543738;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541074;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541073;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541088;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541049;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541067;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541075;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541080;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541108;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541128;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541117;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541114;
UPDATE creature SET PhaseId = 171 WHERE guid = 20541087;
UPDATE creature SET PhaseId = 171 WHERE guid = 20543739;

UPDATE scene_template SET scriptname = "scene_mardum_change_legion_banner" WHERE SceneId = 1116;
UPDATE creature SET PhaseId = 171 WHERE guid = 20543735;
UPDATE creature SET PhaseId = 172 WHERE guid = 20541143;
UPDATE creature SET position_x = 1016.252747, position_y = 2848.764648, position_z = 5.272532, orientation = 1.274962 WHERE guid = 20541143;

DELETE FROM spell_script_names WHERE spell_id IN (200176, 192709);
INSERT INTO spell_script_names VALUES
(200176, "spell_learn_felsaber"),
(192709, "spell_mardum_infernal_smash");
