--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00010000 WHERE `entry` IN
(68, -- Stormwind City Guard
1756, -- Stormwind Royal Guard
2614, -- Air Force Alarm Bot (Alliance)
2615, -- Air Force Alarm Bot (Horde)
3083, -- Honor Guard
3084, -- Bluffwatcher
3296, -- Orgrimmar Grunt
3502, -- Ratchet Bruiser
4262, -- Darnassus Sentinel
4624, -- Booty Bay Bruiser
4979, -- Theramore Guard
5326, -- Coast Crawl Clacker
5595, -- Ironforge Guard
5624, -- Undercity Guardian
6086, -- Auberdine Sentinel
7975, -- Mulgore Protector
7980, -- Deathguard Elite
9460, -- Gadgetzan Bruiser
10038, -- Night Watch Guard
11099, -- Argent Guard
11102, -- Argent Rider
11190, -- Everlook Bruiser
11194, -- Argent Defender
11822, -- Moonglade Warden
12786, -- Guard Quine
12787, -- Guard Hammon
12797, -- Grunt Korf
12798, -- Grunt Bek'rah
13839, -- Royal Dreadguard
14304, -- Kor'kron Elite
14363, -- Thief Catcher Shadowdelve
14365, -- Thief Catcher Farmountain
14367, -- Thief Catcher Thunderbrew
14375, -- Scout Stronghand
14376, -- Scout Manslayer
14377, -- Scout Tharr
14378, -- Huntress Skymane
14379, -- Huntress Ravenoak
14380, -- Huntress Leafrunner
14402, -- Seeker Cromwell
14403, -- Seeker Nahr
14404, -- Seeker Thompson
14423, -- Officer Jaxon
14438, -- Officer Pomeroy
14439, -- Officer Brady
14440, -- Hunter Sagewind
14441, -- Hunter Ragetotem
14442, -- Hunter Thunderhorn
14876, -- Zandalar Headshrinker
14911, -- Zandalar Enforcer
15184, -- Cenarion Hold Infantry
15187, -- Cenarion Emissary Jademoon
15188, -- Cenarion Emissary Blackhoof
15241, -- Gryphon Rider Guard
15242, -- Bat Rider Guard
15371, -- Sunstrider Guardian
15495, -- Nighthaven Defender
15724, -- Drunken Bruiser
15961, -- Lunar Festival Sentinel
16096, -- Steamwheedle Bruiser
16124, -- Unrelenting Trainee
16125, -- Unrelenting Death Knight
16126, -- Unrelenting Rider
16127, -- Spectral Trainee
16139, -- Cenarion Hold Reservist
16148, -- Spectral Death Knight
16150, -- Spectral Rider
16221, -- Silvermoon Guardian
16222, -- Silvermoon City Guardian
16228, -- Argent Dawn Infantry
16229, -- Injured Argent Dawn Infantry
16378, -- Argent Sentry
16432, -- Undercity Elite Guardian
16541, -- Ghostlands Guardian
16580, -- Thrallmar Grunt
16733, -- Exodar Peacekeeper
16842, -- Honor Hold Defender
16921, -- Ammen Vale Guardian
17282, -- Falcon Watch Ranger
17307, -- Vazruden the Herald
17537, -- Vazruden
17549, -- Blood Watch Peacekeeper
17765, -- Alliance Silithyst Sentinel
17766, -- Horde Silithyst Sentinel
17855, -- Expedition Warden
18038, -- Azuremyst Peacekeeper
18099, -- Gordawg
18100, -- Incineratus
18101, -- Aborius
18102, -- Kalandrios
18126, -- Expedition Scout
18139, -- Sporeggar Preserver
18194, -- Expedition Preserver
18488, -- Telaari Watcher
18489, -- Garadar Defender
18568, -- Scryer Arcane Guardian
18758, -- Telhamat Protector
18909, -- Zabra'jin Guard
18910, -- Swamprat Guard
18922, -- Telredor Guard
18943, -- Orebor Harborage Defender
18973, -- Stonebreaker Grunt
18989, -- Stonebreaker Guard
18999, -- Allerian Defender
19071, -- Telaari Elekk Rider
19353, -- Wildhammer Guard
19362, -- Kor'kron Defender
19449, -- Thunderlord Grunt
19500, -- Sylvanaar Sentinel
19504, -- Scryer Guardian
19529, -- Stormspire Nexus-Guard
19541, -- Netherstorm Agent
19687, -- Shattrath City Peacekeeper
19688, -- Scryer Vault Guardian
20447, -- Protectorate Vanguard
20484, -- Area 52 Big Bruiser
20485, -- Area 52 Bruiser
20556, -- Stormwind Marine
20672, -- Royal Guard
20674, -- Shield of Velen
21045, -- Hired Bodyguard
21081, -- Mok'Nathal Hunter
21115, -- Station Guard
21361, -- Designer Island Orc Trainee [PH]
21448, -- Gadgetzan Sniper
21857, -- Inner Demon
21858, -- Sha'tar Vindicator
21974, -- Air Force Alarm Bot (Area 52)
21976, -- Area 52 Death Machine
21977, -- Gadgetzan Air Strike Caller
21986, -- Altar of Sha'tar Vindicator
21993, -- Air Force Guard Post (Horde - Bat Rider)
21996, -- Air Force Guard Post (Alliance - Gryphon)
21997, -- Air Force Guard Post (Goblin - Area 52 - Zeppelin)
21999, -- Air Force Trip Wire - Rooftop (Alliance)
22001, -- Air Force Trip Wire - Rooftop (Horde)
22002, -- Air Force Trip Wire - Ground (Horde)
22003, -- Air Force Trip Wire - Ground (Alliance)
22063, -- Air Force Trip Wire - Rooftop (Goblin - Area 52)
22064, -- Stormspire Drake
22065, -- Air Force Guard Post (Ethereal - Stormspire)
22066, -- Air Force Guard Post (Scryer - Dragonhawk)
22067, -- Scryer Dragonhawk
22068, -- Air Force Trip Wire - Rooftop (Ethereal - Stormspire)
22069, -- Air Force Alarm Bot (Stormspire)
22070, -- Air Force Trip Wire - Rooftop (Scryer)
22071, -- Air Force Alarm Bot (Scryer)
22077, -- Aldor Gryphon Guard
22078, -- Air Force Alarm Bot (Aldor)
22079, -- Air Force Guard Post (Aldor - Gryphon)
22080, -- Air Force Trip Wire - Rooftop (Aldor)
22086, -- Air Force Alarm Bot (Sporeggar)
22087, -- Air Force Guard Post (Sporeggar - Sporebat)
22088, -- Air Force Trip Wire - Rooftop (Sporeggar)
22089, -- Toshley Flying Machine
22090, -- Air Force Guard Post (Toshley's Station - Flying Machine)
22122, -- Cenarion Storm Crow
22124, -- Air Force Alarm Bot (Cenarion)
22125, -- Air Force Guard Post (Cenarion - Stormcrow)
22126, -- Air Force Trip Wire - Rooftop (Cenarion Expedition)
22151, -- Ruuan Weald Sister
22206, -- Expedition Druid
22369, -- Dread Relic Thrall
22407, -- Caravan Defender
22410, -- Expedition Outrider
22453, -- Injured Sha'tar Vindicator
22456, -- Oakun
22462, -- Vindicator Haylen
22494, -- Cosmowrench Bruiser
22923, -- Simon Game Bunny
23095, -- Supremus Punch Invis Stalker
23115, -- Ogri'la Peacekeeper
23146, -- Dragonmaw Enforcer
23257, -- Skyguard Windcharger
23377, -- Skyguard Ace
23636, -- Mudsprocket Bruiser
23681, -- Captain Averen
23719, -- Investigator Asric
23721, -- Concert Bruiser
23739, -- Valgarde Defender
23779, -- Vengeance Landing Deathguard
23835, -- Sergeant Amelyn
23842, -- Westguard Defender
23900, -- Theramore Marksman
23949, -- Lieutenant Nath
23950, -- Lieutenant Khand
23951, -- Lieutenant Aden
24031, -- Camp Winterhoof Brave
24050, -- Wildervar Sentry
24136, -- Feather Vortex
24159, -- Amani Eagle
24225, -- Amani'shi Warrior
24841, -- Marine Halters
24842, -- Marine Anderson
24994, -- Shattered Sun Sentry
24996, -- Mariner Bladewhisper
24997, -- Mariner Swiftstar
24998, -- Mariner Farsight
25007, -- Mariner Evenmist
25013, -- Sentinel Brightgrass
25014, -- Sentinel Winterdew
25021, -- Mariner Moonblade
25022, -- Mariner Stillwake
25023, -- Mariner Everwatch
25024, -- Mariner Softsong
25053, -- Mariner Farseeker
25054, -- Mariner Keenstar
25055, -- Mariner Frostnight
25056, -- Mariner Stillglider
25079, -- Deathguard Fowles
25080, -- Grunt Umgor
25081, -- Grunt Ounda
25083, -- Deathguard Lawson
25106, -- Watcher Du'una
25107, -- Watcher Umjin
25145, -- Budd's Bodyguard
25175, -- Shattered Sun Dragonhawk
25236, -- Unrestrained Dragonhawk
25242, -- Warsong Battleguard
25253, -- Valiance Keep Footman
25359, -- Force-Commander Steeljaw
25373, -- Shadowsword Soulbinder
25483, -- Shadowsword Manafiend
25484, -- Shadowsword Assassin
25485, -- Shadowsword Deathbringer
25486, -- Shadowsword Vanquisher
25506, -- Shadowsword Lifeshaper
25808, -- D.E.H.T.A. Enforcer
25819, -- D.E.H.T.A. Enforcer
25837, -- Shadowsword Commander
25992, -- Big Bruiser
26157, -- Taunka'le Brave
26217, -- Westfall Brigade Footman
26231, -- Saragosa
26253, -- Shattered Sun Peacekeeper
26310, -- Malygos
26379, -- Overlord Agmar
26448, -- Stars' Rest Sentinel
27035, -- Venomspite Deathguard
27073, -- Bor'gorok Battleguard
27126, -- Camp Oneqwah Brave
27167, -- Kamagua Spearman
27170, -- Amber Ledge Warmage
27173, -- Warmage Calandra
27175, -- Transitus Shield Warmage
27178, -- Moa'ki Warrior
27189, -- Unu'pe Spearman
27904, -- Warmage Watkins
27906, -- Warmage Hollister
27952, -- Wyrmrest Protector Visual (Red)
27953, -- Wyrmrest Protector
27954, -- Wyrmrest Protector Visual (Green)
27955, -- Wyrmrest Protector Visual (Bronze)
28250, -- Wyrmrest Protector Visual (Black)
28251, -- Wyrmrest Protector Visual (Blue)
28252, -- Wyrmrest Protector Visual (Nether)
28801, -- Argent Stand Defender
28818, -- Light's Breach Defender
28863, -- Zim'Torga Guardian
28865, -- Ebon Watch Guardian
29202, -- Knight of the Ebon Blade
29292, -- Art Peshkov
29293, -- Daniel Kramer
29294, -- Candace Thomas
29295, -- Meghan Dawson
29617, -- Valiance Keep Defender
29712, -- Stormwind Harbor Guard
29729, -- Frostborn Axemaster
29910, -- K3 Bruiser
29942, -- Warsong Hold Grunt
29960, -- Earthen Stoneguard
29973, -- Tunka'lo Brave
30058, -- Warden of the Chamber
30059, -- Wyrmrest Warden Visual (Bronze)
30072, -- Wyrmrest Warden Visual (Red)
30073, -- Wyrmrest Warden Visual (Green)
30076, -- Wyrmrest Warden Visual (Blue)
30077, -- Wyrmrest Warden Visual (Black)
30189, -- Crusader of Virtue
30208, -- Stormforged Ambusher
30222, -- Stormforged Infiltrator
30312, -- Shadow Vault Boneguard
30344, -- High Captain Justin Bartlett
30352, -- Skybreaker Marine
30431, -- Veteran Crusader Aliocha Segard
30433, -- Aedan Moran
30611, -- Greela "The Grunt" Crankchain
30621, -- Twisted Visage
30622, -- Twisted Visage
30623, -- Twisted Visage
30624, -- Twisted Visage
30625, -- Twisted Visage
30672, -- Crusader of Virtue
30737, -- Nesingwary Game Warden
30755, -- Kor'kron Reaver
30824, -- Sky-Reaver Korm Blackscar
30833, -- Vindicator Maraad
31033, -- Crusader of Virtue
31563, -- Warsong Battleguard
31708, -- Deathguard Barth
31715, -- Deathguard Hicks
31726, -- Grunt Gritch
31727, -- Grunt Grikee
32369, -- Warmage Sarina
32371, -- Warmage Halister
32372, -- Warmage Ilsudria
32373, -- Gatekeeper Melindra
32374, -- Librarian Belleford
32375, -- Warmage Yurias
32476, -- Copperpot Goon
32523, -- Johnny Yes
32524, -- Willy Maybe
32573, -- Valgarde Captive
32722, -- Warmage Lukems
32724, -- Warmage Mumplina
32875, -- Iron Honor Guard
32957, -- Dark Rune Acolyte
33069, -- Darkmoon Bruiser
33110, -- Dark Rune Acolyte
33113, -- Flame Leviathan
33125, -- Iron Honor Guard
33429, -- Boneguard Lieutenant
33543, -- Sunreaver Guardian
33559, -- Darnassus Valiant
33643, -- Silver Covenant Guardian
33698, -- Argent Peacekeeper
33738, -- Darnassus Champion
33780, -- Argent Watchman
34127, -- Boneguard Commander
34179, -- Argent Peacekeeper
34505, -- Copperpot Goon
34800, -- Snobold Vassal
34915, -- Stormforged Marauder
35314, -- Orgrimmar Champion
35322, -- Stormwind Royal Guard
35323, -- Sen'jin Champion
35325, -- Thunder Bluff Champion
35326, -- Silvermoon Champion
35327, -- Undercity Champion
35328, -- Stormwind Champion
35329, -- Ironforge Champion
35330, -- Exodar Champion
35331, -- Gnomeregan Champion
35332, -- Darnassus Champion
35460, -- Kor'kron Elite
35587, -- Argent Peacekeeper
36164, -- Kor'kron Reaver
36166, -- 7th Legion Marine
36213, -- Kor'kron Overseer
36217, -- Overseer Kraggosh
36224, -- Dark Ranger Clea
36225, -- Dark Ranger Anya
36226, -- Dark Ranger Cyndia
36273, -- Bragor Bloodfist
36431, -- Dark Iron Guard
36481, -- Sentinel Stillbough
36517, -- Aleric Hawkins
36619, -- Bone Spike
36656, -- Silver Covenant Sentinel
36657, -- Sunreaver War Mage
36913, -- Eye of the Lich King
37063, -- Stormwind City Guard
37068, -- Spiritual Reflection
37107, -- Spiritual Reflection
37182, -- High Captain Justin Bartlett
37509, -- Shattered Sun Sentry
37693, -- Commander Aliocha Segard [Icecrown Raid]
37699, -- RN Test Honor Guard
37700, -- RN Test Royal Guard
37775, -- Ironforge Guard
37781, -- Sunwell Honor Guard
37790, -- Darnassus Sentinel
37798, -- Exodar Peacekeeper
37800, -- Silvermoon City Guardian
37825, -- Kor'kron Overseer
37831, -- [PH] Captain
37833, -- Sky-Reaver Korm Blackscar
37860, -- Bluffwatcher
37869, -- Orgrimmar Grunt
38164, -- [PH] Captain (Orgrimmar)
38248, -- Impaling Spear
38332, -- Ball of Flame
38451, -- Ball of Inferno Flame
38711, -- Bone Spike
38712, -- Bone Spike
38825, -- Aerin
38830, -- [PH] Grimtotem Protector
38831, -- Slain Bluffwatcher
38839, -- Dark Iron Guard
38843, -- [PH] Grimtotem Collector
38846, -- [PH] Slain Druid
38870, -- [DND] Dark Iron Guard Move To Bunny
38877, -- Dark Iron Citizen
39158, -- Phalanx 2.0
39934, -- Zeppelin Sentry
40138, -- Stormwind City Guard (Corpse)
-- Difficulties
18434,18435,29985,29986,29987,29988,29990,30264,30798,31476,31477,31478,31479,31480,33160,33161,33163,33164,34003,35441,37611,38233,38970,38973,35442,38459,38971,38974,35443,38460,38972,38975);
