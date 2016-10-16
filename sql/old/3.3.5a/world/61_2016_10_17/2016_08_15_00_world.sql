-- Pet Trainer creature updates
UPDATE `creature_template` SET `gossip_menu_id`= 4783 WHERE `entry` IN (543, 3306, 3545, 3698, 4320, 16675, 40405);
UPDATE `creature_template` SET `exp`= 0, `npcflag`= 17, `trainer_type`= 3, `flags_extra`= 2, `ScriptName`= 'npc_pet_trainer' WHERE `entry`= 40405;
UPDATE `gossip_menu_option` SET `option_icon`= 0 WHERE `menu_id`= 6520 AND `id`= 0;

-- gossip menu conditions, hunter class (4) for Pet Trainer gossip window
DELETE FROM `conditions` WHERE `SourceGroup`= 4783;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4783,5838,0,0,15,0,4,0,0,0,0,0,'','Show gossip menu 4783 text id 5838 if player is a Hunter.'),
(14,4783,5839,0,0,15,0,4,0,0,1,0,0,'','Show gossip menu 4783 text id 5839 if player is not a Hunter.'),
(15,4783,   0,0,0,15,0,4,0,0,0,0,0,'','Show gossip menu 4783 option id 0 if player is a Hunter.'),
(15,4783,   1,0,0,15,0,4,0,0,0,0,0,'','Show gossip menu 4783 option id 1 if player is a Hunter.');
