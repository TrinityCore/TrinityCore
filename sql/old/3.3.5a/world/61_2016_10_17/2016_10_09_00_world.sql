-- Evasive Maneuvers, proc charges on miss instead of on dodge
UPDATE `spell_proc` SET `HitMask`=0x4 WHERE `SpellId`=50240;

UPDATE `spell_proc` SET `SpellTypeMask`=`SpellTypeMask`|0x1 WHERE `SpellId` IN (
-58872, -- Damage Shield
-57878, -- Natural Reaction
-52127, -- Water Shield
-51634, -- Focused Attacks
-49027, -- Bloodworms
-48988, -- Bloody Vengeance
-46867, -- Wrecking Crew
-46854, -- Trauma
-45234, -- Focused Will
-41635, -- Prayer of Mending
-34950, -- Go for the Throat
-34935, -- Backlash
-34500, -- Expose Weakness
-33881, -- Natural Perfection
-33150, -- Surge of Light
-33142, -- Blessed Resilience
-30701, -- Elemental Absorption
-30299, -- Nether Protection
-30160, -- Elemental Devastation
-20049, -- Vengeance
-16958, -- Primal Fury
-16256, -- Flurry
-12319, -- Flurry
7383,   -- Water Bubble
8178,   -- Grounding Totem Effect
15600,  -- Hand of Justice
16164,  -- Elemental Focus
16620,  -- Proc Self Invulnerability
17364,  -- Stormstrike
20164,  -- Seal of Justice
20165,  -- Seal of Light
20166,  -- Seal of Wisdom
20375,  -- Seal of Command
20784,  -- Tamed Pet Passive 07 (DND)
23552,  -- Lightning Shield
23578,  -- Expose Weakness
23581,  -- Bloodfang
23686,  -- Lightning Strike
23689,  -- Heroism
24353,  -- Primal Instinct
25669,  -- Decapitate
26480,  -- Badge of the Swarmguard
27656,  -- Flame Lash
27774,  -- The Furious Storm
28752,  -- Adrenaline Rush
28845,  -- Cheat Death
29150,  -- Electric Discharge
29501,  -- Frost Arrow
29624,  -- Searing Arrow
29625,  -- Flaming Cannonball
29626,  -- Shadow Bolt
29632,  -- Shadow Bolt
29633,  -- Fire Blast
29634,  -- Quill Shot
29635,  -- Flaming Shell
29636,  -- Venom Shot
29637,  -- Keeper's Sting
30823,  -- Shamanistic Rage
32734,  -- Earth Shield
32844,  -- Lesser Heroism
33297,  -- Spell Haste Trinket
33510,  -- Health Restore
33648,  -- Reflection of Torment
34074,  -- Aspect of the Viper
34320,  -- Call of the Nexus
34355,  -- Poison Shield
34586,  -- Romulo's Poison
34598,  -- Karazhan Caster Robe
34774,  -- Magtheridon Melee Trinket
34827,  -- Water Shield
35080,  -- Band of the Eternal Champion
35083,  -- Band of the Eternal Sage
35086,  -- Band of the Eternal Restorer
35121,  -- Nether Power
36111,  -- World Breaker
37170,  -- Free Finisher Chance
37213,  -- Mana Cost Reduction
37600,  -- Offensive Discount
37657,  -- Lightning Capacitor
38026,  -- Viscous Shield
38164,  -- Unyielding Knights
38290,  -- Santos' Blessing
38350,  -- Crit Proc Heal
38857,  -- Spell Ground
39027,  -- Poison Shield
39442,  -- Aura of Wrath
39443,  -- Aura of Wrath
40475,  -- Black Temple Melee Trinket
40482,  -- Mage Tier 6 Trinket
41434,  -- The Twin Blades of Azzinoth
41989,  -- Fists of Fury
42083,  -- Fury of the Crashing Waves
42135,  -- Lesser Rune of Warding
42136,  -- Greater Rune of Warding
45054,  -- Augment Pain
45057,  -- Evasive Maneuvers
45354,  -- Item - Sunwell Dungeon Melee Trinket
45355,  -- Item - T7 Melee Trinket Base
45481,  -- Sunwell Exalted Caster Neck
45482,  -- Sunwell Exalted Melee Neck
45483,  -- Sunwell Exalted Tank Neck
46569,  -- Sunwell Exalted Caster Neck
46662,  -- Deathfrost
49222,  -- Bone Shield
49592,  -- Temporal Rift
52420,  -- Deflection
52898,  -- Spell Damping
53397,  -- Invigoration
53646,  -- Demonic Pact
54278,  -- Empowered Imp
54646,  -- Focus Magic
54695,  -- Item - Death Knight's Anguish Base
54707,  -- Sonic Awareness (DND)
54841,  -- Thunder Capacitor
54909,  -- Demonic Pact
55689,  -- Glyph of Shadow
55747,  -- Argent Fury
55776,  -- Swordguard Embroidery
56451,  -- Earth Shield
57345,  -- Darkmoon Card: Greatness
58444,  -- Worg Tooth Oatmeal Stout
58901,  -- Tears of Anguish
59345,  -- Chagrin
59630,  -- Black Magic
60066,  -- Rage of the Unraveller
60221,  -- Essence of Gossamer
60301,  -- Meteorite Whetstone
60306,  -- Vestige of Haldor
60317,  -- Signet of Edward the Odd
60436,  -- Grim Toll
60442,  -- Bandit's Insignia
60473,  -- Forge Ember
60487,  -- Extract of Necromatic Power [sic]
61356,  -- Invigorating Earthsiege Diamond Passive
62115,  -- Strength of the Titans
63251,  -- Glory of the Jouster
64792,  -- Blood of the Old God
65007,  -- Eye of the Broodmother
67151,  -- Item - Hunter T9 4P Bonus (Steady Shot)
67712,  -- Item - Coliseum 25 Normal Caster Trinket
67758,  -- Item - Coliseum 25 Heroic Caster Trinket
71634,  -- Item - Icecrown 25 Normal Tank Trinket 1
71640,  -- Item - Icecrown 25 Heroic Tank Trinket 1
72417,  -- Item - Icecrown Reputation Ring Caster Trigger
75475,  -- Item - Chamber of Aspects 25 Tank Trinket
75481   -- Item - Chamber of Aspects 25 Heroic Trinket
);

UPDATE `spell_proc` SET `SpellTypeMask`=`SpellTypeMask`|0x2 WHERE `SpellId` IN (
-51940, -- Earthliving Weapon (Passive)
-47509, -- Divine Aegis
-33150, -- Surge of Light
33953,  -- Essence of Life
34320,  -- Call of the Nexus
35086,  -- Band of the Eternal Restorer
38299,  -- HoTs on Heals
45484,  -- Sunwell Exalted Healer Neck
57345,  -- Darkmoon Card: Greatness
60473,  -- Forge Ember
60529,  -- Forethought Talisman
64411,  -- Blessing of Ancient Kings
64415,  -- Val'anyr Hammer of Ancient Kings - Equip Effect
65007,  -- Eye of the Broodmother
72419   -- Item - Icecrown Reputation Ring Healer Trigger
);
