DELETE FROM `creature` WHERE `guid`=60000000000025288;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (60000000000025288, 98229, 1481, 0, 0, '0', 0, 0, 0, -1, 0, 1, 1008.96, 2955.44, -10.5578, 2.75549, 300, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `ScriptName`='npc_mardum_ashtongue_mystic' WHERE  `entry`=99914;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE entry IN (
1416, 
2530, 
2530, 
2530, 
2530, 
2530, 
2530, 
6909, 
6909, 
6909, 
6909, 
6909, 
6909, 
6911, 
7999, 
7999, 
7999, 
7999, 
7999, 
10616, 
11056, 
11056, 
11056, 
11056, 
11056, 
11056, 
11056, 
11056, 
12238, 
15189, 
15189, 
15189, 
15190, 
15190, 
15190, 
15190, 
15402, 
15402, 
15402, 
15402, 
15958, 
16217, 
17015, 
17046, 
17046, 
17375, 
17375, 
17445, 
18585, 
18585, 
18585, 
18585, 
18585, 
18585, 
18586, 
18586, 
18586, 
18586, 
18586, 
18586, 
18586, 
22307, 
22307, 
23704, 
23704, 
25084, 
25084, 
25084, 
25084, 
25084, 
25084, 
25380, 
25380, 
25381, 
25636, 
25967, 
26171, 
26185, 
26185, 
26185, 
26189, 
27106, 
27106, 
27106, 
27106, 
27106, 
27107, 
27107, 
27107, 
27107, 
27107, 
27108, 
27108, 
27108, 
27108, 
27110, 
27110, 
27110, 
27110, 
27110, 
27801, 
27801, 
28315, 
28315, 
28315, 
28315, 
28317, 
28317, 
28317, 
28317, 
28604, 
28604, 
28604, 
28604, 
28604, 
28889, 
28889, 
28897, 
28897, 
28897, 
28897, 
28897, 
28907, 
30222, 
30222, 
32784, 
42131, 
42131, 
42131, 
42131, 
42928, 
42928, 
42928, 
45715, 
45715, 
46603, 
46603, 
47715, 
47715, 
100556, 
100556, 
156943, 
156943, 
157238, 
157238, 
157238, 
157450, 
157451, 
157467, 
159308, 
159308, 
159417, 
159417, 
159417, 
159417, 
161286, 
162716, 
162717, 
162718, 
163882, 
165909, 
168310, 
168361, 
168361, 
168550, 
168572, 
168572, 
168574, 
168578, 
168578, 
169696, 
169696);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE entry IN (
185932, 
185932, 
185932, 
185936, 
185936, 
185936, 
185937, 
185937, 
185937, 
185938, 
185938, 
185938, 
187267, 
212969, 
244989, 
271616, 
273454, 
273791, 
273791, 
293552);

replace into `zone_scripts` (`zoneId`, `scriptname`) values
('12951','zone_allied_dk'),
('12952','zone_allied_dk');

REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37098, 'spell_rain_of_bones'),
(245124, 'spell_garothi_cannon_chooser');

REPLACE INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1712, 0, 'instance_antorus_the_burning_throne', 0);

REPLACE INTO creature_template (entry, name, femaleName, subname, minlevel, maxlevel, faction, npcflag, scriptname) VALUES (1000000, "Thordekk", "", "Experience rate selector", 110, 110, 35, 1, "npc_rate_xp_modifier");

UPDATE `creature_template` SET `ScriptName`='npc_transmorpher_beacon' WHERE `entry`='149596';

UPDATE `creature_template` SET `ScriptName` = 'npc_curator_astral_flare' WHERE `entry` = 17096;
UPDATE `creature_template` SET `ScriptName` = 'npc_curator_astral_flare' WHERE `entry` = 19781;
UPDATE `creature_template` SET `ScriptName` = 'npc_curator_astral_flare' WHERE `entry` = 19782;
UPDATE `creature_template` SET `ScriptName` = 'npc_curator_astral_flare' WHERE `entry` = 19783;
UPDATE `creature_template` SET `ScriptName`='npc_riathia_silverstar' WHERE  `entry`=152238;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43878 ;
UPDATE creature_template SET lootid=43878 WHERE entry = 43878;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43873 ;
UPDATE creature_template SET lootid=43873 WHERE entry = 43873;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43875 ;
UPDATE creature_template SET lootid=43875 WHERE entry = 43875;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 44577 ;
UPDATE creature_template SET lootid=44577 WHERE entry = 44577;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43612 ;
UPDATE creature_template SET lootid=43612 WHERE entry = 43612;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 49045 ;
UPDATE creature_template SET lootid=49045 WHERE entry = 49045;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43614 ;
UPDATE creature_template SET lootid=43614 WHERE entry = 43614;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 44819 ;
UPDATE creature_template SET lootid=44819 WHERE entry = 44819;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39425 ;
UPDATE creature_template SET lootid=39425 WHERE entry = 39425;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39428 ;
UPDATE creature_template SET lootid=39428 WHERE entry = 39428;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39788 ;
UPDATE creature_template SET lootid=39788 WHERE entry = 39788;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39587 ;
UPDATE creature_template SET lootid=39587 WHERE entry = 39587;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39731 ;
UPDATE creature_template SET lootid=39731 WHERE entry = 39731;


UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39732 ;
UPDATE creature_template SET lootid=39732 WHERE entry = 39732;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39378 ;
UPDATE creature_template SET lootid=39378 WHERE entry = 39378;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 23578 ;
UPDATE creature_template SET lootid=23578 WHERE entry = 23578;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52155 ;
UPDATE creature_template SET lootid=52155 WHERE entry = 52155;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52151 ;
UPDATE creature_template SET lootid=52151 WHERE entry = 52151;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52271 ;
UPDATE creature_template SET lootid=52271 WHERE entry = 52271;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52059 ;
UPDATE creature_template SET lootid=52059 WHERE entry = 52059;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52053 ;
UPDATE creature_template SET lootid=52053 WHERE entry = 52053;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52148 ;
UPDATE creature_template SET lootid=52148 WHERE entry = 52148;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 162729 ;
UPDATE creature_template SET lootid=162729 WHERE entry = 162729;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163121 ;
UPDATE creature_template SET lootid=163121 WHERE entry = 163121;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165138 ;
UPDATE creature_template SET lootid=165138 WHERE entry = 165138;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 166302 ;
UPDATE creature_template SET lootid=166302 WHERE entry = 166302;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165137 ;
UPDATE creature_template SET lootid=165137 WHERE entry = 165137;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163122 ;
UPDATE creature_template SET lootid=163122 WHERE entry = 163122;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163618 ;
UPDATE creature_template SET lootid=163618 WHERE entry = 163618;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165919 ;
UPDATE creature_template SET lootid=165919 WHERE entry = 165919;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165222 ;
UPDATE creature_template SET lootid=165222 WHERE entry = 165222;


UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163128 ;
UPDATE creature_template SET lootid=163128 WHERE entry = 163128;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165824 ;
UPDATE creature_template SET lootid=165824 WHERE entry = 165824;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 165197 ;
UPDATE creature_template SET lootid=165197 WHERE entry = 165197;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163126 ;
UPDATE creature_template SET lootid=163126 WHERE entry = 163126;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 163157 ;
UPDATE creature_template SET lootid=163157 WHERE entry = 163157;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43878 ;
UPDATE creature_template SET lootid=43878 WHERE entry = 43878;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43873 ;
UPDATE creature_template SET lootid=43873 WHERE entry = 43873;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43875 ;
UPDATE creature_template SET lootid=43875 WHERE entry = 43875;
UPDATE creature_loot_template SET Chance = 7 WHERE entry = 44577 ;
UPDATE creature_template SET lootid=44577 WHERE entry = 44577;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43612 ;
UPDATE creature_template SET lootid=43612 WHERE entry = 43612;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 49045 ;
UPDATE creature_template SET lootid=49045 WHERE entry = 49045;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43614 ;
UPDATE creature_template SET lootid=43614 WHERE entry = 43614;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 44819 ;
UPDATE creature_template SET lootid=44819 WHERE entry = 44819;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39425 ;
UPDATE creature_template SET lootid=39425 WHERE entry = 39425;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39428 ;
UPDATE creature_template SET lootid=39428 WHERE entry = 39428;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39788 ;
UPDATE creature_template SET lootid=39788 WHERE entry = 39788;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39587 ;
UPDATE creature_template SET lootid=39587 WHERE entry = 39587;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39731 ;
UPDATE creature_template SET lootid=39731 WHERE entry = 39731;


UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39732 ;
UPDATE creature_template SET lootid=39732 WHERE entry = 39732;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 39378 ;
UPDATE creature_template SET lootid=39378 WHERE entry = 39378;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 23578 ;
UPDATE creature_template SET lootid=23578 WHERE entry = 23578;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52155 ;
UPDATE creature_template SET lootid=52155 WHERE entry = 52155;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52151 ;
UPDATE creature_template SET lootid=52151 WHERE entry = 52151;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52271 ;
UPDATE creature_template SET lootid=52271 WHERE entry = 52271;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52059 ;
UPDATE creature_template SET lootid=52059 WHERE entry = 52059;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52053 ;
UPDATE creature_template SET lootid=52053 WHERE entry = 52053;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 52148 ;
UPDATE creature_template SET lootid=52148 WHERE entry = 52148;

UPDATE `creature` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1712 AND `spawnDifficulties` = "1, 14, 15, 16, 17";
UPDATE `creature` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1648 AND `spawnDifficulties` = "0, 14, 15, 16, 17";
UPDATE `gameobject` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1712 AND `spawnDifficulties` = "1, 14, 15, 16, 17";
UPDATE `gameobject` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1648 AND `spawnDifficulties` = "0, 14, 15, 16, 17";

UPDATE `creature_template` SET `KillCredit2` = 0 WHERE `KillCredit2` = 173429;

UPDATE `gameobject` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1648 AND `spawnDifficulties` = "0, 14, 15, 16, 17";

UPDATE `creature_template` SET `KillCredit2` = 0 WHERE `KillCredit2` = 173429;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43438 ;
UPDATE creature_template SET lootid=43438 WHERE entry = 43438;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 43214 ;
UPDATE creature_template SET lootid=43214 WHERE entry = 43214;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 42188 ;
UPDATE creature_template SET lootid=42188 WHERE entry = 42188;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 42333 ;
UPDATE creature_template SET lootid=42333 WHERE entry = 42333;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 34797 ;
UPDATE creature_template SET lootid=34797 WHERE entry = 34797;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 34780 ;
UPDATE creature_template SET lootid=34780 WHERE entry = 34780;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 34497 ;
UPDATE creature_template SET lootid=34780 WHERE entry = 34780;

UPDATE creature_loot_template SET Chance = 7 WHERE entry = 34564 ;
UPDATE creature_template SET lootid=34780 WHERE entry = 34780;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150154','154899','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150154','159173','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150154','159186','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150154','158859','7');
UPDATE creature_template SET lootid=150154 WHERE entry = 150154;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155094','159161','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155094','159520','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155094','159188','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155094','159820','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155094','169145','22');
UPDATE creature_template SET lootid=155094 WHERE entry = 155094;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155090','166846','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155090','159174','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155090','170212','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155090','159511','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('155090','159163','9');
UPDATE creature_template SET lootid=155090 WHERE entry = 155090;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','168756','2');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','152577','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','159188','14');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','159168','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','154804','9');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','166846','13');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','154783','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','160925','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','159511','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150292','159593','9');
UPDATE creature_template SET lootid=150292 WHERE entry = 150292;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','168756','2');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','152577','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','159188','14');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','159168','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','154804','9');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','166846','13');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','154783','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','160925','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','159511','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150169','159593','9');
UPDATE creature_template SET lootid=150169 WHERE entry = 150169;

replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','168756','2');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','152577','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','159188','14');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','159168','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','154804','9');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','166846','13');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','154783','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','160925','15');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','159511','7');
replace into `creature_loot_template` (`entry`, `item`, `chance` ) values('150168','159593','9');
UPDATE creature_template SET lootid=150168 WHERE entry = 150168;

UPDATE creature_template SET lootid=46264 WHERE entry = 46264;
UPDATE creature_template SET lootid=59150 WHERE entry = 59150;
UPDATE creature_template SET lootid=17991 WHERE entry = 17991;
UPDATE creature_template SET lootid=17942  WHERE entry = 17942 ;
UPDATE creature_template SET lootid=18341  WHERE entry = 18341 ;
UPDATE creature_template SET lootid=18343  WHERE entry = 18343 ;
UPDATE creature_template SET lootid=131318  WHERE entry = 131318 ;
UPDATE creature_template SET lootid=131817  WHERE entry = 131817 ;
UPDATE creature_template SET lootid=131383  WHERE entry = 131383 ;
UPDATE creature_template SET lootid=133007  WHERE entry = 133007 ;
UPDATE creature_template SET lootid=164267 WHERE entry = 164267 ;

UPDATE creature_template SET lootid=170850 WHERE entry = 170850;
UPDATE creature_template SET lootid=170838 WHERE entry = 170838;
UPDATE creature_template SET lootid=164510 WHERE entry = 164510;
UPDATE creature_template SET lootid=167994 WHERE entry = 167994;
UPDATE creature_template SET lootid=169875 WHERE entry = 169875;
UPDATE creature_template SET lootid=167998 WHERE entry = 167998;
UPDATE creature_template SET lootid=170690 WHERE entry = 170690;
UPDATE creature_template SET lootid=174210 WHERE entry = 174210;
UPDATE creature_template SET lootid=169927 WHERE entry = 169927;
UPDATE creature_template SET lootid=174773 WHERE entry = 174773;
UPDATE creature_template SET lootid=163086 WHERE entry = 163086;
UPDATE creature_template SET lootid=162744 WHERE entry = 162744;
UPDATE creature_template SET lootid=167536 WHERE entry = 167536;
UPDATE creature_template SET lootid=167533 WHERE entry = 167533;
UPDATE creature_template SET lootid=164506 WHERE entry = 164506;
UPDATE creature_template SET lootid=162317 WHERE entry = 162317;
UPDATE creature_template SET lootid=164267 WHERE entry = 164267;

UPDATE creature_template SET lootid=71483 WHERE entry = 71483;
UPDATE creature_template SET lootid=58778 WHERE entry = 58778;
UPDATE creature_template SET lootid=26401 WHERE entry = 26401;
UPDATE creature_template SET lootid=63976 WHERE entry = 63976;
UPDATE creature_template SET lootid=50822 WHERE entry = 50822;

UPDATE creature_template SET lootid=65862 WHERE entry = 65862;
UPDATE creature_template SET lootid=64403 WHERE entry = 64403;
UPDATE creature_template SET lootid=64706 WHERE entry = 64706;
UPDATE creature_template SET lootid=58992 WHERE entry = 58992;
UPDATE creature_template SET lootid=64614 WHERE entry = 64614;
UPDATE creature_template SET lootid=64029 WHERE entry = 64029;
UPDATE creature_template SET lootid=63996 WHERE entry = 63996;
UPDATE creature_template SET lootid=64122 WHERE entry = 64122;
UPDATE creature_template SET lootid=67133 WHERE entry = 67133;

UPDATE creature_template SET lootid=110570 WHERE entry = 110570;
UPDATE creature_template SET lootid=58928 WHERE entry = 58928;
UPDATE creature_template SET lootid=62596 WHERE entry = 62596;
UPDATE creature_template SET lootid=64173 WHERE entry = 64173;
UPDATE creature_template SET lootid=65735 WHERE entry = 65735;
UPDATE creature_template SET lootid=64158 WHERE entry = 64158;
UPDATE creature_template SET lootid=64588 WHERE entry = 64588;
UPDATE creature_template SET lootid=64615 WHERE entry = 64615;
UPDATE creature_template SET lootid=64557 WHERE entry = 64557;

UPDATE creature_template SET lootid=163457 WHERE entry = 163457;
UPDATE creature_template SET lootid=163459 WHERE entry = 163459;
UPDATE creature_template SET lootid=168318 WHERE entry = 168318;
UPDATE creature_template SET lootid=163458 WHERE entry = 163458;
UPDATE creature_template SET lootid=163506 WHERE entry = 163506;
UPDATE creature_template SET lootid=163524 WHERE entry = 163524;
UPDATE creature_template SET lootid=173729 WHERE entry = 173729;
UPDATE creature_template SET lootid=166411 WHERE entry = 166411;
UPDATE creature_template SET lootid=168718 WHERE entry = 168718;

UPDATE creature_template SET lootid=168717 WHERE entry = 168717;
UPDATE creature_template SET lootid=163589 WHERE entry = 163589;
UPDATE creature_template SET lootid=163077 WHERE entry = 163077;
UPDATE creature_template SET lootid=168845 WHERE entry = 168845;
UPDATE creature_template SET lootid=168843 WHERE entry = 168843;

UPDATE creature_template SET lootid=168844 WHERE entry = 168844;
UPDATE creature_template SET lootid=162061 WHERE entry = 162061;

UPDATE creature_template SET lootid=171211 WHERE entry = 171211;
UPDATE creature_template SET lootid=171014 WHERE entry = 171014;

UPDATE creature_template SET lootid=171010 WHERE entry = 171010;
UPDATE creature_template SET lootid=170623 WHERE entry = 170623;
UPDATE creature_template SET lootid=171011 WHERE entry = 171011;
UPDATE creature_template SET lootid=163460 WHERE entry = 163460;
UPDATE creature_template SET lootid=171013 WHERE entry = 171013;

UPDATE creature_template SET faction=14 WHERE entry = 170838;

SET @ID = 14377;
SET @Qtype = 0;


-- ======== QUEST TYPE LIST ========
-- 0  Quest is enabled, but it is auto-completed when accepted; this skips quest objectives and quest details.
-- 1  Quest is disabled (not yet implemented in the core).
-- 2  Quest is enabled (does not auto-complete).
-- 3  Quest is a World Quest.
-- =================================


-- Do not edit below this line
UPDATE quest_template SET QuestType = @Qtype WHERE  ID = @ID;

DELETE FROM `spell_proc` WHERE `SpellId` IN (135286);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(135286, 0, 7, 0x800, 0x0, 0x0, 0x0, 0x10, 1, 2, 0x403, 0x10, 0, 0, 0, 0, 0);

UPDATE `quest_offer_reward` SET `RewardText` = 'Will you lay the candle down and call the Headless Horseman from his doomed rest?' WHERE `ID` = 11405;
UPDATE `quest_request_items` SET `CompletionText` = 'This dirt has been recently disturbed. Earthworms lie in the topsoil, squirming to escape the dark depths beneath them.' WHERE `ID` = 11405;

UPDATE `gameobject_template` SET `ScriptName`='go_blackened_urn' WHERE `entry`=194092;






