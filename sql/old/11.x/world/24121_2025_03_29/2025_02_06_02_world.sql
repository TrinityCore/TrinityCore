DELETE FROM `creature` WHERE `guid` IN(7000223, 7000240);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=122967;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(122967, 0, 0, 128956, -1110.5, 2259.43, 741.76, 5.762872, 8, 0, 'Priestess Alun''za - Group 0 - Blood-Tainted Cauldron of Gold'),
(122967, 0, 0, 128956, -1110.55, 2325.28, 741.76, 0.0458011, 8, 0, 'Priestess Alun''za - Group 0 - Blood-Tainted Cauldron of Gold');

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=122967;
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2, `speed_run`=1.428571462631225585, `BaseAttackTime`=769, `unit_flags3`=0x0, `ScriptName`='npc_priestess_alun_za_spirit_of_gold' WHERE `entry`=131009; -- Spirit of Gold
UPDATE `creature_template` SET `unit_flags2`=67108864, `unit_flags3`=16777217 WHERE `entry`=130738; -- Corrupted Gold
UPDATE `creature_template` SET `unit_flags`=32832, `ScriptName`='boss_priestess_alun_za' WHERE `entry`=122967;
UPDATE `creature_template` SET `ScriptName`='npc_priestess_alun_za_corrupted_gold', `flags_extra`=0x20000000 WHERE `entry`=130738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=128956;
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=0x10000000, `VerifiedBuild`=58773 WHERE (`Entry`=131009 AND `DifficultyID`=23); -- 131009 (Spirit of Gold) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `VerifiedBuild`=58773 WHERE (`Entry`=130738 AND `DifficultyID`=23); -- 130738 (Corrupted Gold) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `VerifiedBuild`=58773 WHERE (`Entry`=128956 AND `DifficultyID`=23); -- 128956 (Blood-Tainted Cauldron of Gold) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=0x10000000, `VerifiedBuild`=58773 WHERE (`Entry`=122967 AND `DifficultyID`=0); -- 122967 (Priestess Alun'za) - CanSwim

DELETE FROM `creature_model_info` WHERE `DisplayID` = 81527;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(81527, 1.468834877014160156, 3, 0, 53989);

DELETE FROM `creature_text` WHERE `CreatureID`=122967;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(122967, 0, 0, 'You came for de gold, but you will leave behind your bones!', 14, 0, 100, 0, 0, 97339, 140324, 0, 'Priestess Alun\'za'),
(122967, 0, 1, 'Servants of Yazma are not welcome here!', 14, 0, 100, 0, 0, 97338, 140323, 0, 'Priestess Alun\'za'),
(122967, 1, 0, '$n gilds her hands with gold.', 16, 0, 100, 0, 0, 227383, 138800, 0, 'Priestess Alun\'za'),
(122967, 2, 0, 'Atal\'Dazar\'s power flows through me!', 14, 0, 100, 0, 0, 97332, 140330, 0, 'Priestess Alun\'za'),
(122967, 2, 1, 'My claws will find your heart.', 14, 0, 100, 0, 0, 227383, 140353, 0, 'Priestess Alun\'za'),
(122967, 3, 0, '|TInterface\\Icons\\SPELL_HOLY_PURIFY.BLP:20|t$n casts |cFFFF0000|Hspell:255577|h[Transfusion]|h|r!', 41, 0, 100, 0, 0, 97337, 138801, 0, 'Priestess Alun\'za'),
(122967, 4, 0, 'You do not belong here!', 14, 0, 100, 0, 0, 97337, 140354, 0, 'Priestess Alun\'za'),
(122967, 4, 1, 'Corruption be purified!', 14, 0, 100, 0, 0, 97336, 140331, 0, 'Priestess Alun\'za'),
(122967, 5, 0, 'Death is a better fit for you.', 14, 0, 100, 0, 0, 97328, 140328, 0, 'Priestess Alun\'za'),
(122967, 5, 1, 'You have been cleansed!', 14, 0, 100, 0, 0, 97329, 140329, 0, 'Priestess Alun\'za'),
(122967, 6, 0, 'You should never have come here.', 14, 0, 100, 0, 0, 97331, 140325, 0, 'Priestess Alun\'za'),
(122967, 6, 1, 'Only de worthy are buried here. Your corpses will feed de raptors!', 14, 0, 100, 0, 0, 97330, 140326, 0, 'Priestess Alun\'za'),
(122967, 7, 0, 'De pools... must be... cleansed.', 14, 0, 100, 0, 0, 97340, 140327, 0, 'Priestess Alun\'za');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (255592, 255615, 255575);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 255592, 0, 0, 51, 0, 5, 128956, 0, '', 0, 0, 0, '', 'Spell \'Tainted Blood\' can only hit \'Blood-Tainted Cauldron of Gold\''),
(13, 1, 255615, 0, 0, 51, 0, 5, 128956, 0, '', 0, 0, 0, '', 'Spell \'Tainted Blood\' can only hit \'Blood-Tainted Cauldron of Gold\''),
(13, 1, 255575, 0, 0, 51, 0, 6, 0, 0, '', 0, 0, 0, '', 'Spell \'Transfusion\' can only hit Player');

DELETE FROM `smart_scripts` WHERE `entryorguid`=128956 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(128956, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Blood-Tainted Cauldron of Gold - On Just Created - Set ReactState Passive');

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (16860, 16553));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(16860, 0, 0, 53989),
(16553, 0, 0, 53989);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id`IN (11867, 12159));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(11867, 0, 16553, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 60000, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_priestess_alun_za_tainted_blood', 53989), -- Spell: 255559 (Tainted Blood)
(12159, 0, 16860, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1.5, 1.5, 0, 0, 0, 0, 0, 0, 'at_priestess_alun_za_corrupted_gold',53989); -- Spell: 258703 (Corrupted Gold)

DELETE FROM `spell_script_names` WHERE `spell_id` IN (255615, 255592, 255566, 255591, 255584, 258388, 255565, 258681, 255577, 255575, 259205, 259209, 255835, 255836, 259032);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(255615, 'spell_priestess_alun_za_agitate'),
(255592, 'spell_priestess_alun_za_tainted_blood'),
(255566, 'spell_priestess_alun_za_bubble'),
(255591, 'spell_priestess_alun_za_molten_gold'),
(255584, 'spell_priestess_alun_za_molten_gold_selector'),
(258388, 'spell_priestess_alun_za_ritual'),
(258681, 'spell_priestess_alun_za_energy_regen'),
(255577, 'spell_priestess_alun_za_transfusion_cast'),
(255575, 'spell_priestess_alun_za_transfusion'),
(259205, 'spell_priestess_alun_za_spirit_of_gold'),
(259209, 'spell_priestess_alun_za_spirit_of_gold'),
(255835, 'spell_priestess_alun_za_transfusion_heal'),
(255836, 'spell_priestess_alun_za_transfusion_damage'),
(259032, 'spell_priestess_alun_za_corrupt');
