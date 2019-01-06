DELETE FROM `script_waypoint` WHERE `entry`= 2768;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= -93342;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_zuni_lvl_1_trigger_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93342, 'spell_zuni_lvl_1_trigger_aura');

-- spellclick
DELETE FROM `spell_dbc` WHERE `Id` IN (83580, 89480);
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(83580, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Grilling Primer'),
(89480, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Summon Main Event Vehicle');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (6140, 6141, 6142, 4244);
