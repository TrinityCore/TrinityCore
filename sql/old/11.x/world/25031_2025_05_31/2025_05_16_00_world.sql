-- Creature templates
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (66677, 66676, 66674); -- Gunship Turret

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (66674, 66676, 66677);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(66674, 130996, 3, 0),
(66676, 130997, 3, 0),
(66677, 130998, 3, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (66674, 66676, 66677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 66674, 130996, 0, 0, 47, 0, 31765, 8, 0, 0, 0, 0, '', 'Allow spellclick if quest 31765 is taken'),
(18, 66676, 130997, 0, 0, 47, 0, 31765, 8, 0, 0, 0, 0, '', 'Allow spellclick if quest 31765 is taken'),
(18, 66677, 130998, 0, 0, 47, 0, 31765, 8, 0, 0, 0, 0, '', 'Allow spellclick if quest 31765 is taken');

-- Vehicle data
DELETE FROM `vehicle_template` WHERE `creatureId`=66183;
INSERT INTO `vehicle_template` (`creatureId`, `despawnDelayMs`, `Pitch`) VALUES
(66183, 0, -0.34906584024429321);

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry`=11876;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(11876, 0, -2, 0, 0, 0, 1);

DELETE FROM `creature_template_spell` WHERE `CreatureID`=66183;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(66183, 0, 130163, 58911), -- Gunship Turret
(66183, 1, 130162, 58911); -- Gunship Turret

-- Quests
DELETE FROM `quest_template_addon` WHERE `ID`=31765;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(31765, 0, 0, 0, 29690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE `quest_poi` SET `VerifiedBuild`=58911 WHERE (`QuestID`=31765 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=31765 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=58911 WHERE (`QuestID`=31765 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=31765 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=58911 WHERE `ID`=31765;

DELETE FROM `quest_request_items` WHERE `ID`=31765;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(31765, 0, 5, 0, 0, 'What are you waiting for?! Get on those guns!', 58911); -- Paint it Red!

DELETE FROM `quest_offer_reward` WHERE `ID`=31765;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(31765, 0, 0, 0, 0, 0, 0, 0, 0, 'Superior Horde firepower at its finest!$B$B...and you did okay too I guess.', 60257); -- Paint it Red!

UPDATE `creature_queststarter` SET `VerifiedBuild`=58911 WHERE (`id`=55135 AND `quest`=31765);

UPDATE `creature_questender` SET `VerifiedBuild`=58911 WHERE (`id`=66667 AND `quest`=31765);

-- Spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (130996, 130997, 130998, 130162, 130237, 130248);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 130996, 0, 0, 31, 0, 3, 66674, 0, 0, 0, 0, '', 'Spell "Summon Gunship Turret, Left" targets Gunship Turret'),
(13, 1, 130997, 0, 0, 31, 0, 3, 66676, 0, 0, 0, 0, '', 'Spell "Summon Gunship Turret, Middle" targets Gunship Turret'),
(13, 1, 130998, 0, 0, 31, 0, 3, 66677, 0, 0, 0, 0, '', 'Spell "Summon Gunship Turret, Right" targets Gunship Turret'),
(13, 1, 130162, 0, 0, 31, 0, 3, 66200, 0, 0, 0, 0, '', 'Spell "Shredder Round" targets Thunder Hold Soldier'),
(13, 1, 130162, 0, 1, 31, 0, 3, 66202, 0, 0, 0, 0, '', 'Spell "Shredder Round" targets Thunder Hold Laborer'),
(13, 1, 130162, 0, 2, 31, 0, 3, 66203, 0, 0, 0, 0, '', 'Spell "Shredder Round" targets Thunder Hold Cannon'),
(13, 1, 130162, 0, 3, 31, 0, 3, 66210, 0, 0, 0, 0, '', 'Spell "Shredder Round" targets Thunder Hold Explosive Barrel'),
(13, 1, 130162, 0, 4, 31, 0, 3, 66291, 0, 0, 0, 0, '', 'Spell "Shredder Round" targets Thunder Hold Soldier'),
(13, 3, 130237, 0, 0, 31, 0, 3, 66200, 0, 0, 0, 0, '', 'Spell "Cannon Explosion" targets Thunder Hold Soldier'),
(13, 3, 130237, 0, 1, 31, 0, 3, 66202, 0, 0, 0, 0, '', 'Spell "Cannon Explosion" targets Thunder Hold Laborer'),
(13, 3, 130237, 0, 2, 31, 0, 3, 66203, 0, 0, 0, 0, '', 'Spell "Cannon Explosion" targets Thunder Hold Cannon'),
(13, 3, 130237, 0, 3, 31, 0, 3, 66210, 0, 0, 0, 0, '', 'Spell "Cannon Explosion" targets Thunder Hold Explosive Barrel'),
(13, 3, 130237, 0, 4, 31, 0, 3, 66291, 0, 0, 0, 0, '', 'Spell "Cannon Explosion" targets Thunder Hold Soldier'),
(13, 1, 130248, 0, 0, 31, 0, 3, 66200, 0, 0, 0, 0, '', 'Spell "Barrel Explosion" targets Thunder Hold Soldier'),
(13, 1, 130248, 0, 1, 31, 0, 3, 66202, 0, 0, 0, 0, '', 'Spell "Barrel Explosion" targets Thunder Hold Laborer'),
(13, 1, 130248, 0, 2, 31, 0, 3, 66203, 0, 0, 0, 0, '', 'Spell "Barrel Explosion" targets Thunder Hold Cannon'),
(13, 1, 130248, 0, 3, 31, 0, 3, 66210, 0, 0, 0, 0, '', 'Spell "Barrel Explosion" targets Thunder Hold Explosive Barrel'),
(13, 1, 130248, 0, 4, 31, 0, 3, 66291, 0, 0, 0, 0, '', 'Spell "Barrel Explosion" targets Thunder Hold Soldier');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (85299, 92678, 130233, 130246, 130996, 130997, 130998);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85299, 'spell_gen_reverse_cast_target_to_caster_triggered'),
(92678, 'spell_gen_abandon_vehicle'),
(130233, 'spell_cannon_explosion_reversecast'),
(130246, 'spell_barrel_explosion_reversecast'),
(130996, 'spell_summon_gunship_turret'),
(130997, 'spell_summon_gunship_turret'),
(130998, 'spell_summon_gunship_turret');

DELETE FROM `serverside_spell` WHERE `Id`=131848;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `AttributesEx15`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(131848,0,0,0,0,0x29800100,0x10000020,0x4005,0x10100000,0x80,0x60008,0x21600,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,13,0,0,0,-1,0,0,0,'See Quest Invis 1',0,0,0,0,0,0,0,0,0,0,0,0,1,0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID`=131848;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(131848,0,0,6,19,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1000,7,0,0,0,0,0,0,0,1,0);

DELETE FROM `spell_custom_attr` WHERE `entry` IN (130233, 130246);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(130233, 0x02000000),
(130246, 0x02000000);

-- Terrain swap
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=25 AND `SourceEntry`=1074;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25,0,1074,0,0,6,0,67,0,0,'',0,0,0,'','Apply terrain swap 1074 if player is Horde'),
(25,0,1074,0,0,47,0,29690,64,0,'',1,0,0,'','Apply terrain swap 1074 if quest 29690 is not rewarded'),
(25,0,1074,0,0,-40002,0,0,0,0,'',0,0,0,'','Apply terrain swap 1074 if condition reference 40002 is fulfilled');

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=66183;

DELETE FROM `event_script_names` WHERE `Id`=34051;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(34051, 'SmartEventTrigger');

UPDATE `quest_template_addon` SET `ScriptName`='SmartQuest' WHERE `ID`=31765;

DELETE FROM `smart_scripts` WHERE `entryorguid`=34051 AND `source_type`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34051,3,0,1,'',87,0,100,0,0,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Game event 34051 - On trigger - Store invoker in target list 1'),
(34051,3,1,2,'',61,0,100,0,0,0,0,0,0,'',100,1,0,0,0,0,0,0,NULL,19,55135,100,0,0,NULL,0,0,0,0,'Game event 34051 - Event linked - Send stored target 1 to General Nazgrim'),
(34051,3,2,0,'',61,0,100,0,0,0,0,0,0,'',45,1,1,0,0,0,0,0,NULL,19,55135,100,0,0,NULL,0,0,0,0,'Game event 34051 - Event linked - Set data 1 1 on General Nazgrim');

DELETE FROM `smart_scripts` WHERE `entryorguid`=31765 AND `source_type`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(31765,5,0,1,'',48,0,100,0,269073,0,0,0,0,'',64,2,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Quest 31765 - On objective 269073 completed - Store invoker in target list 2'),
(31765,5,1,2,'',61,0,100,0,0,0,0,0,0,'',100,2,0,0,0,0,0,0,NULL,19,55135,100,0,0,NULL,0,0,0,0,'Quest 31765 - Event linked - Send stored target 2 to General Nazgrim'),
(31765,5,2,0,'',61,0,100,0,0,0,0,0,0,'',45,2,1,0,0,0,0,0,NULL,19,55135,100,0,0,NULL,0,0,0,0,'Quest 31765 - Event linked - Set data 2 1 on General Nazgrim');

DELETE FROM `smart_scripts` WHERE `entryorguid`=55135 AND `source_type`=0 AND `id` IN (1, 2);	
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55135,0,1,0,'',38,0,100,0,1,1,0,0,0,'',1,0,0,1,0,0,0,0,NULL,12,1,0,0,0,NULL,0,0,0,0,'General Nazgrim - On data set 1 1 - Talk to stored target'),
(55135,0,2,0,'',38,0,100,0,2,1,0,0,0,'',1,1,0,1,0,0,0,0,NULL,12,2,0,0,0,NULL,0,0,0,0,'General Nazgrim - On data set 2 1 - Talk to stored target');

DELETE FROM `creature_text` WHERE `CreatureID`=55135 AND `GroupID` IN (0, 1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(55135, 0, 0, 'Aim true! Send them limping back to Stormwind!', 12, 0, 100, 0, 0, 32520, 68804, 5, 'General Nazgrim'),
(55135, 1, 0, 'Haha! That''s right. Show them Hellscream''s fury!', 12, 0, 100, 0, 0, 32516, 68800, 5, 'General Nazgrim');

SET @ACTIONLIST := 66183 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66183 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ACTIONLIST;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66183,0,0,0,'',54,0,100,0x200,0,0,0,0,0,'',11,85299,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Gunship Turret - On summon - Cast ''Reverse Cast Ride Seat 1'' to invoker'),
(66183,0,1,0,'',28,0,100,0x200,0,0,0,0,0,'',80,@ACTIONLIST,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Gunship Turret - On passenger removed - Call timed actionlist'),
(@ACTIONLIST,9,0,0,'',0,0,100,0x200,0,0,0,0,0,'',28,130996,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Turret - Remove aura ''Summon Gunship Turret, Left'' from invoker'),
(@ACTIONLIST,9,1,0,'',0,0,100,0x200,0,0,0,0,0,'',28,130997,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Turret - Remove aura ''Summon Gunship Turret, Middle'' from invoker'),
(@ACTIONLIST,9,2,0,'',0,0,100,0x200,0,0,0,0,0,'',28,130998,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Turret - Remove aura ''Summon Gunship Turret, Right'' from invoker'),
(@ACTIONLIST,9,3,0,'',0,0,100,0x200,0,0,0,0,0,'',11,93862,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Turret - Cast ''Update Zone Auras and Phase Shift'' to invoker'),
(@ACTIONLIST,9,4,0,'',0,0,100,0x200,0,0,0,0,0,'',41,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Gunship Turret - Despawn');

DELETE FROM `smart_scripts` WHERE `entryorguid`=66200 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66200,0,0,0,'',11,0,100,0,0,0,0,0,0,'',116,15,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Set corpse delay'),
(66200,0,1,0,'',1,0,100,0,0,6200,4800,6200,0,'',11,130266,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - Out of combat (4.8s-6.2s) - Cast ''Shoot'''),
(66200,0,2,0,'',8,0,100,0x1,130248,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On spell hit - Disable health regen'),
(66200,0,3,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Set active (TEMP)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=66200;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,66200,0,0,58,1,0,0,0,'Shooter',0,0,0,'','Trigger smart event if object has StringId ''Shooter''');

DELETE FROM `smart_scripts` WHERE `entryorguid`=66202 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66202,0,0,0,'',11,0,100,0,0,0,0,0,0,'',116,15,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Laborer - On respawn - Set corpse delay'),
(66202,0,1,0,'',1,0,100,0,0,3600,2400,3600,0,'',5,36,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Laborer - Out of combat (2.4s-3.6s) - Play emote'),
(66202,0,2,0,'',8,0,100,0x1,130248,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Laborer - On spell hit - Disable health regen'),
(66202,0,3,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Laborer - On respawn - Set active (TEMP)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=66202;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,66202,0,0,58,1,0,0,0,'AttackBarrel',0,0,0,'','Trigger smart event if object has StringId ''AttackBarrel''');

SET @ACTIONLIST := 66203 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66203 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ACTIONLIST;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66203,0,0,1,'',11,0,100,0,0,0,0,0,0,'',8,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On respawn - Set react state passive'),
(66203,0,1,2,'',61,0,100,0,0,0,0,0,0,'',42,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - Event linked - Set invincibility'),
(66203,0,2,0,'',61,0,100,0,0,0,0,0,0,'',116,15,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - Event linked - Set corpse delay'),
(66203,0,3,0,'',8,0,100,0x1,130162,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,4,0,'',8,0,100,0x1,130237,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,5,6,'',8,0,100,0x1,130248,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On spell hit - Store invoker in target list'),
(66203,0,6,0,'',61,0,100,0,0,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - Event linked - Disable health regen'),
(66203,0,7,0,'',2,0,100,0x1,0,10,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On health pct (0-10%) - Call timed actionlist (Not repeatable)'),
(66203,0,8,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Cannon - On respawn - Set active (TEMP)'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',42,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Cannon - Remove invincibility'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,0,0,0,0,0,'',11,130233,0,0,0,0,0,0,NULL,12,1,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Cannon - Cast ''Cannon Explosion Reversecast'' to stored target');

SET @ACTIONLIST := 66210 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66210 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ACTIONLIST;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66210,0,0,1,'',11,0,100,0,0,0,0,0,0,'',8,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On respawn - Set react state passive'),
(66210,0,1,0,'',61,0,100,0,0,0,0,0,0,'',42,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - Event linked - Set invincibility'),
(66210,0,2,0,'',8,0,100,0x1,130162,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,3,0,'',8,0,100,0x1,130237,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,4,5,'',8,0,100,0x1,130248,0,0,0,0,'',64,1,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On spell hit - Store invoker in target list'),
(66210,0,5,0,'',61,0,100,0,0,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - Event linked - Disable health regen'),
(66210,0,6,0,'',2,0,100,0x1,0,10,0,0,0,'',80,@ACTIONLIST+0,2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On health pct (0-10%) - Call timed actionlist (Not repeatable)'),
(66210,0,7,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Explosive Barrel - On respawn - Set active (TEMP)'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',11,130246,0,0,0,0,0,0,NULL,12,1,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Explosive Barrel - Cast ''Barrel Explosion Reversecast'' to stored target'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,0,0,0,0,0,'',3,0,11686,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Explosive Barrel - Change display id'),
(@ACTIONLIST+0,9,2,0,'',0,0,100,0,4800,4800,0,0,0,'',41,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Explosive Barrel - Despawn');

SET @ENTRY := 66291;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
SET @ACTIONLIST := 66291 * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=66291 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ACTIONLIST;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(66291,0,0,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 1'),
(66291,0,1,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+1,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 2'),
(66291,0,2,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+2,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 3'),
(66291,0,3,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+3,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 4'),
(66291,0,4,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+4,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 5'),
(66291,0,5,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+5,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 6'),
(66291,0,6,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+6,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 7'),
(66291,0,7,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+7,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 8'),
(66291,0,8,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+8,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 9'),
(66291,0,9,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+9,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 10'),
(66291,0,10,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+10,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 11'),
(66291,0,11,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+11,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 12'),
(66291,0,12,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+12,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 13'),
(66291,0,13,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+13,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 14'),
(66291,0,14,0,'',11,0,100,0,0,0,0,0,0,'',53,0,@PATH+14,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Start scripted path 15'),
(66291,0,15,0,'',11,0,100,0,0,0,0,0,0,'',116,15,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Set corpse delay'),
(66291,0,16,17,'',58,0,100,0,0xFFFFFFFF,0,0,0,0,'',101,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On scripted path ended - Set home position'),
(66291,0,17,0,'',61,0,100,0,0,0,0,0,0,'',22,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - Event linked - Set event phase 1'),
(66291,0,18,0,'',1,0x1,100,0,0,0,6000,6500,0,'',80,@ACTIONLIST+0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - Out of combat (6-6.5s) - Call timed actionlist (Event phase 1)'),
(66291,0,19,0,'',8,0,100,0x1,130248,0,0,0,0,'',102,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On spell hit - Disable health regen'),
(66291,0,20,0,'',11,0,100,0,0,0,0,0,0,'',48,1,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Thunder Hold Soldier - On respawn - Set active (TEMP)'),
(@ACTIONLIST+0,9,0,0,'',0,0,100,0,0,0,0,0,0,'',66,0,0,0,0,0,0,0,NULL,19,66203,5,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Face closest Thunder Hold Cannon'),
(@ACTIONLIST+0,9,1,0,'',0,0,100,0,0,0,0,0,0,'',11,130265,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Cast ''Cannon Blast'''),
(@ACTIONLIST+0,9,2,0,'',0,0,100,0,0,0,0,0,0,'',17,0,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Remove emote state'),
(@ACTIONLIST+0,9,3,0,'',0,0,100,0,1200,1200,0,0,0,'',17,27,0,0,0,0,0,0,NULL,1,0,0,0,0,NULL,0,0,0,0,'Actionlist - Thunder Hold Soldier - Set emote state');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=66291;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,66291,0,0,58,1,0,0,0,'CannoneerPath1',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath1'''),
(22,2,66291,0,0,58,1,0,0,0,'CannoneerPath2',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath2'''),
(22,3,66291,0,0,58,1,0,0,0,'CannoneerPath3',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath3'''),
(22,4,66291,0,0,58,1,0,0,0,'CannoneerPath4',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath4'''),
(22,5,66291,0,0,58,1,0,0,0,'CannoneerPath5',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath5'''),
(22,6,66291,0,0,58,1,0,0,0,'CannoneerPath6',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath6'''),
(22,7,66291,0,0,58,1,0,0,0,'CannoneerPath7',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath7'''),
(22,8,66291,0,0,58,1,0,0,0,'CannoneerPath8',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath8'''),
(22,9,66291,0,0,58,1,0,0,0,'CannoneerPath9',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath9'''),
(22,10,66291,0,0,58,1,0,0,0,'CannoneerPath10',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath10'''),
(22,11,66291,0,0,58,1,0,0,0,'CannoneerPath11',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath11'''),
(22,12,66291,0,0,58,1,0,0,0,'CannoneerPath12',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath12'''),
(22,13,66291,0,0,58,1,0,0,0,'CannoneerPath13',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath13'''),
(22,14,66291,0,0,58,1,0,0,0,'CannoneerPath14',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath14'''),
(22,15,66291,0,0,58,1,0,0,0,'CannoneerPath15',0,0,0,'','Trigger smart event if object has StringId ''CannoneerPath15'''),
(22,19,66291,0,0,29,1,66203,5,0,'',0,0,0,'','Trigger smart event if object near Thunder Hold Cannon');

-- Spawn groups
SET @CGUID := 4000454;

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+297;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(2,0,@CGUID+0),
(2,0,@CGUID+1),
(2,0,@CGUID+2),
(2,0,@CGUID+3),
(2,0,@CGUID+4),
(2,0,@CGUID+5),
(2,0,@CGUID+6),
(2,0,@CGUID+7),
(2,0,@CGUID+8),
(2,0,@CGUID+9),
(2,0,@CGUID+10),
(2,0,@CGUID+11),
(2,0,@CGUID+12),
(2,0,@CGUID+13),
(2,0,@CGUID+14),
(2,0,@CGUID+15),
(2,0,@CGUID+16),
(2,0,@CGUID+17),
(2,0,@CGUID+18),
(2,0,@CGUID+19),
(2,0,@CGUID+20),
(2,0,@CGUID+21),
(2,0,@CGUID+22),
(2,0,@CGUID+23),
(2,0,@CGUID+24),
(2,0,@CGUID+25),
(2,0,@CGUID+26),
(2,0,@CGUID+27),
(2,0,@CGUID+28),
(2,0,@CGUID+29),
(2,0,@CGUID+30),
(2,0,@CGUID+31),
(2,0,@CGUID+32),
(2,0,@CGUID+33),
(2,0,@CGUID+34),
(2,0,@CGUID+35),
(2,0,@CGUID+36),
(2,0,@CGUID+37),
(2,0,@CGUID+38),
(2,0,@CGUID+39),
(2,0,@CGUID+40),
(2,0,@CGUID+41),
(2,0,@CGUID+42),
(2,0,@CGUID+43),
(2,0,@CGUID+44),
(2,0,@CGUID+45),
(2,0,@CGUID+46),
(2,0,@CGUID+47),
(2,0,@CGUID+48),
(2,0,@CGUID+49),
(2,0,@CGUID+50),
(2,0,@CGUID+51),
(2,0,@CGUID+52),
(2,0,@CGUID+53),
(2,0,@CGUID+54),
(2,0,@CGUID+55),
(2,0,@CGUID+56),
(2,0,@CGUID+57),
(2,0,@CGUID+58),
(2,0,@CGUID+59),
(2,0,@CGUID+60),
(2,0,@CGUID+61),
(2,0,@CGUID+62),
(2,0,@CGUID+63),
(2,0,@CGUID+64),
(2,0,@CGUID+65),
(2,0,@CGUID+66),
(2,0,@CGUID+67),
(2,0,@CGUID+68),
(2,0,@CGUID+69),
(2,0,@CGUID+70),
(2,0,@CGUID+71),
(2,0,@CGUID+72),
(2,0,@CGUID+73),
(2,0,@CGUID+74),
(2,0,@CGUID+75),
(2,0,@CGUID+76),
(2,0,@CGUID+77),
(2,0,@CGUID+78),
(2,0,@CGUID+79),
(2,0,@CGUID+80),
(2,0,@CGUID+81),
(2,0,@CGUID+82),
(2,0,@CGUID+83),
(2,0,@CGUID+84),
(2,0,@CGUID+85),
(2,0,@CGUID+86),
(2,0,@CGUID+87),
(2,0,@CGUID+88),
(2,0,@CGUID+89),
(2,0,@CGUID+90),
(2,0,@CGUID+91),
(2,0,@CGUID+92),
(2,0,@CGUID+93),
(2,0,@CGUID+94),
(2,0,@CGUID+95),
(2,0,@CGUID+96),
(2,0,@CGUID+97),
(2,0,@CGUID+98),
(2,0,@CGUID+99),
(2,0,@CGUID+100),
(2,0,@CGUID+101),
(2,0,@CGUID+102),
(2,0,@CGUID+103),
(2,0,@CGUID+104),
(2,0,@CGUID+105),
(2,0,@CGUID+106),
(2,0,@CGUID+107),
(2,0,@CGUID+108),
(2,0,@CGUID+109),
(2,0,@CGUID+110),
(2,0,@CGUID+111),
(2,0,@CGUID+112),
(2,0,@CGUID+113),
(2,0,@CGUID+114),
(2,0,@CGUID+115),
(2,0,@CGUID+116),
(2,0,@CGUID+117),
(2,0,@CGUID+118),
(2,0,@CGUID+119),
(2,0,@CGUID+120),
(2,0,@CGUID+121),
(2,0,@CGUID+122),
(2,0,@CGUID+123),
(2,0,@CGUID+124),
(2,0,@CGUID+125),
(2,0,@CGUID+126),
(2,0,@CGUID+127),
(2,0,@CGUID+128),
(2,0,@CGUID+129),
(2,0,@CGUID+130),
(2,0,@CGUID+131),
(2,0,@CGUID+132),
(2,0,@CGUID+133),
(2,0,@CGUID+134),
(2,0,@CGUID+135),
(2,0,@CGUID+136),
(2,0,@CGUID+137),
(2,0,@CGUID+138),
(2,0,@CGUID+139),
(2,0,@CGUID+140),
(2,0,@CGUID+141),
(2,0,@CGUID+142),
(2,0,@CGUID+143),
(2,0,@CGUID+144),
(2,0,@CGUID+145),
(2,0,@CGUID+146),
(2,0,@CGUID+147),
(2,0,@CGUID+148),
(2,0,@CGUID+149),
(2,0,@CGUID+150),
(2,0,@CGUID+151),
(2,0,@CGUID+152),
(2,0,@CGUID+153),
(2,0,@CGUID+154),
(2,0,@CGUID+155),
(2,0,@CGUID+156),
(2,0,@CGUID+157),
(2,0,@CGUID+158),
(2,0,@CGUID+159),
(2,0,@CGUID+160),
(2,0,@CGUID+161),
(2,0,@CGUID+162),
(2,0,@CGUID+163),
(2,0,@CGUID+164),
(2,0,@CGUID+165),
(2,0,@CGUID+166),
(2,0,@CGUID+167),
(2,0,@CGUID+168),
(2,0,@CGUID+169),
(2,0,@CGUID+170),
(2,0,@CGUID+171),
(2,0,@CGUID+172),
(2,0,@CGUID+173),
(2,0,@CGUID+174),
(2,0,@CGUID+175),
(2,0,@CGUID+176),
(2,0,@CGUID+177),
(2,0,@CGUID+178),
(2,0,@CGUID+179),
(2,0,@CGUID+180),
(2,0,@CGUID+181),
(2,0,@CGUID+182),
(2,0,@CGUID+183),
(2,0,@CGUID+184),
(2,0,@CGUID+185),
(2,0,@CGUID+186),
(2,0,@CGUID+187),
(2,0,@CGUID+188),
(2,0,@CGUID+189),
(2,0,@CGUID+190),
(2,0,@CGUID+191),
(2,0,@CGUID+192),
(2,0,@CGUID+193),
(2,0,@CGUID+194),
(2,0,@CGUID+195),
(2,0,@CGUID+196),
(2,0,@CGUID+197),
(2,0,@CGUID+198),
(2,0,@CGUID+199),
(2,0,@CGUID+200),
(2,0,@CGUID+201),
(2,0,@CGUID+202),
(2,0,@CGUID+203),
(2,0,@CGUID+204),
(2,0,@CGUID+205),
(2,0,@CGUID+206),
(2,0,@CGUID+207),
(2,0,@CGUID+208),
(2,0,@CGUID+209),
(2,0,@CGUID+210),
(2,0,@CGUID+211),
(2,0,@CGUID+212),
(2,0,@CGUID+213),
(2,0,@CGUID+214),
(2,0,@CGUID+215),
(2,0,@CGUID+216),
(2,0,@CGUID+217),
(2,0,@CGUID+218),
(2,0,@CGUID+219),
(2,0,@CGUID+220),
(2,0,@CGUID+221),
(2,0,@CGUID+222),
(2,0,@CGUID+223),
(2,0,@CGUID+224),
(2,0,@CGUID+225),
(2,0,@CGUID+226),
(2,0,@CGUID+227),
(2,0,@CGUID+228),
(2,0,@CGUID+229),
(2,0,@CGUID+230),
(2,0,@CGUID+231),
(2,0,@CGUID+232),
(2,0,@CGUID+233),
(2,0,@CGUID+234),
(2,0,@CGUID+235),
(2,0,@CGUID+236),
(2,0,@CGUID+237),
(2,0,@CGUID+238),
(2,0,@CGUID+239),
(2,0,@CGUID+240),
(2,0,@CGUID+241),
(2,0,@CGUID+242),
(2,0,@CGUID+243),
(2,0,@CGUID+244),
(2,0,@CGUID+245),
(2,0,@CGUID+246),
(2,0,@CGUID+247),
(2,0,@CGUID+248),
(2,0,@CGUID+249),
(2,0,@CGUID+250),
(2,0,@CGUID+251),
(2,0,@CGUID+252),
(2,0,@CGUID+253),
(2,0,@CGUID+254),
(2,0,@CGUID+255),
(2,0,@CGUID+256),
(2,0,@CGUID+257),
(2,0,@CGUID+258),
(2,0,@CGUID+259),
(2,0,@CGUID+260),
(2,0,@CGUID+261),
(2,0,@CGUID+262),
(2,0,@CGUID+263),
(2,0,@CGUID+264),
(2,0,@CGUID+265),
(2,0,@CGUID+266),
(2,0,@CGUID+267),
(2,0,@CGUID+268),
(2,0,@CGUID+269),
(2,0,@CGUID+270),
(2,0,@CGUID+271),
(2,0,@CGUID+272),
(2,0,@CGUID+273),
(2,0,@CGUID+274),
(2,0,@CGUID+275),
(2,0,@CGUID+276),
(2,0,@CGUID+277),
(2,0,@CGUID+278),
(2,0,@CGUID+279),
(2,0,@CGUID+280),
(2,0,@CGUID+281),
(2,0,@CGUID+282),
(2,0,@CGUID+283),
(2,0,@CGUID+284),
(2,0,@CGUID+285),
(2,0,@CGUID+286),
(2,0,@CGUID+287),
(2,0,@CGUID+288),
(2,0,@CGUID+289),
(2,0,@CGUID+290),
(2,0,@CGUID+291),
(2,0,@CGUID+292),
(2,0,@CGUID+293),
(2,0,@CGUID+294),
(2,0,@CGUID+295),
(2,0,@CGUID+296),
(2,0,@CGUID+297);
