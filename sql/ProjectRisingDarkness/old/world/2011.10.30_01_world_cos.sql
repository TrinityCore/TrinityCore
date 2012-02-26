UPDATE `creature_template` SET `gossip_menu_id` = 907 WHERE `entry` = 26499;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_chromie' WHERE `entry` = 26527;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_cos_zombie' WHERE `entry` = 27737;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_infinite_corruptor' WHERE `entry` = 32273;

UPDATE `script_waypoint` SET location_x = 2449.32, location_y = 1191.09 WHERE entry = 26499 AND pointid = 26;

UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 20562;
UPDATE `creature_template` SET `unit_flags` = 320 WHERE `entry` IN (32273,32313);
UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 26499;

DELETE FROM `script_texts` WHERE entry BETWEEN -1595052 AND -1595048;
INSERT INTO `script_texts` (entry, content_default, content_loc6, content_loc7) VALUES
(-1595048, 'Scourge forces has been spotted at the King Square!', '¡Tropas de la plaga han sido avistadas en Plaza del Rey!.', content_loc6),
(-1595049, 'Scourge forces has been spotted near the Festival\'s Street fountain!', '¡Tropas de la plaga han sido avistadas cerca de la fuente de la Calle del Festival!.', content_loc6),
(-1595050, 'Scourge forces has been spotted near the Council!', '¡Tropas de la plaga han sido avistadas cerca del Concejo!.', content_loc6),
(-1595051, 'Scourge forces has been spotted near the King Square fountain!', '¡Tropas de la plaga han sido avistadas cerca de la fuente de la Plaza del Rey!.', content_loc6);

-- Exit AreaTrigger Teleport
UPDATE `areatrigger_teleport` SET id = 5181 WHERE id = 5148;

-- Spell: Robar Carne
DELETE FROM `spell_linked_spell` WHERE spell_trigger IN (-52708, 52708);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES('-52708','52711','0','Robar Carne');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES('52708','52712','0','Robar Carne');

-- Spawns del tramo final (Thx Locknes)
DELETE FROM `creature` WHERE `id` IN (27737,27729,27734,27736,28199,28200,28201,28249,28409,32273);

SET @GUID := 142600;

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
(@GUID+00,27737,595,3,1,25543,0,2319.89,1285.78,131.407,1.72169,60,10,0,630,0,1,0,0,0),
(@GUID+01,27737,595,3,1,10979,0,2308.12,1304.21,127.601,4.39662,60,10,0,630,0,1,0,0,0),
(@GUID+02,27737,595,3,1,25542,0,2335.47,1262.04,132.921,1.42079,60,10,0,630,0,1,0,0,0),
(@GUID+03,27737,595,3,1,25543,0,2297.73,1338.75,124.622,2.5574,60,10,0,630,0,1,0,0,0),
(@GUID+04,27737,595,3,1,10979,0,2322.65,1265.39,133.033,5.6524,60,10,0,630,0,1,0,0,0),
(@GUID+05,27737,595,3,1,10973,0,2277.83,1331.92,124.19,3.48045,60,10,0,630,0,1,0,0,0),
(@GUID+06,27737,595,3,1,25543,0,2294.18,1316.93,125.672,6.05649,60,10,0,630,0,1,0,0,0),
(@GUID+07,27737,595,3,1,10973,0,2310.56,1369,128.372,5.03364,60,10,0,630,0,1,0,0,0),
(@GUID+08,27737,595,3,1,10979,0,2306.15,1322.85,125.708,4.99133,60,10,0,630,0,1,0,0,0),
(@GUID+09,27737,595,3,1,10973,0,2320.14,1297.48,129.694,1.35248,60,10,0,630,0,1,0,0,0),
(@GUID+10,27737,595,3,1,25542,0,2291.57,1327.27,124.545,5.32358,60,10,0,630,0,1,0,0,0),
(@GUID+11,27737,595,3,1,25542,0,2308.04,1352.65,126.907,5.83741,60,10,0,630,0,1,0,0,0),
(@GUID+12,27737,595,3,1,10979,0,2329.44,1281.11,132.636,2.25207,60,10,0,630,0,1,0,0,0),
(@GUID+13,27737,595,3,1,0,0,2407.32,1423.8,131.522,6.24743,60,10,0,706,0,1,0,0,0),
(@GUID+14,27737,595,3,1,0,0,2417.26,1428.41,131.652,6.20423,60,10,0,730,0,1,0,0,0),
(@GUID+15,27737,595,3,1,0,0,2420.48,1419.99,130.716,0.0977616,60,10,0,706,0,1,0,0,0),
(@GUID+16,27737,595,3,1,0,0,2426.63,1413.41,130.464,0.404064,60,10,0,730,0,1,0,0,0),
(@GUID+17,27737,595,3,1,0,0,2430.46,1417.6,130.557,0.125247,60,10,0,730,0,1,0,0,0),
(@GUID+18,27737,595,3,1,0,0,2433.94,1427.03,131.18,0.0584885,60,10,0,706,0,1,0,0,0),
(@GUID+19,27737,595,3,1,0,0,2446.5,1428.37,131.013,6.10606,60,10,0,756,0,1,0,0,0),
(@GUID+20,27737,595,3,1,0,0,2449.49,1423.35,130.588,5.77619,60,10,0,706,0,1,0,0,0),
(@GUID+21,27737,595,3,1,0,0,2441.92,1424.41,130.606,6.07857,60,10,0,706,0,1,0,0,0),
(@GUID+22,27737,595,3,1,0,0,2450.6,1438.61,132.213,4.74889,60,10,0,730,0,1,0,0,0),
(@GUID+23,27737,595,3,1,0,0,2460.17,1436.46,131.501,4.73711,60,10,0,756,0,1,0,0,0),
(@GUID+24,27737,595,3,1,0,0,2444.68,1421.68,130.324,6.01338,60,10,0,756,0,1,0,0,0),
(@GUID+25,27737,595,3,1,0,0,2456.87,1419.07,130.488,5.39763,60,10,0,706,0,1,0,0,0),
(@GUID+26,27737,595,3,1,0,0,2464.27,1422.15,130.976,5.22092,60,10,0,756,0,1,0,0,0),
(@GUID+27,27737,595,3,1,0,0,2468.21,1403.06,130.39,5.6364,60,10,0,756,0,1,0,0,0),
(@GUID+28,27737,595,3,1,0,0,2460.88,1406.8,130.508,5.96234,60,10,0,756,0,1,0,0,0),
(@GUID+29,27737,595,3,1,0,0,2485.77,1398.35,130.795,4.71591,60,10,0,756,0,1,0,0,0),
(@GUID+30,27737,595,3,1,0,0,2485.79,1380.46,130.15,5.02928,60,10,0,730,0,1,0,0,0),
(@GUID+31,27737,595,3,1,0,0,2475.77,1396.31,130.124,4.84079,60,10,0,730,0,1,0,0,0),
(@GUID+32,27737,595,3,1,0,0,2476.92,1387.21,129.401,5.05128,60,10,0,730,0,1,0,0,0),
(@GUID+33,27737,595,3,1,0,0,2483.24,1389.37,130.123,4.74104,60,10,0,730,0,1,0,0,0),
(@GUID+34,27737,595,3,1,0,0,2480.2,1370.15,129.533,5.79583,60,10,0,706,0,1,0,0,0),
(@GUID+35,27737,595,3,1,0,0,2481.54,1375.11,129.642,5.4644,60,10,0,730,0,1,0,0,0),
(@GUID+36,27737,595,3,1,0,0,2489.44,1359.42,131.233,5.378,60,10,0,730,0,1,0,0,0),
(@GUID+37,27737,595,3,1,0,0,2486.59,1356.19,131.876,5.7275,60,10,0,756,0,1,0,0,0),
(@GUID+38,27737,595,3,1,0,0,2495.53,1348.61,133.072,5.52722,60,10,0,730,0,1,0,0,0),
(@GUID+39,27737,595,3,1,0,0,2504.48,1349.65,132.856,5.11881,60,10,0,730,0,1,0,0,0),
(@GUID+40,27737,595,3,1,0,0,2493.11,1380.29,130.24,4.93189,60,10,0,706,0,1,0,0,0),
(@GUID+41,27737,595,3,1,0,0,2487.18,1392.64,130.512,4.93818,60,10,0,706,0,1,0,0,0),
(@GUID+42,27737,595,3,1,0,0,2506.49,1336.89,132.794,5.19343,60,10,0,756,0,1,0,0,0),
(@GUID+43,27737,595,3,1,0,0,2518.2,1306.39,130.623,4.81723,60,10,0,756,0,1,0,0,0),
(@GUID+44,27737,595,3,1,0,0,2513.4,1299.67,130.868,4.4206,60,10,0,756,0,1,0,0,0),
(@GUID+45,27737,595,3,1,0,0,2511.45,1291.47,130.808,5.00729,60,10,0,756,0,1,0,0,0),
(@GUID+46,27737,595,3,1,0,0,2518.56,1292.32,130.528,5.16438,60,10,0,756,0,1,0,0,0),
(@GUID+47,27737,595,3,1,0,0,2515.49,1279.85,129.214,5.28847,60,10,0,730,0,1,0,0,0),
(@GUID+48,27737,595,3,1,0,0,2514.37,1285.92,129.934,5.70473,60,10,0,706,0,1,0,0,0),
(@GUID+49,27737,595,3,1,0,0,2522.65,1274.29,128.576,5.44634,60,10,0,706,0,1,0,0,0),
(@GUID+50,27737,595,3,1,0,0,2535.38,1275.77,127.42,5.49817,60,10,0,756,0,1,0,0,0),
(@GUID+51,27737,595,3,1,0,0,2537.59,1273.1,127.05,5.02693,60,10,0,730,0,1,0,0,0),
(@GUID+52,27737,595,3,1,0,0,2547.49,1261.7,126.44,4.78425,60,10,0,730,0,1,0,0,0),
(@GUID+53,27737,595,3,1,0,0,2534.36,1261.06,127.125,4.3994,60,10,0,756,0,1,0,0,0),
(@GUID+54,27737,595,3,1,0,0,2532.69,1251.44,127.452,5.4479,60,10,0,730,0,1,0,0,0),
(@GUID+55,27737,595,3,1,0,0,2551.84,1252.35,125.455,5.04342,60,10,0,706,0,1,0,0,0),
(@GUID+56,27737,595,3,1,0,0,2536.1,1244,126.928,5.16515,60,10,0,756,0,1,0,0,0),
(@GUID+57,27737,595,3,1,0,0,2543.63,1247.23,126.131,5.19735,60,10,0,706,0,1,0,0,0),
(@GUID+58,27737,595,3,1,0,0,2554.21,1238.95,125.475,4.64836,60,10,0,730,0,1,0,0,0),
(@GUID+59,27737,595,3,1,0,0,2548.89,1227.37,126.375,5.31517,60,10,0,756,0,1,0,0,0),
(@GUID+60,27737,595,3,1,0,0,2560.46,1225.4,125.496,4.85335,60,10,0,706,0,1,0,0,0),
(@GUID+61,27737,595,3,1,0,0,2555.11,1218.55,125.944,5.11646,60,10,0,730,0,1,0,0,0),
(@GUID+62,27737,595,3,1,0,0,2561.91,1211.56,125.38,5.5877,60,10,0,730,0,1,0,0,0),
(@GUID+63,27737,595,3,1,0,0,2568.67,1202.96,125.509,4.96095,60,10,0,756,0,1,0,0,0),
(@GUID+64,27737,595,3,1,0,0,2571.93,1193.48,125.619,5.07641,60,10,0,756,0,1,0,0,0),
(@GUID+65,27737,595,3,1,0,0,2577.77,1180.88,125.562,4.64522,60,10,0,756,0,1,0,0,0),
(@GUID+66,27737,595,3,1,0,0,2574.2,1166.63,126.089,4.44966,60,10,0,706,0,1,0,0,0),
(@GUID+67,27737,595,3,1,0,0,2564.78,1166.82,127.092,4.2266,60,10,0,756,0,1,0,0,0),
(@GUID+68,27737,595,3,1,0,0,2577.56,1158.41,126.385,4.07738,60,10,0,756,0,1,0,0,0),
(@GUID+69,27737,595,3,1,0,0,2567.93,1176.56,126.2,4.7489,60,10,0,706,0,1,0,0,0),
(@GUID+70,27737,595,3,1,0,0,2559.28,1189.46,126.642,4.73319,60,10,0,756,0,1,0,0,0),
(@GUID+71,27737,595,3,1,0,0,2554.14,1213.37,126.599,5.13845,60,10,0,706,0,1,0,0,0),
(@GUID+72,27737,595,3,1,0,0,2560.58,1218.48,125.281,4.97351,60,10,0,730,0,1,0,0,0),
(@GUID+73,27737,595,3,1,0,0,2570.2,1170.58,126.311,4.64365,60,10,0,756,0,1,0,0,0),

(@GUID+74,27729,595,3,1,0,0,2496.57,1354.66,132.217,5.13691,120,5,0,63000,0,1,0,0,0),
(@GUID+75,27729,595,3,1,0,0,2494.22,1365.17,130.812,5.15654,120,5,0,63000,0,1,0,0,0),
(@GUID+76,27729,595,3,1,0,0,2440.41,1434.46,131.456,5.69372,120,5,0,63000,0,1,0,0,0),
(@GUID+77,27729,595,3,1,0,0,2433.18,1421.13,130.644,0.046706,120,5,0,63000,0,1,0,0,0),
(@GUID+78,27734,595,3,1,0,0,2546.07,1239.17,125.945,5.07801,120,5,0,63000,0,1,0,0,0),
(@GUID+79,27734,595,3,1,0,0,2458.58,1426.22,131.056,5.42984,120,5,0,63000,0,1,0,0,0),
(@GUID+80,27736,595,3,1,0,0,2488.11,1364.91,130.402,5.35524,120,5,0,130330,0,1,0,0,0),
(@GUID+81,28199,595,3,1,0,0,2527.63,1267.59,128.168,5.12906,120,5,0,63000,0,1,0,0,0),
(@GUID+82,28199,595,3,1,0,0,2528.06,1284.34,128.877,5.14869,120,5,0,63000,0,1,0,0,0),
(@GUID+83,28199,595,3,1,0,0,2466.27,1414.57,130.977,5.18637,120,5,0,63000,0,1,0,0,0),
(@GUID+84,28200,595,3,1,0,0,2570.51,1181.4,125.809,4.61855,120,5,0,50400,44070,1,0,0,0),
(@GUID+85,28200,595,3,1,0,0,2560.45,1202.05,126.031,4.85417,120,5,0,50400,44070,1,0,0,0),
(@GUID+86,28200,595,3,1,0,0,2487.85,1373.29,130.236,5.078,120,5,0,50400,44070,1,0,0,0),
(@GUID+87,28200,595,3,1,0,0,2416.7,1416.52,130.379,0.191224,120,5,0,50400,44070,1,0,0,0),
(@GUID+88,28200,595,3,1,0,0,2424.42,1422.68,130.868,0.25327,120,5,0,50400,44070,1,0,0,0),
(@GUID+89,28201,595,3,1,0,0,2540.67,1254.82,126.274,4.97198,120,5,0,130330,0,1,0,0,0),
(@GUID+90,28201,595,3,1,0,0,2410.03,1417.19,130.577,0.191229,120,5,0,130330,0,1,0,0,0),
(@GUID+91,28249,595,3,1,0,0,2562.66,1177.9,126.716,4.77171,120,5,0,63000,0,1,0,0,0),
(@GUID+92,28249,595,3,1,0,0,2566.72,1190.41,125.837,4.7992,120,5,0,63000,0,1,0,0,0),
(@GUID+93,28249,595,3,1,0,0,2472.34,1404.76,130.752,5.20601,120,5,0,63000,0,1,0,0,0),
(@GUID+94,28249,595,3,1,0,0,2460.59,1413.26,130.46,5.4377,120,5,0,63000,0,1,0,0,0),
(@GUID+95,28249,595,3,1,0,0,2415.04,1423.52,131.111,0.214785,120,5,0,63000,0,1,0,0,0);

-- Traducciones al ESPAÑxOL
UPDATE `script_texts`
SET content_loc6 = 'Me alegra que lo consiguieras Uther.', content_loc7 = content_loc6
WHERE entry = -1595070;

UPDATE `script_texts`
SET content_loc6 = 'Controla tu tono cuando te dirijas a mi, chico. Puede que seas el principe, ¡pero yo sigo siendo tu superior como paladín!', content_loc7 = content_loc6
WHERE entry = -1595071;

UPDATE `script_texts`
SET content_loc6 = 'Ojalá pudiera olvidarlo. Mira, Uther, hay algo acerca de la Plaga que debes saber...', content_loc7 = content_loc6
WHERE entry = -1595072;

UPDATE `script_texts`
SET content_loc6 = 'Oh, no. Es demasiado tarde. ¡Todas estas personas han sido infectadas! Puede que ahora parezcan normales, pero solo es cuestión de tiempo que se conviertan en no-muertos.', content_loc7 = content_loc6
WHERE entry = -1595073;

UPDATE `script_texts`
SET content_loc6 = '¿Qué?', content_loc7 = content_loc6
WHERE entry = -1595074;

UPDATE `script_texts`
SET content_loc6 = 'Esta ciudad debe ser purgada.', content_loc7 = content_loc6
WHERE entry = -1595075;

UPDATE `script_texts`
SET content_loc6 = '¡Cómo puedes siquiera pensar eso? Tiene que haber otra opción.', content_loc7 = content_loc6
WHERE entry = -1595076;

UPDATE `script_texts`
SET content_loc6 = '¡Máldita sea, Uther! ¡Como tu futuro rey te ordeno que purgues esta ciudad!', content_loc7 = content_loc6
WHERE entry = -1595077;

UPDATE `script_texts`
SET content_loc6 = '¡Todavía no eres mi rey, chico! ¡Y tampoco obedecería esa orden si lo fueras!', content_loc7 = content_loc6
WHERE entry = -1595078;

UPDATE `script_texts`
SET content_loc6 = 'Entonces debo considerar esto un acto de traición.', content_loc7 = content_loc6
WHERE entry = -1595079;

UPDATE `script_texts`
SET content_loc6 = '¿Traición? ¿Has perdido el juicio, Arthas?', content_loc7 = content_loc6
WHERE entry = -1595080;

UPDATE `script_texts`
SET content_loc6 = '¿Eso crees? Lord Uther, ¡por mi derecho a la sucesión del trono y la soberanía de mi corona, quedas destutido de tu rango y suspendo a tus paladines del servicio!', content_loc7 = content_loc6
WHERE entry = -1595081;

UPDATE `script_texts`
SET content_loc6 = '¡Arthas! No puedes...', content_loc7 = content_loc6
WHERE entry = -1595082;

UPDATE `script_texts`
SET content_loc6 = '¡Esta hecho! Aquellos que tengais el valor para salvar esta tierra, ¡seguidme! El resto, ¡salid de mi vista!', content_loc7 = content_loc6
WHERE entry = -1595083;

UPDATE `script_texts`
SET content_loc6 = 'Acabas de cruzar un límite terrible, Arthas.', content_loc7 = content_loc6
WHERE entry = -1595084;

UPDATE `script_texts`
SET content_loc6 = '¿Jaina?', content_loc7 = content_loc6
WHERE entry = -1595085;

UPDATE `script_texts`
SET content_loc6 = 'Lo siento, Arthas. No puedo verte hacer esto.', content_loc7 = content_loc6
WHERE entry = -1595086;

UPDATE `script_texts`
SET content_loc6 = 'Tomad esta posición, y yo lideraré un pequeño grupo a Stratholme para comenzar la matanza. ¡Debemos contener y purgar a los infectados por el bien de todo Lordaeron!', content_loc7 = content_loc6
WHERE entry = -1595087;

UPDATE `script_texts`
SET content_loc6 = 'Parece que todo el mundo esta listo. Recordad, todas estas personas estan infectadas y pronto morirán. Debemos purgar Stratholme para proteger de la Plaga lo que queda de Lordaeron. Vamos.', content_loc7 = content_loc6
WHERE entry = -1595088;

UPDATE `script_texts`
SET content_loc6 = 'Principe Arthas, ¡alabada sea la Luz! Mucha gente en la ciudad ha comenzado a caer gravemente enferma. ¿Puede ayudarnos?', content_loc7 = content_loc6
WHERE entry = -1595089;

UPDATE `script_texts`
SET content_loc6 = 'Solo puedo ayudarte con una muerte limpia.', content_loc7 = content_loc6
WHERE entry = -1595090;

UPDATE `script_texts`
SET content_loc6 = '¿Qué? ¡Esto no puede estar pasando!', content_loc7 = content_loc6
WHERE entry = -1595091;

UPDATE `script_texts`
SET content_loc6 = 'Eso fue solo el comienzo.', content_loc7 = content_loc6
WHERE entry = -1595092;

UPDATE `script_texts`
SET content_loc6 = '¡No lo permitiré Mal\'Ganis! ¡Será mejor que esta gente muera a mis manos a que sean tus esclavos en la muerte!', content_loc7 = content_loc6
WHERE entry = -1595093;

UPDATE `script_texts`
SET content_loc6 = 'Mal\'Ganis enviará algunas de sus tropas de la Plaga. Los que tengais el acero y la magia mas fuertes ireis a acabar con ellos. Yo guiaré al resto de tropas para continuar con la purga.', content_loc7 = content_loc6
WHERE entry = -1595094;

UPDATE `script_texts`
SET content_loc6 = '¡Campeones, reunios conmigo en el Concejo! Debemos enfrentarnos a Mal\'Ganis', content_loc7 = content_loc6
WHERE entry = -1595095;

UPDATE `script_texts`
SET content_loc6 = 'Seguidme. Conozco el camino.', content_loc7 = content_loc6
WHERE entry = -1595096;

UPDATE `script_texts`
SET content_loc6 = 'Ah, por fin has llegado Principe Arthas. Justo a tiempo.', content_loc7 = content_loc6
WHERE entry = -1595097;

UPDATE `script_texts`
SET content_loc6 = 'Si, me alegro de haber llegado antes que la Plaga.', content_loc7 = content_loc6
WHERE entry = -1595098;

UPDATE `script_texts`
SET content_loc6 = '¿Qué es esta brujer', content_loc7 = content_loc6
WHERE entry = -1595099;

UPDATE `script_texts`
SET content_loc6 = 'No es necesario que lo entiendas, Arthas. ¡Lo único que tienes que hacer es morir!', content_loc7 = content_loc6
WHERE entry = -1595100;

UPDATE `script_texts`
SET content_loc6 = 'Parece que Mal\'Ganis tiene más que la plaga en su arsenal. Deberiamos darnos prisa.', content_loc7 = content_loc6
WHERE entry = -1595101;

UPDATE `script_texts`
SET content_loc6 = '¡Más brujería vil! ¡Preparaos para cualquier cosa!', content_loc7 = content_loc6
WHERE entry = -1595102;

UPDATE `script_texts`
SET content_loc6 = 'Adelante.', content_loc7 = content_loc6
WHERE entry = -1595103;

UPDATE `script_texts`
SET content_loc6 = 'Vigilad vuestras espaldas... nos han rodeado en esta estancia.', content_loc7 = content_loc6
WHERE entry = -1595104;

UPDATE `script_texts`
SET content_loc6 = 'Un obstaculo menos del que preocuparse.', content_loc7 = content_loc6
WHERE entry = -1595105;

UPDATE `script_texts`
SET content_loc6 = 'Mal\'Ganis no nos lo esta poniendo fácil...', content_loc7 = content_loc6
WHERE entry = -1595106;

UPDATE `script_texts`
SET content_loc6 = 'Son persistentes.', content_loc7 = content_loc6
WHERE entry = -1595107;

UPDATE `script_texts`
SET content_loc6 = '¿Qué más puede poner en mi camino?', content_loc7 = content_loc6
WHERE entry = -1595108;

UPDATE `script_texts`
SET content_loc6 = 'Hago lo que debo por Lordaeron y ni tus palabras ni tus acciones me detendrán.', content_loc7 = content_loc6
WHERE entry = -1595109;

UPDATE `script_texts`
SET content_loc6 = 'El camino más rapido hasta Mal\'Ganis se encuentra justo detras de esa estantería.', content_loc7 = content_loc6
WHERE entry = -1595110;

UPDATE `script_texts`
SET content_loc6 = 'Esto será solo un momento.', content_loc7 = content_loc6
WHERE entry = -1595111;

UPDATE `script_texts`
SET content_loc6 = '¡Me alegra que este pasadizo secreto aun funcione!', content_loc7 = content_loc6
WHERE entry = -1595112;

UPDATE `script_texts`
SET content_loc6 = 'Movamonos lo más rápido posible. Si nos nos matan los no-muertos lo hará el fuego.', content_loc7 = content_loc6
WHERE entry = -1595113;

UPDATE `script_texts`
SET content_loc6 = 'Descansad un momento y limpiad vuestros pulmones. Debemos movernos pronto.', content_loc7 = content_loc6
WHERE entry = -1595114;

UPDATE `script_texts`
SET content_loc6 = 'Es suficiente, debemos movernos de nuevo. Mal\'Ganis espera.', content_loc7 = content_loc6
WHERE entry = -1595115;

UPDATE `script_texts`
SET content_loc6 = 'Por fin algo de suerte. La Calle del Mercado aun no se ha incendiado. Se supone que Mal\'Ganis esta en la Plaza de los Cruzados, justo delante. Avisadme cuando esteis preparados.', content_loc7 = content_loc6
WHERE entry = -1595116;

UPDATE `script_texts`
SET content_loc6 = '¡Se hará justicia!', content_loc7 = content_loc6
WHERE entry = -1595117;

UPDATE `script_texts`
SET content_loc6 = 'Vamos a terminar esto ahora mismo Mal\'Ganis... solos tu y yo.', content_loc7 = content_loc6
WHERE entry = -1595118;

UPDATE `script_texts`
SET content_loc6 = '¡Te perseguiré hasta el fin del mundo si hace falta! ¿Me oyes? ¡Hasta el fin del mundo!', content_loc7 = content_loc6
WHERE entry = -1595119;

UPDATE `script_texts`
SET content_loc6 = 'Lo habeis hecho bien. Cualquier cosa que Mal\'Ganis haya dejado es vuestra. Tomadla como recompensa. Yo debo comenzar a planear una expedición a Rasganorte.', content_loc7 = content_loc6
WHERE entry = -1595120;

UPDATE `script_texts`
SET content_loc6 = 'Principe Arthas Menethil, una gran oscuridad se ha apoderado de tu alma hoy. La muerte que estas destinado a causarle a otros, hoy será la tuya.', content_loc7 = content_loc6
WHERE entry = -1595000;

UPDATE `script_texts`
SET content_loc6 = 'Ya lo veremos, joven principe.', content_loc7 = content_loc6
WHERE entry = -1595001;

UPDATE `script_texts`
SET content_loc6 = 'Tic, tac, tic, tac...', content_loc7 = content_loc6
WHERE entry = -1595002;

UPDATE `script_texts`
SET content_loc6 = '¡No lo bastante rápido!', content_loc7 = content_loc6
WHERE entry = -1595003;

UPDATE `script_texts`
SET content_loc6 = '¡Acabemos con esto!', content_loc7 = content_loc6
WHERE entry = -1595004;

UPDATE `script_texts`
SET content_loc6 = 'Para ti no hay futuro.', content_loc7 = content_loc6
WHERE entry = -1595005;

UPDATE `script_texts`
SET content_loc6 = '¡Esta es la hora de nuestro mayor triunfo!', content_loc7 = content_loc6
WHERE entry = -1595006;

UPDATE `script_texts`
SET content_loc6 = 'Tu destino era fracasar.', content_loc7 = content_loc6
WHERE entry = -1595007;

UPDATE `script_texts`
SET content_loc6 = '¡AH!', content_loc7 = content_loc6
WHERE entry = -1595008;

UPDATE `script_texts`
SET content_loc6 = 'Si, este es el principio. Te he estado esperando joven principe. Soy Mal\'Ganis', content_loc7 = content_loc6
WHERE entry = -1595009;

UPDATE `script_texts`
SET content_loc6 = 'Como puedes ver, tu gente ahora me pertenece. Pondre esta ciudad patas arriba casa por casa, hasta que la llama de la vida que extinguida para siempre.', content_loc7 = content_loc6
WHERE entry = -1595010;

UPDATE `script_texts`
SET content_loc6 = 'Esta sera una buena prueba, Principe Arthas...', content_loc7 = content_loc6
WHERE entry = -1595011;

UPDATE `script_texts`
SET content_loc6 = 'Demasiado fácil...', content_loc7 = content_loc6
WHERE entry = -1595012;

UPDATE `script_texts`
SET content_loc6 = 'Tu interferencia ha disgustado al señor oscuro...', content_loc7 = content_loc6
WHERE entry = -1595013;

UPDATE `script_texts`
SET content_loc6 = 'Busco al principe Arthas, no a ti...', content_loc7 = content_loc6
WHERE entry = -1595014;

UPDATE `script_texts`
SET content_loc6 = 'Anak\'Keri...', content_loc7 = content_loc6
WHERE entry = -1595015;

UPDATE `script_texts`
SET content_loc6 = 'Mi embate pasará por encima de las tropas del Rey Exánime...', content_loc7 = content_loc6
WHERE entry = -1595016;

UPDATE `script_texts`
SET content_loc6 = 'Mueres en vano, insignificante mortal...', content_loc7 = content_loc6
WHERE entry = -1595017;

UPDATE `script_texts`
SET content_loc6 = '¡Se te acabó el tiempo!', content_loc7 = content_loc6
WHERE entry = -1595018;

UPDATE `script_texts`
SET content_loc6 = 'Se acabó.', content_loc7 = content_loc6
WHERE entry = -1595019;

UPDATE `script_texts`
SET content_loc6 = 'Pareces... cansado...', content_loc7 = content_loc6
WHERE entry = -1595020;

UPDATE `script_texts`
SET content_loc6 = 'He pasado mucho tiempo en este debilucho caparazón...', content_loc7 = content_loc6
WHERE entry = -1595021;

UPDATE `script_texts`
SET content_loc6 = '¡Kirel narak! ¡SOY MAL\'GANIS! ¡SOY ETERNO!', content_loc7 = content_loc6
WHERE entry = -1595022;

UPDATE `script_texts`
SET content_loc6 = '¡YA BASTA! Aqui malgasto mi tiempo... Debo recuperar mi fuerza en el mundo natal...', content_loc7 = content_loc6
WHERE entry = -1595023;

UPDATE `script_texts`
SET content_loc6 = '¡Nunca derrotareis al Rey Exánime sin mis tropas! Me vengaré... ¡De él y de vosotros!', content_loc7 = content_loc6
WHERE entry = -1595024;

UPDATE `script_texts`
SET content_loc6 = 'Tu viaje acaba de comenzar joven principe. Reune a tus tropas. Y ven a verme en las árticas tierras de rasganorte. Allí ajustaremos cuentas. Allí es donde se revelará tu verdadero destino.', content_loc7 = content_loc6
WHERE entry = -1595025;

UPDATE `script_texts`
SET content_loc6 = '¡Hora de jugar!', content_loc7 = content_loc6
WHERE entry = -1595026;

UPDATE `script_texts`
SET content_loc6 = 'Aburrido...', content_loc7 = content_loc6
WHERE entry = -1595027;

UPDATE `script_texts`
SET content_loc6 = '¡Por qué has dejado de moverte?', content_loc7 = content_loc6
WHERE entry = -1595028;

UPDATE `script_texts`
SET content_loc6 = '¡Levanta! ¡Yo no terminado!', content_loc7 = content_loc6
WHERE entry = -1595029;

UPDATE `script_texts`
SET content_loc6 = '¡Juguetes nuevos!', content_loc7 = content_loc6
WHERE entry = -1595030;

UPDATE `script_texts`
SET content_loc6 = '¡Esto... no divertido...!', content_loc7 = content_loc6
WHERE entry = -1595031;

UPDATE `script_texts`
SET content_loc6 = '¡Ah, ha llegado la diversión!', content_loc7 = content_loc6
WHERE entry = -1595032;

UPDATE `script_texts`
SET content_loc6 = 'Llegas demasiado tarde, campeón de Lordaeron. Los muertos tendrán su día', content_loc7 = content_loc6
WHERE entry = -1595033;

UPDATE `script_texts`
SET content_loc6 = '¡La diversión no ha hecho más que empezar!', content_loc7 = content_loc6
WHERE entry = -1595034;

UPDATE `script_texts`
SET content_loc6 = '¡Ah, materiales de calidad!', content_loc7 = content_loc6
WHERE entry = -1595035;

UPDATE `script_texts`
SET content_loc6 = 'No te preocupes, te daré un buen uso.', content_loc7 = content_loc6
WHERE entry = -1595036;

UPDATE `script_texts`
SET content_loc6 = 'Solo seguis... el plan del maestro...', content_loc7 = content_loc6
WHERE entry = -1595037;

UPDATE `script_texts`
SET content_loc6 = '¡BOOM! Jajajajaja...', content_loc7 = content_loc6
WHERE entry = -1595038;

UPDATE `script_texts`
SET content_loc6 = 'Sangre... destrucción... ¡DESTERNILLANTE!', content_loc7 = content_loc6
WHERE entry = -1595039;

UPDATE `script_texts`
SET content_loc6 = 'Quiero una muestra...', content_loc7 = content_loc6
WHERE entry = -1595040;

UPDATE `script_texts`
SET content_loc6 = 'Tamaña fuerza... ¡HA DE SER MIA!', content_loc7 = content_loc6
WHERE entry = -1595041;

UPDATE `script_texts`
SET content_loc6 = 'Tu carne te traiciona.', content_loc7 = content_loc6
WHERE entry = -1595042;

UPDATE `script_texts`
SET content_loc6 = 'Decid hola a algunos amigos mios.', content_loc7 = content_loc6
WHERE entry = -1595043;

UPDATE `script_texts`
SET content_loc6 = '¡Vamos, ciudadanos de Stratholme! Conoced a vuestros salvadores.', content_loc7 = content_loc6
WHERE entry = -1595044;

UPDATE `script_texts`
SET content_loc6 = '¡Cómo osáis interrumpir nuestro trabajo aquí!', content_loc7 = content_loc6
WHERE entry = -1595045;

UPDATE `script_texts`
SET content_loc6 = 'Mi tiempo... se ha acabado...', content_loc7 = content_loc6
WHERE entry = -1595046;

UPDATE `script_texts`
SET content_loc6 = '¡Mi trabajo aquí ha terminado!', content_loc7 = content_loc6
WHERE entry = -1595047;

-- Loot for Infinite Corruptor
DELETE FROM `creature_loot_template` WHERE (`entry`=32273);
INSERT INTO `creature_loot_template` VALUES
(32273, 22926, 0.0296, 1, 0, -22926, 1),
(32273, 35947, 0.9923, 1, 0, 1, 1),
(32273, 36051, 1.08, 1, 0, -36051, 1),
(32273, 36059, 2.37, 1, 0, -36059, 1),
(32273, 37254, 0.0444, 1, 0, -37254, 1),
(32273, 37761, 0.0592, 1, 0, -37761, 1),
(32273, 41777, 0.0204, 1, 0, -41777, 1),
(32273, 43951, 100, 1, 0, 1, 1),
(32273, 47241, 100, 1, 0, 1, 1);

UPDATE `creature_template` SET `lootid` = 32273 WHERE `entry` IN (32273, 32313);