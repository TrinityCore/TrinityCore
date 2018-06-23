DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278730 /*Netherlight Crucible*/, 272190 /*Navigation Console*/, 251228 /*Draenei Pillow 3*/, 278732 /*Portal to Stormwind*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(278730, 0, 8192), -- Netherlight Crucible
(272190, 0, 8192), -- Navigation Console
(251228, 0, 32), -- Draenei Pillow 3
(278732, 0, 32); -- Portal to Stormwind


DELETE FROM `scene_template` WHERE (`SceneId`=1902 AND `ScriptPackageID`=2005);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1902, 9, 2005);

DELETE FROM `creature_template_addon` WHERE `entry` IN (132358 /*132358 (Enstraa)*/, 130986 /*130986 (Vigilant Quoram)*/, 132224 /*132224 (Durael)*/, 130560 /*130560 (Maras)*/, 132325 /*132325 (Jarus)*/, 132334 /*132334 (Grand Artificer Romuul)*/, 132323 /*132323 (Yalia)*/, 132328 /*132328 (Lightforged Bulwark)*/, 132215 /*132215 (Lightforged Vindicator)*/, 130993 /*130993 (Captain Fareeya)*/, 132225 /*132225 (Lightforged Artificer)*/, 132262 /*132262 (Lightforged Protector) - Blessing of Kings*/, 132214 /*132214 (Lightforged Anchorite)*/, 132266 /*132266 (Lightforged Protector) - Blessing of Kings*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(132358, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132358 (Enstraa)
(130986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 130986 (Vigilant Quoram)
(132224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132224 (Durael)
(130560, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 130560 (Maras)
(132325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132325 (Jarus)
(132334, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132334 (Grand Artificer Romuul)
(132323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132323 (Yalia)
(132328, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132328 (Lightforged Bulwark)
(132215, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132215 (Lightforged Vindicator)
(130993, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 130993 (Captain Fareeya)
(132225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132225 (Lightforged Artificer)
(132262, 0, 0, 0, 1, 0, 0, 0, 0, '79968'), -- 132262 (Lightforged Protector) - Blessing of Kings
(132214, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132214 (Lightforged Anchorite)
(132266, 0, 0, 0, 1, 0, 0, 0, 0, '79968'); -- 132266 (Lightforged Protector) - Blessing of Kings

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=114590; -- 114590 (Generic Bunny)
UPDATE `creature_template_addon` SET `auras`='250840' WHERE `entry`=126390; -- 126390 (Thelbus Wimblenod)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (132358, 130986, 132224, 130560, 132325, 132334, 132323, 132328, 132215, 130993, 132225, 132262, 132214, 132266);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(132358, 110, 110, 0, 0, 26822),
(130986, 110, 110, 0, 0, 26822),
(132224, 110, 110, 0, 0, 26822),
(130560, 110, 110, 0, 0, 26822),
(132325, 110, 110, 0, 0, 26822),
(132334, 110, 110, 0, 0, 26822),
(132323, 110, 110, 0, 0, 26822),
(132328, 110, 110, 0, 0, 26822),
(132215, 110, 110, 0, 0, 26822),
(130993, 110, 110, 0, 0, 26822),
(132225, 110, 110, 0, 0, 26822),
(132262, 110, 110, 0, 0, 26822),
(132214, 110, 110, 0, 0, 26822),
(132266, 110, 110, 0, 0, 26822);



UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78659;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78434;
UPDATE `creature_model_info` SET `BoundingRadius`=1.757107, `CombatReach`=4.5, `VerifiedBuild`=26822 WHERE `DisplayID`=79929;
UPDATE `creature_model_info` SET `BoundingRadius`=1.1, `CombatReach`=1.65, `VerifiedBuild`=26822 WHERE `DisplayID`=82307;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=80784;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=17882;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78677;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78896;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82302;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=83125;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=27823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=76255;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=60739;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9, `CombatReach`=1.35, `VerifiedBuild`=26822 WHERE `DisplayID`=82309;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78910;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82324;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78387;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78607;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82303;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=71154;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82301;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=78378;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82321;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82300;
UPDATE `creature_model_info` SET `VerifiedBuild`=26822 WHERE `DisplayID`=77524;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9, `CombatReach`=1.35, `VerifiedBuild`=26822 WHERE `DisplayID`=82308;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82322;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82297;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=26822 WHERE `DisplayID`=82323;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=132358 AND `ID`=1) OR (`CreatureID`=130986 AND `ID`=1) OR (`CreatureID`=132334 AND `ID`=1) OR (`CreatureID`=132328 AND `ID`=1) OR (`CreatureID`=132215 AND `ID`=1) OR (`CreatureID`=130993 AND `ID`=1) OR (`CreatureID`=132225 AND `ID`=1) OR (`CreatureID`=132262 AND `ID`=1) OR (`CreatureID`=132214 AND `ID`=1) OR (`CreatureID`=132266 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(132358, 1, 12260, 0, 0, 0, 0, 0, 0, 0, 0), -- Enstraa
(130986, 1, 153354, 0, 0, 153353, 0, 0, 0, 0, 0), -- Vigilant Quoram
(132334, 1, 126431, 0, 0, 45617, 0, 0, 0, 0, 0), -- Grand Artificer Romuul
(132328, 1, 140555, 0, 0, 138831, 0, 0, 0, 0, 0), -- Lightforged Bulwark
(132215, 1, 94667, 0, 0, 110156, 0, 0, 0, 0, 0), -- Lightforged Vindicator
(130993, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0), -- Captain Fareeya
(132225, 1, 28487, 0, 0, 29637, 0, 0, 0, 0, 0), -- Lightforged Artificer
(132262, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0), -- Lightforged Protector
(132214, 1, 122076, 0, 0, 0, 0, 0, 0, 0, 0), -- Lightforged Anchorite
(132266, 1, 141994, 0, 0, 0, 0, 0, 0, 0, 0); -- Lightforged Protector



UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132358; -- Enstraa
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=3 WHERE `entry`=130986; -- Vigilant Quoram
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=4227, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132224; -- Durael
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130560; -- Maras
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=123395; -- High Priestess Ishanah
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132325; -- Jarus
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132334; -- Grand Artificer Romuul
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132323; -- Yalia
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132328; -- Lightforged Bulwark
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=132215; -- Lightforged Vindicator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1665, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=130993; -- Captain Fareeya
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132225; -- Lightforged Artificer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2860, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132262; -- Lightforged Protector
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132214; -- Lightforged Anchorite
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2860, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=132266; -- Lightforged Protector


UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=130986; -- Vigilant Quoram
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126075; -- A'naa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126389; -- Artificer Shela'na
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132215; -- Lightforged Vindicator
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=1960; -- Pilot Hammerfoot
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132224; -- Durael
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132358; -- Enstraa
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=114590; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=123395; -- High Priestess Ishanah
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132325; -- Jarus
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132262; -- Lightforged Protector
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126022; -- Anchorite Lysara
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132334; -- Grand Artificer Romuul
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=130560; -- Maras
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132328; -- Lightforged Bulwark
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=125524; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132266; -- Lightforged Protector
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132225; -- Lightforged Artificer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126030; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132323; -- Yalia
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=126390; -- Thelbus Wimblenod
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=125843; -- Exodar Artificer
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=132214; -- Lightforged Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=26822 WHERE `entry`=130993; -- Captain Fareeya

DELETE FROM `gameobject_template` WHERE `entry` IN (273288 /*Anvil*/, 246170 /*Chair Low*/, 278732 /*Portal to Stormwind*/, 278729 /*Vindicaar Matrix Core*/, 273496 /*Mailbox*/, 273287 /*Forge*/, 273289 /*Anvil*/, 272190 /*Navigation Console*/, 280498 /*Forge of Light*/, 278730 /*Netherlight Crucible*/, 251228 /*Draenei Pillow 3*/, 278728 /*Crown Pedestal*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(273288, 8, 44015, 'Anvil', '', '', '', 0.9999999, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Anvil
(246170, 5, 30889, 'Chair Low', '', '', '', 1.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Chair Low
(278732, 22, 47526, 'Portal to Stormwind', '', '', '', 1.5, 258310, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Portal to Stormwind
(278729, 5, 43982, 'Vindicaar Matrix Core', '', '', '', 1.55148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Vindicaar Matrix Core
(273496, 19, 44066, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Mailbox
(273287, 8, 44014, 'Forge', '', '', '', 0.9999999, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Forge
(273289, 8, 44015, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Anvil
(272190, 5, 43348, 'Navigation Console', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Navigation Console
(280498, 8, 47673, 'Forge of Light', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Forge of Light
(278730, 5, 44671, 'Netherlight Crucible', '', '', '', 1.15, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Netherlight Crucible
(251228, 5, 23603, 'Draenei Pillow 3', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822), -- Draenei Pillow 3
(278728, 5, 43983, 'Crown Pedestal', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26822); -- Crown Pedestal

UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=273684; -- Magical Boots
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=273681; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=202862; -- Tiny Blue Ragdoll
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=233662; -- Small Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=273683; -- Magical Hat
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=273682; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26822 WHERE `entry`=276296; -- Netherlight Crucible

