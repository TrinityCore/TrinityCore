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

-- Postmaster Malown
DELETE FROM `creature_text` WHERE `CreatureID` = 11143;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11143,0,0,"Prepare to be Malowned!",12,0,100,0,0,0,6504,0,"Postmaster Malown SAY_AGGRO"),
(11143,1,0,"You've been MALOWNED!",12,0,100,0,0,0,6530,0,"Postmaster Malown SAY_SLAY");

-- Ramstein the Gorger
DELETE FROM `creature_summon_groups` WHERE `summonerId` = 10439 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(10439,0,0,10394,4032.51220703125,-3375.840087890625,119.834259033203125,4.694935798645019531,8,0,"Ramstein the Gorger - Group 0 - Black Guard Sentry"),
(10439,0,0,10394,4035.098876953125,-3376.0771484375,119.8341827392578125,4.380776405334472656,8,0,"Ramstein the Gorger - Group 0 - Black Guard Sentry"),
(10439,0,0,10394,4036.68359375,-3377.730224609375,119.834228515625,4.433136463165283203,8,0,"Ramstein the Gorger - Group 0 - Black Guard Sentry"),
(10439,0,0,10394,4029.888916015625,-3377.631103515625,119.834442138671875,4.660028934478759765,8,0,"Ramstein the Gorger - Group 0 - Black Guard Sentry"),
(10439,0,0,10394,4033.248291015625,-3377.55615234375,119.8343276977539062,4.380776405334472656,8,0,"Ramstein the Gorger - Group 0 - Black Guard Sentry"),

(10439,0,1,11030,3931.286376953125,-3381.27099609375,119.763946533203125,4.86946868896484375,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3929.6494140625,-3386.864501953125,119.7804946899414062,5.393067359924316406,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.6337890625,-3388.093994140625,119.783355712890625,5.305800914764404296,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3931.753173828125,-3383.35888671875,119.770294189453125,4.886921882629394531,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3930.00830078125,-3383.300048828125,119.7698440551757812,5.131268024444580078,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3929.09326171875,-3388.217041015625,119.783355712890625,5.445427417755126953,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3930.91796875,-3382.405517578125,119.7672958374023437,4.97418832778930664,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.635009765625,-3385.118408203125,119.7757720947265625,4.817108631134033203,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.1171875,-3381.52880859375,119.7643890380859375,4.642575740814208984,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3930.132080078125,-3384.76220703125,119.7742538452148437,5.201081275939941406,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3930.72314453125,-3387.157470703125,119.7815322875976562,5.305800914764404296,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3932.75439453125,-3383.357666015625,119.7704391479492187,4.729842185974121093,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3930.82470703125,-3383.27490234375,119.7698974609375,5.026548385620117187,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3932.278564453125,-3381.40576171875,119.764312744140625,4.764749050140380859,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.45654296875,-3387.333251953125,119.7825088500976562,4.886921882629394531,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.560791015625,-3381.559814453125,119.7642974853515625,4.590215682983398437,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3932.07373046875,-3384.960693359375,119.775146484375,5.009094715118408203,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3932.382080078125,-3387.284423828125,119.7821731567382812,5.078907966613769531,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.690185546875,-3383.302490234375,119.7698822021484375,4.555309295654296875,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.503662109375,-3392.61962890625,119.70001220703125,5.649033069610595703,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3933.49658203125,-3389.21875,119.6870956420898437,5.617430686950683593,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3945.834228515625,-3393.9228515625,119.6992721557617187,6.250233650207519531,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3931.498046875,-3391.091796875,119.6890487670898437,6.044087409973144531,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3959.78857421875,-3396.4404296875,119.6981277465820312,6.078636646270751953,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3958.38818359375,-3396.561279296875,119.6981887817382812,6.175701141357421875,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3931.83349609375,-3390.5341796875,119.6877059936523437,4.882398128509521484,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3957.708251953125,-3396.381591796875,119.6982421875,6.153931140899658203,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3959.053955078125,-3396.48779296875,119.698150634765625,6.134456634521484375,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3929.69287109375,-3393.99462890625,119.6960067749023437,5.02886056900024414,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3931.53271484375,-3391.615234375,119.690277099609375,4.975285530090332031,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3929.46875,-3392.318115234375,119.6920928955078125,4.994153976440429687,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3970.814453125,-3399.48828125,119.0560226440429687,5.892495155334472656,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3968.68017578125,-3398.609130859375,119.1448135375976562,5.892423152923583984,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead"),
(10439,0,1,11030,3944.25390625,-3393.5615234375,119.69940185546875,6.096739768981933593,8,0,"Ramstein the Gorger - Group 1 - Mindless Undead");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 11030;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11030 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11030,0,0,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mindless Undead - On Spawn - Set In Combat With Zone");
