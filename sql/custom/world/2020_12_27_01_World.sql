DELETE FROM `gossip_menu_option` WHERE MenuId IN(22081,22082);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(22081, 0, 0, 'What can you tell me about the Lightforged draenei?', 0),
(22082, 0, 0, 'What do we know about the void elves?', 0);



DELETE FROM `gossip_menu` WHERE (`MenuId`=22202 AND `TextId`=34012) OR (`MenuId`=22081 AND `TextId`=34010) OR (`MenuId`=22082 AND `TextId`=34006) OR (`MenuId`=22201 AND `TextId`=34011) OR (`MenuId`=22203 AND `TextId`=34013) OR (`MenuId`=22198 AND `TextId`=34007) OR (`MenuId`=22199 AND `TextId`=34008) OR (`MenuId`=22200 AND `TextId`=34009);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22202, 34012), -- 126323
(22081, 34010), -- 126319
(22082, 34006), -- 126321
(22201, 34011), -- 133197
(22203, 34013), -- 126328
(22198, 34007), -- 126332
(22199, 34008), -- 126326
(22200, 34009); -- 126324

UPDATE `creature_template` SET `gossip_menu_id` = 22202 WHERE `entry` = 126323;
UPDATE `creature_template` SET `gossip_menu_id` = 22081 WHERE `entry` = 126319;
UPDATE `creature_template` SET `gossip_menu_id` = 22082 WHERE `entry` = 126321;
UPDATE `creature_template` SET `gossip_menu_id` = 22201 WHERE `entry` = 133197;
UPDATE `creature_template` SET `gossip_menu_id` = 22203 WHERE `entry` = 126328;
UPDATE `creature_template` SET `gossip_menu_id` = 22198 WHERE `entry` = 126332;
UPDATE `creature_template` SET `gossip_menu_id` = 22199 WHERE `entry` = 126326;
UPDATE `creature_template` SET `gossip_menu_id` = 22200 WHERE `entry` = 126324;

DELETE FROM `npc_text` WHERE ID IN (34011, 34013, 34007, 34008, 34006, 34010, 34009, 34012);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(34011, 1, 0, 0, 0, 0, 0, 0, 0, 147222, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34011
(34013, 1, 0, 0, 0, 0, 0, 0, 0, 147231, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34013
(34007, 1, 0, 0, 0, 0, 0, 0, 0, 147229, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34007
(34008, 1, 0, 0, 0, 0, 0, 0, 0, 147228, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34008
(34006, 1, 0, 0, 0, 0, 0, 0, 0, 147223, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34006
(34010, 1, 0, 0, 0, 0, 0, 0, 0, 147224, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34010
(34009, 1, 0, 0, 0, 0, 0, 0, 0, 147226, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34009
(34012, 1, 0, 0, 0, 0, 0, 0, 0, 147233, 0, 0, 0, 0, 0, 0, 0, 26972); -- 34012

DELETE FROM `gameobject_template` WHERE entry IN (273855, 273853, 278328, 278326, 278331, 278329, 278330, 278327, 278333, 278332, 278325, 278324);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `AIName`, `ScriptName`, `VerifiedBuild`)VALUES
(273855, 22, 47677, 'Lightforged Draenei', 'inspect', '', '', 0.85, 257990, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 273855
(273853, 22, 47680, 'Void Elf', 'inspect', '', '', 1.3, 257989, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 273853
(278328, 5, 15617, 'Chair', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278328
(278326, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278326
(278331, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278331
(278329, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278329
(278330, 7, 15419, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278330
(278327, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278327
(278333, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278333
(278332, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278332
(278325, 7, 15617, 'Chair', '', '', '', 0.9999999, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972), -- 278325
(278324, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 26972); -- 278324

-- forgot to make him have gossip --
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126323;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126319;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126321;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 133197;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126328;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126332;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126324;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 126326;



 -- Vehicle fix -- 

DELETE FROM `vehicle_template_accessory` WHERE entry = 126326;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(126326, 116312, 0, 0, 'gelbin in his suit', 6, 30000);

UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `VehicleId` = 5547, `type` = 7, `faction` = 1733 WHERE `entry` = 126326;
UPDATE `creature_template` SET `minlevel` = 98, `maxlevel` = 110, `VehicleId` = 5078, `type` = 7, `faction` = 1733 WHERE `entry` = 116312;


DELETE FROM `creature_template` WHERE entry IN (133433, 133441, 133509, 133672, 133396, 133363, 133431, 133411, 112698, 129679, 133332, 133326);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(133433, 0, 0, 83231, 83232, 82918, 82919, 'Ghostblade Scout', NULL, NULL, NULL, NULL, -1, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133433  ONE
(133441, 0, 0, 82925, 82928, 83233, 83234, 'Trained Brightlance', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 4096, 0, 1, 1, 0, 0, 26972), -- 133441 ONE
(133509, 0, 0, 82973, 83108, 83235, 83236, 'Riftwarden Acolyte', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133509 ONE
(133672, 0, 0, 15813, 47034, 58463, 37884, 'Master Arcanist', NULL, NULL, NULL, NULL, 5, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133672  NEED TWO OF THESE
(133396, 0, 0, 82895, 0, 0, 0, 'Jandros Terres', NULL, 'First Aid Trainer', NULL, NULL, 6, 0, 0, 0, 0, 7, 134217728, 0, 1, 1, 0, 0, 26972), -- 133396 ONE
(133363, 0, 0, 82875, 0, 0, 0, 'Aevedos', NULL, 'Tailoring Trainer', NULL, NULL, -1, 0, 0, 0, 0, 7, 134217728, 0, 1, 1, 0, 0, 26972), -- 133363 ONE
(133431, 0, 0, 80978, 82914, 83229, 83230, 'Lightforged Sunshield', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 10, 0, 0, 26972), -- 133431 ONE
(133411, 0, 0, 82899, 0, 0, 0, 'Dalia Skyblossom', NULL, 'Cooking Trainer', NULL, NULL, 0, 0, 0, 0, 0, 7, 134217728, 0, 1.05, 1, 0, 0, 26972), -- 133411 ONE
(112698, 0, 0, 63716, 72180, 72181, 72183, 'Cat', NULL, NULL, NULL, 'openhandglow', 0, 0, 0, 0, 52, 1, 0, 0, 1, 1, 0, 0, 26972), -- 112698 ONE
(129679, 0, 0, 82867, 0, 0, 0, 'Shani Ward', NULL, 'Innkeeper', NULL, NULL, -1, 0, 0, 0, 0, 7, 134217728, 0, 5, 1, 0, 0, 26972), -- 129679
(133332, 0, 0, 82854, 0, 0, 0, 'Statiks Quikfuse', NULL, 'Engineering Supplies', NULL, NULL, 0, 0, 0, 0, 0, 7, 134217728, 0, 1.05, 1, 0, 0, 26972), -- 133332
(133326, 0, 0, 82847, 0, 0, 0, 'Artificer Farud', NULL, 'Engineering Trainer', NULL, NULL, 6, 0, 0, 0, 0, 7, 134217728, 0, 1, 10, 0, 0, 26972); -- 133326

DELETE FROM `npc_vendor` WHERE (`entry`=133332 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4361 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=68660 AND `ExtendedCost`=6003 AND `type`=1) OR (`entry`=133332 AND `item`=59489 AND `ExtendedCost`=3310 AND `type`=1) OR (`entry`=133332 AND `item`=59477 AND `ExtendedCost`=3392 AND `type`=1) OR (`entry`=133332 AND `item`=59478 AND `ExtendedCost`=3311 AND `type`=1) OR (`entry`=133332 AND `item`=59479 AND `ExtendedCost`=3311 AND `type`=1) OR (`entry`=133332 AND `item`=59480 AND `ExtendedCost`=3308 AND `type`=1) OR (`entry`=133332 AND `item`=59491 AND `ExtendedCost`=3305 AND `type`=1) OR (`entry`=133332 AND `item`=59493 AND `ExtendedCost`=3307 AND `type`=1) OR (`entry`=133332 AND `item`=59496 AND `ExtendedCost`=3306 AND `type`=1) OR (`entry`=133411 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(133332, 165, 39354, 0, 0, 1, 0, 0, 26972), -- 39354
(133332, 164, 4364, 3, 0, 1, 0, 0, 26972), -- 4364
(133332, 163, 4357, 4, 0, 1, 0, 0, 26972), -- 4357
(133332, 162, 4371, 1, 0, 1, 0, 0, 26972), -- 4371
(133332, 161, 4361, 2, 0, 1, 0, 0, 26972), -- 4361
(133332, 160, 4404, 1, 0, 1, 0, 0, 26972), -- 4404
(133332, 159, 10647, 0, 0, 1, 0, 0, 26972), -- 10647
(133332, 158, 3466, 0, 0, 1, 0, 0, 26972), -- 3466
(133332, 157, 2880, 0, 0, 1, 0, 0, 26972), -- 2880
(133332, 156, 39684, 0, 0, 1, 0, 0, 26972), -- 39684
(133332, 155, 40533, 0, 0, 1, 0, 0, 26972), -- 40533
(133332, 154, 4400, 0, 0, 1, 0, 0, 26972), -- 4400
(133332, 153, 4399, 0, 0, 1, 0, 0, 26972), -- 4399
(133332, 152, 90146, 0, 0, 1, 0, 0, 26972), -- 90146
(133332, 151, 2901, 0, 0, 1, 0, 0, 26972), -- 2901
(133332, 150, 5956, 0, 0, 1, 0, 0, 26972), -- 5956
(133332, 22, 68660, 0, 6003, 1, 0, 0, 26972), -- 68660
(133332, 21, 59489, 0, 3310, 1, 0, 0, 26972), -- 59489
(133332, 20, 59477, 0, 3392, 1, 0, 0, 26972), -- 59477
(133332, 19, 59478, 0, 3311, 1, 0, 0, 26972), -- 59478
(133332, 18, 59479, 0, 3311, 1, 0, 0, 26972), -- 59479
(133332, 17, 59480, 0, 3308, 1, 0, 0, 26972), -- 59480
(133332, 16, 59491, 0, 3305, 1, 0, 0, 26972), -- 59491
(133332, 15, 59493, 0, 3307, 1, 0, 0, 26972), -- 59493
(133332, 14, 59496, 0, 3306, 1, 0, 0, 26972), -- 59496
(133411, 5, 21219, 0, 0, 1, 0, 0, 26972), -- 21219
(133411, 4, 21099, 0, 0, 1, 0, 0, 26972), -- 21099
(133411, 3, 2678, 0, 0, 1, 0, 0, 26972), -- 2678
(133411, 2, 30817, 0, 0, 1, 0, 0, 26972), -- 30817
(133411, 1, 159, 0, 0, 1, 0, 0, 26972); -- 159

DELETE FROM `gossip_menu` WHERE (`MenuId`=22176 AND `TextId`=33978) OR (`MenuId`=22177 AND `TextId`=33979) OR (`MenuId`=22173 AND `TextId`=33975) OR (`MenuId`=22172 AND `TextId`=33974) OR (`MenuId`=341 AND `TextId`=820) OR (`MenuId`=22124 AND `TextId`=18046) OR (`MenuId`=22171 AND `TextId`=33973) OR (`MenuId`=22169 AND `TextId`=33971);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22176, 33978), -- 133322
(22177, 33979), -- 133369
(22173, 33975), -- 133326
(22172, 33974), -- 133332
(341, 820), -- 129679
(22124, 18046), -- 133411
(22171, 33973), -- 133363
(22169, 33971); -- 133396

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22176 AND `OptionIndex`=0) OR (`MenuId`=22177 AND `OptionIndex`=0) OR (`MenuId`=22173 AND `OptionIndex`=0) OR (`MenuId`=22172 AND `OptionIndex`=0) OR (`MenuId`=341 AND `OptionIndex`=0) OR (`MenuId`=22124 AND `OptionIndex`=1) OR (`MenuId`=22124 AND `OptionIndex`=0) OR (`MenuId`=22171 AND `OptionIndex`=0) OR (`MenuId`=22169 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(22176, 0, 3, 'I want to become a blacksmith.', 0),
(22177, 0, 3, 'Tell me about Mining.', 0),
(22173, 0, 3, 'Train me in Engineering.', 0),
(22172, 0, 1, 'Let me browse your goods.', 0),
(341, 0, 5, 'Make this inn your home.', 0),
(22124, 1, 1, 'Let me browse your goods.', 0),
(22124, 0, 3, 'I''m here for cooking training.', 0),
(22171, 0, 3, 'Train me in Tailoring.', 0),
(22169, 0, 3, 'Train me in First Aid.', 0);



DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=22176 AND `OptionIndex`=0) OR (`MenuId`=22177 AND `OptionIndex`=0) OR (`MenuId`=22173 AND `OptionIndex`=0) OR (`MenuId`=22124 AND `OptionIndex`=0) OR (`MenuId`=22171 AND `OptionIndex`=0) OR (`MenuId`=22169 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(22176, 0, 27),
(22177, 0, 91),
(22173, 0, 407),
(22124, 0, 136),
(22171, 0, 163),
(22169, 0, 160);

DELETE FROM `npc_text` WHERE `ID` IN (33978 /*33978*/, 33979 /*33979*/, 33975 /*33975*/, 33974 /*33974*/, 820 /*820*/, 18046 /*18046*/, 33973 /*33973*/, 33971 /*33971*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33978, 1, 0, 0, 0, 0, 0, 0, 0, 147196, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33978
(33979, 1, 0, 0, 0, 0, 0, 0, 0, 147197, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33979
(33975, 1, 0, 0, 0, 0, 0, 0, 0, 147191, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33975
(33974, 1, 0, 0, 0, 0, 0, 0, 0, 147188, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33974
(820, 100, 0, 0, 0, 0, 0, 0, 0, 2821, 0, 0, 0, 0, 0, 0, 0, 26972), -- 820
(18046, 1, 0, 0, 0, 0, 0, 0, 0, 51896, 0, 0, 0, 0, 0, 0, 0, 26972), -- 18046
(33973, 1, 0, 0, 0, 0, 0, 0, 0, 147187, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33973
(33971, 1, 0, 0, 0, 0, 0, 0, 0, 147183, 0, 0, 0, 0, 0, 0, 0, 26972); -- 33971

UPDATE `creature_template` SET `gossip_menu_id` = 22124 WHERE `entry` = 133411;
UPDATE `gossip_menu_option` SET `OptionType` = 3, `OptionNpcFlag` = 209 WHERE `MenuId` = 22124 AND `OptionIndex` = 1;
UPDATE `gossip_menu_option` SET `OptionType` = 5, `OptionNpcFlag` = 209 WHERE `MenuId` = 22124 AND `OptionIndex` = 0;

UPDATE `creature_template` SET `gossip_menu_id` = 22169 WHERE `entry` = 133396;
UPDATE `gossip_menu_option` SET `OptionType` = 5, `OptionNpcFlag` = 81 WHERE `MenuId` = 22169 AND `OptionIndex` = 0;

UPDATE `creature_template` SET `gossip_menu_id` = 22171 WHERE `entry` = 133363;
UPDATE `gossip_menu_option` SET `OptionType` = 5, `OptionNpcFlag` = 81 WHERE `MenuId` = 22171 AND `OptionIndex` = 0;

UPDATE `creature_template` SET `gossip_menu_id` = 341 WHERE `entry` = 129679;
UPDATE `gossip_menu_option` SET `OptionType` = 8, `OptionNpcFlag` = 65537 WHERE `MenuId` = 341 AND `OptionIndex` = 0;

UPDATE `creature_template` SET `gossip_menu_id` = 22173 WHERE `entry` = 133326;
UPDATE `gossip_menu_option` SET `OptionType` = 5, `OptionNpcFlag` = 81 WHERE `MenuId` = 22173 AND `OptionIndex` = 0;



-- GAME OBJECT_TEMPLATE
DELETE FROM `gameobject_template` WHERE `entry` IN (278311, 281204, 281205);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(278311, 8, 23396, 'Bonfire', '', '', '', 1, 4, 10, 215916, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(281204, 5, 14839, 'Cooking Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 281204
(281205, 5, 7409, 'Simmering Stew', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 281205



-- REMOVE unused smart_script
DELETE FROM `smart_scripts` WHERE `entryorguid` = 130758;

-- remove the smartai ainame from 130758 correct the npcflag

UPDATE `creature_template` SET `AIName` = "", `npcflag` = 16777216 WHERE `entry` = 130758;

-- destination for the spell
DELETE  FROM `spell_target_position` WHERE ID = 258297;
INSERT INTO `spell_target_position` (`ID`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`)VALUES
(258297, 1860, 459.089, 1450.14, 758.018, 27326);

-- add spell to npcspellclick

DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 130758;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`)VALUES
(130758, 258298, 1, 1);