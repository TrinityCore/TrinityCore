-- Creatures
UPDATE `creature_template` SET `ScriptName`='boss_murojin' WHERE `entry`=247570;
UPDATE `creature_template` SET `ScriptName`='boss_nekraxx' WHERE `entry`=247572;

-- Jump Charge Parameters
DELETE FROM `jump_charge_params` WHERE `id` IN (1515, 1516);
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `unlimitedSpeed`, `minHeight`, `maxHeight`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`, `triggerSpellId`) VALUES
(1516, 88.83, 0, 0, NULL, 0.001, 167151, NULL, NULL, NULL),
(1515, 69, 0, 0, 2, 0, 169394, NULL, NULL, NULL);

-- Convo
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` = 31838);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(31838, 109872, 0, 247570, 130699, 0, 0, 66263);

DELETE FROM `conversation_line_template` WHERE `Id` = 88429;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(88429, 1881, 0, 0, 0, 66263);

DELETE FROM `conversation_template` WHERE `Id` = 31838;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(31838, 88429, 0, 66263);

-- Waypoints
SET @ENTRY := 247570;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Muro\'jin - Intro path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 1, -908.35016, 154.8508, 99.766556, NULL, 0),
(@PATH, 2, -913.1424, 156.8368, 99.76655, 0.939757, 0);

SET @ENTRY := 247572;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 3, 0x2, 54.6738, 'Nekraxx - Cyclic path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -903.1597, 234.39583, 182.88557, NULL, 0),
(@PATH, 1, -887.0816, 316.5729, 197.14137, NULL, 0),
(@PATH, 2, -861.73267, 410.0625, 213.4189, NULL, 0),
(@PATH, 3, -749.066, 449.04514, 217.18285, NULL, 0),
(@PATH, 4, -674.1684, 409.11978, 218.18811, NULL, 0),
(@PATH, 5, -631.96356, 334.6146, 218.54137, NULL, 0),
(@PATH, 6, -662.00867, 259.18057, 211.22678, NULL, 0),
(@PATH, 7, -716.7309, 208.37674, 199.23856, NULL, 0),
(@PATH, 8, -823.0139, 146.42361, 180.83803, NULL, 0),
(@PATH, 9, -883.2344, 108.9375, 175.99745, NULL, 0),
(@PATH, 10, -917.57117, 131.2118, 176.54427, NULL, 0),
(@PATH, 11, -910.7274, 189.55035, 178.5131, NULL, 0);

SET @ENTRY := 247572;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 3, 0x2, 50, 'Nekraxx - Intro path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -837.2899, 235.53473, 163.36263, NULL, 0),
(@PATH, 1, -914.7274, 162.20312, 108.62212, NULL, 0);

-- Worldstates
DELETE FROM `world_state` WHERE `ID` IN (29249, 29250);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(29250, 8, '2874', NULL, '', 'Maisara Caverns - Prisoners Freed (max count)'),
(29249, 0, '2874', NULL, 'worldstate_maisara_caverns_prisoners_freed', 'Maisara Caverns - Prisoners Freed (counter)');

-- Areatriggers
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (38589,39140,38585,40107));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(38589, 0, 40226, 0, 4, 0, 0, 0, 0, -1, 0, 834, NULL, 4000, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_murojin_and_nekraxx_icy_slick', 66263), -- Spell: 1243751 (Icy Slick)
(39140, 0, 40662, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 10000, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 'at_murojin_and_nekraxx_carrion_swoop', 66263), -- Spell: 1249481 (Carrion Swoop)
(38585, 0, 40223, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 40000, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 'at_murojin_and_nekraxx_freezing_trap', 66263), -- Spell: 1243731 (Freezing Trap)
(40107, 0, 41450, 0, 2, 0, 0, 0, 0, -1, 0, 0, NULL, 8000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, '', 66263); -- Spell: 1243741 (Freezing Trap)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (40226,40662,40223,41450));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(40226, 0, 66263),
(40662, 0, 66263),
(40223, 0, 66263),
(41450, 0, 66263);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_maisara_caverns_release_captive', 'spell_murojin_and_nekraxx_harpoon', 'spell_murojin_and_nekraxx_freezing_trap_selector', 'spell_murojin_and_nekraxx_freezing_trap_missile', 'spell_murojin_and_nekraxx_freezing_trap_stun', 'spell_murojin_and_nekraxx_barrage_selector', 'spell_murojin_and_nekraxx_barrage_periodic', 'spell_murojin_and_nekraxx_flanking_spear', 'spell_murojin_and_nekraxx_revive_pet', 'spell_murojin_and_nekraxx_fetid_quillstorm_selector', 'spell_murojin_and_nekraxx_fetid_quillstorm_charge', 'spell_murojin_and_nekraxx_fetid_quillstorm', 'spell_murojin_and_nekraxx_fetid_quillstorm_visual', 'spell_murojin_and_nekraxx_carrion_swoop_selector', 'spell_murojin_and_nekraxx_carrion_swoop_aura', 'spell_murojin_and_nekraxx_carrion_swoop_knockback', 'spell_murojin_and_nekraxx_coordinated_assault');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1259069, 'spell_maisara_caverns_release_captive'),
(1266483, 'spell_murojin_and_nekraxx_harpoon'),
(1260728, 'spell_murojin_and_nekraxx_freezing_trap_selector'),
(1260731, 'spell_murojin_and_nekraxx_freezing_trap_missile'),
(1243741, 'spell_murojin_and_nekraxx_freezing_trap_stun'),
(1260642, 'spell_murojin_and_nekraxx_barrage_selector'),
(1259069, 'spell_murojin_and_nekraxx_barrage_periodic'),
(1266485, 'spell_murojin_and_nekraxx_flanking_spear'),
(1249789, 'spell_murojin_and_nekraxx_revive_pet'),
(1249474, 'spell_murojin_and_nekraxx_fetid_quillstorm_selector'),
(1249475, 'spell_murojin_and_nekraxx_fetid_quillstorm_charge'),
(1243900, 'spell_murojin_and_nekraxx_fetid_quillstorm'),
(1256157, 'spell_murojin_and_nekraxx_fetid_quillstorm_visual'),
(1249477, 'spell_murojin_and_nekraxx_carrion_swoop_selector'),
(1249478, 'spell_murojin_and_nekraxx_carrion_swoop_aura'),
(1249669, 'spell_murojin_and_nekraxx_carrion_swoop_knockback'),
(1249989, 'spell_murojin_and_nekraxx_coordinated_assault');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (247570, 247572);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- Aggro
(247570, 0, 0, 'What be dis, Nekraxx? Fresh prey? Ha ha ha!', 14, 0, 33, 0, 0, 301644, 297146, 0, 'Muro\'jin'),
(247570, 0, 1, 'More heads for de quota. Ready, Nekraxx?', 14, 0, 33, 0, 0, 301646, 297147, 0, 'Muro\'jin'),
(247570, 0, 2, 'Oh, you look like a good catch.', 14, 0, 33, 0, 0, 301645, 297149, 0, 'Muro\'jin'),
-- Flanking spear
(247570, 1, 0, 'Cut where de blood flow.', 14, 0, 50, 0, 0, 301669, 297201, 0, 'Muro\'jin'),
(247570, 1, 1, 'De fit survive. You won\'t.', 14, 0, 50, 0, 0, 301671, 297212, 0, 'Muro\'jin'),
-- Infected Pinions
(247570, 2, 0, 'If I don\'t getcha, Nekraxx will!', 14, 0, 50, 0, 0, 301667, 297211, 0, 'Muro\'jin'),
(247570, 2, 1, 'Sic \'em, Nekraxx!', 14, 0, 50, 0, 0, 301658, 297176, 0, 'Muro\'jin'),
-- Freezing Trap
(247570, 3, 0, 'Freeze!', 14, 0, 33, 0, 0, 301661, 297172, 0, 'Muro\'jin'),
(247570, 3, 1, 'Frozen in fright.', 14, 0, 33, 0, 0, 301662, 297173, 0, 'Muro\'jin'),
(247570, 3, 2, 'Right into my trap.', 14, 0, 33, 0, 0, 301663, 297174, 0, 'Muro\'jin'),
-- Fetid Quillstorm
(247570, 4, 0, 'Nekraxx, strike!', 14, 0, 50, 0, 0, 301660, 297179, 0, 'Muro\'jin'),
(247570, 4, 1, 'With me, Nekraxx!', 14, 0, 50, 0, 0, 301659, 297178, 0, 'Muro\'jin'),
-- Barrage
(247570, 5, 0, 'Aim for de heart.', 14, 0, 50, 0, 0, 301668, 297200, 0, 'Muro\'jin'),
(247570, 5, 1, 'Right on target.', 14, 0, 50, 0, 0, 301664, 297198, 0, 'Muro\'jin'),
-- Barrage Warning
(247570, 6, 0, '|TInterface\Icons\Ability_Hunter_RapidRegeneration:20|t You have been targetted by |cFFFF0000|Hspell:1260643|h[Barrage]|h|r!', 68, 0, 100, 0, 0, 301664, 0, 0, 'Muro\'jin'),
-- Carrion Swoop
(247570, 7, 0, 'Take dem down, Nekraxx!', 14, 0, 50, 0, 0, 301651, 297182, 0, 'Muro\'jin'),
(247570, 7, 1, 'Nekraxx, fly!', 14, 0, 50, 0, 0, 301650, 297183, 0, 'Muro\'jin'),
-- Coordinated Assault
(247570, 8, 0, 'De killin\' blow.', 14, 0, 50, 0, 0, 301654, 297186, 0, 'Muro\'jin'),
(247570, 8, 1, 'In for de kill.', 14, 0, 50, 0, 0, 301654, 297188, 0, 'Muro\'jin'),
-- Slay
(247570, 9, 0, 'Too bad. Dey worth more alive.', 14, 0, 100, 0, 0, 301677, 297152, 0, 'Muro\'jin'),
-- Nekraxx Died
(247570, 10, 0, 'Nekraxx! No!', 14, 0, 100, 0, 0, 301683, 297189, 0, 'Muro\'jin'),
-- Nekraxx Revived
(247570, 11, 0, 'You gonna pay for dat!', 14, 0, 100, 0, 0, 301649, 297192, 0, 'Muro\'jin'),
-- Carrion Swoop Warning
(247572, 0, 0, '|TInterface\\ICONS\\INV_Misc_EagleClaw_Fel.BLP:20|t %s targets $n with |cFFFF0000|Hspell:1249479|h[Carrion Swoop]|h|r!', 68, 0, 100, 0, 0, 301651, 0, 0, 'Nekraxx to Player');
