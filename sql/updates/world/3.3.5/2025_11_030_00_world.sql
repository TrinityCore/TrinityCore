--
UPDATE `gossip_menu_option` SET `MenuID` = 202 WHERE `MenuID` = 201;

UPDATE `smart_scripts` SET `action_param1` = 0, `action_param3` = 1 WHERE `entryorguid` = 3669 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param1` = 1, `action_param3` = 1 WHERE `entryorguid` = 3670 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param1` = 2, `action_param3` = 1 WHERE `entryorguid` = 3671 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 3673 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `action_param1` = 4, `action_param3` = 1 WHERE `entryorguid` = 3654 AND `source_type` = 0 AND `id` = 0;

UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 3678;

UPDATE `creature_template` SET `flags_extra` = `flags_extra` |512 WHERE `entry` IN (3678,3679);

DELETE FROM `creature_text` WHERE `CreatureID` IN (3678,3679);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3678,0,0,"At last! Naralex can be awakened! Come aid me, brave adventurers!",14,0,100,0,0,0,2101,0,"Disciple of Naralex SAY_ALL_DONE"),
(3678,1,0,"I must make the necessary preparations before the awakening ritual can begin. You must protect me!",12,0,100,1,0,0,1255,0,"Disciple of Naralex SAY_PROGRESS_1"),
(3678,2,0,"These caverns were once a temple of promise for regrowth in the Barrens. Now, they are the halls of nightmares.",12,0,100,1,0,0,1256,0,"Disciple of Naralex SAY_PROGRESS_2"),
(3678,3,0,"Come. We must continue. There is much to be done before we can pull Naralex from his nightmare.",12,0,100,25,0,0,1257,0,"Disciple of Naralex SAY_PROGRESS_3"),
(3678,4,0,"Within this circle of fire I must cast the spell to banish the spirits of the slain Fanglords.",12,0,100,0,0,0,1258,0,"Disciple of Naralex SAY_PROGRESS_4"),
(3678,5,0,"The caverns have been purified. To Naralex's chamber we go!",12,0,100,1,0,0,1259,0,"Disciple of Naralex SAY_PROGRESS_5"),
(3678,6,0,"Beyond this corridor, Naralex lies in fitful sleep. Let us go awaken him before it is too late.",12,0,100,25,0,0,1263,0,"Disciple of Naralex SAY_PROGRESS_6"),
(3678,7,0,"Protect me brave souls as I delve into the Emerald Dream to rescue Naralex and put an end to this corruption!",12,0,100,20,0,0,1264,0,"Disciple of Naralex SAY_PROGRESS_7"),
(3678,8,0,"%s begins to perform the awakening ritual on Naralex.",16,0,100,0,0,0,1265,0,"Disciple of Naralex SAY_PROGRESS_8"),
(3678,9,0,"At last! Naralex awakes from the nightmare.",12,0,100,25,0,0,1267,0,"Disciple of Naralex SAY_PROGRESS_9"),

(3678,10,0,"Attacked! Help get this $n off of me!",12,0,100,0,0,0,1273,0,"Disciple of Naralex SAY_AGGRO"),
(3678,10,1,"Deal with this $n! I need to prepare to awake Naralex!",12,0,100,0,0,0,1274,0,"Disciple of Naralex SAY_AGGRO"),
(3678,10,2,"I can't handle this $n alone! Help!",12,0,100,0,0,0,1275,0,"Disciple of Naralex SAY_AGGRO"),
(3678,10,3,"This $n is a minion from Naralex's nightmare no doubt!",12,0,100,0,0,0,1276,0,"Disciple of Naralex SAY_AGGRO"),
(3678,10,4,"Help!",12,0,100,0,0,0,1277,0,"Disciple of Naralex SAY_AGGRO"),

(3679,0,0,"%s tosses fitfully in troubled sleep.",16,0,100,0,0,0,1268,0,"Naralex EMOTE_AWAKENING_1"),
(3679,1,0,"%s writhes in agony. The Disciple seems to be breaking through.",16,0,100,0,0,0,1269,0,"Naralex EMOTE_AWAKENING_2"),
(3679,2,0,"%s dreams up a horrendous vision. Something stirs beneath the murky waters.",16,0,100,0,0,0,1270,0,"Naralex EMOTE_AWAKENING_3"),
(3679,3,0,"I AM AWAKE, AT LAST!",14,0,100,15,0,5789,1271,0,"Naralex SAY_AWAKENING_4"),
(3679,4,0,"Ah, to be pulled from the dreaded nightmare! I thank you, my loyal Disciple, along with your brave companions.",12,0,100,2,0,0,1272,0,"Naralex SAY_AWAKENING_5"),
(3679,5,0,"We must go and gather with the other Disciples. There is much work to be done before I can make another attempt to restore the Barrens. Farewell, brave souls!",12,0,100,1,0,0,2103,0,"Naralex SAY_AWAKENING_6");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 3678 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(3678,0,0,3636,-67.947014,206.72076,-93.50498,1.890911,6,300000,"Disciple of Naralex - Group 0 - Deviate Ravager"),
(3678,0,0,3636,-69.287880,211.94266,-93.44985,4.095106,6,300000,"Disciple of Naralex - Group 0 - Deviate Ravager"),

(3678,0,1,5048,-60.2539,273.098,-92.760864,0.40142572,6,300000,"Disciple of Naralex - Group 1 - Deviate Adder"),
(3678,0,1,5048,-50.1238,274.717,-92.760864,3.03687290,6,300000,"Disciple of Naralex - Group 1 - Deviate Adder"),
(3678,0,1,5048,-57.5453,280.207,-92.760864,5.07890800,6,300000,"Disciple of Naralex - Group 1 - Deviate Adder"),

(3678,0,2,5762,171.395,213.766,-105.507670,5.0440016,6,300000,"Disciple of Naralex - Group 2 - Deviate Moccasin"),
(3678,0,2,5762,171.690,213.234,-105.419660,1.6231562,6,300000,"Disciple of Naralex - Group 2 - Deviate Moccasin"),
(3678,0,2,5762,178.669,262.253,-106.152664,1.3264502,6,300000,"Disciple of Naralex - Group 2 - Deviate Moccasin"),

(3678,0,3,5763,125.646,169.517,-106.152664,0.94247776,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,155.845,186.688,-107.083664,0.05235988,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,162.067,218.715,-105.362660,1.98967530,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,96.7788,283.762,-104.785670,3.82227100,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,126.322,282.248,-103.797660,0.94247776,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,164.627,274.123,-107.297660,4.66002900,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),
(3678,0,3,5763,144.843,278.079,-104.574660,4.43313650,6,300000,"Disciple of Naralex - Group 3 - Nightmare Ectoplasm"),

(3678,0,4,3654,150.943,262.797,-103.90366,3.700098,6,300000,"Disciple of Naralex - Group 4 - Mutanus the Devourer");

DELETE FROM `waypoint_data` WHERE `id` = 29426;

DELETE FROM `waypoint_data` WHERE `id` IN (367800,367801,367802,367803,367804,367900);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(367800,1,-113.91917,142.769,-80.914154,NULL,0,0,0,100,0),
(367800,2,-111.23017,153.39638,-80.598915,NULL,0,0,0,100,0),
(367800,3,-110.97073,165.60736,-79.444725,NULL,0,0,0,100,0),
(367800,4,-109.30049,181.25143,-79.76007,NULL,0,0,0,100,0),
(367800,5,-110.1942,190.9626,-80.42993,NULL,0,0,0,100,0),
(367800,6,-109.58964,199.15425,-81.23881,NULL,0,0,0,100,0),
(367800,7,-110.56909,206.86935,-82.88934,NULL,0,0,0,100,0),
(367800,8,-110.30787,216.23227,-85.9362,NULL,0,0,0,100,0),
(367800,9,-108.06385,227.87166,-89.926414,NULL,0,0,0,100,0),
(367800,10,-104.28827,234.40804,-91.64163,NULL,0,0,0,100,0),

(367801,1,-99.53033,230.78362,-91.13202,NULL,0,0,0,100,0),
(367801,2,-97.78033,229.78362,-90.88202,NULL,0,0,0,100,0),
(367801,3,-95.03033,229.03362,-90.38202,NULL,0,0,0,100,0),
(367801,4,-93.78033,228.78362,-90.38202,NULL,0,0,0,100,0),
(367801,5,-91.78033,228.28362,-90.38202,NULL,0,0,0,100,0),
(367801,6,-90.78033,228.28362,-91.13202,NULL,0,0,0,100,0),
(367801,7,-87.28033,227.78362,-92.38202,NULL,0,0,0,100,0),
(367801,8,-85.272385,227.1592,-93.12241,NULL,0,0,0,100,0),
(367801,9,-81.619774,223.63588,-93.58602,NULL,0,0,0,100,0),
(367801,10,-71.02429,212.48766,-93.52011,NULL,0,0,0,100,0),
(367801,11,-66.8499,209.88943,-93.30499,NULL,0,0,0,100,0),
(367801,12,-61.41215,207.00401,-93.55031,NULL,0,0,0,100,0),
(367801,13,-49.681805,204.15556,-95.96281,NULL,0,0,0,100,0),
(367801,14,-41.188667,204.99422,-96.51606,NULL,0,0,0,100,0),
(367801,15,-35.381386,212.98494,-96.097084,NULL,0,0,0,100,0),
(367801,16,-33.46709,223.27979,-95.68127,NULL,0,0,0,100,0),
(367801,17,-31.874804,231.84636,-94.49322,NULL,0,0,0,100,0),
(367801,18,-33.1077,240.3214,-93.5856,NULL,0,0,0,100,0),
(367801,19,-38.079693,250.99289,-93.11742,NULL,0,0,0,100,0),
(367801,20,-43.072884,259.32315,-92.84188,NULL,0,0,0,100,0),
(367801,21,-54.713943,273.85025,-92.84426,NULL,0,0,0,100,0),

(367802,1,-49.880116,287.8062,-92.24503,NULL,0,0,0,100,0),
(367802,2,-47.99677,295.32455,-90.81826,NULL,0,0,0,100,0),
(367802,3,-38.468487,306.85004,-89.96177,NULL,0,0,0,100,0),
(367802,4,-34.199474,309.35944,-89.57565,NULL,0,0,0,100,0),
(367802,5,-23.514927,310.80438,-88.513176,NULL,0,0,0,100,0),
(367802,6,-9.611309,305.38797,-88.19709,NULL,0,0,0,100,0),
(367802,7,-3.915017,301.293,-86.814804,NULL,0,0,0,100,0),
(367802,8,-0.235204,294.51816,-85.46129,NULL,0,0,0,100,0),
(367802,9,3.204272,288.31448,-85.4905,NULL,0,0,0,100,0),
(367802,10,10.753059,278.38467,-85.8368,NULL,0,0,0,100,0),
(367802,11,16.977774,273.39676,-86.23834,NULL,0,0,0,100,0),
(367802,12,25.977861,264.6067,-86.788,NULL,0,0,0,100,0),
(367802,13,29.228964,257.175,-87.57598,NULL,0,0,0,100,0),
(367802,14,30.13821,248.86757,-87.36985,NULL,0,0,0,100,0),
(367802,15,38.86757,240.09755,-87.588615,NULL,0,0,0,100,0),
(367802,16,43.998184,234.17651,-87.98252,NULL,0,0,0,100,0),
(367802,17,48.403416,229.11066,-88.36456,NULL,0,0,0,100,0),
(367802,18,54.5601,210.85043,-89.80927,NULL,0,0,0,100,0),

(367803,1,67.69076,205.52835,-92.56347,NULL,0,0,0,100,0),
(367803,2,71.46944,206.84753,-93.108925,NULL,0,0,0,100,0),
(367803,3,77.15617,209.72255,-93.07799,NULL,0,0,0,100,0),
(367803,4,80.431854,214.86958,-93.177925,NULL,0,0,0,100,0),
(367803,5,83.29396,220.0915,-93.69437,NULL,0,0,0,100,0),
(367803,6,86.2444,225.64459,-94.54216,NULL,0,0,0,100,0),
(367803,7,89.99905,229.58038,-95.01256,NULL,0,0,0,100,0),
(367803,8,94.13328,232.7041,-95.36724,NULL,0,0,0,100,0),
(367803,9,99.00888,233.9866,-95.57549,NULL,0,0,0,100,0),
(367803,10,104.59536,233.409,-95.82651,NULL,0,0,0,100,0),
(367803,11,109.07845,232.6175,-96.046,NULL,0,0,0,100,0),
(367803,12,112.8708,233.57512,-96.32112,NULL,0,0,0,100,0),
(367803,13,114.51453,235.30222,-96.160706,NULL,0,0,0,100,0),
(367803,14,114.94154,237.7185,-96.02783,NULL,0,0,0,100,0),

(367804,1,119.04473,234.3336,-94.031525,NULL,0,1,0,100,0),
(367804,2,123.39298,232.1507,-93.80932,NULL,0,1,0,100,0),
(367804,3,129.23982,232.90259,-94.39268,NULL,0,1,0,100,0),
(367804,4,133.76927,236.9294,-95.39268,NULL,0,1,0,100,0),
(367804,5,136.03003,244.8155,-95.80936,NULL,0,1,0,100,0),
(367804,6,134.06624,253.92725,-95.1149,NULL,0,1,0,100,0),
(367804,7,123.16401,266.276,-93.587135,NULL,0,1,0,100,0),
(367804,8,113.3055,265.7754,-91.4482,NULL,0,1,0,100,0),
(367804,9,95.87152,250.9106,-87.55935,NULL,0,1,0,100,0),
(367804,10,87.43284,232.42879,-85.761505,NULL,0,1,0,100,0),
(367804,11,83.19081,218.43571,-84.08354,NULL,0,1,0,100,0),
(367804,12,70.24749,206.56226,-85.1376,NULL,0,1,0,100,0),
(367804,13,47.183872,206.66559,-83.493935,NULL,0,1,0,100,0),
(367804,14,34.54772,204.78317,-82.05306,NULL,0,1,0,100,0),
(367804,15,7.085161,202.25589,-77.79443,NULL,0,1,0,100,0),
(367804,16,-42.047256,203.44832,-83.76682,NULL,0,1,0,100,0),
(367804,17,-65.46242,208.19424,-83.76682,NULL,0,1,0,100,0),
(367804,18,-84.21845,225.56584,-83.76682,NULL,0,1,0,100,0),

(367900,1,117.57947,245.2589,-92.93683,NULL,0,1,0,100,0),
(367900,2,122.07437,244.77504,-91.96459,NULL,0,1,0,100,0),
(367900,3,126.5081,244.80745,-91.52022,NULL,0,1,0,100,0),
(367900,4,130.2855,244.1119,-91.49244,NULL,0,1,0,100,0),
(367900,5,131.33621,246.79683,-90.96464,NULL,0,1,0,100,0),
(367900,6,131.5437,250.70665,-90.85357,NULL,0,1,0,100,0),
(367900,7,131.16864,254.23598,-90.909134,NULL,0,1,0,100,0),
(367900,8,129.56184,256.8811,-90.77021,NULL,0,1,0,100,0),
(367900,9,125.7399,260.43616,-90.35347,NULL,0,1,0,100,0),
(367900,10,120.87533,261.45663,-91.15907,NULL,0,1,0,100,0),
(367900,11,116.536,261.01016,-91.46457,NULL,0,1,0,100,0),
(367900,12,107.43984,258.64542,-91.270226,NULL,0,1,0,100,0),
(367900,13,98.73815,250.1042,-90.18684,NULL,0,1,0,100,0),
(367900,14,91.52554,238.34152,-89.32576,NULL,0,1,0,100,0),
(367900,15,88.4579,228.32156,-88.59779,NULL,0,1,0,100,0),
(367900,16,83.84989,220.01965,-86.313835,NULL,0,1,0,100,0),
(367900,17,77.0841,211.77414,-84.73362,NULL,0,1,0,100,0),
(367900,18,67.49621,205.84052,-84.928276,NULL,0,1,0,100,0),
(367900,19,53.191616,205.93796,-84.08481,NULL,0,1,0,100,0),
(367900,20,33.344265,203.22813,-79.139854,NULL,0,1,0,100,0),
(367900,21,5.091723,198.6573,-71.71256,NULL,0,1,0,100,0),
(367900,22,-32.916367,204.26924,-83.12926,NULL,0,1,0,100,0),
(367900,23,-62.042313,206.22604,-83.12926,NULL,0,1,0,100,0);
