DELETE FROM `spell_proc_event` WHERE `entry` IN ('15337','15338');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('15337','0','6','8396800','2','0','0','2','0','0','0'), -- Improved Spirit Tap (Rank 1)
('15338','0','6','8396800','2','0','0','2','0','0','0'); -- Improved Spirit Tap (Rank 2)
