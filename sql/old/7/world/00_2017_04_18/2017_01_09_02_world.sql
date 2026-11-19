--
DELETE FROM `npc_trainer` WHERE `ID` IN (201012,201015,201016) OR `SpellID` IN (-201012,-201015,-201016);
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES

-- Engineering trainers
(1676,   -201012, 0, 0, 0, 0), -- Finbus Geargrind 
(1702,   -201012, 0, 0, 0, 0), -- Bronk Guzzlegear  
(3290,   -201012, 0, 0, 0, 0), -- Deek Fizzlebizz 
(3494,   -201012, 0, 0, 0, 0), -- Tinkerwiz  
(4941,   -201012, 0, 0, 0, 0), -- Caz Twosprocket 
(5174,   -201012, 0, 0, 0, 0), -- Springspindle Fizzlegear 
(5518,   -201012, 0, 0, 0, 0), -- Lilliam Sparkspindle  
(8736,   -201012, 0, 0, 0, 0), -- Buzzek Bracketswing   
(8738,   -201012, 0, 0, 0, 0), -- Vazario Linkgrease   
(10993,  -201012, 0, 0, 0, 0), -- Twizwick Sprocketgrind 
(11017,  -201012, 0, 0, 0, 0), -- Roxxik   
(11025,  -201012, 0, 0, 0, 0), -- Mukdrak
(11031,  -201012, 0, 0, 0, 0), -- Franklin Lloyd 
(11037,  -201012, 0, 0, 0, 0), -- Jenna Lemkenilli 
(16667,  -201012, 0, 0, 0, 0), -- Danwe
(16726,  -201012, 0, 0, 0, 0), -- Ockil
(17222,  -201012, 0, 0, 0, 0), -- Artificer Daelo 
(17634,  -201012, 0, 0, 0, 0), -- K. Lee Smallfry
(17637,  -201012, 0, 0, 0, 0), -- Mack Diver
(18752,  -201012, 0, 0, 0, 0), -- Zebig
(18775,  -201012, 0, 0, 0, 0), -- Lebowski
(19576,  -201012, 0, 0, 0, 0), -- Xyrol
(24868,  -201012, 0, 0, 0, 0), -- Niobe Whizzlespark 
(25099,  -201012, 0, 0, 0, 0), -- Jonathan Garrett 
(25277,  -201012, 0, 0, 0, 0), -- Chief Engineer Leveny 
(26907,  -201012, 0, 0, 0, 0), -- Tisha Longbridge  
(26955,  -201012, 0, 0, 0, 0), -- Jamesina Watterly 
(26991,  -201012, 0, 0, 0, 0), -- Sock Brightbolt 
(28697,  -201012, 0, 0, 0, 0), -- Timofey Oshenko
(33586,  -201012, 0, 0, 0, 0), -- Binkie Brightgear 
(33611,  -201012, 0, 0, 0, 0), -- Engineering
(33634,  -201012, 0, 0, 0, 0), -- Engineer Sinbei 
(33677,  -201012, 0, 0, 0, 0), -- Technician Mihila 
(45545,  -201012, 0, 0, 0, 0), -- jack-pisarek-slamfix
(52636,  -201012, 0, 0, 0, 0), -- Tana Lentner 
(52651,  -201012, 0, 0, 0, 0), -- Engineer Palehoof 
(55143,  -201012, 0, 0, 0, 0), -- Sally Fizzlefury 
(72407,  -201012, 0, 0, 0, 0), -- Roxxik
(85918,  -201012, 0, 0, 0, 0), -- Hilda Copperfuze 
(86012,  -201012, 0, 0, 0, 0), -- Han Leaprocket 
(92194,  -201012, 0, 0, 0, 0), -- Timofey Oshenko
(95634,  -201012, 0, 0, 0, 0), -- Tinkerwiz
(95907,  -201012, 0, 0, 0, 0), -- Fixxia Geartweak 
(98872,  -201012, 0, 0, 0, 0), -- Buzzek Bracketswing 
(99098,  -201012, 0, 0, 0, 0), -- Timofey Oshenko 
(107898, -201012, 0, 0, 0, 0), -- Finbus Geargrind 

-- Goblin Engineering trainers
(8126,   -201015, 0, 0, 0, 0), -- Nixx Sprocketspring 
(8738,   -201015, 0, 0, 0, 0), -- Vazario Linkgrease 
(29513 , -201015, 0, 0, 0, 0), -- Didi the Wrench 
(95634,  -201015, 0, 0, 0, 0), -- Nixx Sprocketspring
(102961, -201015, 0, 0, 0, 0), -- Didi the Wrench 

-- Gnomish Engineering Trainers
(7406,   -201016, 0, 0, 0, 0), -- Oglethorpe Obnoticus
(7944,   -201016, 0, 0, 0, 0), -- Tinkmaster Overspark 
(29514,  -201016, 0, 0, 0, 0), -- Findle Whistlesteam
(93519,  -201016, 0, 0, 0, 0), -- Findle Whistlesteam 
(99078,  -201016, 0, 0, 0, 0), -- Findle Whistlesteam 
(113926, -201016, 0, 0, 0, 0), -- Findle Whistlesteam

-- Engineering spells
(201012, 3922,   115,    202, 30,  0),  -- Handful of Copper Bolts
(201012, 3923,   130,    202, 30,  0),  -- Rough Copper Bomb
(201012, 3924,   150,    202, 50,  0),  -- Copper Tube
(201012, 3925,   150,    202, 50,  0),  -- Rough Boomstick
(201012, 3929,   250,    202, 75,  0),  -- Coarse Blasting Powder
(201012, 3931,   250,    202, 75,  0),  -- Coarse Dynamite
(201012, 3932,   300,    202, 85,  0),  -- Target Dummy
(201012, 3934,   400,    202, 100, 0),  -- Flying Tiger Goggles
(201012, 3936,   420,    202, 105, 0),  -- Deadly Blunderbuss
(201012, 3937,   450,    202, 105, 0),  -- Large Copper Bomb
(201012, 3938,   450,    202, 105, 0),  -- Bronze Tube
(201012, 3939,   500,    202, 120, 19), -- Lovingly Crafted Boomstick
(201012, 3941,   500,    202, 120, 0),  -- Small Bronze Bomb
(201012, 3942,   500,    202, 125, 0),  -- Whirring Bronze Gizmo
(201012, 3945,   500,    202, 125, 0),  -- Heavy Blasting Powder
(201012, 3946,   500,    202, 125, 0),  -- Heavy Dynamite
(201012, 3949,   550,    202, 130, 0),  -- Silver-plated Shotgun
(201012, 3950,   600,    202, 140, 0),  -- Big Bronze Bomb
(201012, 3953,   600,    202, 145, 0),  -- Bronze Framework
(201012, 3955,   750,    202, 150, 0),  -- Explosive Sheep
(201012, 3956,   450,    202, 150, 0),  -- Green Tinted Goggles
(201012, 3958,   800,    202, 160, 0),  -- Iron Strut
(201012, 3961,   900,    202, 170, 0),  -- Gyrochronatom
(201012, 3962,   1000,   202, 175, 0),  -- Iron Grenade
(201012, 3963,   1000,   202, 175, 0),  -- Compact Harvest Reaper Kit
(201012, 3965,   1200,   202, 185, 0),  -- Advanced Target Dummy
(201012, 3967,   1400,   202, 190, 0),  -- Big Iron Bomb
(201012, 3973,   300,    202, 90,  0),  -- Silver Contact
(201012, 3977,   200,    202, 60,  0),  -- Crude Scope
(201012, 3978,   475,    202, 110, 0),  -- Standard Scope
(201012, 3979,   1200,   202, 180, 20), -- Accurate Scope
(201012, 4039,   10,     0,   0,   5),  -- Apprentice Engineer
(201012, 4040,   500,    202, 50,  10), -- Journeyman Engineer
(201012, 4041,   5000,   202, 125, 20), -- Expert Engineer
(201012, 6458,   400,    202, 135, 0),  -- Ornate Spyglass
(201012, 7430,   150,    202, 50,  0),  -- Arclight Spanner
(201012, 8334,   300,    202, 100, 0),  -- Clockwork Box
(201012, 9271,   500,    202, 150, 0),  -- Aquadynamic Fish Attractor
(201012, 12584,  1000,   202, 150, 0),  -- Gold Power Core
(201012, 12585,  1000,   202, 175, 0),  -- Solid Blasting Powder
(201012, 12586,  1000,   202, 175, 0),  -- Solid Dynamite
(201012, 12589,  1300,   202, 195, 0),  -- Mithril Tube
(201012, 12590,  1000,   202, 175, 0),  -- Gyromatic Micro-Adjustor
(201012, 12591,  1500,   202, 200, 0),  -- Unstable Trigger
(201012, 12594,  1600,   202, 205, 0),  -- Fire Goggles
(201012, 12595,  1600,   202, 205, 0),  -- Mithril Blunderbuss
(201012, 12599,  1800,   202, 215, 0),  -- Mithril Casing
(201012, 12603,  1800,   202, 215, 0),  -- Mithril Frag Bomb
(201012, 12615,  2500,   202, 225, 0),  -- Spellpower Goggles Xtreme
(201012, 12617,  2200,   202, 230, 0),  -- Deepdive Helmet
(201012, 12618,  2200,   202, 230, 0),  -- Rose Colored Goggles
(201012, 12619,  2400,   202, 235, 0),  -- Hi-Explosive Bomb
(201012, 12622,  2800,   202, 245, 0),  -- Green Lens
(201012, 12657,  50000,  202, 200, 35), -- Artisan Engineer
(201012, 12754,  2250,   202, 235, 0),  -- The Big One
(201012, 12759,  2800,   202, 240, 0),  -- Gnomish Death Ray
(201012, 12895,  1500,   202, 205, 0),  -- Inlaid Mithril Cylinder Plans
(201012, 15255,  1500,   202, 200, 0),  -- Mechanical Repair Kit
(201012, 19788,  4000,   202, 250, 0),  -- Dense Blasting Powder
(201012, 19790,  10000,  202, 260, 0),  -- Thorium Grenade
(201012, 19791,  5000,   202, 260, 0),  -- Thorium Widget
(201012, 19792,  10000,  202, 260, 0),  -- Thorium Rifle
(201012, 19794,  20000,  202, 270, 0),  -- Spellpower Goggles Xtreme Plus
(201012, 19795,  10000,  202, 275, 0),  -- Thorium Tube
(201012, 19825,  20000,  202, 290, 0),  -- Master Engineer's Goggles
(201012, 23070,  5000,   202, 250, 0),  -- Dense Dynamite
(201012, 23071,  5000,   202, 260, 0),  -- Truesilver Transformer
(201012, 30303,  10000,  202, 300, 0),  -- Elemental Blasting Powder
(201012, 30304,  10000,  202, 300, 0),  -- Fel Iron Casing
(201012, 30305,  10000,  202, 300, 0),  -- Handful of Fel Iron Bolts
(201012, 30306,  20000,  202, 325, 0),  -- Adamantite Frame
(201012, 30307,  50000,  202, 340, 0),  -- Hardened Adamantite Tube
(201012, 30308,  50000,  202, 340, 0),  -- Khorium Power Core
(201012, 30309,  50000,  202, 340, 0),  -- Felsteel Stabilizer
(201012, 30310,  15000,  202, 300, 0),  -- Fel Iron Bomb
(201012, 30311,  25000,  202, 325, 0),  -- Adamantite Grenade
(201012, 30312,  20000,  202, 320, 0),  -- Fel Iron Musket
(201012, 30351,  100000, 202, 275, 50), -- Master Engineer
(201012, 30558,  25000,  202, 325, 65), -- The Bigger One
(201012, 30560,  35000,  202, 340, 0),  -- Super Sapper Charge
(201012, 30565,  100000, 202, 375, 70), -- Foreman's Enchanted Helmet
(201012, 30570,  50000,  202, 350, 0),  -- Nigh-Invulnerability Belt
(201012, 39895,  10000,  202, 275, 0),  -- Fused Wiring
(201012, 39971,  20000,  202, 335, 0),  -- Icy Blasting Primers
(201012, 40274,  50000,  202, 350, 0),  -- Furious Gizmatic Goggles
(201012, 41307,  50000,  202, 375, 0),  -- Gyro-balanced Khorium Destroyer
(201012, 41311,  50000,  202, 350, 0),  -- Justicebringer 2000 Specs
(201012, 41312,  50000,  202, 350, 0),  -- Tankatronic Goggles
(201012, 41314,  50000,  202, 350, 0),  -- Surestrike Goggles v2.0
(201012, 41315,  50000,  202, 350, 0),  -- Gadgetstorm Goggles
(201012, 41316,  50000,  202, 350, 0),  -- Living Replicator Specs
(201012, 41317,  50000,  202, 350, 0),  -- Deathblow X11 Goggles
(201012, 41318,  50000,  202, 350, 0),  -- Wonderheal XT40 Shades
(201012, 41319,  50000,  202, 350, 0),  -- Magnified Moon Specs
(201012, 41320,  50000,  202, 350, 0),  -- Destruction Holo-gogs
(201012, 41321,  50000,  202, 350, 0),  -- Powerheal 4000 Lens
(201012, 44155,  50000,  202, 300, 60), -- Flying Machine
(201012, 44157,  180000, 202, 375, 60), -- Turbo-Charged Flying Machine
(201012, 51305,  350000, 202, 350, 0),  --  Grand Master Engineer
(201012, 53281,  50000,  202, 350, 0),  -- Volatile Blasting Trigger
(201012, 54353,  125000, 202, 400, 0),  -- Mark "S" Boomstick
(201012, 54736,  100000, 202, 390, 0),  -- EMP Generator
(201012, 54793,  100000, 202, 380, 0),  -- Frag Belt
(201012, 55002,  100000, 202, 380, 0),  -- Flexweave Underlay
(201012, 55016,  125000, 202, 405, 0),  -- Nitro Boosts
(201012, 56349,  50000,  202, 350, 0),  -- Handful of Cobalt Bolts
(201012, 56459,  100000, 202, 375, 0),  -- Hammer Pick
(201012, 56460,  50000,  202, 350, 0),  -- Cobalt Frag Bomb
(201012, 56461,  100000, 202, 375, 0),  -- Bladed Pickaxe
(201012, 56462,  150000, 202, 435, 0),  -- Gnomish Army Knife
(201012, 56463,  100000, 202, 375, 0),  -- Explosive Decoy
(201012, 56464,  100000, 202, 375, 0),  -- Overcharged Capacitor
(201012, 56465,  125000, 202, 420, 0),  -- Mechanized Snow Goggles
(201012, 56466,  125000, 202, 420, 0),  -- Sonic Booster
(201012, 56467,  125000, 202, 420, 0),  -- Noise Machine
(201012, 56468,  125000, 202, 405, 0),  -- Box of Bombs
(201012, 56469,  150000, 202, 425, 0),  -- Gnomish Lightning Generator
(201012, 56470,  150000, 202, 425, 0),  -- Sun Scope
(201012, 56471,  100000, 202, 390, 0),  -- Froststeel Tube
(201012, 56472,  150000, 202, 425, 0),  -- MOLL-E
(201012, 56474,  125000, 202, 410, 0),  -- Truesight Ice Blinders
(201012, 56476,  125000, 202, 410, 0),  -- Healing Injector Kit
(201012, 56477,  125000, 202, 415, 0),  -- Mana Injector Kit
(201012, 56478,  200000, 202, 430, 0),  -- Heartseeker Scope
(201012, 56479,  200000, 202, 450, 0),  -- Armor Plated Combat Shotgun
(201012, 56480,  150000, 202, 440, 0),  -- Armored Titanium Goggles
(201012, 56481,  150000, 202, 440, 0),  -- Weakness Spectralizers
(201012, 56483,  150000, 202, 440, 0),  -- Charged Titanium Specs
(201012, 56484,  150000, 202, 440, 0),  -- Visage Liquification Goggles
(201012, 56486,  150000, 202, 440, 0),  -- Greensight Gogs
(201012, 56487,  150000, 202, 440, 0),  -- Electroflux Sight Enhancers
(201012, 56574,  150000, 202, 440, 0),  -- Truesight Ice Blinders
(201012, 60874,  200000, 202, 450, 0),  -- Nesingwary 4000
(201012, 61471,  100000, 202, 390, 0),  -- Diamond-cut Refractor Scope
(201012, 61481,  125000, 202, 420, 0),  -- Mechanized Snow Goggles
(201012, 61482,  125000, 202, 420, 0),  -- Mechanized Snow Goggles
(201012, 61483,  125000, 202, 420, 0),  -- Mechanized Snow Goggles
(201012, 62271,  150000, 202, 440, 0),  -- Unbreakable Healing Amplifiers
(201012, 63750,  5000,   202, 250, 0),  -- High-powered Flashlight
(201012, 67326,  100000, 202, 410, 0),  -- Goblin Beam Welder
(201012, 67839,  100000, 202, 410, 0),  -- Mind Amplification Dish
(201012, 67920,  150000, 202, 435, 0),  -- Wormhole Generator: Northrend
(201012, 81714,  240000, 202, 525, 0),  -- Reinforced Bio-Optic Killshades
(201012, 81715,  240000, 202, 525, 0),  -- Specialized Bio-Optic Killshades
(201012, 81716,  240000, 202, 525, 0),  -- Deadly Bio-Optic Killshades
(201012, 81720,  240000, 202, 525, 0),  -- Energized Bio-Optic Killshades
(201012, 81722,  240000, 202, 525, 0),  -- Agile Bio-Optic Killshades
(201012, 81724,  240000, 202, 525, 0),  -- Camouflage Bio-Optic Killshades
(201012, 81725,  240000, 202, 525, 0),  -- Lightweight Bio-Optic Killshades
(201012, 82775,  500000, 202, 425, 0),  -- Illustrious Grand Master Engineer
(201012, 84403,  150000, 202, 425, 0),  -- Handful of Obsidium Bolts
(201012, 84406,  150000, 202, 440, 0),  -- Authentic Jr. Engineer Goggles
(201012, 84408,  150000, 202, 450, 80), -- R19 Threatfinder
(201012, 84409,  160000, 202, 455, 0),  -- Volatile Seaforium Blastpack
(201012, 84410,  150000, 202, 450, 80), -- Safety Catch Removal Kit
(201012, 84411,  160000, 202, 450, 0),  -- High-Powered Bolt Gun
(201012, 84412,  160000, 202, 475, 0),  -- Personal World Destroyer
(201012, 84413,  160000, 202, 475, 0),  -- De-Weaponized Mechanical Companion
(201012, 84415,  170000, 202, 475, 0),  -- Lure Master Tackle Box
(201012, 84416,  170000, 202, 475, 0),  -- Elementium Toolbox
(201012, 84417,  170000, 202, 495, 83), -- Volatile Thunderstick
(201012, 84418,  170000, 202, 475, 80), -- Elementium Dragonling
(201012, 84420,  170000, 202, 475, 83), -- Finely-Tuned Throat Needler
(201012, 84421,  170000, 202, 490, 0),  -- Loot-a-Rang
(201012, 84429,  200000, 202, 505, 0),  -- Goblin Barbecue
(201012, 84430,  200000, 202, 510, 0),  -- Heat-Treated Spinning Lure
(201012, 84431,  240000, 202, 525, 85), -- Overpowered Chicken Splitter
(201012, 84432,  240000, 202, 525, 85), -- Kickback 5000
(201012, 94748,  150000, 202, 445, 0),  -- Electrified Ether
(201012, 95703,  150000, 202, 440, 0),  -- Electrostatic Condenser
(201012, 95705,  200000, 202, 500, 0),  -- Gnomish Gravity Well
(201012, 109099, 150000, 202, 550, 0),  -- Watergliding Jets
(201012, 110404, 600000, 202, 500, 0),  -- Zen Master Engineer
(201012, 126392, 150000, 202, 550, 0),  -- Goblin Glider
(201012, 127008, 150000, 202, 600, 0),  -- Blingtron 4000
(201012, 127113, 50000,  202, 500, 0),  -- Ghost Iron Bolts
(201012, 127114, 50000,  202, 500, 0),  -- High-Explosive Gunpowder
(201012, 127115, 50000,  202, 560, 85), -- Lord Blastington's Scope of Doom
(201012, 127116, 50000,  202, 525, 85), -- Mirror Scope
(201012, 127117, 150000, 202, 600, 0),  -- Lightweight Retinal Armor
(201012, 127118, 50000,  202, 600, 0),  -- Agile Retinal Armor
(201012, 127119, 150000, 202, 600, 0),  -- Camouflage Retinal Armor
(201012, 127120, 150000, 202, 600, 0),  -- Deadly Retinal Armor
(201012, 127121, 150000, 202, 600, 0),  -- Energized Retinal Armor
(201012, 127122, 150000, 202, 600, 0),  -- Specialized Retinal Armor
(201012, 127123, 50000,  202, 600, 87), -- Reinforced Retinal Armor
(201012, 127124, 50000,  202, 500, 0),  -- Locksmith's Powderkeg
(201012, 127127, 50000,  202, 525, 85), -- G91 Landshark
(201012, 127128, 50000,  202, 550, 85), -- Goblin Dragon Gun, Mark II
(201012, 127129, 50000,  202, 525, 85), -- Blingtron 4000
(201012, 127130, 50000,  202, 525, 0),  -- Mist-Piercing Goggles
(201012, 127131, 50000,  202, 550, 0),  -- Thermal Anvil
(201012, 127132, 50000,  202, 570, 0),  -- Wormhole Generator: Pandaria
(201012, 127134, 50000,  202, 550, 0),  -- Ghost Iron Dragonling
(201012, 127135, 50000,  202, 575, 0),  -- Mechanical Pandaren Dragonling
(201012, 127136, 150000, 202, 525, 0),  -- Big Game Hunter          
(201012, 127137, 50000,  202, 450, 90), -- Long-Range Trillium Sniper
(201012, 127138, 160000, 202, 600, 0),  -- Depleted-Kyparium Rocket
(201012, 127139, 160000, 202, 600, 0),  -- Geosynchronous World Spinner
(201012, 131211, 50000,  202, 550, 0),  -- Flashing Tinker's Gear
(201012, 131212, 50000,  202, 550, 0),  -- Fractured Tinker's Gear
(201012, 131213, 50000,  202, 550, 0),  -- Precise Tinker's Gear
(201012, 131214, 50000,  202, 550, 0),  -- Quick Tinker's Gear
(201012, 131215, 50000,  202, 550, 0),  -- Rigid Tinker's Gear
(201012, 131216, 50000,  202, 550, 0),  -- Smooth Tinker's Gear
(201012, 131217, 50000,  202, 550, 0),  -- Sparkling Tinker's Gear
(201012, 131218, 50000,  202, 550, 0),  -- Subtle Tinker's Gear
(201012, 131353, 50000,  202, 500, 0),  -- Pandaria Fireworks
(201012, 131563, 50000,  202, 550, 0),  -- Tinker's Kit

-- Goblin Engineering Spells
(201015, 8895,    2200,   202, 225, 0),  -- Goblin Rocket Boots
(201015, 12715,   1500,   202, 205, 0),  -- Goblin Rocket Fuel Recipe
(201015, 12716,   1500,   202, 205, 0),  -- Goblin Mortar
(201015, 12717,   1500,   202, 205, 0),  -- Goblin Mining Helmet
(201015, 12718,   1500,   202, 205, 0),  -- Goblin Construction Helmet
(201015, 12754,   2250,   202, 235, 0),  -- The Big One
(201015, 12755,   2400,   202, 230, 0),  -- Goblin Bomb Dispenser
(201015, 12758,   2600,   202, 245, 0),  -- Goblin Rocket Helmet
(201015, 12760,   1500,   202, 205, 0),  -- Goblin Sapper Charge
(201015, 12908,   2800,   202, 240, 0),  -- Goblin Dragon Gun
(201015, 30558,   25000,  202, 325, 65), -- The Bigger One
(201015, 30563,   50000,  202, 350, 0),  -- Goblin Rocket Launcher
(201015, 30565,   100000, 202, 375, 0),  -- Foreman's Enchanted Helmet
(201015, 30560,   35000,  202, 340, 0),  -- Super Sapper Charge 
(201015, 30566,   100000, 202, 375, 0),  -- Foreman's Reinforced Helmet
(201015, 56514,   150000, 202, 425, 70), -- Global Thermal Sapper Charge
(201015, 84412,   160000, 202, 475, 0),  -- Personal World Destroyer
(201012, 95707,   200000, 202, 500, 0),  -- Big Daddy
(201015, 127138,  160000, 202, 600, 0),  -- Depleted-Kyparium Rocket

-- Gnomish Engineering Spells
(201016, 12895,  1500,   202, 200, 0), -- Inlaid Mithril Cylinder Plans
(201016, 12897,  1500,   202, 210, 0), -- Gnomish Goggles
(201016, 12899,  1500,   202, 205, 0), -- Gnomish Shrink Ray
(201016, 12902,  1800,   202, 210, 0), -- Gnomish Net-o-Matic Projector
(201016, 12903,  2000,   202, 215, 0), -- Gnomish Harm Prevention Belt
(201016, 12905,  1500,   202, 210, 0), -- Gnomish Rocket Boots
(201016, 12906,  2400,   202, 230, 0), -- Gnomish Battle Chicken
(201016, 12907,  2600,   202, 235, 0), -- Gnomish Mind Control Cap
(201016, 30568,  25000,  202, 325, 0), -- Gnomish Flame Turret
(201016, 30569,  35000,  202, 340, 0), -- Gnomish Poultryizer
(201016, 30570,  50000,  202, 350, 0), -- Nigh-Invulnerability Belt
(201016, 30574,  100000, 202, 375, 0), -- Gnomish Power Goggles
(201016, 30575,  100000, 202, 375, 0), -- Gnomish Battle Goggles
(201016, 56473,  150000, 202, 425, 0), -- Gnomish X-Ray Specs
(201016, 95705,  200000, 202, 500, 0); -- Gnomish Gravity Well
