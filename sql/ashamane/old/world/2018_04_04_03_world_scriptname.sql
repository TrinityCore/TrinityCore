UPDATE instance_template SET parent = 1220, script = "instance_emerald_nightmare", insideResurrection = 1 WHERE map = 1520;

UPDATE creature_template SET scriptname = "boss_nythendra" WHERE entry = 102672;

UPDATE areatrigger_template SET scriptname = "at_nythendra_infested_ground" WHERE Id = 10594;

DELETE FROM spell_script_names WHERE scriptname IN ("spell_nythendra_rot", "spell_nythendra_volatile_rot_damage");
INSERT INTO spell_script_names VALUES
(203096, "spell_nythendra_rot"),
(204470, "spell_nythendra_volatile_rot_damage");
