SET @CGUID := 10006843;
SET @NPCTEXTID := 600133;

UPDATE `creature_template` SET `npcflag`=0x83,`faction`=35,`unit_flags2`=0x800 WHERE `entry`=235252;
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3008,`StaticFlags1`=`StaticFlags1`|0x10000020 WHERE `entry`=235252;

DELETE FROM `creature` WHERE `guid`=@CGUID AND `id`=235252;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 235252, 2738, 15781, 15781, '0', 0, 0, 0, 0, -867.623291015625, -96.5243072509765625, 545.04339599609375, 4.959111690521240234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- 235252 (Area: Tazavesh, the Veiled Market - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry`=235252;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(235252, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `npc_text` WHERE `ID`=@NPCTEXTID;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID, 1, 0, 0, 0, 0, 0, 0, 0, 279065, 0, 0, 0, 0, 0, 0, 0, 63305); -- 235252

DELETE FROM `gossip_menu` WHERE `MenuID`=37574 AND `TextID`=@NPCTEXTID;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37574, @NPCTEXTID, 63305); -- 235252

DELETE FROM `gossip_menu_option` WHERE `MenuID`=37574;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37574, 133224, 0, 1, 'Show me your wares.', 0, 0, 0, 0, 0, 59184, 0, 0, NULL, 0, NULL, NULL, 63305);

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=235252;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(235252, 37574, 63305);

DELETE FROM `npc_vendor` WHERE `entry`=235252;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(235252,  1, 239487, 0,  9102, 1, 140884, 0, 63305), -- Pattern: Pure Dexterous Fiber
(235252,  2, 239485, 0,  9102, 1, 140884, 0, 63305), -- Pattern: Pure Energizing Fiber
(235252,  3, 239486, 0,  9102, 1, 140884, 0, 63305), -- Pattern: Pure Chronomantic Fiber
(235252,  4, 239488, 0,  9102, 1, 140884, 0, 63305), -- Pattern: Pure Precise Fiber
(235252,  5, 244043, 0,  9102, 1, 140887, 0, 63305), -- Technique: Contract: The K'aresh Trust
(235252,  6, 244334, 0,  9102, 1, 140887, 0, 63305), -- Technique: Vantus Rune: Manaforge Omega
(235252,  7, 244841, 0,  9102, 1, 141592, 0, 63305), -- Recipe: Invigorating Healing Potion
(235252,  8, 248550, 0,  9102, 1, 141592, 0, 63305), -- Recipe: Umbral Essentia
(235252,  9, 245967, 0,  8938, 1, 138493, 0, 63305), -- Shawl of the Trust
(235252, 10, 245975, 0,  8870, 1, 138494, 0, 63305), -- Consortium Brute's Chestguard
(235252, 11, 245976, 0,  8870, 1, 138494, 0, 63305), -- Consortium Skirmisher's Cuirass
(235252, 12, 245977, 0,  8870, 1, 138494, 0, 63305), -- Consortium Scout's Jacket
(235252, 13, 245978, 0,  8870, 1, 138494, 0, 63305), -- Consortium Magi's Robes
(235252, 14, 235865, 0,  8997, 1, 134091, 0, 63305), -- Ethereal Tome of Alchemy Knowledge
(235252, 15, 235864, 0,  8997, 1, 134092, 0, 63305), -- Ethereal Tome of Blacksmithing Knowledge
(235252, 16, 235863, 0,  8997, 1, 134093, 0, 63305), -- Ethereal Tome of Enchanting Knowledge
(235252, 17, 235862, 0,  8997, 1, 134094, 0, 63305), -- Ethereal Tome of Engineering Knowledge
(235252, 18, 235861, 0, 10487, 1, 134095, 0, 63305), -- Ethereal Tome of Herbalism Knowledge
(235252, 19, 235860, 0,  8997, 1, 134096, 0, 63305), -- Ethereal Tome of Inscription Knowledge
(235252, 20, 235859, 0,  8997, 1, 134097, 0, 63305), -- Ethereal Tome of Jewelcrafting Knowledge
(235252, 21, 235858, 0,  8997, 1, 134098, 0, 63305), -- Ethereal Tome of Leatherworking Knowledge
(235252, 22, 235857, 0, 10487, 1, 134099, 0, 63305), -- Ethereal Tome of Mining Knowledge
(235252, 23, 235856, 0, 10487, 1, 134100, 0, 63305), -- Ethereal Tome of Skinning Knowledge
(235252, 24, 235855, 0,  8997, 1, 134101, 0, 63305), -- Ethereal Tome of Tailoring Knowledge
(235252, 25, 245969, 0,  8939, 1, 138500, 0, 63305), -- Mantle of the Trust
(235252, 26, 245693, 0, 10462, 1, 138501, 0, 63305), -- K'areshi Ribbon Stash
(235252, 27, 242729, 0, 10601, 1, 138502, 0, 63305), -- Ruby Void Creeper
(235252, 28, 245971, 0,  8871, 1, 138503, 0, 63305), -- Consortium Brute's Clasp
(235252, 29, 245972, 0,  8871, 1, 138503, 0, 63305), -- Consortium Skirmisher's Armbands
(235252, 30, 245973, 0,  8871, 1, 138503, 0, 63305), -- Consortium Scout's Armlets
(235252, 31, 245974, 0,  8871, 1, 138503, 0, 63305), -- Consortium Magi's Cuffs
(235252, 32, 245980, 0, 10461, 1, 138504, 0, 63305), -- Inter-Phase Scoop
(235252, 33, 245979, 0, 10461, 1, 138504, 0, 63305), -- Arcano-Charged Wrench
(235252, 34, 245981, 0, 10461, 1, 138504, 0, 63305), -- K'areshi Multi-Tool
(235252, 35, 243191, 0, 10392, 1, 138505, 0, 63305), -- Ethereal Augment Rune
(235252, 36, 237484, 0,  8936, 1, 138506, 0, 63305); -- Terror of the Wastes

DELETE FROM `creature_questender` WHERE `id`=235252;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(235252, 90630, 63305),
(235252, 90631, 63305),
(235252, 90632, 63305),
(235252, 90633, 63305),
(235252, 90634, 63305),
(235252, 90635, 63305),
(235252, 92330, 63305),
(235252, 91142, 63305),
(235252, 90637, 63305),
(235252, 90636, 63305),
(235252, 90638, 63305),
(235252, 91143, 63305),
(235252, 90665, 63305),
(235252, 90666, 63305),
(235252, 90667, 63305),
(235252, 85109, 63305);

DELETE FROM `creature_queststarter` WHERE `id`=235252;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(235252, 90630, 63305),
(235252, 90631, 63305),
(235252, 90632, 63305),
(235252, 90633, 63305),
(235252, 90634, 63305),
(235252, 90635, 63305),
(235252, 92330, 63305),
(235252, 91142, 63305),
(235252, 90637, 63305),
(235252, 90636, 63305),
(235252, 90638, 63305),
(235252, 91143, 63305),
(235252, 90665, 63305),
(235252, 90666, 63305),
(235252, 90667, 63305);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (90667,90666,90665,91143,90638,90636,90637,91142,92330,90635,90634,90633,90632,90631,90630,85109);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(90630, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- A Small Bundle of Crystals
(90631, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Weathered Crests
(90632, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Valorstones
(90633, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Weathered Crests
(90634, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- A Small Bundle of Crystals
(90635, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Valorstones
(92330, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Valorstones
(91142, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Tabard for the Trusted
(90637, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- A Key in the Wastes
(90636, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Carved Crests
(90638, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- A Bundle of Crystals
(91143, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Carved Crests
(90665, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Carved Crests
(90666, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- A Bundle of Crystals
(90667, 0, 0, 0, 0, 0, 0, 0, 0, 'Another task completed. The Trust thanks you for your efforts. The founder has set aside a fund to encourage such initiative.', 63305), -- Enchanted Runed Ethereal Crest
(85109, 0, 0, 0, 0, 0, 0, 0, 0, 'Our thanks, traveler. May this serve you well.', 63305); -- Renowned with the K'aresh Trust

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=235252;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (90667,90666,90665,91143,90638,90636,90637,91142,92330,90635,90634,90633,90632,90631,90630);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(19, 0, 90630, 56, 138492, 0, 'A Small Bundle of Crystals - requires K''aresh Trust renown 5'),
(19, 0, 90631, 56, 138492, 0, 'Weathered Crests - requires K''aresh Trust renown 5'),
(19, 0, 90632, 56, 138493, 0, 'Valorstones - requires K''aresh Trust renown 6'),
(19, 0, 90633, 56, 138495, 0, 'Weathered Crests - requires K''aresh Trust renown 8'),
(19, 0, 90634, 56, 138495, 0, 'A Small Bundle of Crystals - requires K''aresh Trust renown 8'),
(19, 0, 90635, 56, 138496, 0, 'Valorstones - requires K''aresh Trust renown 9'),
(19, 0, 91142, 56, 138497, 0, 'Tabard for the Trusted - requires K''aresh Trust renown 10'),
(19, 0, 90636, 56, 138499, 0, 'Carved Crests - requires K''aresh Trust renown 12'),
(19, 0, 90637, 56, 138499, 0, 'A Key in the Wastes - requires K''aresh Trust renown 12'),
(19, 0, 90638, 56, 138500, 0, 'A Bundle of Crystals - requires K''aresh Trust renown 13'),
(19, 0, 91143, 56, 138501, 0, 'Carved Crests - requires K''aresh Trust renown 14'),
(19, 0, 92330, 56, 138503, 0, 'Valorstones - requires K''aresh Trust renown 16'),
(19, 0, 90665, 56, 138504, 0, 'Carved Crests - requires K''aresh Trust renown 17'),
(19, 0, 90666, 56, 138505, 0, 'A Bundle of Crystals - requires K''aresh Trust renown 18'),
(19, 0, 90667, 56, 138507, 0, 'Enchanted Runed Ethereal Crest - requires K''aresh Trust renown 20'),
(23, 235252, 235865, 7, 171, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Alchemy Knowledge requires Alchemy (1)'),
(23, 235252, 235864, 7, 164, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Blacksmithing Knowledge requires Blacksmithing (1)'),
(23, 235252, 235863, 7, 333, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Enchanting Knowledge requires Enchanting (1)'),
(23, 235252, 235862, 7, 202, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Engineering Knowledge requires Engineering (1)'),
(23, 235252, 235861, 7, 182, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Herbalism Knowledge requires Herbalism (1)'),
(23, 235252, 235860, 7, 773, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Inscription Knowledge requires Inscription (1)'),
(23, 235252, 235859, 7, 755, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Jewelcrafting Knowledge requires Jewelcrafting (1)'),
(23, 235252, 235858, 7, 165, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Leatherworking Knowledge requires Leatherworking (1)'),
(23, 235252, 235857, 7, 186, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Mining Knowledge requires Mining (1)'),
(23, 235252, 235856, 7, 393, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Skinning Knowledge requires Skinning (1)'),
(23, 235252, 235855, 7, 197, 1, 'Om''sirik <Renown Quartermaster> - Ethereal Tome of Tailoring Knowledge requires Tailoring (1)');
