delete from spell_script_names where ScriptName = 'spell_item_chocolate_cookie';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(87649, 'spell_item_chocolate_cookie');

delete from spell_dbc where id = 99041;
INSERT INTO `spell_dbc` (`Id`, `runeCostID`, `SpellScalingId`, `SpellAuraOptionsId`, `SpellAuraRestrictionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellCooldownsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellReagentsId`, `SpellShapeshiftId`, `SpellTargetRestrictionsId`, `SpellTotemsId`, `ResearchProject`, `SpellMiscId`) VALUES 
(99041, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);