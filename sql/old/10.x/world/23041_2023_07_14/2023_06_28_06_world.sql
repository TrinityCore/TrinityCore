-- Creature templates
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=22820; -- Seer Olum
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=22486; -- Greater Earthbind Totem
UPDATE `creature_template` SET `speed_walk`=1.799999952316284179, `speed_run`=2.228571414947509765, `unit_flags`=32832, `unit_flags3`=524288 WHERE `entry`=22352; -- Colossus Rager
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=2099200, `unit_flags3`=524289 WHERE `entry`=22335; -- Mushrom Spell Effect
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags3`=524288 WHERE `entry`=22250; -- Rancid Mushroom
UPDATE `creature_template` SET `speed_run`=1.428571462631225585, `unit_flags`=32768 WHERE `entry`=22238; -- Serpentshrine Tidecaller
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=22236; -- Water Elemental Totem
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `BaseAttackTime`=2400, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=22119; -- Fathom Lurker
UPDATE `creature_template` SET `speed_walk`=0.400000005960464477, `speed_run`=0.428571432828903198, `unit_flags3`=524288 WHERE `entry`=22104; -- Cyclone (Karathress)
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1, `speed_run`=1, `unit_flags2`=0 WHERE `entry`=22091; -- Spitfire Totem
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=22056; -- Coilfang Strider
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=22055; -- Coilfang Elite
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=22036; -- Tainted Spawn of Hydross
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=524288 WHERE `entry`=22009; -- Tainted Elemental
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21966; -- Fathom-Guard Sharkkis
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21965; -- Fathom-Guard Tidalvess
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21964; -- Fathom-Guard Caribdis
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2097152, `unit_flags3`=524289 WHERE `entry`=21958; -- Enchanted Elemental
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=21934; -- Hydross Cleansing Field Helper
UPDATE `creature_template` SET `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=21933; -- Hydross Beam Helper
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21216; -- Hydross the Unstable
UPDATE `creature_template` SET `speed_run`=12 / 7.0, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2099200 WHERE `entry`=21932; -- Hydross the Unstable
UPDATE `creature_template` SET `speed_run`=2.142857074737548828, `unit_flags`=33587968, `unit_flags2`=2099200, `unit_flags3`=524289 WHERE `entry`=21812; -- Phantom Leotheras
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21806; -- Greyheart Spellbinder
UPDATE `creature_template` SET `speed_run`=2.142857074737548828, `BaseAttackTime`=500, `unit_flags`=32832, `unit_flags3`=524288 WHERE `entry`=21508; -- Coilfang Frenzy
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32768, `unit_flags3`=524288 WHERE `entry` IN (21253,21260); -- Tainted Water Elemental
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21251; -- Underbog Colossus
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21228; -- Tidewalker Hydromancer
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21227; -- Tidewalker Harpooner
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21226; -- Tidewalker Shaman
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21225; -- Tidewalker Warrior
UPDATE `creature_template` SET `speed_walk`=1.60000002384185791, `speed_run`=1.714285731315612792, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21224; -- Tidewalker Depth-Seer
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=21215; -- Leotheras the Blind
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=21214; -- Fathom-Lord Karathress
UPDATE `creature_template` SET `speed_run`=2.142857074737548828, `BaseAttackTime`=1600, `unit_flags`=16448, `unit_flags2`=2099200 WHERE `entry`=21213; -- Morogrim Tidewalker

-- Difficulty
UPDATE `creature_template_difficulty` SET `DifficultyID`=4 WHERE (`DifficultyID`=2 AND `Entry` IN (21260,21932,22820,22486,22352,22335,22250,22238,22236,22119,22104,22091,22057,22056,22055,22036,22009,21987,21966,21965,21964,21958,21934,21933,21216,21863,21812,21806,21508,21339,21301,21299,21298,21263,21253,21251,21246,21232,21231,21230,21229,21228,21227,21226,21225,21224,21221,21220,21218,21217,21215,21214,21213,21212));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=43, `VerifiedBuild`=49890 WHERE (`Entry`=22820 AND `DifficultyID`=4);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1011, `VerifiedBuild`=49890 WHERE (`DifficultyID`=4 AND `Entry` IN (22486,22352,22335,22250,22236,22091,22057,22056,22055,22009,21987,21958,21934,21933,21863,21508));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1011, `VerifiedBuild`=49890 WHERE (`DifficultyID`=4 AND `Entry` IN (22238,22119,22036,21966,21965,21964,21806,21339,21301,21299,21298,21263,21260,21253,21246,21232,21231,21230,21229,21228,21227,21226,21225,21224,21221,21220,21218));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1011, `VerifiedBuild`=49890 WHERE (`DifficultyID`=4 AND `Entry` IN (22104,21217,21216,21812,21215,21214,21213,21212,21932));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=1011, `VerifiedBuild`=49890 WHERE (`Entry`=21251 AND `DifficultyID`=4);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=49890 WHERE `DisplayID` IN (16925, 16997, 862, 19075, 17754, 20231, 18194, 20772, 13069, 20672, 15880, 20609, 1004, 20641, 5564, 11172, 18030, 5286, 391, 5243, 20514, 11686);
UPDATE `creature_model_info` SET `BoundingRadius`=0.994680166244506835, `CombatReach`=0, `VerifiedBuild`=49890 WHERE `DisplayID`=21101;
UPDATE `creature_model_info` SET `BoundingRadius`=2.473487615585327148, `VerifiedBuild`=49890 WHERE `DisplayID` IN (20671, 20205, 20470, 20201);
UPDATE `creature_model_info` SET `BoundingRadius`=1.657800197601318359, `CombatReach`=0, `VerifiedBuild`=49890 WHERE `DisplayID`=20670;
UPDATE `creature_model_info` SET `BoundingRadius`=1.92270064353942871, `VerifiedBuild`=49890 WHERE `DisplayID`=20560;
UPDATE `creature_model_info` SET `BoundingRadius`=4.5, `CombatReach`=4.5, `VerifiedBuild`=49890 WHERE `DisplayID`=20479;
UPDATE `creature_model_info` SET `BoundingRadius`=1.243350148200988769, `CombatReach`=0, `VerifiedBuild`=49890 WHERE `DisplayID` IN (20638, 20639, 20637, 20636, 20635, 20640);
UPDATE `creature_model_info` SET `BoundingRadius`=1.276379585266113281, `VerifiedBuild`=49890 WHERE `DisplayID`=20642;
UPDATE `creature_model_info` SET `BoundingRadius`=4.015157699584960937, `VerifiedBuild`=49890 WHERE `DisplayID`=20812;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `VerifiedBuild`=49890 WHERE `DisplayID` IN (1773, 5293);
UPDATE `creature_model_info` SET `BoundingRadius`=1.312847495079040527, `VerifiedBuild`=49890 WHERE `DisplayID`=20212;
UPDATE `creature_model_info` SET `BoundingRadius`=2.748319625854492187, `VerifiedBuild`=49890 WHERE `DisplayID`=20200;
UPDATE `creature_model_info` SET `BoundingRadius`=3.84764719009399414, `VerifiedBuild`=49890 WHERE `DisplayID`=20662;
UPDATE `creature_model_info` SET `BoundingRadius`=6.315000057220458984, `CombatReach`=6, `VerifiedBuild`=49890 WHERE `DisplayID`=20739;
UPDATE `creature_model_info` SET `BoundingRadius`=3.004086256027221679, `CombatReach`=3, `VerifiedBuild`=49890 WHERE `DisplayID`=20748;
UPDATE `creature_template_model` SET `VerifiedBuild`=49890 WHERE (`Idx`=0 AND `CreatureID` IN (22335,22091,21213,21806,21260,22009,21226,21934,22238,22820,21214,21232,21298,21220,21231,21863,21230,56921,22119,71018,22057,28363,47654,21508,21215,21301,40165,22236,21966,356,21299,22036,21339,71486,22250,21221,25064,21251,305,22104,21227,21932,21933,21229,14505,22486,21252,54741,22056,21965,21812,18379,21216,21246,65011,40625,22055,21964,21225,21263,64993,22352,21253,35362,21212,21228,21218,304,59072,15384,21224,53488,21958,21987,68288)) OR (`Idx`=1 AND `CreatureID` IN (21934,22057,40165,21933,21252,15384,53488,21987));

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=49890 WHERE `entry` IN (185114, 183407, 183490, 184917, 185117, 184574, 184918, 184205, 185052, 184572, 184914, 184920, 184699, 185116, 185118, 184698, 184204, 185053, 184915, 185051, 185115, 184913, 184919, 184916, 184697, 184571, 184203, 184921, 184573, 184570, 184569, 184568, 185054);
UPDATE `gameobject_template` SET `ContentTuningId`=1011, `VerifiedBuild`=49890 WHERE `entry`=185474; -- Cage
UPDATE `gameobject_template` SET `ContentTuningId`=1011, `VerifiedBuild`=49890 WHERE `entry`=184956; -- Strange Pool
UPDATE `gameobject_template` SET `ContentTuningId`=234, `VerifiedBuild`=49890 WHERE `entry`=185199; -- Serpentshrine Mushroom
