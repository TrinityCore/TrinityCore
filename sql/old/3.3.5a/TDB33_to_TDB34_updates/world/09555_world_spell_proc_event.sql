-- Idols
-- Librams
-- Totems
-- Sigils
DELETE FROM `spell_proc_event` WHERE `entry` IN (71214, 71217, 67389, 67386, 67392, 71178, 67361, 71176, 71191, 71194, 71186, 67379, 67365, 67363, 64955, 71228, 71226, 67381, 67384);
INSERT INTO `spell_proc_event` VALUES
( 64955, 0x00,  10, 0x00000000, 0x00000040, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T8 Protection Relic
( 67361, 0x00,   7, 0x00000002, 0x00000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Item - Druid T9 Balance Relic (Moonfire)
( 67363, 0x00,  10, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Item - Paladin T9 Holy Relic (Judgement)
( 67365, 0x00,  10, 0x00000000, 0x00000800, 0x00000000, 0x00040000, 0x00000000,   0,   0,   6), -- Item - Paladin T9 Retribution Relic (Seal of Vengeance)
( 67379, 0x00,  10, 0x00000000, 0x00040000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T9 Protection Relic (Hammer of The Righteous)
( 67381, 0x00,  15, 0x00000000, 0x20000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,  10), -- Item - Death Knight T9 Tank Relic (Rune Strike)
( 67384, 0x00,  15, 0x00000010, 0x08020000, 0x00000000, 0x00000000, 0x00000000,   0,  80,  10), -- Item - Death Knight T9 Melee Relic (Rune Strike)
( 67386, 0x00,  11, 0x00000001, 0x00000000, 0x00000000, 0x00010000, 0x00000000,   0,   0,   6), -- Item - Shaman T9 Elemental Relic (Lightning Bolt)
( 67389, 0x00,  11, 0x00000100, 0x00000000, 0x00000000, 0x00004000, 0x00000000,   0,   0,   8), -- Item - Shaman T9 Restoration Relic (Chain Heal)
( 67392, 0x00,  11, 0x00000000, 0x00000000, 0x00000004, 0x00000010, 0x00000000,   0,   0,   0), -- Item - Shaman T9 Enhancement Relic (Lava Lash)
( 71176, 0x00,   7, 0x00200002, 0x00000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Item - Druid T10 Balance Relic (Moonfire and Insect Swarm)
( 71178, 0x00,   7, 0x00000010, 0x00000000, 0x00000000, 0x00040000, 0x00000000,   0,   0,   0), -- Item - Druid T10 Restoration Relic (Rejuvenation)
( 71186, 0x00,  10, 0x00000000, 0x00008000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T10 Retribution Relic (Crusader Strike)
( 71191, 0x00,  10, 0x00000000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T10 Holy Relic (Holy Shock)
( 71194, 0x00,  10, 0x00000000, 0x00100000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Paladin T10 Protection Relic (Shield of Righteousness)
( 71214, 0x00,  11, 0x00001400, 0x00000010, 0x00000000, 0x00000010, 0x00000000,   0,   0,   6), -- Item - Shaman T10 Enhancement Relic (Stormstrike)
( 71217, 0x00,  11, 0x00000000, 0x00000000, 0x00000010, 0x00004000, 0x00000000,   0,   0,   0), -- Item - Shaman T10 Restoration Relic (Riptide)
( 71226, 0x00,  15, 0x00000010, 0x08020000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Death Knight T10 DPS Relic (Obliterate, Scourge Strike, Death Strike)
( 71228, 0x00,  15, 0x00000000, 0x20000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Item - Death Knight T10 Tank Relic (Runestrike)