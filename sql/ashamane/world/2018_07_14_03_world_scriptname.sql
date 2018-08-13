DELETE FROM spell_script_names WHERE scriptname in ("spell_pal_aura_of_sacrifice", "spell_pal_aura_of_sacrifice_ally");
INSERT INTO spell_script_names VALUES
(210372, "spell_pal_aura_of_sacrifice_ally");

DELETE FROM spell_areatrigger WHERE SpellMiscId = 6777;
INSERT INTO spell_areatrigger (SpellMiscId, AreaTRiggerId) VALUES
(6777, 100102);

DELETE FROM areatrigger_template WHERE Id = 100102;
INSERT INTO areatrigger_template VALUES
(100102, 0, 4, 10, 10, 0, 0, 0, 0, "at_pal_aura_of_sacrifice", 0);
