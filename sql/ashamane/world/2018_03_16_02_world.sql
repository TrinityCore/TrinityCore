UPDATE `areatrigger_template` SET `Data0`=4.828773, `Data1`=4.828773, `VerifiedBuild`=26124 WHERE `Id`=10713;
UPDATE `areatrigger_template` SET `Type`=1, `Data0`=2.5, `Data1`=2.5, `Data2`=3, `Data3`=2.5, `Data4`=2.5, `Data5`=3, `VerifiedBuild`=26124 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10991;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11908;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=13120;


UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=6321 AND `AreaTriggerId`=10991); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=90000, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=8000 WHERE (`SpellMiscId`=11408 AND `AreaTriggerId`=16170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=9080 AND `AreaTriggerId`=13120); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5484 AND `ConversationActorId`=59284 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(5484, 59284, 0, 26124);


DELETE FROM `conversation_actor_template` WHERE `Id`=59284;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(59284, 123679, 77522, 26124);


DELETE FROM `conversation_line_template` WHERE `Id`=12312;
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(12312, 0, 108, 0, 0, 26124);


DELETE FROM `conversation_template` WHERE `Id`=5484;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(5484, 12312, 15494, 26124);


DELETE FROM `gameobject_template_addon` WHERE `entry`=271098;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(271098, 0, 262144); -- Figurine naaru abandonnée


DELETE FROM `creature_template_addon` WHERE `entry` IN (128359 /*128359 (Invocateur augari résonnant) - Lire le parchemin*/, 128358 /*128358 (Novice augari résonnant) - Lecture assise*/, 122769 /*122769 (Figurine naaru dégradée)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(128359, 0, 0, 0, 1, 0, 0, 0, 0, '133464'), -- 128359 (Invocateur augari résonnant) - Lire le parchemin
(128358, 0, 0, 1, 1, 0, 0, 0, 0, '101059'), -- 128358 (Novice augari résonnant) - Lecture assise
(122769, 0, 0, 50331648, 1, 0, 0, 0, 0, ''); -- 122769 (Figurine naaru dégradée)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123508; -- 123508 (Panthara dévore-mana)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123574; -- 123574 (Assemblage d'âmes liées)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='252178' WHERE `entry`=123504; -- Eveilleur augari
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=124440; -- 124440 (Surveillante Y'Beda)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123471; -- 123471 (Novice augari)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=123505; -- 123505 (Invocatrice augari)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=123506; -- 123506 (Invocateur augari)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=123472; -- 123472 (Novice augari)
UPDATE `creature_template_addon` SET `auras`='145751' WHERE `entry`=123488; -- Vigilant du conservatorium
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=122359; -- 122359 (Marchand rémanent)
UPDATE `creature_template_addon` SET `auras`='252542' WHERE `entry`=122353; -- 122353 (Assemblage d'Argus ancien)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=122365; -- 122365 (Marsuul floremarche)
UPDATE `creature_template_addon` SET `auras`='243926 252542' WHERE `entry`=122368; -- 122368 (Assemblage d'Argus détraqué)
UPDATE `creature_template_addon` SET `auras`='241884' WHERE `entry`=121251; -- 121251 (Krokul troublé par le Vide)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121250; -- Krokul touché par l'Ombre
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=125830; -- 125830
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=119874; -- 119874
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=121564; -- 121564 (Carabuk bondissant)
UPDATE `creature_template_addon` SET `auras`='77131 74490' WHERE `entry`=119828; -- Vigilant argusséen

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (119748, 123474, 123504, 126939, 127044, 119828, 123508, 122363, 122353, 126959, 119874, 126952, 121564, 122368, 119884, 123507, 126960, 126900, 122010, 124477, 124440, 123574);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(119748, 0, 26124),
(123474, 0, 26124),
(123504, 0, 26124),
(126939, 0, 26124),
(127044, 0, 26124),
(119828, 0, 26124),
(123508, 0, 26124),
(122363, 0, 26124),
(122353, 0, 26124),
(126959, 0, 26124),
(119874, 0, 26124),
(126952, 0, 26124),
(121564, 0, 26124),
(122368, 0, 26124),
(119884, 0, 26124),
(123507, 0, 26124),
(126960, 0, 26124),
(126900, 0, 26124),
(122010, 0, 26124),
(124477, 0, 26124),
(124440, 0, 26124),
(123574, 0, 26124);


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=128359 AND `ID`=1) OR (`CreatureID`=128358 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(128359, 1, 124728, 0, 0, 0, 0, 0, 0, 0, 0), -- Invocateur augari résonnant
(128358, 1, 151145, 0, 0, 0, 0, 0, 0, 0, 0); -- Novice augari résonnant



UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=123574; -- Assemblage d'âmes liées
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=127409; -- Sculpture antique de consul
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=127410; -- Sculpture antique d'éveilleur
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=127411; -- Sculpture antique d'érudit
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=128359; -- Invocateur augari résonnant
UPDATE `creature_template` SET `HoverHeight`=1.875 WHERE `entry`=124773; -- Assemblage d'âmes liées
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=128358; -- Novice augari résonnant
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=124070; -- Vigilant Quoram
UPDATE `creature_template` SET `unit_flags`=536903936, `unit_flags2`=2099201, `unit_flags3`=8320 WHERE `entry`=123488; -- Vigilant du conservatorium
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=122360; -- Vestige de jeunesse
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=122769; -- Figurine naaru dégradée
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=121251; -- Krokul troublé par le Vide
UPDATE `creature_template` SET `unit_flags`=570720512 WHERE `entry`=119828; -- Vigilant argusséen

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (123629, 127411, 127410, 127409);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(123629, 247788, 0, 0),
(127411, 252867, 0, 0),
(127410, 252874, 0, 0),
(127409, 252862, 0, 0);


UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=123574; -- Assemblage d'âmes liées
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=123508; -- Panthara dévore-mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110975; -- Unseen Pathfinder
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=123504; -- Eveilleur augari
UPDATE `creature_template` SET `HealthModifier`=68 WHERE `entry`=124440; -- Surveillante Y'Beda
UPDATE `creature_template` SET `HealthModifier`=1 WHERE `entry`=127044; -- Familier de mana
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=123474; -- Consul augari
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=94072; -- Dark Minion
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=15, `VerifiedBuild`=26124 WHERE `entry`=124477; -- Redresseur de torts sancteforge
UPDATE `creature_template` SET `HealthModifier`=0.3 WHERE `entry`=123567; -- Familier arcanique
UPDATE `creature_template` SET `KillCredit1`=128360, `HealthScalingExpansion`=6, `type`=3, `VerifiedBuild`=26124 WHERE `entry`=128359; -- Invocateur augari résonnant
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=123507; -- Familier arcanique agité
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=5, `ManaModifier`=10, `VerifiedBuild`=26124 WHERE `entry`=123679; -- Archimage Y'mera
UPDATE `creature_template` SET `KillCredit1`=128360, `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=26124 WHERE `entry`=128358; -- Novice augari résonnant
UPDATE `creature_template` SET `HealthModifier`=0.2 WHERE `entry`=125827; -- Goinfre de mana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111254; -- Defias Thief
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97022; -- Greater Lightning Elemental
UPDATE `creature_template` SET `HealthModifier`=65 WHERE `entry`=126900; -- Instructrice Tarahna
UPDATE `creature_template` SET `HealthModifier`=1 WHERE `entry`=126959; -- Habitant sans repos
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=126960; -- Habitante sans repos
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=122353; -- Assemblage d'Argus ancien
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=126939; -- Cerf marcheur des ruines
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=122368; -- Assemblage d'Argus détraqué
UPDATE `creature_template` SET `HealthModifier`=0.2 WHERE `entry`=125499; -- Traqueur dimensionnel chétif
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=26124 WHERE `entry`=122769; -- Figurine naaru dégradée
UPDATE `creature_template` SET `HealthModifier`=0.3 WHERE `entry`=126952; -- Jeune marcheur des ruines
UPDATE `creature_template` SET `HealthModifier`=0.5 WHERE `entry`=121564; -- Carabuk bondissant
UPDATE `creature_template` SET `HealthModifier`=3 WHERE `entry`=122010; -- Panthara croc-d'ombre

UPDATE `gameobject_template` SET `type`=10, `displayId`=42717, `castBarCaption`='Inspection', `size`=1.5, `Data0`=1690, `Data3`=3000, `Data10`=244698, `Data14`=45353, `Data20`=1, `Data23`=1, `VerifiedBuild`=26124 WHERE `entry`=271098; -- Figurine naaru abandonnée

