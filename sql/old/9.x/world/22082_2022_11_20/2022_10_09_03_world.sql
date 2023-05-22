UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=7230; -- Shayis Steelfury
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=7231; -- Kelgruk Bloodaxe
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=18 WHERE `entry`=11177; -- Okothos Ironrager
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=11178; -- Borgosh Corebender
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=20124; -- Kradu Grimblade
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=20125; -- Zula Slagfury
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=16 WHERE `entry`=1215; -- Alchemist Mallory
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3603; -- Cyndra Kindwhisper

DELETE FROM `creature_trainer` WHERE (`CreatureID`=2399 AND `MenuID`=4356 AND `OptionID`=0) OR (`CreatureID`=3557 AND `MenuID`=2749 AND `OptionID`=0) OR (`CreatureID`=17637 AND `MenuID`=7513 AND `OptionID`=0) OR (`CreatureID`=11074 AND `MenuID`=4170 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(2399, 163, 4356, 0),
(3557, 27, 2749, 0),
(17637, 870, 7513, 0),
(11074, 62, 4170, 0);

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (4356,2749,4170,7513));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(4356, 0, 3, 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 45745),
(2749, 0, 3, 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 45745),
(4170, 0, 3, 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 45745),
(7513, 0, 3, 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=3290 AND `MenuID`=4136 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(3290, 407, 4136, 0);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=4136 AND `OptionID`=0) OR (`MenuID`=22946 AND `OptionID` IN (3,2));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(4136, 0, 3, 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 45745),
(22946, 3, 0, 'What happened here?', 38328, 1, 0, 0, 0, 0, 0, NULL, 0, 45745),
(22946, 2, 0, 'Can you show me what Darkshore was like before the battle?', 169023, 1, 0, 0, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `gameobject_template` WHERE `entry` IN (376257,364439,364438,351981);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(376257, 10, 9510, 'Orb of Translocation', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 23504, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Orb of Translocation
(364439, 7, 17820, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(364438, 7, 17820, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Chair
(351981, 7, 32512, 'Chair', '', '', '', 0.999998748302459716, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Chair

UPDATE `gameobject_template` SET `ContentTuningId`=11, `VerifiedBuild`=45745 WHERE `entry`=207183; -- Humbert's Pants
UPDATE `gameobject_template` SET `ContentTuningId`=11, `VerifiedBuild`=45745 WHERE `entry`=207182; -- Humbert's Sword
UPDATE `gameobject_template` SET `ContentTuningId`=11, `VerifiedBuild`=45745 WHERE `entry`=207184; -- Humbert's Helm
UPDATE `gameobject_template` SET `ContentTuningId`=865, `VerifiedBuild`=45745 WHERE `entry`=24776; -- Yuriv's Tombstone
UPDATE `gameobject_template` SET `ContentTuningId`=7, `VerifiedBuild`=45745 WHERE `entry`=205165; -- Sea Dog Crate
UPDATE `gameobject_template` SET `ContentTuningId`=7, `VerifiedBuild`=45745 WHERE `entry`=194341; -- Dusty Journal
UPDATE `gameobject_template` SET `ContentTuningId`=7, `VerifiedBuild`=45745 WHERE `entry`=205350; -- Horde Communication Panel
UPDATE `gameobject_template` SET `ContentTuningId`=7, `VerifiedBuild`=45745 WHERE `entry` IN (288257, 205143); -- Abandoned Outhouse
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=32109, `ContentTuningId`=7, `VerifiedBuild`=45745 WHERE `entry`=205099; -- Ferocious Doomweed
UPDATE `gameobject_template` SET `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182165; -- Wanted Poster
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18761, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182095; -- Burstcap Mushroom
UPDATE `gameobject_template` SET `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=184578; -- Discarded Nutriment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18676, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182256; -- Discarded Nutriment
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18694, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182053; -- Glowcap
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39340, `ContentTuningId`=37, `VerifiedBuild`=45745 WHERE `entry`=207478; -- Silverbound Treasure Chest
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182529; -- Zangarmarsh Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=20890, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=184740; -- Wicker Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=18760, `ContentTuningId`=38, `VerifiedBuild`=45745 WHERE `entry`=182139; -- Feralfen Idol
UPDATE `gameobject_template` SET `ContentTuningId`=676, `VerifiedBuild`=45745 WHERE `entry`=183043; -- Ragveil
UPDATE `gameobject_template` SET `ContentTuningId`=1281, `VerifiedBuild`=45745 WHERE `entry` IN (321185, 321184, 321182); -- Tauren Rug
UPDATE `gameobject_template` SET `ContentTuningId`=617, `VerifiedBuild`=45745 WHERE `entry`=266049; -- Cloud
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=29608, `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=203253; -- Kalimdor Eagle Nest
UPDATE `gameobject_template` SET `ContentTuningId`=14, `VerifiedBuild`=45745 WHERE `entry`=203446; -- Horde Banner
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=27844, `ContentTuningId`=16, `VerifiedBuild`=45745 WHERE `entry`=202136; -- Stonetalon Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39335, `ContentTuningId`=3, `VerifiedBuild`=45745 WHERE `entry`=207473; -- Silverbound Treasure Chest 
UPDATE `gameobject_template` SET `ContentTuningId`=288, `VerifiedBuild`=45745 WHERE `entry`=293886; -- Portal to Stormwind
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=45745 WHERE `entry`=2739; -- Chest of the Black Feather
UPDATE `gameobject_template` SET `ContentTuningId`=72, `VerifiedBuild`=45745 WHERE `entry`=2742; -- Chest of Nesting
UPDATE `gameobject_template` SET `ContentTuningId`=830, `VerifiedBuild`=45745 WHERE `entry`=296536; -- Bloodied Sentinel's Glaive
UPDATE `gameobject_template` SET `ContentTuningId`=290, `VerifiedBuild`=45745 WHERE `entry`=298776; -- Portal to Boralus Harbor
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=31999, `ContentTuningId`=9, `VerifiedBuild`=45745 WHERE `entry`=205092; -- Nascent Elementium
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=206314; -- Twilight Rune of Water
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=206312; -- Twilight Rune of Air
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=206313; -- Twilight Rune of Fire
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=206018; -- Earth Portal Controller
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=206019; -- Air Portal Controller
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry` IN (206848, 206846); -- Black Dragon Egg
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=207259; -- Induction Samophlange
UPDATE `gameobject_template` SET `ContentTuningId`=56, `VerifiedBuild`=45745 WHERE `entry`=208209; -- Anvil
UPDATE `gameobject_template` SET `ContentTuningId`=657, `VerifiedBuild`=45745 WHERE `entry`=218719; -- Raft
UPDATE `gameobject_template` SET `type`=50, `Data6`=15, `Data9`=35059, `Data11`=79156, `Data14`=0, `Data18`=1, `ContentTuningId`=864, `VerifiedBuild`=45745 WHERE `entry`=204281; -- Worm Mound
