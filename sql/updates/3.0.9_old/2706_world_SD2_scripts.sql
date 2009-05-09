UPDATE creature_template SET ScriptName='npc_kingdom_of_dalaran_quests' WHERE entry IN (29169,23729,26673,27158,29158,29161,26471,29155,29159,29160,29162);
DELETE FROM spell_target_position WHERE id=53360;
INSERT INTO spell_target_position VALUES
(53360, 571, 5807.829, 587.960, 660.939, 1.663);