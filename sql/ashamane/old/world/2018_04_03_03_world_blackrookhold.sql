UPDATE instance_template SET parent = 1220, script = "instance_black_rook_hold", insideResurrection = 1 WHERE map = 1501;

UPDATE creature_template SET scriptname = "boss_amalgam_of_souls" WHERE entry = 98542;
UPDATE creature_template SET scriptname = "npc_aos_soul_echo" WHERE entry = 99090;

DELETE FROM `spell_areatrigger_splines` WHERE SpellMiscId = 5167;
INSERT INTO `spell_areatrigger_splines` VALUES
(5167, 0, 0,  0,  0, 0),
(5167, 1, 20, 0, 0, 0);

DELETE FROM `spell_areatrigger_rollpitchyaw` WHERE SpellMiscId = 5167;
INSERT INTO `spell_areatrigger_rollpitchyaw` VALUES
(5167, 0, 0, 0, 0, 0, 370.0098, 26124);

UPDATE areatrigger_template SET scriptname = "at_aos_swirling_scythe" WHERE Id = 9899;

UPDATE creature_template SET scriptname = "npc_aos_soul_echo" WHERE entry = 99090;
UPDATE creature_template SET scriptname = "npc_soultorn_vanguard" WHERE entry = 100485;
UPDATE creature_template SET scriptname = "npc_risen_arcanist" WHERE entry = 100486;
