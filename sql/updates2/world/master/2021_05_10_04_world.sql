REPLACE INTO playerchoice (ChoiceId, UiTextureKitId, SoundKitId, Question, HideWarboardHeader, KeepOpenAfterChoice, VerifiedBuild) VALUES
(505, 261, 0, 'Las siguientes misiones son para aventureros de nivel más bajo.', 0, 0, 38134);


REPLACE INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `ResponseIdentifier`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetID`, `UiTextureAtlasElementID`, `SoundKitID`, `GroupID`, `UiTextureKitID`, `Answer`, `Header`, `SubHeader`, `ButtonTooltip`, `Description`, `Confirmation`, `RewardQuestID`, `VerifiedBuild`) VALUES 
(505, 997, 3, 2, 1851141, 0, 0, 0, 0, 0, '0', '', '', 'Viaja a Gorgrond', 'Los orcos Roca Negra son expertos trabajando la mena de Roca Negra para luego convertirla en las armas de artillería y las naves que la Horda de Hierro utiliza para sembrar el caos.\n\nMonta una base en Gorgrond e impide que el batallón mecánico de la Horda de Hierro avance por Draenor.', '', 0, 0, 38134),
(505, 1000, 2, 1, 1851142, 0, 0, 0, 0, 0, '0', '', '', 'Viaja a Nagrand', 'El clan Grito de Guerra es el pilar del poderío militar de la Horda de Hierro.\n\nDeben pagar por sus acciones si queremos detener su marcha bélica sobre Draenor.', '', 0, 0, 38134),
(505, 1429, 1, 0, 1851120, 0, 0, 0, 0, 0, '0', '', '', 'Combate a la Legión', '¡La Legión Ardiente ha regresado a Azeroth!', '', 0, 0, 38134);

DELETE FROM `areatrigger_template` WHERE `Id` IN (20632, 20051, 20165, 19764, 17676, 10741);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(20632, 1, 0, 4, 3, 3, 0, 0, 0, 0, 38134),
(20051, 1, 0, 4, 5, 5, 0, 0, 0, 0, 38134),
(20165, 1, 0, 0, 2, 2, 0, 0, 0, 0, 38134),
(19764, 1, 0, 0, 1, 1, 0, 0, 0, 0, 38134),
(17676, 1, 4, 0, 8, 8, 10, 10, 0, 0, 38134),
(10741, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134);


UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `Data0`=7, `Data1`=7 WHERE `Id`=19401;
UPDATE `areatrigger_template` SET `Data0`=7, `Data1`=7 WHERE `Id`=19401;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17558;

REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(12915, 17558, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 38134), -- SpellId : 265702
(16209, 20632, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 292124
(14743, 19401, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 38134), -- SpellId : 244989
(15477, 20051, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 285629
(15603, 20165, 0, 0, 0, 0, 0, 0, 0, 0, 21000, 38134), -- SpellId : 286844
(15141, 19764, 0, 0, 0, 0, 0, 0, 0, 0, 5872, 38134), -- SpellId : 282248
(13045, 17676, 0, 0, 0, 0, 0, 0, 0, 0, 5872, 38134), -- SpellId : 267211
(6054, 10741, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 38134); -- SpellId : 204739


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=653, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=423, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=626, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1554, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7115 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1320, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7115 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1446, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1253, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1000, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=13404 AND `AreaTriggerId`=17993); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7115 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=426, `TimeToTargetScale`=6000 WHERE (`SpellMiscId`=11983 AND `AreaTriggerId`=16670); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0



REPLACE INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(7217, 63194, 0, 38134),
(7471, 51642, 0, 38134),
(7444, 51642, 0, 38134),
(10183, 64220, 0, 38134),
(7070, 51642, 0, 38134),
(10184, 64220, 0, 38134),
(9895, 51642, 0, 38134),
(9894, 51642, 0, 38134),
(10719, 51642, 0, 38134);


UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8190 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8189 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8189 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8188 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8188 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8187 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8187 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=7464 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=51642, `VerifiedBuild`=38134 WHERE (`ConversationId`=7453 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8186 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8186 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (16497, 17075, 17048, 23862, 16093, 23863, 17744, 23063, 23062, 22400, 22399, 25257);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(16497, 0, 121, 0, 0, 38134),
(17075, 0, 82, 0, 0, 38134),
(17048, 0, 82, 0, 0, 38134),
(23862, 0, 90, 0, 0, 38134),
(16093, 0, 82, 0, 0, 38134),
(23863, 0, 90, 0, 0, 38134),
(17744, 0, 0, 0, 0, 38134),
(23063, 0, 82, 0, 0, 38134),
(23062, 0, 82, 0, 0, 38134),
(22400, 2850, 0, 0, 0, 38134),
(22399, 0, 0, 0, 0, 38134),
(25257, 0, 82, 0, 0, 38134);

UPDATE `conversation_line_template` SET `StartTime`=4586, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18534;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18533;
UPDATE `conversation_line_template` SET `StartTime`=6614, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18532;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18531;
UPDATE `conversation_line_template` SET `StartTime`=10347, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18530;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18529;
UPDATE `conversation_line_template` SET `StartTime`=8125, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18528;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18527;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=17068;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=17057;
UPDATE `conversation_line_template` SET `StartTime`=5498, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18526;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18525;

DELETE FROM `conversation_template` WHERE `Id` IN (7747, 7471, 7070, 7217, 10719, 7444, 10184, 10183, 9733, 9895, 9894);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(7747, 17744, 3650, 0, 38134),
(7471, 17075, 5787, 0, 38134),
(7070, 16093, 5151, 0, 38134),
(7217, 16497, 6669, 0, 38134),
(10719, 25257, 9800, 0, 38134),
(7444, 17048, 7836, 0, 38134),
(10184, 23863, 7387, 0, 38134),
(10183, 23862, 9357, 0, 38134),
(9733, 22399, 6100, 0, 38134),
(9895, 23063, 6460, 0, 38134),
(9894, 23062, 5675, 0, 38134);



UPDATE `conversation_template` SET `LastLineEndTime`=10788, `VerifiedBuild`=38134 WHERE `Id`=8190;
UPDATE `conversation_template` SET `LastLineEndTime`=12302, `VerifiedBuild`=38134 WHERE `Id`=8189;
UPDATE `conversation_template` SET `LastLineEndTime`=15049, `VerifiedBuild`=38134 WHERE `Id`=8188;
UPDATE `conversation_template` SET `LastLineEndTime`=17402, `VerifiedBuild`=38134 WHERE `Id`=8187;
UPDATE `conversation_template` SET `LastLineEndTime`=11646, `VerifiedBuild`=38134 WHERE `Id`=8186;
UPDATE `conversation_template` SET `LastLineEndTime`=6232, `VerifiedBuild`=38134 WHERE `Id`=7464;
UPDATE `conversation_template` SET `LastLineEndTime`=5803, `VerifiedBuild`=38134 WHERE `Id`=7453;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (326214 /*Extremidad fétida*/, 326208 /*Vara del Rey del Trueno*/, 281601 /*Bebida refrescante*/, 281598 /*Bebida refrescante*/, 277463 /*Calabaza verde*/, 277512 /*Melón a rayas*/, 277587 /*Manzana*/, 277468 /*Calabaza pasada*/, 277579 /*Zanahoria*/, 277578 /*Zanahoria*/, 277589 /*Naranja*/, 277590 /*Naranja*/, 290452 /*Doblón del navegante*/, 287454 /*Piedra enorme*/, 277462 /*Calabazón*/, 321350 /*Canoa*/, 326498 /*Raíces sobrecrecidas*/, 325562 /*Objeto*/, 325629 /*Objeto*/, 325561 /*Objeto*/, 287451 /*Planta carnívora*/, 282658 /*Antorcha supercaliente*/, 282628 /*Montículo de arena*/, 282625 /*Pala*/, 289320 /*Colisión*/, 305794 /*Barril de combustible*/, 305840 /*Bolsa de bombas*/, 304067 /*Equipamiento de motor*/, 305841 /*Elixir maravilloso de Miriam*/, 310624 /*Cuerda de escalar*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(326214, 94, 0, 10428, 0), -- Extremidad fétida
(326208, 94, 1, 10428, 0), -- Vara del Rey del Trueno
(281601, 0, 0, 5546, 0), -- Bebida refrescante
(281598, 0, 0, 5546, 0), -- Bebida refrescante
(277463, 0, 0, 5546, 0), -- Calabaza verde
(277512, 0, 0, 5546, 0), -- Melón a rayas
(277587, 0, 0, 5546, 0), -- Manzana
(277468, 0, 0, 5546, 0), -- Calabaza pasada
(277579, 0, 0, 5546, 0), -- Zanahoria
(277578, 0, 0, 5546, 0), -- Zanahoria
(277589, 0, 0, 5546, 0), -- Naranja
(277590, 0, 0, 5546, 0), -- Naranja
(290452, 0, 0, 5546, 0), -- Doblón del navegante
(287454, 0, 34, 0, 0), -- Piedra enorme
(277462, 0, 0, 5546, 0), -- Calabazón
(321350, 0, 48, 0, 0), -- Canoa
(326498, 94, 0, 10428, 0), -- Raíces sobrecrecidas
(325562, 1375, 2, 0, 0), -- Objeto
(325629, 1375, 2, 0, 0), -- Objeto
(325561, 1375, 2, 0, 0), -- Objeto
(287451, 0, 34, 0, 0), -- Planta carnívora
(282658, 0, 32, 9121, 0), -- Antorcha supercaliente
(282628, 0, 34, 0, 0), -- Montículo de arena
(282625, 0, 32, 9116, 0), -- Pala
(289320, 0, 32, 0, 0), -- Colisión
(305794, 0, 262144, 0, 0), -- Barril de combustible
(305840, 0, 262144, 0, 0), -- Bolsa de bombas
(304067, 0, 262144, 0, 0), -- Equipamiento de motor
(305841, 0, 0, 2150, 0), -- Elixir maravilloso de Miriam
(310624, 0, 32, 2100, 0); -- Cuerda de escalar

UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291201; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428 WHERE `entry`=271652; -- Caparazón grueso
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428 WHERE `entry`=284424; -- Flor gigante
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428 WHERE `entry`=293706; -- Cardobusto
UPDATE `gameobject_template_addon` SET `WorldEffectID`=5546 WHERE `entry`=277523; -- Ofrenda maldita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=9288 WHERE `entry`=287459; -- Piqueta
UPDATE `gameobject_template_addon` SET `flags`=32768 WHERE `entry`=289356; -- Fragmento de azerita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428 WHERE `entry`=271828; -- Parras asfixiadoras
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428 WHERE `entry`=284423; -- Semilla reluciente
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10428, `AIAnimKitID`=13184 WHERE `entry`=269983; -- Almeja perlada
UPDATE `gameobject_template_addon` SET `flags`=34 WHERE `entry`=270945; -- Almeja gigante
UPDATE `gameobject_template_addon` SET `flags`=32769 WHERE `entry`=289359; -- Trozo de azerita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=9287 WHERE `entry`=277428; -- Piedra rúnica
UPDATE `gameobject_template_addon` SET `flags`=32801 WHERE `entry`=273295; -- Cristal de azerita
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=16466 WHERE `entry`=289526; -- Globo de Ventura y Cía.
UPDATE `gameobject_template_addon` SET `WorldEffectID`=5546 WHERE `entry`=281838; -- Tótem de Frondavelada
UPDATE `gameobject_template_addon` SET `WorldEffectID`=5546 WHERE `entry`=281844; -- Resguardo mortal
UPDATE `gameobject_template_addon` SET `flags`=32801 WHERE `entry`=289437; -- Cristal de azerita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2100 WHERE `entry`=305839; -- Especialidad de Plomocorto
UPDATE `gameobject_template_addon` SET `WorldEffectID`=6026 WHERE `entry`=307750; -- Cuerda enrollada

DELETE FROM `quest_offer_reward` WHERE `ID`=53711;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(53711, 5, 1, 0, 0, 0, 3000, 0, 0, '¡Todos en Boralus celebraron cuando vieron las explosiones en esa nave de guerra! La Horda lo pensará dos veces antes de volver a atacar Boralus.', 38134); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (287166,282369,282366));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(287166, 0, 1643, 1117.0799560546875, -636.47998046875, 28.69000053405761718, 38134), -- Spell: 287166 (Proudmore Gryphon - Exit at End) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(282369, 0, 1643, 1097.02001953125, -1046.300048828125, 127.029998779296875, 38134), -- Spell: 282369 (Summon Proudmore Gyrphon) Efffect: 28 (SPELL_EFFECT_SUMMON)
(282366, 0, 1643, 522.280029296875, -696.08001708984375, 49.470001220703125, 38134); -- Spell: 282366 (Summon Proudmore Gyrphon) Efffect: 28 (SPELL_EFFECT_SUMMON)


DELETE FROM `creature_template_addon` WHERE `entry` IN (129469 /*129469 (Reptador de las profundidades marinas) - Azerite Infusion*/, 129471 /*129471 (Reptador de la arena de las profundidades marinas) - Azerite Infusion*/, 150719 /*150719 (Burbuja de azerita detectada) - Detected Azerite, Invasion*/, 146874 /*146874 (Clamavientos Mariah) - Azerite Infusion, Invasion*/, 134797 /*134797 (Ermitaño del océano) - Azerite Infusion*/, 146866 /*146866 (Elemental de escarcha esclavizado) - Azerite Infusion, Invasion*/, 139203 /*139203 (Antárbol glauco) - Azerite Infusion, Busy*/, 139207 /*139207 (Caminabosques ancestral) - Azerite Infusion, Nature Visual 4 - Flower Footsteps*/, 140354 /*140354 (Serpiente alada de escamas brillantes) - Azerite Infusion*/, 139197 /*139197 (Azotador glauco) - Azerite Infusion*/, 146883 /*146883 (Maestro de canes Angvold) - Azerite Infusion, Vargul Male Shield, Invasion*/, 139461 /*139461 (Faucerroca vinculado a la piedra) - Azerite Infusion, Invasion*/, 146911 /*146911 (Can de añublo putrecarne) - Azerite Infusion, Invasion*/, 146895 /*146895 (Vándalo putrecarne) - Azerite Infusion, Invasion, Busy, Invasion, Carry Azerite Chuck*/, 140769 /*140769 (Vena dorada) - Azerite Infusion, Force Reaction*/, 139202 /*139202 (Cuidador glauco) - Azerite Infusion, Force Reaction*/, 139225 /*139225 (Guardián de Soto Eterno) - Azerite Infusion, Thorned Fur, Force Reaction*/, 139459 /*139459 (Soldado vinculado a la piedra) - Azerite Infusion, Invasion*/, 139229 /*139229 (Aluna Hermana de hojas) - Azerite Infusion*/, 139460 /*139460 (Tejetierra vinculado a la piedra) - Azerite Infusion, Invasion*/, 140069 /*140069 (Lobo pielóxida) - Azerite Infusion*/, 140068 /*140068 (Gruñidor pielóxida) - Azerite Infusion*/, 132819 /*132819 (Cachorro pielóxida) - Azerite Infusion*/, 137954 /*137954 (Pollo salvaje)*/, 139472 /*139472 (Señor de piedra Qinsho) - Azerite Infusion, Invasion*/, 146186 /*146186 (Guerrero aguijígneo) - Azerite Infusion*/, 146185 /*146185 (Obrero aguijígneo) - Azerite Infusion*/, 132913 /*132913 (Ettin isleño) - Azerite Infusion*/, 136600 /*136600 (Sapo tropical)*/, 140979 /*140979 (Grancolmillo) - Azerite Infusion, Worm State*/, 140980 /*140980 (Gusano escamajade) - Azerite Infusion, Worm State*/, 132887 /*132887 (Cría muerteaguijón) - Azerite Infusion*/, 140107 /*140107 (Azotador muertaguijón) - Azerite Infusion*/, 140114 /*140114 (Pinzaestruendo) - Azerite Infusion*/, 140108 /*140108 (Escórpido muertaguijón) - Azerite Infusion*/, 144944 /*144944 (Chupasangre sediento) - Azerite Infusion*/, 140272 /*140272 (Trotabosques) - Azerite Infusion*/, 144948 /*144948 (Cazador alacuero)*/, 139223 /*139223 (Dríade glauca) - Azerite Infusion*/, 139226 /*139226 (Hermana Anina) - Azerite Infusion*/, 140760 /*140760 (Vida terrestre gigante) - Azerite Infusion*/, 140456 /*140456 (Musken zarzapelaje) - Azerite Infusion*/, 140457 /*140457 (Pastador zarzapelaje) - Azerite Infusion*/, 140458 /*140458 (Toro zarzapelaje) - Azerite Infusion*/, 140455 /*140455 (Cría zarzapelaje) - Azerite Infusion*/, 140263 /*140263 (Venado pezuñas rúnicas) - Azerite Infusion*/, 140262 /*140262 (Cierva pezuñas rúnicas) - Azerite Infusion*/, 140260 /*140260 (Trotador pezuñas rúnicas) - Azerite Infusion*/, 140264 /*140264 (Cría pezuñas rúnicas) - Azerite Infusion*/, 139199 /*139199 (Escupidor glauco) - Azerite Infusion*/, 139208 /*139208 (Protector de los ancestros) - Azerite Infusion*/, 139200 /*139200 (Atrapamoscas glauco) - Azerite Infusion*/, 140168 /*140168 (Pechofuerte anciano) - Azerite Infusion*/, 146862 /*146862 (Subyugadora cuernaniebla) - Azerite Infusion, Invasion*/, 140087 /*140087 (Cierva rumiapinos) - Azerite Infusion*/, 141874 /*141874 (Marinero)*/, 140250 /*140250 (Venado rumiapinos) - Azerite Infusion*/, 137438 /*137438 (Zuna)*/, 141875 /*141875 (Marinera)*/, 140171 /*140171 (Peloniebla) - Azerite Infusion*/, 140267 /*140267 (Cuernogrande Uwanu) - Azerite Infusion*/, 132864 /*132864 (Nudillatroz joven) - Azerite Infusion*/, 141881 /*141881 (Marinero)*/, 141880 /*141880 (Marinera)*/, 141899 /*141899 (Marinero)*/, 123292 /*123292 (Punzador chisparazón) - Azerite Infusion*/, 123289 /*123289 (Garraletal chisparazón) - Azerite Infusion*/, 123290 /*123290 (Pinzador chisparazón) - Azerite Infusion, Busy, Dig*/, 140609 /*140609 (Mako voraz)*/, 123291 /*123291 (Cangrejo chisparazón) - Azerite Infusion*/, 122605 /*122605 (Enemigo recién petrificado) - Azerite Infusion, Petrified, Petrified*/, 149941 /*149941 (Transporte) - Island Initialization*/, 146860 /*146860 (Merodeador cuernaniebla) - Island Initialization*/, 146864 /*146864 (Vinculador terrestre cuernaniebla) - Island Initialization*/, 146863 /*146863 (Devastador cuernaniebla) - Island Initialization*/, 146875 /*146875 (Valimok el Sañoso) - Island Initialization*/, 146870 /*146870 (Vinculahechizos Ohnazae) - Island Initialization*/, 146859 /*146859 (Elemental de roca esclavizado) - Island Initialization*/, 130334 /*130334 (Observador motaplaca) - Azerite Infusion*/, 130335 /*130335 (Cristaliris motaplaca) - Azerite Infusion*/, 147068 /*147068 (Fisura de azerita) - Azerite Wound*/, 147933 /*147933 (Azeresquirla geoactiva) - Azerite Infusion*/, 147968 /*147968 (Azerita agitada) - Azerite Infusion*/, 140084 /*140084 (Puñoatroz) - Azerite Infusion*/, 131407 /*131407 (Asesino a sueldo de Ventura) - Invasion, -Unknown-, Stun, Stun*/, 139808 /*139808 (Zoquete de Ventura) - Invasion, Ritual, Azerite Infusion*/, 140336 /*140336 (Serpiente alada noctiescamas) - Azerite Infusion*/, 139807 /*139807 (Perita de Ventura) - Invasion, Ritual, Azerite Infusion*/, 140076 /*140076 (Lomoblanco nudillatroz) - Azerite Infusion*/, 140077 /*140077 (Vapuleador nudillatroz) - Azerite Infusion, Force Reaction*/, 137951 /*137951 (Ardilla asustadiza)*/, 149354 /*149354 (Lomocristal azergema monstruoso) - Invasion, -Unknown-, Stun, Stun, Rare Elite*/, 147932 /*147932 (Azeresquirla agitada) - Invasion, -Unknown-, Stun, Stun*/, 140777 /*140777 (Coloso de gemas) - Azerite Infusion*/, 147935 /*147935 (Reptador azergema) - Invasion, Azerite Infusion*/, 147938 /*147938 (Lomocristal azergema) - Invasion, -Unknown-, Stun, Stun*/, 147202 /*147202 (Azeresquirla animada) - Invasion, -Unknown-, Stun, Stun*/, 147948 /*147948 (Azerita coagulada) - Invasion, -Unknown-, Stun, Stun*/, 147936 /*147936 (Lomotiesto azergema) - Invasion, -Unknown-, Stun, Stun*/, 142336 /*142336 (Pulpo pigmeo)*/, 136594 /*136594 (Capitán Rez'okun) - Bot AI Regroup Advert, Near Boat Trigger*/, 134787 /*134787 (Cangrejo pinzaespina) - Azerite Infusion*/, 131261 /*131261 (Durkis)*/, 140620 /*140620 (Aguijonero del Mar del Sur)*/, 147188 /*147188 (Extractor de azerita) - Invasion, Azerite Extractor*/, 144898 /*144898 (Capitán Nashashuk)*/, 144823 /*144823 (Ingeniero jefe Erzog)*/, 144803 /*144803 (Tripulante sanguinario)*/, 144934 /*144934 (Grifo Valiente)*/, 144810 /*144810 (Ingeniero de la nave de guerra)*/, 145153 /*145153 (Clarividente lanzafilosa) - Spare Spears*/, 144925 /*144925 (Suministros de la Horda)*/, 144928 /*144928 (Válvula de presión)*/, 144931 /*144931 (Correborrascas Valiente)*/, 141662 /*141662 (Maresabio Valiente) - Call of the Abyss*/, 144314 /*144314 (Guardia del puerto)*/, 139287 /*139287 (Denteserra)*/, 144660 /*144660 (Quest Bunny - Zeppelin Destruction East) - Zeppelin Burning*/, 152131 /*152131 (Guardia Valiente)*/, 145134 /*145134 (Gryphon Handler)*/, 144932 /*144932 (Grifo Valiente)*/, 144673 /*144673 (Quest Bunny - Zeppelin Destruction West) - Zeppelin Burning*/, 146364 /*146364 (Bruja helada Renegada) - Blizzard*/, 144728 /*144728 - Vile Belch*/, 144729 /*144729 (Defensor de Boralus)*/, 144730 /*144730 (Sanamareas de Boralus)*/, 144731 /*144731 (Mascahuesos Renegado) - Sight Beyond Sight, Ghost Aura*/, 148906 /*148906 (Ollie)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(129469, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 129469 (Reptador de las profundidades marinas) - Azerite Infusion
(129471, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 129471 (Reptador de la arena de las profundidades marinas) - Azerite Infusion
(150719, 0, 0, 0, 1, 0, 0, 0, 0, '292124 277614'), -- 150719 (Burbuja de azerita detectada) - Detected Azerite, Invasion
(146874, 0, 0, 0, 1, 0, 0, 0, 0, '276104 277614'), -- 146874 (Clamavientos Mariah) - Azerite Infusion, Invasion
(134797, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 134797 (Ermitaño del océano) - Azerite Infusion
(146866, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614'), -- 146866 (Elemental de escarcha esclavizado) - Azerite Infusion, Invasion
(139203, 0, 0, 0, 1, 0, 0, 0, 0, '276102 263998'), -- 139203 (Antárbol glauco) - Azerite Infusion, Busy
(139207, 0, 0, 0, 1, 0, 0, 0, 0, '276104 276004'), -- 139207 (Caminabosques ancestral) - Azerite Infusion, Nature Visual 4 - Flower Footsteps
(140354, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140354 (Serpiente alada de escamas brillantes) - Azerite Infusion
(139197, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 139197 (Azotador glauco) - Azerite Infusion
(146883, 0, 0, 0, 1, 0, 0, 0, 0, '276105 285589 277614'), -- 146883 (Maestro de canes Angvold) - Azerite Infusion, Vargul Male Shield, Invasion
(139461, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614'), -- 139461 (Faucerroca vinculado a la piedra) - Azerite Infusion, Invasion
(146911, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614'), -- 146911 (Can de añublo putrecarne) - Azerite Infusion, Invasion
(146895, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614 263998 279483 277918'), -- 146895 (Vándalo putrecarne) - Azerite Infusion, Invasion, Busy, Invasion, Carry Azerite Chuck
(140769, 0, 0, 0, 1, 0, 0, 0, 0, '276105 273393'), -- 140769 (Vena dorada) - Azerite Infusion, Force Reaction
(139202, 0, 0, 0, 1, 0, 0, 0, 0, '276102 273393'), -- 139202 (Cuidador glauco) - Azerite Infusion, Force Reaction
(139225, 0, 0, 0, 1, 0, 0, 0, 0, '276104 278173 273393'), -- 139225 (Guardián de Soto Eterno) - Azerite Infusion, Thorned Fur, Force Reaction
(139459, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614'), -- 139459 (Soldado vinculado a la piedra) - Azerite Infusion, Invasion
(139229, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 139229 (Aluna Hermana de hojas) - Azerite Infusion
(139460, 0, 0, 0, 1, 0, 0, 0, 0, '276102 277614'), -- 139460 (Tejetierra vinculado a la piedra) - Azerite Infusion, Invasion
(140069, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140069 (Lobo pielóxida) - Azerite Infusion
(140068, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140068 (Gruñidor pielóxida) - Azerite Infusion
(132819, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 132819 (Cachorro pielóxida) - Azerite Infusion
(137954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137954 (Pollo salvaje)
(139472, 0, 0, 0, 1, 0, 0, 0, 0, '276105 277614'), -- 139472 (Señor de piedra Qinsho) - Azerite Infusion, Invasion
(146186, 0, 0, 50331648, 1, 0, 0, 0, 0, '276102'), -- 146186 (Guerrero aguijígneo) - Azerite Infusion
(146185, 0, 0, 50331648, 1, 0, 0, 0, 0, '276102'), -- 146185 (Obrero aguijígneo) - Azerite Infusion
(132913, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 132913 (Ettin isleño) - Azerite Infusion
(136600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136600 (Sapo tropical)
(140979, 0, 0, 0, 1, 0, 0, 0, 0, '276104 244121'), -- 140979 (Grancolmillo) - Azerite Infusion, Worm State
(140980, 0, 0, 0, 1, 0, 0, 0, 0, '276102 244121'), -- 140980 (Gusano escamajade) - Azerite Infusion, Worm State
(132887, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 132887 (Cría muerteaguijón) - Azerite Infusion
(140107, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140107 (Azotador muertaguijón) - Azerite Infusion
(140114, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140114 (Pinzaestruendo) - Azerite Infusion
(140108, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140108 (Escórpido muertaguijón) - Azerite Infusion
(144944, 0, 0, 50331648, 1, 0, 0, 0, 0, '276102'), -- 144944 (Chupasangre sediento) - Azerite Infusion
(140272, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140272 (Trotabosques) - Azerite Infusion
(144948, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144948 (Cazador alacuero)
(139223, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 139223 (Dríade glauca) - Azerite Infusion
(139226, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 139226 (Hermana Anina) - Azerite Infusion
(140760, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 140760 (Vida terrestre gigante) - Azerite Infusion
(140456, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140456 (Musken zarzapelaje) - Azerite Infusion
(140457, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140457 (Pastador zarzapelaje) - Azerite Infusion
(140458, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140458 (Toro zarzapelaje) - Azerite Infusion
(140455, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140455 (Cría zarzapelaje) - Azerite Infusion
(140263, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140263 (Venado pezuñas rúnicas) - Azerite Infusion
(140262, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140262 (Cierva pezuñas rúnicas) - Azerite Infusion
(140260, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140260 (Trotador pezuñas rúnicas) - Azerite Infusion
(140264, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140264 (Cría pezuñas rúnicas) - Azerite Infusion
(139199, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 139199 (Escupidor glauco) - Azerite Infusion
(139208, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 139208 (Protector de los ancestros) - Azerite Infusion
(139200, 0, 0, 0, 1, 0, 3128, 0, 0, '276102'), -- 139200 (Atrapamoscas glauco) - Azerite Infusion
(140168, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140168 (Pechofuerte anciano) - Azerite Infusion
(146862, 0, 0, 0, 1, 0, 0, 0, 0, '276104 277614'), -- 146862 (Subyugadora cuernaniebla) - Azerite Infusion, Invasion
(140087, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140087 (Cierva rumiapinos) - Azerite Infusion
(141874, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141874 (Marinero)
(140250, 0, 0, 3, 1, 0, 0, 0, 0, '276102'), -- 140250 (Venado rumiapinos) - Azerite Infusion
(137438, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 137438 (Zuna)
(141875, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141875 (Marinera)
(140171, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140171 (Peloniebla) - Azerite Infusion
(140267, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 140267 (Cuernogrande Uwanu) - Azerite Infusion
(132864, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 132864 (Nudillatroz joven) - Azerite Infusion
(141881, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 141881 (Marinero)
(141880, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141880 (Marinera)
(141899, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141899 (Marinero)
(123292, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 123292 (Punzador chisparazón) - Azerite Infusion
(123289, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 123289 (Garraletal chisparazón) - Azerite Infusion
(123290, 0, 0, 0, 1, 0, 0, 0, 0, '276102 263998 274327'), -- 123290 (Pinzador chisparazón) - Azerite Infusion, Busy, Dig
(140609, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 140609 (Mako voraz)
(123291, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 123291 (Cangrejo chisparazón) - Azerite Infusion
(122605, 0, 0, 0, 1, 0, 0, 0, 0, '276102 245139 258452'), -- 122605 (Enemigo recién petrificado) - Azerite Infusion, Petrified, Petrified
(149941, 0, 0, 50331648, 1, 0, 0, 0, 0, '257025'), -- 149941 (Transporte) - Island Initialization
(146860, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146860 (Merodeador cuernaniebla) - Island Initialization
(146864, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146864 (Vinculador terrestre cuernaniebla) - Island Initialization
(146863, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146863 (Devastador cuernaniebla) - Island Initialization
(146875, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146875 (Valimok el Sañoso) - Island Initialization
(146870, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146870 (Vinculahechizos Ohnazae) - Island Initialization
(146859, 0, 0, 0, 1, 0, 0, 0, 0, '257025'), -- 146859 (Elemental de roca esclavizado) - Island Initialization
(130334, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 130334 (Observador motaplaca) - Azerite Infusion
(130335, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 130335 (Cristaliris motaplaca) - Azerite Infusion
(147068, 0, 0, 0, 1, 0, 0, 0, 0, '285629'), -- 147068 (Fisura de azerita) - Azerite Wound
(147933, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 147933 (Azeresquirla geoactiva) - Azerite Infusion
(147968, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 147968 (Azerita agitada) - Azerite Infusion
(140084, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140084 (Puñoatroz) - Azerite Infusion
(131407, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 131407 (Asesino a sueldo de Ventura) - Invasion, -Unknown-, Stun, Stun
(139808, 0, 0, 0, 1, 0, 0, 0, 0, '277614 293036 276102'), -- 139808 (Zoquete de Ventura) - Invasion, Ritual, Azerite Infusion
(140336, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 140336 (Serpiente alada noctiescamas) - Azerite Infusion
(139807, 0, 0, 0, 1, 0, 0, 0, 0, '277614 293036 276102'), -- 139807 (Perita de Ventura) - Invasion, Ritual, Azerite Infusion
(140076, 0, 0, 0, 1, 0, 0, 0, 0, '276104'), -- 140076 (Lomoblanco nudillatroz) - Azerite Infusion
(140077, 0, 0, 0, 1, 0, 0, 0, 0, '276102 273393'), -- 140077 (Vapuleador nudillatroz) - Azerite Infusion, Force Reaction
(137951, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137951 (Ardilla asustadiza)
(149354, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068 286931'), -- 149354 (Lomocristal azergema monstruoso) - Invasion, -Unknown-, Stun, Stun, Rare Elite
(147932, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 147932 (Azeresquirla agitada) - Invasion, -Unknown-, Stun, Stun
(140777, 0, 0, 0, 1, 0, 0, 0, 0, '276105'), -- 140777 (Coloso de gemas) - Azerite Infusion
(147935, 0, 0, 0, 1, 0, 0, 0, 0, '277614 276102'), -- 147935 (Reptador azergema) - Invasion, Azerite Infusion
(147938, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 147938 (Lomocristal azergema) - Invasion, -Unknown-, Stun, Stun
(147202, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 147202 (Azeresquirla animada) - Invasion, -Unknown-, Stun, Stun
(147948, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 147948 (Azerita coagulada) - Invasion, -Unknown-, Stun, Stun
(147936, 0, 0, 0, 1, 0, 0, 0, 0, '277614 249986 252273 281068'), -- 147936 (Lomotiesto azergema) - Invasion, -Unknown-, Stun, Stun
(142336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 142336 (Pulpo pigmeo)
(136594, 0, 0, 0, 0, 0, 0, 0, 0, '267808 245380'), -- 136594 (Capitán Rez'okun) - Bot AI Regroup Advert, Near Boat Trigger
(134787, 0, 0, 0, 1, 0, 0, 0, 0, '276102'), -- 134787 (Cangrejo pinzaespina) - Azerite Infusion
(131261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131261 (Durkis)
(140620, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 140620 (Aguijonero del Mar del Sur)
(147188, 0, 0, 0, 1, 0, 0, 0, 0, '277614 285806'), -- 147188 (Extractor de azerita) - Invasion, Azerite Extractor
(144898, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144898 (Capitán Nashashuk)
(144823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144823 (Ingeniero jefe Erzog)
(144803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144803 (Tripulante sanguinario)
(144934, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144934 (Grifo Valiente)
(144810, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144810 (Ingeniero de la nave de guerra)
(145153, 0, 0, 0, 1, 0, 0, 0, 0, '261116'), -- 145153 (Clarividente lanzafilosa) - Spare Spears
(144925, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144925 (Suministros de la Horda)
(144928, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144928 (Válvula de presión)
(144931, 0, 83664, 50331648, 1, 0, 0, 0, 0, ''), -- 144931 (Correborrascas Valiente)
(141662, 0, 0, 0, 1, 0, 0, 0, 0, '259148'), -- 141662 (Maresabio Valiente) - Call of the Abyss
(144314, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 144314 (Guardia del puerto)
(139287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 139287 (Denteserra)
(144660, 0, 0, 0, 1, 0, 0, 0, 0, '281924'), -- 144660 (Quest Bunny - Zeppelin Destruction East) - Zeppelin Burning
(152131, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152131 (Guardia Valiente)
(145134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145134 (Gryphon Handler)
(144932, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144932 (Grifo Valiente)
(144673, 0, 0, 0, 1, 0, 0, 0, 0, '281924'), -- 144673 (Quest Bunny - Zeppelin Destruction West) - Zeppelin Burning
(146364, 0, 0, 0, 1, 0, 0, 0, 0, '204739'), -- 146364 (Bruja helada Renegada) - Blizzard
(144728, 0, 0, 0, 1, 0, 0, 0, 0, '276316'), -- 144728 - Vile Belch
(144729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144729 (Defensor de Boralus)
(144730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144730 (Sanamareas de Boralus)
(144731, 0, 0, 0, 1, 0, 0, 0, 0, '201626 205544'), -- 144731 (Mascahuesos Renegado) - Sight Beyond Sight, Ghost Aura
(148906, 0, 0, 1, 1, 0, 0, 0, 0, ''); -- 148906 (Ollie)

UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=124497; -- 124497 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=128384; -- 128384 (Gran venado de los bajíos)
UPDATE `creature_template_addon` SET `auras`='105944' WHERE `entry`=130359; -- 130359 (Halieto costero)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=124882; -- 124882 (Roland Segueta)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=124921; -- 124921 (Cuervo del puerto)
UPDATE `creature_template_addon` SET `bytes1`=0, `movementAnimKit`=0 WHERE `entry`=128625; -- 128625 (Gaviota del puerto)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123192; -- 123192
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=139090; -- 139090 (Guardia de la expedición)
UPDATE `creature_template_addon` SET `aiAnimKit`=14225 WHERE `entry`=125924; -- 125924 (Trabajador de embarcadero de Puntanzuelo)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=137755; -- 137755 (Oficial Valiente)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='244863' WHERE `entry`=133309; -- 133309 (Trabajador de Vadoarlén)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='' WHERE `entry`=129627; -- 129627
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=1 WHERE `entry`=126581; -- 126581 (Roughneck Rider)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=142774; -- 142774
UPDATE `creature_template_addon` SET `auras`='272105' WHERE `entry`=135889; -- 135889
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=142457; -- 142457
UPDATE `creature_template_addon` SET `bytes1`=65536 WHERE `entry`=126141; -- 126141 (Ángel de la Resurrección)
UPDATE `creature_template_addon` SET `auras`='276102 273393' WHERE `entry`=132868; -- 132868 (Azerita coagulada)
UPDATE `creature_template_addon` SET `auras`='276102 273393' WHERE `entry`=126423; -- 126423 (Cangrejo lomocoral)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=132925; -- 132925 (Azerita detectada)
UPDATE `creature_template_addon` SET `auras`='277614 276102' WHERE `entry`=131311; -- 131311 (Azerita desatada)
UPDATE `creature_template_addon` SET `auras`='273393' WHERE `entry`=137947; -- 137947 (Rata carroñera)
UPDATE `creature_template_addon` SET `auras`='273393' WHERE `entry`=136598; -- 136598 (Aguijonero arenoso)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137950; -- 137950 (Hundidor de playa)
UPDATE `creature_template_addon` SET `aiAnimKit`=16421 WHERE `entry`=143111; -- 143111
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=124805; -- 124805
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=143844; -- 143844
UPDATE `creature_template_addon` SET `bytes2`=1, `aiAnimKit`=15780 WHERE `entry`=135675; -- 135675 (7th Legion Marine)
UPDATE `creature_template_addon` SET `aiAnimKit`=13281 WHERE `entry`=143295; -- 143295
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=142136; -- 142136
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=142137; -- 142137
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=143250; -- 143250
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135230; -- 135230
UPDATE `creature_template_addon` SET `bytes1`=6, `auras`='' WHERE `entry`=142180; -- 142180
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=144727; -- 144727 (Chamán rompenubes)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=140350; -- 140350
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=131229; -- 131229 (Carroñero trizahuesos)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=128710; -- 128710 (Hidra destrozada)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=144929; -- 144929 (Generic - Empty Bunny - Long AOI)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=126387; -- 126387
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=144029; -- 144029
UPDATE `creature_template_addon` SET `auras`='272990' WHERE `entry`=140313; -- 140313
UPDATE `creature_template_addon` SET `bytes2`=257, `aiAnimKit`=0 WHERE `entry`=136633; -- 136633 (Harbor Guard)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=126496; -- 126496
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=143336; -- 143336
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=141091; -- 141091
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=144030; -- 144030
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='281055' WHERE `entry`=143186; -- 143186
UPDATE `creature_template_addon` SET `auras`='251140' WHERE `entry`=143863; -- 143863
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=133325; -- 133325
UPDATE `creature_template_addon` SET `auras`='273259' WHERE `entry`=125004; -- 125004
UPDATE `creature_template_addon` SET `auras`='212171' WHERE `entry`=143128; -- 143128
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='233027' WHERE `entry`=132638; -- 132638
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=143330; -- 143330
UPDATE `creature_template_addon` SET `auras`='277932' WHERE `entry`=137744; -- 137744
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=135658; -- 135658
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=125005; -- 125005 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=140421; -- 140421
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=135783; -- 135783
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=143700; -- 143700
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=142955; -- 142955
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=137547; -- 137547 (Asistente de Punta Garfio)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=135112; -- 135112
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='244807' WHERE `entry`=140906; -- 140906
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=123169; -- 123169
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=141772; -- 141772
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=143192; -- 143192
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=135053; -- 135053
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='279123' WHERE `entry`=134722; -- 134722
UPDATE `creature_template_addon` SET `auras`='268058' WHERE `entry`=123642; -- 123642 (Boralus Citizen)
UPDATE `creature_template_addon` SET `auras`='269572' WHERE `entry`=123244; -- 123244
UPDATE `creature_template_addon` SET `auras`='244867' WHERE `entry`=135792; -- 135792 (Boralus Worker)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=134847; -- 134847

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=38 AND `Entry` IN (129469,129471,150719,146874,134797,146866,139203,139207,140354,139197,146883,139461,146911,146895,140769,139202,139225,139459,139229,139460,140069,140068,132819,137954,139472,146186,146185,132913,136600,140979,140980,132887,140107,140114,140108,144944,140272,144948,139223,139226,140760,140456,140457,140458,140455,140263,140262,140260,140264,139199,139208,139200,140168,126141,132868,142324,146862,126423,140087,141874,140250,137438,141875,140171,140267,132864,141881,141880,141899,140632,123292,123289,123290,140609,123291,122605,149941,146860,146864,146863,132912,146875,146870,146859,130334,130335,147068,147933,147968,132925,140084,131407,139808,140336,139807,140076,140077,137951,137955,149354,147932,131311,140777,147935,147938,147202,147948,147936,137947,136598,137958));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(129469, 38, 10, 50, -1, -1, 289, 38134),
(129471, 38, 10, 50, 1, 1, 289, 38134),
(150719, 38, 10, 50, 0, 0, 289, 38134),
(146874, 38, 10, 50, 2, 2, 289, 38134),
(134797, 38, 10, 50, 2, 2, 289, 38134),
(146866, 38, 10, 50, 0, 0, 289, 38134),
(139203, 38, 10, 50, 1, 1, 289, 38134),
(139207, 38, 10, 50, 1, 1, 289, 38134),
(140354, 38, 10, 50, 0, 0, 289, 38134),
(139197, 38, 10, 50, -1, -1, 289, 38134),
(146883, 38, 10, 50, 2, 2, 289, 38134),
(139461, 38, 10, 50, 1, 1, 289, 38134),
(146911, 38, 10, 50, 1, 1, 289, 38134),
(146895, 38, 10, 50, 0, 0, 289, 38134),
(140769, 38, 10, 50, 2, 2, 289, 38134),
(139202, 38, 10, 50, 1, 1, 289, 38134),
(139225, 38, 10, 50, 1, 1, 289, 38134),
(139459, 38, 10, 50, 0, 0, 289, 38134),
(139229, 38, 10, 50, 2, 2, 289, 38134),
(139460, 38, 10, 50, 1, 1, 289, 38134),
(140069, 38, 10, 50, 0, 0, 289, 38134),
(140068, 38, 10, 50, 1, 1, 289, 38134),
(132819, 38, 10, 50, -1, -1, 289, 38134),
(137954, 38, 1, 1, 0, 0, 81, 38134),
(139472, 38, 10, 50, 2, 2, 289, 38134),
(146186, 38, 10, 50, 1, 1, 289, 38134),
(146185, 38, 10, 50, 0, 0, 289, 38134),
(132913, 38, 10, 50, 2, 2, 289, 38134),
(136600, 38, 1, 1, 0, 0, 81, 38134),
(140979, 38, 10, 50, 2, 2, 289, 38134),
(140980, 38, 10, 50, 0, 0, 289, 38134),
(132887, 38, 10, 50, -1, -1, 289, 38134),
(140107, 38, 10, 50, 1, 1, 289, 38134),
(140114, 38, 10, 50, 2, 2, 289, 38134),
(140108, 38, 10, 50, 0, 0, 289, 38134),
(144944, 38, 10, 50, 1, 1, 289, 38134),
(140272, 38, 10, 50, 2, 2, 289, 38134),
(144948, 38, 10, 50, 0, 0, 289, 38134),
(139223, 38, 10, 50, 1, 1, 289, 38134),
(139226, 38, 10, 50, 2, 2, 289, 38134),
(140760, 38, 10, 50, 2, 2, 289, 38134),
(140456, 38, 10, 50, 0, 0, 289, 38134),
(140457, 38, 10, 50, 1, 1, 289, 38134),
(140458, 38, 10, 50, 1, 1, 289, 38134),
(140455, 38, 10, 50, -1, -1, 289, 38134),
(140263, 38, 10, 50, 0, 0, 289, 38134),
(140262, 38, 10, 50, 0, 0, 289, 38134),
(140260, 38, 10, 50, 1, 1, 289, 38134),
(140264, 38, 10, 50, -1, -1, 289, 38134),
(139199, 38, 10, 50, 0, 0, 289, 38134),
(139208, 38, 10, 50, 1, 1, 289, 38134),
(139200, 38, 10, 50, 0, 0, 289, 38134),
(140168, 38, 10, 50, 2, 2, 289, 38134),
(126141, 38, 10, 50, 0, 0, 289, 38134),
(132868, 38, 10, 50, 0, 0, 289, 38134),
(142324, 38, 10, 50, 0, 0, 289, 38134),
(146862, 38, 10, 50, 1, 1, 289, 38134),
(126423, 38, 10, 50, 0, 0, 289, 38134),
(140087, 38, 10, 50, 0, 0, 289, 38134),
(141874, 38, 10, 50, 0, 0, 289, 38134),
(140250, 38, 10, 50, 0, 0, 289, 38134),
(137438, 38, 10, 50, 0, 0, 189, 38134),
(141875, 38, 10, 50, 0, 0, 289, 38134),
(140171, 38, 10, 50, 2, 2, 289, 38134),
(140267, 38, 10, 50, 2, 2, 289, 38134),
(132864, 38, 10, 50, -1, -1, 289, 38134),
(141881, 38, 10, 50, 0, 0, 289, 38134),
(141880, 38, 10, 50, 0, 0, 289, 38134),
(141899, 38, 10, 50, 0, 0, 289, 38134),
(140632, 38, 10, 50, 0, 0, 289, 38134),
(123292, 38, 10, 50, -1, -1, 289, 38134),
(123289, 38, 10, 50, 1, 1, 289, 38134),
(123290, 38, 10, 50, 1, 1, 289, 38134),
(140609, 38, 10, 50, 0, 0, 289, 38134),
(123291, 38, 10, 50, 0, 0, 289, 38134),
(122605, 38, 10, 50, 0, 0, 289, 38134),
(149941, 38, 10, 50, 0, 0, 289, 38134),
(146860, 38, 10, 50, 1, 1, 289, 38134),
(146864, 38, 10, 50, 1, 1, 289, 38134),
(146863, 38, 10, 50, 1, 1, 289, 38134),
(132912, 38, 10, 50, 0, 0, 289, 38134),
(146875, 38, 10, 50, 2, 2, 289, 38134),
(146870, 38, 10, 50, 2, 2, 289, 38134),
(146859, 38, 10, 50, 0, 0, 289, 38134),
(130334, 38, 10, 50, 1, 1, 289, 38134),
(130335, 38, 10, 50, 1, 1, 289, 38134),
(147068, 38, 10, 50, 0, 0, 289, 38134),
(147933, 38, 10, 50, 1, 1, 289, 38134),
(147968, 38, 10, 50, 0, 0, 289, 38134),
(132925, 38, 10, 50, 0, 0, 289, 38134),
(140084, 38, 10, 50, 2, 2, 289, 38134),
(131407, 38, 10, 50, 0, 0, 289, 38134),
(139808, 38, 10, 50, 1, 1, 289, 38134),
(140336, 38, 10, 50, 0, 0, 289, 38134),
(139807, 38, 10, 50, 1, 1, 289, 38134),
(140076, 38, 10, 50, 1, 1, 289, 38134),
(140077, 38, 10, 50, 1, 1, 289, 38134),
(137951, 38, 1, 1, 0, 0, 81, 38134),
(137955, 38, 1, 1, 0, 0, 81, 38134),
(149354, 38, 10, 50, 2, 2, 289, 38134),
(147932, 38, 10, 50, 0, 0, 289, 38134),
(131311, 38, 10, 50, 1, 1, 289, 38134),
(140777, 38, 10, 50, 2, 2, 289, 38134),
(147935, 38, 10, 50, 0, 0, 289, 38134),
(147938, 38, 10, 50, 1, 1, 289, 38134),
(147202, 38, 10, 50, -1, -1, 289, 38134),
(147948, 38, 10, 50, -1, -1, 289, 38134),
(147936, 38, 10, 50, 1, 1, 289, 38134),
(137947, 38, 1, 1, 0, 0, 81, 38134),
(136598, 38, 1, 1, 0, 0, 81, 38134),
(137958, 38, 1, 1, 0, 0, 81, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141646 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137790 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137781 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137751 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137755 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138853 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137679 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141868 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141869 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=142336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141863 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=136592 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=136594 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=136599 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137946 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=79556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=134787 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=131261 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=141777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=140620 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=289, `VerifiedBuild`=38134 WHERE (`Entry`=147188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143101 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=482, `VerifiedBuild`=38134 WHERE (`Entry`=73400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144823 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144803 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144934 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144810 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145153 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144928 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143057 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=131229 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144931 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=144314 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128593 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152131 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144932 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144673 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144178 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=146364 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144728 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138956 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138955 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142046 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142035 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142051 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138953 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138952 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142453 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137201 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142043 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142069 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138410 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=128630 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137483 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=328, `VerifiedBuild`=38134 WHERE (`Entry`=142955 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137547 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1 WHERE `DisplayID`=80619;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=74698;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86618;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249328166246414184, `CombatReach`=0.974999964237213134 WHERE `DisplayID`=22469;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87392;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=85507;
UPDATE `creature_model_info` SET `BoundingRadius`=0.357120037078857421, `CombatReach`=1.440000057220458984, `VerifiedBuild`=38134 WHERE `DisplayID`=52574;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85550;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77591;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85437;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=52582;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85440;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85548;
UPDATE `creature_model_info` SET `BoundingRadius`=0.186420083045959472, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=93454;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85547;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.489275455474853515, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=93452;
UPDATE `creature_model_info` SET `BoundingRadius`=1.399999976158142089, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=83869;
UPDATE `creature_model_info` SET `BoundingRadius`=0.83760005235671997, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=89487;
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=45334;
UPDATE `creature_model_info` SET `BoundingRadius`=1.392014861106872558, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=22206;
UPDATE `creature_model_info` SET `BoundingRadius`=0.802699983119964599, `CombatReach`=3.449999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=89479;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416400015354156494, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86196;
UPDATE `creature_model_info` SET `BoundingRadius`=2.394019365310668945, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=54681;
UPDATE `creature_model_info` SET `BoundingRadius`=0.686863839626312255, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=59860;
UPDATE `creature_model_info` SET `BoundingRadius`=1.933423042297363281, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=1336;
UPDATE `creature_model_info` SET `BoundingRadius`=0.686863839626312255, `CombatReach`=0.400000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=59872;
UPDATE `creature_model_info` SET `BoundingRadius`=1.873069405555725097, `CombatReach`=1.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=25240;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20000004768371582, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=86367;
UPDATE `creature_model_info` SET `BoundingRadius`=0.397799968719482421, `VerifiedBuild`=38134 WHERE `DisplayID`=38188;
UPDATE `creature_model_info` SET `BoundingRadius`=1.170668363571166992, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=25241;
UPDATE `creature_model_info` SET `BoundingRadius`=3.628347396850585937, `CombatReach`=4.25, `VerifiedBuild`=38134 WHERE `DisplayID`=86903;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416400015354156494, `CombatReach`=2.40000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86195;
UPDATE `creature_model_info` SET `BoundingRadius`=1.643068432807922363, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=2432;
UPDATE `creature_model_info` SET `BoundingRadius`=0.950173497200012207, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86365;
UPDATE `creature_model_info` SET `BoundingRadius`=1.137702107429504394, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=2721;
UPDATE `creature_model_info` SET `BoundingRadius`=1.092699527740478515, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86352;
UPDATE `creature_model_info` SET `BoundingRadius`=1.472768902778625488, `CombatReach`=2.324999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=86359;
UPDATE `creature_model_info` SET `BoundingRadius`=1.548884153366088867, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=80030;
UPDATE `creature_model_info` SET `BoundingRadius`=1.239107370376586914, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=80029;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20000004768371582, `CombatReach`=4.800000190734863281 WHERE `DisplayID`=30500;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=26204;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=64117;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=1.399999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=79481;
UPDATE `creature_model_info` SET `BoundingRadius`=0.75, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85199;
UPDATE `creature_model_info` SET `BoundingRadius`=0.550000011920928955, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=37539;
UPDATE `creature_model_info` SET `BoundingRadius`=3.106671333312988281, `CombatReach`=1.799999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=57485;
UPDATE `creature_model_info` SET `BoundingRadius`=0.982793688774108886, `CombatReach`=0.85000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=45091;
UPDATE `creature_model_info` SET `BoundingRadius`=0.244999989867210388, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=30129;
UPDATE `creature_model_info` SET `BoundingRadius`=2.416299819946289062, `CombatReach`=1.399999976158142089 WHERE `DisplayID`=53767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.657338976860046386, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=62290;
UPDATE `creature_model_info` SET `BoundingRadius`=0.758468091487884521, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=67940;
UPDATE `creature_model_info` SET `BoundingRadius`=2.774618387222290039, `CombatReach`=3.25, `VerifiedBuild`=38134 WHERE `DisplayID`=65102;
UPDATE `creature_model_info` SET `BoundingRadius`=1.606585025787353515, `CombatReach`=1.609999895095825195, `VerifiedBuild`=38134 WHERE `DisplayID`=65862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.918048560619354248, `CombatReach`=0.920000016689300537, `VerifiedBuild`=38134 WHERE `DisplayID`=65861;
UPDATE `creature_model_info` SET `BoundingRadius`=0.924982249736785888, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=45089;
UPDATE `creature_model_info` SET `BoundingRadius`=0.346720516681671142, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=70448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.346720516681671142, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=70451;
UPDATE `creature_model_info` SET `BoundingRadius`=0.244999989867210388, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=30137;
UPDATE `creature_model_info` SET `BoundingRadius`=2.394019365310668945, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=54678;
UPDATE `creature_model_info` SET `BoundingRadius`=0.210000008344650268, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=80464;
UPDATE `creature_model_info` SET `BoundingRadius`=1.607157826423645019, `CombatReach`=1.625 WHERE `DisplayID`=839;
UPDATE `creature_model_info` SET `BoundingRadius`=1.459499955177307128, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=71985;
UPDATE `creature_model_info` SET `BoundingRadius`=0.802699983119964599, `CombatReach`=3.449999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=89480;
UPDATE `creature_model_info` SET `BoundingRadius`=0.607638478279113769, `CombatReach`=2.625, `VerifiedBuild`=38134 WHERE `DisplayID`=89476;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.977200031280517578, `CombatReach`=4.199999809265136718, `VerifiedBuild`=38134 WHERE `DisplayID`=89483;
UPDATE `creature_model_info` SET `BoundingRadius`=0.503471910953521728, `CombatReach`=2.175000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=89473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.870009303092956542, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=2075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47928;
UPDATE `creature_model_info` SET `BoundingRadius`=0.346720516681671142, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=70449;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.924982249736785888, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=70443;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87981;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87500;
UPDATE `creature_model_info` SET `BoundingRadius`=1.607157826423645019, `CombatReach`=1.625, `VerifiedBuild`=38134 WHERE `DisplayID`=36389;
UPDATE `creature_model_info` SET `BoundingRadius`=1.329661965370178222, `CombatReach`=1.149999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=45090;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87502;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87501;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87509;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599132537841796, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=78925;
UPDATE `creature_model_info` SET `BoundingRadius`=3.82742619514465332, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=76627;
UPDATE `creature_model_info` SET `BoundingRadius`=1.91371309757232666, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76626;
UPDATE `creature_model_info` SET `BoundingRadius`=3.612242937088012695, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=69324;
UPDATE `creature_model_info` SET `BoundingRadius`=5.057140350341796875, `CombatReach`=7, `VerifiedBuild`=38134 WHERE `DisplayID`=70340;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=89807;
UPDATE `creature_model_info` SET `BoundingRadius`=1.607157826423645019, `CombatReach`=1.625 WHERE `DisplayID`=3186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.351899981498718261, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=88384;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15137;
UPDATE `creature_model_info` SET `BoundingRadius`=0.399049997329711914, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=88386;
UPDATE `creature_model_info` SET `BoundingRadius`=1.854413032531738281, `CombatReach`=1.875 WHERE `DisplayID`=837;
UPDATE `creature_model_info` SET `BoundingRadius`=0.322235822677612304, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=80910;
UPDATE `creature_model_info` SET `BoundingRadius`=1.503324747085571289, `CombatReach`=2.25 WHERE `DisplayID`=83052;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=86908;
UPDATE `creature_model_info` SET `BoundingRadius`=1.45000004768371582, `CombatReach`=1.8125, `VerifiedBuild`=38134 WHERE `DisplayID`=89809;
UPDATE `creature_model_info` SET `BoundingRadius`=3, `CombatReach`=3.75, `VerifiedBuild`=38134 WHERE `DisplayID`=89818;
UPDATE `creature_model_info` SET `BoundingRadius`=0.195299997925758361, `CombatReach`=0.629999995231628417, `VerifiedBuild`=38134 WHERE `DisplayID`=84157;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=89814;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87497;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87498;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=47930;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87496;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87494;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306255877017974853, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.090000003576278686, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=63970;
UPDATE `creature_model_info` SET `BoundingRadius`=3.512032508850097656, `VerifiedBuild`=38134 WHERE `DisplayID`=89589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87825;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87818;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87831;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164 WHERE `DisplayID`=86639;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.913979768753051757, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=81194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.866400063037872314, `CombatReach`=3.60000014305114746, `VerifiedBuild`=38134 WHERE `DisplayID`=88893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=84589;
UPDATE `creature_model_info` SET `BoundingRadius`=0.558000028133392333 WHERE `DisplayID`=31288;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88856;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=88861;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88855;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236000001430511474, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88857;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=88860;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87399;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=90587;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85439;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87402;
UPDATE `creature_model_info` SET `BoundingRadius`=3.13771986961364746, `CombatReach`=6.299999713897705078, `VerifiedBuild`=38134 WHERE `DisplayID`=67032;
UPDATE `creature_model_info` SET `BoundingRadius`=0.252000004053115844, `CombatReach`=0.576000034809112548, `VerifiedBuild`=38134 WHERE `DisplayID`=43293;
UPDATE `creature_model_info` SET `BoundingRadius`=9.9450531005859375, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=80474;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=68185;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88185;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88204;
UPDATE `creature_model_info` SET `BoundingRadius`=0.290052592754364013, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.497899949550628662, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=68184;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=88407;
UPDATE `creature_model_info` SET `BoundingRadius`=0.497899949550628662, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=68186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.497899949550628662, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=68183;
UPDATE `creature_model_info` SET `BoundingRadius`=2.948759078979492187, `CombatReach`=3.520000219345092773, `VerifiedBuild`=38134 WHERE `DisplayID`=10612;
UPDATE `creature_model_info` SET `BoundingRadius`=0.531285345554351806, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=67530;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88200;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88152;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85512;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106639862060546, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=86546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=74487;
UPDATE `creature_model_info` SET `BoundingRadius`=0.136766985058784484, `CombatReach`=0.899999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=76518;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167159661650657653, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=76516;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=72180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87563;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87561;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86083;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86084;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106639862060546, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=86543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=74792;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85198;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=81387;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=11709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=74789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=85840;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88497;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80051;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85281;
UPDATE `creature_model_info` SET `BoundingRadius`=0.173778563737869262, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=68729;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=79383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87948;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88295;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=72178;

DELETE FROM `npc_vendor` WHERE (`entry`=131261 AND `item`=170252 AND `ExtendedCost`=6302 AND `type`=1) OR (`entry`=131261 AND `item`=170253 AND `ExtendedCost`=6303 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(131261, 2, 170252, 0, 6302, 1, 0, 0, 38134), -- Pouch of Gangrenous Spores
(131261, 1, 170253, 0, 6303, 1, 0, 0, 38134); -- Poisoned Whetstone


DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (146874,146883,146895,139460,139472,146862,146860,146864,146863,146875,146870,131407,136592,142136,144898,144823,144803,144810,145153,144931,141662,144314,152131,145134,146364,144729,144730));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(146874, 1, 50428, 0, 0, 79333, 0, 0, 0, 0, 0), -- Clamavientos Mariah
(146883, 1, 64604, 0, 0, 57452, 0, 0, 0, 0, 0), -- Maestro de canes Angvold
(146895, 1, 36529, 0, 0, 0, 0, 0, 0, 0, 0), -- Vándalo putrecarne
(139460, 1, 80522, 0, 0, 0, 0, 0, 0, 0, 0), -- Tejetierra vinculado a la piedra
(139472, 1, 93127, 0, 0, 0, 0, 0, 0, 0, 0), -- Señor de piedra Qinsho
(146862, 1, 73473, 0, 0, 23156, 0, 0, 0, 0, 0), -- Subyugadora cuernaniebla
(146860, 1, 108797, 0, 0, 0, 0, 0, 0, 0, 0), -- Merodeador cuernaniebla
(146864, 1, 116639, 0, 0, 0, 0, 0, 0, 0, 0), -- Vinculador terrestre cuernaniebla
(146863, 1, 60639, 0, 0, 60639, 0, 0, 0, 0, 0), -- Devastador cuernaniebla
(146875, 1, 50810, 0, 0, 0, 0, 0, 0, 0, 0), -- Valimok el Sañoso
(146870, 1, 77223, 0, 0, 48032, 0, 0, 0, 0, 0), -- Vinculahechizos Ohnazae
(131407, 1, 2147, 0, 0, 0, 0, 0, 12523, 0, 0), -- Asesino a sueldo de Ventura
(136592, 1, 155766, 0, 0, 155766, 0, 0, 0, 0, 0), -- Flynn Céfiro
(142136, 1, 2202, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(144898, 1, 116796, 0, 0, 0, 0, 0, 0, 0, 0), -- Capitán Nashashuk
(144823, 1, 156874, 0, 0, 0, 0, 0, 0, 0, 0), -- Ingeniero jefe Erzog
(144803, 1, 134779, 0, 0, 0, 0, 0, 55361, 0, 0), -- Tripulante sanguinario
(144810, 1, 156874, 0, 0, 0, 0, 0, 3780, 0, 0), -- Ingeniero de la nave de guerra
(145153, 1, 160115, 0, 0, 0, 0, 0, 0, 0, 0), -- Clarividente lanzafilosa
(144931, 1, 155800, 0, 0, 158911, 0, 0, 14105, 0, 0), -- Correborrascas Valiente
(141662, 1, 159928, 0, 0, 0, 0, 0, 0, 0, 0), -- Maresabio Valiente
(144314, 1, 158900, 0, 0, 0, 0, 0, 155816, 0, 0), -- Guardia del puerto
(152131, 1, 158900, 0, 0, 0, 0, 0, 155816, 0, 0), -- Guardia Valiente
(145134, 1, 0, 0, 0, 0, 0, 0, 155816, 0, 0), -- Gryphon Handler
(146364, 1, 134849, 0, 0, 0, 0, 0, 0, 0, 0), -- Bruja helada Renegada
(144729, 1, 158912, 0, 0, 159799, 0, 0, 0, 0, 0), -- Defensor de Boralus
(144730, 1, 155759, 0, 0, 155789, 0, 0, 155807, 0, 0); -- Sanamareas de Boralus

UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=143572 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=163840, `ItemID2`=0 WHERE (`CreatureID`=139088 AND `ID`=5); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=123642 AND `ID`=2); -- Boralus Citizen
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=133282 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=139088 AND `ID`=4); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=135792 AND `ID`=5); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=135792 AND `ID`=4); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=142137 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=123642 AND `ID`=1); -- Boralus Citizen
UPDATE `creature_equip_template` SET `ItemID1`=45123 WHERE (`CreatureID`=135792 AND `ID`=3); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=139088 AND `ID`=3); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=155799, `ItemID2`=159799 WHERE (`CreatureID`=139088 AND `ID`=2); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=2717 WHERE (`CreatureID`=135792 AND `ID`=2); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=155894 WHERE (`CreatureID`=135792 AND `ID`=1); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=80580 WHERE (`CreatureID`=134838 AND `ID`=3); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=155894 WHERE (`CreatureID`=134838 AND `ID`=2); -- -Unknown-

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=21990 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21990, 0, 21990, 0);




UPDATE `creature_template` SET `unit_flags`=536904448 WHERE `entry`=124497; -- Fallhaven Villager
UPDATE `creature_template` SET `gossip_menu_id`=21990 WHERE `entry`=132146; -- Helen Vistagua
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=128 WHERE `entry`=129490; -- Burke Stevenson
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=128 WHERE `entry`=129489; -- Kyle Vadovela
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141646; -- Marino del almirantazgo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137790; -- Sargento de maniobras Smithson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137695; -- Cautivo Ortuk
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137750; -- Cautiva Idina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137781; -- Interrogador Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137751; -- Cautivo Ta'dom
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137755; -- Oficial Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138853; -- Cadete Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137679; -- Reservista Valiente
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129469; -- Reptador de las profundidades marinas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=80 WHERE `entry`=129471; -- Reptador de la arena de las profundidades marinas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=33 WHERE `entry`=150719; -- Burbuja de azerita detectada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32848, `unit_flags3`=32 WHERE `entry`=146874; -- Clamavientos Mariah
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=17179869184, `BaseAttackTime`=3000, `unit_flags`=80, `unit_flags2`=18874368, `unit_flags3`=32 WHERE `entry`=134797; -- Ermitaño del océano
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=32784 WHERE `entry`=146866; -- Elemental de escarcha esclavizado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=139203; -- Antárbol glauco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139207; -- Caminabosques ancestral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140354; -- Serpiente alada de escamas brillantes
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=0, `unit_flags3`=32 WHERE `entry`=139197; -- Azotador glauco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=146883; -- Maestro de canes Angvold
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139461; -- Faucerroca vinculado a la piedra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=146911; -- Can de añublo putrecarne
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=146895; -- Vándalo putrecarne
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags`=294976, `unit_flags2`=2097156, `unit_flags3`=33 WHERE `entry`=140769; -- Vena dorada
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags2`=4, `unit_flags3`=33 WHERE `entry`=139202; -- Cuidador glauco
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139225; -- Guardián de Soto Eterno
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=32 WHERE `entry`=139459; -- Soldado vinculado a la piedra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=139229; -- Aluna Hermana de hojas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139460; -- Tejetierra vinculado a la piedra
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=140069; -- Lobo pielóxida
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=140068; -- Gruñidor pielóxida
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=132819; -- Cachorro pielóxida
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=137954; -- Pollo salvaje
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=16448, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=139472; -- Señor de piedra Qinsho
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=64 WHERE `entry`=146186; -- Guerrero aguijígneo
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=146185; -- Obrero aguijígneo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=132913; -- Ettin isleño
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=136600; -- Sapo tropical
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2022, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140979; -- Grancolmillo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags3`=32 WHERE `entry`=140980; -- Gusano escamajade
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132887; -- Cría muerteaguijón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140107; -- Azotador muertaguijón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=1500, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140114; -- Pinzaestruendo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140108; -- Escórpido muertaguijón
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=144944; -- Chupasangre sediento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140272; -- Trotabosques
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=144948; -- Cazador alacuero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139223; -- Dríade glauca
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139226; -- Hermana Anina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=140760; -- Vida terrestre gigante
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140456; -- Musken zarzapelaje
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140457; -- Pastador zarzapelaje
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140458; -- Toro zarzapelaje
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140455; -- Cría zarzapelaje
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=32 WHERE `entry`=140263; -- Venado pezuñas rúnicas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=32 WHERE `entry`=140262; -- Cierva pezuñas rúnicas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140260; -- Trotador pezuñas rúnicas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140264; -- Cría pezuñas rúnicas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags3`=32 WHERE `entry`=139199; -- Escupidor glauco
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=139208; -- Protector de los ancestros
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=0, `unit_flags3`=32 WHERE `entry`=139200; -- Atrapamoscas glauco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140168; -- Pechofuerte anciano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=32768, `speed_run`=1.142857193946838378, `RangeAttackTime`=0 WHERE `entry`=126141; -- Ángel de la Resurrección
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags`=294912, `unit_flags2`=4, `unit_flags3`=33 WHERE `entry`=132868; -- Azerita coagulada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142324; -- Delfín azuleta
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=32848 WHERE `entry`=146862; -- Subyugadora cuernaniebla
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags`=262144, `unit_flags2`=16777220, `unit_flags3`=33 WHERE `entry`=126423; -- Cangrejo lomocoral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140087; -- Cierva rumiapinos
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141874; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140250; -- Venado rumiapinos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2900, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=137438; -- Zuna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141875; -- Marinera
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140171; -- Peloniebla
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=140267; -- Cuernogrande Uwanu
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132864; -- Nudillatroz joven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141881; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141880; -- Marinera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141899; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140632; -- Mordedor lomoescamas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123292; -- Punzador chisparazón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123289; -- Garraletal chisparazón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=80 WHERE `entry`=123290; -- Pinzador chisparazón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140609; -- Mako voraz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123291; -- Cangrejo chisparazón
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=17196646400, `RangeAttackTime`=0 WHERE `entry`=122605; -- Enemigo recién petrificado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33817344, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=6015 WHERE `entry`=149941; -- Transporte
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=146860; -- Merodeador cuernaniebla
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=146864; -- Vinculador terrestre cuernaniebla
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=146863; -- Devastador cuernaniebla
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132912; -- Azerita detectada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=146875; -- Valimok el Sañoso
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=146870; -- Vinculahechizos Ohnazae
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850112, `unit_flags3`=33 WHERE `entry`=146859; -- Elemental de roca esclavizado
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags`=294976, `unit_flags2`=4, `unit_flags3`=33 WHERE `entry`=130334; -- Observador motaplaca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130335; -- Cristaliris motaplaca
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `unit_flags`=33554432 WHERE `entry`=147068; -- Fisura de azerita
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147933; -- Azeresquirla geoactiva
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147968; -- Azerita agitada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33555200 WHERE `entry`=132925; -- Azerita detectada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=1500, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=140084; -- Puñoatroz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33850112 WHERE `entry`=131407; -- Asesino a sueldo de Ventura
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=139808; -- Zoquete de Ventura
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=0, `unit_flags3`=32 WHERE `entry`=140336; -- Serpiente alada noctiescamas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832, `unit_flags3`=32 WHERE `entry`=139807; -- Perita de Ventura
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=140076; -- Lomoblanco nudillatroz
UPDATE `creature_template` SET `minlevel`=50, `faction`=1924, `RangeAttackTime`=0, `unit_flags`=294976, `unit_flags2`=4, `unit_flags3`=33 WHERE `entry`=140077; -- Vapuleador nudillatroz
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=137951; -- Ardilla asustadiza
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=137955; -- Ermitaña de los bosques
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=149354; -- Lomocristal azergema monstruoso
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850112, `unit_flags3`=33, `HoverHeight`=1 WHERE `entry`=147932; -- Azeresquirla agitada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=131311; -- Azerita desatada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2097152, `unit_flags3`=32 WHERE `entry`=140777; -- Coloso de gemas
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=32768, `unit_flags3`=32 WHERE `entry`=147935; -- Reptador azergema
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=32832 WHERE `entry`=147938; -- Lomocristal azergema
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850112, `unit_flags3`=33 WHERE `entry`=147202; -- Azeresquirla animada
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147948; -- Azerita coagulada
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33850176, `unit_flags3`=33 WHERE `entry`=147936; -- Lomotiesto azergema
UPDATE `creature_template` SET `faction`=1924, `RangeAttackTime`=0, `unit_flags`=262144, `unit_flags2`=2052, `unit_flags3`=33 WHERE `entry`=137947; -- Rata carroñera
UPDATE `creature_template` SET `faction`=1924, `RangeAttackTime`=0, `unit_flags`=262144, `unit_flags2`=2052, `unit_flags3`=33 WHERE `entry`=136598; -- Aguijonero arenoso
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=262144 WHERE `entry`=137958; -- Zorro xilocarmesí
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295168 WHERE `entry`=141868; -- Marinera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295168 WHERE `entry`=141869; -- Oteadora
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=294912 WHERE `entry`=142336; -- Pulpo pigmeo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295168 WHERE `entry`=141867; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295680 WHERE `entry`=141862; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295680 WHERE `entry`=141863; -- Marinero
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=294912, `unit_flags2`=1073743872 WHERE `entry`=136592; -- Flynn Céfiro
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=294912, `unit_flags2`=1073743872 WHERE `entry`=136594; -- Capitán Rez'okun
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=262144 WHERE `entry`=136599; -- Buccino de la marisma
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=262144 WHERE `entry`=137946; -- Ratón de la arena
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=79556; -- Islas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2348, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=262144, `unit_flags2`=16777216, `unit_flags3`=32 WHERE `entry`=134787; -- Cangrejo pinzaespina
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=137950; -- Hundidor de playa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2908, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=294976, `unit_flags2`=34816 WHERE `entry`=131261; -- Durkis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=295680 WHERE `entry`=141777; -- Marinera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=294912 WHERE `entry`=140620; -- Aguijonero del Mar del Sur
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147188; -- Extractor de azerita
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143111; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143101; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143114; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143098; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry`=138704; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=124725; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=22600 WHERE `entry`=135808; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21307 WHERE `entry`=121235; -- Taelia
UPDATE `creature_template` SET `gossip_menu_id`=22725, `npcflag`=0 WHERE `entry`=139522; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `RangeAttackTime`=0 WHERE `entry`=73400; -- Healing Ran Invisible Stalker DND
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135153; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21990 WHERE `entry`=135064; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=144898; -- Capitán Nashashuk
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=144727; -- Chamán rompenubes
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=144823; -- Ingeniero jefe Erzog
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144803; -- Tripulante sanguinario
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=144934; -- Grifo Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144810; -- Ingeniero de la nave de guerra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145153; -- Clarividente lanzafilosa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67651584, `unit_flags3`=1 WHERE `entry`=144925; -- Suministros de la Horda
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=100665344, `dynamicflags`=128 WHERE `entry`=144928; -- Válvula de presión
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143057; -- Coastal Bounder
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131229; -- Carroñero trizahuesos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2909, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=144931; -- Correborrascas Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2995, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=141662; -- Maresabio Valiente
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2995, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144314; -- Guardia del puerto
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=128710; -- Hidra destrozada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128593; -- Cría de tortuga marina petravalva
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=139287; -- Denteserra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69748736, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144660; -- Quest Bunny - Zeppelin Destruction East
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=152131; -- Guardia Valiente
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=145134; -- Gryphon Handler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=144932; -- Grifo Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69748736, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144673; -- Quest Bunny - Zeppelin Destruction West
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=143547; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144178; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=146364; -- Bruja helada Renegada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=144728; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2618, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=144729; -- Defensor de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2618, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=144730; -- Sanamareas de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144731; -- Mascahuesos Renegado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=139068; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142029; -- Percy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142040; -- Tigre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138956; -- Eliza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138954; -- Lilly
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138955; -- Jack
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138957; -- Hannah
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137199; -- Tink
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142046; -- Sofía
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142030; -- Frankie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142035; -- Meeko
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142031; -- Nellie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142044; -- Kenshi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142042; -- Anarquía
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142050; -- Gandy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142051; -- Holly
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142111; -- Mango
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142055; -- Chillidos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138953; -- Jim Clark
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138952; -- Amelia Clark
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138422; -- Boswell
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138423; -- Winston
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142453; -- Tobiana
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137196; -- Nala
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137191; -- Catherine Morgan
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137201; -- Sammy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142613; -- Murciélago
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142043; -- Tormentita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142052; -- Miau Miau
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142053; -- Gizmo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142032; -- Mika
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142069; -- Babar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138421; -- Finnigan
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138410; -- Señor Guy
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148906; -- Ollie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144114; -- Nina Martinel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=143535; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=142490; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128630; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137483; -- Laurence E. Craft
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143571; -- Tanuki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142541; -- Ellie
UPDATE `creature_template` SET `faction`=2908, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=135783; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=142955; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137547; -- Asistente de Punta Garfio


UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=140755 AND `Idx`=0); -- Cangrejo marino resplandeciente
UPDATE `creature_template_model` SET `DisplayScale`=0.349999994039535522 WHERE (`CreatureID`=141295 AND `Idx`=0); -- Murray
UPDATE `creature_template_model` SET `DisplayScale`=0.649999976158142089 WHERE (`CreatureID`=144445 AND `Idx`=0); -- Croador del continente
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=137790 AND `Idx`=0); -- Sargento de maniobras Smithson
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=137695 AND `Idx`=0); -- Cautivo Ortuk
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=144823 AND `Idx`=0); -- Ingeniero jefe Erzog
UPDATE `creature_template_model` SET `CreatureDisplayID`=88854 WHERE (`CreatureID`=144803 AND `Idx`=0); -- Tripulante sanguinario
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=144810 AND `Idx`=0); -- Ingeniero de la nave de guerra
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=144898 AND `Idx`=0); -- Capitán Nashashuk
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=143057 AND `Idx`=1); -- Coastal Bounder
UPDATE `creature_template_model` SET `DisplayScale`=2.5 WHERE (`CreatureID`=139287 AND `Idx`=0); -- Denteserra
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142040 AND `Idx`=0); -- Tigre
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142029 AND `Idx`=0); -- Percy
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=138956 AND `Idx`=0); -- Eliza
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=138954 AND `Idx`=0); -- Lilly
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=142055 AND `Idx`=0); -- Chillidos
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142050 AND `Idx`=0); -- Gandy
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142046 AND `Idx`=0); -- Sofía
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142044 AND `Idx`=0); -- Kenshi
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142042 AND `Idx`=0); -- Anarquía
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142035 AND `Idx`=0); -- Meeko
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142031 AND `Idx`=0); -- Nellie
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=142030 AND `Idx`=0); -- Frankie
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138423 AND `Idx`=0); -- Winston
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138422 AND `Idx`=0); -- Boswell
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=137196 AND `Idx`=0); -- Nala
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=148906 AND `Idx`=0); -- Ollie
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142053 AND `Idx`=0); -- Gizmo
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142052 AND `Idx`=0); -- Miau Miau
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142032 AND `Idx`=0); -- Mika
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138421 AND `Idx`=0); -- Finnigan
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138410 AND `Idx`=0); -- Señor Guy
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=143571 AND `Idx`=0); -- Tanuki
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142541 AND `Idx`=0); -- Ellie


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=292917 AND `Idx`=0); -- Escamareas centelleante

DELETE FROM `world_quest` WHERE `id` IN (53711 /*53711*/, 53699 /*53699*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(53711, 25200, 16288, 1), -- 53711
(53699, 25200, 16288, 1); -- 53699

UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099


DELETE FROM `areatrigger_template` WHERE `Id`=24351;
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(24351, 1, 0, 0, 2, 2, 0, 0, 0, 0, 38134);

UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12740;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12515;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=22171;


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=705, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=600000 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0
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
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6000, `TimeToTargetScale`=6000 WHERE (`SpellMiscId`=18034 AND `AreaTriggerId`=22171); -- SpellId : 0
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
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0


DELETE FROM `conversation_line_template` WHERE `Id` IN (36194, 36198, 36196, 36188, 36202, 36190, 27724, 36192, 32903, 34972, 36200, 32902);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(36194, 0, 0, 0, 0, 38134),
(36198, 0, 0, 0, 0, 38134),
(36196, 0, 0, 0, 0, 38134),
(36188, 0, 0, 0, 0, 38134),
(36202, 0, 0, 0, 0, 38134),
(36190, 0, 0, 0, 0, 38134),
(27724, 10577, 0, 2, 0, 38134),
(36192, 0, 0, 0, 0, 38134),
(32903, 0, 0, 0, 0, 38134),
(34972, 0, 0, 0, 0, 38134),
(36200, 0, 0, 0, 0, 38134),
(32902, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33475;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33474;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33476;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31896;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31895;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31916;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31915;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31914;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31592;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31955;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31954;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31953;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31944;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31943;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31949;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31948;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31898;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31897;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31882;
UPDATE `conversation_line_template` SET `StartTime`=3622 WHERE `Id`=27723;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33371;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31951;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=31950;


DELETE FROM `gameobject_template_addon` WHERE `entry`=342068;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(342068, 0, 262144, 0, 0); -- Altar necrótico

UPDATE `gameobject_template_addon` SET `faction`=1733 WHERE `entry`=259114; -- [DNT] Command Table Collision Cylinder


DELETE FROM `quest_offer_reward` WHERE `ID` IN (59589 /*-Unknown-*/, 58946 /*-Unknown-*/, 58923 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59589, 0, 0, 0, 0, 0, 0, 0, 0, 'Una sabia elección, $n.\n\nPuedes probar tus nuevas habilidades con los muñecos de práctica que hay fuera.', 38134), -- -Unknown-
(58946, 0, 0, 0, 0, 0, 0, 0, 0, 'Buen trabajo, $n. Siempre que te topes con esta magia vil, disípala.\n\nYo he cumplido mi tarea. La Luz me llama.\n\nBuena suerte, y recuerda que el cálido abrazo de la Luz siempre te acompaña.', 38134), -- -Unknown-
(58923, 0, 0, 0, 0, 0, 0, 0, 0, 'Quienes sirvan a la Luz conocerán su bendición. Acepta este regalo, paladín.\n\nInvócala cuando no tengas más fuerzas y cuando toda la esperanza parezca perdida. La Luz te protegerá del peligro.', 38134); -- -Unknown-



UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56344 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56344 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59589 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55988 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55990 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=55981 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56839 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56344 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=56344 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58946 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59254 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (59589 /*-Unknown-*/, 58946 /*-Unknown-*/, 58923 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59589, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58946, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(58923, 6, 5, 6, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55989; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55989; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55988; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55988; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55990; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=55981; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=56839; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=56839; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=56344; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59254; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=59254; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID` IN (58983 /*-Unknown-*/, 58909 /*-Unknown-*/, 55992 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58983, 0, 1, 0, 0, 'Gracias por venir.', 38134), -- -Unknown-
(58909, 0, 1, 0, 0, '¿Darlene te ha dado el entrenamiento necesario?', 38134), -- -Unknown-
(55992, 0, 0, 0, 0, '¡Debes ir y matar a Gor\'groth antes de que sea demasiado tarde!', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=55174; -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`ID`=245111 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(245111, 0, 530, -3560.52001953125, 583.3499755859375, 10.93999958038330078, 38134); -- Spell: 245111 (Portal: Black Temple) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (60649 /*60649 (Black Lamb)*/, 174534 /*174534 (Mey) - Read Scroll*/, 163048 /*163048 (InvisBunny) - Necrotic Field (DNT)*/, 162998 /*162998 (Yorah)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(60649, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 60649 (Black Lamb)
(174534, 0, 0, 0, 1, 0, 0, 0, 0, '314649'), -- 174534 (Mey) - Read Scroll
(163048, 0, 0, 0, 1, 0, 0, 0, 0, '317220'), -- 163048 (InvisBunny) - Necrotic Field (DNT)
(162998, 0, 0, 0, 1, 0, 14590, 0, 0, ''); -- 162998 (Yorah)

UPDATE `creature_template_addon` SET `auras`='281526' WHERE `entry`=135520; -- 135520
UPDATE `creature_template_addon` SET `auras`='292845' WHERE `entry`=149374; -- 149374 (FX Stalker)
UPDATE `creature_template_addon` SET `auras`='79977 79976' WHERE `entry`=61840; -- 61840 (Naanae)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=176220; -- 176220 (Antoinette Jardenne)
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=51998; -- 51998 (Arthur Huwe)
UPDATE `creature_template_addon` SET `auras`='98892 228687 228695' WHERE `entry`=114832; -- 114832 (PvP Training Dummy)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=1286; -- 1286 (Edna Mullby)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=1302; -- 1302 (Bernard Gump)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=1275; -- 1275 (Kyra Señalo)
UPDATE `creature_template_addon` SET `mount`=29284, `auras`='78855' WHERE `entry`=42218; -- 42218 (Guardia Real de Ventormenta)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=121541; -- 121541 (Ban-Lu)
UPDATE `creature_template_addon` SET `auras`='214567 305886' WHERE `entry`=156821; -- 156821 (Clamasombras Mazoscuro)
UPDATE `creature_template_addon` SET `auras`='321820' WHERE `entry`=153582; -- 153582 (Wug)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=153239; -- 153239 (Ogre Brute)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=152571; -- 152571 (Harpy Snatcher)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=156900; -- 156900 (Hrun el Exiliado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=160394; -- 160394 (Barrow Spider)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=160433; -- 160433 (Barrow Spiderling)
UPDATE `creature_template_addon` SET `auras`='305513' WHERE `entry`=156799; -- 156799 (Henry Garrick)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=153964; -- 153964 (Pico sangrante)
UPDATE `creature_template_addon` SET `aiAnimKit`=18518 WHERE `entry`=156345; -- 156345 (Grifo Martillo Salvaje)


UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=128630 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=43103 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=47688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=93307 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=93296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=35365 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=24729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=34998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=34997 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=861, `VerifiedBuild`=38134 WHERE (`Entry`=15187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=60649 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=741, `VerifiedBuild`=38134 WHERE (`Entry`=174530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=741, `VerifiedBuild`=38134 WHERE (`Entry`=174534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=741, `VerifiedBuild`=38134 WHERE (`Entry`=174529 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=741, `VerifiedBuild`=38134 WHERE (`Entry`=163048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=741, `VerifiedBuild`=38134 WHERE (`Entry`=162998 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=5, `ContentTuningID`=957 WHERE (`Entry`=160737 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80051;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79383;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33220;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=25899;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2208;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2459;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37116;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99500;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63521;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=63522;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29796;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29515;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=29514;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=15321;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5 WHERE `DisplayID`=5565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=87182;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42906;
UPDATE `creature_model_info` SET `BoundingRadius`=0.322235822677612304, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=80910;
UPDATE `creature_model_info` SET `BoundingRadius`=2.104584932327270507, `CombatReach`=1.346938848495483398 WHERE `DisplayID`=52656;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=95040;
UPDATE `creature_model_info` SET `BoundingRadius`=2.125280141830444335, `CombatReach`=1.5 WHERE `DisplayID`=283;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=79614;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=70722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.798952639102935791, `CombatReach`=1.125 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277218431234359741, `CombatReach`=0.649999976158142089 WHERE `DisplayID`=2177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.798952639102935791, `CombatReach`=1.125 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `BoundingRadius`=0.514177203178405761, `CombatReach`=1.875 WHERE `DisplayID`=66292;
UPDATE `creature_model_info` SET `BoundingRadius`=0.334899783134460449, `CombatReach`=0.4375 WHERE `DisplayID`=75374;


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=176220 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(176220, 1, 2202, 0, 0, 0, 0, 0, 0, 0, 0); -- Antoinette Jardenne

UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=176192 AND `ID`=1); -- Xavier Carpintero
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=42218 AND `ID`=1); -- Guardia Real de Ventormenta

DELETE FROM `gossip_menu` WHERE (`MenuId`=25353 AND `TextId`=39570) OR (`MenuId`=25116 AND `TextId`=39583) OR (`MenuId`=25098 AND `TextId` IN (39600,39558)) OR (`MenuId`=25099 AND `TextId`=39559);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25353, 39570, 38134), -- 164952 (Ezul'aan)
(25116, 39583, 38134), -- 164952 (Ezul'aan)
(25098, 39600, 38134), -- 162998 (Yorah)
(25099, 39559, 38134), -- 162998 (Yorah)
(25098, 39558, 38134); -- 162998 (Yorah)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=685 AND `TextId`=1235); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=25353 AND `OptionIndex`=6) OR (`MenuId`=25098 AND `OptionIndex` IN (1,0)) OR (`MenuId`=25099 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(25353, 6, 0, 'Cuéntame qué opciones de especialización tengo.', 0, 38134),
(25098, 1, 0, 'Necesito que reduzcas el tiempo de reutilización de Escudo divino.', 0, 38134),
(25099, 0, 0, 'Daré todo de mí para servir a la Luz. Lo juro.', 0, 38134),
(25098, 0, 0, '¿Qué desea que haga la Luz?', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=25353 AND `OptionIndex`=6) OR (`MenuId`=25098 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(25353, 6, 25116, 0),
(25098, 0, 25099, 0);




UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128630; -- Cazadora firmemar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=43103; -- Trillador Puntazul
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=47688; -- Officer Connelly
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=93307; -- Rygarius
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=93296; -- Café
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=256 WHERE `entry`=35365; -- Behsten
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=24729; -- Alicia
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=34998; -- Alison Devay
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=34997; -- Devin Valle Lejano
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=30, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=15187; -- Emisaria Cenarion Lunajade
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=164939; -- Signilda Forjadura
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=164957; -- Camille Taylor
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=164954; -- Juisheng Semigarra
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=164949; -- Patrice Lancaster
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=44252; -- Karin
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry`=43694; -- Katie Stokx
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3508; -- Mikey
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3507; -- Andi
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3512; -- Jimmy
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3511; -- Steven
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3510; -- Oposti
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3509; -- Geoff
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3505; -- Pat
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3513; -- Señorita Danna
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=8670; -- Subastador Chilton
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=15659; -- Subastadora Jaxon
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=8719; -- Subastador Fitch
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=14438; -- Oficial Pomeroy
UPDATE `creature_template` SET `gossip_menu_id`=685 WHERE `entry`=3518; -- Thomas Molina
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=14423; -- Oficial Jaxon
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=158637; -- Orbe guía
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=60649; -- Black Lamb
UPDATE `creature_template` SET `gossip_menu_id`=25162 WHERE `entry`=154169; -- Captain Garrick
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2968, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=174530; -- Pem
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `faction`=2968, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=174534; -- Mey
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `BaseAttackTime`=2000 WHERE `entry`=174529; -- Jard
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=156954; -- Captain Kelra
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=161306; -- Invisible Stalker
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=155733; -- Cofre del tesoro escondido
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=153211; -- Meredy Huntswell
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=163048; -- InvisBunny
UPDATE `creature_template` SET `gossip_menu_id`=25098, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=162998; -- Yorah
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=156932; -- Ralia Dreamchaser
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=156929; -- Ralia Dreamchaser
UPDATE `creature_template` SET `gossip_menu_id`=24886 WHERE `entry`=161666; -- Austin Huxworth
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.571428596973419189 WHERE `entry`=153964; -- Pico sangrante
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.571428596973419189 WHERE `entry`=153266; -- Zarpatroz el Terrible
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=150238; -- Geomante jabaespín
UPDATE `creature_template` SET `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=17 WHERE `entry`=160737; -- Muñeco de combate


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=54933 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=58923 AND `Idx`=0);

DELETE FROM `creature_template` WHERE `entry`=158142;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(158142, 0, 0, 'Margarita', '', NULL, NULL, NULL, 0, 0, 0, 1, 0, 0, 0, 0, 12, 0, 0, 1, 1, 0, 1890, 38134); -- Daisy


UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=158683 AND `Idx`=0); -- Sunsoaked Flitter

DELETE FROM `gameobject_template` WHERE `entry`=342068;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(342068, 10, 28714, 'Altar necrótico', 'questinteract', 'Destruyendo', '', 1, 2741, 0, 0, 1, 0, 0, 0, 0, 0, 0, 344119, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 741, 38134); -- Altar necrótico



UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=341951 AND `Idx`=0); -- Cicuta marchita

DELETE FROM `npc_text` WHERE `ID` IN (39583 /*39583*/, 39600 /*39600*/, 39559 /*39559*/, 39558 /*39558*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39583, 1, 0, 0, 0, 0, 0, 0, 0, 187308, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39583
(39600, 1, 0, 0, 0, 0, 0, 0, 0, 187403, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39600
(39559, 1, 0, 0, 0, 0, 0, 0, 0, 187213, 0, 0, 0, 0, 0, 0, 0, 38134), -- 39559
(39558, 1, 0, 0, 0, 0, 0, 0, 0, 187212, 0, 0, 0, 0, 0, 0, 0, 38134); -- 39558

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=1235; -- 1235


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0


UPDATE `conversation_actors` SET `ConversationActorId`=59733, `VerifiedBuild`=38134 WHERE (`ConversationId`=5422 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59733, `VerifiedBuild`=38134 WHERE (`ConversationId`=5422 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59733, `VerifiedBuild`=38134 WHERE (`ConversationId`=5422 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59734, `VerifiedBuild`=38134 WHERE (`ConversationId`=5423 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59734, `VerifiedBuild`=38134 WHERE (`ConversationId`=5423 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59734, `VerifiedBuild`=38134 WHERE (`ConversationId`=5423 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59734, `VerifiedBuild`=38134 WHERE (`ConversationId`=5423 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59732, `VerifiedBuild`=38134 WHERE (`ConversationId`=5421 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59732, `VerifiedBuild`=38134 WHERE (`ConversationId`=5421 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59732, `VerifiedBuild`=38134 WHERE (`ConversationId`=5421 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59730, `VerifiedBuild`=38134 WHERE (`ConversationId`=5419 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59730, `VerifiedBuild`=38134 WHERE (`ConversationId`=5419 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59730, `VerifiedBuild`=38134 WHERE (`ConversationId`=5419 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=59730, `VerifiedBuild`=38134 WHERE (`ConversationId`=5419 AND `Idx`=0);


UPDATE `conversation_line_template` SET `StartTime`=15864, `VerifiedBuild`=38134 WHERE `Id`=12152;
UPDATE `conversation_line_template` SET `StartTime`=10257, `VerifiedBuild`=38134 WHERE `Id`=12151;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=12150;
UPDATE `conversation_line_template` SET `StartTime`=24457, `VerifiedBuild`=38134 WHERE `Id`=12156;
UPDATE `conversation_line_template` SET `StartTime`=14192, `VerifiedBuild`=38134 WHERE `Id`=12155;
UPDATE `conversation_line_template` SET `StartTime`=5606, `VerifiedBuild`=38134 WHERE `Id`=12154;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=12153;
UPDATE `conversation_line_template` SET `StartTime`=13859, `VerifiedBuild`=38134 WHERE `Id`=12149;
UPDATE `conversation_line_template` SET `StartTime`=6971, `VerifiedBuild`=38134 WHERE `Id`=12148;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=12147;
UPDATE `conversation_line_template` SET `StartTime`=32239, `VerifiedBuild`=38134 WHERE `Id`=12145;
UPDATE `conversation_line_template` SET `StartTime`=18423, `VerifiedBuild`=38134 WHERE `Id`=12144;
UPDATE `conversation_line_template` SET `StartTime`=9630, `VerifiedBuild`=38134 WHERE `Id`=12143;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=12142;


UPDATE `conversation_template` SET `LastLineEndTime`=28460, `VerifiedBuild`=38134 WHERE `Id`=5423;
UPDATE `conversation_template` SET `LastLineEndTime`=19373, `VerifiedBuild`=38134 WHERE `Id`=5421;
UPDATE `conversation_template` SET `LastLineEndTime`=22818, `VerifiedBuild`=38134 WHERE `Id`=5422;
UPDATE `conversation_template` SET `LastLineEndTime`=40280, `VerifiedBuild`=38134 WHERE `Id`=5419;


UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=298459; -- Pergamino de Hiel de corazón
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=278671; -- Talismán maldito
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=278670; -- Talismán maldito
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=5605 WHERE `entry`=226941; -- Impacto de sangre
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=272198; -- Talismán maldito


UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47978 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47978 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47978 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47978 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47969 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=47968 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48622 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-


UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47980; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47980; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47981; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47981; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47979; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47978; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47968; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=47968; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID` IN (58983 /*-Unknown-*/, 58909 /*-Unknown-*/, 55992 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58983, 0, 1, 0, 0, 'Gracias por venir.', 38134), -- -Unknown-
(58909, 0, 1, 0, 0, '¿Darlene te ha dado el entrenamiento necesario?', 38134), -- -Unknown-
(55992, 0, 0, 0, 0, '¡Debes ir y matar a Gor\'groth antes de que sea demasiado tarde!', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=55174; -- -Unknown-


UPDATE `creature_template_addon` SET `aiAnimKit`=13899 WHERE `entry`=130164; -- 130164 (Jabalí de las Tierras Altas)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=124885; -- 124885 (Fauceoscura embrujado)
UPDATE `creature_template_addon` SET `auras`='248069' WHERE `entry`=124890; -- 124890 (Escarbueso embrujado)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='123169' WHERE `entry`=127806; -- 127806 (Gran venado montés)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='123169' WHERE `entry`=127807; -- 127807 (Cierva montesa)
UPDATE `creature_template_addon` SET `aiAnimKit`=8181 WHERE `entry`=124306; -- 124306 (Lawrence Levy)
UPDATE `creature_template_addon` SET `auras`='46598' WHERE `entry`=124405; -- 124405 (Cuervo picoteador)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=128852; -- 128852 (Halcón del viento gélido)
UPDATE `creature_template_addon` SET `aiAnimKit`=3449 WHERE `entry`=130684; -- 130684 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes2`=257, `aiAnimKit`=13506, `auras`='246932' WHERE `entry`=124499; -- 124499 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=124497; -- 124497 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=128384; -- 128384
UPDATE `creature_template_addon` SET `auras`='105944' WHERE `entry`=130359; -- 130359


UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=124922 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=124306 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=124405 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78257;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=36743;


UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21872 AND `TextId`=33431); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21873 AND `TextId`=33432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21873 AND `TextId`=33432); -- 0

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=21873 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21873, 0, 21872, 0);


UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=124953; -- Helena Gentil
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33088 WHERE `entry`=124922; -- Helena Gentil
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=124885; -- Fauceoscura embrujado
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=127806; -- Gran venado montés
UPDATE `creature_template` SET `faction`=190 WHERE `entry`=127807; -- Cierva montesa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124306; -- Lawrence Levy
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=124173; -- Enjambre de moscapestosa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124405; -- Cuervo picoteador
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=129810; -- Tarántula patas de rubí
UPDATE `creature_template` SET `gossip_menu_id`=21872 WHERE `entry`=130419; -- Cyril White
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=124499; -- Fallhaven Villager
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=124382; -- Bonepicker Raven
UPDATE `creature_template` SET `unit_flags`=536904448 WHERE `entry`=124497; -- Fallhaven Villager
UPDATE `creature_template` SET `gossip_menu_id`=21990 WHERE `entry`=132146; -- -Unknown-


UPDATE `quest_template` SET `RewardMoney`=89550, `RewardBonusMoney`=240, `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `LogTitle`='Familiares furiosos', `LogDescription`='Mata 10 animales hechizados en las Laderas Ocultas.', `QuestDescription`='<La fauna de las laderas parece estar bajo el hechizo de Helena, y este aldeano es una de sus víctimas. \n\nDeben ser los culpables de las desapariciones recientes en Amparo del Ocaso.\n\nQuizá si sus números se redujeran ya no serían una amenaza tan grande para los habitantes del pueblo.>', `VerifiedBuild`=38134 WHERE `ID`=47980; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=89550, `RewardBonusMoney`=240, `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `LogTitle`='Rota maldición', `LogDescription`='Destruye $1oa efigies menores en las Laderas Ocultas.', `QuestDescription`='<En su apuro, parece que Helena olvidó su libro de hechizos. En las páginas del libro se detallan las instrucciones del ritual que utilizó para atrapar a los aldeanos de Amparo del Ocaso. \n\nParece que la efigie que impide que el hechizo se disipe está protegida por otras más pequeñas que rodean la aldea. Si las destruyes, quizás afecte a la efigie principal que aflige a los aldeanos.>', `QuestCompletionLog`='Regresa a la efigie maldita.', `VerifiedBuild`=38134 WHERE `ID`=47981; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=179100, `RewardBonusMoney`=300, `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `LogTitle`='Cacería de brujas', `LogDescription`='Escucha la historia de Helena Gentil en las Laderas Ocultas.', `QuestDescription`='¿Una maldición afecta a los aldeanos? Madre mía, ¡qué espanto!\n\nAunque, a decir verdad, han sucedido cosas muy extrañas en Amparo del Ocaso últimamente. ¿Me pregunto si estos serán los culpables?\n\nToma asiento y bebe un poco de té. Te contaré todo lo que sé.', `VerifiedBuild`=38134 WHERE `ID`=47979; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=8440, `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `LogTitle`='La vieja bruja díscola', `LogDescription`='Confronta a Helena Gentil en su casa en las afueras de Amparo del Ocaso.', `QuestDescription`='<El libro mayor indica que una vieja llamada Helena Gentil se instaló en una casa cerca del pueblo.\n\nLos mensajes de los aldeanos indican que estuvo un tanto involucrada en los distintos males que han abatido a la aldea en estos tiempos. \n\nQuizá sepa algo sobre la causa de este hechizo, si es que no la afectó a ella también.>', `VerifiedBuild`=38134 WHERE `ID`=47978; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=168800, `RewardBonusMoney`=480, `FlagsEx`=2097216, `AllowableRaces`=6130900294268439629, `LogTitle`='La maldición de Amparo del Ocaso', `VerifiedBuild`=38134 WHERE `ID`=47969; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=84400, `RewardBonusMoney`=240, `FlagsEx`=2105408, `AllowableRaces`=6130900294268439629, `LogTitle`='Señales y augurios', `LogDescription`='Investiga las escrituras de los aldeanos en Amparo del Ocaso.', `QuestDescription`='<El boletín que estaba publicando el alcalde White cuando lo alcanzó el hechizo indica que habrían ocurrido algunos acontecimientos extraños en la ciudad últimamente.\n\nPosiblemente, estos eventos estén conectados con lo que sea que haya lanzado el hechizo sobre la aldea.\n\nTal vez existan registros del resto de los aldeanos que puedan ayudarnos a encontrar la fuente de esta magia.>', `QuestCompletionLog`='Regresa al Registro de Amparo del Ocaso.', `VerifiedBuild`=38134 WHERE `ID`=47968; -- -Unknown-


DELETE FROM `areatrigger_template` WHERE `Id` IN (19538, 24351);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(19538, 1, 1, 0, 4, 4, 7.5, 4, 4, 7.5, 38134),
(24351, 1, 0, 0, 2, 2, 0, 0, 0, 0, 38134);

UPDATE `areatrigger_template` SET `Flags`=0 WHERE `Id`=9181;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=21554;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=12929;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=14881 AND `AreaTriggerId`=19538);
REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(14881, 19538, 0, 0, 0, 0, 0, 0, 0, 2624, 10000, 38134); -- SpellId : 279302


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `AnimId`=0, `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4435 AND `AreaTriggerId`=9181); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2574, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=17311 AND `AreaTriggerId`=21554); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=4436 AND `AreaTriggerId`=3841); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
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
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4000 WHERE (`SpellMiscId`=11995 AND `AreaTriggerId`=16705); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
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
UPDATE `spell_areatrigger` SET `AnimId`=0, `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0


REPLACE INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(9894, 51642, 0, 38134),
(9918, 51642, 0, 38134),
(10180, 64220, 0, 38134),
(9925, 51642, 0, 38134),
(10179, 64220, 0, 38134),
(10240, 64220, 0, 38134),
(9026, 57728, 1, 38134),
(10031, 64220, 0, 38134),
(9964, 64220, 0, 38134),
(9025, 57728, 1, 38134),
(9965, 64220, 0, 38134);



UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6067 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6067 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=6067 AND `Idx`=0);

DELETE FROM `conversation_line_template` WHERE `Id` IN (23062, 23144, 23856, 23156, 23855, 23927, 23548, 23266, 25053, 25052);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(23062, 0, 82, 0, 0, 38134),
(23144, 0, 82, 0, 0, 38134),
(23856, 0, 82, 0, 0, 38134),
(23156, 0, 82, 0, 0, 38134),
(23855, 0, 82, 0, 0, 38134),
(23927, 0, 101, 0, 0, 38134),
(23548, 0, 90, 0, 0, 38134),
(23266, 0, 101, 0, 0, 38134),
(25053, 5900, 0, 0, 0, 38134),
(25052, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `StartTime`=9250, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13463;
UPDATE `conversation_line_template` SET `StartTime`=3950, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13462;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=13461;



DELETE FROM `conversation_template` WHERE `Id` IN (9894, 10180, 9925, 9026, 9025, 9965, 10637, 10240, 9964, 10031, 9918, 10179);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(9894, 23062, 5675, 0, 38134),
(10180, 23856, 6071, 0, 38134),
(9925, 23156, 4771, 0, 38134),
(9026, 20365, 5706, 0, 38134),
(9025, 20363, 6884, 0, 38134),
(9965, 23267, 8273, 0, 38134),
(10637, 25052, 7550, 0, 38134),
(10240, 23927, 3722, 0, 38134),
(9964, 23266, 7970, 0, 38134),
(10031, 23548, 10923, 0, 38134),
(9918, 23144, 6367, 0, 38134),
(10179, 23855, 8590, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=14500, `VerifiedBuild`=38134 WHERE `Id`=6067;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (305841 /*Elixir maravilloso de Miriam*/, 310624 /*Cuerda de escalar*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(305841, 0, 0, 2150, 0), -- Elixir maravilloso de Miriam
(310624, 0, 32, 2100, 0); -- Cuerda de escalar

UPDATE `gameobject_template_addon` SET `WorldEffectID`=6026 WHERE `entry`=307750; -- Cuerda enrollada
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=216247; -- Horde Banner - Ground, Spear, 1.5
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=307028; -- Granadas de azerita
UPDATE `gameobject_template_addon` SET `WorldEffectID`=11225 WHERE `entry`=307837; -- Expositor de armas
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=312184; -- Salto a propulsión de Grizzek
UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=320324; -- Poción de bendición de florecimiento
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=8192 WHERE `entry`=215396; -- Suministros de Fuego Infernal
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=284469; -- Cofre del tesoro pequeño


DELETE FROM `quest_poi` WHERE (`QuestID`=51226 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51226 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(51226, 0, 1, 0, 335196, 136901, 1643, 895, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51226, 0, 0, -1, 0, 0, 1643, 895, 0, 0, 0, 0, 0, 1451204, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53814 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53814 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=54237 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=54237 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49072 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49072 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49734 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49734 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49715 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49715 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51226 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51226 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(51226, 1, 7, 107, -1185, 111, 38134), -- -Unknown-
(51226, 1, 6, 99, -1143, 102, 38134), -- -Unknown-
(51226, 1, 5, 154, -1034, 110, 38134), -- -Unknown-
(51226, 1, 4, 266, -1006, 111, 38134), -- -Unknown-
(51226, 1, 3, 277, -1023, 116, 38134), -- -Unknown-
(51226, 1, 2, 302, -1081, 127, 38134), -- -Unknown-
(51226, 1, 1, 307, -1183, 100, 38134), -- -Unknown-
(51226, 1, 0, 124, -1232, 92, 38134), -- -Unknown-
(51226, 0, 0, 231, -993, 110, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53699 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53814 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53814 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=54237 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=54237 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53951 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52475 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49066 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48909 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49039 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49072 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49072 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53711 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48874 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48879 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=48873 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49069 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49028 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50356 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50352 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50351 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50249 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49720 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49716 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49734 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49734 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49733 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49715 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49715 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-


DELETE FROM `quest_details` WHERE `ID`=53711;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(53711, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49066; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49066; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48909; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48909; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49039; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49072; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48874; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48879; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48873; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=48873; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49069; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49028; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50356; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50356; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50352; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50352; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50351; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50249; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50249; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49720; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49720; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49716; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49734; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51226; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51226; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49733; -- -Unknown-

DELETE FROM `quest_request_items` WHERE `ID` IN (58983 /*-Unknown-*/, 58909 /*-Unknown-*/, 55992 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(58983, 0, 1, 0, 0, 'Gracias por venir.', 38134), -- -Unknown-
(58909, 0, 1, 0, 0, '¿Darlene te ha dado el entrenamiento necesario?', 38134), -- -Unknown-
(55992, 0, 0, 0, 0, '¡Debes ir y matar a Gor\'groth antes de que sea demasiado tarde!', 38134); -- -Unknown-

UPDATE `quest_request_items` SET `VerifiedBuild`=38134 WHERE `ID`=55174; -- -Unknown-
UPDATE `quest_request_items` SET `CompletionText`='Oí que se enfurecen si destruyes las estructuras de hielo más grandes que hay en el área. ¡Haz lo que sabes hacer y destruye a todos los que te cruces en el camino!' WHERE `ID`=49066; -- -Unknown-
UPDATE `quest_request_items` SET `CompletionText`='¿Necesitas algo de mí?' WHERE `ID`=49028; -- -Unknown-
UPDATE `quest_request_items` SET `CompletionText`='¿Trajiste el polvo?' WHERE `ID`=50352; -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (292018,282366,286959));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(292018, 0, 1, -3484.60009765625, -4663.240234375, 17.71999931335449218, 38134), -- Spell: 292018 (Teleport: Theramore) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(282366, 0, 1643, 522.280029296875, -696.08001708984375, 49.470001220703125, 38134), -- Spell: 282366 (Summon Proudmore Gyrphon) Efffect: 28 (SPELL_EFFECT_SUMMON)
(286959, 0, 1, 6666.02001953125, -79.4599990844726562, 38.84999847412109375, 38134); -- Spell: 286959 (Teleport to Darkshore) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (139287 /*139287 (Denteserra)*/, 144729 /*144729 (Defensor de Boralus) - Enrage*/, 144730 /*144730 (Sanamareas de Boralus)*/, 144932 /*144932 (Grifo Valiente)*/, 144731 /*144731 (Mascahuesos Renegado)*/, 144728 /*144728 (Rompepuertas arrasador)*/, 145134 /*145134 (Gryphon Handler)*/, 145282 /*145282 (Rabiosa de los Honorables) - Blood Fury*/, 144676 /*144676 (Quest Bunny - Zeppelin Random Blasts - West)*/, 144673 /*144673 (Quest Bunny - Zeppelin Destruction West) - Zeppelin Burning*/, 144672 /*144672 (Carga de azerita)*/, 144675 /*144675 (Quest Bunny - Zeppelin Random Blasts -  East)*/, 144660 /*144660 (Quest Bunny - Zeppelin Destruction East) - Zeppelin Burning*/, 144674 /*144674 (Carga de azerita)*/, 145308 /*145308 (Sargento Colmilloacero)*/, 145310 /*145310 (Aprendiz de Orgrimmar)*/, 145818 /*145818 (Teniente Haas)*/, 145817 /*145817 (Capitán Holgresh) - Lightning Shield*/, 144677 /*144677 (Quest Bunny - Periodic Cannon Fire)*/, 144659 /*144659 (Carga de azerita)*/, 144722 /*144722 (Togoth Brazo Cruel)*/, 146684 /*146684 (Cañonero petragrís)*/, 144724 /*144724 (Piloto de zepelín goblin)*/, 149257 /*149257 (Fizzi Arcojalata)*/, 144721 /*144721 (Experto en pólvora negra)*/, 144667 /*144667 (Cañón de asedio)*/, 144719 /*144719 (Cañonero de los Honorables)*/, 145392 /*145392 (Embajador Gaines)*/, 145395 /*145395 (Katrianna) - Elune's Guidance*/, 148268 /*148268 (Spell Bunny) - 6FX Bonfire*/, 147236 /*147236 (Lanzaflamas de la Séptima Legión) - No NPC Damage Below Override Points%*/, 146692 /*146692 (Guardia de Estación Oriental)*/, 152173 /*152173 (Guardia de Kennings)*/, 141051 /*141051 (Matriarca pelóxido)*/, 137152 /*137152 (Vigilante de la compañía)*/, 148906 /*148906 (Ollie)*/, 147645 /*147645 (Tizzy Engranéctica)*/, 147201 /*147201 (Alfil)*/, 147666 /*147666 (Manapuf)*/, 147203 /*147203 (Sir Steve)*/, 148900 /*148900 (Ñami)*/, 148899 /*148899 (Izzy)*/, 148902 /*148902 (Bobi)*/, 174526 /*174526 (Gizmo)*/, 150471 /*150471 (Dexter)*/, 148901 /*148901 (Rubí)*/, 158255 /*158255 (Corcel kultirano)*/, 145370 /*145370 (Huérfano kultirano)*/, 158377 /*158377 (Fortuna Envoltios)*/, 158379 /*158379 (Serafina Tuercanix) - Cosmetic - SitGround and Use - Breakable*/, 158326 /*158326 (Telecóptero)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(139287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 139287 (Denteserra)
(144729, 0, 0, 0, 1, 0, 0, 0, 0, '218121'), -- 144729 (Defensor de Boralus) - Enrage
(144730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144730 (Sanamareas de Boralus)
(144932, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144932 (Grifo Valiente)
(144731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144731 (Mascahuesos Renegado)
(144728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144728 (Rompepuertas arrasador)
(145134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145134 (Gryphon Handler)
(145282, 0, 0, 0, 1, 0, 0, 0, 0, '289976'), -- 145282 (Rabiosa de los Honorables) - Blood Fury
(144676, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144676 (Quest Bunny - Zeppelin Random Blasts - West)
(144673, 0, 0, 0, 1, 0, 0, 0, 0, '281924'), -- 144673 (Quest Bunny - Zeppelin Destruction West) - Zeppelin Burning
(144672, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144672 (Carga de azerita)
(144675, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144675 (Quest Bunny - Zeppelin Random Blasts -  East)
(144660, 0, 0, 0, 1, 0, 0, 0, 0, '281924'), -- 144660 (Quest Bunny - Zeppelin Destruction East) - Zeppelin Burning
(144674, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144674 (Carga de azerita)
(145308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145308 (Sargento Colmilloacero)
(145310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145310 (Aprendiz de Orgrimmar)
(145818, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145818 (Teniente Haas)
(145817, 0, 0, 0, 1, 0, 0, 0, 0, '19514'), -- 145817 (Capitán Holgresh) - Lightning Shield
(144677, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144677 (Quest Bunny - Periodic Cannon Fire)
(144659, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144659 (Carga de azerita)
(144722, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144722 (Togoth Brazo Cruel)
(146684, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 146684 (Cañonero petragrís)
(144724, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144724 (Piloto de zepelín goblin)
(149257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 149257 (Fizzi Arcojalata)
(144721, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144721 (Experto en pólvora negra)
(144667, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144667 (Cañón de asedio)
(144719, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144719 (Cañonero de los Honorables)
(145392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145392 (Embajador Gaines)
(145395, 0, 0, 0, 1, 0, 0, 0, 0, '273609'), -- 145395 (Katrianna) - Elune's Guidance
(148268, 0, 0, 0, 1, 0, 0, 0, 0, '161766'), -- 148268 (Spell Bunny) - 6FX Bonfire
(147236, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 147236 (Lanzaflamas de la Séptima Legión) - No NPC Damage Below Override Points%
(146692, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 146692 (Guardia de Estación Oriental)
(152173, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152173 (Guardia de Kennings)
(141051, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 141051 (Matriarca pelóxido)
(137152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137152 (Vigilante de la compañía)
(148906, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 148906 (Ollie)
(147645, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147645 (Tizzy Engranéctica)
(147201, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147201 (Alfil)
(147666, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147666 (Manapuf)
(147203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 147203 (Sir Steve)
(148900, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 148900 (Ñami)
(148899, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 148899 (Izzy)
(148902, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 148902 (Bobi)
(174526, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174526 (Gizmo)
(150471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 150471 (Dexter)
(148901, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 148901 (Rubí)
(158255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158255 (Corcel kultirano)
(145370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145370 (Huérfano kultirano)
(158377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158377 (Fortuna Envoltios)
(158379, 0, 0, 0, 1, 0, 0, 0, 0, '264338'), -- 158379 (Serafina Tuercanix) - Cosmetic - SitGround and Use - Breakable
(158326, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- 158326 (Telecóptero)

UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=144727; -- 144727 (Chamán rompenubes)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='260824 247218' WHERE `entry`=144720; -- 144720 (Guerrero experimentado)
UPDATE `creature_template_addon` SET `auras`='165144' WHERE `entry`=148749; -- 148749 (Discípulo huojin)
UPDATE `creature_template_addon` SET `auras`='32064' WHERE `entry`=149515; -- 149515 (Rabioso de los Honorables)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=144958; -- 144958 (Bruto de los Honorables)
UPDATE `creature_template_addon` SET `auras`='120703' WHERE `entry`=126455; -- 126455
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=145028; -- 145028 (Cazador de las sombras de los Honorables)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=147168; -- 147168 (Adepto de la Séptima Legión)
UPDATE `creature_template_addon` SET `auras`='258089' WHERE `entry`=127413; -- 127413 (Kurek el Perdido)
UPDATE `creature_template_addon` SET `bytes1`=8, `aiAnimKit`=0, `auras`='' WHERE `entry`=127165; -- 127165
UPDATE `creature_template_addon` SET `auras`='29266' WHERE `entry`=126709; -- 126709
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=127976; -- 127976
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='109525' WHERE `entry`=126929; -- 126929
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126625; -- 126625
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=15826 WHERE `entry`=126953; -- 126953
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='244863' WHERE `entry`=133413; -- 133413 (Empleado de Neviza)
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=133024; -- 133024 (Maestra de establo Diana)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=133021; -- 133021 (Sobrestante Aquilón)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=130369; -- 130369 (Fernn el Traidor)
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry`=130363; -- 130363 (Amotinado fortalecido)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=130410; -- 130410 (Alabardero rebelde)
UPDATE `creature_template_addon` SET `auras`='259034' WHERE `entry`=130508; -- 130508 (Madre de linaje Razora)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=138286; -- 138286 (Halcón marino hambriento)
UPDATE `creature_template_addon` SET `bytes2`=2, `auras`='' WHERE `entry`=130326; -- 130326 (Halconero petragrís)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=130878; -- 130878 (Halcón marino entrenado)
UPDATE `creature_template_addon` SET `auras`='151597' WHERE `entry`=136901; -- 136901 (Saurolisco colmisalina)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=130358; -- 130358 (Marino petragrís)
UPDATE `creature_template_addon` SET `mount`=81692 WHERE `entry`=133399; -- 133399
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123264; -- 123264
UPDATE `creature_template_addon` SET `auras`='263410' WHERE `entry`=122452; -- 122452 (Foundry Worker)
UPDATE `creature_template_addon` SET `auras`='255593' WHERE `entry`=123226; -- 123226
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=126387; -- 126387
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=125326; -- 125326
UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=138738; -- 138738 (Bridgeport Sentry)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=143186; -- 143186
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=144030; -- 144030
UPDATE `creature_template_addon` SET `aiAnimKit`=547 WHERE `entry`=143144; -- 143144 (Dustin Fowler)
UPDATE `creature_template_addon` SET `aiAnimKit`=547 WHERE `entry`=143145; -- 143145 (Criss Replogle)
UPDATE `creature_template_addon` SET `auras`='273259' WHERE `entry`=143128; -- 143128
UPDATE `creature_template_addon` SET `auras`='277932' WHERE `entry`=137744; -- 137744
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=126496; -- 126496
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=143330; -- 143330
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137547; -- 137547 (Asistente de Punta Garfio)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=135783; -- 135783
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=144213; -- 144213
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=140421; -- 140421
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=134847; -- 134847
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='279123' WHERE `entry`=134722; -- 134722
UPDATE `creature_template_addon` SET `auras`='266042' WHERE `entry`=143793; -- 143793
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=141772; -- 141772
UPDATE `creature_template_addon` SET `bytes1`=6 WHERE `entry`=135604; -- 135604
UPDATE `creature_template_addon` SET `auras`='272105' WHERE `entry`=135889; -- 135889
UPDATE `creature_template_addon` SET `auras`='267132' WHERE `entry`=135792; -- 135792 (Boralus Worker)
UPDATE `creature_template_addon` SET `auras`='266042' WHERE `entry`=135603; -- 135603 (Boralus Civilian)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=135658; -- 135658
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=142457; -- 142457
UPDATE `creature_template_addon` SET `bytes2`=0, `aiAnimKit`=13903 WHERE `entry`=143248; -- 143248
UPDATE `creature_template_addon` SET `auras`='271334' WHERE `entry`=143259; -- 143259
UPDATE `creature_template_addon` SET `bytes1`=5 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=125005; -- 125005 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `auras`='266042' WHERE `entry`=123244; -- 123244
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=135677; -- 135677 (7th Legion Rifleman)
UPDATE `creature_template_addon` SET `auras`='275224' WHERE `entry`=143844; -- 143844
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142180; -- 142180
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=143502; -- 143502
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142166; -- 142166
UPDATE `creature_template_addon` SET `bytes2`=1, `aiAnimKit`=15780 WHERE `entry`=135675; -- 135675 (7th Legion Marine)
UPDATE `creature_template_addon` SET `bytes2`=257, `aiAnimKit`=0 WHERE `entry`=136633; -- 136633 (Harbor Guard)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=124805; -- 124805


UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144730 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144932 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144728 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145282 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144673 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144672 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144675 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145310 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145818 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145817 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144659 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144722 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=146684 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144724 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=149257 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144721 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144667 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=144719 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=145395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=148268 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=147236 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=146692 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139278 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=127481 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=131128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=128093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134540 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=141051 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134339 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134212 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134628 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133621 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133406 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134178 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=123713 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133428 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134370 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=134371 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133551 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133028 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133024 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133021 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130497 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=138284 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130364 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130363 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130410 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130508 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138286 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=132720 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130887 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=131019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130375 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=136948 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133035 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130556 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130326 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130878 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=136901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=130358 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143144 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143145 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138956 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138953 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138957 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138952 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139058 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139113 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138954 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138955 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142046 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142030 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142035 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142040 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142031 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142052 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142032 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142055 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138421 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=139053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142453 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137191 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137201 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142043 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142053 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142050 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142051 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142069 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142111 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=138410 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137196 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=144114 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137420 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137431 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137432 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137483 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=147645 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=147201 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=464, `VerifiedBuild`=38134 WHERE (`Entry`=147666 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142514 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137427 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142549 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142116 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142118 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143501 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142527 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=147203 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142125 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142124 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142122 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142129 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142130 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142507 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148900 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142541 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148902 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142505 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=174526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142092 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142091 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142065 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142513 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142090 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142563 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143721 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=150471 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=148901 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=142506 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=158255 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137547 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=145370 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=771, `VerifiedBuild`=38134 WHERE (`Entry`=158377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=771, `VerifiedBuild`=38134 WHERE (`Entry`=158379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=158326 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=9.9450531005859375, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=80474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.531285345554351806, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=67530;
UPDATE `creature_model_info` SET `BoundingRadius`=2.948759078979492187, `CombatReach`=3.520000219345092773, `VerifiedBuild`=38134 WHERE `DisplayID`=10612;
UPDATE `creature_model_info` SET `BoundingRadius`=0.290052592754364013, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88972;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65037;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38615;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88943;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306799978017807006, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=89043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=89044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=89045;
UPDATE `creature_model_info` SET `BoundingRadius`=0.397799968719482421, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=89215;
UPDATE `creature_model_info` SET `BoundingRadius`=0.483599990606307983, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=89216;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89146;
UPDATE `creature_model_info` SET `BoundingRadius`=0.828294098377227783, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89151;
UPDATE `creature_model_info` SET `BoundingRadius`=1.20196533203125, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84034;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89177;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85640;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `CombatReach`=1.875, `VerifiedBuild`=38134 WHERE `DisplayID`=88804;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372000008821487426, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88802;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85636;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89813;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84591;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=90240;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81158;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=88803;
UPDATE `creature_model_info` SET `BoundingRadius`=0.736249983310699462 WHERE `DisplayID`=49764;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88831;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89811;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=89064;
UPDATE `creature_model_info` SET `BoundingRadius`=0.367200016975402832, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=89065;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89003;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=89148;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=90119;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89152;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89812;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=89810;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89187;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89153;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416666418313980102, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89149;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=89179;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416400015354156494, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89143;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249600008130073547, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.416400015354156494, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=89145;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=76856;
UPDATE `creature_model_info` SET `BoundingRadius`=2.026976823806762695, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=10944;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=2.434175491333007812, `CombatReach`=5 WHERE `DisplayID`=913;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=24978;
UPDATE `creature_model_info` SET `BoundingRadius`=1.947340369224548339, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=20827;
UPDATE `creature_model_info` SET `BoundingRadius`=0.927151322364807128 WHERE `DisplayID`=62863;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88692;
UPDATE `creature_model_info` SET `BoundingRadius`=0.964008271694183349, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=11611;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83047;
UPDATE `creature_model_info` SET `BoundingRadius`=1.45000004768371582, `CombatReach`=1.8125, `VerifiedBuild`=38134 WHERE `DisplayID`=33863;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=36635;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83046;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=84157;
UPDATE `creature_model_info` SET `BoundingRadius`=1.45000004768371582, `CombatReach`=1.8125, `VerifiedBuild`=38134 WHERE `DisplayID`=34068;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82904;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82903;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82902;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83088;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83048;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85179;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82666;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82664;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82663;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81271;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81195;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81161;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81272;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81273;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81530;
UPDATE `creature_model_info` SET `BoundingRadius`=3.108532428741455078, `CombatReach`=3.432000160217285156, `VerifiedBuild`=38134 WHERE `DisplayID`=81342;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=85817;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82614;
UPDATE `creature_model_info` SET `BoundingRadius`=1.66178131103515625, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=81085;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81532;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81533;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81165;
UPDATE `creature_model_info` SET `BoundingRadius`=0.28943634033203125, `CombatReach`=0.140000000596046447 WHERE `DisplayID`=81217;
UPDATE `creature_model_info` SET `BoundingRadius`=0.28943634033203125, `CombatReach`=0.140000000596046447, `VerifiedBuild`=38134 WHERE `DisplayID`=81216;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81270;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81159;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81289;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81290;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81127;
UPDATE `creature_model_info` SET `BoundingRadius`=1.163246870040893554, `CombatReach`=1.399999976158142089 WHERE `DisplayID`=81269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=30041;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83264;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88185;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88693;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88696;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86083;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86084;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86139;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86138;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167159661650657653, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=76516;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106639862060546, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=86546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=74487;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=72180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=81387;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87563;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87561;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106639862060546, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=86543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86114;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85198;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=85840;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `BoundingRadius`=0.308195561170578002, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=11709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=74789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106580257415771, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=74792;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88200;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88497;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85329;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85332;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85281;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=89751;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=87972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=75047;
UPDATE `creature_model_info` SET `BoundingRadius`=0.127860605716705322, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=45263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463575661182403564 WHERE `DisplayID`=52598;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463575661182403564, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=53517;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87668;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87582;
UPDATE `creature_model_info` SET `BoundingRadius`=0.180873200297355651, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=44820;
UPDATE `creature_model_info` SET `BoundingRadius`=0.531192958354949951 WHERE `DisplayID`=54854;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463575661182403564, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=96674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=79383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=79381;
UPDATE `creature_model_info` SET `BoundingRadius`=0.173778563737869262, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=68729;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463575661182403564, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=75814;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87568;
UPDATE `creature_model_info` SET `BoundingRadius`=0.173778563737869262, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=68845;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463575661182403564 WHERE `DisplayID`=52600;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87670;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=87578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.33942541480064392, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=87760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=63870;
UPDATE `creature_model_info` SET `BoundingRadius`=0.151963323354721069, `VerifiedBuild`=38134 WHERE `DisplayID`=76518;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85368;
UPDATE `creature_model_info` SET `BoundingRadius`=0.908434152603149414, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85892;
UPDATE `creature_model_info` SET `BoundingRadius`=1.282961130142211914, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=93453;
UPDATE `creature_model_info` SET `BoundingRadius`=0.55433821678161621, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=93451;
UPDATE `creature_model_info` SET `BoundingRadius`=0.290699988603591918, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=93521;
UPDATE `creature_model_info` SET `BoundingRadius`=0.290699988603591918, `CombatReach`=1.424999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=93508;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (144729,144730,145134,145282,145308,145310,145818,145817,144722,146684,144724,144721,144719,145392,145395,146692,152173)) OR (`ID`=2 AND `CreatureID`=144721);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(144729, 1, 158912, 0, 0, 159799, 0, 0, 0, 0, 0), -- Defensor de Boralus
(144730, 1, 155759, 0, 0, 155789, 0, 0, 155807, 0, 0), -- Sanamareas de Boralus
(145134, 1, 0, 0, 0, 0, 0, 0, 155816, 0, 0), -- Gryphon Handler
(145282, 1, 109233, 0, 0, 109233, 0, 0, 0, 0, 0), -- Rabiosa de los Honorables
(145308, 1, 110166, 0, 0, 0, 0, 0, 0, 0, 0), -- Sargento Colmilloacero
(145310, 1, 118400, 0, 0, 0, 0, 0, 0, 0, 0), -- Aprendiz de Orgrimmar
(145818, 1, 108922, 0, 0, 0, 0, 0, 0, 0, 0), -- Teniente Haas
(145817, 1, 117577, 0, 0, 117577, 0, 0, 0, 0, 0), -- Capitán Holgresh
(144722, 1, 94650, 0, 0, 0, 0, 0, 27507, 0, 0), -- Togoth Brazo Cruel
(146684, 1, 159585, 0, 0, 158597, 0, 0, 155816, 0, 0), -- Cañonero petragrís
(144724, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Piloto de zepelín goblin
(144721, 2, 31824, 0, 0, 0, 0, 0, 0, 0, 0), -- Experto en pólvora negra
(144721, 1, 2884, 0, 0, 0, 0, 0, 0, 0, 0), -- Experto en pólvora negra
(144719, 1, 107254, 0, 0, 0, 0, 0, 0, 0, 0), -- Cañonero de los Honorables
(145392, 1, 133271, 0, 0, 0, 0, 0, 0, 0, 0), -- Embajador Gaines
(145395, 1, 72486, 0, 0, 72486, 0, 0, 0, 0, 0), -- Katrianna
(146692, 1, 155799, 0, 0, 158911, 0, 0, 155816, 0, 0), -- Guardia de Estación Oriental
(152173, 1, 158900, 0, 0, 0, 0, 0, 155816, 0, 0); -- Guardia de Kennings

UPDATE `creature_equip_template` SET `ItemID1`=155799, `ItemID2`=159799 WHERE (`CreatureID`=139088 AND `ID`=2); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=118559 WHERE (`CreatureID`=135792 AND `ID`=7); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=118568 WHERE (`CreatureID`=123641 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=132642 AND `ID`=2); -- Kul Tiran Noble
UPDATE `creature_equip_template` SET `ItemID1`=161122 WHERE (`CreatureID`=135792 AND `ID`=5); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=155894 WHERE (`CreatureID`=135792 AND `ID`=4); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=80580 WHERE (`CreatureID`=134838 AND `ID`=3); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=155894 WHERE (`CreatureID`=134838 AND `ID`=2); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=80057 WHERE (`CreatureID`=135792 AND `ID`=2); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=135792 AND `ID`=1); -- Boralus Worker


UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21860 AND `TextId`=33402); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21860 AND `TextId`=33402); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22239 AND `TextId`=34072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22239 AND `TextId`=34072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22240 AND `TextId`=34073); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22239 AND `TextId`=34072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22239 AND `TextId`=34072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22239 AND `TextId`=34072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22233 AND `TextId`=34057); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22233 AND `TextId`=34057); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22223 AND `TextId`=34043); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22223 AND `TextId`=34043); -- 0

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=22239 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(22239, 0, 22240, 0);


UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=143968; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=139287; -- Denteserra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=143547; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2618, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=144729; -- Defensor de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2618, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=144730; -- Sanamareas de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=18432 WHERE `entry`=144932; -- Grifo Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144731; -- Mascahuesos Renegado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=144728; -- Rompepuertas arrasador
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=145134; -- Gryphon Handler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=145282; -- Rabiosa de los Honorables
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67651584, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144676; -- Quest Bunny - Zeppelin Random Blasts - West
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69748736, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144673; -- Quest Bunny - Zeppelin Destruction West
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67160064, `unit_flags3`=1 WHERE `entry`=144672; -- Carga de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67651584, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144675; -- Quest Bunny - Zeppelin Random Blasts -  East
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=69748736, `unit_flags3`=1, `dynamicflags`=128 WHERE `entry`=144660; -- Quest Bunny - Zeppelin Destruction East
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67160064, `unit_flags3`=1 WHERE `entry`=144674; -- Carga de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2500, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=145308; -- Sargento Colmilloacero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1835, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=145310; -- Aprendiz de Orgrimmar
UPDATE `creature_template` SET `minlevel`=50, `dynamicflags`=0 WHERE `entry`=145818; -- Teniente Haas
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=145817; -- Capitán Holgresh
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=34816 WHERE `entry`=144677; -- Quest Bunny - Periodic Cannon Fire
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67160064, `unit_flags3`=1 WHERE `entry`=144659; -- Carga de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=144722; -- Togoth Brazo Cruel
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=146684; -- Cañonero petragrís
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2201, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=144724; -- Piloto de zepelín goblin
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=144727; -- Chamán rompenubes
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=875, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=149257; -- Fizzi Arcojalata
UPDATE `creature_template` SET `speed_walk`=0.800000011920928955, `speed_run`=0.914285719394683837, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=144720; -- Guerrero experimentado
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=144721; -- Experto en pólvora negra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1735, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=67125248, `unit_flags3`=1 WHERE `entry`=144667; -- Cañón de asedio
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=144719; -- Cañonero de los Honorables
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=145392; -- Embajador Gaines
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=145395; -- Katrianna
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=148268; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `dynamicflags`=0 WHERE `entry`=147236; -- Lanzaflamas de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=146692; -- Guardia de Estación Oriental
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67108928 WHERE `entry`=127413; -- Kurek el Perdido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=127680; -- Cadáver de venado fresco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139278; -- Ranja
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=127677; -- Rataespín muerto
UPDATE `creature_template` SET `unit_flags`=67108864 WHERE `entry`=128774; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127481; -- Lord Kennings
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131128; -- Pingüino del glaciar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141696 WHERE `entry`=128093; -- Viejo Garrascarcha
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=32784 WHERE `entry`=152173; -- Guardia de Kennings
UPDATE `creature_template` SET `gossip_menu_id`=21860 WHERE `entry`=127646; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=134465; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=537166080, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=126709; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=67108928 WHERE `entry`=126929; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33040 WHERE `entry`=134540; -- Técnica civil Alena
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33040 WHERE `entry`=134541; -- Encargada de artillería Prim
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2030, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=141051; -- Matriarca pelóxido
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=142893; -- Ranger Peppers
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=134339; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134212; -- Modelador de tierra Brugaw
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134628; -- Técnica civil Alena
UPDATE `creature_template` SET `gossip_menu_id`=22239, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133621; -- Encargada de artillería Prim
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=126625; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=67108864 WHERE `entry`=126991; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133554; -- Encargada de artillería Prim
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134521; -- Mordisqueador enfurecido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133553; -- Técnica civil Alena
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133406; -- Azerita burbujeante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=134178; -- Azerita animada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123713; -- Mordisqueador de azerita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133428; -- Minero armado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134370; -- Mula de carga
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134371; -- Minero armado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133413; -- Empleado de Neviza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133551; -- Jefe minero Theock
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133552; -- Jefe químico Walters
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137152; -- Vigilante de la compañía
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137151; -- Capataz Zaleev
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133028; -- Hayden el Tiro Loco
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133024; -- Maestra de establo Diana
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133021; -- Sobrestante Aquilón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130497; -- Halcón marino avizor
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=64 WHERE `entry`=130369; -- Fernn el Traidor
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=138284; -- Rata aterradora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130364; -- Halconero rebelde
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130363; -- Amotinado fortalecido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130410; -- Alabardero rebelde
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=130508; -- Madre de linaje Razora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33554432 WHERE `entry`=138336; -- Trucha muerta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138286; -- Halcón marino hambriento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132720; -- Maestro de halcones Lloyd
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130887; -- Plumarea
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131019; -- Alabardero petragrís
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130375; -- Tallis Corazón del Cielo
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=136948; -- Cría colmisalina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=133035; -- Oficial Jovan
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130556; -- Marino herido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130326; -- Halconero petragrís
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=130878; -- Halcón marino entrenado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136901; -- Saurolisco colmisalina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=130358; -- Marino petragrís
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=133951; -- Hermano Alen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143144; -- Dustin Fowler
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143145; -- Criss Replogle
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138956; -- Eliza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138953; -- Jim Clark
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138957; -- Hannah
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138952; -- Amelia Clark
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139058; -- Criada elegante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139113; -- Posadera aburrida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138954; -- Lilly
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138955; -- Jack
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142029; -- Percy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142046; -- Sofía
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142030; -- Frankie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142035; -- Meeko
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142040; -- Tigre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142031; -- Nellie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142052; -- Miau Miau
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142044; -- Kenshi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142042; -- Anarquía
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142032; -- Mika
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142055; -- Chillidos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138421; -- Finnigan
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138422; -- Boswell
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138423; -- Winston
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139053; -- Anfitrión arrogante
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142453; -- Tobiana
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137199; -- Tink
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137191; -- Catherine Morgan
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148906; -- Ollie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137201; -- Sammy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142613; -- Murciélago
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142043; -- Tormentita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142053; -- Gizmo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142050; -- Gandy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142051; -- Holly
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142069; -- Babar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142111; -- Mango
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138410; -- Señor Guy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137196; -- Nala
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144114; -- Nina Martinel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=142490; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137420; -- Cynthia Brote
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137431; -- Annie Lacier
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137432; -- Timothy Green
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137483; -- Laurence E. Craft
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147645; -- Tizzy Engranéctica
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=147201; -- Alfil
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=147666; -- Manapuf
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142517; -- Hexxar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142514; -- Bucket
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142530; -- Molly
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137427; -- Rana piegajoso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142542; -- Nara
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142549; -- Yuki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142116; -- Ripley
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142118; -- Ronin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142536; -- Matt Salow
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143501; -- Sierra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142527; -- Chloe
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142526; -- Bax
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=147203; -- Sir Steve
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142125; -- Dama Zoe
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142124; -- Fitz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142122; -- Addie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142134; -- Brian Inboden
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142129; -- Wally
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142130; -- Russell
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142507; -- Mango
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148900; -- Ñami
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143571; -- Tanuki
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148899; -- Izzy
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142541; -- Ellie
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148902; -- Bobi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142505; -- Abbey
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_walk`=0.280000001192092895, `speed_run`=0.100000001490116119, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=174526; -- Gizmo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142092; -- Xander
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142091; -- Coop
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142127; -- Cora
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142065; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142513; -- Loki
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142126; -- Sir Reginald
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142090; -- Bates
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142563; -- Seth Spaulding
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142099; -- Elsie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143721; -- Val
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=150471; -- Dexter
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216 WHERE `entry`=148901; -- Rubí
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142506; -- Mochi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143516; -- Yeti
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912, `unit_flags3`=32769 WHERE `entry`=158255; -- Corcel kultirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137547; -- Asistente de Punta Garfio
UPDATE `creature_template` SET `faction`=2908, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=135783; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `unit_flags`=33536 WHERE `entry`=145370; -- Huérfano kultirano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3135, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=158377; -- Fortuna Envoltios
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3135, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=158379; -- Serafina Tuercanix
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=4, `speed_run`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `HoverHeight`=5 WHERE `entry`=158326; -- Telecóptero
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135153; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry`=138704; -- -Unknown-


UPDATE `creature_template_model` SET `DisplayScale`=2.5 WHERE (`CreatureID`=139287 AND `Idx`=0); -- Denteserra
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=145282 AND `Idx`=0); -- Rabiosa de los Honorables
UPDATE `creature_template_model` SET `CreatureDisplayID`=89044 WHERE (`CreatureID`=145310 AND `Idx`=0); -- Aprendiz de Orgrimmar
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=145818 AND `Idx`=0); -- Teniente Haas
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=144721 AND `Idx`=0); -- Experto en pólvora negra
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=145395 AND `Idx`=0); -- Katrianna
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=145392 AND `Idx`=0); -- Embajador Gaines
UPDATE `creature_template_model` SET `DisplayScale`=2.5 WHERE (`CreatureID`=139278 AND `Idx`=0); -- Ranja
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=144722 AND `Idx`=0); -- Togoth Brazo Cruel
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=145817 AND `Idx`=0); -- Capitán Holgresh
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=145308 AND `Idx`=0); -- Sargento Colmilloacero
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=134212 AND `Idx`=0); -- Modelador de tierra Brugaw
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=134521 AND `Idx`=0); -- Mordisqueador enfurecido
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=123713 AND `Idx`=0); -- Mordisqueador de azerita
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=130508 AND `Idx`=0); -- Madre de linaje Razora
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=136948 AND `Idx`=0); -- Cría colmisalina
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955, `Probability`=3 WHERE (`CreatureID`=136901 AND `Idx`=0); -- Saurolisco colmisalina
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=138956 AND `Idx`=0); -- Eliza
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=138954 AND `Idx`=0); -- Lilly
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=148906 AND `Idx`=0); -- Ollie
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=142055 AND `Idx`=0); -- Chillidos
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142052 AND `Idx`=0); -- Miau Miau
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142046 AND `Idx`=0); -- Sofía
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142044 AND `Idx`=0); -- Kenshi
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142042 AND `Idx`=0); -- Anarquía
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142040 AND `Idx`=0); -- Tigre
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142035 AND `Idx`=0); -- Meeko
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142032 AND `Idx`=0); -- Mika
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142031 AND `Idx`=0); -- Nellie
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=142030 AND `Idx`=0); -- Frankie
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142029 AND `Idx`=0); -- Percy
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138423 AND `Idx`=0); -- Winston
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138422 AND `Idx`=0); -- Boswell
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138421 AND `Idx`=0); -- Finnigan
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142053 AND `Idx`=0); -- Gizmo
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142050 AND `Idx`=0); -- Gandy
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=138410 AND `Idx`=0); -- Señor Guy
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=137196 AND `Idx`=0); -- Nala
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=147201 AND `Idx`=0); -- Alfil
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=143501 AND `Idx`=0); -- Sierra
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142549 AND `Idx`=0); -- Yuki
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=142542 AND `Idx`=0); -- Nara
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142530 AND `Idx`=0); -- Molly
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=142517 AND `Idx`=0); -- Hexxar
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142514 AND `Idx`=0); -- Bucket
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=142116 AND `Idx`=0); -- Ripley
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137427 AND `Idx`=0); -- Rana piegajoso
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142527 AND `Idx`=0); -- Chloe
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142526 AND `Idx`=0); -- Bax
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142130 AND `Idx`=0); -- Russell
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142129 AND `Idx`=0); -- Wally
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=142125 AND `Idx`=0); -- Dama Zoe
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142122 AND `Idx`=0); -- Addie
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=150471 AND `Idx`=0); -- Dexter
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=142513 AND `Idx`=0); -- Loki
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142506 AND `Idx`=0); -- Mochi
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142099 AND `Idx`=0); -- Elsie
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=142090 AND `Idx`=0); -- Bates
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=148902 AND `Idx`=0); -- Bobi
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=148901 AND `Idx`=0); -- Rubí
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=148900 AND `Idx`=0); -- Ñami
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=143721 AND `Idx`=0); -- Val
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=143571 AND `Idx`=0); -- Tanuki
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142541 AND `Idx`=0); -- Ellie
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=142507 AND `Idx`=0); -- Mango
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=142505 AND `Idx`=0); -- Abbey
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=142127 AND `Idx`=0); -- Cora
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=142126 AND `Idx`=0); -- Sir Reginald
UPDATE `creature_template_model` SET `DisplayScale`=0.60000002384185791 WHERE (`CreatureID`=142092 AND `Idx`=0); -- Xander
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=142091 AND `Idx`=0); -- Coop
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=143516 AND `Idx`=0); -- Yeti
UPDATE `creature_template_model` SET `DisplayScale`=0.949999988079071044 WHERE (`CreatureID`=158379 AND `Idx`=0); -- Serafina Tuercanix
UPDATE `creature_template_model` SET `DisplayScale`=0.949999988079071044 WHERE (`CreatureID`=158377 AND `Idx`=0); -- Fortuna Envoltios


DELETE FROM `world_quest` WHERE `id` IN (53711 /*53711*/, 53699 /*53699*/, 52475 /*52475*/, 53814 /*53814*/, 53951 /*53951*/, 54237 /*54237*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(53711, 25200, 16288, 1), -- 53711
(53699, 25200, 16288, 1), -- 53699
(52475, 25200, 16288, 1), -- 52475
(53814, 25200, 16288, 1), -- 53814
(53951, 25200, 16288, 1), -- 53951
(54237, 25200, 16288, 1); -- 54237

UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14063 WHERE `id`=49099; -- 49099
