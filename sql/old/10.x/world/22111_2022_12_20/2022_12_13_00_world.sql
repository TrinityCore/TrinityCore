-- smart_scripts startup fixes

-- Missing gameobject_templates
DELETE FROM `gameobject_template` WHERE `entry` IN (19901, 20352, 61927, 113791, 175329, 175330, 175331);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(19901, 10, 465, 'Circle of Imprisonment', '', '', '', 1, 93, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 11723),
(20352, 10, 343, 'Circle of Imprisonment', '', '', '', 1, 93, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 12340),
(61927, 8, 200, 'Bonfire', '', '', '', 0.75, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 12340),
(113791, 2, 602, 'Brazier of Everfount', '', '', '', 1, 0, 1630, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 12340),
(175329, 3, 3613, 'Blackwood Nut Stores', '', '', '', 1.1, 93, 12811, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(175330, 3, 3613, 'Blackwood Fruit Stores', '', '', '', 0.72, 93, 12810, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 12340),
(175331, 3, 3613, 'Blackwood Grain Stores', '', '', '', 0.91, 93, 12812, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 12340);

-- Creature/Gameobject is not using SmartAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (503, 1855, 2010, 2498, 2817, 2984, 3879, 3893, 3898, 3899, 3900, 4484, 4488, 4530, 4531, 4630, 4781, 4789, 5353, 6142, 6221, 6626, 7411, 7774, 7917, 7997, 8417, 8421, 10216, 10605, 10717, 10758, 10926, 11798, 11800, 12319, 12997, 13716, 14523, 15203, 15204, 15206, 15207, 15208, 15209, 15211, 15212, 15220, 15305, 15307, 15491, 19671, 19672, 23580, 23941);
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=4781;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=148498;

-- Creature uses ScriptName or deprecated script
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (34697, 38978);

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=474 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5976 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=10261 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=10263 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=11563 AND `id` IN (2, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=38981 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=39965 AND `id`=11;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=40080 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=50749 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=64267 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=64913 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (3143, 6353, 10445, 34697, 38978, 44367, 44906, 44954, 44966, 44987, 61411, 173254);
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=204019 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=4229100 AND `id` IN (1, 4, 5);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=4294500 AND `id` IN (1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=5458704;

-- Creature guid does not exist
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-19361, -13579, -19402, -19412, -371666, -371675, -371684);

-- Unused event_type or action_type
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=30, `event_param5`=40, `comment`='Riverpaw Mystic - Friendly At 0-30% Health - Cast ''Healing Wave''' WHERE `source_type`=0 AND `entryorguid`=453 AND `id`=3;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Ambermill Watcher - Friendly At 0-40% Health - Cast ''Renew''' WHERE `source_type`=0 AND `entryorguid`=1888 AND `id`=3;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Boulderfist Shaman - Friendly At 0-40% Health - Cast ''Healing Wave''' WHERE `source_type`=0 AND `entryorguid`=2570 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Medic Tamberlyn - Friendly At 0-40% Health - Cast ''First Aid''' WHERE `source_type`=0 AND `entryorguid`=5199 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Medic Helaina - Friendly At 0-40% Health - Cast ''First Aid''' WHERE `source_type`=0 AND `entryorguid`=5200 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Deadwood Gardener - Friendly At 0-40% Health - Cast ''Rejuvenation''' WHERE `source_type`=0 AND `entryorguid`=7154 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Scarlet Warder - Friendly At 0-40% Health - Cast ''Holy Light''' WHERE `source_type`=0 AND `entryorguid`=9447 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Scarlet Curate - Friendly At 0-40% Health - Cast ''Renew''' WHERE `source_type`=0 AND `entryorguid`=9450 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Shatterspear Priestess - Friendly At 0-40% Health - Cast ''Heal''' WHERE `source_type`=0 AND `entryorguid`=32855 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Blackmaw Shaman - Friendly At 0-40% Health - Cast ''Healing Wave''' WHERE `source_type`=0 AND `entryorguid`=36012 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Deepfin Seer - Friendly At 0-40% Health - Cast ''Healing Touch''' WHERE `source_type`=0 AND `entryorguid`=41592 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Idra''kess Prophet - Friendly At 0-40% Health - Cast ''Greater Heal''' WHERE `source_type`=0 AND `entryorguid`=41608 AND `id`=4;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Azsh''ir Abyss Priestess - Friendly At 0-40% Health - Cast ''Greater Heal''' WHERE `source_type`=0 AND `entryorguid`=42453 AND `id`=4;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40, `comment`='Marshtide Cleric - Friendly At 0-40% Health - Cast ''Heal''' WHERE `source_type`=0 AND `entryorguid`=46841 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=74, `event_param1`=0, `event_param2`=40, `event_param5`=40 WHERE `source_type`=0 AND `entryorguid` IN (61239, 61339) AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=0, `event_param2`=0, `target_type`=2, `comment`='Gosh-Haldir - In Combat - Cast ''Fatal Bite''' WHERE `source_type`=0 AND `entryorguid`=2476 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=0, `event_param2`=0, `target_type`=2, `comment`='Ruuzlu - In Combat - Cast ''Execute''' WHERE `source_type`=0 AND `entryorguid`=7797 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=0, `event_param2`=0, `target_type`=2, `comment`='Sand Slitherer - In Combat - Cast ''Fatal Bite''' WHERE `source_type`=0 AND `entryorguid`=44595 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=0, `event_param3`=6000, `event_param4`=9000 WHERE `event_type`=67;

UPDATE `smart_scripts` SET `action_type`=11, `comment`='Rattlecage Skeleton - In Combat - Cast ''Battle Shout''' WHERE `source_type`=0 AND `entryorguid`=-325170 AND `id`=2;
UPDATE `smart_scripts` SET `action_type`=11, `comment`='Saltspittle Puddlejumper - On Reset - Cast ''Battle Stance'' (No Repeat)' WHERE `source_type`=0 AND `entryorguid`=3737 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `target_type`=1, `target_param1`=0, `target_param3`=0, `comment`='Conflagration - Out of Combat - Cast ''Burning Heat''' WHERE `source_type`=0 AND `entryorguid`=39994 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `comment`='Sand Vortex - Out of Combat - Cast ''Sand Vortex''' WHERE `source_type`=0 AND `entryorguid`=41730 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `comment`='Valdred - On Just summoned - Cast Kneel' WHERE `source_type`=0 AND `entryorguid`=49231 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `comment`='Risen Dead - On Script - Cast ''Enrage''' WHERE `source_type`=9 AND `entryorguid`=5037400 AND `id`=3;
UPDATE `smart_scripts` SET `action_type`=133, `target_type`=1, `target_param1`=0, `target_param2`=0, `target_param3`=0 WHERE `source_type`=0 AND `entryorguid`=17826 AND `id`=13;
UPDATE `smart_scripts` SET `action_type`=133, `action_param2`=48191, `target_type`=1, `target_param1`=0, `target_param2`=0, `target_param3`=0 WHERE `source_type`=0 AND `entryorguid`=18471 AND `id`=26;
UPDATE `smart_scripts` SET `action_type`=41, `action_param1`=1000, `action_param2`=1 WHERE `source_type`=0 AND `entryorguid` IN (44614, 44794) AND `id`=7;
UPDATE `smart_scripts` SET `action_type`=146, `action_param1`=1, `comment`='Injured Stormwind Infantry - On Spellhit - Set uninteractible' WHERE `source_type`=0 AND `entryorguid`=50047 AND `id`=5;

-- Non-existent spell entry
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (683, 787, 819, 909, 1062, 1183, 1679, 2030, 2170, 2742, 2744, 3811, 3939, 3940, 4025, 4036, 4119, 4151, 4278, 4682, 4798, 4850, 5333, 5682, 6047, 7727, 12320, 13219, 14832);

UPDATE `smart_scripts` SET `action_param1`=23381 WHERE `source_type`=0 AND `entryorguid` IN (-251442, -251439, -251437, -251436, -251430, -251426, -251425) AND `id`=5;
UPDATE `smart_scripts` SET `action_param1`=11971 WHERE `source_type`=0 AND `entryorguid`=568 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=75930, `comment`='Panther - In Combat - Cast ''Mangle''' WHERE `source_type`=0 AND `entryorguid`=736 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=11972 WHERE `source_type`=0 AND `entryorguid`=1540 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=12550 WHERE `source_type`=0 AND `entryorguid`=1544 AND `id`=2;
UPDATE `smart_scripts` SET `event_param1`=12550, `action_param1`=12550 WHERE `source_type`=0 AND `entryorguid`=1544 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=11986 WHERE `source_type`=0 AND `entryorguid`=2640 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=11986 WHERE `source_type`=0 AND `entryorguid`=2718 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=23381 WHERE `source_type`=0 AND `entryorguid`=3672 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=23381 WHERE `source_type`=0 AND `entryorguid`=3840 AND `id`=5;
UPDATE `smart_scripts` SET `action_param1`=20815 WHERE `source_type`=0 AND `entryorguid`=4289 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=20296 WHERE `source_type`=0 AND `entryorguid`=4289 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=32749 WHERE `source_type`=0 AND `entryorguid`=4300 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=34517 WHERE `source_type`=0 AND `entryorguid`=4300 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=12039 WHERE `source_type`=0 AND `entryorguid`=4303 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=19514 WHERE `source_type`=0 AND `entryorguid`=5236 AND `id` IN (1, 2, 3);
UPDATE `smart_scripts` SET `action_param1`=79924 WHERE `source_type`=0 AND `entryorguid`=5236 AND `id`=4;
UPDATE `smart_scripts` SET `action_param1`=11970 WHERE `source_type`=0 AND `entryorguid`=6226 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=15732 WHERE `source_type`=0 AND `entryorguid`=10425 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=3, `event_type`=2, `event_param2`=10 WHERE `source_type`=0 AND `entryorguid`=15277 AND `id`=7;
UPDATE `smart_scripts` SET `action_param1`=16827 WHERE `source_type`=0 AND `entryorguid`=16348 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=34945 WHERE `source_type`=0 AND `entryorguid`=23368 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=17139 WHERE `source_type`=0 AND `entryorguid`=23368 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=53570 WHERE `source_type`=0 AND `entryorguid`=28490 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=75417 WHERE `source_type`=0 AND `entryorguid`=40419 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=91677 WHERE `source_type`=0 AND `entryorguid`=47138 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=503 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (683, 819, 1028) AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=787 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=909 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=938 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=940 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=942 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1029 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1036 AND `id` IN (1, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1038 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1060 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1062 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1175 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1183 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1679 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1717 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1854 AND `id` IN (1, 4);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=1911 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2021 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2030 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2170 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2171 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2203 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2205 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2338 AND `id` IN (1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2344 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2583 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2651 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2713 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2742 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2744 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=2761 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3271 AND `id` IN (2, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3380 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3458 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3804 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3808 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3811 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3900 AND `id` IN (1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3939 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=3940 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4025 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4036 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4050 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4051 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4116 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4119 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4151 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4278 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4296 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4299 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4303 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4467 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4517 AND `id` IN (0, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4649 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4680 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4682 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4684 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4798 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4799 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4805 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4809 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4818 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4820 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4831 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4847 AND `id` IN (0, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4850 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4852 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4962 AND `id` IN (0, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=4971 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5333 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5335 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5601 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5682 AND `id` IN (0, 1);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5915 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=6047 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=6113 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=6207 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=6210 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=7175 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=7291 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=7321 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=7727 AND `id` IN (0, 1, 2);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=7843 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=10979 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=11032 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=12320 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=13219 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=14832 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=15184 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=15212 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=15277 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17143 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17150 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17199 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17206 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17551 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17725 AND `id` IN (2, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=17810 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=19480 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=19671 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23188 AND `id`=7;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=23619 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (23623, 23624, 23625, 23626) AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=24687 AND `id` IN (4, 5);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=25087 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (25090, 25091, 25092) AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26178 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=26428 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=29614 AND `id` IN (5, 6, 7);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=32377 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=35143 AND `id` IN (1, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36499 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36516 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36522 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36551 AND `id`=5;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36564 AND `id` IN (3, 5);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36620 AND `id` IN (3, 5, 7);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36840 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36842 AND `id` IN (1, 3);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36879 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36892 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=36896 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=37712 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=37728 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=38482 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=40417 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=43540 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (44614, 44794) AND `id`=6;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=50051 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2732801 AND `id` IN (3, 4);

-- Missing SMART_EVENT_FLAG_NOT_REPEATABLE
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid` IN (-131059, -131058, -131056, -131055, -105495, -105489, -105488, -105487) AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=702 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=1393 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=1538 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=1664 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=4961 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=3 WHERE `source_type`=0 AND `entryorguid`=9707 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=3 WHERE `source_type`=0 AND `entryorguid`=9708 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=3 WHERE `source_type`=0 AND `entryorguid`=10375 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=3 WHERE `source_type`=0 AND `entryorguid` IN (10680, 10681) AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=16459 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=17240 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=17311 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=17664 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=18372 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid` IN (18734, 18735, 18736, 18737, 18738) AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=20132 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=20769 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=22979 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=3 WHERE `source_type`=0 AND `entryorguid`=23030 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=23037 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=23162 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=23274 AND `id` IN (15, 18);
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=23376 AND `id` IN (0, 3);
UPDATE `smart_scripts` SET `event_flags`=7 WHERE `source_type`=0 AND `entryorguid`=26638 AND `id` IN (1, 2);
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=27250 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=27254 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=27615 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid` IN (27616, 27618, 27619) AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=27640 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=28027 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=28362 AND `id`=9;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=28608 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=28902 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=28998 AND `id`=9;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=29352 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=30096 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=30146 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=513 WHERE `source_type`=0 AND `entryorguid`=30174 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=30399 AND `id`=7;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=30845 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=31222 AND `id`=5;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=31271 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=31277 AND `id`=8;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=32484 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=32868 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=33498 AND `id` IN (0, 1);
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=34300 AND `id`=4;
UPDATE `smart_scripts` SET `event_flags`=7 WHERE `source_type`=0 AND `entryorguid`=37670 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=42940 AND `id`=1;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=45919 AND `id`=5;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=58731 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=63240 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `source_type`=0 AND `entryorguid`=67004 AND `id`=2;

-- Missing event timers
UPDATE `smart_scripts` SET `event_param2`=1000, `event_param3`=3000, `event_param4`=3000 WHERE `source_type`=0 AND `entryorguid`=314 AND `id`=1;
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid` IN (5254, 5343, 5366, 7726, 29368) AND `id` IN (4, 5, 6, 7, 8);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid` IN (5251, 7939, 8147) AND `id` IN (6, 8, 11);
UPDATE `smart_scripts` SET `event_param1`=15000, `event_param2`=25000 WHERE `source_type`=0 AND `entryorguid`=5808 AND `id`=0;
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=7000 WHERE `source_type`=0 AND `entryorguid`=9817 AND `id`=7;
UPDATE `smart_scripts` SET `event_param3`=8000, `event_param4`=10000 WHERE `source_type`=0 AND `entryorguid`=11340 AND `id`=2;
UPDATE `smart_scripts` SET `event_param3`=15000, `event_param4`=20000 WHERE `source_type`=0 AND `entryorguid`=11353 AND `id`=0;
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=18678 AND `id` IN (9, 11);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=23285 AND `id` IN (9, 12);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=25969 AND `id`=3;
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=26865 AND `id` IN (12, 13, 15, 17, 18);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=28083 AND `id` IN (9, 12);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=28752 AND `id` IN (4, 6, 8);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid`=35151 AND `id` IN (4, 5, 6, 7);
UPDATE `smart_scripts` SET `event_param3`=1000, `event_param4`=1000 WHERE `source_type`=0 AND `entryorguid`=36856 AND `id`=4;
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid` IN (39733, 39965, 43488) AND `id` IN (4, 5, 6, 7, 8);
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=500 WHERE `source_type`=0 AND `entryorguid` IN (39946, 39972, 40069, 40360, 44400) AND `id` IN (6, 8, 11);
UPDATE `smart_scripts` SET `event_param3`=8000, `event_param4`=10000 WHERE `source_type`=0 AND `entryorguid`=43014 AND `id`=1;
UPDATE `smart_scripts` SET `event_param3`=60000, `event_param4`=60000 WHERE `source_type`=0 AND `entryorguid`=46709 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=10000, `event_param2`=10000, `event_param3`=35000, `event_param4`=40000 WHERE `source_type`=0 AND `entryorguid`=50780 AND `id`=1;
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=3000 WHERE `source_type`=0 AND `entryorguid`=63611 AND `id`=0;

-- Event links
UPDATE `smart_scripts` SET `link`=0 WHERE `source_type`=0 AND `entryorguid` IN (-460049, 3616, 41641, 46274, 47250) AND `id`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `source_type`=0 AND `entryorguid`=14908 AND `id`=7;
UPDATE `smart_scripts` SET `link`=0 WHERE `source_type`=0 AND `entryorguid`=29614 AND `id`=4;

-- Invalid data for SMART_EVENT_VICTIM_CASTING
UPDATE `smart_scripts` SET `event_param3`=0, `event_param4`=0 WHERE `event_type`=13;

-- Invalid data for SMART_ACTION_SET_INGAME_PHASE_ID & SMART_ACTION_SET_INGAME_PHASE_GROUP
UPDATE `creature` SET `phaseUseFlags`= 0, `PhaseId`= 170 WHERE `guid`=27588 AND `id`=26206;

UPDATE `smart_scripts` SET `comment`='Skyguard Ace - On Data 1 1 Set - Remove phase 170' WHERE `source_type`=0 AND `entryorguid`=-130968 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Skyguard Ace - On Data 1 1 Set - Remove phase 170 (Skyguard Ace)' WHERE `source_type`=0 AND `entryorguid`=-130968 AND `id` IN (3, 4);
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=1, `comment`='Anvilrage Guardsman - On Respawn - Set phase 170' WHERE `source_type`=0 AND `entryorguid` IN (-91106, -91107) AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Anvilrage Guardsman - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid` IN (889100, 889101) AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=1, `comment`='High Chief Bristlelimb - On Reset - Set phase 170' WHERE `source_type`=0 AND `entryorguid`=17702 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='High Chief Bristlelimb - On Data Set - Remove phase 170' WHERE `source_type`=0 AND `entryorguid`=17702 AND `id`=3;
UPDATE `smart_scripts` SET `action_type`=16, `action_param1`=371, `action_param2`=1, `comment`='Halfdan the Ice-Hearted - On Just Summoned - Set phase group 371' WHERE `source_type`=0 AND `entryorguid`=23671 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Halfdan the Ice-Hearted - On Just Summoned - Remove phase 170 from Val''kyr Observer' WHERE `source_type`=0 AND `entryorguid`=23671 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=1, `comment`='Halfdan the Ice-Hearted - Ooc - Set phase 170 to Val''kyr Observer' WHERE `source_type`=0 AND `entryorguid`=23671 AND `id`=17;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Raelorasz - On Quest ''Mustering the Reds'' Rewarded - Remove phase 170 (Keristrasza)' WHERE `source_type`=0 AND `entryorguid`=26117 AND `id`=3;
UPDATE `smart_scripts` SET `action_type`=16, `comment`='Warlord Jin''arrak - On Just Summoned - Set phase group 371' WHERE `source_type`=0 AND `entryorguid`=27199 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=177, `action_param2`=1, `comment`='Gymer - On Passenger Boarded - Set phase 177' WHERE `source_type`=0 AND `entryorguid`=29884 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=177, `action_param2`=0, `comment`='Gymer - On Passenger Removed - Remove phase 177' WHERE `source_type`=0 AND `entryorguid`=29884 AND `id`=5;
UPDATE `smart_scripts` SET `action_type`=16, `comment`='Machine - Just created - Set phase group 371' WHERE `source_type`=0 AND `entryorguid`=30134 AND `id`=16;
UPDATE `smart_scripts` SET `action_param2`=1, `comment`='Crusader Olakin Sainrith - On Just Summoned - Set phase 175' WHERE `source_type`=0 AND `entryorguid`=31428 AND `id`=6;
UPDATE `smart_scripts` SET `action_param2`=1, `comment`='Ghostwing - On Just Summoned - Set phase 175' WHERE `source_type`=0 AND `entryorguid`=31432 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=16, `comment`='Your Corpse - On Just Summoned - Set phase group 371 (No Repeat)' WHERE `source_type`=0 AND `entryorguid`=32742 AND `id`=1;
UPDATE `smart_scripts` SET `comment`='Banner of Provocation - On counter set - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=181058 AND `id`=2;
UPDATE `smart_scripts` SET `comment`='Bundle of Bloodthistle - On Data Set 3 3 - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=184798 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Zul''Drak Skull Pile 02 - On Data Set 0 1 - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=190594 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Convocation Summoning Circle Spell Focus - On Data Set 0 1 - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=191124 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Shadow Council Torch (x2.00) - On Data Set 0 1 - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=191365 AND `id`=0;
UPDATE `smart_scripts` SET `comment`='Archbishop Landgren''s Corpse - On Data Set 0 1 - Set phase 170' WHERE `source_type`=1 AND `entryorguid`=191578 AND `id`=0;
UPDATE `smart_scripts` SET `action_param2`=1, `comment`='Razorthorn Dirt Mound - On Script - Set phase 170' WHERE `source_type`=9 AND `entryorguid`=18707300 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Razorthorn Dirt Mound - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid`=18707300 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=1, `comment`='Nerubian Crater - On Script - Set phase 170' WHERE `source_type`=9 AND `entryorguid`=19055500 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Nerubian Crater - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid`=19055500 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=1, `comment`='Convocation Summoning Circle - On Script - Set phase 170' WHERE `source_type`=9 AND `entryorguid`=19112300 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Convocation Summoning Circle - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid`=19112300 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Shadow Council Torch (x2.00) - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid`=19136500 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=1, `comment`='Val''kyr Observer - On Script - Set phase 170 to nearby Val''kyr Observer' WHERE `source_type`=9 AND `entryorguid`=2411800 AND `id`=5;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=1, `comment`='Val''kyr Observer - On Script - Set phase 170 to Self' WHERE `source_type`=9 AND `entryorguid`=2411800 AND `id`=6;
UPDATE `smart_scripts` SET `action_param1`=170, `action_param2`=0, `comment`='Mootoo the Younger - On Script - Remove phase 170' WHERE `source_type`=9 AND `entryorguid`=2550404 AND `id`=1;
UPDATE `smart_scripts` SET `comment`='Brann - On ActionList - Set phase group 371' WHERE `source_type`=9 AND `entryorguid`=3038200 AND `id`=2;

-- Invalid misc data
UPDATE `smart_scripts` SET `event_param2`=12000 WHERE `source_type`=0 AND `entryorguid`=1804 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=40 WHERE `source_type`=0 AND `entryorguid`=6176 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=120 WHERE `source_type`=0 AND `entryorguid`=7750 AND `id`=1;
UPDATE `smart_scripts` SET `event_param1`=83562 WHERE `source_type`=0 AND `entryorguid`=9397 AND `id`=0;
UPDATE `smart_scripts` SET `action_param1`=0 WHERE `source_type`=0 AND `entryorguid`=14718 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=22268, `action_param2`=0 WHERE `source_type`=0 AND `entryorguid`=22448 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `source_type`=0 AND `entryorguid` IN (20234, 26602, 26853, 26876, 26881) AND `id`=2;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=95006, `action_param2`=2, `target_type`=1 WHERE `source_type`=0 AND `entryorguid`=30698 AND `id`=9;
UPDATE `smart_scripts` SET `action_type`=86, `action_param3`=21, `action_param4`=50, `target_param1`=50 WHERE `source_type`=0 AND `entryorguid`=31119 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=7, `event_param1`=0 WHERE `source_type`=0 AND `entryorguid`=31260 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=66780, `action_param2`=0 WHERE `source_type`=0 AND `entryorguid`=35126 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=66781, `action_param2`=0 WHERE `source_type`=0 AND `entryorguid`=35128 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=66782, `action_param2`=0 WHERE `source_type`=0 AND `entryorguid`=35130 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=7, `event_param1`=0 WHERE `source_type`=0 AND `entryorguid`=36879 AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=519, `event_param1`=0 WHERE `source_type`=0 AND `entryorguid`=36896 AND `id`=2;
UPDATE `smart_scripts` SET `target_type`=23 WHERE `source_type`=0 AND `entryorguid`=37988 AND `id`=5;
UPDATE `smart_scripts` SET `event_param3`=12000, `event_param4`=18000 WHERE `source_type`=0 AND `entryorguid`=37112 AND `id`=2;
UPDATE `smart_scripts` SET `action_param3`=1, `target_type`=23 WHERE `source_type`=0 AND `entryorguid`=37988 AND `id`=6;
UPDATE `smart_scripts` SET `action_param3`=0 WHERE `source_type`=0 AND `entryorguid`=46230 AND `id`=2;
UPDATE `smart_scripts` SET `link`=0, `event_type`=4 WHERE `source_type`=0 AND `entryorguid` IN (47599, 47600) AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=134 WHERE `source_type`=0 AND `entryorguid`=47930 AND `id`=1;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=20 WHERE `source_type`=0 AND `entryorguid`=58769 AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `source_type`=0 AND `entryorguid`=59722 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=290189 WHERE `source_type`=0 AND `entryorguid`=149626 AND `id` IN (0, 2);
UPDATE `smart_scripts` SET `event_type`=70, `event_flags`=1, `event_param1`=2, `action_type`=87, `action_param1`=16481900, `action_param2`=16481901, `action_param3`=16481902, `action_param4`=16481903, `action_param5`=16481904, `action_param6`=16481905, `target_type`=1, `target_param1`=0, `target_param2`=0, `comment`='Dark Keeper Portrait - ON_STATE_CHANGED - Random action list' WHERE `source_type`=1 AND `entryorguid`=164819 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=70, `event_param1`=2 WHERE `source_type`=1 AND `entryorguid`=204019 AND `id`=2;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=102760, `target_type`=1 WHERE `source_type`=9 AND `entryorguid`=1566400 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=36421 WHERE `source_type`=9 AND `entryorguid`=1999500 AND `id`=17;
UPDATE `smart_scripts` SET `action_param1`=22268, `action_param2`=0 WHERE `source_type`=9 AND `entryorguid`=2244801 AND `id`=5;
UPDATE `smart_scripts` SET `action_param2`=294149 WHERE `source_type`=9 AND `entryorguid`=2362200 AND `id`=3;
UPDATE `smart_scripts` SET `target_type`=10 WHERE `source_type`=9 AND `entryorguid`=2598300 AND `id`=1;

-- Missing creature texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (2984, 4500, 4781, 6492, 7774, 10717, 13716, 15491, 24480, 49178);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2984, 0, 0, 'I''ve been expecting you, $n.', 12, 3, 100, 0, 0, 0, 947, 0, 'Seer Wiserunner'),
(4500, 0, 0, 'Puny $r wanna fight Overlord Mok''Morokk? Me beat you! Me boss here!', 12, 0, 100, 0, 0, 0, 1515, 0, 'Overlord Mok''Morokk - on Quest Accept'),
(4500, 1, 0, 'Me scared! Me run now!', 14, 0, 100, 0, 0, 0, 1523, 0, 'Overlord Mok''Morokk - on Health 0%-25%'),
(4500, 2, 0, 'Me still boss of ogres. Haw!', 14, 0, 100, 0, 0, 0, 1514, 0, 'Overlord Mok''Morokk'),
(4781, 0, 0, '%s nervously crawls from the crate.', 16, 0, 100, 0, 0, 0, 1638, 0, 'Snufflenose Gopher'),
(4781, 1, 0, '%s wiggles his whiskers at $n.', 16, 0, 100, 0, 0, 0, 1591, 0, 'Snufflenose Gopher'),
(4781, 2, 0, '%s sniffs at the ground...', 16, 0, 100, 0, 0, 0, 1592, 0, 'Snufflenose Gopher'),
(6492, 0, 0, '%s is angered and attacks!', 16, 0, 100, 0, 0, 0, 3074, 0, 'Rift Spawn'),
(6492, 1, 0, '%s escapes into the void!', 16, 0, 100, 0, 0, 0, 2564, 0, 'Rift Spawn'),
(6492, 2, 0, '%s is sucked into the coffer!', 16, 0, 100, 0, 0, 0, 2553, 0, 'Rift Spawn'),
(7774, 0, 0, 'Don''t forget to get my bell out of the chest here. And remember, if do happen to wander off, just ring it and i''ll find you again.', 12, 0, 100, 0, 0, 0, 3921, 0, 'Shay Leafrunner'),
(7774, 1, 0, 'This is quite an adventure!', 12, 0, 100, 0, 0, 0, 3914, 0, 'Shay Leafrunner'),
(7774, 1, 1, 'Oh, I wandered off again.  I''m sorry.', 12, 0, 100, 0, 0, 0, 3913, 0, 'Shay Leafrunner'),
(7774, 1, 2, 'The bell again, such a sweet sound.', 12, 0, 100, 0, 0, 0, 3916, 0, 'Shay Leafrunner'),
(7774, 1, 3, 'I can''t help it, really. This is just such a beautiful place.', 12, 0, 100, 0, 0, 0, 3915, 0, 'Shay Leafrunner'),
(7774, 1, 4, 'Oh, there you are!', 12, 0, 100, 0, 0, 0, 3906, 0, 'Shay Leafrunner'),
(7774, 2, 0, '%s begins to wander off.', 16, 0, 100, 0, 0, 0, 3918, 0, 'Shay Leafrunner'),
(7774, 3, 0, 'Are we taking the scenic route?', 12, 0, 100, 0, 0, 0, 3912, 0, 'Shay Leafrunner'),
(7774, 3, 1, 'Oh, what a beautiful flower over there...', 12, 0, 100, 0, 0, 0, 3907, 0, 'Shay Leafrunner'),
(7774, 3, 2, 'These trees are quite glorious, aren''t they?', 12, 0, 100, 0, 0, 0, 3908, 0, 'Shay Leafrunner'),
(7774, 3, 3, 'Are you sure this is the right way? Maybe we should go this way instead...', 12, 0, 100, 0, 0, 0, 3909, 0, 'Shay Leafrunner'),
(7774, 3, 4, 'Hmmm, I wonder what''s over this way?', 12, 0, 100, 0, 0, 0, 3911, 0, 'Shay Leafrunner'),
(7774, 4, 0, 'Oh, here you are, Rockbiter! I''m sorry, I know I''m not supposed to wander off.', 12, 0, 100, 0, 0, 0, 3917, 0, 'Shay Leafrunner'),
(10717, 0, 0, '%s is summoned through a temporal rift!', 16, 0, 100, 0, 0, 0, 6033, 0, ''),
(13716, 0, 0, 'You wish to learn of the stone? Follow me.', 12, 0, 100, 1, 0, 0, 8952, 0, 'Celebras - Line 0'),
(13716, 1, 0, 'For so long I have drifted in my cursed form. You have freed me... Your hard work shall be repaid.', 12, 0, 100, 1, 0, 0, 8953, 0, 'Celebras - Line 1'),
(13716, 2, 0, 'Please do as I instruct you, $n.', 12, 0, 100, 1, 0, 0, 8954, 0, 'Celebras - Line 2'),
(13716, 3, 0, 'Read this tome I have placed before you, and speak the words aloud.', 12, 0, 100, 1, 0, 0, 8950, 0, 'Celebras - Line 3'),
(13716, 4, 0, '%s begins to channel his energy, focusing on the stone.', 16, 0, 100, 469, 0, 0, 8951, 0, 'Celebras - Emote'),
(13716, 5, 0, 'Together, the two parts shall become one, once again.', 12, 0, 100, 1, 0, 0, 8948, 0, 'Celebras - Line 5'),
(13716, 6, 0, 'Shal myrinan ishnu daldorah...', 12, 0, 100, 1, 0, 0, 8949, 0, 'Celebras - Line 6'),
(13716, 7, 0, 'My scepter will once again become whole!', 12, 0, 100, 1, 0, 0, 8955, 0, 'Celebras - Line 7'),
(13716, 8, 0, 'Perhaps we can attempt this later. Please speak to me again if you wish to do so.', 12, 0, 100, 0, 0, 0, 8947, 0, 'Celebras the Redeemed'),
(15491, 0, 0, 'Pitiful, predictable mortals... You know not what you have done! The Master''s will fulfilled. The Moonglade shall be destroyed and Malfurion along with it!', 14, 0, 100, 0, 0, 0, 11030, 0, 'Eranikus Say 0'),
(15491, 1, 1, '%s lets loose a sinister laugh.', 16, 0, 100, 0, 0, 0, 11296, 0, 'Eranikus Say 1'),
(15491, 2, 2, 'You are certainly not your father, insect. Should it interest me, I would crush you with but a swipe of my claws. Turn Shan''do Stormrage over to me and your pitiful life will be spared along with the lives of your people.', 14, 0, 100, 0, 0, 0, 11294, 0, 'Eranikus Say 2'),
(15491, 3, 3, 'My redemption? You are bold, little one. My redemption comes by the will of my god.', 14, 0, 100, 0, 0, 0, 11297, 0, 'Eranikus Say 3'),
(15491, 4, 4, '%s roars furiously.', 16, 0, 100, 0, 0, 0, 11298, 0, 'Eranikus Say 4'),
(15491, 5, 5, 'Rise, servants of the Nightmare! Rise and destroy this world! Let there be no survivors...', 14, 0, 100, 0, 0, 0, 11299, 0, 'Eranikus Say 5'),
(15491, 6, 6, 'Where is your savior? How long can you hold out against my attacks?', 14, 0, 100, 0, 0, 0, 11304, 0, 'Eranikus Say 6'),
(15491, 7, 7, 'Remulos, look how easy they fall before me? You can stop this, fool. Turn the druid over to me and it will all be over...', 14, 0, 100, 0, 0, 0, 11306, 0, 'Eranikus Say 7'),
(15491, 8, 8, 'Defeated my minions? Then face me, mortals!', 14, 0, 100, 0, 0, 0, 11305, 0, 'Eranikus Say 8'),
(15491, 9, 9, 'IT BURNS! THE PAIN... SEARING...', 14, 0, 100, 0, 0, 0, 11314, 0, 'Eranikus Say 9'),
(15491, 10, 10, 'WHY? Why did this happen to ... to me? Where were you Tyrande? Where were you when I fell from the grace of Elune?', 14, 0, 100, 0, 0, 0, 11315, 0, 'Eranikus Say 10'),
(15491, 11, 11, 'I... I feel... I feel the touch of Elune upon my being once more... She smiles upon me... Yes... I...', 14, 0, 100, 0, 0, 0, 11316, 0, 'Eranikus Say 11'),
(15491, 12, 12, '%s falls to one knee.', 16, 0, 100, 0, 0, 0, 11319, 0, 'Eranikus Say 12'),
(24480, 0, 0, 'I thought you''d never ask!', 15, 0, 100, 0, 0, 0, 23477, 0, 'Mojo'),
(24480, 0, 1, 'Now that''s what I call froggy-style!', 15, 0, 100, 0, 0, 0, 23478, 0, 'Mojo'),
(24480, 0, 2, 'This won''t take long, did it?', 15, 0, 100, 0, 0, 0, 23479, 0, 'Mojo'),
(24480, 0, 3, 'I promise not to give you warts...', 15, 0, 100, 0, 0, 0, 23480, 0, 'Mojo'),
(24480, 0, 4, 'There''s just never enough Mojo to go around...', 15, 0, 100, 0, 0, 0, 23481, 0, 'Mojo'),
(24480, 0, 5, 'Listen, $n, I know of a little swamp not too far from here....', 15, 0, 100, 0, 0, 0, 23482, 0, 'Mojo'),
(24480, 0, 6, 'Your lily pad or mine?', 15, 0, 100, 0, 0, 0, 23483, 0, 'Mojo'),
(24480, 0, 7, 'Feelin'' a little froggy, are ya?', 15, 0, 100, 0, 0, 0, 23484, 0, 'Mojo'),
(24480, 1, 0, 'Mojo leaps into $n''s pocket!', 16, 0, 100, 0, 0, 0, 23485, 0, 'Mojo'),
(49178, 0, 0, 'FOOD FOR GROLNAR!', 14, 0, 100, 0, 0, 0, 49256, 0, 'Grolnar the Berserk');

-- Missing waypoints
DELETE FROM `waypoints` WHERE `entry` IN (7997, 13716, 15491, 19666, 369200, 1710900, 1710901);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(7997, 1, -4532.19, 807.833, 59.9749, NULL, 0, 'Captured Sprite Darter'),
(7997, 2, -4526.04, 799.328, 59.4271, NULL, 0, 'Captured Sprite Darter'),
(7997, 3, -4518.87, 786.24, 59.9261, NULL, 0, 'Captured Sprite Darter'),
(7997, 4, -4516.6, 766.617, 60.6654, NULL, 0, 'Captured Sprite Darter'),
(7997, 5, -4516.79, 749.124, 60.4805, NULL, 0, 'Captured Sprite Darter'),
(7997, 6, -4517.52, 731.643, 60.9822, NULL, 0, 'Captured Sprite Darter'),
(7997, 7, -4522.3, 710.707, 60.8061, NULL, 0, 'Captured Sprite Darter'),
(7997, 8, -4530.08, 695.036, 60.6917, NULL, 0, 'Captured Sprite Darter'),
(7997, 9, -4537.26, 679.979, 60.5726, NULL, 0, 'Captured Sprite Darter'),
(7997, 10, -4541.54, 655.429, 58.551, NULL, 0, 'Captured Sprite Darter'),
(7997, 11, -4539.33, 649.443, 57.9488, NULL, 0, 'Captured Sprite Darter'),
(7997, 12, -4526.54, 639.678, 56.2069, NULL, 0, 'Captured Sprite Darter'),
(7997, 13, -4507.92, 627.417, 55.6034, NULL, 0, 'Captured Sprite Darter'),
(13716, 1, 657.207, 73.8004, -86.8318, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 1'),
(13716, 2, 656.58, 83.1467, -86.8285, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 2'),
(13716, 3, 656.595, 73.5683, -86.8284, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 3'),
(13716, 4, 655.405, 73.8083, -86.8384, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 4'),
(13716, 5, 655.405, 73.8083, -86.8384, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 5'),
(13716, 6, 653.437, 73.9764, -85.3354, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 6'),
(13716, 7, 655.724, 67.3549, -86.828, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 7'),
(13716, 8, 650.08, 65.0115, -86.7745, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 8'),
(13716, 9, 655.445, 67.6601, -86.8283, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 9'),
(13716, 10, 657.399, 78.0873, -86.8283, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 10'),
(13716, 11, 652.611, 86.3702, -86.8453, NULL, 0, 'Celebras - The Scepter of Celebras - waypoint 11'),
(15491, 1, 7949.81, -2605.47, 513.591, NULL, 0, 'Eranikus'),
(15491, 2, 7931.33, -2575.21, 489.629, NULL, 0, 'Eranikus'),
(15491, 3, 7925.13, -2573.75, 489.64, NULL, 0, 'Eranikus'),
(15491, 4, 7910.55, -2565.55, 488.616, NULL, 0, 'Eranikus'),
(15491, 5, 7867.44, -2567.33, 486.946, NULL, 0, 'Eranikus'),
(19666, 1, -68.4021, -19.7878, -0.952996, NULL, 0, 'Shadow Lord Xiraxis'),
(19666, 2, -67.832, -48.3341, -0.955288, NULL, 0, 'Shadow Lord Xiraxis'),
(19666, 3, -67.7851, -75.7174, -0.938923, NULL, 0, 'Shadow Lord Xiraxis'),
(369200, 1, 4606.61, 2.96905, 69.909, NULL, 0, 'Volcor'),
(369200, 2, 4612.49, 14.2943, 69.8441, NULL, 0, 'Volcor'),
(1710900, 1, -10463.3, -3322.52, 20.9924, NULL, 0, ''),
(1710900, 2, -10468.9, -3331.02, 25.4713, NULL, 0, ''),
(1710900, 3, -10463.3, -3322.52, 20.9924, NULL, 0, ''),
(1710900, 4, -10461.1, -3319.65, 20.9641, NULL, 0, ''),
(1710901, 1, -10457.4, -3322.28, 20.9642, NULL, 0, ''),
(1710901, 2, -10454.3, -3320.74, 20.9642, NULL, 0, ''),
(1710901, 3, -10455.1, -3311.08, 21.0004, NULL, 0, ''),
(1710901, 4, -10445.8, -3296.79, 20.1784, NULL, 0, ''),
(1710901, 5, -10455.1, -3311.08, 21.0004, NULL, 0, ''),
(1710901, 6, -10454.3, -3320.74, 20.9642, NULL, 0, ''),
(1710901, 7, -10457.4, -3322.28, 20.9642, NULL, 0, ''),
(1710901, 8, -10461.1, -3319.65, 20.9641, NULL, 0, '');

-- Non-existent areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (2246, 2248, 2250, 2252, 2626, 2627, 2628, 2629, 2630, 2631, 2632, 2633, 2634, 2635, 2636, 2637, 4354);
DELETE FROM `smart_scripts` WHERE `source_type`=2 AND `entryorguid` IN (2246, 2248, 2250, 2252, 2626, 2627, 2628, 2629, 2630, 2631, 2632, 2633, 2634, 2635, 2636, 2637, 4354);

-- Action 15 SpecialFlags for Quest entry does not include FLAGS_EXPLORATION_OR_EVENT
DELETE FROM `quest_template_addon` WHERE `ID`=4770;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(4770, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2);

UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=27222;
