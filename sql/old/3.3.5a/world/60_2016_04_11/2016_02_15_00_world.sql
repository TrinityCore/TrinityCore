--
UPDATE `creature_template` SET `unit_flags`=512, `VehicleId`=240, `InhabitType`=4 WHERE `entry`=30477;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `exp`=2, `unit_flags`=512, `VehicleId`=240, `InhabitType`=4 WHERE `entry`=30487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29428,30477,30487);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29428,30477,30487) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30477*100,30487*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29428,0,0,2,62,0,100,0,9917,0,0,0,11,58061,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ricket - On gossip select - Spellcast Forcecast Summon Rocket (Alliance)'),
(29428,0,1,2,62,0,100,0,9917,1,0,0,11,58062,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ricket - On gossip select - Spellcast Forcecast Summon Rocket (Horde)'),
(29428,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ricket - On gossip select - Close gossip'),
(30477,0,0,0,54,0,100,0,0,0,0,0,80,30477*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - Just summoned - Run script'),
(30477,0,1,2,40,0,100,0,18,30477,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 18 reached - Spellcast Eject All Passengers'),
(30477,0,2,0,61,0,100,0,0,0,0,0,11,42895,0,0,0,0,0,23,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 18 reached - Spellcast Cosmetic - Combat Knockdown Foe'),
(30477,0,3,0,40,0,100,0,24,30477,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 24 reached - Despawn'),
(30487,0,0,0,54,0,100,0,0,0,0,0,80,30487*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - Just summoned - Run script'),
(30487,0,1,2,40,0,100,0,13,30487,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 13 reached - Spellcast Eject All Passengers'),
(30487,0,2,0,61,0,100,0,0,0,0,0,11,42895,0,0,0,0,0,23,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 13 reached - Spellcast Cosmetic - Combat Knockdown Foe'),
(30487,0,3,0,40,0,100,0,17,30487,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device - On WP 17 reached - Despawn'),
(30477*100,9,0,0,0,0,100,0,3000,3000,0,0,53,1,30477,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device script - Start WP movement'),
(30487*100,9,0,0,0,0,100,0,3000,3000,0,0,53,1,30487,0,0,0,0,1,0,0,0,0,0,0,0,'D16 Propelled Delivery Device script - Start WP movement');

DELETE FROM `waypoints` WHERE `entry` IN (30477,30487);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(30477,1,6164.999,-1064.512,422.1189,'D16 Propelled Delivery Device'),
(30477,2,6204.096,-998.4872,457.5628,'D16 Propelled Delivery Device'),
(30477,3,6289.573,-952.1809,504.6187,'D16 Propelled Delivery Device'),
(30477,4,6307.788,-872.7999,541.7296,'D16 Propelled Delivery Device'),
(30477,5,6370.582,-821.9507,653.868,'D16 Propelled Delivery Device'),
(30477,6,6413.268,-660.4708,808.3953,'D16 Propelled Delivery Device'),
(30477,7,6554.813,-550.3772,1018.112,'D16 Propelled Delivery Device'),
(30477,8,6633.265,-419.3159,1173.914,'D16 Propelled Delivery Device'),
(30477,9,6760.503,-364.4665,1277.719,'D16 Propelled Delivery Device'),
(30477,10,6807.88,-427.5194,1399.109,'D16 Propelled Delivery Device'),
(30477,11,6808.07,-471.4465,1419.247,'D16 Propelled Delivery Device'),
(30477,12,6775.634,-529.2309,1394.387,'D16 Propelled Delivery Device'),
(30477,13,6720.645,-535.5529,1328.054,'D16 Propelled Delivery Device'),
(30477,14,6660.31,-486.8651,1238.553,'D16 Propelled Delivery Device'),
(30477,15,6658.937,-417.8409,1186.11,'D16 Propelled Delivery Device'),
(30477,16,6680.49,-329.3087,1098.609,'D16 Propelled Delivery Device'),
(30477,17,6683.783,-220.3454,972.7203,'D16 Propelled Delivery Device'),
(30477,18,6663.772,-192.1261,962.2485,'D16 Propelled Delivery Device'),
(30477,19,6654.82,-180.1689,958.1317,'D16 Propelled Delivery Device'),
(30477,20,6631.467,-171.3305,966.4633,'D16 Propelled Delivery Device'),
(30477,21,6598.223,-162.3664,984.2227,'D16 Propelled Delivery Device'),
(30477,22,6566.67,-155.2077,992.0551,'D16 Propelled Delivery Device'),
(30477,23,6529.651,-154.9363,992.0551,'D16 Propelled Delivery Device'),
(30477,24,6454.417,-152.1311,962.305,'D16 Propelled Delivery Device'),
(30487,1,6169.229,-1069.619,420.6945,'D16 Propelled Delivery Device'),
(30487,2,6232.725,-1031.598,505.7779,'D16 Propelled Delivery Device'),
(30487,3,6339.224,-1035.08,575.3331,'D16 Propelled Delivery Device'),
(30487,4,6431.492,-987.6745,694.8887,'D16 Propelled Delivery Device'),
(30487,5,6632.437,-925.9739,896.1384,'D16 Propelled Delivery Device'),
(30487,6,6822.084,-755.521,1171.194,'D16 Propelled Delivery Device'),
(30487,7,7090.693,-619.4874,1455.639,'D16 Propelled Delivery Device'),
(30487,8,7260.75,-282.75,1513.362,'D16 Propelled Delivery Device'),
(30487,9,7552.502,-334.6509,1657.668,'D16 Propelled Delivery Device'),
(30487,10,7692.301,-509.425,1536.5,'D16 Propelled Delivery Device'),
(30487,11,7799.192,-636.3267,1252.278,'D16 Propelled Delivery Device'),
(30487,12,7841.555,-726.5501,1193.916,'D16 Propelled Delivery Device'),
(30487,13,7844.731,-775.3613,1185.833,'D16 Propelled Delivery Device'),
(30487,14,7842.449,-815.5735,1186.396,'D16 Propelled Delivery Device'),
(30487,15,7838.703,-859.9572,1173.173,'D16 Propelled Delivery Device'),
(30487,16,7865.014,-911.2181,1163.979,'D16 Propelled Delivery Device'),
(30487,17,7856.225,-951.6568,1151.563,'D16 Propelled Delivery Device');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9917 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9917,1,0,'I am ready to head further into Storm Peaks.',32890,1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9917,0,0,28,12862,0,0,0,'','Ricket - Show gossip option only if player has completed but not rewarded quest When All Else Fails'),
(15,9917,1,0,28,13060,0,0,0,'','Ricket - Show gossip option only if player has completed but not rewarded quest When All Else Fails');
