SET @CGUID := 21010555;

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10003;

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5280 AND `AreaTriggerId`=10003);

DELETE FROM `gameobject_template_addon` WHERE `entry`=270855;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(270855, 0, 262176); -- Note anodine

UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=273292; -- Noyau de la matrice du Vindicaar
UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=148502; -- Test Object


DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 121014, 1220, 7502, 7505, 1, '0', 0, 0, 0, -853.7049, 4262.12, 746.3644, 0.7395566, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Balise sancteforge (Area: Aire de Krasus - Difficulty: 0)

DELETE FROM `spell_target_position` WHERE (`ID`=241271 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(241271, 0, 1669, 389.98, 1417.1, 769.6, 25996); -- Spell: Transport Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (122130 /*122130 (Grand redresseur de torts) - Bénédiction des rois*/, 114946 /*114946 (Muninn)*/, 121014 /*Balise sancteforge*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(122130, 0, 0, 0, 0, 0, 0, 0, 0, '79968'), -- 122130 (Grand redresseur de torts) - Bénédiction des rois
(114946, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114946 (Muninn)
(121014, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Balise sancteforge

UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1, `auras`='244972' WHERE `entry`=121516; -- 121516 (Mage de bataille sancteforge)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=125843; -- 125843 (Artificier de l'Exodar)
UPDATE `creature_template_addon` SET `auras`='237554' WHERE `entry`=126030; -- 126030 (Anachorète ligelumière)
UPDATE `creature_template_addon` SET `auras`='250286' WHERE `entry`=126057; -- 126057 (Exossature endommagée)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1, `auras`='244972' WHERE `entry`=121394; -- 121394 (Rempart sancteforge)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=126043; -- 126043 (Redresseur de torts blessé)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- Ban Lu

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (121261, 127120, 116308, 127151, 128244, 128245, 122130, 106263, 106262, 128241, 114946, 128242, 128243, 127518);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(121261, 0, 25996),
(127120, 0, 25996),
(116308, 0, 25996),
(127151, 0, 25996),
(128244, 0, 25996),
(128245, 0, 25996),
(122130, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(128241, 0, 25996),
(114946, 0, 25996),
(128242, 0, 25996),
(128243, 0, 25996),
(127518, 0, 25996);

UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78662;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16624;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=76272;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28222;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78381;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71285;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27824;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78386;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71288;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78663;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78609;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65834;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71286;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=80784;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71289;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=72361;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71637;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68890;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26770;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78434;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72364;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79263;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79814;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79447;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72353;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78432;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79241;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78433;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78660;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78521;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=75584;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71801;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77525;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79815;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79812;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77522;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78896;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71154;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=78664;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77524;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=79813;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77526;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77527;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=76422;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39810;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1669;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27955;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28162;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69154;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28282;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28111;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26394;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70927;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=59729;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=77656;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11686;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27823;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=122130 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(122130, 1, 112261, 0, 0, 138831, 0, 0, 0, 0, 0); -- Grand redresseur de torts

UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=121516 AND `ID`=1); -- Mage de bataille sancteforge
UPDATE `creature_equip_template` SET `ItemID1`=140555 WHERE (`CreatureID`=121394 AND `ID`=2); -- Rempart sancteforge
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=121394 AND `ID`=1); -- Rempart sancteforge


UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=128244; -- Dame Liadrin
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=128241; -- Silgryn
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=127120; -- Redresseuse de torts Jaelaana
UPDATE `creature_template` SET `VehicleId`=5393 WHERE `entry`=126057; -- Exossature endommagée
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=123395; -- Grande prêtresse Ishanah
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106528; -- Flower Pot
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2105, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33572864 WHERE `entry`=122130; -- Grand redresseur de torts
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=114946; -- Muninn
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=8796109799424, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=121014; -- Balise sancteforge

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 121014;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(121014, 241271, 3, 0);


UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121179; -- Vereesa Coursevent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=120845; -- Arator le Rédempteur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121230; -- Alleria Coursevent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127518; -- Adjudant Vortus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125521; -- Aeqinus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125520; -- Virtos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126022; -- Anachorète Lysara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125518; -- Jost
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125519; -- Divinius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121516; -- Mage de bataille sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128245; -- Archimage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127429; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127459; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125522; -- Santus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125517; -- Heradus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=129674; -- Maras
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125843; -- Artificier de l'Exodar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128243; -- Aethas Saccage-Soleil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125349; -- Enstraa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128244; -- Dame Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125351; -- Khaela
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126030; -- Anachorète ligelumière
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128241; -- Silgryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=120533; -- Prophète Velen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127476; -- Carte de reconnaissance
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125525; -- Duraël
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128242; -- Kal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125341; -- Khamir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125343; -- Vorel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125912; -- Adjuratrice du Kirin Tor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125911; -- Adjurateur du Kirin Tor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127120; -- Redresseuse de torts Jaelaana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127151; -- Toraan le Révéré
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=127163; -- Gardien krokul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126042; -- Artificier sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121464; -- Pilote sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126057; -- Exossature endommagée
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121394; -- Rempart sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121261; -- Lothraxion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125524; -- Anachorète ligelumière
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126043; -- Redresseur de torts blessé
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126389; -- Artificière Shela'na
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123395; -- Grande prêtresse Ishanah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123671; -- Maître-lame Telaamon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123668; -- Capitaine Fareeya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123669; -- Grand redresseur de torts Sorvos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123413; -- Archimage Y'mera
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114590; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123670; -- Baraat le Long-Tireur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125523; -- Redresseur de torts de l'Exodar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=122219; -- Volcan d'Argus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=126425; -- Noyau de la matrice du Vindicaar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=78217; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121589; -- Thaumaturge Vashreen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=125270; -- Crédit de quête - Retourner au Vindicaar
UPDATE `creature_template` SET `modelid1`=74779, `modelid2`=74782, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=118524; -- Dalaran Crystal
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=43359; -- ELM General Purpose Bunny Infinite Hide Body
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111246; -- Archmage Timear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106528; -- Flower Pot
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96804; -- Hamaka
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113780; -- Innocent Jim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96830; -- Linda Ann Kastinglow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96829; -- Arcanist Alec
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96805; -- Mato
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108853; -- Great Eagle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106263; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32638; -- Hakmud of Argus
UPDATE `creature_template` SET `HealthModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=50815; -- Skarr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32639; -- Gnimo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106262; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93537; -- Misensi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93536; -- Awilo Lon'gomba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=65011; -- Albino Riding Crane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=305; -- Etalon blanc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32335; -- Griffon neigeux cuirassé
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18362; -- Swift Purple Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18406; -- Swift Blue Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=304; -- Palefroi corrompu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=14505; -- Destrier de l'effroi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114946; -- Muninn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template` SET `movementId`=961, `VerifiedBuild`=25996 WHERE `entry`=100324; -- Hati
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type_flags2`=16384, `VerifiedBuild`=25996 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=50058; -- Terrorpene
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101436; -- Wormhole
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=54638; -- Generic Bunny
UPDATE `creature_template` SET `modelid1`=74087, `HealthScalingExpansion`=6, `type`=7, `type_flags`=134217728, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=116308; -- Karam Magespear
UPDATE `creature_template` SET `modelid1`=70927, `HealthScalingExpansion`=6, `type`=7, `type_flags`=2363464, `ManaModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=122130; -- Grand redresseur de torts
UPDATE `creature_template` SET `modelid1`=77656, `IconName`='argusteleporter', `HealthScalingExpansion`=6, `rank`=1, `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=121014; -- Balise sancteforge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=40295; -- Rob-fusée mécanique bleu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97205; -- Dragonnet né-des-tempêtes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112144; -- Corgnelius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112132; -- Jeune chauve-souris de feu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99394; -- Ondulin fétide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106152; -- Bébé noble-bois
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=71033; -- Diablotin diabolique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=71015; -- Gardien de ménagerie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111423; -- Wyrmelin détaché
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35399; -- Jeune raptor d'obsidienne
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97238; -- Araignée nourrice
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113136; -- Bénax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99403; -- Jeune sabre fantomatique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98116; -- Méduse aiguemorne
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97207; -- Emmigosa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108568; -- Chouette pygmée
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90205; -- Fragment de désir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=34364; -- Chat calico
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7561; -- Serpent albinos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=7382; -- Chat tigré roux


UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273005; -- Console sancteforge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273784; -- Portail vers Dalaran
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273681; -- Caisse
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273682; -- Caisse
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273350; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273401; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273402; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273351; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=272417; -- Jugement de la Lumière
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273349; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273400; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273352; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273403; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `castBarCaption`='Activation', `VerifiedBuild`=25996 WHERE `entry`=273292; -- Noyau de la matrice du Vindicaar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273354; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273405; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273348; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273399; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273353; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273404; -- Jugement de la Lumière activé - Jaune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273498; -- Enclume
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273497; -- Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273841; -- Piédestal de la couronne
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273317; -- Boîte aux lettres
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=272812; -- Bannière
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273455; -- Enclume
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=276296; -- Creuset de Halo-du-Néant
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273272; -- Creuset de Halo-du-Néant
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273850; -- Ombre
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273849; -- Lumière
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=272208; -- Le Vindicaar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=273764; -- Portail menant au Vindicaar
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=224813; -- Garrison Building Alliance Pet Stable V1
UPDATE `gameobject_template` SET `type`=48, `displayId`=31867, `size`=1.066213, `Data0`=1, `Data1`=1, `Data2`=1, `Data3`=1902, `Data4`=15, `VerifiedBuild`=25996 WHERE `entry`=246944; -- Obliterum Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251579; -- Illidari Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251286; -- Illidari Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=244560; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=244561; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=245249; -- Banner
UPDATE `gameobject_template` SET `type`=10, `displayId`=26705, `castBarCaption`='Reading…', `size`=0.5, `Data0`=43, `Data3`=1, `Data6`=1, `Data7`=7154, `Data9`=1, `Data10`=231933, `Data13`=1, `Data14`=24589, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=148502; -- Test Object
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template` SET `type`=10, `displayId`=43358, `IconName`='questinteract', `castBarCaption`='Reading…', `size`=0.5, `Data0`=93, `Data3`=3000, `Data6`=1, `Data7`=7264, `Data9`=1, `Data10`=247027, `Data13`=1, `Data14`=24589, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=270855; -- Note anodine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252245; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242174; -- Violet Hold Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250333; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250337; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250334; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250328; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250336; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250338; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250329; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187575; -- Hanging, Square, Small - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250332; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250339; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250340; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250331; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259281; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181018; -- Hanging, Tall/Thin, Medium - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=187668; -- Hanging, Tall/Thin, Small - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259282; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242172; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181016; -- Standing, Exterior, Medium - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259283; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259835; -- Fireplace
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251312; -- Shaman Stones
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251311; -- Portal to the Maelstrom

