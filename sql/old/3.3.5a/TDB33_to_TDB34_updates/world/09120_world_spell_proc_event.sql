DELETE FROM `spell_proc_event` WHERE `entry` IN (51459,51462,51463,51464,51465,49219,49627,49628);
INSERT INTO `spell_proc_event`(`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(51459,0,0,0,0,0,4,0,0,0,0), -- Necrosis Rank 1
(51462,0,0,0,0,0,4,0,0,0,0), -- Necrosis Rank 2
(51463,0,0,0,0,0,4,0,0,0,0), -- Necrosis Rank 3
(51464,0,0,0,0,0,4,0,0,0,0), -- Necrosis Rank 4
(51465,0,0,0,0,0,4,0,0,0,0), -- Necrosis Rank 5
(49219,0,0,0,0,0,4,0,0,0,0), -- Blood-Caked Blade Rank 1
(49627,0,0,0,0,0,4,0,0,0,0), -- Blood-Caked Blade Rank 2
(49628,0,0,0,0,0,4,0,0,0,0); -- Blood-Caked Blade Rank 3
