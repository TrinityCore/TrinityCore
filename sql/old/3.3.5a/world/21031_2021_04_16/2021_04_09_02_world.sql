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
38883, -- ScottG Test
39231, -- The Lich King (Temp)
-- Difficulties
29324,29718,30775,31734,32846,33070,33147,33190,33449,33664,33668,33692,33693,33694,33724,33815,33885,33989,33995,34003,34106,34108,34109,34152,34171,34566,35216,35262,35263,35264,35268,35269,35270,35271,35272,35403,35405,35615,35616,36067,36082,37504,37505,37506,37957,37958,37959,38108,38123,38138,38139,38156,38157,38166,38170,38174,38258,38388,38390,38399,38400,38401,38402,38418,38431,38434,38435,38436,38549,38550,38582,38583,38585,38586,38590,38602,38604,38605,38637,38638,38639,38640,38723,38724,38733,38734,38758,38759,38760,38761,38769,38770,38771,38772,38784,38785,38786,38787,38788,38789,38790,39166,39167,39168,39232,39233,39234);
