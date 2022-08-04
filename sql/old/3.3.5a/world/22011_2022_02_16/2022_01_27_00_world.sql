-- add some new locations
DELETE FROM `game_tele` WHERE `name` IN ('AcherusTheEbonHold','TheSeersLibrary','WaygateSholazar','WaygateUnGoro','TheShapersTerrace','StonetalonMountainsUnfinishedRegion','TopOfDunMorogh','ExteriorTest','ScottTest','Testing','QA_DVD','SunwellFixUnused');
INSERT INTO `game_tele` (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(2359.64, -5662.41, 382.261, 0.5969, 0, 'AcherusTheEbonHold'),
(-2250.18, 5559.37, 67.0219, 2.82446, 530, 'TheSeersLibrary'),
(4844.54, 5158.85, -92.826, 0.366961, 571, 'WaygateSholazar'),
(-6168.45, -1325.14, -172.389, 5.49729, 1, 'WaygateUnGoro'),
(-6194.39, -1272.2, -160.184, 1.56245, 1, 'TheShapersTerrace'),
(1871, 1425, 141, 0, 1, 'StonetalonMountainsUnfinishedRegion'),
(-4803.53, -996.022, 892.776, 5.99259, 0, 'TopOfDunMorogh'),

-- add some testing maps, fix Scott Test mapID
(65.2591, 32.2083, 0.01, 0, 573, 'ExteriorTest'),
(0, 0, -144, 0, 25, 'ScottTest'),
(0, 0, -144, 0, 13, 'Testing'),
(3100, 100, 0.01, 0, 606, 'QA_DVD'),
(0, 0, -2.80408, 0, 598, 'SunwellFixUnused');

-- mark mapID 598 (Sunwell Fix Unused) as valid
DELETE FROM `instance_template` WHERE `map`=598;
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES (598, 0, '', 0);
