-- Add support for quest ID: 11008 - "Fires Over Skettis" based on Warpten fix and Nelegalno/shlomi1515 updates
-- Also add support for achievement - http://www.wowhead.com/achievement=1275/bombs-away
SET @TRIGGER :=  22991;
SET @EGG :=     185549;
SET @SKYBLAST := 39844;
SET @SUMMEGG :=  39843;
-- Adds SAI support for Monstrous Kaliri Egg Trigger and the GO
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@TRIGGER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@TRIGGER,0,0,0,25,0,100,0,0,0,0,0,11,@SUMMEGG,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - On spawn/reset - Summon Monstrous Kaliri Egg (object wild)'),
(@TRIGGER,0,1,2,8,0,100,0,@SKYBLAST,0,0,0,33,@TRIGGER,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - On Skyguard Blasting Charge hit - Give kill credit to invoker party'),
(@TRIGGER,0,2,3,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,@EGG,1,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - Linked with previous event - Despawn'),
(@TRIGGER,0,3,0,61,0,100,0,0,0,0,0,80,@TRIGGER*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - Linked with previous event - Start script 0'),
(@TRIGGER*100,9,0,0,0,0,100,0,44000,44000,0,0,11,@SUMMEGG,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger /On actionlist/ - Action 0 - Cast Summon Monstrous Kaliri Egg');
-- Add SAI for Cannonball Stack
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@EGG;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@EGG;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@EGG,1,0,0,38,0,100,0,0,1,0,0,70,45,0,0,0,0,0,1,0,0,0,0,0,0,0,' Monstrous Kaliri Egg - On data set 0 1 - Respawn object /make it reappear after 45 secs/');
-- Remove achievement from disabled
DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=3922;
-- Insert GO spawns taken directly from already spawned triggers coordinates = no need to sniff them
SET @guid := 979; -- 4.x
DELETE FROM `gameobject` WHERE `id`=@EGG;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`) VALUES
(@guid+0,@EGG,530,1,1,-3857.69,3426.25,363.733,-0.087267,180),
(@guid+1,@EGG,530,1,1,-3845.16,3332.2,338.59,2.9147,180),
(@guid+2,@EGG,530,1,1,-3965.16,3232.7,347.552,-0.122173,180),
(@guid+3,@EGG,530,1,1,-3955.86,3222.16,347.503,0.244346,180),
(@guid+4,@EGG,530,1,1,-3953.3,3227.94,347.564,-0.244346,180),
(@guid+5,@EGG,530,1,1,-4044.66,3287.29,348.362,0.349066,180),
(@guid+6,@EGG,530,1,1,-4041.39,3271,346.642,-2.09439,180),
(@guid+7,@EGG,530,1,1,-4049.31,3285.9,348.335,1.43117,180),
(@guid+8,@EGG,530,1,1,-4076.99,3415.22,334.008,-2.33874,180),
(@guid+9,@EGG,530,1,1,-4076.79,3412.91,334.617,-1.0821,180),
(@guid+10,@EGG,530,1,1,-4077.92,3412.57,334.768,-0.733038,180),
(@guid+11,@EGG,530,1,1,-4107.93,3121.5,357.427,1.01229,180),
(@guid+12,@EGG,530,1,1,-4108.31,3123.66,357.633,-0.680679,180),
(@guid+13,@EGG,530,1,1,-4110.19,3122.64,358.083,-0.034907,180),
(@guid+14,@EGG,530,1,1,-3996.89,3142.12,372.729,3.05433,180),
(@guid+15,@EGG,530,1,1,-4109.06,3019.1,352.24,0.261799,180),
(@guid+16,@EGG,530,1,1,-4018.35,3076.7,375.29,-0.733038,180),
(@guid+17,@EGG,530,1,1,-4184.98,3044.71,352.394,1.81514,180),
(@guid+18,@EGG,530,1,1,-4187.52,3040.39,352.071,-0.017453,180),
(@guid+19,@EGG,530,1,1,-4189.67,3039.9,352.247,-0.785398,180),
(@guid+20,@EGG,530,1,1,-4192.61,3045.1,352.096,3.14159,180),
(@guid+21,@EGG,530,1,1,-4192.02,3046.91,352.297,2.46091,180),
(@guid+22,@EGG,530,1,1,-4186.47,3047.19,352.316,2.60054,180),
(@guid+23,@EGG,530,1,1,-3915.67,2983.4,396.957,-1.91986,180),
(@guid+24,@EGG,530,1,1,-3883.21,3004.11,399.738,-1.64061,180),
(@guid+25,@EGG,530,1,1,-3883.26,3001.55,399.431,-2.3911,180),
(@guid+26,@EGG,530,1,1,-3884.29,3003.3,400.063,-1.88496,180),
(@guid+27,@EGG,530,1,1,-3903.02,3095.85,383.783,-2.28638,180),
(@guid+28,@EGG,530,1,1,-3898.45,3093.06,383.667,2.53073,180),
(@guid+29,@EGG,530,1,1,-3900.75,3100.75,383.795,-0.436333,180),
(@guid+30,@EGG,530,1,1,-4107.81,3023.42,352.142,1.06465,180),
(@guid+31,@EGG,530,1,1,-4113.58,3022.4,352.157,-0.645772,180),
(@guid+32,@EGG,530,1,1,-3893.09,3677.17,374.516,-1.23918,180),
(@guid+33,@EGG,530,1,1,-3892.47,3674,374.478,-2.14675,180),
(@guid+34,@EGG,530,1,1,-4198.53,3168.91,355.847,-0.383972,180),
(@guid+35,@EGG,530,1,1,-4197.01,3170.04,356.117,-1.15192,180),
(@guid+36,@EGG,530,1,1,-4196.54,3167.69,356.348,-0.541052,180),
(@guid+37,@EGG,530,1,1,-4020.07,3077.84,374.391,1.53589,180),
(@guid+38,@EGG,530,1,1,-4019.32,3079.74,375.109,-1.25664,180),
(@guid+39,@EGG,530,1,1,-3917.21,2981.62,396.483,0.733038,180),
(@guid+40,@EGG,530,1,1,-3918.45,2982.44,397.24,-1.72788,180),
(@guid+41,@EGG,530,1,1,-3839.35,3344.85,337.834,2.75762,180),
(@guid+42,@EGG,530,1,1,-3835.3,3344.77,338.155,-0.767945,180),
(@guid+43,@EGG,530,1,1,-3846.43,3430.29,363.729,0.488692,180),
(@guid+44,@EGG,530,1,1,-3864.13,3439.06,363.679,-0.05236,180),
(@guid+45,@EGG,530,1,1,-3863.24,3440.42,363.655,0.349066,180),
(@guid+46,@EGG,530,1,1,-3846.35,3439.34,363.628,-0.122173,180),
(@guid+47,@EGG,530,1,1,-3847.32,3441.39,363.648,0.453786,180),
(@guid+48,@EGG,530,1,1,-3686.21,3301,320.513,0.837758,180),
(@guid+49,@EGG,530,1,1,-3687.77,3299.85,320.307,2.75762,180),
(@guid+50,@EGG,530,1,1,-3692.64,3302.07,320.396,-0.226893,180),
(@guid+51,@EGG,530,1,1,-3661.91,3379.15,320.377,0.890118,180),
(@guid+52,@EGG,530,1,1,-3660.65,3381.9,320.182,1.18682,180),
(@guid+53,@EGG,530,1,1,-3665.48,3380.11,320.365,-0.471239,180),
(@guid+54,@EGG,530,1,1,-3685.07,3305.97,320.198,-2.87979,180),
(@guid+55,@EGG,530,1,1,-3688.3,3308.93,320.337,1.65806,180),
(@guid+56,@EGG,530,1,1,-3690.65,3306.77,320.43,-2.79253,180),
(@guid+57,@EGG,530,1,1,-3879.37,3665.22,374.393,-2.30383,180),
(@guid+58,@EGG,530,1,1,-3990.42,3139.13,372.878,-2.61799,180),
(@guid+59,@EGG,530,1,1,-3991.59,3134.33,372.703,-0.017453,180),
(@guid+60,@EGG,530,1,1,-3884.89,3684.98,374.492,-2.53073,180),
(@guid+61,@EGG,530,1,1,-3800.8,3789.62,314,6.0912,180),
(@guid+62,@EGG,530,1,1,-3799.02,3788.06,314.158,3.19395,180),
(@guid+63,@EGG,530,1,1,-3798.91,3790.61,313.852,3.63029,180);
