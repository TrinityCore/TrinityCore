

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18034 AND `AreaTriggerId`=22171); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18034 AND `AreaTriggerId`=22171); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0


DELETE FROM `conversation_actor_template` WHERE `Id` IN (71352, 71350);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(71352, 156280, 92690, 38134),
(71350, 149899, 91998, 38134);

UPDATE `conversation_actor_template` SET `CreatureId`=156900, `CreatureModelId`=92803, `VerifiedBuild`=38134 WHERE `Id`=53609;
UPDATE `conversation_actor_template` SET `CreatureId`=156902, `CreatureModelId`=91010, `VerifiedBuild`=38134 WHERE `Id`=53609;

DELETE FROM `conversation_line_template` WHERE `Id` IN (34698, 36228, 33099, 33097, 33096, 29666, 33079, 33051, 33052, 33053, 31917, 34697, 34011, 29667, 36224, 29665, 27723, 27722);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(34698, 0, 0, 0, 0, 38134),
(36228, 0, 0, 0, 0, 38134),
(33099, 21141, 0, 0, 0, 38134),
(33097, 9522, 0, 0, 0, 38134),
(33096, 0, 0, 0, 0, 38134),
(29666, 0, 0, 0, 0, 38134),
(33079, 0, 0, 0, 0, 38134),
(33051, 1000, 0, 1, 0, 38134),
(33052, 0, 0, 0, 0, 38134),
(33053, 0, 0, 0, 0, 38134),
(31917, 0, 0, 0, 0, 38134),
(34697, 0, 0, 0, 0, 38134),
(34011, 0, 0, 0, 0, 38134),
(29667, 0, 0, 0, 0, 38134),
(36224, 0, 0, 0, 0, 38134),
(29665, 0, 0, 0, 0, 38134),
(27723, 3622, 0, 1, 0, 38134),
(27722, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=41382;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=41381;


UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12958;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=13421;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12957;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12956;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12953;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12945;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12939;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12938;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12934;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=11512;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=11408;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=11348;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12091;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12089;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12088;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12087;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12086;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=13712;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=13712;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12070;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=14449;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=14440;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=13710;
UPDATE `conversation_template` SET `VerifiedBuild`=38134 WHERE `Id`=12058;
UPDATE `conversation_template` SET `FirstLineID`=36103, `LastLineEndTime`=3104, `VerifiedBuild`=38134 WHERE `Id`=14424;
UPDATE `conversation_template` SET `FirstLineID`=36101, `LastLineEndTime`=5297, `VerifiedBuild`=38134 WHERE `Id`=14423;
UPDATE `conversation_template` SET `FirstLineID`=31382, `LastLineEndTime`=7201, `VerifiedBuild`=38134 WHERE `Id`=12798;
UPDATE `conversation_template` SET `FirstLineID`=31445, `LastLineEndTime`=5882, `VerifiedBuild`=38134 WHERE `Id`=12818;
UPDATE `conversation_template` SET `FirstLineID`=32717, `LastLineEndTime`=2875, `VerifiedBuild`=38134 WHERE `Id`=10768;

DELETE FROM `gameobject_template_addon` WHERE `entry`=342259;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(342259, 0, 2113540, 0, 3737); -- Grimorio antiguo

UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=327407; -- Alijo de los ogros precioso
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=7912 WHERE `entry`=341951; -- Cicuta marchita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=329919; -- Suministros robados
UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=326716; -- Pedestal de ritual
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=3737 WHERE `entry`=342366; -- Flor de velo
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=17848 WHERE `entry`=327146; -- Tótem de arpías
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=329918; -- Tesoros de los jabaespines
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=339770; -- Cofre del tesoro abandonado


DELETE FROM `creature_template_locale` WHERE (`locale`='esMX' AND `entry` IN (168255,163963,154155,156913,166262,165198,157328,156828,161504,156821,156501,157300,168740,161350,156814,168738,156825,156965,153581,174529,174528,174523,174527,174525,153583,153582,156961,156960,161306,156954,154103,154146,154147,153580,154145,153238,153242,153239,156948,156947,153566,153565,164927,155733,172026,161006,156944,156943,156942,156941,163040,172027,171997,163039,156932,165352,160451,156929,156902,160964,156900,156891,156886,156885,156887,164026,164025,163069,156882,155199,153211,152571,156986,164022,157104,156860,156859,152998,169162,163246,155192,155197,162948,163533,164868,163218,172029,172028,163209,155572,152843,162954,160394,160433,153964,153266,174977,156808,165758,161666,150245,168382,156833,156807,162817,165150,156267,156781,156595,156736,156749,156804,156803,156801,156800,154300,157114,156526,156518,156799,157091,156532,174955,149899,154268,149915,165730,165711,165757,165727,156716,156676,155371,165713,151091,156662,150238,165712,154301,150237,154327,156660,164605,175031,164827,165360,153168,151088,154170,151089,156622,156612,156610,156609,149917,156626,157051,155607,157043,155125,157046,156280,157044,157042,157049,154867,156345,156403,167886,160664,156607,161130,156651,164577,165359,161265,161133,161131,167761));
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(168255, 'esMX', 'Grifo de la Alianza', NULL, NULL, NULL, 38134),
(163963, 'esMX', 'Brunston Martillero', NULL, 'Clan Martillo Salvaje', NULL, 38134),
(154155, 'esMX', 'Grifo de la Alianza', NULL, NULL, NULL, 38134),
(156913, 'esMX', 'Cadáver putrefacto', NULL, NULL, NULL, 38134),
(166262, 'esMX', 'Cadáver putrefacto', NULL, NULL, NULL, 38134),
(165198, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(157328, 'esMX', 'Canalizador Mazoscuro', NULL, NULL, NULL, 38134),
(156828, 'esMX', 'Orbe sombrío', NULL, NULL, NULL, 38134),
(161504, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(156821, 'esMX', 'Clamasombras Mazoscuro', NULL, NULL, NULL, 38134),
(156501, 'esMX', 'Ravnyr', NULL, NULL, NULL, 38134),
(157300, 'esMX', 'Tunk', NULL, NULL, NULL, 38134),
(168740, 'esMX', 'Ermitaña de ciudadela', NULL, NULL, NULL, 38134),
(161350, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(156814, 'esMX', 'Gor\'groth', NULL, NULL, NULL, 38134),
(168738, 'esMX', 'Rata de ciudadela', NULL, NULL, NULL, 38134),
(156825, 'esMX', 'Centurión Mazoscuro', NULL, NULL, NULL, 38134),
(156965, 'esMX', 'Capitana Kelra', NULL, NULL, NULL, 38134),
(153581, 'esMX', 'Grunk', NULL, NULL, NULL, 38134),
(174529, 'esMX', 'Jard', NULL, NULL, NULL, 38134),
(174528, 'esMX', 'Zink', NULL, NULL, NULL, 38134),
(174523, 'esMX', 'Tiang', NULL, NULL, NULL, 38134),
(174527, 'esMX', 'Trem', NULL, NULL, NULL, 38134),
(174525, 'esMX', 'Kee', NULL, NULL, NULL, 38134),
(153583, 'esMX', 'Jugnug', NULL, NULL, NULL, 38134),
(153582, 'esMX', 'Wug', NULL, NULL, NULL, 38134),
(156961, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(156960, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(161306, 'esMX', 'Acechador invisible', NULL, NULL, NULL, 38134),
(156954, 'esMX', 'Capitana Kelra', NULL, NULL, NULL, 38134),
(154103, 'esMX', 'Chef ogro', NULL, NULL, NULL, 38134),
(154146, 'esMX', 'Wug', NULL, NULL, NULL, 38134),
(154147, 'esMX', 'Jugnug', NULL, NULL, NULL, 38134),
(153580, 'esMX', 'Gor\'groth', NULL, NULL, NULL, 38134),
(154145, 'esMX', 'Grunk', NULL, NULL, NULL, 38134),
(153238, 'esMX', 'Jabalí domesticado', NULL, NULL, NULL, 38134),
(153242, 'esMX', 'Taumaturgo umbrío ogro', NULL, NULL, NULL, 38134),
(153239, 'esMX', 'Bruto ogro', NULL, NULL, NULL, 38134),
(156948, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(156947, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(153566, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(153565, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(164927, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(155733, 'esMX', 'Cofre del tesoro escondido', NULL, NULL, NULL, 38134),
(172026, 'esMX', 'Cucaracha', NULL, NULL, NULL, 38134),
(161006, 'esMX', 'Taumaturgo umbrío ogro', NULL, NULL, NULL, 38134),
(156944, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(156943, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(156942, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(156941, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(163040, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(172027, 'esMX', 'Carroñero roedor', NULL, NULL, NULL, 38134),
(171997, 'esMX', 'Vigía de los bosques', NULL, NULL, NULL, 38134),
(163039, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(156932, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(165352, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(160451, 'esMX', 'Hrun el Exiliado', NULL, NULL, NULL, 38134),
(156929, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(156902, 'esMX', 'Ralia Cazasueños', NULL, NULL, NULL, 38134),
(160964, 'esMX', 'Miembro de expedición liberado', 'Miembro de expedición liberada', NULL, NULL, 38134),
(156900, 'esMX', 'Hrun el Exiliado', NULL, NULL, NULL, 38134),
(156891, 'esMX', 'Bjorn Manosfirmes', NULL, NULL, NULL, 38134),
(156886, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(156885, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(156887, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(164026, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(164025, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(163069, 'esMX', 'Yorah', NULL, NULL, NULL, 38134),
(156882, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(155199, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(153211, 'esMX', 'Meredy Huntswell', NULL, NULL, NULL, 38134),
(152571, 'esMX', 'Arpía ladrona', NULL, NULL, NULL, 38134),
(156986, 'esMX', 'Capataz ogro', NULL, NULL, NULL, 38134),
(164022, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(157104, 'esMX', 'Acechador invisible', NULL, NULL, NULL, 38134),
(156860, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(156859, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(152998, 'esMX', 'Huargo cazador', NULL, NULL, NULL, 38134),
(169162, 'esMX', 'Huargo cazador', NULL, NULL, NULL, 38134),
(163246, 'esMX', 'Abisario invocado', NULL, NULL, NULL, 38134),
(155192, 'esMX', 'Arpía emboscadora', NULL, NULL, NULL, 38134),
(155197, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(162948, 'esMX', 'Guerrero esquelético', NULL, NULL, NULL, 38134),
(163533, 'esMX', 'Hjalmar el Imperecedero', NULL, NULL, NULL, 38134),
(164868, 'esMX', 'Monje pandaren', NULL, NULL, NULL, 38134),
(163218, 'esMX', 'Abisario', NULL, NULL, NULL, 38134),
(172029, 'esMX', 'Puercoespín espinoso', NULL, NULL, NULL, 38134),
(172028, 'esMX', 'Errante montés', NULL, NULL, NULL, 38134),
(163209, 'esMX', 'Hubert Lucas', NULL, NULL, NULL, 38134),
(155572, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(152843, 'esMX', 'Arpía Clamarrayos', NULL, NULL, NULL, 38134),
(162954, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(160394, 'esMX', 'Araña de carreta', NULL, NULL, NULL, 38134),
(160433, 'esMX', 'Arañuelo de carreta', NULL, NULL, NULL, 38134),
(153964, 'esMX', 'Pico sangrante', NULL, 'Terror de los cielos', NULL, 38134),
(153266, 'esMX', 'Zarpatroz el Terrible', NULL, NULL, NULL, 38134),
(174977, 'esMX', 'Spar Point Advertisement', NULL, NULL, NULL, 38134),
(156808, 'esMX', 'Jabalí pequeño', NULL, NULL, NULL, 38134),
(165758, 'esMX', 'Brincador moteado', NULL, NULL, NULL, 38134),
(161666, 'esMX', 'Austin Huxworth', NULL, 'Maestra de establos', NULL, 38134),
(150245, 'esMX', 'Lindie Resortín', NULL, NULL, NULL, 38134),
(168382, 'esMX', 'Spar Point Advertisement', NULL, NULL, NULL, 38134),
(156833, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(156807, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(162817, 'esMX', 'Torgok', NULL, 'Vinculador de almas', NULL, 38134),
(165150, 'esMX', 'Cadáver monstruoso', NULL, NULL, NULL, 38134),
(156267, 'esMX', 'Jabalí gigante', NULL, NULL, NULL, 38134),
(156781, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(156595, 'esMX', 'Jabalí gigante', NULL, NULL, NULL, 38134),
(156736, 'esMX', 'Jabalí redimensionado', NULL, NULL, NULL, 38134),
(156749, 'esMX', 'Lindie Resortín', NULL, NULL, NULL, 38134),
(156804, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(156803, 'esMX', 'Alaria', NULL, NULL, NULL, 38134),
(156801, 'esMX', 'Soldado Cole', NULL, NULL, NULL, 38134),
(156800, 'esMX', 'Intendente Richter', NULL, 'Suministros', NULL, 38134),
(154300, 'esMX', 'Bjorn Manosfirmes', NULL, NULL, NULL, 38134),
(157114, 'esMX', 'Engendro de luz', NULL, NULL, NULL, 38134),
(156526, 'esMX', 'Exploramático 5000', NULL, NULL, NULL, 38134),
(156518, 'esMX', 'Exploramático 5000', NULL, NULL, NULL, 38134),
(156799, 'esMX', 'Henry Garrick', NULL, NULL, NULL, 38134),
(157091, 'esMX', 'Cadáver monstruoso', NULL, NULL, NULL, 38134),
(156532, 'esMX', 'Sirviente zombi', NULL, NULL, NULL, 38134),
(174955, 'esMX', 'Capitana de la Alianza', NULL, NULL, NULL, 38134),
(149899, 'esMX', 'Lindie Resortín', NULL, NULL, NULL, 38134),
(154268, 'esMX', 'Buitre hambriento', NULL, NULL, NULL, 38134),
(149915, 'esMX', 'Austin Huxworth', NULL, NULL, NULL, 38134),
(165730, 'esMX', 'Venado de las llanuras', NULL, NULL, NULL, 38134),
(165711, 'esMX', 'Cervato de la planicie', NULL, NULL, NULL, 38134),
(165757, 'esMX', 'Perro de pradera', NULL, NULL, NULL, 38134),
(165727, 'esMX', 'Cierva de la planicie', NULL, NULL, NULL, 38134),
(156716, 'esMX', 'Jabalí merodeador', NULL, NULL, NULL, 38134),
(156676, 'esMX', 'Sobrestante ogro', NULL, NULL, NULL, 38134),
(155371, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(165713, 'esMX', 'Rata escurridiza', NULL, NULL, NULL, 38134),
(151091, 'esMX', 'Geoseñor Grek\'og', NULL, NULL, NULL, 38134),
(156662, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(150238, 'esMX', 'Geomante jabaespín', NULL, NULL, NULL, 38134),
(165712, 'esMX', 'Cucaracha', NULL, NULL, NULL, 38134),
(154301, 'esMX', 'Lindie Resortín', NULL, NULL, NULL, 38134),
(150237, 'esMX', 'Guerrero jabaespín', NULL, NULL, NULL, 38134),
(154327, 'esMX', 'Austin Huxworth', NULL, NULL, NULL, 38134),
(156660, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(164605, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(175031, 'esMX', 'Alaria', NULL, NULL, NULL, 38134),
(164827, 'esMX', 'Halcón picoafilado', NULL, NULL, NULL, 38134),
(165360, 'esMX', 'Sobreviviente de la Alianza', NULL, NULL, NULL, 38134),
(153168, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(151088, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(154170, 'esMX', 'Austin Huxworth', NULL, NULL, NULL, 38134),
(151089, 'esMX', 'Bjorn Manosfirmes', NULL, NULL, NULL, 38134),
(156622, 'esMX', 'Intendente Richter', NULL, NULL, NULL, 38134),
(156612, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(156610, 'esMX', 'Austin Huxworth', NULL, NULL, NULL, 38134),
(156609, 'esMX', 'Bjorn Manoforte', NULL, NULL, NULL, 38134),
(149917, 'esMX', 'Soldado Cole', NULL, NULL, NULL, 38134),
(156626, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(157051, 'esMX', 'Compañero de entrenamiento de la Alianza', NULL, NULL, NULL, 38134),
(155607, 'esMX', 'Soldado Cole', NULL, NULL, NULL, 38134),
(157043, 'esMX', 'Kee-La', NULL, NULL, NULL, 38134),
(155125, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134),
(157046, 'esMX', 'Austin Huxworth', NULL, NULL, NULL, 38134),
(156280, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(157044, 'esMX', 'Bjorn Manosfirmes', NULL, NULL, NULL, 38134),
(157042, 'esMX', 'Intendente Richter', NULL, NULL, NULL, 38134),
(157049, 'esMX', 'Timonel Lenard', NULL, NULL, NULL, 38134),
(154867, 'esMX', 'Jinete de grifos Martillo Salvaje', NULL, NULL, NULL, 38134),
(156345, 'esMX', 'Grifo Martillo Salvaje', NULL, NULL, NULL, 38134),
(156403, 'esMX', 'Un bote', NULL, NULL, NULL, 38134),
(167886, 'esMX', 'Marinero de la Alianza', 'Marinera de la Alianza', NULL, NULL, 38134),
(160664, 'esMX', 'Soldado Cole', NULL, NULL, NULL, 38134),
(156607, 'esMX', 'Alaria', NULL, NULL, NULL, 38134),
(161130, 'esMX', 'Cabra costera', NULL, NULL, NULL, 38134),
(156651, 'esMX', 'Capitana Garrick', NULL, NULL, NULL, 38134),
(164577, 'esMX', 'Compañera de entrenamiento de la Alianza', NULL, NULL, NULL, 38134),
(165359, 'esMX', 'Sobreviviente de la Alianza', NULL, NULL, NULL, 38134),
(161265, 'esMX', 'Jrokgar', NULL, NULL, NULL, 38134),
(161133, 'esMX', 'Albatros costero', NULL, NULL, NULL, 38134),
(161131, 'esMX', 'Puercoespín espinoso', NULL, NULL, NULL, 38134),
(167761, 'esMX', 'InvisBunny', NULL, NULL, NULL, 38134);

UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=1860 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=95577 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=89715 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=416 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=112144 AND `locale`='esMX');


DELETE FROM `quest_template_locale` WHERE (`locale`='esMX' AND `ID` IN (55991,55989,55988,55990,56839,55981,56344,55639,54933,55882,55764,55881,55763,55965,55196,58962,55194,55879,55193,55184,55186,55173,59254,55174,58209,54951,59342,55992,56034));
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(55991, 'esMX', 'El fin del principio', 'Viaja a la Ciudad de Ventormenta en un grifo de la Alianza.', 'Ahora que los refuerzos llegaron y la tormenta pasó, es hora de que regresemos a Ventormenta.\n\nTu aporte y el de los demás reclutas ha sido invaluable, $n. Yo misma me cercioraré de incluir todo en el informe que le daré a mi rey.\n\nSube a un grifo y volvamos a casa.', '', '', '', '', '', '', 38134),
(55989, 'esMX', 'Destrucción de catapultas', 'Haz explotar $1oa catapultas dentro de la Ciudadela Mazoscuro.', '¡Parece que los ogros planean atacar a nuestros amigos en el campamento!\n\nVi que estaban trabajando con algunas catapultas. Jamás creí que esos brutos sabrían cómo usarlas.\n\nPor suerte para ti, empaqué algo especial, cortesía de nuestro amiguito Lindie.\n\nLleva estas bombas. ¡Harán desaparecer las catapultas en un parpadeo!', '', '', '', '', '', '', 38134),
(55988, 'esMX', 'Ogros al matadero', 'Mata a $1oa ogros dentro de la Ciudadela Mazoscuro.', 'Esto es malo, $n. Atraparon a la capitana Kelra con magia, los ogros se preparan para atacar a nuestros amigos... ¡y el ritual está casi terminado!\n\nTengo que mantener la calma. Ahora no podemos rendirnos, ¿verdad?\n\nSé que suena arriesgado, pero tenemos que atacar a los ogros.\n\nEstamos en su territorio, así que podremos sorprenderlos y distraerlos del campamento.\n\nAcaba con todos los ogros que puedas. Así, les daremos un respiro a nuestros amigos.', '', '', '', '', '', '', 38134),
(55990, 'esMX', 'Controlar sus piedras', 'Recupera las piedras de resguardo de Jugnug, Wug y Grunk, y luego úsalas para liberar a la capitana Kelra.', 'La capitana Kelra no resistirá mucho más. Tenemos que conseguir las piedras de resguardo para destruir el ritual antes de que la mate.\n\nNosotros resistiremos aquí. ¡Tú mata a los tenientes ogros y consigue las piedras de resguardo!', '', '', '', '', '', '', 38134),
(56839, 'esMX', 'Zarpatroz el Terrible', 'Derrota a Zarpatroz el Terrible.', '<Ves un cartel rudimentario que hicieron los ogros. Tiene una advertencia.>\n\n¡Oso GRANDE! ¡Malo!\n\n¡Oso grande protege tesoro grande de ogro!\n\n¡Ritual, luego matar! ¡Obtener tesoro, conseguir más poder!', '', 'Zarpatroz es una bestia muy fuerte, ¡necesitarás amigos para derrotarlo!', 'Zarpatroz el Terrible', '', '', 'Busca el tesoro dentro de la cueva de Zarpatroz.', 38134),
(55981, 'esMX', 'Frente a sus ojos', 'Haz que Meredy te transforme en ogro y luego explora la ciudadela de ogros cercana.', 'Tenemos que entrar a la Ciudadela Mazoscuro, rescatar a la capitana de la expedición y detener al ogro nigromante que está detrás de todo esto.\n\nMeredy te lanzará una ilusión para darte apariencia de ogro, y tú nos llevarás a los demás como “prisioneros”.\n\nEste plan es... creativo. Pero es la mejor forma de infiltrarnos en su territorio.\n\nHabla con Meredy cuando estés $glisto:lista; para que te lance el hechizo.\n\nElla me garantizó que los efectos solo serán temporales.', '', '', '', '', '', '', 38134),
(56344, 'esMX', 'Hacia la Ciudadela Mazoscuro', 'Reúnete con la capitana Garrick afuera de la Ciudadela Mazoscuro.', 'Rescatamos a todos menos a la capitana de la expedición. El Exploramático de Lindie la vio justo en las afueras de la Ciudadela Mazoscuro.\n\nA Meredy se le ocurrió un… plan interesante para rescatar a la capitana. Quizá sea nuestra única oportunidad.\n\nVen. Nos reuniremos en las sombras de la Ciudadela Mazoscuro, y ahí daremos comienzo a nuestra misión de rescate.', '', '', '', '', '', 'Reúnete con la capitana Garrick afuera de la Ciudadela Mazoscuro.', 38134),
(55639, 'esMX', 'Quien mora en el foso', 'Rescata a $1oa miembros de la expedición atrapados', 'El viento susurra que hay gente atrapada en el foso. Es posible que haya más miembros de la expedición dentro.\n\nMe temo que dependerá de ti bajar y salvar a los sobrevivientes.\n\nDebería haber seis en total... Aunque los vientos dicen que hay una persona más lejos...\n\nCon nuestra suerte, el último sobreviviente está en el fondo del foso.\n\nBuena suerte, $n. Ah, y... procura que no te sigan las arañas cuando salgas.', '', '', '', '', '', 'Preséntate nuevamente ante la capitana Garrick.', 38134),
(54933, 'esMX', 'Luz en libertad', 'Usa la luz de engendro de luz para disipar la energía necrótica cercana.', 'Ah... no estás del lado de los ogros. Por favor ayúdame.\n\nMe ataron en contra de mi voluntad con magia oscura. Solo necesito que me liberes.\n\nToma un poco de mi luz. Úsala para disipar las energías necróticas que me mantienen cautivo.', '', '', '', '', '', '', 38134),
(55882, 'esMX', 'Mensaje a la base', 'Vuelve al campamento de la Alianza y habla con la capitana Garrick.', '¡Lo logramos! ¡Qué emoción! ¿Así se sienten todos los aventureros?\n\n¡Podría acostumbrarme a esto!\n\nVolvamos al campamento e informemos a la capitana de nuestro triunfo.', '', '', '', '', '', 'Vuelve al campamento de la Alianza y habla con la capitana Garrick.', 38134),
(55764, 'esMX', 'La matanza de las arpías', 'Derrota a $1oa arpías y sus aliados.', 'Las arpías se preparan para un asalto espantoso, $n.\n\n¡Quieren atacar a nuestros aliados en el campamento!\n\nLas arpías se lanzan y atrapan a sus víctimas para llevarlas a sus nidos... y darse un festín.\n\nTenemos que detenerlas. Mata a las arpías y a sus huargos y cerciórate de debilitarlas para que no puedan atacarnos.', '', '', '', '', '', '', 38134),
(55881, 'esMX', 'Purga de tótems', 'Incendia $1oa tótems de arpías.', 'Los tótems de las arpías están por todas partes.\n\nLas arpías son conocidas por usar su magia para corromper a los que las rodean. Incluso ahora, escucho susurros despreciables en el aire...\n\n¡Debemos destruir estos tótems antes de que uno de nosotros caiga víctima de su magia oscura!', '', '', '', '', '', '', 38134),
(55763, 'esMX', 'El rescate de Meredy Huntswell', 'Rescata a Meredy Huntswell del ritual de nigromancia de las arpías.', '¡Las arpías tienen prisionera a la maga de nuestra expedición, Meredy Huntswell!\n\nTenemos que detener el ritual y rescatar a Meredy.\n\nTú ve al frente. Kee-La y yo nos quedaremos en la retaguardia por si necesitas apoyo.', '', '', '', '', '', 'Reúnete con Meredy Huntswell en la entrada de la Percha de Arpías.', 38134),
(55965, 'esMX', 'Rumbo oeste', 'Reúnete con Bjorn Manosfirmes al oeste del campamento de la Alianza.', 'La capitana Garrick quiere que vayamos al oeste del campamento a ver si encontramos a otros miembros de la expedición.\n\nAlaria y yo nos adelantaremos. Reúnete con nosotros en el oeste y veremos qué podemos encontrar.', '', '', '', '', '', 'Reúnete con Bjorn Manosfirmes al oeste del campamento de la Alianza.', 38134),
(55196, 'esMX', 'El problema de las arpías', 'Reúnete con Henry Garrick cerca de la Percha de Arpías.', 'Gracias por salvarme, $n. Haré todo lo posible para ayudarte.\n\n¡Tenemos que encontrar a los demás sobrevivientes de mi expedición antes de que los ogros los sacrifiquen para su ritual oscuro!\n\nVi que unas arpías arrastraban a uno de los sobrevivientes. Tienen un nidal en el norte.\n\nKee-La y yo te veremos allí con un informe de exploración.', '', '', '', '', '', 'Reúnete con Henry Garrick cerca de la Percha de Arpías.', 38134),
(58962, 'esMX', 'El trato de un brujo', 'Investiga el cadáver del brujo de la primera expedición.', 'Mientras arrasabas hordas de no-muertos, yo estaba explorando más la zona con el dispositivo de Lindie.\n\nVi lo que parecía ser un portal cerca del puente, junto al cadáver de un brujo que creíamos perdido en el naufragio.\n\n¿Crees que podrías investigar la zona e intentar cerrar ese portal? No necesitamos más problemas en esta isla; ya tenemos suficientes.', '', '', '', '', '', 'Habla con tu nuevo abisario leal.', 38134),
(55194, 'esMX', 'Nunca son suficientes suministros', 'Cómprale un objeto a la intendente Richter y véndele cualquiera de tus objetos.', 'La intendente Richter consiguió algunos suministros de los restos de esta isla.\n\n¿Por qué no la visitas? Tal vez tenga algo que necesites\n\nTienes que equiparte bien para enfrentar lo que nos espera.', '', '', '', '', '', '', 38134),
(55879, 'esMX', 'Monta el jabalí mejorado científicamente', 'Monta el jabalí gigante para destruir el ejército de no-muertos.', 'No sabemos cuánto durará el redimensionamiento, así que avancemos.\n\nVamos a montar este jabalí gigante y arrasar con el ejército de no-muertos que nos separa de Henry.\n\nLos más grandes vibran con magia oscura. Si los matamos, seguramente acabarán con todos los enemigos cerca de ellos.\n\nCon suerte, Henry sabrá más sobre los planes de los ogros.', '', '', '', '', '', 'Busca a Henry Garrick.', 38134),
(55193, 'esMX', 'El Exploramático 5000', 'Usa el Exploramático 5000 para buscar a Henry Garrick.', 'Estás buscando a Henry Garrick, ¿no? Es un buen sujeto, ¡un poco sombrío pero agradable!\n\n¡Afortunadamente, has rescatado al único e inigualable Lindie Resortín, inventor extraordinario! \n\nTengo mi Exploramático 5000 listo. Subirá al cielo y te permitirá explorar toda el área.\n\nTú harás los honores. ¡Usa mi Exploramático 5000 para buscar a Henry y el resto de la expedición!', '', '', '', '', '', '', 38134),
(55184, 'esMX', 'Nigromancia de jabaespines prohibida', 'Mata a $1oa jabaespines en la Zarzas de Jabaespines.', 'Los jabaespines son primitivos y salvajes. Raras veces practican otra magia aparte de la geomancia.\n\nPero estos jabaespines particulares parecen estar incursionando en la nigromancia. Esto debe parar.\n\nMata a los nigromantes en su guarida. ¡No podemos permitirles que levanten un ejército de no-muertos!', '', '', '', '', '', 'Reúnete con Austin Huxworth al norte de las Zarzas de Jabaespines.', 38134),
(55186, 'esMX', 'Muerte a los jabaespines', 'Mata al geoseñor Grek\'og.', 'Según investigué, los jabaespines salvajes están realizando un ritual de nigromancia en uno de los miembros de la expedición.\n\nSu líder es el geoseñor Grek\'og. Es él quien quiere drenar la vida de nuestro amigo.\n\nMata a Grek\'og y salva a este cautivo de la expedición. Tal vez sepa a dónde llevaron a los demás.', '', 'El jabaespín a cargo del ritual en uno de los miembros de la expedición.', 'Geoseñor Grek\'og', '', '', 'Reúnete con Lindie Resortín al norte de las Zarzas de Jabaespines.', 38134),
(55173, 'esMX', 'Rumbo norte', 'Explora el norte y busca a Austin Huxworth.', 'Los jabaespines secuestraron al resto de la expedición y los llevaron al norte.\n\nOí decir que necesitaban más sacrificios para una especie de ritual.\n\n¡Por favor, tienes que rescatarlos! El hijo de la capitana Garrick era parte de nuestro grupo. Juró que su madre nos salvaría.', '', '', '', '', '', 'Busca a Austin Huxworth en el norte.', 38134),
(59254, 'esMX', 'Tácticas de combate mejoradas', 'Entrena con la capitana Garrick.', 'Alaria dice que los jabaespines secuestraron al resto de la expedición... también a mi hijo.\n\nSegún parece, tendremos que internarnos en la guarida de los jabaespines. Y eso no es algo sencillo de hacer. Son más agresivos y más inteligentes que los múrlocs a los que te enfrentaste antes.\n\nTengo que estar segura de que no te enviaré a tu muerte. Por eso mismo, vamos a llevar a cabo una última sesión de entrenamiento.', '', '', '', '', '', '', 38134),
(55174, 'esMX', 'Carne cocida', 'Consigue $1oa carne cruda de la fauna que rodea el Campamento Abandonado y cocínala en una fogata.', 'Esta es Alaria, una chamán que iba con la expedición perdida.\n\nCasi muere de inanición. ¡Tenemos que darle algo de comer!\n\nCaza fauna cercana para conseguir un poco de carne. Trae cualquier cosa que encuentres para cocinar.\n\nSi logramos que Alaria recobre su fuerza, puede que nos diga qué les pasó a los demás.', '', '', '', '', '', 'Dale la carne cocinada a Alaria.', 38134),
(58209, 'esMX', 'Mantén tu posición', 'Practica con el soldado Cole.', 'Espero que la lluvia no sea un mal augurio. Se supone que esto es una simple misión de rescate.\n\nPracticarás conmigo hoy. Tenemos que asegurarnos de que podrás defenderte cuando desembarquemos.\n\n¡Veamos qué puedes hacer!', '', '', '', '', '', '', 38134),
(54951, 'esMX', 'Cuidados de emergencia', 'Usa un equipo de primeros auxilios en Austin Huxworth, Bjorn Manosfirmes y Kee-la.', 'Tenemos que enmendar a todos antes de comenzar la búsqueda de mi... de la expedición perdida.\n\nLlévate un equipo de primeros auxilios y atiende a los heridos. Nadie se va a quedar atrás.', '', '', '', '', '', '', 38134),
(59342, 'esMX', 'Domar lo salvaje', 'Aprende Domesticar bestia de Austin Huxworth. Luego usa Domesticar bestia con cualquier criatura salvaje cercana.', '$gUn cazador:Una cazadora; como tú necesita una bestia confiable a su lado. De lo contrario, estos jabaespines te asesinarán.\n\nCuando estés $glisto:lista;, te enseñaré lo que necesitas para domar a una bestia como esa. Luego, tendrás que salir en busca de tu leal compañero.', '', '', '', '', '', '', 38134),
(55992, 'esMX', 'Calabozo: Ciudadela Mazoscuro', 'Completa el calabozo \"Ciudadela Mazoscuro\".', 'Gor\'groth planea resucitar a un poderoso dragón, Ravnyr.\n\nEstá llevando a cabo el ritual oscuro en la cima de la ciudadela. Pero al salvarme a mí y a mi tripulación, has obstaculizado sus planes.\n\nAhora, debes atacar la ciudadela e impedir que complete el ritual. Su magia oscura es un insulto para la Luz.\n\nNecesitamos toda la ayuda posible. Dentro de la ciudadela, te toparás con los tenientes más importantes de Gor\'groth.', '', '', '', '', '', '', 38134),
(56034, 'esMX', 'Redimensionando la situación', 'Usa el redimensionador v9.0.1 contra $1oa jabalíes merodeadores.', 'El Redimensionador v9.0.1 apenas funciona con objetos inanimados. ¡No tengo idea de cuál será el resultado con materia orgánica!\n\n¡Pero si no hacemos algo, Henry morirá!\n\nEn tiempos de guerra, los experimentos científicos son fundamentales, $n.\n\nToma el Redimensionador v9.0.1. Te seguiré y lo calibraré.\n\n¡Vamos a montar un jabalí gigante!', '', '', '', '', '', 'Habla con la capitana Garrick.', 38134);

UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=31815 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=54748 AND `locale`='esMX');
UPDATE `quest_template_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=2 AND `locale`='esMX');


DELETE FROM `quest_objectives_locale` WHERE (`locale`='esMX' AND `ID` IN (389997,389991,389990,394292,389996,389995,389994,389970,389973,389972,389971,390205,390204,390131,393740,391940,391939,390025,390024,390023,390022,389603,389809,389775,395231,395234,395230,396763,388875,389796,391875,388849,396220,394179,396789,393824,391859,391858,388448,396359,396360,395924,394065,394461,390101));
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(389997, 'esMX', 55991, 0, 'Viaje a Ciudad de Ventormenta en Grifo de la Alianza', 38134),
(389991, 'esMX', 55989, 0, 'Catapultas destruidas', 38134),
(389990, 'esMX', 55988, 0, 'Ogros asesinados', 38134),
(394292, 'esMX', 55990, 4, 'Desactiva las runas que incapacitan a la capitana Kelra', 38134),
(389996, 'esMX', 55990, 2, 'Piedra de resguardo de Grunk recuperada', 38134),
(389995, 'esMX', 55990, 1, 'Piedra de resguardo de Wug recuperada', 38134),
(389994, 'esMX', 55990, 0, 'Piedra de resguardo de Jugnug recuperada', 38134),
(389970, 'esMX', 55981, 1, 'Usa /señalar con Lindie o Corcho', 38134),
(389973, 'esMX', 55981, 4, 'Llega a la entrada de la ciudadela', 38134),
(389972, 'esMX', 55981, 3, 'Usa /bailar en el área de cocina', 38134),
(389971, 'esMX', 55981, 2, 'Usa /saludar con Gor\'groth.', 38134),
(390205, 'esMX', 55981, 6, 'Busca al ogro en el área de cocina', 38134),
(390204, 'esMX', 55981, 0, 'Entra a la Ciudadela Mazoscuro', 38134),
(390131, 'esMX', 55981, 5, 'Pide a Meredy que use el hechizo de transformación en ogro', 38134),
(393740, 'esMX', 55639, 2, 'Sube a Ralia Cazasueños para escapar', 38134),
(391940, 'esMX', 55639, 1, 'Derrota a Hrun para rescatar a Ralia Cazasueños', 38134),
(391939, 'esMX', 55639, 0, 'Miembro de expedición atrapado rescatado de los capullos', 38134),
(390025, 'esMX', 54933, 4, 'Cuarta energía necrótica dispersada', 38134),
(390024, 'esMX', 54933, 3, 'Tercera energía necrótica dispersada', 38134),
(390023, 'esMX', 54933, 2, 'Segunda energía necrótica dispersada', 38134),
(390022, 'esMX', 54933, 1, 'Primera energía necrótica dispersada', 38134),
(389603, 'esMX', 55764, 0, 'Arpías y cohortes asesinados', 38134),
(389809, 'esMX', 55881, 0, 'Tótems de arpías quemados', 38134),
(389775, 'esMX', 55763, 1, 'Meredy Huntswell rescatada', 38134),
(395231, 'esMX', 58962, 2, 'Abisario invocado con el grimorio', 38134),
(395234, 'esMX', 58962, 3, 'Grimorio antiguo recuperado', 38134),
(395230, 'esMX', 58962, 1, 'Cadáver de brujo muerto investigado', 38134),
(396763, 'esMX', 55194, 1, 'Cualquier objeto vendido a la intendente Richter', 38134),
(388875, 'esMX', 55194, 0, 'Cualquier objeto comprado a la intendente Richter', 38134),
(389796, 'esMX', 55879, 0, 'Sube al jabalí gigante', 38134),
(391875, 'esMX', 55193, 0, 'Usa el Exploramático 5000 para explorar el área', 38134),
(388849, 'esMX', 55184, 1, 'Jabaespín asesinado', 38134),
(396220, 'esMX', 59254, 1, 'Habilidades probadas contra la Capitana Garrick', 38134),
(394179, 'esMX', 55174, 0, 'Cocina la carne en la hoguera', 38134),
(396789, 'esMX', 55174, 2, 'Carne cruda obtenida de vida silvestre', 38134),
(393824, 'esMX', 58209, 0, 'Practica con el soldado Cole', 38134),
(391859, 'esMX', 54951, 2, 'Equipo de primeros auxilios usado en Austin Huxworth', 38134),
(391858, 'esMX', 54951, 1, 'Equipo de primeros auxilios usado en Kee-La', 38134),
(388448, 'esMX', 54951, 0, 'Equipo de primeros auxilios usado en Bjorn Manosfirmes', 38134),
(396359, 'esMX', 59342, 1, 'Cualquier bestia salvaje domada', 38134),
(396360, 'esMX', 59342, 0, 'Domesticar bestia aprendido de Austin', 38134),
(395924, 'esMX', 55992, 2, 'Habla con la capitana Garrick para abandonar Ciudadela Mazoscuro', 38134),
(394065, 'esMX', 55992, 0, 'Ritual final de Gor\'groth detenido', 38134),
(394461, 'esMX', 55992, 1, 'Usa el Buscador de grupos para entrar al calabozo \"Ciudadela Mazoscuro\"', 38134),
(390101, 'esMX', 56034, 0, 'Redimensionador v9.0.1 probado con jabalíes merodeadores', 38134);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=38134 WHERE (`ID`=269051 AND `locale`='esMX');


DELETE FROM `quest_request_items_locale` WHERE (`locale`='esMX' AND `ID` IN (55990,58962,56034,55174));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(55990, 'esMX', '¿Así que estas son las piedras que usaron para contenerme? Los ogros sí que estaban preocupados de que frustraras sus planes.', 38134),
(58962, 'esMX', 'Veo que tienes el grimorio con el que se realizó el pacto.', 38134),
(56034, 'esMX', 'Ten cuidado cuando apuntas el Redimensionador v9.0.1. Verifica que estás usándolo solo en los jabalíes del área más cercana.', 38134),
(55174, 'esMX', 'Por favor... necesito... comida...', 38134);

DELETE FROM `scene_template` WHERE (`SceneId`=2402 AND `ScriptPackageID`=2809);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2402, 16, 2809, 0);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (56839 /*-Unknown-*/, 54933 /*-Unknown-*/, 58962 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(56839, 0, 0, 0, 0, 0, 0, 0, 0, '<Encuentras un alijo de tesoros, ¡tal como lo anticipó el cartel de los ogros!>', 38134), -- -Unknown-
(54933, 0, 0, 0, 0, 0, 0, 0, 0, 'Muchas gracias, $n. Debo abandonar este mundo, pero te deseo suerte.\n\nTe otorgo mi bendición. Espero que te sea útil para combatir a estos monstruos.', 38134), -- -Unknown-
(58962, 0, 0, 0, 0, 0, 0, 0, 0, 'Se ha cerrado nuestro trato.\n\nLlámame desde el Vacío y responderé tu llamado.\n\n<El abisario mira el cadáver del huargo.>\n\nVeamos si eres más fuerte que los anteriores.', 38134); -- -Unknown-



DELETE FROM `quest_poi` WHERE (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55879 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(55989, 0, 2, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55989, 0, 1, 0, 389991, 326651, 2175, 1409, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55989, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(54933, 0, 4, 3, 390025, 326719, 2175, 1409, 0, 0, 0, 0, 0, 1794183, 0, 38134), -- -Unknown-
(54933, 0, 3, 2, 390024, 326718, 2175, 1409, 0, 0, 0, 0, 0, 1794182, 0, 38134), -- -Unknown-
(54933, 0, 2, 1, 390023, 326717, 2175, 1409, 0, 0, 0, 0, 0, 1794181, 0, 38134), -- -Unknown-
(54933, 0, 1, 0, 390022, 326716, 2175, 1409, 0, 0, 0, 0, 0, 1794179, 0, 38134), -- -Unknown-
(54933, 0, 0, -1, 0, 0, 2175, 1409, 0, 0, 0, 0, 0, 1827148, 0, 38134), -- -Unknown-
(55879, 0, 4, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55879, 0, 3, 2, 395073, 162817, 2175, 1409, 0, 0, 0, 0, 0, 1886678, 0, 38134), -- -Unknown-
(55879, 1, 2, 0, 389796, 156595, 2175, 1409, 0, 2, 0, 72677, 0, 0, 0, 38134), -- -Unknown-
(55879, 0, 1, 0, 389796, 156595, 2175, 1409, 0, 2, 0, 72676, 0, 0, 0, 38134), -- -Unknown-
(55879, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55186, 0, 2, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(55186, 0, 1, 0, 388852, 151091, 2175, 1409, 0, 0, 0, 0, 0, 1731928, 0, 38134), -- -Unknown-
(55186, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=55989 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55989 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(55989, 2, 0, 705, -1874, 165, 38134), -- -Unknown-
(55989, 1, 4, 536, -2086, 0, 38134), -- -Unknown-
(55989, 1, 3, 490, -2052, 0, 38134), -- -Unknown-
(55989, 1, 2, 441, -2004, 0, 38134), -- -Unknown-
(55989, 1, 1, 464, -1997, 0, 38134), -- -Unknown-
(55989, 1, 0, 611, -2118, 0, 38134), -- -Unknown-
(55989, 0, 0, 707, -1877, 187, 38134), -- -Unknown-
(54933, 4, 0, 280, -2474, 0, 38134), -- -Unknown-
(54933, 3, 0, 291, -2514, 0, 38134), -- -Unknown-
(54933, 2, 0, 325, -2497, 0, 38134), -- -Unknown-
(54933, 1, 0, 314, -2460, 0, 38134), -- -Unknown-
(54933, 0, 0, 299, -2486, 115, 38134), -- -Unknown-
(55879, 4, 0, 99, -2424, 165, 38134), -- -Unknown-
(55879, 3, 0, 244, -2243, 84, 38134), -- -Unknown-
(55879, 2, 11, 207, -2349, 0, 38134), -- -Unknown-
(55879, 2, 10, 179, -2316, 0, 38134), -- -Unknown-
(55879, 2, 9, 183, -2274, 0, 38134), -- -Unknown-
(55879, 2, 8, 192, -2248, 0, 38134), -- -Unknown-
(55879, 2, 7, 219, -2215, 0, 38134), -- -Unknown-
(55879, 2, 6, 249, -2218, 0, 38134), -- -Unknown-
(55879, 2, 5, 275, -2245, 0, 38134), -- -Unknown-
(55879, 2, 4, 287, -2271, 0, 38134), -- -Unknown-
(55879, 2, 3, 287, -2295, 0, 38134), -- -Unknown-
(55879, 2, 2, 269, -2325, 0, 38134), -- -Unknown-
(55879, 2, 1, 249, -2346, 0, 38134), -- -Unknown-
(55879, 2, 0, 231, -2352, 90, 38134), -- -Unknown-
(55879, 1, 0, 116, -2424, 90, 38134), -- -Unknown-
(55879, 0, 0, 228, -2294, 81, 38134), -- -Unknown-
(55186, 2, 0, -138, -2639, 90, 38134), -- -Unknown-
(55186, 1, 0, 18, -2509, 73, 38134), -- -Unknown-
(55186, 0, 0, 105, -2415, 90, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID`=58962;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(58962, 1, 6, 25, 0, 0, 0, 0, 0, 38134); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (56034 /*-Unknown-*/, 58962 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(56034, 0, 0, 0, 0, 'Ten cuidado cuando apuntas el Redimensionador v9.0.1. Verifica que estás usándolo solo en los jabalíes del área más cercana.', 38134), -- -Unknown-
(58962, 0, 0, 0, 0, 'Veo que tienes el grimorio con el que se realizó el pacto.', 0); -- -Unknown-


DELETE FROM `creature_template_addon` WHERE `entry` IN (156986 /*156986 (Capataz ogro)*/, 163246 /*163246 (Abisario invocado)*/, 163218 /*163218 (Abisario)*/, 163209 /*163209 (Hubert Lucas) - Permanent Feign Death (Stun, Untrackable, Immune)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(156986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156986 (Capataz ogro)
(163246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163246 (Abisario invocado)
(163218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163218 (Abisario)
(163209, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'); -- 163209 (Hubert Lucas) - Permanent Feign Death (Stun, Untrackable; Immune)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=157300; -- 157300 (Tunk)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=153581; -- 153581 (Grunk)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=153582; -- 153582 (Wug)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=153239; -- 153239 (Ogre Brute)
UPDATE `creature_template_addon` SET `bytes1`=33554432 WHERE `entry`=152843; -- 152843 (Harpy Boltcaller)
UPDATE `creature_template_addon` SET `auras`='316915' WHERE `entry`=160394; -- 160394 (Barrow Spider)
UPDATE `creature_template_addon` SET `auras`='316915' WHERE `entry`=160433; -- 160433 (Barrow Spiderling)
UPDATE `creature_template_addon` SET `auras`='305513 325408' WHERE `entry`=156799; -- 156799 (Henry Garrick)

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=150 AND `Entry` IN (156913,166262)) OR (`DifficultyID`=0 AND `Entry` IN (163246,163218,163209));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(156913, 150, 9, 10, -2, -2, 1729, 38134),
(166262, 150, 9, 10, -2, -2, 1729, 38134),
(163246, 0, 1, 10, 0, 0, 741, 38134),
(163218, 0, 1, 10, 0, 0, 741, 38134),
(163209, 0, 1, 10, 0, 0, 741, 38134);



UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=154155 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156942 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156932 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156900 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156886 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156882 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=155199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156986 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=160394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=160433 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=161666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156801 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156800 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=157114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=149899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=149915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=165730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=165727 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156716 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=151091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=150238 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=149917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=156610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=10 WHERE (`Entry`=156612 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=5, `ContentTuningID`=957 WHERE (`Entry`=160737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=161133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=161131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1 WHERE (`Entry`=161130 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92822;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85966;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77694;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87543;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78416;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.694444000720977783, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=92803;
UPDATE `creature_model_info` SET `BoundingRadius`=0.79957592487335205, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=72536;
UPDATE `creature_model_info` SET `BoundingRadius`=0.928183615207672119, `CombatReach`=0.655102074146270751 WHERE `DisplayID`=1157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10824;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=79614;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=70722;
UPDATE `creature_model_info` SET `BoundingRadius`=2.104584932327270507, `CombatReach`=1.346938848495483398 WHERE `DisplayID`=52696;
UPDATE `creature_model_info` SET `BoundingRadius`=0.798952639102935791, `CombatReach`=1.125 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277218431234359741, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=2177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.798952639102935791, `CombatReach`=1.125 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=75374;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=156986 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(156986, 1, 164292, 0, 0, 0, 0, 0, 0, 0, 0); -- Capataz ogro


DELETE FROM `gossip_menu` WHERE (`MenuId`=25321 AND `TextId`=39934) OR (`MenuId`=24887 AND `TextId`=39219) OR (`MenuId`=25143 AND `TextId`=39616);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25321, 39934, 38134), -- 156886 (Meredy Huntswell)
(24887, 39219, 38134), -- 153211 (Meredy Huntswell)
(25143, 39616, 38134); -- 163209 (Hubert Lucas)


DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (24887,25143));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(24887, 0, 0, 'Combatiré a las arpías que se acerquen. ¿Puedes liberarte con tu magia?', 0, 38134),
(25143, 0, 0, '<Levántate y recupera el grimorio del brujo para terminar el ritual e invocar a un abisario.>', 0, 38134);



UPDATE `creature_template` SET `faction`=534 WHERE `entry`=163963; -- Brunston Martillero
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=156913; -- Cadáver putrefacto
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=166262; -- Cadáver putrefacto
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=156501; -- Ravnyr
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=161504; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=157300; -- Tunk
UPDATE `creature_template` SET `minlevel`=10 WHERE `entry`=156814; -- Gor'groth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156965; -- Captain Kelra
UPDATE `creature_template` SET `minlevel`=1 WHERE `entry`=156961; -- Captain Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=156960; -- Meredy Huntswell
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=156954; -- Captain Kelra
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=6491; -- Ángel de la Resurrección
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=156943; -- Meredy Huntswell
UPDATE `creature_template` SET `minlevel`=1, `faction`=1732 WHERE `entry`=156941; -- Captain Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156942; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156932; -- Ralia Dreamchaser
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156929; -- Ralia Dreamchaser
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=156902; -- Ralia Cazasueños
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=156900; -- Hrun el Exiliado
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156891; -- Bjorn Stouthands
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=156886; -- Meredy Huntswell
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156885; -- Kee-La
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=163069; -- Yorah
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=155197; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=155199; -- Kee-La
UPDATE `creature_template` SET `gossip_menu_id`=24887, `faction`=1732 WHERE `entry`=153211; -- Meredy Huntswell
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156860; -- Kee-La
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156859; -- Henry Garrick
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=152998; -- Hunting Worg
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=163246; -- Abisario invocado
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=163218; -- Abisario
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=152843; -- Harpy Boltcaller
UPDATE `creature_template` SET `gossip_menu_id`=25143, `minlevel`=1, `maxlevel`=10, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=163209; -- Hubert Lucas
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=160394; -- Barrow Spider
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=160433; -- Barrow Spiderling
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=153964; -- Pico sangrante
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=150245; -- Lindie Springstock
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=161666; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156833; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=1 WHERE `entry`=156807; -- Captain Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10, `unit_flags2`=2048 WHERE `entry`=156595; -- Giant Boar
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=154300; -- Bjorn Stouthands
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156803; -- Alaria
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=156801; -- Private Cole
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=156800; -- Quartermaster Richter
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=157114; -- Lightspawn
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156799; -- Henry Garrick
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=149899; -- Lindie Springstock
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=149915; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=154301; -- Lindie Springstock
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=154327; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=175031; -- Alaria
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=154170; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=149917; -- Private Cole
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=156622; -- Quartermaster Richter
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=156610; -- Austin Huxworth
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156609; -- Bjorn Stouthands
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=10 WHERE `entry`=156612; -- Kee-La
UPDATE `creature_template` SET `minlevel`=1, `faction`=1732 WHERE `entry`=156626; -- Captain Garrick
UPDATE `creature_template` SET `faction`=2618 WHERE `entry`=167886; -- Alliance Sailor
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=157049; -- Helmsman Lenard
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=157043; -- Kee-La
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=157042; -- Quartermaster Richter
UPDATE `creature_template` SET `faction`=1732 WHERE `entry`=157046; -- Austin Huxworth
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=17 WHERE `entry`=160737; -- Muñeco de combate
UPDATE `creature_template` SET `faction`=2618 WHERE `entry`=157044; -- Bjorn Stouthands


UPDATE `quest_template` SET `FlagsEx`=2107456, `VerifiedBuild`=38134 WHERE `ID`=55991; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1720, `RewardBonusMoney`=90, `FlagsEx`=2099392, `VerifiedBuild`=38134 WHERE `ID`=31815; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1470, `RewardBonusMoney`=90 WHERE `ID`=55989; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1470, `RewardBonusMoney`=90 WHERE `ID`=55988; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1470, `RewardBonusMoney`=90 WHERE `ID`=55990; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=4410, `RewardBonusMoney`=120, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=56839; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1470, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55981; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=735, `RewardBonusMoney`=30, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=56344; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=2940, `RewardBonusMoney`=90, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55639; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=100, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=54933; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=510, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55882; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55764; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55881; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55763; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=400, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55965; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=400, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55196; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1600, `RewardBonusMoney`=150, `FlagsEx`=2097218, `VerifiedBuild`=38134 WHERE `ID`=58962; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=600, `RewardBonusMoney`=30, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55194; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55879; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55193; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55184; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=55186; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=180, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=55173; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=59254; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=30, `FlagsEx`=2105410, `VerifiedBuild`=38134 WHERE `ID`=55174; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `FlagsEx`=2105410, `VerifiedBuild`=38134 WHERE `ID`=58209; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=54951; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60 WHERE `ID`=2; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=30, `FlagsEx`=2105410, `VerifiedBuild`=38134 WHERE `ID`=56775; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=30 WHERE `ID`=59342; -- -Unknown-
UPDATE `quest_template` SET `QuestType`=2, `RewardMoney`=4060, `RewardBonusMoney`=210 WHERE `ID`=55992; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=150, `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=56034; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=35651648, `VerifiedBuild`=38134 WHERE `ID`=46736; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=35651648, `VerifiedBuild`=38134 WHERE `ID`=46735; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=35651648, `VerifiedBuild`=38134 WHERE `ID`=46277; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=200, `RewardBonusMoney`=30 WHERE `ID`=32470; -- -Unknown-


UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389997; -- 389997
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=269051; -- 269051
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389991; -- 389991
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389990; -- 389990
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394292; -- 394292
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394291; -- 394291
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389996; -- 389996
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389995; -- 389995
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389994; -- 389994
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391409; -- 391409
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389970; -- 389970
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389973; -- 389973
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389972; -- 389972
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389971; -- 389971
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390205; -- 390205
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390204; -- 390204
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390131; -- 390131
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=393740; -- 393740
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391940; -- 391940
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391939; -- 391939
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390025; -- 390025
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390024; -- 390024
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390023; -- 390023
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390022; -- 390022
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389603; -- 389603
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389809; -- 389809
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389775; -- 389775
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395231; -- 395231
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395234; -- 395234
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395230; -- 395230
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396763; -- 396763
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388875; -- 388875
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395073; -- 395073
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396499; -- 396499
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=389796; -- 389796
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391875; -- 391875
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388849; -- 388849
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388852; -- 388852
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396220; -- 396220
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394179; -- 394179
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396789; -- 396789
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=393824; -- 393824
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391859; -- 391859
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=391858; -- 391858
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=388448; -- 388448
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396359; -- 396359
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396360; -- 396360
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=395924; -- 395924
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394065; -- 394065
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=394461; -- 394461
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=390101; -- 390101


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269051 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389996 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389995 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389994 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391409 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389971 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390131 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393740 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391940 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391939 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389775 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396763 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388875 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=395073 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388852 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396220 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396789 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396789 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396789 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=395924 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394065 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394065 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390101 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58962 AND `Idx`=0);


UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168255 AND `Idx`=0); -- Alliance Gryphon
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163963 AND `Idx`=0); -- Brunston Martillero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154155 AND `Idx`=0); -- Grifo de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156913 AND `Idx`=2); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156913 AND `Idx`=1); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156913 AND `Idx`=0); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166262 AND `Idx`=2); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166262 AND `Idx`=1); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=166262 AND `Idx`=0); -- Cadáver putrefacto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165198 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165198 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157328 AND `Idx`=0); -- Canalizador Mazoscuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156828 AND `Idx`=1); -- Orbe sombrío
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156828 AND `Idx`=0); -- Orbe sombrío
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161504 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156821 AND `Idx`=2); -- Clamasombras Mazoscuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156821 AND `Idx`=1); -- Clamasombras Mazoscuro
UPDATE `creature_template_model` SET `CreatureDisplayID`=92822, `DisplayScale`=2.5, `VerifiedBuild`=38134 WHERE (`CreatureID`=156821 AND `Idx`=0); -- Clamasombras Mazoscuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156501 AND `Idx`=0); -- Ravnyr
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157300 AND `Idx`=0); -- Tunk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168740 AND `Idx`=0); -- Ermitaña de ciudadela
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161350 AND `Idx`=0); -- Capitana Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156814 AND `Idx`=0); -- Gor'groth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168738 AND `Idx`=2); -- Rata de ciudadela
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168738 AND `Idx`=1); -- Rata de ciudadela
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168738 AND `Idx`=0); -- Rata de ciudadela
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156825 AND `Idx`=1); -- Centurión Mazoscuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156825 AND `Idx`=0); -- Centurión Mazoscuro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156965 AND `Idx`=0); -- Captain Kelra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153581 AND `Idx`=0); -- Grunk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174529 AND `Idx`=0); -- Jard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174528 AND `Idx`=0); -- Zink
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174523 AND `Idx`=0); -- Tiang
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174527 AND `Idx`=0); -- Trem
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174525 AND `Idx`=0); -- Kee
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153583 AND `Idx`=0); -- Jugnug
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153582 AND `Idx`=0); -- Wug
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156961 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156960 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161306 AND `Idx`=1); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161306 AND `Idx`=0); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156954 AND `Idx`=0); -- Captain Kelra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154103 AND `Idx`=0); -- Chef ogro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154146 AND `Idx`=0); -- Wug
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154147 AND `Idx`=0); -- Jugnug
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153580 AND `Idx`=0); -- Gor'groth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154145 AND `Idx`=0); -- Grunk
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153238 AND `Idx`=0); -- Jabalí domesticado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153242 AND `Idx`=3); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153242 AND `Idx`=2); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153242 AND `Idx`=1); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153242 AND `Idx`=0); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153239 AND `Idx`=3); -- Ogre Brute
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153239 AND `Idx`=2); -- Ogre Brute
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153239 AND `Idx`=1); -- Ogre Brute
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153239 AND `Idx`=0); -- Ogre Brute
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156948 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156947 AND `Idx`=0); -- Ralia Dreamchaser
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153566 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153565 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164927 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164927 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=6491 AND `Idx`=0); -- Ángel de la Resurrección
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155733 AND `Idx`=0); -- Cofre del tesoro escondido
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172026 AND `Idx`=2); -- Cucaracha
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172026 AND `Idx`=1); -- Cucaracha
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172026 AND `Idx`=0); -- Cucaracha
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161006 AND `Idx`=3); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161006 AND `Idx`=2); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161006 AND `Idx`=1); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161006 AND `Idx`=0); -- Ogre Shadowcaster
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156944 AND `Idx`=0); -- Ralia Dreamchaser
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156943 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156942 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156941 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163040 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163040 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172027 AND `Idx`=1); -- Carroñero roedor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172027 AND `Idx`=0); -- Carroñero roedor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171997 AND `Idx`=2); -- Vigía de los bosques
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171997 AND `Idx`=1); -- Vigía de los bosques
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=171997 AND `Idx`=0); -- Vigía de los bosques
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163039 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163039 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156932 AND `Idx`=0); -- Ralia Dreamchaser
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165352 AND `Idx`=0); -- Ralia Dreamchaser
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160451 AND `Idx`=1); -- Hrun el Exiliado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160451 AND `Idx`=0); -- Hrun el Exiliado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156929 AND `Idx`=0); -- Ralia Dreamchaser
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156902 AND `Idx`=0); -- Ralia Cazasueños
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160964 AND `Idx`=3); -- Freed Expedition Member
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160964 AND `Idx`=2); -- Freed Expedition Member
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160964 AND `Idx`=1); -- Freed Expedition Member
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160964 AND `Idx`=0); -- Freed Expedition Member
UPDATE `creature_template_model` SET `DisplayScale`=2, `VerifiedBuild`=38134 WHERE (`CreatureID`=156900 AND `Idx`=0); -- Hrun el Exiliado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156891 AND `Idx`=0); -- Bjorn Stouthands
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156886 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156885 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156887 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164026 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164026 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164025 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164025 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163069 AND `Idx`=0); -- Yorah
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=1860 AND `Idx`=0); -- Voidwalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156882 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=43499 AND `Idx`=0); -- Consagración
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155199 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153211 AND `Idx`=0); -- Meredy Huntswell
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152571 AND `Idx`=0); -- Harpy Snatcher
UPDATE `creature_template_model` SET `DisplayScale`=2, `VerifiedBuild`=38134 WHERE (`CreatureID`=156986 AND `Idx`=0); -- Capataz ogro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164022 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164022 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157104 AND `Idx`=1); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157104 AND `Idx`=0); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156860 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156859 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152998 AND `Idx`=1); -- Hunting Worg
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152998 AND `Idx`=0); -- Hunting Worg
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169162 AND `Idx`=1); -- Hunting Worg
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=169162 AND `Idx`=0); -- Hunting Worg
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163246 AND `Idx`=0); -- Abisario invocado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155192 AND `Idx`=0); -- Harpy Ambusher
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155197 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162948 AND `Idx`=0); -- Guerrero esquelético
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163533 AND `Idx`=0); -- Hjalmar the Undying
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164868 AND `Idx`=0); -- Monje pandaren
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163218 AND `Idx`=1); -- Abisario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163218 AND `Idx`=0); -- Abisario
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172029 AND `Idx`=1); -- Puercoespín espinoso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172029 AND `Idx`=0); -- Puercoespín espinoso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=172028 AND `Idx`=0); -- Errante montés
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=163209 AND `Idx`=0); -- Hubert Lucas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155572 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155572 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152843 AND `Idx`=0); -- Harpy Boltcaller
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162954 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162954 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160394 AND `Idx`=2); -- Barrow Spider
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160394 AND `Idx`=1); -- Barrow Spider
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160394 AND `Idx`=0); -- Barrow Spider
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160433 AND `Idx`=2); -- Barrow Spiderling
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160433 AND `Idx`=1); -- Barrow Spiderling
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160433 AND `Idx`=0); -- Barrow Spiderling
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153964 AND `Idx`=0); -- Pico sangrante
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153266 AND `Idx`=0); -- Zarpatroz el Terrible
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174977 AND `Idx`=1); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174977 AND `Idx`=0); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156808 AND `Idx`=0); -- Small Boar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165758 AND `Idx`=1); -- Spotted Hopper
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165758 AND `Idx`=0); -- Spotted Hopper
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161666 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150245 AND `Idx`=0); -- Lindie Springstock
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168382 AND `Idx`=1); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=168382 AND `Idx`=0); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156833 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156807 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162817 AND `Idx`=0); -- Torgok
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165150 AND `Idx`=0); -- Monstrous Cadaver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156267 AND `Idx`=0); -- Giant Boar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156781 AND `Idx`=0); -- Capitana Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156595 AND `Idx`=0); -- Giant Boar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156736 AND `Idx`=0); -- Jabalí redimensionado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156749 AND `Idx`=0); -- Lindie Springstock
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156804 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156803 AND `Idx`=0); -- Alaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156801 AND `Idx`=0); -- Private Cole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156800 AND `Idx`=0); -- Quartermaster Richter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154300 AND `Idx`=0); -- Bjorn Stouthands
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=95577 AND `Idx`=0); -- Tentáculo del vacío
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157114 AND `Idx`=0); -- Lightspawn
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156526 AND `Idx`=0); -- Exploramático 5000
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156518 AND `Idx`=0); -- Exploramático 5000
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156799 AND `Idx`=0); -- Henry Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157091 AND `Idx`=0); -- Monstrous Cadaver
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156532 AND `Idx`=3); -- Zombie Servant
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156532 AND `Idx`=2); -- Zombie Servant
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156532 AND `Idx`=1); -- Zombie Servant
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156532 AND `Idx`=0); -- Zombie Servant
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174955 AND `Idx`=0); -- Capitana de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=149899 AND `Idx`=0); -- Lindie Springstock
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154268 AND `Idx`=0); -- Buitre hambriento
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=149915 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165730 AND `Idx`=0); -- Venado de las llanuras
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165711 AND `Idx`=2); -- Cervato de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165711 AND `Idx`=1); -- Cervato de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165711 AND `Idx`=0); -- Cervato de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165757 AND `Idx`=0); -- Perro de pradera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165727 AND `Idx`=2); -- Cierva de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165727 AND `Idx`=1); -- Cierva de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165727 AND `Idx`=0); -- Cierva de la planicie
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156716 AND `Idx`=0); -- Jabalí merodeador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156676 AND `Idx`=0); -- Sobrestante ogro
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155371 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165713 AND `Idx`=1); -- Rata escurridiza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165713 AND `Idx`=0); -- Rata escurridiza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=151091 AND `Idx`=0); -- Geoseñor Grek'og
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156662 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150238 AND `Idx`=1); -- Geomante jabaespín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150238 AND `Idx`=0); -- Geomante jabaespín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165712 AND `Idx`=0); -- Cucaracha
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154301 AND `Idx`=0); -- Lindie Springstock
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150237 AND `Idx`=1); -- Guerrero jabaespín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150237 AND `Idx`=0); -- Guerrero jabaespín
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154327 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156660 AND `Idx`=0); -- Capitana Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164605 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=175031 AND `Idx`=0); -- Alaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164827 AND `Idx`=3); -- Halcón picoafilado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164827 AND `Idx`=2); -- Halcón picoafilado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164827 AND `Idx`=1); -- Halcón picoafilado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164827 AND `Idx`=0); -- Halcón picoafilado
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=89715 AND `Idx`=0); -- Franklin Martin
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165360 AND `Idx`=0); -- Sobreviviente de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=416 AND `Idx`=0); -- Imp
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153168 AND `Idx`=0); -- Capitana Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=151088 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154170 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=151089 AND `Idx`=0); -- Bjorn Manosfirmes
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165189 AND `Idx`=0); -- Mascota de cazador genérica
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=112144 AND `Idx`=0); -- Corgnelius
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156622 AND `Idx`=0); -- Quartermaster Richter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156612 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156610 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156609 AND `Idx`=0); -- Bjorn Stouthands
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=149917 AND `Idx`=0); -- Private Cole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161228 AND `Idx`=1); -- Ermitaño resplandeciente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161228 AND `Idx`=0); -- Ermitaño resplandeciente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156626 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157070 AND `Idx`=1); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157070 AND `Idx`=0); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157051 AND `Idx`=0); -- Compañero de entrenamiento de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155607 AND `Idx`=0); -- Soldado Cole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160656 AND `Idx`=1); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160656 AND `Idx`=0); -- Invisible Stalker
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55689 AND `Idx`=0); -- Hagara la Vinculatormentas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55312 AND `Idx`=0); -- Yor'sahj el Velador
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55308 AND `Idx`=0); -- Señor de la guerra Zon'ozz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=55265 AND `Idx`=0); -- Morchok
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174754 AND `Idx`=0); -- El carruaje del castillo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158336 AND `Idx`=0); -- Carruaje de Amparo Umbrío
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161879 AND `Idx`=0); -- Carruaje de Caída del Orgullo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158365 AND `Idx`=0); -- Carruaje del Bosque del Flagelo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174751 AND `Idx`=0); -- Carruaje de la Compuerta Antigua
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174750 AND `Idx`=0); -- Carruaje del cáliz
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157043 AND `Idx`=0); -- Kee-La
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155125 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=155125 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157046 AND `Idx`=0); -- Austin Huxworth
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156280 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157044 AND `Idx`=0); -- Bjorn Stouthands
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157042 AND `Idx`=0); -- Quartermaster Richter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=157049 AND `Idx`=0); -- Helmsman Lenard
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154867 AND `Idx`=0); -- Jinete de grifos Martillo Salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156345 AND `Idx`=0); -- Grifo Martillo Salvaje
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156403 AND `Idx`=1); -- Un bote
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156403 AND `Idx`=0); -- Un bote
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167886 AND `Idx`=3); -- Alliance Sailor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167886 AND `Idx`=2); -- Alliance Sailor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167886 AND `Idx`=1); -- Alliance Sailor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167886 AND `Idx`=0); -- Alliance Sailor
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160664 AND `Idx`=0); -- Private Cole
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=160737 AND `Idx`=0); -- Muñeco de combate
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174971 AND `Idx`=1); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=174971 AND `Idx`=0); -- Spar Point Advertisement
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=151719 AND `Idx`=0); -- Voice in the Deeps
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152568 AND `Idx`=0); -- Urduu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152360 AND `Idx`=0); -- Hemotóxico el alfa
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=154148 AND `Idx`=0); -- Ama de las mareas Leth'sindra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153928 AND `Idx`=0); -- Señor de las Mareas Dispersio
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153898 AND `Idx`=0); -- Señor de las Mareas Aquatus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152290 AND `Idx`=0); -- Silencioso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152359 AND `Idx`=0); -- Cienagosa la madre de la manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=153658 AND `Idx`=0); -- Shiz'narasz the Consumer
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152552 AND `Idx`=0); -- Shassera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152542 AND `Idx`=0); -- Matriarca de escamas Zodia
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152545 AND `Idx`=0); -- Matriarca de escamas Vynara
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152548 AND `Idx`=0); -- Matriarca de escamas Gratinax
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152795 AND `Idx`=4); -- Petravalva garrarena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152795 AND `Idx`=3); -- Petravalva garrarena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152795 AND `Idx`=2); -- Petravalva garrarena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152795 AND `Idx`=1); -- Petravalva garrarena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152795 AND `Idx`=0); -- Petravalva garrarena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=151870 AND `Idx`=0); -- Castillo de arena
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150583 AND `Idx`=0); -- Arrastrapiés rocamaleza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152682 AND `Idx`=0); -- Prince Vortran
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152681 AND `Idx`=0); -- Príncipe Tifonus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152397 AND `Idx`=0); -- Oronu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152465 AND `Idx`=0); -- Espina de púas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=144644 AND `Idx`=0); -- Arrastraciénagas
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152323 AND `Idx`=0); -- Rey Gakula
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152567 AND `Idx`=0); -- Algasauce
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152448 AND `Idx`=0); -- Caparazón titilante iridiscente
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152553 AND `Idx`=0); -- Escamas de granate
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152555 AND `Idx`=0); -- Elderspawn Nalaada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152414 AND `Idx`=0); -- Elder Unu
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152291 AND `Idx`=0); -- Deslizadora de las profundidades
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152756 AND `Idx`=0); -- Terror Faucedaga
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152556 AND `Idx`=0); -- Chasm-Haunter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152464 AND `Idx`=0); -- Terror de cuevaoscura
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152712 AND `Idx`=0); -- Blindlight
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152361 AND `Idx`=0); -- Horroescama el padre de la manada
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152566 AND `Idx`=0); -- Anémonar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152794 AND `Idx`=1); -- Espirazón amatista
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152794 AND `Idx`=0); -- Espirazón amatista
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152416 AND `Idx`=0); -- Allseer Oma'kil
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=152415 AND `Idx`=0); -- Alga the Eyeless
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162248 AND `Idx`=0); -- Vigía corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162245 AND `Idx`=0); -- Atormentador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162241 AND `Idx`=0); -- Despojamentes corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162253 AND `Idx`=1); -- Taumaturgo corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162253 AND `Idx`=0); -- Taumaturgo corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162251 AND `Idx`=1); -- Invocador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162251 AND `Idx`=0); -- Invocador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158706 AND `Idx`=0); -- Putrefacción corrupta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162254 AND `Idx`=0); -- Observador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158531 AND `Idx`=0); -- Guardia neferset corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162243 AND `Idx`=0); -- Devoramentes corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162247 AND `Idx`=0); -- Carcelero corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=158632 AND `Idx`=0); -- Bestia de carne corrupta
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162244 AND `Idx`=0); -- Orador del Sino corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162246 AND `Idx`=0); -- Dominador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156709 AND `Idx`=0); -- Expoliador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=159087 AND `Idx`=0); -- Limpiahuesos corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162290 AND `Idx`=0); -- Buscasangre corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162252 AND `Idx`=1); -- Decapitador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162252 AND `Idx`=0); -- Decapitador corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162250 AND `Idx`=1); -- Asesino corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162250 AND `Idx`=0); -- Asesino corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162249 AND `Idx`=1); -- Acólito corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=162249 AND `Idx`=0); -- Acólito corrupto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156607 AND `Idx`=0); -- Alaria
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161130 AND `Idx`=0); -- Cabra costera
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=156651 AND `Idx`=0); -- Captain Garrick
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=164577 AND `Idx`=0); -- Compañera de entrenamiento de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150228 AND `Idx`=1); -- Murloc Spearhunter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150228 AND `Idx`=0); -- Murloc Spearhunter
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=165359 AND `Idx`=0); -- Sobreviviente de la Alianza
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150229 AND `Idx`=1); -- Moldeador de agua múrloc
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=150229 AND `Idx`=0); -- Moldeador de agua múrloc
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161224 AND `Idx`=1); -- Cangrejo evasivo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161224 AND `Idx`=0); -- Cangrejo evasivo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161265 AND `Idx`=0); -- Jrokgar
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161133 AND `Idx`=2); -- Albatros costero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161133 AND `Idx`=1); -- Albatros costero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161133 AND `Idx`=0); -- Albatros costero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161131 AND `Idx`=1); -- Puercoespín espinoso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=161131 AND `Idx`=0); -- Puercoespín espinoso
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167761 AND `Idx`=1); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=167761 AND `Idx`=0); -- InvisBunny
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=21354 AND `Idx`=0); -- Caballo de guerra ígneo
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=65011 AND `Idx`=0); -- Grulla de montar albina
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=39209 AND `Idx`=0); -- Gran elekk de exarca
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=28302 AND `Idx`=0); -- Destrero de la muerte de Acherus
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=18362 AND `Idx`=0); -- Grifo morado presto
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=14565 AND `Idx`=0); -- Destrero
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=14505 AND `Idx`=0); -- Dreadsteed
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=9158 AND `Idx`=0); -- Caballo de guerra
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=304 AND `Idx`=0); -- Felsteed
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=305 AND `Idx`=0); -- White Stallion
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=39208 AND `Idx`=0); -- Elekk de exarca
UPDATE `creature_template_model` SET `VerifiedBuild`=38134 WHERE (`CreatureID`=308 AND `Idx`=0); -- Semental negro


UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=153581 AND `Idx`=0); -- Grunk
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=153583 AND `Idx`=0); -- Jugnug
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=153582 AND `Idx`=0); -- Wug
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=150238 AND `Idx`=0); -- Geomante jabaespín
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=150237 AND `Idx`=0); -- Guerrero jabaespín
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=152359 AND `Idx`=1); -- Cienagosa la madre de la manada
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=152359 AND `Idx`=0); -- Cienagosa la madre de la manada
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=152548 AND `Idx`=0); -- Matriarca de escamas Gratinax
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=152556 AND `Idx`=0); -- Chasm-Haunter
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162241 AND `Idx`=0); -- Despojamentes corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162253 AND `Idx`=1); -- Taumaturgo corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162253 AND `Idx`=0); -- Taumaturgo corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162251 AND `Idx`=1); -- Invocador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162251 AND `Idx`=0); -- Invocador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158706 AND `Idx`=0); -- Putrefacción corrupta
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162254 AND `Idx`=0); -- Observador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162243 AND `Idx`=0); -- Devoramentes corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162247 AND `Idx`=0); -- Carcelero corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=158632 AND `Idx`=0); -- Bestia de carne corrupta
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162244 AND `Idx`=0); -- Orador del Sino corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162246 AND `Idx`=0); -- Dominador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=156709 AND `Idx`=0); -- Expoliador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162252 AND `Idx`=1); -- Decapitador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162252 AND `Idx`=0); -- Decapitador corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162250 AND `Idx`=1); -- Asesino corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162250 AND `Idx`=0); -- Asesino corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162249 AND `Idx`=1); -- Acólito corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=162249 AND `Idx`=0); -- Acólito corrupto
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161130 AND `Idx`=0); -- Cabra costera
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=150228 AND `Idx`=0); -- Murloc Spearhunter
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=150229 AND `Idx`=0); -- Moldeador de agua múrloc
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161133 AND `Idx`=0); -- Albatros costero
UPDATE `creature_questitem` SET `VerifiedBuild`=38134 WHERE (`CreatureEntry`=161131 AND `Idx`=0); -- Puercoespín espinoso

DELETE FROM `gameobject_template` WHERE `entry`=342221;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `IconName`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(342221, 8, 42710, '', '', 0.25, 2097, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 741, 38134); -- Portal del Vacío


UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336441; -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=334502; -- TEMP DOOR
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=336442; -- 6DU_HighmaulRaid_Door02
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=334578; -- Puerta sombría
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=252247; -- Portal de instancia
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=327407; -- Alijo de los ogros precioso
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339643; -- Puerta de Mazoscuro
UPDATE `gameobject_template` SET `Data0`=3155, `Data3`=1, `Data14`=40509, `Data20`=1, `Data23`=1, `VerifiedBuild`=38134 WHERE `entry`=339865; -- Piedra rúnica ogra
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=346113; -- Piedra de druida
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=341951; -- Cicuta marchita
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=330627; -- Señal de peligro
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339568; -- Capullo grueso
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=21680; -- Bandera de duelo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326719; -- Pedestal de ritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326718; -- Pedestal de ritual
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=329919; -- Suministros robados
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326717; -- Pedestal de ritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326651; -- Catapulta
UPDATE `gameobject_template` SET `type`=3, `IconName`='questinteract', `size`=0.400000005960464477, `Data0`=1691, `Data2`=1, `Data8`=58962, `Data14`=23645, `Data30`=100793, `Data31`=1, `ContentTuningId`=741, `VerifiedBuild`=38134 WHERE `entry`=342259; -- Grimorio antiguo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=326716; -- Pedestal de ritual
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=342131; -- Esqueleto
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=342365; -- Hoguera
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=342366; -- Flor de velo
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=327146; -- Tótem de arpías
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=329918; -- Tesoros de los jabaespines
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349948; -- Fogata
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=349947; -- Fogata
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=38134 WHERE `entry`=339770; -- Cofre del tesoro abandonado
UPDATE `gameobject_template` SET `type`=15, `displayId`=61205, `VerifiedBuild`=38134 WHERE `entry`=333479; -- Nave de la Alianza
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=339769; -- Hoguera
UPDATE `gameobject_template` SET `VerifiedBuild`=38134 WHERE `entry`=335718; -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=342259 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(342259, 0, 174947, 38134); -- Grimorio antiguo

UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=339769 AND `Idx`=0); -- Hoguera

DELETE FROM `npc_text` WHERE `ID` IN (39934 /*39934*/, 39219 /*39219*/, 39616 /*39616*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39934, 1, 0, 0, 0, 0, 0, 0, 0, 191017, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39934
(39219, 1, 0, 0, 0, 0, 0, 0, 0, 184681, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39219
(39616, 1, 0, 0, 0, 0, 0, 0, 0, 187477, 0, 0, 0, 0, 0, 0, 0, 38134); -- 39616

