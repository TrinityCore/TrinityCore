-- SAI for Marcella Bloom
SET @ENTRY := 32421;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5717.51,`position_y`=688.2948,`position_z`=645.7512 WHERE `guid`=111385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - On spawn - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,40,0,100,0,6,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 6 - pause path'),
(@ENTRY,0,3,4,40,0,100,0,11,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 11 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.577925, 'Marcella Bloom - Reach wp 11 - turm to'),
(@ENTRY,0,5,0,40,0,100,0,19,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 19 - pause path'),
(@ENTRY,0,6,7,40,0,100,0,23,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 23 - pause path'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.710423, 'Marcella Bloom - Reach wp 23 - turm to'),
(@ENTRY,0,8,0,40,0,100,0,28,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 28 - pause path'),
(@ENTRY,0,9,10,40,0,100,0,29,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 29 - pause path'),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.689773, 'Marcella Bloom - Reach wp 29 - turm to');
-- Waypoints for Marcella Bloom from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5716.89,687.1589,645.7512, 'Marcella Bloom'),
(@ENTRY,2,5718.788,687.6731,645.7512, 'Marcella Bloom'),
(@ENTRY,3,5720.209,685.3612,645.7512, 'Marcella Bloom'),
(@ENTRY,4,5719.699,682.4218,645.7512, 'Marcella Bloom'),
(@ENTRY,5,5717.591,679.3567,645.7512, 'Marcella Bloom'),
(@ENTRY,6,5720.298,678.0955,646.5342, 'Marcella Bloom'),
(@ENTRY,7,5718.915,679.5812,645.7512, 'Marcella Bloom'),
(@ENTRY,8,5719.611,681.8755,645.7512, 'Marcella Bloom'),
(@ENTRY,9,5722.21,685.3296,645.7512, 'Marcella Bloom'),
(@ENTRY,10,5724.167,689.1262,645.7512, 'Marcella Bloom'),
(@ENTRY,11,5721.995,691.3812,645.7512, 'Marcella Bloom'),
(@ENTRY,12,5722.081,690.9567,645.7512, 'Marcella Bloom'),
(@ENTRY,13,5723.241,689.3571,645.7512, 'Marcella Bloom'),
(@ENTRY,14,5722.383,687.1551,645.7512, 'Marcella Bloom'),
(@ENTRY,15,5720.378,686.7902,645.7512, 'Marcella Bloom'),
(@ENTRY,16,5718.554,688.1351,645.7512, 'Marcella Bloom'),
(@ENTRY,17,5716.704,689.7863,645.7512, 'Marcella Bloom'),
(@ENTRY,18,5714.546,691.0844,645.7512, 'Marcella Bloom'),
(@ENTRY,19,5712.564,690.2685,645.7512, 'Marcella Bloom'),
(@ENTRY,20,5712.319,692.1107,645.7512, 'Marcella Bloom'),
(@ENTRY,21,5710.912,694.2338,645.7512, 'Marcella Bloom'),
(@ENTRY,22,5707.329,693.1917,645.7512, 'Marcella Bloom'),
(@ENTRY,23,5705.615,695.2361,645.7512, 'Marcella Bloom'),
(@ENTRY,24,5706.731,693.772,645.7512, 'Marcella Bloom'),
(@ENTRY,25,5708.21,694.3374,645.7512, 'Marcella Bloom'),
(@ENTRY,26,5709.226,695.5887,645.7512, 'Marcella Bloom'),
(@ENTRY,27,5711.422,696.0734,645.7512, 'Marcella Bloom'),
(@ENTRY,28,5713.526,695.2763,645.7512, 'Marcella Bloom'),
(@ENTRY,29,5713.636,691.7002,645.7512, 'Marcella Bloom'),
(@ENTRY,30,5716.311,690.1725,645.7512, 'Marcella Bloom'),
(@ENTRY,31,5717.51,688.2948,645.7512, 'Marcella Bloom');

-- SAI for Inzi Charmlight
SET @ENTRY := 28682;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5715.564,`position_y`=678.4122,`position_z`=645.7512 WHERE `guid`=97343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - On spawn - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,6,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 6 - pause path'),
(@ENTRY,0,2,0,40,0,100,0,18,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 18 - pause path'),
(@ENTRY,0,3,4,40,0,100,0,21,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 21 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.426008, 'Marcella Bloom - Reach wp 21 - turm to'),
(@ENTRY,0,5,0,40,0,100,0,22,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 22 - pause path'),
(@ENTRY,0,6,0,40,0,100,0,27,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Marcella Bloom - Reach wp 27 - pause path');
-- Waypoints for Inzi Charmlight from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5719.897,682.5544,645.7512, 'Inzi Charmlight'),
(@ENTRY,2,5719.891,686.0665,645.7512, 'Inzi Charmlight'),
(@ENTRY,3,5717.111,689.0646,645.7512, 'Inzi Charmlight'),
(@ENTRY,4,5711.454,694.7701,645.7512, 'Inzi Charmlight'),
(@ENTRY,5,5711.846,699.7839,645.7512, 'Inzi Charmlight'),
(@ENTRY,6,5709.633,700.0297,645.7512, 'Inzi Charmlight'),
(@ENTRY,7,5711.143,699.2699,645.7512, 'Inzi Charmlight'),
(@ENTRY,8,5712.436,694.9948,645.7512, 'Inzi Charmlight'),
(@ENTRY,9,5714.122,692.908,645.7512, 'Inzi Charmlight'),
(@ENTRY,10,5716.777,690.9016,645.7512, 'Inzi Charmlight'),
(@ENTRY,11,5718.896,688.1526,645.7512, 'Inzi Charmlight'),
(@ENTRY,12,5720.531,686.9282,645.7512, 'Inzi Charmlight'),
(@ENTRY,13,5722.85,687.8686,645.7512, 'Inzi Charmlight'),
(@ENTRY,14,5726.107,690.4207,645.7512, 'Inzi Charmlight'),
(@ENTRY,15,5727.03,694.2952,645.7512, 'Inzi Charmlight'),
(@ENTRY,16,5711.432,707.4515,653.6919, 'Inzi Charmlight'),
(@ENTRY,17,5708.918,708.4698,653.7011, 'Inzi Charmlight'),
(@ENTRY,18,5708.552,708.3618,653.7029, 'Inzi Charmlight'),
(@ENTRY,19,5709.459,706.2948,653.7265, 'Inzi Charmlight'),
(@ENTRY,20,5707.508,704.3312,653.7484, 'Inzi Charmlight'),
(@ENTRY,21,5705.197,703.1964,653.7423, 'Inzi Charmlight'),
(@ENTRY,22,5702.96,703.35,653.7493, 'Inzi Charmlight'),
(@ENTRY,23,5703.561,701.5987,653.7566, 'Inzi Charmlight'),
(@ENTRY,24,5703,699.5547,653.7488, 'Inzi Charmlight'),
(@ENTRY,25,5700.375,698.8538,653.7443, 'Inzi Charmlight'),
(@ENTRY,26,5697.52,698.8721,653.7496, 'Inzi Charmlight'),
(@ENTRY,27,5697.274,696.8895,653.7393, 'Inzi Charmlight'),
(@ENTRY,28,5697.476,697.3153,653.7394, 'Inzi Charmlight'),
(@ENTRY,29,5699.13,698.1936,653.7425, 'Inzi Charmlight'),
(@ENTRY,30,5700.803,696.9131,653.7471, 'Inzi Charmlight'),
(@ENTRY,31,5700.124,694.2091,653.7356, 'Inzi Charmlight'),
(@ENTRY,32,5698.897,690.7084,653.7178, 'Inzi Charmlight'),
(@ENTRY,33,5715.564,678.4122,645.7512, 'Inzi Charmlight');

-- SAI for Katherine Lee
SET @ENTRY := 28705;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5707.611,`position_y`=715.5347,`position_z`=642.4725 WHERE `guid`=98952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Katherine Lee - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,5,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Katherine Lee - Reach wp 5 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8377581, 'Katherine Lee - Reach wp 5 - turm to'),
(@ENTRY,0,3,4,40,0,100,0,10,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Katherine Lee - Reach wp 10 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.408554, 'Katherine Lee - Reach wp 10 - turm to');
-- Waypoints for Katherine Lee from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5708.027,715.2877,642.4726, 'Katherine Lee'),
(@ENTRY,2,5707.466,713.4067,642.4758, 'Katherine Lee'),
(@ENTRY,3,5705.038,713.5079,642.4757, 'Katherine Lee'),
(@ENTRY,4,5702.446,715.9288,642.4717, 'Katherine Lee'),
(@ENTRY,5,5700.928,718.1786,642.4681, 'Katherine Lee'),
(@ENTRY,6,5702.446,715.9288,642.4717, 'Katherine Lee'),
(@ENTRY,7,5705.038,713.5079,642.4757, 'Katherine Lee'),
(@ENTRY,8,5707.466,713.4067,642.4758, 'Katherine Lee'),
(@ENTRY,9,5708.027,715.2877,642.4726, 'Katherine Lee'),
(@ENTRY,10,5707.611,715.5347,642.4725, 'Katherine Lee');

-- SAI for Laire Brewgold
SET @ENTRY := 32424;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5639.154,`position_y`=728.4048,`position_z`=641.61 WHERE `guid`=111730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Laire Brewgold - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,1,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Laire Brewgold - Reach wp 1 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8377581, 'Laire Brewgold - Reach wp 1 - turm to'),
(@ENTRY,0,3,4,40,0,100,0,2,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Laire Brewgold - Reach wp 2 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.122173, 'Laire Brewgold - Reach wp 2 - turm to'),
(@ENTRY,0,5,6,40,0,100,0,10,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Laire Brewgold - Reach wp 10 - pause path'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.583087, 'Laire Brewgold - Reach wp 10 - turm to');
-- Waypoints for Laire Brewgold from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5635.932,732.4274,641.7092, 'Laire Brewgold'),
(@ENTRY,2,5633.13,729.802,641.7224, 'Laire Brewgold'),
(@ENTRY,3,5632.857,730.7568,641.7197, 'Laire Brewgold'),
(@ENTRY,4,5638.495,728.9272,641.6107, 'Laire Brewgold'),
(@ENTRY,5,5642.401,730.9983,641.6825, 'Laire Brewgold'),
(@ENTRY,6,5645.889,733.0624,641.682, 'Laire Brewgold'),
(@ENTRY,7,5655.076,730.4822,641.6819, 'Laire Brewgold'),
(@ENTRY,8,5661.111,726.7043,641.6643, 'Laire Brewgold'),
(@ENTRY,9,5663.163,728.8862,641.6496, 'Laire Brewgold'),
(@ENTRY,10,5661.848,731.7643,641.6437, 'Laire Brewgold'),
(@ENTRY,11,5661.233,732.0867,641.6819, 'Laire Brewgold'),
(@ENTRY,12,5661.178,729.5889,641.6537, 'Laire Brewgold'),
(@ENTRY,13,5659.352,724.879,641.6767, 'Laire Brewgold'),
(@ENTRY,14,5656.774,721.9439,641.6959, 'Laire Brewgold'),
(@ENTRY,15,5653.122,721.5146,641.6296, 'Laire Brewgold'),
(@ENTRY,16,5649.408,722.6322,641.5455, 'Laire Brewgold'),
(@ENTRY,17,5645.466,725.3781,641.6395, 'Laire Brewgold'),
(@ENTRY,18,5639.154,728.4048,641.61, 'Laire Brewgold');

-- SAI for Coira Longrifle
SET @ENTRY := 32426;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=5644.824,`position_y`=730.5149,`position_z`=641.6822 WHERE `guid`=111940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Coira Longrifle - On spawn - Start WP movement'),
(@ENTRY,0,1,2,40,0,100,0,5,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coira Longrifle - Reach wp 5 - pause path'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.740167, 'Coira Longrifle - Reach wp 5 - turm to'),
(@ENTRY,0,3,4,40,0,100,0,14,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coira Longrifle - Reach wp 14 - pause path'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.996804, 'Coira Longrifle - Reach wp 14 - turm to'),
(@ENTRY,0,5,6,40,0,100,0,20,@ENTRY,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coira Longrifle - Reach wp 20 - pause path'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.864306, 'Coira Longrifle - Reach wp 20 - turm to');
-- Waypoints for Coira Longrifle from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,5643.844,727.0675,641.6488, 'Coira Longrifle'),
(@ENTRY,2,5650.929,722.0482,641.5745, 'Coira Longrifle'),
(@ENTRY,3,5656.711,719.6259,641.5991, 'Coira Longrifle'),
(@ENTRY,4,5658.714,721.329,641.6793, 'Coira Longrifle'),
(@ENTRY,5,5658.198,724.0913,641.6834, 'Coira Longrifle'),
(@ENTRY,6,5658.953,723.9452,641.6814, 'Coira Longrifle'),
(@ENTRY,7,5661.61,728.0839,641.6577, 'Coira Longrifle'),
(@ENTRY,8,5664.91,733.9921,641.6255, 'Coira Longrifle'),
(@ENTRY,9,5663.366,736.1543,641.5908, 'Coira Longrifle'),
(@ENTRY,10,5660.653,736.6083,641.6053, 'Coira Longrifle'),
(@ENTRY,11,5659.226,737.1793,641.6076, 'Coira Longrifle'),
(@ENTRY,12,5656.145,740.5176,641.5779, 'Coira Longrifle'),
(@ENTRY,13,5652.403,743.0245,641.5914, 'Coira Longrifle'),
(@ENTRY,14,5648.907,746.6327,641.6072, 'Coira Longrifle'),
(@ENTRY,15,5648.699,746.1017,641.6102, 'Coira Longrifle'),
(@ENTRY,16,5648.634,743.4974,641.6179, 'Coira Longrifle'),
(@ENTRY,17,5647.743,739.7487,641.6585, 'Coira Longrifle'),
(@ENTRY,18,5645.861,735.217,641.6819, 'Coira Longrifle'),
(@ENTRY,19,5644.097,732.8497,641.6823, 'Coira Longrifle'),
(@ENTRY,20,5645.18,730.3257,641.6822, 'Coira Longrifle'),
(@ENTRY,21,5644.824,730.5149,641.6822, 'Coira Longrifle');
