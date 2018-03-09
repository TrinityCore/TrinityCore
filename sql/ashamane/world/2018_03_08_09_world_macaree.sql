UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=15685;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=16415;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9448;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=6094;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9805;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10370;

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=10858 AND `AreaTriggerId`=15685); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1592, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=4714 AND `AreaTriggerId`=9448); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=1613 AND `AreaTriggerId`=6094); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5084 AND `AreaTriggerId`=9805); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5663 AND `AreaTriggerId`=10370); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=6050 AND `ConversationActorId`=58162 AND `Idx`=0) OR (`ConversationId`=5474 AND `ConversationActorId`=58162 AND `Idx`=0) OR (`ConversationId`=6038 AND `ConversationActorId`=58162 AND `Idx`=0) OR (`ConversationId`=5488 AND `ConversationActorId`=59530 AND `Idx`=0) OR (`ConversationId`=5478 AND `ConversationActorId`=58380 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(6050, 58162, 0, 26124),
(5474, 58162, 0, 26124),
(6038, 58162, 0, 26124),
(5488, 59530, 0, 26124),
(5478, 58380, 0, 26124);

UPDATE `conversation_actors` SET `VerifiedBuild`=26124 WHERE (`ConversationId`=6026 AND `ConversationActorId`=51642 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26124 WHERE (`ConversationId`=5472 AND `ConversationActorId`=58162 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=26124 WHERE (`ConversationId`=6026 AND `ConversationActorId`=51642 AND `Idx`=0);

DELETE FROM `conversation_actor_template` WHERE `Id`=59530;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(59530, 120514, 75811, 26124);

UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=58162;
UPDATE `conversation_actor_template` SET `CreatureId`=120218, `CreatureModelId`=74146, `VerifiedBuild`=26124 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=58162;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=58162;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=58162;
UPDATE `conversation_actor_template` SET `CreatureId`=120218, `CreatureModelId`=74146, `VerifiedBuild`=26124 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `VerifiedBuild`=26124 WHERE `Id`=58380;

DELETE FROM `conversation_line_template` WHERE `Id` IN (13443, 12302, 13431, 12316, 12306);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(13443, 0, 107, 0, 0, 26124),
(12302, 0, 107, 0, 0, 26124),
(13431, 0, 107, 0, 0, 26124),
(12316, 0, 83, 0, 0, 26124),
(12306, 0, 120, 0, 0, 26124);

UPDATE `conversation_line_template` SET `VerifiedBuild`=26124 WHERE `Id`=13419;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26124 WHERE `Id`=12300;
UPDATE `conversation_line_template` SET `VerifiedBuild`=26124 WHERE `Id`=13419;

DELETE FROM `conversation_template` WHERE `Id` IN (6050, 5478, 5488, 5474, 6038);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(6050, 13443, 8246, 26124),
(5478, 12306, 15020, 26124),
(5488, 12316, 9528, 26124),
(5474, 12302, 13462, 26124),
(6038, 13431, 8064, 26124);

UPDATE `conversation_template` SET `LastLineEndTime`=2859, `VerifiedBuild`=26124 WHERE `Id`=6026;
UPDATE `conversation_template` SET `LastLineEndTime`=2859, `VerifiedBuild`=26124 WHERE `Id`=6026;
UPDATE `conversation_template` SET `LastLineEndTime`=9470, `VerifiedBuild`=26124 WHERE `Id`=5472;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (273414 /*Ancienne cache érédar*/, 273775 /*Tome en bon état*/, 273301 /*Ancienne cache érédar*/, 268760 /*Matrice d'argunite*/, 272009 /*Collection de cristaux préservée*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(273414, 0, 278528), -- Ancienne cache érédar
(273775, 0, 262144), -- Tome en bon état
(273301, 0, 2375680), -- Ancienne cache érédar
(268760, 0, 262144), -- Matrice d'argunite
(272009, 0, 4); -- Collection de cristaux préservée

UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry`=273415; -- Ancienne cache érédar


UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=251162 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (126152 /*126152 (Genéral Zah'd)*/, 127791 /*127791 (Grande tisseuse d'ombre)*/, 127798 /*127798 (Ecorcheur du Vide)*/, 122405 /*122405 (Adjuratrice ombre-garde)*/, 127281 /*127281 (Carabuk hébété) - Sombre expérience*/, 127285 /*127285 (Marsuul hébété) - Sombre expérience*/, 127286 /*127286 (Panthara hébétée) - Sombre expérience*/, 127287 /*127287 (Raie de mana hébétée) - Sombre expérience*/, 125849 /*125849 (Site d'invasion : Aurinor)*/, 126910 /*126910 (Commandant Xethgar)*/, 125842 /*125842 (Vigilant domestique)*/, 126889 /*126889 (Sorolis l'Infortuné)*/, 127397 /*127397 (Pénétrer dans la Salle de l'Érudition)*/, 127409 /*127409 (Sculpture antique de consul) - Aura de statue bleue*/, 127410 /*127410 (Sculpture antique d'éveilleur) - Aura de statue jaune*/, 127411 /*127411 (Sculpture antique d'érudit) - Aura de statue rouge*/, 126866 /*126866 (Vigilant Kuro)*/, 128357 /*128357 (Assemblage d'Argus endommagé) - Permanent Feign Death (No Anim)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(126152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126152 (Genéral Zah'd)
(127791, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127791 (Grande tisseuse d'ombre)
(127798, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 127798 (Ecorcheur du Vide)
(122405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122405 (Adjuratrice ombre-garde)
(127281, 0, 0, 50331648, 1, 0, 0, 0, 0, '252683'), -- 127281 (Carabuk hébété) - Sombre expérience
(127285, 0, 0, 50331648, 1, 0, 0, 0, 0, '252681'), -- 127285 (Marsuul hébété) - Sombre expérience
(127286, 0, 0, 50331648, 1, 0, 0, 0, 0, '252684'), -- 127286 (Panthara hébétée) - Sombre expérience
(127287, 0, 0, 50331648, 1, 0, 0, 0, 0, '252685'), -- 127287 (Raie de mana hébétée) - Sombre expérience
(125849, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125849 (Site d'invasion : Aurinor)
(126910, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126910 (Commandant Xethgar)
(125842, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125842 (Vigilant domestique)
(126889, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126889 (Sorolis l'Infortuné)
(127397, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 127397 (Pénétrer dans la Salle de l'Érudition)
(127409, 0, 0, 0, 1, 0, 0, 0, 0, '252902'), -- 127409 (Sculpture antique de consul) - Aura de statue bleue
(127410, 0, 0, 0, 1, 0, 0, 0, 0, '252904'), -- 127410 (Sculpture antique d'éveilleur) - Aura de statue jaune
(127411, 0, 0, 0, 1, 0, 0, 0, 0, '252903'), -- 127411 (Sculpture antique d'érudit) - Aura de statue rouge
(126866, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126866 (Vigilant Kuro)
(128357, 0, 0, 0, 1, 0, 0, 0, 0, '145751'); -- 128357 (Assemblage d'Argus endommagé) - Permanent Feign Death (No Anim)

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=121670; -- 121670 (Adepte ombre-garde)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=126997; -- 126997 (Gangre-lanceur du Trône ardent)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=124435; -- 124435 (Maître-démon antoréen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=121395; -- 121395
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='246008' WHERE `entry`=123471; -- 123471 (Novice augari)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='140387' WHERE `entry`=123472; -- 123472 (Novice augari)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=123506; -- 123506 (Invocateur augari)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=123505; -- 123505 (Invocatrice augari)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=122359; -- 122359 (Marchand rémanent)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122357; -- 122357 (Habitant oublié)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=128217; -- 128217
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=128203; -- 128203 (Paysagiste du tournoi)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122358; -- 122358 (Habitante oubliée)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `auras`='' WHERE `entry`=122022; -- 122022 (Ombraileron)
UPDATE `creature_template_addon` SET `bytes1`=33554432 WHERE `entry`=126913; -- 126913 (Ondulon le Dernier)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=121565; -- 121565 (Carabuk aliéné par l'Ombre)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=121564; -- 121564 (Carabuk bondissant)
UPDATE `creature_template_addon` SET `auras`='245052' WHERE `entry`=121563; -- Krokul happé par les ténèbres
UPDATE `creature_template_addon` SET `auras`='245049' WHERE `entry`=121562; -- 121562 (Marsuul follombre)
UPDATE `creature_template_addon` SET `auras`='245068' WHERE `entry`=119874; -- 119874 (Panthara court-l'ombre)
UPDATE `creature_template_addon` SET `auras`='244841' WHERE `entry`=124398; -- 124398 (Manifestation du Vide)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123301; -- Krokul touché par l'Ombre
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='120703' WHERE `entry`=122365; -- 122365 (Marsuul floremarche)
UPDATE `creature_template_addon` SET `auras`='160677' WHERE `entry`=121250; -- Krokul touché par l'Ombre
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121251; -- 121251 (Krokul troublé par le Vide)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='120703' WHERE `entry`=125830; -- 125830 (Marsuul pygmée)
UPDATE `creature_template_addon` SET `auras`='99203' WHERE `entry`=120603; -- 120603 (Echo zélé)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=120836; -- 120836 (Echo d'âme distordue)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=120693; -- 120693
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=119968; -- 119968 (Marsuul foudrepatte)
UPDATE `creature_template_addon` SET `auras`='131727' WHERE `entry`=119745; -- 119745 (Petit marsuul)
UPDATE `creature_template_addon` SET `auras`='243314' WHERE `entry`=119864; -- 119864 (Echo fanatique)
UPDATE `creature_template_addon` SET `auras`='243314' WHERE `entry`=119866; -- 119866 (Echo fanatique)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=126043; -- 126043
UPDATE `creature_template_addon` SET `auras`='237554 240226' WHERE `entry`=126030; -- 126030
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126390; -- 126390 (Thelbus Chignopine)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=125523; -- 125523

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (122363, 121670, 121671, 122022, 121674, 126952, 126913, 121562, 119749, 119748, 121563, 124430, 119828, 119745, 123507, 121564, 124446, 119864, 122010, 123508, 122014, 119884, 124444, 127044, 120836, 121629, 128357, 123504, 126869, 122353, 126866, 124432, 123474, 123196, 126959, 120603, 119968, 122015, 119866, 126908, 122946, 120604, 123574, 119874, 126889, 122368, 126960, 126939, 119747, 119077, 121675, 127518, 124312, 121673, 128176, 126912, 121672, 126152, 121263, 124440, 126900, 126910);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(122363, 0, 26124),
(121670, 0, 26124),
(121671, 0, 26124),
(122022, 0, 26124),
(121674, 0, 26124),
(126952, 0, 26124),
(126913, 0, 26124),
(121562, 0, 26124),
(119749, 0, 26124),
(119748, 0, 26124),
(121563, 0, 26124),
(124430, 0, 26124),
(119828, 0, 26124),
(119745, 0, 26124),
(123507, 0, 26124),
(121564, 0, 26124),
(124446, 0, 26124),
(119864, 0, 26124),
(122010, 0, 26124),
(123508, 0, 26124),
(122014, 0, 26124),
(119884, 0, 26124),
(124444, 0, 26124),
(127044, 0, 26124),
(120836, 0, 26124),
(121629, 0, 26124),
(128357, 0, 26124),
(123504, 0, 26124),
(126869, 0, 26124),
(122353, 0, 26124),
(126866, 0, 26124),
(124432, 0, 26124),
(123474, 0, 26124),
(123196, 0, 26124),
(126959, 0, 26124),
(120603, 0, 26124),
(119968, 0, 26124),
(122015, 0, 26124),
(119866, 0, 26124),
(126908, 0, 26124),
(122946, 0, 26124),
(120604, 0, 26124),
(123574, 0, 26124),
(119874, 0, 26124),
(126889, 0, 26124),
(122368, 0, 26124),
(126960, 0, 26124),
(126939, 0, 26124),
(119747, 0, 26124),
(119077, 0, 26124),
(121675, 0, 26124),
(127518, 0, 26124),
(124312, 0, 26124),
(121673, 0, 26124),
(128176, 0, 26124),
(126912, 0, 26124),
(121672, 0, 26124),
(126152, 0, 26124),
(121263, 0, 26124),
(124440, 0, 26124),
(126900, 0, 26124),
(126910, 0, 26124);



UPDATE `creature_model_info` SET `BoundingRadius`=1.318045, `CombatReach`=2, `VerifiedBuild`=26124 WHERE `DisplayID`=78760;
UPDATE `creature_model_info` SET `BoundingRadius`=1.462744, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=75471;
UPDATE `creature_model_info` SET `BoundingRadius`=1.262269, `CombatReach`=2, `VerifiedBuild`=26124 WHERE `DisplayID`=76900;
UPDATE `creature_model_info` SET `BoundingRadius`=1.593707, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=78264;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79736;
UPDATE `creature_model_info` SET `BoundingRadius`=4.394217, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=74902;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75008;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75005;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75011;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76899;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74885;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76939;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77177;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76423;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67538;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77922;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79206;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79204;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79199;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79203;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78361;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76684;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79205;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78360;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78363;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78359;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75581;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78065;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78362;
UPDATE `creature_model_info` SET `BoundingRadius`=1.9379, `CombatReach`=6, `VerifiedBuild`=26124 WHERE `DisplayID`=78364;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63536;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75203;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75425;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7028427, `CombatReach`=1.8, `VerifiedBuild`=26124 WHERE `DisplayID`=78621;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75417;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75207;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75426;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75678;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75424;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75427;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78606;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77026;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77021;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75418;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76338;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78288;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78385;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77024;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78287;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78505;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77022;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78289;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77371;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77374;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77098;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79748;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76300;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3, `CombatReach`=1.95, `VerifiedBuild`=26124 WHERE `DisplayID`=79150;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77373;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77352;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77351;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77372;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77353;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=59112;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77350;
UPDATE `creature_model_info` SET `BoundingRadius`=0.27, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=78961;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=1.5, `VerifiedBuild`=26124 WHERE `DisplayID`=78960;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77346;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77343;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79931;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77347;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=57521;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75470;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80396;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79160;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77389;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77387;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77344;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77345;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77349;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77348;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76588;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77388;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77342;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77747;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76636;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79749;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75914;
UPDATE `creature_model_info` SET `BoundingRadius`=3.221362, `CombatReach`=8.25, `VerifiedBuild`=26124 WHERE `DisplayID`=79928;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80278;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76015;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80275;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80272;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79202;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80273;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80274;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8657478, `CombatReach`=0.75, `VerifiedBuild`=26124 WHERE `DisplayID`=80271;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28111;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75915;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78597;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78595;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76816;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76832;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76819;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76845;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=81492;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76314;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78958;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76818;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76820;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80282;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80280;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78522;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76830;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76833;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80286;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76817;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79201;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80281;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76822;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80284;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79671;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80283;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79187;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80277;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76826;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76831;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76824;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76827;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76828;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77204;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=81493;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76829;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76825;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76821;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79189;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78523;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79192;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79191;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79193;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79194;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76309;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79188;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79190;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76310;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79060;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78937;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1130;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79221;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79735;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76602;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=62382;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=62384;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76601;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74903;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76600;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78378;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78380;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76336;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78388;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63407;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79241;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78383;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77159;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76308;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76406;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77158;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78509;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77157;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75146;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78511;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75178;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75183;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76605;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75224;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76405;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76404;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76587;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79020;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77113;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77128;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75480;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78502;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77523;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75479;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76237;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76227;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76233;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76231;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78500;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78499;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76234;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75468;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75474;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76232;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76235;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76236;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=60404;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78598;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78599;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75524;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75869;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75871;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75870;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75875;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75873;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75514;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75512;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75523;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79925;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75517;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75519;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74905;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36944;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75872;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75868;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74907;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3, `CombatReach`=1.95, `VerifiedBuild`=26124 WHERE `DisplayID`=75518;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75874;
UPDATE `creature_model_info` SET `BoundingRadius`=1.3, `CombatReach`=1.95, `VerifiedBuild`=26124 WHERE `DisplayID`=75513;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75920;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75996;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36952;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36955;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78508;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75472;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75475;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75918;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75526;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75913;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75917;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=77656;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75527;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75521;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75522;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75490;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75919;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75520;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75516;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76555;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75916;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75525;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78661;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79812;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=39810;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71154;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78432;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79483;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78386;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78910;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74146;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75811;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78097;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=79813;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76339;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78387;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71155;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=122405 AND `ID`=1) OR (`CreatureID`=126910 AND `ID`=1) OR (`CreatureID`=125842 AND `ID`=1) OR (`CreatureID`=126889 AND `ID`=1) OR (`CreatureID`=126866 AND `ID`=1) OR (`CreatureID`=128357 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(122405, 1, 42348, 0, 0, 116709, 0, 0, 0, 0, 0), -- Adjuratrice ombre-garde
(126910, 1, 147493, 0, 0, 0, 0, 0, 0, 0, 0), -- Commandant Xethgar
(125842, 1, 114823, 0, 0, 114824, 0, 0, 0, 0, 0), -- Vigilant domestique
(126889, 1, 124728, 0, 0, 0, 0, 0, 0, 0, 0), -- Sorolis l'Infortuné
(126866, 1, 153354, 0, 0, 153353, 0, 0, 0, 0, 0), -- Vigilant Kuro
(128357, 1, 114920, 0, 0, 114921, 0, 0, 0, 0, 0); -- Assemblage d'Argus endommagé


UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110456; -- Unseen Marksman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109577; -- Earthen Ring Geomancer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123258; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126152; -- Genéral Zah'd
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1073741824, `VerifiedBuild`=26124 WHERE `entry`=128318; -- Traqueur de piège instable
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111727; -- Aluneth
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=2097224, `HealthModifier`=1.15385, `VerifiedBuild`=26124 WHERE `entry`=127798; -- Ecorcheur du Vide
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=15, `VerifiedBuild`=26124 WHERE `entry`=127791; -- Grande tisseuse d'ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127783; -- Adjuratrice ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127786; -- Seigneur du Vide lié
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=6.23077, `VerifiedBuild`=26124 WHERE `entry`=122405; -- Adjuratrice ombre-garde
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=4, `type_flags`=2097224, `HealthModifier`=8, `movementId`=144, `VerifiedBuild`=26124 WHERE `entry`=122412; -- Seigneur du Vide lié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128017; -- Sang vicié d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119077; -- Protectrice de la Sylverêve
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `family`=151, `type`=1, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=127281; -- Carabuk hébété
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `family`=127, `type`=1, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=127285; -- Marsuul hébété
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=1, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=127286; -- Panthara hébétée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121629; -- Traqueur du Vide ensorcelé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121670; -- Adepte ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121672; -- Phase-lame ombre-garde
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `family`=34, `type`=1, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=127287; -- Raie de mana hébétée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121671; -- Siphonneur ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121644; -- 121644
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121673; -- Traqueur gorgé de Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127797; -- Champion ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127795; -- Adepte de la guerre ombreux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127796; -- Traque-faille ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126249; -- Traqueur d'orbe du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125102; -- Portail du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127784; -- Arqueur du Vide ombre-garde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127135; -- Tas de pierres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127793; -- Décharge du Vide
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1074790416, `type_flags2`=70, `VerifiedBuild`=26124 WHERE `entry`=125849; -- Site d'invasion : Aurinor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111316; -- Silver Hand Templar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111292; -- Silver Hand Knight
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125350; -- Balise sancteforge
UPDATE `creature_template` SET `HealthScalingExpansion`=2, `VerifiedBuild`=26124 WHERE `entry`=54569; -- Transcendence Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99625; -- Wind Spirit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126994; -- Ancien citoyen
UPDATE `creature_template` SET `HealthModifier`=60, `VerifiedBuild`=26124 WHERE `entry`=126912; -- Skreeg le Dévoreur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126993; -- Ancien citoyen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126992; -- Ancienne citoyenne
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126997; -- Gangre-lanceur du Trône ardent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126459; -- Lieu d'excavation
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126996; -- Molosse antoréen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126995; -- Garde-portail antoréen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120514; -- Grand exarque Turalyon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127271; -- Portail de la Légion
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2251, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=61, `VerifiedBuild`=26124 WHERE `entry`=126910; -- Commandant Xethgar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126998; -- Exécuteur du Trône ardent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=58960; -- Seigneur du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126999; -- Oeil d'Antorus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124485; -- 124485
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26124 WHERE `entry`=125937; -- Vigilant domestique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128174; -- Wyrm ivre de corruption
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125259; -- Extraterrestrial Exploration - Arinor Gardens
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=4, `VerifiedBuild`=26124 WHERE `entry`=125842; -- Vigilant domestique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124432; -- Manœuvre antoréen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124435; -- Maître-démon antoréen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124430; -- Démon traqueur abject
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125841; -- Wyrm ivre de corruption
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124448; -- Spoliateur antoréen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124446; -- Larve gueule-d'acide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124313; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124998; -- Bouclier
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124997; -- Bouclier
UPDATE `creature_template` SET `HealthModifier`=68, `VerifiedBuild`=26124 WHERE `entry`=124440; -- Surveillante Y'Beda
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124999; -- Bouclier
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124444; -- Aile démoniaque gueule-d'acide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125002; -- Bouclier - Bun
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128013; -- Talbie
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2243, `rank`=2, `type`=7, `type_flags`=2097224, `HealthModifier`=64, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=126889; -- Sorolis l'Infortuné
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=26124 WHERE `entry`=127397; -- Pénétrer dans la Salle de l'Érudition
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124076; -- 124076
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123574; -- Assemblage d'âmes liées
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123504; -- Eveilleur augari
UPDATE `creature_template` SET `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=26124 WHERE `entry`=127409; -- Sculpture antique de consul
UPDATE `creature_template` SET `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=26124 WHERE `entry`=127411; -- Sculpture antique d'érudit
UPDATE `creature_template` SET `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=26124 WHERE `entry`=127410; -- Sculpture antique d'éveilleur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123474; -- Consul augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127044; -- Familier de mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123567; -- Familier arcanique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123527; -- Brouteur carabuk
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124773; -- Assemblage d'âmes liées
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123471; -- Novice augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123507; -- Familier arcanique agité
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123512; -- Marsuul coursemage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123472; -- Novice augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128172; -- Goinfre de mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124070; -- Vigilant Quoram
UPDATE `creature_template` SET `HealthModifier`=65, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=126900; -- Instructrice Tarahna
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123521; -- Grand vizir Jarasum
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123511; -- Raie de mana arcaileron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123520; -- Grande consule Vélara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123522; -- Grand Éveilleur Aargon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123506; -- Invocateur augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98167; -- Void Tendril
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123505; -- Invocatrice augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123488; -- Vigilant du conservatorium
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123508; -- Panthara dévore-mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123629; -- Ether rémanent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124558; -- Conduit de puissance
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128015; -- Brunaile
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2237, `rank`=2, `type`=9, `type_flags`=270532680, `HealthModifier`=86, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=126866; -- Vigilant Kuro
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128194; -- Ciaileron domestiqué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128195; -- 128195
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128192; -- Exploitant de cristaux oublié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128193; -- Marsuul domestiqué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128191; -- Argunite de culture
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128196; -- Carabuk domestiqué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128288; -- Hakmud d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125827; -- Goinfre de mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128173; -- Marsuul pygmée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122359; -- Marchand rémanent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122368; -- Assemblage d'Argus détraqué
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122361; -- Marchande rémanente
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `RequiredExpansion`=6, `type`=9, `type_flags`=144, `type_flags2`=6, `HealthModifier`=3, `VerifiedBuild`=26124 WHERE `entry`=128357; -- Assemblage d'Argus endommagé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122353; -- Assemblage d'Argus ancien
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126959; -- Habitant sans repos
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120218; -- Illidan Hurlorage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126960; -- Habitante sans repos
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126952; -- Jeune marcheur des ruines
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128215; -- Akama
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128211; -- Conseiller Hataaru
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125532; -- Maître jed'hin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125737; -- Fight Point
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125738; -- Maître jed'hin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128198; -- Y'selfa l'artisane
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128217; -- 128217
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128199; -- Kuraam
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128208; -- Guérisseuse Askara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128210; -- Gardien de reliques Calindris
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122357; -- Habitant oublié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128213; -- Naielle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128214; -- Conseiller Othaar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128212; -- Conseiller Larohir
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128203; -- Paysagiste du tournoi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126971; -- Habitante oubliée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126970; -- Habitant oublié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122360; -- Vestige de jeunesse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122358; -- Habitante oubliée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126939; -- Cerf marcheur des ruines
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126977; -- Maître jed'hin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126976; -- Adepte jed'hin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=91250; -- Iron Warwolf
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126975; -- Novice jed'hin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122363; -- Marcheur des ruines carabuk
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121675; -- Implorateur du Vide ensorcelé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121676; -- Moissonneur du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121674; -- Grignoteur du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123196; -- Marcheur du Vide ensorcelé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127023; -- Fragment d'ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128016; -- Danse-l'ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123051; -- 123051
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121645; -- 121645
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122015; -- Falcostrige du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127146; -- Tas de pierres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128171; -- Eclaté du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122014; -- Obscurité insidieuse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122022; -- Ombraileron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122010; -- Panthara croc-d'ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127083; -- Artificière Andaara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126951; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126047; -- Tireur de précision sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126044; -- Rempart sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126048; -- Prêtre de guerre sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121565; -- Carabuk aliéné par l'Ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125260; -- Extraterrestrial Exploration - Oronaar Collapse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=127037; -- Nabiru
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121564; -- Carabuk bondissant
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125504; -- Eclaté du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125505; -- Suintement chaotique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122946; -- Engeance du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122945; -- Dévot d'Isolon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121563; -- Krokul happé par les ténèbres
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121562; -- Marsuul follombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119874; -- Panthara court-l'ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128168; -- Traqueur du Vide chétif
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109839; -- Druid of the Claw
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122770; -- Griffonnages frénétiques au mur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126638; -- Premier Naaru
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124398; -- Manifestation du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128176; -- Sort de sécurité augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119747; -- Traqueur du Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125495; -- Traqueur du Vide chétif
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123667; -- Grande lectrice Enaara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123302; -- Krokul troublé par le Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123301; -- Krokul touché par l'Ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119749; -- Krokul marqué par le Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128167; -- Jeune ciaileron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122768; -- Autel abandonné
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126368; -- Enquêter dans les ruines d'Oronaar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125493; -- Jeune ciaileron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121250; -- Krokul touché par l'Ombre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122365; -- Marsuul floremarche
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122364; -- Petit marsuul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125830; -- Marsuul pygmée
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121251; -- Krokul troublé par le Vide
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119884; -- Ancien traqueur des ruines
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119868; -- Echo horrifié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120690; -- Echo fidèle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119870; -- Echo horrifié
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119828; -- Vigilant argusséen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120223; -- Prophète Velen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119748; -- Raie de mana ciaileron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120689; -- Echo fidèle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120603; -- Echo zélé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120894; -- 120894
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120604; -- Echo zélé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120836; -- Echo d'âme distordue
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=128170; -- Traqueur dimensionnel chétif
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120536; -- Pylône ancien
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120693; -- 120693
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125855; -- Phalène d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119968; -- Marsuul foudrepatte
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125499; -- Traqueur dimensionnel chétif
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119745; -- Petit marsuul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120883; -- Echo d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120884; -- Echo d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119864; -- Echo fanatique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119866; -- Echo fanatique
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120875; -- Echo d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120876; -- Echo d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120877; -- Echo d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96622; -- Ronchon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121059; -- 121059
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122509; -- Balise sancteforge
UPDATE `creature_template` SET `HealthModifier`=69, `VerifiedBuild`=26124 WHERE `entry`=126869; -- Capitaine Faruq
UPDATE `creature_template` SET `HealthModifier`=63, `VerifiedBuild`=26124 WHERE `entry`=126908; -- Zul'tan l'Abondant
UPDATE `creature_template` SET `HealthModifier`=78, `VerifiedBuild`=26124 WHERE `entry`=126913; -- Ondulon le Dernier
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124015; -- Intendante Kl'azz
UPDATE `creature_template` SET `HealthModifier`=80, `VerifiedBuild`=26124 WHERE `entry`=122912; -- Commandant Sathrenaël
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2201, `type_flags`=2097224, `HealthModifier`=74, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=123464; -- Soeur Subversia
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=122942; -- Erudite gangre-liée
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2225, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=66, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=124804; -- Tereck le Sélectionneur
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VignetteID`=2265, `rank`=2, `type`=3, `type_flags`=2097224, `HealthModifier`=76, `VerifiedBuild`=26124 WHERE `entry`=126040; -- Puscilla
UPDATE `creature_template` SET `HealthModifier`=70, `ManaModifier`=1, `VerifiedBuild`=26124 WHERE `entry`=122947; -- Maîtresse Il'thendra
UPDATE `creature_template` SET `HealthModifier`=80, `VerifiedBuild`=26124 WHERE `entry`=126254; -- Lieutenant Xakaar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124312; -- Grand exarque Turalyon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121263; -- Grand artificier Romuul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126408; -- Illidan Hurlorage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=126390; -- Thelbus Chignopine
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=123139; -- Console de navigation
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121397; -- Prêtre de guerre sancteforge


UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127791 AND `Idx`=0); -- Grande tisseuse d'ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127783 AND `Idx`=0); -- Adjuratrice ombre-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122405 AND `Idx`=0); -- Adjuratrice ombre-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127797 AND `Idx`=0); -- Champion ombre-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127795 AND `Idx`=0); -- Adepte de la guerre ombreux
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127796 AND `Idx`=0); -- Traque-faille ombre-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=127784 AND `Idx`=0); -- Arqueur du Vide ombre-garde
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124432 AND `Idx`=0); -- Manœuvre antoréen
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124435 AND `Idx`=0); -- Maître-démon antoréen
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124430 AND `Idx`=0); -- Démon traqueur abject
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124448 AND `Idx`=0); -- Spoliateur antoréen
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=124444 AND `Idx`=0); -- Aile démoniaque gueule-d'acide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123504 AND `Idx`=2); -- Eveilleur augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123504 AND `Idx`=1); -- Eveilleur augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123504 AND `Idx`=0); -- Eveilleur augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123474 AND `Idx`=2); -- Consul augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123474 AND `Idx`=1); -- Consul augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123474 AND `Idx`=0); -- Consul augari
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123508 AND `Idx`=1); -- Panthara dévore-mana
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123508 AND `Idx`=0); -- Panthara dévore-mana
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122368 AND `Idx`=0); -- Assemblage d'Argus détraqué
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122353 AND `Idx`=0); -- Assemblage d'Argus ancien
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122014 AND `Idx`=0); -- Obscurité insidieuse
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=122010 AND `Idx`=0); -- Panthara croc-d'ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121563 AND `Idx`=2); -- Krokul happé par les ténèbres
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121563 AND `Idx`=1); -- Krokul happé par les ténèbres
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121563 AND `Idx`=0); -- Krokul happé par les ténèbres
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123302 AND `Idx`=1); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123302 AND `Idx`=0); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123301 AND `Idx`=1); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=123301 AND `Idx`=0); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119749 AND `Idx`=1); -- Krokul marqué par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119749 AND `Idx`=0); -- Krokul marqué par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121250 AND `Idx`=3); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121250 AND `Idx`=2); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121250 AND `Idx`=1); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121250 AND `Idx`=0); -- Krokul touché par l'Ombre
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121251 AND `Idx`=3); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121251 AND `Idx`=2); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121251 AND `Idx`=1); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=121251 AND `Idx`=0); -- Krokul troublé par le Vide
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=120603 AND `Idx`=0); -- Echo zélé
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=120604 AND `Idx`=0); -- Echo zélé
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=120836 AND `Idx`=0); -- Echo d'âme distordue
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119864 AND `Idx`=0); -- Echo fanatique
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=119866 AND `Idx`=0); -- Echo fanatique

DELETE FROM `gameobject_template` WHERE `entry` IN (277388 /*Pierre de rencontre du Siège du triumvirat*/, 271722 /*271722*/, 273774 /*[DNT] Altar*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(277388, 23, 5495, 'Seat of the Triumvirate Meeting Stone', '', '', '', 1, 110, 255, 8910, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Pierre de rencontre du Siège du triumvirat
(271722, 5, 43094, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- 271722
(273774, 5, 44237, '[DNT] Altar', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- [DNT] Altar

UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=179944; -- Meeting Stone Summoning Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273696; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273439; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277286; -- Portail vers la surface de Mac’Aree
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276229; -- Coffre de maison brisé
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273412; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276224; -- Coffre de biens mal acquis
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273959; -- Tas de rochers
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272688; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272745; -- Métier à tisser le tisse-lumière
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277402; -- Banc
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277404; -- Banc
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273415; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273407; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277340; -- Coffre augari secret
UPDATE `gameobject_template` SET `type`=50, `displayId`=23883, `Data0`=57, `Data1`=75774, `Data6`=300, `Data9`=21400, `Data17`=2086, `Data18`=20, `Data19`=1, `RequiredLevel`=110, `VerifiedBuild`=26124 WHERE `entry`=273414; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=275108; -- Portail de la Légion
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269894; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272448; -- Pylône sacré
UPDATE `gameobject_template` SET `type`=10, `displayId`=18306, `size`=2, `Data0`=1634, `Data3`=3000, `Data7`=7303, `Data9`=1, `Data17`=1, `Data20`=1, `Data22`=52178, `Data26`=1, `VerifiedBuild`=26124 WHERE `entry`=273775; -- Tome en bon état
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273915; -- Cristal de guérison ancien
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273424; -- Wall Lock (Cosmetic)
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272744; -- Coffre de Vorel
UPDATE `gameobject_template` SET `type`=50, `displayId`=23883, `Data0`=57, `Data1`=75758, `Data6`=300, `Data9`=21400, `Data17`=2069, `Data18`=20, `Data19`=1, `RequiredLevel`=110, `VerifiedBuild`=26124 WHERE `entry`=273301; -- Ancienne cache érédar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252145; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272780; -- Veine d'empyrium
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276232; -- Tas de rochers
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276226; -- Coffre teinté de vide
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=275094; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276230; -- Trésor du cherche-destin
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276835; -- Portail vers la surface de Mac’Aree
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276183; -- Feu de camp abandonné
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271100; -- Griffonnages frénétiques au mur
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273916; -- Cristal d’amélioration ancien
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273914; -- Cristal de garde ancien
UPDATE `gameobject_template` SET `type`=10, `displayId`=44047, `size`=0.2, `Data0`=1690, `Data3`=1, `Data10`=240355, `Data14`=131380, `Data20`=1, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=268760; -- Matrice d'argunite
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=277342; -- Fournitures augari
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272768; -- Gisement d'empyrium
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271103; -- Effigie de prière
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=273674; -- 273674
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=273676; -- 273676
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271097; -- Autel abandonné
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=273677; -- 273677
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=273673; -- 273673
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=273675; -- 273675
UPDATE `gameobject_template` SET `type`=3, `displayId`=15025, `Data0`=1690, `Data3`=1, `Data14`=69544, `Data16`=1, `Data17`=53209, `Data30`=74438, `VerifiedBuild`=26124 WHERE `entry`=272009; -- Collection de cristaux préservée
UPDATE `gameobject_template` SET `name`='', `VerifiedBuild`=26124 WHERE `entry`=272062; -- 272062
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273661; -- Porte d’entrée
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=276233; -- Porte
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273721; -- Jugement de la Lumière
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273515; -- Le Vindicaar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=272782; -- Astralée
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268745; -- Pylône ancien
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=270938; -- Balise sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273684; -- Bottes de magie
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=273683; -- Chapeau magique
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=233662; -- Small Crate

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=272009 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(272009, 0, 151555, 26124); -- Collection de cristaux préservée

UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=272745 AND `Idx`=0); -- Métier à tisser le tisse-lumière
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=272744 AND `Idx`=0); -- Coffre de Vorel
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=276226 AND `Idx`=0); -- Coffre teinté de vide

