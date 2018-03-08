UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11721;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=15386;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=6095;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12286;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9110;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=13677;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9170;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=2947;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=15410;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16170;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=15548;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=3921;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16415;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16104;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16123;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=8015 AND `AreaTriggerId`=12286);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(8015, 12286, 0, 0, 0, 0, 0, 0, 5283, 26124); -- SpellId : 220024

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=10533 AND `AreaTriggerId`=15386); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2050, `TimeToTargetScale`=2500, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=1612 AND `AreaTriggerId`=6095); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1682, `TimeToTargetScale`=1750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1691, `TimeToTargetScale`=1750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1390, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=9737 AND `AreaTriggerId`=13677); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1482, `TimeToTargetScale`=1750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1448, `TimeToTargetScale`=1750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=11408 AND `AreaTriggerId`=16170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=10717 AND `AreaTriggerId`=15548); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3200, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=658 AND `AreaTriggerId`=3921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=11336 AND `AreaTriggerId`=16104); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=11363 AND `AreaTriggerId`=16123); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5910 AND `ConversationActorId`=51642 AND `Idx`=0) OR (`ConversationId`=5237 AND `ConversationActorId`=51642 AND `Idx`=0) OR (`ConversationId`=5278 AND `ConversationActorId`=51642 AND `Idx`=0) OR (`ConversationId`=5850 AND `ConversationActorId`=60352 AND `Idx`=0) OR (`ConversationId`=5847 AND `ConversationActorId`=58811 AND `Idx`=0) OR (`ConversationId`=5846 AND `ConversationActorId`=58811 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(5910, 51642, 0, 26124),
(5237, 51642, 0, 26124),
(5278, 51642, 0, 26124),
(5850, 60352, 0, 26124),
(5847, 58811, 0, 26124),
(5846, 58811, 0, 26124);


DELETE FROM `conversation_actor_template` WHERE `Id`=58811;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(58811, 120514, 75811, 26124);

UPDATE `conversation_actor_template` SET `CreatureId`=120521, `CreatureModelId`=75273, `VerifiedBuild`=26124 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=120218, `CreatureModelId`=74146, `VerifiedBuild`=26124 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=121263, `CreatureModelId`=76255, `VerifiedBuild`=26124 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=60352;

DELETE FROM `conversation_line_template` WHERE `Id` IN (13242, 11700, 11791, 13096, 13093, 13092);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(13242, 0, 1058, 0, 0, 26124),
(11700, 0, 296, 0, 0, 26124),
(11791, 0, 106, 0, 0, 26124),
(13096, 0, 296, 0, 0, 26124),
(13093, 0, 82, 0, 0, 26124),
(13092, 0, 82, 0, 0, 26124);


DELETE FROM `conversation_template` WHERE `Id` IN (5278, 5847, 5850, 5846, 5910, 5237);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(5278, 11791, 13472, 26124),
(5847, 13093, 6463, 26124),
(5850, 13096, 7135, 26124),
(5846, 13092, 4561, 26124),
(5910, 13242, 13699, 26124),
(5237, 11700, 10577, 26124);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (273787 /*Cristal de téléportation*/, 272455 /*Fournitures de guerre érédars*/, 276491 /*Coffre krokul perdu*/, 268800 /*Cage de la Légion*/, 276490 /*Cache krokul d’urgence*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(273787, 0, 262144), -- Cristal de téléportation
(272455, 0, 278528), -- Fournitures de guerre érédars
(276491, 0, 2113536), -- Coffre krokul perdu
(268800, 0, 262148), -- Cage de la Légion
(276490, 0, 2113536); -- Cache krokul d’urgence



UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=250362 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (123964 /*123964 (Cible du Vindicaar) - RShwayder Test 02*/, 121297 /*121297 (Dévoreur écumant)*/, 125388 /*125388 (Vagath le Trahi)*/, 125115 /*125115 (Dame Hérética) - Infusion infernale*/, 128011 /*Stridemort*/, 127942 /*127942 (Récupérateur de la Gangreforge)*/, 121398 /*121398 (Maître-lame Telaamon) - No NPC Damage Below Override Points%*/, 121534 /*121534 (Démon guerrier fauche-âmes) - Échelle : 95-120%*/, 121517 /*121517 (Baraat le Long-Tireur) - No NPC Damage Below Override Points%*/, 127823 /*127823 (Exossature sancteforge) - No NPC Damage Below 45-90%, Flamme purificatrice*/, 125257 /*125257 (Extraterrestrial Exploration - Shattered Fields)*/, 121578 /*121578 (Archimage Y'mera) - No NPC Damage Below Override Points%*/, 124775 /*Commandant Endaxis - Inspiration de l'effroi*/, 127504 /*Tas de pierres*/, 120637 /*Démon ardent - Flammes ardentes*/, 120638 /*120638 (Charognard gangreflamme)*/, 120723 /*Fanatique annihiléenne*/, 120601 /*120601 (Magraloth)*/, 121246 /*121246 (Esclave sombreroué) - , Permanent Feign Death (Stun, Untrackable)*/, 120704 /*Gardien annihiléen*/, 124804 /*124804 (Tereck le Sélectionneur)*/, 123420 /*123420 (Imploratrice funeste gangresiège) - Réduction de 100% de la menace*/, 127501 /*Tas de pierres*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(123964, 0, 0, 0, 1, 0, 0, 0, 0, '144373'), -- 123964 (Cible du Vindicaar) - RShwayder Test 02
(121297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121297 (Dévoreur écumant)
(125388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125388 (Vagath le Trahi)
(125115, 0, 0, 0, 1, 0, 0, 0, 0, '251466'), -- 125115 (Dame Hérética) - Infusion infernale
(128011, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- Stridemort
(127942, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127942 (Récupérateur de la Gangreforge)
(121398, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 121398 (Maître-lame Telaamon) - No NPC Damage Below Override Points%
(121534, 0, 0, 0, 1, 0, 0, 0, 0, '123978'), -- 121534 (Démon guerrier fauche-âmes) - Échelle : 95-120%
(121517, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 121517 (Baraat le Long-Tireur) - No NPC Damage Below Override Points%
(127823, 0, 0, 0, 1, 0, 0, 0, 0, '151597 250825'), -- 127823 (Exossature sancteforge) - No NPC Damage Below 45-90%, Flamme purificatrice
(125257, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 125257 (Extraterrestrial Exploration - Shattered Fields)
(121578, 0, 0, 0, 1, 0, 0, 0, 0, '155893'), -- 121578 (Archimage Y'mera) - No NPC Damage Below Override Points%
(124775, 0, 0, 0, 1, 0, 0, 0, 0, '251245'), -- Commandant Endaxis - Inspiration de l'effroi
(127504, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Tas de pierres
(120637, 0, 0, 0, 1, 0, 0, 0, 0, '244975'), -- Démon ardent - Flammes ardentes
(120638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120638 (Charognard gangreflamme)
(120723, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fanatique annihiléenne
(120601, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120601 (Magraloth)
(121246, 0, 0, 262144, 1, 0, 0, 0, 0, '196285 145363'), -- 121246 (Esclave sombreroué) - , Permanent Feign Death (Stun, Untrackable)
(120704, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gardien annihiléen
(124804, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 124804 (Tereck le Sélectionneur)
(123420, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 123420 (Imploratrice funeste gangresiège) - Réduction de 100% de la menace
(127501, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- Tas de pierres

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126419; -- 126419 (Naroua)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=126042; -- 126042
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=122041; -- 122041 (Maîtresse de l'Ombre)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=0 WHERE `entry`=125121; -- 125121 (Découpe-chair nathraxéen)
UPDATE `creature_template_addon` SET `auras`='248706' WHERE `entry`=125109; -- Gangréclat flamboyant
UPDATE `creature_template_addon` SET `auras`='233004' WHERE `entry`=119395; -- Infernal gangresiège
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='186571' WHERE `entry`=121397; -- 121397 (Prêtre de guerre sancteforge)
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='186571' WHERE `entry`=121395; -- 121395
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=121396; -- 121396 (Tireur de précision sancteforge)
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='186571' WHERE `entry`=121394; -- 121394
UPDATE `creature_template_addon` SET `bytes1`=262144, `bytes2`=1, `auras`='186571' WHERE `entry`=121516; -- 121516
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=120602; -- 120602 (Kar'aaz)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=111345; -- 111345 (Generic Bunny)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=119745; -- 119745 (Petit marsuul)
UPDATE `creature_template_addon` SET `aiAnimKit`=13756 WHERE `entry`=125468; -- 125468 (Mange-goudron)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=124439; -- 124439 (Foule-combe sauvage)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=123076; -- 123076 (Alpha voile-de-brune)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=124303; -- 124303 (Panthara voile-de-brune)
UPDATE `creature_template_addon` SET `auras`='99203' WHERE `entry`=122924; -- 122924 (Conquérant érédar)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=124278; -- 124278 (Marsuul gangremarqué)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=119597; -- 119597 (Champion gangresiège)
UPDATE `creature_template_addon` SET `auras`='241767' WHERE `entry`=120596; -- Vaisseau de la Légion
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='159474' WHERE `entry`=128162; -- Larve bilieuse

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (124303, 123110, 125502, 121531, 124225, 120723, 124278, 123109, 122912, 125110, 125109, 120638, 125103, 123422, 126256, 124279, 125129, 125223, 125468, 121410, 123420, 124775, 122039, 125121, 119395, 122041, 123659, 127942, 125290, 124975, 119604, 119602, 122794, 121536, 124265, 119597, 124271, 120395, 120476, 122922, 119398, 125139, 120637, 120704, 125294, 119533, 120598, 125388, 123421, 121423, 120330, 124670, 125503, 120596, 121417, 124269, 126419, 121418, 123658, 125389, 119538, 124804, 119745, 125479, 123418, 119576, 120602, 121575, 110597, 120329, 128176, 120737, 125501, 125292, 120322, 125115, 124015, 123689, 121297, 126688, 121359, 120354, 122993, 122924, 120763, 121544, 125820, 122911, 124348, 120601, 110473, 121421, 121413, 121408);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(124303, 0, 26124),
(123110, 0, 26124),
(125502, 0, 26124),
(121531, 0, 26124),
(124225, 0, 26124),
(120723, 0, 26124),
(124278, 0, 26124),
(123109, 0, 26124),
(122912, 0, 26124),
(125110, 0, 26124),
(125109, 0, 26124),
(120638, 0, 26124),
(125103, 0, 26124),
(123422, 0, 26124),
(126256, 0, 26124),
(124279, 0, 26124),
(125129, 0, 26124),
(125223, 0, 26124),
(125468, 0, 26124),
(121410, 0, 26124),
(123420, 0, 26124),
(124775, 0, 26124),
(122039, 0, 26124),
(125121, 0, 26124),
(119395, 1, 26124),
(122041, 0, 26124),
(123659, 0, 26124),
(127942, 0, 26124),
(125290, 0, 26124),
(124975, 0, 26124),
(119604, 0, 26124),
(119602, 0, 26124),
(122794, 0, 26124),
(121536, 0, 26124),
(124265, 0, 26124),
(119597, 0, 26124),
(124271, 0, 26124),
(120395, 0, 26124),
(120476, 0, 26124),
(122922, 0, 26124),
(119398, 0, 26124),
(125139, 0, 26124),
(120637, 0, 26124),
(120704, 0, 26124),
(125294, 0, 26124),
(119533, 0, 26124),
(120598, 0, 26124),
(125388, 0, 26124),
(123421, 0, 26124),
(121423, 0, 26124),
(120330, 0, 26124),
(124670, 0, 26124),
(125503, 0, 26124),
(120596, 0, 26124),
(121417, 0, 26124),
(124269, 0, 26124),
(126419, 0, 26124),
(121418, 0, 26124),
(123658, 0, 26124),
(125389, 0, 26124),
(119538, 0, 26124),
(124804, 0, 26124),
(119745, 0, 26124),
(125479, 0, 26124),
(123418, 0, 26124),
(119576, 0, 26124),
(120602, 0, 26124),
(121575, 0, 26124),
(110597, 0, 26124),
(120329, 0, 26124),
(128176, 0, 26124),
(120737, 0, 26124),
(125501, 0, 26124),
(125292, 0, 26124),
(120322, 0, 26124),
(125115, 0, 26124),
(124015, 0, 26124),
(123689, 0, 26124),
(121297, 0, 26124),
(126688, 0, 26124),
(121359, 0, 26124),
(120354, 0, 26124),
(122993, 0, 26124),
(122924, 0, 26124),
(120763, 0, 26124),
(121544, 0, 26124),
(125820, 0, 26124),
(122911, 0, 26124),
(124348, 0, 26124),
(120601, 0, 26124),
(110473, 0, 26124),
(121421, 0, 26124),
(121413, 0, 26124),
(121408, 0, 26124);



UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79743;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75228;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5411867, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=73562;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73561;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78926;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75474;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75473;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77962;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77938;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78660;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78382;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77960;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75811;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76272;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78376;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=42720;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=42722;
UPDATE `creature_model_info` SET `BoundingRadius`=1.15581, `CombatReach`=1, `VerifiedBuild`=26124 WHERE `DisplayID`=77877;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71032;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77508;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77870;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75147;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=75305;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78099;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63813;
UPDATE `creature_model_info` SET `BoundingRadius`=5.048706, `CombatReach`=4.5, `VerifiedBuild`=26124 WHERE `DisplayID`=74446;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79746;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78349;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78336;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1913;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78341;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78413;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75428;
UPDATE `creature_model_info` SET `BoundingRadius`=1.47147, `CombatReach`=2, `VerifiedBuild`=26124 WHERE `DisplayID`=78333;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78343;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78337;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=58255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78412;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64169;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=51621;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79744;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8462658, `CombatReach`=0.6, `VerifiedBuild`=26124 WHERE `DisplayID`=79747;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64476;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78386;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78381;
UPDATE `creature_model_info` SET `BoundingRadius`=1.35, `CombatReach`=2.025, `VerifiedBuild`=26124 WHERE `DisplayID`=76337;
UPDATE `creature_model_info` SET `BoundingRadius`=1.35, `CombatReach`=2.025, `VerifiedBuild`=26124 WHERE `DisplayID`=76437;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80152;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78388;
UPDATE `creature_model_info` SET `BoundingRadius`=1.35, `CombatReach`=2.025, `VerifiedBuild`=26124 WHERE `DisplayID`=76434;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76339;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78814;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76336;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78390;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=38615;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=62261;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78389;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78384;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77889;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78938;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79745;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78464;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78377;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78379;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78383;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78380;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78387;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76338;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76378;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77370;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75584;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76432;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76436;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79241;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78385;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77656;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68116;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76340;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77891;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78455;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72942;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64483;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78486;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76416;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78378;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76433;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77884;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77885;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77892;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77890;
UPDATE `creature_model_info` SET `BoundingRadius`=2.012089, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=78200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76411;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77139;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75938;
UPDATE `creature_model_info` SET `BoundingRadius`=1.2, `CombatReach`=1.8, `VerifiedBuild`=26124 WHERE `DisplayID`=77141;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75935;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75936;
UPDATE `creature_model_info` SET `BoundingRadius`=2.073884, `CombatReach`=1.35, `VerifiedBuild`=26124 WHERE `DisplayID`=77119;
UPDATE `creature_model_info` SET `BoundingRadius`=0.921726, `CombatReach`=0.6, `VerifiedBuild`=26124 WHERE `DisplayID`=77118;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=20907;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75939;
UPDATE `creature_model_info` SET `BoundingRadius`=6.431781, `CombatReach`=5.5, `VerifiedBuild`=26124 WHERE `DisplayID`=76410;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77140;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75932;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75475;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74906;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77105;
UPDATE `creature_model_info` SET `BoundingRadius`=1.75, `CombatReach`=2.625, `VerifiedBuild`=26124 WHERE `DisplayID`=78217;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76317;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=41574;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=20944;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79020;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79742;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77948;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76305;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77097;
UPDATE `creature_model_info` SET `BoundingRadius`=1.35, `CombatReach`=2.025, `VerifiedBuild`=26124 WHERE `DisplayID`=77164;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77111;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77160;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74901;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77096;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78055;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78054;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75164;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78025;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75174;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76301;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75247;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77918;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76594;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=77109;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76318;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75183;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79812;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68890;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28222;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71637;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65834;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26770;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=16624;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76352;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76310;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77923;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77540;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75424;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74465;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75426;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65204;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77619;
UPDATE `creature_model_info` SET `CombatReach`=1.363636, `VerifiedBuild`=26124 WHERE `DisplayID`=76275;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75425;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75886;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76312;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76302;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77760;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=75142;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75746;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75418;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75417;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77941;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=74923;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77759;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76311;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78449;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75888;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75427;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=75880;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75678;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75265;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=127942 AND `ID`=1) OR (`CreatureID`=121398 AND `ID`=1) OR (`CreatureID`=121517 AND `ID`=1) OR (`CreatureID`=121578 AND `ID`=1) OR (`CreatureID`=120723 AND `ID`=1) OR (`CreatureID`=120601 AND `ID`=1) OR (`CreatureID`=120704 AND `ID`=1) OR (`CreatureID`=124804 AND `ID`=1) OR (`CreatureID`=123420 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(127942, 1, 31824, 0, 0, 0, 0, 0, 0, 0, 0), -- Récupérateur de la Gangreforge
(121398, 1, 85428, 0, 0, 0, 0, 0, 0, 0, 0), -- Maître-lame Telaamon
(121517, 1, 106264, 0, 0, 106264, 0, 0, 147617, 0, 0), -- Baraat le Long-Tireur
(121578, 1, 107249, 0, 0, 0, 0, 0, 0, 0, 0), -- Archimage Y'mera
(120723, 1, 72255, 0, 0, 0, 0, 0, 0, 0, 0), -- Fanatique annihiléenne
(120601, 1, 28365, 0, 0, 0, 0, 0, 0, 0, 0), -- Magraloth
(120704, 1, 147522, 0, 0, 0, 0, 0, 0, 0, 0), -- Gardien annihiléen
(124804, 1, 113913, 0, 0, 0, 0, 0, 0, 0, 0), -- Tereck le Sélectionneur
(123420, 1, 118992, 0, 0, 0, 0, 0, 0, 0, 0); -- Imploratrice funeste gangresiège


UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128008; -- Griffe-Infâme
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=117626; -- Dreadscar Trickster
UPDATE `creature_template` SET `HealthModifier`=61, `VerifiedBuild`=26124 WHERE `entry`=126419; -- Naroua
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127505; -- Tas de pierres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126445; -- Marsuul malicieux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124569; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127752; -- Raelaara la Charitable
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120763; -- Grand exarque Turalyon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124975; -- Image du grand artificier Romuul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127751; -- Forgelumière Sel'ann
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125443; -- Alleria Coursevent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125502; -- Tireuse funeste nathraxéenne
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125501; -- Découpe-chair nathraxéen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125503; -- Chasseur d'âmes vorace
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=70, `VerifiedBuild`=26124 WHERE `entry`=123964; -- Cible du Vindicaar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121544; -- Grand inquisiteur Raalgar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122039; -- Canonnier de la Légion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123658; -- Capitaine de la haute garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121413; -- Défenseur du Déclin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124208; -- Converti raté
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122041; -- Maîtresse de l'Ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121575; -- Guerrier de la haute garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125258; -- Extraterrestrial Exploration - Nath'raxas Hold
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127528; -- Site d'invasion prioritaire : matrone Folnuna
UPDATE `creature_template` SET `KillCredit1`=121987, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=0.7, `VerifiedBuild`=26124 WHERE `entry`=121297; -- Dévoreur écumant
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123659; -- Guetteur de la haute garde
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2223, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=70, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=125388; -- Vagath le Trahi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126688; -- Découpe-chair nathraxéen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125389; -- Chasseur d'âmes vorace
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128010; -- Dégob
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125139; -- Seigneur du désastre nathrezim
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125223; -- Chasseur d'âmes vorace
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106885; -- Tiger Initiate
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125129; -- Tireuse funeste nathraxéenne
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125121; -- Découpe-chair nathraxéen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121536; -- Gardeffroi de la citadelle
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `type_flags`=2147483720, `HealthModifier`=6, `VerifiedBuild`=26124 WHERE `entry`=125115; -- Dame Hérética
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125290; -- Tireuse funeste nathraxéenne
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125292; -- Découpe-chair nathraxéen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125294; -- Pyroclaste nathraxéen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125109; -- Gangréclat flamboyant
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125110; -- Braise courroucée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125103; -- Ecraseur igné
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125032; -- Éclat d'Apocalypse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128009; -- Luisemort
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121661; -- Sneaky Snake
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110597; -- Neige-Plume
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110473; -- Emmarel Shadewarden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=94365; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=94358; -- Ashbringer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110340; -- Myonix
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=60199; -- Rune of Power
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=95160; -- Vrykul
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `VerifiedBuild`=26124 WHERE `entry`=96118; -- Order of the Awakened Battle Standard
UPDATE `creature_template` SET `HealthScalingExpansion`=5, `type`=14, `VerifiedBuild`=26124 WHERE `entry`=128011; -- Stridemort
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=127942; -- Récupérateur de la Gangreforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122304; -- Tempête d'Argus
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=1.25, `VerifiedBuild`=26124 WHERE `entry`=121534; -- Démon guerrier fauche-âmes
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262216, `HealthModifier`=9, `ManaModifier`=10, `VerifiedBuild`=26124 WHERE `entry`=121398; -- Maître-lame Telaamon
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262216, `HealthModifier`=10, `ManaModifier`=10, `VerifiedBuild`=26124 WHERE `entry`=121517; -- Baraat le Long-Tireur
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `rank`=6, `type`=7, `type_flags`=1073741824, `HealthModifier`=0.1, `movementId`=129, `VerifiedBuild`=26124 WHERE `entry`=125257; -- Extraterrestrial Exploration - Shattered Fields
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4168, `HealthModifier`=7, `VerifiedBuild`=26124 WHERE `entry`=127823; -- Exossature sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122622; -- Pilote sancteforge
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262216, `HealthModifier`=8, `ManaModifier`=10, `VerifiedBuild`=26124 WHERE `entry`=121578; -- Archimage Y'mera
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123594; -- VFX Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122794; -- Batterie sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128135; -- Soldat défunt
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111727; -- Aluneth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119395; -- Infernal gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121548; -- Avant-garde brisemenace
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128012; -- Grince-dents
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123061; -- Val'aan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125439; -- Argunite scintillante
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121545; -- Bouclier
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121521; -- Grand redresseur de torts Sorvos
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128166; -- Argunite scintillante
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123260; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121519; -- Capitaine Fareeya
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121547; -- Exossature sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121531; -- Destructeur gangremarqué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121520; -- Grande lectrice Enaara
UPDATE `creature_template` SET `HealthModifier`=65, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=122911; -- Commandant Vecaya
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121396; -- Tireur de précision sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119398; -- Crache-fiel brûlaile
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123109; -- Messager vengeur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123110; -- Profanateur lié à l'ombre
UPDATE `creature_template` SET `HealthModifier`=75, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=125820; -- Mère des diablotins Laglath
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125387; -- Gangréclat instable
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124670; -- Surveillant érédar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123565; -- Travailleur de la Légion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125481; -- Corruption coagulée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121587; -- Batterie sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125152; -- Eclaireur de l'avant-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125146; -- Cherche-âme en chasse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125178; -- 125178
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125151; -- Maître-portail de l'avant-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120514; -- Grand exarque Turalyon
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=26124 WHERE `entry`=127504; -- Tas de pierres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110715; -- Kirin Tor Invoker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120602; -- Kar'aaz
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120598; -- Xeth'tal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120586; -- 120586
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120638; -- Charognard gangreflamme
UPDATE `creature_template` SET `KillCredit1`=119383, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=120637; -- Démon ardent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123698;
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2147483752, `HealthModifier`=25, `movementId`=84, `VerifiedBuild`=26124 WHERE `entry`=120601; -- Magraloth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111345; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120723; -- Fanatique annihiléenne
UPDATE `creature_template` SET `KillCredit1`=119383, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=120704; -- Gardien annihiléen
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26124 WHERE `entry`=121246; -- Esclave sombreroué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119745; -- Petit marsuul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120521; -- Chef Hatuun
UPDATE `creature_template` SET `HealthModifier`=82, `VerifiedBuild`=26124 WHERE `entry`=124775; -- Commandant Endaxis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122834; -- Dame Shahrazad
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123025; -- Erédar réprouvé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125256; -- Extraterrestrial Exploration - Petrified Forest
UPDATE `creature_template` SET `HealthModifier`=71, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=125479; -- Crache-goudron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125468; -- Mange-goudron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126638; -- Premier Naaru
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124439; -- Foule-combe sauvage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128007; -- Sabot-Néfaste
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123076; -- Alpha voile-de-brune
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124738; -- Voile-de-brune pétrifié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124711; -- Foule-combe pétrifié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122891; -- Dévoreur ur'zul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122837; -- Krokul capturé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122835; -- Sculpte-âme érédar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122815; -- Dévoreur ur'zul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123130; -- Acolyte érédar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127920; -- Na'nuu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124486; -- Jeune voile-de-brune
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124303; -- Panthara voile-de-brune
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99904; -- T'uure
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126160; -- Chevaucheur de tête Jerek
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123390; -- Monture foule-combe
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123389; -- Dresseur krokul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121175; -- Esclave sombreroué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121174; -- Esclave sombreroué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124269; -- Panthara alpha
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124271; -- Traqueur panthara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124834; -- Krokul blessé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124833; -- Guerrier krokul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126194; -- Redresseur de torts de l'Exodar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124265; -- Foule-combe chitineux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121423; -- Kal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121421; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121359; -- Aethas Saccage-Soleil
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119538; -- Archimage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121418; -- Dame Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121417; -- Vereesa Coursevent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121408; -- Arator le Rédempteur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122924; -- Conquérant érédar
UPDATE `creature_template` SET `KillCredit1`=119606, `KillCredit2`=119533, `HealthScalingExpansion`=6, `type`=3, `VerifiedBuild`=26124 WHERE `entry`=123420; -- Imploratrice funeste gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123418; -- Championne gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122922; -- Implorateur funeste gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121410; -- Redresseur de torts Boros
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120330; -- Démon abject
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120322; -- Champion gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119576; -- Démon abject
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=26124 WHERE `entry`=127501; -- Tas de pierres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123074; -- Foule-combe sauvage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124278; -- Marsuul gangremarqué
UPDATE `creature_template` SET `HealthModifier`=67, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=123689; -- Talestra l'Infâme
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128176; -- Sort de sécurité augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122993; -- Implorateur funeste gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122902; -- Faille d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120329; -- Champion gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119604; -- Traqueuse balafraile
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120218; -- Illidan Hurlorage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123084; -- Gangrecristal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119597; -- Champion gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120395; -- Conquérant érédar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120596; -- Vaisseau de la Légion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125058; -- Rôdeur des crêtes krokul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120354; -- Oblitérateur garothi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124294; -- Boulets explosifs de dévastateur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123421; -- Imploratrice funeste gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119533; -- Implorateur funeste gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128162; -- Larve bilieuse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126256; -- Manœuvre gangre-lié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123422; -- Championne gangresiège
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124225; -- Foule-combe chitineux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119602; -- Démon abject


UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121544 AND `Idx`=0); -- Grand inquisiteur Raalgar
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125109 AND `Idx`=0); -- Gangréclat flamboyant
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125110 AND `Idx`=0); -- Braise courroucée
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125103 AND `Idx`=0); -- Ecraseur igné
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=110340 AND `Idx`=2); -- Myonix
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=110340 AND `Idx`=1); -- Myonix
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=110340 AND `Idx`=0); -- Myonix
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121548 AND `Idx`=1); -- Avant-garde brisemenace
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121548 AND `Idx`=0); -- Avant-garde brisemenace
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121531 AND `Idx`=1); -- Destructeur gangremarqué
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121531 AND `Idx`=0); -- Destructeur gangremarqué
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123109 AND `Idx`=1); -- Messager vengeur
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123109 AND `Idx`=0); -- Messager vengeur
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123110 AND `Idx`=1); -- Profanateur lié à l'ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123110 AND `Idx`=0); -- Profanateur lié à l'ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124670 AND `Idx`=0); -- Surveillant érédar
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123565 AND `Idx`=0); -- Travailleur de la Légion
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125152 AND `Idx`=1); -- Eclaireur de l'avant-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125152 AND `Idx`=0); -- Eclaireur de l'avant-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125151 AND `Idx`=1); -- Maître-portail de l'avant-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=125151 AND `Idx`=0); -- Maître-portail de l'avant-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122891 AND `Idx`=0); -- Dévoreur ur'zul
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122815 AND `Idx`=0); -- Dévoreur ur'zul
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119597 AND `Idx`=0); -- Champion gangresiège
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=120395 AND `Idx`=0); -- Conquérant érédar
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123421 AND `Idx`=0); -- Imploratrice funeste gangresiège
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119533 AND `Idx`=0); -- Implorateur funeste gangresiège
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123422 AND `Idx`=0); -- Championne gangresiège
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119602 AND `Idx`=0); -- Démon abject

DELETE FROM `gameobject_template` WHERE `entry` IN (271955 /*Boulets de gangrecanon*/, 272680 /*Arme de siège sancteforge*/, 272664 /*Bannière*/, 276406 /*Tas de rochers*/, 272753 /*Focalisation de sort*/, 276423 /*Tas de rochers*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(271955, 5, 7379, 'Felcannon cannonballs', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulets de gangrecanon
(272680, 5, 41633, 'Sancteforge Siege Weapon', '', '', '', 0.78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Arme de siège sancteforge
(272664, 5, 31876, 'Banner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Bannière
(276406, 5, 43997, 'Pile of rocks', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Tas de rochers
(272753, 8, 9510, 'Spell focalisation', '', '', '', 1, 1924, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Focalisation de sort
(276423, 5, 43997, 'Pile of rocks', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Tas de rochers

UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272771; -- Fournitures de guerre érédars
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276404; -- Tas de rochers
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273464; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276489; -- Coffre de tour de la Légion
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241861; -- Gangrecristal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271972; -- Gangrecanon
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273819; -- Bannière
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272678; -- Arme de siège sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272679; -- Arme de siège sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272748; -- Tas de cendre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272747; -- Tas de cendre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272630; -- Gangrerune
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277391; -- Feu de camp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272757; -- Téléporteur
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272756; -- Poteau
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277395; -- Enclume
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277390; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272749; -- Tas de cendre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272465; -- Barricade
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272663; -- Livre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272661; -- Livre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272662; -- Autel
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271715; -- Autel
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272560; -- Flèche de malheur
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272456; -- Fournitures de guerre érédars
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273830; -- Torse infernal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273829; -- Bras infernal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273828; -- Carcasse infernale
UPDATE `gameobject_template` SET `type`=10, `displayId`=42733, `Data0`=93, `Data3`=1, `Data10`=251932, `Data14`=35196, `Data20`=1, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=273787; -- Cristal de téléportation
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272778; -- Riche gisement d'empyrium
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=275084; -- Portail antéen
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273465; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269265; -- Pylône sacré
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276638; -- Gangrefeu
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271707; -- Portail de la Légion
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271689; -- Eclat d’énergie gangrenée
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272615; -- Portail de la Légion
UPDATE `gameobject_template` SET `type`=50, `displayId`=33706, `Data0`=57, `Data1`=75294, `Data6`=300, `Data9`=21400, `Data17`=2024, `Data18`=20, `Data19`=1, `RequiredLevel`=110, `VerifiedBuild`=26124 WHERE `entry`=272455; -- Fournitures de guerre érédars
UPDATE `gameobject_template` SET `type`=3, `displayId`=44843, `Data0`=57, `Data2`=1, `Data4`=1, `Data5`=1, `Data13`=1, `Data14`=21400, `Data29`=2289, `Data30`=76203, `RequiredLevel`=110, `VerifiedBuild`=26124 WHERE `entry`=276491; -- Coffre krokul perdu
UPDATE `gameobject_template` SET `type`=10, `displayId`=26125, `Data3`=3000, `Data5`=1, `Data10`=183765, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=241536; -- Moongrass
UPDATE `gameobject_template` SET `type`=10, `displayId`=26854, `Data0`=93, `Data1`=46840, `Data3`=3000, `Data6`=3000, `Data10`=240591, `Data14`=24815, `Data20`=1, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=268800; -- Cage de la Légion
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272780; -- Veine d'empyrium
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268801; -- Cage endommagée
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273222; -- Fournitures de guerre érédars
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277343; -- Trésor augari perdu depuis longtemps
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=234436; -- Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=234435; -- Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271114; -- Ossements érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272640; -- Faux
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272636; -- Corde
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273511; -- Lit de camp 02
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272634; -- Paquet
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269183; -- Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271155; -- Gangrerune
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269184; -- Livre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277639; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272635; -- Sac
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272575; -- Râtelier d’armes
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272573; -- Enclume
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=267797; -- Lit de camp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273508; -- Bouclier
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273507; -- Masse
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273502; -- Débris
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271849; -- Fournitures de guerre érédars
UPDATE `gameobject_template` SET `type`=3, `displayId`=44843, `Data0`=57, `Data2`=1, `Data4`=1, `Data5`=1, `Data13`=1, `Data14`=21400, `Data22`=1, `Data29`=2291, `Data30`=76206, `RequiredLevel`=110, `VerifiedBuild`=26124 WHERE `entry`=276490; -- Cache krokul d’urgence
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271730; -- Effet gangrené
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241537; -- Chaos Clover
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272313; -- Épandeur de corruption qui fuit
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271712; -- Parchemin érédun ancien
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273792; -- Fissures
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277344; -- Souvenirs augari précieux
UPDATE `gameobject_template` SET `type`=10, `displayId`=26123, `size`=0.3, `Data3`=3000, `Data5`=1, `Data10`=183759, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=241523; -- Felbloom
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241535; -- Bleakthorn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271137; -- Cadre
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273052; -- Herbe incrustée de corruption
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241538; -- Doom Shroom
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272768; -- Gisement d'empyrium
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271612; -- Corde
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271610; -- Drapé


UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=271689 AND `Idx`=0); -- Eclat d’énergie gangrenée
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=271114 AND `Idx`=0); -- Ossements érédar
