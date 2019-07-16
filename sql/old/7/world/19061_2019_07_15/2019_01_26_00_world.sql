-- 
DELETE FROM `spell_target_position` WHERE (`ID`=130702 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(130702, 0, 870, -307.16, -1772.89, 62.32, 28153);

UPDATE `trainer_spell` SET `MoneyCost`=425, `VerifiedBuild`=28153 WHERE (`TrainerId`=580 AND `SpellId`=35907);
UPDATE `trainer_spell` SET `MoneyCost`=850 WHERE (`TrainerId`=580 AND `SpellId`=125610);

DELETE FROM `npc_vendor` WHERE (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4301 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4300 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4299 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4298 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4297 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4296 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4295 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4294 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4293 AND `type`=1) OR (`entry`=63596 AND `item`=98715 AND `ExtendedCost`=4292 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(63596, 10, 98715, 0, 4301, 1, 0, 0, 28153),
(63596, 9, 98715, 0, 4300, 1, 0, 0, 28153), 
(63596, 8, 98715, 0, 4299, 1, 0, 0, 28153), 
(63596, 7, 98715, 0, 4298, 1, 0, 0, 28153), 
(63596, 6, 98715, 0, 4297, 1, 0, 0, 28153), 
(63596, 5, 98715, 0, 4296, 1, 0, 0, 28153), 
(63596, 4, 98715, 0, 4295, 1, 0, 0, 28153), 
(63596, 3, 98715, 0, 4294, 1, 0, 0, 28153), 
(63596, 2, 98715, 0, 4293, 1, 0, 0, 28153), 
(63596, 1, 98715, 0, 4292, 1, 0, 0, 28153); 

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22082 AND `OptionIndex`=0) OR (`MenuId`=22201 AND `OptionIndex`=3) OR (`MenuId`=22081 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(22082, 0, 0, 'What do we know about the void elves?', 0, 28153),
(22201, 3, 0, 'What can you tell me about the Dark Iron dwarves?', 0, 28153),
(22081, 0, 0, 'What can you tell me about the Lightforged draenei?', 0, 28153);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=112694;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(112694, 224326, 1, 0);
