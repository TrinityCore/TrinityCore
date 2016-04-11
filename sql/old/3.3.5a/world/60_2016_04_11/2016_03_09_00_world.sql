UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(4968,23704);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(4968,23704) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2370400) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4968, 0, 0, 1, 62, 0, 100, 0, 2465, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Gossip Select - Close Gossip'),
(4968, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Gossip Select - Say Line 6'),
(4968, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 23122, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Gossip Select - Cast Jaina''s Autograph'),
(4968, 0, 3, 4, 20, 0, 100, 0, 11142, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Quest Reward (Survey Alcaz Island - Face player'),
(4968, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Quest Reward (Survey Alcaz Island - Say Line 0'), -- 04:20:13.000
(4968, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 81, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Quest Reward (Survey Alcaz Island - Set NPC Flags'), 
(4968, 0, 6, 0, 52, 0, 100, 0, 0, 4968, 0, 0, 1, 1, 7000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 0 - Say Line 1'), -- 04:20:18.000
(4968, 0, 7, 0, 52, 0, 100, 0, 1, 4968, 0, 0, 1, 2, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 1 - Say Line 2'), -- 04:20:25.000
(4968, 0, 8, 0, 52, 0, 100, 0, 2, 4968, 0, 0, 1, 3, 7000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 2 - Say Line 3'), -- 04:20:31.000
(4968, 0, 9, 0, 52, 0, 100, 0, 3, 4968, 0, 0, 1, 4, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 3 - Say Line 4'), -- 04:20:38.000
(4968, 0, 10, 0, 52, 0, 100, 0, 4, 4968, 0, 0, 1, 5, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 4 - Say Line 5'), -- 04:20:44.000
(4968, 0, 11, 12, 52, 0, 100, 0, 5, 4968, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 5 - Set Npc Flag'),
(4968, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Text Over Line 5 - Evade'),
(23704, 0, 0, 1, 62, 0, 100, 0, 8782, 0, 0, 0, 11, 42295, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cassa Crimsonwing - On Gossip Option 0 Selected - Cast Spell 42295'),
(23704, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cassa Crimsonwing - On Linked Actions - Close Gossip');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=2465;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(2465, 0, 0, 'Lady Jaina, this may sound like an odd request... but I have a young ward who is quite shy.  You are a hero to him, and he asked me to get your autograph.', 9663, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2465;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 2465, 0, 0, 0, 9, 0, 558, 0, 0, 0, 0, 0, '', 'Lady Jaina Proudmoore Shows gossip option 2465 if player has quest Jaina''s Autograph');

DELETE FROM `creature_text` WHERE `entry`=4968;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(4968, 0, 0, 'Perhaps I should explain...', 12, 0, 100, 1, 0, 0, 33092, 'Lady Jaina Proudmoore to Player'),
(4968, 1, 0, 'I had arranged for a secret summit between Warchief Thrall and King Wrynn, here in Theramore.', 12, 0, 100, 1, 0, 0, 33093, 'Lady Jaina Proudmoore to Player'),
(4968, 2, 0, 'The king was to travel here by ship, in secret. But the ship never arrived, and King Wrynn disappeared.', 12, 0, 100, 1, 0, 0, 33094, 'Lady Jaina Proudmoore to Player'),
(4968, 3, 0, 'Your help enabled us to connect the Defias to the mastermind behind the abduction, Onyxia, who was posing as a member of the royal court.', 12, 0, 100, 1, 0, 0, 33095, 'Lady Jaina Proudmoore to Player'),
(4968, 4, 0, 'Meanwhile, the king managed to escape his captors, and returned to Stormwind to deal with Onyxia.', 12, 0, 100, 1, 0, 0, 33096, 'Lady Jaina Proudmoore to Player'),
(4968, 5, 0, 'I will send word that you have discovered the link to the Defias. I was a fool to think them broken with the defeat of Edwin Van Cleef, and King Wrynn will want to make an example of all who remain.', 12, 0, 100, 1, 0, 0, 33097, 'Lady Jaina Proudmoore to Player'),
(4968, 6, 0, 'Why... that is very sweet of you.  I gather that you are volunteering time for Children''s Week, yes $c?  Well, you are to be commended.  It is imperative that we remember those less fortunate - especially the children.$B$BI''d be happy to sign an autograph.  Here you go.', 12, 0, 100, 1, 0, 0, 9665, 'Lady Jaina Proudmoore to Player');
