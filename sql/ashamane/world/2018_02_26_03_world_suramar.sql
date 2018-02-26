DELETE FROM `areatrigger_template` WHERE `Id`=11869;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(11869, 0, 0, 5, 5, 0, 0, 0, 0, 25996);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=13267;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10276;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10660;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11266;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10693;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10665;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=10727;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11908;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=15273;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=9836;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=12515;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25996 WHERE `Id`=11813;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=9249 AND `AreaTriggerId`=13267) OR (`SpellMiscId`=5114 AND `AreaTriggerId`=9836);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(9249, 13267, 0, 0, 0, 0, 0, 0, 0, 25996), -- SpellId : 231969
(5114, 9836, 0, 0, 0, 0, 0, 0, 0, 25996); -- SpellId : 194538

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5972 AND `AreaTriggerId`=10660); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6710 AND `AreaTriggerId`=11266); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6711 AND `AreaTriggerId`=10693); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=59, `TimeToTargetScale`=20000, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7363 AND `AreaTriggerId`=12515); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25996 WHERE (`SpellMiscId`=7349 AND `AreaTriggerId`=11813); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=732 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=712 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=1056 AND `ConversationActorId`=50880 AND `Idx`=0) OR (`ConversationId`=3453 AND `ConversationActorId`=51894 AND `Idx`=0) OR (`ConversationId`=1457 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=711 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=1051 AND `ConversationActorId`=50880 AND `Idx`=0) OR (`ConversationId`=713 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=710 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=1060 AND `ConversationActorId`=50880 AND `Idx`=0) OR (`ConversationId`=1048 AND `ConversationActorId`=50880 AND `Idx`=0) OR (`ConversationId`=730 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=714 AND `ConversationActorId`=50128 AND `Idx`=0) OR (`ConversationId`=1057 AND `ConversationActorId`=50880 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(732, 50128, 0, 25996),
(712, 50128, 0, 25996),
(1056, 50880, 0, 25996),
(3453, 51894, 0, 25996),
(1457, 50128, 0, 25996),
(711, 50128, 0, 25996),
(1051, 50880, 0, 25996),
(713, 50128, 0, 25996),
(710, 50128, 0, 25996),
(1060, 50880, 0, 25996),
(1048, 50880, 0, 25996),
(730, 50128, 0, 25996),
(714, 50128, 0, 25996),
(1057, 50880, 0, 25996);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (50128, 50880, 51894);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(50128, 99667, 65081, 25996),
(50880, 101499, 65843, 25996),
(51894, 96679, 67161, 25996);


DELETE FROM `conversation_line_template` WHERE `Id` IN (1734, 1692, 2598, 7234, 3287, 3286, 3285, 1691, 2577, 2576, 1695, 1690, 1689, 2603, 2568, 1731, 3284, 2599);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(1734, 0, 575, 0, 0, 25996),
(1692, 0, 575, 0, 0, 25996),
(2598, 0, 575, 0, 0, 25996),
(7234, 0, 604, 0, 0, 25996),
(3287, 16858, 575, 0, 0, 25996),
(3286, 11205, 575, 0, 8250, 25996),
(3285, 0, 575, 0, 0, 25996),
(1691, 0, 575, 0, 0, 25996),
(2577, 4606, 575, 0, 8250, 25996),
(2576, 0, 575, 0, 0, 25996),
(1695, 0, 575, 0, 0, 25996),
(1690, 15871, 575, 0, 0, 25996),
(1689, 0, 575, 0, 0, 25996),
(2603, 0, 575, 0, 0, 25996),
(2568, 0, 575, 0, 0, 25996),
(1731, 0, 575, 0, 0, 25996),
(3284, 0, 575, 0, 0, 25996),
(2599, 0, 575, 0, 0, 25996);


DELETE FROM `conversation_template` WHERE `Id` IN (1056, 1057, 1051, 1060, 1048, 1457, 714, 713, 730, 732, 712, 711, 710, 3453);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(1056, 2598, 5501, 25996),
(1057, 2599, 6919, 25996),
(1051, 2576, 10212, 25996),
(1060, 2603, 4001, 25996),
(1048, 2568, 5341, 25996),
(1457, 3285, 23941, 25996),
(714, 3284, 9712, 25996),
(713, 1695, 10992, 25996),
(730, 1731, 13291, 25996),
(732, 1734, 11275, 25996),
(712, 1692, 12091, 25996),
(711, 1691, 10491, 25996),
(710, 1689, 21967, 25996),
(3453, 7234, 11350, 25996);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (266432 /*Arcfence Post*/, 266783 /*Crate*/, 266787 /*Candles*/, 266785 /*Candles*/, 266827 /*Web*/, 266771 /*Book*/, 266805 /*Web*/, 266795 /*Book*/, 266791 /*Scrolls*/, 266776 /*Bookshelf*/, 266778 /*Bookshelf*/, 266773 /*Book*/, 266772 /*Book*/, 245950 /*Fountain*/, 245926 /*Library*/, 266056 /*Nightborne Teleporter*/, 266781 /*Pylon*/, 266779 /*Bookshelf*/, 266775 /*Table*/, 266774 /*Table*/, 266789 /*Table*/, 245927 /*Warp Lab*/, 245954 /*Fountain*/, 266793 /*Table*/, 266784 /*Crate*/, 266780 /*Books*/, 266777 /*Bookshelf*/, 266433 /*Arcshaper Rune*/, 266055 /*Stasis Pad*/, 266126 /*"Your Ancestors"*/, 266127 /*"Just wanted you to feel at home, mon."*/, 266131 /*Replacement Sunwell*/, 266125 /*Portal to Silvermoon*/, 266128 /*"We found your mounts..."*/, 251874 /*Wriggling Cocoon*/, 247071 /*Wriggling Cocoon*/, 251873 /*Wriggling Cocoon*/, 251354 /*Wriggling Cocoon*/, 251334 /*Conspicuous Sand Pile*/, 251324 /*Conspicuous Sand Pile*/, 251329 /*Conspicuous Dirt Pile*/, 250289 /*Clam*/, 250288 /*Speckled Pearl*/, 250282 /*Seaweed*/, 250287 /*Seaweed*/, 250291 /*Clam*/, 250290 /*Clam*/, 250285 /*Driftwood*/, 250286 /*Seaweed*/, 250284 /*Driftwood*/, 266919 /*The Nighthold Portcullis*/, 266130 /*"Didn't want you to get the shakes."*/, 268368 /*Kirin Tor Arcane Matrix*/, 280797 /*Mail Tube*/, 247858 /*Mail Tube*/, 246011 /*Portal to Shattrath*/, 252801 /*Artifact Research Notes*/, 266619 /*A Mysterious Note*/, 266705 /*Willem West's Table*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(266432, 0, 16), -- Arcfence Post
(266783, 1375, 8192), -- Crate
(266787, 1375, 0), -- Candles
(266785, 1375, 0), -- Candles
(266827, 1375, 0), -- Web
(266771, 1375, 0), -- Book
(266805, 1375, 0), -- Web
(266795, 1375, 0), -- Book
(266791, 1375, 0), -- Scrolls
(266776, 1375, 0), -- Bookshelf
(266778, 1375, 0), -- Bookshelf
(266773, 1375, 0), -- Book
(266772, 1375, 0), -- Book
(245950, 0, 262144), -- Fountain
(245926, 0, 262144), -- Library
(266056, 0, 262144), -- Nightborne Teleporter
(266781, 1375, 8192), -- Pylon
(266779, 1375, 8192), -- Bookshelf
(266775, 1375, 8192), -- Table
(266774, 1375, 8192), -- Table
(266789, 1375, 8192), -- Table
(245927, 0, 262144), -- Warp Lab
(245954, 0, 262144), -- Fountain
(266793, 1375, 8192), -- Table
(266784, 1375, 8192), -- Crate
(266780, 1375, 8192), -- Books
(266777, 1375, 8192), -- Bookshelf
(266433, 0, 16), -- Arcshaper Rune
(266055, 0, 16), -- Stasis Pad
(266126, 0, 262144), -- "Your Ancestors"
(266127, 0, 262144), -- "Just wanted you to feel at home, mon."
(266131, 0, 262144), -- Replacement Sunwell
(266125, 1735, 0), -- Portal to Silvermoon
(266128, 0, 262144), -- "We found your mounts..."
(251874, 0, 16), -- Wriggling Cocoon
(247071, 0, 16), -- Wriggling Cocoon
(251873, 0, 16), -- Wriggling Cocoon
(251354, 0, 16), -- Wriggling Cocoon
(251334, 0, 262144), -- Conspicuous Sand Pile
(251324, 0, 262144), -- Conspicuous Sand Pile
(251329, 0, 262144), -- Conspicuous Dirt Pile
(250289, 0, 262144), -- Clam
(250288, 0, 262144), -- Speckled Pearl
(250282, 0, 262144), -- Seaweed
(250287, 0, 262144), -- Seaweed
(250291, 0, 262144), -- Clam
(250290, 0, 262144), -- Clam
(250285, 0, 262144), -- Driftwood
(250286, 0, 262144), -- Seaweed
(250284, 0, 262144), -- Driftwood
(266919, 0, 32), -- The Nighthold Portcullis
(266130, 0, 262144), -- "Didn't want you to get the shakes."
(268368, 0, 262144), -- Kirin Tor Arcane Matrix
(280797, 0, 262144), -- Mail Tube
(247858, 0, 262144), -- Mail Tube
(246011, 1735, 0), -- Portal to Shattrath
(252801, 0, 262144), -- Artifact Research Notes
(266619, 0, 2113540), -- A Mysterious Note
(266705, 1375, 16); -- Willem West's Table

UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=246225; -- Weathered Telemancy Beacon
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=221482; -- PA Mug Bamboo 06
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=260498; -- Leypetal Blossom
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=252812; -- Treasure Chest
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=251416; -- Ancient Mana Chunk
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=252772; -- Ancient Mana Chunk
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=260247; -- Ancient Mana Chunk
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=252774; -- Ancient Mana Crystal
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=260248; -- Ancient Mana Shard
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=260249; -- Ancient Mana Shard
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=252408; -- Ancient Mana Shard
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=245126; -- Crystallized Ancient Mana
UPDATE `gameobject_template_addon` SET `flags`=36 WHERE `entry`=265435; -- Doodad_7sr_hubmanatree_seedholder001

DELETE FROM `quest_poi` WHERE (`QuestID`=-469762048 AND `BlobIndex`=603979776 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `WoDUnk1`, `VerifiedBuild`) VALUES
(-469762048, 603979776, 0, 1862270988, 25, 35375, 3, 0, -1, 0, 0, 1116, 950, 0, 25996); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=44691 AND `BlobIndex`=0 AND `Idx1`=0); -- Hungry Work
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40830 AND `BlobIndex`=0 AND `Idx1`=0); -- Close Enough
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40748 AND `BlobIndex`=0 AND `Idx1`=0); -- Network Security
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40747 AND `BlobIndex`=0 AND `Idx1`=0); -- The Delicate Art of Telemancy
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41762 AND `BlobIndex`=0 AND `Idx1`=0); -- Sympathizers Among the Shal'dorei
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41760 AND `BlobIndex`=0 AND `Idx1`=0); -- Kel'danath's Legacy
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40796 AND `BlobIndex`=0 AND `Idx1`=0); -- Lingering on the Edge
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41143 AND `BlobIndex`=0 AND `Idx1`=0); -- Mglrgrs Of Our Grmlgrlr
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=42728 AND `BlobIndex`=0 AND `Idx1`=0); -- A Mlrglrmg For Grlmrgl
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=42688 AND `BlobIndex`=0 AND `Idx1`=0); -- Mrgls of Endearment
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=42396 AND `BlobIndex`=0 AND `Idx1`=0); -- Do The Thing!
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41704 AND `BlobIndex`=0 AND `Idx1`=0); -- Subject 16
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41702 AND `BlobIndex`=0 AND `Idx1`=0); -- Written in Stone
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=41149 AND `BlobIndex`=0 AND `Idx1`=0); -- A Re-Warding Effort
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40326 AND `BlobIndex`=0 AND `Idx1`=0); -- Scattered Memories
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40012 AND `BlobIndex`=0 AND `Idx1`=0); -- An Old Ally
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40011 AND `BlobIndex`=0 AND `Idx1`=0); -- Oculeth's Workshop
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=44672 AND `BlobIndex`=0 AND `Idx1`=0); -- Ancient Mana
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=42229 AND `BlobIndex`=0 AND `Idx1`=0); -- Shal'Aran
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40009 AND `BlobIndex`=0 AND `Idx1`=0); -- Arcane Thirst
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40123 AND `BlobIndex`=0 AND `Idx1`=0); -- The Nightborne Pact
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=40008 AND `BlobIndex`=0 AND `Idx1`=0); -- The Only Way Out is Through
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=39987 AND `BlobIndex`=0 AND `Idx1`=0); -- Trail of Echoes
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=39986 AND `BlobIndex`=0 AND `Idx1`=0); -- Magic Message
UPDATE `quest_poi` SET `ObjectiveIndex`=8192, `MapID`=285696, `WorldMapAreaId`=250880, `WoDUnk1`=222477312, `VerifiedBuild`=25996 WHERE (`QuestID`=34209 AND `BlobIndex`=0 AND `Idx1`=1); -- Vouchsafe Our Arrival
UPDATE `quest_poi` SET `VerifiedBuild`=25996 WHERE (`QuestID`=34209 AND `BlobIndex`=0 AND `Idx1`=0); -- Vouchsafe Our Arrival

DELETE FROM `spell_target_position` WHERE (`ID`=232241 AND `EffectIndex`=0) OR (`ID`=229237 AND `EffectIndex`=2) OR (`ID`=241931 AND `EffectIndex`=0) OR (`ID`=191474 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(232241, 0, 1220, 1776.73, 4637.35, 124, 25996), -- Spell: Téléportation : Hub Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(229237, 2, 1662, 949.07, 4166.23, 1.42, 25996), -- Spell: Téléportation : sanctum de l’ordre Efffect: 227 (SPELL_EFFECT_TELEPORT_TO_LFG_DUNGEON)
(241931, 0, 1220, -1620.93, 3212.35, 129.02, 25996), -- Spell: Saut céleste vers le rivage Brisé Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(191474, 0, 1220, -835.44, 4276.82, 746.25, 25996); -- Spell: Saut vers Dalaran Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222545 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=193753 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=202664 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=202605 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=224674 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222550 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=224670 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=217759 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222712 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=194453 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=193590 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=251062 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=595.85, `PositionY`=6701.74, `PositionZ`=62.42, `VerifiedBuild`=25996 WHERE (`ID`=225162 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=222695 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=3201.61, `PositionY`=1532.4, `PositionZ`=180.8, `VerifiedBuild`=25996 WHERE (`ID`=225219 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `PositionX`=2278.69, `PositionY`=6596.63, `PositionZ`=137.47, `VerifiedBuild`=25996 WHERE (`ID`=225114 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=216016 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `MapID`=1153, `PositionX`=5563.7, `PositionY`=4599.9, `PositionZ`=141.71, `VerifiedBuild`=25996 WHERE (`ID`=171253 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=215792 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=25996 WHERE (`ID`=225574 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (102017 /*102017 (Chief Telemancer Oculeth)*/, 102142 /*102142 (Chief Telemancer Oculeth)*/, 101782 /*101782 (Chief Telemancer Oculeth)*/, 101116 /*101116 (Warpcaster Thwen) - Armure dimensionnelle*/, 116069 /*116069 (Beam Target Stalker)*/, 116626 /*116626 (Warp Aberration)*/, 116622 /*116622 (Unstable Rift) - Visuel de Faille dimensionnelle, Faille dimensionnelle*/, 116623 /*116623 (Warp Spark)*/, 101110 /*101110 (Warp Ray)*/, 117437 /*Ligne tellurique - Ligne tellurique*/, 115469 /*115469 (Orlis)*/, 116421 /*116421 (Ley Line Channeler) - Canalisation des Arcanes*/, 115480 /*115480 (Fel-Powered Sentinel)*/, 115519 /*115519 (Felborne Spellbreaker)*/, 114924 /*114924 (Duskwatch Saberguard)*/, 101499 /*101499 (Chief Telemancer Oculeth)*/, 113483 /*113483 (Menagerie Shopkeeper)*/, 116063 /*116063 (Animated Spellbook)*/, 114927 /*114927 (Fist of the Duskwatch)*/, 114926 /*114926 (Arcane Sentinel) - Détecteur, Détection de l'invisibilité et du camouflage*/, 115430 /*115430 (Charged Arcshaper Staff)*/, 115526 /*115526 (Arcshaper Thorendis) - Arquebouclier fortifié*/, 116050 /*116050 (Duskwatch Conjurer)*/, 115261 /*115261 (Disabled Construct) - Permanent Feign Death (Stun, Untrackable)*/, 113205 /*113205 (Leyscarred Stag) - Imprégnation des Arcanes*/, 114866 /*Mage gardien du Concordat argenté*/, 114880 /*Chevalier de sang garde de l’aube*/, 114929 /*114929 (Duskwatch Defender)*/, 114995 /*Mage de guerre du Concordat argenté*/, 114838 /*Tyrande Murmevent*/, 115926 /*Sentinelle de Darnassus - Mascarade*/, 114883 /*114883 (Grand Magister Rommath) - Armure de la fournaise*/, 114897 /*Sentinelle de Darnassus*/, 114885 /*114885 (Dawnseeker Guardian)*/, 114887 /*114887 (Lanesh the Steelweaver)*/, 114841 /*Dame Liadrin - Aura de vindicte*/, 69759 /*69759 (Defense Crystal) - Grille de défense de cristal*/, 115605 /*115605 (Chicken Escapee)*/, 114849 /*114849 (Ancient Defender)*/, 99793 /*99793 (Leyscale Manalisk) - Imprégnation des Arcanes*/, 108536 /*108536 (Monstrous Leycrawler)*/, 98699 /*98699 (Webbed Husk)*/, 108878 /*108878 (Mrs. Mrglglrm)*/, 110824 /*Griffe-des-marées*/, 100846 /*100846 (Leytusk)*/, 90232 /*Faille déliée - Faille de mana*/, 90242 /*Wyrm de faille*/, 108535 /*108535 (Marsh Hydra)*/, 108779 /*108779 (Mrs. Mrglglrm) - Tenue de maman murloc*/, 108389 /*108389 (Mrgrlilgrl)*/, 108390 /*108390 (Mr. Mrglglrm) - Tenue de papa murloc*/, 112802 /*Mar’tura*/, 107302 /*107302 (Pearlhunter Phin)*/, 107303 /*107303 (Crab)*/, 112367 /*112367 (Leyscar Runt)*/, 109803 /*Carapateur entaillurique*/, 105728 /*105728 (Scythemaster Cil'raman)*/, 100059 /*100059 (Arcane Ward) - Visuel de protection des Arcanes*/, 99539 /*99539 (Eternal Tether) - Longe éternelle (périodique)*/, 99524 /*99524 (Keeper Selentia)*/, 99088 /*99088 (Ancient Keeper)*/, 99482 /*99482 (First Arcanist Thalyssra)*/, 98967 /*98967 (Barrier Bunny) - Contrôleur de siphon de mana*/, 98946 /*98946 (Withered Thirster)*/, 98312 /*98312 (First Arcanist Thalyssra) - Barrière des Arcanes*/, 98943 /*98943 (Withered)*/, 99213 /*99213 (Erasmus Moonblade) - Arrêt du temps*/, 114071 /*114071 (Pulsing Arcane Echo) - Visuel d’Echo arcanique vibrant*/, 114070 /*114070 (Blinking Arcane Echo) - Visuel d’Echo arcanique clignotant*/, 112627 /*112627 (Curious Manasaber)*/, 98209 /*98209 (Echo of First Arcanist Thalyssra)*/, 100169 /*100169 (Faint Arcane Echo) - Visuel de Faible écho arcanique*/, 99267 /*99267 (Nightborne Scion)*/, 114931 /*Rebelle souffrenuit*/, 115381 /*115381 (Nightborne Rebel)*/, 115500 /*115500 (Dusktalon)*/, 114865 /*Magus garde de l’aube*/, 115924 /*Magus garde de l’aube - Mascarade*/, 114845 /*Démolisseur ignétoile*/, 115684 /*Garde-paix du Kirin Tor - Armure de givre*/, 115498 /*115498 (Lothrius Mooncaller)*/, 122926 /*122926 (Chromie)*/, 118506 /*Sorcelame saccage-soleil*/, 98266 /*98266 (Arcane Anomaly)*/, 103976 /*103976 (The Postmaster)*/, 79861 /*79861 (Generic Bunny)*/, 119436 /*119436 (NO ADDRESS)*/, 119396 /*119396 (RETURN TO SENDER)*/, 119438 /*119438 (BAD HANDWRITING)*/, 119437 /*119437 (NOT ENOUGH STAMPS)*/, 104230 /*Postier-lémentaire*/, 97501 /*Linzi Rirouge*/, 119226 /*119226 (Danath Trollbane)*/, 103116 /*103116 (Dalaran Citizen)*/, 103119 /*103119 (Dalaran Citizen)*/, 103118 /*103118 (Dalaran Citizen)*/, 103120 /*103120 (Dalaran Citizen)*/, 117448 /*117448 (Cinnamon) - Chapeau de Cannelle*/, 97389 /*97389 (Eye of Odyn)*/, 100635 /*100635 (Skyseer Ghrent)*/, 106459 /*Capitaine Hjalmar Stahlstrom*/, 107994 /*107994 (Einar the Runecaster)*/, 110437 /*110437 (Haklang Ulfsson)*/, 113267 /*Aspirant valarjar*/, 116609 /*116609 (Battlelord's Armor)*/, 120413 /*120413 (Rensar Greathoof)*/, 120412 /*120412 (Farseer Nobundo)*/, 120415 /*120415 (Highlord Darion Mograine)*/, 120424 /*120424 (Alonsus Faol)*/, 120418 /*120418 (Havi)*/, 120421 /*120421 (Ritssyn Flamescowl)*/, 120420 /*120420 (Iron-Body Ponshu)*/, 120423 /*120423 (Emmarel Shadewarden)*/, 120422 /*120422 (Lady Liadrin)*/, 120417 /*120417 (Meryl Felstorm)*/, 120416 /*120416 (Lord Jorach Ravenholdt)*/, 120419 /*120419 (Kor'vas Bloodthorn)*/, 124678 /*124678 (Dalaran Citizen)*/, 120687 /*120687 (Violet Shadowmend)*/, 116420 /*116420 (Glowing Blue Gem)*/, 116419 /*116419 (Glowing Green Gem) - Gemme activée*/, 116408 /*116408 (Glowing Red Gem) - Gemme activée*/, 125261 /*125261 (Bran Buckbeard)*/, 119088 /*119088 (Anebria Sunwine)*/, 119642 /*119642 (Reliquary Pick)*/, 97489 /*Garl Mornegrise*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(102017, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102017 (Chief Telemancer Oculeth)
(102142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102142 (Chief Telemancer Oculeth)
(101782, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 101782 (Chief Telemancer Oculeth)
(101116, 0, 0, 50331648, 1, 0, 0, 0, 0, '201011'), -- 101116 (Warpcaster Thwen) - Armure dimensionnelle
(116069, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116069 (Beam Target Stalker)
(116626, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116626 (Warp Aberration)
(116622, 0, 0, 0, 1, 0, 0, 0, 0, '211880 211884'), -- 116622 (Unstable Rift) - Visuel de Faille dimensionnelle, Faille dimensionnelle
(116623, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116623 (Warp Spark)
(101110, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 101110 (Warp Ray)
(117437, 0, 0, 0, 1, 0, 0, 0, 0, '233817'), -- Ligne tellurique - Ligne tellurique
(115469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115469 (Orlis)
(116421, 0, 0, 0, 1, 0, 0, 0, 0, '39550'), -- 116421 (Ley Line Channeler) - Canalisation des Arcanes
(115480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115480 (Fel-Powered Sentinel)
(115519, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 115519 (Felborne Spellbreaker)
(114924, 0, 69468, 0, 1, 0, 0, 0, 0, ''), -- 114924 (Duskwatch Saberguard)
(101499, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101499 (Chief Telemancer Oculeth)
(113483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 113483 (Menagerie Shopkeeper)
(116063, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 116063 (Animated Spellbook)
(114927, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114927 (Fist of the Duskwatch)
(114926, 0, 0, 0, 1, 0, 0, 0, 0, '203761 67236'), -- 114926 (Arcane Sentinel) - Détecteur, Détection de l'invisibilité et du camouflage
(115430, 0, 0, 0, 1, 0, 0, 0, 0, '229543'), -- 115430 (Charged Arcshaper Staff)
(115526, 0, 0, 33554432, 1, 0, 0, 0, 0, '229750'), -- 115526 (Arcshaper Thorendis) - Arquebouclier fortifié
(116050, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116050 (Duskwatch Conjurer)
(115261, 0, 0, 262144, 1, 0, 0, 0, 0, '145362'), -- 115261 (Disabled Construct) - Permanent Feign Death (Stun, Untrackable)
(113205, 0, 0, 0, 1, 0, 0, 0, 0, '225291'), -- 113205 (Leyscarred Stag) - Imprégnation des Arcanes
(114866, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mage gardien du Concordat argenté
(114880, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Chevalier de sang garde de l’aube
(114929, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114929 (Duskwatch Defender)
(114995, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mage de guerre du Concordat argenté
(114838, 0, 6080, 0, 1, 0, 0, 0, 0, ''), -- Tyrande Murmevent
(115926, 0, 0, 8, 1, 0, 0, 0, 0, '230370'), -- Sentinelle de Darnassus - Mascarade
(114883, 0, 0, 0, 257, 0, 0, 0, 0, '79849'), -- 114883 (Grand Magister Rommath) - Armure de la fournaise
(114897, 0, 62588, 0, 1, 0, 0, 0, 0, ''), -- Sentinelle de Darnassus
(114885, 0, 0, 0, 258, 0, 0, 0, 0, ''), -- 114885 (Dawnseeker Guardian)
(114887, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 114887 (Lanesh the Steelweaver)
(114841, 0, 0, 0, 1, 0, 0, 0, 0, '165746'), -- Dame Liadrin - Aura de vindicte
(69759, 0, 0, 50331648, 1, 0, 0, 0, 0, '138034'), -- 69759 (Defense Crystal) - Grille de défense de cristal
(115605, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115605 (Chicken Escapee)
(114849, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 114849 (Ancient Defender)
(99793, 0, 0, 0, 1, 0, 0, 0, 0, '225291'), -- 99793 (Leyscale Manalisk) - Imprégnation des Arcanes
(108536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108536 (Monstrous Leycrawler)
(98699, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98699 (Webbed Husk)
(108878, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108878 (Mrs. Mrglglrm)
(110824, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Griffe-des-marées
(100846, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100846 (Leytusk)
(90232, 0, 0, 0, 1, 0, 0, 0, 0, '179500'), -- Faille déliée - Faille de mana
(90242, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Wyrm de faille
(108535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108535 (Marsh Hydra)
(108779, 0, 0, 0, 1, 0, 0, 0, 0, '216021'), -- 108779 (Mrs. Mrglglrm) - Tenue de maman murloc
(108389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 108389 (Mrgrlilgrl)
(108390, 0, 0, 0, 2, 0, 0, 0, 0, '216018'), -- 108390 (Mr. Mrglglrm) - Tenue de papa murloc
(112802, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mar’tura
(107302, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107302 (Pearlhunter Phin)
(107303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107303 (Crab)
(112367, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112367 (Leyscar Runt)
(109803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Carapateur entaillurique
(105728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 105728 (Scythemaster Cil'raman)
(100059, 0, 0, 0, 1, 0, 0, 0, 0, '204889'), -- 100059 (Arcane Ward) - Visuel de protection des Arcanes
(99539, 0, 0, 0, 1, 0, 0, 0, 0, '216370'), -- 99539 (Eternal Tether) - Longe éternelle (périodique)
(99524, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 99524 (Keeper Selentia)
(99088, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 99088 (Ancient Keeper)
(99482, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99482 (First Arcanist Thalyssra)
(98967, 0, 0, 0, 1, 0, 0, 0, 0, '194869'), -- 98967 (Barrier Bunny) - Contrôleur de siphon de mana
(98946, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98946 (Withered Thirster)
(98312, 0, 0, 0, 1, 0, 0, 0, 0, '194124'), -- 98312 (First Arcanist Thalyssra) - Barrière des Arcanes
(98943, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98943 (Withered)
(99213, 0, 0, 0, 1, 0, 0, 0, 0, '195289'), -- 99213 (Erasmus Moonblade) - Arrêt du temps
(114071, 0, 0, 0, 1, 0, 0, 0, 0, '227111'), -- 114071 (Pulsing Arcane Echo) - Visuel d’Echo arcanique vibrant
(114070, 0, 0, 0, 1, 0, 0, 0, 0, '227110'), -- 114070 (Blinking Arcane Echo) - Visuel d’Echo arcanique clignotant
(112627, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 112627 (Curious Manasaber)
(98209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98209 (Echo of First Arcanist Thalyssra)
(100169, 0, 0, 0, 1, 0, 0, 0, 0, '227109'), -- 100169 (Faint Arcane Echo) - Visuel de Faible écho arcanique
(99267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99267 (Nightborne Scion)
(114931, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Rebelle souffrenuit
(115381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115381 (Nightborne Rebel)
(115500, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115500 (Dusktalon)
(114865, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Magus garde de l’aube
(115924, 0, 0, 8, 1, 0, 0, 0, 0, '230370'), -- Magus garde de l’aube - Mascarade
(114845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Démolisseur ignétoile
(115684, 0, 0, 0, 257, 0, 0, 0, 0, '183111'), -- Garde-paix du Kirin Tor - Armure de givre
(115498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115498 (Lothrius Mooncaller)
(122926, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122926 (Chromie)
(118506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sorcelame saccage-soleil
(98266, 0, 0, 0, 1, 0, 0, 0, 0, '193606'), -- 98266 (Arcane Anomaly)
(103976, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103976 (The Postmaster)
(79861, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 79861 (Generic Bunny)
(119436, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119436 (NO ADDRESS)
(119396, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119396 (RETURN TO SENDER)
(119438, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119438 (BAD HANDWRITING)
(119437, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 119437 (NOT ENOUGH STAMPS)
(104230, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Postier-lémentaire
(97501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Linzi Rirouge
(119226, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 119226 (Danath Trollbane)
(103116, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103116 (Dalaran Citizen)
(103119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103119 (Dalaran Citizen)
(103118, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103118 (Dalaran Citizen)
(103120, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103120 (Dalaran Citizen)
(117448, 0, 0, 1, 1, 0, 0, 0, 0, '233861'), -- 117448 (Cinnamon) - Chapeau de Cannelle
(97389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 97389 (Eye of Odyn)
(100635, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100635 (Skyseer Ghrent)
(106459, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Capitaine Hjalmar Stahlstrom
(107994, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107994 (Einar the Runecaster)
(110437, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 110437 (Haklang Ulfsson)
(113267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Aspirant valarjar
(116609, 0, 0, 0, 1, 0, 12290, 0, 0, ''), -- 116609 (Battlelord's Armor)
(120413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120413 (Rensar Greathoof)
(120412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120412 (Farseer Nobundo)
(120415, 0, 70478, 0, 1, 0, 0, 0, 0, ''), -- 120415 (Highlord Darion Mograine)
(120424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120424 (Alonsus Faol)
(120418, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120418 (Havi)
(120421, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120421 (Ritssyn Flamescowl)
(120420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120420 (Iron-Body Ponshu)
(120423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120423 (Emmarel Shadewarden)
(120422, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120422 (Lady Liadrin)
(120417, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120417 (Meryl Felstorm)
(120416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120416 (Lord Jorach Ravenholdt)
(120419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120419 (Kor'vas Bloodthorn)
(124678, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 124678 (Dalaran Citizen)
(120687, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120687 (Violet Shadowmend)
(116420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 116420 (Glowing Blue Gem)
(116419, 0, 0, 0, 1, 0, 0, 0, 0, '232269'), -- 116419 (Glowing Green Gem) - Gemme activée
(116408, 0, 0, 0, 1, 0, 0, 0, 0, '232268'), -- 116408 (Glowing Red Gem) - Gemme activée
(125261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 125261 (Bran Buckbeard)
(119088, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119088 (Anebria Sunwine)
(119642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 119642 (Reliquary Pick)
(97489, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Garl Mornegrise

UPDATE `creature_template_addon` SET `auras`='201446' WHERE `entry`=98548; -- 98548 (Chief Telemancer Oculeth)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='231918' WHERE `entry`=111921; -- 111921 (Buried Exile)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=106648; -- 106648 (Stormwing Drake)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=106609; -- 106609 (Adolescent Stormwing)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=107567; -- 107567 (Suramar Shieldguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=101848; -- 101848 (Absolon)
UPDATE `creature_template_addon` SET `auras`='212102' WHERE `entry`=106873; -- 106873 (Font of Arcane Energy)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145362' WHERE `entry`=101825; -- 101825 (Nightborne Enforcer)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145362' WHERE `entry`=101821; -- 101821 (Nightborne Warpcaster)
UPDATE `creature_template_addon` SET `auras`='204844' WHERE `entry`=99791; -- Ettin de Koralune
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=104224; -- Grogneur de Suramar
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=103540; -- 103540 (Starclutch Screecher)
UPDATE `creature_template_addon` SET `auras`='225291 152209' WHERE `entry`=113126; -- 113126 (Meredil Lockjaw)
UPDATE `creature_template_addon` SET `auras`='191825' WHERE `entry`=97140; -- 97140 (First Arcanist Thalyssra)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113985; -- 113985 (Elieth)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145362' WHERE `entry`=98555; -- 98555 (Withered Shambler)
UPDATE `creature_template_addon` SET `auras`='152209' WHERE `entry`=99749; -- 99749 (Moonlight Hunter)
UPDATE `creature_template_addon` SET `auras`='187063' WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template_addon` SET `auras`='12544 18950' WHERE `entry`=96771; -- 96771 (Warmage Lukems)
UPDATE `creature_template_addon` SET `auras`='12544 18950' WHERE `entry`=96770; -- 96770 (Warmage Mumplina)
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=93544; -- 93544 (Jang Quillpaw)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=93532; -- 93532 (Jessica Sellers)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113785; -- 113785 (Hugh Mann)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=97005; -- 97005 (Debbi Moore)
UPDATE `creature_template_addon` SET `aiAnimKit`=3228 WHERE `entry`=110622; -- 110622 (Trevor Page)
UPDATE `creature_template_addon` SET `auras`='226952' WHERE `entry`=113901; -- 113901 (Crixa)
UPDATE `creature_template_addon` SET `auras`='79849' WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template_addon` SET `auras`='60913 61354' WHERE `entry`=96479; -- 96479 (Breanni)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (113189, 105486, 109803, 113195, 115381, 113126, 114793, 105632, 108942, 98555, 105756, 105785, 113190, 91717, 112825, 115924, 90242, 114931, 113184, 102960, 114929, 115480, 114865, 105885, 108535, 113122, 105645, 99791, 112331, 112336, 114849, 105685, 104845, 102415, 108528, 101821, 112441, 112370, 101110, 106648, 105686, 121413, 99792, 114897, 112948, 106609, 103540, 98699, 116421, 99749, 105014, 116063, 113417, 108628, 105884, 115519, 113127, 69759, 113267, 114845, 113162, 108536, 99267, 112827, 105650, 103092, 101825, 105623, 119436, 103805, 120424, 114926, 119438, 105625, 119437, 119226, 99779, 41200, 105339, 101497, 100058, 105332, 114866, 107567, 114946, 104224, 110824, 120419, 111216, 113110, 105723, 115926, 115469, 100846, 105653, 101554, 101581, 111197, 102413, 101580, 113205, 110577, 113123, 109054, 105728, 104810, 119396, 111921, 114927, 112392, 101900, 113571, 115700, 112802, 114924, 107994, 106263, 106262, 111675, 105564, 91715, 112543, 99349, 99524, 100635, 114880, 101577, 105640, 114995, 106119, 99793, 107772, 99213, 112545, 105232, 115526, 119057);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(113189, 0, 25996),
(105486, 0, 25996),
(109803, 0, 25996),
(113195, 0, 25996),
(115381, 0, 25996),
(113126, 0, 25996),
(114793, 0, 25996),
(105632, 0, 25996),
(108942, 0, 25996),
(98555, 0, 25996),
(105756, 0, 25996),
(105785, 0, 25996),
(113190, 0, 25996),
(91717, 0, 25996),
(112825, 0, 25996),
(115924, 0, 25996),
(90242, 0, 25996),
(114931, 0, 25996),
(113184, 0, 25996),
(102960, 0, 25996),
(114929, 0, 25996),
(115480, 0, 25996),
(114865, 0, 25996),
(105885, 0, 25996),
(108535, 0, 25996),
(113122, 0, 25996),
(105645, 0, 25996),
(99791, 0, 25996),
(112331, 0, 25996),
(112336, 0, 25996),
(114849, 0, 25996),
(105685, 0, 25996),
(104845, 0, 25996),
(102415, 0, 25996),
(108528, 0, 25996),
(101821, 0, 25996),
(112441, 0, 25996),
(112370, 0, 25996),
(101110, 0, 25996),
(106648, 0, 25996),
(105686, 0, 25996),
(121413, 0, 25996),
(99792, 0, 25996),
(114897, 0, 25996),
(112948, 0, 25996),
(106609, 0, 25996),
(103540, 0, 25996),
(98699, 0, 25996),
(116421, 0, 25996),
(99749, 0, 25996),
(105014, 0, 25996),
(116063, 0, 25996),
(113417, 0, 25996),
(108628, 0, 25996),
(105884, 0, 25996),
(115519, 0, 25996),
(113127, 0, 25996),
(69759, 0, 25996),
(113267, 0, 25996),
(114845, 0, 25996),
(113162, 0, 25996),
(108536, 0, 25996),
(99267, 0, 25996),
(112827, 0, 25996),
(105650, 0, 25996),
(103092, 0, 25996),
(101825, 0, 25996),
(105623, 0, 25996),
(119436, 0, 25996),
(103805, 0, 25996),
(120424, 0, 25996),
(114926, 0, 25996),
(119438, 0, 25996),
(105625, 0, 25996),
(119437, 0, 25996),
(119226, 0, 25996),
(99779, 0, 25996),
(41200, 0, 25996),
(105339, 0, 25996),
(101497, 0, 25996),
(100058, 0, 25996),
(105332, 0, 25996),
(114866, 0, 25996),
(107567, 0, 25996),
(114946, 0, 25996),
(104224, 0, 25996),
(110824, 0, 25996),
(120419, 0, 25996),
(111216, 0, 25996),
(113110, 0, 25996),
(105723, 0, 25996),
(115926, 0, 25996),
(115469, 0, 25996),
(100846, 0, 25996),
(105653, 0, 25996),
(101554, 0, 25996),
(101581, 0, 25996),
(111197, 0, 25996),
(102413, 0, 25996),
(101580, 0, 25996),
(113205, 0, 25996),
(110577, 0, 25996),
(113123, 0, 25996),
(109054, 0, 25996),
(105728, 0, 25996),
(104810, 0, 25996),
(119396, 0, 25996),
(111921, 0, 25996),
(114927, 0, 25996),
(112392, 0, 25996),
(101900, 0, 25996),
(113571, 0, 25996),
(115700, 0, 25996),
(112802, 0, 25996),
(114924, 0, 25996),
(107994, 0, 25996),
(106263, 0, 25996),
(106262, 0, 25996),
(111675, 0, 25996),
(105564, 0, 25996),
(91715, 0, 25996),
(112543, 0, 25996),
(99349, 0, 25996),
(99524, 0, 25996),
(100635, 0, 25996),
(114880, 0, 25996),
(101577, 0, 25996),
(105640, 0, 25996),
(114995, 0, 25996),
(106119, 0, 25996),
(99793, 0, 25996),
(107772, 0, 25996),
(99213, 0, 25996),
(112545, 0, 25996),
(105232, 0, 25996),
(115526, 0, 25996),
(119057, 0, 25996);


DELETE FROM `creature_model_info` WHERE `DisplayID`=68439;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(68439, 0.306, 1.5, 0, 25996);

UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67341;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66555;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=31379;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=53731;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68015;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19403;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=44552;
UPDATE `creature_model_info` SET `BoundingRadius`=1.734094, `VerifiedBuild`=25996 WHERE `DisplayID`=33646;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66605;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64607;
UPDATE `creature_model_info` SET `BoundingRadius`=1.323187, `CombatReach`=0.6, `VerifiedBuild`=25996 WHERE `DisplayID`=34170;
UPDATE `creature_model_info` SET `BoundingRadius`=1.323187, `CombatReach`=0.6, `VerifiedBuild`=25996 WHERE `DisplayID`=34171;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67342;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67629;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67339;
UPDATE `creature_model_info` SET `BoundingRadius`=2.163142, `CombatReach`=4, `VerifiedBuild`=25996 WHERE `DisplayID`=73832;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67132;
UPDATE `creature_model_info` SET `BoundingRadius`=2.205311, `VerifiedBuild`=25996 WHERE `DisplayID`=26775;
UPDATE `creature_model_info` SET `BoundingRadius`=1.622357, `CombatReach`=3, `VerifiedBuild`=25996 WHERE `DisplayID`=75570;
UPDATE `creature_model_info` SET `BoundingRadius`=2.205311, `VerifiedBuild`=25996 WHERE `DisplayID`=34194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5852861, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=70877;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42349;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70590;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73502;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65843;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9548614, `VerifiedBuild`=25996 WHERE `DisplayID`=43100;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40003;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24928;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73412;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73410;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6671286, `VerifiedBuild`=25996 WHERE `DisplayID`=40024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9548614, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=44778;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36006;
UPDATE `creature_model_info` SET `BoundingRadius`=0.481606, `VerifiedBuild`=25996 WHERE `DisplayID`=71944;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=58159;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63866;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=21888;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70948;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69721;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66589;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67465;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39553;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40584;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69317;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60863;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=53781;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73514;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70442;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70448;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26068;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=53782;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47721;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66563;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67171;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=46523;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=39623;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46522;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=46525;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19706;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=46524;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47953;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47403;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47670;
UPDATE `creature_model_info` SET `BoundingRadius`=0.10875, `CombatReach`=0.75, `VerifiedBuild`=25996 WHERE `DisplayID`=36331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26074;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=56952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74615;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71840;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68392;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65204;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=44577;
UPDATE `creature_model_info` SET `BoundingRadius`=3.5, `CombatReach`=4.375, `VerifiedBuild`=25996 WHERE `DisplayID`=32112;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60914;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68736;
UPDATE `creature_model_info` SET `BoundingRadius`=1.790547, `VerifiedBuild`=25996 WHERE `DisplayID`=22255;
UPDATE `creature_model_info` SET `BoundingRadius`=2.059129, `VerifiedBuild`=25996 WHERE `DisplayID`=43225;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70524;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62708;
UPDATE `creature_model_info` SET `BoundingRadius`=1.53238, `VerifiedBuild`=25996 WHERE `DisplayID`=26753;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70232;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67253;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61702;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55455;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=391;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=188;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5243;
UPDATE `creature_model_info` SET `BoundingRadius`=2.864584, `CombatReach`=6, `VerifiedBuild`=25996 WHERE `DisplayID`=44781;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1994;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28507;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69916;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45881;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69915;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36284;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32061;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45491;
UPDATE `creature_model_info` SET `BoundingRadius`=0.87234, `VerifiedBuild`=25996 WHERE `DisplayID`=70943;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72654;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62387;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67340;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66246;
UPDATE `creature_model_info` SET `BoundingRadius`=2.092043, `VerifiedBuild`=25996 WHERE `DisplayID`=69293;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66341;
UPDATE `creature_model_info` SET `BoundingRadius`=1.307527, `VerifiedBuild`=25996 WHERE `DisplayID`=69219;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66542;
UPDATE `creature_model_info` SET `BoundingRadius`=0.93, `CombatReach`=4.5, `VerifiedBuild`=25996 WHERE `DisplayID`=72663;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71134;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72843;
UPDATE `creature_model_info` SET `BoundingRadius`=2.092043, `VerifiedBuild`=25996 WHERE `DisplayID`=69230;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68737;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69229;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66211;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69273;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16213;
UPDATE `creature_model_info` SET `BoundingRadius`=3.138064, `VerifiedBuild`=25996 WHERE `DisplayID`=69220;
UPDATE `creature_model_info` SET `BoundingRadius`=0.87234, `VerifiedBuild`=25996 WHERE `DisplayID`=70831;
UPDATE `creature_model_info` SET `BoundingRadius`=1.031494, `VerifiedBuild`=25996 WHERE `DisplayID`=68393;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=52601;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70451;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46710;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70446;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.72695, `VerifiedBuild`=25996 WHERE `DisplayID`=70582;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27627;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70817;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40090;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72734;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=51815;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40089;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=55080;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5189645, `VerifiedBuild`=25996 WHERE `DisplayID`=30256;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40094;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63621;
UPDATE `creature_model_info` SET `BoundingRadius`=3.230401, `VerifiedBuild`=25996 WHERE `DisplayID`=32807;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=54854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=6148;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70768;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66030;
UPDATE `creature_model_info` SET `BoundingRadius`=0.72695, `VerifiedBuild`=25996 WHERE `DisplayID`=69442;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66667;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65100;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66541;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72041;
UPDATE `creature_model_info` SET `BoundingRadius`=0.58156, `VerifiedBuild`=25996 WHERE `DisplayID`=68237;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=62592;
UPDATE `creature_model_info` SET `BoundingRadius`=0.58156, `VerifiedBuild`=25996 WHERE `DisplayID`=68239;
UPDATE `creature_model_info` SET `BoundingRadius`=0.58156, `VerifiedBuild`=25996 WHERE `DisplayID`=68238;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66567;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66262;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70016;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71587;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70012;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71231;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70014;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67365;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70011;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63624;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26073;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=51301;
UPDATE `creature_model_info` SET `BoundingRadius`=1.0075, `CombatReach`=3.25, `VerifiedBuild`=25996 WHERE `DisplayID`=47695;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66974;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64541;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65737;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47090;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69097;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69094;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27949;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27944;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26376;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26378;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71830;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67195;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72076;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=25996 WHERE `DisplayID`=79714;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65834;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67193;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63776;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47094;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25645;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38491;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25650;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25620;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66652;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25622;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2428;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71622;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69194;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72947;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26075;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26390;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72985;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=45425;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69575;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28433;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25618;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28146;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28163;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=24916;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38804;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25610;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25635;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=75274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=75276;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=75277;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=75278;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3043069, `CombatReach`=0.75, `VerifiedBuild`=25996 WHERE `DisplayID`=68547;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28149;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26310;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28153;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65163;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36894;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36893;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=38800;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25594;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65174;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25604;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23672;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36883;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69528;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66838;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72114;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29735;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1595;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65172;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70701;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69780;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26300;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25621;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46696;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65234;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25880;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=56737;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46697;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30415;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=46694;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30358;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26321;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25602;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72235;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65164;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=48278;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29834;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3672, `CombatReach`=1.8, `VerifiedBuild`=25996 WHERE `DisplayID`=64782;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=73438;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25608;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27958;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65345;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25878;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65106;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=29835;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65256;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27962;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25609;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28150;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28154;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68004;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68021;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68020;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68022;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27956;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3058;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63488;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65083;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19744;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25655;
UPDATE `creature_model_info` SET `BoundingRadius`=0.525, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=74532;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26347;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=48000;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65171;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26311;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65173;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65253;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28158;
UPDATE `creature_model_info` SET `BoundingRadius`=1.509789, `CombatReach`=1.875, `VerifiedBuild`=25996 WHERE `DisplayID`=67956;
UPDATE `creature_model_info` SET `BoundingRadius`=1.831403, `CombatReach`=1.729, `VerifiedBuild`=25996 WHERE `DisplayID`=73429;
UPDATE `creature_model_info` SET `BoundingRadius`=3.380034, `CombatReach`=2, `VerifiedBuild`=25996 WHERE `DisplayID`=69052;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3645831, `CombatReach`=1.575, `VerifiedBuild`=25996 WHERE `DisplayID`=72034;
UPDATE `creature_model_info` SET `BoundingRadius`=1.449397, `CombatReach`=1.8, `VerifiedBuild`=25996 WHERE `DisplayID`=67937;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67230;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70110;
UPDATE `creature_model_info` SET `BoundingRadius`=1.328614, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=67361;
UPDATE `creature_model_info` SET `BoundingRadius`=1.748563, `CombatReach`=0.6, `VerifiedBuild`=25996 WHERE `DisplayID`=67162;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3819442, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=72035;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42720;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42722;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65681;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3645831, `CombatReach`=1.575, `VerifiedBuild`=25996 WHERE `DisplayID`=72055;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65679;
UPDATE `creature_model_info` SET `BoundingRadius`=1.509789, `CombatReach`=1.875, `VerifiedBuild`=25996 WHERE `DisplayID`=67938;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65678;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65680;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=74255;
UPDATE `creature_model_info` SET `BoundingRadius`=2.03999, `CombatReach`=0.7, `VerifiedBuild`=25996 WHERE `DisplayID`=67161;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27853;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27852;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27854;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27961;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=67362;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72104;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4668, `CombatReach`=1.8, `VerifiedBuild`=25996 WHERE `DisplayID`=67016;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=64939;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=30869;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=67043;
UPDATE `creature_model_info` SET `BoundingRadius`=1.831403, `CombatReach`=1.729, `VerifiedBuild`=25996 WHERE `DisplayID`=76630;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=65975;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4513886, `CombatReach`=1.95, `VerifiedBuild`=25996 WHERE `DisplayID`=41568;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66672;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=61971;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=67760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=69542;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=66159;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69149;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69153;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72103;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71599;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65228;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=3714;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65242;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65412;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72095;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65354;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65370;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=23337;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65422;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4213, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=75912;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26442;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27960;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27959;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=32991;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=35818;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9200326, `VerifiedBuild`=25996 WHERE `DisplayID`=22003;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9200326, `VerifiedBuild`=25996 WHERE `DisplayID`=27019;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27616;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28151;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26437;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36906;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34635;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26396;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28143;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28161;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72465;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26395;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26330;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25674;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=36905;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=63038;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71597;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71088;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15180;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72344;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71596;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25673;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=33542;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=75130;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25882;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71019;
UPDATE `creature_model_info` SET `BoundingRadius`=1.335313, `VerifiedBuild`=25996 WHERE `DisplayID`=72945;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=75301;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27952;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27287;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28144;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28148;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71017;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74200;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74199;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=75302;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1646705, `VerifiedBuild`=25996 WHERE `DisplayID`=16910;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68483;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68484;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71942;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65477;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72078;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3817, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=78398;
UPDATE `creature_model_info` SET `BoundingRadius`=0.383, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=75049;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25955;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25875;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=72074;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=25996 WHERE `DisplayID`=75435;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28160;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28159;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=71943;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25983;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27915;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26299;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=74087;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26307;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26440;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25041;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65101;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=42872;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=68480;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=26441;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25605;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65244;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64759;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16883;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=52659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47997;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=59537;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=60156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=58822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=70638;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=56704;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25807;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28157;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=40155;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2954;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=69926;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2610845, `VerifiedBuild`=25996 WHERE `DisplayID`=27883;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65451;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27680;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25947;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25806;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65714;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64049;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17170;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=47999;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27822;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=25791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=34172;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27657;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5777;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=80;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=27719;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=65227;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28147;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=28156;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=58842;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=64048;

DELETE FROM `npc_vendor` WHERE (`entry`=97140 AND `item`=128609 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=128600 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=128602 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=128603 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=137850 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=137979 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=137976 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=137973 AND `ExtendedCost`=6066 AND `type`=1) OR (`entry`=97140 AND `item`=142120 AND `ExtendedCost`=6068 AND `type`=1) OR (`entry`=97140 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=97140 AND `item`=140575 AND `ExtendedCost`=6107 AND `type`=1) OR (`entry`=97140 AND `item`=139604 AND `ExtendedCost`=6050 AND `type`=1) OR (`entry`=97140 AND `item`=140325 AND `ExtendedCost`=6106 AND `type`=1) OR (`entry`=97140 AND `item`=136899 AND `ExtendedCost`=6108 AND `type`=1) OR (`entry`=97140 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=97140 AND `item`=139600 AND `ExtendedCost`=6051 AND `type`=1) OR (`entry`=97140 AND `item`=140324 AND `ExtendedCost`=6105 AND `type`=1) OR (`entry`=97140 AND `item`=140746 AND `ExtendedCost`=6109 AND `type`=1) OR (`entry`=97140 AND `item`=140015 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=97140 AND `item`=139979 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=97140 AND `item`=121738 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=97140 AND `item`=121736 AND `ExtendedCost`=6118 AND `type`=1) OR (`entry`=112392 AND `item`=143727 AND `ExtendedCost`=6183 AND `type`=1) OR (`entry`=112392 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139687 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139682 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139681 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139685 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139688 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=139684 AND `ExtendedCost`=6125 AND `type`=1) OR (`entry`=112392 AND `item`=124124 AND `ExtendedCost`=6214 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(97140, 46, 128609, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement de cape (Lien d'Intelligence)
(97140, 45, 128600, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de coup critique)
(97140, 44, 128602, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de Maîtrise)
(97140, 43, 128603, 0, 6066, 1, 0, 0, 25996), -- Formule : Enchantement d'anneau (Lien de polyvalence)
(97140, 42, 137850, 0, 6066, 1, 0, 0, 25996), -- Dessin : Pendentif en rubistre subtil
(97140, 41, 137979, 0, 6066, 1, 0, 0, 25996), -- Patron : Mules en soie tissée imprégnée
(97140, 40, 137976, 0, 6066, 1, 0, 0, 25996), -- Patron : Culotte en soie tissée imprégnée
(97140, 39, 137973, 0, 6066, 1, 0, 0, 25996), -- Patron : Brassards en soie tissée imprégnée
(97140, 38, 142120, 0, 6068, 1, 0, 0, 25996), -- Recette : Potion de puissance prolongée
(97140, 37, 139686, 0, 6125, 1, 0, 0, 25996), -- Espauliers de seigneur de bataille
(97140, 25, 140575, 0, 6107, 1, 0, 0, 25996), -- Tabard des Souffrenuit
(97140, 24, 139604, 0, 6050, 1, 0, 0, 25996), -- Pendentif d'améthyste trempé de mana
(97140, 23, 140325, 0, 6106, 1, 0, 0, 25996), -- Masque de fête artisanal
(97140, 22, 136899, 0, 6108, 1, 0, 0, 25996), -- Oeil éteint
(97140, 21, 139683, 0, 6125, 1, 0, 0, 25996), -- Gantelets de seigneur de bataille
(97140, 9, 139600, 0, 6051, 1, 0, 0, 25996), -- Cordelière tressée en fil de mana
(97140, 7, 140324, 0, 6105, 1, 0, 0, 25996), -- Balise de télémancie mobile
(97140, 6, 140746, 0, 6109, 1, 0, 0, 25996), -- Carte au trésor : Suramar
(97140, 5, 140015, 0, 6118, 1, 0, 0, 25996), -- Solerets gangrâme de récupération
(97140, 4, 139979, 0, 6118, 1, 0, 0, 25996), -- Souliers des Coursenuit
(97140, 3, 121738, 0, 6118, 1, 0, 0, 25996), -- Bottes de réfugié de Ferbois
(97140, 2, 121736, 0, 6118, 1, 0, 0, 25996), -- Mules « glissantes » sacrenuit
(112392, 16, 143727, 0, 6183, 1, 0, 0, 25996), -- Salut de champion
(112392, 12, 139686, 0, 6125, 1, 0, 0, 25996), -- Espauliers de seigneur de bataille
(112392, 11, 139687, 0, 6125, 1, 0, 0, 25996), -- Ceinturon de seigneur de bataille
(112392, 10, 139682, 0, 6125, 1, 43054, 0, 25996), -- Bottes de guerre de seigneur de bataille
(112392, 9, 139681, 0, 6125, 1, 43118, 0, 25996), -- Pansière de seigneur de bataille
(112392, 8, 139685, 0, 6125, 1, 43111, 0, 25996), -- Cuissards de seigneur de bataille
(112392, 7, 139683, 0, 6125, 1, 0, 0, 25996), -- Gantelets de seigneur de bataille
(112392, 6, 139688, 0, 6125, 1, 43117, 0, 25996), -- Garde-poignets de seigneur de bataille
(112392, 5, 139684, 0, 6125, 1, 0, 0, 25996), -- Grand heaume de seigneur de bataille
(112392, 1, 124124, 0, 6214, 1, 0, 0, 25996); -- Sang de Sargeras

UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=97140 AND `item`=140218 AND `ExtendedCost`=0 AND `type`=1); -- Faveur du cherche-mana
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Charbon
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur élémentaire
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur puissant
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Catalyseur léger
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Marteau de forgeron
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=25996 WHERE (`entry`=114887 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Pioche de mineur
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=97140 AND `item`=140218 AND `ExtendedCost`=0 AND `type`=1); -- Faveur du cherche-mana
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=97140 AND `item`=140218 AND `ExtendedCost`=0 AND `type`=1); -- Faveur du cherche-mana
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=25996 WHERE (`entry`=97140 AND `item`=140218 AND `ExtendedCost`=0 AND `type`=1); -- Faveur du cherche-mana
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140985 AND `ExtendedCost`=6102 AND `type`=1); -- Renfort d'armure supérieur de seigneur de bataille
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140946 AND `ExtendedCost`=6101 AND `type`=1); -- Renfort d'armure de seigneur de bataille
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140984 AND `ExtendedCost`=5952 AND `type`=1); -- Renfort d'armure inférieur de seigneur de bataille
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140537 AND `ExtendedCost`=0 AND `type`=1); -- Rempart du Séjour céleste
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140557 AND `ExtendedCost`=0 AND `type`=1); -- Prestelame du Séjour céleste
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=25996 WHERE (`entry`=112392 AND `item`=140559 AND `ExtendedCost`=0 AND `type`=1); -- Claymore du Séjour céleste

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=101116 AND `ID`=1) OR (`CreatureID`=115469 AND `ID`=1) OR (`CreatureID`=116421 AND `ID`=1) OR (`CreatureID`=115480 AND `ID`=1) OR (`CreatureID`=115519 AND `ID`=1) OR (`CreatureID`=114924 AND `ID`=1) OR (`CreatureID`=114927 AND `ID`=1) OR (`CreatureID`=114926 AND `ID`=1) OR (`CreatureID`=115526 AND `ID`=1) OR (`CreatureID`=116050 AND `ID`=1) OR (`CreatureID`=114866 AND `ID`=1) OR (`CreatureID`=114880 AND `ID`=1) OR (`CreatureID`=114929 AND `ID`=1) OR (`CreatureID`=115381 AND `ID`=1) OR (`CreatureID`=114995 AND `ID`=1) OR (`CreatureID`=115926 AND `ID`=1) OR (`CreatureID`=114883 AND `ID`=1) OR (`CreatureID`=114897 AND `ID`=1) OR (`CreatureID`=114885 AND `ID`=1) OR (`CreatureID`=114887 AND `ID`=1) OR (`CreatureID`=114841 AND `ID`=1) OR (`CreatureID`=108390 AND `ID`=1) OR (`CreatureID`=99482 AND `ID`=1) OR (`CreatureID`=98312 AND `ID`=1) OR (`CreatureID`=99213 AND `ID`=1) OR (`CreatureID`=99267 AND `ID`=1) OR (`CreatureID`=115684 AND `ID`=1) OR (`CreatureID`=118506 AND `ID`=1) OR (`CreatureID`=119226 AND `ID`=1) OR (`CreatureID`=106459 AND `ID`=1) OR (`CreatureID`=110437 AND `ID`=1) OR (`CreatureID`=120413 AND `ID`=1) OR (`CreatureID`=120412 AND `ID`=1) OR (`CreatureID`=120415 AND `ID`=1) OR (`CreatureID`=120420 AND `ID`=1) OR (`CreatureID`=120423 AND `ID`=1) OR (`CreatureID`=120422 AND `ID`=1) OR (`CreatureID`=120417 AND `ID`=1) OR (`CreatureID`=120416 AND `ID`=1) OR (`CreatureID`=120419 AND `ID`=1) OR (`CreatureID`=120687 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(101116, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Warpcaster Thwen
(115469, 1, 140775, 0, 0, 0, 0, 0, 0, 0, 0), -- Orlis
(116421, 1, 133175, 0, 0, 0, 0, 0, 0, 0, 0), -- Ley Line Channeler
(115480, 1, 116375, 0, 0, 0, 0, 0, 0, 0, 0), -- Fel-Powered Sentinel
(115519, 1, 137257, 0, 0, 137257, 0, 0, 0, 0, 0), -- Felborne Spellbreaker
(114924, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Saberguard
(114927, 1, 132170, 0, 0, 132249, 0, 0, 0, 0, 0), -- Fist of the Duskwatch
(114926, 1, 40497, 0, 0, 0, 0, 0, 0, 0, 0), -- Arcane Sentinel
(115526, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Arcshaper Thorendis
(116050, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Duskwatch Conjurer
(114866, 1, 43619, 0, 0, 0, 0, 0, 0, 0, 0), -- Mage gardien du Concordat argenté
(114880, 1, 27405, 0, 0, 27406, 0, 0, 0, 0, 0), -- Chevalier de sang garde de l’aube
(114929, 1, 132170, 0, 0, 133174, 0, 0, 0, 0, 0), -- Duskwatch Defender
(115381, 1, 6976, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Rebel
(114995, 1, 43619, 0, 0, 0, 0, 0, 0, 0, 0), -- Mage de guerre du Concordat argenté
(115926, 1, 91793, 0, 0, 0, 0, 0, 13147, 0, 0), -- Sentinelle de Darnassus
(114883, 1, 29114, 0, 0, 0, 0, 0, 0, 0, 0), -- Grand Magister Rommath
(114897, 1, 91793, 0, 0, 0, 0, 0, 13147, 0, 0), -- Sentinelle de Darnassus
(114885, 1, 35117, 0, 0, 0, 0, 0, 34280, 0, 0), -- Dawnseeker Guardian
(114887, 1, 5956, 0, 0, 0, 0, 0, 0, 0, 0), -- Lanesh the Steelweaver
(114841, 1, 49767, 0, 0, 0, 0, 0, 0, 0, 0), -- Dame Liadrin
(108390, 1, 0, 0, 0, 0, 0, 0, 15460, 0, 0), -- Mr. Mrglglrm
(99482, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(98312, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- First Arcanist Thalyssra
(99213, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0), -- Erasmus Moonblade
(99267, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Nightborne Scion
(115684, 1, 43617, 0, 0, 0, 0, 0, 0, 0, 0), -- Garde-paix du Kirin Tor
(118506, 1, 45727, 0, 0, 94256, 0, 0, 0, 0, 0), -- Sorcelame saccage-soleil
(119226, 1, 29156, 0, 0, 117413, 0, 0, 0, 0, 0), -- Danath Trollbane
(106459, 1, 137263, 0, 0, 140748, 0, 0, 0, 0, 0), -- Capitaine Hjalmar Stahlstrom
(110437, 1, 108282, 0, 0, 126883, 0, 0, 0, 0, 0), -- Haklang Ulfsson
(120413, 1, 118803, 0, 0, 0, 0, 0, 0, 0, 0), -- Rensar Greathoof
(120412, 1, 1908, 0, 0, 0, 0, 0, 0, 0, 0), -- Farseer Nobundo
(120415, 1, 50252, 0, 0, 0, 0, 0, 0, 0, 0), -- Highlord Darion Mograine
(120420, 1, 79719, 0, 0, 0, 0, 0, 0, 0, 0), -- Iron-Body Ponshu
(120423, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0), -- Emmarel Shadewarden
(120422, 1, 49767, 0, 0, 0, 0, 0, 0, 0, 0), -- Lady Liadrin
(120417, 1, 111743, 0, 0, 0, 0, 0, 0, 0, 0), -- Meryl Felstorm
(120416, 1, 5285, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Jorach Ravenholdt
(120419, 1, 128358, 0, 0, 128372, 0, 0, 0, 0, 0), -- Kor'vas Bloodthorn
(120687, 1, 115865, 0, 0, 0, 0, 0, 0, 0, 0); -- Violet Shadowmend

UPDATE `creature_equip_template` SET `ItemID2`=140748, `ItemID3`=0 WHERE (`CreatureID`=114558 AND `ID`=1); -- Greater Sparring Partner
UPDATE `creature_equip_template` SET `ItemID2`=140748, `ItemID3`=0 WHERE (`CreatureID`=96572 AND `ID`=1); -- Valarjar forge-foudre

DELETE FROM `gossip_menu` WHERE (`MenuId`=18748 AND `TextId`=27380) OR (`MenuId`=19960 AND `TextId`=28198) OR (`MenuId`=19960 AND `TextId`=28199) OR (`MenuId`=19217 AND `TextId`=28178) OR (`MenuId`=20589 AND `TextId`=30862) OR (`MenuId`=20674 AND `TextId`=31007) OR (`MenuId`=20545 AND `TextId`=30763) OR (`MenuId`=20673 AND `TextId`=31003) OR (`MenuId`=19828 AND `TextId`=29436) OR (`MenuId`=18558 AND `TextId`=26867) OR (`MenuId`=20578 AND `TextId`=30840) OR (`MenuId`=19958 AND `TextId`=29678) OR (`MenuId`=19646 AND `TextId`=25240) OR (`MenuId`=20375 AND `TextId`=30468) OR (`MenuId`=20007 AND `TextId`=29823) OR (`MenuId`=18747 AND `TextId`=27251) OR (`MenuId`=20344 AND `TextId`=30432);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(18748, 27380), -- 97140 (First Arcanist Thalyssra)
(19960, 28198), -- 98548 (Chief Telemancer Oculeth)
(19960, 28199), -- 98548 (Chief Telemancer Oculeth)
(19217, 28178), -- 101782 (Chief Telemancer Oculeth)
(20589, 30862), -- Garde-paix du Kirin Tor
(20674, 31007), -- 114883 (Grand Magister Rommath)
(20545, 30763), -- Dame Liadrin
(20673, 31003), -- 115498 (Lothrius Mooncaller)
(19828, 29436), -- 107302 (Pearlhunter Phin)
(18558, 26867), -- 90417 (Archmage Khadgar)
(20578, 30840), -- 90418 (Archmage Modera)
(19958, 29678), -- 96586 (Master Smith Helgar)
(19646, 25240), -- 107994 (Einar the Runecaster)
(20375, 30468), -- 112392 (Quartermaster Durnolf)
(20007, 29823), -- Capitaine Hjalmar Stahlstrom
(18747, 27251), -- 97389 (Eye of Odyn)
(20344, 30432); -- 110437 (Haklang Ulfsson)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=19828 AND `OptionIndex`=3) OR (`MenuId`=19828 AND `OptionIndex`=2) OR (`MenuId`=19828 AND `OptionIndex`=1) OR (`MenuId`=19828 AND `OptionIndex`=0) OR (`MenuId`=20375 AND `OptionIndex`=0) OR (`MenuId`=20007 AND `OptionIndex`=0) OR (`MenuId`=20344 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(19828, 3, 0, '<Show Phin the fine sand.>', 113713),
(19828, 2, 0, '<Show Phin the crab oil.>', 113711),
(19828, 1, 0, '<Show Phin the crab claw.>', 113712),
(19828, 0, 0, '<Show Phin the crab shell.>', 113705),
(20375, 0, 1, 'Let''s see what you have.', 122256), -- OptionBroadcastTextID: 11820 - 17411 - 92547 - 122256 - 122264 - 122277 - 122283 - 122291 - 122296 - 122299 - 122301 - 122309
(20007, 0, 28, 'The Valarjar await.', 117226),
(20344, 0, 28, 'Place a work order for Champion armaments.', 122236); -- OptionBroadcastTextID: 122236 - 122241

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=118613 WHERE (`MenuId`=19960 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=118613 WHERE (`MenuId`=19960 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=118613 WHERE (`MenuId`=19960 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=122363 WHERE (`MenuId`=18748 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `OptionText`='Show me what missions you have prepared.' WHERE (`MenuId`=18747 AND `OptionIndex`=0);

DELETE FROM `creature_template` WHERE `entry`=103976;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`, `VerifiedBuild`) VALUES
(103976, 0, 0, 68439, 0, 0, 0, 'The Postmaster', NULL, NULL, NULL, NULL, 6, 0, 0, 1, 0, 7, 0, 0, 1, 1, 0, 0, 0, 110, 110, 35, 3, 1, 1.142857, 2000, 2000, 8, 33536, 2048, 0, 0, 0, 1, 25996); -- The Postmaster

UPDATE `creature_template` SET `gossip_menu_id`=19960, `npcflag`=3, `speed_run`=1.142857 WHERE `entry`=98548; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102017; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102142; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101782; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113571; -- Buried Hoarder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=101116; -- Warpcaster Thwen
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=116069; -- Beam Target Stalker
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=570720256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=111921; -- Buried Exile
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116626; -- Warp Aberration
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=116622; -- Unstable Rift
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116623; -- Warp Spark
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101110; -- Warp Ray
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101581; -- Tanzanite Borer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101577; -- Tanzanite Shatterer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113417; -- Swarming Spiderling
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=117437; -- Ligne tellurique
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115469; -- Orlis
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2820, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=116421; -- Ley Line Channeler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108528; -- Vil rôdeur
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115480; -- Fel-Powered Sentinel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112370; -- Reclus des ruines
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115519; -- Felborne Spellbreaker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=114924; -- Duskwatch Saberguard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101499; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112948; -- Glitterpool Snapper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=111770; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2847, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=113483; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105650; -- Confined Raptor
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105640; -- Bound Goat
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105645; -- Penned Turtle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=2 WHERE `entry`=116063; -- Animated Spellbook
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112421; -- Moist Owlette
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113936; -- Rudaux
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2886, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=114927; -- Fist of the Duskwatch
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=114926; -- Arcane Sentinel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=115430; -- Charged Arcshaper Staff
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=103005; -- Bowl of Fruit
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480, `HoverHeight`=3 WHERE `entry`=115526; -- Arcshaper Thorendis
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2821, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=116050; -- Duskwatch Conjurer
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105232; -- Oldus
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=102960; -- Glitterpool Heron
UPDATE `creature_template` SET `faction`=188, `HoverHeight`=2 WHERE `entry`=65209; -- Frôleur aquatique dansant
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570721024, `unit_flags2`=67110913, `unit_flags3`=8192 WHERE `entry`=115261; -- Disabled Construct
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `unit_flags2`=2048 WHERE `entry`=88989; -- Violet Firefly
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=102415; -- Suramar Skyhunter
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=113205; -- Leyscarred Stag
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112825; -- Shieldscar Stag
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112827; -- Shieldscar Doe
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2362, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=114866; -- Mage gardien du Concordat argenté
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=114880; -- Chevalier de sang garde de l’aube
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=114929; -- Duskwatch Defender
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2362, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=114995; -- Mage de guerre du Concordat argenté
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107567; -- Suramar Shieldguard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=534, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33600, `unit_flags2`=51200, `unit_flags3`=1 WHERE `entry`=114838; -- Tyrande Murmevent
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2713, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=115926; -- Sentinelle de Darnassus
UPDATE `creature_template` SET `gossip_menu_id`=20674, `minlevel`=113, `maxlevel`=113, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=18432 WHERE `entry`=114883; -- Grand Magister Rommath
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2713, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=114897; -- Sentinelle de Darnassus
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114885; -- Dawnseeker Guardian
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2361, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=114887; -- Lanesh the Steelweaver
UPDATE `creature_template` SET `gossip_menu_id`=20545, `minlevel`=110, `maxlevel`=110, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=114841; -- Dame Liadrin
UPDATE `creature_template` SET `minlevel`=85, `speed_run`=1, `unit_flags2`=67108864 WHERE `entry`=69759; -- Defense Crystal
UPDATE `creature_template` SET `faction`=7, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=115605; -- Chicken Escapee
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2713, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=2131968 WHERE `entry`=114849; -- Ancient Defender
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101848; -- Absolon
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=111513; -- Leyweaver Ke'lorin
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=99793; -- Leyscale Manalisk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=101900; -- Sinister Shrieker
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113123; -- Leytouched Cliffquill
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108536; -- Monstrous Leycrawler
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98699; -- Webbed Husk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108878; -- Mrs. Mrglglrm
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=110826; -- Bécasse côtière
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=88978; -- Kelp Scuttler
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113162; -- Chasseuse fal’dorei
UPDATE `creature_template` SET `minlevel`=98, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=110824; -- Griffe-des-marées
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=100846; -- Leytusk
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67127296 WHERE `entry`=90232; -- Faille déliée
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=106873; -- Font of Arcane Energy
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=90242; -- Wyrm de faille
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108521; -- Skrog des mers
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108535; -- Marsh Hydra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108779; -- Mrs. Mrglglrm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=0, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108389; -- Mrgrlilgrl
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=108390; -- Mr. Mrglglrm
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=112802; -- Mar’tura
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=106913; -- Font of Arcane Energy
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107302; -- Pearlhunter Phin
UPDATE `creature_template` SET `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=107303; -- Crab
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=112367; -- Leyscar Runt
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=104618; -- Theryn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=109803; -- Carapateur entaillurique
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=89380; -- Coastal Sandpiper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113189; -- Coastal Snapper
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113127; -- Cliffwing Skytalon
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=100058; -- Arcanist Kel'danath
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113122; -- Suramar Cliffquill
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=101825; -- Nightborne Enforcer
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=101821; -- Nightborne Warpcaster
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=105785; -- Fal'dorei Conjurer
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=99792; -- Plaie-des-elfes
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105885; -- Hungering Husk
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105486; -- Withered Droll
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=105625; -- Fal'dorei Weaver
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags2`=133120 WHERE `entry`=109188; -- Withered Test Subject
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99779; -- Stonespine Gazer
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=0 WHERE `entry`=110577; -- Oreth the Vile
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=8192 WHERE `entry`=110576; -- Oreth's Victim
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=105728; -- Scythemaster Cil'raman
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=107974; -- Kill Credit Orathiss Scene 1
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=105686; -- Fal'dorei Webspinner
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105623; -- Trancheur fal’dorei
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114793; -- Trancheur fal’dorei
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105685; -- Fal'dorei Broodlord
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=106276; -- Fal'dorei Web Target Stalker
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=105756; -- Jeune araignée de ligne tellurique
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109054; -- Shal’an
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=103811; -- Starclutch Hatchling
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104224; -- Grogneur de Suramar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=94, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=100059; -- Arcane Ward
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103805; -- Sablehorn Doe
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=103540; -- Starclutch Screecher
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=108942; -- Withered Feaster
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=109022; -- Arcane Ward
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1965, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=100014; -- Carcasse flétrie
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=73543; -- Phalène cerclefeu
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=63062; -- Raton voleur
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113126; -- Meredil Lockjaw
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113184; -- Cunning Bushtail
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=111675; -- Ancient Cloudwing
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113190; -- Meredil Thrashmaw
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=106869; -- Snarler Pup
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=111712; -- Withered WQ Turn In Bunny
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=114720; -- Font of Arcane Energy
UPDATE `creature_template` SET `gossip_menu_id`=18748, `speed_run`=1.142857 WHERE `entry`=97140; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags3`=1 WHERE `entry`=99539; -- Eternal Tether
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=2147516416, `unit_flags2`=2048 WHERE `entry`=99524; -- Keeper Selentia
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=99088; -- Ancient Keeper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=18432, `unit_flags3`=1 WHERE `entry`=99482; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=98967; -- Barrier Bunny
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98946; -- Withered Thirster
UPDATE `creature_template` SET `npcflag`=2, `speed_run`=1.142857, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=113985; -- Elieth
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=51200, `unit_flags3`=1, `VehicleId`=915 WHERE `entry`=98312; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=98943; -- Withered
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=99213; -- Erasmus Moonblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=114071; -- Pulsing Arcane Echo
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=104894; -- Moonlight Cub
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=114070; -- Blinking Arcane Echo
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112627; -- Curious Manasaber
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2799, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=98209; -- Echo of First Arcanist Thalyssra
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=570721024, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=98555; -- Withered Shambler
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=100169; -- Faint Arcane Echo
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1693, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=99267; -- Nightborne Scion
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=114931; -- Rebelle souffrenuit
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2884, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115381; -- Nightborne Rebel
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=115500; -- Dusktalon
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=114865; -- Magus garde de l’aube
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=115924; -- Magus garde de l’aube
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=73828; -- Phalène cerclefeu
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2714, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=114845; -- Démolisseur ignétoile
UPDATE `creature_template` SET `gossip_menu_id`=20589, `minlevel`=0, `maxlevel`=0, `faction`=2008, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=115684; -- Garde-paix du Kirin Tor
UPDATE `creature_template` SET `gossip_menu_id`=20673, `minlevel`=110, `maxlevel`=110, `faction`=2828, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=33554432, `unit_flags3`=1 WHERE `entry`=115498; -- Lothrius Mooncaller
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112336; -- Meredil Glider
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=99749; -- Moonlight Hunter
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048 WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=105339; -- Shadowgore Darkcaster
UPDATE `creature_template` SET `minlevel`=98, `unit_flags3`=8192 WHERE `entry`=105332; -- Desmond Gravesorrow
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=93542; -- Tanithria
UPDATE `creature_template` SET `npcflag`=82 WHERE `entry`=93525; -- Ainderu Summerleaf
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=2010, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122926; -- Chromie
UPDATE `creature_template` SET `gossip_menu_id`=18558, `speed_run`=1.142857 WHERE `entry`=90417; -- Archmage Khadgar
UPDATE `creature_template` SET `gossip_menu_id`=20578, `npcflag`=3 WHERE `entry`=90418; -- Archmage Modera
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=118506; -- Sorcelame saccage-soleil
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33280, `unit_flags2`=67110912 WHERE `entry`=98266; -- Arcane Anomaly
UPDATE `creature_template` SET `minlevel`=98, `speed_run`=1.142857 WHERE `entry`=105723; -- Vicktor Ebonfall
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110 WHERE `entry`=110738; -- Kaela Noirmédaille
UPDATE `creature_template` SET `minlevel`=98, `unit_flags3`=1 WHERE `entry`=105564; -- Injured Kirin Tor Guardian
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=93527; -- Timothy Jones
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=92195; -- Professor Pallin
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=79861; -- Generic Bunny
UPDATE `creature_template` SET `npcflag`=268435585 WHERE `entry`=99867; -- Warpweaver Tuviss
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=93531; -- Enchanter Nalthanis
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=119436; -- NO ADDRESS
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=119396; -- RETURN TO SENDER
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=119438; -- BAD HANDWRITING
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=119437; -- NOT ENOUGH STAMPS
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=104230; -- Postier-lémentaire
UPDATE `creature_template` SET `npcflag`=17716740096, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=85290; -- Vaultkeeper Sarniv
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=99349; -- Robert "Chance" Llore
UPDATE `creature_template` SET `unit_class`=8 WHERE `entry`=113785; -- Hugh Mann
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=108792; -- Jenny McCree
UPDATE `creature_template` SET `npcflag`=130 WHERE `entry`=106930; -- Lieutenant Surtees
UPDATE `creature_template` SET `npcflag`=17179869313, `unit_flags3`=32 WHERE `entry`=96483; -- Jepetto Joybuzz
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=67110912, `VehicleId`=2587 WHERE `entry`=68238; -- Carousel Rocket
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1732, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97501; -- Linzi Rirouge
UPDATE `creature_template` SET `npcflag`=17179873408, `unit_flags3`=32 WHERE `entry`=97012; -- Abra Cadabra
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=67110912, `VehicleId`=2587 WHERE `entry`=68239; -- Carousel Wyvern
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=67110912, `VehicleId`=2587 WHERE `entry`=68232; -- Carousel Gryphon
UPDATE `creature_template` SET `npcflag`=4225 WHERE `entry`=97331; -- Icks
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2713, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33088, `unit_flags2`=2048 WHERE `entry`=119226; -- Danath Trollbane
UPDATE `creature_template` SET `npcflag`=17179869313, `unit_flags3`=32 WHERE `entry`=97213; -- Windle Sparkshine
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=103092; -- Le grand Akazamzarak
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=35845; -- Dave's Industrial Light and Magic Bunny (Small)(Sessile)
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103116; -- Dalaran Citizen
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103119; -- Dalaran Citizen
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103118; -- Dalaran Citizen
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=103120; -- Dalaran Citizen
UPDATE `creature_template` SET `npcflag`=17179873408, `unit_flags3`=32 WHERE `entry`=97011; -- Valaden Silverblade
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=117448; -- Cinnamon
UPDATE `creature_template` SET `gossip_menu_id`=19958, `speed_run`=1.142857 WHERE `entry`=96586; -- Master Smith Helgar
UPDATE `creature_template` SET `npcflag`=1099511627779, `speed_run`=1.142857 WHERE `entry`=111741; -- Fjornson Stonecarver
UPDATE `creature_template` SET `gossip_menu_id`=18747, `minlevel`=100, `maxlevel`=100, `faction`=190, `npcflag`=137438953473, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=97389; -- Eye of Odyn
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=100635; -- Skyseer Ghrent
UPDATE `creature_template` SET `gossip_menu_id`=20007, `minlevel`=110, `maxlevel`=110, `npcflag`=1168231104513, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=106459; -- Capitaine Hjalmar Stahlstrom
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=107494; -- Maîtresse de l’arène val’kyr
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112577; -- Weaponmaster Asvard
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=96469; -- Odyn
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=114558; -- Greater Sparring Partner
UPDATE `creature_template` SET `gossip_menu_id`=19646, `minlevel`=98, `maxlevel`=110, `npcflag`=2199023255553, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=107994; -- Einar the Runecaster
UPDATE `creature_template` SET `gossip_menu_id`=20375, `minlevel`=98 WHERE `entry`=112392; -- Quartermaster Durnolf
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=96572; -- Valarjar forge-foudre
UPDATE `creature_template` SET `gossip_menu_id`=20344, `minlevel`=110, `maxlevel`=110, `npcflag`=1168231104515, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `minlevel`=98, `maxlevel`=110, `speed_walk`=1.2, `speed_run`=0.7142857, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=113267; -- Aspirant valarjar
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116609; -- Battlelord's Armor
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93819; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120413; -- Rensar Greathoof
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120412; -- Farseer Nobundo
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `speed_run`=1.385714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120415; -- Highlord Darion Mograine
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=120424; -- Alonsus Faol
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120418; -- Havi
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120421; -- Ritssyn Flamescowl
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=120420; -- Iron-Body Ponshu
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120423; -- Emmarel Shadewarden
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120422; -- Lady Liadrin
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120417; -- Meryl Felstorm
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120416; -- Lord Jorach Ravenholdt
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120419; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97490; -- Halga Char-d’acier
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=2007, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124678; -- Dalaran Citizen
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97512; -- Chasseresse-dimensionnelle Kula
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `npcflag`=3, `unit_flags2`=2099200 WHERE `entry`=32725; -- Warmage Silva
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=68, `npcflag`=130, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120687; -- Violet Shadowmend
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=96797; -- Nargut
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=96798; -- Rhukah
UPDATE `creature_template` SET `npcflag`=640 WHERE `entry`=92936; -- Aimee
UPDATE `creature_template` SET `npcflag`=17179869313, `unit_flags3`=32 WHERE `entry`=96812; -- Elizabeth Ross
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=112847; -- Bewdley
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=113775; -- Punchy Lou
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116420; -- Glowing Blue Gem
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116419; -- Glowing Green Gem
UPDATE `creature_template` SET `unit_flags`=33587456 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=116408; -- Glowing Red Gem
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags2`=2048 WHERE `entry`=125261; -- Bran Buckbeard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=83, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=119088; -- Anebria Sunwine
UPDATE `creature_template` SET `faction`=2156, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=119642; -- Reliquary Pick
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=109, `speed_run`=1.142857 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=104, `speed_run`=1.142857 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `speed_walk`=1 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=103, `maxlevel`=103 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=108628; -- Armond Thaco
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=98 WHERE `entry`=112079; -- Pèlerin cramoisi
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105, `faction`=1732, `npcflag`=17179869184, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=97489; -- Garl Mornegrise

SET @GROUP_ID := 0;
SET @ID := 0;

REPLACE INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(90417, @GROUP_ID+0, @ID+0, 'Nobody touch it! Not until our guest arrives.', 12, 0, 100, 1, 0, 67263, 101006, 'Archmage Khadgar to Player'),
(90417, @GROUP_ID+1, @ID+0, 'Any disturbance should catalyze the sequence. Just, uh, give it a poke or something.', 12, 0, 100, 1, 0, 67264, 100058, 'Archmage Khadgar to Player'),
(90417, @GROUP_ID+2, @ID+0, 'Be careful, champion. The land of Suramar has been wild for ten thousand years.', 12, 0, 100, 0, 0, 67271, 100062, 'Archmage Khadgar to Player'),
(97140, @GROUP_ID+0, @ID+0, 'I shall prepare a holding area for the subjects while you are away.', 12, 0, 100, 396, 0, 67262, 107469, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+1, @ID+0, 'Oculeth!', 12, 0, 100, 0, 0, 67243, 100883, 'First Arcanist Thalyssra to Player'),
(97140, @GROUP_ID+2, @ID+0, 'He is withering...', 12, 0, 100, 0, 0, 67244, 104371, 'First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+0, @ID+0, 'Make haste for Suramar. You may be our last hope.', 12, 0, 100, 25, 0, 67269, 100096, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+1, @ID+0, 'Ith''nala kanesh!', 12, 0, 100, 0, 0, 67270, 100256, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+2, @ID+0, 'I hope someone out there is listening...', 12, 0, 100, 0, 0, 67540, 100262, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+3, @ID+0, '%s winces in pain and holds her side.', 16, 0, 100, 0, 0, 0, 100097, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+4, @ID+0, 'Ngh... need to keep moving.', 12, 0, 100, 0, 0, 67541, 100265, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+5, @ID+0, 'Rath!', 12, 0, 100, 0, 0, 67542, 100916, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+6, @ID+0, 'Withered... I must be getting close.', 12, 0, 100, 0, 0, 67543, 100268, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+7, @ID+0, 'Rath-domaas!', 12, 0, 100, 0, 0, 67544, 100002, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+8, @ID+0, 'Stand down, Erasmus! Can you not see that Elisande has forsaken us?!', 12, 0, 100, 5, 0, 67545, 100279, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+9, @ID+0, 'An''ah!', 12, 0, 100, 0, 0, 67546, 100915, 'Echo of First Arcanist Thalyssra to Player'),
(98209, @GROUP_ID+10, @ID+0, 'That will buy me some time...', 12, 0, 100, 0, 0, 67547, 100282, 'Echo of First Arcanist Thalyssra to Player'),
(98266, @GROUP_ID+0, @ID+0, 'Ith''el kanesh!', 12, 0, 100, 0, 0, 67265, 100088, 'Echo of First Arcanist Thalyssra to Player'),
(98266, @GROUP_ID+1, @ID+0, 'I am Thalyssra of the shal''dorei... the Nightborne. First Arcanist in the court of Suramar.', 12, 0, 100, 1, 0, 67266, 100089, 'Echo of First Arcanist Thalyssra to Player'),
(98266, @GROUP_ID+2, @ID+0, 'My people have made a dire pact. One that spells doom for this world.', 12, 0, 100, 603, 0, 67267, 100091, 'Echo of First Arcanist Thalyssra to Player'),
(98266, @GROUP_ID+3, @ID+0, 'Time is short. If you have found this message, you are capable of finding me as well.', 12, 0, 100, 1, 0, 67268, 100094, 'Echo of First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+0, @ID+0, 'Rath-anu''tanos!', 12, 0, 100, 0, 0, 67511, 100280, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+1, @ID+0, 'We must take care. The withered ones prowl this area, ravenous in their hunger for magic and flesh alike.', 12, 0, 100, 0, 0, 67512, 114540, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+2, @ID+0, 'Such is the fate of nightborne who cannot drink of the Nightwell.', 12, 0, 100, 0, 0, 67513, 100338, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+3, @ID+0, 'This is my fate as well... unless...', 12, 0, 100, 0, 0, 67514, 101935, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+4, @ID+0, 'Look out!', 12, 0, 100, 0, 0, 67515, 107590, 'First Arcanist Thalyssra to Player'), -- BroadcastTextID: 14999 - 25299 - 27921 - 39797 - 40269 - 54489 - 56206 - 58002 - 78487 - 87001 - 91594 - 99114 - 107590 - 114489
(98312, @GROUP_ID+5, @ID+0, 'E''rath omnas!', 12, 0, 100, 0, 0, 67516, 100340, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+6, @ID+0, 'Get them off the barrier!', 12, 0, 100, 0, 0, 67525, 100544, 'First Arcanist Thalyssra to Withered Thirster'),
(98312, @GROUP_ID+7, @ID+0, 'My strength is fading... we must find shelter...', 12, 0, 100, 0, 0, 67517, 100339, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+8, @ID+0, '<cough> I... need a moment...', 12, 0, 100, 0, 0, 67518, 100588, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+9, @ID+0, 'The barrier is being drained!', 12, 0, 100, 0, 0, 67524, 100543, 'First Arcanist Thalyssra to Withered Thirster'),
(98312, @GROUP_ID+10, @ID+0, 'There are so many...', 12, 0, 100, 0, 0, 67519, 100589, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+11, @ID+0, 'Strange. Why do they not follow?', 12, 0, 100, 0, 0, 67520, 100590, 'First Arcanist Thalyssra to Player'),
(98312, @GROUP_ID+12, @ID+0, '<cough> I need to rest...', 12, 0, 100, 0, 0, 67521, 100591, 'First Arcanist Thalyssra to Player'),
(98548, @GROUP_ID+0, @ID+0, 'Blech. How did we live before the Nightwell?', 12, 0, 100, 0, 0, 71462, 121592, 'Chief Telemancer Oculeth to Player'), -- BroadcastTextID: 99809 - 121592
(99213, @GROUP_ID+0, @ID+0, 'Die!', 14, 0, 100, 0, 0, 67547, 100918, 'Erasmus Moonblade to Erasmus Moonblade'), -- BroadcastTextID: 15042 - 24874 - 50341 - 52152 - 52213 - 53514 - 58394 - 64538 - 64553 - 64561 - 72512 - 80033 - 81021 - 83278 - 85147 - 87846 - 91001 - 94016 - 94096 - 94059 - 100918 - 101696 - 117343
(99213, @GROUP_ID+1, @ID+0, 'Gah! A time stop spell... She will pay for that!', 12, 0, 100, 0, 0, 67549, 100919, 'Erasmus Moonblade to Erasmus Moonblade'),
(99213, @GROUP_ID+2, @ID+0, 'This is not your business, outlander. Thalyssra has betrayed the Grand Magistrix and must be put down!', 12, 0, 100, 0, 0, 67550, 100921, 'Erasmus Moonblade'),
(99213, @GROUP_ID+3, @ID+0, 'Witness the power of the Nightborne!', 12, 0, 100, 0, 0, 67551, 100924, 'Erasmus Moonblade'),
(99213, @GROUP_ID+4, @ID+0, 'Who... are you?', 12, 0, 100, 0, 0, 67552, 100925, 'Erasmus Moonblade to Player'),
(99267, @GROUP_ID+0, @ID+0, 'She must have come this way. Keep looking!', 12, 0, 100, 1, 0, 67554, 100003, 'Nightborne Scion to Player'),
(99267, @GROUP_ID+1, @ID+0, 'The shal''dorei are... chosen...', 12, 0, 100, 0, 0, 66014, 116624, 'Nightborne Scion to Player'), -- BroadcastTextID: 116624 - 116710
(99267, @GROUP_ID+2, @ID+0, 'We have... failed.', 12, 0, 100, 0, 0, 65810, 116758, 'Nightborne Scion to Player'), -- BroadcastTextID: 116758 - 116789
(99524, @GROUP_ID+0, @ID+0, 'Selentia wails, calling forth ancient keepers!', 41, 0, 100, 463, 0, 53888, 101162, 'Keeper Selentia to Player'),
(99524, @GROUP_ID+1, @ID+0, 'The tethers have broken. Selentia is vulnerable!', 41, 0, 100, 0, 0, 0, 114593, 'Keeper Selentia to Eternal Tether'),
(101116, @GROUP_ID+0, @ID+0, 'My, my. You look rather gaunt, honored teacher. Are you eating enough? Ahahaha!', 12, 0, 100, 396, 0, 67293, 104159, 'Warpcaster Thwen to Player'),
(101116, @GROUP_ID+1, @ID+0, 'You should be proud! Your handiwork is going to help us reclaim every corner of our ancient lands.', 12, 0, 100, 397, 0, 67294, 104158, 'Warpcaster Thwen to Player'),
(101116, @GROUP_ID+2, @ID+0, 'Face it, old man. I have surpassed you.', 12, 0, 100, 0, 0, 67282, 104232, 'Warpcaster Thwen to Player'),
(101116, @GROUP_ID+3, @ID+0, 'My warp field is not working! Where have you taken us?!', 12, 0, 100, 0, 0, 67290, 104248, 'Warpcaster Thwen to Player'),
(101116, @GROUP_ID+4, @ID+0, 'No! This place... it must bend to my will!', 12, 0, 100, 0, 0, 67288, 104270, 'Warpcaster Thwen to Player'),
(101116, @GROUP_ID+5, @ID+0, 'An''ratha... an''tal-thandros!', 12, 0, 100, 0, 0, 67289, 104271, 'Warpcaster Thwen to Player'),
(101499, @GROUP_ID+0, @ID+0, 'That is far enough.', 12, 0, 100, 0, 0, 67418, 103939, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+1, @ID+0, 'Well, you are not from the palace... and you are no demon, at least not entirely.', 12, 0, 100, 274, 0, 67419, 103940, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+2, @ID+0, 'Identify yourself, before I teleport you to the depths of the Great Sea.', 12, 0, 100, 25, 0, 67420, 103943, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+3, @ID+0, 'What is this? A coin...', 12, 0, 100, 0, 0, 67421, 103949, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+4, @ID+0, 'The sign of the dusk lily... This is the First Arcanist''s seal! Is she alive?!', 12, 0, 100, 1, 0, 67422, 103950, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+5, @ID+0, 'Then there is still a chance... Come quickly! I need your help.', 12, 0, 100, 1, 0, 67423, 103969, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+6, @ID+0, 'Right. The trap.', 12, 0, 100, 1, 0, 67424, 103951, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+7, @ID+0, 'N''eth ana!', 12, 0, 100, 0, 0, 67425, 103967, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+8, @ID+0, 'The teleporter is just outside. Activate it first, then step on the pad.', 12, 0, 100, 0, 0, 67484, 103970, 'Chief Telemancer Oculeth to Player'),
(101499, @GROUP_ID+9, @ID+0, 'Go ahead, I am right behind you.', 12, 0, 100, 1, 0, 67287, 104149, 'Chief Telemancer Oculeth to Player'),
(101782, @GROUP_ID+0, @ID+0, 'Urgh!', 12, 0, 100, 482, 0, 67281, 104162, 'Chief Telemancer Oculeth to Player'), -- BroadcastTextID: 104162 - 126754
(101782, @GROUP_ID+1, @ID+0, 'Good trick... <cough> Warping the space around your body like that.', 12, 0, 100, 0, 0, 67283, 104233, 'Chief Telemancer Oculeth to Player'),
(101782, @GROUP_ID+2, @ID+0, 'But what if that space is already unstable?', 12, 0, 100, 0, 0, 67284, 104235, 'Chief Telemancer Oculeth to Player'),
(101782, @GROUP_ID+3, @ID+0, '<cough> Unstable... space...', 12, 0, 100, 0, 0, 67291, 104249, 'Chief Telemancer Oculeth to Player'),
(101782, @GROUP_ID+4, @ID+0, 'Thwen always took magic too lightly... She was a terrible student... <cough>', 12, 0, 100, 1, 0, 67285, 104268, 'Chief Telemancer Oculeth to Player'),
(101782, @GROUP_ID+5, @ID+0, 'I haven''t much left... <cough> I will get us as close as I can... Come close.', 12, 0, 100, 0, 0, 67286, 104269, 'Chief Telemancer Oculeth to Player'),
(101821, @GROUP_ID+0, @ID+0, 'My magic... defeated?', 12, 0, 100, 0, 0, 66016, 116433, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 102167 - 116433
(101821, @GROUP_ID+1, @ID+0, 'Your age has ended!', 12, 0, 100, 0, 0, 65799, 116705, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 100931 - 116705
(101821, @GROUP_ID+2, @ID+0, 'Arash-falas...', 12, 0, 100, 0, 0, 65811, 116791, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 102165 - 116431 - 116760 - 116771 - 116781 - 116791
(101821, @GROUP_ID+3, @ID+0, 'Tor''theras falar!', 12, 0, 100, 0, 0, 66017, 116790, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 102166 - 116432 - 116759 - 116770 - 116780 - 116790
(101821, @GROUP_ID+4, @ID+0, 'None may challenge us!', 12, 0, 100, 0, 0, 66026, 116701, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 116687 - 116701
(101821, @GROUP_ID+5, @ID+0, 'No! It is not my time....', 12, 0, 100, 0, 0, 66015, 116778, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 116768 - 116778
(101821, @GROUP_ID+6, @ID+0, 'Anath''ashar!', 12, 0, 100, 0, 0, 65818, 116709, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 100935 - 116681 - 116688 - 116695 - 116702 - 116709
(101821, @GROUP_ID+7, @ID+0, 'Your death is fated!', 12, 0, 100, 0, 0, 65814, 116703, 'Nightborne Warpcaster to Player'), -- BroadcastTextID: 100929 - 116703
(101825, @GROUP_ID+0, @ID+0, 'Feel the might of the shal''dorei!', 12, 0, 100, 0, 0, 65905, 116690, 'Nightborne Enforcer to Player'), -- BroadcastTextID: 116676 - 116690
(101848, @GROUP_ID+0, @ID+0, 'The darkness lifts... thank you.', 12, 0, 100, 0, 0, 0, 104167, 'Absolon to Player'),
(101848, @GROUP_ID+1, @ID+0, 'I left the City to find my daughter. She was one of those who dared speak against Elisande...', 12, 0, 100, 0, 0, 0, 119837, 'Absolon to Player'),
(101848, @GROUP_ID+2, @ID+0, 'She is gone. I thought I would join her in the ruins as a mindless husk, but you...', 12, 0, 100, 0, 0, 0, 119838, 'Absolon to Player'),
(101848, @GROUP_ID+3, @ID+0, 'You saved me.', 12, 0, 100, 0, 0, 0, 119839, 'Absolon to Player'),
(101848, @GROUP_ID+4, @ID+0, 'I will seek shelter now. I hope we meet again, friend.', 12, 0, 100, 0, 0, 0, 119840, 'Absolon to Player'),
(101852, @GROUP_ID+0, @ID+0, 'Here we are - my old sanctuary!', 12, 0, 100, 1, 0, 67275, 104154, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+1, @ID+0, 'Strange... the defenses are offline...', 12, 0, 100, 1, 0, 67276, 104155, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+2, @ID+0, 'Intruders! How did they get in here?!', 12, 0, 100, 1, 0, 67277, 104156, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+3, @ID+0, 'This coil taps into the ancient leylines. Crank it up to full power!', 12, 0, 100, 1, 0, 67278, 104221, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+4, @ID+0, 'Good. If we overcharge enough coils, the entire system will failsafe into a lockdown.', 12, 0, 100, 0, 0, 67280, 104224, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+5, @ID+0, 'There are more coils in the chamber below - and more intruders, I imagine.', 12, 0, 100, 0, 0, 67279, 104223, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+6, @ID+0, 'Thwen... I should have recognized your uniquely oafish meddling on my network.', 12, 0, 100, 25, 0, 67292, 104157, 'Chief Telemancer Oculeth to Player'),
(101852, @GROUP_ID+7, @ID+0, 'I can deal with Thwen. You overload the coils!', 12, 0, 100, 1, 0, 67296, 104161, 'Chief Telemancer Oculeth to Player'),
(107302, @GROUP_ID+0, @ID+0, 'Pearlhunter Phin stares at you in disbelief.', 16, 0, 100, 0, 0, 0, 111594, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+1, @ID+0, 'Pearlhunter Phin waves a hand in front of its nose and groans loudly.', 16, 0, 100, 61, 0, 0, 111596, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+2, @ID+0, 'Pearlhunter Phin chuckles, then shakes their head in shame.', 16, 0, 100, 0, 0, 0, 111595, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+3, @ID+0, 'Pearlhunter Phin points at the Leyscar Scuttler.', 16, 0, 100, 0, 0, 0, 114473, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+4, @ID+0, 'Mrglrgr! Mrlgrlr mrlgrl grlrglr. Mrglrgrl?', 12, 0, 100, 0, 0, 416, 113697, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+5, @ID+0, 'Pearlhunter Phin''s jaw drops as it stares at you, bewildered.', 16, 0, 100, 0, 0, 0, 113701, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+6, @ID+0, 'Pearlhunter Phin''s eyes roll back in its head as it sighs heavily.', 16, 0, 100, 0, 0, 0, 113703, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+7, @ID+0, 'Pearlhunter Phin hops around in frustration.', 16, 0, 100, 35, 0, 0, 113702, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+8, @ID+0, 'Pearlhunter Phin excitedly grabs the sand and begins scrubbing the flaw on the pearl.', 16, 0, 100, 0, 0, 0, 113704, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+9, @ID+0, 'Pearlhunter Phin presents the pearl to Mr. Mrglglrm.', 16, 0, 100, 0, 0, 0, 113863, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+10, @ID+0, 'Grlmgrl, mgrlgrg. Glrgrlmrgl mrglrlgr lrglr! Rlmgrlm mgrglrmg mrglrglrm. Mrlgrgmrlg gmrlgrl mlrglrg?', 12, 0, 100, 0, 0, 23615, 113855, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+11, @ID+0, 'Mrg, mrlgmrlg...', 12, 0, 100, 0, 0, 419, 113856, 'Pearlhunter Phin to Player'),
(107302, @GROUP_ID+12, @ID+0, 'Glmrg! Gmlrgm mglrmgrl mrmglr!', 12, 0, 100, 0, 0, 18075, 114794, 'Pearlhunter Phin to Player'),
(107567, @GROUP_ID+0, @ID+0, 'Initiating self-destruct procedure.', 12, 0, 100, 0, 0, 0, 115099, 'Suramar Shieldguard'),
(108389, @GROUP_ID+0, @ID+0, 'Grgmrlg! Glrmg, mglrmglrgr.', 12, 0, 100, 0, 0, 420, 113857, 'Mrgrlilgrl to Player'),
(108389, @GROUP_ID+1, @ID+0, 'Mrlgmrlg, mgrmlgr rgmlrgmlr?', 12, 0, 100, 0, 0, 416, 114372, 'Mrgrlilgrl to Player'),
(108389, @GROUP_ID+2, @ID+0, 'Mrgrlilrgl shakes their head and looks at Pearlhunter Phin.', 16, 0, 100, 0, 0, 0, 114373, 'Mrgrlilgrl to Player'),
(108389, @GROUP_ID+3, @ID+0, 'Mrglrg! Glrmglmrg mglrmgl gmlrg. Mrglmrg?', 12, 0, 100, 0, 0, 419, 114374, 'Mrgrlilgrl to Player'),
(108390, @GROUP_ID+0, @ID+0, 'Mgrlgl. Gmrglmr?', 12, 0, 100, 0, 0, 18071, 113858, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+1, @ID+0, 'Mr. Mrglglrm knocks the pearl down, cracking it!', 16, 0, 100, 0, 0, 0, 113860, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+2, @ID+0, 'Mlgr! Mlgrmlrgrlmgr! Mlgrg mlgrmlgrrlm! Rlmgrlmgr!', 12, 0, 100, 0, 0, 419, 113859, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+3, @ID+0, 'Mrglrmglr? Grlmglrg!', 12, 0, 100, 0, 0, 18075, 114362, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+4, @ID+0, 'Grlgm. Mrglmrglr!', 12, 0, 100, 0, 0, 18077, 114363, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+5, @ID+0, 'Grmlrgm... mrglrgml mlrmglrg mrmg. Mrgl...', 12, 0, 100, 0, 0, 18073, 114365, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+6, @ID+0, 'Mr. Mrglglrm gestures at you.', 16, 0, 100, 0, 0, 0, 114366, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+7, @ID+0, 'Glrgm! Mrglmrlg mrglmglr? Mrl? Grlm?!', 12, 0, 100, 0, 0, 18077, 114367, 'Mr. Mrglglrm to Player'),
(108390, @GROUP_ID+8, @ID+0, 'Mlrgmlrg. Mrlg mrglmr, mlrglrmgr? Grlgmlmrg rglmrglmr.', 12, 0, 100, 0, 0, 18075, 114368, 'Mr. Mrglglrm to Player'),
(108709, @GROUP_ID+0, @ID+0, 'Pearlhunter Phin runs over and begins digging furiously.', 16, 0, 100, 0, 0, 0, 114164, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+1, @ID+0, 'Pearlhunter Phin throws their arms in the air, seemingly frustrated.', 16, 0, 100, 0, 0, 0, 114160, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+2, @ID+0, 'Mrlg. Grlgm.', 12, 0, 100, 0, 0, 417, 114163, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+3, @ID+0, 'Pearlhunter Phin hops around impatiently.', 16, 0, 100, 0, 0, 0, 114159, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+4, @ID+0, 'Mrgrlg! Glrgmrl mgrlgr...', 12, 0, 100, 0, 0, 415, 114161, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+5, @ID+0, 'Pearlhunter Phin groans and kicks a nearby rock.', 16, 0, 100, 0, 0, 0, 114158, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+6, @ID+0, 'GRGRLM! Mlrgmr, gmrlg Glrmrgl mrlg Mrgrlilrgl.', 12, 0, 100, 0, 0, 419, 114167, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+7, @ID+0, 'Pearlhunter Phin triumphantly pulls out handful of long fangs from the pile of sand.', 16, 0, 100, 0, 0, 0, 114165, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+8, @ID+0, 'Mrglrg! Grmgl, grmlgrmlg mlrgr lrrg.', 12, 0, 100, 0, 0, 417, 114166, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+9, @ID+0, 'Mrgrlilgrl! Mrglmr gmrlgrmglr?!', 12, 0, 100, 0, 0, 419, 114782, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+10, @ID+0, 'Pearlhunter Phin breaks the cocoon open.', 16, 0, 100, 0, 0, 0, 114375, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+11, @ID+0, 'Grmlrgr! Mlrgmlrg mglrm glrmg!', 12, 0, 100, 0, 0, 419, 114369, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+12, @ID+0, 'Mrglglrm! Mrlgmrlg mglr!', 12, 0, 100, 0, 0, 416, 114370, 'Pearlhunter Phin to Player'),
(108709, @GROUP_ID+13, @ID+0, 'Grlgr mrlgml. Mrglrglmr!', 12, 0, 100, 0, 0, 417, 114371, 'Pearlhunter Phin to Player'),
(111863, @GROUP_ID+0, @ID+0, 'What is this place?', 12, 0, 100, 0, 0, 67381, 94147, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+1, @ID+0, 'This chamber... I have never seen anything like it.', 12, 0, 100, 0, 0, 67383, 117057, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+2, @ID+0, 'So dark...', 12, 0, 100, 0, 0, 67384, 117539, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+3, @ID+0, 'In''alah!', 12, 0, 100, 463, 0, 67385, 117454, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+4, @ID+0, 'Much better.', 12, 0, 100, 0, 0, 67386, 117220, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+5, @ID+0, 'Old teleporters. Not so different from the ones in Suramar city. Seems they are inactive.', 12, 0, 100, 0, 0, 67387, 117064, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+6, @ID+0, 'Let us explore downstairs. Watch your step.', 12, 0, 100, 0, 0, 67388, 117219, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+7, @ID+0, 'Strange. The floor looks like... a map?', 12, 0, 100, 0, 0, 67389, 117221, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+8, @ID+0, 'And we are at the center...', 12, 0, 100, 0, 0, 67390, 117551, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+9, @ID+0, 'One thing is certain - leyline energy is being fed into this chamber from elsewhere.', 12, 0, 100, 0, 0, 67391, 117222, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+10, @ID+0, 'What could have required such power? A weapon, perhaps?', 12, 0, 100, 0, 0, 67392, 117557, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+11, @ID+0, 'And those keepers protecting it... How long their vigil must have been...', 12, 0, 100, 0, 0, 67393, 117558, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+12, @ID+0, '<Sigh.> I have more questions now than before!', 12, 0, 100, 0, 0, 67394, 117559, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+13, @ID+0, 'For now, at least, we know the withered have learned to avoid this place.', 12, 0, 100, 0, 0, 67395, 101214, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+14, @ID+0, 'And nobody from the palace would think to search for us here.', 12, 0, 100, 0, 0, 67396, 101215, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+15, @ID+0, 'It is a perfect refuge. A temporary home, until I can return to Suramar.', 12, 0, 100, 0, 0, 67397, 117561, 'First Arcanist Thalyssra to Player'),
(111863, @GROUP_ID+16, @ID+0, 'But first, I will need allies.', 12, 0, 100, 0, 0, 67398, 117562, 'First Arcanist Thalyssra to Player');

UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=121413; -- Défenseur du Déclin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109409; -- Nightborne Wretch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98548; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109448; -- Earthcaller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102017; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102142; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101782; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113571; -- Buried Hoarder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101116; -- Warpcaster Thwen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116069; -- Beam Target Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111921; -- Buried Exile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116626; -- Warp Aberration
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116623; -- Warp Spark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116622; -- Unstable Rift
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101497; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101852; -- Nightfallen Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101110; -- Warp Ray
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112905; -- Crimson Silkwing
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101581; -- Tanzanite Borer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101580; -- Tanzanite Skitterer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101577; -- Tanzanite Shatterer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113417; -- Swarming Spiderling
UPDATE `creature_template` SET `type`=10, `type_flags`=1024, `VerifiedBuild`=25996 WHERE `entry`=117437; -- Ligne tellurique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102413; -- Warp Dagger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106648; -- Stormwing Drake
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106609; -- Adolescent Stormwing
UPDATE `creature_template` SET `KillCredit1`=115480, `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=115519; -- Felborne Spellbreaker
UPDATE `creature_template` SET `KillCredit1`=115480, `HealthScalingExpansion`=6, `type`=9, `type_flags`=2147483720, `HealthModifier`=3, `VerifiedBuild`=25996 WHERE `entry`=115469; -- Orlis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116421; -- Ley Line Channeler
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=9, `type_flags`=268435968, `HealthModifier`=1.5, `VerifiedBuild`=25996 WHERE `entry`=115480; -- Fel-Powered Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113420; -- Cocon d’œufs grouillant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112370; -- Reclus des ruines
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108528; -- Vil rôdeur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114924; -- Duskwatch Saberguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101576; -- Telemancer's Trap
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101574; -- Telemancer's Trap
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104810; -- Penned Murloc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112948; -- Glitterpool Snapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111770; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105653; -- Captive Lion Seal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113483; -- Menagerie Shopkeeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112331; -- Skittering Riverbug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105650; -- Confined Raptor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113772; -- Rope Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105640; -- Bound Goat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105645; -- Penned Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104845; -- Caged Macaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116063; -- Animated Spellbook
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112421; -- Moist Owlette
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116076; -- Conjured Arcane Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113936; -- Rudaux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115430; -- Charged Arcshaper Staff
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114926; -- Arcane Sentinel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116050; -- Duskwatch Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115526; -- Arcshaper Thorendis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103005; -- Bowl of Fruit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105232; -- Oldus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102960; -- Glitterpool Heron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=65209; -- Frôleur aquatique dansant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115261; -- Disabled Construct
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=88989; -- Violet Firefly
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102415; -- Suramar Skyhunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113205; -- Leyscarred Stag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112825; -- Shieldscar Stag
UPDATE `creature_template` SET `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=112827; -- Shieldscar Doe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114866; -- Mage gardien du Concordat argenté
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114927; -- Fist of the Duskwatch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=102492; -- Glitterpool Frog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114880; -- Chevalier de sang garde de l’aube
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114929; -- Duskwatch Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113601; -- Lapin GÉANT à tout faire (JSB)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114995; -- Mage de guerre du Concordat argenté
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107567; -- Suramar Shieldguard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114838; -- Tyrande Murmevent
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114883; -- Grand Magister Rommath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115926; -- Sentinelle de Darnassus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114897; -- Sentinelle de Darnassus
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114885; -- Dawnseeker Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114841; -- Dame Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114887; -- Lanesh the Steelweaver
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `type`=11, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=69759; -- Defense Crystal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115605; -- Chicken Escapee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114849; -- Ancient Defender
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=129049; -- Tottle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=128396; -- Uuna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101499; -- Chief Telemancer Oculeth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=72762; -- Brilliant Windfeather
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106885; -- Tiger Initiate
UPDATE `creature_template` SET `KillCredit1`=111902, `VerifiedBuild`=25996 WHERE `entry`=111901; -- Suramar Refugee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111902; -- Suramar Refugee
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=6, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=119057; -- Banshee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110750; -- Tirisgarde Apprentice
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111513; -- Leyweaver Ke'lorin
UPDATE `creature_template` SET `KillCredit1`=103527, `VerifiedBuild`=25996 WHERE `entry`=99793; -- Leyscale Manalisk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101900; -- Sinister Shrieker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113123; -- Leytouched Cliffquill
UPDATE `creature_template` SET `modelid1`=74613, `modelid2`=74615, `VerifiedBuild`=25996 WHERE `entry`=101848; -- Absolon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99527; -- Rejeton cristallin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108536; -- Monstrous Leycrawler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98699; -- Webbed Husk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108878; -- Mrs. Mrglglrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110826; -- Bécasse côtière
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=88978; -- Kelp Scuttler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=64806; -- Bigorneau rapana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108709; -- Pearlhunter Phin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113162; -- Chasseuse fal’dorei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91717; -- Azsunian Oliveback
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91715; -- Azsunian Kingfeather
UPDATE `creature_template` SET `RequiredExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=110824; -- Griffe-des-marées
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100846; -- Leytusk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90232; -- Faille déliée
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106873; -- Font of Arcane Energy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90242; -- Wyrm de faille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108521; -- Skrog des mers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101554; -- Spikebacked Scuttler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108535; -- Marsh Hydra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108389; -- Mrgrlilgrl
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108779; -- Mrs. Mrglglrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108390; -- Mr. Mrglglrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112802; -- Mar’tura
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106913; -- Font of Arcane Energy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107303; -- Crab
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112367; -- Leyscar Runt
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104661; -- Pacified Withered
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107302; -- Pearlhunter Phin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=89380; -- Coastal Sandpiper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109803; -- Carapateur entaillurique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113189; -- Coastal Snapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113127; -- Cliffwing Skytalon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100058; -- Arcanist Kel'danath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113122; -- Suramar Cliffquill
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105884; -- Spellwyrm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104618; -- Theryn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101825; -- Nightborne Enforcer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101821; -- Nightborne Warpcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99792; -- Plaie-des-elfes
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105785; -- Fal'dorei Conjurer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105885; -- Hungering Husk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105486; -- Withered Droll
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106119; -- Withered Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105625; -- Fal'dorei Weaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109188; -- Withered Test Subject
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99779; -- Stonespine Gazer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110577; -- Oreth the Vile
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110576; -- Oreth's Victim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112859; -- Vicious Spiderling
UPDATE `creature_template` SET `VignetteID`=1829, `VerifiedBuild`=25996 WHERE `entry`=105728; -- Scythemaster Cil'raman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99791; -- Ettin de Koralune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107974; -- Kill Credit Orathiss Scene 1
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113532; -- Arcward
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114793; -- Trancheur fal’dorei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105623; -- Trancheur fal’dorei
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105686; -- Fal'dorei Webspinner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106276; -- Fal'dorei Web Target Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105685; -- Fal'dorei Broodlord
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99653; -- Rejeton cristallin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105756; -- Jeune araignée de ligne tellurique
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113110; -- Spellwing Strix
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105676; -- Webbed Victim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105632; -- Broodmother Shu'malis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111316; -- Silver Hand Templar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109054; -- Shal’an
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104224; -- Grogneur de Suramar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103811; -- Starclutch Hatchling
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99667; -- Arcanist Kel'danath
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103805; -- Sablehorn Doe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100059; -- Arcane Ward
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103540; -- Starclutch Screecher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108942; -- Withered Feaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113195; -- Swarming Vermin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109022; -- Arcane Ward
UPDATE `creature_template` SET `modelid1`=68238, `modelid2`=68239, `HealthScalingExpansion`=6, `type`=7, `type_flags`=0, `HealthModifier`=0.6, `VerifiedBuild`=25996 WHERE `entry`=100014; -- Carcasse flétrie
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=73543; -- Phalène cerclefeu
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=63062; -- Raton voleur
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=114281; -- Flight Master's Mount
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113126; -- Meredil Lockjaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109751; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=59773; -- Terracotta Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105014; -- Territorial Croaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113136; -- Bénax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111216; -- Fléchetteur du val d’Ambre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113184; -- Cunning Bushtail
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111197; -- Anax
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=64782; -- Raton voleur
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109577; -- Earthen Ring Geomancer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109839; -- Druid of the Claw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111694; -- Acherus Death Knight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111254; -- Defias Thief
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115700; -- Stellagosa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115693; -- Arcaniste Valtrois
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113190; -- Meredil Thrashmaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107947; -- Flare Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106869; -- Snarler Pup
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114720; -- Font of Arcane Energy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111712; -- Withered WQ Turn In Bunny
UPDATE `creature_template` SET `family`=160, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=111675; -- Ancient Cloudwing
UPDATE `creature_template` SET `modelid2`=0, `VerifiedBuild`=25996 WHERE `entry`=97140; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111863; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99088; -- Ancient Keeper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99539; -- Eternal Tether
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99524; -- Keeper Selentia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98967; -- Barrier Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98946; -- Withered Thirster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113985; -- Elieth
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99482; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98312; -- First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98943; -- Withered
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99213; -- Erasmus Moonblade
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114071; -- Pulsing Arcane Echo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=104894; -- Moonlight Cub
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108729; -- Wand Spark 3
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108728; -- Wand Spark 2
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108725; -- Wand Spark 1
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114070; -- Blinking Arcane Echo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112627; -- Curious Manasaber
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98209; -- Echo of First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98555; -- Withered Shambler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100169; -- Faint Arcane Echo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99267; -- Nightborne Scion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115381; -- Nightborne Rebel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114931; -- Rebelle souffrenuit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114865; -- Magus garde de l’aube
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114845; -- Démolisseur ignétoile
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=115684; -- Garde-paix du Kirin Tor
UPDATE `creature_template` SET `family`=160, `VerifiedBuild`=25996 WHERE `entry`=115500; -- Dusktalon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112336; -- Meredil Glider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115924; -- Magus garde de l’aube
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115498; -- Lothrius Mooncaller
UPDATE `creature_template` SET `HealthScalingExpansion`=3, `VerifiedBuild`=25996 WHERE `entry`=73828; -- Phalène cerclefeu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99749; -- Moonlight Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98267; -- Echo of First Arcanist Thalyssra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105332; -- Desmond Gravesorrow
UPDATE `creature_template` SET `modelid1`=22903, `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=41200; -- Generic Bunny - PRK
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93524; -- Lalla Brightweave
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96770; -- Warmage Mumplina
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96771; -- Warmage Lukems
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93525; -- Ainderu Summerleaf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93542; -- Tanithria
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105339; -- Shadowgore Darkcaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112441; -- Robert Newhearth
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=2, `type_flags2`=16384, `HealthModifier`=10, `ManaModifier`=10, `VerifiedBuild`=25996 WHERE `entry`=122926; -- Chromie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107968; -- Archmage Lan'dalock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90418; -- Archmage Modera
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90463; -- Archmage Karlain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90431; -- Archmage Ansirem Runeweaver
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=118506; -- Sorcelame saccage-soleil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105081; -- Archmage Kalec
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92459; -- Dorothy Egan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93526; -- Tiffany Cartier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92460; -- Edward Egan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98266; -- Arcane Anomaly
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105723; -- Vicktor Ebonfall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105564; -- Injured Kirin Tor Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110738; -- Kaela Noirmédaille
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93527; -- Timothy Jones
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93543; -- Sminx Glasseye
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113784; -- Classic Larry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93529; -- Olisarra the Kind
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113873; -- Archivist Elysiana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93528; -- Angelique Butler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106359; -- Runed Ladder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93544; -- Jang Quillpaw
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93532; -- Jessica Sellers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93533; -- Theresa Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=78217; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92195; -- Professor Pallin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96841; -- Emeline Fizzlefry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96840; -- Sabriana Sorrowgaze
UPDATE `creature_template` SET `modelid1`=38985, `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=79861; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96772; -- Warmage Kath'leen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93531; -- Enchanter Nalthanis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97718; -- Vanessa Sellers
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99867; -- Warpweaver Tuviss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93530; -- Ildine Sorrowspear
UPDATE `creature_template` SET `IconName`='questinteract', `HealthScalingExpansion`=6, `type`=3, `type_flags`=1610612752, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=119436; -- NO ADDRESS
UPDATE `creature_template` SET `IconName`='questinteract', `HealthScalingExpansion`=6, `type`=3, `type_flags`=1610612752, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=119437; -- NOT ENOUGH STAMPS
UPDATE `creature_template` SET `IconName`='questinteract', `HealthScalingExpansion`=6, `type`=3, `type_flags`=1610612752, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=119438; -- BAD HANDWRITING
UPDATE `creature_template` SET `IconName`='questinteract', `HealthScalingExpansion`=6, `type`=3, `type_flags`=1610612752, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=119396; -- RETURN TO SENDER
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `VerifiedBuild`=25996 WHERE `entry`=104230; -- Postier-lémentaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96839; -- The Magnificent Merleaux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96838; -- Kitz Proudbreeze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96987; -- Norvin Alderman
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97332; -- Richard Hatstock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96944; -- Muran Fairden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96949; -- Farseer Lopaa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96947; -- Matron Nessa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=85290; -- Vaultkeeper Sarniv
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113785; -- Hugh Mann
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96976; -- Cloth Merchant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96975; -- Paldesse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97342; -- Salan Sunthread
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99349; -- Robert "Chance" Llore
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96789; -- Caliel Brightwillow
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108792; -- Jenny McCree
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96948; -- Pathstalker Gilen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96950; -- Summoner Mazek
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96951; -- Naseev
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96945; -- Ranger Bodine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96946; -- Varlean
UPDATE `creature_template` SET `type_flags2`=16384, `VerifiedBuild`=25996 WHERE `entry`=106930; -- Lieutenant Surtees
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96483; -- Jepetto Joybuzz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=68238; -- Carousel Rocket
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93534; -- Katherine Lee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97501; -- Linzi Rirouge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93545; -- Bradford Duncan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112554; -- Pesky Bug
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=68239; -- Carousel Wyvern
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96968; -- Aquanos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96967; -- Shandy Glossgleam
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=68232; -- Carousel Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97012; -- Abra Cadabra
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112716; -- Rasil Fireborne
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96979; -- Bragund Brightlink
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96792; -- Inzi Charmlight
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112720; -- Jemma Wilson
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97331; -- Icks
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112717; -- Ginger Blockgear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114730; -- Caeli
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97685; -- Gnolie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96793; -- Stefen Cotter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96980; -- Matilda Brightlink
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96990; -- Applebough
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=50, `ManaModifier`=10, `VerifiedBuild`=25996 WHERE `entry`=119226; -- Danath Trollbane
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96977; -- Valerie Langrom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96999; -- Susana Averoy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=77021; -- Chimérion albinos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96978; -- Rafael Langrom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97213; -- Windle Sparkshine
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97004; -- "Red" Jack Findle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96791; -- Marcella Bloom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96832; -- Crafticus Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96833; -- Grezla the Hag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96790; -- Isirami Fairwind
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113782; -- Hannis Shoalwalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103119; -- Dalaran Citizen
UPDATE `creature_template` SET `rank`=0, `VerifiedBuild`=25996 WHERE `entry`=103092; -- Le grand Akazamzarak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103120; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=35845; -- Dave's Industrial Light and Magic Bunny (Small)(Sessile)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103118; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103116; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108323; -- Gilnean Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111243; -- Archmage Lan'dalock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=95844; -- Marcia Chase
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=8, `VerifiedBuild`=25996 WHERE `entry`=117448; -- Cinnamon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=42717; -- Young Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97002; -- Ninsianna
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113779; -- Sister Might
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97339; -- Cho Ironpalm
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97011; -- Valaden Silverblade
UPDATE `creature_template` SET `modelid1`=77398, `HealthScalingExpansion`=4, `type_flags`=262144, `type_flags2`=1, `HealthModifier`=1, `ManaModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=417; -- Chasseur corrompu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=78116; -- Water Elemental
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97007; -- Kerta the Bold
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97009; -- Jawknee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97529; -- L’incroyable Zanzo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=123650; -- Fennombre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=75487; -- Razorfang Hunter
UPDATE `creature_template` SET `movementId`=961, `VerifiedBuild`=25996 WHERE `entry`=106549; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103159; -- Bébé Winston
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=90417; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107987; -- Hymdall
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96586; -- Master Smith Helgar
UPDATE `creature_template` SET `type_flags`=134217728, `type_flags2`=16384, `VerifiedBuild`=25996 WHERE `entry`=111741; -- Fjornson Stonecarver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106459; -- Capitaine Hjalmar Stahlstrom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=100635; -- Skyseer Ghrent
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97389; -- Eye of Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112577; -- Weaponmaster Asvard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107494; -- Maîtresse de l’arène val’kyr
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96401; -- Aspirant valarjar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96469; -- Odyn
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=114558; -- Greater Sparring Partner
UPDATE `creature_template` SET `IconName`='trainer', `VerifiedBuild`=25996 WHERE `entry`=107994; -- Einar the Runecaster
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112420; -- Ymirjar Lord's Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112353; -- Battlegear of Might Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112418; -- Hellscream's Conquest Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112416; -- Wrynn's Conquest Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112356; -- Battlegear of Wrath Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112413; -- Valorous Siegebreaker Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112357; -- Conqueror's Battlegear Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112408; -- Heroes' Dreadnaught Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112361; -- Warbringer Armor Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112390; -- Destroyer Armor Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112400; -- Onslaught Set
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112392; -- Quartermaster Durnolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116609; -- Battlelord's Armor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62822; -- Cousin Slowhands
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=62821; -- Mystic Birdhat
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96572; -- Valarjar forge-foudre
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113267; -- Aspirant valarjar
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=17255; -- Jeune hippogriffe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=93819; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=54638; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106548; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32252; -- Wanathan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32251; -- Shokavis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96801; -- Kyunghee
UPDATE `creature_template` SET `modelid1`=74526, `HealthModifier`=6, `VerifiedBuild`=25996 WHERE `entry`=101527; -- Bling-o-tron 6000
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96803; -- Mimbihi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112545; -- Zariya
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=63365; -- Navet navrant
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=15, `VerifiedBuild`=25996 WHERE `entry`=120418; -- Havi
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=20, `VerifiedBuild`=25996 WHERE `entry`=120413; -- Rensar Greathoof
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=6, `VerifiedBuild`=25996 WHERE `entry`=120415; -- Highlord Darion Mograine
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=20, `VerifiedBuild`=25996 WHERE `entry`=120420; -- Iron-Body Ponshu
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=10, `ManaModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=120417; -- Meryl Felstorm
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=120423; -- Emmarel Shadewarden
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=10, `ManaModifier`=80, `VerifiedBuild`=25996 WHERE `entry`=120421; -- Ritssyn Flamescowl
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=15, `VerifiedBuild`=25996 WHERE `entry`=120416; -- Lord Jorach Ravenholdt
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=20, `ManaModifier`=15, `VerifiedBuild`=25996 WHERE `entry`=120424; -- Alonsus Faol
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=15, `VerifiedBuild`=25996 WHERE `entry`=120422; -- Lady Liadrin
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=10, `ManaModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=120419; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `HealthModifier`=200, `ManaModifier`=100, `VerifiedBuild`=25996 WHERE `entry`=120412; -- Farseer Nobundo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112543; -- Khronus Lightwarden
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110642; -- Fizzi Liverzapper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=86425; -- Gorgrond Wastetalon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97490; -- Halga Char-d’acier
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `type_flags`=4096, `VerifiedBuild`=25996 WHERE `entry`=124678; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106720; -- Svergan Stormcloak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=416; -- Diablotin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97512; -- Chasseresse-dimensionnelle Kula
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32751; -- Backbiter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=82646; -- Venombarb
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `VerifiedBuild`=25996 WHERE `entry`=32725; -- Warmage Silva
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97692; -- Frère de la Lumière
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106843; -- Prince Farondis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97725; -- Prêtresse d’Élune
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=34527; -- Dave's Industrial Light and Magic Bunny (Small)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107590; -- Mayla Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109739; -- Tyrande Whisperwind
UPDATE `creature_template` SET `modelid1`=64062, `modelid2`=11686, `VerifiedBuild`=25996 WHERE `entry`=72587; -- VFX Bunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97767; -- Prêtresse maléficieuse
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99350; -- Shannon Noel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106951; -- Advisor Stillwater
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97792; -- Prêtre du soleil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96953; -- Ranger Eoss
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96959; -- Vinsun
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96802; -- Umbiwa
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4096, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=120687; -- Violet Shadowmend
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96484; -- Clockwork Assistant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96799; -- Abohba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97003; -- Sheddle Glossgleam
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96797; -- Nargut
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96798; -- Rhukah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96796; -- Uda the Beast
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97005; -- Debbi Moore
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96956; -- Pathstalker Rislar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96957; -- Murgha the Tempered
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96837; -- Babagahnoosh the Grumpy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96836; -- Magus Fansy Goodbringer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96028; -- Wrath of Azshara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=91784; -- Warlord Parjesh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96952; -- Hahna Moonscrest
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96812; -- Elizabeth Ross
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92438; -- Glaciela Rimebang
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97001; -- Orton Bennet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92936; -- Aimee
UPDATE `creature_template` SET `IconName`='questinteract', `VerifiedBuild`=25996 WHERE `entry`=112947; -- Emilia Baumoon
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96955; -- Matron Ossela
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110621; -- Erika Page
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96958; -- Summoner Calwen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110623; -- Sunny
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96811; -- Andrew Matthews
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112847; -- Bewdley
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=114732; -- Winnie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109390; -- Annie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110622; -- Trevor Page
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109554; -- Altius Maximus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113775; -- Punchy Lou
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96810; -- Archivist Betha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96809; -- Arille Azuregaze
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags2`=16384, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=119486; -- Apothecary Lee
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96808; -- Sandra Bartan
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags2`=16384, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=119272; -- Sarah the Savage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=111816; -- Calydus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96834; -- Fabioso the Fabulous
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=109387; -- Beck
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags2`=16384, `HealthModifier`=5, `VerifiedBuild`=25996 WHERE `entry`=119487; -- Talia Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96835; -- Grindle Firespark
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116420; -- Glowing Blue Gem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116419; -- Glowing Green Gem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=116408; -- Glowing Red Gem
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112007; -- Mel Lynchen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97863; -- Bonegrim
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113900; -- Liyana
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112456; -- Rachele
UPDATE `creature_template` SET `IconName`='questinteract', `VerifiedBuild`=25996 WHERE `entry`=113901; -- Crixa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96781; -- Kizi Copperclip
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96827; -- Adorean Lew
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96778; -- Aemara
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `type`=7, `VerifiedBuild`=25996 WHERE `entry`=119088; -- Anebria Sunwine
UPDATE `creature_template` SET `type`=10, `type_flags`=1611661328, `type_flags2`=6, `VerifiedBuild`=25996 WHERE `entry`=119642; -- Reliquary Pick
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=3, `VerifiedBuild`=25996 WHERE `entry`=125261; -- Bran Buckbeard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96828; -- Bitty Frostflinger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112437; -- Roscoe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=110409; -- Credit - Portal Taken
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106815; -- "The Tidestone of Golganneth" Teleport Used Quest Kill Credit ELM
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107587; -- "The Hammer of Khaz'goroth" Teleport Used Quest Kill Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96807; -- Afsaneh Asrar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112012; -- Sir Jonathan Trueheart
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96780; -- Aerith Primrose
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96779; -- Dagna Flintlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103630; -- Elite Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=27047; -- Invisible Stalker (Floating Only)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97141; -- Koraud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96782; -- Lucian Trias
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96785; -- Christi Stockton
UPDATE `creature_template` SET `IconName`='questinteract', `VerifiedBuild`=25996 WHERE `entry`=107772; -- Ol' Toomba
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96777; -- Jarold Puller
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=20, `VerifiedBuild`=25996 WHERE `entry`=116175; -- Karam Magespear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96198; -- Catriona Macrae
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96806; -- Amisi Azuregaze
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97514; -- Danric l’Audacieux
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96784; -- Fialla Sweetberry
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96983; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108076; -- "Move Like No Other" Lan'dalock's Area Trigger Quest POI Blob
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=108628; -- Armond Thaco
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1860; -- Marcheur du Vide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96788; -- Jessa Weaver
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97212; -- 7.0 Dalaran - Shopkeeper - Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=115287; -- Serr'ah
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=29929; -- Mechano-Hog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=305; -- Etalon blanc
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=65078; -- Great Purple Dragon Turtle
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=62106; -- Great Red Dragon Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=51195; -- Kor'kron Annihilator
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=40725; -- X-53 Touring Rocket
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=36883; -- Sunwalker Kodo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31694; -- Azure Drake Mount
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18379; -- Swift Purple Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18377; -- Coursier du vent rouge rapide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18380; -- Swift Yellow Wind Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20030; -- Thalassian Charger
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=30542; -- Rivendare's Deathcharger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20029; -- Thalassian Warhorse
UPDATE `creature_template` SET `movementId`=140, `VerifiedBuild`=25996 WHERE `entry`=77178; -- Dread Raven
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=37059; -- Great Sunwalker Kodo
UPDATE `creature_template` SET `family`=0, `type`=1, `VerifiedBuild`=25996 WHERE `entry`=358; -- Timber Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98724; -- Giada Goldleash
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=112079; -- Pèlerin cramoisi
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=25058; -- Fuzz
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31742; -- Cosmetic Prairie Dog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=107326; -- Draemus
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31741; -- Cosmetic Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31719; -- Cosmetic Frenzy
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31740; -- Cosmetic Turtle
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96787; -- Warcaster Fanoraithe
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31728; -- Cosmetic Cat Set 1/2
UPDATE `creature_template` SET `type_flags`=134217728, `VerifiedBuild`=25996 WHERE `entry`=96786; -- Archmage Celindra
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31714; -- Cosmetic Ribbon Snake
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31735; -- Cosmetic Pig
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31710; -- Cosmetic Black Kingsnake
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31730; -- Cosmetic Frog
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31729; -- Cosmetic Cat Set 2/2
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `HealthModifier`=0.6, `VerifiedBuild`=25996 WHERE `entry`=121602; -- Manapoof
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=71163; -- Val’kyr en herbe
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32752; -- Tabitha
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97489; -- Garl Mornegrise
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96479; -- Breanni
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=31689; -- Gnome Diver
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=34330; -- Jones
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=31796; -- Cosmetic Worg Pup
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=103626; -- Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=113783; -- Savash Windcalller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=32494; -- Dalaran Child
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=92489; -- Mei Francis
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96842; -- Archmage Tenaj
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=96843; -- Darthalia Ebonscorch
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=97207; -- Emmigosa
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=99394; -- Ondulin fétide
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98116; -- Méduse aiguemorne
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=25996 WHERE `entry`=94867; -- Requin gauche
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=84853; -- Ame de la forge
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=88225; -- Compagnon de sentinelle
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=88222; -- Paonneau de la Flore éternelle
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=86447; -- Ikky
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=25996 WHERE `entry`=33198; -- Scorpion de Durotar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=43084; -- Forest Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=124303; -- Duskcloak Panthara
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98725; -- Lio the Lioness
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=98723; -- Tiffy Trapspring
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=106551; -- Hati

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=115469 AND `Idx`=0) OR (`CreatureEntry`=115480 AND `Idx`=0) OR (`CreatureEntry`=96028 AND `Idx`=7);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(115469, 0, 142241, 25996), -- Orlis
(115480, 0, 134107, 25996), -- Fel-Powered Sentinel
(96028, 7, 146688, 25996); -- Wrath of Azshara

UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101110 AND `Idx`=0); -- Warp Ray
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101581 AND `Idx`=3); -- Tanzanite Borer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101581 AND `Idx`=2); -- Tanzanite Borer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101581 AND `Idx`=1); -- Tanzanite Borer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101581 AND `Idx`=0); -- Tanzanite Borer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101580 AND `Idx`=0); -- Tanzanite Skitterer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101577 AND `Idx`=3); -- Tanzanite Shatterer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101577 AND `Idx`=2); -- Tanzanite Shatterer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101577 AND `Idx`=1); -- Tanzanite Shatterer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101577 AND `Idx`=0); -- Tanzanite Shatterer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106648 AND `Idx`=1); -- Stormwing Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106648 AND `Idx`=0); -- Stormwing Drake
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106609 AND `Idx`=1); -- Adolescent Stormwing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=106609 AND `Idx`=0); -- Adolescent Stormwing
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112948 AND `Idx`=1); -- Glitterpool Snapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112948 AND `Idx`=0); -- Glitterpool Snapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105653 AND `Idx`=0); -- Captive Lion Seal
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105650 AND `Idx`=1); -- Confined Raptor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105650 AND `Idx`=0); -- Confined Raptor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105640 AND `Idx`=2); -- Bound Goat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105640 AND `Idx`=1); -- Bound Goat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105640 AND `Idx`=0); -- Bound Goat
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105645 AND `Idx`=0); -- Penned Turtle
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104845 AND `Idx`=0); -- Caged Macaw
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=114926 AND `Idx`=0); -- Arcane Sentinel
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105232 AND `Idx`=1); -- Oldus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105232 AND `Idx`=0); -- Oldus
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=102960 AND `Idx`=0); -- Glitterpool Heron
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113205 AND `Idx`=2); -- Leyscarred Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113205 AND `Idx`=1); -- Leyscarred Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113205 AND `Idx`=0); -- Leyscarred Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112825 AND `Idx`=2); -- Shieldscar Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112825 AND `Idx`=1); -- Shieldscar Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112825 AND `Idx`=0); -- Shieldscar Stag
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112827 AND `Idx`=2); -- Shieldscar Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112827 AND `Idx`=1); -- Shieldscar Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112827 AND `Idx`=0); -- Shieldscar Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=72762 AND `Idx`=0); -- Brilliant Windfeather
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99793 AND `Idx`=1); -- Leyscale Manalisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99793 AND `Idx`=0); -- Leyscale Manalisk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101900 AND `Idx`=2); -- Sinister Shrieker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101900 AND `Idx`=1); -- Sinister Shrieker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101900 AND `Idx`=0); -- Sinister Shrieker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113123 AND `Idx`=0); -- Leytouched Cliffquill
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=91717 AND `Idx`=0); -- Azsunian Oliveback
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=91715 AND `Idx`=0); -- Azsunian Kingfeather
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110824 AND `Idx`=2); -- Griffe-des-marées
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110824 AND `Idx`=1); -- Griffe-des-marées
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=110824 AND `Idx`=0); -- Griffe-des-marées
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100846 AND `Idx`=1); -- Leytusk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100846 AND `Idx`=0); -- Leytusk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101554 AND `Idx`=2); -- Spikebacked Scuttler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101554 AND `Idx`=1); -- Spikebacked Scuttler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=101554 AND `Idx`=0); -- Spikebacked Scuttler
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=108535 AND `Idx`=0); -- Marsh Hydra
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112802 AND `Idx`=0); -- Mar’tura
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=6); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=5); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=4); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=3); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=2); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=1); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=109803 AND `Idx`=0); -- Carapateur entaillurique
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113189 AND `Idx`=2); -- Coastal Snapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113189 AND `Idx`=1); -- Coastal Snapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113189 AND `Idx`=0); -- Coastal Snapper
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113127 AND `Idx`=0); -- Cliffwing Skytalon
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=100058 AND `Idx`=0); -- Arcanist Kel'danath
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113122 AND `Idx`=0); -- Suramar Cliffquill
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99779 AND `Idx`=1); -- Stonespine Gazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99779 AND `Idx`=0); -- Stonespine Gazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104224 AND `Idx`=2); -- Grogneur de Suramar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104224 AND `Idx`=1); -- Grogneur de Suramar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=104224 AND `Idx`=0); -- Grogneur de Suramar
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103805 AND `Idx`=2); -- Sablehorn Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103805 AND `Idx`=1); -- Sablehorn Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103805 AND `Idx`=0); -- Sablehorn Doe
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=103540 AND `Idx`=0); -- Starclutch Screecher
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113126 AND `Idx`=0); -- Meredil Lockjaw
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=59773 AND `Idx`=0); -- Terracotta Guardian
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=105014 AND `Idx`=0); -- Territorial Croaker
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113184 AND `Idx`=0); -- Cunning Bushtail
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=113190 AND `Idx`=0); -- Meredil Thrashmaw
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=112336 AND `Idx`=0); -- Meredil Glider
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99749 AND `Idx`=2); -- Moonlight Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99749 AND `Idx`=1); -- Moonlight Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=99749 AND `Idx`=0); -- Moonlight Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=75487 AND `Idx`=0); -- Razorfang Hunter
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=6); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=5); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=4); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=3); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=2); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=1); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=96028 AND `Idx`=0); -- Wrath of Azshara
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=91784 AND `Idx`=1); -- Warlord Parjesh
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=91784 AND `Idx`=0); -- Warlord Parjesh

DELETE FROM `gameobject_template` WHERE `entry` IN (267261 /*Spell Focus*/, 254156 /*Bench*/, 254157 /*Bench*/, 266147 /*High Elf Banner 2*/, 266146 /*High Elf Banner 1*/, 265417 /*Night Elf Single Tent 2*/, 266145 /*Kirin Tor Banner*/, 265479 /*Night Elf Cart*/, 265418 /*Night Elf Single Tent 1*/, 265481 /*Night Elf Barrel*/, 265478 /*Night Elf Crate*/, 265429 /*Blood Elf Tent 4*/, 266125 /*Portal to Silvermoon*/, 265428 /*Blood Elf Tent 3*/, 265424 /*Blood Elf Banner 1*/, 265482 /*Flagpole*/, 265480 /*Night Elf Banner 3*/, 265426 /*Blood Elf Ballista 2*/, 265422 /*Night Elf Banner 2*/, 265425 /*Blood Elf Banner 2*/, 251887 /*Web Trail*/, 251423 /*Battered Shotgun*/, 240356 /*Unbound Rift*/, 266008 /*Teleport Pad*/, 258810 /*Main Chamber - 3 - Dirty - Rubble 02*/, 255360 /*Rear Chamber - Dirty - Web 23*/, 255366 /*Rear Chamber - Dirty - Web 17*/, 255362 /*Rear Chamber - Dirty - Web 13*/, 255355 /*Rear Chamber - Dirty - Web 09*/, 255356 /*Rear Chamber - Dirty - Web 18*/, 255353 /*Rear Chamber - Dirty - Web 16*/, 255364 /*Rear Chamber - Dirty - Web 27*/, 253810 /*Rear Chamber - Dirty - Web 26*/, 255365 /*Rear Chamber - Dirty - Web 12*/, 253809 /*Rear Chamber - Dirty - Web 26*/, 255359 /*Rear Chamber - Dirty - Web 14*/, 255363 /*Rear Chamber - Dirty - Web 22*/, 253811 /*Rear Chamber - Dirty - Web 25*/, 255361 /*Rear Chamber - Dirty - Web 28*/, 255374 /*Rear Chamber - Dirty - Web 10*/, 255367 /*Rear Chamber - Dirty - Web 11*/, 255372 /*Rear Chamber - Dirty - Web 08*/, 255354 /*Rear Chamber - Dirty - Web 15*/, 255357 /*Rear Chamber - Dirty - Web 07*/, 255358 /*Rear Chamber - Dirty - Web 06*/, 255371 /*Rear Chamber - Dirty - Web 21*/, 255373 /*Rear Chamber - Dirty - Web 20*/, 253876 /*Right Chamber - H - Dirty - Wrecked Table*/, 255370 /*Rear Chamber - Dirty - Web 02*/, 253912 /*Right Chamber - H - Dirty - Rug*/, 253877 /*Right Chamber - H - Dirty - Wrecked Table 02*/, 253878 /*Right Chamber - H - Dirty - Rubble*/, 255375 /*Rear Chamber - Dirty - Web 28*/, 255368 /*Rear Chamber - Dirty - Web 05*/, 255377 /*Doodad_6td_web_a002*/, 255379 /*Rear Chamber - Dirty - Web 01*/, 255369 /*Rear Chamber - Dirty - Web 04*/, 255378 /*Rear Chamber - Dirty - Web 19*/, 255376 /*Rear Chamber - Dirty - Web 30*/, 253824 /*Central Chamber - Dirty - Web 09*/, 253825 /*Rear Chamber - Dirty - Web 29*/, 258840 /*Main Chamber - 6 - Dirty - Rubble 01*/, 258832 /*Main Chamber - 5 - Dirty - Rubble 01*/, 258820 /*Main Chamber - 5 - Dirty - Rubble 03*/, 258837 /*Main Chamber - 6 - Dirty - Rubble 02*/, 258835 /*Doodad_7ne_nightelf_urnlarge01_wrecked003*/, 258838 /*Doodad_7ne_ancient_rubble006*/, 258836 /*Doodad_7ne_nightelf_brazier02_wrecked003*/, 253840 /*Right Chamber - J - Dirty - Urn Wrecked*/, 253829 /*Right Chamber - F - Dirty - Web 03*/, 258821 /*Main Chamber - 4 - Dirty - Rubble 08*/, 253841 /*Right Chamber - J - Dirty - Ruin 01*/, 258815 /*Main Chamber - 4 - Dirty - Rubble 07*/, 253839 /*Right Chamber - J - Dirty - Brazier Wrecked*/, 253842 /*Right Chamber - J - Dirty - Ruin 02*/, 253901 /*Right Chamber - D - Dirty - Rubble*/, 253844 /*Right Chamber - K - Dirty - Urn Wrecked*/, 253843 /*Right Chamber - K - Dirty - Bookcase*/, 253813 /*Right Chamber - C - Dirty - Bookcase 02*/, 253812 /*Right Chamber - C - Dirty - Bookshelf*/, 258813 /*Doodad_6dr_draenei_rubble_glass002*/, 253898 /*Right Chamber - C - Dirty - Wrecked Table*/, 253897 /*Right Chamber - C - Dirty - Scroll 02*/, 253896 /*Right Chamber - C - Dirty - Book*/, 258812 /*Doodad_7ne_nightelf_glassrubble002*/, 253917 /*Right Chamber - B - Dirty - Bookcase 02*/, 253895 /*Right Chamber - C - Dirty - Scroll 05*/, 258834 /*Main Chamber - 2 - Dirty - Rubble 02*/, 258811 /*Main Chamber - 3 - Dirty - Rubble 01*/, 258839 /*Main Chamber - 8 - Dirty - Rubble 02*/, 258818 /*Main Chamber - 8 - Dirty - Rubble 01*/, 258806 /*Main Chamber - 1 - Dirty - Rubble 04*/, 258805 /*Main Chamber - 1 - Dirty - Rubble 01*/, 253914 /*Right Chamber - B - Dirty - Bookcase*/, 253814 /*Right Chamber - A - Dirty - Wrecked Bench*/, 258833 /*Main Chamber - 2 - Dirty - Rubble 01*/, 258817 /*Main Chamber - 1 - Dirty - Rubble 02*/, 258816 /*Main Chamber - 1 - Dirty - Rubble 03*/, 258814 /*Main Chamber - 1 - Dirty - Rubble 05*/, 258804 /*Main Chamber - 1 - Dirty - Rubble 06*/, 258803 /*Main Chamber - 1 - Dirty - Rubble 07*/, 258784 /*Entrance - Dirty - Web 18*/, 258764 /*Entrance - Dirty - Web 06*/, 253835 /*Entrance - Dirty - Web 29*/, 253833 /*Entrance - Dirty - Web 28*/, 258785 /*Entrance - Dirty - Web 04*/, 258782 /*Entrance - Dirty - Web 05*/, 258783 /*Entrance - Dirty - Web 33*/, 258788 /*Entrance - Dirty - Web 07*/, 258757 /*Entrance - Dirty - Web 19*/, 258758 /*Entrance - Dirty - Web 20*/, 258760 /*Entrance - Dirty - Web 15*/, 258756 /*Doodad_KarazahnWeb718*/, 258796 /*Entrance - Dirty - Web 34*/, 258778 /*Entrance - Dirty - Web 02*/, 258777 /*Entrance - Dirty - Web 01*/, 265475 /*Blood Elf Lantern*/, 265427 /*Blood Elf Tent 2*/, 265430 /*Blood Elf Wagon 2*/, 266080 /*Moon Guard Tent 1*/, 244874 /*Portal to Suramar*/, 266129 /*Portal to Violet Citadel*/, 247849 /*Flavor Mail Tube*/, 280797 /*Mail Tube*/, 247858 /*Mail Tube*/, 246011 /*Portal to Shattrath*/, 267923 /*The Legend of Odyn*/, 267922 /*The Favored of Odyn*/, 271739 /*Nomi's Test Kitchen*/, 266618 /*Mail Pile*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(267261, 8, 9145, 'Spell Focus', '', '', '', 1, 1913, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Spell Focus
(254156, 7, 36447, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(254157, 7, 36447, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Bench
(266147, 5, 9050, 'High Elf Banner 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- High Elf Banner 2
(266146, 5, 9049, 'High Elf Banner 1', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- High Elf Banner 1
(265417, 5, 9176, 'Night Elf Single Tent 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Single Tent 2
(266145, 5, 39024, 'Kirin Tor Banner', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Kirin Tor Banner
(265479, 5, 29654, 'Night Elf Cart', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Cart
(265418, 5, 9177, 'Night Elf Single Tent 1', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Single Tent 1
(265481, 5, 8518, 'Night Elf Barrel', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Barrel
(265478, 5, 6035, 'Night Elf Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Crate
(265429, 5, 38822, 'Blood Elf Tent 4', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Tent 4
(266125, 5, 6956, 'Portal to Silvermoon', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Silvermoon
(265428, 5, 38821, 'Blood Elf Tent 3', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Tent 3
(265424, 5, 6794, 'Blood Elf Banner 1', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Banner 1
(265482, 5, 6394, 'Flagpole', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Flagpole
(265480, 5, 6390, 'Night Elf Banner 3', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Banner 3
(265426, 5, 13602, 'Blood Elf Ballista 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Ballista 2
(265422, 5, 8616, 'Night Elf Banner 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Night Elf Banner 2
(265425, 5, 6796, 'Blood Elf Banner 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Banner 2
(251887, 5, 31862, 'Web Trail', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Web Trail
(251423, 5, 13469, 'Battered Shotgun', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Battered Shotgun
(240356, 5, 9011, 'Unbound Rift', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Unbound Rift
(266008, 5, 36224, 'Teleport Pad', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Teleport Pad
(258810, 5, 36390, 'Main Chamber - 3 - Dirty - Rubble 02', '', '', '', 0.73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Dirty - Rubble 02
(255360, 5, 10418, 'Rear Chamber - Dirty - Web 23', '', '', '', 0.5147183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 23
(255366, 5, 10416, 'Rear Chamber - Dirty - Web 17', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 17
(255362, 5, 10418, 'Rear Chamber - Dirty - Web 13', '', '', '', 0.5147181, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 13
(255355, 5, 10418, 'Rear Chamber - Dirty - Web 09', '', '', '', 0.6850887, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 09
(255356, 5, 10418, 'Rear Chamber - Dirty - Web 18', '', '', '', 1.011192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 18
(255353, 5, 10418, 'Rear Chamber - Dirty - Web 16', '', '', '', 0.6929428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 16
(255364, 5, 36391, 'Rear Chamber - Dirty - Web 27', '', '', '', 0.539808, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 27
(253810, 5, 36391, 'Rear Chamber - Dirty - Web 26', '', '', '', 0.539808, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 26
(255365, 5, 36391, 'Rear Chamber - Dirty - Web 12', '', '', '', 0.6469489, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 12
(253809, 5, 36391, 'Rear Chamber - Dirty - Web 26', '', '', '', 0.6469489, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 26
(255359, 5, 10418, 'Rear Chamber - Dirty - Web 14', '', '', '', 0.6413692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 14
(255363, 5, 31861, 'Rear Chamber - Dirty - Web 22', '', '', '', 0.981845, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 22
(253811, 5, 31861, 'Rear Chamber - Dirty - Web 25', '', '', '', 0.9818454, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 25
(255361, 5, 10418, 'Rear Chamber - Dirty - Web 28', '', '', '', 0.3659957, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 28
(255374, 5, 10418, 'Rear Chamber - Dirty - Web 10', '', '', '', 1.24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 10
(255367, 5, 10416, 'Rear Chamber - Dirty - Web 11', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 11
(255372, 5, 10418, 'Rear Chamber - Dirty - Web 08', '', '', '', 1.24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 08
(255354, 5, 10418, 'Rear Chamber - Dirty - Web 15', '', '', '', 0.9668549, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 15
(255357, 5, 10418, 'Rear Chamber - Dirty - Web 07', '', '', '', 0.7778844, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 07
(255358, 5, 10418, 'Rear Chamber - Dirty - Web 06', '', '', '', 1.026243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 06
(255371, 5, 10417, 'Rear Chamber - Dirty - Web 21', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 21
(255373, 5, 10418, 'Rear Chamber - Dirty - Web 20', '', '', '', 1.24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 20
(253876, 5, 30914, 'Right Chamber - H - Dirty - Wrecked Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - H - Dirty - Wrecked Table
(255370, 5, 10417, 'Rear Chamber - Dirty - Web 02', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 02
(253912, 5, 36407, 'Right Chamber - H - Dirty - Rug', '', '', '', 1.73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - H - Dirty - Rug
(253877, 5, 30914, 'Right Chamber - H - Dirty - Wrecked Table 02', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - H - Dirty - Wrecked Table 02
(253878, 5, 36393, 'Right Chamber - H - Dirty - Rubble', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - H - Dirty - Rubble
(255375, 5, 36391, 'Rear Chamber - Dirty - Web 28', '', '', '', 1.376949, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 28
(255368, 5, 10416, 'Rear Chamber - Dirty - Web 05', '', '', '', 0.9999994, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 05
(255377, 5, 31862, 'Doodad_6td_web_a002', '', '', '', 0.8884844, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_6td_web_a002
(255379, 5, 10417, 'Rear Chamber - Dirty - Web 01', '', '', '', 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 01
(255369, 5, 10416, 'Rear Chamber - Dirty - Web 04', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 04
(255378, 5, 31862, 'Rear Chamber - Dirty - Web 19', '', '', '', 0.8884839, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 19
(255376, 5, 10417, 'Rear Chamber - Dirty - Web 30', '', '', '', 0.9000002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 30
(253824, 5, 31863, 'Central Chamber - Dirty - Web 09', '', '', '', 2.74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Central Chamber - Dirty - Web 09
(253825, 5, 31863, 'Rear Chamber - Dirty - Web 29', '', '', '', 2.470001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Rear Chamber - Dirty - Web 29
(258840, 5, 36405, 'Main Chamber - 6 - Dirty - Rubble 01', '', '', '', 0.99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 6 - Dirty - Rubble 01
(258832, 5, 36398, 'Main Chamber - 5 - Dirty - Rubble 01', '', '', '', 0.54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 5 - Dirty - Rubble 01
(258820, 5, 36393, 'Main Chamber - 5 - Dirty - Rubble 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 5 - Dirty - Rubble 03
(258837, 5, 36393, 'Main Chamber - 6 - Dirty - Rubble 02', '', '', '', 1.11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 6 - Dirty - Rubble 02
(258835, 5, 36397, 'Doodad_7ne_nightelf_urnlarge01_wrecked003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_urnlarge01_wrecked003
(258838, 5, 37648, 'Doodad_7ne_ancient_rubble006', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_ancient_rubble006
(258836, 5, 36405, 'Doodad_7ne_nightelf_brazier02_wrecked003', '', '', '', 1.21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_brazier02_wrecked003
(253840, 5, 36397, 'Right Chamber - J - Dirty - Urn Wrecked', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Dirty - Urn Wrecked
(253829, 5, 31862, 'Right Chamber - F - Dirty - Web 03', '', '', '', 0.888484, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - F - Dirty - Web 03
(258821, 5, 36392, 'Main Chamber - 4 - Dirty - Rubble 08', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 4 - Dirty - Rubble 08
(253841, 5, 36398, 'Right Chamber - J - Dirty - Ruin 01', '', '', '', 0.6700003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Dirty - Ruin 01
(258815, 5, 24061, 'Main Chamber - 4 - Dirty - Rubble 07', '', '', '', 0.43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 4 - Dirty - Rubble 07
(253839, 5, 36396, 'Right Chamber - J - Dirty - Brazier Wrecked', '', '', '', 0.8199999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Dirty - Brazier Wrecked
(253842, 5, 36399, 'Right Chamber - J - Dirty - Ruin 02', '', '', '', 0.6800002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - J - Dirty - Ruin 02
(253901, 5, 36404, 'Right Chamber - D - Dirty - Rubble', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - D - Dirty - Rubble
(253844, 5, 36397, 'Right Chamber - K - Dirty - Urn Wrecked', '', '', '', 1.06, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - K - Dirty - Urn Wrecked
(253843, 5, 36372, 'Right Chamber - K - Dirty - Bookcase', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - K - Dirty - Bookcase
(253813, 5, 36372, 'Right Chamber - C - Dirty - Bookcase 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Bookcase 02
(253812, 5, 36372, 'Right Chamber - C - Dirty - Bookshelf', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Bookshelf
(258813, 5, 24061, 'Doodad_6dr_draenei_rubble_glass002', '', '', '', 0.76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_6dr_draenei_rubble_glass002
(253898, 5, 36389, 'Right Chamber - C - Dirty - Wrecked Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Wrecked Table
(253897, 5, 35706, 'Right Chamber - C - Dirty - Scroll 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Scroll 02
(253896, 5, 36401, 'Right Chamber - C - Dirty - Book', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Book
(258812, 5, 36390, 'Doodad_7ne_nightelf_glassrubble002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_7ne_nightelf_glassrubble002
(253917, 5, 36372, 'Right Chamber - B - Dirty - Bookcase 02', '', '', '', 0.9200002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Dirty - Bookcase 02
(253895, 5, 36400, 'Right Chamber - C - Dirty - Scroll 05', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - C - Dirty - Scroll 05
(258834, 5, 37648, 'Main Chamber - 2 - Dirty - Rubble 02', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Dirty - Rubble 02
(258811, 5, 24061, 'Main Chamber - 3 - Dirty - Rubble 01', '', '', '', 0.49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 3 - Dirty - Rubble 01
(258839, 5, 36393, 'Main Chamber - 8 - Dirty - Rubble 02', '', '', '', 1.29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 8 - Dirty - Rubble 02
(258818, 5, 36397, 'Main Chamber - 8 - Dirty - Rubble 01', '', '', '', 0.7600002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 8 - Dirty - Rubble 01
(258806, 5, 37648, 'Main Chamber - 1 - Dirty - Rubble 04', '', '', '', 0.5700001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 04
(258805, 5, 36397, 'Main Chamber - 1 - Dirty - Rubble 01', '', '', '', 0.7599998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 01
(253914, 5, 36372, 'Right Chamber - B - Dirty - Bookcase', '', '', '', 0.9999998, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - B - Dirty - Bookcase
(253814, 5, 36394, 'Right Chamber - A - Dirty - Wrecked Bench', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Right Chamber - A - Dirty - Wrecked Bench
(258833, 5, 37649, 'Main Chamber - 2 - Dirty - Rubble 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 2 - Dirty - Rubble 01
(258817, 5, 36390, 'Main Chamber - 1 - Dirty - Rubble 02', '', '', '', 0.73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 02
(258816, 5, 24061, 'Main Chamber - 1 - Dirty - Rubble 03', '', '', '', 0.4900001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 03
(258814, 5, 37649, 'Main Chamber - 1 - Dirty - Rubble 05', '', '', '', 0.6200002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 05
(258804, 5, 36398, 'Main Chamber - 1 - Dirty - Rubble 06', '', '', '', 0.54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 06
(258803, 5, 36399, 'Main Chamber - 1 - Dirty - Rubble 07', '', '', '', 0.54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Main Chamber - 1 - Dirty - Rubble 07
(258784, 5, 10418, 'Entrance - Dirty - Web 18', '', '', '', 1.035328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 18
(258764, 5, 10418, 'Entrance - Dirty - Web 06', '', '', '', 1.051044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 06
(253835, 5, 31863, 'Entrance - Dirty - Web 29', '', '', '', 2.309999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 29
(253833, 5, 36395, 'Entrance - Dirty - Web 28', '', '', '', 0.7700002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 28
(258785, 5, 10418, 'Entrance - Dirty - Web 04', '', '', '', 1.234083, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 04
(258782, 5, 10418, 'Entrance - Dirty - Web 05', '', '', '', 1.051044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 05
(258783, 5, 10418, 'Entrance - Dirty - Web 33', '', '', '', 1.035328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 33
(258788, 5, 10418, 'Entrance - Dirty - Web 07', '', '', '', 1.183239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 07
(258757, 5, 10418, 'Entrance - Dirty - Web 19', '', '', '', 0.8817681, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 19
(258758, 5, 10418, 'Entrance - Dirty - Web 20', '', '', '', 0.8817675, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 20
(258760, 5, 10418, 'Entrance - Dirty - Web 15', '', '', '', 0.8817679, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 15
(258756, 5, 10418, 'Doodad_KarazahnWeb718', '', '', '', 0.7156047, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Doodad_KarazahnWeb718
(258796, 5, 10418, 'Entrance - Dirty - Web 34', '', '', '', 0.8817674, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 34
(258778, 5, 10418, 'Entrance - Dirty - Web 02', '', '', '', 1.20595, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 02
(258777, 5, 10418, 'Entrance - Dirty - Web 01', '', '', '', 1.205949, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Entrance - Dirty - Web 01
(265475, 5, 7084, 'Blood Elf Lantern', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Lantern
(265427, 5, 10877, 'Blood Elf Tent 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Tent 2
(265430, 5, 17197, 'Blood Elf Wagon 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Blood Elf Wagon 2
(266080, 5, 38818, 'Moon Guard Tent 1', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Moon Guard Tent 1
(244874, 22, 36654, 'Portal to Suramar', 'questinteract', '', '', 1, 193590, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Suramar
(266129, 22, 8111, 'Portal to Violet Citadel', 'interact', '', '', 1, 229754, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Violet Citadel
(247849, 5, 32410, 'Flavor Mail Tube', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Flavor Mail Tube
(280797, 10, 32409, 'Mail Tube', '', '', '', 1.387, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 206277, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mail Tube
(247858, 10, 32409, 'Mail Tube', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 206277, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Mail Tube
(246011, 22, 7146, 'Portal to Shattrath', '', '', '', 1, 35718, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Portal to Shattrath
(267923, 8, 9510, 'The Legend of Odyn', '', '', '', 1, 1915, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- The Legend of Odyn
(267922, 8, 9510, 'The Favored of Odyn', '', '', '', 1, 1914, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- The Favored of Odyn
(271739, 8, 9510, 'Nomi''s Test Kitchen', '', '', '', 1, 1921, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996), -- Nomi's Test Kitchen
(266618, 5, 39238, 'Mail Pile', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25996); -- Mail Pile

UPDATE `gameobject_template` SET `castBarCaption`='Overcharging', `VerifiedBuild`=25996 WHERE `entry`=246297; -- Arcane Coil
UPDATE `gameobject_template` SET `name`='Ancient Console', `VerifiedBuild`=25996 WHERE `entry`=248555; -- Ancient Console
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266432; -- Arcfence Post
UPDATE `gameobject_template` SET `castBarCaption`='Overcharging', `VerifiedBuild`=25996 WHERE `entry`=246328; -- Arcane Coil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266783; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266827; -- Web
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266805; -- Web
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266795; -- Book
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266791; -- Scrolls
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266787; -- Candles
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266785; -- Candles
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266778; -- Bookshelf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266776; -- Bookshelf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266773; -- Book
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266772; -- Book
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266771; -- Book
UPDATE `gameobject_template` SET `name`='Teleporter', `VerifiedBuild`=25996 WHERE `entry`=251618; -- Teleporter
UPDATE `gameobject_template` SET `type`=3, `displayId`=34597, `IconName`='questinteract', `castBarCaption`='Collecting', `Data0`=1691, `Data2`=1, `Data14`=19676, `Data30`=64114, `VerifiedBuild`=25996 WHERE `entry`=246225; -- Weathered Telemancy Beacon
UPDATE `gameobject_template` SET `type`=10, `displayId`=33856, `castBarCaption`='Activating', `Data0`=1691, `Data3`=1, `Data10`=199275, `Data14`=27700, `Data18`=1, `Data20`=1, `Data22`=45310, `Data23`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=245950; -- Fountain
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254164; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254162; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254159; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254165; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254163; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=254161; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254160; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=254158; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=245948; -- Breakfast Nook
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=245947; -- Telemetry Lab
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=245942; -- Garden
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=245928; -- Workshop
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=246229; -- Cracked Warpsleeve
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=221482; -- PA Mug Bamboo 06
UPDATE `gameobject_template` SET `name`='Gate', `VerifiedBuild`=25996 WHERE `entry`=251617; -- Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266793; -- Table
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266789; -- Table
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266784; -- Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266781; -- Pylon
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266780; -- Books
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266779; -- Bookshelf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266777; -- Bookshelf
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266775; -- Table
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266774; -- Table
UPDATE `gameobject_template` SET `type`=10, `displayId`=36343, `IconName`='questinteract', `castBarCaption`='Activating', `size`=0.6, `Data0`=1691, `Data10`=229575, `Data14`=27700, `Data20`=1, `Data22`=46351, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266056; -- Nightborne Teleporter
UPDATE `gameobject_template` SET `type`=10, `displayId`=33856, `castBarCaption`='Activating', `Data0`=1691, `Data3`=1, `Data10`=199267, `Data14`=27700, `Data18`=1, `Data20`=1, `Data22`=45310, `Data23`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=245954; -- Fountain
UPDATE `gameobject_template` SET `type`=10, `displayId`=33857, `castBarCaption`='Activating', `Data0`=1691, `Data3`=1, `Data10`=199266, `Data14`=27700, `Data18`=1, `Data20`=1, `Data22`=45310, `Data23`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=245927; -- Warp Lab
UPDATE `gameobject_template` SET `type`=10, `displayId`=33858, `castBarCaption`='Activating', `Data0`=1691, `Data3`=1, `Data10`=199265, `Data14`=27700, `Data18`=1, `Data20`=1, `Data22`=45310, `Data23`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=245926; -- Library
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=254290; -- Aquarium of Wonders
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=245925; -- Garden
UPDATE `gameobject_template` SET `castBarCaption`='Activating', `VerifiedBuild`=25996 WHERE `entry`=246237; -- Test Chamber
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258108; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258107; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258106; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258105; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258104; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258103; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258100; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258099; -- Chair
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=70259, `Data3`=0, `Data6`=30, `Data9`=24982, `Data13`=0, `Data14`=228183, `Data18`=10, `Data19`=1, `Data26`=0, `Data30`=0, `VerifiedBuild`=25996 WHERE `entry`=260498; -- Leypetal Blossom
UPDATE `gameobject_template` SET `name`='Feeding Post', `VerifiedBuild`=25996 WHERE `entry`=251621; -- Feeding Post
UPDATE `gameobject_template` SET `type`=10, `displayId`=36343, `size`=0.3, `Data3`=3000, `Data25`=1, `VerifiedBuild`=25996 WHERE `entry`=266055; -- Stasis Pad
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258159; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258158; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258155; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258154; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258153; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258152; -- Chair
UPDATE `gameobject_template` SET `type`=10, `displayId`=39123, `Data3`=3000, `VerifiedBuild`=25996 WHERE `entry`=266433; -- Arcshaper Rune
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258157; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=258156; -- Chair
UPDATE `gameobject_template` SET `type`=10, `displayId`=39016, `IconName`='questinteract', `unk1`='Removing', `size`=0.25, `Data0`=43, `Data3`=1, `Data10`=229765, `Data15`=22741, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266126; -- "Your Ancestors"
UPDATE `gameobject_template` SET `type`=10, `displayId`=9680, `IconName`='questinteract', `unk1`='Removing', `size`=0.35, `Data0`=43, `Data3`=1, `Data10`=229765, `Data15`=22741, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266127; -- "Just wanted you to feel at home, mon."
UPDATE `gameobject_template` SET `type`=10, `displayId`=39053, `IconName`='questinteract', `unk1`='Removing', `size`=0.05, `Data0`=43, `Data3`=1, `Data10`=229765, `Data15`=22741, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266131; -- Replacement Sunwell
UPDATE `gameobject_template` SET `type`=10, `displayId`=39017, `IconName`='questinteract', `unk1`='Removing', `size`=0.5, `Data0`=43, `Data2`=55412, `Data3`=1, `Data10`=229765, `Data15`=22741, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266128; -- "We found your mounts..."
UPDATE `gameobject_template` SET `Data1`=60576, `VerifiedBuild`=25996 WHERE `entry`=253280; -- Leystone Seam
UPDATE `gameobject_template` SET `type`=10, `displayId`=10461, `Data3`=10000, `VerifiedBuild`=25996 WHERE `entry`=251874; -- Wriggling Cocoon
UPDATE `gameobject_template` SET `type`=10, `displayId`=10461, `Data3`=10000, `VerifiedBuild`=25996 WHERE `entry`=247071; -- Wriggling Cocoon
UPDATE `gameobject_template` SET `type`=10, `displayId`=10461, `Data3`=10000, `VerifiedBuild`=25996 WHERE `entry`=251873; -- Wriggling Cocoon
UPDATE `gameobject_template` SET `type`=10, `displayId`=10461, `Data3`=10000, `VerifiedBuild`=25996 WHERE `entry`=251354; -- Wriggling Cocoon
UPDATE `gameobject_template` SET `type`=10, `displayId`=30824, `IconName`='questinteract', `castBarCaption`='Marking', `Data0`=43, `Data3`=1, `Data10`=215541, `Data14`=81646, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=251334; -- Conspicuous Sand Pile
UPDATE `gameobject_template` SET `type`=10, `displayId`=30824, `IconName`='questinteract', `castBarCaption`='Marking', `Data0`=43, `Data3`=1, `Data10`=216119, `Data14`=81646, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=251324; -- Conspicuous Sand Pile
UPDATE `gameobject_template` SET `type`=10, `displayId`=20, `IconName`='questinteract', `castBarCaption`='Marking', `Data0`=43, `Data3`=1, `Data10`=216119, `Data14`=81646, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=251329; -- Conspicuous Dirt Pile
UPDATE `gameobject_template` SET `type`=3, `displayId`=33265, `castBarCaption`='Opening', `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data30`=59652, `RequiredLevel`=98, `VerifiedBuild`=25996 WHERE `entry`=239803; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251563; -- Small Ley Crystal
UPDATE `gameobject_template` SET `name`='Ancient Door', `VerifiedBuild`=25996 WHERE `entry`=250262; -- Ancient Door
UPDATE `gameobject_template` SET `castBarCaption`='Attuning', `VerifiedBuild`=25996 WHERE `entry`=252560; -- Hungering Orb
UPDATE `gameobject_template` SET `type`=10, `displayId`=34031, `IconName`='questinteract', `size`=0.3, `Data0`=43, `Data2`=51126, `Data3`=3000, `Data10`=212808, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250289; -- Clam
UPDATE `gameobject_template` SET `type`=10, `displayId`=9559, `IconName`='questinteract', `size`=0.05, `Data0`=43, `Data3`=3000, `Data10`=212810, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250288; -- Speckled Pearl
UPDATE `gameobject_template` SET `type`=10, `displayId`=34028, `IconName`='questinteract', `Data0`=43, `Data2`=51123, `Data3`=3000, `Data10`=212809, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250285; -- Driftwood
UPDATE `gameobject_template` SET `type`=10, `displayId`=34033, `IconName`='questinteract', `size`=0.3, `Data0`=43, `Data2`=51126, `Data3`=3000, `Data10`=212808, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250291; -- Clam
UPDATE `gameobject_template` SET `type`=10, `displayId`=34026, `IconName`='questinteract', `size`=0.6, `Data0`=43, `Data2`=51125, `Data3`=3000, `Data10`=212811, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250286; -- Seaweed
UPDATE `gameobject_template` SET `type`=10, `displayId`=34032, `IconName`='questinteract', `size`=0.3, `Data0`=43, `Data2`=51126, `Data3`=3000, `Data10`=212808, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250290; -- Clam
UPDATE `gameobject_template` SET `type`=10, `displayId`=34029, `IconName`='questinteract', `size`=0.6, `Data0`=43, `Data2`=51125, `Data3`=3000, `Data10`=212811, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250282; -- Seaweed
UPDATE `gameobject_template` SET `type`=10, `displayId`=34030, `IconName`='questinteract', `size`=0.6, `Data0`=43, `Data2`=51125, `Data3`=3000, `Data10`=212811, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250287; -- Seaweed
UPDATE `gameobject_template` SET `type`=10, `displayId`=34027, `IconName`='questinteract', `Data0`=43, `Data2`=51123, `Data3`=3000, `Data10`=212809, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=250284; -- Driftwood
UPDATE `gameobject_template` SET `type`=3, `displayId`=31287, `castBarCaption`='Opening', `size`=0.75, `Data0`=57, `Data2`=1, `Data13`=1, `Data14`=21400, `Data18`=110, `Data19`=3, `Data29`=1572, `Data30`=67917, `RequiredLevel`=110, `VerifiedBuild`=25996 WHERE `entry`=252812; -- Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=247694; -- Kel'danath's Knapsack
UPDATE `gameobject_template` SET `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=248407; -- Kel'danath's Manaflask
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252263; -- Leyline Feed
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252809; -- Treasure Chest
UPDATE `gameobject_template` SET `Data1`=68513, `VerifiedBuild`=25996 WHERE `entry`=245324; -- Rich Leystone Deposit
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=252810; -- Small Treasure Chest
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=251489; -- Cage
UPDATE `gameobject_template` SET `castBarCaption`='Opening', `VerifiedBuild`=25996 WHERE `entry`=257291; -- Nightborne Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252262; -- Leyline Feed
UPDATE `gameobject_template` SET `type`=3, `displayId`=28519, `castBarCaption`='Gathering', `size`=0.85, `Data0`=2608, `Data13`=1, `Data14`=24982, `Data18`=110, `Data19`=3, `Data26`=228183, `Data30`=70185, `VerifiedBuild`=25996 WHERE `entry`=251416; -- Ancient Mana Chunk
UPDATE `gameobject_template` SET `Data1`=60585, `VerifiedBuild`=25996 WHERE `entry`=241743; -- Felslate Deposit
UPDATE `gameobject_template` SET `name`='Ley Crystal Small B01', `VerifiedBuild`=25996 WHERE `entry`=251417; -- Ley Crystal Small B01
UPDATE `gameobject_template` SET `name`='Ley Crystal Small C01', `VerifiedBuild`=25996 WHERE `entry`=251418; -- Ley Crystal Small C01
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `VerifiedBuild`=25996 WHERE `entry`=252772; -- Ancient Mana Chunk
UPDATE `gameobject_template` SET `type`=10, `displayId`=34726, `IconName`='questinteract', `castBarCaption`='Inspecting', `size`=1.5, `Data0`=1690, `Data3`=1, `Data10`=196185, `Data14`=45353, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=245327; -- Kel'danath's Notes
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=245328; -- Enchanted Scroll
UPDATE `gameobject_template` SET `type`=3, `displayId`=28519, `castBarCaption`='Gathering', `size`=0.85, `Data0`=2608, `Data13`=1, `Data14`=24982, `Data18`=110, `Data19`=3, `Data26`=228183, `Data30`=70186, `VerifiedBuild`=25996 WHERE `entry`=260247; -- Ancient Mana Chunk
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=244778; -- Starlight Rose
UPDATE `gameobject_template` SET `Data1`=60590, `VerifiedBuild`=25996 WHERE `entry`=255344; -- Felslate Seam
UPDATE `gameobject_template` SET `type`=3, `displayId`=26437, `castBarCaption`='Gathering', `size`=0.6, `Data0`=2608, `Data13`=1, `Data14`=24982, `Data18`=110, `Data19`=3, `Data26`=228183, `Data30`=70187, `VerifiedBuild`=25996 WHERE `entry`=260248; -- Ancient Mana Shard
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `VerifiedBuild`=25996 WHERE `entry`=252774; -- Ancient Mana Crystal
UPDATE `gameobject_template` SET `type`=3, `displayId`=26437, `castBarCaption`='Gathering', `size`=0.6, `Data0`=2608, `Data13`=1, `Data14`=24982, `Data18`=110, `Data19`=3, `Data26`=228183, `Data30`=70188, `VerifiedBuild`=25996 WHERE `entry`=260249; -- Ancient Mana Shard
UPDATE `gameobject_template` SET `name`='Teleportation Nexus', `VerifiedBuild`=25996 WHERE `entry`=253144; -- Teleportation Nexus
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `VerifiedBuild`=25996 WHERE `entry`=252408; -- Ancient Mana Shard
UPDATE `gameobject_template` SET `name`='Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath003', `VerifiedBuild`=25996 WHERE `entry`=265469; -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath003
UPDATE `gameobject_template` SET `name`='Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_ShortSouth01', `VerifiedBuild`=25996 WHERE `entry`=259929; -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_ShortSouth01
UPDATE `gameobject_template` SET `name`='Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath004', `VerifiedBuild`=25996 WHERE `entry`=265470; -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath004
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254238; -- Gondola
UPDATE `gameobject_template` SET `name`='Door', `VerifiedBuild`=25996 WHERE `entry`=251844; -- Door
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254239; -- Gondola
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254276; -- Gondola
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254145; -- Gondola
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254149; -- Gondola
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254148; -- Gondola
UPDATE `gameobject_template` SET `name`='Gondola', `VerifiedBuild`=25996 WHERE `entry`=254147; -- Gondola
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266919; -- The Nighthold Portcullis
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Glass 02', `VerifiedBuild`=25996 WHERE `entry`=253874; -- Right Chamber - H - Dirty - Glass 02
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Book 02', `VerifiedBuild`=25996 WHERE `entry`=253872; -- Right Chamber - H - Dirty - Book 02
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Scroll', `VerifiedBuild`=25996 WHERE `entry`=253880; -- Right Chamber - H - Dirty - Scroll
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Book 03', `VerifiedBuild`=25996 WHERE `entry`=253913; -- Right Chamber - H - Dirty - Book 03
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Orb', `VerifiedBuild`=25996 WHERE `entry`=253875; -- Right Chamber - H - Dirty - Orb
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Book 01', `VerifiedBuild`=25996 WHERE `entry`=253871; -- Right Chamber - H - Dirty - Book 01
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Glass 01', `VerifiedBuild`=25996 WHERE `entry`=253873; -- Right Chamber - H - Dirty - Glass 01
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Paper 01', `VerifiedBuild`=25996 WHERE `entry`=253883; -- Right Chamber - H - Dirty - Paper 01
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Scattered Papers', `VerifiedBuild`=25996 WHERE `entry`=253882; -- Right Chamber - H - Dirty - Scattered Papers
UPDATE `gameobject_template` SET `name`='Right Chamber - H - Dirty - Paper 02', `VerifiedBuild`=25996 WHERE `entry`=253884; -- Right Chamber - H - Dirty - Paper 02
UPDATE `gameobject_template` SET `name`='Doodad_6sm_willowtree_sparkle001', `VerifiedBuild`=25996 WHERE `entry`=258343; -- Doodad_6sm_willowtree_sparkle001
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb772', `VerifiedBuild`=25996 WHERE `entry`=258733; -- Doodad_KarazahnWeb772
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb728', `VerifiedBuild`=25996 WHERE `entry`=258726; -- Doodad_KarazahnWeb728
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb731', `VerifiedBuild`=25996 WHERE `entry`=258725; -- Doodad_KarazahnWeb731
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank006', `VerifiedBuild`=25996 WHERE `entry`=258801; -- Doodad_7vr_vrykul_roadplank006
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb759', `VerifiedBuild`=25996 WHERE `entry`=258724; -- Doodad_KarazahnWeb759
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb737', `VerifiedBuild`=25996 WHERE `entry`=258722; -- Doodad_KarazahnWeb737
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank005', `VerifiedBuild`=25996 WHERE `entry`=258802; -- Doodad_7vr_vrykul_roadplank005
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank004', `VerifiedBuild`=25996 WHERE `entry`=258800; -- Doodad_7vr_vrykul_roadplank004
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank003', `VerifiedBuild`=25996 WHERE `entry`=258799; -- Doodad_7vr_vrykul_roadplank003
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank001', `VerifiedBuild`=25996 WHERE `entry`=258797; -- Doodad_7vr_vrykul_roadplank001
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb746', `VerifiedBuild`=25996 WHERE `entry`=258742; -- Doodad_KarazahnWeb746
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb730', `VerifiedBuild`=25996 WHERE `entry`=258723; -- Doodad_KarazahnWeb730
UPDATE `gameobject_template` SET `name`='Doodad_7vr_vrykul_roadplank002', `VerifiedBuild`=25996 WHERE `entry`=258798; -- Doodad_7vr_vrykul_roadplank002
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb769', `VerifiedBuild`=25996 WHERE `entry`=258736; -- Doodad_KarazahnWeb769
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb758', `VerifiedBuild`=25996 WHERE `entry`=258737; -- Doodad_KarazahnWeb758
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb723', `VerifiedBuild`=25996 WHERE `entry`=258734; -- Doodad_KarazahnWeb723
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb726', `VerifiedBuild`=25996 WHERE `entry`=258727; -- Doodad_KarazahnWeb726
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb766', `VerifiedBuild`=25996 WHERE `entry`=258750; -- Doodad_KarazahnWeb766
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb752', `VerifiedBuild`=25996 WHERE `entry`=258749; -- Doodad_KarazahnWeb752
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb750', `VerifiedBuild`=25996 WHERE `entry`=258752; -- Doodad_KarazahnWeb750
UPDATE `gameobject_template` SET `name`='Doodad_7sr_ivy_b010', `VerifiedBuild`=25996 WHERE `entry`=253739; -- Doodad_7sr_ivy_b010
UPDATE `gameobject_template` SET `name`='Doodad_7sr_ivy_a005', `VerifiedBuild`=25996 WHERE `entry`=253738; -- Doodad_7sr_ivy_a005
UPDATE `gameobject_template` SET `name`='Right Chamber - Dirty - Web 03', `VerifiedBuild`=25996 WHERE `entry`=253806; -- Right Chamber - Dirty - Web 03
UPDATE `gameobject_template` SET `name`='Right Chamber - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253807; -- Right Chamber - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253808; -- Right Chamber - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scroll 02', `VerifiedBuild`=25996 WHERE `entry`=253881; -- Central Chamber - Dirty - Scroll 02
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Loose Paper 03', `VerifiedBuild`=25996 WHERE `entry`=253885; -- Central Chamber - Dirty - Loose Paper 03
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Papers', `VerifiedBuild`=25996 WHERE `entry`=253785; -- Right Chamber - I - Dirty - Papers
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Glass 05', `VerifiedBuild`=25996 WHERE `entry`=253786; -- Right Chamber - I - Dirty - Glass 05
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Brazier', `VerifiedBuild`=25996 WHERE `entry`=253903; -- Right Chamber - I - Dirty - Brazier
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Glass 03', `VerifiedBuild`=25996 WHERE `entry`=253787; -- Right Chamber - I - Dirty - Glass 03
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 04', `VerifiedBuild`=25996 WHERE `entry`=253788; -- Right Chamber - I - Dirty - Scroll 04
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 02', `VerifiedBuild`=25996 WHERE `entry`=253891; -- Right Chamber - I - Dirty - Scroll 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Glass 02', `VerifiedBuild`=25996 WHERE `entry`=253789; -- Right Chamber - I - Dirty - Glass 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Table', `VerifiedBuild`=25996 WHERE `entry`=253904; -- Right Chamber - I - Dirty - Table
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253828; -- Right Chamber - I - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Paper 02', `VerifiedBuild`=25996 WHERE `entry`=253911; -- Right Chamber - I - Dirty - Paper 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Glass', `VerifiedBuild`=25996 WHERE `entry`=253905; -- Right Chamber - I - Dirty - Glass
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253890; -- Right Chamber - I - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253889; -- Right Chamber - I - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 03', `VerifiedBuild`=25996 WHERE `entry`=253906; -- Right Chamber - I - Dirty - Scroll 03
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Loose Paper 04', `VerifiedBuild`=25996 WHERE `entry`=253909; -- Central Chamber - Dirty - Loose Paper 04
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Glass 04', `VerifiedBuild`=25996 WHERE `entry`=253791; -- Right Chamber - I - Dirty - Glass 04
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - OldBook 01', `VerifiedBuild`=25996 WHERE `entry`=253907; -- Right Chamber - I - Dirty - OldBook 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253887; -- Right Chamber - I - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Scroll 02', `VerifiedBuild`=25996 WHERE `entry`=253888; -- Right Chamber - I - Dirty - Scroll 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - OldBook 02', `VerifiedBuild`=25996 WHERE `entry`=253908; -- Right Chamber - I - Dirty - OldBook 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253827; -- Right Chamber - I - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Paper 01', `VerifiedBuild`=25996 WHERE `entry`=253910; -- Right Chamber - I - Dirty - Paper 01
UPDATE `gameobject_template` SET `name`='Right Chamber - I - Dirty - Paper 03', `VerifiedBuild`=25996 WHERE `entry`=253790; -- Right Chamber - I - Dirty - Paper 03
UPDATE `gameobject_template` SET `name`='Doodad_7sr_ivy_a002', `VerifiedBuild`=25996 WHERE `entry`=253737; -- Doodad_7sr_ivy_a002
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253816; -- Right Chamber - G - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Web 03', `VerifiedBuild`=25996 WHERE `entry`=253830; -- Right Chamber - G - Dirty - Web 03
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Wrecked bench', `VerifiedBuild`=25996 WHERE `entry`=253879; -- Right Chamber - G - Dirty - Wrecked bench
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Rubble 02', `VerifiedBuild`=25996 WHERE `entry`=253865; -- Right Chamber - G - Dirty - Rubble 02
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253817; -- Right Chamber - G - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - J - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253838; -- Right Chamber - J - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Wrecked Table', `VerifiedBuild`=25996 WHERE `entry`=253867; -- Right Chamber - G - Dirty - Wrecked Table
UPDATE `gameobject_template` SET `name`='Right Chamber - J - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253837; -- Right Chamber - J - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Book', `VerifiedBuild`=25996 WHERE `entry`=253866; -- Right Chamber - G - Dirty - Book
UPDATE `gameobject_template` SET `name`='Right Chamber - F - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253834; -- Right Chamber - F - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - F - Dirty - Wrecked Table', `VerifiedBuild`=25996 WHERE `entry`=253782; -- Right Chamber - F - Dirty - Wrecked Table
UPDATE `gameobject_template` SET `name`='Right Chamber - F - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253784; -- Right Chamber - F - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - G - Dirty - Rubble 01', `VerifiedBuild`=25996 WHERE `entry`=253864; -- Right Chamber - G - Dirty - Rubble 01
UPDATE `gameobject_template` SET `name`='Leyline Marker 01', `VerifiedBuild`=25996 WHERE `entry`=247076; -- Leyline Marker 01
UPDATE `gameobject_template` SET `name`='Leyline Marker 02', `VerifiedBuild`=25996 WHERE `entry`=252307; -- Leyline Marker 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Bookcase 01', `VerifiedBuild`=25996 WHERE `entry`=253868; -- Right Chamber - E - Dirty - Bookcase 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253815; -- Right Chamber - E - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Scroll 02', `VerifiedBuild`=25996 WHERE `entry`=253862; -- Right Chamber - E - Dirty - Scroll 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Scroll 03', `VerifiedBuild`=25996 WHERE `entry`=253863; -- Right Chamber - E - Dirty - Scroll 03
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Loose Paper 05', `VerifiedBuild`=25996 WHERE `entry`=253860; -- Right Chamber - E - Dirty - Loose Paper 05
UPDATE `gameobject_template` SET `name`='Leyline Marker 03', `VerifiedBuild`=25996 WHERE `entry`=252308; -- Leyline Marker 03
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Loose Paper 01', `VerifiedBuild`=25996 WHERE `entry`=253854; -- Right Chamber - E - Dirty - Loose Paper 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Bookcase 02', `VerifiedBuild`=25996 WHERE `entry`=253869; -- Right Chamber - E - Dirty - Bookcase 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Glass Rubble 01', `VerifiedBuild`=25996 WHERE `entry`=253861; -- Right Chamber - E - Dirty - Glass Rubble 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Loose Paper 03', `VerifiedBuild`=25996 WHERE `entry`=253856; -- Right Chamber - E - Dirty - Loose Paper 03
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253857; -- Right Chamber - E - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Loose Paper 04', `VerifiedBuild`=25996 WHERE `entry`=253858; -- Right Chamber - E - Dirty - Loose Paper 04
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Scattered Papers', `VerifiedBuild`=25996 WHERE `entry`=253859; -- Right Chamber - E - Dirty - Scattered Papers
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253826; -- Right Chamber - E - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Book 01', `VerifiedBuild`=25996 WHERE `entry`=253853; -- Right Chamber - E - Dirty - Book 01
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Bookcase 03', `VerifiedBuild`=25996 WHERE `entry`=253870; -- Right Chamber - E - Dirty - Bookcase 03
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Scroll 04', `VerifiedBuild`=25996 WHERE `entry`=253852; -- Right Chamber - E - Dirty - Scroll 04
UPDATE `gameobject_template` SET `name`='Leyline Marker 09', `VerifiedBuild`=25996 WHERE `entry`=252314; -- Leyline Marker 09
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Loose Paper 02', `VerifiedBuild`=25996 WHERE `entry`=253855; -- Right Chamber - E - Dirty - Loose Paper 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Book 02', `VerifiedBuild`=25996 WHERE `entry`=253851; -- Right Chamber - E - Dirty - Book 02
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Glass Rubble 02', `VerifiedBuild`=25996 WHERE `entry`=253899; -- Right Chamber - E - Dirty - Glass Rubble 02
UPDATE `gameobject_template` SET `name`='Leyline Marker 04', `VerifiedBuild`=25996 WHERE `entry`=252309; -- Leyline Marker 04
UPDATE `gameobject_template` SET `name`='Right Chamber - E - Dirty - Glass Rubble 03', `VerifiedBuild`=25996 WHERE `entry`=253900; -- Right Chamber - E - Dirty - Glass Rubble 03
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Web 11', `VerifiedBuild`=25996 WHERE `entry`=253831; -- Central Chamber - Dirty - Web 11
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Dirty - Glass rubble 01', `VerifiedBuild`=25996 WHERE `entry`=253794; -- Right Chamber - K - Dirty - Glass rubble 01
UPDATE `gameobject_template` SET `name`='Right Chamber - D - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253902; -- Right Chamber - D - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Leyline Marker 05', `VerifiedBuild`=25996 WHERE `entry`=252310; -- Leyline Marker 05
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Dirty - Scroll', `VerifiedBuild`=25996 WHERE `entry`=253796; -- Right Chamber - K - Dirty - Scroll
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Dirty - Glass rubble 02', `VerifiedBuild`=25996 WHERE `entry`=253793; -- Right Chamber - K - Dirty - Glass rubble 02
UPDATE `gameobject_template` SET `name`='Right Chamber - K - Dirty - Loose Paper', `VerifiedBuild`=25996 WHERE `entry`=253795; -- Right Chamber - K - Dirty - Loose Paper
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Paper', `VerifiedBuild`=25996 WHERE `entry`=253893; -- Right Chamber - C - Dirty - Paper
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253894; -- Right Chamber - C - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scroll 02', `VerifiedBuild`=25996 WHERE `entry`=253849; -- Central Chamber - Dirty - Scroll 02
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Loose paper 01', `VerifiedBuild`=25996 WHERE `entry`=253804; -- Central Chamber - Dirty - Loose paper 01
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Scroll 03', `VerifiedBuild`=25996 WHERE `entry`=253916; -- Right Chamber - C - Dirty - Scroll 03
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Scroll 04', `VerifiedBuild`=25996 WHERE `entry`=253892; -- Right Chamber - C - Dirty - Scroll 04
UPDATE `gameobject_template` SET `name`='Right Chamber - D - Dirty - Glass rubble', `VerifiedBuild`=25996 WHERE `entry`=253886; -- Right Chamber - D - Dirty - Glass rubble
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scroll 03', `VerifiedBuild`=25996 WHERE `entry`=253848; -- Central Chamber - Dirty - Scroll 03
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scroll 01', `VerifiedBuild`=25996 WHERE `entry`=253847; -- Central Chamber - Dirty - Scroll 01
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253819; -- Right Chamber - C - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - C - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253818; -- Right Chamber - C - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Rubble 01', `VerifiedBuild`=25996 WHERE `entry`=253803; -- Central Chamber - Dirty - Rubble 01
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scattered papers', `VerifiedBuild`=25996 WHERE `entry`=253801; -- Central Chamber - Dirty - Scattered papers
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Rubble 02', `VerifiedBuild`=25996 WHERE `entry`=253800; -- Central Chamber - Dirty - Rubble 02
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Glass Rubble 03', `VerifiedBuild`=25996 WHERE `entry`=253797; -- Right Chamber - B - Dirty - Glass Rubble 03
UPDATE `gameobject_template` SET `type`=3, `displayId`=26437, `IconName`='questinteract', `castBarCaption`='Collecting', `size`=0.5, `Data0`=1691, `Data2`=1, `Data14`=19676, `Data30`=62699, `VerifiedBuild`=25996 WHERE `entry`=245126; -- Crystallized Ancient Mana
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Bookcase 04', `VerifiedBuild`=25996 WHERE `entry`=253919; -- Right Chamber - B - Dirty - Bookcase 04
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Book', `VerifiedBuild`=25996 WHERE `entry`=253915; -- Right Chamber - B - Dirty - Book
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Book', `VerifiedBuild`=25996 WHERE `entry`=253850; -- Central Chamber - Dirty - Book
UPDATE `gameobject_template` SET `name`='Right Chamber - A - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253832; -- Right Chamber - A - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Web 03', `VerifiedBuild`=25996 WHERE `entry`=253822; -- Right Chamber - B - Dirty - Web 03
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253821; -- Right Chamber - B - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Web 01', `VerifiedBuild`=25996 WHERE `entry`=253820; -- Right Chamber - B - Dirty - Web 01
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Scattered papers 02', `VerifiedBuild`=25996 WHERE `entry`=253802; -- Central Chamber - Dirty - Scattered papers 02
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Scattered Papers', `VerifiedBuild`=25996 WHERE `entry`=253799; -- Right Chamber - B - Dirty - Scattered Papers
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Scroll', `VerifiedBuild`=25996 WHERE `entry`=253798; -- Right Chamber - B - Dirty - Scroll
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Glass Rubble 02', `VerifiedBuild`=25996 WHERE `entry`=253792; -- Right Chamber - B - Dirty - Glass Rubble 02
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Glass Rubble 01', `VerifiedBuild`=25996 WHERE `entry`=253783; -- Right Chamber - B - Dirty - Glass Rubble 01
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Bookcase 03', `VerifiedBuild`=25996 WHERE `entry`=253918; -- Right Chamber - B - Dirty - Bookcase 03
UPDATE `gameobject_template` SET `name`='Right Chamber - A - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253836; -- Right Chamber - A - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Right Chamber - B - Dirty - Web 04', `VerifiedBuild`=25996 WHERE `entry`=253823; -- Right Chamber - B - Dirty - Web 04
UPDATE `gameobject_template` SET `name`='Leyline Marker 08', `VerifiedBuild`=25996 WHERE `entry`=252313; -- Leyline Marker 08
UPDATE `gameobject_template` SET `name`='Leyline Marker 07', `VerifiedBuild`=25996 WHERE `entry`=252312; -- Leyline Marker 07
UPDATE `gameobject_template` SET `name`='Leyline Marker 06', `VerifiedBuild`=25996 WHERE `entry`=252311; -- Leyline Marker 06
UPDATE `gameobject_template` SET `name`='Main Chamber - 8 - Dirty - Web 02', `VerifiedBuild`=25996 WHERE `entry`=253845; -- Main Chamber - 8 - Dirty - Web 02
UPDATE `gameobject_template` SET `name`='Central Chamber - Dirty - Web 10', `VerifiedBuild`=25996 WHERE `entry`=253846; -- Central Chamber - Dirty - Web 10
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 27', `VerifiedBuild`=25996 WHERE `entry`=258795; -- Entrance - Dirty - Web 27
UPDATE `gameobject_template` SET `name`='Doodad_6td_web_a005', `VerifiedBuild`=25996 WHERE `entry`=258794; -- Doodad_6td_web_a005
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 22', `VerifiedBuild`=25996 WHERE `entry`=258793; -- Entrance - Dirty - Web 22
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 26', `VerifiedBuild`=25996 WHERE `entry`=258761; -- Entrance - Dirty - Web 26
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb673', `VerifiedBuild`=25996 WHERE `entry`=258762; -- Doodad_KarazahnWeb673
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb676', `VerifiedBuild`=25996 WHERE `entry`=258781; -- Doodad_KarazahnWeb676
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb675', `VerifiedBuild`=25996 WHERE `entry`=258775; -- Doodad_KarazahnWeb675
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 21', `VerifiedBuild`=25996 WHERE `entry`=258780; -- Entrance - Dirty - Web 21
UPDATE `gameobject_template` SET `name`='Doodad_6td_web_a004', `VerifiedBuild`=25996 WHERE `entry`=258763; -- Doodad_6td_web_a004
UPDATE `gameobject_template` SET `name`='Teleporter', `VerifiedBuild`=25996 WHERE `entry`=246714; -- Teleporter
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 24', `VerifiedBuild`=25996 WHERE `entry`=258765; -- Entrance - Dirty - Web 24
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 25', `VerifiedBuild`=25996 WHERE `entry`=258773; -- Entrance - Dirty - Web 25
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 35', `VerifiedBuild`=25996 WHERE `entry`=258768; -- Entrance - Dirty - Web 35
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 09', `VerifiedBuild`=25996 WHERE `entry`=258791; -- Entrance - Dirty - Web 09
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 32', `VerifiedBuild`=25996 WHERE `entry`=258769; -- Entrance - Dirty - Web 32
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 16', `VerifiedBuild`=25996 WHERE `entry`=258787; -- Entrance - Dirty - Web 16
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 17', `VerifiedBuild`=25996 WHERE `entry`=258786; -- Entrance - Dirty - Web 17
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 14', `VerifiedBuild`=25996 WHERE `entry`=258767; -- Entrance - Dirty - Web 14
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 31', `VerifiedBuild`=25996 WHERE `entry`=258766; -- Entrance - Dirty - Web 31
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 13', `VerifiedBuild`=25996 WHERE `entry`=258771; -- Entrance - Dirty - Web 13
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 10', `VerifiedBuild`=25996 WHERE `entry`=258790; -- Entrance - Dirty - Web 10
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 30', `VerifiedBuild`=25996 WHERE `entry`=258770; -- Entrance - Dirty - Web 30
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 12', `VerifiedBuild`=25996 WHERE `entry`=258772; -- Entrance - Dirty - Web 12
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb692', `VerifiedBuild`=25996 WHERE `entry`=258789; -- Doodad_KarazahnWeb692
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb697', `VerifiedBuild`=25996 WHERE `entry`=258776; -- Doodad_KarazahnWeb697
UPDATE `gameobject_template` SET `name`='Entrance - Dirty - Web 11', `VerifiedBuild`=25996 WHERE `entry`=258759; -- Entrance - Dirty - Web 11
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=253975; -- Bench
UPDATE `gameobject_template` SET `name`='Doodad_KarazahnWeb693', `VerifiedBuild`=25996 WHERE `entry`=258774; -- Doodad_KarazahnWeb693
UPDATE `gameobject_template` SET `name`='Doodad_7sr_hubmanatree_lightbeam008', `VerifiedBuild`=25996 WHERE `entry`=265461; -- Doodad_7sr_hubmanatree_lightbeam008
UPDATE `gameobject_template` SET `name`='Doodad_7sr_hubmanatree_dead001', `VerifiedBuild`=25996 WHERE `entry`=265436; -- Doodad_7sr_hubmanatree_dead001
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=253976; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266900; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=253126; -- Instance Portal
UPDATE `gameobject_template` SET `name`='Instance Portal', `VerifiedBuild`=25996 WHERE `entry`=252248; -- Instance Portal
UPDATE `gameobject_template` SET `name`='Doodad_7DU_SuramarCatacombs_ToggleLight002', `VerifiedBuild`=25996 WHERE `entry`=261534; -- Doodad_7DU_SuramarCatacombs_ToggleLight002
UPDATE `gameobject_template` SET `name`='Doodad_7DU_SuramarCatacombs_ToggleLight003', `VerifiedBuild`=25996 WHERE `entry`=261535; -- Doodad_7DU_SuramarCatacombs_ToggleLight003
UPDATE `gameobject_template` SET `type`=2, `displayId`=32754, `Data1`=9665, `Data9`=1, `VerifiedBuild`=25996 WHERE `entry`=265435; -- Doodad_7sr_hubmanatree_seedholder001
UPDATE `gameobject_template` SET `name`='Doodad_7DU_SuramarCatacombs_ToggleLight001', `VerifiedBuild`=25996 WHERE `entry`=261533; -- Doodad_7DU_SuramarCatacombs_ToggleLight001
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246492; -- Runescale Koi School
UPDATE `gameobject_template` SET `Data1`=60553, `VerifiedBuild`=25996 WHERE `entry`=241726; -- Leystone Deposit
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=247023; -- Shadowbloom
UPDATE `gameobject_template` SET `type`=10, `displayId`=8448, `IconName`='questinteract', `unk1`='Removing', `size`=2, `Data0`=43, `Data3`=1, `Data10`=229765, `Data15`=22741, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266130; -- "Didn't want you to get the shakes."
UPDATE `gameobject_template` SET `name`='Torch', `VerifiedBuild`=25996 WHERE `entry`=248855; -- Torch
UPDATE `gameobject_template` SET `name`='Table Poison', `VerifiedBuild`=25996 WHERE `entry`=247564; -- Table Poison
UPDATE `gameobject_template` SET `name`='Smokebomb 01', `VerifiedBuild`=25996 WHERE `entry`=247558; -- Smokebomb 01
UPDATE `gameobject_template` SET `type`=10, `displayId`=40924, `IconName`='questinteract', `size`=1.3, `Data6`=3000, `Data10`=236313, `Data20`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=268368; -- Kirin Tor Arcane Matrix
UPDATE `gameobject_template` SET `type`=3, `displayId`=387, `size`=0.75, `Data3`=1, `Data30`=71620, `VerifiedBuild`=25996 WHERE `entry`=268054; -- Kel'Thuzad and the Forming of the Scourge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251211; -- Well-worn Scroll
UPDATE `gameobject_template` SET `name`='Cage', `VerifiedBuild`=25996 WHERE `entry`=248852; -- Cage
UPDATE `gameobject_template` SET `name`='Dagger', `VerifiedBuild`=25996 WHERE `entry`=247579; -- Dagger
UPDATE `gameobject_template` SET `name`='Books', `VerifiedBuild`=25996 WHERE `entry`=248860; -- Books
UPDATE `gameobject_template` SET `name`='Papers', `VerifiedBuild`=25996 WHERE `entry`=248858; -- Papers
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=247572; -- Chair
UPDATE `gameobject_template` SET `name`='Lantern', `VerifiedBuild`=25996 WHERE `entry`=248857; -- Lantern
UPDATE `gameobject_template` SET `name`='Papers', `VerifiedBuild`=25996 WHERE `entry`=248859; -- Papers
UPDATE `gameobject_template` SET `name`='Lockpicking Junk 03', `VerifiedBuild`=25996 WHERE `entry`=247571; -- Lockpicking Junk 03
UPDATE `gameobject_template` SET `name`='Talismanic Textiles', `VerifiedBuild`=25996 WHERE `entry`=242049; -- Talismanic Textiles
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=248093; -- Box of Bear Fur
UPDATE `gameobject_template` SET `name`='Tanithria''s Finishing Table', `VerifiedBuild`=25996 WHERE `entry`=242640; -- Tanithria's Finishing Table
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=249919; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250390; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242641; -- Tanithria's Dyeing Tub
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242636; -- Tanithria's Purple Dye
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242637; -- Tanithria's Blue Dye
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242638; -- Tanithria's Red Dye
UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=242639; -- Tanithria's Green Dye
UPDATE `gameobject_template` SET `name`='Khadgar''s Lockbox', `VerifiedBuild`=25996 WHERE `entry`=248522; -- Khadgar's Lockbox
UPDATE `gameobject_template` SET `name`='Khadgar''s Lockbox', `VerifiedBuild`=25996 WHERE `entry`=248523; -- Khadgar's Lockbox
UPDATE `gameobject_template` SET `type`=3, `displayId`=8351, `size`=0.75, `Data3`=1, `Data30`=71625, `VerifiedBuild`=25996 WHERE `entry`=268060; -- Rise of the Horde
UPDATE `gameobject_template` SET `castBarCaption`='Retrieving', `VerifiedBuild`=25996 WHERE `entry`=248933; -- Compendium of Ancient Weapons Volume I
UPDATE `gameobject_template` SET `name`='Khadgar''s Lockbox', `VerifiedBuild`=25996 WHERE `entry`=248822; -- Khadgar's Lockbox
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250389; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250387; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250388; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250392; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250391; -- Chair
UPDATE `gameobject_template` SET `type`=22, `name`='Tiffany''s Carving Machine', `VerifiedBuild`=25996 WHERE `entry`=245623; -- Tiffany's Carving Machine
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242047; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246154; -- Broken Toy Box
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259262; -- Bench
UPDATE `gameobject_template` SET `name`='Cartier & Co. Fine Jewelry', `VerifiedBuild`=25996 WHERE `entry`=242045; -- Cartier & Co. Fine Jewelry
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259343; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259342; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=36322, `size`=0.75, `Data3`=1, `Data30`=71623, `VerifiedBuild`=25996 WHERE `entry`=268057; -- Mount Hyjal and Illidan's Gift
UPDATE `gameobject_template` SET `type`=3, `displayId`=8128, `size`=0.75, `Data3`=1, `Data30`=71628, `VerifiedBuild`=25996 WHERE `entry`=268066; -- The Alliance of Lordaeron
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250394; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259344; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250393; -- Chair
UPDATE `gameobject_template` SET `name`='First to Your Aid', `VerifiedBuild`=25996 WHERE `entry`=242048; -- First to Your Aid
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259379; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250217; -- Chair
UPDATE `gameobject_template` SET `castBarCaption`='Perusing', `VerifiedBuild`=25996 WHERE `entry`=249730; -- Runes of the Aqir
UPDATE `gameobject_template` SET `type`=3, `displayId`=8345, `size`=0.75, `Data3`=1, `Data30`=71626, `VerifiedBuild`=25996 WHERE `entry`=268061; -- Sargeras and the Betrayal
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250216; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250219; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250218; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259341; -- Stool
UPDATE `gameobject_template` SET `castBarCaption`='Perusing', `VerifiedBuild`=25996 WHERE `entry`=249732; -- Verdigris or Malachite? Selecting the Proper Green Ink
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `Data1`=0, `VerifiedBuild`=25996 WHERE `entry`=249729; -- The Masterful Miller's Manual
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242037; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Hay Bale', `VerifiedBuild`=25996 WHERE `entry`=242366; -- Hay Bale
UPDATE `gameobject_template` SET `name`='The Scribe''s Sacellum', `VerifiedBuild`=25996 WHERE `entry`=242039; -- The Scribe's Sacellum
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=244651; -- Steamy Romance Novel
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259378; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Perusing', `VerifiedBuild`=25996 WHERE `entry`=249731; -- Scrolls, Scrolls, Scrolls
UPDATE `gameobject_template` SET `type`=3, `displayId`=8051, `size`=0.75, `Data3`=1, `Data30`=71641, `VerifiedBuild`=25996 WHERE `entry`=268081; -- The Scourge of Lordaeron
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259334; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250260; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=248856; -- Caution!
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242040; -- Lamp
UPDATE `gameobject_template` SET `name`='Simply Enchanting', `VerifiedBuild`=25996 WHERE `entry`=242041; -- Simply Enchanting
UPDATE `gameobject_template` SET `name`='Shard up for some enchanting materials? Come inside!', `VerifiedBuild`=25996 WHERE `entry`=242042; -- Shard up for some enchanting materials? Come inside!
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250305; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Vale of Eternal Blossoms', `VerifiedBuild`=25996 WHERE `entry`=246006; -- Portal to Vale of Eternal Blossoms
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242215; -- Lamp
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242216; -- Mailbox
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259285; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259390; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242220; -- Mailbox
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259387; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259380; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250435; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259304; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250261; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=8127, `size`=0.8, `Data3`=1, `Data30`=71627, `VerifiedBuild`=25996 WHERE `entry`=268065; -- Sunwell - The Fall of Quel'Thalas
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250310; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250258; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Exodar', `VerifiedBuild`=25996 WHERE `entry`=246003; -- Portal to Exodar
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259284; -- Bench
UPDATE `gameobject_template` SET `name`='The Threads of Fate', `VerifiedBuild`=25996 WHERE `entry`=241959; -- The Threads of Fate
UPDATE `gameobject_template` SET `name`='The Wonderworks', `VerifiedBuild`=25996 WHERE `entry`=241972; -- The Wonderworks
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250259; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=248079; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250301; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250302; -- Bench
UPDATE `gameobject_template` SET `name`='Portal to Darnassus', `VerifiedBuild`=25996 WHERE `entry`=245997; -- Portal to Darnassus
UPDATE `gameobject_template` SET `name`='Fireplace', `VerifiedBuild`=25996 WHERE `entry`=259834; -- Fireplace
UPDATE `gameobject_template` SET `name`='Portal to Ironforge', `VerifiedBuild`=25996 WHERE `entry`=245998; -- Portal to Ironforge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241951; -- Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259382; -- Chair
UPDATE `gameobject_template` SET `name`='Couch', `Data1`=2, `VerifiedBuild`=25996 WHERE `entry`=259288; -- Couch
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259383; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259381; -- Chair
UPDATE `gameobject_template` SET `name`='Dalaran Merchant''s Bank', `VerifiedBuild`=25996 WHERE `entry`=242127; -- Dalaran Merchant's Bank
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259384; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Stormwind', `Data0`=245992, `VerifiedBuild`=25996 WHERE `entry`=246002; -- Portal to Stormwind
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259351; -- Chair
UPDATE `gameobject_template` SET `name`='Dalaran Merchant''s Bank', `VerifiedBuild`=25996 WHERE `entry`=242128; -- Dalaran Merchant's Bank
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250514; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250513; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250512; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250522; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250523; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Dalaran Crater', `VerifiedBuild`=25996 WHERE `entry`=246008; -- Portal to Dalaran Crater
UPDATE `gameobject_template` SET `name`='WARNING: Drop', `VerifiedBuild`=25996 WHERE `entry`=246708; -- WARNING: Drop
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246009; -- Portal to Karazhan
UPDATE `gameobject_template` SET `name`='Portal to Wyrmrest Temple', `VerifiedBuild`=25996 WHERE `entry`=246013; -- Portal to Wyrmrest Temple
UPDATE `gameobject_template` SET `name`='Couch', `Data1`=2, `VerifiedBuild`=25996 WHERE `entry`=259286; -- Couch
UPDATE `gameobject_template` SET `name`='Couch', `Data1`=2, `VerifiedBuild`=25996 WHERE `entry`=259287; -- Couch
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250521; -- Chair
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259311; -- Beanbag
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259312; -- Beanbag
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250509; -- Chair
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259310; -- Beanbag
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259309; -- Beanbag
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250510; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250528; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=200296; -- Washing Tub
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=200297; -- Shandy's Clothesline
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250511; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250527; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259317; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250525; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=36322, `size`=0.75, `Data3`=1, `Data30`=71618, `VerifiedBuild`=25996 WHERE `entry`=268052; -- Exile of the High Elves
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241943; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250526; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250524; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250515; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242126; -- Mailbox
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=246262; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250517; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250516; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250455; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=246258; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250501; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242125; -- Lamp
UPDATE `gameobject_template` SET `name`='Photonic Playground', `VerifiedBuild`=25996 WHERE `entry`=250438; -- Photonic Playground
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250502; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250503; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250506; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=258327; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250507; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250456; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250454; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250508; -- Chair
UPDATE `gameobject_template` SET `name`='The Militant Mystic', `VerifiedBuild`=25996 WHERE `entry`=242129; -- The Militant Mystic
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250505; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=246257; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250504; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250453; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241952; -- Lamp
UPDATE `gameobject_template` SET `name`='Langrom''s Leather & Links', `VerifiedBuild`=25996 WHERE `entry`=242130; -- Langrom's Leather & Links
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250476; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250520; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=241965; -- Mailbox
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250518; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250519; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242131; -- Lamp
UPDATE `gameobject_template` SET `name`='Collision Wall', `VerifiedBuild`=25996 WHERE `entry`=247337; -- Collision Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=249362; -- Lever
UPDATE `gameobject_template` SET `type`=3, `displayId`=6558, `size`=0.75, `Data3`=1, `Data30`=71612, `VerifiedBuild`=25996 WHERE `entry`=268046; -- Arathor and the Troll Wars
UPDATE `gameobject_template` SET `name`='A Hero''s Welcome', `VerifiedBuild`=25996 WHERE `entry`=241961; -- A Hero's Welcome
UPDATE `gameobject_template` SET `name`='Glorious Goods', `VerifiedBuild`=25996 WHERE `entry`=242132; -- Glorious Goods
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241968; -- Lamp
UPDATE `gameobject_template` SET `name`='Luggage', `VerifiedBuild`=25996 WHERE `entry`=247015; -- Luggage
UPDATE `gameobject_template` SET `name`='Stairs', `VerifiedBuild`=25996 WHERE `entry`=247013; -- Stairs
UPDATE `gameobject_template` SET `name`='Sack', `VerifiedBuild`=25996 WHERE `entry`=247019; -- Sack
UPDATE `gameobject_template` SET `castBarCaption`='Placing', `VerifiedBuild`=25996 WHERE `entry`=247018; -- Tip Bucket
UPDATE `gameobject_template` SET `name`='Portal to Caverns of Time', `VerifiedBuild`=25996 WHERE `entry`=246005; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `name`='Curiosities & Moore', `VerifiedBuild`=25996 WHERE `entry`=241960; -- Curiosities & Moore
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250464; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250457; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=241966; -- Mailbox
UPDATE `gameobject_template` SET `name`='The Arsenal Absolute', `VerifiedBuild`=25996 WHERE `entry`=241953; -- The Arsenal Absolute
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259296; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259268; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242177; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Forge of Power', `VerifiedBuild`=25996 WHERE `entry`=247320; -- Forge of Power
UPDATE `gameobject_template` SET `Data2`=8, `Data4`=42681, `VerifiedBuild`=25996 WHERE `entry`=248980; -- The Legend of Odyn
UPDATE `gameobject_template` SET `type`=45, `displayId`=15781, `Data0`=191, `VerifiedBuild`=25996 WHERE `entry`=252801; -- Artifact Research Notes
UPDATE `gameobject_template` SET `Data4`=0, `VerifiedBuild`=25996 WHERE `entry`=248979; -- Saga of the Valarjar
UPDATE `gameobject_template` SET `name`='[DNT] Command Table Collision Cylinder', `size`=2.25, `VerifiedBuild`=25996 WHERE `entry`=259095; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250879; -- Training Troops
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=250878; -- Training Troops
UPDATE `gameobject_template` SET `name`='Forge of Odyn', `VerifiedBuild`=25996 WHERE `entry`=245726; -- Forge of Odyn
UPDATE `gameobject_template` SET `Data0`=224, `VerifiedBuild`=25996 WHERE `entry`=250880; -- Training Troops
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252887; -- Blessing of Mjolnir
UPDATE `gameobject_template` SET `Data2`=8, `VerifiedBuild`=25996 WHERE `entry`=248981; -- The Favored of Odyn
UPDATE `gameobject_template` SET `name`='Valhallas Portal', `VerifiedBuild`=25996 WHERE `entry`=244516; -- Valhallas Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252016; -- Requisitioned Armaments
UPDATE `gameobject_template` SET `name`='Cylinder Collision (2 Scale)', `VerifiedBuild`=25996 WHERE `entry`=246280; -- Cylinder Collision (2 Scale)
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250300; -- Bench
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259396; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250341; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250342; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259397; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250343; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259398; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250345; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250344; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250356; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250358; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250357; -- Stool
UPDATE `gameobject_template` SET `name`='Stool' WHERE `entry`=250328; -- Stool
UPDATE `gameobject_template` SET `name`='Stool' WHERE `entry`=250329; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250359; -- Stool
UPDATE `gameobject_template` SET `name`='Stool' WHERE `entry`=250332; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250360; -- Stool
UPDATE `gameobject_template` SET `name`='Illidari Gateway' WHERE `entry`=251286; -- Illidari Gateway
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259265; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259267; -- Chair
UPDATE `gameobject_template` SET `name`='Stool' WHERE `entry`=250331; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250355; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250352; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250354; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250351; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250353; -- Stool
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250336; -- Bench
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250340; -- Bench
UPDATE `gameobject_template` SET `name`='Fireplace' WHERE `entry`=259835; -- Fireplace
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246664; -- Test Kitchen Results
UPDATE `gameobject_template` SET `name`='Portal to the Maelstrom' WHERE `entry`=251311; -- Portal to the Maelstrom
UPDATE `gameobject_template` SET `name`='Shaman Stones' WHERE `entry`=251312; -- Shaman Stones
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250350; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250349; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250348; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250347; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250346; -- Stool
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250339; -- Bench
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250338; -- Bench
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250334; -- Bench
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250333; -- Bench
UPDATE `gameobject_template` SET `castBarCaption`='Retrieving', `Data1`=0, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=246710; -- Nomi's Silver Mackerel
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259264; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242176; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Well', `VerifiedBuild`=25996 WHERE `entry`=242218; -- Well
UPDATE `gameobject_template` SET `name`='Banner' WHERE `entry`=245249; -- Banner
UPDATE `gameobject_template` SET `name`='Archmage Vargoth''s Retreat', `VerifiedBuild`=25996 WHERE `entry`=251883; -- Archmage Vargoth's Retreat
UPDATE `gameobject_template` SET `name`='Teleport Pad', `VerifiedBuild`=25996 WHERE `entry`=244562; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Instance Portal' WHERE `entry`=252245; -- Instance Portal
UPDATE `gameobject_template` SET `name`='Violet Hold Gate' WHERE `entry`=242174; -- Violet Hold Gate
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259305; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=8133, `size`=1.1, `Data3`=1, `Data30`=71611, `VerifiedBuild`=25996 WHERE `entry`=268045; -- Aftermath of the Second War
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259306; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246465; -- Tidestone of Golganneth
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246466; -- Tears of Elune
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=246463; -- Hammer of Khaz'goroth
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259303; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=8128, `size`=1.65, `Data3`=1, `Data30`=71634, `VerifiedBuild`=25996 WHERE `entry`=268074; -- The Guardians of Tirisfal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=251992; -- The Aegis of Aggramar
UPDATE `gameobject_template` SET `name`='Facade' WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259307; -- Bench
UPDATE `gameobject_template` SET `name`='Teleport Pad' WHERE `entry`=244560; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Teleport Pad' WHERE `entry`=244561; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259308; -- Bench
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259416; -- Stool
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259415; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259266; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259271; -- Stool
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250335; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250458; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259270; -- Stool
UPDATE `gameobject_template` SET `type`=3, `displayId`=447, `Data3`=1, `Data30`=71638, `VerifiedBuild`=25996 WHERE `entry`=268078; -- The Lich King Triumphant
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=250337; -- Bench
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=259269; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=194115; -- Shoeshine Seat
UPDATE `gameobject_template` SET `type`=3, `displayId`=105, `size`=0.75, `Data3`=1, `Data30`=71617, `VerifiedBuild`=25996 WHERE `entry`=268051; -- Empires' Fall
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=246260; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=246, `size`=0.75, `Data3`=1, `Data30`=71615, `VerifiedBuild`=25996 WHERE `entry`=268049; -- Charge of the Dragonflights
UPDATE `gameobject_template` SET `type`=3, `displayId`=6845, `size`=0.85, `Data3`=1, `Data30`=71610, `VerifiedBuild`=25996 WHERE `entry`=268044; -- Aegwynn and the Dragon Hunt
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=246261; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250472; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250471; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Vale of Eternal Blossoms', `VerifiedBuild`=25996 WHERE `entry`=246007; -- Portal to Vale of Eternal Blossoms
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250298; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250459; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250299; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250473; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242200; -- Mailbox
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=241963; -- Mailbox
UPDATE `gameobject_template` SET `name`='The Legerdemain Lounge', `VerifiedBuild`=25996 WHERE `entry`=241958; -- The Legerdemain Lounge
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259273; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241948; -- Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259279; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259272; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241944; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Harp', `VerifiedBuild`=25996 WHERE `entry`=254236; -- Harp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259280; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259339; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259278; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250470; -- Chair
UPDATE `gameobject_template` SET `type`=10, `displayId`=29136, `IconName`='questinteract', `Data0`=1634, `Data3`=3000, `Data7`=6882, `Data9`=1, `Data10`=232187, `Data17`=1, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=266736; -- Levia's Research Journal
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259426; -- Chair
UPDATE `gameobject_template` SET `name`='Dalaran Visitor Center', `VerifiedBuild`=25996 WHERE `entry`=241954; -- Dalaran Visitor Center
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=250297; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250477; -- Chair
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=259283; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=25996 WHERE `entry`=259277; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250479; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=36320, `Data3`=1, `Data30`=71608, `VerifiedBuild`=25996 WHERE `entry`=267991; -- The Birth of the Lich King
UPDATE `gameobject_template` SET `castBarCaption`='Reading' WHERE `entry`=270855; -- Inconspicuous Note
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250461; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259275; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250480; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250460; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250474; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250478; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250463; -- Chair
UPDATE `gameobject_template` SET `name`='Barbershop Chair', `Data0`=2, `VerifiedBuild`=25996 WHERE `entry`=241922; -- Barbershop Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250462; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250485; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=16059, `IconName`='questinteract', `size`=0.5, `Data0`=1691, `Data2`=1, `Data8`=45185, `Data30`=70543, `VerifiedBuild`=25996 WHERE `entry`=266619; -- A Mysterious Note
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=242231; -- Mailbox
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259274; -- Chair
UPDATE `gameobject_template` SET `name`='Skull Candle', `VerifiedBuild`=25996 WHERE `entry`=235098; -- Skull Candle
UPDATE `gameobject_template` SET `name`='Crystal Dust', `VerifiedBuild`=25996 WHERE `entry`=235099; -- Crystal Dust
UPDATE `gameobject_template` SET `name`='Bones', `VerifiedBuild`=25996 WHERE `entry`=235100; -- Bones
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=259281; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242235; -- Lamp
UPDATE `gameobject_template` SET `name`='Mailbox' WHERE `entry`=242172; -- Mailbox
UPDATE `gameobject_template` SET `type`=10, `displayId`=14564, `IconName`='questinteract', `castBarCaption`='Destroying', `size`=0.5, `Data0`=2399, `Data3`=1, `Data5`=1, `Data10`=183572, `Data14`=24585, `Data22`=33195, `Data23`=1, `VerifiedBuild`=25996 WHERE `entry`=269967; -- Ironbound Crate
UPDATE `gameobject_template` SET `name`='Bench' WHERE `entry`=259282; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259276; -- Chair
UPDATE `gameobject_template` SET `name`='The Filthy Animal', `VerifiedBuild`=25996 WHERE `entry`=242232; -- The Filthy Animal
UPDATE `gameobject_template` SET `name`='Barbershop Chair', `Data0`=2, `VerifiedBuild`=25996 WHERE `entry`=241921; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241950; -- Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250494; -- Chair
UPDATE `gameobject_template` SET `name`='Barbershop Chair', `Data0`=2, `VerifiedBuild`=25996 WHERE `entry`=241920; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259337; -- Coffee Grinder
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250492; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250493; -- Chair
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259295; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266851; -- Wand of Simulated Life
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266705; -- Willem West's Table
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259294; -- Beanbag
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259293; -- Beanbag
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250487; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259335; -- Coffee Press
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=266761; -- Research Notes
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250436; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250214; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250497; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242233; -- Lamp
UPDATE `gameobject_template` SET `name`='Barbershop', `VerifiedBuild`=25996 WHERE `entry`=242237; -- Barbershop
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250495; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250496; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250449; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241949; -- Lamp
UPDATE `gameobject_template` SET `type`=3, `displayId`=7707, `size`=0.75, `Data3`=1, `Data30`=71633, `VerifiedBuild`=25996 WHERE `entry`=268073; -- The Founding of Quel'Thalas
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242234; -- Lamp
UPDATE `gameobject_template` SET `type`=9, `displayId`=14799, `Data0`=7178, `Data2`=1, `VerifiedBuild`=25996 WHERE `entry`=269989; -- Mel's Journal
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=259336; -- Coffee Grinder
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250451; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250490; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250484; -- Chair
UPDATE `gameobject_template` SET `name`='Teleport Pad', `VerifiedBuild`=25996 WHERE `entry`=244537; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Teleport Pad', `VerifiedBuild`=25996 WHERE `entry`=244536; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Teleport Pad', `VerifiedBuild`=25996 WHERE `entry`=244534; -- Teleport Pad
UPDATE `gameobject_template` SET `name`='Sword', `VerifiedBuild`=25996 WHERE `entry`=241480; -- Sword
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250450; -- Stool
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=259338; -- Chair
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259292; -- Beanbag
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250491; -- Chair
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259291; -- Beanbag
UPDATE `gameobject_template` SET `type`=3, `displayId`=1128, `size`=0.5, `Data3`=1, `Data30`=71614, `VerifiedBuild`=25996 WHERE `entry`=268048; -- Beyond the Dark Portal
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=241964; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=252331; -- Traveller Pepe
UPDATE `gameobject_template` SET `type`=3, `displayId`=7707, `Data3`=1, `Data30`=71631, `VerifiedBuild`=25996 WHERE `entry`=268059; -- Rise of the Blood Elves
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259290; -- Beanbag
UPDATE `gameobject_template` SET `name`='Beanbag', `VerifiedBuild`=25996 WHERE `entry`=259289; -- Beanbag
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250481; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250215; -- Chair
UPDATE `gameobject_template` SET `castBarCaption`='Reading' WHERE `entry`=148502; -- Test Object
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250483; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241945; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250482; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250631; -- Chair
UPDATE `gameobject_template` SET `name`='One More Glass', `VerifiedBuild`=25996 WHERE `entry`=242236; -- One More Glass
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250499; -- Chair
UPDATE `gameobject_template` SET `name`='Stool', `VerifiedBuild`=25996 WHERE `entry`=250452; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242227; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250500; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250498; -- Chair
UPDATE `gameobject_template` SET `name`='The Hunter''s Reach', `VerifiedBuild`=25996 WHERE `entry`=241955; -- The Hunter's Reach
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242228; -- Wall Lamp
UPDATE `gameobject_template` SET `type`=3, `displayId`=8133, `size`=0.75, `Data3`=1, `Data30`=71609, `VerifiedBuild`=25996 WHERE `entry`=268043; -- Icecrown and the Frozen Throne
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242225; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='The Legerdemain Lounge', `VerifiedBuild`=25996 WHERE `entry`=241957; -- The Legerdemain Lounge
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242226; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241971; -- Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251581; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241969; -- Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251594; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251580; -- Chair
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=25996 WHERE `entry`=241967; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242224; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251582; -- Chair
UPDATE `gameobject_template` SET `type`=3, `displayId`=36321, `size`=1.25, `Data3`=1, `Data30`=71645, `VerifiedBuild`=25996 WHERE `entry`=268086; -- The War of the Ancients
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251592; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251593; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242169; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241947; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251595; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250467; -- Chair
UPDATE `gameobject_template` SET `name`='Drape', `VerifiedBuild`=25996 WHERE `entry`=251624; -- Drape
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242170; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=242223; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Magical Menagerie', `VerifiedBuild`=25996 WHERE `entry`=241956; -- Magical Menagerie
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250468; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241946; -- Wall Lamp
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=250469; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251585; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=25996 WHERE `entry`=251584; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=241970; -- Lamp

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=266619 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(266619, 0, 143494, 25996); -- A Mysterious Note

UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246225 AND `Idx`=0); -- Weathered Telemancy Beacon
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246229 AND `Idx`=0); -- Cracked Warpsleeve
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=245126 AND `Idx`=0); -- Crystallized Ancient Mana
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=247023 AND `Idx`=0); -- Shadowbloom
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=249729 AND `Idx`=0); -- The Masterful Miller's Manual
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=246710 AND `Idx`=0); -- Nomi's Silver Mackerel

DELETE FROM `page_text` WHERE `ID` IN (7034 /*7034*/, 7033 /*7033*/, 7032 /*7032*/, 7031 /*7031*/, 7030 /*7030*/, 7029 /*7029*/, 7028 /*7028*/, 7025 /*7025*/, 7024 /*7024*/, 7023 /*7023*/, 7022 /*7022*/, 7021 /*7021*/, 7020 /*7020*/, 7019 /*7019*/, 7018 /*7018*/, 7017 /*7017*/, 5269 /*5269*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7034, 'He succeeded. The construct awoke, and lashed out at all living creatures. This was why it had been destroyed and buried in the first place: the Old Gods'' minions had corrupted it, turning its purpose against the allies of the titans.<BR/><BR/>Though Volund survived his first contact with it, the construct seemed to be unstoppable. It turned toward the nearest bastion of the titan-forged, Stormheim itself, and marched to destroy it. It might have succeeded. Volund collected all of his treasures, all of his artifacts, all of his hoarded instruments, and brought them to bear against the construct.<BR/><BR/>There was a great flash of light, and then a great silence. The construct, along with Volund, was no more. <BR/><BR/>Volund had saved Stormheim from his folly. And may we all learn from his errors. Power must be respected, guarded, and carefully curated.<BR/><BR/></P>\n</BODY></HTML>', 0, 47880, 0, 25996), -- 7034
(7033, 'But the artifacts of the titans were valuable treasures. They often imparted incredible power to Volund on the battlefield. He had been skilled before; he was unstoppable now. He moved faster, struck harder, and carried vastly outnumbered warbands to victory. Any artifacts he couldn''t use himself, he would lend to other warriors, granting them marvelous abilities.<BR/><BR/>Yet he was not satisfied. Once he had collected enough of the titans'' power for himself, he could single-handedly destroy every enemy on Azeroth and ensure eternal peace. So he believed.<BR/><BR/>Volund eventually located something that might have made his dreams come true. An ancient titan construct, built for war against the Old Gods'' most powerful abominations, was resting beneath a mountain range near Stormheim. If it were awoken, Volund believed it would roam Azeroth on its own, eradicating all traces of evil and chaos. Volund studied it for years before attempting to raise it back to life.<BR/><BR/>', 7034, 47880, 1, 25996), -- 7033
(7032, '<HTML><BODY>\n<H2 align="center">Volund''s Folly</H2>\n<HR/>\n<P>\nPower can be earned. It can be created. It can be lent. But when it is stolen, there will always be a price to pay.<BR/><BR/>Heed the tale of Volund the Hoarder. <BR/><BR/>Brave and clever, studious and wise, he was an astonishing force on the battlefield. The enemies of Odyn quailed before Volund. His blade, his bow, and his spear secured many victories and earned him much honor. His attentions were drawn to the ancient and mysterious leavings of the Black Empire. The war between the titans and the Old Gods had left countless fragments of power scattered across Azeroth. The instruments of the Old Gods were too dangerous to touch, so Volund destroyed them wherever he found them.<BR/><BR/>', 7033, 47880, 1, 25996), -- 7032
(7031, 'Heimir''s dream was simple. Perhaps these outsiders would become mighty warriors in their own right, equal to any vrykul. But for as long as he lived, none ever defeated him in sparring.<BR/><BR/>And yet he never despaired. It is the duty of the vrykul to defend this world. How better to spend his time than to teach its weakest the ways of strength?<BR/><BR/></P>\n</BODY></HTML>', 7032, 47879, 0, 25996), -- 7031
(7030, 'Heimir never knew their language, and they knew not his. So they communicated the only way they could: Heimir would raise his blade, wait for them to raise theirs, and then begin sparring. Did any of them rise to the skill of even a novice vrykul? No. But that was no surprise. They were primitive mortals, not titan-forged warriors.<BR/><BR/>Heimir would remain there, training, until they showed that they had truly developed a warrior''s spirit. Then he would leave. He would not return until generations had passed.<BR/><BR/>And in that time, the warrior tradition grew. The students would continue their training. They would become masters and instruct new acolytes in their ways. Heimir no longer needed to teach them the basics. He would train them in new, advanced techniques. Then he would leave. Generations later, he would build their knowledge yet again.<BR/><BR/>', 7031, 47879, 1, 25996), -- 7030
(7029, 'Most creatures fled the moment they saw him, and for good reason. Even among vrykul, Heimir''s size and stature were formidable. But sometimes, they would come back, observing him from a distance. Heimir did not mind. With every sunrise, he would rise from sleep and practice with his sword and shield. The visitors watched him carefully.<BR/><BR/>Heimir showed them the rudiments of battle. He demonstrated the forms and techniques that would lay the foundation for honorable warfare. And then, weeks later, he would stop. He would sit in a clearing, his sword on his lap, waiting alone. For days he would wait. Weeks. Months, at times.<BR/><BR/>Eventually, one of the curious mortals would approach. Sometimes they had made primitive blades-or if they lacked metalworking knowledge, they had chopped trees into heavy wooden practice swords. That was always a good sign. Those who made the effort were rewarded.<BR/><BR/>', 7030, 47879, 1, 25996), -- 7029
(7028, '<HTML><BODY>\n<H2 align="center">The Lessons of the Blackfist</H2>\n<HR/>\n<P>\nVrykul defend this world. It is our duty, our task, our solemn vow. Yet we share this world with many other creatures, lesser mortals of diminished power and strength. Most are selfish, insignificant beings. Some have a sense of order and honor. A rare few have the fortitude to achieve true might, wielding the powers that drift in and out of our realm with skill and cunning. <BR/><BR/>A vrykul warrior, Heimir of the Black Fist, took it upon himself to seek out native creatures as he traveled. He was driven by curiosity. Most vrykul dismissed these outsiders as worthless. Could any of them rise to something more?<BR/><BR/>', 7029, 47879, 1, 25996), -- 7028
(7025, '<HTML><BODY>\n<H2 align="center">The Prophecy of Rythas the Oracle</H2>\n<HR/>\n<P>\nOur world is young. It sleeps, troubled with dreams.<BR/>I have known its slumber. I have felt its heart beat.<BR/>Darkness seeks to claim it. <BR/>Beneath the land, chaos. Beneath the sea, patient menace.<BR/>Our hope lies in the sky. Odyn''s refuge must stand.<BR/><BR/>\nThe world''s soul is weak. It will one day be strong.<BR/>Only the worthy can protect it.<BR/>Do not fear death. To live as a vrykul is to know danger.<BR/>A glorious death will not be the end.<BR/>The second life begins in the sky. Odyn''s refuge must stand.<BR/><BR/>\nThe Halls of Valor will one day close. Its gates barred, its heroes spurned.<BR/>A champion will rise and break them free.<BR/>The champion''s face is hidden; their name is cloaked. What power will this creature hold?<BR/>It will arise in time. It will save us all.<BR/>It will ensure that Odyn''s refuge will stand.<BR/>\n</P>\n</BODY></HTML>', 7028, 47878, 0, 25996), -- 7025
(7024, 'Iounn became a stalwart defender of the Valkyra, a thorn in Helya''s side. Time and time again, she thwarted Helya''s plans to destroy the Halls of Valor.<BR/><BR/>But all of it was nearly for naught. Ashildir herself died in battle. Helya''s minions sought her remains, hoping to snatch her soul for Helheim. None but Iounn stood against them. Bravely she fought, ignoring wounds and fatigue. She carried Ashildir home to Stormheim, where she was laid to rest. Her spirit ascended, and she would forever serve as the queen of the Valkyra.<BR/><BR/>Iounn had been badly injured. She lay next to Ashildir''s grave and waited for her life''s end. She raised her shield one last time in salute, and passed away with a smile on her face.<BR/><BR/>And when her spirit was raised, she joined Ashildir''s side once more to continue her work as a defender of the Valarjar Valkyra. Iounn had rested enough. She was looking forward yet again.<BR/><BR/></P>\n</BODY></HTML>', 7025, 47877, 0, 25996), -- 7024
(7023, '<HTML><BODY>\n<H2 align="center">A Shieldmaiden''s Creed</H2>\n<HR/>\n<P>\nShieldmaiden Iounn was her name. Her raids took her to the north, to the east, and to the west. Never did she flinch from battle. Countless enemies fell before her. But while her comrades celebrated each victory, she did not.<BR/><BR/>"That is in the past," she would say. "Let us look forward."<BR/><BR/>Years passed. Her travels took her across Azeroth. Her battles begat great tales of bravery and power. Yet she still did not celebrate. Looking forward, not back, was her eternal creed.<BR/><BR/>When Ashildir began her quest to form the Valkyra, she called upon the mightiest women among all the vrykul to join her. Dark forces were working against Odyn and the Halls of Valor. The future of their people was at stake. <BR/><BR/>Shieldmaiden Iounn answered. "Ashildir has set her sights past this life and onto the next. I will help."<BR/><BR/>', 7024, 47877, 1, 25996), -- 7023
(7022, '"We will die, but we will bring their crew down to the depths with us! Keep death''s song in your heart and a blade between your teeth, even as your blood rushes free. If a single one of their crew is left alive, all of our souls are forfeit. But if they die with us, the Naglfar will sail on and return to Helya... empty of our souls and theirs. Let our dying breaths rob Helheim of its faithful.<BR/><BR/>"Here it comes. I expect to see each and every one of you in the Halls shortly.<BR/><BR/>"Open fire."<BR/><BR/></P>\n</BODY></HTML>', 7023, 47876, 0, 25996), -- 7022
(7021, '<HTML><BODY>\n<H2 align="center">The Last Words of Asgrim the Dreadkiller</H2>\n<HR/>\n<P>\n"You see it, yes? We must have driven Helya to true fury. That is her prize on the horizon, sailing for us now. <BR/><BR/>"Let there be no doubt: we will die this day. That is the dread ship Naglfar, and it will blast our vessel into splinters. And then what will happen? Its crew will pluck us from the waters and slit our throats, and the Naglfar will ferry our souls to Helheim, where Helya will strip us clean of all that makes us mighty and great and free. She wants nothing less than to force our servitude and obedience for eternity.<BR/><BR/>"Let her try! Let her Kvaldir puppets rush to oblivion! Together we have sent thousands of those cursed, befouled creatures back to their hell. We have saved countless vrykul souls from her clutches.<BR/><BR/>', 7022, 47876, 1, 25996), -- 7021
(7020, 'The red dragon stood beside him and opened one of her veins. Her blood mingled with his, and Oktel felt his might returning. "I am the Life-Binder. I lend you this power not to take life, but to protect it," she said. "The aqir will kill many creatures if left unchallenged. Go on, warrior, and finish your quest."<BR/><BR/>Oktel stood and walked deep into the deserts, finding the aqir''s biggest warren. He kept his word, destroying the aqir that had attacked him and crushing their countless clutches of eggs. He returned to his people with the skulls of insect lords strung together around his neck. The vrykul called him a new name: Oktel Dragonblood.<BR/><BR/>In time he would be the thane of his people, a fierce warrior in battle but a compassionate cultivator of life in peace. After his death, he was honored by vrykul and dragons alike. <BR/><BR/>May he now have the relief he so richly earned.<BR/><BR/></P>\n</BODY></HTML>', 7021, 47875, 0, 25996), -- 7020
(7019, 'The aqir refused to let that happen. They laid a false trail, waited for him to follow it alone, and then struck. They rose up as a swarm, filling the sky, attacking him from all directions. They tore Oktel near to pieces and left him to die slowly in the blistering heat, meaning his fate to be a warning to the rest of his kind.<BR/><BR/>For three days and nights he suffered, lacking the strength to move. Yet he lived.<BR/><BR/>On the fourth day he was found by a red dragon. Wondrous, massive, and powerful, she circled above and called out to Oktel. "I cannot imagine your agony," she said. "Why have you clung to life for so long?"<BR/><BR/>"I have too much left to do," Oktel replied.<BR/><BR/>"I can return you to the care of your people," the dragon said.<BR/><BR/>"My work is not done. Lend me a morsel of your strength, and I will return to my people on my own, with a collection of aqiri heads in my grasp," Oktel said.<BR/><BR/>', 7020, 47875, 1, 25996), -- 7019
(7018, '<HTML><BODY>\n<H2 align="center">His Name is Dragonblood</H2>\n<HR/>\n<P>\nAfter the dark masters of the Black Empire fell before the might of the titan-forged, the aqir were silent for centuries. But they were not idle. They rested in their underground burrows, plotting, scheming, building their numbers, believing that the Old Gods would rise again one day.<BR/><BR/>They hid themselves well. They made their warrens deep below the ground. Few vrykul could track them beneath the deserts of the southwest.<BR/><BR/>A vrykul warrior named Oktel resolved to learn their secrets. He spent years wandering the barren sands alone, studying the ways of the aqir. Slowly, carefully, he identified their habits, their territory, and their weaknesses. His observations were recorded and distributed among other vrykul, greatly aiding them in their raids. If given enough time, he was certain he could uncover the aqir''s hidden labyrinths of burrows.<BR/><BR/>', 7019, 47875, 1, 25996), -- 7018
(7017, '<HTML><BODY>\n<p></p>\n<H2 align="center">Honor in Remembrance</H2><HR/>\n<P>\nI dreamt of heroism. I wanted to stride into battle as a warrior, blade in hand, and remove the enemies of Odyn from this world.<BR/><BR/>But that was not to be. I was not born the strongest or the fastest. I was not attuned to mystical power. I could never rise to glory in war. So instead I resolved to chronicle the actions of those who could. I began with Odyn himself, telling the stories of his greatest battles and achievements as he cleansed the Black Empire from Azeroth.<BR/><BR/>Now I will record the actions of his followers. Countless vrykul have sought Odyn''s favor through acts of heroism. They deserve to be remembered in this life and the next�. and if I can help them achieve immortality among the living, perhaps they will invite me to join their number in the Halls of Valor and tell their tales for all eternity.<BR/><BR/>\n-Anonymous<BR/><BR/>\n</P>\n</BODY></HTML>', 7018, 0, 0, 25996), -- 7017
(5269, '<HTML><BODY>\n<H1 align="center">The Favored of Odyn</H1>\n<IMG src="Interface\\Common\\spacer" align="center" width="1" height="27"/>\n<IMG src="Interface\\Pictures\\artifactbook-warrior-cover" align="center" width="230" height="230"/>\n<IMG src="Interface\\Common\\spacer" align="center" width="1" height="27"/>\n<p align="center">Tales of the greatest vrykul that ever lived</p>\n</BODY></HTML>', 7017, 0, 0, 25996); -- 5269


DELETE FROM `npc_text` WHERE `ID` IN (31007 /*31007*/, 30763 /*30763*/, 31003 /*31003*/, 30862 /*30862*/, 29436 /*29436*/, 30840 /*30840*/, 29678 /*29678*/, 30468 /*30468*/, 29823 /*29823*/, 30432 /*30432*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(31007, 1, 1, 0, 0, 0, 0, 0, 0, 125127, 125125, 0, 0, 0, 0, 0, 0, 25996), -- 31007
(30763, 1, 0, 0, 0, 0, 0, 0, 0, 123561, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30763
(31003, 1, 1, 1, 1, 0, 0, 0, 0, 125108, 125109, 125110, 125111, 0, 0, 0, 0, 25996), -- 31003
(30862, 1, 1, 1, 1, 1, 1, 1, 1, 124238, 124239, 124240, 124242, 124243, 124244, 124245, 124246, 25996), -- 30862
(29436, 1, 0, 0, 0, 0, 0, 0, 0, 113740, 0, 0, 0, 0, 0, 0, 0, 25996), -- 29436
(30840, 1, 0, 0, 0, 0, 0, 0, 0, 124128, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30840
(29678, 1, 0, 0, 0, 0, 0, 0, 0, 115663, 0, 0, 0, 0, 0, 0, 0, 25996), -- 29678
(30468, 1, 0, 0, 0, 0, 0, 0, 0, 122308, 0, 0, 0, 0, 0, 0, 0, 25996), -- 30468
(29823, 1, 0, 0, 0, 0, 0, 0, 0, 117226, 0, 0, 0, 0, 0, 0, 0, 25996), -- 29823
(30432, 1, 0, 0, 0, 0, 0, 0, 0, 122235, 0, 0, 0, 0, 0, 0, 0, 25996); -- 30432

UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28198; -- 28198
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28199; -- 28199
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=28178; -- 28178
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27380; -- 27380
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=26867; -- 26867
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=25240; -- 25240
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=27251; -- 27251

