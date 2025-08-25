-- Dathrohan
DELETE FROM `creature_text` WHERE `CreatureID` IN (10812,10813);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10812,0,0,"Today you have unmade what took me years to create! For this you shall all die by my hand!",14,0,100,0,0,0,6441,0,"Grand Crusader Dathrohan SAY_AGGRO"),
(10813,0,0,"You fools think you can defeat me so easily? Face the true might of the Nathrezim!",14,0,100,0,0,0,6447,0,"Balnazzar SAY_TRANSFORM"),
(10813,1,0,"Damn you mortals! All my plans of revenge, all my hate...I will be avenged...",12,0,100,0,0,0,6442,0,"Balnazzar SAY_DEATH");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 10813 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(10813,0,0,10391,3460.35595703125,-3070.571533203125,135.086151123046875,0.331612557172775268,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10391,3465.2890625,-3069.987060546875,135.085845947265625,5.480333805084228515,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10391,3463.61572265625,-3074.91162109375,135.085845947265625,5.009094715118408203,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10390,3460.01220703125,-3076.04052734375,135.0858306884765625,1.186823844909667968,8,0,"Balnazzar - Group 0 - Skeletal Guardian"),
(10813,0,0,10390,3467.909423828125,-3076.40087890625,135.085662841796875,3.769911050796508789,8,0,"Balnazzar - Group 0 - Skeletal Guardian"),
(10813,0,0,10391,3509.2685546875,-3066.473876953125,135.08038330078125,4.817108631134033203,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10391,3510.966064453125,-3069.011474609375,135.08038330078125,3.490658521652221679,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10391,3516.04248046875,-3066.873046875,135.08038330078125,3.996803998947143554,8,0,"Balnazzar - Group 0 - Skeletal Berserker"),
(10813,0,0,10390,3513.560791015625,-3063.026611328125,135.08038330078125,2.356194496154785156,8,0,"Balnazzar - Group 0 - Skeletal Guardian"),
(10813,0,0,10390,3518.825439453125,-3060.92578125,135.08038330078125,3.944444179534912109,8,0,"Balnazzar - Group 0 - Skeletal Guardian");

UPDATE `creature_template` SET `unit_class` = 2 WHERE `entry` = 10813;
