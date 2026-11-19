-- Unstable Affliction / Immolate stacking from same caster
DELETE FROM `spell_group` where `id`=1112;
INSERT INTO spell_group (id, spell_id) VALUES
(1112, 348),
(1112, 30108);
