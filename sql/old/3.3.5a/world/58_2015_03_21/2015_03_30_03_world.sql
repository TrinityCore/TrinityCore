SET @JAINA         := 38606;
SET @MURADIN       := 38607;
SET @UTHER         := 38608;
SET @SYLVANAS      := 38609;
SET @DARION        := 37120;
SET @ALEXANDROS    := 38610;
SET @JAINAQUEST    := 24916;
SET @MURADINQUEST  := 24917;
SET @UTHERQUEST    := 24919;
SET @SYLVANASQUEST := 24918;
SET @DARIONQUEST   := 24915;

UPDATE `creature_template` SET `gossip_menu_id`=11065, `npcflag`=3, `speed_run`=1, `unit_class`=8, `unit_flags`=33088, `unit_flags2`=2099200, `AIName`='SmartAI' WHERE `entry`=@JAINA;
UPDATE `creature_template` SET `npcflag`=2, `speed_run`=1.714286, `unit_flags`=33600, `AIName`='SmartAI' WHERE `entry`=@MURADIN;
UPDATE `creature_template` SET `npcflag`=2, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200, `AIName`='SmartAI' WHERE `entry`=@UTHER;
UPDATE `creature_template` SET `npcflag`=2, `speed_walk`=0.888888, `speed_run`=0.9920629, `unit_class`=2, `unit_flags`=33088, `unit_flags2`=2099200, `AIName`='SmartAI' WHERE `entry`=@SYLVANAS;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ALEXANDROS;

UPDATE `quest_template` SET `OfferRewardText`='Impossible...$B$BFather, is it you?!$B$BYou have done me a great service, hero. I offer you the reins of my faithful steed. Do with it as you please, but do not forget those that assisted you in this monumental feat.', `RequestItemsText`='What is that you hold, $c?$B$BIt calls out to me, stirring feelings I thought to be long dead.' WHERE `Id`=@DARIONQUEST;
UPDATE `quest_template` SET `OfferRewardText`='What... how did you manage to come by this!?$B$BYou have done me a great service, hero. My heart could not bear to keep this locket, but I will place an enchantment upon it that you may find useful. Do with it as you please, but do not forget those that assisted you in this monumental feat.', `RequestItemsText`='Yes, $c? How can I assist you?' WHERE `Id`=@JAINAQUEST;
UPDATE `quest_template` SET `OfferRewardText`='Aye. I know this blade... and I will treasure it always - a moment of time that will be lost forever.$B$BYou have done me a great service, hero. I offer you a gift from the Frostborn dwarves. Do with it as you please, but do not forget those that assisted you in this monumental feat.', `RequestItemsText`='Whatdya got there, $r?' WHERE  `Id`=@MURADINQUEST;
UPDATE `quest_template` SET `OfferRewardText`='<Sylvanas silently reflects for a moment before returning her gaze to you.>$B$BYou have done me a great service, hero. I offer you the boon of the Banshee Queen. Do with it as you please, but do not forget those that assisted you in this monumental feat.', `RequestItemsText`='What is it, $r?' WHERE `Id`=@SYLVANASQUEST;
UPDATE `quest_template` SET `OfferRewardText`='<Uther stares at the medal, speechless for a moment.>$B$BArthas'' medal.$B$BI remember well the day I presented it to him...$B$BYou have done me a great service, hero. My soul may now rest in peace. I offer you a memory lost in time. Do with it as you please, but do not forget those that assisted you in this monumental feat.', `RequestItemsText`='How may I be of service, $r?' WHERE `Id`=@UTHERQUEST;

UPDATE `creature_queststarter` SET `id`=@JAINA WHERE `id`=37120 AND `quest`=24916;
UPDATE `creature_queststarter` SET `id`=@MURADIN WHERE `id`=37120 AND `quest`=24917;
UPDATE `creature_queststarter` SET `id`=@UTHER WHERE `id`=37120 AND `quest`=24919;
UPDATE `creature_queststarter` SET `id`=@SYLVANAS WHERE `id`=37120 AND `quest`=24918;

UPDATE `creature_questender` SET `id`=@JAINA WHERE `id`=37120 AND `quest`=24916;
UPDATE `creature_questender` SET `id`=@MURADIN WHERE `id`=37120 AND `quest`=24917;
UPDATE `creature_questender` SET `id`=@UTHER WHERE `id`=37120 AND `quest`=24919;
UPDATE `creature_questender` SET `id`=@SYLVANAS WHERE `id`=37120 AND `quest`=24918;

DELETE FROM `spell_target_position` WHERE `ID`=72468;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES 
(72468, 0, 631, -66.8684, 2158.28, 30.73743, 3.893452, 17658);

DELETE FROM `gossip_menu` WHERE `entry`=11065 AND `text_id`=15382;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(11065, 15382);

DELETE FROM `npc_text` WHERE `ID`=15382;
INSERT INTO `npc_text` (`ID`, `text0_1`, `BroadcastTextID0`, `prob0`, `text1_1`, `BroadcastTextID1`, `prob1`, `VerifiedBuild`) VALUES 
(15382, 'He''s truly gone, isn''t he?$b$bI... I can feel it.', 38510, 1, 'Was there truly no way to save him?$b$bI fear I shall always wonder.', 38511, 1, 19342);

DELETE FROM `creature_text` WHERE `entry` IN (@JAINA,@MURADIN,@UTHER,@SYLVANAS,@ALEXANDROS);
DELETE FROM `creature_text` WHERE `entry`=@DARION AND `groupid` IN (4,5,6);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(@JAINA, 0, 0, 'What''s this!?', 12, 0, 100, 5, 0, 17383, 38201, 'Lady Jaina Proudmoore to Player'),
(@JAINA, 1, 0, 'He... he kept it? All this time, he kept it!?', 12, 0, 100, 5, 0, 17384, 38202, 'Lady Jaina Proudmoore'),
(@JAINA, 2, 0, 'I knew! ', 12, 0, 100, 5, 0, 17385, 38203, 'Lady Jaina Proudmoore'),
(@JAINA, 3, 0, 'I sensed a part of him still alive! Trapped... struggling... Oh, Arthas!', 12, 0, 100, 396, 0, 17386, 38204, 'Lady Jaina Proudmoore'),
(@JAINA, 4, 0, 'Perhaps - perhaps he might someday remember what he once was.', 12, 0, 100, 396, 0, 17387, 38205, 'Lady Jaina Proudmoore'),
(@JAINA, 5, 0, 'By the Light, may he at last find rest, free from the icy grip of that terrible blade.', 12, 0, 100, 396, 0, 17388, 38206, 'Lady Jaina Proudmoore'),
(@MURADIN, 0, 0, 'Oh, lad...', 12, 0, 100, 396, 0, 17421, 38171, 'Muradin Bronzebeard'),
(@MURADIN, 1, 0, 'How I miss those endless days in Lordaeron...', 12, 0, 100, 396, 0, 17422, 38172, 'Muradin Bronzebeard'),
(@MURADIN, 2, 0, '...sharpenin'' yer skill with this dull blade...', 12, 0, 100, 396, 0, 17423, 38173, 'Muradin Bronzebeard'),
(@MURADIN, 3, 0, '...forgin'' ya into a weapon meant to withstand the demands of a great destiny.', 12, 0, 100, 396, 0, 17424, 38174, 'Muradin Bronzebeard'),
(@MURADIN, 4, 0, 'Heh... Yeh sure put them skills ta use, didn''t yeh, lad?', 12, 0, 100, 6, 0, 17425, 38175, 'Muradin Bronzebeard'),
(@MURADIN, 5, 0, 'If only I''da been able ta stop yeh that day, how different things mighta been.', 12, 0, 100, 396, 0, 17426, 38176, 'Muradin Bronzebeard'),
(@MURADIN, 6, 0, 'If only I''da never discovered that accursed blade...', 12, 0, 100, 396, 0, 17427, 38177, 'Muradin Bronzebeard'),
(@MURADIN, 7, 0, 'Farewell, Arthas... my brother.', 12, 0, 100, 396, 0, 17428, 38178, 'Muradin Bronzebeard'),
(@UTHER, 0, 0, 'Arthas...', 12, 0, 100, 396, 0, 17402, 38160, 'Uther the Lightbringer'),
(@UTHER, 1, 0, 'Alas, hero of Azeroth, you give me a greater gift than you know.', 12, 0, 100, 396, 0, 17403, 38161, 'Uther the Lightbringer'),
(@UTHER, 2, 0, 'Long have I struggled to forgive the prince for his terrible transgressions.', 12, 0, 100, 396, 0, 17404, 38162, 'Uther the Lightbringer'),
(@UTHER, 3, 0, 'My soul has been wracked with unbearable anxiety, dark thoughts... distancing me from the Light.', 12, 0, 100, 396, 0, 17405, 38163, 'Uther the Lightbringer'),
(@UTHER, 4, 0, 'I recall clearly the gleam of pride in his eye as he stood before me, eager to defeat the enemies of the Light...', 12, 0, 100, 396, 0, 17406, 38165, 'Uther the Lightbringer'),
(@UTHER, 5, 0, 'Eager to defend his people, no matter the cost.', 12, 0, 100, 396, 0, 17407, 38166, 'Uther the Lightbringer'),
(@UTHER, 6, 0, 'It is this memory of Arthas that I choose to keep in my heart.', 12, 0, 100, 396, 0, 17408, 38167, 'Uther the Lightbringer'),
(@UTHER, 7, 0, 'I shall always be in your debt, friend.', 12, 0, 100, 396, 0, 17409, 38168, 'Uther the Lightbringer'),
(@UTHER, 8, 0, 'Thank you.', 12, 0, 100, 0, 0, 17410, 38169, 'Uther the Lightbringer'),
(@SYLVANAS, 0, 0, 'So, it is done.', 12, 0, 100, 396, 0, 17376, 38179, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 1, 0, 'I had not dared to trust my senses - too many times has the Lich King made me to be a fool.', 12, 0, 100, 396, 0, 17377, 38180, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 2, 0, 'Finally, he has been made to pay for the atrocities he imposed upon my people.', 12, 0, 100, 396, 0, 17378, 38181, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 3, 0, 'May Azeroth never fail to remember the terrible price we paid for our weakness... for our pride.', 12, 0, 100, 396, 0, 17379, 38183, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 4, 0, 'But what now, hero? What of those freed from his grasp, but still shackled to their mortal coils?', 12, 0, 100, 6, 0, 17380, 38184, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 5, 0, 'Leave me. ', 12, 0, 100, 396, 0, 17381, 38185, 'Lady Sylvanas Windrunner'),
(@SYLVANAS, 6, 0, 'I have much to ponder.', 12, 0, 100, 396, 0, 17382, 38186, 'Lady Sylvanas Windrunner'),
(@ALEXANDROS, 0, 0, 'Darion, my son.', 12, 0, 100, 396, 0, 17414, 38152, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 1, 0, 'At last, I am able to lay my eyes upon you again.', 12, 0, 100, 396, 0, 17415, 38153, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 2, 0, 'The Lich King tormented me without end, Darion.', 12, 0, 100, 396, 0, 17416, 38154, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 3, 0, 'Endlessly, he sought to break my will, to force me to serve him, to bind me to his blade...', 12, 0, 100, 396, 0, 17417, 38155, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 4, 0, 'Finally, when events demanded his full attention, he left me.', 12, 0, 100, 396, 0, 17418, 38156, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 5, 0, 'The one memory, I clung to, Darion... The one thought that kept me from giving in...', 12, 0, 100, 396, 0, 17419, 38157, 'Highlord Alexandros Mograine'),
(@ALEXANDROS, 6, 0, 'It was your sacrifice, my son, that again saved me from eternal peril.', 12, 0, 100, 396, 0, 17420, 38158, 'Highlord Alexandros Mograine'),
(@DARION, 4, 0, 'Father...', 12, 0, 100, 396, 0, 17411, 38143, 'Highlord Darion Mograine'),
(@DARION, 5, 0, 'Father. I feared for your... your sanity.', 12, 0, 100, 396, 0, 17412, 38150, 'Highlord Darion Mograine'),
(@DARION, 6, 0, 'Father... For you, I would give my life a thousand times.', 12, 0, 100, 396, 0, 17413, 38151, 'Highlord Darion Mograine');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@JAINA, @JAINA*100, @MURADIN, @MURADIN*100, @UTHER, @UTHER*100, @SYLVANAS, @SYLVANAS*100, @DARION*100+1, @ALEXANDROS) AND `source_type` IN (0,9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DARION AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@JAINA, 0, 0, 0, 20, 0, 100, 0, @JAINAQUEST, 0, 0, 0, 80, @JAINA*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Quest ''Jaina''s Locket'' Finished - Run Script'),
(@JAINA*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Remove NPC Flags'),
(@JAINA*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Remove NPC Flags'),
(@JAINA*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Remove NPC Flags'),
(@JAINA*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Remove NPC Flags'),
(@JAINA*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Remove NPC Flags'),
(@JAINA*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 0'),
(@JAINA*100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 1'),
(@JAINA*100, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 2'),
(@JAINA*100, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 3'),
(@JAINA*100, 9, 9, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 4'),
(@JAINA*100, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Say Line 5'),
(@JAINA*100, 9, 11, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Restore NPC Flags'),
(@JAINA*100, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Restore NPC Flags'),
(@JAINA*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Restore NPC Flags'),
(@JAINA*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Restore NPC Flags'),
(@JAINA*100, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Script - Restore NPC Flags'),
(@MURADIN, 0, 0, 0, 20, 0, 100, 0, @MURADINQUEST, 0, 0, 0, 80, @MURADIN*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Quest ''Muradin''s Lament'' Finished - Run Script'),
(@MURADIN*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Remove NPC Flags'),
(@MURADIN*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Remove NPC Flags'),
(@MURADIN*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Remove NPC Flags'),
(@MURADIN*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Remove NPC Flags'),
(@MURADIN*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Remove NPC Flags'),
(@MURADIN*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 0'),
(@MURADIN*100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 1'),
(@MURADIN*100, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 2'),
(@MURADIN*100, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 3'),
(@MURADIN*100, 9, 9, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 4'),
(@MURADIN*100, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 5'),
(@MURADIN*100, 9, 11, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 6'),
(@MURADIN*100, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Say Line 7'),
(@MURADIN*100, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Restore NPC Flags'),
(@MURADIN*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Restore NPC Flags'),
(@MURADIN*100, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Restore NPC Flags'),
(@MURADIN*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Restore NPC Flags'),
(@MURADIN*100, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Muradin Bronzebeard - On Script - Restore NPC Flags'),
(@UTHER, 0, 0, 0, 20, 0, 100, 0, @UTHERQUEST, 0, 0, 0, 80, @UTHER*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Quest ''The Lightbringer''s Redemption'' Finished - Run Script'),
(@UTHER*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Remove NPC Flags'),
(@UTHER*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Remove NPC Flags'),
(@UTHER*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Remove NPC Flags'),
(@UTHER*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Remove NPC Flags'),
(@UTHER*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Remove NPC Flags'),
(@UTHER*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 0'),
(@UTHER*100, 9, 6, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 1'),
(@UTHER*100, 9, 7, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 2'),
(@UTHER*100, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 3'),
(@UTHER*100, 9, 9, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 4'),
(@UTHER*100, 9, 10, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 5'),
(@UTHER*100, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 6'),
(@UTHER*100, 9, 12, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 7'),
(@UTHER*100, 9, 13, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Say Line 8'),
(@UTHER*100, 9, 14, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Restore NPC Flags'),
(@UTHER*100, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Restore NPC Flags'),
(@UTHER*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Restore NPC Flags'),
(@UTHER*100, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Restore NPC Flags'),
(@UTHER*100, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Uther the Lightbringer - On Script - Restore NPC Flags'),
(@SYLVANAS, 0, 0, 0, 20, 0, 100, 0, @SYLVANASQUEST, 0, 0, 0, 80, @SYLVANAS*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Quest ''Sylvanas'' Vengeance'' Finished - Run Script'),
(@SYLVANAS*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Remove NPC Flags'),
(@SYLVANAS*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Remove NPC Flags'),
(@SYLVANAS*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Remove NPC Flags'),
(@SYLVANAS*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Remove NPC Flags'),
(@SYLVANAS*100, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Remove NPC Flags'),
(@SYLVANAS*100, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 0'),
(@SYLVANAS*100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 1'),
(@SYLVANAS*100, 9, 7, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 2'),
(@SYLVANAS*100, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 3'),
(@SYLVANAS*100, 9, 9, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 4'),
(@SYLVANAS*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 5'),
(@SYLVANAS*100, 9, 11, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Say Line 6'),
(@SYLVANAS*100, 9, 12, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Restore NPC Flags'),
(@SYLVANAS*100, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Restore NPC Flags'),
(@SYLVANAS*100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Restore NPC Flags'),
(@SYLVANAS*100, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Restore NPC Flags'),
(@SYLVANAS*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @DARION, 0, 10, 0, 0, 0, 0, 'Lady Sylvanas Windrunner - On Script - Restore NPC Flags'),
(@DARION, 0, 7, 0, 20, 0, 100, 0, @DARIONQUEST, 0, 0, 0, 80, @DARION*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Quest ''Mograine''s Reunion'' Finished - Run Script'),
(@DARION*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Remove NPC Flags'),
(@DARION*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Remove NPC Flags'),
(@DARION*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Remove NPC Flags'),
(@DARION*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Remove NPC Flags'),
(@DARION*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Remove NPC Flags'),
(@DARION*100+1, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Play Emote 432'),
(@DARION*100+1, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 72468, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Cast ''Summon Alexandros'''),
(@DARION*100+1, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @ALEXANDROS, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Set Orientation Closest Creature ''Highlord Alexandros Mograine'''),
(@DARION*100+1, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 4'),
(@DARION*100+1, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 0'),
(@DARION*100+1, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 1'),
(@DARION*100+1, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 5'),
(@DARION*100+1, 9, 12, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 2'),
(@DARION*100+1, 9, 13, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 3'),
(@DARION*100+1, 9, 14, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 4'),
(@DARION*100+1, 9, 15, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 5'),
(@DARION*100+1, 9, 16, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 9, @ALEXANDROS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 6'),
(@DARION*100+1, 9, 17, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Say Line 6'),
(@DARION*100+1, 9, 18, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Set Orientation Home Position'),
(@DARION*100+1, 9, 19, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @ALEXANDROS, 10, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Despawn Highlord Alexandros'),
(@DARION*100+1, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Restore NPC Flags'),
(@DARION*100+1, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 9, @JAINA, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Restore NPC Flags'),
(@DARION*100+1, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @MURADIN, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Restore NPC Flags'),
(@DARION*100+1, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @UTHER, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Restore NPC Flags'),
(@DARION*100+1, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 9, @SYLVANAS, 0, 10, 0, 0, 0, 0, 'Highlord Darion Mograine - On Script - Restore NPC Flags'),
(@ALEXANDROS, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 72469, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Highlord Alexandros Mograine - Out of Combat - Cast ''Alexandros Spawn''');
