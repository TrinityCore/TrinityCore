-- Spells Ids that were not in 3.3.5 dbc but present in 4.3.4
DELETE FROM `spell_dbc` WHERE `Id` IN (37264, 56817, 64748, 64934, 65142, 74805, 100000);
