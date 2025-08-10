ALTER TABLE `game_tele` MODIFY `id` int UNSIGNED AUTO_INCREMENT;

-- Add teleport locations,make sure names are unique
DELETE FROM `game_tele` WHERE `name` IN ('AhnKahet','AhnQirajBacklands','AhnQirajThroneRoom','ArathiDwarvenFarm','BadlandsUnfinishedRegion','BehindGnomeregan','BlackcharCaveInside','BlackwingLairOutside','CrystalsongForest','DeathKnightStarterArea','DancingTrollVillage','DeadminesStrangePlace','DeeprunTramDeeprunDivers','DeeprunTramNessy','DeeprunTramUnderwaterLocation','EasternPlaguelandsUnfinishedRegion','ElwynnFalls','EyeOfEternity','ForgeOfSouls','GillijimsIsle',/*'Gilneas',*/'GrimBatolWatchPost','HallsOfLightning','HallsOfReflection','HallsOfStone','HyjalBlizzardConstructionCo','HyjalCaveInside','HyjalCaveOutside','HyjalCrater','HyjalJump','HyjalTheWorldTree','KarazhanCrypts','NaxxramasOutside','NewmansLanding','ObsidianSanctum','Oculus','OldIronForge','PitOfCriminals','PitOfSaron','QuelThalasShore','QuelThalasShoreTower','RubySanctum','SilithusSouthernFarm','SilithusUnfinishedRegion','ShadowfangKeepNotInstanced','StormwindPrison','StranglethornValeUnfinishedRegion','StratholmeOutside','TanarisSouthSeasIsland','TheCullingOfStratholme','TheForbiddingSeaIslands','TheStockade','TirisfalGladesUnfinishedRegion','TopOfBlackrockMountain','TrialOfTheCrusader','UlduarRaid','WetlandsDwarvenVillage','WetlandsHiddenSpot','ZulGurubAltarOfStorms','ZulGurubNotInstanced');
INSERT INTO `game_tele` (`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES 

-- Add missing dungeon/raid entrances
(-8779.9,834.349,94.6801,0.653013,0,'TheStockade'),
(3643.31,2036.51,1.78742,4.33919,571,'AhnKahet'),
(-8750.76,-4442.2,-199.26,4.37694,1,'TheCullingOfStratholme'),
(9182.92,-1384.82,1110.21,5.57779,571,'HallsOfLightning'),
(8921.91,-993.503,1039.41,1.55263,571,'HallsOfStone'),
(5630.44,1994.01,798.059,4.58756,571,'HallsOfReflection'),
(5598.74,2015.85,798.042,3.81001,571,'PitOfSaron'),
(3600.5,197.34,-113.76,5.29905,571,'RubySanctum'),
(3859.44,6989.85,152.041,5.79635,571,'EyeOfEternity'),
(5666.25,2009.2,798.041,5.43184,571,'ForgeOfSouls'),
(3457.11,262.394,-113.819,3.28258,571,'ObsidianSanctum'),
(3879.96,6984.62,106.312,3.19669,571,'Oculus'),
(8515.68,716.982,558.248,1.57315,571,'TrialOfTheCrusader'),
(9327.25,-1114.64,1245.15,0.002312,571,'UlduarRaid'),

-- Add some missing locations
(2358.17,-5663.21,426.027,5.31323,609,'DeathKnightStarterArea'),
(5474.07,39.7615,149.546,6.27193,571,'CrystalsongForest'),

-- Add some interesting locations and unfinished areas
(-4819.56,-974.088,464.709,3.963,0,'OldIronForge'),
-- (-1.33456,57.3787,-27.5507,1.56687,35,'StormwindPrison'),
(-11139.2,-1742.44,-29.7367,3.17689,0,'PitOfCriminals'),
(-9479,1783,49.94,6.09565,1,'AhnQirajBacklands'),
(-7347.62,-642.264,294.575,0.405538,0,'BlackcharCaveInside'),
(-7396.4,-1070.18,589.39,0.099237,469,'BlackwingLairOutside'),
(-1464.96,501.067,0,2.94009,36,'DeadminesStrangePlace'),
(74.5078,1184.51,-119.551,2.90473,369,'DeeprunTramDeeprunDivers'),
(-98.3923,1216.83,-122.163,1.48305,369,'DeeprunTramNessy'),
(-33.273,1234.09,-126.101,1.50661,369,'DeeprunTramUnderwaterLocation'),
-- (-13693.5,2806.3,-1.59534,1.65007,0,'GillijimsIsle'),
(3598,-4523,198.865,2.61805,533,'NaxxramasOutside'),
(-6376.91,1262.61,7.18831,2.23557,0,'NewmansLanding'),
(-202.557,1666.88,79.7641,2.61805,0,'ShadowfangKeepNotInstanced'),
(3176.63,-4039.28,105.464,3.3092,329,'StratholmeOutside'),
(-7465.29,-1080.31,896.78,5.76179,0,'TopOfBlackrockMountain'),
(-3857,-3485,597.64,3.3092,0,'WetlandsHiddenSpot'),
(-12031.9,-2583.71,-29.6474,2.99504,309,'ZulGurubAltarOfStorms'),
(-12332.5,-1859.81,130.321,2.99504,0,'ZulGurubNotInstanced'),
(-1849.54,-4149.05,9.8162,3.07668,0,'ArathiDwarvenFarm'),
-- (-987.068,1579.95,53.6713,3.05311,0,'Gilneas'),
-- (3638.48,-3584.03,47.5125,0.002514,0,'EasternPlaguelandsUnfinishedRegion'),
(-4074.75,-3397.44,375.381,2.85616,0,'GrimBatolWatchPost'),
(-10750.5,2432.04,6.14444,0.240715,1,'SilithusSouthernFarm'),
(-9678.11,1530.11,21.3024,0.240715,1,'SilithusUnfinishedRegion'),
(-13008,-1619.4,143.737,5.87988,0,'StranglethornValeUnfinishedRegion'),
(-9392.34,-4855.91,300.757,0.591072,0,'TheForbiddingSeaIslands'),
(2231.97,2242.84,110,0.5,0,'TirisfalGladesUnfinishedRegion'),
(-4031.92,-1411.13,156.758,0.429314,0,'WetlandsDwarvenVillage'),
-- (-7119.49,-4114.49,461.939,2.52239,0,'BadlandsUnfinishedRegion'),
-- (5475.99,-3728.73,1593.44,5.80284,1,'HyjalBlizzardConstructionCo'),
-- (5430.49,-2805.7,1516.44,3.89825,1,'HyjalCrater'),
-- (4857.47,-1791.17,1156.66,4.79909,1,'HyjalCaveInside'),
-- (4822.82,-1749.73,1162.03,5.47845,1,'HyjalCaveOutside'),
(5372.72,-3378.71,1656.47,5.27658,1,'HyjalTheWorldTree'),
(5234.35,-1219.99,1376.69,0.9464,1,'HyjalJump'),
(-8534.77,2009.38,100.721,3.51074,1,'AhnQirajThroneRoom'),
-- (-11805,-4754,6,0,1,'TanarisSouthSeasIsland'),
(7333,-1542,160.981,0,1,'DancingTrollVillage'),
(-5041,1014,396,0,0,'BehindGnomeregan'),
-- (3611.44,-2820.78,177.579,6.12813,0,'QuelThalasShore'),
(4296.04,-2763.72,16.268,0.51962,0,'QuelThalasShoreTower'),
(-11069,-1795,53.7249,0,0,'KarazhanCrypts'),
(-8322,-340,145,0,0,'ElwynnFalls');

-- Clean up: remove duplicates with typos
DELETE FROM `game_tele` WHERE `name` IN ('MuerderRow','MurderEow','MurderRow','SunctumOfTheSun','SanctumOfTheSun','Deathknell','Deathnell','CenarionHold','CenarioHold','TheScaradWalp','TheScarabWall','TowerOfIlgalar','TowerOfLlgalar','TheTempleOfAtalHakkar','TempleOfAtalHakkar','GrongolbaseCamp','GromgolBaseCamp','RavagedTwilightCapm','RavagedTwilightCamp','RuinsOfZulManwe','RuinsOfZulMamwe','BoulderfistOutpost','BoulderfistOuspost');
INSERT INTO `game_tele` (`position_x`,`position_y`,`position_z`,`orientation`,`map`,`name`) VALUES 
(9755.35,-7304.14,24.4126,0.426204,530,'MurderRow'),
(7169.99,-7082.62,56.1741,5.68364,530,'SanctumOfTheSun'),
(1843.5,1590,93.2971,3.08757,0,'Deathknell'),
(-6818.09,733.814,41.5661,2.3082,1,'CenarionHold'),
(-8098.67,1525.15,2.77194,3.01977,1,'TheScarabWall'),
(-9284.76,-3346.89,109.759,1.52871,0,'TowerOfIlgalar'),
(-10447.1,-3824.83,18.0678,6.07301,0,'TheTempleOfAtalHakkar'),
(-12388.9,172.578,2.83358,1.91753,0,'GromgolBaseCamp'),
(-6160.61,1746.37,24.2906,0.89614,1,'RavagedTwilightCamp'),
(-12901.5,-653.396,51.3323,4.29414,0,'RuinsOfZulMamwe'),
(-1197.66,-2130.17,61.2405,1.26105,0,'BoulderfistOutpost');
