UPDATE `creature_template` SET `npcflag`=49 WHERE `entry`=19340; -- Mi'irku Farstep
UPDATE `creature_template` SET `npcflag`=49 WHERE `entry`=32712; -- The Amazing Zanzo

DELETE FROM `npc_vendor` WHERE `item` IN (30637, 30622, 30623);

DELETE FROM `creature_equip_template` WHERE `entry` IN (19362, 19792, 20238, 34830, 35063, 35075, 35186, 35200, 35237, 35882, 36179, 36600, 37965, 38409, 38432, 38493, 38998, 39006, 39129, 39642, 39655, 39843, 40529, 40776, 40777, 40779, 41122, 41509, 41911, 41913, 41915, 42218, 42296, 42297, 42775, 42937, 43138, 43229, 43232, 44158, 44847, 44855, 45334, 45798, 47168, 47289, 48125);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(19362, 30178, 0, 2507), -- Kor'kron Defender
(19792, 30179, 21549, 0), -- Eclipsion Centurion
(20238, 0, 0, 5258), -- Honor Hold Scout
(34830, 2704, 0, 0), -- Defiant Troll
(35063, 31824, 0, 0), -- Kezan Citizen
(35075, 3346, 0, 0), -- Kezan Citizen
(35186, 2718, 0, 0), -- Kezan Partygoer
(35200, 2179, 0, 0), -- Pirate Party Crasher
(35237, 2179, 0, 0), -- Pirate Party Crasher
(35882, 12629, 0, 0), -- Orc Survivor
(36179, 17040, 13604, 0), -- Goblin Survivor
(36600, 1911, 0, 0), -- Geargrinder Gizmo
(37965, 40595, 49933, 0), -- Argent Commander
(38409, 50154, 0, 0), -- Goblin Survivor
(38432, 33963, 0, 0), -- Megs Dreadshredder
(38493, 46107, 49933, 0), -- Argent Crusader
(38998, 3346, 0, 0), -- Explorer's League Digger
(39006, 1903, 0, 12523), -- Siege Tank Engineer
(39129, 1902, 0, 0), -- Peasant Laborer
(39642, 33275, 0, 0), -- Hovel Brute
(39655, 12629, 0, 0), -- Orc Survivor
(39843, 43219, 0, 0), -- Twilight Stormcaller
(40529, 2202, 0, 0), -- Gnome Bar Patron
(40776, 5289, 0, 0), -- Speedbarge Crewmember
(40777, 1910, 0, 0), -- Speedbarge Crewmember
(40779, 2703, 0, 0), -- Speedbarge Crewmember
(41122, 3350, 0, 0), -- Frostmane Snowstrider
(41509, 12993, 12993, 30456), -- Irontree Warden
(41911, 37, 0, 0), -- Forsaken Invader
(41913, 2901, 0, 0), -- Gilneas Citizen
(41915, 50035, 60952, 2551), -- Worgen Warrior
(42218, 21573, 21572, 2551), -- Stormwind Royal Guard
(42296, 11763, 2944, 0), -- Shadowsworn Spellblade
(42297, 23369, 2944, 0), -- Shadowsworn Occultist
(42775, 0, 0, 33080), -- Bilgewater Dockworker
(42937, 14877, 0, 0), -- Blackrock Invader
(43138, 57125, 0, 0), -- Stonehearth Defender
(43229, 57011, 0, 0), -- Injured Earthen
(43232, 39447, 0, 0), -- Earthen Champion
(44158, 1902, 0, 0), -- Orgrimmar Skyway Peon
(44847, 52840, 0, 57176), -- Twilight Armsman
(44855, 60208, 0, 0), -- Twilight Cryptomancer
(45334, 52057, 0, 0), -- Twilight Bonebreaker
(45798, 31601, 0, 0), -- Crushblow Warrior
(47168, 0, 0, 52052), -- Wildhammer Homesteader
(47289, 1903, 0, 0), -- Argent Crusade Engineer
(48125, 54824, 0, 0); -- Advisor Sarophas
