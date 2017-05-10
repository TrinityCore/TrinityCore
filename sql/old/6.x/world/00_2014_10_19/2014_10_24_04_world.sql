DELETE FROM `creature_formations` WHERE `leaderGUID`=38429;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(38429, 38429, 0, 0, 2),
(38429, 38430, 3, 270, 2);
-- Pathing for Mattie Alred Entry: 5668 'TDB FORMAT'
SET @NPC := 38429;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1717.818,`position_y`=303.1138,`position_z`=-61.47988 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1717.818,303.1138,-61.47988,0,0,0,0,100,0),
(@PATH,2,1724.056,285.5189,-62.18394,0,0,0,0,100,0),
(@PATH,3,1725.809,279.2398,-62.18219,0,0,0,0,100,0),
(@PATH,4,1728.313,268.6199,-62.17767,0,0,0,0,100,0),
(@PATH,5,1730.295,250.8002,-62.17767,0,0,0,0,100,0),
(@PATH,6,1716.658,240.3017,-62.17767,0,0,0,0,100,0),
(@PATH,7,1692.596,241.7838,-62.17767,0,0,0,0,100,0),
(@PATH,8,1672.504,242.9413,-62.17767,0,0,0,0,100,0),
(@PATH,9,1665.619,249.5088,-62.1778,0,0,0,0,100,0),
(@PATH,10,1663.849,264.2947,-62.17823,0,0,0,0,100,0),
(@PATH,11,1659.715,273.889,-62.17942,0,0,0,0,100,0),
(@PATH,12,1652.447,286.605,-62.18125,0,0,0,0,100,0),
(@PATH,13,1637.696,299.425,-62.17578,0,0,0,0,100,0),
(@PATH,14,1621.363,308.3512,-62.17768,0,0,0,0,100,0),
(@PATH,15,1605.388,311.2079,-62.17768,0,0,0,0,100,0),
(@PATH,16,1598.25,318.9116,-62.17767,0,0,0,0,100,0),
(@PATH,17,1598.482,334.9213,-62.17767,0,0,0,0,100,0),
(@PATH,18,1599.09,358.2072,-62.17767,0,0,0,0,100,0),
(@PATH,19,1598.418,367.1544,-62.22174,0,0,0,0,100,0),
(@PATH,20,1610.374,374.7628,-62.17767,0,0,0,0,100,0),
(@PATH,21,1627.031,371.8268,-62.17767,0,0,0,0,100,0),
(@PATH,22,1637.79,368.5305,-62.16847,0,0,0,0,100,0),
(@PATH,23,1655.578,358.9601,-60.74146,0,0,0,0,100,0),
(@PATH,24,1657.84,352.9977,-60.72892,0,0,0,0,100,0),
(@PATH,25,1654.79,342.4309,-62.17167,0,0,0,0,100,0),
(@PATH,26,1668.162,325.3488,-62.15568,0,0,0,0,100,0),
(@PATH,27,1680.751,314.6597,-62.15656,0,0,0,0,100,0),
(@PATH,28,1694.482,302.0437,-62.16363,0,0,0,0,100,0);
-- 0xF13016240000906A .go 1717.818 303.1138 -61.47988

DELETE FROM `creature_text` WHERE `entry`=29903;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(29903, 0, 0, '%s sniffs and finds the trail.', 16, 0, 100, 0, 0, 0, 'Frostbite',30550),
(29903, 1, 0, 'The iron dwarves followed you! Use the net and the ice slick to escape!', 42, 0, 100, 0, 0, 0, 'Frostbite',30548),
(29903, 2, 0, '%s has tracked the scent to its source inside the cave.', 16, 0, 100, 377, 0, 0, 'Frostbite',30551),
(29903, 3, 0, 'Frostbite has tracked the scent to its source. Investigate the cave!', 42, 0, 100, 377, 0, 0, 'Frostbite',30549);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=29857;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(29857, 55460, 3, 0);
UPDATE `creature_template` SET `spell1`=54997, `spell2`=54996,`ainame`='SmartAI', `scriptname`='' WHERE `entry`=29903;
DELETE FROM `smart_scripts` WHERE `entryorguid`=29903 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2990300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29903,0,0,1,54,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Just Summoned - Cast Frosthound Periodic'),
(29903,0,1,0,61,0,100,0,0,0,0,0,80,2990300,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Just Summoned - Run Script'),
(29903,0,2,0,7,0,100,0,0,0,0,0,11,54993,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Evade - Cast Frosthound Periodic'),
(29903,0,3,0,40,0,100,0,4,29903,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Reached WP3 - Say Line 1'),
(29903,0,4,5,40,0,100,0,23,29903,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Reached WP3 - Say Line 2'),
(29903,0,5,6,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frost Bite - On Reached WP3 - Say Line 3'),
(29903,0,6,7,61,0,100,0,0,0,0,0,33,29677,0,0,0,0,0,23,0,0,0,0,0,0,0,'Frost Bite - On Reached WP3 - Give Kill Credit'),
(29903,0,7,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - On Reached WP3 - Despawn'),
(2990300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - Script - Say Line 0'),
(2990300,9,1,0,0,0,100,0,0,0,0,0,11,55476,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - Script - Cast Frostbite Boss Emote'),
(2990300,9,2,0,0,0,100,0,0,0,0,0,53,1,29903,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Bite - Script - Start WP');
DELETE FROM `waypoints` WHERE `entry`=29903;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(29903, 1, 7749.87 ,-1092.157 ,925.391, 'Frost Bite'),
(29903, 2, 7730.882 ,-1117.335 ,923.5192, 'Frost Bite'),
(29903, 3, 7709.588 ,-1138.151 ,923.0368, 'Frost Bite'),
(29903, 4, 7684.467 ,-1156.5 ,926.3825, 'Frost Bite'),
(29903, 5, 7667.916 ,-1167.89 ,925.6334, 'Frost Bite'),
(29903, 6, 7644.327 ,-1188.346 ,924.3444, 'Frost Bite'),
(29903, 7, 7626.495 ,-1208.446 ,928.0288, 'Frost Bite'),
(29903, 8, 7616.337 ,-1225.497 ,931.144, 'Frost Bite'),
(29903, 9, 7603.483 ,-1248.83 ,929.348, 'Frost Bite'),
(29903, 10, 7587.603 ,-1277.074 ,930.1173, 'Frost Bite'),
(29903, 11, 7579.03 ,-1288.508 ,930.7244, 'Frost Bite'),
(29903, 12, 7562.141 ,-1316.05 ,930.8729, 'Frost Bite'),
(29903, 13, 7534.76 ,-1348.399 ,931.9465, 'Frost Bite'),
(29903, 14, 7511.374 ,-1368.219 ,933.2729, 'Frost Bite'),
(29903, 15, 7476.767 ,-1399.918 ,934.6421, 'Frost Bite'),
(29903, 16, 7453.468 ,-1419.903 ,935.6179, 'Frost Bite'),
(29903, 17, 7422.59 ,-1443.929 ,934.3792, 'Frost Bite'),
(29903, 18, 7390.717 ,-1473.35 ,930.7485, 'Frost Bite'),
(29903, 19, 7366.973 ,-1493.927 ,930.0501, 'Frost Bite'),
(29903, 20, 7341.166 ,-1526.338 ,932.729, 'Frost Bite'),
(29903, 21, 7328.682 ,-1533.398 ,932.6253, 'Frost Bite'),
(29903, 22, 7318.588 ,-1547.078 ,936.2808, 'Frost Bite'),
(29903, 23, 7311.917 ,-1563.737 ,940.9844, 'Frost Bite');
