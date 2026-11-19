-- Update creature Spawns
UPDATE `creature` SET `position_x`=-10574.9287109375, `position_y`=1620.375, `position_z`=40.32911300659179687, `orientation`=0.961269855499267578 WHERE `guid` = 275107;
UPDATE `creature` SET `position_x`=-10616.0283203125, `position_y`=1649.6024169921875, `position_z`=42.50060653686523437, `orientation`=5.476982593536376953 WHERE `guid` = 275030;
UPDATE `creature` SET `position_x`=-10649.314453125, `position_y`=1618.3480224609375, `position_z`=43.24734878540039062, `orientation`=6.176519393920898437 WHERE `guid` = 275014;
UPDATE `creature` SET `position_x`=-10584.8544921875, `position_y`=1748.895751953125, `position_z`=39.90491867065429687, `orientation`=4.977270126342773437 WHERE `guid` = 275109;
UPDATE `creature` SET `position_x`=-10527.439453125, `position_y`=1689.30908203125, `position_z`=18.83073997497558593, `orientation`=3.954272747039794921 WHERE `guid` = 275105;
UPDATE `creature` SET `position_x`=-10550.396484375, `position_y`=1715.7552490234375, `position_z`=33.640594482421875, `orientation`=1.941838622093200683 WHERE `guid` = 275112;
UPDATE `creature` SET `position_x`=-10582.7568359375, `position_y`=1683.19970703125, `position_z`=38.51180648803710937, `orientation`=4.287467002868652343 WHERE `guid` = 275108;
UPDATE `creature` SET `position_x`=-10683.080078125, `position_y`=1651.09814453125, `position_z`=42.30972671508789062, `orientation`=1.847476363182067871 WHERE `guid` = 274975;
UPDATE `creature` SET `position_x`=-10616.8388671875, `position_y`=1581.623291015625, `position_z`=41.89981460571289062, `orientation`=1.320326089859008789 WHERE `guid` = 275015;
UPDATE `creature` SET `position_x`=-10616.888671875, `position_y`=1717.1978759765625, `position_z`=41.11151885986328125, `orientation`=4.939281940460205078 WHERE `guid` = 275016;
UPDATE `creature` SET `position_x`=-10650.802734375, `position_y`=1684.1461181640625, `position_z`=42.27070999145507812, `orientation`=2.824531078338623046 WHERE `guid` = 275017;
UPDATE `creature` SET `position_x`=-10523.080078125, `position_y`=1634.045166015625, `position_z`=27.20848655700683593, `orientation`=1.566889166831970214 WHERE `guid` = 275104;
UPDATE `creature` SET `position_x`=-10514.0595703125, `position_y`=1592.60595703125, `position_z`=28.2515716552734375, `orientation`=0.076884463429450988 WHERE `guid` = 275133;
UPDATE `creature` SET `position_x`=-10508.998046875, `position_y`=1757.703125, `position_z`=31.1963043212890625, `orientation`=2.92313551902770996 WHERE `guid` = 275132;
UPDATE `creature` SET `position_x`=-10438.513671875, `position_y`=1845.376708984375, `position_z`=29.06567192077636718, `orientation`=0.742607474327087402 WHERE `guid` = 275240;
UPDATE `creature` SET `position_x`=-10480.5244140625, `position_y`=1781.32470703125, `position_z`=31.37090492248535156, `orientation`=6.261449813842773437 WHERE `guid` = 275239;
UPDATE `creature` SET `position_x`=-10469.767578125, `position_y`=1840.63720703125, `position_z`=21.66096687316894531, `orientation`=2.373662948608398437 WHERE `guid` = 275236;
UPDATE `creature` SET `position_x`=-10477.595703125, `position_y`=1808.9930419921875, `position_z`=26.46253585815429687, `orientation`=1.727594733238220214 WHERE `guid` = 275238;
UPDATE `creature` SET `position_x`=-10510.5693359375, `position_y`=1795.236083984375, `position_z`=34.12454986572265625, `orientation`=1.950740575790405273 WHERE `guid` = 275131;
UPDATE `creature` SET `position_x`=-10503.0048828125, `position_y`=1828.7603759765625, `position_z`=36.65398788452148437, `orientation`=3.972281455993652343 WHERE `guid` = 275178;

UPDATE `creature` SET `wander_distance` = 12, `MovementType` = 1 WHERE `guid` IN (275107, 275030, 275014, 275109, 275105, 275112, 275108, 274975, 275015, 275016, 275017, 275104, 275133, 275132, 275240, 275239, 275236, 275238, 275131, 275178);
