-- A lot of missing npcs/gobs/quest relations/quests/phases etc..
-- http://www.wowwiki.com/Storm_Peaks_quests
-- http://www.wowwiki.com/Sons_of_Hodir
-- http://www.wowhead.com/faction=1119#comments:id=905880
SET @NJORMELD           := 30099; -- At Fjorn's Anvil
SET @NJORMELD2          := 30127; -- At Dun Niffelem
SET @SNORRI_NPC         := 30123; -- At Fjorn's Anvil
SET @SNORRI_MOUNT       := 30124; -- Snorri spell_click
SET @NPC_BUNNY          := 30122; -- Storm Peaks Anvil Bunny
SET @NPC_SR2            := 30120; -- Seething Revenant (phase 2)
SET @NPC_SR3            := 30387; -- Seething Revenant (phase 3)
SET @NPC_FGS            := 30121; -- Frost Giant Stormherald
SET @NPC_BR             := 30160; -- Brittle Revenant
SET @NPC_SOH2           := 30262; -- Son of Hodir (phase 2)
SET @NPC_BF             := 30320; -- Battlescarred Frostworg (phase 2)
SET @SM                 := 30260; -- Stoic Mammoth (phase 2)
SET @RJ                 := 30422; -- Roaming Jormungar
SET @WARBEAR            := 29918; -- Warbear Matriarch
SET @HYLDSMEET_WB       := 30174; -- Hyldsmeet Warbear
SET @BUNNY_SPEAR        := 30246; -- Dun Niffelem Spear Chain Bunny (Phase 2)
SET @F_WORG             := 30219; -- Ethereal Frostwarg
SET @SF_INFIL           := 30222; -- Stormforged Infiltrator

SET @NPC_THORIM2        := 30390; -- at Thunderfall
SET @NPC_THORIM3        := 30295; -- at Terrace of the Makers
-- Will be used in Hot and Cold
SET @SPELL_RIDE         := 55957; -- Ride Snorri
SET @SPELL_GATHER       := 56750; -- Gather Snow
SET @SPELL_THROW        := 56753; -- Throw Snowball
SET @SPELL_SLEEP        := 32951; -- Sleeping Sleep
SET @SPELL_WAKE         := 56752; -- Wake Snorri
SET @SPELL_KCtTM        := 56755; -- KC toTarget Master
SET @SPELL_KC           := 56754; -- Kill Credit, Seething Revenant
SET @F_REPUTATION       := 57048; -- Force Reputation
SET @SUMMON_SFINF       := 56325; -- Summon Stormforged Infiltrator

SET @GO_SNOWDRIFT       := 192075; -- Snowdrift
SET @GO_ANVIL1          := 192060; -- Fjorn's Anvil (at Fjorn's Anvil)
SET @GO_ANVIL2          := 192071; -- Fjorn's Anvil (at Dun Niffelem)
SET @GO_SPEAR           := 192079; -- Hodir's Spear
SET @GO_ARNGRIM         := 192524; -- Arngrim the Insatiable
SET @GO_HORN            := 192078; -- Hodir's Horn
SET @GO_WARG            := 300244; -- Corpse of the Fallen Worg (Spell focus)
SET @GO_GRANITE         := 191815; -- Granite Boulder
SET @GO_GRANITE2        := 191814; -- Granite Boulder
SET @QUEST1             := 12967; -- Battling the Elements
SET @QUEST2             := 12981; -- Hot and Cold
SET @QUEST3             := 13003; -- Thrusting Hodir's Spear
SET @QUEST4             := 13046; -- Feeding Arngrim
SET @QUEST5             := 12977; -- Blowing Hodir's Horn

SET @GUID_BUNNY1        := 63373;  -- 4 required NPC
SET @GUID_BUNNY2        := 129993;  -- 6 required NPC
SET @GUID_BUNNY         := 116620; -- 23 required NPC
SET @GUID               := 142335; -- 77 reqiured NPC
SET @OGUID              := 20918;  -- 17 requied GO
SET @GUID_GO            := 21065;  -- 20 required GO


DELETE FROM `gameobject` WHERE `id` IN (@GO_ANVIL1,@GO_ANVIL2,@GO_SNOWDRIFT,@GO_SPEAR,@GO_ARNGRIM,@GO_HORN,@GO_WARG,@GO_GRANITE,@GO_GRANITE2);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Making anvil visible in phase 1 just to be sure it can be seen
(@GUID_GO+0,@GO_ANVIL1,571,1,1+2+4,7217.072,-3645.753,819.4065,1.797689,0,0,0.782608,0.6225148,300,255,1),
(@GUID_GO+1,@GO_ANVIL2,571,1,4,7213.591,-2648.741,810.5506,0.2268925,0,0,0.113203,0.9935719,300,255,1),
--
(@GUID_GO+2,@GO_SNOWDRIFT,571,1,4,7218.64,-3529.71,828.539,-1.93732,0,0,-0.824127,0.566404,300,100,1),
(@GUID_GO+3,@GO_SNOWDRIFT,571,1,4,7201.17,-3556.13,828.03,2.18166,0,0,0.88701,0.461749,300,100,1),
(@GUID_GO+4,@GO_SNOWDRIFT,571,1,4,7230.44,-3555.63,841.772,1.85005,0,0,0.798636,0.601815,300,100,1),
(@GUID_GO+5,@GO_SNOWDRIFT,571,1,4,7169.6,-3615.71,830.249,-2.89724,0,0,-0.992546,0.121873,300,100,1),
(@GUID_GO+6,@GO_SNOWDRIFT,571,1,4,7121.83,-3542.56,835.008,-0.750491,0,0,-0.366501,0.930418,300,100,1),
(@GUID_GO+7,@GO_SNOWDRIFT,571,1,4,7131.5,-3584.22,840.195,-1.91986,0,0,-0.819151,0.573577,300,100,1),
(@GUID_GO+8,@GO_SNOWDRIFT,571,1,4,7162.55,-3582.66,830.36,1.11701,0,0,0.529919,0.848048,300,100,1),
(@GUID_GO+9,@GO_SNOWDRIFT,571,1,4,7176.21,-3511.2,833.381,1.93731,0,0,0.824125,0.566409,300,100,1),
(@GUID_GO+10,@GO_SNOWDRIFT,571,1,4,7148.73,-3559.17,830.36,-2.72271,0,0,-0.978147,0.207914,300,100,1),
(@GUID_GO+11,@GO_SNOWDRIFT,571,1,4,7165.47,-3639.53,832.157,0.890117,0,0,0.430511,0.902586,300,100,1),
(@GUID_GO+12,@GO_SPEAR,571,1,4,7309.3,-2782.45,869.824,-0.610864,0,0,-0.300705,0.953717,180,255,1),
(@GUID_GO+13,@GO_ARNGRIM,571,1,4,7355.87,-2962.37,912.502,1.74533,0,0,0.766045,0.642787,180,255,1),
(@GUID_GO+14,@GO_HORN,571,1,4,7142.23,-2723.25,787.769,-2.63544,0,0,-0.968147,0.250383,180,255,1),
(@GUID_GO+15,@GO_WARG, 571, 1, 4, 7161.11, -2228.79, 758.93, 5.72936, 0, 0, 0.273389, -0.961904, 300, 0, 1),
-- Additional GO's for Mending Fences
(@GUID_GO+16,@GO_GRANITE,571,1,1,7229.834,-3560.515,840.1581,4.97419,0,0,0,1,120,255,1), -- Granite Boulder (Area: Fjorn's Anvil)
(@GUID_GO+32,@GO_GRANITE,571,1,1,7170.086,-3644.12,830.1971,3.996807,0,0,0,1,120,255,1), -- Granite Boulder (Area: Fjorn's Anvil)
(@GUID_GO+33,@GO_GRANITE,571,1,1,7273.538,-3632.394,829.7211,0.4537851,0,0,0,1,120,255,1), -- Granite Boulder (Area: Fjorn's Anvil)
(@GUID_GO+34,@GO_GRANITE,571,1,1,7464.846,-3014.682,851.4673,5.253442,0,0,0,1,120,255,1); -- Granite Boulder (Area: Frostfield Lake

DELETE FROM `creature` WHERE `id` IN (@NJORMELD,@SNORRI_NPC,@NPC_BUNNY,@NPC_SR2,@NPC_FGS,@NPC_BR,@NPC_SR3,@NPC_SOH2,@NPC_BF,@SM,@RJ,@BUNNY_SPEAR,@NPC_THORIM3);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@NJORMELD,571,1,4,24531,0,7183.295,-3519.859,827.4118,0.03490658,300,0,0,50400,0,0,0,0,0),
(@GUID+1,@SNORRI_NPC,571,1,4,26772,0,7167.375,-3543.059,827.746,6.056293,300,0,0,50400,0,0,0,0,0),
(@GUID+2,@NPC_BUNNY,571,1,4,19595,0,7219.52,-3645.4,824.558,2.61799,300,0,0,4979,0,0,0,0,0),
(@GUID+3,@NPC_SR2,571,1,4,25680,0,7268.63,-3640.36,825.267,2.37365,120,5,0,12600,0,1,0,0,0),
(@GUID+4,@NPC_SR2,571,1,4,25680,0,7192.8,-3665,824.727,6.05783,120,5,0,12600,0,1,0,0,0),
(@GUID+5,@NPC_SR2,571,1,4,25680,0,7250.05,-3636.57,825.872,-1.4385,120,5,0,12600,0,1,0,0,0),
(@GUID+6,@NPC_SR2,571,1,4,25680,0,7201.55,-3622.78,823.52,5.55015,120,5,0,12600,0,1,0,0,0),
(@GUID+7,@NPC_SR2,571,1,4,25680,0,7223.84,-3676.14,828.727,2.17625,120,5,0,12600,0,1,0,0,0),
(@GUID+8,@NPC_FGS,571,1,4,24531,0,7201.98,-3624.42,823.542,5.13733,120,0,0,48700,0,0,0,0,0),
(@GUID+9,@NPC_FGS,571,1,4,24531,0,7251.04,-3644,823.097,3.15905,120,0,0,48700,0,0,0,0,0),
(@GUID+10,@NPC_FGS,571,1,4,24531,0,7220.33,-3671.06,823.633,1.67552,120,0,0,50400,0,0,0,0,0),
(@GUID+11,@NPC_BR,571,1,4,26698,0,7419.28,-3141.33,837.577,1.34635,300,0,0,12600,0,0,0,0,0),
(@GUID+12,@NPC_BR,571,1,4,26698,0,7359.13,-3103.31,837.534,4.17214,300,0,0,12600,0,2,0,0,0),
(@GUID+13,@NPC_BR,571,1,4,26698,0,7376.07,-3153.04,837.577,1.80255,300,0,0,12600,0,0,0,0,0),
(@GUID+14,@NPC_BR,571,1,4,26698,0,7315.46,-3179.34,837.617,1.60589,300,0,0,12600,0,0,0,0,0),
(@GUID+15,@NPC_BR,571,1,4,26698,0,7255.27,-3083.26,837.577,-2.07948,300,0,0,12600,0,0,0,0,0),
(@GUID+16,@NPC_BR,571,1,4,26698,0,7405.8,-3082.12,837.57,-0.036917,300,0,0,12600,0,0,0,0,0),
(@GUID+17,@NPC_BR,571,1,4,26698,0,7300.77,-3084.76,837.577,3.23101,300,0,0,12600,0,0,0,0,0),
(@GUID+18,@NPC_SR3,571,1,8,0,0,7231.77,-3648.91,823.616,5.67933,600,0,0,12600,0,0,0,0,0),
(@GUID+19,@NPC_SR3,571,1,8,0,0,7181.85,-3561.65,827.102,1.34394,600,0,0,12600,0,0,0,0,0),
(@GUID+20,@NPC_SR3,571,1,8,0,0,7171.87,-3564.23,826.705,1.05727,600,0,0,12600,0,0,0,0,0),
(@GUID+21,@NPC_SR3,571,1,8,0,0,7235.26,-3480.56,850.328,4.32905,600,0,0,12600,0,0,0,0,0),
(@GUID+22,@NPC_SR3,571,1,8,0,0,7190.62,-3549.54,827.918,1.28897,600,0,0,12600,0,0,0,0,0),
(@GUID+23,@NPC_SR3,571,1,8,0,0,7146.46,-3553.65,830.519,0.613523,600,0,0,12600,0,0,0,0,0),
(@GUID+24,@NPC_SR3,571,1,8,0,0,7209.96,-3426.8,839.399,1.92906,600,0,0,12600,0,0,0,0,0),
(@GUID+25,@NPC_SR3,571,1,8,0,0,7191.38,-3364.16,846.246,1.41463,600,0,0,12600,0,0,0,0,0),
(@GUID+26,@NPC_SR3,571,1,8,25680,0,7224.41,-3496.64,840.3,3.8813,300,0,0,12600,0,0,0,0,0),
(@GUID+27,@NPC_SOH2,571,1,4,24531,0,7200.93,-2751.15,777.517,1.58738,300,0,0,73050,0,0,0,0,0),
(@GUID+28,@NPC_SOH2,571,1,4,24531,0,7305.37,-2755.09,775.266,1.22173,300,0,0,73050,0,0,0,0,0),
(@GUID+29,@NPC_SOH2,571,1,4,24531,0,7316.17,-2635.26,814.969,3.28639,300,0,0,75600,0,0,0,0,0),
(@GUID+30,@NPC_SOH2,571,1,4,24531,0,7125.52,-2690.9,786.766,0.244346,300,0,0,75600,0,0,0,0,0),
(@GUID+31,@NPC_SOH2,571,1,4,24531,0,7126.99,-2749.76,786.682,0.261799,300,0,0,73050,0,0,0,0,0),
(@GUID+32,@NPC_SOH2,571,1,4,24531,0,7450.26,-2713.95,809.15,4.57385,300,0,0,73050,0,0,0,0,0),
(@GUID+33,@NPC_SOH2,571,1,4,24531,0,7241.71,-2883.89,824.505,5.93024,300,0,0,73050,0,2,0,0,0),
(@GUID+34,@NPC_SOH2,571,1,4,24531,0,7206.07,-2828.19,824.699,1.46608,300,0,0,73050,0,0,0,0,0),
(@GUID+35,@NPC_SOH2,571,1,4,24531,0,7327.04,-2396.17,749.132,0.84682,300,0,0,75600,0,0,0,0,0),
(@GUID+36,@NPC_SOH2,571,1,4,24531,0,7303.96,-2519.59,750.318,2.88288,300,0,0,75600,0,2,0,0,0),
(@GUID+37,@NPC_SOH2,571,1,4,24531,0,7419.77,-2885.54,823.037,1.64061,300,0,0,75600,0,0,0,0,0),
(@GUID+38,@NPC_SOH2,571,1,4,24531,0,7288.75,-2579.84,750.516,1.13446,300,0,0,75600,0,0,0,0,0),
(@GUID+39,@NPC_SOH2,571,1,4,24531,0,7239.24,-2638.54,753.62,5.48033,300,0,0,75600,0,0,0,0,0),
(@GUID+40,@NPC_SOH2,571,1,4,24531,0,7431.13,-2429.4,753.04,4.09782,300,0,0,73050,0,0,0,0,0),
(@GUID+41,@NPC_SOH2,571,1,4,24531,0,7394.44,-2524.73,749.249,5.16889,300,0,0,73050,0,2,0,0,0),
(@GUID+42,@NPC_SOH2,571,1,4,24531,0,7407.6,-2934.94,847.905,1.95477,300,0,0,75600,0,0,0,0,0),
(@GUID+43,@NPC_BF,571,1,4,26331,0,7401.46,-2522.13,749.245,5.24142,300,0,0,60875,0,2,0,0,0),
(@GUID+44,@NPC_BF,571,1,4,26331,0,7311.83,-2530.07,749.488,2.87671,300,0,0,60875,0,2,0,0,0),
(@GUID+45,@SM,571,1,4,0,0,7143.71,-2251.43,760.439,1.29097,300,0,0,11379,0,0,0,0,0),
(@GUID+46,@SM,571,1,4,27281,0,7172.8,-2257.74,759.628,1.11662,300,0,0,11379,0,0,0,0,0),
(@GUID+47,@SM,571,1,4,27281,0,7218.29,-2214.53,759.112,3.43747,300,0,0,11379,0,0,0,0,0),
(@GUID+48,@SM,571,1,4,27281,0,7164.95,-2214.65,758.563,4.15611,300,0,0,11379,0,0,0,0,0),
(@GUID+49,@SM,571,1,4,0,0,7105.5,-2211.86,759.098,0.688573,300,0,0,11379,0,0,0,0,0),
(@GUID+50,@SM,571,1,4,27281,0,7110.67,-2133.14,758.775,5.04282,300,0,0,11379,0,0,0,0,0),
(@GUID+51,@SM,571,1,4,27281,0,7071.03,-2168.81,760.815,0.91791,300,0,0,11379,0,0,0,0,0),
(@GUID+52,@SM,571,1,4,27281,0,7028.51,-2077.67,753.23,5.25331,300,0,0,11379,0,0,0,0,0),
(@GUID+53,@SM,571,1,4,27281,0,7106.01,-1988.13,771.455,4.35011,300,0,0,11379,0,0,0,0,0),
(@GUID+54,@SM,571,1,4,0,0,7041.36,-1981.59,776.354,0.266033,300,0,0,11379,0,0,0,0,0),
(@GUID+55,@SM,571,1,4,0,0,7133.88,-2039.53,771.902,3.57334,300,0,0,11379,0,0,0,0,0),
(@GUID+56,@SM,571,1,4,27281,0,7077.88,-2078.98,759.218,1.99469,300,0,0,11379,0,0,0,0,0),
(@GUID+57,@RJ,571,1,4,26262,0,7188.82,-2320.21,757.813,-1.87154,300,0,0,12175,0,0,0,0,0),
(@GUID+58,@RJ,571,1,4,26262,0,7250.3,-2342.8,751.68,0.851782,300,0,0,12600,0,0,0,0,0),
(@GUID+59,@RJ,571,1,4,26262,0,7149.57,-2163.88,761.147,2.97457,300,0,0,12600,0,0,0,0,0),
(@GUID+60,@RJ,571,1,4,26262,0,7194.98,-2195.57,761.949,-0.387345,300,0,0,12600,0,0,0,0,0),
(@GUID+61,@RJ,571,1,4,26262,0,7157.35,-2262.32,761.623,0.494206,300,0,0,12600,0,0,0,0,0),
(@GUID+62,@RJ,571,1,4,26262,0,7252.51,-2230.52,760.183,3.20023,300,0,0,12175,0,0,0,0,0),
(@GUID+63,@RJ,571,1,4,26262,0,7082.68,-2112.98,758.537,3.60123,300,0,0,12175,0,0,0,0,0),
(@GUID+64,@RJ,571,1,4,26262,0,7138.08,-2036.25,771.858,2.03839,300,0,0,12600,0,0,0,0,0),
(@GUID+65,@RJ,571,1,4,26262,0,7065.27,-2070.9,759.016,0.790229,300,0,0,12600,0,0,0,0,0),
(@GUID+66,@RJ,571,1,4,26262,0,7142.27,-2214.55,758.268,5.21568,300,0,0,12600,0,0,0,0,0),
(@GUID+67,@RJ,571,1,4,26262,0,7093.6,-2159.45,758.662,5.46951,300,0,0,12175,0,0,0,0,0),
(@GUID+68,@RJ,571,1,4,26262,0,7050.49,-2148.12,755.994,5.28631,300,0,0,12175,0,0,0,0,0),
(@GUID+69,@RJ,571,1,4,26262,0,7117.06,-2117.56,760.043,4.86823,300,0,0,12175,0,0,0,0,0),
(@GUID+70,@RJ,571,1,4,26262,0,7134.93,-2112.19,761.723,0.788161,300,0,0,12600,0,0,0,0,0),
(@GUID+71,@RJ,571,1,4,26262,0,7123.43,-2085.57,764.362,5.11831,300,0,0,12175,0,0,0,0,0),
(@GUID+72,@BUNNY_SPEAR,571,1,4,0,0,7266.99,-2753.76,870.875,6.23082,180,0,0,9215,0,0,0,0,0),
(@GUID+73,@BUNNY_SPEAR,571,1,4,0,0,7347.33,-2809.35,868.826,0.122173,180,0,0,9215,0,0,0,0,0),
(@GUID+74,@BUNNY_SPEAR,571,1,4,0,0,7215.59,-2712.18,894.848,0.034907,180,0,0,9215,0,0,0,0,0),
(@GUID+75,@BUNNY_SPEAR,571,1,4,0,0,7393.33,-2841.03,888.614,6.14356,180,0,0,9215,0,0,0,0,0),
(@GUID+76,@NPC_THORIM3,571,1,1,0,0,7762.389,-2159.516,1233.409,1.53589,300,0,0,13481,0,0,0,0,0);

UPDATE `creature_template` SET `npcflag`=`npcflag`|1|2,`faction_A`=2107,`faction_H`=2107 WHERE `entry`=@NJORMELD;
UPDATE `creature_template` SET `faction_A`=2107,`faction_H`=2107,`npcflag`=`npcflag`|16777216 WHERE `entry`=@SNORRI_NPC;
UPDATE `creature_template` SET `npcflag`=`npcflag`|33554688 WHERE `entry`=@NPC_BUNNY;
UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=0,`spell1`=@SPELL_GATHER,`spell2`=@SPELL_THROW,`spell5`=@SPELL_WAKE WHERE `entry`=@SNORRI_MOUNT;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=2124,`faction_H`=2124 WHERE `entry`=@NPC_SR2;
UPDATE `creature_template` SET `faction_A`=2107,`faction_H`=2107,`unit_flags`=`unit_flags`|131072 WHERE `entry`=@NPC_FGS;
UPDATE `creature_template` SET `gossip_menu_id`=10109 WHERE `entry`=@NPC_THORIM3;
UPDATE `creature_template` SET `spell1`=54459, `spell2`=54458, `spell3`=54460, `spell4`=0, `spell5`=0, `spell6`=0 WHERE  `entry`=@WARBEAR;
UPDATE `gameobject_template` SET `flags`=0 WHERE  `entry`=191814;
UPDATE `gameobject_template` SET `flags`=0 WHERE  `entry`=191815;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_WAKE;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_WAKE,-@SPELL_SLEEP,1,'Wake Snorri removes Sleeping Sleep');

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NJORMELD,@NJORMELD2,@SNORRI_NPC,@NPC_FGS,@NPC_THORIM3,@F_WORG);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@F_WORG,0,0x0,0x101,0,0, '31748'), -- Spirit Particles, big.
(@NJORMELD,0,0,0,0,0,'61208'),      -- Fjorn's Anvil - Quest Invisibility 3
(@NJORMELD2,0,0,0,0,0,'56768'),     -- Quest Invisibility Tier 1
(@SNORRI_NPC,0,0,0,0,0,'61208'),    -- Fjorn's Anvil - Quest Invisibility 3
(@NPC_FGS,0,0,0,0,0,'56568'),       -- Cooling Breath
(@NPC_THORIM3,0,0,0,0,0,'54500');   -- Quest Invisibility 1

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=@SNORRI_NPC;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=29375 AND `SourceEntry`=41556;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@SNORRI_NPC,@SPELL_RIDE,0,0,9,0,12967,0,0,0,0,'','Required quest active for spellclick'),
(1,29375,41556,0,0,9,0,12915,0,0,0,0,'','Drop Slag Covered Metal on quest Mending Fences taken'),
-- These next 2 conditions are not blizzlike (adding them for idiots that turn in Mending Fences without taking this item)
(1,29375,41556,0,1,8,0,12915,0,0,0,0,'','Drop Slag Covered Metal on quest Mending Fences rewarded'),
(1,29375,41556,0,2,14,0,12922,0,0,0,0,'','Stop dropping Slag Covered Metal on quest The Refiner''s Fire');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@SNORRI_NPC;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@SNORRI_NPC,@SPELL_RIDE,3,0);

DELETE FROM `creature_text` WHERE `entry`=@SNORRI_MOUNT;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SNORRI_MOUNT,0,0,'Oh, hello, little $r.',12,0,100,15,0,0,"Snorri text");

DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@NPC_SR2,@NPC_FGS);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@SNORRI_MOUNT,@NPC_SR2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Snorri (mount)
(@SNORRI_MOUNT,0,0,0,54,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snorri - Say text - On just spawned'),
(@SNORRI_MOUNT,0,1,0,60,0,100,0,30000,60000,30000,60000,11,@SPELL_SLEEP,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snorri - On Update -  Cast sleep self'),
(@SNORRI_MOUNT,0,2,0,8,0,100,0,@SPELL_KCtTM,0,0,0,11,@SPELL_KC,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snorri - On spellhit -  Cast spell on owner'),
-- Seething Revenant
(@NPC_SR2,0,0,0,0,0,100,0,3000,6000,7000,12000,11,56620,1,0,0,0,0,2,0,0,0,0,0,0,0,'Seething Revenant - In Combat - Cast Seething Flames'),
(@NPC_SR2,0,1,0,6,0,100,0,0,0,0,0,11,@SPELL_KCtTM,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seething Revenant - Cast KC - Target Master');

-- Quest relations
DELETE FROM `gameobject_questrelation` WHERE `id` IN (@GO_ANVIL2,@GO_SPEAR,@GO_ARNGRIM,@GO_HORN);
INSERT INTO `gameobject_questrelation` (`id`,`quest`) VALUES
(@GO_ANVIL2,@QUEST2),
(@GO_SPEAR,@QUEST3),
(@GO_ARNGRIM,@QUEST4),
(@GO_HORN,@QUEST5);

DELETE FROM `gameobject_involvedrelation` WHERE `id`IN (@GO_ANVIL2,@GO_SPEAR,@GO_ARNGRIM,@GO_HORN);
INSERT INTO `gameobject_involvedrelation` (`id`,`quest`) VALUES
(@GO_ANVIL2,@QUEST2),
(@GO_SPEAR,@QUEST3),
(@GO_ARNGRIM,@QUEST4),
(@GO_HORN,@QUEST5);

-- Quest progression linking
UPDATE `quest_template` SET `PrevQuestId`=13063 WHERE `id`=12900; -- Making a Harness
UPDATE `quest_template` SET `PrevQuestId`=12900 WHERE `id`=12983; -- The Last of Her Kind
UPDATE `quest_template` SET `PrevQuestId`=12900 WHERE `id`=12989; -- The Slithering Darkness
UPDATE `quest_template` SET `PrevQuestId`=12956 WHERE `id`=12924; -- Forging an Alliance
UPDATE `quest_template` SET `PrevQuestId`=13047 WHERE `id`=13109; -- Diametrically Opposed
UPDATE `quest_template` SET `PrevQuestId`=12967 WHERE `id`=12981; -- Hot and Cold
UPDATE `quest_template` SET `PrevQuestId`=12987 WHERE `id`=13006; -- Polishing the Helm
UPDATE `quest_template` SET `PrevQuestId`=13001 WHERE `id`=13003; -- Thrusting Hodir's Spear

-- Quest reputation conditions
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=21000 WHERE `id`=13046; -- Feeding Arngrim
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=9000 WHERE `id`=13003; -- Thrusting Hodir's Spear
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=9000 WHERE `id`=13001; -- Raising Hodir's Spear
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=9000 WHERE `id`=12994; -- Spy Hunter
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=13559; -- Hodir's Tribute
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=13421; -- Remember Everfrost!
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=13420; -- Everfrost
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=13006; -- Polishing the Helm
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=12987; -- Mounting Hodir's Helm
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=12985; -- Forging a Head
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=13011; -- Jormuttar is Soo Fat...
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=3000 WHERE `id`=12975; -- In Memoriam
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=0 WHERE `id`=12977;  -- Blowing Hodir's Horn
UPDATE `quest_template` SET `RequiredMinRepFaction`=1119,`RequiredMinRepValue`=0 WHERE `id`=12981;  -- Hot and Cold

UPDATE `quest_template` SET `ExclusiveGroup`=-13035 WHERE `id`=13035;   -- Loken's Lackeys
UPDATE `quest_template` SET `ExclusiveGroup`=-13035 WHERE `id`=13005;   -- The Earthen Oath
UPDATE `quest_template` SET `PrevQuestId`=13035 WHERE `id`=13047;       -- The Reckoning

DELETE FROM `gossip_menu` WHERE `entry` IN (9900,9898,9899,10109);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9900,13747),   -- King Jokkum gossip for quest Krolmir, Hammer of Storms
(9898,13748),   -- King Jokkum gossip for quest Krolmir, Hammer of Storms
(9899,13749),   -- King Jokkum gossip for quest Krolmir, Hammer of Storms
(10109,14034); -- Thorim at Terrace of the Makers

-- Npc Texts
DELETE FROM `npc_text` WHERE `id` IN (13747,13748,13749);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(13747,'You are permitted to visit our stronghold, little $r.$b$bDo not bring us dishonor!','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(13748,'I do not trust you enough to speak of such things.$b$bYou must respect the trials our people have endured, the burdens we have borne...$b$bPerhaps, if you were to bring great honor to Dun Niffelem, I would be inclined to share with you the knowledge of our people.','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),
(13749,'Very well, little $c.$b$bWhile there is much left for you to do to mend our relations with Thorim, I am compelled to share with you this one secret.$b$bSpeak to me again when you are ready to be shown that which you seek.','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);
-- Gossip menus
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9900,9899);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9900,0,0,'If it please you, King Jokkum, may I know what has become of Krolmir?',1,1,9898,0,0,0,NULL),
(9900,1,0,'If it please you, King Jokkum, may I know what has become of Krolmir?',1,1,9899,0,0,0,NULL),
(9899,0,0,'I am ready to be shown the fate of Krolmir,',1,1,0,0,0,0,NULL);
-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9900;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9900,1,0,0,8,0,13011,0,0,0,0,'','Show gossip if player has quest completed'),
(15,9900,0,0,0,8,0,13011,0,0,1,0,'','Show gossip if player doesn''t have quest completed');

-- Hot and Cold (12981)

SET @SPELL_ESSENCE        := 56099;    -- Throw Essence of Ice 
SET @SPELL_SSM            := 56073;     -- Summon Smoldering Scrap
SET @SPELL_SFIS           := 56101;     -- Summon Frozen Iron Scrap
SET @AURA_SMOKE           := 56118;     -- Smolder Smoke
SET @NPC_BUNNY2           := 30169;     -- Smoldering Scrap Bunny
SET @GO_SMOLDERING_SCRAP  := 192124;    -- Smoldering Scrap


DELETE FROM `creature` WHERE `id`=@NPC_BUNNY2;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID_BUNNY+0,@NPC_BUNNY2,571,1,8,1,0,7138.416,-3553.746,832.2787,4.694936,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+1,@NPC_BUNNY2,571,1,8,1,0,7191.637,-3490.598,833.993,0.2094395,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+2,@NPC_BUNNY2,571,1,8,1,0,7181.407,-3533.111,826.9557,3.211406,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+3,@NPC_BUNNY2,571,1,8,1,0,7178.466,-3558.917,827.0338,3.351032,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+4,@NPC_BUNNY2,571,1,8,1,0,7204.097,-3497.685,830.7673,2.635447,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+5,@NPC_BUNNY2,571,1,8,1,0,7232.065,-3474.279,850.7675,3.926991,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+6,@NPC_BUNNY2,571,1,8,1,0,7206.615,-3481.997,833.5632,3.281219,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+7,@NPC_BUNNY2,571,1,8,1,0,7192.001,-3386.612,846.4163,2.111848,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+8,@NPC_BUNNY2,571,1,8,1,0,7206.483,-3460.641,835.8506,3.909538,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+9,@NPC_BUNNY2,571,1,8,1,0,7227.852,-3415.956,840.174,1.553343,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+10,@NPC_BUNNY2,571,1,8,1,0,7222.42,-3441.838,837.1934,2.146755,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+11,@NPC_BUNNY2,571,1,8,1,0,7207.466,-3438.533,838.8736,2.897247,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+12,@NPC_BUNNY2,571,1,8,1,0,7217.787,-3378.616,846.7336,5.410521,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+13,@NPC_BUNNY2,571,1,8,1,0,7206.611,-3404.196,841.4804,4.223697,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+14,@NPC_BUNNY2,571,1,8,1,0,7248.638,-3625.245,826.9236,3.647738,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+15,@NPC_BUNNY2,571,1,8,1,0,7219.116,-3607.771,822.712,1.658063,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+16,@NPC_BUNNY2,571,1,8,1,0,7204.861,-3628.249,823.5885,4.223697,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+17,@NPC_BUNNY2,571,1,8,1,0,7196.265,-3652.629,823.5908,4.886922,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+18,@NPC_BUNNY2,571,1,8,1,0,7246.637,-3648.932,823.046,0.9948376,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+19,@NPC_BUNNY2,571,1,8,1,0,7236.381,-3678.733,822.8235,0.8726646,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+20,@NPC_BUNNY2,571,1,8,1,0,7192.001,-3386.612,846.4163,2.111848,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+21,@NPC_BUNNY2,571,1,8,1,0,7217.787,-3378.616,846.7336,5.410521,120,0,0,1,0,0,0,0,0),
(@GUID_BUNNY+22,@NPC_BUNNY2,571,1,8,1,0,7206.611,-3404.196,841.4804,4.223697,120,0,0,1,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_BUNNY2;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_BUNNY2,0,0,0,1,0,@AURA_SMOKE);

UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128 WHERE `entry`=@NPC_BUNNY2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_BUNNY2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_BUNNY2,0,0,0,11,0,100,0,0,0,0,0,11,@SPELL_SSM,0,0,0,0,0,1,0,0,0,0,0,0,0,'Smoldering Scrap Bunny - On spawn - Cast Summon Smoldering Scrap'),
(@NPC_BUNNY2,0,1,2,8,0,100,1,@SPELL_ESSENCE,0,0,0,99,3,0,0,0,0,0,20,@GO_SMOLDERING_SCRAP,1,0,0,0,0,0,'Smoldering Scrap Bunny- On spellhit - Set Go state 3'),
(@NPC_BUNNY2,0,2,3,61,0,100,0,0,0,0,0,11,@SPELL_SFIS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Smoldering Scrap Bunny - Link - Cast Summon Frozen Iron Scrap'),
(@NPC_BUNNY2,0,3,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Smoldering Scrap Bunny - Link - Despawn');

-- Spear Holder
-- Will be used with @SPELL_CHAIN
SET @BUNNY_SPEAR   := 30246; -- Dun Niffelem Spear Chain Bunny (Phase 2)
SET @SPELL_CHAIN   := 56379; -- Spear Chain Beam

UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`=4, `modelid1`=21342, `modelid2`=0 WHERE `entry`=30246;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=@BUNNY_SPEAR;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-142408,-142407);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-142408,0,0,0,60,0,100,0,0,1,20000,20000,11,@SPELL_CHAIN,0,0,0,0,0,10,142410,@BUNNY_SPEAR,0,0,0,0,0,'Chain Bunny - OOC - Cast Chain on bunny'),
(-142407,0,0,0,60,0,100,0,0,1,20000,20000,11,@SPELL_CHAIN,0,0,0,0,0,10,142409,@BUNNY_SPEAR,0,0,0,0,0,'Chain Bunny- OOC - Cast Chain on bunny');

-- Into the Pit
SET @SPELL_SMASH   := 54458;
SET @SPELL_DSHOUT  := 54459;
SET @SPELL_CHARGE  := 54460;

UPDATE `creature_template` SET `AIName`='SmartAI', `faction_A`=1125, `faction_H`=1125 WHERE  `entry`=@HYLDSMEET_WB;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@HYLDSMEET_WB;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HYLDSMEET_WB,0,0,0,0,0,100,0,3000,6000,7000,12000,11,@SPELL_SMASH,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Smash'),
(@HYLDSMEET_WB,0,1,0,0,0,100,0,1000,35000,70000,95000,11,@SPELL_DSHOUT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Demoralizing Shout'),
(@HYLDSMEET_WB,0,2,0,0,0,100,0,5000,9000,11000,17000,11,@SPELL_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hyldsmeet Warbear - In Combat - Cast Charge');

-- Spy Hunter
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE entry= @F_WORG;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@F_WORG,@F_WORG*100,@F_WORG*100+1,@F_WORG*100+2) AND `source_type`IN(0,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@F_WORG,0,0,1,54,0,100,0,0,0,0,0,87,@F_WORG*100,@F_WORG*100+1,@F_WORG*100+2,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg - Just summoned - Execute random Action Script'),
(@F_WORG,0,1,2,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg - On Link - Set Run'),
(@F_WORG,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg - On Link - Say 0'),
--
(@F_WORG*100,9,1,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,8,0,0,0,7149.648,-2189.751,759.320,0,'Ethereal Frostwarg  - On Script - Go to POS'),
(@F_WORG*100,9,2,0,0,0,100,0,1000,1000,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 1'),
(@F_WORG*100,9,3,0,0,0,100,0,7000,7000,7000,7000,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Random Movement'),
(@F_WORG*100,9,4,0,0,0,100,0,1000,1000,1000,1000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 2'),
(@F_WORG*100,9,5,0,0,0,100,0,1000,1000,1000,1000,11,@SUMMON_SFINF,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script -  Summon SFI'),
--
(@F_WORG*100+1,9,1,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,8,0,0,0,7220.366,-2228.265,758.8727,0,'Ethereal Frostwarg  - On Script - Go to POS'),
(@F_WORG*100+1,9,2,0,0,0,100,0,1000,1000,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 1'),
(@F_WORG*100+1,9,3,0,0,0,100,0,7000,7000,7000,7000,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Random Movement'),
(@F_WORG*100+1,9,4,0,0,0,100,0,1000,1000,1000,1000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 2'),
(@F_WORG*100+1,9,5,0,0,0,100,0,1000,1000,1000,1000,11,@SUMMON_SFINF,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Summon SFI'),
--
(@F_WORG*100+2,9,1,0,0,0,100,0,5000,5000,5000,5000,69,0,0,0,0,0,0,8,0,0,0,7181.581,-2264.689,758.043,0,'Ethereal Frostwarg  - On Script -  Summon SFI'),
(@F_WORG*100+2,9,2,0,0,0,100,0,1000,1000,1000,1000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 1'),
(@F_WORG*100+2,9,3,0,0,0,100,0,7000,7000,7000,7000,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Random Movement'),
(@F_WORG*100+2,9,4,0,0,0,100,0,1000,1000,1000,1000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Say 2'),
(@F_WORG*100+2,9,5,0,0,0,100,0,1000,1000,1000,1000,11,@SUMMON_SFINF,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ethereal Frostwarg  - On Script - Summon SFI');

DELETE FROM `creature_text` WHERE entry = @F_WORG;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@F_WORG, 0, 0, 'The worg sprints off in search of enemies.', 16, 0, 100, 0, 0, 1108, 'Ethereal Frostworg'),
(@F_WORG, 1, 0, 'The worg growls as it closes in on its prey.', 16, 0, 100, 0, 0, 0, 'Ethereal Frostworg'),
(@F_WORG, 2, 0, 'The frostworg howls, exposing its prey!', 16, 0, 100, 53, 0, 9036, 'Ethereal Frostworg');

/*SoH phasing progression
Since all npcs/gobs from @PHASE1 are using ingame phasemask 1,
won't use this spell to phase the area,because that would need all of them rephased
(as spell @PHASE1 is actually ingame phasemask 2)
*/

SET @PHASE1         := 55857; -- Phase Shift 1: Frost Giants 
SET @PHASE2         := 55858; -- Phase Shift 2: Frost Giants
SET @PHASE3         := 55952; -- Phase Shift 3: Fjorn's Anvil
SET @SPIKE          := 56305; -- See Quest Invisibility 1 (Ice Spike Bunny)
SET @QUEST_TIER1    := 56771; -- See Invisibility Tier 1
SET @FA             := 61209; -- Fjorn's Anvil - See Quest Invisibility 3
SET @BARGAIN1       := 55012; -- Lok'lira's Bargain
SET @BARGAIN2       := 72914; -- Lok'lira's Bargain
SET @SEE_INV        := 54502; -- See Quest Invisibility 1

SET @AREA0          := 4437; -- Valley of Ancient Winters
SET @AREA1          := 4438; -- Dun Niffelem
SET @AREA2          := 4439; -- Frostfield Lake
SET @AREA3          := 4495; -- Fjorn's Anvil
SET @AREA4          := 4440; -- Thunderfall
SET @AREA5          := 4446; -- Terrace of the Makers
SET @AREA6          := 4455; -- Hibernal Cavern 

-- P1 adds when taking Forging an Alliance (0,1,2,3,4)(0 ends disguise)
-- P2 starts with  Forging an Alliance (0,1,2,3,4)
-- P3 starts after turning in Forging an Alliance (3)
-- @PHASE1 added just as a reference, it won't be used
DELETE FROM `spell_area` WHERE `area` IN (@AREA0,@AREA1,@AREA2,@AREA3,@AREA4,@AREA5,@AREA5,@AREA6);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(@BARGAIN2, @AREA0, 12972, 13063, 0, 0, 2, 1, 74, 11),
(@BARGAIN1, @AREA0, 12972, 13063, 0, 0, 2, 1, 74, 11),
(@PHASE2, @AREA0, 12924, 0, 0, 0, 2, 1, 74, 11),
(@PHASE2, @AREA1, 12924, 0, 0, 0, 2, 1, 74, 11),
(@SPIKE, @AREA1, 12987, 12987, 0, 0, 2, 1, 74, 11),
(@QUEST_TIER1, @AREA1, 12967, 0, 0, 0, 2, 1, 64, 11),
(@PHASE3, @AREA3, 12924, 0, 0, 0, 2, 1, 64, 11),
(@PHASE2,@AREA6, 12924, 0, 0, 0, 2, 1, 74, 11),
(@PHASE2, @AREA4, 12924, 0, 0, 0, 2, 1, 74, 11),
(@PHASE2, @AREA2, 12924, 0, 0, 0, 2, 1, 74, 11),
(@BARGAIN1, @AREA1, 12856, 12856, 0, 0, 2, 1, 74, 11),
(@FA, @AREA3, 12924, 12924, 0, 0, 2, 1, 74, 11),
(@BARGAIN2, @AREA1, 12856, 12856, 0, 0, 2, 1, 74, 11),
(@PHASE2, @AREA3, 12924, 12924, 0, 0, 2, 1, 74, 11),
(@SEE_INV, @AREA5, 13057, 0, 0, 0, 2, 1, 74, 11);

-- Mending Fences
SET @SFIG             := 29375;   -- Stormforged Iron Giant
SET @S_EARTHEN        := 55528;   -- Summon Earthen Ironbane
SET @SHOCKWAVE        := 57741;   -- Shockwave

DELETE FROM `creature_equip_template` WHERE entry = 29927;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(29927, 1, 743, 0, 0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 55818;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`,`comment`) VALUES (55818, 55528, 0, 'Summon Earthen');
DELETE FROM `spell_scripts` WHERE `id`= 55818;
INSERT INTO `spell_scripts` (`id`, `command`, `datalong`, `datalong2`) VALUES (55818, 15, 55528, 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE entry = @SFIG;
UPDATE `creature_template` SET `faction_A`=2118,`faction_H`=2118,`unit_flags`=526336,`speed_run`=0.99206285714286 WHERE `entry`=29927; -- Earthen Ironbane
DELETE FROM `creature_ai_scripts` WHERE creature_id = @SFIG;
DELETE FROM `smart_scripts` WHERE entryorguid = 29375 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@SFIG, 0, 0, 0, 0, 0, 100, 0, 6000, 12000, 20000, 26000, 11, @SHOCKWAVE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormforged Iron Giant - In combat - Cast Shockwave'),
(@SFIG, 0, 1, 2, 8, 0, 100, 0, 55818, 0, 0, 0, 11, @S_EARTHEN, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormforged Iron Giant - On Spellhit - Summon Earthen Ironbane'),
(@SFIG, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, @S_EARTHEN, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormforged Iron Giant - On Spellhit - Summon Earthen Ironbane'),
(@SFIG, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, @S_EARTHEN, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormforged Iron Giant - On Spellhit - Summon Earthen Ironbane');

-- Forging a Head (12985)
SET @NPC            := 29914;   -- Dead Iron Giant
SET @SPELL          := 29266;   -- Permanent Feign Death
SET @SF_A           := 30208;   -- Stormforged Ambusher

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` =@NPC ; 
DELETE FROM `smart_scripts` WHERE entryorguid IN (@NPC,@NPC*100,@NPC*100+1) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@NPC, 0, 0, 0, 8, 0, 100, 0, 56227, 0, 0, 0, 88, @NPC*100,@NPC*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Run Random Script on Salvage Corpse Spell Hit'),
(@NPC, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Set Passive'),
(@NPC*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 56230, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Cast Create Fireforged Eyes'),
(@NPC*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Despawn'),
(@NPC*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @SF_A, 1, 60000, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Summon Stormforged Ambusher'),
(@NPC*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dead Iron Giant - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56227;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 56227, 0, 0, 31, 0, 3, 29914, 0, 0, 0, 0, '', 'Salvage Corpse can hit Dead Iron Giant');


DELETE FROM `creature_loot_template` WHERE entry = @SF_A;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(@SF_A, 42105, -33, 1, 0, 1, 1),
(@SF_A, 42423, -50, 1, 0, 1, 1);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=56562;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(56562, 56566, 0, 'Carve Bear Flank triggers create bear flank');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 17 AND `SourceEntry`= 56562;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 56562, 0, 0, 23, 0, 4455, 0, 0, 0, 0, 0, '', 'Carve Bear Flank only hits bear');

DELETE FROM `creature` WHERE `id`=@NPC AND `phaseMask`=4;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID_BUNNY2,@NPC,571,1,4,0,0,7429.23,-3187.91,837.452,0.19249,120,0,0,50400,0,0,0,0,0),
(@GUID_BUNNY2+1,@NPC,571,1,4,0,0,7359.28,-3176.45,837.452,1.31954,120,0,0,50400,0,0,0,0,0),
(@GUID_BUNNY2+2,@NPC,571,1,4,0,0,7280.03,-3142.9,837.452,4.41243,120,0,0,50400,0,0,0,0,0),
(@GUID_BUNNY2+3,@NPC,571,1,4,0,0,7515.58,-3137.05,837.452,5.47429,120,0,0,50400,0,0,0,0,0),
(@GUID_BUNNY2+4,@NPC,571,1,4,0,0,7509.03,-3225.78,837.432,2.03661,120,0,0,50400,0,0,0,0,0),
(@GUID_BUNNY2+5,@NPC,571,1,4,0,0,7259.32,-3221.84,837.452,1.06349,120,0,0,50400,0,0,0,0,0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+16;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,192187,571,1,4,7306.37,-2060.06,760.918,-3.11488,0,0,-0.999911,0.0133559,180,255,1),
(@OGUID+1,192188,571,1,4,7313.11,-2054.22,760.599,2.81615,0,0,0.98679,0.162004,180,255,1),
(@OGUID+2,192189,571,1,4,7313.61,-2054.12,761.261,0.711686,0,0,0.348381,0.937353,180,255,1),
(@OGUID+3,192190,571,1,4,7309.42,-2060.01,761.261,0.504564,0,0,0.249614,0.968345,180,255,1),
(@OGUID+4,192191,571,1,4,7320.77,-2041.83,760.599,2.81615,0,0,0.98679,0.162004,180,255,1),
(@OGUID+5,192192,571,1,4,7314.04,-2044.86,759.983,1.09942,0,0,0.52244,0.852676,180,255,1),
(@OGUID+6,192193,571,1,4,7325.57,-2044.47,760.737,-0.80439,0,0,-0.391439,0.920204,180,255,1),
(@OGUID+7,192194,571,1,4,7320.69,-2053.65,761.339,-0.80439,0,0,-0.391439,0.920204,180,255,1),
(@OGUID+8,192195,571,1,4,7321,-2054.29,760.9,-1.40123,0,0,-0.644688,0.764446,180,255,1),
-- Granite Boulders for "Mending Fences"
(@OGUID+9,191814,571,1,1,7337.647,-3049.821,841.3665,1.221729,0,0,0,1,120,255,1), -- Granite Boulder (Area: Dun Niffelem)
(@OGUID+10,191814,571,1,1,7254.236,-3021.713,846.6954,0.4886912,0,0,0,1,120,255,1), -- Granite Boulder (Area: Frostfield Lake)
(@OGUID+11,191814,571,1,1,7329.995,-3292.084,859.1428,5.550147,0,0,0,1,120,255,1), -- Granite Boulder (Area: Frostfield Lake)
(@OGUID+12,191814,571,1,1,7241.131,-3344.769,852.5411,1.692969,0,0,0,1,120,255,1), -- Granite Boulder (Area: Frostfield Lake)
(@OGUID+13,191814,571,1,1,7158.728,-3356.495,860.1804,4.433136,0,0,0,1,120,255,1), -- Granite Boulder (Area: Frostfield Lake)
(@OGUID+14,191814,571,1,1,7239.152,-3403.615,849.8006,2.35619,0,0,0,1,120,255,1), -- Granite Boulder (Area: Frostfield Lake)
(@OGUID+15,191814,571,1,1,7160.917,-3487.592,857.127,1.623156,0,0,0,1,120,255,1), -- Granite Boulder (Area: Fjorn's Anvil)
(@OGUID+16,191814,571,1,1,7207.494,-3539.533,827.2614,2.408554,0,0,0,1,120,255,1); -- Granite Boulder (Area: Fjorn's Anvil)

DELETE FROM `creature_loot_template` WHERE entry = @SM;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(@SM, 42104, -33, 1, 0, 1, 1),
(@SM, 42542, -29, 1, 0, 1, 1),
(@SM, 45912, 0.1, 1, 0, 1, 1);


UPDATE `spell_area` SET `quest_start`=12921 WHERE `spell` IN (55012,72914) AND `area`=4437; -- Valley of Ancient Winters
DELETE FROM `spell_area` WHERE `spell`=54784; -- Frost Reaction Frost Vrykul

-- Already spawned by TDB and visible in all phases
UPDATE `creature` SET `phaseMask`=1|2|4 WHERE `guid` IN (116761,116762,116763);

DELETE FROM `creature_addon` WHERE `guid` IN (116761,116762,116763);
DELETE FROM `creature_template_addon` WHERE `entry`=@NPC;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,0,0,0,0,0,@SPELL);

UPDATE `creature` SET `phaseMask`=1 WHERE  `guid`=152124;
UPDATE `gameobject` SET `phaseMask`=4 WHERE `id`=192081; -- Horn Fragment
