delete from achievement_criteria_data where criteria_id = 15993;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(15993, 11, 0, 0, 'achievement_headed_south');

delete from spell_dbc where id = 93957;
INSERT INTO `spell_dbc` (`Id`, `runeCostID`, `SpellScalingId`, `SpellAuraOptionsId`, `SpellAuraRestrictionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellCooldownsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellReagentsId`, `SpellShapeshiftId`, `SpellTargetRestrictionsId`, `SpellTotemsId`, `ResearchProject`, `SpellMiscId`) VALUES 
(93957, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

delete from spell_area where spell = 93957;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(93957, 0, 0, 0, 0, 0, 2, 0, 64, 11);