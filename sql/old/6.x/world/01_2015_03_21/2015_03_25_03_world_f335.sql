DELETE FROM `creature_text` WHERE `entry` IN(22865,22820);
DELETE FROM `creature_text` WHERE `entry` =21700 AND `groupid`>7;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(22865, 0, 0, 'You disappoint me, Akama.  I wanted to question the treacherous worm myself!  I''m beginning to question your allegiance, Broken.', 12, 0, 100, 1, 0, 11608, 20628, 'Illidan''s Presence to Player'),
(22865, 1, 0, 'I do not sense lies in your voice, Akama.  That Kael''thas would betray me does not come as a big surprise - I''m not as oblivious as some would think. That one of your own was involved with him puts your loyalties into question.', 12, 0, 100, 5, 0, 11609, 20629, 'Illidan''s Presence to Player'),
(22865, 2, 0, 'Send your Ashtongue into Tempest Keep and slay his most prized possession, the phoenix known as Al''ar.  I must know that you''re not on his side.  Do not think of betraying me, Broken.  We both know who owns your soul!', 12, 0, 100, 1, 0, 11610, 20630, 'Illidan''s Presence to Player'),
(21700, 8, 0, 'Olum... old friend.  It is good to see that you are safe.', 12, 0, 100, 6, 0, 11600, 20490, 'Akama to Player'),
(21700, 9, 0, 'Illidan will become suspicious... that much is for certain.  We will deal with it as we always do.', 12, 0, 100, 0, 0, 11601, 20491, 'Akama to Player'),
(21700, 10, 0, 'You cannot... be serious, Olum.  Your sacrifice has already been too great.', 12, 0, 100, 274, 0, 11602, 20492, 'Akama to Player'),
(21700, 11, 0, 'It appears your mind is set then.  We will guide you to the spirit world with as much kindness as we can.', 12, 0, 100, 396, 0, 11603, 20493, 'Akama to Player'),
(21700, 12, 0, 'Farewell, dear friend. We shall meet you in the next world when our duties in this one are fulfilled.', 12, 0, 100, 0, 0, 11604, 20494, 'Akama to Player'),
(21700, 13, 0, 'Master!  We''ve found the traitor who escaped Vashj!  His body lies in front of me... lifeless!', 12, 0, 100, 0, 0, 11605, 20495, 'Akama to Player'),
(21700, 14, 0, 'But, sire!  You have misjudged my actions... I do have knowledge of someone close to you who plans to betray you.  It is that dog, Kael''thas!  He has allied with Kil''jaeden and intends to replace you as Lord of Outland!', 12, 0, 100, 0, 0, 11606, 20496, 'Akama to Player'),
(21700, 15, 0, 'It will be done, my lord!', 12, 0, 100, 66, 0, 11607, 20497, 'Akama to Player'),
(22820, 0, 0, 'Akama, my friend!  Have you been informed?  I was found out by Vashj''s followers.  Our secret is in peril!', 12, 0, 100, 0, 0, 11611, 20498, 'Seer Olum to Player'),
(22820, 1, 0, 'Illidan is looking for me.  I am not safe here... none of us are.', 12, 0, 100, 1, 0, 11612, 20502, 'Seer Olum to Player'),
(22820, 2, 0, 'Illidan will find me and when he does... he will pry the Ashtongue secret from me - such is the power of the Betrayer!  No... there is only one way.  My usefulness to the cause has come to an end. I must venture into the spirit world!', 12, 0, 100, 6, 0, 11613, 20499, 'Seer Olum to Player'),
(22820, 3, 0, 'My decision is final.  I will not be dissuaded.  I have devoted my life to our plan.  To jeopardize it now would betray all who have died for the cause long before me.', 12, 0, 100, 274, 0, 11614, 20500, 'Seer Olum to Player'),
(22820, 4, 0, 'I thank you, Akama.  You honor me by allowing me this moment, surrounded by my brothers.  Farewell, friend.  Guide our people well.', 12, 0, 100, 2, 0, 11615, 20501, 'Seer Olum to Player');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(22820,22865,22870);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(22820,22865,22870) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =21700 AND `source_type`=0 AND `id` IN(4,5);

DELETE FROM `smart_scripts` WHERE `entryorguid` =2170002 AND `source_type`=9;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=22870;


INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22870, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 36545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olums Spirit - On Just Summoned - Cast Floating Drowned'),
(22870, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 36550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olums Spirit - On Just Summoned - Cast Floating Drowned'),
(22870, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 22870, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olums Spirit - On Just Summoned - Start WP'),
(22870, 0, 3, 0, 40, 0, 100, 0, 1, 22870, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Olums Spirit - On Reached WP1 - Despawn'),

(22820, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seer Olum - On Just Summoned - Set NPC Flags'),
(22820, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 22820, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seer Olum - On Just Summoned - Start WP'),
(22820, 0, 2, 0, 40, 0, 100, 0, 2, 22820, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seer Olum - On Reached WP2 - Set Home Position'),
(22820, 0, 3, 4, 8, 0, 100, 0, 39552, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seer Olum - On Spellhit (Olums Sacrifice) - Die'),
(22820, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 22870, 1, 20000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seer Olum - On Spellhit (Olums Sacrifice) - Summon Olums Spirit'),

(22865, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 37816, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidans Presence- On Just Summoned - Cast Shadowform'),
(22865, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidans Presence- On Data Set - Play Emote OneShotExclamation (5)'),
(22865, 0, 2, 0, 38, 0, 100, 0, 2, 2, 0, 0, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Illidans Presence- On Data Set - Play Emote OneShotBattleRoar (53)'),


(21700, 0, 4, 5, 20, 0, 100, 0, 10944, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10944 rewarded - Store Targetlist'),
(21700, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2170002, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - On Quest 10944 rewarded - Run Script'),
(2170002, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Set NPC Flags'),
(2170002, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 22820, 1, 180000, 0, 0, 0, 8, 0, 0, 0, -3726.361, 1040.714, 56.03985, 5.846853, 'Akama - Script 3 - Summon Seer Olum'), -- 00:57:39.985 Number: 4250
(2170002, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 0 on Seer Olum'), -- 00:57:41.328 Number: 4268
(2170002, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 8'), -- 00:57:51.438 Number: 4412
(2170002, 9, 4, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 1 on Seer Olum'), -- 00:58:01.547 Number: 4545
(2170002, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 9'), -- 00:58:08.422 Number: 4613
(2170002, 9, 6, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 2 on Seer Olum'), -- 00:58:18.485 Number: 4746
(2170002, 9, 7, 0, 0, 0, 100, 0, 25000, 25000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 10'), -- 00:58:43.578 Number: 5020
(2170002, 9, 8, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 3 on Seer Olum'), -- 00:58:53.688 Number: 5102
(2170002, 9, 9, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 11'), -- 00:59:06.610 Number: 5239
(2170002, 9, 10, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 4 on Seer Olum'), -- 00:59:20.328 Number: 5385
(2170002, 9, 11, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 11, 39552, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Cast Olums Sacrifice'), -- 00:59:31.532 Number: 5519
(2170002, 9, 12, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 12'), -- 00:59:45.438 Number: 5726
(2170002, 9, 13, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 13'), -- 01:00:06.110 Number: 5970
(2170002, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Set Bytes 1'), 
(2170002, 9, 15, 0, 0, 0, 100, 0, 300, 300, 0, 0, 12, 22865, 1, 86000, 0, 0, 0, 8, 0, 0, 0, -3721.867, 1029.501, 56.03928, 0.03490658, 'Akama - Script 3 - Summon Illidans Presence'), -- 01:00:06.438 Number: 5980
(2170002, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 50, 185520, 86, 0, 0, 0, 0, 8, 0, 0, 0, -3721.867, 1029.501, 56.03928, 0.03490658, 'Akama - Script 3 - Summon Fel Fire (GO)'), -- 01:00:06.438 Number: 5980
(2170002, 9, 17, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 22865, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 0 on Illidans Presence'), -- 01:00:14.610 Number: 6082
(2170002, 9, 18, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 22865, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Set Data 1 1 on Illidans Presence'), -- 01:00:19.516 Number: 6135
(2170002, 9, 19, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 22820, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Despawn Seer Olum'), -- 01:00:28.000 Number: 6250
(2170002, 9, 20, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Set Bytes 1'), -- 01:00:29.219 Number: 6273
(2170002, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 14'), -- 01:00:29.328 Number: 6276
(2170002, 9, 22, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 22865, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 1 on Illidans Presence'), -- 01:00:45.110 Number: 6432
(2170002, 9, 23, 0, 0, 0, 100, 0, 23000, 23000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 22865, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 2 on Illidans Presence'), -- 01:01:08.125 Number: 6672
(2170002, 9, 24, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 22865, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Set Data 2 2 on Illidans Presence'), -- 01:01:14.125 Number: 6731
(2170002, 9, 25, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 1, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 15'), -- 01:01:31.188 Number: 6926
(2170002, 9, 26, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Akama - Script 3 - Say Line 15'); -- Set NPC Flags

DELETE FROM `creature_template_addon` WHERE `entry` IN(22870,22865);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(22870, 0, 0x0, 0x1, '36545'), -- 22870 - 36545
(22865, 0, 0x0, 0x1, '37816'); -- 22865 - 37816

DELETE FROM `waypoints` WHERE `entry` IN(22820,22870);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(22820, 1,-3724.758, 1036.542, 55.99855, 'Seer Olum'),
(22820, 2,-3723.388, 1033.147, 56.20685, 'Seer Olum'),
(22870, 1,-3718.94, 1032.773, 63.84426, 'Olums Spirit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=39552;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 39552, 0, 0, 31, 0, 3, 22820, 0, 0, 0, 0, '', 'Olums Sacrifice targets Seer Olum'),
(22, 1, 22820, 0, 0, 23, 1, 3821, 0, 0, 0, 0, 0, '', 'The Lich King - Only Run SAI in The Wardens Cage');

UPDATE `creature_template` SET `gossip_menu_id`=8564 WHERE  `entry`=22820;

DELETE FROM `gossip_menu` WHERE `entry`=8564;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8564, 10733); -- 22820
