UPDATE `areatrigger_template` SET `VerifiedBuild`=26822 WHERE `Id`=16670;
UPDATE `areatrigger_template` SET `Flags`=1031, `VerifiedBuild`=26822 WHERE `Id`=10003;

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=16670);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(11983, 16670, 0, 0, 0, 0, 0, 2910, 6000, 26822); -- SpellId : 256948

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (280794 /*Rift to Telogrus*/, 280793 /*Rift to Fathom's Edge*/, 253044 /*Pillow*/, 280944 /*Mailbox*/, 268668 /*Stool*/, 279607 /*Rift to Stormwind*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(280794, 0, 32), -- Rift to Telogrus
(280793, 0, 32), -- Rift to Fathom's Edge
(253044, 1375, 16), -- Pillow
(280944, 1732, 0), -- Mailbox
(268668, 1375, 8192), -- Stool
(279607, 0, 32); -- Rift to Stormwind

DELETE FROM `scene_template` WHERE (`SceneId`=1903 AND `ScriptPackageID`=2006);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1903, 9, 2006);

DELETE FROM `creature_template_addon` WHERE `entry` IN (133422 /*133422 (Shadreen)*/, 132730 /*132730 (Voidstorm Visual Bunny) - -Unknown-*/, 132676 /*132676 (Voidstalker)*/, 126773 /*126773 (Locus-Walker)*/, 132407 /*132407 (Umbral Ranger)*/, 132671 /*132671 (High Elf Wayfarer)*/, 132657 /*132657 (Atynar)*/, 132386 /*132386 (Rift Warden)*/, 132616 /*132616 (Silvermoon Scholar)*/, 132400 /*132400 (Curious Voidstalker)*/, 132970 /*132970 (Nascent Voidling)*/, 132385 /*132385 (Locus Researcher) - -Unknown-*/, 132397 /*132397 (Void Suppression Visual Bunny)*/, 132648 /*132648 (Veiled Riftblade)*/, 132705 /*132705 (Danessa)*/, 132382 /*132382 (Magister Umbric)*/, 131345 /*131345 (Alleria Windrunner)*/, 132659 /*132659 (Veiled Riftblade)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(133422, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133422 (Shadreen)
(132730, 0, 0, 0, 1, 0, 0, 0, 0, '262605'), -- 132730 (Voidstorm Visual Bunny) - -Unknown-
(132676, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132676 (Voidstalker)
(126773, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 126773 (Locus-Walker)
(132407, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 132407 (Umbral Ranger)
(132671, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 132671 (High Elf Wayfarer)
(132657, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 132657 (Atynar)
(132386, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 132386 (Rift Warden)
(132616, 0, 0, 1, 257, 0, 0, 0, 0, ''), -- 132616 (Silvermoon Scholar)
(132400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132400 (Curious Voidstalker)
(132970, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132970 (Nascent Voidling)
(132385, 0, 0, 0, 257, 0, 0, 0, 0, '260888'), -- 132385 (Locus Researcher) - -Unknown-
(132397, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132397 (Void Suppression Visual Bunny)
(132648, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 132648 (Veiled Riftblade)
(132705, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132705 (Danessa)
(132382, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132382 (Magister Umbric)
(131345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131345 (Alleria Windrunner)
(132659, 0, 0, 0, 257, 0, 0, 0, 0, ''); -- 132659 (Veiled Riftblade)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (133422, 126773, 132407, 132657, 132386, 132385, 132648, 132705, 132382, 131345, 132659);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(133422, 110, 110, 0, 0, 26822),
(126773, 110, 110, 0, 0, 26822),
(132407, 110, 110, 0, 0, 26822),
(132657, 110, 110, 0, 0, 26822),
(132386, 110, 110, 0, 0, 26822),
(132385, 110, 110, 0, 0, 26822),
(132648, 110, 110, 0, 0, 26822),
(132705, 110, 110, 0, 0, 26822),
(132382, 110, 110, 0, 0, 26822),
(131345, 110, 110, 0, 0, 26822),
(132659, 110, 110, 0, 0, 26822);

UPDATE `creature_model_info` SET `BoundingRadius`=0.6942481, `CombatReach`=1.1, `VerifiedBuild`=26822 WHERE `DisplayID`=78953;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82526;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7573616, `CombatReach`=1.2, `VerifiedBuild`=26822 WHERE `DisplayID`=78749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82513;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82409;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82520;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82519;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3124998, `CombatReach`=1.35, `VerifiedBuild`=26822 WHERE `DisplayID`=82557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82402;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82512;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82549;
UPDATE `creature_model_info` SET `BoundingRadius`=1.299441, `CombatReach`=0.6, `VerifiedBuild`=26822 WHERE `DisplayID`=79002;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82401;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78511;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82400;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82596;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42720;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=42722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3993053, `CombatReach`=1.725, `VerifiedBuild`=26822 WHERE `DisplayID`=82404;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4301679, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=78869;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82548;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=126773 AND `ID`=1) OR (`CreatureID`=132407 AND `ID`=1) OR (`CreatureID`=132648 AND `ID`=1) OR (`CreatureID`=131345 AND `ID`=1) OR (`CreatureID`=132659 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(126773, 1, 124381, 0, 0, 0, 0, 0, 0, 0, 0), -- Locus-Walker
(132407, 1, 0, 0, 0, 0, 0, 0, 105125, 0, 0), -- Umbral Ranger
(132648, 1, 31604, 0, 0, 0, 0, 0, 0, 0, 0), -- Veiled Riftblade
(131345, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Windrunner
(132659, 1, 33295, 0, 0, 153892, 0, 0, 0, 0, 0); -- Veiled Riftblade

UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=4196352 WHERE `entry`=133422; -- Shadreen
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=4196352 WHERE `entry`=132730; -- Voidstorm Visual Bunny
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2774, `speed_walk`=0.4, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132676; -- Voidstalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126773; -- Locus-Walker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2774, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132407; -- Umbral Ranger
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132671; -- High Elf Wayfarer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=65537, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132657; -- Atynar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132386; -- Rift Warden
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132616; -- Silvermoon Scholar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `speed_walk`=0.4, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132400; -- Curious Voidstalker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags2`=2048 WHERE `entry`=132970; -- Nascent Voidling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=132385; -- Locus Researcher
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=132397; -- Void Suppression Visual Bunny
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2774, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132648; -- Veiled Riftblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132705; -- Danessa
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2501, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132382; -- Magister Umbric
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131345; -- Alleria Windrunner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2774, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132659; -- Veiled Riftblade

UPDATE `creature_template` SET `HealthScalingExpansion`=6, `HealthModifier`=10, `VerifiedBuild`=26822 WHERE `entry`=6499; -- Ironhide Devilsaur
UPDATE `creature_template` SET `modelid2`=38373, `VerifiedBuild`=26822 WHERE `entry`=78116; -- Water Elemental
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=131072; -- Voidstalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132397; -- Void Suppression Visual Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=65011; -- Albino Riding Crane
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=48632; -- Golden King
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=39208; -- Exarch's Elekk
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18406; -- Swift Blue Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62822; -- Cousin Slowhands
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=133422; -- Shadreen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126773; -- Locus-Walker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132616; -- Silvermoon Scholar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1860; -- Voidwalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132648; -- Veiled Riftblade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29929; -- Mechano-Hog
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=40725; -- X-53 Touring Rocket
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=26822 WHERE `entry`=18376; -- Swift Red Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=9158; -- Warhorse
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=305; -- White Stallion
UPDATE `creature_template` SET `family`=0, `type`=1, `VerifiedBuild`=26822 WHERE `entry`=307; -- Pinto
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132659; -- Veiled Riftblade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62821; -- Mystic Birdhat
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132676; -- Voidstalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132386; -- Rift Warden
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132657; -- Atynar
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132400; -- Curious Voidstalker
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132705; -- Danessa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=33030; -- Magnificent Flying Carpet
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=65078; -- Great Purple Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=32633; -- Traveler's Tundra Mammoth
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26822 WHERE `entry`=32206; -- Armored Brown Bear
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=31694; -- Azure Drake Mount
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=29582; -- Winged Steed of the Ebon Blade
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=28302; -- Acherus Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=14565; -- Charger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=304; -- Felsteed
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=62106; -- Great Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132382; -- Magister Umbric
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132730; -- Voidstorm Visual Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132407; -- Umbral Ranger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132671; -- High Elf Wayfarer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132970; -- Nascent Voidling
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132385; -- Locus Researcher
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=77178; -- Dread Raven
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=18362; -- Swift Purple Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=30542; -- Rivendare's Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=131345; -- Alleria Windrunner

DELETE FROM `gameobject_template` WHERE `entry` IN (280945 /*Mailbox*/, 280975 /*Sword*/, 280946 /*Command Table*/, 280794 /*Rift to Telogrus*/, 280960 /*Wooden Table*/, 280944 /*Mailbox*/, 280972 /*Workbench*/, 280971 /*Anvil*/, 268668 /*Stool*/, 280793 /*Rift to Fathom's Edge*/, 280963 /*Bed*/, 280968 /*Cloth Tent*/, 280964 /*Pillow*/, 280967 /*Rug*/, 279607 /*Rift to Stormwind*/, 280973 /*Workbench*/, 280959 /*Supply Crate Stack 02*/, 280969 /*Rug*/, 280958 /*Supply Crate Stack 01*/, 280800 /*Void Orb*/, 280974 /*Crystal*/, 280970 /*Rug*/, 280949 /*Cloth Tent*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(280945, 5, 44342, 'Mailbox', '', '', '', 0.35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Mailbox
(280975, 5, 4175, 'Sword', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Sword
(280946, 5, 34378, 'Command Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Command Table
(280794, 22, 42710, 'Rift to Telogrus', '', '', '', 0.25, 259377, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rift to Telogrus
(280960, 5, 15420, 'Wooden Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Wooden Table
(280944, 19, 6476, 'Mailbox', '', '', '', 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Mailbox
(280972, 5, 26249, 'Workbench', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Workbench
(280971, 8, 47377, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Anvil
(268668, 5, 11604, 'Stool', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Stool
(280793, 22, 42710, 'Rift to Fathom''s Edge', '', '', '', 0.25, 260866, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rift to Fathom's Edge
(280963, 5, 10561, 'Bed', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Bed
(280968, 5, 15325, 'Cloth Tent', '', '', '', 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Cloth Tent
(280964, 5, 23602, 'Pillow', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Pillow
(280967, 5, 8603, 'Rug', '', '', '', 0.45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rug
(279607, 22, 42710, 'Rift to Stormwind', '', '', '', 0.25, 258310, -1, 0, 1, 1, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rift to Stormwind
(280973, 5, 15597, 'Workbench', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Workbench
(280959, 5, 22545, 'Supply Crate Stack 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Supply Crate Stack 02
(280969, 5, 30875, 'Rug', '', '', '', 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rug
(280958, 5, 17621, 'Supply Crate Stack 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Supply Crate Stack 01
(280800, 5, 47248, 'Void Orb', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Void Orb
(280974, 5, 15947, 'Crystal', 'questinteract', '', '', 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Crystal
(280970, 5, 36368, 'Rug', '', '', '', 0.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Rug
(280949, 5, 15325, 'Cloth Tent', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822); -- Cloth Tent

UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=221625; -- Medical Supply Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=253044; -- Pillow

