-- Add items to spell_loot_template
DELETE FROM `spell_loot_template` WHERE `Entry` IN (86883,86884,86885,86656);
INSERT INTO `spell_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(86883, 62336, 0, 100, 0, 1, 0, 1, 1, 'Spell Cataclysm Reclamation: Jewelcrafting creates Plans Random jewelcrafting design'),
(86884, 62337, 0, 100, 0, 1, 0, 1, 1, 'Spell Cataclysm Reclamation: Leatherworking creates Plans Random leatherworking pattern'),
(86885, 62338, 0, 100, 0, 1, 0, 1, 1, 'Spell Cataclysm Reclamation: Tailoring creates Plans Random tailoring pattern'),
(86656, 62312, 0, 100, 0, 1, 0, 1, 1, 'Spell Cataclysm Reclamation: Blacksmithing creates Plans Random blacksmithing plan');
