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

/*
Sniff check these
-- Wintergrasp Cannons (Spell 51421 : Fire Cannon)
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1735 WHERE `entry`=28366; -- *** WRONG ****
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732 WHERE `entry` IN (30499,30740, 28319); -- Alliance
UPDATE `creature_template` SET `faction_A`=1735,`faction_H`=1735 WHERE `entry` IN (30400,30739, 32629); -- Horde

-- Added by Malcrom
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732 WHERE `entry` IN (28312); -- Alliance
UPDATE `creature_template` SET `faction_A`=1735,`faction_H`=1735 WHERE `entry` IN (32627); -- Horde

-- Wintergrasp Catapult speed adjustments
UPDATE `creature_template` SET `speed_walk`=2.8,`speed_run`=1.71429 WHERE `entry`=27881;

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9904 WHERE `entry`=30400;
UPDATE `creature_template` SET `gossip_menu_id`=10229 WHERE `entry`=31091;
*/

UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=27894; -- Knight Dameron
UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=31346; -- Marshal Magruder
UPDATE `creature_model_info` SET `bounding_radius`=0.3366,`combat_reach`=1.65,`gender`=0 WHERE `modelid`=31347; -- Champion Ros'slai

DELETE FROM `creature_template_addon` WHERE `entry` IN (31841,31842,30400,30499,30489,30869,31036,31051,31052,31054,31108,31109,31153,32294,39172,30870,31053,31091,31101,31102,31106,31107,31151,32296,39173,30740);
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
(30740,0,0,257,375, NULL); -- Valiance Expedition Champion

