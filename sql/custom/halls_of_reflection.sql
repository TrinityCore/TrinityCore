DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69784,70224,70225,69708,70194);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,69874,0,18,1,37014,0,0, '', 'Destroy Wall - Only target Ice Wall Target'),
(13,0,70224,0,18,1,37014,0,0, '', 'Destroy Wall - Only target Ice Wall Target'),
(13,0,70225,0,18,1,37014,0,0, '', 'Destroy Wall - Only target Ice Wall Target'),
(13,0,69708,0,18,1,37226,0,0, '', 'Ice Prison - Only target The Lich King'),
(13,0,70194,0,18,1,37226,0,0, '', 'Dark Binding - Only target The Lich King');


INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES 
(38112,668,3,1,0,0,5276.81,2037.45,709.32,5.58779,604800,0,0,377468,0,0,0,0,0), -- Falric
(38113,668,3,1,0,0,5341.72,1975.74,709.32,2.40694,604800,0,0,539240,0,0,0,0,0); -- Marwyn

(202302,668,3,1,5309.51,2006.64,709.341,5.50041,0,0,0.381473,-0.92438,604800,100,1),
(202236,668,3,1,5309.51,2006.64,709.341,5.53575,0,0,0.365077,-0.930977,604800,100,1),
(201596,668,3,1,5275.28,1694.23,786.147,0.981225,0,0,0.471166,0.882044,25,0,1),
(500001,668,3,1,5323.61,1755.85,770.305,0.784186,0,0,0.382124,0.924111,604800,100,1),

UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38177;
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38564;
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38172;
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38524;
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38176;
UPDATE `creature_template` SET `unit_flags`=576 WHERE `entry`=38544;

DELETE FROM script_waypoint WHERE entry IN (36955,37226,37554);
INSERT INTO script_waypoint VALUES
(36955, 0, 5587.682,2228.586,733.011, 0, 'Lady Jaina Proudmore - WP 1'),
(36955, 1, 5600.715,2209.058,731.618, 0, 'Lady Jaina Proudmore - WP 2'),
(36955, 2, 5606.417,2193.029,731.129, 0, 'Lady Jaina Proudmore - WP 3'),
(36955, 3, 5598.562,2167.806,730.918, 0, 'Lady Jaina Proudmore - WP 4 - Summon IceWall 01'), 
(36955, 4, 5556.436,2099.827,731.827, 0, 'Lady Jaina Proudmore - WP 5 - Spell Channel'),
(36955, 5, 5543.498,2071.234,731.702, 0, 'Lady Jaina Proudmore - WP 6'),
(36955, 6, 5528.969,2036.121,731.407, 0, 'Lady Jaina Proudmore - WP 7'),
(36955, 7, 5512.045,1996.702,735.122, 0, 'Lady Jaina Proudmore - WP 8'),
(36955, 8, 5504.490,1988.789,735.886, 0, 'Lady Jaina Proudmore - WP 9 - Spell Channel'),
(36955, 9, 5489.645,1966.389,737.653, 0, 'Lady Jaina Proudmore - WP 10'),
(36955, 10, 5475.517,1943.176,741.146, 0, 'Lady Jaina Proudmore - WP 11'),
(36955, 11, 5466.930,1926.049,743.536, 0, 'Lady Jaina Proudmore - WP 12'),
(36955, 12, 5445.157,1894.955,748.757, 0, 'Lady Jaina Proudmore - WP 13 - Spell Channel'),
(36955, 13, 5425.907,1869.708,753.237, 0, 'Lady Jaina Proudmore - WP 14'),
(36955, 14, 5405.118,1833.937,757.486, 0, 'Lady Jaina Proudmore - WP 15'),
(36955, 15, 5370.324,1799.375,761.007, 0, 'Lady Jaina Proudmore - WP 16'),
(36955, 16, 5335.422,1766.951,767.635, 0, 'Lady Jaina Proudmore - WP 17 - Spell Channel'),
(36955, 17, 5311.438,1739.390,774.165, 0, 'Lady Jaina Proudmore - WP 18'),
(36955, 18, 5283.589,1703.755,784.176, 0, 'Lady Jaina Proudmore - WP 19'),
(36955, 19, 5260.400,1677.775,784.301, 3000, 'Lady Jaina Proudmore - WP 20'),
(36955, 20, 5262.439,1680.410,784.294, 0, 'Lady Jaina Proudmore - WP 21'),
(36955, 21, 5260.400,1677.775,784.301, 0, 'Lady Jaina Proudmore - WP 22'),
(37554, 0, 5587.682,2228.586,733.011, 0, 'Sylvannas - WP 1'),
(37554, 1, 5600.715,2209.058,731.618, 0, 'Sylvannas - WP 2'),
(37554, 2, 5606.417,2193.029,731.129, 0, 'Sylvannas - WP 3'),
(37554, 3, 5598.562,2167.806,730.918, 0, 'Sylvannas - WP 4 - Summon Ice Wall'), 
(37554, 4, 5556.436,2099.827,731.827, 0, 'Sylvannas - WP 5 - Channel Destroy Ice Wall'),
(37554, 5, 5543.498,2071.234,731.702, 0, 'Sylvannas - WP 6'),
(37554, 6, 5528.969,2036.121,731.407, 0, 'Sylvannas - WP 7'),
(37554, 7, 5512.045,1996.702,735.122, 0, 'Sylvannas - WP 8'),
(37554, 8, 5504.490,1988.789,735.886, 0, 'Sylvannas - WP 9 - Spell Channel'),
(37554, 9, 5489.645,1966.389,737.653, 0, 'Sylvannas - WP 10'),
(37554, 10, 5475.517,1943.176,741.146, 0, 'Sylvannas - WP 11'),
(37554, 11, 5466.930,1926.049,743.536, 0, 'Sylvannas - WP 12'),
(37554, 12, 5445.157,1894.955,748.757, 0, 'Sylvannas - WP 13 - Spell Channel'),
(37554, 13, 5425.907,1869.708,753.237, 0, 'Sylvannas - WP 14'),
(37554, 14, 5405.118,1833.937,757.486, 0, 'Sylvannas - WP 15'),
(37554, 15, 5370.324,1799.375,761.007, 0, 'Sylvannas - WP 16'),
(37554, 16, 5335.422,1766.951,767.635, 0, 'Sylvannas - WP 17 - Spell Channel'),
(37554, 17, 5311.438,1739.390,774.165, 0, 'Sylvannas - WP 18'),
(37554, 18, 5283.589,1703.755,784.176, 0, 'Sylvannas - WP 19'),
(37554, 19, 5260.400,1677.775,784.301, 3000, 'Sylvannas - WP 20'),
(37554, 20, 5262.439,1680.410,784.294, 0, 'Sylvannas - WP 21'),
(37554, 21, 5260.400,1677.775,784.301, 0, 'Sylvannas - WP 22'),
(37226, 0, 5577.187,2236.003,733.012, 0, 'The Lich King - WP 0'),
(37226, 1, 5587.682,2228.586,733.011, 0, 'The Lich King - WP 1'),
(37226, 2, 5600.715,2209.058,731.618, 0, 'The Lich King - WP 2'),
(37226, 3, 5606.417,2193.029,731.129, 0, 'The Lich King - WP 3'),
(37226, 4, 5598.562,2167.806,730.918, 0, 'The Lich King - WP 4'), 
(37226, 5, 5559.218,2106.802,731.229, 0, 'The Lich King - WP 5'),
(37226, 6, 5543.498,2071.234,731.702, 0, 'The Lich King - WP 6'),
(37226, 7, 5528.969,2036.121,731.407, 0, 'The Lich King - WP 7'),
(37226, 8, 5512.045,1996.702,735.122, 0, 'The Lich King - WP 8'),
(37226, 9, 5504.490,1988.789,735.886, 0, 'The Lich King - WP 9'),
(37226, 10, 5489.645,1966.389,737.653, 0, 'The Lich King - WP 10'),
(37226, 11, 5475.517,1943.176,741.146, 0, 'The Lich King - WP 11'),
(37226, 12, 5466.930,1926.049,743.536, 0, 'The Lich King - WP 12'),
(37226, 13, 5445.157,1894.955,748.757, 0, 'The Lich King - WP 13'),
(37226, 14, 5425.907,1869.708,753.237, 0, 'The Lich King - WP 14'),
(37226, 15, 5405.118,1833.937,757.486, 0, 'The Lich King - WP 15'),
(37226, 16, 5370.324,1799.375,761.007, 0, 'The Lich King - WP 16'),
(37226, 17, 5335.422,1766.951,767.635, 0, 'The Lich King - WP 17'),
(37226, 18, 5311.438,1739.390,774.165, 0, 'The Lich King - WP 18'),
(37226, 19, 5283.589,1703.755,784.176, 0, 'The Lich King - WP 19'),
(37226, 20, 5278.694,1697.912,785.692, 0, 'The Lich King - WP 20'),
(37226, 21, 5283.589,1703.755,784.176, 0, 'The Lich King - WP 21');