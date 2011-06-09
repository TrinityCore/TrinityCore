-- Remove Surge of Light (Priest) on cast:
DELETE FROM spell_linked_spell WHERE spell_effect = -88688;
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
-- Flash Heal remove Surge of Light
(2061,-88688,0,'Flash Heal (Rank 1) - Surge of Light'),
(9472,-88688,0,'Flash Heal (Rank 2) - Surge of Light'),
(9473,-88688,0,'Flash Heal (Rank 3) - Surge of Light'),
(9474,-88688,0,'Flash Heal (Rank 4) - Surge of Light'),
(10915,-88688,0,'Flash Heal (Rank 5) - Surge of Light'),
(10916,-88688,0,'Flash Heal (Rank 6) - Surge of Light'),
(10917,-88688,0,'Flash Heal (Rank 7) - Surge of Light'),
(25233,-88688,0,'Flash Heal (Rank 8) - Surge of Light'),
(25235,-88688,0,'Flash Heal (Rank 9) - Surge of Light'),
(48070,-88688,0,'Flash Heal (Rank 10) - Surge of Light'),
(48071,-88688,0,'Flash Heal (Rank 11) - Surge of Light'),
-- Smite remove Surge of Light
(585,-88688,0,'Smite (Rank 1) - Surge of Light'),
(591,-88688,0,'Smite (Rank 2) - Surge of Light'),
(598,-88688,0,'Smite (Rank 3) - Surge of Light'),
(984,-88688,0,'Smite (Rank 4) - Surge of Light'),
(1004,-88688,0,'Smite (Rank 5) - Surge of Light'),
(6060,-88688,0,'Smite (Rank 6) - Surge of Light'),
(10933,-88688,0,'Smite (Rank 7) - Surge of Light'),
(10934,-88688,0,'Smite (Rank 8) - Surge of Light'),
(25363,-88688,0,'Smite (Rank 9) - Surge of Light'),
(25364,-88688,0,'Smite (Rank 10) - Surge of Light'),
(48122,-88688,0,'Smite (Rank 11) - Surge of Light'),
(48123,-88688,0,'Smite (Rank 12) - Surge of Light');

-- Remove Infusion of Light (Paladin) on cast:
DELETE FROM spell_linked_spell WHERE spell_effect IN (-53672,-54149);
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
-- Rank 1 (53672)
-- Holy Light
(635, -53672, 0, 'Holy Light (Rank 1) - Infusion of Light (Rank 1)'),
(639, -53672, 0, 'Holy Light (Rank 2) - Infusion of Light (Rank 1)'),
(647, -53672, 0, 'Holy Light (Rank 3) - Infusion of Light (Rank 1)'),
(1026, -53672, 0, 'Holy Light (Rank 4) - Infusion of Light (Rank 1)'),
(1042, -53672, 0, 'Holy Light (Rank 5) - Infusion of Light (Rank 1)'),
(3472, -53672, 0, 'Holy Light (Rank 6) - Infusion of Light (Rank 1)'),
(10328, -53672, 0, 'Holy Light (Rank 7) - Infusion of Light (Rank 1)'),
(10329, -53672, 0, 'Holy Light (Rank 8) - Infusion of Light (Rank 1)'),
(25292, -53672, 0, 'Holy Light (Rank 9) - Infusion of Light (Rank 1)'),
(27135, -53672, 0, 'Holy Light (Rank 10) - Infusion of Light (Rank 1)'),
(27136, -53672, 0, 'Holy Light (Rank 11) - Infusion of Light (Rank 1)'),
(48781, -53672, 0, 'Holy Light (Rank 12) - Infusion of Light (Rank 1)'),
(48782, -53672, 0, 'Holy Light (Rank 13) - Infusion of Light (Rank 1)'),
-- Flash of light
(19750, -53672, 0, 'Flash of Light (Rank 1) - Infusion of Light (Rank 1)'),
(19939, -53672, 0, 'Flash of Light (Rank 2) - Infusion of Light (Rank 1)'),
(19940, -53672, 0, 'Flash of Light (Rank 3) - Infusion of Light (Rank 1)'),
(19941, -53672, 0, 'Flash of Light (Rank 4) - Infusion of Light (Rank 1)'),
(19942, -53672, 0, 'Flash of Light (Rank 5) - Infusion of Light (Rank 1)'),
(19943, -53672, 0, 'Flash of Light (Rank 6) - Infusion of Light (Rank 1)'),
(27137, -53672, 0, 'Flash of Light (Rank 7) - Infusion of Light (Rank 1)'),
(48784, -53672, 0, 'Flash of Light (Rank 8) - Infusion of Light (Rank 1)'),
(48785, -53672, 0, 'Flash of Light (Rank 9) - Infusion of Light (Rank 1)'),

-- Rank 2 (54149)
-- Holy Light
(635, -54149, 0, 'Holy Light (Rank 1) - Infusion of Light (Rank 2)'),
(639, -54149, 0, 'Holy Light (Rank 2) - Infusion of Light (Rank 2)'),
(647, -54149, 0, 'Holy Light (Rank 3) - Infusion of Light (Rank 2)'),
(1026, -54149, 0, 'Holy Light (Rank 4) - Infusion of Light (Rank 2)'),
(1042, -54149, 0, 'Holy Light (Rank 5) - Infusion of Light (Rank 2)'),
(3472, -54149, 0, 'Holy Light (Rank 6) - Infusion of Light (Rank 2)'),
(10328, -54149, 0, 'Holy Light (Rank 7) - Infusion of Light (Rank 2)'),
(10329, -54149, 0, 'Holy Light (Rank 8) - Infusion of Light (Rank 2)'),
(25292, -54149, 0, 'Holy Light (Rank 9) - Infusion of Light (Rank 2)'),
(27135, -54149, 0, 'Holy Light (Rank 10) - Infusion of Light (Rank 2)'),
(27136, -54149, 0, 'Holy Light (Rank 11) - Infusion of Light (Rank 2)'),
(48781, -54149, 0, 'Holy Light (Rank 12) - Infusion of Light (Rank 2)'),
(48782, -54149, 0, 'Holy Light (Rank 13) - Infusion of Light (Rank 2)'),
-- Flash of light
(19750, -54149, 0, 'Flash of Light (Rank 1) - Infusion of Light (Rank 2)'),
(19939, -54149, 0, 'Flash of Light (Rank 2) - Infusion of Light (Rank 2)'),
(19940, -54149, 0, 'Flash of Light (Rank 3) - Infusion of Light (Rank 2)'),
(19941, -54149, 0, 'Flash of Light (Rank 4) - Infusion of Light (Rank 2)'),
(19942, -54149, 0, 'Flash of Light (Rank 5) - Infusion of Light (Rank 2)'),
(19943, -54149, 0, 'Flash of Light (Rank 6) - Infusion of Light (Rank 2)'),
(27137, -54149, 0, 'Flash of Light (Rank 7) - Infusion of Light (Rank 2)'),
(48784, -54149, 0, 'Flash of Light (Rank 8) - Infusion of Light (Rank 2)'),
(48785, -54149, 0, 'Flash of Light (Rank 9) - Infusion of Light (Rank 2)');