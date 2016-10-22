--
DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_brewfest_relay_race_turn_in";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43755, "spell_brewfest_relay_race_turn_in");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-43880;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-43880, -43332, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Exhausted'"), 
(-43880, -43310, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Ram Level - Neutral'"), 
(-43880, -43052, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Ram Fatigue'"), 
(-43880, -42994, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Ram - Gallop'"), 
(-43880, -42993, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Ram - Canter'"), 
(-43880, -42992, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Ram - Trot'"), 
(-43880, -42146, 0, "On removal of aura 'Ramsteins Swift Work Ram' also remove aura 'Brewfest Racing Ram Aura [DND]'");

DELETE FROM `gossip_menu_option` WHERE `id`=4 AND `menu_id` IN (8934, 8976);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8934, 4, 0, "I want to race for tokens!", 0, 1, 1, 0, 0, 0, 0, "", 0, -1),
(8976, 4, 0, "I want to race for tokens!", 0, 1, 1, 0, 0, 0, 0, "", 0, -1);

UPDATE `smart_scripts` SET `link`=2 WHERE `id`=1 AND `entryorguid` IN (24468, 24510);
DELETE FROM `smart_scripts` WHERE `id`=2 AND `entryorguid` IN (24468, 24510);
DELETE FROM `smart_scripts` WHERE `entryorguid`=23558 AND `id` IN (6, 7, 8, 9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24497 AND `id` IN (8, 9, 10, 11);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24468, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 43755, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Pol Amberstill <Ram Racing Apprentice> - Within 0-25 Range - Cast 'Brewfest - Daily - Relay Race - Player - Increase Mount Duration - DND'"),
(24510, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 43755, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Driz Tumblequick <Ram Racing Apprentice> - Within 0-25 Range - Cast 'Brewfest - Daily - Relay Race - Player - Increase Mount Duration - DND'"),
(23558, 0, 6, 7, 62, 0, 100, 0, 8934, 4, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Neill Ramstein <Ram Racing Master> - On Gossip Option 4 Selected - Close Gossip"),
(23558, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 85, 43880, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Neill Ramstein <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Ramstein's Swift Work Ram'"),
(23558, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 85, 44689, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Neill Ramstein <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Relay Race Accept Hidden Debuff - DND'"),
(23558, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 44262, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Neill Ramstein <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Brewfest - Create Ram Racing Crop'"),
(24497, 0, 8, 9, 62, 0, 100, 0, 8976, 4, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Ram Master Ray <Ram Racing Master> - On Gossip Option 4 Selected - Close Gossip"),
(24497, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 85, 43880, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Ram Master Ray <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Ramstein's Swift Work Ram'"),
(24497, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 85, 44689, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Ram Master Ray <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Relay Race Accept Hidden Debuff - DND'"),
(24497, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 44262, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Ram Master Ray <Ram Racing Master> - On Gossip Option 4 Selected - Cast Spell 'Brewfest - Create Ram Racing Crop'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8934, 8976) AND `SourceEntry`=4;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8934, 4, 0, 0, 8, 0, 11122, 0, 0, 0, 0, 0, "", "Brewfest Relay Race - Show gossip if player has turned in the quest 'There and Back Again'"),
(15, 8934, 4, 0, 0, 1, 0, 44689, 0, 0, 1, 0, 0, "", "Brewfest Relay Race - Show gossip if player does not have aura 'Relay Race Accept Hidden Debuff - DND'"),
(15, 8934, 4, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, "", "Brewfest Relay Race - Show gossip if player does not have aura 'Rental Racing Ram'"),
(15, 8976, 4, 0, 0, 8, 0, 11412, 0, 0, 0, 0, 0, "", "Brewfest Relay Race - Show gossip if player has turned in the quest 'There and Back Again'"),
(15, 8976, 4, 0, 0, 1, 0, 44689, 0, 0, 1, 0, 0, "", "Brewfest Relay Race - Show gossip if player does not have aura 'Relay Race Accept Hidden Debuff - DND'"),
(15, 8976, 4, 0, 0, 1, 0, 43883, 0, 0, 1, 0, 0, "", "Brewfest Relay Race - Show gossip if player does not have aura 'Rental Racing Ram'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (24468, 24510, 24364, 24527) AND `ElseGroup`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (24468, 24510) AND `SourceGroup`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 24468, 0, 1, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramsteins Swift Work Ram'"), 
(22, 1, 24468, 0, 1, 2, 0, 33797, 1, 0, 0, 0, 0, "", "SAI triggers only if player has item 'Portable Brewfest Keg'"), 
(22, 1, 24510, 0, 1, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramsteins Swift Work Ram'"), 
(22, 1, 24510, 0, 1, 2, 0, 33797, 1, 0, 0, 0, 0, "", "SAI triggers only if player has item 'Portable Brewfest Keg'"), 
(22, 1, 24364, 0, 1, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramsteins Swift Work Ram'"), 
(22, 1, 24364, 0, 1, 2, 0, 33797, 1, 0, 1, 0, 0, "", "SAI triggers only if player does not have item 'Portable Brewfest Keg'"), 
(22, 1, 24527, 0, 1, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramsteins Swift Work Ram'"), 
(22, 1, 24527, 0, 1, 2, 0, 33797, 1, 0, 1, 0, 0, "", "SAI triggers only if player does not have item 'Portable Brewfest Keg'"), 
(22, 3, 24468, 0, 0, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramsteins Swift Work Ram'"),
(22, 3, 24510, 0, 0, 1, 0, 43880, 0, 0, 0, 0, 0, "", "SAI triggers only if player has aura 'Ramstein's Swift Work Ram'");

-- Update wrong comments
UPDATE `conditions` SET `Comment`="SAI triggers only if player has aura 'Rental Racing Ram'" WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24510 AND `ConditionTypeOrReference`=1 AND `ConditionValue1`=43883;
UPDATE `conditions` SET `Comment`="SAI triggers only if player has item 'Portable Brewfest Keg'" WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24510 AND `ConditionTypeOrReference`=2;
UPDATE `smart_scripts` SET `Comment`="Driz Tumblequick <Ram Racing Apprentice> - Within 0-25 Range - Cast 'Brewfest - Throw Keg - DND'" WHERE `entryorguid`=24510 AND `id`=0;
