UPDATE `gameobject_template` SET `flags`=16 WHERE `entry` IN (191349, 193603);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` AND `SourceGroup` IN (27692,27755,27756);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(21,27692,50344,0,0,13,1,2,3,2,0,0,0,'','Vehicle Spell requires Boss Urom must be done'),
(21,27755,49592,0,0,13,1,2,3,2,0,0,0,'','Vehicle Spell requires Boss Urom must be done'),
(21,27756,50253,0,0,13,1,2,3,2,0,0,0,'','Vehicle Spell requires Boss Urom must be done');

UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (27657,27659);
UPDATE `creature_template` SET `gossip_menu_id`=9573 WHERE `entry`=27657;
UPDATE `creature_template` SET `gossip_menu_id`=9708 WHERE `entry`=27658;
UPDATE `creature_template` SET `gossip_menu_id`=9574 WHERE `entry`=27659;

DELETE FROM `npc_text` WHERE `ID`=13467;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(13467, 'The trickster Mage-Lord Urom protects the third ring.  He will appear alone and defenseless, but do not be fooled by appearances!  Urom is a powerful conjurer who commands a menagerie of Phantasmal creatures.  Seek him out above.', 'The trickster Mage-Lord Urom protects the third ring.  He will appear alone and defenseless, but do not be fooled by appearances!  Urom is a powerful conjurer who commands a menagerie of Phantasmal creatures.  Seek him out above.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 14545);


DELETE FROM `gossip_menu` WHERE `entry` IN (9573,9703,9704,9787,9575,9699,9700,9708,9574,9701,9702,9786);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
-- Verdisa
(9573, 12915), -- 27657 -- init -- urom not done
(9573, 13241), -- 27657 -- eregos done
(9573, 13269), -- 27657 -- eregos not done

(9703, 13258), -- 27657 -- attacks
(9704, 13259), -- 27657 -- special

(9787, 13466), -- 27657 -- varos not done
(9787, 13467), -- 27657 -- urom not done
(9787, 13468), -- 27657 -- eregos not done

-- Belgaristrasz
(9575, 12916), -- 27658 -- varos not done
(9575, 13237), -- 27658 -- urom not done
(9575, 13238), -- 27658 -- eregos not done
(9575, 13239), -- 27658 -- eregos done

(9699, 13254), -- 27658 -- attacks
(9700, 13255), -- 27658 -- special

(9708, 13267), -- 27658 -- init

-- Eternos
(9574, 12917), -- 27659 -- init -- urom not done
(9574, 13240), -- 27659 -- eregos done
(9574, 13268), -- 27659 -- eregos not done

(9701, 13256), -- 27659 -- attacks
(9702, 13257), -- 27659 -- special

(9786, 13466), -- 27659 -- varos not done
(9786, 13467), -- 27659 -- urom not done
(9786, 13468); -- 27659 -- eregos not done


DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9708,9574,9573,9575);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
-- Verdisa
(9573, 0, 0, 'What should we do next?',                                  1, 1, 9787, 0, 0, 0, ''), -- 27657 -- eregos not done
(9573, 1, 0, 'I want to fly on the wings of the green flight.',          1, 1,    0, 0, 0, 0, ''), -- 27657 -- no essence
(9573, 2, 0, 'I want to exchange my Amber Essence for Emerald Essence.', 1, 1,    0, 0, 0, 0, ''), -- 27657 -- has amber essence
(9573, 3, 0, 'I want to exchange my Ruby Essence for Emerald Essence.',  1, 1,    0, 0, 0, 0, ''), -- 27657 -- has ruby essence
(9573, 4, 0, 'What abilities do emerald drakes have?',                   1, 1, 9703, 0, 0, 0, ''), -- 27657
(9573, 5, 0, 'What is the ultimate ability of the emerald drake?',       1, 1, 9704, 0, 0, 0, ''), -- 27657 -- urom must be done

-- Eternos
(9574, 0, 0, 'What should we do next?',                                  1, 1, 9786, 0, 0, 0, ''), -- 27659 -- eregos not done
(9574, 1, 0, 'I want to fly on the wings of the bronze flight.',         1, 1,    0, 0, 0, 0, ''), -- 27659 -- no essence
(9574, 2, 0, 'I want to exchange my Emerald Essence for Amber Essence.', 1, 1,    0, 0, 0, 0, ''), -- 27659 -- has emerald essence
(9574, 3, 0, 'I want to exchange my Ruby Essence for Amber Essence.',    1, 1,    0, 0, 0, 0, ''), -- 27659 -- has ruby essence
(9574, 4, 0, 'What abilities do amber drakes have?',                     1, 1, 9701, 0, 0, 0, ''), -- 27659
(9574, 5, 0, 'What is the ultimate ability of the amber drake?',         1, 1, 9702, 0, 0, 0, ''), -- 27659 -- urom must be done

-- Belgaristrasz
(9708, 0, 0, 'So where do we go from here?',                             1, 1, 9575, 0, 0, 0, ''), -- 27658

(9575, 0, 0, 'I want to fly on the wings of the red flight.',            1, 1,    0, 0, 0, 0, ''), -- 27658 -- no essence
(9575, 1, 0, 'I want to exchange my Amber Essence for Ruby Essence.',    1, 1,    0, 0, 0, 0, ''), -- 27658 -- has amber essence
(9575, 2, 0, 'I want to exchange my Emerald Essence for Ruby Essence.',  1, 1,    0, 0, 0, 0, ''), -- 27658 -- has emerald essence
(9575, 3, 0, 'What abilities do ruby drakes have?',                      1, 1, 9699, 0, 0, 0, ''), -- 27658
(9575, 4, 0, 'What is the ultimate ability of the Ruby Drake?',          1, 1, 9700, 0, 0, 0, ''); -- 27658 -- urom must be done


/*
    DATA_DRAKOS           = 0,
    DATA_VAROS            = 1,
    DATA_UROM             = 2,
    DATA_EREGOS           = 3,

    DONE                  = 3,
	
    ITEM_EMERALD_ESSENCE  = 37815,
    ITEM_AMBER_ESSENCE    = 37859,
    ITEM_RUBY_ESSENCE     = 37860,
*/

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (9573,9787,9575,9574,9786);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9573,12915,0,0,13,1,2,3,2,1,0,0,'','Show text only if Boss Urom not done'),   -- urom not done
(14,9573,13241,0,0,13,1,3,3,2,0,0,0,'','Show text only if Boss Eregos done'),     -- eregos done
(14,9573,13269,0,0,13,1,2,3,2,0,0,0,'','Show text only if Boss Urom done'),       -- urom done
(14,9573,13269,0,0,13,1,3,3,2,1,0,0,'','Show text only if Boss Eregos not done'), -- eregos not done

(14,9787,13466,0,0,13,1,1,3,2,1,0,0,'','Show text only if Boss Varos not done'),  -- varos not done
(14,9787,13467,0,0,13,1,1,3,2,0,0,0,'','Show text only if Boss Varos done'),      -- varos done
(14,9787,13467,0,0,13,1,2,3,2,1,0,0,'','Show text only if Boss Urom not done'),   -- urom not done
(14,9787,13468,0,0,13,1,2,3,2,0,0,0,'','Show text only if Boss Urom done'),       -- urom done
(14,9787,13468,0,0,13,1,3,3,2,1,0,0,'','Show text only if Boss Eregos not done'), -- eregos not done

(14,9575,12916,0,0,13,1,1,3,2,1,0,0,'','Show text only if Boss Varos not done'),  -- varos not done
(14,9575,13237,0,0,13,1,1,3,2,0,0,0,'','Show text only if Boss Varos done'),      -- varos done
(14,9575,13237,0,0,13,1,2,3,2,1,0,0,'','Show text only if Boss Urom not done'),   -- urom not done
(14,9575,13238,0,0,13,1,2,3,2,0,0,0,'','Show text only if Boss Urom done'),       -- urom done
(14,9575,13238,0,0,13,1,3,3,2,1,0,0,'','Show text only if Boss Eregos not done'), -- eregos not done
(14,9575,13239,0,0,13,1,3,3,2,0,0,0,'','Show text only if Boss Eregos done'),     -- eregos done

(14,9574,12917,0,0,13,1,2,3,2,1,0,0,'','Show text only if Boss Urom not done'),   -- urom not done
(14,9574,13240,0,0,13,1,3,3,2,0,0,0,'','Show text only if Boss Eregos done'),     -- eregos done
(14,9574,13268,0,0,13,1,2,3,2,0,0,0,'','Show text only if Boss Urom done'),       -- urom done
(14,9574,13268,0,0,13,1,3,3,2,1,0,0,'','Show text only if Boss Eregos not done'), -- eregos not done

(14,9786,13466,0,0,13,1,1,3,2,1,0,0,'','Show text only if Boss Varos not done'),  -- varos not done
(14,9786,13467,0,0,13,1,1,3,2,0,0,0,'','Show text only if Boss Varos done'),      -- varos done
(14,9786,13467,0,0,13,1,2,3,2,1,0,0,'','Show text only if Boss Urom not done'),   -- urom not done
(14,9786,13468,0,0,13,1,2,3,2,0,0,0,'','Show text only if Boss Urom done'),       -- urom done
(14,9786,13468,0,0,13,1,3,3,2,1,0,0,'','Show text only if Boss Eregos not done'); -- eregos not done


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9573,9574,9575);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9573,0,0,0,13,1,3,3,2,1,0,0,'','Show options for gossip only if Boss Eregos not done'), -- eregos not done
(15,9573,1,0,0,2,0,37859,1,0,1,0,0,'','Show options for gossip only if Player has no amber essence'),   -- has no amber essence
(15,9573,1,0,0,2,0,37815,1,0,1,0,0,'','Show options for gossip only if Player has no emerald essence'), -- has no emerald essence
(15,9573,1,0,0,2,0,37860,1,0,1,0,0,'','Show options for gossip only if Player has no ruby essence'),    -- has no ruby essence
(15,9573,2,0,0,2,0,37859,1,0,0,0,0,'','Show options for gossip only if Player has amber essence'),      -- has amber essence
(15,9573,3,0,0,2,0,37860,1,0,0,0,0,'','Show options for gossip only if Player has ruby essence'),       -- has ruby essence
(15,9573,5,0,0,13,1,2,3,2,0,0,0,'','Show options for gossip only if Boss Urom done'), -- urom done

(15,9574,0,0,0,13,1,3,3,2,1,0,0,'','Show options for gossip only if Boss Eregos not done'), -- eregos not done
(15,9574,1,0,0,2,0,37859,1,0,1,0,0,'','Show options for gossip only if Player has no amber essence'),   -- has no amber essence
(15,9574,1,0,0,2,0,37815,1,0,1,0,0,'','Show options for gossip only if Player has no emerald essence'), -- has no emerald essence
(15,9574,1,0,0,2,0,37860,1,0,1,0,0,'','Show options for gossip only if Player has no ruby essence'),    -- has no ruby essence
(15,9574,2,0,0,2,0,37815,1,0,0,0,0,'','Show options for gossip only if Player has emerald essence'),    -- has emerald essence
(15,9574,3,0,0,2,0,37860,1,0,0,0,0,'','Show options for gossip only if Player has ruby essence'),       -- has ruby essence
(15,9574,5,0,0,13,1,2,3,2,0,0,0,'','Show options for gossip only if Boss Urom done'), -- urom done

(15,9575,0,0,0,2,0,37859,1,0,1,0,0,'','Show options for gossip only if Player has no amber essence'),   -- has no amber essence
(15,9575,0,0,0,2,0,37815,1,0,1,0,0,'','Show options for gossip only if Player has no emerald essence'), -- has no emerald essence
(15,9575,0,0,0,2,0,37860,1,0,1,0,0,'','Show options for gossip only if Player has no ruby essence'),    -- has no ruby essence
(15,9575,1,0,0,2,0,37859,1,0,0,0,0,'','Show options for gossip only if Player has amber essence'),      -- has amber essence
(15,9575,2,0,0,2,0,37815,1,0,0,0,0,'','Show options for gossip only if Player has emerald essence'),    -- has emerald essence
(15,9575,4,0,0,13,1,2,3,2,0,0,0,'','Show options for gossip only if Boss Urom done'); -- urom done


DELETE FROM `spell_script_names` WHERE `spell_id` IN (49345,49461,49462,49427,49459,49463,49838);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49345, 'spell_oculus_call_ruby_emerald_amber_drake'),
(49461, 'spell_oculus_call_ruby_emerald_amber_drake'),
(49462, 'spell_oculus_call_ruby_emerald_amber_drake'),
(49427, 'spell_oculus_ride_ruby_emerald_amber_drake_que'),
(49459, 'spell_oculus_ride_ruby_emerald_amber_drake_que'),
(49463, 'spell_oculus_ride_ruby_emerald_amber_drake_que'),
(49838, 'spell_oculus_stop_time');


-- Remove invalid ScriptNames from DB
UPDATE `conditions` SET `ScriptName`='' WHERE `ScriptName`='0';
