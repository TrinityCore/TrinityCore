UPDATE `gameobject_template` SET `faction`=114 WHERE `entry` IN (192310,192312,192313,192314,192316,192317,192318,192319,192320,192321,192322,192323,192324,192325,192326,192327,192328,192329,
192330,192331,192332,192333,192334,192335,192286,192287,192292,192299,192304,192305,192306,192307,192308,192309); -- Alliance Banner

UPDATE `gameobject_template` SET `faction`=114 WHERE `entry` IN (192269,192284,192285,192338,192339,192349,192350,192351,192352,192353,192354,192355,192356,192357,192358,192359,192360,192361,
192362,192363,192364,192366,192367,192368,192369,192370,192371,192372,192373,192374,192375,192376,192377,192378,192379,192254,
192255,192336); -- Horde Banner

UPDATE `gameobject_template` SET `faction`=114 WHERE `entry` IN (193096,193097,193098,193099,193100,193101,193102,193103,193104,193105,193106,193107,193108,193109,193124,193125,193126,193127,
193128,193129,193130,193131,193132,193133,193134,193135,193136,193137,193138,193139,193140,193141,193142,193143,193144,193145,
193146,193147,193148,193149,193150,193151,193152,193153,193154,193155,193156,193157,193158,193159,193160,193161,193162,193163,
193164,193165); -- nameless GOs

UPDATE `creature_template` SET `exp`=0 WHERE `entry`=31841; -- Taunka Spirit Guide
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=31842; -- Dwarven Spirit Guide
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=31052; -- Bowyer Randolph
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry`=39172; -- Marshal Magruder
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry`=30488; -- Travis Day
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=31053; -- Primalist Mulfort
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|4 WHERE `entry`=31107; -- Lieutenant Murp (?)
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|768 WHERE `entry`=39173; -- Champion Ros'slai
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|16 WHERE `entry`=30740; -- Valiance Expedition Champion (?)
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=27852; -- Wintergrasp Control Arms
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216 WHERE `entry`=28366; -- Wintergrasp Tower Cannon
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`unit_class`=4,`speed_walk`=1.2 WHERE `entry`=32629; -- Wintergrasp Siege Turret
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`unit_class`=4,`speed_walk`=1.2 WHERE `entry`=28319; -- Wintergrasp Siege Turret
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`unit_class`=4,`speed_walk`=1.2,`speed_run`=1 WHERE `entry`=32627; -- Wintergrasp Siege Engine
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`unit_class`=4,`speed_walk`=1.2,`speed_run`=1 WHERE `entry`=28312; -- Wintergrasp Siege Engine
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`speed_walk`=1.2,`speed_run`=1 WHERE `entry`=28094; -- Wintergrasp Demolisher
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=16777216,`unit_flags`=16384,`unit_class`=4,`speed_walk`=2.8,`speed_run`=1.71429 WHERE `entry`=27881; -- Wintergrasp Catapult

UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=27894; -- Knight Dameron
UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=31346; -- Marshal Magruder
UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=31347; -- Champion Ros'slai
UPDATE `creature_model_info` SET `bounding_radius`=0.305,`combat_reach`=5,`gender`=2 WHERE `modelid`=25301; -- Wintergrasp Siege Turret

DELETE FROM `creature_template_addon` WHERE `entry` IN (31841,31842,30400,30499,30489,30869,31036,31051,31052,31054,31108,31109,31153,32294,39172,30870,31053,31091,31101,31102,31106,31107,31151,32296,39173,30740,32629,28319,28366,32627,28312,28094,27881,30739);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31841,0,0,1,0, '58729'), -- Taunka Spirit Guide (Spiritual Immunity, Spirit Heal Channel) FIX: Do we need the spell that revives players here (22011)? It has a duration (found in sniffs). 
(31842,0,0,1,0, '58729'), -- Dwarven Spirit Guide                                               This spell (and the spell it triggers, are used in the "ressurect system" in Battleground.cpp
(30400,0,0,1,0, NULL), -- Goblin Mechanic
(30499,0,0,1,0, NULL), -- Gnomish Engineer
(30489,0,0,1,0, NULL), -- Morgan Day
(30869,0,0,1,0, NULL), -- Arzo Safeflight
(31036,14337,0,257,0, NULL), -- Commander Zanneth
(31051,0,0,1,0, NULL), -- Sorceress Kaylana
(31052,0,0,257,0, NULL), -- Bowyer Randolph
(31054,0,0,257,0, NULL), -- Anchorite Tessa
(31108,0,0,257,0, NULL), -- Siege Master Stouthandle
(31109,0,0,257,0, NULL), -- Senior Demolitionist Legoso
(31153,6569,0,257,0, NULL), -- Tactical Officer Ahbramis
(32294,27247,0,1,0, NULL), -- Knight Dameron
(39172,28912,0,1,0, NULL), -- Marshal Magruder
(30870,0,0,1,0, NULL), -- Herzo Safeflight
(31053,0,0,257,0, '18950'), -- Primalist Mulfort (Invisibility and Stealth Detection ... why?)
(31091,0,0,257,0, '18950'), -- Commander Dardosh (Invisibility and Stealth Detection)
(31101,0,0,1,0, NULL), -- Hoodoo Master Fu'jin
(31102,0,0,1,0, NULL), -- Vieron Blazefeather
(31106,0,0,257,0, NULL), -- Siegesmith Stronghoof
(31107,0,0,257,0, NULL), -- Lieutenant Murp
(31151,0,0,257,0, NULL), -- Tactical Officer Kilrath
(32296,27245,0,1,0, NULL), -- Stone Guard Mukar
(39173,29261,0,1,0, NULL), -- Champion Ros'slai
(30740,0,0,257,375, NULL), -- Valiance Expedition Champion
(32629,0,0,257,0, NULL), -- Wintergrasp Siege Turret
(28319,0,0,257,0, NULL), -- Wintergrasp Siege Turret
(28366,0,0,257,0, NULL), -- Wintergrasp Tower Cannon
(32627,0,0,257,0, NULL), -- Wintergrasp Siege Engine
(28312,0,0,257,0, NULL), -- Wintergrasp Siege Engine
(28094,0,0,257,0, NULL), -- Wintergrasp Demolisher
(27881,0,0,257,0, NULL), -- Wintergrasp Catapult
(30739,0,0,257,375, NULL); -- Warsong Champion

-- Wintergrasp vehicles:
UPDATE `creature_template` SET `spell1`=51421, /* Fire Cannon */ `spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=28366; -- Wintergrasp Tower Cannon (Both)
UPDATE `creature_template` SET `spell1`=57609, /* Fire Cannon */ `spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=32629; -- Wintergrasp Siege Turret (H)
UPDATE `creature_template` SET `spell1`=57609, /* Fire Cannon */ `spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=28319; -- Wintergrasp Siege Turret (A)
UPDATE `creature_template` SET `spell1`=54109, /* Ram */ `spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=32627; -- Wintergrasp Siege Engine (H)
UPDATE `creature_template` SET `spell1`=54109, /* Ram */ `spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=28312; -- Wintergrasp Siege Engine (A)
UPDATE `creature_template` SET `spell1`=54107, /* Ram */ `spell2`=50896, /* Hurl Boulder */ `spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=28094; -- Wintergrasp Demolisher (H)
UPDATE `creature_template` SET `spell1`=57606, /* Plague Barrel */ `spell2`=50989, /* Flame Breath */ `spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry`=27881; -- Wintergrasp Catapult (Both)

-- Note: Siege Engines, Demolisher faction is guess (vehicles get the faction of his driver)
-- Demolisher spell positions is not confirmed
-- Wintergrasp Tower Cannon H: 1735 A: 1732
