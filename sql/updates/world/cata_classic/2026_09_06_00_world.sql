DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (219977,219985,218794,219976));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(219977, 1, 49393, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Clank Coppernozzle
(219985, 1, 71732, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Kazz Fizzledink
(218794, 1, 71739, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Blitz Skuzzweaver
(219976, 1, 5956, 0, 0, 0, 0, 0, 0, 0, 0, 60192); -- Clink Coppernozzle

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (433390 /*Miniature Crate*/, 433389 /*Miniature Flamingo*/, 433391 /*Miniature Parasol*/, 428217 /*Miniature Parasol*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(433390, 35, 0x0, 0, 0), -- Miniature Crate
(433389, 35, 0x0, 0, 0), -- Miniature Flamingo
(433391, 35, 0x0, 0, 0), -- Miniature Parasol
(428217, 35, 0x0, 0, 0); -- Miniature Parasol

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (120006, 120003);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(120006, 0.305999994277954101, 1.5, 0, 60192),
(120003, 0.305999994277954101, 1.5, 0, 60192);

UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000 WHERE `entry`=223475; -- [DND] Goblin Town-in-a-Box Bunny
UPDATE `creature_template` SET `faction`=35, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=218747; -- Elle Arcspark
UPDATE `creature_template` SET `faction`=35, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=219976; -- Clink Coppernozzle
UPDATE `creature_template` SET `faction`=35, `npcflag`=640, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=219980; -- Razik Chumpchanger
UPDATE `creature_template` SET `faction`=35, `npcflag`=268435456, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=218794; -- Blitz Skuzzweaver
UPDATE `creature_template` SET `faction`=35, `npcflag`=18014398509481984, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=219985; -- Kazz Fizzledink
UPDATE `creature_template` SET `faction`=35, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=219977; -- Clank Coppernozzle
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=219981; -- Moxie Woolpuller

UPDATE `creature_template` SET `ScriptName`= 'npc_goblin_town_in_a_box_vendor', `flags_extra`= `flags_extra` | 0x1000 WHERE `entry` IN (218747, 219976, 219980, 218794, 219985, 219977, 219981);
UPDATE `creature_template` SET `flags_extra`= 0x80 WHERE `entry`= 223475;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=223475 AND `DifficultyID`=0); -- 223475 [DND] Goblin Town-in-a-Box Bunny - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=218747 AND `DifficultyID`=0); -- 218747 (Elle Arcspark) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=219976 AND `DifficultyID`=0); -- 219976 (Clink Coppernozzle) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=219980 AND `DifficultyID`=0); -- 219980 (Razik Chumpchanger) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=218794 AND `DifficultyID`=0); -- 218794 (Blitz Skuzzweaver) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=219985 AND `DifficultyID`=0); -- 219985 (Kazz Fizzledink) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=219977 AND `DifficultyID`=0); -- 219977 (Clank Coppernozzle) - Sessile
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x100, `VerifiedBuild`=60192 WHERE (`Entry`=219981 AND `DifficultyID`=0); -- 219981 (Moxie Woolpuller) - Sessile

DELETE FROM `npc_vendor` WHERE `entry` IN (219981, 218747, 219977, 219976, 219980);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219981, 8, 39502, 0, 0, 1, 0, 0, 60192), -- Resilient Parchment
(219981, 7, 39501, 0, 0, 1, 0, 0, 60192), -- Heavy Parchment
(219981, 6, 10648, 0, 0, 1, 0, 0, 60192), -- Common Parchment
(219981, 5, 39354, 0, 0, 1, 0, 0, 60192), -- Light Parchment
(219981, 4, 6532, 0, 0, 1, 0, 0, 60192), -- Bright Baubles
(219981, 3, 3371, 0, 0, 1, 0, 0, 60192), -- Crystal Vial
(219981, 2, 38426, 0, 0, 1, 0, 0, 60192), -- Eternium Thread
(219981, 1, 14341, 0, 0, 1, 0, 0, 60192), -- Rune Thread
(218747, 12, 4364, 2, 0, 1, 0, 0, 60192), -- Coarse Blasting Powder
(218747, 11, 4357, 4, 0, 1, 0, 0, 60192), -- Rough Blasting Powder
(218747, 10, 10647, 0, 0, 1, 0, 0, 60192), -- Engineer's Ink
(218747, 9, 10648, 0, 0, 1, 0, 0, 60192), -- Common Parchment
(218747, 8, 3466, 0, 0, 1, 0, 0, 60192), -- Strong Flux
(218747, 7, 2880, 0, 0, 1, 0, 0, 60192), -- Weak Flux
(218747, 6, 39684, 0, 0, 1, 0, 0, 60192), -- Hair Trigger
(218747, 5, 40533, 0, 0, 1, 0, 0, 60192), -- Walnut Stock
(218747, 4, 4400, 0, 0, 1, 0, 0, 60192), -- Heavy Stock
(218747, 3, 4399, 0, 0, 1, 0, 0, 60192), -- Wooden Stock
(218747, 2, 2901, 0, 0, 1, 0, 0, 60192), -- Mining Pick
(218747, 1, 5956, 0, 0, 1, 0, 0, 60192), -- Blacksmith Hammer
(219977, 6, 25877, 0, 0, 1, 0, 0, 60192), -- Master's Throwing Dagger
(219977, 5, 30751, 0, 0, 1, 0, 0, 60192), -- Mag'hari Light Axe
(219977, 4, 30752, 0, 0, 1, 0, 0, 60192), -- Mag'hari Battleaxe
(219977, 3, 30750, 0, 0, 1, 0, 0, 60192), -- Draenic Warblade
(219977, 2, 30749, 0, 0, 1, 0, 0, 60192), -- Draenic Sparring Blade
(219977, 1, 30754, 0, 0, 1, 0, 0, 60192), -- Ancient Bone Mace
(219976, 6, 30784, 0, 0, 1, 0, 0, 60192), -- Worn Mag'hari Gauntlets
(219976, 5, 30781, 0, 0, 1, 0, 0, 60192), -- Mag'hari Chain Vest
(219976, 4, 30775, 0, 0, 1, 0, 0, 60192), -- Layered Bone Shield
(219976, 3, 30765, 0, 0, 1, 0, 0, 60192), -- Heavy Draenic Breastplate
(219976, 2, 30771, 0, 0, 1, 0, 0, 60192), -- Heavy Draenic Bracers
(219976, 1, 30777, 0, 0, 1, 0, 0, 60192), -- Aldor Heavy Belt
(219980, 5, 4470, 0, 0, 1, 0, 0, 60192), -- Simple Wood
(219980, 4, 60335, 0, 0, 1, 0, 0, 60192), -- Thick Hide Pack
(219980, 3, 58275, 0, 0, 1, 0, 0, 60192), -- Hardtack
(219980, 2, 58274, 0, 0, 1, 0, 0, 60192), -- Fresh Water
(219980, 1, 159, 0, 0, 1, 0, 0, 60192); -- Refreshing Spring Water

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_item_open_goblin_town_in_a_box',
'spell_item_open_goblin_town_in_a_box_forcecast',
'spell_gen_crazy_gadgets_calculations',
'spell_gen_overcharged_town');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(437831, 'spell_item_open_goblin_town_in_a_box'),
(440489, 'spell_item_open_goblin_town_in_a_box_forcecast'),
(440395, 'spell_gen_crazy_gadgets_calculations'),
(448366, 'spell_gen_overcharged_town');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE `entry`= 433079;
DELETE FROM `smart_scripts` WHERE `entryOrGuid`= 433079 AND `source_type`= 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(433079,1,0,0,'',60,0,100,0x100,2000,2000,0,0,0,'',128,29214,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,''),
(433079,1,1,0,'',60,0,100,0x100,3000,3000,0,0,0,'',41,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'');

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (32286, 33276) AND `IsCustom`= 0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreaTriggerCustom`, `Shape`, `ShapeData0`, `ShapeData1`, `ScriptName`) VALUES
(32286, 0, 1, 1, 0, 10, 10, 'areatrigger_goblin_town_in_a_box_1'),
(33276, 0, 2, 1, 0, 10, 10, 'areatrigger_goblin_town_in_a_box_2');

DELETE FROM `areatrigger_template` WHERE `Id` IN (1, 2) AND `IsCustom`= 1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetFlags`) VALUES
(1, 1, 0x1, 0x400),
(2, 1, 0x1, 0x400);
