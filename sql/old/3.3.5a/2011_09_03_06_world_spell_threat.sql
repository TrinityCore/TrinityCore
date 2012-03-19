-- ----------
-- Tank Class Passive Threat
-- ----------
DELETE FROM spell_linked_spell WHERE spell_effect IN (57340, 57339);
INSERT INTO spell_linked_spell VALUES
    (7376,  57339, 2, 'Defensive Stance Passive - Tank Class Passive Threat'),
    (21178, 57339, 2, 'Bear Form (Passive2) - Tank Class Passive Threat'),
    (25780, 57340, 2, 'Righteous Fury - Tank Class Passive Threat'),
    (48263, 57340, 2, 'Frost Presence - Tank Class Passive Threat');

-- ----------
-- restructure spell_threat
-- ----------
TRUNCATE TABLE `spell_threat`;
ALTER    TABLE `spell_threat` CHANGE `Threat` `flatMod` int(6);
ALTER    TABLE `spell_threat` ADD COLUMN `pctMod`   FLOAT NOT NULL DEFAULT 1.0 COMMENT 'threat multiplier for damage/healing' AFTER `flatMod`;
ALTER    TABLE `spell_threat` ADD COLUMN `apPctMod` FLOAT NOT NULL DEFAULT 0.0 COMMENT 'additional threat bonus from attack power' AFTER `pctMod`;
INSERT INTO `spell_threat` VALUES
-- Other
-- Src: SELECT id, SpellNameEN, RankEN FROM `Spell` WHERE `DescriptionEN` LIKE '%threat%' AND `SpellFamilyName` <> '0' AND NOT (Attributes & 0x40) GROUP BY SpellNameEN ORDER BY RankEN DESC;
    (5676,  0,   2.00, 0.0),  -- Searing Pain (Rank 1) (Warlock)
    (28176, 0,   0.00, 0.0),  -- Fel Armor - Heal (Rank 1) (Warlock) [Assumption]
    (8056,  0,   2.00, 0.0),  -- Frost Shock (Rank 1) (Shaman) [Assumption]
    (26688, 0,   0.00, 0.0),  -- Anesthetic Poison - Proc (Rank 1) (Rogue)
    (15237, 0,   0.00, 0.0),  -- Holy Nova - Heal (Rank 1) (Priest)
    (23455, 0,   0.00, 0.0),  -- Holy Nova - Damage (Rank 1) (Priest)
    (32546, 0,   0.50, 0.0),  -- Binding Heal (Rank 1) (Priest) [Assumption]
    (33619, 0,   0.00, 0.0),  -- Reflective Shield - Proc (Priest)
    (2139,  180, 1.00, 0.0),  -- Counterspell (Mage) [Assumption]
-- Death Knight
-- Src: http://www.tankspot.com/showthread.php?40485-Death-Knight-threat-values&p=113584#post113584
    (63611, 0,   0.00, 0.0),  -- Blood Presence - Heal
    (45524, 240, 1.00, 0.0),  -- Chains of Ice
    (43265, 0,   1.90, 0.0),  -- Death and Decay
    (49576, 110, 1.00, 0.0),  -- Death Grip
    (48743, 0,   0.00, 0.0),  -- Death Pact
    (65142, 0,   0.00, 0.0),  -- Ebon Plague
    (47568, 0,   0.00, 0.0),  -- Empower Rune Weapon
    (51209, 112, 1.00, 0.0),  -- Hungering Cold
    (49039, 110, 1.00, 0.0),  -- Lichborn
    (56815, 0,   1.75, 0.0),  -- Rune Strike
    (50422, 0,   0.00, 0.0),  -- Scent of Blood - Proc
    (55090, 51,  1.00, 0.0),  -- Scourge Strike (Rank 1)
    (55265, 63,  1.00, 0.0),  -- Scourge Strike (Rank 2)
    (55270, 98,  1.00, 0.0),  -- Scourge Strike (Rank 3)
    (55271, 120, 1.00, 0.0),  -- Scourge Strike (Rank 4)
    (49916, 138, 1.00, 0.0),  -- Strangulate
    (50181, 0,   0.00, 0.0),  -- Vendetta - Proc
-- Druid
-- Src: http://www.tankspot.com/showthread.php?47813-WOTLK-Bear-Threat-Values&p=200948#post200948
    (17057, 0,   0.00, 0.0),  -- Furor - Proc 
    (5211,  53,  1.00, 0.0),  -- Bash (Rank 3)
    (6798,  105, 1.00, 0.0),  -- Bash (Rank 2)
    (8983,  158, 1.00, 0.0),  -- Bash (Rank 1)
    (45334, 40,  1.00, 0.0),  -- Feral Charge (Bear) - Root
    (19675, 80,  1.00, 0.0),  -- Feral Charge (Bear) - Interrupt
    (34299, 0,   0.00, 0.0),  -- Improved Leader of the Pack - Heal
    (6807,  13,  1.00, 0.0),  -- Maul (Rank 1)
    (6808,  20,  1.00, 0.0),  -- Maul (Rank 2)
    (6809,  27,  1.00, 0.0),  -- Maul (Rank 3)
    (8972,  47,  1.00, 0.0),  -- Maul (Rank 4)
    (9745,  75,  1.00, 0.0),  -- Maul (Rank 5)
    (9880,  106, 1.00, 0.0),  -- Maul (Rank 6)
    (9881,  140, 1.00, 0.0),  -- Maul (Rank 7)
    (26996, 212, 1.00, 0.0),  -- Maul (Rank 8)
    (48479, 345, 1.00, 0.0),  -- Maul (Rank 9)
    (48480, 422, 1.00, 0.0),  -- Maul (Rank 10)
    (60089, 638, 1.00, 0.0),  -- Faerie Fire (Feral) - Proc
    (33745, 182, 0.50, 0.0),  -- Lacerate (Rank 1)
    (48567, 409, 0.50, 0.0),  -- Lacerate (Rank 2)
    (48568, 515, 0.50, 0.0),  -- Lacerate (Rank 3)
    (779,   0,   1.50, 0.0),  -- Swipe (Bear) (Rank 1)
    (5209,  98,  1.00, 0.0),  -- Challenging Roar
    (29166, 0,   10.0, 0.0),  -- Innervate [base is 5 per 1 mana]
-- Paladin
-- Src: http://www.tankspot.com/showthread.php?39761-Paladin-Threat-Values-(Updated-for-3.2.2)&p=103813#post103813
    (7294,  0,   2.00, 0.0),  -- Retribution Aura
    (20185, 0,   0.00, 0.0),  -- Judgement of Light
    (19742, 0,   0.00, 0.0),  -- Blessing of Wisdom (Rank 1)
    (25894, 0,   0.00, 0.0),  -- Greater Blessing of Wisdom (Rank 1)
    (20470, 0,   0.00, 0.0),  -- Righteous Fury
    (498,   0,   0.00, 0.0),  -- Divine Protection
-- Warrior
-- Src: http://www.tankspot.com/showthread.php?39775-WoW-3.0-Threat-Values-(Warrior)&p=103972#post103972
    (845,   8,   1.00, 0.0),  -- Cleave (Rank 1)
    (7369,  15,  1.00, 0.0),  -- Cleave (Rank 2)
    (11608, 25,  1.00, 0.0),  -- Cleave (Rank 3)
    (11609, 35,  1.00, 0.0),  -- Cleave (Rank 4)
    (20569, 48,  1.00, 0.0),  -- Cleave (Rank 5)
    (25231, 68,  1.00, 0.0),  -- Cleave (Rank 6)
    (47519, 95,  1.00, 0.0),  -- Cleave (Rank 7)
    (47520, 112, 1.00, 0.0),  -- Cleave (Rank 8)
    (78,    5,   1.00, 0.0),  -- Heroic Strike (Rank 1)
    (284,   10,  1.00, 0.0),  -- Heroic Strike (Rank 2)
    (285,   16,  1.00, 0.0),  -- Heroic Strike (Rank 3)
    (1608,  22,  1.00, 0.0),  -- Heroic Strike (Rank 4)
    (11564, 31,  1.00, 0.0),  -- Heroic Strike (Rank 5)
    (11565, 48,  1.00, 0.0),  -- Heroic Strike (Rank 6)
    (11566, 70,  1.00, 0.0),  -- Heroic Strike (Rank 7)
    (11567, 92,  1.00, 0.0),  -- Heroic Strike (Rank 8)
    (25286, 104, 1.00, 0.0),  -- Heroic Strike (Rank 9)
    (29707, 121, 1.00, 0.0),  -- Heroic Strike (Rank 10)
    (30324, 164, 1.00, 0.0),  -- Heroic Strike (Rank 11)
    (47449, 224, 1.00, 0.0),  -- Heroic Strike (Rank 12)
    (47450, 259, 1.00, 0.0),  -- Heroic Strike (Rank 13)
    (57755, 0,   1.50, 0.0),  -- Heroic Throw
    (6572,  7,   1.00, 0.0),  -- Revenge (Rank 1)
    (6574,  11,  1.00, 0.0),  -- Revenge (Rank 2)
    (7379,  15,  1.00, 0.0),  -- Revenge (Rank 3)
    (11600, 27,  1.00, 0.0),  -- Revenge (Rank 4)
    (11601, 41,  1.00, 0.0),  -- Revenge (Rank 5)
    (25288, 53,  1.00, 0.0),  -- Revenge (Rank 6)
    (25269, 58,  1.00, 0.0),  -- Revenge (Rank 7)
    (30357, 71,  1.00, 0.0),  -- Revenge (Rank 8)
    (57823, 121, 1.00, 0.0),  -- Revenge (Rank 9)
    (23922, 228, 1.00, 0.0),  -- Shield Slam (Rank 1)
    (23923, 268, 1.00, 0.0),  -- Shield Slam (Rank 2)
    (23924, 307, 1.00, 0.0),  -- Shield Slam (Rank 3)
    (23925, 347, 1.00, 0.0),  -- Shield Slam (Rank 4)
    (25258, 387, 1.00, 0.0),  -- Shield Slam (Rank 5)
    (30356, 426, 1.00, 0.0),  -- Shield Slam (Rank 6)
    (47487, 650, 1.00, 0.0),  -- Shield Slam (Rank 7)
    (47488, 770, 1.00, 0.0),  -- Shield Slam (Rank 8)
    (1464,  18,  1.00, 0.0),  -- Slam (Rank 1)
    (8820,  24,  1.00, 0.0),  -- Slam (Rank 2)
    (11604, 38,  1.00, 0.0),  -- Slam (Rank 3)
    (11605, 49,  1.00, 0.0),  -- Slam (Rank 4)
    (25241, 59,  1.00, 0.0),  -- Slam (Rank 5)
    (25242, 78,  1.00, 0.0),  -- Slam (Rank 6)
    (47474, 123, 1.00, 0.0),  -- Slam (Rank 7)
    (47475, 140, 1.00, 0.0),  -- Slam (Rank 8)
    (7386,  345, 1.00, 0.05), -- Sunder Armor
    (20243, 0,   1.00, 0.05), -- Devastate (Rank 1)
    (6343,  0,   1.85, 0.0);  -- Thunder Clap (Rank 1)
