SET @SQUIRE=33238;
SET @GRUNT=33239;
SET @GOSSIPSQUIRE=10318; -- From sniff
SET @GOSSIPGRUNT=10317; -- Guess
-- Add Spell Script name
DELETE FROM `spell_script_names` WHERE `spell_id` = 67039;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUE 
(67039, 'TW_spell_vanity_mount_check');
-- spell link to apply tired debuff
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (67401, 68852);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`, `type`, `comment`) VALUES
(-67368, 67401, 0, 'Argent Squire - Bank - Tired'),
(-67377, 67401, 0, 'Argent Squire - Shop - Tired'),
(-67376, 67401, 0, 'Argent Squire - Mail - Tired'),
(-68849, 68852, 0, 'Argent Grunt - Bank - Tired'),
(-68850, 68852, 0, 'Argent Grunt - Shop - Tired'),
(-68851, 68852, 0, 'Argent Grunt - Mail - Tired');
-- Add gossip menu id for argent squire and gruntling
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIPSQUIRE, `ScriptName`='TW_npc_vanity_argent_squire' WHERE `entry` = @SQUIRE;
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIPGRUNT, `ScriptName`='TW_npc_vanity_argent_squire' WHERE `entry` = @GRUNT;
-- Add gossip menu text for argent gruntling
DELETE FROM `gossip_menu` WHERE `entry`IN (@GOSSIPGRUNT);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(@GOSSIPGRUNT, 14372);
-- Add gossip menu options for argent squire and gruntling
DELETE FROM `gossip_menu_option` WHERE `menu_id`IN (@GOSSIPSQUIRE,@GOSSIPGRUNT);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(@GOSSIPSQUIRE, 0, 6, 'Visit a bank', 35513, 9, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 1, 1, 'Visit a trader', 35515, 3, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 2, 0, 'Visit a mailbox', 35534, 1, 1, 0, 0, 0, 0, '', 0), 
(@GOSSIPSQUIRE, 3, 0, 'Darnassus Champion\'s Pennant', 33675, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 4, 0, 'Exodar Champion\'s Pennant', 33676, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 5, 0, 'Gnomeeregan Champion\'s Pennant', 33678, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 6, 0, 'Ironforge Champion\'s Pennant', 33679, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPSQUIRE, 7, 0, 'Stormwind Champion\'s Pennant', 33401, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 0, 6, 'Visit a bank', 35513, 9, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 1, 1, 'Visit a trader', 35515, 3, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 2, 0, 'Visit a mailbox', 35534, 1, 1, 0, 0, 0, 0, '', 0), 
(@GOSSIPGRUNT, 3, 0, 'Darkspear Champion\'s Pennant', 33681, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 4, 0, 'Forsaken Champion\'s Pennant', 33682, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 5, 0, 'Orgrimmar Champion\'s Pennant', 33683, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 6, 0, 'Silvermoon Champion\'s Pennant', 33685, 1, 1, 0, 0, 0, 0, '', 0),
(@GOSSIPGRUNT, 7, 0, 'Thunder Bluff Champion\'s Pennant', 33686, 1, 1, 0, 0, 0, 0, '', 0);
-- Add conditions for gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (@GOSSIPSQUIRE,@GOSSIPGRUNT);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, @GOSSIPSQUIRE, 0, 0, 1, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent squire show Visit a bank if player has achievement pony up'),
(15, @GOSSIPSQUIRE, 0, 0, 1, 1, 1, 67401, 0, 0, 1, 0, '', 'Argent squire show Visit a bank no tired aura'),
(15, @GOSSIPSQUIRE, 0, 0, 1, 1, 1, 67377, 0, 0, 1, 0, '', 'Argent squire show Visit a bank no shop aura'),
(15, @GOSSIPSQUIRE, 0, 0, 1, 1, 1, 67376, 0, 0, 1, 0, '', 'Argent squire show Visit a bank no postman aura'),
(15, @GOSSIPSQUIRE, 1, 0, 2, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent squire show Visit a trader if player has achievement pony up'),
(15, @GOSSIPSQUIRE, 1, 0, 2, 1, 1, 67401, 0, 0, 1, 0, '', 'Argent squire show Visit a trader no tired aura'),
(15, @GOSSIPSQUIRE, 1, 0, 2, 1, 1, 67368, 0, 0, 1, 0, '', 'Argent squire show Visit a trader no bank errand aura'),
(15, @GOSSIPSQUIRE, 1, 0, 2, 1, 1, 67376, 0, 0, 1, 0, '', 'Argent squire show Visit a trader no postman aura'),
(15, @GOSSIPSQUIRE, 2, 0, 3, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent squire show Visit a mailbox if player has achievement pony up'),
(15, @GOSSIPSQUIRE, 2, 0, 3, 1, 1, 67401, 0, 0, 1, 0, '', 'Argent squire show Visit a mailbox no tired aura'),
(15, @GOSSIPSQUIRE, 2, 0, 3, 1, 1, 67368, 0, 0, 1, 0, '', 'Argent squire show Visit a mailbox no bank errand aura'),
(15, @GOSSIPSQUIRE, 2, 0, 3, 1, 1, 67377, 0, 0, 1, 0, '', 'Argent squire show Visit a mailbox no shop aura'),
(15, @GOSSIPSQUIRE, 3, 0, 0, 8, 0, 13725, 0, 0, 0, 0, '', 'Argent squire show Darnassus Champion\'s Pennant if player has completed Champion of Darnassus'),
(15, @GOSSIPSQUIRE, 4, 0, 0, 8, 0, 13724, 0, 0, 0, 0, '', 'Argent squire show Exodar Champion\'s Pennant if player has completed Champion of the Exodar'),
(15, @GOSSIPSQUIRE, 5, 0, 0, 8, 0, 13723, 0, 0, 0, 0, '', 'Argent squire show Gnomeeregan Champion\'s Pennant if player has completed Champion of Gnomeregan'),
(15, @GOSSIPSQUIRE, 6, 0, 0, 8, 0, 13713, 0, 0, 0, 0, '', 'Argent squire show Ironforge Champion\'s Pennant if player has completed Champion of Ironforge'),
(15, @GOSSIPSQUIRE, 7, 0, 0, 8, 0, 13699, 0, 0, 0, 0, '', 'Argent squire show Stormwind Champion\'s Pennant if player has completed Champion of Stormwind'),
(15, @GOSSIPGRUNT, 0, 0, 1, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent Gruntling show Visit a bank if player has achievement pony up'),
(15, @GOSSIPGRUNT, 0, 0, 1, 1, 1, 68852, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a bank no tired aura'),
(15, @GOSSIPGRUNT, 0, 0, 1, 1, 1, 68851, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a bank no shop aura'),
(15, @GOSSIPGRUNT, 0, 0, 1, 1, 1, 68850, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a bank no Postman aura'),
(15, @GOSSIPGRUNT, 1, 0, 2, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent Gruntling show Visit a trader if player has achievement pony up'),
(15, @GOSSIPGRUNT, 1, 0, 2, 1, 1, 68852, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no tired aura'),
(15, @GOSSIPGRUNT, 1, 0, 2, 1, 1, 68849, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no bank errand aura'),
(15, @GOSSIPGRUNT, 1, 0, 2, 1, 1, 68850, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no Postman aura'),
(15, @GOSSIPGRUNT, 2, 0, 3, 17, 0, 3736, 0, 0, 0, 0, '', 'Argent Gruntling show Visit a mailbox if player has achievement pony up'),
(15, @GOSSIPGRUNT, 2, 0, 3, 1, 1, 68852, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no tired aura'),
(15, @GOSSIPGRUNT, 2, 0, 3, 1, 1, 68849, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no bank errand aura'),
(15, @GOSSIPGRUNT, 2, 0, 3, 1, 1, 68851, 0, 0, 1, 0, '', 'Argent Gruntling show Visit a trader no shop aura'),
(15, @GOSSIPGRUNT, 3, 0, 0, 8, 0, 13727, 0, 0, 0, 0, '', 'Argent Gruntling show Darkspear Champion\'s Pennant if player has completed Champion of Sen\'jin'),
(15, @GOSSIPGRUNT, 4, 0, 0, 8, 0, 13729, 0, 0, 0, 0, '', 'Argent Gruntling show Forsaken Champion\'s Pennant if player has completed Champion of the Undercity'),
(15, @GOSSIPGRUNT, 5, 0, 0, 8, 0, 13726, 0, 0, 0, 0, '', 'Argent Gruntling show Orgrimmar Champion\'s Pennant if player has completed Champion of Orgrimmar'),
(15, @GOSSIPGRUNT, 6, 0, 0, 8, 0, 13731, 0, 0, 0, 0, '', 'Argent Gruntling show Silvermoon Champion\'s Pennant if player has completed Champion of Silvermoon City'),
(15, @GOSSIPGRUNT, 7, 0, 0, 8, 0, 13728, 0, 0, 0, 0, '', 'Argent Gruntling show Thunder Bluff Champion\'s Pennant if player has completed Champion of Thunder Bluff');