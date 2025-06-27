SET @Defender          := 10948; -- Darrowshire Defender
SET @Skeleton          := 10952; -- Maraudin Skeleton
SET @Corpse            := 10951; -- Marauding Corpse
SET @Silver            := 10949; -- Silver hand disciple
SET @Sevant            := 10953; -- Sevant of Horgus
SET @Lightfire         := 10944; -- Davil Lightfire
SET @Horgus            := 10946; -- Horgus the Ravager
SET @Betrayer          := 10947; -- Darrowshire Betrayer
SET @Redpath           := 10937; -- Captain Redpath 
SET @Bloodletter       := 10954; -- Bloodletter
SET @Marduk            := 10939; -- Marduk the Black
SET @CorruptedRed      := 10938; -- Redpath the Corrupted
SET @Joseph            := 10936; -- Joseph Redpath
SET @Davil             := 10945; -- Davil Crokford
SET @Pamela            := 10926; -- Pamela Redpath
SET @Relic             := 177526; -- Relic Bundle, spell:=18987

DELETE FROM `creature_template_addon` WHERE `entry` IN(@Silver ,@Lightfire, @Defender, @Joseph, @Davil, @Pamela, @Horgus);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@Silver, 0, 0, 0, '17327'),
(@Lightfire, 0, 0, 0, '17327'), 
(@Defender, 0, 0, 0, '17327'),
(@Joseph, 0, 0, 0, '17327'),
(@Davil, 0, 0, 0, '17327'), 
(@Pamela, 0, 0, 0, '17327'),
(@Horgus, 0, 0, 0, '17467');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Defender, @Skeleton, @Corpse, @Sevant, @Lightfire, @Horgus, @Betrayer, @Redpath, @Bloodletter, @Marduk, @CorruptedRed, @Joseph, @Pamela, @Davil, @CorruptedRed);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@Relic;
UPDATE `gameobject` SET `position_x`=1439.81, `position_y`=-3702.22, `position_z`=77.12 WHERE `guid`=99891;
UPDATE `creature` SET `Orientation`=2.276223 WHERE `id`=@Pamela;

DELETE FROM `creature_summon_groups` WHERE `summonerid`=@Redpath;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@Redpath,0,0,@Defender,1484.442993, -3676.545410, 79.871506, 0.169049,8,0),
(@Redpath,0,0,@Defender,1497.560669, -3637.805176, 85.364410, 3.957781,8,0),  
(@Redpath,0,0,@Defender,1509.516357, -3640.667969, 88.113441, 4.707833,8,0), 
(@Redpath,0,0,@Defender,1511.495483, -3650.671631, 88.055191, 1.052592,8,0),
(@Redpath,0,0,@Defender,1503.856812, -3664.068359, 83.389610, 1.052592,8,0),
(@Redpath,0,0,@Defender,1494.220215, -3656.542725, 83.329399, 0.954417,8,0),
(@Redpath,0,0,@Defender,1495.856445, -3684.522461, 80.549515, 0.002224,8,0), 
(@Redpath,0,0,@Defender,1494.905640, -3678.563477, 80.728012, 6.140110,8,0), 
(@Redpath,0,0,@Defender,1494.013916, -3671.843262, 81.187721, 0.139665,8,0), 
(@Redpath,0,0,@Defender,1493.794922, -3665.639893, 81.787727, 5.719919,8,0),
(@Redpath,0,0,@Defender,1513.222290, -3693.317627, 84.312233, 2.388256,8,0),
(@Redpath,0,0,@Defender,1508.203369, -3701.367188, 81.152023, 1.888743,8,0),
(@Redpath,0,0,@Defender,1516.244263, -3706.704346, 82.785568, 5.756826,8,0),
(@Redpath,0,0,@Defender,1511.111084, -3709.822998, 82.240448, 2.073311,8,0),
(@Redpath,0,0,@Defender,1504.386353, -3709.648193, 81.169960, 0.557490,8,0),
(@Redpath,0,1,@Skeleton, 1497.560669, -3637.805176, 85.364410, 3.957781,8,0),  -- phase 1
(@Redpath,0,1,@Corpse, 1509.516357, -3640.667969, 88.113441, 4.707833,8,0), 
(@Redpath,0,1,@Skeleton ,1511.495483, -3650.671631, 88.055191, 1.052592,8,0),
(@Redpath,0,1,@Corpse, 1503.856812, -3664.068359, 83.389610, 1.052592,8,0),
(@Redpath,0,1,@Skeleton ,1494.220215, -3656.542725, 83.329399, 0.954417,8,0),
(@Redpath,0,1,@Skeleton, 1495.856445, -3684.522461, 80.549515, 0.002224,8,0), 
(@Redpath,0,1,@Corpse, 1494.905640, -3678.563477, 80.728012, 6.140110,8,0), 
(@Redpath,0,1,@Skeleton, 1494.013916, -3671.843262, 81.187721, 0.139665,8,0), 
(@Redpath,0,1,@Corpse, 1493.794922, -3665.639893, 81.787727, 5.719919,8,0),
(@Redpath,0,1,@Skeleton, 1513.222290, -3693.317627, 84.312233, 2.388256,8,0),
(@Redpath,0,1,@Corpse, 1508.203369, -3701.367188, 81.152023, 1.888743,8,0),
(@Redpath,0,1,@Skeleton, 1516.244263, -3706.704346, 82.785568, 5.756826,8,0),
(@Redpath,0,1,@Corpse, 1511.111084, -3709.822998, 82.240448, 2.073311,8,0),
(@Redpath,0,1,@Skeleton, 1504.386353, -3709.648193, 81.169960, 0.557490,8,0),
(@Redpath,0,2,@Sevant, 1497.560669, -3637.805176, 85.364410, 3.957781,8,0),  -- phase 2
(@Redpath,0,2,@Sevant, 1509.516357, -3640.667969, 88.113441, 4.707833,8,0), 
(@Redpath,0,2,@Sevant, 1511.495483, -3650.671631, 88.055191, 1.052592,8,0),
(@Redpath,0,2,@Sevant, 1503.856812, -3664.068359, 83.389610, 1.052592,8,0),
(@Redpath,0,2,@Sevant, 1494.220215, -3656.542725, 83.329399, 0.954417,8,0),
(@Redpath,0,2,@Sevant, 1495.856445, -3684.522461, 80.549515, 0.002224,8,0), 
(@Redpath,0,2,@Sevant, 1494.905640, -3678.563477, 80.728012, 6.140110,8,0), 
(@Redpath,0,2,@Sevant, 1494.013916, -3671.843262, 81.187721, 0.139665,8,0), 
(@Redpath,0,2,@Sevant, 1493.794922, -3665.639893, 81.787727, 5.719919,8,0),
(@Redpath,0,2,@Sevant, 1513.222290, -3693.317627, 84.312233, 2.388256,8,0),
(@Redpath,0,2,@Sevant, 1508.203369, -3701.367188, 81.152023, 1.888743,8,0),
(@Redpath,0,2,@Sevant, 1516.244263, -3706.704346, 82.785568, 5.756826,8,0),
(@Redpath,0,2,@Sevant, 1511.111084, -3709.822998, 82.240448, 2.073311,8,0),
(@Redpath,0,2,@Sevant, 1504.386353, -3709.648193, 81.169960, 0.557490,8,0),
(@Redpath,0,3,@Silver,1495.857910, -3682.440674,80.630501, 0.022911,8,0), 
(@Redpath,0,3,@Silver,1490.361938, -3684.647705, 80.350754, 0.285233,8,0), 
(@Redpath,0,3,@Silver,1495.075928, -3670.077148, 81.964828, 0.846651,8,0), 
(@Redpath,0,3,@Silver,1489.382568, -3666.546875, 81.307182, 0.058259,8,0),
(@Redpath,0,4,@Betrayer, 1497.560669, -3637.805176, 85.364410, 3.957781,8,0),  -- phase3
(@Redpath,0,4,@Betrayer, 1509.516357, -3640.667969, 88.113441, 4.707833,8,0), 
(@Redpath,0,4,@Betrayer, 1511.495483, -3650.671631, 88.055191, 1.052592,8,0),
(@Redpath,0,4,@Betrayer, 1503.856812, -3664.068359, 83.389610, 1.052592,8,0),
(@Redpath,0,4,@Betrayer, 1494.220215, -3656.542725, 83.329399, 0.954417,8,0),
(@Redpath,0,4,@Bloodletter, 1495.856445, -3684.522461, 80.549515, 0.002224,8,0), 
(@Redpath,0,4,@Bloodletter, 1494.905640, -3678.563477, 80.728012, 6.140110,8,0), 
(@Redpath,0,4,@Bloodletter, 1494.013916, -3671.843262, 81.187721, 0.139665,8,0), 
(@Redpath,0,4,@Bloodletter, 1493.794922, -3665.639893, 81.787727, 5.719919,8,0),
(@Redpath,0,4,@Betrayer, 1513.222290, -3693.317627, 84.312233, 2.388256,8,0),
(@Redpath,0,4,@Betrayer, 1508.203369, -3701.367188, 81.152023, 1.888743,8,0),
(@Redpath,0,4,@Betrayer, 1516.244263, -3706.704346, 82.785568, 5.756826,8,0),
(@Redpath,0,4,@Betrayer, 1511.111084, -3709.822998, 82.240448, 2.073311,8,0),
(@Redpath,0,4,@Betrayer, 1504.386353, -3709.648193, 81.169960, 0.557490,8,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Relic AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Relic*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lightfire  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lightfire *100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Defender  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Defender *100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Marduk AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Marduk*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Horgus AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Horgus*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Redpath AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Redpath*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Redpath*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @CorruptedRed AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @CorruptedRed*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Davil AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Joseph AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Joseph*100 AND `source_type` = 9; 
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Joseph*100+1 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Relic, 1, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Relic*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Relic - On spawn - action list'),
(@Relic*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 12, @Redpath, 6, 6000, 0, 0, 0, 8, 0, 0, 0, 1453.091431, -3693.156494, 76.784241, 0.486776, 'Relic - action list - spawn Redpath'),
(@Redpath, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Redpath*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - On spawn - action list'),
(@Redpath*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Set invisible - action list'),
(@Redpath*100, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn groupe 1 - action list'),
(@Redpath*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Defender, 40, 0, 0, 0, 0, 0, 'Defender - talk1 - action list'),
(@Redpath*100, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g2 wave1- action list'),
(@Redpath*100, 9, 4, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g2 wave2 - action list'),
(@Redpath*100, 9, 5, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 12, @Lightfire, 6, 6000, 0, 0, 0, 8, 0, 0, 0, 1453.091431, -3693.156494, 76.784241, 0.486776, 'Redpath - spawn Lightfire - action list'),
(@Redpath*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Davil, 8, 600000, 0, 0, 0, 8, 0, 0, 0, 1464.515991, -3678.878418, 78.043877, 0.577881, 'Redpath - Spawn Davil - action list'),
(@Redpath*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g3 wave1 - action list'),
(@Redpath*100, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g4 wave1 - action list'),
(@Redpath*100, 9, 9, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g4 wave2 - action list'),
(@Redpath*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Horgus, 6, 6000, 0, 0, 0, 8, 0, 0, 0, 1501.275024, -3675.826172, 81.447624, 3.300069, 'Redpath - Spawn Horgus - action list'),
(@Redpath*100, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Horgus, 100, 0, 0, 0, 0, 0, 'Horgus - talk1 - action list'),
(@Horgus, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 29060, 1, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Horgus - On spawn - cast spell 29060'),
(@Lightfire, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 1,@Lightfire, 0, 0, 9000000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On spawn - waypoint1'),
(@Lightfire, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On spawn - texte1'),
(@Davil, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - On spawn - action list'),
(@Davil, 0, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightfire - On spawn - texte2'),
(@Joseph, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Joseph*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - On spawn - action list'),
(@Joseph*100, 9, 0, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - despawn - action list'),
(@Joseph*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, @Joseph, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - Start Script - waypoint '),
(@Joseph*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - Start Script - remove npcflag'),
(@Joseph, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, @Joseph*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - On waypoint4 - Start Script'),
(@Joseph*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - On Script - Talk1'),
(@Joseph*100+1, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Pamela, 10, 0, 0, 0, 0, 0, 'Pamela - On Script - Talk1'),
(@Joseph*100+1, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Pamela, 10, 0, 0, 0, 0, 0, 'Pamela - On Script - Talk2'),
(@Joseph*100+1, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Pamela, 10, 0, 0, 0, 0, 0, 'Pamela - On Script - Talk3'),
(@Joseph*100+1, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Pamela, 10, 0, 0, 0, 0, 0, 'Pamela - On Script - Talk4'),
(@Joseph*100+1, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - On Script - Talk2'),
(@Joseph*100+1, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Joseph - despawn - action list'),
(@Joseph, 0, 2, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, @Joseph, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Joseph - On waypoint4 - Start Script'),
(@Horgus, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 80, @Horgus*100, 2, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Horgus - On death - action list'),
(@Horgus*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire -  talk 2 - action list'),
(@Horgus*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - talk 2 - action list'),
(@Horgus*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire -  talk 3 - action list'),
(@Horgus*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire -  talk 3 - action list'),
(@Horgus*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set React Passive'),
(@Horgus*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0,19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire - On Script - Set Immune To NPC'),
(@Horgus*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire - On Script - evade'),
(@Horgus*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 65, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire - play emote - action list'),
(@Horgus*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Lightfire, 100, 0, 0, 0, 0, 0, 'Lightfire - despawn - action list'),
(@Horgus*100, 9, 9, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 47, 1, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - Visible On - action list'),
(@Horgus*100, 9, 10, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 53, 1, @Redpath, 0, 0, 0, 2, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - waypoint 1 - action list'),
(@Horgus*100, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath -  talk 1 - action list'),
(@Horgus*100, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Redpath -  talk 2 - action list'),
(@Horgus*100, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g1 wave3 - action list'),
(@Horgus*100, 9, 14, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 107, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g4 wave1 - action list'),
(@Horgus*100, 9, 15, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 107, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - Spawn g4 wave2 - action list'),
(@Horgus*100, 9, 16, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 86, 18650, 2, 19, @Redpath, 50, 0, 19, @Redpath, 50, 0, 0, 0, 0, 0, 'Redpath - Spawn Marduk - action list'),
(@Horgus*100, 9, 17, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Marduk, 100, 0, 0, 0, 0, 0, 'Marduk - talk 1 - action list'),
(@Horgus*100, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - On Script - Set React Passive'),
(@Horgus*100, 9, 19, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0,19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - On Script - Set Immune To NPC'),
(@Horgus*100, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - On Script - evade'),
(@Horgus*100, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - set visible off - action list'),
(@Horgus*100, 9, 22, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 12, @CorruptedRed, 6, 60000, 0, 0, 0, 8, 0, 0, 0, 1494.081055, -3676.041748,80.846764, 6.269975, 'Redpath - Spawn CorruptedRed - action list'),
(@Horgus*100, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @CorruptedRed, 40, 0, 0, 0, 0, 0, 'CorruptedRed - talk 1 - action list'),
(@Horgus*100, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @CorruptedRed, 40, 0, 0, 0, 0, 0, 'CorruptedRed - On talk 2 - action list'),
(@Horgus*100, 9, 25, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 2, 0, 0, 0, 0, 0, 19, @Marduk, 40, 0, 0, 0, 0, 0, 'Marduk - Despawn - action list'),
(@Marduk, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, @Marduk*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horgus - On spawn - ActionList'),
(@Marduk*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marduk - On Script - Root'),
(@Marduk*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marduk - On Script - Set React Passive'),
(@Marduk*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marduk - On Script - Unit flag non attackable'),
(@Marduk*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - On Script - Set Immune To NPC'),
(@Marduk*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 131072, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Redpath - On Script - Set PACIFIED'),
(@CorruptedRed, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 80, @CorruptedRed*100, 2, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'CorruptedRed - On death - action list'),
(@CorruptedRed*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Joseph, 8, 60000, 0, 0, 0, 8, 0, 0, 0, 1444.337891, -3702.661133, 77.368271, 0.860624, 'Joseph - Spawn  - action list'),
(@CorruptedRed*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - talk3 - action list'),
(@CorruptedRed*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - talk4 - action list'),
(@CorruptedRed*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - talk5 - action list'),
(@CorruptedRed*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - Set visible - action list'),
(@CorruptedRed*100, 9, 5, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - despawn - action list'),
(@CorruptedRed*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Silver, 100, 0, 0, 0, 0, 0, 'Silver - despawn - action list'),
(@CorruptedRed*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - despawn - action list'),
(@CorruptedRed*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Betrayer, 100, 0, 0, 0, 0, 0, 'Silver - despawn - action list'),
(@Lightfire, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 80, @Lightfire*100, 2, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Lightfire - On death - action list'),
(@Lightfire*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - talk4 - action list'),
(@Lightfire*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 6, 5721, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Player - Quest failed - action list'),
(@Lightfire*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - despawn - action list'),
(@Lightfire*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Silver, 100, 0, 0, 0, 0, 0, 'Silver - despawn - action list'),
(@Lightfire*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @CorruptedRed, 100, 0, 0, 0, 0, 0, 'CorruptedRed - despawn - action list'),
(@Lightfire*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Betrayer, 100, 0, 0, 0, 0, 0, 'Betrayer - despawn - action list'),
(@Lightfire*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Bloodletter, 100, 0, 0, 0, 0, 0, 'Bloodletter - despawn - action list'),
(@Lightfire*100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Sevant, 100, 0, 0, 0, 0, 0, 'Sevant - despawn - action list'),
(@Lightfire*100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Horgus, 100, 0, 0, 0, 0, 0, 'Horgus - despawn - action list'),
(@Lightfire*100, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Skeleton, 100, 0, 0, 0, 0, 0, 'Skeleton - despawn - action list'),
(@Lightfire*100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Corpse, 100, 0, 0, 0, 0, 0, 'Corpse - despawn - action list'),
(@Lightfire*100, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Redpath, 100, 0, 0, 0, 0, 0, 'Redpath - despawn - action list'),
(@Lightfire*100, 9, 12, 0, 0, 0, 100, 0, 1000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - despawn - action list'),
(@Redpath, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 80, @Redpath*100+1, 2, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Redpath - On death - action list'),
(@Redpath*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - talk1 - action list'),
(@Redpath*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 6, 5721, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Player - quest failed - action list'),
(@Redpath*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Defender, 100, 0, 0, 0, 0, 0, 'Defender - despawn - action list'),
(@Redpath*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Silver, 100, 0, 0, 0, 0, 0, 'Silver - despawn - action list'),
(@Redpath*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @CorruptedRed, 100, 0, 0, 0, 0, 0, 'CorruptedRed - despawn - action list'),
(@Redpath*100+1, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Betrayer, 100, 0, 0, 0, 0, 0, 'Betrayer - despawn - action list'),
(@Redpath*100+1, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Bloodletter, 100, 0, 0, 0, 0, 0, 'Bloodletter - despawn - action list'),
(@Redpath*100+1, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Sevant, 100, 0, 0, 0, 0, 0, 'Sevant - despawn - action list'),
(@Redpath*100+1, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Horgus, 100, 0, 0, 0, 0, 0, 'Horgus - despawn - action list'),
(@Redpath*100+1, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Skeleton, 100, 0, 0, 0, 0, 0, 'Skeleton - despawn - action list'),
(@Redpath*100+1, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @Corpse, 100, 0, 0, 0, 0, 0, 'Corpse - despawn - action list'),
(@Redpath*100+1, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Davil, 100, 0, 0, 0, 0, 0, 'Davil - despawn - action list'),
(@Defender,0,0,0,0,0,100,0,3000,5000,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Darrowshire Defender - In Combat - Cast Strike'),
(@Defender,0,1,0,0,0,100,0,5000,7000,7000,10000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,'Darrowshire Defender - In Combat - Cast Shield Block'),
(@Lightfire,0,4,0,4,0,100,1,0,0,0,0,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Davil Lightfire - On Aggro - Cast Devotion Aura'),
(@Lightfire,0,5,0,0,0,100,0,5000,7000,8000,10000,11,17284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Davil Lightfire - In Combat - Cast Holy Strike'),
(@Lightfire,0,6,0,0,0,100,0,8000,11000,15000,20000,11,13005,0,0,0,0,0,5,0,0,0,0,0,0,0,'Davil Lightfire - In Combat - Cast Hammer of Justice'),
(@Redpath,0,2,0,0,0,100,0,5000,7000,8000,10000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Captain Redpath - In Combat - Cast Cleave'),
(@Redpath,0,3,0,0,0,100,0,8000,10000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Captain Redpath - In Combat - Cast Backhand'),
(@Redpath,0,4,0,0,0,100,0,3000,5000,15000,20000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captain Redpath - In Combat - Cast Battle Shout'),
(@Horgus,0,2,0,0,0,100,0,3000,5000,6000,8000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Horgus the Ravager - In Combat - Cast Thrash'),
(@Horgus,0,3,0,0,0,100,0,8000,11000,9000,12000,11,15608,1,0,0,0,0,2,0,0,0,0,0,0,0,'Horgus the Ravager - In Combat - Cast Ravenous Claw'),
(@CorruptedRed,0,1,0,0,0,100,0,3000,5000,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Redpath the Corrupted - In Combat - Cast Strike'),
(@CorruptedRed,0,2,0,0,0,100,0,8000,10000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,'Redpath the Corrupted - In Combat - Cast Backhand'),
(@CorruptedRed,0,3,0,0,0,100,0,3000,5000,15000,20000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,'Redpath the Corrupted - In Combat - Cast Demoralizing Shout'),
(@CorruptedRed,0,4,0,0,0,100,0,5000,7000,9000,14000,11,12542,1,0,0,0,0,6,0,0,0,0,0,0,0,'Redpath the Corrupted - In Combat - Cast Fear');

DELETE FROM `waypoints` WHERE `entry` IN (@Lightfire, @Redpath, @Joseph);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Lightfire,1, 1501.275024, -3675.826172, 81.447624,'Lightfire'),
(@joseph,1, 1433.060059, -3682.163086, 76.364197 , 'Joseph'),
(@joseph,2, 1433.873169, -3640.699707, 78.194763, 'Joseph'),
(@joseph,3, 1454.325439, -3595.439941, 86.951950, 'Joseph'),
(@joseph,4, 1455.368286, -3596.347900, 86.950905, 'Joseph'),
(@Redpath,1, 1501.275024, -3675.826172, 81.447624,'Redpath');

UPDATE `npc_text` SET `BroadcastTextID0`=7454  WHERE `ID`=4777;
DELETE FROM `gossip_menu` WHERE `entry`=3922 AND `text_id`=4777;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3922,4777);
UPDATE `creature_template` SET `gossip_menu_id`=3922 WHERE `entry`=10945;
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=10945;
UPDATE `npc_text` SET `BroadcastTextID0`=7455  WHERE `ID`=4778;
DELETE FROM `gossip_menu` WHERE `entry`=3861 AND `text_id`=4778;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3861,4778);
UPDATE `creature_template` SET `gossip_menu_id`=3861 WHERE `entry`=10936;
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=10936;

DELETE FROM `creature_text` WHERE `entry` IN (@Defender, @Lightfire, @Horgus, @Redpath, @Marduk, @CorruptedRed, @Joseph, @Pamela, @Davil) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Defender, 0, 0, 'Darrowshire, to arms! The Scourge approach!', 14, 0, 100, 0, 0, 0, 'Defender1', 7358),
(@Lightfire, 0, 0, 'Do not lose hope, Darrowshire! We will not fall!', 14, 0, 100, 0, 0, 0, 'Lightfire1', 7343),
(@Horgus, 0, 0, 'The light burns bright in you, Davil, I will enjoy snuffing it out.', 14, 0, 100, 0, 0, 0, 'Horgus', 7344),
(@Lightfire, 1, 0, 'Horgus, your nightmare ends! Now!', 14, 0, 100, 0, 0, 0, 'Lightfire2', 7346),
(@Defender, 1, 0, 'Horgus is slain! Take heat, defenders of Darrowshire.', 14, 0, 100, 0, 0, 0, 'Defender2', 7368),
(@Lightfire, 2, 0, 'Ah! My wounds are too severe. Defenders, fight on without me!', 12, 0, 100, 0, 0, 0, 'Lightfire2', 7227),
(@Lightfire, 3, 0, 'Davil Lightfire has succumbed to his wounds!', 16, 0, 100, 0, 0, 0, 'Lightfire2', 7367),
(@Redpath, 0, 0, 'Defenders of Darrowshire! Rally! we must prevail!', 14, 0, 100, 0, 0, 0, 'Redpath1', 7355),
(@Davil, 1, 0, 'Captain Redpath has appeared on the battlefield! Protect him!', 41, 0, 100, 0, 0, 0, 'Redpath2', 45683),
(@Davil, 0, 0, 'Captain Redpath!  How could you forsake us!', 41, 0, 100, 0, 0, 0, 'Redpath3', 7212),
(@Davil, 2, 0, 'Protect Davil Lightfire!', 41, 0, 100, 0, 0, 0, 'Lightfire1', 45681),
(@Davil, 3, 0, 'Davil Lightfire is defeated!  Darrowshire is lost!', 41, 0, 100, 0, 0, 0, 'Redpath4', 7366),
(@Marduk, 0, 0, 'Redpath! Your life ends, here and now!', 12, 0, 100, 0, 0, 0, 'Marduk1', 7471),
(@CorruptedRed, 0, 0, 'Darrowshire! Your are doomed!', 14, 0, 100, 0, 0, 0, 'CorruptedRed1', 7356),
(@CorruptedRed, 1, 0, 'Captain Joseph Redpath has been corrupted! Kill him quickly!', 41, 0, 100, 0, 0, 0, 'CorruptedRed2', 45684),
(@Defender, 2, 0, 'Captain Redpath is slain!', 14, 0, 100, 0, 0, 0, 'Defender3', 7369),
(@Defender, 3, 0, 'The Scourge are defeated! Darrowshire is saved!', 14, 0, 100, 0, 0, 0, 'Defender4', 7407),
(@Defender, 4, 0, 'Speak with Joseph Redpath in the center of Darrowshire.', 41, 0, 100, 0, 0, 0, 'Defender5', 45685),
(@Joseph, 0, 0, 'Pamela? Are you there, honey?', 12, 0, 100, 0, 0, 0, 'Joseph1', 7397),
(@Pamela, 0, 0, 'Daddy!', 12, 0, 100, 0, 0, 0, 'Pamela1', 7399),
(@Pamela, 1, 0, 'Daddy! You''re back!', 12, 0, 100, 0, 0, 0, 'Pamela2', 7400),
(@Pamela, 2, 0, 'Let''s go play! No, tell me a story, Daddy! No... let''s go pick flowers! And play tea time! I found my dollie, did I tell you?', 12, 0, 100, 0, 0, 0, 'Pamela3', 7401),
(@Pamela, 3, 0, 'I missed you so much, Daddy!', 12, 0, 100, 0, 0, 0, 'Pamela4', 7402),
(@Joseph, 1, 0, 'I missed you too, honey. And I''m finally home...', 12, 0, 100, 0, 0, 0, 'Joseph2', 7403);
