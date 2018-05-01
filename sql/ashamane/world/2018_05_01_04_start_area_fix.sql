-- Dwarf start area fix

UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 37081; 

DELETE FROM `creature` WHERE `id`=37070;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(167268, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6296.17, 326.164, 376.828, 0.0802196, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167269, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6266.06, 310.896, 382.809, -1.45674, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167271, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6290.69, 348.408, 377.022, -2.47413, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167273, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6294.01, 314.756, 376.628, -2.07352, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167276, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6280.72, 370.715, 381.87, 0.432933, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167278, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6278.89, 393.446, 381.37, 2.03069, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167282, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6258.61, 404.793, 383.891, 1.86152, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167297, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6235.97, 404.548, 388.52, 4.83771, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167352, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6259.55, 393.766, 383.098, 5.70256, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167366, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6204.6, 304.649, 388.96, 2.29419, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167369, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6269.25, 305.163, 382.544, 0.572368, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167371, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6209.6, 310.083, 388.104, 2.28721, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(167372, 37070, 0, 6176, 132, 1, 0, 0, 0, -1, 730, 0, -6237.68, 375.519, 385.447, 4.96282, 300, 8, 0, 42, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210115287, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6277.04, 363.05, 380.821, 3.94663, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115288, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6284.54, 362.388, 379.874, 3.94663, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115289, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6293.95, 361.763, 378.857, 3.94663, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115290, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6302.44, 349.679, 377.555, 4.79486, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115291, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6301.54, 332.779, 376.387, 0.642459, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115292, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6290.5, 325.99, 376.712, 1.11134, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115293, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6277.98, 323.777, 375.585, 2.54391, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115294, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6283.71, 317.544, 376.609, 2.54391, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115295, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6305.82, 320.987, 378.092, 2.69942, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115296, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6320.75, 335.637, 376.572, 1.84176, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115297, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6321.4, 352.131, 376.627, 1.52839, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115298, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6310.24, 363.784, 377.757, 6.20936, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115299, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6298.91, 367.016, 378.789, 4.80507, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210115300, 37070, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -6280.64, 383.487, 381.948, 5.99259, 300, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 37080;

UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7468' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10526' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9733' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10201' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9113' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '1297' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10202' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '345' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12677' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '4305' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10898' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '4341' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '4325' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12850' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12835' AND `OptionIndex` = '3'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '441' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9832' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12040' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12443' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11919' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '6059' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '342' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '8058' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '8124' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12726' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12675' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12838' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12025' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '4283' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7288' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '6183' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9633' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12101' AND `OptionIndex` = '3'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10209' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7949' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12823' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9487' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10029' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10123' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9112' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7817' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12607' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '8884' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9868' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '6527' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '24' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10392' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '12842' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7809' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11822' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7820' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9427' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '8760' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '9478' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '20471' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '20199' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '19312' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '18383' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '20586' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '19836' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '18963' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '18817' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '20232' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '20270' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '18458' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '16524' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '21462' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7173' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11403' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11814' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11128' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '7952' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '10363' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '8950' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '3' WHERE `MenuId` = '11779' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7468' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10139' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10526' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9113' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10201' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9733' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '1297' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10202' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '345' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12677' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '4305' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10898' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '4341' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '4325' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12850' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12835' AND `OptionIndex` = '3'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '6059' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11919' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12443' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12040' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9832' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '441' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '342' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '8058' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '8124' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12726' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12675' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12838' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12025' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '4283' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7288' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '6183' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9633' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12101' AND `OptionIndex` = '3'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10209' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7949' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12823' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9487' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10029' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10123' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9112' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7817' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12607' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '8884' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9868' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '6527' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '24' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10392' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '12842' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7809' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11822' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7820' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9427' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '8760' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '9478' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '20471' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '20199' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '19312' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '18383' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '20586' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '19836' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '18963' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '18817' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '20232' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '20270' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '18458' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '16524' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '21462' AND `OptionIndex` = '2'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7173' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11403' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11814' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11128' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '7952' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '10363' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '8950' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '128' WHERE `MenuId` = '11779' AND `OptionIndex` = '0'; 


-- Soothsayer Rikkari SAI
SET @ENTRY := 37173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37173,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,3,52,0,100,0,1,37173,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,61,0,100,0,1,37173,0,0,33,37110,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 2 Over - Quest Credit 'Trolling for Information'");




-- Soothsayer Rikkari SAI
SET @ENTRY := 37173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37173,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37173,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,1,37173,0,0,33,37110,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Text 2 Over - Quest Credit 'Trolling for Information'");

-- Soothsayer Mirim'koa SAI
SET @ENTRY := 37174;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37174,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37174,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,2,37174,0,0,33,37111,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Text 2 Over - Quest Credit 'Trolling for Information'");

-- Soothsayer Shi'kala SAI
SET @ENTRY := 37108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,3,5000,6000,1,0,4000,0,0,0,0,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Within 1-3 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,1,0,52,0,100,0,0,37108,0,0,1,1,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 0 Over - Say Line 1"),
(@ENTRY,0,2,0,52,0,100,0,1,37108,0,0,1,2,4000,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 1 Over - Say Line 2"),
(@ENTRY,0,3,0,52,0,100,0,2,37108,0,0,33,37109,0,0,0,0,7,7,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Text 2 Over - Quest Credit 'Trolling for Information'");

UPDATE `gameobject_loot_template` SET `Chance` = '100' WHERE `Entry` = '201706' AND `Item` = '49754';
DELETE FROM `creature` WHERE `id`=37113;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115304, 37113, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, -6243.37, 309.875, 383.675, 4.72384, 300, 0, 0, 236, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature` SET `spawndist` = 4, `MovementType` = 1 WHERE `id` IN (37070);
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (37080);