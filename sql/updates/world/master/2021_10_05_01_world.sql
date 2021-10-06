
SET @ID := 1689;

DELETE FROM `instance_template` WHERE `map` IN (1520, 1530, 1571, 1594, 1648, 1669, 1676, 1677, 1753, 1754, 1762, 1763, 1779, 1822, 1861, 2070, 2096, 2097, 2164, 2217);
INSERT INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1520, 0, '', 0), -- Emerald Nightmare
(1530, 0, '', 0), -- Nighthold
(1571, 0, '', 0), -- Court of Stars
(1594, 0, '', 0), -- The MOTHERLODE!!
(1648, 0, '', 0), -- Trial of Valor
(1669, 0, '', 0), -- Argus
(1676, 0, '', 0), -- Tomb of Sargeras
(1677, 0, '', 0), -- Cathedral of Eternal Night
(1753, 0, '', 0), -- Seat of Triumvirate
(1754, 0, '', 0), -- Freehold
(1762, 0, '', 0), -- Kings Rest
(1763, 0, '', 0), -- Ataldazar
(1779, 0, '', 0), -- Argus Invasion Points
(1822, 0, '', 0), -- Siege of Boralus
(1861, 0, '', 0), -- Uldir
(2070, 0, '', 0), -- Battle of Dazaralor
(2096, 0, '', 0), -- Crucible of Storms
(2097, 0, '', 0), -- Operation: Mechagon
(2164, 0, '', 0), -- Eternal Palace
(2217, 0, '', 0); -- Nyalotha

DELETE FROM `game_tele` WHERE (`id` BETWEEN @ID+0 AND @ID+67);
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(@ID +  0, -12635.5, -2819.78,  2475.47,   5.19324, 1669, 'TempleOfAnguish'),
(@ID +  1,     6382, -797.654,  1650.52,   5.96671, 1676, 'TombOfSargerasChamberOfTheAvatar'),   
(@ID +  2,  5837.07, -795.422,  2954.32,    6.2638, 1676, 'TombOfSargerasChamberOfTheMoon'),     
(@ID +  3,  6170.62, -967.469,  2891.91,    3.5306, 1676, 'TombOfSargerasTerraceOfTheMoon'),     
(@ID +  4,  5968.33, -1132.59,  2852.88,   1.22149, 1676, 'TombOfSargerasTheAbyssalThrone'),     
(@ID +  5,  6233.41, -795.194,  2959.68, 0.0316169, 1676, 'TombOfSargerasTheGuardiansSanctum'),  
(@ID +  6,  6541.97, -787.175,  1508.69,   6.26059, 1676, 'TombOfSargerasFelstormsBreach'),      
(@ID +  7,  4495.58, -1097.95,  5335.97,    4.7376, 1676, 'TombOfSargerasTheTwistingNether'),                  
(@ID +  8, -5646.25, -6504.49,  177.515,   5.38567, 1669, 'EscapeFromArgus'),                 
(@ID +  9,  1646.73,  1598.12,  107.126,   1.56215, 1208, 'GrimRail'),                           
(@ID + 10,  1231.91,  1713.28,  177.166,   2.98606, 1209, 'SkyReach'),                
(@ID + 11,     1054,     3529,  3.87887,   5.18085, 1571, 'CourtOfStarsDungeon'),                              
(@ID + 12,  3191.97,  2899.36,  639.659,   2.13033, 1477, 'HallsOfValorFenryr'),   
(@ID + 13,  7146.92,  7323.32,   13.791,   6.07021, 1492, 'MawOfSoulsDungeon'),           
(@ID + 14,  2857.08,  1086.72,  98.7189,  0.726489, 1458, 'NeltharionsLairDungeon'),                    
(@ID + 15,   5401.2,  10819.9,  20.4223,   5.29925, 1753, 'SeatOfTheTriumvirateDungeon'),               
(@ID + 16,  3522.29,  4804.85,  590.072,   3.14332, 1516, 'ArcwayDungeon'),                             
(@ID + 17,  4184.47,  -761.06,  269.521,   1.56861, 1493, 'VaultOfTheWardensDungeon'),      
(@ID + 18, -7717.58,  1419.89, -228.648,   4.92218, 1520, 'EmeraldNightmareClutchOfCorruption'), 
(@ID + 19,  1835.04,  1405.57,  363.912,   5.06747, 1520, 'EmeraldNightmareClutchOfCorruption1'),
(@ID + 20,    11552,    11293, -35.1025,   3.01366, 1520, 'EmeraldNightmareMulgore'),            
(@ID + 21, -12842.6,  12286.5, -253.006,    1.0423, 1520, 'EmeraldNightmareUngoro'),             
(@ID + 22,  583.973,   -12824,  5.50463,   2.34999, 1520, 'EmeraldNightmareDragons'),            
(@ID + 23, -2915.01,  3744.98,  94.3729,   5.66828, 1520, 'EmeraldNightmareAshenvale'),          
(@ID + 24,  -2776.7,  2486.09,  92.6233,  0.343259, 1520, 'EmeraldNightmareHinterlands'),        
(@ID + 25, -2986.85,  1337.07,  45.3371, 0.0448046, 1520, 'EmeraldNightmareDuskwood'),           
(@ID + 26, -4124.38,   191.81,  30.8498,    5.7193, 1520, 'EmeraldNightmareFeralas'),            
(@ID + 27, -12414.7, -13117.9,  324.203, 0.0919226, 1520, 'EmeraldNightmareGrizzlyHills'),       
(@ID + 28,  11370.5, -12670.5,      487,   4.62758, 1520, 'EmeraldNightmareMoonglade'),          
(@ID + 29, -2925.02, -5050.25,  147.706,   4.28199, 1520, 'EmeraldNightmareRiftOfAln'),          
(@ID + 30, -3028.77,   8466.5,  27.4185,   3.74792, 1520, 'EmeraldNightmareEmeraldDream'),   
(@ID + 31,  3610.12,   5604.6,  38.7932,    2.3287, 1648, 'TrialOfValor'),                       
(@ID + 32,  3189.44,  528.932,   633.15,   3.14551, 1648, 'TrialOfValorOdyn'),                   
(@ID + 33,  321.321,  319.541,  31.4491,   1.07598, 1648, 'TrialOfValorHelheim'),                
(@ID + 34,  465.436,  3376.46,  44.7613,   3.21228, 1530, 'NightHoldArcingDepths'),              
(@ID + 35, -124.518,  3506.91, -253.876,   5.49778, 1530, 'NightHoldNightwell'),                 
(@ID + 36,   235.63,  3184.06,  289.415,   5.62263, 1530, 'NightHoldElisandeQuarters'),          
(@ID + 37, -3416.06,  9527.61,  8.80324,  0.219028, 1712, 'Antorus'),                            
(@ID + 38, -2817.92,  10871.5,  139.478,   4.08714, 1712, 'AntorusGazeOfTheLegion'),             
(@ID + 39, -4306.63, -11161.1,  771.558,   5.90698, 1712, 'AntorusElunaria'),                      
(@ID + 40, -10574.7,  8779.27,  1871.47,   4.71238, 1712, 'AntorusTheExhaust'),                   
(@ID + 41, -12634.3, -3369.77,  2513.82,   1.56762, 1712, 'AntorusTheBurningThrone'),              
(@ID + 42, -3703.82, -1594.62,  634.295,   1.57944, 1712, 'AntorusHallsBounlessReach'),          
(@ID + 43,  2883.32, -4566.41,   291.96,   1.71831, 1712, 'AntorusSeatOfThePantheon'),           
(@ID + 44,  3136.79, -9635.33,  62.1518,   3.12024, 1712, 'AntorusVindicaar'), 
(@ID + 45,  4490.76,  6588.63,  42.0133,    3.1518, 1779, 'InvPointFolnuna'),                    
(@ID + 46,  5713.05, -1409.76,  29.9925,   3.83586, 1779, 'InvPointMeto'),                       
(@ID + 47,   5267.9, -9773.53,   10.521,   1.21419, 1779, 'InvPointAlluradel'),                  
(@ID + 48, -1384.46,  8353.95,  94.6257,    2.6389, 1779, 'InvPointSotanathor'),                 
(@ID + 49, -10034.3,  2793.49,  20.0162,   5.59592, 1779, 'InvPointOccularus'),                  
(@ID + 50, -9897.36, -4999.18,  129.274,  0.862324, 1779, 'InvPointVilemus'), 
(@ID + 51, -945.431,  2524.03,  833.583,   1.54564, 1762, 'KingsRestDungeon'),                          
(@ID + 52,  965.992, -386.025,  28.0247,   1.54564, 2097, 'MechagonDungeon'),                           
(@ID + 53,  1089.06, -617.785,  17.6689,   0.78325, 1822, 'SiegeOfBoralusDungeon'),                     
(@ID + 54,  654.604, -3645.94,  1.92823,   5.90058, 1594, 'MotherlodeDungeon'),                         
(@ID + 55, -375.973, -256.022,   1113.4, 0.0101462, 1861, 'UldirRaid'),             
(@ID + 56,    -2271,      803,  5.93201,   6.27085, 2070, 'BattleOfDazaralor'),                  
(@ID + 57, -6012.03,  2412.94,  14.8388,   0.55387, 2070, 'BattleOfDazaralorJaina'),             
(@ID + 58,  13384.6,   -13410,  41.0752,   4.67328, 2070, 'BatlleOfDazaralorBoralus'), 
(@ID + 59,  3404.45,  -1847.6,  108.529,  0.436058, 2096, 'CrucibleOfStorms'),                   
(@ID + 60,  3654.81, -1735.71,   -350.5,   1.47828, 2096, 'CrucibleOfStormsTendrilOfCorruption'),
(@ID + 61,  297.645, -124.401,  1471.01,   1.56075, 2164, 'EternalPalace'),                      
(@ID + 62,  216.937,  2432.95,  717.702,   1.62915, 2164, 'EternalPalaceAzshara'),               
(@ID + 63, -1805.67,  -43.656, -519.746,   6.27478, 2217, 'Nyalotha'),                         
(@ID + 64,   -11586,  9318.02,    124.8,   6.15693, 2217, 'NyalothaLocusOfTheInfiniteTruths'), 
(@ID + 65, -700.783,  2529.79,  332.085,   6.24878, 1677, 'CathedralOfEternalNight'),                      
(@ID + 66,  747.861,  1693.89,  596.794,  0.716915, 1669, 'Krokuun'),                            
(@ID + 67,  5682.25,  9919.45, -72.6483,   3.91304, 1669, 'MacAree'); 
