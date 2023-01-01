-- Conflicts: Halazzi (23577) uses no corresponding difficulty flag (probably removed in Cata)
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00000020 WHERE `entry` IN
(15689, -- Netherspite
16011, -- Loatheb
16028, -- Patchwerk
17842, -- Azgalor
17968, -- Archimonde
21216, -- Hydross the Unstable
21362, -- Phoenix
21932, -- Hydross the Unstable
22409, -- ZZZ - Dan Reed Test
22878, -- Aqueous Lord
22898, -- Supremus
22917, -- Illidan Stormrage
22947, -- Mother Shahraz
22949, -- Gathios the Shatterer
22950, -- High Nethermancer Zerevor
22997, -- Flame of Azzinoth
23375, -- Shadow Demon
23418, -- Essence of Suffering
23576, -- Nalorakk
23899, -- Tethyr
24674, -- Phoenix
24850, -- Kalecgos
24882, -- Brutallus
24891, -- Kalecgos
24892, -- Sathrovarr the Corruptor
25038, -- Felmyst
25315, -- Kil'jaeden
25507, -- Sunblade Protector
25772, -- Void Sentinel
25840, -- Entropius
26893, -- Grauf
27605, -- Colossal Abomination
27696, -- The Prophet Tharon'ja
28859, -- Malygos
29542, -- Archbishop Landgren
29620, -- Dreadlord Mal'Ganis
29621, -- Grand Admiral Westwind
29629, -- Owen Test Creature
31099, -- Patchwerk
32845, -- Hodir
32857, -- Stormcaller Brundir
32865, -- Thorim
32867, -- Steelbreaker
32871, -- Algalon the Observer
32927, -- Runemaster Molgeim
33113, -- Flame Leviathan
33118, -- Ignis the Furnace Master
33186, -- Razorscale
33271, -- General Vezax
33293, -- XT-002 Deconstructor
33329, -- Heart of the Deconstructor
33432, -- Leviathan Mk II
33524, -- Saronite Animus
33651, -- VX-001
33663, -- Patchwerk (PTR DPS Test)
33667, -- Patchwerk (PTR Tank Test)
33670, -- Aerial Command Unit
33806, -- Void Beast
33988, -- Immortal Guardian
34035, -- Feral Defender
34515, -- XT-005 Debugger
34564, -- Anub'arak
34567, -- Dark Essence
34568, -- Light Essence
34702, -- Ambrose Boltspark
34780, -- Lord Jaraxxus
34815, -- Felflame Infernal
34826, -- Mistress of Pain
34921, -- Felflame Infernal Ball
34922, -- Overlord Agmar
34924, -- High Commander Halford Wyrmbane
34925, -- North Sea Kraken
36064, -- Marked Immortal Guardian
36597, -- The Lich King
36612, -- Lord Marrowgar
36626, -- Festergut
36627, -- Rotface
36678, -- Professor Putricide
36789, -- Valithria Dreamwalker
36897, -- Little Ooze
36899, -- Big Ooze
36939, -- High Overlord Saurfang
36948, -- Muradin Bronzebeard
37022, -- Blighted Abomination
37037, -- Acanthurus
37098, -- Val'kyr Herald
37126, -- Sister Svalna
37193, -- Balistoides
37194, -- Chaetodon
37530, -- Slimy Tentacle
37531, -- Frostwarden Handler
37535, -- Ooze Covered Tentacle
37562, -- Gas Cloud
37672, -- Mutated Abomination
37697, -- Volatile Ooze
37813, -- Deathbringer Saurfang
37886, -- Gluttonous Abomination
37934, -- Blistering Zombie
37955, -- Blood-Queen Lana'thel
37970, -- Prince Valanar
37972, -- Prince Keleseth
37973, -- Prince Taldaram
38004, -- Blood-Queen Lana'thel
38019, -- Anolis
38020, -- Basiliscus
38021, -- Conolophus
38216, -- Mutated Professor Putricide
38285, -- Mutated Abomination
38308, -- Ooze Covered Tentacle Stalker
38309, -- Slimy Tentacle Stalker
38367, -- Tesla Coil Stalker
38386, -- Patchwerk (PTR All-Around Test)
38572, -- Bug 181860
38589, -- Valithria Dreamwalker
38708, -- Devilsaur Queen
38883, -- Idle Before Scaling
39165, -- Fire Ball
39231, -- The Lich King (Temp)
39625, -- General Umbriss
39788, -- Anraphet
39800, -- Flame Warden
39801, -- Earth Warden
40177, -- Forgemaster Throngus
40319, -- Drahga Shadowburner
40320, -- Valiona
40484, -- Erudax
40960, -- Bug 193702
41442, -- Atramedes
42305, -- North Sea Kraken
43226, -- The 1000 DPS Man
43324, -- Cho'gall
43486, -- The 10000 DPS Man
43622, -- Corrupting Adherent
43707, -- Blood of the Old God
43888, -- Malformation
43922, -- Absolute Corruption
44023, -- Darkened Creation
45858, -- Congealed Blood
45992, -- Valiona
45993, -- Theralion
46965, -- Cho'gall
47120, -- Argaloth
47257, -- Cho'gall
47259, -- Twilight Servant
47261, -- Eye of Twilight
47262, -- Camera Bunny
47307, -- Eye of Twilight
48142, -- Cho'gall
48145, -- Twilight Servant
49185, -- Camera Target Bunny
50264, -- Spiked Tentacle
51437, -- Forgemaster Throngus
51493, -- Cho'gall
51494, -- Cho'gall
51599, -- Cho'gall
52151, -- Bloodlord Mandokir
54310, -- Camera Target Bunny 01
54311, -- Camera Target Bunny 02
54590, -- Arcurion
54646, -- Corrupted Slime
54686, -- Shadow Borer
54696, -- Flailing Tentacle
55520, -- [ph] Tough Guy
55657, -- [ph] Tough Guys Spirit
55660, -- [ph] Tough Guy Spirit 2
55869, -- Alizabal
56589, -- Striker Ga'dok
56636, -- Commander Ri'mok
57758, -- Camera Target Bunny
57910, -- Nalice
58122, -- Camera Target Bunny
58584, -- Camera Target Bunny
58629, -- Camera Target Bunny
58663, -- Camera Target Bunny
60009, -- Feng the Accursed
60016, -- Feng the Accursed
60018, -- Feng the Accursed
60019, -- Feng the Accursed
60020, -- Feng the Accursed
62511, -- Amber-Shaper Un'sok
62711, -- Amber Monstrosity
62837, -- Grand Empress Shek'zeer
63666, -- Amber-Shaper Un'sok
68078, -- Iron Qon
68397, -- Lei Shen
68904, -- Suen
68905, -- Lu'lin
69012, -- Lesser Diffused Lightning
69013, -- Diffused Lightning
69014, -- Greater Diffused Lightning
69095, -- Test Subject
69232, -- Ball Lightning
69473, -- Ra-den
69781, -- Bug 348427
70135, -- Teleport Transform
70139, -- RRP Test Creature
70437, -- Lei Shen
70455, -- Bug 348456
70592, -- Teleport Transform
71246, -- Norushen
71466, -- Iron Juggernaut
71529, -- Thok the Bloodthirsty
71658, -- Kor'kron Jailer
71742, -- Akolik
71744, -- Skumblade Captive
71749, -- Waterspeaker Gorai
71753, -- Inkgill Captive
71763, -- Montak
71764, -- Gai-Cho Refugee
71865, -- Garrosh Hellscream
72224, -- Bug 365757 Jumper
72249, -- Galakras
72349, -- Garrosh Hellscream
72616, -- Iron Juggernaut
72748, -- Transform Dummy
72749, -- Transform Dummy
72750, -- Transform Dummy
72957, -- Galakras
73081, -- Garrosh Hellscream
73103, -- Garrosh Hellscream
73195, -- Kor'kron Jailer
73462, -- Garrosh Hellscream
73620, -- Garrosh Hellscream
73663, -- Transform Dummy
-- Difficulties
29324,29718,30775,31734,32846,33070,33147,33190,33449,33664,33668,33692,33693,33694,33724,33815,33885,33989,33995,34003,34106,34108,34109,34152,34171,34566,35216,35262,35263,35264,35268,35269,35270,35271,35272,35403,35405,35615,35616,36067,36082,37504,37505,37506,37957,37958,37959,38108,38123,38138,38139,38156,38157,38166,38170,38174,38258,38388,38390,38399,38400,38401,38402,38418,38431,38434,38435,38436,38549,38550,38582,38583,38585,38586,38590,38602,38604,38605,38637,38638,38639,38640,38723,38724,38733,38734,38758,38759,38760,38761,38769,38770,38771,38772,38784,38785,38786,38787,38788,38789,38790,39166,39167,39168,39232,39233,39234,48337,48702,48784,48801,48822,49583,49584,49585);
