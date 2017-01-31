UPDATE `creature_template` SET `gossip_menu_id`=8372 WHERE  `entry`=21700;
UPDATE `creature_template` SET `unit_flags`=768 WHERE  `entry`=21768;
UPDATE `creature_template` SET `unit_flags`=33536 WHERE  `entry`=21776;

DELETE FROM `gossip_menu` WHERE `entry`=8372;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8372, 10447); -- 21700

DELETE FROM `creature_text` WHERE `entry`IN(21700,21768,21699);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(21700, 0, 0, 'Have no fear, $r.  Just play along.', 15, 0, 100, 0, 0, 0, 19402, 'Akama to Player'),
(21700, 1, 0, 'A mere nuisance, I assure you!  Tell the Master his prisoner will not escape while Akama and his Deathsworn watch over her.', 14, 0, 100, 0, 0, 0, 19403, 'Akama to Player'),
(21700, 2, 0, 'Forgive my harsh methods, but the Betrayer cannot learn of the truth.  My secret must be kept at all costs!', 12, 0, 100, 0, 0, 0, 19405, 'Akama to Player'),
(21700, 3, 0, 'In due time, Maiev.  I''ve spent years preparing to make my move - I can''t afford to put my plans in peril by tipping my hand too soon.', 12, 0, 100, 0, 0, 0, 19408, 'Akama to Player'),
(21700, 4, 0, 'The Heart of Fury... I witnessed its power long ago, when Velen wielded it.  I feel the same power coursing through it right now!', 12, 0, 100, 0, 0, 0, 19858, 'Akama to Player'),
(21700, 5, 0, 'With this crystal''s powers, my Deathsworn and I... we''d be unstoppable!  We could destroy Illidan!  We could... replace him as lords of Outland!', 12, 0, 100, 0, 0, 0, 19859, 'Akama to Player'),
(21700, 6, 0, 'But that is not part of the vision I was granted... that is not... how my people will be freed.', 12, 0, 100, 0, 0, 0, 19860, 'Akama to Player'),
(21700, 7, 0, 'Please, $n.  You must take the Heart of Fury somewhere safe... you must take it to A''dal!', 12, 0, 100, 0, 0, 0, 19870, 'Akama to Player'),
(21699, 0, 0, 'Release me immediately or face my wrath!', 12, 0, 100, 15, 0, 0, 19395, 'Maiev Shadowsong'),
(21699, 1, 0, 'If we truly desire the same thing, Akama, then release me!  If Illidan is to die, it shall be by my hand!', 12, 0, 100, 22, 0, 0, 0, 'Maiev Shadowsong to Player'),
(21699, 2, 0, 'Curse you, Akama!  I am not a pawn in your game... my will is my own.  When I unleash my wrath upon Illidan it will have nothing to do with your foolish scheme!', 12, 0, 100, 0, 0, 0, 19409, 'Maiev Shadowsong to Player'),
(21768, 0, 0, 'Mortals, here?  What is the meaning of this, pathetic Broken!', 14, 0, 100, 0, 0, 0, 19401, 'Vagath to Player'),
(21768, 1, 0, 'You''d do well not to toy with me, Akama.  Illidan has given me specific orders to keep a close watch on the Warden.  If I find out you''re hiding anything from me, I will crush you with my own hands!', 12, 0, 100, 0, 0, 0, 19404, 'Vagath to Player');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(21700,21768,21776,21669);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(21700,21768,21776,21669) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` in(2170000,2170001) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21768, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 21768, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On Just Summoned - Start WP'),
(21768, 0, 1, 0, 40, 0, 100, 0, 2, 21768, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On Reached WP2 - Pause WP'),
(21768, 0, 2, 3, 40, 0, 100, 0, 4, 21768, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 21776, 0, 100, 0, 0, 0, 0, 'Vagath - On Reached WP4 - Despawn Illidari Temptress'),
(21768, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vagath - On Reached WP4 - Despawn'),
(21776, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 29, 0, 0, 0, 0, 0, 0, 19, 21768, 0, 0, 0, 0, 0, 0, 'Illidari Temptress - On Just Summoned - Follow Vagath'),
(21669, 0, 0, 0, 1, 0, 100, 0, 0, 300000, 300000, 900000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Maiev Shadowsong - OOC - Say Line 0'),
(21700, 0, 0, 1, 20, 0, 100, 0, 10628, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10628 rewarded - Store Targetlist'),
(21700, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2170000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10628 rewarded - Run Script'),
(21700, 0, 2, 3, 20, 0, 100, 0, 10707, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10707 rewarded - Store Targetlist'),
(21700, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2170001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10707 rewarded - Run Script'),
(2170000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script - Set NPC Flags'),
(2170000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script - Summon Group'),
(2170000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 21768, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 0 on Vagath'), -- 15:52:01.922
(2170000, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.530727, 'Akama - Script - Set Orientation'), -- 15:52:02.032
(2170000, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 0'), -- 15:52:07.141
(2170000, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 11, 37448, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Cast Chain Lightning'), -- 15:52:13.110
(2170000, 9, 6, 0, 0, 0, 100, 0, 50, 50, 0, 0, 85, 37493, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - InVoker Cast Feign Death'), -- 15:52:13.125
(2170000, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 1'), -- 15:52:13.188
(2170000, 9, 8, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21768, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 1 on Vagath'), -- 15:52:21.219
(2170000, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 2'), -- 15:52:38.500
(2170000, 9, 10, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 37449, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Cast Resurrect'), -- 15:52:40.813
(2170000, 9, 11, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 28, 37493, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Remove Aura Feign Death'), -- 15:52:43.828
(2170000, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Set Unit Flags 2 on Player'), -- 15:52:13.125
(2170000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script - Set Npc Flags'),
(2170000, 9, 14, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 21699, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 1 on Maiev Shadowsong '), -- 15:52:53.000
(2170000, 9, 15, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 3'), -- 15:52:59.016
(2170000, 9, 16, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 21699, 0, 0, 0, 0, 0, 0, 'Akama - Script - Say Line 2 on Maiev Shadowsong '), -- 15:53:05.063
(2170001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Set NPC Flags'),
(2170001, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Set Orientation'), 
(2170001, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Say Line 4'), -- 15:23:44.859
(2170001, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Say Line 5'), -- 15:23:50.906
(2170001, 9, 4, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Say Line 6'), -- 15:23:59.359
(2170001, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Set NPC Flags'), -- 15:24:05.265
(2170001, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Akama - Script 2 - Say Line 6'); -- 15:24:05.422

DELETE FROM `creature_summon_groups` WHERE `summonerId`=21700;

INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(21700, 0, 0, 21768, -3726.069,1040.505, 56.03978, 4.852015, 1, 60000),
(21700, 0, 0, 21776, -3730.32, 1041.369, 56.03996, 4.72222, 1, 60000),
(21700, 0, 0, 21776, -3722.402, 1041.253, 56.0398, 4.72222, 1, 60000);

DELETE FROM `waypoints` WHERE `entry` =21768;

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(21768, 1,-3724.426, 1030.954, 55.95728, 'Vagath'),
(21768, 2,-3721.095, 1030.279, 55.95773, 'Vagath'),
(21768, 3,-3725.885, 1035.806, 55.95677, 'Vagath'),
(21768, 4,-3726.25, 1040.238, 55.95593, 'Vagath');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=37493;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(37493, 31261, 2, 'Feign Death');
