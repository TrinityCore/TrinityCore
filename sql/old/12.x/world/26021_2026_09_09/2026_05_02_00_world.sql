UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321,`StaticFlags1`=0x10000060,`VerifiedBuild`=67186 WHERE `Entry`=255473 AND `DifficultyID`=0; -- 255473 (Maren Silverwing) - ImmuneToPc, ImmuneToNpc, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321,`StaticFlags1`=0x10000060,`VerifiedBuild`=67186 WHERE `Entry`=255476 AND `DifficultyID`=0; -- 255476 (Triam Dawnsetter) - ImmuneToPc, ImmuneToNpc, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3313,`StaticFlags1`=0x10000060,`VerifiedBuild`=67186 WHERE `Entry`=255495 AND `DifficultyID`=0; -- 255495 (Rae'ana) - ImmuneToPc, ImmuneToNpc, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3321,`StaticFlags1`=0x10000020,`VerifiedBuild`=67186 WHERE `Entry`=255503 AND `DifficultyID`=0; -- 255503 (Sergeant Vornin) - ImmuneToPc, CanSwim
UPDATE `creature_template` SET `faction`=3526,`npcflag`=129,`BaseAttackTime`=2000,`unit_flags`=0x300,`unit_flags2`=0x800 WHERE `entry`=255473; -- Maren Silverwing
UPDATE `creature_template` SET `faction`=3526,`npcflag`=129,`BaseAttackTime`=2000,`unit_flags`=0x300,`unit_flags2`=0x800 WHERE `entry`=255476; -- Triam Dawnsetter
UPDATE `creature_template` SET `faction`=3270,`npcflag`=131,`BaseAttackTime`=2000,`unit_flags`=0x300,`unit_flags2`=0x800 WHERE `entry`=255495; -- Rae'ana
UPDATE `creature_template` SET `faction`=3524,`npcflag`=129,`BaseAttackTime`=2000,`unit_flags`=0x100,`unit_flags2`=0x800 WHERE `entry`=255503; -- Sergeant Vornin

DELETE FROM `creature_template_addon` WHERE `entry` IN (255473,255476,255495,255503);
INSERT INTO `creature_template_addon` (`entry`,`PathId`,`mount`,`StandState`,`AnimTier`,`VisFlags`,`SheathState`,`PvpFlags`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`visibilityDistanceType`,`auras`) VALUES
(255473,0,0,0,0,0,0,0,0,0,0,0,0,'421177 421175'), -- Maren Silverwing <Quartermaster> - Disable ALL Mounts, Disable ALL Mounts
(255476,0,0,0,0,0,0,0,0,0,0,0,0,'421177 421175'), -- Triam Dawnsetter <Cosmetic Equipment Salvager> - Disable ALL Mounts, Disable ALL Mounts
(255495,0,0,0,0,0,1,0,0,0,0,0,0,''), -- Rae'ana <Historian and Research Supplier>
(255503,0,0,0,0,0,1,0,0,0,0,0,0,''); -- Sergeant Vornin <Animal Handler>

DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (255473,255476,255495,255503);
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(255473,42907,67186), -- Maren Silverwing <Quartermaster>
(255476,42101,67186), -- Triam Dawnsetter <Cosmetic Equipment Salvager>
(255495,42103,67186), -- Rae'ana <Historian and Research Supplier>
(255503,42114,67186); -- Sergeant Vornin <Animal Handler>

DELETE FROM `npc_vendor` WHERE `entry` IN (255473,255476,255495,255503);
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`ExtendedCost`,`type`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) VALUES
(255473, 1,263928,0,11138,1,     0,0,67186), -- Cache of Void-Touched Armaments
(255473, 2,263929,0,11139,1,     0,0,67186), -- Cache of Void-Touched Armaments
(255473, 3,268996,0,11400,1,     0,0,67186), -- Field Accolade Pouch
(255476, 1,264323,0,11267,1,154160,0,67314), -- Cache of Void-Touched Weapons
(255476, 2,264314,0,11266,1,154156,0,67314), -- Cache of Void-Touched Headgear
(255476, 3,264315,0,11266,1,154158,0,67314), -- Cache of Void-Touched Shoulderwear
(255476, 4,264316,0,11266,1,154153,0,67314), -- Cache of Void-Touched Cloaks
(255476, 5,264317,0,11266,1,154152,0,67314), -- Cache of Void-Touched Chestpieces
(255476, 6,264318,0,11266,1,154159,0,67314), -- Cache of Void-Touched Bracers
(255476, 7,264319,0,11266,1,154155,0,67314), -- Cache of Void-Touched Gloves
(255476, 8,264320,0,11266,1,154151,0,67314), -- Cache of Void-Touched Belts
(255476, 9,264321,0,11266,1,154157,0,67314), -- Cache of Void-Touched Legwear
(255476,10,264322,0,11266,1,154154,0,67314), -- Cache of Void-Touched Boots
(255495, 1,273159,0,11542,1,153041,0,67186), -- Void Elf Scribe's Desk
(255495, 2,273135,0,11525,1,153041,0,67186), -- Void Elf Floating Desk
(255495, 3,273142,0,11525,1,153041,0,67186), -- Runic Parchment
(255495, 4,273157,0,11525,1,153041,0,67186), -- Void Flame Candle
(255495, 5,273147,0,11525,1,153041,0,67186), -- Void Inkwell
(255495, 6,271158,0,11268,1,153045,0,67186), -- Dark Obelisk
(255503, 1,264348,0,11269,1,149652,0,67186), -- Unbound Manawyrm
(255503, 2,268578,0,11519,1,153046,0,67186), -- Void-Touched Hawkstrider
(255503, 3,270331,0,11520,1,153044,0,67186), -- Void-Infused Mindbreaker Fry
(255503, 4,270330,0,11520,1,153044,0,67186), -- Void-Touched Dragonhawk Egg
(255503, 5,270989,0,11521,1,154481,0,67186); -- Cappy

SET @NPCTEXTID := 610020;
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+8;
INSERT INTO `npc_text` (`ID`,`Probability0`,`Probability1`,`Probability2`,`Probability3`,`Probability4`,`Probability5`,`Probability6`,`Probability7`,`BroadcastTextId0`,`BroadcastTextId1`,`BroadcastTextId2`,`BroadcastTextId3`,`BroadcastTextId4`,`BroadcastTextId5`,`BroadcastTextId6`,`BroadcastTextId7`,`VerifiedBuild`) VALUES
(@NPCTEXTID+0,1,0,0,0,0,0,0,0,307720,0,0,0,0,0,0,0,67186), -- Triam Dawnsetter <Cosmetic Equipment Salvager>
(@NPCTEXTID+1,1,0,0,0,0,0,0,0,307718,0,0,0,0,0,0,0,67186), -- Triam Dawnsetter <Cosmetic Equipment Salvager>
(@NPCTEXTID+2,1,0,0,0,0,0,0,0,307724,0,0,0,0,0,0,0,67186), -- Rae'ana <Historian and Research Supplier>
(@NPCTEXTID+3,1,0,0,0,0,0,0,0,307722,0,0,0,0,0,0,0,67186), -- Rae'ana <Historian and Research Supplier>
(@NPCTEXTID+4,1,0,0,0,0,0,0,0,307743,0,0,0,0,0,0,0,67186), -- Sergeant Vornin <Animal Handler>
(@NPCTEXTID+5,1,0,0,0,0,0,0,0,307740,0,0,0,0,0,0,0,67186), -- Sergeant Vornin <Animal Handler>
(@NPCTEXTID+6,1,0,0,0,0,0,0,0,312807,0,0,0,0,0,0,0,67186), -- Maren Silverwing <Quartermaster>
(@NPCTEXTID+7,1,0,0,0,0,0,0,0,312805,0,0,0,0,0,0,0,67186), -- Maren Silverwing <Quartermaster>
(@NPCTEXTID+8,1,0,0,0,0,0,0,0,312813,0,0,0,0,0,0,0,67186); -- Maren Silverwing <Quartermaster>

DELETE FROM `gossip_menu` WHERE `MenuID` IN (42100,42101,42102,42103,42113,42114,42906,42907,42909);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(42100,@NPCTEXTID+0,67186), -- Triam Dawnsetter <Cosmetic Equipment Salvager>
(42101,@NPCTEXTID+1,67186), -- Triam Dawnsetter <Cosmetic Equipment Salvager>
(42102,@NPCTEXTID+2,67186), -- Rae'ana <Historian and Research Supplier>
(42103,@NPCTEXTID+3,67186), -- Rae'ana <Historian and Research Supplier>
(42113,@NPCTEXTID+4,67186), -- Sergeant Vornin <Animal Handler>
(42114,@NPCTEXTID+5,67186), -- Sergeant Vornin <Animal Handler>
(42906,@NPCTEXTID+6,67186), -- Maren Silverwing <Quartermaster>
(42907,@NPCTEXTID+7,67186), -- Maren Silverwing <Quartermaster>
(42909,@NPCTEXTID+8,67186); -- Maren Silverwing <Quartermaster>

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (42100,42101,42102,42103,42113,42114,42906,42907,42909);
INSERT INTO `gossip_menu_option` (`MenuID`,`GossipOptionID`,`OptionID`,`OptionNpc`,`OptionText`,`OptionBroadcastTextID`,`Language`,`Flags`,`ActionMenuID`,`ActionPoiID`,`GossipNpcOptionID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`SpellID`,`OverrideIconID`,`VerifiedBuild`) VALUES
(42100,139799,0,0,'I want to talk about something else.',0,0,0,42101,0,NULL,0,0,NULL,0,NULL,NULL,67314),
(42101,138131,0,0,'What did you find?',0,0,0,42100,0,NULL,0,0,NULL,0,NULL,NULL,67314),
(42101,138965,1,1,'What gear slots are available?',0,0,0,0,0,NULL,0,0,NULL,0,NULL,NULL,67314),
(42102,139803,0,0,'I want to talk about something else.',0,0,0,42103,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42103,138132,0,0,'What is your role in the Ranger Captain''s task force?',0,0,0,42102,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42103,138355,1,1,'Can I see the relics you have found and deemed safe?',0,0,0,0,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42113,139802,0,0,'I want to talk about something else.',0,0,0,42114,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42114,138139,0,0,'Oh, just curious what your part is in the task force?',0,0,0,42113,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42114,138966,1,1,'Do you have any mounts or pets available now?',0,0,0,0,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42906,139798,0,0,'I want to talk about something else.',0,0,0,42907,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42907,139420,0,1,'I''d like to exchange Field Accolades for gear.',0,0,0,0,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42907,139421,1,0,'What did you discover recently?',0,0,0,42906,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42907,139423,2,0,'Is Mayven your sister?',0,0,0,42909,0,NULL,0,0,NULL,0,NULL,NULL,67186),
(42909,139424,0,0,'I want to talk about something else.',0,0,0,42907,0,NULL,0,0,NULL,0,NULL,NULL,67186);
