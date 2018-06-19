UPDATE creature_template SET inhabitType = 4 WHERE entry = 81907;

DELETE FROM spell_script_names WHERE scriptname = "spell_shadowmoon_claiming";
INSERT INTO spell_script_names VALUES
(169455, "spell_shadowmoon_claiming");

UPDATE creature_template SET npcflag = npcflag | 8589934592 WHERE entry IN (81369, 86018, 86016, 80600, 85806, 86017, 80426);
