-- Clear spell_bonus_data from unneeded data
DELETE FROM `spell_bonus_data` WHERE `entry` IN (
-- Already present in DBC:
116,   -- Mage - Frostbolt
120,   -- Mage - Cone of Cold
122,   -- Mage - Frost Nova
133,   -- Mage - Fireball
139,   -- Priest - Renew
331,   -- Shaman - Healing Wave
339,   -- Druid - Entangling Roots
348,   -- Warlock - Immolate, present data for direct part, missing for DOT, fixed in SpellMgr::LoadSpellInfoCorrections
403,   -- Shaman - Lightning Bolt
421,   -- Shaman - Chain Lightning
585,   -- Priest - Smite
596,   -- Priest - Prayer of Healing
603,   -- Warlock - Curse of Doom
635,   -- Paladin - Holy Light
686,   -- Warlock - Shadow Bolt
689,   -- Warlock - Drain Life
755,   -- Warlock - Health Funnel
774,   -- Druid - Rejuvenation
980,   -- Warlock - Curse of Agony
1064,  -- Shaman - Chain Heal
1120,  -- Warlock - Drain Soul
1449,  -- Mage - Arcane Explosion
1949,  -- Warlock - Hellfire
2060,  -- Priest - Greater Heal
2061,  -- Priest - Flash Heal
2120,  -- Mage - Flamestrike
2136,  -- Mage - Fire Blast
2912,  -- Druid - Starfire
2944,  -- Priest - Devouring Plague
2948,  -- Mage - Scorch
3606,  -- Shaman - Searing Totem Attack Rank 1
5176,  -- Druid - Wrath
5185,  -- Druid - Healing Touch
5570,  -- Druid - Insect Swarm
5676,  -- Warlock - Searing Pain
5857,  -- Warlock - Hellfire Effect
6350,  -- Shaman - Searing Totem Attack Rank 2
6351,  -- Shaman - Searing Totem Attack Rank 3
6352,  -- Shaman - Searing Totem Attack Rank 4
6353,  -- Warlock - Soul Fire
6789,  -- Warlock - Death Coil
7268,  -- Mage - Arcane Missile
7294,  -- Paladin - Retribution Aura
8004,  -- Shaman - Lesser Healing Wave
8034,  -- Shaman - Frostbrand Attack Rank 1
8037,  -- Shaman - Frostbrand Attack Rank 2
8042,  -- Shaman - Earth Shock
8050,  -- Shaman - Flame Shock
8056,  -- Shaman - Frost Shock
8092,  -- Priest - Mind Blast
8921,  -- Druid - Moonfire
8936,  -- Druid - Regrowth
10435, -- Shaman - Searing Totem Attack Rank 5
10436, -- Shaman - Searing Totem Attack Rank 6
10458, -- Shaman - Frostbrand Attack Rank 3
11113, -- Mage - Blast Wave
11366, -- Mage - Pyroblast
13376, -- Greater Fire Elemental - Fire Shield
14914, -- Priest - Holy Fire
15237, -- Priest - Holy Nova (damage)
16352, -- Shaman - Frostbrand Attack Rank 4
16353, -- Shaman - Frostbrand Attack Rank 5
17877, -- Warlock - Shadowburn
19236, -- Priest - Desperate Prayer
19750, -- Paladin - Flash of Light
23455, -- Priest- Holy Nova (healing)
25501, -- Shaman - Frostbrand Attack Rank 6
25530, -- Shaman - Searing Totem Attack Rank 7
25912, -- Paladin - Holy Shock (damage)
25914, -- Paladin - Holy Shock (healing)
27243, -- Warlock - Seed of Corruption
27285, -- Warlock - Seed of Corruption proc
29722, -- Warlock - Incinerate
30108, -- Warlock - Unstable Affliction
30283, -- Warlock - Shadowfury
30451, -- Mage - Arcane Blast
30455, -- Mage - Ice Lance
31661, -- Mage - Dragon's Breath
31707, -- Mage - Water Elemental Waterbolt
32379, -- Priest - Shadow Word: Death
32546, -- Priest - Binding Heal
33763, -- Druid - Lifebloom
34861, -- Priest - Circle of Healing
34914, -- Priest - Vampiric Touch
42208, -- Mage - Blizzard
42223, -- Warlock - Rain of Fire
42231, -- Druid - Hurricane
44203, -- Druid - Tranquility
44425, -- Mage - Arcane Barrage
44457, -- Mage - Living Bomb
44461, -- Mage - Living Bomb explosion
44614, -- Mage - Frostfire Bolt
45284, -- Shaman - Lightning Overload Lightning Bolt
45297, -- Shaman - Lightning Overload Chain Lightning
47666, -- Priest - Penance (damage)
47750, -- Priest - Penance (healing)
48438, -- Druid - Wild Growth
49821, -- Priest - Mind Sear
50288, -- Druid - Starfall
50294, -- Druid - Starfall AOE
50464, -- Druid - Nourish
50796, -- Warlock - Chaos Bolt
51505, -- Shaman - Lava Burst
51945, -- Shaman - Earthliving Rank 1
51990, -- Shaman - Earthliving Rank 2
51997, -- Shaman - Earthliving Rank 3
51998, -- Shaman - Earthliving Rank 4
51999, -- Shaman - Earthliving Rank 5
52000, -- Shaman - Earthliving Rank 6
57984, -- Greater Fire Elemental - Fire Blast
58381, -- Priest - Mind Flay
58700, -- Shaman - Searing Totem Attack Rank 8
58701, -- Shaman - Searing Totem Attack Rank 9
58702, -- Shaman - Searing Totem Attack Rank 10
58797, -- Shaman - Frostbrand Attack Rank 7
58798, -- Shaman - Frostbrand Attack Rank 8
58799, -- Shaman - Frostbrand Attack Rank 9
59637, -- Mage - Mirror Image Fire Blast
59638, -- Mage - Mirror Image Frostbolt
61295, -- Shaman - Riptide
61391, -- Druid - Typhoon
64801, -- Druid - T8 Restoration 4P Bonus
64844, -- Priest - Divine Hymn
71757, -- Mage - Deep Freeze damage

-- Unneeded (dummy effects, higher ranks, etc)
633,   -- Paladin - Lay on Hands
2645,  -- Shaman - Ghost Wolf
2819,  -- Rogue - Deadly Poison Rank 2
5138,  -- Warlock - Drain Mana
5672,  -- Shaman - Healing Stream Totem
8026,  -- Shaman - Flametongue Weapon Proc Rank 1
8028,  -- Shaman - Flametongue Weapon Proc Rank 2
8029,  -- Shaman - Flametongue Weapon Proc Rank 3
8129,  -- Priest - Mana Burn
8188,  -- Shaman - Magma Totem Passive Rank 1
10445, -- Shaman - Flametongue Weapon Proc Rank 4
10582, -- Shaman - Magma Totem Passive Rank 2
10583, -- Shaman - Magma Totem Passive Rank 3
10584, -- Shaman - Magma Totem Passive Rank 4
16343, -- Shaman - Flametongue Weapon Proc Rank 5
16344, -- Shaman - Flametongue Weapon Proc Rank 6
18790, -- Warlock - Fel Stamina
20467, -- Paladin - Seal of Command unleashed
25488, -- Shaman - Flametongue Weapon Proc Rank 7
25551, -- Shaman - Magma Totem Passive Rank 5
28176, -- Warlock - Fel Armor
31893, -- Paladin - Seal of Blood
31898, -- Paladin - Seal of Blood unleashed
32220, -- Paladin - Seal of Blood self
32221, -- Paladin - Seal of Blood self proc
34433, -- Priest - Shadowfiend
47476, -- Death Knight - Strangulate
50842, -- Death Knight - Pestilence
53718, -- Paladin - Seal of the Martyr
53719, -- Paladin - Seal of the Martyr unleashed
53725, -- Paladin - Seal of the Martyr self
53726, -- Paladin - Seal of the Martyr self proc
58733, -- Shaman - Magma Totem Passive Rank 6
58736, -- Shaman - Magma Totem Passive Rank 7
58786, -- Shaman - Flametongue Weapon Proc Rank 8
58787, -- Shaman - Flametongue Weapon Proc Rank 9
58788  -- Shaman - Flametongue Weapon Proc Rank 10
);

-- Misc corrections noted while revising table
UPDATE `spell_bonus_data` SET `ap_dot_bonus`=0.02 WHERE `entry`=3674; -- Hunter - Black Arrow
UPDATE `spell_bonus_data` SET `ap_bonus`=0.2, `direct_bonus`=0.32 WHERE `entry`=20187; -- Paladin - Seal of Righteousness unleashed
UPDATE `spell_bonus_data` SET `ap_dot_bonus`=0.025, `dot_bonus`=0.013 WHERE `entry` IN (31803,53742); -- Paladin - Holy Vengeance/Blood Corruption
UPDATE `spell_bonus_data` SET `ap_bonus`=0.14, `direct_bonus`=0.22 WHERE `entry` IN (31804,53733); -- Paladin - Seal of Vengeance/Corruption unleashed
