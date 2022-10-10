delete from spell_script_names where spell_id in (116550);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(116550, 'spell_eperor_energizing_smash');

delete from spell_dbc where id = 113314;
INSERT INTO `spell_dbc` (`Id`, `runeCostID`, `SpellScalingId`, `SpellAuraOptionsId`, `SpellAuraRestrictionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellCooldownsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellReagentsId`, `SpellShapeshiftId`, `SpellTargetRestrictionsId`, `SpellTotemsId`, `ResearchProject`, `SpellMiscId`) VALUES 
(113314, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

delete from spell_target_filter where spellId in (116819,117194,116829);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(116819, 15, 2, -1, 17, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Eperor - Magnetic Pull'),
(117194, 15, 2, -1, 17, 0, 0, 0, 1, 0, 0, 0, 0, 0, 'Eperor - Magnetic Pull'),
(116829, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Emperor - Focused Energy');

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (116805,127758);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 116805, 0, 0, 31, 0, 3, 60396, 0, 0, 0, '', NULL),
(13, 2, 116805, 0, 1, 31, 0, 3, 60397, 0, 0, 0, '', NULL),
(13, 2, 116805, 0, 2, 31, 0, 3, 60398, 0, 0, 0, '', NULL),
(13, 2, 116805, 0, 3, 31, 0, 3, 60399, 0, 0, 0, '', NULL),
(13, 2, 116805, 0, 4, 31, 0, 3, 60400, 0, 0, 0, '', NULL),
(13, 1, 127758, 0, 0, 31, 0, 3, 60396, 0, 0, 0, '', NULL),
(13, 1, 127758, 0, 1, 31, 0, 3, 60397, 0, 0, 0, '', NULL),
(13, 1, 127758, 0, 2, 31, 0, 3, 60398, 0, 0, 0, '', NULL),
(13, 1, 127758, 0, 3, 31, 0, 3, 60399, 0, 0, 0, '', NULL),
(13, 1, 127758, 0, 4, 31, 0, 3, 60400, 0, 0, 0, '', NULL);

update creature_template set ScriptName = 'npc_emperor_terracotta_boss', flags_extra = 128 where entry in (67221, 60575);
update creature_template set MinLevel = 92, MaxLevel = 92, faction = 16, npcflag = 0, speed_run = 0.7, speed_walk = 1, speed_fly = 0.5, `unit_flags2`=2099200, InhabitType = 7, ScriptName = 'npc_emperor_titan_spark' where entry = 60480;

delete from creature_equip_template where entry in (60399,60400);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(60399, 80939, 0, 0),
(60400, 80289, 0, 0);

delete from npc_spellclick_spells where npc_entry in (60399,60400);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(60399, 46598, 1, 0),
(60400, 46598, 1, 0);

delete from vehicle_template_accessory where entryOrAura in (60399,60400);
INSERT INTO `vehicle_template_accessory` (`entryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(60399, 67221, 0, 1, '60399 - 67221', 8, 0),
(60399, 67221, 1, 1, '60399 - 67221', 8, 0),
(60399, 67221, 2, 1, '60399 - 67221', 8, 0),
(60400, 60575, 0, 1, '60400 - 60575', 8, 0),
(60400, 60575, 1, 1, '60400 - 60575', 8, 0),
(60400, 60575, 2, 1, '60400 - 60575', 8, 0);

delete from creature_model_info where modelid in (41391,41392);
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`, `hostileId`) VALUES 
(41391, 2.1, 8.75, 2, 0, 0),
(41392, 2.1, 8.75, 2, 0, 0);