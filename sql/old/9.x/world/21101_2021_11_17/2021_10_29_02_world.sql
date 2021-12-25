-- 
SET @CGUID := 1050138;

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1732, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=40593 WHERE `entry`=133362; -- Ambassador Moorgard
UPDATE `creature_template_model` SET `VerifiedBuild`=40593 WHERE (`CreatureID`=133362 AND `Idx`=0); -- Ambassador Moorgard

DELETE FROM `creature_model_info` WHERE `DisplayID`=82874;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(82874, 0.321299970149993896, 1.574999928474426269, 0, 40593);

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 133362, 0, 1519, 9171, '0', 10275, 0, 0, 0, -8172.59228515625, 801.0711669921875, 74.05037689208984375, 3.948031902313232421, 120, 0, 0, 47165, 57510, 0, 0, 0, 0, 40593); -- Ambassador Moorgard (Area: Stormwind Embassy - Difficulty: 0) (Auras: 262182 - Tophat)

DELETE FROM `creature_template_addon` WHERE `entry`=133362;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(133362, 0, 0, 0, 1, 0, 0, 0, 0, '262182'); -- 133362 (Ambassador Moorgard) - Tophat

DELETE FROM `creature_questender` WHERE `id`=133362 AND `quest` IN(51486, 49772, 49788, 55142, 58146);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(133362, 51486), -- Fer the Alliance (Dark Iron Dwarf)
(133362, 49772), -- For the Alliance (Lightforged Draenei)
(133362, 49788), -- For the Alliance (Void Elf)
(133362, 55142), -- For the Alliance (Kul Tiran)
(133362, 58146); -- For the Alliance (Mechagnome)

DELETE FROM `creature_queststarter` WHERE `id`=133362 AND `quest` IN(50305, 50313, 53500, 55146, 58147);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(133362, 50305), -- Stranger in a Strange Land (Void Elf)
(133362, 50313), -- Stranger in a Strange Land (Lightforged Draenei)
(133362, 53500), -- Stranger in a Strange Land (Dark Iron Dwarf)
(133362, 55146), -- Stranger in a Strange Land (Kul Tiran)
(133362, 58147); -- Stranger in a Strange Land (Mechagnome)

DELETE FROM `quest_template_addon` WHERE `ID` IN(51486,49772,49788,55142,58146,53500,50313,50305,55146,58147);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`) VALUES
(51486, 0, 53500), -- Fer the Alliance (Dark Iron Dwarf)
(49772, 0, 50313), -- For the Alliance (Lightforged Draenei)
(49788, 0, 50305), -- For the Alliance (Void Elf)
(55142, 0, 55146), -- For the Alliance (Kul Tiran)
(58146, 0, 58147), -- For the Alliance (Mechagnome)
(53500, 51486, 0), -- Stranger in a Strange Land (Dark Iron Dwarf)
(50313, 49772, 0), -- Stranger in a Strange Land (Lightforged Draenei)
(50305, 49788, 0), -- Stranger in a Strange Land (Void Elf)
(55146, 55142, 0), -- Stranger in a Strange Land (Kul Tiran)
(58147, 58146, 0); -- Stranger in a Strange Land (Mechagnome)

DELETE FROM `phase_area` WHERE `PhaseId`=10275 AND `AreaId` IN(9171, 5316, 5397);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9171, 10275, 'Cosmetic: Ambassador Moorgard at Stormwind Embassy (Area: Stormwind Embassy)'),
(5316, 10275, 'Cosmetic: Ambassador Moorgard at Stormwind Embassy (Area: Olivias Pond)'),
(5397, 10275, 'Cosmetic: Ambassador Moorgard at Stormwind Embassy (Area: The Wollerton Stead)'); 

DELETE FROM `conversation_actors` WHERE (`ConversationId`=6793 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(6793, 60390, 0, 126306, 82047, 40593);

DELETE FROM `conversation_line_template` WHERE `Id` IN (15489, 15490, 15491, 15492, 15493, 15494, 15495);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(15489, 82, 0, 0, 40593),
(15490, 82, 0, 0, 40593), -- Lightforged Draenei
(15491, 82, 0, 0, 40593), -- Void Elf
(15492, 82, 0, 0, 40593),
(15493, 82, 0, 0, 40593),
(15494, 82, 0, 0, 40593), -- Lightforged Draenei and Dark Iron Dwarf
(15495, 82, 0, 0, 40593); -- Void Elf

DELETE FROM `conversation_template` WHERE `Id`=6793;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(6793, 15489, 5124, 40593);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup`=10275 AND `SourceEntry`=0) OR (`SourceTypeOrReferenceId`=29 AND `SourceEntry` IN(15490,15491,15494,15495));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10275, 0, 0, 0, 16, 0, 0x800|0x4000|0x10000000|0x20000000|0x80000000, 0, 0, 0, 'Player is race Dark Iron Dwarf/Mechagnome/Void Elf/Lightforged Draenei/Kul Tiran'),
(29, 0, 15490, 0, 0, 16, 0, 0x20000000, 0, 0, 0, 'Only show conversation line if player is Lightforged Draenei'),
(29, 0, 15494, 0, 0, 16, 0, 0x800|0x20000000, 0, 0, 0, 'Only show conversation line if player is Dark Iron Dwarf or Lightforged Draenei'),
(29, 0, 15491, 0, 0, 16, 0, 0x10000000, 0, 0, 0, 'Only show conversation line if player is Void Elf'),
(29, 0, 15495, 0, 0, 16, 0, 0x10000000, 0, 0, 0, 'Only show conversation line if player is Void Elf');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=133362;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 133362 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(133362, 0, 0, 0, 20, 0, 100, 0, 51486, 0, 0, 0, 0, '', 143, 6793, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Moorgard - On quest reward 51486 (Dark Iron Dwarf) - Start Conversation 6793 - Invoker'),
(133362, 0, 1, 0, 20, 0, 100, 0, 49772, 0, 0, 0, 0, '', 143, 6793, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Moorgard - On quest reward 49772 (Lightforged Draenei) - Start Conversation 6793 - Invoker'),
(133362, 0, 2, 0, 20, 0, 100, 0, 49788, 0, 0, 0, 0, '', 143, 6793, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Moorgard - On quest reward 49788 (Void Elf) - Start Conversation 6793 - Invoker');
