DELETE FROM `points_of_interest` WHERE `entry` IN (430, 431, 432); -- Dupes

UPDATE `points_of_interest` SET `x`=1611.974, `y`=-4345.156 WHERE `entry`=178;
UPDATE `points_of_interest` SET `x`=2281.68, `y`=283.71 WHERE `entry`=446;
UPDATE `points_of_interest` SET `x`=2265.609, `y`=240.1493 WHERE `entry`=447;
UPDATE `points_of_interest` SET `x`=2235.247, `y`=317.6962 WHERE `entry`=433;

SET @ID := 457;
DELETE FROM `points_of_interest` WHERE `entry` BETWEEN @ID+0 AND @ID+36;
INSERT INTO `points_of_interest` (`entry`, `x`, `y`, `icon`, `flags`, `data`, `icon_name`) VALUES
(@ID+0, -8282.65, 716.852, 7, 99, 0, 'Stormwind Druid Trainer'),
(@ID+1, 1731.276, -4510.059, 7, 99, 0, 'Orgrimmar Ethereals'),
(@ID+2, 1961.85, -4801.29, 7, 99, 0, 'Orgrimmar Battlemasters'),
(@ID+3, -4088.889, 6359.151, 7, 99, 0, 'Darkmoon Game Tokens'),
(@ID+4, 2231.17, 241.611, 7, 99, 0, 'Dedlow Wormwood'),
(@ID+5, 9924.486, 2311.766, 7, 99, 0, 'Darnassus Blacksmithing'),
(@ID+6, -4128.34, 6324.929, 7, 99, 0, 'AAA Tonk Arena'),
(@ID+7, -4018.019, 6292.561, 7, 99, 0, 'AAA Cannon'),
(@ID+8, -3998.495, 6280.141, 7, 99, 0, 'AAA Whack-a-Gnoll'),
(@ID+9, -4290.156, 6308.554, 7, 99, 0, 'AAA Ring Toss'),
(@ID+10, -4076.424, 6351.396, 7, 99, 0, 'AAA Shooting Gallery'),
(@ID+11, -4263.249, 6281.231, 7, 99, 0, 'AAA Fortune Teller'),
(@ID+12, -3721.332, -4538.389, 7, 99, 0, 'Theramore Banker'),
(@ID+13, -3779.576, -4542.243, 7, 99, 0, 'Theramore Hunter'),
(@ID+14, -3760.573, -4458.26, 7, 99, 0, 'Theramore Mage'),
(@ID+15, -3692.575, -4513.229, 7, 99, 0, 'Theramore Paladin'),
(@ID+16, -3651.748, -4501.245, 7, 99, 0, 'Theramore Priest'),
(@ID+17, -3819.238, -4563.955, 7, 99, 0, 'Theramore Rogue'),
(@ID+18, -3616.101, -4471.278, 7, 99, 0, 'Theramore Shaman'),
(@ID+19, -3744.523, -4435.247, 7, 99, 0, 'Theramore Warlock'),
(@ID+20, -3727.549, -4538.478, 7, 99, 0, 'Theramore Warrior'),
(@ID+21, -3700.832, -4331.733, 7, 99, 0, 'Theramore Alchemy'),
(@ID+22, -3618.908, -4454.213, 7, 99, 0, 'Theramore Archaeology'),
(@ID+23, -3785.925, -4366.835, 7, 99, 0, 'Theramore Blacksmithing'),
(@ID+24, -3617.13, -4486.976, 7, 99, 0, 'Theramore Cooking'),
(@ID+25, -3772.045, -4441.656, 7, 99, 0, 'Theramore Enchanting'),
(@ID+26, -3798.238, -4374.755, 7, 99, 0, 'Theramore Engineering'),
(@ID+27, -3747.083, -4532.172, 7, 99, 0, 'Theramore First Aid'),
(@ID+28, -3849.286, -4610.167, 7, 99, 0, 'Theramore Fishing'),
(@ID+29, -3697.021, -4335.253, 7, 99, 0, 'Theramore Herbalism'),
(@ID+30, -3774.651, -4448.427, 7, 99, 0, 'Theramore Inscription'),
(@ID+31, -3612.543, -4456.313, 7, 99, 0, 'Theramore Jewelcrafting'),
(@ID+32, -3613.028, -4461.912, 7, 99, 0, 'Theramore Leatherworking'),
(@ID+33, -3777.125, -4366.255, 7, 99, 0, 'Theramore Mining'),
(@ID+34, -3843.384, -4405.833, 7, 99, 0, 'Theramore Riding'),
(@ID+35, -3612.49, -4458.981, 7, 99, 0, 'Theramore Skinning'),
(@ID+36, -3846.469, -4449.224, 7, 99, 0, 'Theramore Tailoring');
