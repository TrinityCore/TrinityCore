

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
