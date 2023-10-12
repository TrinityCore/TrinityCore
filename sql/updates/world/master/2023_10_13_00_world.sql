-- 
SET @AREATRIGGERID := 42; 
SET @ATSPAWNID := 34;
SET @BOUNDING_RADIUS := 7.36909;

-- fix TrialOfValorHelheim tele pos
UPDATE `game_tele` SET `position_x`=340.86285, `position_y`=355.21353, `position_z`=30.486437 WHERE `id`=1722;

-- fix guarm exit door
UPDATE `gameobject_addon` SET `AIAnimKitID`=0 WHERE `guid`=400206;

DELETE FROM `instance_template` WHERE `map`=1648;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1648, 0, 'instance_trial_of_valor');

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @AREATRIGGERID+0 AND @AREATRIGGERID+2;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES 
(@AREATRIGGERID+0, 0, 0, 4, @BOUNDING_RADIUS*1.25, @BOUNDING_RADIUS*1.25, 0, 0, 0, 0, 0, 0, 0), -- Berserk Charge
(@AREATRIGGERID+1, 0, 0, 4, @BOUNDING_RADIUS, @BOUNDING_RADIUS, 0, 0, 0, 0, 0, 0, 0), -- Headlong Charge
(@AREATRIGGERID+2, 1, 1, 0, 30, 20, 10, 30, 20, 10, 0, 0, 0); -- Guarm In Range Convo Trigger

UPDATE `areatrigger_template` SET `VerifiedBuild`=48865 WHERE (`IsServerSide`=0 AND `Id` IN (13352,13353,13354));

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (9358, 9359, 9355, 9352, 9357, 9360, 9353, 9354, 9356, 9293, 8816);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(9358, 13352, 0, 0, 0, 0, -1, 0, 115, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 48865), -- Spell: 232804 (Guardian's Breath)
(9359, 13353, 0, 0, 0, 0, -1, 0, 116, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 48865), -- Spell: 232805 (Guardian's Breath)
(9355, 13354, 0, 0, 0, 0, -1, 0, 117, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 48865), -- Spell: 232801 (Guardian's Breath)
(9352, 13352, 0, 0, 0, 0, -1, 0, 115, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232773 (Guardian's Breath)
(9357, 13352, 0, 0, 0, 0, -1, 0, 115, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232803 (Guardian's Breath)
(9360, 13353, 0, 0, 0, 0, -1, 0, 116, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232806 (Guardian's Breath)
(9353, 13353, 0, 0, 0, 0, -1, 0, 116, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232774 (Guardian's Breath)
(9354, 13354, 0, 0, 0, 0, -1, 0, 117, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232776 (Guardian's Breath)
(9356, 13354, 0, 0, 0, 0, -1, 0, 117, 0, 5000, 3, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Spell: 232802 (Guardian's Breath)
(9293, @AREATRIGGERID+0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, @BOUNDING_RADIUS*1.25, @BOUNDING_RADIUS*1.25, 0, 0, 0, 0, 0, 0, 0), -- Spell: 232173 (Berserk Charge)
(8816, @AREATRIGGERID+1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, @BOUNDING_RADIUS, @BOUNDING_RADIUS, 0, 0, 0, 0, 0, 0, 0); -- Spell: 227833 (Headlong Charge)

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE (`AreaTriggerCreatePropertiesId`=9355 AND `Idx` IN (3,2,1,0) OR (`AreaTriggerCreatePropertiesId`=9358 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9359 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=11887 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9352 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9353 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9354 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9356 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9357 AND `Idx` IN (3,2,1,0)) OR (`AreaTriggerCreatePropertiesId`=9360 AND `Idx` IN (3,2,1,0)));
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(9355, 3, 40, -10, NULL, NULL, 48865), -- SpellId : 232801
(9355, 2, 30, -23, NULL, NULL, 48865), -- SpellId : 232801
(9355, 1, -1, -2, NULL, NULL, 48865), -- SpellId : 232801
(9355, 0, 0, -1, NULL, NULL, 48865), -- SpellId : 232801
(9358, 3, 30, 23, NULL, NULL, 48865), -- SpellId : 232804
(9358, 2, 40, 10, NULL, NULL, 48865), -- SpellId : 232804
(9358, 1, 0, 1, NULL, NULL, 48865), -- SpellId : 232804
(9358, 0, -1, 2, NULL, NULL, 48865), -- SpellId : 232804
(9359, 3, 40, 10, NULL, NULL, 48865), -- SpellId : 232805
(9359, 2, 40, -10, NULL, NULL, 48865), -- SpellId : 232805
(9359, 1, 0, -1, NULL, NULL, 48865), -- SpellId : 232805
(9359, 0, 0, 1, NULL, NULL, 48865), -- SpellId : 232805
(9352, 3, 40, 10, NULL, NULL, 23420), -- Spell: 232773 (Guardian's Breath)
(9352, 2, 40, -10, NULL, NULL, 23420), -- Spell: 232773 (Guardian's Breath)
(9352, 1, 0, -1, NULL, NULL, 23420), -- Spell: 232773 (Guardian's Breath)
(9352, 0, 0, 1, NULL, NULL, 23420), -- Spell: 232773 (Guardian's Breath)
(9353, 3, 40, -10, NULL, NULL, 23420), -- Spell: 232774 (Guardian's Breath)
(9353, 2, 30, -23, NULL, NULL, 23420), -- Spell: 232774 (Guardian's Breath)
(9353, 1, -1, -2, NULL, NULL, 23420), -- Spell: 232774 (Guardian's Breath)
(9353, 0, 0, -1, NULL, NULL, 23420), -- Spell: 232774 (Guardian's Breath)
(9354, 3, 30, 23, NULL, NULL, 23420), -- Spell: 232776 (Guardian's Breath)
(9354, 2, 40, 10, NULL, NULL, 23420), -- Spell: 232776 (Guardian's Breath)
(9354, 1, 0, 1, NULL, NULL, 23420), -- Spell: 232776 (Guardian's Breath)
(9354, 0, -1, 2, NULL, NULL, 23420), -- Spell: 232776 (Guardian's Breath)
(9356, 3, 40, 10, NULL, NULL, 23420), -- Spell: 232802 (Guardian's Breath)
(9356, 2, 40, -10, NULL, NULL, 23420), -- Spell: 232802 (Guardian's Breath)
(9356, 1, 0, -1, NULL, NULL, 23420), -- Spell: 232802 (Guardian's Breath)
(9356, 0, 0, 1, NULL, NULL, 23420), -- Spell: 232802 (Guardian's Breath)
(9357, 3, 40, -10, NULL, NULL, 23420), -- Spell: 232803 (Guardian's Breath)
(9357, 2, 30, -23, NULL, NULL, 23420), -- Spell: 232803 (Guardian's Breath)
(9357, 1, -1, -2, NULL, NULL, 23420), -- Spell: 232803 (Guardian's Breath)
(9357, 0, 0, -1, NULL, NULL, 23420), -- Spell: 232803 (Guardian's Breath)
(9360, 3, 30, 23, NULL, NULL, 23420), -- Spell: 232806 (Guardian's Breath)
(9360, 2, 40, 10, NULL, NULL, 23420), -- Spell: 232806 (Guardian's Breath)
(9360, 1, 0, 1, NULL, NULL, 23420), -- Spell: 232806 (Guardian's Breath)
(9360, 0, -1, 2, NULL, NULL, 23420); -- Spell: 232806 (Guardian's Breath)

UPDATE `areatrigger_create_properties` SET `ScriptName`='at_guardians_breath_red' WHERE `Id` IN(9358, 9352, 9357);
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_guardians_breath_green' WHERE `Id` IN(9359, 9360, 9353);
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_guardians_breath_blue' WHERE `Id` IN(9355, 9354, 9356);
UPDATE `areatrigger_create_properties` SET `ScriptName`='SmartAreaTriggerAI' WHERE `Id` IN(9293, 8816);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES 
(@ATSPAWNID+0, @AREATRIGGERID+2, 1, 1648, '14,15,16,17', 469.0233, 460.4998, 4.8196, 4.7948, 1, 0, 0, 1, 30, 20, 10, 30, 20, 10, 0, 0, 'SmartAreaTriggerAI', 'Guarm In Range Convo Trigger');

DELETE FROM `smart_scripts` WHERE (`source_type`=11 AND `entryorguid` IN(@AREATRIGGERID+0, @AREATRIGGERID+1)) OR (`source_type`=12 AND `entryorguid`=@AREATRIGGERID+2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@AREATRIGGERID+0, 11, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 232197, 2, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'On Guarm Berserk Charge AreaTrigger enter - Cast Spell Berserk Charge - Invoker'),
(@AREATRIGGERID+1, 11, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 86, 227843, 2, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'On Guarm Headlong Charge AreaTrigger enter - Cast Spell Headlong Charge - Invoker'),
(@AREATRIGGERID+2, 12, 0, 0, 46, 0, 100, 1, 0, 0, 0, 0, 0, '', 143, 3916, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 0, 'On Guarm In Range AreaTrigger enter - Create Conversation - Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN(@AREATRIGGERID+0, @AREATRIGGERID+1) AND `SourceId` = 11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, @AREATRIGGERID+0, 11, 0, 52, 0, 64, 0, 0, 0, 'Action invoker is of type player'),
(22, 1, @AREATRIGGERID+1, 11, 0, 52, 0, 64, 0, 0, 0, 'Action invoker is of type player');

DELETE FROM `vehicle_template_accessory` WHERE (`entry`=114323 AND `seat_id` IN (2,1,0));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(114323, 114344, 2, 1, 'Guarm - Guarm', 8, 0), -- Guarm - Guarm
(114323, 114343, 1, 1, 'Guarm - Guarm', 8, 0), -- Guarm - Guarm
(114323, 114341, 0, 1, 'Guarm - Guarm', 8, 0); -- Guarm - Guarm

SET @PATH1 := (114323 * 100) + 0;
SET @PATH2 := (114323 * 100) + 1;
SET @PATH3 := (114323 * 100) + 2;
SET @PATH4 := (114323 * 100) + 3;
SET @PATH5 := (114323 * 100) + 4;
DELETE FROM `waypoint_data` WHERE `id` IN(@PATH1, @PATH2, @PATH3, @PATH4, @PATH5);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH1, 1, 479.3734, 447.34622, 5.0953035),
(@PATH1, 2, 476.8734, 483.59622, 5.3453035),
(@PATH1, 3, 476.6234, 513.5962, 5.3453035),
(@PATH1, 4, 476.1234, 543.0962, 3.5953035),
(@PATH1, 5, 465.6234, 554.3462, 2.8453035),
(@PATH1, 6, 453.1234, 546.3462, 3.3453035),
(@PATH1, 7, 455.3734, 514.5962, 5.3453035),
(@PATH1, 8, 458.1234, 483.34622, 5.3453035),
(@PATH1, 9, 460.21182, 446.06946, 4.8042874),
-- 
(@PATH2, 1, 460.23074, 445.21594, 4.981337),
(@PATH2, 2, 457.48074, 482.71594, 5.481337),
(@PATH2, 3, 455.48074, 512.96594, 5.231337),
(@PATH2, 4, 453.23074, 544.46594, 3.481337),
(@PATH2, 5, 465.98074, 556.71594, 2.231337),
(@PATH2, 6, 475.73074, 543.96594, 3.481337),
(@PATH2, 7, 476.73074, 513.21594, 5.481337),
(@PATH2, 8, 476.98074, 482.21594, 5.481337),
(@PATH2, 9, 479.75348, 446.0139, 5.0435843),
--
(@PATH3, 1, 455.23175, 513.30900, 5.4119940),
(@PATH3, 2, 454.73175, 481.80902, 5.4119940),
(@PATH3, 3, 456.23175, 456.55902, 4.9119940),
(@PATH3, 4, 466.98175, 445.55902, 5.1619940),
(@PATH3, 5, 481.23175, 454.30902, 5.1619940),
(@PATH3, 6, 475.98175, 481.55902, 5.4119940),
(@PATH3, 7, 475.73175, 513.30900, 5.4119940),
(@PATH3, 8, 475.49652, 546.96704, 2.8322177),
-- 
(@PATH4, 1, 475.39313, 542.08264, 3.4581099),
(@PATH4, 2, 475.14313, 510.33264, 5.45811),
(@PATH4, 3, 477.39313, 477.08264, 5.45811),
(@PATH4, 4, 479.64313, 453.83264, 5.20811),
(@PATH4, 5, 468.14313, 445.08264, 5.20811),
(@PATH4, 6, 455.89313, 454.33264, 4.95811),
(@PATH4, 7, 455.39313, 478.58264, 5.20811),
(@PATH4, 8, 455.14313, 509.33264, 5.45811),
(@PATH4, 9, 455.09723, 543.7743, 3.1613498),
--
(@PATH5, 1, 469.844, 445.488, 5.00465);

UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_guarm' WHERE `entry`=114323;

DELETE FROM `creature_text` WHERE `CreatureID`=114323;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(114323, 0, 0, '|TInterface\\Icons\\SPELL_FIRE_TWILIGHTFLAMEBREATH.BLP:20|t%s begins to cast |cFFFF0000|Hspell:227573|h[Guardian\'s Breath]|h|r!', 41, 0, 100, 0, 0, 0, 124841, 2, 'Guarm to Player'),
(114323, 1, 0, '%s goes into a berserker rage!', 41, 0, 100, 53, 0, 0, 34057, 2, 'Guarm'); -- BroadcastTextID: 4428 - 11694 - 34057

DELETE FROM `spell_script_names` WHERE `spell_id` IN(227512, 227642, 228226, 228250, 228246, 228187, 227673, 227667, 227669, 227660, 227666, 227658, 227894, 227816, 227720, 227721, 227735, 228201, 228824, 228684, 228809, 228817, 228744, 228794, 228810, 228811, 228818, 228819);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(227512, 'spell_multi_headed_proc_guarm'),
(227642, 'spell_multi_headed_damage_guarm'),
(228226, 'spell_lick_selector_guarm'),
(228250, 'spell_lick_selector_guarm'),
(228246, 'spell_lick_selector_guarm'),
(228187, 'spell_guardians_breath_color_selector'),
(227673, 'spell_guardians_breath'),
(227667, 'spell_guardians_breath'),
(227669, 'spell_guardians_breath'),
(227660, 'spell_guardians_breath'),
(227666, 'spell_guardians_breath'),
(227658, 'spell_guardians_breath'),
(227894, 'spell_roaring_leap_selector'),
(227816, 'spell_headlong_charge_trigger'),
(227720, 'spell_mixed_elements_green_blue'),
(227721, 'spell_mixed_elements_red_blue'),
(227735, 'spell_mixed_elements_red_green'),
(228201, 'spell_off_the_leash'),
(228824, 'spell_volatile_foam_initial'),
(228684, 'spell_volatile_foam_selector_red'),
(228809, 'spell_volatile_foam_selector_green'),
(228817, 'spell_volatile_foam_selector_blue'),
(228744, 'spell_volatile_foam_aura_initial_red'),
(228794, 'spell_volatile_foam_aura_red'),
(228810, 'spell_volatile_foam_aura_initial_green'),
(228811, 'spell_volatile_foam_aura_green'),
(228818, 'spell_volatile_foam_aura_initial_blue'),
(228819, 'spell_volatile_foam_aura_blue');

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (3916,3917));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(3916, 55620, 0, 114263, 67230, 0, 0, 50791),
(3917, 55620, 0, 114263, 67230, 0, 0, 50791);

DELETE FROM `conversation_line_template` WHERE `Id` IN (8934, 8935);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(8934, 680, 0, 0, 0, 50791),
(8935, 680, 0, 0, 0, 50791);

DELETE FROM `conversation_template` WHERE `Id` IN (1816, 3821, 3916, 3917, 4114, 4180);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(3916, 8934, 0, 50791),
(3917, 8935, 0, 50791);
