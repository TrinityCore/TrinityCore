-- 
UPDATE `creature` SET `MovementType` = 2 WHERE `id` = 18917;
UPDATE `creature_template_addon` SET `path_id` = 679350 WHERE `entry` = 18917;
DELETE FROM `waypoint_data` WHERE `id` IN (679350);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`action`,`orientation`,`move_type`,`action_chance`,`wpguid`) VALUES
(679350,1,-3829.48,-11459.8,-138.541, 0, 0,2.41908, 0,100, 0),
(679350,2,-3839.35,-11454,-132.163, 0, 0,2.53689, 0,100, 0),
(679350,3,-3844.71,-11450.4,-132.205, 0, 0,2.26593, 0,100, 0),
(679350,4,-3873.98,-11414.8,-132.421, 0, 0,1.88737, 0,100, 0),
(679350,5,-3874,-11411.5,-132.225, 0, 0,1.75149, 0,100, 0),
(679350,6,-3874.36,-11399.9,-127.28, 0, 0,1.59441, 0,100, 0),
(679350,7,-3874.84,-11395.4,-127.27, 0, 0,2.29499, 0,100, 0),
(679350,8,-3892.69,-11373.3,-127.395, 3000, 0,2.1, 0,100, 0),
(679350,9,-3892.69,-11373.3,-127.395, 39000, 0,2.1, 0,100, 0), -- earth
(679350,10,-3862.49,-11363.8,-127.003, 0, 0,0.338363, 0,100, 0),
(679350,11,-3836.29,-11352.4,-126.654, 3000, 0,0.969038, 0,100, 0),
(679350,12,-3836.29,-11352.4,-126.654, 34000, 0,0.969038, 0,100, 0),  -- air
(679350,13,-3813.84,-11340.2,-126.344, 0, 0,0.167932, 0,100, 0),
(679350,14,-3796.9,-11337,-126.125, 0, 0,6.21, 0,100, 0),
(679350,15,-3778.75,-11341.2,-135.563, 0, 0,5.80081, 0,100, 0),
(679350,16,-3760.81,-11356.7,-135.41, 0, 0,4.80415, 0,100, 0),
(679350,17,-3760.49,-11366.8,-135.446, 0, 0,4.71697, 0,100, 0),
(679350,18,-3759.85,-11375.6,-138.324, 0, 0,4.8572, 0,100, 0),
(679350,19,-3745.79,-11427.3,-137.905, 0, 0,5.8625, 0,100, 0),
(679350,20,-3733.29,-11432.1,-131.04, 0, 0,5.76197, 0,100, 0),
(679350,21,-3711.24,-11444.1,-119.476, 0, 0,5.78553, 0,100, 0),
(679350,22,-3695.661,-11443.53,-119.294, 3000, 0,0.220984, 0,100, 0),
(679350,23,-3695.661,-11443.53,-119.294, 36000, 0,0.220984, 0,100, 0),  -- fire
(679350,24,-3708.46,-11439.2,-119.447, 0, 0,2.92668, 0,100, 0),
(679350,25,-3723.72,-11435.1,-126.368, 0, 0,2.87558, 0,100, 0),
(679350,26,-3743.96,-11430.2,-136.623, 0, 0,3.6814, 0,100, 0),
(679350,27,-3763.88,-11451.1,-136.234, 0, 0,4.07611, 0,100, 0),
(679350,28,-3767.72,-11457.4,-134.258, 0, 0,4.13108, 0,100, 0),
(679350,29,-3783.32,-11479.5,-134.526, 0, 0,3.3017, 0,100, 0),
(679350,30,-3791.01,-11479.3,-134.612, 0, 0,3.10875, 0,100, 0),
(679350,31,-3800.16,-11479.2,-138.267, 0, 0,3.14802, 0,100, 0),
(679350,32,-3809.66,-11477.5,-138.372, 0, 0,1.66984, 0,100, 0),
(679350,33,-3809.247,-11471.89,-138.346, 4000, 0,1.23787, 0,100, 0),
(679350,34,-3809.247,-11471.89,-138.346, 46000, 0,1.23787, 0, 100, 0); -- water

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (18917);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18917) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1891700,1891701,1891702,1891703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18917, 0, 0, 0, 34, 0, 100, 0, 2, 8, 0, 0, 80, 1891700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - In movement informer - Action list"),
(18917, 0, 1, 0, 34, 0, 100, 0, 2, 11, 0, 0, 80, 1891701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - In movement informer - Action list"),
(18917, 0, 2, 0, 34, 0, 100, 0, 2, 22, 0, 0, 80, 1891702, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - In movement informer - Action list"),
(18917, 0, 3, 0, 34, 0, 100, 0, 2, 33, 0, 0, 80, 1891703, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - In movement informer - Action list"),
(1891700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 18823, 10, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text Minor Water Spirit"),
(1891700, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891700, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891700, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891700, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891700, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 18918, 10, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891701, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891702, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 2, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text"),
(1891703, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chakaa - Action list - Say text");

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (67935);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(67935, 67935, 0, 0, 515),
(67935, 105110, 4, 20, 515),
(67935, 105204, 4, 45, 515),
(67935, 104939, 4, 75, 515),
(67935, 104888, 4, 340, 515),
(67935, 67936, 4, 315, 515),
(67935, 67937, 4, 290, 515);

DELETE FROM `creature_text` WHERE `CreatureID` IN (18917, 18918, 18823);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18823,0,0,'What about the earth spirits?',12,7,100,0,0,0,16110,0,"Minor Water Spirit"), -- Minor Water Spirit
(18917,0,0,'%s chuckles softly.',16,0,100,11,0,0,16111,0,"Chakaa"),
(18917,1,0,'The earth spirits are very much present in this chamber, my child. After all, we are underground, are we not?',12,7,100,6,0,0,16112,0,"Chakaa"),
(18917,2,0,'They are stoic, the spirits of the earth. Through them, the shaman learns to endure the hardships of life.',12,7,100,1,0,0,16113,0,"Chakaa"),
(18917,3,0,'The rocks are here when we first enter this world, and they will remain long after we pass.',12,7,100,1,0,0,16115,0,"Chakaa"),
(18917,4,0,'Stand... there is more to discuss.',12,7,100,1,0,0,16118,0,"Chakaa"),
(18917,5,0,'Stop here a moment, my children, and close your eyes. Can you feel the air currents?',12,7,100,1,0,0,16041,0,"Chakaa"),
(18917,6,0,'The two students close their eyes and bow their heads.',16,7,100,0,0,0,16043,0,"Chakaa"),
(18918,0,0,'Yes, teacher.',12,7,100,273,0,0,16050,0,"Drysc"), -- Drysc 
(18917,7,0,'The spirits of the air can be found even here, underground. They dislike being surrounded, constricted by the earth... their precious freedom is limited here.',12,7,100,1,0,0,16055,0,"Chakaa"),
(18917,8,0,'They are flighty, these spirits, and easily distracted... but they will share their secrets with those who know how to listen.',12,7,100,1,0,0,16057,0,"Chakaa"),
(18917,9,0,'%s smiles to himself as he watches the students fidget in their concentration.',16,0,100,0,0,0,16060,0,"Chakaa"),
(18917,10,0,'Come. There is more to study than the secrets on the wind.',12,7,100,1,0,0,16061,0,"Chakaa"),
(18917,11,0,'Can you feel the warmth here, my children?',12,7,100,6,0,0,16073,0,"Chakaa"),
(18917,12,0,'The students nod slowly, eyes rapt on their teacher.',16,0,100,0,0,0,16074,0,"Chakaa"),
(18917,13,0,'Focus upon that warmth as I speak...',12,7,100,1,0,0,16075,0,"Chakaa"),
(18917,14,0,'The strength of fire lies in change. Its strength is considerable, but ever-shifting... unpredictable.',12,7,100,1,0,0,16076,0,"Chakaa"),
(18917,15,0,'This is extended to the spirits themselves. They are often quick to anger; it is important thet you learn to listen without falling prey to their tempers.',12,7,100,1,0,0,16077,0,"Chakaa"),
(18917,16,0,'That is enough for now. Come.',12,7,100,1,0,0,16078,0,"Chakaa"),
(18917,17,0,'The water here is peaceful, is it not? Listening to the trickle from the ceiling can aid you in finding its true voice...',12,7,100,1,0,0,16079,0,"Chakaa"),
(18917,18,0,'The water spirits are perhaps the most outspoken. They are generous and understanding. Indeed, if you are having trouble hearing the voices, it is with water that you should begin.',12,7,100,1,0,0,16080,0,"Chakaa"),
(18917,19,0,'Close your eyes, my children, and listen to the water within these halls.',12,7,100,1,0,0,16081,0,"Chakaa"),
(18917,20,0,'Both students close their eyes, straining to hear the voices.',16,0,100,0,0,0,16104,0,"Chakaa"),
(18917,21,0,'%s nods to himself and clears his throat.',16,0,100,273,0,0,16107,0,"Chakaa"),
(18917,22,0,'Stand, my children... that\'s enough for now.',12,7,100,0,0,0,16108,0,"Chakaa");
