-- 
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=44428 WHERE  `entryorguid`=24788 AND `source_type`=0 AND `id`=3 AND `link`=4;
DELETE FROM `serverside_spell_effect` WHERE `SpellID`=44428;
INSERT INTO `serverside_spell_effect` (`SpellID`, `Effect`, `EffectItemType`, `ImplicitTarget1`) VALUES
(44428, 24, 34116, 0);
