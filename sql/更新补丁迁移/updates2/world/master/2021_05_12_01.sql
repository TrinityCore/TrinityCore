DELETE FROM `areatrigger_template` WHERE `Id` IN (25703, 26038, 25704, 26074, 25556, 25695, 23736, 23737);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(25703, 1, 0, 0, 12, 12, 0, 0, 0, 0, 38134),
(26038, 1, 0, 0, 4, 4, 0, 0, 0, 0, 38134),
(25704, 1, 0, 2, 7, 7, 0, 0, 0, 0, 38134),
(26074, 1, 0, 0, 3, 3, 0, 0, 0, 0, 38134),
(25556, 1, 4, 6, 6, 6, 6, 6, 0.300000011920928955, 0.300000011920928955, 38134),
(25695, 1, 0, 2, 13, 13, 0, 0, 0, 0, 38134),
(23736, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134),
(23737, 1, 0, 0, 6, 6, 0, 0, 0, 0, 38134);

UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=24507;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=23299;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=23297;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=23299;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=23297;
UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9228;



REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(20636, 24507, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 322648
(21431, 25703, 0, 0, 0, 0, 0, 0, 0, 0, 15000, 38134), -- SpellId : 338434
(21827, 26038, 0, 0, 0, 0, 0, 0, 0, 0, 7500, 38134), -- SpellId : 342761
(21432, 25704, 0, 22500, 0, 0, 0, 0, 22, 0, 30000, 38134), -- SpellId : 337563
(21870, 26074, 0, 0, 0, 0, 0, 0, 0, 0, 15000, 38134), -- SpellId : 343394
(21269, 25556, 0, 20271, 0, 0, 0, 0, 0, 0, 30000, 38134), -- SpellId : 336956
(21422, 25695, 0, 20415, 0, 0, 0, 0, 217, 0, 20000, 38134); -- SpellId : 337556

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19775 AND `AreaTriggerId`=23736); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19775 AND `AreaTriggerId`=23736); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=19776 AND `AreaTriggerId`=23737); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=9810 AND `AreaTriggerId`=14725); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0


DELETE FROM `conversation_actor_template` WHERE `Id` IN (71881, 75089);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(71881, 161907, 96443, 38134),
(75089, 165333, 94122, 38134);

UPDATE `conversation_actor_template` SET `CreatureId`=134344, `CreatureModelId`=87378, `VerifiedBuild`=38134 WHERE `Id`=51642;

DELETE FROM `conversation_line_template` WHERE `Id` IN (32165, 35383, 35408, 35407, 36131, 36130, 39347, 31140, 31139, 40146, 32598, 14219, 32955, 31596, 40799, 31210, 31209, 31151, 31152, 32557, 41738, 40606, 35277, 31129, 31128, 31117, 31116, 30240, 34265);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(32165, 0, 1372, 0, 0, 38134),
(35383, 0, 1541, 0, 0, 38134),
(35408, 4850, 0, 1, 0, 38134),
(35407, 0, 0, 0, 0, 38134),
(36131, 4200, 0, 1, 0, 38134),
(36130, 0, 0, 0, 0, 38134),
(39347, 0, 0, 0, 0, 38134),
(31140, 6800, 0, 0, 0, 38134),
(31139, 0, 0, 0, 0, 38134),
(40146, 0, 1372, 0, 0, 38134),
(32598, 0, 0, 0, 0, 38134),
(14219, 0, 1108, 0, 0, 38134),
(32955, 0, 0, 0, 0, 38134),
(31596, 0, 1541, 0, 0, 38134),
(40799, 0, 0, 0, 0, 38134),
(31210, 5150, 0, 0, 1, 38134),
(31209, 0, 0, 0, 1, 38134),
(31151, 5050, 0, 0, 0, 38134),
(31152, 0, 0, 0, 0, 38134),
(32557, 0, 0, 0, 0, 38134),
(41738, 0, 0, 0, 0, 38134),
(40606, 0, 0, 0, 0, 38134),
(35277, 0, 0, 0, 0, 38134),
(31129, 5600, 0, 0, 0, 38134),
(31128, 0, 0, 0, 0, 38134),
(31117, 5450, 0, 0, 0, 38134),
(31116, 0, 0, 0, 0, 38134),
(30240, 0, 0, 0, 0, 38134),
(34265, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=32484;

DELETE FROM `conversation_template` WHERE `Id` IN (13784, 15966, 13010, 12735, 14129, 16203, 13264, 13153, 13139, 12723, 12717, 12714, 12709, 16126, 13763, 14113, 14072, 12400, 14431, 12853, 6330);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(13784, 39347, 6401, 0, 38134),
(15966, 40146, 8743, 0, 38134),
(13010, 32165, 7501, 0, 38134),
(12735, 31209, 9550, 0, 38134),
(14129, 35407, 9200, 0, 38134),
(16203, 40799, 6450, 0, 38134),
(13264, 32955, 5500, 0, 38134),
(13153, 32598, 6900, 0, 38134),
(13139, 32557, 5550, 0, 38134),
(12723, 31152, 8650, 0, 38134),
(12717, 31139, 13100, 0, 38134),
(12714, 31128, 17300, 0, 38134),
(12709, 31116, 11100, 0, 38134),
(16126, 40606, 8600, 0, 38134),
(13763, 34265, 4850, 0, 38134),
(14113, 35383, 11952, 0, 38134),
(14072, 35277, 4800, 0, 38134),
(12400, 30240, 4150, 0, 38134),
(14431, 36130, 7350, 0, 38134),
(12853, 31596, 12127, 0, 38134),
(6330, 14219, 12959, 0, 38134);


UPDATE `conversation_template` SET `LastLineEndTime`=11482, `VerifiedBuild`=38134 WHERE `Id`=13124;
UPDATE `conversation_template` SET `FirstLineID`=41738, `LastLineEndTime`=4450, `VerifiedBuild`=38134 WHERE `Id`=16561;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (353615 /*Cristal desviador*/, 335649 /*Aterrangustias*/, 335655 /*Brazo de Oonar*/, 356879 /*Cajón de artesano*/, 340073 /*Arma desechada*/, 354128 /*Hacha arrojadiza maldraxxi*/, 349509 /*Arma desechada*/, 340074 /*Arma desechada*/, 340072 /*Arma desechada*/, 357723 /*Portal de negociantes*/, 349560 /*Portal de negociantes*/, 349612 /*Se busca: Tasador Vix*/, 339195 /*La piedra más grande que puedas encontrar*/, 338855 /*Zerekriss*/, 349546 /*Jaula de negociantes*/, 352110 /*Puerta de la torre*/, 336689 /*Corraíz*/, 355886 /*Cofre abrumado por la plaga*/, 354470 /*Fortaleza explosiva*/, 358579 /*Plataforma de transporte*/, 349810 /*Esfera de traslado: Casa de las Plagas*/, 365130 /*Poción abrumada por la plaga*/, 365076 /*Asiento de peluquería*/, 365073 /*Asiento de peluquería*/, 365074 /*Asiento de peluquería*/, 365075 /*Asiento de peluquería*/, 332214 /*Portal a las Cavernas del Tiempo*/, 355229 /*Portal a Oribos*/, 259031 /*Portal a Ventormenta*/, 353977 /*Altar de piedra*/, 354927 /*Portal*/, 364864 /*Puerta de pináculo*/, 353390 /*Puerta de celda*/, 353389 /*Puerta de celda*/, 351470 /*Estrella mortal*/, 353601 /*Cristal desviador*/, 351980 /*Suministros perdidos*/, 353614 /*Cristal desviador*/, 353602 /*Cristal desviador*/, 353616 /*Cristal desviador*/, 336675 /*Necrópolis - Guerreros*/, 353400 /*Puerta de celda*/, 353398 /*Puerta de celda*/, 353397 /*Puerta de celda*/, 353391 /*Puerta de celda*/, 353392 /*Puerta de celda*/, 350775 /*Puerta*/, 364865 /*Puerta de pinchos*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(353615, 0, 32, 0, 0), -- Cristal desviador
(335649, 0, 262144, 0, 0), -- Aterrangustias
(335655, 0, 262144, 0, 10618), -- Brazo de Oonar
(356879, 94, 2113540, 0, 0), -- Cajón de artesano
(340073, 0, 2113540, 0, 0), -- Arma desechada
(354128, 0, 262144, 569, 0), -- Hacha arrojadiza maldraxxi
(349509, 0, 2113540, 0, 0), -- Arma desechada
(340074, 0, 2113540, 0, 0), -- Arma desechada
(340072, 0, 2113540, 0, 0), -- Arma desechada
(357723, 35, 0, 0, 0), -- Portal de negociantes
(349560, 35, 0, 0, 0), -- Portal de negociantes
(349612, 0, 4, 0, 0), -- Se busca: Tasador Vix
(339195, 0, 262145, 0, 0), -- La piedra más grande que puedas encontrar
(338855, 0, 1048608, 0, 0), -- Zerekriss
(349546, 0, 32, 0, 0), -- Jaula de negociantes
(352110, 0, 32, 0, 0), -- Puerta de la torre
(336689, 0, 278528, 0, 0), -- Corraíz
(355886, 0, 2, 2437, 0), -- Cofre abrumado por la plaga
(354470, 0, 0, 520, 0), -- Fortaleza explosiva
(358579, 0, 0, 0, 11129), -- Plataforma de transporte
(349810, 0, 0, 0, 13683), -- Esfera de traslado: Casa de las Plagas
(365130, 0, 0, 520, 0), -- Poción abrumada por la plaga
(365076, 0, 0, 16227, 0), -- Asiento de peluquería
(365073, 0, 0, 16227, 0), -- Asiento de peluquería
(365074, 0, 0, 16227, 0), -- Asiento de peluquería
(365075, 0, 0, 16227, 0), -- Asiento de peluquería
(332214, 1735, 0, 0, 3503), -- Portal a las Cavernas del Tiempo
(355229, 1735, 0, 0, 3503), -- Portal a Oribos
(259031, 1732, 0, 0, 0), -- Portal a Ventormenta
(353977, 0, 0, 0, 9340), -- Altar de piedra
(354927, 0, 1048608, 0, 0), -- Portal
(364864, 0, 32, 0, 0), -- Puerta de pináculo
(353390, 0, 32, 0, 0), -- Puerta de celda
(353389, 0, 32, 0, 0), -- Puerta de celda
(351470, 0, 278528, 0, 0), -- Estrella mortal
(353601, 0, 32, 0, 0), -- Cristal desviador
(351980, 0, 278528, 2437, 0), -- Suministros perdidos
(353614, 0, 32, 0, 0), -- Cristal desviador
(353602, 0, 32, 0, 0), -- Cristal desviador
(353616, 0, 32, 0, 0), -- Cristal desviador
(336675, 0, 1048864, 0, 0), -- Necrópolis - Guerreros
(353400, 0, 32, 0, 0), -- Puerta de celda
(353398, 0, 32, 0, 0), -- Puerta de celda
(353397, 0, 32, 0, 0), -- Puerta de celda
(353391, 0, 32, 0, 0), -- Puerta de celda
(353392, 0, 32, 0, 0), -- Puerta de celda
(350775, 0, 32, 0, 0), -- Puerta
(364865, 0, 32, 0, 0); -- Puerta de pinchos

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=336691; -- Sombranoche
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2100 WHERE `entry`=334654; -- Ingrediente purulento: Aceite viscoso
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=520 WHERE `entry`=293675; -- Sed devoradora
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8872 WHERE `entry`=281288; -- Pila de basura misteriosa
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=9340 WHERE `entry`=281467; -- Huesos
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=9340 WHERE `entry`=278790; -- Huevo quebrado
UPDATE `gameobject_template_addon` SET `WorldEffectID`=11129 WHERE `entry`=316905; -- Trituramática Mk1
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=242040; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=242043; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=259337; -- Molinillo de café
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=259335; -- Prensa de café
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241950; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241948; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241969; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241949; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241970; -- Farola
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=241971; -- Farola
UPDATE `gameobject_template_addon` SET `WorldEffectID`=6658 WHERE `entry`=252408; -- Fragmento de maná ancestral
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=265474; -- Cofre vil
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=2437 WHERE `entry`=251552; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=250091; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=239692; -- Huevo imbuido de magia arcana
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=2437 WHERE `entry`=240644; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=251168; -- Cristal efímero
UPDATE `gameobject_template_addon` SET `flags`=0, `WorldEffectID`=2437 WHERE `entry`=250083; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=251187; -- Cristal efímero
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=214464; -- Mogu Crypt Doors (phased/closed)
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211963; -- Puerta dorada
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211704; -- Puertas doradas
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry`=211702; -- Puertas doradas
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211703; -- Puertas doradas

DELETE FROM `quest_offer_reward` WHERE `ID` IN (61397 /*-Unknown-*/, 62694 /*-Unknown-*/, 58090 /*-Unknown-*/, 58088 /*-Unknown-*/, 58068 /*-Unknown-*/, 62085 /*-Unknown-*/, 57301 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(61397, 6, 0, 0, 0, 0, 0, 0, 0, 'Con tus habilidades únicas, tenemos una oportunidad que no se había presentado hasta ahora.', 38134), -- -Unknown-
(62694, 0, 0, 0, 0, 0, 0, 0, 0, 'Nuestras casas rivales lo pensarán dos veces antes de entrar a nuestra fortaleza otra vez. Sangre y gloria para ti, Surcafauces.', 38134), -- -Unknown-
(58090, 5, 0, 0, 0, 0, 0, 0, 0, 'La desguazadora Minoire tendrá que renunciar a su lugar en la competencia.', 38134), -- -Unknown-
(58088, 5, 0, 0, 0, 0, 0, 0, 0, 'Sé que la desguazadora Minoire te ha enviado. Siempre usa mejoras para ganar la pelea.', 38134), -- -Unknown-
(58068, 0, 0, 0, 0, 0, 0, 0, 0, 'Estaríamos tan perdidos sin tu ayuda. De verdad.', 38134), -- -Unknown-
(62085, 1, 0, 0, 0, 0, 0, 0, 0, 'Me preguntaba dónde estaría mi cantimplora. ¿Dónde la encontraste, $n? ¿Bebiste un sorbo antes de volver aquí?\n\nSupongo que no hay problema.', 38134), -- -Unknown-
(57301, 0, 0, 0, 0, 0, 0, 0, 0, 'Puedes seguir agregando todos los ingredientes que quieras. ¡Cuantos más agreguemos, más crearemos!', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=58090 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58090 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58090 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58090 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=58068 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58068 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59520 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=59520 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=59520 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=59520 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=59520 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=59520 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=59520 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59520 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59234 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59234 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=59234 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=12103 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=12103 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=12103 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=62631 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(58090, 0, 3, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 0, 1882894, 0, 38134), -- -Unknown-
(58090, 0, 2, 1, 393667, 160259, 2222, 1536, 0, 2, 0, 0, 0, 1856606, 0, 38134), -- -Unknown-
(58090, 0, 1, 0, 397180, 177957, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58090, 0, 0, -1, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 1852129, 0, 38134), -- -Unknown-
(58068, 0, 7, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58068, 1, 6, 4, 393616, 159696, 2222, 1536, 0, 0, 0, 0, 0, 1859070, 0, 38134), -- -Unknown-
(58068, 0, 5, 4, 393616, 159696, 2222, 1536, 0, 0, 0, 0, 0, 1852161, 0, 38134), -- -Unknown-
(58068, 0, 4, 3, 393611, 160124, 2222, 1536, 0, 0, 0, 0, 0, 1852161, 0, 38134), -- -Unknown-
(58068, 0, 3, 2, 393610, 160125, 2222, 1536, 0, 0, 0, 0, 0, 1856606, 0, 38134), -- -Unknown-
(58068, 0, 2, 1, 393615, 159824, 2222, 1536, 0, 0, 0, 0, 0, 1856590, 0, 38134), -- -Unknown-
(58068, 0, 1, 0, 393609, 160123, 2222, 1536, 0, 0, 0, 0, 0, 1856590, 0, 38134), -- -Unknown-
(58068, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 0, 1852129, 0, 38134), -- -Unknown-
(59520, 0, 7, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 0, 1922839, 0, 38134), -- -Unknown-
(59520, 0, 6, 31, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59520, 0, 5, 1, 396463, 176057, 2289, 1674, 0, 0, 0, 0, 0, 1915178, 0, 38134), -- -Unknown-
(59520, 3, 4, 0, 396462, 183724, 2289, 1674, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59520, 2, 3, 0, 396462, 183724, 2289, 1674, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59520, 1, 2, 0, 396462, 183724, 2289, 1674, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59520, 0, 1, 0, 396462, 183724, 2289, 1674, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59520, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 0, 1922839, 0, 38134), -- -Unknown-
(59234, 0, 2, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59234, 1, 1, 1, 409171, 164541, 2222, 1536, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59234, 0, 0, 1, 409171, 164541, 2222, 1536, 0, 0, 0, 0, 0, 1828605, 0, 38134), -- -Unknown-
(12103, 1, 2, 0, 393639, 82701, 1220, 627, 0, 2, 0, 23503, 0, 0, 0, 38134), -- -Unknown-
(12103, 0, 1, 0, 393639, 82701, 1220, 627, 0, 2, 0, 23504, 0, 0, 0, 38134), -- -Unknown-
(12103, 0, 0, -1, 0, 0, 1514, 709, 0, 0, 0, 0, 0, 1082451, 0, 38134), -- -Unknown-
(62631, 0, 0, -1, 0, 0, 2222, 1670, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60466, 0, 4, 32, 0, 0, 2222, 1533, 0, 0, 0, 0, 0, 1861577, 0, 38134), -- -Unknown-
(60466, 0, 3, 2, 398287, 178890, 2222, 1533, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60466, 0, 2, 1, 398285, 178885, 2222, 1533, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60466, 0, 1, 0, 398288, 178891, 2222, 1533, 0, 0, 0, 0, 0, 1861603, 0, 38134), -- -Unknown-
(60466, 0, 0, -1, 0, 0, 2222, 1533, 0, 0, 0, 0, 0, 1861577, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62843 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62843 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62785 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62785 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58088 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58088 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56120 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56120 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50603 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50598 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62456 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57651 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57651 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53435 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=58090 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58090 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58090 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58090 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58068 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=59520 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=59520 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=59520 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=59520 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=59520 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=59520 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=59520 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=59520 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59520 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59234 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=59234 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59234 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=12103 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=12103 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=12103 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=62631 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(58090, 3, 0, 2409, -2936, 3306, 38134), -- -Unknown-
(58090, 2, 0, 2698, -2762, 0, 38134), -- -Unknown-
(58090, 1, 0, 2805, -2752, 0, 38134), -- -Unknown-
(58090, 0, 0, 2768, -2757, 3307, 38134), -- -Unknown-
(58068, 7, 0, 2760, -2776, 0, 38134), -- -Unknown-
(58068, 6, 0, 2667, -2788, 3308, 38134), -- -Unknown-
(58068, 5, 0, 2646, -2780, 3307, 38134), -- -Unknown-
(58068, 4, 0, 2646, -2780, 3307, 38134), -- -Unknown-
(58068, 3, 0, 2694, -2761, 3307, 38134), -- -Unknown-
(58068, 2, 0, 2667, -2761, 3307, 38134), -- -Unknown-
(58068, 1, 0, 2667, -2761, 3307, 38134), -- -Unknown-
(58068, 0, 0, 2757, -2770, 3307, 38134), -- -Unknown-
(59520, 7, 0, 1752, -3117, 3258, 38134), -- -Unknown-
(59520, 6, 0, 2097, -3112, 0, 38134), -- -Unknown-
(59520, 5, 0, 979, -3689, 3070, 38134), -- -Unknown-
(59520, 4, 5, 1903, -3306, 3247, 38134), -- -Unknown-
(59520, 4, 4, 1893, -3286, 3224, 38134), -- -Unknown-
(59520, 4, 3, 1938, -3217, 3232, 38134), -- -Unknown-
(59520, 4, 2, 1991, -3188, 3263, 38134), -- -Unknown-
(59520, 4, 1, 1956, -3327, 3255, 38134), -- -Unknown-
(59520, 4, 0, 1948, -3331, 3255, 38134), -- -Unknown-
(59520, 3, 2, 1950, -3788, 3214, 38134), -- -Unknown-
(59520, 3, 1, 1985, -3762, 3217, 38134), -- -Unknown-
(59520, 3, 0, 1986, -3821, 3221, 38134), -- -Unknown-
(59520, 2, 4, 1905, -3658, 3227, 38134), -- -Unknown-
(59520, 2, 3, 1913, -3652, 3230, 38134), -- -Unknown-
(59520, 2, 2, 1918, -3655, 3229, 38134), -- -Unknown-
(59520, 2, 1, 1939, -3692, 3224, 38134), -- -Unknown-
(59520, 2, 0, 1935, -3695, 3222, 38134), -- -Unknown-
(59520, 1, 8, 2026, -3469, 3260, 38134), -- -Unknown-
(59520, 1, 7, 1967, -3455, 3258, 38134), -- -Unknown-
(59520, 1, 6, 1961, -3453, 3257, 38134), -- -Unknown-
(59520, 1, 5, 1958, -3437, 3262, 38134), -- -Unknown-
(59520, 1, 4, 1962, -3433, 3261, 38134), -- -Unknown-
(59520, 1, 3, 2027, -3443, 3258, 38134), -- -Unknown-
(59520, 1, 2, 2089, -3475, 3271, 38134), -- -Unknown-
(59520, 1, 1, 2089, -3478, 3272, 38134), -- -Unknown-
(59520, 1, 0, 2086, -3478, 3272, 38134), -- -Unknown-
(59520, 0, 0, 1752, -3117, 3258, 38134), -- -Unknown-
(59234, 2, 0, 1801, -3117, 3257, 38134), -- -Unknown-
(59234, 1, 11, 1550, -3481, 0, 38134), -- -Unknown-
(59234, 1, 10, 1463, -3439, 0, 38134), -- -Unknown-
(59234, 1, 9, 1422, -3409, 0, 38134), -- -Unknown-
(59234, 1, 8, 1406, -3327, 0, 38134), -- -Unknown-
(59234, 1, 7, 1463, -3062, 0, 38134), -- -Unknown-
(59234, 1, 6, 1519, -3020, 0, 38134), -- -Unknown-
(59234, 1, 5, 2055, -2929, 0, 38134), -- -Unknown-
(59234, 1, 4, 2168, -2955, 0, 38134), -- -Unknown-
(59234, 1, 3, 2265, -3047, 0, 38134), -- -Unknown-
(59234, 1, 2, 2234, -3144, 0, 38134), -- -Unknown-
(59234, 1, 1, 2152, -3199, 0, 38134), -- -Unknown-
(59234, 1, 0, 1606, -3491, 0, 38134), -- -Unknown-
(59234, 0, 0, 1700, -3039, 3261, 38134), -- -Unknown-
(12103, 2, 0, -936, 4553, -125, 38134), -- -Unknown-
(12103, 1, 0, -711, 4410, -125, 38134), -- -Unknown-
(12103, 0, 0, 818, 3608, 174, 38134), -- -Unknown-
(62631, 0, 0, -1725, 1178, 0, 38134), -- -Unknown-
(60466, 4, 0, -4130, -4614, 6534, 38134), -- -Unknown-
(60466, 3, 7, -3996, -4917, 6598, 38134), -- -Unknown-
(60466, 3, 6, -4191, -4778, 6538, 38134), -- -Unknown-
(60466, 3, 5, -4245, -4585, 6541, 38134), -- -Unknown-
(60466, 3, 4, -4237, -4579, 6548, 38134), -- -Unknown-
(60466, 3, 3, -4194, -4606, 6546, 38134), -- -Unknown-
(60466, 3, 2, -3814, -4888, 6603, 38134), -- -Unknown-
(60466, 3, 1, -3867, -4922, 6605, 38134), -- -Unknown-
(60466, 3, 0, -3950, -4931, 6601, 38134), -- -Unknown-
(60466, 2, 6, -4024, -4925, 6566, 38134), -- -Unknown-
(60466, 2, 5, -4143, -4795, 6543, 38134), -- -Unknown-
(60466, 2, 4, -4196, -4646, 6531, 38134), -- -Unknown-
(60466, 2, 3, -4011, -4672, 6549, 38134), -- -Unknown-
(60466, 2, 2, -3936, -4771, 6602, 38134), -- -Unknown-
(60466, 2, 1, -3969, -4908, 6598, 38134), -- -Unknown-
(60466, 2, 0, -3985, -4958, 6575, 38134), -- -Unknown-
(60466, 1, 0, -4106, -4628, 6536, 38134), -- -Unknown-
(60466, 0, 0, -4130, -4614, 6534, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62843 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62843 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61397 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62785 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62785 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58605 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58095 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58088 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58088 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57301 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49413 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56120 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56120 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50603 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50598 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62840 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62694 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62456 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57818 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57651 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57651 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57538 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53435 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53435 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (62843 /*-Unknown-*/, 61397 /*-Unknown-*/, 62785 /*-Unknown-*/, 58095 /*-Unknown-*/, 58090 /*-Unknown-*/, 58088 /*-Unknown-*/, 58068 /*-Unknown-*/, 12103 /*-Unknown-*/, 31834 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(62843, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61397, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62785, 1, 1, 273, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58095, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58090, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58088, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58068, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(12103, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(31834, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59520; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59520; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59520; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59520; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=57301; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=57301; -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (58090 /*-Unknown-*/, 62694 /*-Unknown-*/, 62840 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58090, 0, 0, 0, 0, 'No esperaba este giro en la trama.', 0), -- -Unknown-
(62694, 0, 0, 0, 0, '¿Cómo va la batalla?', 38134), -- -Unknown-
(62840, 0, 1, 0, 0, 'El ánima estará mejor aquí, lejos de quienes amenazan las Tierras de las Sombras.', 38134); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (326061,324547,337689,337688));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(326061, 0, 2222, 4129.2998046875, -2594.909912109375, 3341.360107421875, 38134), -- Spell: 326061 (Teleport: House of Eyes) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(324547, 0, 0, 0, 0, 0, 38134), -- Spell: 324547 (Hearth Kidneystone) Efffect: 13 (SPELL_EFFECT_RITUAL_BASE)
(337689, 0, 2222, 1888.52001953125, -2611.389892578125, 3398.219970703125, 38134), -- Spell: 337689 (Teleport: Lower Tier) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(337688, 0, 2222, 1733.0999755859375, -2547.330078125, 3529.570068359375, 38134); -- Spell: 337688 (Teleport: Upper Tier) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `MapID`=1153, `PositionX`=5563.7001953125, `PositionY`=4599.89990234375, `PositionZ`=141.7100067138671875 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=194004 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=5276.39990234375, `PositionY`=-4045.239990234375, `PositionZ`=19.57999992370605468, `VerifiedBuild`=38134 WHERE (`ID`=173143 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (161905 /*161905 (Oseadora Heirmir)*/, 175394 /*175394 (Ja'red Haze)*/, 163224 /*163224 (Arena - Bunny)*/, 172656 /*172656 (Acechador del centro de la arena)*/, 163030 /*163030 (Contendiente de la arena)*/, 166568 /*166568 (Hellinka)*/, 166570 /*166570 (Avrilla Angar)*/, 161733 /*161733 (Anzio, el Infalible)*/, 175393 /*175393 (Eli'ot Roush)*/, 161697 /*161697 (Fogonero Marahueso)*/, 161696 /*161696 (Acerón Wilhelm)*/, 169697 /*169697 (Acerino Obernolte)*/, 161702 /*161702 (Slumbar Valorum)*/, 173003 /*173003 (Nalcorn Talsen)*/, 166420 /*166420 (Varissa Stubin)*/, 170496 /*170496 (Shanir Cortavenas)*/, 163032 /*163032 (Contendiente de la arena)*/, 158071 /*158071 (Animado descerebrado) - Anim Replacement - New Drunk*/, 160256 /*160256 (Desguazadora Minoire)*/, 172608 /*172608 (Mortisombra de Xantuth) - Summon Skeleton*/, 172567 /*172567 (Mortisombra de Xantuth) - Summon Skeleton*/, 172591 /*172591 (Mortisombra de Xantuth) - Summon Skeleton*/, 166226 /*166226 (Contendiente de la arena)*/, 161599 /*161599 (Esclerosis burbujeante) - Shattersoul Bow*/, 162813 /*162813 (Aprendiz de la arena)*/, 162797 /*162797 (Cicatriz) - Deepscar's Frenzy*/, 163084 /*163084 (Examinadora Sahaari)*/, 161597 /*161597 (Baba arrasadora)*/, 166331 /*166331 (Zo'umlo)*/, 166321 /*166321 (Proveedor de especímenes)*/, 166531 /*166531 (Señora Dyrax) - Containment Field, Containment Field*/, 166545 /*166545 (Instructor Erix)*/, 159833 /*159833 (So'narynar)*/, 166640 /*166640 (Au'larrynar)*/, 166564 /*166564 (Aprendiz incansable)*/, 166540 /*166540 (Aprendiz incansable)*/, 163043 /*163043 (Espectadora de la arena)*/, 161585 /*161585 (Huesos)*/, 163019 /*163019 (Gran maestro Vole)*/, 161559 /*161559 (Louison)*/, 161757 /*161757 (Contendiente de la arena)*/, 166253 /*166253 (Gran maestro Vole) - Ride Vehicle Hardcoded*/, 162899 /*162899 (Gran maestro Vole)*/, 175392 /*175392 (Trampero Hickman)*/, 163083 /*163083 (Evaluador Malus)*/, 166400 /*166400 (Aprendiz incansable)*/, 164507 /*164507 (Espectador de la arena)*/, 161710 /*161710 (Marcel Mullby)*/, 159830 /*159830 (Au'narim)*/, 159827 /*159827 (Desguazadora Minoire)*/, 165473 /*165473 (Colmisangre alfa)*/, 166562 /*166562 (Talzedo) - Beginner's Spell*/, 159828 /*159828 (Fan de Desguazadora)*/, 162872 /*162872 (Xantuth la Contagiada) - Containment Cell Visuals*/, 166552 /*166552 (Jessana)*/, 159824 /*159824 (Gunn Tragahuesos)*/, 159689 /*159689 (Sobrestante Kalvaros) - Cosmetic - Offhand Book*/, 159825 /*159825 (Fan de Tragahuesos)*/, 164492 /*164492 (Espectador de la arena)*/, 163041 /*163041 (Prospector de la arena)*/, 159822 /*159822 (Fan de Dínamo)*/, 159696 /*159696 (Rencissa, la Dínamo)*/, 162588 /*162588 (Picartílago)*/, 164508 /*164508 (Espectador de la arena)*/, 175023 /*175023 (Animated Cruor) - Battle Pet Periodic*/, 174652 /*174652 (Animated Cruor)*/, 169795 /*169795 (Avispa cinérea zombi) - Permanent Feign Death (Flies)*/, 169830 /*169830 (Larva parasitaria)*/, 168226 /*168226 (Earl el ciego)*/, 175391 /*175391 (Luke Herczeg)*/, 161677 /*161677 (Plimpton)*/, 162093 /*162093 (Kurly)*/, 167639 /*167639 (Desollador Coxis)*/, 161675 /*161675 (Iva Gamey)*/, 161673 /*161673 (Elsie Mullby)*/, 164797 /*164797 (Minni) - 9.0 Carry Maldraxxus Barrel*/, 167638 /*167638 (Berk la Pútrida)*/, 167637 /*167637 (Tai Wol'Kur)*/, 167636 /*167636 (Winslow Swan) - Play Lute*/, 175144 /*175144 (Oso bebé)*/, 175398 /*175398 (Mantaraganak)*/, 167640 /*167640 (Capitán John Shin)*/, 174002 /*174002 (Sargento Krashj)*/, 165335 /*165335 (Recluta leal)*/, 172609 /*172609 (Mortisombra de Xantuth) - Summon Skeleton, Necrotic Breath*/, 148086 /*148086 (Skullsplitter Thug)*/, 148080 /*148080 (Olly)*/, 129394 /*129394 (Bribón callejero intrigante) - Major Dinofication*/, 142983 /*142983 (Swizzle Palanqueta)*/, 142973 /*142973 (Mai-Lu)*/, 138949 /*138949 (Throk)*/, 154465 /*154465 (Guardián terráneo)*/, 104792 /*104792 (Diablillo encarcelado)*/, 175518 /*175518 (Aventurero de las Tierras de las Sombras)*/, 66854 /*66854 (Iniciado Chuang)*/, 66260 /*66260 (Maestro Cenit)*/, 66256 /*66256 (Maestra Cheng)*/, 66360 /*66360 (Maestro Brandom)*/, 66257 /*66257 (Maestro Tsang) - Meditating*/, 66947 /*66947 (Alumno monje) - Stand On Balance Pole*/, 66946 /*66946 (Poste de equilibrio)*/, 67021 /*67021 (Alumno monje) - Meditating*/, 128106 /*128106 (Zidormi)*/, 67066 /*67066 (Alumno monje)*/, 64975 /*64975 (Ponshu Cuerpo Férreo) - Brewback*/, 66969 /*66969 (Saco de entrenamiento)*/, 67095 /*67095 (Maestra Yeoh) - Roll*/, 67092 /*67092 (Maestro Chow) - Roll*/, 167649 /*167649 (Kresto Piromuerte)*/, 174488 /*174488 (Defensor inquebrantable) - Training Dummy Marker*/, 174491 /*174491 (Probador de hierro) - Training Dummy Marker*/, 174484 /*174484 (Campeón inamovible) - Training Dummy Marker*/, 174487 /*174487 (Veterano competente) - Training Dummy Marker*/, 165433 /*165433 (Erak Ariaacero)*/, 165434 /*165434 (Evaluador Simmons)*/, 165432 /*165432 (Aprendiz Thayer)*/, 174492 /*174492 (Edrich Adebo) - Carry Candle*/, 174489 /*174489 (Guía nigromántico) - Training Dummy Marker, Passive Uber DoT*/, 165435 /*165435 (Stanley vistafilada)*/, 172680 /*172680 (Visión del Primus)*/, 165321 /*165321 (Merick Feldcicatriz)*/, 175371 /*175371 (Mortis Elfsen)*/, 175370 /*175370 (Gwor, el Odioso)*/, 175311 /*175311 (Destripador Araya)*/, 167210 /*167210 (Tabulador Killham)*/, 175310 /*175310 (Mellisa Fate)*/, 175312 /*175312 (Taiya Tacere)*/, 165431 /*165431 (Kiara Coil) - Carry Candle*/, 161985 /*161985 (Baronesa Vashj)*/, 175314 /*175314 (Tripazón) - 9.0 Carry Maldraxxus Armor*/, 161988 /*161988 (Alexandros Mograine)*/, 167748 /*167748 (Osbourne Black) - Soul Warden Spell Visual*/, 165347 /*165347 (Alvira Mortaja) - Carry Vase, Filled with Crystals, With Kneeling*/, 173000 /*173000 (Madeleine Roux)*/, 165350 /*165350 (Lyra Granizormenta) - Carry Candle*/, 172176 /*172176 (Tsu Zettai)*/, 161907 /*161907 (Baronesa Draka)*/, 161904 /*161904 (Maestro de plagas Marileth)*/, 167205 /*167205 (Yondare Maleficio)*/, 167208 /*167208 (Gran maestro Vole) - Hologram-ify*/, 167201 /*167201 (Gatherer Zaya)*/, 167645 /*167645 (Jericó Murallada)*/, 172173 /*172173 (Intérprete de disputas) - Read Scroll*/, 175791 /*175791 (Felicia Noche) - Carry Candle*/, 174505 /*174505 (Proveedor supremo)*/, 161909 /*161909 (Arkadia Moa)*/, 168685 /*168685 (Teniente McBride)*/, 167207 /*167207 (Sabbath Sombranoche)*/, 175963 /*175963 (Serafina Von)*/, 173022 /*173022 (Enceladus)*/, 175998 /*175998 (Elspeth Larink)*/, 164128 /*164128 (Mefiles el Leal)*/, 169992 /*169992 (Rencor imperfecto) - Mod Scale 105-110%*/, 164713 /*164713 (Fungio aterrado)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(161905, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161905 (Oseadora Heirmir)
(175394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175394 (Ja'red Haze)
(163224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163224 (Arena - Bunny)
(172656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172656 (Acechador del centro de la arena)
(163030, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163030 (Contendiente de la arena)
(166568, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166568 (Hellinka)
(166570, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 166570 (Avrilla Angar)
(161733, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161733 (Anzio, el Infalible)
(175393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175393 (Eli'ot Roush)
(161697, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161697 (Fogonero Marahueso)
(161696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161696 (Acerón Wilhelm)
(169697, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 169697 (Acerino Obernolte)
(161702, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161702 (Slumbar Valorum)
(173003, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173003 (Nalcorn Talsen)
(166420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166420 (Varissa Stubin)
(170496, 0, 96469, 0, 1, 0, 0, 0, 0, ''), -- 170496 (Shanir Cortavenas)
(163032, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163032 (Contendiente de la arena)
(158071, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 158071 (Animado descerebrado) - Anim Replacement - New Drunk
(160256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160256 (Desguazadora Minoire)
(172608, 0, 0, 50331648, 1, 0, 0, 0, 0, '321276'), -- 172608 (Mortisombra de Xantuth) - Summon Skeleton
(172567, 0, 0, 0, 1, 0, 0, 0, 0, '321276'), -- 172567 (Mortisombra de Xantuth) - Summon Skeleton
(172591, 0, 0, 50331648, 1, 0, 0, 0, 0, '321276'), -- 172591 (Mortisombra de Xantuth) - Summon Skeleton
(166226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166226 (Contendiente de la arena)
(161599, 0, 0, 0, 1, 0, 0, 0, 0, '314845'), -- 161599 (Esclerosis burbujeante) - Shattersoul Bow
(162813, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 162813 (Aprendiz de la arena)
(162797, 0, 0, 0, 1, 0, 0, 0, 0, '340309'), -- 162797 (Cicatriz) - Deepscar's Frenzy
(163084, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163084 (Examinadora Sahaari)
(161597, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161597 (Baba arrasadora)
(166331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166331 (Zo'umlo)
(166321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166321 (Proveedor de especímenes)
(166531, 0, 0, 0, 1, 0, 0, 0, 0, '332452 347254'), -- 166531 (Señora Dyrax) - Containment Field, Containment Field
(166545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166545 (Instructor Erix)
(159833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159833 (So'narynar)
(166640, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166640 (Au'larrynar)
(166564, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166564 (Aprendiz incansable)
(166540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166540 (Aprendiz incansable)
(163043, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163043 (Espectadora de la arena)
(161585, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161585 (Huesos)
(163019, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163019 (Gran maestro Vole)
(161559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161559 (Louison)
(161757, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161757 (Contendiente de la arena)
(166253, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 166253 (Gran maestro Vole) - Ride Vehicle Hardcoded
(162899, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162899 (Gran maestro Vole)
(175392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175392 (Trampero Hickman)
(163083, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163083 (Evaluador Malus)
(166400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166400 (Aprendiz incansable)
(164507, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164507 (Espectador de la arena)
(161710, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161710 (Marcel Mullby)
(159830, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159830 (Au'narim)
(159827, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159827 (Desguazadora Minoire)
(165473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165473 (Colmisangre alfa)
(166562, 0, 0, 0, 1, 0, 0, 0, 0, '324578'), -- 166562 (Talzedo) - Beginner's Spell
(159828, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159828 (Fan de Desguazadora)
(162872, 0, 0, 0, 1, 0, 0, 0, 0, '317096'), -- 162872 (Xantuth la Contagiada) - Containment Cell Visuals
(166552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166552 (Jessana)
(159824, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159824 (Gunn Tragahuesos)
(159689, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 159689 (Sobrestante Kalvaros) - Cosmetic - Offhand Book
(159825, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159825 (Fan de Tragahuesos)
(164492, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164492 (Espectador de la arena)
(163041, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 163041 (Prospector de la arena)
(159822, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159822 (Fan de Dínamo)
(159696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159696 (Rencissa, la Dínamo)
(162588, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162588 (Picartílago)
(164508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164508 (Espectador de la arena)
(175023, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- 175023 (Animated Cruor) - Battle Pet Periodic
(174652, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174652 (Animated Cruor)
(169795, 0, 0, 50593792, 1, 0, 0, 0, 0, '154470'), -- 169795 (Avispa cinérea zombi) - Permanent Feign Death (Flies)
(169830, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169830 (Larva parasitaria)
(168226, 0, 0, 8, 0, 0, 0, 0, 0, ''), -- 168226 (Earl el ciego)
(175391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175391 (Luke Herczeg)
(161677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161677 (Plimpton)
(162093, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162093 (Kurly)
(167639, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167639 (Desollador Coxis)
(161675, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161675 (Iva Gamey)
(161673, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161673 (Elsie Mullby)
(164797, 0, 0, 0, 1, 0, 0, 0, 0, '320796'), -- 164797 (Minni) - 9.0 Carry Maldraxxus Barrel
(167638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167638 (Berk la Pútrida)
(167637, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167637 (Tai Wol'Kur)
(167636, 0, 0, 0, 1, 0, 0, 0, 0, '326244'), -- 167636 (Winslow Swan) - Play Lute
(175144, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175144 (Oso bebé)
(175398, 0, 0, 1, 257, 0, 0, 0, 0, ''), -- 175398 (Mantaraganak)
(167640, 0, 96544, 0, 1, 0, 0, 0, 0, ''), -- 167640 (Capitán John Shin)
(174002, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174002 (Sargento Krashj)
(165335, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165335 (Recluta leal)
(172609, 0, 0, 50331648, 1, 0, 0, 0, 0, '321276 337074'), -- 172609 (Mortisombra de Xantuth) - Summon Skeleton, Necrotic Breath
(148086, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 148086 (Skullsplitter Thug)
(148080, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 148080 (Olly)
(129394, 0, 0, 0, 1, 0, 0, 0, 0, '256354'), -- 129394 (Bribón callejero intrigante) - Major Dinofication
(142983, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 142983 (Swizzle Palanqueta)
(142973, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 142973 (Mai-Lu)
(138949, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 138949 (Throk)
(154465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 154465 (Guardián terráneo)
(104792, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 104792 (Diablillo encarcelado)
(175518, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 175518 (Aventurero de las Tierras de las Sombras)
(66854, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66854 (Iniciado Chuang)
(66260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66260 (Maestro Cenit)
(66256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66256 (Maestra Cheng)
(66360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66360 (Maestro Brandom)
(66257, 0, 0, 0, 1, 0, 0, 0, 0, '131604'), -- 66257 (Maestro Tsang) - Meditating
(66947, 0, 0, 0, 1, 0, 0, 0, 0, '130074'), -- 66947 (Alumno monje) - Stand On Balance Pole
(66946, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66946 (Poste de equilibrio)
(67021, 0, 0, 0, 1, 0, 0, 0, 0, '131769'), -- 67021 (Alumno monje) - Meditating
(128106, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 128106 (Zidormi)
(67066, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67066 (Alumno monje)
(64975, 0, 0, 0, 1, 0, 0, 0, 0, '114742'), -- 64975 (Ponshu Cuerpo Férreo) - Brewback
(66969, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 66969 (Saco de entrenamiento)
(67095, 0, 0, 0, 1, 0, 1223, 0, 0, '131956'), -- 67095 (Maestra Yeoh) - Roll
(67092, 0, 0, 0, 1, 0, 1223, 0, 0, '131956'), -- 67092 (Maestro Chow) - Roll
(167649, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167649 (Kresto Piromuerte)
(174488, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 174488 (Defensor inquebrantable) - Training Dummy Marker
(174491, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 174491 (Probador de hierro) - Training Dummy Marker
(174484, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 174484 (Campeón inamovible) - Training Dummy Marker
(174487, 0, 0, 0, 1, 0, 0, 0, 0, '98892'), -- 174487 (Veterano competente) - Training Dummy Marker
(165433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165433 (Erak Ariaacero)
(165434, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 165434 (Evaluador Simmons)
(165432, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165432 (Aprendiz Thayer)
(174492, 0, 0, 0, 1, 0, 0, 0, 0, '321990'), -- 174492 (Edrich Adebo) - Carry Candle
(174489, 0, 0, 50331648, 1, 0, 0, 0, 0, '98892 167347'), -- 174489 (Guía nigromántico) - Training Dummy Marker, Passive Uber DoT
(165435, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 165435 (Stanley vistafilada)
(172680, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172680 (Visión del Primus)
(165321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165321 (Merick Feldcicatriz)
(175371, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175371 (Mortis Elfsen)
(175370, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 175370 (Gwor, el Odioso)
(175311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175311 (Destripador Araya)
(167210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167210 (Tabulador Killham)
(175310, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 175310 (Mellisa Fate)
(175312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175312 (Taiya Tacere)
(165431, 0, 0, 0, 1, 0, 0, 0, 0, '321990'), -- 165431 (Kiara Coil) - Carry Candle
(161985, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161985 (Baronesa Vashj)
(175314, 0, 0, 0, 1, 0, 0, 0, 0, '322217'), -- 175314 (Tripazón) - 9.0 Carry Maldraxxus Armor
(161988, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 161988 (Alexandros Mograine)
(167748, 0, 0, 0, 1, 0, 0, 0, 0, '337016'), -- 167748 (Osbourne Black) - Soul Warden Spell Visual
(165347, 0, 0, 0, 1, 0, 0, 0, 0, '321988'), -- 165347 (Alvira Mortaja) - Carry Vase, Filled with Crystals, With Kneeling
(173000, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173000 (Madeleine Roux)
(165350, 0, 0, 0, 1, 0, 0, 0, 0, '321990'), -- 165350 (Lyra Granizormenta) - Carry Candle
(172176, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 172176 (Tsu Zettai)
(161907, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161907 (Baronesa Draka)
(161904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161904 (Maestro de plagas Marileth)
(167205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167205 (Yondare Maleficio)
(167208, 0, 0, 33554432, 1, 0, 0, 0, 0, '155059'), -- 167208 (Gran maestro Vole) - Hologram-ify
(167201, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 167201 (Gatherer Zaya)
(167645, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 167645 (Jericó Murallada)
(172173, 0, 0, 0, 1, 0, 0, 0, 0, '212171'), -- 172173 (Intérprete de disputas) - Read Scroll
(175791, 0, 0, 0, 1, 0, 0, 0, 0, '321990'), -- 175791 (Felicia Noche) - Carry Candle
(174505, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 174505 (Proveedor supremo)
(161909, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 161909 (Arkadia Moa)
(168685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168685 (Teniente McBride)
(167207, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167207 (Sabbath Sombranoche)
(175963, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175963 (Serafina Von)
(173022, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173022 (Enceladus)
(175998, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175998 (Elspeth Larink)
(164128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164128 (Mefiles el Leal)
(169992, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169992 (Rencor imperfecto) - Mod Scale 105-110%
(164713, 0, 0, 1, 1, 0, 0, 0, 0, ''); -- 164713 (Fungio aterrado)

UPDATE `creature_template_addon` SET `auras`='260037' WHERE `entry`=166567; -- 166567 (Mímico)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=162816; -- 162816 (Generic Bunny)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=166424; -- 166424 (Obrero de la Arena)
UPDATE `creature_template_addon` SET `auras`='317184 336859' WHERE `entry`=162873; -- 162873 (Azmogal)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='192297' WHERE `entry`=169055; -- 169055 (Raspamédulas)
UPDATE `creature_template_addon` SET `auras`='323641' WHERE `entry`=168192; -- 168192 (Anciano colmisangre)
UPDATE `creature_template_addon` SET `auras`='214567' WHERE `entry`=159856; -- 159856 (Peste virulenta)
UPDATE `creature_template_addon` SET `auras`='306664 306722 306719' WHERE `entry`=157226; -- 157226 (Poza de monstruosidades mezcladas)
UPDATE `creature_template_addon` SET `auras`='250264' WHERE `entry`=143595; -- 143595 (Peón del muelle)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=133212; -- 133212 (Comerciante Munengo)
UPDATE `creature_template_addon` SET `aiAnimKit`=16381 WHERE `entry`=142776; -- 142776 (Wahla)
UPDATE `creature_template_addon` SET `auras`='159510' WHERE `entry`=139634; -- 139634 (Biru el borracho)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142502; -- 142502 (Zandalari Child)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=133549; -- 133549 (Vagante zandalari)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=132394; -- 132394 (Vagante zandalari)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=120900; -- 120900 (Guerrero amani)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=146234; -- 146234 (FX Stalker)
UPDATE `creature_template_addon` SET `auras`='270114' WHERE `entry`=132308; -- 132308 (Conquistador rastari)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=131514; -- 131514 (Ciudadano desesperado)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=131216; -- 131216 (Forsaken Battleguard)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=96820; -- 96820 (Pagadora Alstein)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=96698; -- 96698 (Blood Knight)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=96708; -- 96708 (Blood Knight)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=104230; -- 104230 (Mailemental)
UPDATE `creature_template_addon` SET `auras`='211577' WHERE `entry`=106655; -- 106655 (Arcanomántico Vridiel)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=96808; -- 96808 (Sandra Bartan)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116420; -- 116420 (Gema azul resplandeciente)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116419; -- 116419 (Gema verde resplandeciente)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=96782; -- 96782 (Lucian Trias)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=72587; -- 72587 (VFX Bunny)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=34330; -- 34330 (Jones)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- 121541 (Ban-Lu)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115072; -- 115072 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115071; -- 115071 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115074; -- 115074 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115003; -- 115003 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115002; -- 115002 (Maribeth)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115073; -- 115073 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115000; -- 115000 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=10816 WHERE `entry`=114892; -- 114892 (Withering Civilian)
UPDATE `creature_template_addon` SET `aiAnimKit`=10816 WHERE `entry`=114889; -- 114889 (Shal'dorei Civilian)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=10816 WHERE `entry`=114888; -- 114888 (Civiles shal'dorei)
UPDATE `creature_template_addon` SET `aiAnimKit`=2953 WHERE `entry`=115075; -- 115075 (Civil Shal'dorei condenado)
UPDATE `creature_template_addon` SET `aiAnimKit`=2560 WHERE `entry`=116411; -- 116411 (Portal de máquina de almas)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=82347; -- 82347 (Persecutor)
UPDATE `creature_template_addon` SET `bytes1`=50593792, `bytes2`=1, `auras`='159474' WHERE `entry`=89940; -- 89940 (Azurewing Scalewarden)
UPDATE `creature_template_addon` SET `auras`='183815' WHERE `entry`=54638; -- 54638 (Generic Bunny)
UPDATE `creature_template_addon` SET `mount`=72966, `auras`='' WHERE `entry`=91629; -- 91629 (Agente Illidari)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106920; -- 106920 (Feathered Prowler)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=89386; -- 89386 (Hipogrifo alarrisco)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=91265; -- 91265 (Zorro de Llothien)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='123169 159474' WHERE `entry`=91308; -- 91308 (Equino trotasol)
UPDATE `creature_template_addon` SET `auras`='213090' WHERE `entry`=107439; -- 107439 (Alimentador de bestias Ojosalado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=91128; -- 91128 (Basilisco de laguna)
UPDATE `creature_template_addon` SET `aiAnimKit`=7624 WHERE `entry`=88797; -- 88797 (Anciano Aldryth)
UPDATE `creature_template_addon` SET `auras`='182773' WHERE `entry`=88090; -- 88090 (Comandante sondeador Zarrin)
UPDATE `creature_template_addon` SET `aiAnimKit`=7702 WHERE `entry`=89341; -- 89341 (Magister Garuhod)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=89634; -- 89634 (Ciudadano de Nar'thalas)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=88782; -- 88782 (Vigía de la noche de Nar'thalas)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=93619; -- 93619 (Moledor infernal)
UPDATE `creature_template_addon` SET `auras`='79977 79976' WHERE `entry`=98159; -- 98159 (Alynblaze)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=40891; -- 40891 (Obrero Dranosh'ar)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=74228; -- 74228 (Rebanacabezas Lanza Negra)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=141693; -- 141693 (Velma Warnam)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=149522; -- 149522 (Peón de Orgrimmar)
UPDATE `creature_template_addon` SET `bytes1`=3, `aiAnimKit`=0 WHERE `entry`=141119; -- 141119 (Refugiado Renegado)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=160424; -- 160424 (Creasedios veterano)
UPDATE `creature_template_addon` SET `auras`='273259' WHERE `entry`=165017; -- 165017 (Inventor de plagas)


UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161905 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=163224 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=172656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=163030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166570 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161733 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175393 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=166567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=166565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=169697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=157540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161712 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=170542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161702 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=173003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=170496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164997 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=163032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=158071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160256 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=172608 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=172567 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=172591 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=166226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=161599 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=162813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=162797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162816 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=163084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=161597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166331 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=166321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166531 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=166545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=163043 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=163019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=161757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=162899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=166421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=163083 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=166424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=159827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=165473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=166562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=162872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1330, `VerifiedBuild`=38134 WHERE (`Entry`=166552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=159824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159825 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164492 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=163041 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=159822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=159696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=162588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164508 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=175023 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=174652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169795 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=169830 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=162873 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=162853 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=158642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=168226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162257 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=168192 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162256 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=168196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=173200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=176024 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=169751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162259 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=174653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1336, `VerifiedBuild`=38134 WHERE (`Entry`=170191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=159856 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=176023 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=168216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=162258 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160253 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=164759 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=164758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=167948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=58, `LevelScalingMax`=58, `LevelScalingDeltaMax`=0, `ContentTuningID`=1425, `VerifiedBuild`=38134 WHERE (`Entry`=171599 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=165014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=171415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=158406 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=167358 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=165027 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=157945 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=171217 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=171129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=165052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=157313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=171130 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=172141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161841 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=171133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166579 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=171135 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=165015 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=157515 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1340, `VerifiedBuild`=38134 WHERE (`Entry`=165049 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=165034 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=157226 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=171112 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=167923 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=162093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161675 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161673 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=164797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167637 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167636 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=93008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1334, `VerifiedBuild`=38134 WHERE (`Entry`=175144 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161679 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175398 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=165335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=175021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=168045 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=169634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167642 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=157514 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161890 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161881 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=172609 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=885, `VerifiedBuild`=38134 WHERE (`Entry`=97515 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=885, `VerifiedBuild`=38134 WHERE (`Entry`=97507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136796 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126153 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126161 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=126148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=148086 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=841, `VerifiedBuild`=38134 WHERE (`Entry`=148080 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142157 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=143595 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMax`=0, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=129394 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=129266 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=129267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133207 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133206 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129264 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129279 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128909 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129262 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=-1, `LevelScalingDeltaMax`=-1, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=142766 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120949 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142776 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142781 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134344 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=142757 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144384 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=134346 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129929 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143156 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131351 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=125312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143138 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=148924 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142158 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142973 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131752 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142969 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=138949 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=143396 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=143388 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=143614 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142981 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=292, `VerifiedBuild`=38134 WHERE (`Entry`=151162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142970 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=143615 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=142992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=147974 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=147975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=120843 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=740, `VerifiedBuild`=38134 WHERE (`Entry`=154465 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=96698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=96708 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=30, `LevelScalingDeltaMax`=0, `ContentTuningID`=196, `VerifiedBuild`=38134 WHERE (`Entry`=32454 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=114946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMin`=3, `ContentTuningID`=336, `VerifiedBuild`=38134 WHERE (`Entry`=120419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=39859 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=113127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=113122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=110899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=110948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115003 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=113209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=113210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=73828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=49568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115073 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=114892 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=114889 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=114888 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=114904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=116659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=115012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=335, `VerifiedBuild`=38134 WHERE (`Entry`=116411 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=111414 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=111377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=106772 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=107027 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107241 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=106583 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=106798 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=82347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=106356 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=106516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=106514 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89940 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=92447 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=92630 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=92450 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107244 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91485 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=348, `VerifiedBuild`=38134 WHERE (`Entry`=102456 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=642, `VerifiedBuild`=38134 WHERE (`Entry`=92445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=2114, `VerifiedBuild`=38134 WHERE (`Entry`=91629 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=881, `VerifiedBuild`=38134 WHERE (`Entry`=111624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=8, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=699, `VerifiedBuild`=38134 WHERE (`Entry`=113833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107407 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=339, `VerifiedBuild`=38134 WHERE (`Entry`=104792 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=106920 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89386 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=90696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91267 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=90694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=97294 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91717 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91265 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=90134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91269 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=348, `VerifiedBuild`=38134 WHERE (`Entry`=99598 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=89390 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=62177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=90901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=49842 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=90313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91430 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91431 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107439 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=91128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=93627 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89849 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89653 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=108680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=64352 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89652 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89015 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89661 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107334 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88970 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=108163 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88086 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=89380 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88094 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107367 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88101 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=113137 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109174 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=64806 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=110826 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88888 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=885, `VerifiedBuild`=38134 WHERE (`Entry`=98964 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109154 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89341 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88115 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109372 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109368 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=98381 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88798 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=105040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=105039 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=109124 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=347, `VerifiedBuild`=38134 WHERE (`Entry`=107376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=107139 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89696 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89634 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=633, `VerifiedBuild`=38134 WHERE (`Entry`=106873 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=2114, `VerifiedBuild`=38134 WHERE (`Entry`=88782 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=93619 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=89680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=98159 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=331, `VerifiedBuild`=38134 WHERE (`Entry`=88089 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175518 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66260 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=1217, `VerifiedBuild`=38134 WHERE (`Entry`=66256 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66360 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=1217, `VerifiedBuild`=38134 WHERE (`Entry`=66257 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66947 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=20, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=45, `LevelScalingDeltaMax`=0, `ContentTuningID`=337, `VerifiedBuild`=38134 WHERE (`Entry`=128106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67066 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=64975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=66969 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67095 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=60, `VerifiedBuild`=38134 WHERE (`Entry`=67092 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=170971 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1333, `VerifiedBuild`=38134 WHERE (`Entry`=167273 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=164833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1333, `VerifiedBuild`=38134 WHERE (`Entry`=160424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=160415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167747 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=167355 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=3, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=3, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174484 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=174487 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=165433 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1335, `VerifiedBuild`=38134 WHERE (`Entry`=165434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=165432 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=174492 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=174489 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=165435 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167741 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1333, `VerifiedBuild`=38134 WHERE (`Entry`=157671 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=167354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=156558 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=172680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=157843 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175370 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175311 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167210 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175310 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=157803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165431 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161985 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175314 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167748 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=173000 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=160419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=53, `LevelScalingDeltaMax`=0, `ContentTuningID`=1325, `VerifiedBuild`=38134 WHERE (`Entry`=164915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164221 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165350 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=172176 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=158339 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=161904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=165017 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167205 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=55, `LevelScalingMax`=58, `LevelScalingDeltaMax`=0, `ContentTuningID`=744, `VerifiedBuild`=38134 WHERE (`Entry`=167208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=167201 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167645 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=172173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=175791 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=174505 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=161909 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=166423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=168685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167209 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167207 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=175963 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=173022 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=161994 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=164667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=174650 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1327, `VerifiedBuild`=38134 WHERE (`Entry`=164128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=169992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=164713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=167949 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=169129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=167356 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=167359 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=54, `LevelScalingMax`=54, `LevelScalingDeltaMax`=0, `ContentTuningID`=1329, `VerifiedBuild`=38134 WHERE (`Entry`=160048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=167935 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=53, `LevelScalingMax`=55, `LevelScalingDeltaMax`=0, `ContentTuningID`=745, `VerifiedBuild`=38134 WHERE (`Entry`=170456 AND `DifficultyID`=0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=100590;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(100590, 2.455555438995361328, 2.599999904632568359, 0, 38134);

UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96102;
UPDATE `creature_model_info` SET `BoundingRadius`=2.654331207275390625, `CombatReach`=2.859999895095825195, `VerifiedBuild`=38134 WHERE `DisplayID`=94243;
UPDATE `creature_model_info` SET `BoundingRadius`=0.822990000247955322, `CombatReach`=2.76412510871887207, `VerifiedBuild`=38134 WHERE `DisplayID`=95966;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94145;
UPDATE `creature_model_info` SET `BoundingRadius`=1.197071075439453125, `CombatReach`=1.5 WHERE `DisplayID`=95227;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95327;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95379;
UPDATE `creature_model_info` SET `BoundingRadius`=1.117860913276672363, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=94757;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95387;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=9906;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95968;
UPDATE `creature_model_info` SET `BoundingRadius`=1.007195711135864257, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=96135;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96188;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=32962;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95957;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96897;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95083;
UPDATE `creature_model_info` SET `BoundingRadius`=3.185197830200195312, `CombatReach`=3.432000160217285156, `VerifiedBuild`=38134 WHERE `DisplayID`=94440;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888955116271972, `CombatReach`=2 WHERE `DisplayID`=93593;
UPDATE `creature_model_info` SET `BoundingRadius`=1.451156854629516601, `CombatReach`=5.487999916076660156, `VerifiedBuild`=38134 WHERE `DisplayID`=98164;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96187;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629497289657592773, `CombatReach`=1.125 WHERE `DisplayID`=96060;
UPDATE `creature_model_info` SET `BoundingRadius`=2.654331207275390625, `CombatReach`=2.859999895095825195, `VerifiedBuild`=38134 WHERE `DisplayID`=94245;
UPDATE `creature_model_info` SET `BoundingRadius`=0.615508496761322021, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=96059;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95959;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100426;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95385;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95815;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98067;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95961;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97894;
UPDATE `creature_model_info` SET `BoundingRadius`=1.704095959663391113, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=99589;
UPDATE `creature_model_info` SET `BoundingRadius`=1.420079946517944335, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95393;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5 WHERE `DisplayID`=96196;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93155074119567871, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95011;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96871;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96271;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94050;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94933;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94090;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93155074119567871, `CombatReach`=1.5 WHERE `DisplayID`=94834;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98582;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95769;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94058;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94089;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94070;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93155074119567871, `CombatReach`=1.5 WHERE `DisplayID`=94761;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95386;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95967;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99910;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88361;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98581;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98055;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.526631593704223632, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=97079;
UPDATE `creature_model_info` SET `BoundingRadius`=3.156650543212890625, `CombatReach`=12, `VerifiedBuild`=38134 WHERE `DisplayID`=96310;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99861;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98465;
UPDATE `creature_model_info` SET `BoundingRadius`=1.239107370376586914, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=92246;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=11094;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98462;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98467;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95797;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34901;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98463;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98673;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94922;
UPDATE `creature_model_info` SET `BoundingRadius`=3.860790967941284179, `CombatReach`=5.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=94882;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95790;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28619;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69316;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32019;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96641;
UPDATE `creature_model_info` SET `BoundingRadius`=2.574557065963745117, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=91656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59245;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93547;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94921;
UPDATE `creature_model_info` SET `BoundingRadius`=1.83896946907043457, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=95788;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97464;
UPDATE `creature_model_info` SET `BoundingRadius`=1.471175551414489746, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=95787;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.80686497688293457, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=95550;
UPDATE `creature_model_info` SET `BoundingRadius`=0.80686497688293457, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=94526;
UPDATE `creature_model_info` SET `BoundingRadius`=1.103381752967834472, `CombatReach`=0.75 WHERE `DisplayID`=95785;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96241;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97469;
UPDATE `creature_model_info` SET `BoundingRadius`=0.734413444995880126, `CombatReach`=1.3125, `VerifiedBuild`=38134 WHERE `DisplayID`=97424;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.870888888835906982, `CombatReach`=2.925000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=95947;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97388;
UPDATE `creature_model_info` SET `BoundingRadius`=1.268311858177185058, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=96243;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94155;
UPDATE `creature_model_info` SET `BoundingRadius`=0.615508496761322021, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=96131;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15983;
UPDATE `creature_model_info` SET `BoundingRadius`=0.755396783351898193, `CombatReach`=1.35000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=96553;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96551;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96552;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96467;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93155074119567871, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95559;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95994;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96543;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96893;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96118;
UPDATE `creature_model_info` SET `BoundingRadius`=1.937827825546264648, `CombatReach`=2.024999856948852539, `VerifiedBuild`=38134 WHERE `DisplayID`=96223;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97016;
UPDATE `creature_model_info` SET `BoundingRadius`=1.136063933372497558, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=95384;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699441432952880859, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=96211;
UPDATE `creature_model_info` SET `BoundingRadius`=1.197071075439453125, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95112;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94704;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95113;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100181;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65250;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65239;
UPDATE `creature_model_info` SET `BoundingRadius`=1.623862981796264648, `VerifiedBuild`=38134 WHERE `DisplayID`=59541;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87588;
UPDATE `creature_model_info` SET `BoundingRadius`=2.854794979095458984, `VerifiedBuild`=38134 WHERE `DisplayID`=80569;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3687286376953125, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=79720;
UPDATE `creature_model_info` SET `BoundingRadius`=0.227499991655349731, `CombatReach`=0.649999976158142089 WHERE `DisplayID`=86529;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87746;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90164;
UPDATE `creature_model_info` SET `BoundingRadius`=0.443431794643402099, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=83854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87738;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.409200012683868408, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=78824;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87771;
UPDATE `creature_model_info` SET `BoundingRadius`=0.380948185920715332, `CombatReach`=1.417499899864196777, `VerifiedBuild`=38134 WHERE `DisplayID`=83831;
UPDATE `creature_model_info` SET `BoundingRadius`=0.600794732570648193, `CombatReach`=1.417499899864196777, `VerifiedBuild`=38134 WHERE `DisplayID`=83833;
UPDATE `creature_model_info` SET `BoundingRadius`=0.380948185920715332, `CombatReach`=1.417499899864196777, `VerifiedBuild`=38134 WHERE `DisplayID`=83830;
UPDATE `creature_model_info` SET `BoundingRadius`=0.600794732570648193, `CombatReach`=1.417499899864196777, `VerifiedBuild`=38134 WHERE `DisplayID`=83832;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87745;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87742;
UPDATE `creature_model_info` SET `BoundingRadius`=0.577600002288818359, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=91043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.363630026578903198, `CombatReach`=1.466250061988830566 WHERE `DisplayID`=83861;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87739;
UPDATE `creature_model_info` SET `BoundingRadius`=0.23069000244140625, `CombatReach`=1.466250061988830566 WHERE `DisplayID`=83859;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=87733;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89367;
UPDATE `creature_model_info` SET `BoundingRadius`=0.23069000244140625, `CombatReach`=1.466250061988830566 WHERE `DisplayID`=83858;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88890;
UPDATE `creature_model_info` SET `BoundingRadius`=0.363630026578903198, `CombatReach`=1.466250061988830566 WHERE `DisplayID`=83860;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87748;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88839;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89086;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89085;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81030;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.031000001356005668, `CombatReach`=0.100000001490116119 WHERE `DisplayID`=60862;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.611057877540588378 WHERE `DisplayID`=88157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99435;
UPDATE `creature_model_info` SET `BoundingRadius`=0.28973478078842163 WHERE `DisplayID`=52602;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62151;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=62155;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28151;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65354;
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65372;
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `CombatReach`=2.799999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=64971;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28157;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1004;
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5 WHERE `DisplayID`=5585;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=52659;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=20833;
UPDATE `creature_model_info` SET `BoundingRadius`=0.794200003147125244, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=65424;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67016;
UPDATE `creature_model_info` SET `BoundingRadius`=1.656566381454467773, `VerifiedBuild`=38134 WHERE `DisplayID`=59729;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=30869;
UPDATE `creature_model_info` SET `BoundingRadius`=1.70396125316619873, `VerifiedBuild`=38134 WHERE `DisplayID`=76630;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67043;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65975;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66672;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=67760;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66159;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=23748;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=72654;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=71988;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=74245;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=51301;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=16480;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=70014;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70018;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70017;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71685;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70011;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=72002;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=71989;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70016;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=70013;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=72001;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73535;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=73592;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70880;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66503;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=48804;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32214;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3 WHERE `DisplayID`=32221;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32660;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32661;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=69715;
UPDATE `creature_model_info` SET `BoundingRadius`=0.234999999403953552, `VerifiedBuild`=38134 WHERE `DisplayID`=58573;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69622;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69624;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69621;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69655;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=69614;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69720;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69601;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69574;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69623;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69617;
UPDATE `creature_model_info` SET `BoundingRadius`=2.97482919692993164, `VerifiedBuild`=38134 WHERE `DisplayID`=70402;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63048;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62532;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72868;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=10090;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=62530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71858;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72966;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63194;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=63631;
UPDATE `creature_model_info` SET `BoundingRadius`=0.451181411743164062 WHERE `DisplayID`=36549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.287755131721496582, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=42412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69709;
UPDATE `creature_model_info` SET `BoundingRadius`=4.334691524505615234, `VerifiedBuild`=38134 WHERE `DisplayID`=66542;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69191;
UPDATE `creature_model_info` SET `BoundingRadius`=1.146589994430541992, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=67552;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=26404;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=66621;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=346;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15394;
UPDATE `creature_model_info` SET `BoundingRadius`=0.331982642412185668, `VerifiedBuild`=38134 WHERE `DisplayID`=15397;
UPDATE `creature_model_info` SET `BoundingRadius`=0.331982642412185668, `VerifiedBuild`=38134 WHERE `DisplayID`=15393;
UPDATE `creature_model_info` SET `BoundingRadius`=2.889794349670410156, `VerifiedBuild`=38134 WHERE `DisplayID`=67021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.331982642412185668, `VerifiedBuild`=38134 WHERE `DisplayID`=15395;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61818;
UPDATE `creature_model_info` SET `CombatReach`=5.599999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=57516;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61739;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71007;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61740;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61122;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=34590;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61744;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61746;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69922;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61747;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61742;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61283;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61743;
UPDATE `creature_model_info` SET `BoundingRadius`=1.328571319580078125, `CombatReach`=1.660714149475097656, `VerifiedBuild`=38134 WHERE `DisplayID`=32023;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61745;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=31018;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=486;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=540;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41300;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=680;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=45882;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=66027;
UPDATE `creature_model_info` SET `BoundingRadius`=2.854874610900878906, `CombatReach`=3.5, `VerifiedBuild`=38134 WHERE `DisplayID`=67397;
UPDATE `creature_model_info` SET `BoundingRadius`=2.452655315399169921, `VerifiedBuild`=38134 WHERE `DisplayID`=32568;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61100;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61693;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=60845;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71004;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70986;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61099;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65790;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61123;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33534;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=31215;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=54644;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62070;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61098;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61097;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61096;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69851;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61101;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61095;
UPDATE `creature_model_info` SET `BoundingRadius`=1.429126143455505371, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=31291;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69860;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875231742858886718, `VerifiedBuild`=38134 WHERE `DisplayID`=22590;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2622;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99434;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=16795;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4110;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3859;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=9353;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82770;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2655;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3863;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15783;
UPDATE `creature_model_info` SET `BoundingRadius`=0.402149975299835205, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=27588;
UPDATE `creature_model_info` SET `BoundingRadius`=0.426489889621734619, `CombatReach`=1 WHERE `DisplayID`=2177;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=25436;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45419;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=44998;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45299;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45001;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45640;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45003;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=27756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45642;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41568;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45769;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45771;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96469;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96466;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95965;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95392;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95969;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96561;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99867;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96438;
UPDATE `creature_model_info` SET `BoundingRadius`=0.989875495433807373, `VerifiedBuild`=38134 WHERE `DisplayID`=98199;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96116;
UPDATE `creature_model_info` SET `BoundingRadius`=1.022457480430603027, `CombatReach`=1.079999923706054687, `VerifiedBuild`=38134 WHERE `DisplayID`=95395;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96212;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95997;
UPDATE `creature_model_info` SET `BoundingRadius`=0.923883795738220214, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=98200;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96202;
UPDATE `creature_model_info` SET `BoundingRadius`=0.696711122989654541, `CombatReach`=2.340000152587890625, `VerifiedBuild`=38134 WHERE `DisplayID`=95963;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95573;
UPDATE `creature_model_info` SET `BoundingRadius`=1.091128706932067871, `CombatReach`=1.95000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=96555;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94812;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99843;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99524;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99520;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5 WHERE `DisplayID`=96133;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99514;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99515;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96138;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99516;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94718;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96072;
UPDATE `creature_model_info` SET `BoundingRadius`=0.733513593673706054, `CombatReach`=1.5 WHERE `DisplayID`=95231;
UPDATE `creature_model_info` SET `BoundingRadius`=0.155000001192092895, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=94148;
UPDATE `creature_model_info` SET `BoundingRadius`=0.919484734535217285, `CombatReach`=0.625, `VerifiedBuild`=38134 WHERE `DisplayID`=95786;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95792;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=70087;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95791;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96201;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95979;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95687;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96443;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94122;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.696837902069091796, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=95991;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95394;
UPDATE `creature_model_info` SET `BoundingRadius`=2.126192092895507812, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=95796;
UPDATE `creature_model_info` SET `BoundingRadius`=1.007195711135864257, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=96115;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96209;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95655;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=96200;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98077;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.839329779148101806, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=98197;
UPDATE `creature_model_info` SET `BoundingRadius`=0.923262715339660644, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=96489;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97877;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100073;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629497289657592773, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=96208;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95376;
UPDATE `creature_model_info` SET `BoundingRadius`=0.870888888835906982, `CombatReach`=2.925000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=95944;
UPDATE `creature_model_info` SET `BoundingRadius`=0.733513593673706054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=94992;
UPDATE `creature_model_info` SET `BoundingRadius`=0.919484734535217285, `CombatReach`=0.625, `VerifiedBuild`=38134 WHERE `DisplayID`=95789;
UPDATE `creature_model_info` SET `BoundingRadius`=1.183341622352600097, `CombatReach`=3.300000190734863281 WHERE `DisplayID`=83597;
UPDATE `creature_model_info` SET `BoundingRadius`=1.183341622352600097, `CombatReach`=3.300000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=83594;
UPDATE `creature_model_info` SET `BoundingRadius`=0.615508496761322021, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=96132;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97654;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97655;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80245;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=59546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.760987162590026855, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=96239;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=61550;
UPDATE `creature_model_info` SET `BoundingRadius`=0.88781827688217163, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=96244;
UPDATE `creature_model_info` SET `BoundingRadius`=0.606859982013702392, `CombatReach`=0.41250002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=96635;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94867;

DELETE FROM `npc_vendor` WHERE (`entry`=166640 AND `item`=179939 AND `ExtendedCost`=7046 AND `type`=1) OR (`entry`=166640 AND `item`=180658 AND `ExtendedCost`=7046 AND `type`=1) OR (`entry`=166640 AND `item`=180659 AND `ExtendedCost`=7046 AND `type`=1) OR (`entry`=166640 AND `item`=180657 AND `ExtendedCost`=7046 AND `type`=1) OR (`entry`=166640 AND `item`=180706 AND `ExtendedCost`=7046 AND `type`=1) OR (`entry`=166640 AND `item`=180686 AND `ExtendedCost`=7044 AND `type`=1) OR (`entry`=166640 AND `item`=180694 AND `ExtendedCost`=7045 AND `type`=1) OR (`entry`=166640 AND `item`=179613 AND `ExtendedCost`=7045 AND `type`=1) OR (`entry`=166640 AND `item`=180771 AND `ExtendedCost`=7047 AND `type`=1) OR (`entry`=166640 AND `item`=181623 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=166640 AND `item`=177957 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(166640, 205, 179939, 4, 7046, 1, 0, 0, 38134), -- Wriggling Spider Sac
(166640, 204, 180658, 4, 7046, 1, 0, 0, 38134), -- Witherlight Crystal
(166640, 203, 180659, 4, 7046, 1, 0, 0, 38134), -- Soul Siphoning Shard
(166640, 202, 180657, 4, 7046, 1, 0, 0, 38134), -- Crystallized Ichor
(166640, 201, 180706, 4, 7046, 1, 0, 0, 38134), -- Caustic Muck
(166640, 200, 180686, 1, 7044, 1, 0, 0, 38134), -- "Borrowed" Soulstone
(166640, 199, 180694, 3, 7045, 1, 0, 0, 38134), -- Tome of Power
(166640, 198, 179613, 2, 7045, 1, 0, 0, 38134), -- Extra Sticky Spidey Webs
(166640, 3, 180771, 0, 7047, 1, 0, 0, 38134), -- Potion of Unusual Strength
(166640, 2, 181623, 0, 0, 1, 0, 0, 38134), -- Fluorescent Slime Sample
(166640, 1, 177957, 0, 0, 1, 0, 0, 38134); -- Necessary Enhancers


DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (163084,166540,175392,163083,166400,175391,167640,165335,138949,167649,165433,165434,165432,165435,175371,175311,175310,175312,161988,173000,172176,167205,167201,167645,174505,161909,168685,175963,173022,175998,164128)) OR (`ID`=2 AND `CreatureID` IN (166540,166400,174505));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(163084, 1, 103209, 0, 0, 0, 0, 0, 0, 0, 0), -- Examinadora Sahaari
(166540, 2, 176551, 0, 0, 176724, 0, 0, 0, 0, 0), -- Aprendiz incansable
(166540, 1, 174217, 0, 0, 176724, 0, 0, 0, 0, 0), -- Aprendiz incansable
(175392, 1, 56887, 0, 0, 56887, 0, 0, 0, 0, 0), -- Trampero Hickman
(166400, 2, 106203, 0, 0, 0, 0, 0, 155772, 0, 0), -- Aprendiz incansable
(163083, 1, 48404, 0, 0, 0, 0, 0, 0, 0, 0), -- Evaluador Malus
(166400, 1, 174217, 0, 0, 176724, 0, 0, 155772, 0, 0), -- Aprendiz incansable
(175391, 1, 174217, 0, 0, 174217, 0, 0, 0, 0, 0), -- Luke Herczeg
(167640, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Capitán John Shin
(165335, 1, 176546, 0, 0, 0, 0, 0, 0, 0, 0), -- Recluta leal
(138949, 1, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Throk
(167649, 1, 51400, 0, 0, 0, 0, 0, 0, 0, 0), -- Kresto Piromuerte
(165433, 1, 174308, 0, 0, 0, 0, 0, 0, 0, 0), -- Erak Ariaacero
(165434, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Evaluador Simmons
(165432, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Aprendiz Thayer
(165435, 1, 174308, 0, 0, 0, 0, 0, 176576, 0, 0), -- Stanley vistafilada
(174505, 2, 176547, 0, 0, 0, 0, 0, 0, 0, 0), -- Proveedor supremo
(175371, 1, 177265, 0, 0, 176724, 0, 0, 0, 0, 0), -- Mortis Elfsen
(175311, 1, 174308, 0, 0, 176720, 0, 0, 0, 0, 0), -- Destripador Araya
(175310, 1, 184070, 0, 0, 0, 0, 0, 176576, 0, 0), -- Mellisa Fate
(175312, 1, 183083, 0, 0, 176724, 0, 0, 0, 0, 0), -- Taiya Tacere
(161988, 1, 181255, 0, 0, 0, 0, 0, 0, 0, 0), -- Alexandros Mograine
(173000, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Madeleine Roux
(172176, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Tsu Zettai
(167205, 1, 176591, 0, 0, 0, 0, 0, 0, 0, 0), -- Yondare Maleficio
(167201, 1, 176604, 0, 0, 176724, 0, 0, 0, 0, 0), -- Gatherer Zaya
(167645, 1, 176591, 0, 0, 0, 0, 0, 0, 0, 0), -- Jericó Murallada
(174505, 1, 176566, 0, 0, 0, 0, 0, 0, 0, 0), -- Proveedor supremo
(161909, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- Arkadia Moa
(168685, 1, 177267, 0, 0, 0, 0, 0, 0, 0, 0), -- Teniente McBride
(175963, 1, 176591, 0, 0, 0, 0, 0, 0, 0, 0), -- Serafina Von
(173022, 1, 157585, 0, 0, 0, 0, 0, 0, 0, 0), -- Enceladus
(175998, 1, 178918, 0, 0, 176724, 0, 0, 0, 0, 0), -- Elspeth Larink
(164128, 1, 176607, 0, 0, 0, 0, 0, 0, 0, 0); -- Mefiles el Leal

UPDATE `creature_equip_template` SET `ItemID1`=176593, `ItemID2`=0, `ItemID3`=176576 WHERE (`CreatureID`=157671 AND `ID`=2); -- Guardia de espadas supremo
UPDATE `creature_equip_template` SET `ItemID1`=174217 WHERE (`CreatureID`=167641 AND `ID`=1); -- Cortador Fin
UPDATE `creature_equip_template` SET `ItemID2`=50252 WHERE (`CreatureID`=120415 AND `ID`=1); -- Alto señor Darion Mograine
UPDATE `creature_equip_template` SET `ItemID1`=163831, `ItemID2`=163832 WHERE (`CreatureID`=120422 AND `ID`=1); -- Lady Liadrin
UPDATE `creature_equip_template` SET `ItemID2`=25095, `ItemID3`=0 WHERE (`CreatureID`=106516 AND `ID`=1); -- Astrólogo empíreo
UPDATE `creature_equip_template` SET `ItemID2`=95495, `ItemID3`=0 WHERE (`CreatureID`=89668 AND `ID`=1); -- Estudiante ahogado
UPDATE `creature_equip_template` SET `ItemID2`=95495, `ItemID3`=34347 WHERE (`CreatureID`=89667 AND `ID`=1); -- Estudiante ahogado
UPDATE `creature_equip_template` SET `ItemID2`=95495, `ItemID3`=34347 WHERE (`CreatureID`=89666 AND `ID`=1); -- Estudiante ahogado
UPDATE `creature_equip_template` SET `ItemID2`=2716, `ItemID3`=0 WHERE (`CreatureID`=89341 AND `ID`=1); -- Magister Garuhod
UPDATE `creature_equip_template` SET `ItemID2`=12863, `ItemID3`=0 WHERE (`CreatureID`=109372 AND `ID`=1); -- Nalysse Albapena
UPDATE `creature_equip_template` SET `ItemID2`=120289, `ItemID3`=0 WHERE (`CreatureID`=88798 AND `ID`=1); -- Lady Irisse
UPDATE `creature_equip_template` SET `ItemID2`=118201, `ItemID3`=0 WHERE (`CreatureID`=88782 AND `ID`=1); -- Vigía de la noche de Nar'thalas
UPDATE `creature_equip_template` SET `ItemID1`=5289, `ItemID2`=0 WHERE (`CreatureID`=3296 AND `ID`=1); -- Bruto de Orgrimmar

DELETE FROM `gossip_menu` WHERE (`MenuId`=26226 AND `TextId`=40493) OR (`MenuId`=24779 AND `TextId`=39009) OR (`MenuId`=24825 AND `TextId`=39092) OR (`MenuId`=26421 AND `TextId`=41905) OR (`MenuId`=24833 AND `TextId`=39106) OR (`MenuId`=24826 AND `TextId`=39093) OR (`MenuId`=24707 AND `TextId`=38846) OR (`MenuId`=18887 AND `TextId`=27523);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26226, 40493, 38134), -- 161909 (Arkadia Moa)
(24779, 39009, 38134), -- 159689 (Sobrestante Kalvaros)
(24825, 39092, 38134), -- 159827 (Desguazadora Minoire)
(26421, 41905, 38134), -- 166640 (Au'larrynar)
(24833, 39106, 38134), -- 159696 (Rencissa, la Dínamo)
(24826, 39093, 38134), -- 159824 (Gunn Tragahuesos)
(24707, 38846, 38134), -- 157313 (Cyrlix el Malhablado)
(18887, 27523, 38134); -- 98519 (Da-Nel iniciado)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24706 AND `TextId`=38845); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24706 AND `TextId`=38845); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24706 AND `TextId`=38845); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24706 AND `TextId`=38845); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=24706 AND `TextId`=38845); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25330 AND `TextId`=39953); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (26226,24779,26421,24833,24825,24826)) OR (`OptionIndex`=2 AND `MenuId`=24825) OR (`OptionIndex`=1 AND `MenuId` IN (24825,24833));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(26226, 0, 32, 'Enséñame el Sagrario.', 0, 38134),
(24779, 0, 0, '¿Qué es el Concurso de Conquista?', 0, 38134),
(24825, 2, 0, '¿Esto no es trampa?', 0, 38134),
(24825, 1, 0, 'Estos son los mejoradores que querías.', 0, 38134),
(26421, 0, 1, 'Deja que eche un vistazo a tus mercancías.', 0, 38134),
(24833, 1, 0, 'Toma. Es la roca más grande que pude encontrar.', 0, 38134),
(24833, 0, 0, '¿Necesitas algo?', 0, 38134),
(24825, 0, 0, '¿Necesitas algo?', 0, 38134),
(24826, 0, 0, '¿Necesitas algo?', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=24706 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(24706, 0, 24707, 0);




UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161905; -- Oseadora Heirmir
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175394; -- Ja'red Haze
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=34816 WHERE `entry`=163224; -- Arena - Bunny
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=172656; -- Acechador del centro de la arena
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=163030; -- Contendiente de la arena
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166568; -- Hellinka
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166570; -- Avrilla Angar
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161733; -- Anzio, el Infalible
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175393; -- Eli'ot Roush
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161697; -- Fogonero Marahueso
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161696; -- Acerón Wilhelm
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=166567; -- Mímico
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=166565; -- Zandara
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=169697; -- Acerino Obernolte
UPDATE `creature_template` SET `gossip_menu_id`=6944, `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157540; -- Guardián alado Alamar
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161712; -- Nana Gorrorojo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170542; -- Duelistas veteranos
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161702; -- Slumbar Valorum
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3228, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=173003; -- Nalcorn Talsen
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166420; -- Varissa Stubin
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170496; -- Shanir Cortavenas
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `speed_walk`=0.639999985694885253, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=164997; -- Pellizcador de cadáveres
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=163032; -- Contendiente de la arena
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=2576, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=158071; -- Animado descerebrado
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=160256; -- Desguazadora Minoire
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=4196352, `unit_flags3`=1, `HoverHeight`=15 WHERE `entry`=172608; -- Mortisombra de Xantuth
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=1073743872, `unit_flags3`=1, `HoverHeight`=15 WHERE `entry`=172567; -- Mortisombra de Xantuth
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=4196352, `unit_flags3`=1, `HoverHeight`=15 WHERE `entry`=172591; -- Mortisombra de Xantuth
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=166226; -- Contendiente de la arena
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161599; -- Esclerosis burbujeante
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3172, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=162813; -- Aprendiz de la arena
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=162797; -- Cicatriz
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=6293504 WHERE `entry`=162816; -- Generic Bunny
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=163084; -- Examinadora Sahaari
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161597; -- Baba arrasadora
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=166331; -- Zo'umlo
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166321; -- Proveedor de especímenes
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=14, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=166531; -- Señora Dyrax
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=166545; -- Instructor Erix
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=159833; -- So'narynar
UPDATE `creature_template` SET `gossip_menu_id`=26421, `minlevel`=55, `maxlevel`=55, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=166640; -- Au'larrynar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166564; -- Aprendiz incansable
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166540; -- Aprendiz incansable
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=163043; -- Espectadora de la arena
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=161585; -- Huesos
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=163019; -- Gran maestro Vole
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161559; -- Louison
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=161757; -- Contendiente de la arena
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166253; -- Gran maestro Vole
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200, `VehicleId`=7132 WHERE `entry`=162899; -- Gran maestro Vole
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `dynamicflags`=4 WHERE `entry`=162875; -- Devmorta
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2099200 WHERE `entry`=166421; -- Alaflagelada entrenado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175392; -- Trampero Hickman
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=163083; -- Evaluador Malus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166400; -- Aprendiz incansable
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=33556480 WHERE `entry`=164507; -- Espectador de la arena
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166424; -- Obrero de la Arena
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161710; -- Marcel Mullby
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=159830; -- Au'narim
UPDATE `creature_template` SET `gossip_menu_id`=24825, `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=159827; -- Desguazadora Minoire
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2952, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=165473; -- Colmisangre alfa
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=166562; -- Talzedo
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=159828; -- Fan de Desguazadora
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=1500, `unit_flags`=32768, `unit_flags2`=4196352, `HoverHeight`=15 WHERE `entry`=162872; -- Xantuth la Contagiada
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=166552; -- Jessana
UPDATE `creature_template` SET `gossip_menu_id`=24826, `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=159824; -- Gunn Tragahuesos
UPDATE `creature_template` SET `gossip_menu_id`=24779, `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=159689; -- Sobrestante Kalvaros
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=159825; -- Fan de Tragahuesos
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=164492; -- Espectador de la arena
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=163041; -- Prospector de la arena
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=159822; -- Fan de Dínamo
UPDATE `creature_template` SET `gossip_menu_id`=24833, `minlevel`=60, `maxlevel`=60, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=159696; -- Rencissa, la Dínamo
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=162588; -- Picartílago
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=164508; -- Espectador de la arena
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=175023; -- Animated Cruor
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=174652; -- Animated Cruor
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=34817, `unit_flags3`=8193 WHERE `entry`=169795; -- Avispa cinérea zombi
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169830; -- Larva parasitaria
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `speed_walk`=0.400000005960464477, `speed_run`=0.457142859697341918, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=162873; -- Azmogal
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=162853; -- Urtz el Irrompible
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=4196352 WHERE `entry`=158642; -- Carne de alma podrida
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=168226; -- Earl el ciego
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2576, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169055; -- Raspamédulas
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912 WHERE `entry`=162257; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2952, `BaseAttackTime`=1818, `unit_flags`=32848, `unit_flags2`=2048 WHERE `entry`=168192; -- Anciano colmisangre
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67110912 WHERE `entry`=162256; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2575, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=67110913, `unit_flags3`=8193 WHERE `entry`=168196; -- Plaga virulenta
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173200; -- Bleak Skitterer
UPDATE `creature_template` SET `faction`=190, `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=176024; -- Crawbat
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169751; -- Avispa cinérea
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=162259; -- Cría de chillavientos
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=174653; -- Larva purulenta
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=34816 WHERE `entry`=170191; -- Espora fibrosa
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=1713, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=159856; -- Peste virulenta
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=176023; -- Crawbat
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=1711, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=168216; -- Ancestro chillavientos
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=1711, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=162258; -- Chillavientos voraz
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480, `VehicleId`=6926 WHERE `entry`=160253; -- Babosa pestenato
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=164759; -- Sombrina floreciente
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=164758; -- Sombrina agitado
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=537133120, `unit_flags2`=2048 WHERE `entry`=167948; -- Monstruosidad infecciosa
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=58, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171599; -- Bunny - Ooze Delivery Spot
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165014; -- Plaga animada
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2753, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=171415; -- Moco burbujeante
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=158406; -- Aversión
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167358; -- Gelatina cáustica
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=2753, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165027; -- Extracto ardiente
UPDATE `creature_template` SET `gossip_menu_id`=25330, `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=157945; -- Maestro del hervor Yetch
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=171217; -- Vida reconstruida
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=171129; -- Mocoso
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161380; -- Mezclador de plagas
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=165052; -- Maestro de viales Lurgy
UPDATE `creature_template` SET `gossip_menu_id`=24706, `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=157313; -- Cyrlix el Malhablado
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=171130; -- Experimento degenerativo
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=172141; -- Mortimer, el loco
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=161841; -- Pandemis
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=171133; -- Investigador de la peste
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166579; -- Cecil Chiobrix
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=171135; -- Sully
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `speed_run`=0.357142865657806396, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=165015; -- Pegote colosal
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157515; -- Vradira Furioso
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=165049; -- Judas Sneap
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3238, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165034; -- Vigía de Alto de la Plaga
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=165032; -- Pestilento vil
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=69732352, `unit_flags3`=1 WHERE `entry`=157226; -- Poza de monstruosidades mezcladas
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=171112; -- Sobreviviente limpiapiel
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=167923; -- Resto enfermo
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=94, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=160060; -- Desechos de plaga
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175391; -- Luke Herczeg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161677; -- Plimpton
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=162093; -- Kurly
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167639; -- Desollador Coxis
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161675; -- Iva Gamey
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161673; -- Elsie Mullby
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=164797; -- Minni
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167638; -- Berk la Pútrida
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167637; -- Tai Wol'Kur
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167636; -- Winslow Swan
UPDATE `creature_template` SET `maxlevel`=1, `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=93008; -- Gusano de cadáver
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=175144; -- Oso bebé
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=161679; -- Invocador espectral
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175398; -- Mantaraganak
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161668; -- Invocador Gerard
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167640; -- Capitán John Shin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=174002; -- Sargento Krashj
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=165335; -- Recluta leal
UPDATE `creature_template` SET `npcflag`=1073741824, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=175021; -- Pulsating Maggot
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=168045; -- Oyne Almanato
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=3163, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=67110913, `unit_flags3`=8193 WHERE `entry`=169634; -- Veterano almapartida
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161676; -- Jason Briggs
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167641; -- Cortador Fin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167642; -- Lillian Pastor
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157514; -- Guardián alado Buurkin
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3159, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=161890; -- Carroñero carne sajada
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3159, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=161881; -- Espinacero herido
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=1073743872, `unit_flags3`=1, `HoverHeight`=15 WHERE `entry`=172609; -- Mortisombra de Xantuth
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `RangeAttackTime`=0 WHERE `entry`=97515; -- Sorrow
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=97507; -- Disidra Stormglory
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136796; -- Crustájeo contrabandeado
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126009; -- Maestro de embarcadero Cobo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126153; -- Cultista carmesí
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126161; -- Matrona maldita de sangre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126148; -- Médica bruja Jala
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `unit_flags`=33536 WHERE `entry`=148086; -- Skullsplitter Thug
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `unit_flags`=33536 WHERE `entry`=148080; -- Olly
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138363; -- Jakub Fieltrocálido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142157; -- Pagador Dentirrisa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143595; -- Peón del muelle
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129394; -- Bribón callejero intrigante
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=129266; -- Buba
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=129267; -- Kiki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133207; -- Rufián "mojo malo"
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2900, `RangeAttackTime`=0 WHERE `entry`=133208; -- El tiburón blanco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133206; -- "Rompecolmillos" Yana
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129264; -- Chaka el Ancestral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33587968 WHERE `entry`=133212; -- Comerciante Munengo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129279; -- Caparazón duro tortollano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128909; -- Shalo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129262; -- Keto
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=142766; -- Simi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125996; -- Sr. Sonrisa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120949; -- Discípulo de Nalorakk
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142776; -- Wahla
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125311; -- Comerciante Nog
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131350; -- Custodio Patiko
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142781; -- Ro Ro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134344; -- Foliosagaz Nola
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142757; -- Hansa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=1, `RangeAttackTime`=0 WHERE `entry`=144384; -- Cronista Shoopa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120946; -- Discípulo de Akil'zon
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2968, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134346; -- Toki
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131379; -- Sacerdotisa Vulja
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129929; -- Buscador tortollano
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143156; -- Exzhal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143136; -- Maywiki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131351; -- "Príncipe Nastykhan"
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125312; -- Foliosagaz Rooka
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120951; -- Discípula de Halazzi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120950; -- Discípulo de Jan'alai
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143138; -- Rin'wosho el Comerciante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142983; -- Swizzle Palanqueta
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=148924; -- Proveedora Mukra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142158; -- Intendente Rauka
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142973; -- Mai-Lu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=7, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=131752; -- Mesa de guerra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142969; -- Logarr
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2958, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138949; -- Throk
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143396; -- Bruto de la Horda
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `faction`=1735, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143388; -- Druza Colmillo Abisal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143614; -- Bruto de la Horda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142981; -- Merill Tumbarroja
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142977; -- Meredith Swane
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `unit_flags`=33536 WHERE `entry`=151162; -- Atikka "As" Cazalunas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142975; -- Costurera Vessa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142970; -- Kuma Pezuña Larga
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143615; -- Bruto de la Horda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=142992; -- Uma'wi
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147974; -- Guardia de la muerte de los Renegados
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=130196; -- Nalu'kana
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147975; -- Renegado de la Guardia de añublo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=120843; -- Matón amani
UPDATE `creature_template` SET `npcflag`=140737488355329 WHERE `entry`=143967; -- Mapa de expediciones
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=768 WHERE `entry`=134049; -- Huevo extraño
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=142404; -- Acechadora Mojica
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2964, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=154465; -- Guardián terráneo
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=120740; -- King Rastakhan
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135775; -- Mapa de exploración
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=131287; -- Natal'hakata
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=96698; -- Blood Knight
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=96708; -- Blood Knight
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=93527; -- Timothy Jones
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=92195; -- Profesor Palin
UPDATE `creature_template` SET `npcflag`=16 WHERE `entry`=151827; -- Lianna Tai
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=92183; -- Alard Schmied
UPDATE `creature_template` SET `npcflag`=4243 WHERE `entry`=106655; -- Arcanomántico Vridiel
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=92464; -- Kuhuine Zancada Afable
UPDATE `creature_template` SET `npcflag`=19 WHERE `entry`=93189; -- Mamá Diggs
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=32454; -- Ciudadano de Dalaran
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120413; -- Rensar Granzuña
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=114946; -- Muninn
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120412; -- Clarividente Nobundo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120415; -- Alto señor Darion Mograine
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120422; -- Lady Liadrin
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120418; -- Havi
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33600 WHERE `entry`=120424; -- Alonsus Faol
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120421; -- Ritssyn Llamafruncida
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33600 WHERE `entry`=120420; -- Ponshu Cuerpo Férreo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120423; -- Emmarel Velasombra
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120417; -- Meryl Tormenta Vil
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120416; -- Lord Jorach Ravenholdt
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=120419; -- Kor'vas Espinosangriento
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=39859; -- Dave's Industrial Light and Magic Bunny (Large)(Sessile)
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=113127; -- Garracielo alarrisco
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=115072; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=113122; -- Emplumado de los acantilados de Suramar
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115071; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115074; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=110899; -- Cerrojo vil - Canalizador izquierdo
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=110948; -- Cerrojo vil - Objetivo izquierdo
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115003; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115002; -- Maribeth
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=113209; -- Cerrojo vil - Canalizador derecho
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=113210; -- Cerrojo vil - Objetivo derecho
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=73828; -- Flamering Moth
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=49568; -- Víbora de ceniza
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115014; -- Diablillo Almavil
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115073; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115000; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0, `unit_flags`=33024 WHERE `entry`=114892; -- Withering Civilian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0, `unit_flags`=33024 WHERE `entry`=114889; -- Shal'dorei Civilian
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0, `unit_flags`=33024 WHERE `entry`=114888; -- Civiles shal'dorei
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=115075; -- Civil Shal'dorei condenado
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=114904; -- Soul Engine Jailer
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=116659; -- Transbordador almavil
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=115012; -- Conspirador vilificado
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=116411; -- Portal de máquina de almas
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=111414; -- Mero Escama de Sal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=111377; -- Caracol de concha abocinada
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106772; -- Libro exótico
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=107027; -- Conejito adorable
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107241; -- Kill Credit: Commander
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=2129984 WHERE `entry`=106583; -- Arkethrax
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106798; -- Nora Fuego negro
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=82347; -- Persecutor
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106356; -- Conjurador empíreo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106516; -- Astrólogo empíreo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106514; -- Discípulo empíreo
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=89940; -- Azurewing Scalewarden
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=92447; -- Engendro del caos
UPDATE `creature_template` SET `minlevel`=45, `RangeAttackTime`=0 WHERE `entry`=92630; -- Aterracielos Colminferno
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=92450; -- Eredar Tejefallas
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107245; -- Marius Aterravil
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107244; -- Tehd Zapatero
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=91485; -- Araña vil
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=102456; -- Fel-Tainted Squirrel
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=92445; -- Invasor Guardia vil
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=91629; -- Agente Illidari
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=111624; -- Adepto Aladía
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=113833; -- Murciélago vil Illidari
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107407; -- Odio veloz
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=104792; -- Diablillo encarcelado
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=106920; -- Feathered Prowler
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89386; -- Hipogrifo alarrisco
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=90696; -- Prole de alarrisco
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=91267; -- Zorrito de Llothien
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=90694; -- Osezno de Azsuna
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=97294; -- Olivetail Hare
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=91717; -- Águila lomiverde azsuniana
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=91265; -- Zorro de Llothien
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=90134; -- Llothien Grizzly
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=91308; -- Equino trotasol
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=91269; -- Búho de Llothien
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=99598; -- Matriarca basilisco Colahacha
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=89390; -- Liebre cola de olivo
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=62177; -- Forest Moth
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=90901; -- Pridelord Meowl
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=49842; -- Polilla del bosque
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=90313; -- Llothien Prowler
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=91430; -- Alma en pena llorona
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=91431; -- Estudiante espectral
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107439; -- Alimentador de bestias Ojosalado
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=91128; -- Basilisco de laguna
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=93627; -- Renacuajo Ojosalado
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89849; -- Andellis
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=89653; -- Gangamesh
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89660; -- Thyrillion
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=108680; -- Gaviota de Mareaqua
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109377; -- Filrich
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=64352; -- Rapana Whelk
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=89652; -- Garza de bajío
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89015; -- Cangrejo playero de Azsuna
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89661; -- Instructora Nidriel
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=0, `RangeAttackTime`=0, `unit_flags3`=512 WHERE `entry`=88797; -- Anciano Aldryth
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107334; -- Sythorne
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89668; -- Estudiante ahogado
UPDATE `creature_template` SET `unit_flags`=33587200 WHERE `entry`=17213; -- Retama
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=88970; -- Drowned Nightwatcher
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89667; -- Estudiante ahogado
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=108163; -- Cangrejo caparaescoria
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89666; -- Estudiante ahogado
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=88086; -- Hatecoil Riptail
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=89380; -- Escolopácido de la costa
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88094; -- Skrog de mar
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107367; -- Esclavizador Odio Espiral
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88100; -- Corredor de la costa Ojosalado
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=88101; -- Salteye Tide-Shaman
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=88099; -- Salteye Hookblade
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=113137; -- Tidepool Eel
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109174; -- Guardia de lanza Ojosalado
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=64806; -- Rapana Whelk
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0 WHERE `entry`=110826; -- Coastal Sandpiper
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88888; -- Tosco centinela
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98964; -- Celea
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109154; -- Coloso Odio Espiral
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=4000, `RangeAttackTime`=0 WHERE `entry`=88090; -- Comandante sondeador Zarrin
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0 WHERE `entry`=89014; -- Garza de la pradera
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88783; -- Magister de Nar'thalas
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89341; -- Magister Garuhod
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88115; -- Príncipe Farondis
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109372; -- Nalysse Albapena
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109368; -- Thordal
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `RangeAttackTime`=0, `unit_flags3`=1 WHERE `entry`=88084; -- Hatecoil Raider
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98381; -- Merrus Viento del Alba
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88798; -- Lady Irisse
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=105040; -- Garley Montaluz
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=105039; -- Examinador Andoren Alzalba
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=109124; -- Rana tragacharco
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107376; -- Veridis Fallon
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=107139; -- Encantadora Ilanya
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89696; -- Lomocuero cornudo
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89634; -- Ciudadano de Nar'thalas
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=106873; -- Fuente de energía arcana
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=88782; -- Vigía de la noche de Nar'thalas
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_walk`=1, `RangeAttackTime`=0, `unit_flags`=0 WHERE `entry`=93619; -- Moledor infernal
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=89680; -- Asaltante Odio Espiral
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0 WHERE `entry`=98159; -- Alynblaze
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `RangeAttackTime`=0, `unit_flags3`=1 WHERE `entry`=88089; -- Encantadora Odio Espiral
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=28960; -- Totally Generic Bunny (JSB)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1735, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=175518; -- Aventurero de las Tierras de las Sombras
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `npcflag`=1 WHERE `entry`=74228; -- Rebanacabezas Lanza Negra
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=149626; -- Mago de batalla de vanguardia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=149616; -- Emisaria del Kirin Tor
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=149523; -- Zan'chi
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=149270; -- Mago guardián de Orgrimmar
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=3296; -- Bruto de Orgrimmar
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=66854; -- Iniciado Chuang
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=66260; -- Maestro Cenit
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=66256; -- Maestra Cheng
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=66360; -- Maestro Brandom
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags`=2147483648, `unit_flags2`=2048 WHERE `entry`=66257; -- Maestro Tsang
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=66947; -- Alumno monje
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=66946; -- Poste de equilibrio
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=67021; -- Alumno monje
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=1779, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=128106; -- Zidormi
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=67066; -- Alumno monje
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=35, `npcflag`=3, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=64975; -- Ponshu Cuerpo Férreo
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags3`=1 WHERE `entry`=66969; -- Saco de entrenamiento
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2048 WHERE `entry`=67095; -- Maestra Yeoh
UPDATE `creature_template` SET `minlevel`=35, `RangeAttackTime`=0, `unit_flags`=0, `unit_flags2`=2048 WHERE `entry`=67092; -- Maestro Chow
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167743; -- Vassili Tirolibre
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=170971; -- Tauralus listo para la batalla
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=3000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=167273; -- Tiradora certera de placas óseas
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=164833; -- Tauralus de manada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167737; -- Maestra de asedio Hekk
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=160424; -- Creasedios veterano
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3238, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160415; -- Centinela de placas óseas
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=3000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=167747; -- Aliya Jubón
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167355; -- Pulsating Maggot
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=33556480 WHERE `entry`=167649; -- Kresto Piromuerte
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=174488; -- Defensor inquebrantable
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=174491; -- Probador de hierro
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=131072, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=174484; -- Campeón inamovible
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=131584, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=174487; -- Veterano competente
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=165433; -- Erak Ariaacero
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=165434; -- Evaluador Simmons
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=165432; -- Aprendiz Thayer
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=174492; -- Edrich Adebo
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=131072, `unit_flags3`=1 WHERE `entry`=174489; -- Guía nigromántico
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=165435; -- Stanley vistafilada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167741; -- Morris Marcarroja
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=3172, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=157671; -- Guardia de espadas supremo
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167354; -- Rachis retorcido
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=34816 WHERE `entry`=156558; -- Generic - Empty Bunny
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=34816 WHERE `entry`=172680; -- Visión del Primus
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=165321; -- Merick Feldcicatriz
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `speed_walk`=4, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2097152, `unit_flags3`=1 WHERE `entry`=157843; -- Visectus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=175371; -- Mortis Elfsen
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=175370; -- Gwor, el Odioso
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175311; -- Destripador Araya
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167210; -- Tabulador Killham
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=128, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175310; -- Mellisa Fate
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=175312; -- Taiya Tacere
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=69732352, `unit_flags3`=1 WHERE `entry`=157803; -- Invocación de Visectus
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165431; -- Kiara Coil
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161985; -- Baronesa Vashj
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `npcflag`=4294967296, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=175314; -- Tripazón
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161988; -- Alexandros Mograine
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=167748; -- Osbourne Black
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165347; -- Alvira Mortaja
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173000; -- Madeleine Roux
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160418; -- Moc
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160417; -- Plagoso
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=160419; -- Limo
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `faction`=3171, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=164915; -- Morticolmillo
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=164221; -- Kevin
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165350; -- Lyra Granizormenta
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `npcflag`=128, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=172176; -- Tsu Zettai
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=158339; -- Sargento Romark
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161907; -- Baronesa Draka
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161904; -- Maestro de plagas Marileth
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=165017; -- Inventor de plagas
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167205; -- Yondare Maleficio
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=58, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167208; -- Gran maestro Vole
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167201; -- Gatherer Zaya
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=33556480 WHERE `entry`=167645; -- Jericó Murallada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=172173; -- Intérprete de disputas
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175791; -- Felicia Noche
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=174505; -- Proveedor supremo
UPDATE `creature_template` SET `gossip_menu_id`=26226, `minlevel`=60, `maxlevel`=60, `faction`=3172, `npcflag`=2199023255555, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=161909; -- Arkadia Moa
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166423; -- Alaflagelada entrenado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=168685; -- Teniente McBride
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167209; -- Niall Kugal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167207; -- Sabbath Sombranoche
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175963; -- Serafina Von
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3171, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=173022; -- Enceladus
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=3171, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=161994; -- Tapani Nightwish
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3172, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=175998; -- Elspeth Larink
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_run`=1.357142806053161621, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=164667; -- Prime Shieldguard
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=174650; -- Desperdicios burbujeantes
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=164128; -- Mefiles el Leal
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169992; -- Rencor imperfecto
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=164713; -- Fungio aterrado
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167949; -- Sobreviviente apestado
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169129; -- Murciélago putrepolvo
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167356; -- Excavador limoso
UPDATE `creature_template` SET `maxlevel`=1, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167359; -- Espora sobrecrecida
UPDATE `creature_template` SET `minlevel`=54, `maxlevel`=54, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=160048; -- Resto empapado de peste
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167935; -- Gota contagiosa
UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=170456; -- Chillavientos enfermo

DELETE FROM `quest_template` WHERE `ID` IN (12103 /*-Unknown-*/, 62391 /*-Unknown-*/, 62388 /*-Unknown-*/, 62161 /*-Unknown-*/, 60533 /*-Unknown-*/, 61791 /*-Unknown-*/, 61870 /*-Unknown-*/, 61879 /*-Unknown-*/, 60475 /*-Unknown-*/, 59581 /*-Unknown-*/, 62631 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(12103, 2, 0, 339, -419, 107, 0, 0, 5, 1, 202200, 5, 1, 525, 210839, 0, 0, 0, 0, 1, 0, 7340032, 35660096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 0, 0, 'Antes de la tormenta', 'Ayuda al Gran maestro Cenit en el Pico de la Serenidad.', '¡$n! ¡He estado buscándote por toda esta ciudad extraña!$b$bEl Gran maestro Cenit ordenó que todos los monjes superiores regresaran al Pico de la Serenidad tan pronto como fuera posible. Eso también te incluye, claro.$b$bTe apuesto toda una semana de cerveza que tiene que ver con el ataque a la Costa Quebrada del que tanto he escuchado.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(62391, 2, 0, 837, 11462, 0, 0, 58833, 1, 1, 25740, 1, 1, 7700, 0, 0, 0, 0, 0, 1, 0, 37748744, 2105408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Maldraxxus en marcha', 'Aumenta tu reconocimiento.', 'Será difícil llegar a Kel\'Thuzad mientras esté en su necrópolis.\n\nPuedes irte. Nos llevará tiempo reunir un ejército que pueda penetrar sus defensas.', '', 'Habla con Draka en el Trono del Primus.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(62388, 2, 0, 837, -576, 0, 0, 0, 1, 1, 25740, 1, 1, 7700, 0, 0, 0, 0, 0, 1, 0, 37748744, 2105408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Casa de Rituales', 'Aumenta tu reconocimiento.', 'Detrás de esta guerra están los ritualistas. Cada acto de traición ha sido producto de sus órdenes.\n\nLa fuerza de las armas no es suficiente para derrotar su hechicería. Para lograr la victoria, debemos saber lo que planean.\n\nSigue aumentando nuestras fuerzas. Buscaré el modo de infiltrarnos en la Casa de Rituales.', '', 'Habla con Draka en el Trono del Primus.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(62161, 2, 0, 837, -576, 0, 0, 0, 1, 1, 25740, 1, 1, 7700, 0, 0, 0, 0, 0, 1, 0, 4194312, 2105408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Sangre de hueso', 'Aumenta tu reconocimiento.', 'Lo que más quiero es ir a Revendreth de inmediato... pero parece que ellos deben enfrentar sus propios desafíos.\n\nTodos saben de la marca que dejamos en Bastión. No creo que los venthyr estén ansiosos de darnos la bienvenida en su reino.\n\nUna vez más, necesitamos tu ayuda. Por tu reputación en las Tierras de las Sombras, te has ganado la confianza de muchos. Ahora necesitamos la confianza de Revendreth.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(60533, 3, 0, 2060, 11510, 136, 0, 0, 5, 1, 0, 0, 0, 0, 342092, 0, 0, 0, 0, 1, 0, 36241664, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 20000, 0, 0, 0, 0, 0, 7100, 0, 18446744073709551615, 1626, 8, 0, 0, 'Terrores en Tirna Scithe', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(61791, 3, 0, 837, 10534, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344547, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2407, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1593, 8, 0, 0, 'Compañeros leales de Thenia', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(61870, 3, 0, 837, 11462, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344573, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1622, 8, 0, 0, 'Experimento fallido', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(61879, 3, 0, 837, 10413, 115, 0, 0, 5, 1, 0, 0, 0, 0, 344554, 0, 0, 0, 0, 1, 0, 3735808, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1593, 8, 0, 0, 'Caerán cenizas', 'Derrota a Grixis Pequeñín en un duelo de mascotas.', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(60475, 3, 0, 837, 11510, 109, 0, 0, 5, 1, 0, 0, 0, 0, 327972, 0, 0, 0, 0, 1, 0, 37290240, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 7030, 0, 18446744073709551615, 1579, 8, 0, 0, 'Un taller soñado', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(59581, 3, 0, 837, 10413, 109, 0, 0, 5, 1, 0, 0, 0, 0, 344554, 0, 0, 0, 0, 0, 0, 36241664, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 6836, 0, 18446744073709551615, 1575, 8, 0, 0, 'La fuerza de Caída del Pecado', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134), -- -Unknown-
(62631, 2, 0, 2060, -409, 0, 0, 0, 0, 1, 0, 0, 1, 0, 193103, 0, 0, 0, 0, 1, 0, 35684360, 2097216, 2, 0, 0, 0, 0, 0, 184315, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1594, 8, 0, 0, 'El mundo espera', 'Completa 20 misiones de mundo en las Tierras de las Sombras.', 'Cuando la señal del emisario brilla en el cielo nocturno, las estrellas fortalecen los vínculos existentes y forjan nuevos. La amistad no se gana fácilmente y las acciones prueban la lealtad, pero es más fácil ganar la confianza estos días. Aventúrate en estas tierras y ayuda donde puedas para demostrar tu valor.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134); -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (280328 /*280328*/, 280801 /*280801*/, 262289 /*262289*/, 407695 /*407695*/, 407688 /*407688*/, 407313 /*407313*/, 405877 /*405877*/, 405876 /*405876*/, 405875 /*405875*/, 405874 /*405874*/, 405873 /*405873*/, 405872 /*405872*/, 405871 /*405871*/, 405870 /*405870*/, 405869 /*405869*/, 405868 /*405868*/, 405867 /*405867*/, 406713 /*406713*/, 406768 /*406768*/, 406790 /*406790*/, 398341 /*398341*/, 398338 /*398338*/, 409240 /*409240*/, 396527 /*396527*/, 396572 /*396572*/, 396521 /*396521*/, 396520 /*396520*/, 396535 /*396535*/, 396519 /*396519*/, 408081 /*408081*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(280328, 12103, 0, 3, 1, 98353, 1, 2, 0, 0, 'Completa la gesta \"El fin de la serenidad\"', 38134), -- 280328
(280801, 12103, 0, 2, 2, 97778, 1, 2, 0, 0, 'Habla con el Maestro Cenit', 38134), -- 280801
(262289, 12103, 0, 1, 0, 98514, 1, 0, 0, 0, 'Usa Peregrinaje zen o el portal de Dalaran para ir a Pico de la Serenidad', 38134), -- 262289
(407695, 62391, 14, 0, 1, 87458, 1, 0, 0, 0, 'Alcanza el nivel 22 de reconocimiento', 38134), -- 407695
(407688, 62388, 14, 0, 0, 87456, 1, 0, 0, 0, 'Alcanza el nivel 20 de reconocimiento', 38134), -- 407688
(407313, 62161, 14, 0, 0, 87317, 1, 0, 0, 0, 'Alcanza el nivel 17 de reconocimiento', 38134), -- 407313
(405877, 60533, 2, 10, 9, 355797, 50, 92, 0, 2, 'Barril', 38134), -- 405877
(405876, 60533, 2, 9, 8, 355805, 50, 92, 0, 2, 'Champiñón - Purificar', 38134), -- 405876
(405875, 60533, 2, 8, 7, 355804, 50, 92, 0, 2, 'Champiñón - Fue', 38134), -- 405875
(405874, 60533, 2, 7, 6, 355803, 50, 92, 0, 2, 'Champiñón - Agi', 38134), -- 405874
(405873, 60533, 2, 6, 5, 355795, 50, 92, 0, 2, 'Champiñón - Int', 38134), -- 405873
(405872, 60533, 2, 5, 4, 355796, 50, 92, 0, 2, 'Saco de gorm', 38134), -- 405872
(405871, 60533, 0, 4, 3, 163987, 100, 92, 0, 1, 'T1 Credit', 38134), -- 405871
(405870, 60533, 0, 3, 2, 166499, 34, 92, 0, 3, 'T2 Credit', 38134), -- 405870
(405869, 60533, 0, 2, 1, 163991, 17, 92, 0, 6, 'T3 Credit', 38134), -- 405869
(405868, 60533, 0, 1, 0, 172082, 10, 92, 0, 10, 'T4 Credit', 38134), -- 405868
(405867, 60533, 15, 0, -1, 0, 1, 0, 0, 0, 'Tirna Scithe purificada', 38134), -- 405867
(406713, 61791, 11, 0, 0, 173129, 1, 0, 0, 0, 'Derrota a Thenia en un duelo de mascotas.', 38134), -- 406713
(406768, 61870, 12, 0, 0, 2978, 1, 0, 0, 0, 'Derrota a Bocaglotón en un duelo de mascotas', 38134), -- 406768
(406790, 61879, 12, 0, 0, 2979, 1, 0, 0, 0, 'Derrota a Abrasión en un duelo de mascotas', 38134), -- 406790
(398341, 60475, 0, 1, 1, 168568, 1, 2, 0, 0, 'Entrega los suministros', 38134), -- 398341
(398338, 60475, 1, 0, 0, 178876, 10, 0, 1, 0, '', 38134), -- 398338
(409240, 59581, 0, 6, 5, 161211, 34, 92, 0, 3, '', 38134), -- 409240
(396527, 59581, 2, 5, 2, 348632, 10, 92, 0, 10, '', 38134), -- 396527
(396572, 59581, 2, 4, 4, 348639, 17, 92, 0, 6, '', 38134), -- 396572
(396521, 59581, 2, 3, 1, 348628, 20, 92, 0, 5, '', 38134), -- 396521
(396520, 59581, 0, 2, 0, 161191, 25, 92, 0, 4, '', 38134), -- 396520
(396535, 59581, 3, 1, 3, 161258, 34, 92, 0, 3, '', 38134), -- 396535
(396519, 59581, 15, 0, -1, 0, 1, 0, 0, 0, 'Distrito Cáliz perturbado', 38134), -- 396519
(408081, 62631, 14, 0, 0, 89158, 1, 0, 0, 0, 'Misiones de mundo completadas', 38134); -- 408081

DELETE FROM `quest_visual_effect` WHERE (`ID`=280801 AND `Index`=0) OR (`ID`=406713 AND `Index`=0) OR (`ID`=406768 AND `Index`=0) OR (`ID`=406790 AND `Index`=0) OR (`ID`=398341 AND `Index` IN (5,4,3,2,1,0));
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(280801, 0, 4195, 38134),
(406713, 0, 15901, 38134),
(406768, 0, 15925, 38134),
(406790, 0, 15932, 38134),
(398341, 5, 15809, 38134),
(398341, 4, 15808, 38134),
(398341, 3, 14901, 38134),
(398341, 2, 14900, 38134),
(398341, 1, 14899, 38134),
(398341, 0, 14790, 38134);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393667 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397180 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393616 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393616 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393611 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393610 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393615 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393609 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=390111 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336460 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335942 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=386940 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=269077 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392616 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335223 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341919 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341919 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341918 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341918 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341914 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341914 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289128 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289129 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=389030 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334143 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335389 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289141 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289131 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333882 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333882 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333880 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338203 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337320 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338752 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387768 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387768 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387768 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387768 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=339034 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=339033 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335301 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335301 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335301 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336031 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336031 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340181 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341833 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336560 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335060 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336552 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393813 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340116 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341812 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341812 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336574 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333023 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334088 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=387766 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332859 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=322746 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341835 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336558 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408831 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396502 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408763 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405128 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405055 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405097 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406141 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=7);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=6);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406244 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406154 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406262 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406258 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406258 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406733 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406868 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407572 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407571 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407591 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393734 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393733 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393733 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393784 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=394456 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407764 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407763 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407762 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=5);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407754 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407753 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404448 AND `Index`=4);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404448 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404448 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404448 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404448 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408847 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407788 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407788 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398287 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398288 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405119 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405119 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397077 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393100 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=393100 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=45727 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=39958 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=31834 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=12);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=11);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=10);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=9);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=8);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=7);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=6);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=5);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=4);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=3);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=2);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=1);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61359 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59556 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=57686 AND `Idx`=0);

DELETE FROM `gameobject_template` WHERE `entry` IN (365670 /*Yunque*/, 365672 /*Forja*/, 365674 /*Forja de runas*/, 365673 /*Yunque*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(365670, 8, 61257, 'Yunque', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Yunque
(365672, 8, 66506, 'Forja', '', '', '', 0.999999761581420898, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Forja
(365674, 8, 61260, 'Forja de runas', '', '', '', 1.484677791595458984, 1552, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Forja de runas
(365673, 8, 61256, 'Yunque', '', '', '', 0.999999761581420898, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- Yunque


DELETE FROM `npc_text` WHERE `ID` IN (41905 /*41905*/, 39106 /*39106*/, 39092 /*39092*/, 39093 /*39093*/, 39009 /*39009*/, 38846 /*38846*/, 27523 /*27523*/, 40493 /*40493*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(41905, 1, 0, 0, 0, 0, 0, 0, 0, 205185, 0, 0, 0, 0, 0, 0, 0, 38134), -- 41905
(39106, 1, 0, 0, 0, 0, 0, 0, 0, 183713, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39106
(39092, 1, 0, 0, 0, 0, 0, 0, 0, 183663, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39092
(39093, 1, 0, 0, 0, 0, 0, 0, 0, 183667, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39093
(39009, 1, 0, 0, 0, 0, 0, 0, 0, 182806, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39009
(38846, 1, 0, 0, 0, 0, 0, 0, 0, 180983, 0, 0, 0, 0, 0, 0, 0, 38134), -- 38846
(27523, 1, 0, 0, 0, 0, 0, 0, 0, 100242, 0, 0, 0, 0, 0, 0, 0, 38134), -- 27523
(40493, 1, 0, 0, 0, 0, 0, 0, 0, 196194, 0, 0, 0, 0, 0, 0, 0, 38134); -- 40493

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=38845; -- 38845
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=39953; -- 39953
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34160; -- 34160

DELETE FROM `world_quest` WHERE `id` IN (51238 /*51238*/, 53042 /*53042*/, 57205 /*57205*/, 56120 /*56120*/, 52459 /*52459*/, 55342 /*55342*/, 60950 /*60950*/, 60533 /*60533*/, 51315 /*51315*/, 61791 /*61791*/, 54545 /*54545*/, 54590 /*54590*/, 58144 /*58144*/, 52115 /*52115*/, 53078 /*53078*/, 51832 /*51832*/, 62258 /*62258*/, 61948 /*61948*/, 59017 /*59017*/, 60739 /*60739*/, 58601 /*58601*/, 54615 /*54615*/, 51114 /*51114*/, 46191 /*46191*/, 59581 /*59581*/, 46184 /*46184*/, 52956 /*52956*/, 61816 /*61816*/, 61870 /*61870*/, 51118 /*51118*/, 50540 /*50540*/, 61520 /*61520*/, 60475 /*60475*/, 59904 /*59904*/, 62451 /*62451*/, 54051 /*54051*/, 52315 /*52315*/, 54614 /*54614*/, 54551 /*54551*/, 61879 /*61879*/, 58605 /*58605*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(51238, 86400, 15146, 1), -- 51238
(53042, 86400, 16028, 1), -- 53042
(57205, 86400, 18291, 1), -- 57205
(56120, 259200, 17719, 1), -- 56120
(52459, 86400, 15759, 1), -- 52459
(55342, 86400, 17280, 1), -- 55342
(60950, 86400, 19551, 1), -- 60950
(60533, 259200, 19337, 1), -- 60533
(51315, 86400, 15174, 1), -- 51315
(61791, 86400, 19944, 1), -- 61791
(54545, 86400, 16874, 1), -- 54545
(54590, 86400, 16889, 1), -- 54590
(58144, 86400, 19065, 1), -- 58144
(52115, 86400, 15631, 1), -- 52115
(53078, 86400, 16039, 1), -- 53078
(51832, 86400, 15472, 2), -- 51832
(62258, 86400, 20060, 2), -- 62258
(61948, 86400, 19977, 1), -- 61948
(59017, 604800, 17933, 2), -- 59017
(60739, 86400, 19444, 1), -- 60739
(58601, 86400, 18289, 2), -- 58601
(54615, 86400, 16908, 1), -- 54615
(51114, 86400, 15087, 1), -- 51114
(46191, 21600, 13103, 1), -- 46191
(59581, 86400, 18964, 1), -- 59581
(46184, 21600, 13096, 1), -- 46184
(52956, 604800, 16007, 2), -- 52956
(61816, 604800, 19923, 2), -- 61816
(61870, 86400, 19957, 1), -- 61870
(51118, 86400, 15091, 1), -- 51118
(50540, 86400, 14871, 1), -- 50540
(61520, 86400, 19828, 1), -- 61520
(60475, 86400, 19344, 2), -- 60475
(59904, 86400, 19148, 2), -- 59904
(62451, 86400, 18974, 2), -- 62451
(54051, 86400, 16574, 1), -- 54051
(52315, 86400, 15740, 1), -- 52315
(54614, 86400, 16910, 1), -- 54614
(54551, 86400, 16877, 1), -- 54551
(61879, 86400, 19960, 1), -- 61879
(58605, 86400, 18432, 1); -- 58605

UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46195; -- 46195
UPDATE `world_quest` SET `variable`=13003 WHERE `id`=46194; -- 46194
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=13097 WHERE `id`=46185; -- 46185