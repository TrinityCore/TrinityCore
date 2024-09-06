-- Creature templates
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32625; -- Warsong Gulch Portal
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32619; -- Arathi Basin Portal
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32620; -- Eye of the Storm Portal
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32617; -- Alterac Valley Portal
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=107697; -- Controller
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=30872; -- Shadow Revenant
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27852; -- Wintergrasp Control Arms
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=30877; -- Water Revenant
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=30400; -- Goblin Mechanic
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=30875; -- Tempest Revenant
UPDATE `creature_template` SET `unit_flags`=832, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=26475; -- Magmawyrm
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=27355; -- Rothin the Decaying
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=27362; -- Smoldering Construct
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=32522; -- Cinder Cloud
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=27869; -- Wintergrasp Detection Unit
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32624; -- Warsong Gulch Portal
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32618; -- Arathi Basin Portal
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32616; -- Alterac Valley Portal
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32294; -- Knight Dameron
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=32621; -- Eye of the Storm Portal

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (30872,30873,30876,30877,31689);
INSERT INTO `creature_template_movement` (`CreatureId`,`HoverInitiallyEnabled`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(30872,1,0,0,NULL),
(30873,1,0,0,NULL),
(30876,1,0,0,NULL),
(30877,1,0,0,NULL),
(31689,1,0,0,NULL);

-- Difficulties
UPDATE `creature_template_difficulty` ctd
LEFT JOIN `creature_template_difficulty` ctd2 ON ctd.`Entry`=ctd2.`Entry`
SET
    ctd.`DamageModifier`=ctd2.`DamageModifier`,
    ctd.`LootID`=ctd2.`LootID`,
    ctd.`PickPocketLootID`=ctd2.`PickPocketLootID`,
    ctd.`SkinLootID`=ctd2.`SkinLootID`,
    ctd.`GoldMin`=ctd2.`GoldMin`,
    ctd.`GoldMax`=ctd2.`GoldMax`
WHERE ctd.`Entry` IN (31053,31151,31107,31102,31101,107697,30870,34300,30845,30872,30842,15214,27852,31842,31054,31051,31109,30846,31841,30560,26607,26606,30875,27450,27418,27449,27355,27369,27358,27362,27363,27869,30873)
AND ctd.`DifficultyID`=0 AND ctd2.`DifficultyID`=1 AND ctd2.`Entry` IS NOT NULL;

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (30499,30489,32621,32294,30488,32616,39172,32618,32624,31053,31151,31107,31102,31101,107697,30870,34300,30845,30872,30842,15214,27852,31842,31054,31051,31109,30846,31841,30560,26607,26606,30875,27450,27418,27449,27355,27369,27358,27362,27363,27869,30873,32625,32619,32620,32617,39173,32296,31091,31106,31052,30869,31153,31108,31036,19871,30876,30849,30877,30400,30739,23472,30848,26475,32522,30847,30740));

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=22515 AND `DifficultyID`=0); -- World Trigger
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54762 WHERE (`DifficultyID`=0 AND `Entry` IN (32625,32619,32620,32617,39173,32296,31091,31106,31052,30869,31153,31108,31036,19871,30876,30849,30877,30400,30739,23472,30848,26475,32522,30847,30740));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=31053 AND `DifficultyID`=0); -- 31053 (Primalist Mulfort) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31151 AND `DifficultyID`=0); -- 31151 (Tactical Officer Kilrath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=31107 AND `DifficultyID`=0); -- 31107 (Lieutenant Murp) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31102 AND `DifficultyID`=0); -- 31102 (Vieron Blazefeather) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31101 AND `DifficultyID`=0); -- 31101 (Hoodoo Master Fu'jin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=107697 AND `DifficultyID`=0); -- 107697 (Controller) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=881, `VerifiedBuild`=54762 WHERE (`Entry`=30870 AND `DifficultyID`=0); -- 30870 (Herzo Safeflight) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=34300 AND `DifficultyID`=0); -- 34300 (Mature Lasher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=30845 AND `DifficultyID`=0); -- 30845 (Living Lasher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=30872 AND `DifficultyID`=0); -- 30872 (Shadow Revenant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=30842 AND `DifficultyID`=0); -- 30842 (Wandering Shadow) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=54762 WHERE (`Entry`=15214 AND `DifficultyID`=0); -- 15214 (Invisible Stalker) - 
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27852 AND `DifficultyID`=0); -- 27852 (Wintergrasp Control Arms) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=31842 AND `DifficultyID`=0); -- 31842 (Dwarven Spirit Guide) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31054 AND `DifficultyID`=0); -- 31054 (Anchorite Tessa) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31051 AND `DifficultyID`=0); -- 31051 (Sorceress Kaylana) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=31109 AND `DifficultyID`=0); -- 31109 (Senior Demolitionist Legoso) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=30846 AND `DifficultyID`=0); -- 30846 (Glacial Spirit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=31841 AND `DifficultyID`=0); -- 31841 (Taunka Spirit Guide) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=30560 AND `DifficultyID`=0); -- 30560 (The RP-GG) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=26607 AND `DifficultyID`=0); -- 26607 (Anub'ar Blightbeast) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=26606 AND `DifficultyID`=0); -- 26606 (Anub'ar Slayer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=805306368, `VerifiedBuild`=54762 WHERE (`Entry`=30875 AND `DifficultyID`=0); -- 30875 (Tempest Revenant) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27450 AND `DifficultyID`=0); -- 27450 (Neltharion's Flame Control Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27418 AND `DifficultyID`=0); -- 27418 (Rothin's Spell Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27449 AND `DifficultyID`=0); -- 27449 (Neltharion's Flame Fire Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=27355 AND `DifficultyID`=0); -- 27355 (Rothin the Decaying) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27369 AND `DifficultyID`=0); -- 27369 (Necromantic Rune Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=27358 AND `DifficultyID`=0); -- 27358 (Burning Depths Necromancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=46, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=27362 AND `DifficultyID`=0); -- 27362 (Smoldering Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=27363 AND `DifficultyID`=0); -- 27363 (Smoldering Geist) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=27869 AND `DifficultyID`=0); -- 27869 (Wintergrasp Detection Unit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=30873 AND `DifficultyID`=0); -- 30873 (Flame Revenant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=256, `VerifiedBuild`=54762 WHERE (`Entry`=32624 AND `DifficultyID`=0); -- 32624 (Warsong Gulch Portal) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=256, `VerifiedBuild`=54762 WHERE (`Entry`=32618 AND `DifficultyID`=0); -- 32618 (Arathi Basin Portal) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=39172 AND `DifficultyID`=0); -- 39172 (Marshal Magruder) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=256, `VerifiedBuild`=54762 WHERE (`Entry`=32616 AND `DifficultyID`=0); -- 32616 (Alterac Valley Portal) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=30488 AND `DifficultyID`=0); -- 30488 (Travis Day) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=32294 AND `DifficultyID`=0); -- 32294 (Knight Dameron) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `StaticFlags1`=256, `VerifiedBuild`=54762 WHERE (`Entry`=32621 AND `DifficultyID`=0); -- 32621 (Eye of the Storm Portal) - Sessile
UPDATE `creature_template_difficulty` SET `ContentTuningID`=772, `VerifiedBuild`=54762 WHERE (`Entry`=30489 AND `DifficultyID`=0); -- 30489 (Morgan Day) - 
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=54762 WHERE (`Entry`=30499 AND `DifficultyID`=0);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry` IN (26606,27362,27363,30842,30845,30846,30847,30872,30873,30875,30876,30877,34300) AND `DifficultyID`=1);
UPDATE `creature_questitem` SET `VerifiedBuild`=54762 WHERE (`CreatureEntry`=34300 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=34300 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30872 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=30872 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30846 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=30846 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30876 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30877 AND `DifficultyID`=0 AND `Idx`=2) OR (`CreatureEntry`=30877 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=30877 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=26606 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=26606 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30842 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30875 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=27362 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30845 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=30845 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=27363 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30873 AND `DifficultyID`=0 AND `Idx`=1) OR (`CreatureEntry`=30873 AND `DifficultyID`=0 AND `Idx`=0) OR (`CreatureEntry`=30847 AND `DifficultyID`=0 AND `Idx`=0);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (26503, 13464, 27936, 26496, 26501, 26494, 17650, 31347, 27895, 13462, 13468, 16215, 18219, 4577, 39810, 25197, 29170, 29169, 24467, 19962, 24468, 29171, 24466, 21773, 25553, 27937, 27137, 27758, 13455, 27760, 25196, 13456, 13461, 20270, 18052, 17384, 13662, 24074, 24582, 25950, 5450, 27392, 21910, 27759, 24076, 27391, 27934, 27121, 24075, 24073, 23945, 25239, 8716, 24167, 24580, 13069, 24584, 21305, 24590, 25948, 17522, 25949, 1204, 25951, 25680);
UPDATE `creature_model_info` SET `BoundingRadius`=4.572795867919921875, `VerifiedBuild`=54762 WHERE `DisplayID` IN (27390, 26383);
UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (26502, 26495, 31346, 26484, 27166, 27894, 26499, 3122, 27941, 27940, 27938);
UPDATE `creature_template_model` SET `VerifiedBuild`=54762 WHERE (`Idx`=0 AND `CreatureID` IN (27852,30849,30847,30845,31109,30400,27363,32625,32617,31091,27450,26475,27369,31053,27362,31102,30842,30875,32620,31151,31106,30873,31054,19871,27358,30560,34300,32522,39173,107697,31842,31108,27869,32619,27355,31036,26606,31107,22515,30846,23472,27449,31153,27418,30872,30740,30869,26607,31101,30870,30877,32296,31051,30876,31841,30848,15214,30739,31052)) OR (`Idx`=3 AND `CreatureID` IN (30845,30400,34300,30740,30739)) OR (`Idx`=2 AND `CreatureID` IN (30845,30400,34300,30740,30739)) OR (`Idx`=1 AND `CreatureID` IN (30845,30400,27450,27369,19871,27358,34300,31842,27869,22515,23472,27449,27418,30740,31841,15214,30739));
UPDATE `creature_template_model` SET `VerifiedBuild`=54762 WHERE (`Idx`=0 AND `CreatureID` IN (32616,32618,30499,32621,39172,30488,32294,32624,30489)) OR (`Idx`=3 AND `CreatureID`=30499) OR (`Idx`=2 AND `CreatureID`=30499) OR (`Idx`=1 AND `CreatureID`=30499);

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=54762 WHERE `entry` IN (192030, 189981, 191857, 192032, 191875, 192031, 190171, 259114, 192029, 193126, 192028, 192951, 192048, 191810, 192235, 191871, 189980, 191805, 190172, 191803, 214528, 192819, 191804, 191870, 191802, 193125, 190763, 191801, 192488, 191869, 191874, 194323, 191799, 194012, 191873, 192501, 190378, 191872, 191797, 190356, 191370, 191800, 191796, 190175, 191855, 191795, 191798, 190377, 190176, 188695, 191808, 190375, 190374, 191806, 190371, 190357, 192033, 190373, 190369, 190221, 191133, 194162, 191807, 190370, 190220, 195013, 194356, 191809, 190376, 190372, 190358, 190219);

UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=8192 WHERE `entry`=214528; -- Instance Portal (Raid 10/25 No Heroic)
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=190176; -- Frost Lotus
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=191133; -- Titanium Vein
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=192488; -- Wintergrasp Horde Banner
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=190171; -- Lichbloom
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=190175; -- Frozen Herb
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=190172; -- Icethorn
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry`=190356; -- Shadowsight Tower
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry` IN (192030, 192031, 192032, 192028, 192033, 192029); -- Goblin Workshop
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=192501; -- Wintergrasp Alliance Banner
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry` IN (191798, 191797, 191805); -- Wintergrasp Wall
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry` IN (191799, 191796, 191795, 190376, 190220, 190374, 190372, 190219, 190370, 190371, 190369, 191806, 191807, 191808, 191804, 191809, 191802, 191803, 191800, 191801); -- Wintergrasp Fortress Wall
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry` IN (190378, 190377, 190221, 190373); -- Wintergrasp Fortress Tower
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry`=190375; -- Wintergrasp Fortress Gate
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry`=191810; -- Wintergrasp Fortress Door
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=190358; -- Flamewatch Tower
UPDATE `gameobject_template_addon` SET `faction`=35, `flags`=1048608 WHERE `entry`=190357; -- Winter's Edge Tower
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=192487; -- Wintergrasp Alliance Banner
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=192502; -- Wintergrasp Horde Banner

UPDATE `page_text` SET `Text`='Day 2147021:\nMy brothers are back!  It turns out they were sleeping in other closed off halls.\n\nI\'m a little mad that they left me alone to do all the watching, but I shared my shinier baubles with them anyway because I\'m tired of being alone and attacked all the time.\n                -ARCHAVON\n\nDay 2147060:\nThe violent little people have started attacking my brothers, which is sad.  They leave me alone mostly now though, which is not sad.\n\nI think they want the shiny baubles I gave away.  I feel guilty.\n                -ARCHAVON\n', `VerifiedBuild`=54762 WHERE `ID`=3603; -- 3603
UPDATE `page_text` SET `Text`='Day 2145866:\nThe little green people brought a lot of others, pointed them at each other, and then they all started fighting!\n\nI have trimmed my watching responsibilities back to the hall for safety, but I brought a lot of their baubles with me so that it can maybe be less boring this time.\n                -ARCHAVON\n\nDay 2146240:\nThings have gotten much worse.  I am not sure what the Makers want me to do.  I\'m trying to stay in my hall, but the violent people come in after me several times a day.  They take my baubles.\n                -ARCHAVON\n\n ', `VerifiedBuild`=54762 WHERE `ID`=3602; -- 3602
UPDATE `page_text` SET `Text`='Day 1051213:\nI invented a new game today too, it\'s called \"Kick the Revenant.\"  I made it from the front of the keep to the main road today.  Before next year, I\'m going to try to land it over the river.\n                -ARCHAVON\n\nDay 2145617:\nSome little green people came today.  I have added them to my watching responsibilities.\n                -ARCHAVON\n\nDay 2145657:\nThe little green people have built extra buildings here now.  More buildings seems good.  I think I will speak to them this week and thank them.\n                -ARCHAVON\n\nDay 2145666:\nI thanked one of the little green people today for the extra buildings.  He told me that he\'d be bringing more people for me to watch soon - lots of them.\n\nI\'m excited to have more things to watch.\n                -ARCHAVON\n', `VerifiedBuild`=54762 WHERE `ID`=3549; -- 3549
UPDATE `page_text` SET `Text`='Day 10500: \nThe halls are quiet.  Empty. \n\nI thought the Makers wanted me to watch the hall, but they never specifically said, \"Archavon, watch the hall...\" Maybe it\'s okay if I watch outside too?  It would probably be less boring outside.  It\'s decided - I am now responsible for watching the hall AND the outside.  I shall take on my new responsibility next month.\n                -ARCHAVON\n\nDay 20120:\nThe outside is much more open than the hall.  There are convenient cliffs and mountains bordering it.  I\'m now confident that the Makers meant for me to watch this too.  I hope they don\'t notice that I\'ve only been in the hall for the first decade.\n                -ARCHAVON\n', `VerifiedBuild`=54762 WHERE `ID`=3548; -- 3548
UPDATE `page_text` SET `Text`='<It appears Archavon has been keeping a journal. It appears to be written in multiple languages. A tally has been kept on the cover. >\n\nHorde:   \n  Keep Defended: $4024w\n  Keep Captured: $4022w\n\nAlliance:\n  Keep Defended: $4025w\n  Keep Captured: $4023w\n\nDay 10\nThe Makers are gone.  I have been left to watch.\n                -ARCHAVON\n', `VerifiedBuild`=54762 WHERE `ID`=3547; -- 3547
