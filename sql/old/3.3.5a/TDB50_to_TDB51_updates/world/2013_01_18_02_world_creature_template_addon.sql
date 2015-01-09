-- delete 632 creature_template_addon data that contain no information (bytes2=1 is the default)
DELETE FROM `creature_template_addon` WHERE `entry` IN (
890, -- Fawn
6827, -- Crab
8996, -- Voidwalker Minion
9396, -- Ground Pounder
10928, -- Succubus Minion
15475, -- Beetle
15547, -- Spectral Charger
15548, -- Spectral Stallion
15974, -- Dread Creeper
15975, -- Carrion Spinner
15979, -- Tomb Horror
16017, -- Patchwork Golem
16020, -- Mad Scientist
16021, -- Living Monstrosity
16022, -- Surgical Assistant
16025, -- Stitched Giant
16030, -- Maggot
16036, -- Frenzied Bat
16037, -- Plagued Bat
16056, -- Diseased Maggot
16057, -- Rotting Maggot
16067, -- Deathcharger Steed
16068, -- Larva
16137, -- Naxxramas Military Sub-Boss Trigger
16145, -- Death Knight Captain
16154, -- Risen Squire
16156, -- Dark Touched Warrior
16165, -- Necro Knight
16171, -- Coldmist Widow
16173, -- Shadowbat
16174, -- Greater Shadowbat
16175, -- Vampiric Shadowbat
16176, -- Shadowbeast
16177, -- Dreadbeast
16178, -- Phase Hound
16194, -- Unholy Axe
16211, -- Naxxramas Combat Dummy
16215, -- Unholy Staff
16216, -- Unholy Swords
16244, -- Infectious Ghoul
16297, -- Mutated Grub
16375, -- Sewage Slime
16412, -- Ghostly Baker
16459, -- Wanton Hostess
16460, -- Night Mistress
16481, -- Ghastly Haunt
16482, -- Trapped Soul
16485, -- Arcane Watchman
16488, -- Arcane Anomaly
16489, -- Chaotic Sentience
16491, -- Mana Feeder
16492, -- Syphoner
16506, -- Naxxramas Worshipper
16525, -- Spell Shade
16529, -- Magical Horror
16530, -- Mana Warp
16539, -- Homunculus
16545, -- Ethereal Spellfilcher
16595, -- Fleshbeast
17260, -- Nightbane Helper Target
17316, -- Chess Square, OUTSIDE BLACK (DND)
17467, -- Skunk
17644, -- Infernal Target
17645, -- Infernal Relay
17660, -- Skeletal Gryphon
18955, -- Camera Shaker - 30-90 seconds
20061, -- Frostbite Invisible Stalker
21080, -- Dormant Infernal
21728, -- Skettis Surger
21804, -- Skettis Kaliri
21921, -- Chess - Sound Bunny
22519, -- Chess Piece: Karazhan Invisible Stalker
22520, -- Chess Piece: Status Bar
22523, -- Karazhan - Chess, Victory Dummy Tool
22986, -- Skettis - Invis Raven Stone
22991, -- Monstrous Kaliri Egg Trigger
23225, -- Netherwing Drake Escape Point
23638, -- Longtusk Fisherman
23643, -- Unstable Mur'ghoul
23644, -- Mur'ghoul Flesheater
23645, -- Mur'ghoul Corrupter
23667, -- Winterskorn Rune-Seer
23668, -- Winterskorn Rune-Caster
23669, -- Winterskorn Oracle
23670, -- Winterskorn Elder
23674, -- Iron Rune Sage
23677, -- Frost Nymph
23678, -- Chill Nymph
23755, -- Blockade Pirate
23771, -- Blockade Cannon
23809, -- Vengeance Landing Cannoneer
23810, -- Blockade Explosion Bunny
23821, -- Valgarde Harpoon Target
23867, -- Vengeance Landing Combatant Trigger
23870, -- Ember Clutch Ancient
23874, -- Thornvine Creeper
23876, -- Spore
23884, -- Vengeance Landing Crossbow Trigger
23885, -- Lyana Trigger
23886, -- Bull Lion Seal
23887, -- Lion Seal
23915, -- Westguard Cannon Trigger
23916, -- Westguard Cannon Trigger (Water)
23917, -- Cannon Source Trigger
23919, -- Ice Elemental
23929, -- Giant Tidecrawler
23930, -- Trained Plaguehound
23934, -- North Fleet Salvager
24076, -- Winterskorn Worg
24082, -- Proto-Drake Handler
24084, -- Tunneling Ghoul
24104, -- New Agamand Deathguard
24110, -- ELM General Purpose Bunny Large
24174, -- Fjord Rat
24177, -- Decomposing Ghoul
24182, -- Winterskorn Dwelling Credit
24184, -- Winterskorn Barracks Credit
24340, -- Rampaging Earth Elemental
24439, -- Sack of Relics
24440, -- Gjalerbron Gargoyle
24469, -- Magnataur Huntress
24562, -- Nerub'ar Invader
24567, -- Den Vermin
24613, -- Mammoth Calf
24614, -- Wooly Mammoth
24633, -- Rabid Brown Bear
24635, -- Dragonflayer Harpooner
24637, -- Great Reef Shark
24642, -- Drunken Northsea Pirate
24653, -- Flying Machine
24673, -- Frostwing Chimaera
24676, -- Crazed Northsea Slaver
24677, -- Spearfang Worg
24681, -- Island Shoveltusk
24694, -- Vrykul Harpoon Gun (Wyrmskull)
24846, -- Iron Dwarf
24862, -- Mage Hunter Target
24863, -- Frosthorn Kid
24871, -- Risen Vrykul Ancestor
24872, -- Blood Shade
24883, -- Rodin Lightning Enabler
24901, -- Maddened Frosthorn
25198, -- Winterfin Gatherer
25201, -- Winterfin Tadpole
25204, -- Glimmer Bay Orca
25215, -- Winterfin Shorestriker
25216, -- Winterfin Oracle
25217, -- Winterfin Warrior
25225, -- Practice Dummy
25350, -- Risen Longrunner
25351, -- Ghostly Sage
25355, -- Beryl Hound
25362, -- Warsong Swine
25377, -- Brittle Skeleton
25378, -- En'kilah Necromancer
25383, -- En'kilah Abomination
25390, -- En'kilah Hatchling
25391, -- En'kilah Focus Crystal
25393, -- En'kilah Ghoul
25396, -- Naxxanar Skeletal Mage
25415, -- Enraged Tempest
25417, -- Raging Boiler
25419, -- Boiling Spirit
25422, -- Mystical Webbing
25428, -- Magmoth Shaman
25429, -- Magmoth Forager
25431, -- Kaskala Ancestor
25432, -- Mate of Magmothregar
25433, -- Offspring of Magmothregar
25452, -- Scourged Mammoth
25454, -- Tundra Crawler
25464, -- Bloodspore Moth
25468, -- Bloodspore Roaster
25501, -- Gammoth Tender
25534, -- En'kilah Blood Globe
25600, -- Unliving Swine
25610, -- Scourge Prisoner
25615, -- Plagued Magnataur
25623, -- Harvest Collector
25651, -- Cultist Necrolyte
25660, -- Festering Ghoul
25668, -- Vengeful Taunka Spirit
25670, -- ELM General Purpose Bunny (scale x3)
25675, -- Tundra Wolf
25677, -- Borean Frog
25684, -- Talramas Abomination
25685, -- Gorloc Waddler
25686, -- Gorloc Gibberer
25687, -- Gorloc Steam Belcher
25699, -- Gorloc Mud Splasher
25700, -- Gorloc Hunter
25701, -- Gorloc Dredger
25707, -- Magic-bound Ancient
25709, -- Glacial Ancient
25713, -- Blue Drakonid Supplicant
25715, -- Frozen Elemental
25717, -- Coldarra Scalesworn
25718, -- Coldarra Mage Slayer
25719, -- Coldarra Spellbinder
25721, -- Arcane Serpent
25722, -- Coldarra Spellweaver
25724, -- Ascended Mage Hunter
25728, -- Coldarra Wyrmkin
25781, -- Oil Pool
25829, -- Marsh Fawn
25843, -- Northsea Thug
25880, -- Minion of Kaw
25981, -- Scourged Footman
26047, -- Warsong Worg
26126, -- Bone Warrior
26161, -- Farshire Grain Credit
26175, -- Coldarra - Drake Hunt Invisman
26189, -- Fleeing Cultist
26199, -- Snowfall Glade Den Mother
26200, -- Snowfall Glade Pup
26201, -- Snowfall Glade Shaman
26202, -- Ziggurat Defender
26402, -- Anub'ar Ambusher
26411, -- Deranged Indu'le Villager
26413, -- Anub'ar Dreadweaver
26418, -- Longhoof Grazer
26435, -- Taunka Move Trigger
26446, -- Ice Serpent
26455, -- Moonrest Highborne
26458, -- Drakkari Plaguebringer
26461, -- Scourge Corpserender
26472, -- Highland Mustang
26480, -- Magnataur Youngling
26481, -- Magnataur Alpha
26482, -- Arctic Grizzly
26488, -- Taunka Pack Kodo
26492, -- Wastes Digger
26525, -- Cockroach
26555, -- Scourge Hulk
26606, -- Anub'ar Slayer
26624, -- Wretched Belcher
26625, -- Darkweb Recluse
26628, -- Drakkari Scytheclaw
26636, -- Risen Drakkari Soulmage
26644, -- Ursus Mauler
26646, -- Saronite Horror
26658, -- Reckless Scavenger
26662, -- Azjol-anak Battleguard
26669, -- Ymirjar Savage
26670, -- Ymirjar Flesh Hunter
26675, -- Spider Summon Target
26705, -- Snowplain Disciple
26706, -- Infected Grizzly Bear
26711, -- Injured Mammoth
26712, -- Crystal Channel Target
26728, -- Mage Hunter Initiate
26729, -- Steward
26782, -- Crystalline Keeper
26792, -- Crystalline Protector
26793, -- Crystalline Frayer
26889, -- The End of the Line Area Trigger Kill Credit Bunny
26891, -- Undead Miner
26937, -- Gong Bunny
26948, -- Hulking Atrocity
27165, -- Drained Moonrest Highborne
27230, -- Silvercoat Stag
27247, -- Devout Bodyguard
27254, -- Emerald Lasher
27283, -- Risen Wintergarde Mage
27286, -- Dreadbone Invader
27290, -- Hungering Dead
27358, -- Burning Depths Necromancer
27363, -- Smoldering Geist
27375, -- Risen Gryphon Rider Target
27402, -- Bone Target Bunny
27403, -- Strange Ore Target
27408, -- Duskhowl Prowler
27418, -- Rothin's Spell Bunny
27421, -- Fern Feeder Moth
27438, -- Rainbow Trout
27449, -- Neltharion's Flame Fire Bunny
27452, -- Invisible Stalker Grizzly Hills
27460, -- Mother of Bambina
27496, -- Refurbished Shredder
27513, -- Covetous Geist
27551, -- Enraged Apparition
27552, -- Reanimated Noble
27607, -- Plague Wagon
27633, -- Azure Inquisitor
27635, -- Azure Spellbinder
27636, -- Azure Ley-Whelp
27639, -- Ring-Lord Sorceress
27640, -- Ring-Lord Conjurer
27641, -- Centrifuge Construct
27685, -- Frigid Ghoul Attacker
27686, -- Frigid Geist Attacker
27688, -- Alliance Lumberboat
27689, -- Alliance Lumberboat Explosions
27702, -- Horde Lumberboat
27725, -- Ruby Guardian
27737, -- Risen Zombie
27745, -- Lordaeron Footman
27746, -- Lordaeron Knight
27747, -- High Elf Mage-Priest
27752, -- High Elf Sorceress
27823, -- Naxxramas Dreadguard
27824, -- Naxxramas Shade
27827, -- Grain Crate Helper
27836, -- Wailing Soul
27852, -- Wintergrasp Control Arms
27869, -- Wintergrasp Detection Unit
27909, -- Darkweb Victim
27927, -- Dragonflayer Guardian
27965, -- Dark Rune Shaper
27970, -- Raging Construct
27971, -- Unrelenting Construct
28001, -- Dreadsaber
28002, -- Mangal Crocolisk
28003, -- Bittertide Hydra
28005, -- Wastes Scavenger
28008, -- Galakrond Spell Dummy
28010, -- Stranded Thresher
28011, -- Emperor Cobra
28016, -- Drakuru
28024, -- Rainspeaker Warrior
28025, -- Rainspeaker Oracle
28130, -- Invis Lightning Stalker
28161, -- Chicken Escapee
28169, -- Stratholme Resident
28170, -- Frosthowl Screecher
28202, -- Zul'Drak Rat
28217, -- Injured Rainspeaker Oracle
28218, -- Snowblind Ghoul
28220, -- Frostbitten Corpse
28221, -- Trapdoor Crawler
28231, -- Crystalline Tender
28233, -- Zul'Drak Bat
28234, -- Tribunal of the Ages
28242, -- Risen Reaver
28246, -- Sky Terror
28254, -- Mistwhisper Lightning Target
28268, -- Scourged Argent Footman
28274, -- Plague Sprayer
28277, -- Harry's Bomber
28351, -- Flame Breath Trigger (Skadi)
28367, -- Acherus Dummy
28407, -- Fjord Penguin
28417, -- Priest of Rhunok
28419, -- Frenzied Geist
28440, -- Tundra Penguin
28452, -- Elemental Rift
28466, -- Fruit Tosser
28492, -- Drak'Tharon - Drakuru Event Invisman 00
28498, -- The Lich King
28504, -- Jin'Alai Medicine Man
28519, -- Withered Troll
28523, -- Nass Target KC Bunny
28559, -- Citizen of New Avalon
28560, -- Citizen of New Avalon
28584, -- Unbound Firestorm
28585, -- Slag
28605, -- Havenshire Stallion
28627, -- Wood Pile Dummy
28643, -- Rain of Darkness Dummy
28655, -- Sky Darkener Target
28660, -- Citizen of Havenshire
28662, -- Citizen of Havenshire
28717, -- Overlord Drakuru
28733, -- Anub'ar Shadowcaster
28739, -- Blight Cauldron Bunny 00
28745, -- Alarmed Blightguard
28750, -- Blight Geist
28751, -- Geist WP Bunny
28769, -- Shadowy Tormentor
28778, -- Scourgewagon Bunny
28789, -- Explosion Guy
28804, -- Plague Spreader
28826, -- Stormfury Revenant
28833, -- Scarlet Cannon
28835, -- Stormforged Construct
28839, -- Scarlet Cover Dummy
28850, -- Scarlet Land Cannon
28901, -- Acherus Deathcharger
28903, -- Scourge Plaguehound
28905, -- Gluttonous Geist
28906, -- Scourge Gryphon
28920, -- Stormforged Giant
28931, -- Blightblood Troll
28932, -- Blight Effect Bunny
28935, -- Acherus Dummy
28960, -- Totally Generic Bunny (JSB)
29013, -- Perch Guardian
29026, -- Kolramas Slime
29027, -- Wild Growth Stalker
29036, -- Servant of Freya
29048, -- Ulduar Monitor
29104, -- Scarlet Ballista
29128, -- Anub'ar Prime Guard
29189, -- Howling Geist
29301, -- Camp Winterhoof Wayfarer
29326, -- Ichoron Summon Target
29328, -- Arctic Hare
29392, -- Ravenous Jaws
29395, -- Erekem Guard
29444, -- Drakkari Snake
29449, -- Vargul Deathwaker
29450, -- Vargul Runelord
29452, -- Vargul Blighthound
29461, -- Icetip Crawler
29466, -- Goblin Prisoner
29479, -- Shoveltusk Forager
29483, -- K3 Perimeter Turret
29485, -- Dolomite Giant
29486, -- Tamed Shoveltusk
29487, -- Wild Shoveltusk
29504, -- Seething Revenant
29517, -- Darkmender's Ghoul
29521, -- Unworthy Initiate Anchor
29549, -- Brunnhildar Riding Bear
29551, -- Brunnhildar Bearhandler
29558, -- Frost Giant Target Bunny
29559, -- Lion Seal Whelp
29562, -- Icemaw Bear
29614, -- Onslaught Darkweaver
29630, -- Fanged Pit Viper
29682, -- Slad'ran Summon Target
29697, -- Drakuru Prophet
29700, -- Drakuru Shackles
29710, -- Onslaught Destrier
29730, -- Frostborn Stormrider
29746, -- Databank
29752, -- Databank Core
29774, -- Spitting Cobra
29798, -- Hyldsmeet Proto-Drake
29805, -- Captive Proto Drake Beam Bunny
29811, -- Frostborn Scout
29820, -- Drakkari God Hunter
29822, -- Drakkari Fire Weaver
29826, -- Drakkari Medicine Man
29830, -- Living Mojo
29832, -- Drakkari Golem
29912, -- Obedience Crystal
29920, -- Ruins Dweller
29958, -- Tundra Ram
29960, -- Earthen Stoneguard
30012, -- Victorious Challenger
30046, -- Yulda the Stormspeaker
30066, -- Valkyrion Harpoon Gun
30071, -- Stitched Colossus
30078, -- [DND]Wyrmrest Temple Beam Target
30172, -- Ahn'kahar Swarm Egg
30173, -- Ahn'kahar Guardian Egg
30181, -- Jedoga Controller
30236, -- Argent Cannon
30250, -- Valhalas Vargul
30277, -- Ahn'kahar Slasher
30278, -- Ahn'kahar Spell Flinger
30286, -- Frostbringer
30298, -- Invisible Stalker (Float, Uninteractible, LargeAOI)
30312, -- Shadow Vault Boneguard
30335, -- Shadow Vault Gryphon
30416, -- Bound Fire Elemental
30418, -- Bound Air Elemental
30419, -- Bound Water Elemental
30430, -- Sentry Worg
30576, -- Vile Like Fire! Kill Credit Bunny
30599, -- Vile Like Fire! Fire Bunny
30633, -- Water Terror
30640, -- [DND] Icecrown Airship (A) - Cannon Target
30642, -- Water Terror
30649, -- [DND] Icecrown Airship (H) - Cannon Target
30651, -- [DND] Icecrown Airship (A) - Cannon, Odd
30675, -- Argent Champion
30687, -- Skeletal Constructor
30689, -- Chained Abomination
30701, -- Vile Creeper
30842, -- Wandering Shadow
30845, -- Living Lasher
30848, -- Whispering Wind
30857, -- Defense Dummy Target
30887, -- Scourge Package
30894, -- Lithe Stalker
30897, -- Marnak
30898, -- Kaddrak
30899, -- Abedneum
30900, -- Argent Mason
30920, -- Lumbering Atrocity
30947, -- Eidolon Watcher
30951, -- Restless Lookout
30952, -- Hungering Plaguehound
30960, -- Risen Soldier
30985, -- Summoned Soldier
31041, -- Dispirited Ent
31043, -- Reanimated Crusader
31049, -- Geist Return Bunny
31075, -- Scourge Bomb
31077, -- Safirdrang's Chill Target
31126, -- Agitated Stratholme Citizen
31127, -- Agitated Stratholme Resident
31131, -- Containment Crystal
31140, -- Hulking Abomination
31142, -- Icy Ghoul
31145, -- Shadow Adept
31147, -- Vicious Geist
31150, -- Plagued Fiend
31155, -- Malefic Necromancer
31205, -- Risen Alliance Soldier
31233, -- Sinewy Wolf
31245, -- Invisible Ooze Stalker
31250, -- Ebon Blade Defender
31251, -- Shadow Vault Skirmisher
31262, -- Blight Falconer
31266, -- Shadow Vault Assaulter
31280, -- Ymirheim Spear Gun
31328, -- Fleeing Horde Soldier
31330, -- Fleeing Horde Soldier
31353, -- [DND] Icecrown Airship (N) - Attack Controller
31411, -- Hulking Horror
31438, -- Shadow Vault Abomination
31554, -- Restless Lookout
31556, -- Hungering Plaguehound
31644, -- Cosmetic Trigger - Phase 1 - LAB
31685, -- Borean Marmot
31718, -- Frostbrood Whelp
31731, -- Wyrm Reanimator
31738, -- Cultist Corrupter
31747, -- Necrotic Webspinner
31754, -- Glacial Bonelord
31779, -- Skeletal Archmage
31780, -- Fallen Spiderlord
31783, -- Vrykul Necrolord
31786, -- Oil Slick
31797, -- Ancient Sentinel
31812, -- Decomposed Ghoul
31813, -- Frostskull Magus
31836, -- Blue Dragon Egg
31847, -- Scavenging Geist
31900, -- Scourge Banner-Bearer
31915, -- Horde Transport Dropoff Bunny
32149, -- Fallen Hero's Spirit
32155, -- Destroyed War Machine
32161, -- Scourge War Engineer
32202, -- Desolation KC Bunny
32236, -- Dark Subjugator
32250, -- Overseer Faedris
32255, -- Converted Hero
32257, -- Scourge Converter
32258, -- Gold Beetle
32260, -- Enslaved Minion
32262, -- Shadow Channeler
32264, -- Aldur'thar Channel Bunny
32278, -- Harbinger of Horror
32280, -- Corp'rethar Guardian
32284, -- Scourge Soulbinder
32349, -- Cultist Shard Watcher
32469, -- Ebon Blade Geist
32479, -- Bone Guard
32482, -- Pustulent Colossus
32490, -- Scourge Deathcharger
32498, -- Glacier Penguin
32502, -- Ravaged Ghoul
32505, -- Vargul Wanderer
32507, -- Cultist Acolyte
32520, -- Totally Generic Bunny (All Phase)
32541, -- Initiate's Training Dummy
32542, -- Disciple's Training Dummy
32543, -- Veteran's Training Dummy
32545, -- Initiate's Training Dummy
32546, -- Ebon Knight's Training Dummy
32593, -- Skittering Swarmer
32647, -- Warsong Hold Practice Dummy
32720, -- Violetta
32770, -- Enraged Fleshrender
32771, -- Stitched Brute
32772, -- Skeletal Footsoldier
32874, -- Iron Ring Guard
32875, -- Iron Honor Guard
32879, -- Thorim Controller
32885, -- Captured Mercenary Soldier
32892, -- Thorim Event Bunny
32922, -- Dark Rune Champion
32923, -- Dark Rune Commoner
32924, -- Dark Rune Evoker
32925, -- Dark Rune Warbringer
33140, -- Thorim Golem Right Hand Bunny
33141, -- Thorim Golem Left Hand Bunny
33229, -- Melee Target
33337, -- XT-Toy Pile
33378, -- Thunder Orb
33430, -- Guardian Lasher
33431, -- Forest Swarmer
33500, -- Vezax Bunny
33525, -- Mangrove Ent
33526, -- Ironroot Lasher
33527, -- Nature's Blade
33575, -- Channel Stalker Freya
33661, -- Armsweep Stalker Kologarn
33699, -- Storm Tempered Keeper
33722, -- Storm Tempered Keeper
33772, -- Faceless Horror
33809, -- Rubble Stalker Kologarn
33818, -- Twilight Adherent
33819, -- Twilight Frost Mage
33820, -- Twilight Pyromancer
33822, -- Twilight Guardian
33824, -- Twilight Shadowblade
33838, -- Enslaved Fire Elemental
33856, -- Bot Summon Trigger
34014, -- Sanctum Sentry
34069, -- Molten Colossus
34133, -- Champion of Hodir
34134, -- Winter Revenant
34135, -- Winter Rumbler
34137, -- Winter Jormungar
34144, -- Expedition Mercenary
34145, -- Expedition Engineer
34146, -- Snow Mound (4)
34150, -- Snow Mound (6)
34151, -- Snow Mound (8)
34184, -- Clockwork Mechanic
34190, -- Hardened Iron Golem
34191, -- Trash
34196, -- Rune Etched Sentry
34198, -- Iron Mender
34267, -- Parts Recovery Technician
34271, -- XD-175 Compactobot
34273, -- XB-488 Disposalbot
34300, -- Mature Lasher
34319, -- [DND] Champion Go-To Bunny
34716, -- Captive Aspirant
34907, -- Kvaldir Harpooner
35106, -- Black Knight Caster
35473, -- Argent Tournament Post
35482, -- Hungry Jormungar
36829, -- Deathspeaker High Priest
40091, -- Orb Rotation Focus
40146); -- Halion Controller
