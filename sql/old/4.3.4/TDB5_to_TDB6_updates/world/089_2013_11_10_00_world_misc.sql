-- Creature text for Wrath-Scryer Soccothrates
SET @ENTRY = 20886;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY AND `groupid` IN (7,8,9,10);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 7, 0, 'Did you call on me?',                                      14, 0, 100, 397, 0, 11236, 'Wrath-Scryer Soccothrates - Conversation with Dalliah part 1'),
(@ENTRY, 8, 0, 'To do your heavy lifting, most likely.',                   14, 0, 100, 396, 0, 0, 'Wrath-Scryer Soccothrates - Conversation with Dalliah part 2'),
(@ENTRY, 9, 0, 'Then I''ll commit myself to ignoring you.',                 14, 0, 100, 396, 0, 0, 'Wrath-Scryer Soccothrates - Conversation with Dalliah part 3'),
(@ENTRY, 10, 0, 'You''re the one who should be-- Wait, we have company...', 14, 0, 100, 396, 0, 0, 'Wrath-Scryer Soccothrates - Conversation with Dalliah part 4');

-- Creature text for Dalliah the Doomsayer
SET @ENTRY = 20885;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY AND `groupid` IN (8,9,10);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 8, 0, 'Why would I call on you?',                                                            14, 0, 100, 396, 0, 0, 'Dalliah the Doomsayer - Conversation with Soccothrates part 1'),
(@ENTRY, 9, 0, 'When I need someone to prance around like an overstuffed peacock, I''ll call on you.', 14, 0, 100, 396, 0, 0, 'Dalliah the Doomsayer - Conversation with Soccothrates part 2'),
(@ENTRY, 10, 0, 'What would you know about commitment, sheet-sah?',                                   14, 0, 100, 396, 0, 0, 'Dalliah the Doomsayer - Conversation with Soccothrates part 3');

-- Creature text updates
UPDATE `creature_text` SET `emote`=1 WHERE `entry`=20886 AND `groupid` IN (0,5);
UPDATE `creature_text` SET `emote`=1 WHERE `entry`=20885 AND `groupid` IN (0,6);
UPDATE `creature_text` SET `emote`=66 WHERE `entry`=20886 AND `groupid` IN (6);
UPDATE `creature_text` SET `emote`=66 WHERE `entry`=20885 AND `groupid` IN (7);
UPDATE `creature_text` SET `text`= 'As masters of blood, we are masters of life and death itself. Against us, even hope falls drained and lifeless.' WHERE `entry`=29196 AND `groupid`=8;
UPDATE `creature_text` SET `comment`= 'Wrath-Scryer Soccothrates - Knock Away' WHERE `entry`=20886 AND `groupid` IN (3);

-- Add missing spelldifficulty_dbc values
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (36127,36123,36173,36144,35759,36051);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(36127,36127,39005),(36123,36123,39367), -- Zereketh the Unbound
(36173,36173,39009),(36144,36144,39013), -- Dalliah the Doomsayer
(35759,35759,39006),(36051,36051,39007); -- Wrath-Scryer Soccothrates

UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_zereketh_the_unbound' WHERE entry=20870;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_dalliah_the_doomsayer' WHERE entry=20885;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`= 'boss_wrath_scryer_soccothrates' WHERE entry=20886;
-- DELETE FROM creature_ai_scripts WHERE creature_id IN (20885,20886);
DELETE FROM smart_scripts WHERE entryorguid IN (20870);
/*
DELETE FROM creature_ai_texts WHERE entry BETWEEN -28 AND -23;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -80 AND -73;
*/
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `id`=20870;
