--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00080000 WHERE `entry` IN
(10184, -- Onyxia
15928, -- Thaddius
15931, -- Grobbulus
15932, -- Gluth
15936, -- Heigan the Unclean
15952, -- Maexxna
15953, -- Grand Widow Faerlina
15954, -- Noth the Plaguebringer
15956, -- Anub'Rekhan
15989, -- Sapphiron
15990, -- Kel'Thuzad
16011, -- Loatheb
16028, -- Patchwerk
16060, -- Gothik the Harvester
28859, -- Malygos
28860, -- Sartharion
30449, -- Vesperon
30451, -- Shadron
30452, -- Tenebron
31125, -- Archavon the Stone Watcher
32845, -- Hodir
32857, -- Stormcaller Brundir
32865, -- Thorim
32867, -- Steelbreaker
32871, -- Algalon the Observer
32906, -- Freya
32927, -- Runemaster Molgeim
32930, -- Kologarn
33113, -- Flame Leviathan
33118, -- Ignis the Furnace Master
33186, -- Razorscale
33271, -- General Vezax
33288, -- Yogg-Saron
33293, -- XT-002 Deconstructor
33432, -- Leviathan Mk II
33515, -- Auriaya
33651, -- VX-001
33670, -- Aerial Command Unit
33993, -- Emalon the Storm Watcher
34441, -- Vivienne Blackwhisper
34444, -- Thrakgar
34445, -- Liandra Suncaller
34447, -- Caiphus the Stern
34448, -- Ruj'kah
34449, -- Ginselle Blightslinger
34450, -- Harkzog
34451, -- Birana Stormhoof
34453, -- Narrhok Steelbreaker
34454, -- Maz'dinah
34455, -- Broln Stouthorn
34456, -- Malithas Brightblade
34458, -- Gorgrim Shadowcleave
34459, -- Erin Misthoof
34460, -- Kavina Grovesong
34461, -- Tyrius Duskblade
34463, -- Shaabad
34465, -- Velanaa
34466, -- Anthar Forgemender
34467, -- Alyssia Moonstalker
34468, -- Noozle Whizzlestick
34469, -- Melador Valestrider
34470, -- Saamul
34471, -- Baelnor Lightbearer
34472, -- Irieth Shadowstep
34474, -- Serissa Grimdabbler
34475, -- Shocuul
34496, -- Eydis Darkbane
34497, -- Fjola Lightbane
34564, -- Anub'arak
34780, -- Lord Jaraxxus
34796, -- Gormok the Impaler
34797, -- Icehowl
34799, -- Dreadscale
35013, -- Koralon the Flame Watcher
35144, -- Acidmaw
36597, -- The Lich King
36612, -- Lord Marrowgar
36626, -- Festergut
36627, -- Rotface
36678, -- Professor Putricide
36855, -- Lady Deathwhisper
36899, -- Big Ooze
36939, -- High Overlord Saurfang
36948, -- Muradin Bronzebeard
37562, -- Gas Cloud
37813, -- Deathbringer Saurfang
37955, -- Blood-Queen Lana'thel
37970, -- Prince Valanar
37972, -- Prince Keleseth
37973, -- Prince Taldaram
38216, -- Mutated Professor Putricide
38433, -- Toravon the Ice Watcher
38883, -- Idle Before Scaling
39231, -- The Lich King (Temp)
39625, -- General Umbriss
39788, -- Anraphet
39863, -- Halion
40142, -- Halion
40177, -- Forgemaster Throngus
40484, -- Erudax
40960, -- Bug 193702
41270, -- Onyxia
41376, -- Nefarian
41378, -- Maloriak
41442, -- Atramedes
43404, -- Maloriak
44600, -- Halfus Wyrmbreaker
49938, -- Maloriak - Test
51437, -- Forgemaster Throngus
51452, -- Nefarian
52151, -- Bloodlord Mandokir
52409, -- Ragnaros
52558, -- Lord Rhyolith
52571, -- Majordomo Staghelm
53494, -- Baleroc
53772, -- Lord Rhyolith
53879, -- Deathwing
54192, -- Lord Rhyolith
54199, -- Lord Rhyolith
55265, -- Morchok
55308, -- Warlord Zon'ozz
55689, -- Hagara the Stormbinder
56471, -- Mutated Corruption
57773, -- Kohcrom
60009, -- Feng the Accursed
60016, -- Feng the Accursed
60018, -- Feng the Accursed
60019, -- Feng the Accursed
60020, -- Feng the Accursed
60709, -- Qiang the Merciless
62511, -- Amber-Shaper Un'sok
62711, -- Amber Monstrosity
63666, -- Amber-Shaper Un'sok
68078, -- Iron Qon
68177, -- Feed Tester
68208, -- Ji-Kun Dummy
68397, -- Lei Shen
69095, -- Test Subject
69473, -- Ra-den
69650, -- Phoenix Incubater Test
69653, -- Phoenix Incubate and Feed Test
69712, -- Ji-Kun
70437, -- Lei Shen
70640, -- Ji-Kun Area Trigger Dummy [DNT]
71466, -- Iron Juggernaut
71529, -- Thok the Bloodthirsty
71658, -- Kor'kron Jailer
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
29249,29268,29278,29324,29373,29417,29448,29615,29701,29718,29955,29991,30061,31311,31520,31534,31535,31722,31734,32846,33070,33147,33190,33360,33449,33692,33693,33694,33724,33885,33909,33955,33994,34003,34106,34108,34109,34175,34442,34443,34566,35216,35268,35269,35347,35348,35349,35350,35351,35352,35360,35438,35439,35440,35447,35448,35449,35511,35512,35513,35514,35515,35516,35615,35616,35662,35663,35664,35665,35666,35667,35668,35669,35670,35671,35672,35673,35680,35681,35682,35683,35684,35685,35686,35687,35688,35689,35690,35691,35692,35693,35694,35695,35696,35697,35699,35700,35701,35702,35703,35704,35705,35706,35707,35708,35709,35710,35711,35712,35713,35714,35715,35716,35718,35719,35720,35721,35722,35723,35724,35725,35726,35728,35729,35730,35731,35732,35733,35734,35735,35736,35737,35738,35739,35740,35741,35742,35743,35744,35745,35746,35747,35748,35749,36538,37504,37505,37506,37957,37958,37959,38106,38123,38156,38157,38296,38297,38390,38399,38400,38401,38402,38431,38434,38435,38436,38462,38549,38550,38582,38583,38585,38586,38602,38637,38638,38639,38640,38760,38761,38769,38770,38771,38772,38784,38785,39166,39167,39168,39232,39233,39234,39864,39944,39945,40143,40144,40145,48337,48702,48822,49583,49584,49585,49974,49980,49986,51104,51105,51106,53587,53588,53589,57462,57955,57956,57976,58137,58138,58862,58863,58864);
