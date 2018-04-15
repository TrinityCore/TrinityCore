DELETE FROM spell_linked_spell WHERE spell_trigger IN(7744,42292,59752);
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
(7744, 72757, 0, 'Will of the Forsaken Cooldown Trigger (WOTF)'),
(42292, 72752, 0, 'Will of the Forsaken Cooldown Trigger'),
(59752, 72752, 0, 'Will of the Forsaken Cooldown Trigger');
