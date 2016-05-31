DELETE FROM `gossip_menu` WHERE `entry` IN(7768,7767,7766,7765,7764,7763,7762,7974,7979,7978,7977,7976);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(7768, 9507), -- 18141
(7767, 9508), -- 18141
(7766, 9509), -- 18141
(7765, 9510), -- 18141
(7764, 9511), -- 18141
(7763, 9512), -- 18141
(7762, 9513), -- 18141
(7768, 9819), -- 18141
(7974, 9821), -- 18141
(7979, 9822), -- 18141
(7978, 9823), -- 18141
(7977, 9824), -- 18141
(7976, 9825); -- 18141

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(7768,7767,7766,7765,7764,7763,7762,7974,7979,7978,7977,7976);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
-- A Visit with the Greatmother
(7768, 0, 0, 'Hello, Greatmother. Garrosh told me that you wanted to speak with me.', 15770, 1, 1, 7767, 0, 0, 0, '', 0),
(7767, 0, 0, 'You raised all of the orcs here, Greatmother?', 15772, 1, 1, 7766, 0, 0, 0, '', 0),
(7766, 0, 0, 'Do you believe that?', 15774, 1, 1, 7765, 0, 0, 0, '', 0),
(7765, 0, 0, 'What can be done? I have tried many different things. I have done my best to help the people of Nagrand. Each time I have approached Garrosh, he has dismissed me.', 15776, 1, 1, 7764, 0, 0, 0, '', 0),
(7764, 0, 0, 'Left? How can you choose to leave?', 15778, 1, 1, 7763, 0, 0, 0, '', 0),
(7763, 0, 0, 'What is this duty?', 15780, 1, 1, 7762, 0, 0, 0, '', 0),
(7762, 0, 0, 'Is there anything I can do for you, Greatmother?', 15782, 1, 1, 0, 0, 0, 0, '', 0),
-- There is no hope
(7768, 1, 0, 'Garrosh is beyond redemption, Greatmother. I fear that in helping the Mag\'har, I have convinced Garrosh that he is unfit to lead.', 16845, 1, 1, 7974, 0, 0, 0, '', 0),
(7974, 0, 0, 'I have done all that I could, Greatmother. I thank you for your kind words.', 16849, 1, 1, 7979, 0, 0, 0, '', 0),
(7979, 0, 0, 'Greatmother, you are the mother of Durotan?', 16851, 1, 1, 7978, 0, 0, 0, '', 0),
(7978, 0, 0, 'Greatmother, I never had the honor. Durotan died long before my time, but his heroics are known to all on my world. The orcs of Azeroth reside in a place known as Durotar, named after your son. And... <You take a moment to breathe and think through what you are about to tell the Greatmother.>', 16853, 1, 1, 7977, 0, 0, 0, '', 0),
(7977, 0, 0, 'It is my warchief, Greatmother. The leader of my people. From my world. He... He is the son of Durotan. He is your grandchild.', 16855, 1, 1, 7976, 0, 0, 0, '', 0),
(7976, 0, 0, 'I will return to Azeroth at once, Greatmother.', 16857, 1, 1, 0, 0, 0, 0, '', 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14,15) AND `SourceGroup`=7768;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 7768, 0, 0, 0, 9, 0, 10044, 0, 0, 0, 0, 0, '', 'Greatmother Geyah - Show gossip option only if player has A Visit With the Greatmother taken'),
(15, 7768, 1, 0, 0, 9, 0, 10172, 0, 0, 0, 0, 0, '', 'Greatmother Geyah - Show gossip option only if player has There is no hope taken'),
(14, 7768, 9819, 0, 0, 9, 0, 10172, 0, 0, 0, 0, 0, '', 'Greatmother Geyah - Show npc text only if player has There is no hope taken'),
(14, 7768, 9507, 0, 0, 9, 0, 10172, 0, 0, 1, 0, 0, '', 'Greatmother Geyah - Show npc text only if player does not have There is no hope taken');

DELETE FROM `npc_text` WHERE `ID` IN(9819,9821,9822,9823,9824,9825);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `VerifiedBuild`) VALUES 
(9819, '', "What did Garrosh tell you, $n?", 16844, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9821, '', "<Greatmother Geyah nods, accepting your answer.>$B$BI can no longer fight the spirits, $n. My time has long since passed. Once again, I must thank you for all that you have done. While Garrosh may be unmovable, many of my people have been lifted by your accomplishments. They are now willing to fight for our rights as a united clan.", 16848, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9822, '', "<Greatmother Geyah smiles at you.>$B$BYou remind me of my son, $n.$B$BHe was an immovable mountain: A pillar of strength and honor.$B$B<Geyah's eyes well up with tears.>$B$BHe sacrificed himself so that we could survive. So that generations of orcs after him could be born into a world without the blood curse... Without Gul'dan and his dark Horde...$B$B<Geyah stares into the distance, lost in thought.>$B$BOh Durotan, how I wish you could be here. Your people so desperately need you...", 16850, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9823, '', "<Greatmother Geyah nods.>$B$BDid you know my son?", 16852, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9824, '', "<Greatmother Geyah's violet eyes lock onto yours.>$B$BYes...", 16854, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(9825, '', "<Tears stream down Greatmother Geyah's face.>$B$BI... I... Durotan survived to have a child? The child Draka told me of before they left... It was their greatest fear... To raise a child in this world. On the other side of that gate was their only hope. I dared not tell Durotan, but secretly, I begged the spirits to watch over them - to protect their child and to give them strength.$B$BI... I must see my grandchild. I must see him. Please, I am too weak. You must tell him. Before I leave this world...", 16856, 0, 1, 1, 1, 1, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE  `entry` =18141;
DELETE FROM `smart_scripts` WHERE `entryorguid` =18141;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18141, 0, 0, 2, 62, 0, 100, 0, 7762, 0, 0, 0, 15, 10044, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Geyah - On Gossip Option Select - Complete Quest (A Visit With the Greatmother)'),
(18141, 0, 1, 2, 62, 0, 100, 0, 7976, 0, 0, 0, 15, 10172, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Geyah - On Gossip Option Select - Complete Quest (There is no hope)'),
(18141, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greatmother Geyah - On Gossip Option Select - Close Gossip');
