/* QUEST: Grim(oire) Business (10998)

	Notes: The enrage is not interruptible by the circles method (one player standing on each fire circle)
*/

SET @NPC_VIMGOL             := 22911;
SET @NPC_PENTAGRAM_BUNNY    := 23081;
SET @NPC_PENTAGRAM_RESETER  := 23040;

SET @SPELL_PENTAGRAM_VISUAL := 39921;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN  (@NPC_VIMGOL, @NPC_PENTAGRAM_RESETER, @NPC_PENTAGRAM_BUNNY);

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 13 AND SourceEntry IN (@SPELL_PENTAGRAM_VISUAL);
INSERT INTO `conditions` VALUES
(13, 0, @SPELL_PENTAGRAM_VISUAL, 0, 18, 1, @NPC_PENTAGRAM_BUNNY, 0, 0, '', 'VimGol Pentagram visual');

DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_PENTAGRAM_BUNNY*100, @NPC_VIMGOL*100) AND `source_type`=9);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_PENTAGRAM_BUNNY, @NPC_PENTAGRAM_RESETER, @NPC_VIMGOL) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_VIMGOL, 0, 1, 0, 54, 0, 100, 1, 0, 0, 0, 0, 80, @NPC_VIMGOL*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Start intro when summoned'),
(@NPC_VIMGOL, 0, 2, 0, 2, 0, 100, 1, 0, 50, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3279.97, 4640.92, 216.525, 1.69266, 'VimGol - Move to center position'),
(@NPC_VIMGOL, 0, 3, 4, 34, 0, 100, 1, 8, 0, 0, 0, 11, 40545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Cast Unholy Growht'),
(@NPC_VIMGOL, 0, 4, 7, 61, 0, 100, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Say Unhloy Growth'),
(@NPC_VIMGOL, 0, 5, 0, 8, 0, 100, 1, 40545, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Restore Combat Movement after unholy growth'),
(@NPC_VIMGOL, 0, 6, 8, 6, 0, 100, 1, 0, 0, 0, 0, 11, 39862, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Summon GO on death'),
(@NPC_VIMGOL, 0, 7, 0, 61, 0, 100, 1, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Disable combat movement'),
(@NPC_VIMGOL, 0, 8, 0, 61, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_PENTAGRAM_RESETER, 3, 500, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Summon Reseter'),
(@NPC_VIMGOL*100, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Set passive and unattackable'),
(@NPC_VIMGOL*100, 9, 2, 0, 0, 0, 100, 1, 1300, 1300, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Say Intro'),
(@NPC_VIMGOL*100, 9, 3, 0, 0, 0, 100, 1, 5000, 5000, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol - Remove OOC_NOT_ATTACKABLE flag'),
(@NPC_VIMGOL*100, 9, 4, 0, 0, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 'VimGol - Remove OOC_NOT_ATTACKABLE flag'),
(@NPC_PENTAGRAM_BUNNY, 0, 1, 0, 25, 0, 100, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Set Phase 1 on spawn'),
(@NPC_PENTAGRAM_BUNNY, 0, 2, 3, 10, 1, 100, 1, 1, 1, 0, 0, 11, @SPELL_PENTAGRAM_VISUAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Cast when a player approaches'),
(@NPC_PENTAGRAM_BUNNY, 0, 3, 0, 61, 1, 100, 1, 0, 0, 0, 0, 12, @NPC_VIMGOL, 6, 5000, 0, 0, 0, 8, 0, 0, 0, 3279.85, 4640.21, 216.527, 1.6024, 'VimGol Pentagram Bunny - Cast when a player approaches'),
(@NPC_PENTAGRAM_BUNNY, 0, 4, 5, 8, 1, 100, 1, @SPELL_PENTAGRAM_VISUAL, 0, 0, 0, 11, @SPELL_PENTAGRAM_VISUAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Chained Cast'),
(@NPC_PENTAGRAM_BUNNY, 0, 5, 0, 61, 1, 100, 1, 0, 0, 0, 0, 80, @NPC_PENTAGRAM_BUNNY*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Set Phase 2 when hitted by pentagram'),
(@NPC_PENTAGRAM_BUNNY, 0, 8, 9, 8, 2, 100, 1, @SPELL_PENTAGRAM_VISUAL, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Chained Cast'),
(@NPC_PENTAGRAM_BUNNY, 0, 9, 0, 61, 2, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Pentagram Bunny - Reset Script'),
(@NPC_PENTAGRAM_BUNNY*100, 9, 1, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ''),
(@NPC_PENTAGRAM_RESETER, 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_PENTAGRAM_VISUAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'VimGol Ring Reseter');

DELETE FROM creature_text WHERE entry IN (@NPC_VIMGOL);
INSERT INTO creature_text (entry, groupid, id, TEXT, TYPE, LANGUAGE, probability, emote, duration, sound, COMMENT) VALUES
(@NPC_VIMGOL,1,0,'żCómo osais invocarme?',14,0,100,1,0,0,'GomVil - Intro'),
(@NPC_VIMGOL,2,0,'ˇAhora yo crecer y machacaros!',14,0,100,1,0,0,'GomVil - Enrage');
/*(@NPC_VIMGOL,1,0,'You dare summon me?',14,0,100,1,0,0,'GomVil - Intro'),
(@NPC_VIMGOL,2,0,'Now me grow bigger and crush you!',14,0,100,1,0,0,'GomVil - Enrage');*/

/* QUEST: Into the Soulgrinder
*/

SET @NPC_SOULGINDER_HANDLER       := 23019;
SET @NPC_SOULGRINDER_RITUAL_BUNNY := 23037;
SET @NPC_SHUNDERED_GHOST          := 24039;
SET @NPC_SKULLOC                  := 22910;

SET @SPELL_SOULGRINDER_VISUAL     := 39918;
SET @SPELL_SOULGRINDER_BEAM       := 39920;
SET @SPELL_SOULGRINDER_BUNNY      := 39936;

SET @SPELL_SUMMON_OGRE_GHOST      := 39620;
SET @SPELL_OGRE_TANSFORM          := 39916;
SET @SPELL_OGRE_SHADOW_BOLT       := 20816;
SET @SPELL_OGRE_CRIPPLE           := 11443;

SET @SPELL_SKULLOC_SHADOWFORM     := 39944;
SET @SPELL_SKULLOC_CORRUPTION     := 39621;
SET @SPELL_SKULLOC_BANISH         := 39622;
SET @SPELL_SKULLOC_SUMMON_CHEST   := 39909;

SET @SPELL_GENERAL_TRIGGER        := 56685;

-- Despawn existant Skulloc soul
DELETE FROM `gameobject` WHERE `id`=185577;

-- Summon The Soulgrinder when the player casts Vim'Gol Cantation
DELETE FROM `event_scripts` WHERE `id` = 14739;
INSERT INTO `event_scripts` VALUES
(14739, 0, 10, @NPC_SOULGINDER_HANDLER, 500000, 0, 3534.92, 5590.75, 0.17575, 3.7700);

UPDATE `creature_template` SET `flags_extra` = 130 WHERE `entry` IN  (@NPC_SOULGINDER_HANDLER, @NPC_SOULGRINDER_RITUAL_BUNNY);
UPDATE `creature_template` SET `faction_A` = 16, `faction_H` = 16 WHERE `entry` IN  (@NPC_SOULGINDER_HANDLER, @NPC_SKULLOC, @NPC_SHUNDERED_GHOST);
UPDATE `creature_template` SET `unit_flags` = 256 WHERE `entry` = @NPC_SKULLOC;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC_SOULGINDER_HANDLER, @NPC_SOULGRINDER_RITUAL_BUNNY, @NPC_SHUNDERED_GHOST, @NPC_SKULLOC);

DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_SOULGINDER_HANDLER, @NPC_SOULGRINDER_RITUAL_BUNNY, @NPC_SHUNDERED_GHOST, @NPC_SKULLOC) AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC_SOULGINDER_HANDLER*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_SOULGINDER_HANDLER, 0, 1, 2, 25, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_SOULGRINDER_VISUAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soulgrinder -  Visual disc'),
(@NPC_SOULGINDER_HANDLER, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 80, @NPC_SOULGINDER_HANDLER*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soulgrinder -  Call beams timed list'),
(@NPC_SOULGINDER_HANDLER, 0, 3, 0, 8, 0, 100, 1, @SPELL_GENERAL_TRIGGER, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soulgrinder -  Despawn trigger recived'),
(@NPC_SOULGINDER_HANDLER*100, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_SKULLOC, 8, 0, 0, 0, 0, 8, 0, 0, 0, 3483.65, 5553.48, 7.52039, 0.506145, 'Soulgrinder - Summon Skulloc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 1, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 2, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 3, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 4, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 5, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 6, 0, 0, 0, 100, 1, 1000, 3000, 0, 0, 12, @NPC_SOULGRINDER_RITUAL_BUNNY, 8, 0, 0, 0, 0, 8, 0, 0, 0, 3491.73, 5529.07, 17.4812, 1.08968, 'Soulgrinder - Summon beam 1'),
(@NPC_SOULGINDER_HANDLER*100, 9, 7, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 8, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 9, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 10, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 11, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 12, 0, 0, 0, 100, 1, 1000, 3000, 0, 0, 12, @NPC_SOULGRINDER_RITUAL_BUNNY, 8, 0, 0, 0, 0, 8, 0, 0, 0, 3464.63, 5564.68, 17.8395, 0.134638, 'Soulgrinder - Summon beam 2'),
(@NPC_SOULGINDER_HANDLER*100, 9, 13, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 14, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 15, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 16, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 17, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 18, 0, 0, 0, 100, 1, 1000, 3000, 0, 0, 12, @NPC_SOULGRINDER_RITUAL_BUNNY, 8, 0, 0, 0, 0, 8, 0, 0, 0, 3514.26, 5524.18, 17.0851, 0.134638, 'Soulgrinder - Summon beam 3'),
(@NPC_SOULGINDER_HANDLER*100, 9, 19, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 20, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 21, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 22, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 23, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 24, 0, 0, 0, 100, 1, 1000, 3000, 0, 0, 12, @NPC_SOULGRINDER_RITUAL_BUNNY, 8, 0, 0, 0, 0, 8, 0, 0, 0, 3469.4, 5580.96, 18.4037, 0.134638, 'Soulgrinder - Summon beam 3'),
(@NPC_SOULGINDER_HANDLER*100, 9, 25, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 26, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 27, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 28, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 29, 0, 0, 0, 100, 1, 7000, 7000, 0, 0, 11, @SPELL_SUMMON_OGRE_GHOST, 8, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Cast Summon Orc'),
(@NPC_SOULGINDER_HANDLER*100, 9, 30, 0, 0, 0, 100, 1, 1000, 3000, 0, 0, 28, @SPELL_SOULGRINDER_BEAM, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soulgrinder - Remove any beam on me'),
(@NPC_SOULGINDER_HANDLER*100, 9, 31, 0, 0, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_SOULGRINDER_BEAM, 8, 0, 0, 0, 0, 11, @NPC_SKULLOC, 100, 0, 0, 0, 0, 0, 'Soulgrinder - Cast beam on Skulloc'),
(@NPC_SOULGRINDER_RITUAL_BUNNY, 0, 1, 0, 25, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_SOULGRINDER_BUNNY, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Soulgrinder Ritual bunny - Cast visual on self'),
(@NPC_SOULGRINDER_RITUAL_BUNNY, 0, 2, 0, 1, 0, 100, 1, 500, 500, 0, 0, 11, @SPELL_SOULGRINDER_BEAM, 3, 0, 0, 0, 0, 11, @NPC_SOULGINDER_HANDLER, 100, 0, 0, 0, 0, 0, 'Soulgrinder Ritual bunny - Cast beam to Soulgrinder'),
(@NPC_SHUNDERED_GHOST, 0, 1, 2, 25, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_OGRE_TANSFORM, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sundered Ghost - Cast transform on spawn'),
(@NPC_SHUNDERED_GHOST, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Sundered Ghost - Aggro on spawn'),
(@NPC_SHUNDERED_GHOST, 0, 3, 0, 0, 0, 100, 0, 0, 500, 3000, 3500, 11, @SPELL_OGRE_SHADOW_BOLT, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sundered Ghost - Cast Shadown Bolt'),
(@NPC_SHUNDERED_GHOST, 0, 4, 0, 0, 0, 65, 0, 3000, 6000, 5000, 8000, 11, @SPELL_OGRE_CRIPPLE, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Sundered Ghost - Cast Cripple'),
(@NPC_SHUNDERED_GHOST, 0, 5, 0, 21, 0, 65, 0, 0, 0, 0, 0, 11, @SPELL_GENERAL_TRIGGER, 0, 0, 0, 0, 0, 11, @NPC_SOULGINDER_HANDLER , 100, 0, 0, 0, 0, 0, 'Sundered Ghost - Cast Despawn Trigger on Soulgrinder'),
(@NPC_SHUNDERED_GHOST, 0, 6, 0, 1, 0, 100, 1, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sundered Ghost - Despawn after evading'),
(@NPC_SKULLOC, 0, 1, 0, 0, 0, 100, 0, 1000, 3000, 18000, 25000, 11, @SPELL_SKULLOC_BANISH, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Cast Banish'),
(@NPC_SKULLOC, 0, 2, 0, 0, 0, 100, 0, 0, 1000, 3000, 7000, 11, @SPELL_SKULLOC_CORRUPTION, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Cast Banish'),
(@NPC_SKULLOC, 0, 3, 0, 8, 0, 100, 1, @SPELL_SOULGRINDER_BEAM, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Set reactive when hited by beam'),
(@NPC_SKULLOC, 0, 4, 0, 25, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_SKULLOC_SHADOWFORM, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Add Shadowform on spawn'),
(@NPC_SKULLOC, 0, 5, 6, 4, 0, 100, 1, 0, 0, 0, 0, 28, @SPELL_SOULGRINDER_BEAM, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Remove beam on aggro'),
(@NPC_SKULLOC, 0, 6, 7, 61, 0, 100, 1, 0, 0, 0, 0, 28, @SPELL_SKULLOC_SHADOWFORM, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Remove shadowform on aggro'),
(@NPC_SKULLOC, 0, 7, 0, 61, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_GENERAL_TRIGGER, 0, 0, 0, 0, 0, 11, @NPC_SOULGINDER_HANDLER, 100, 0, 0, 0, 0, 0, 'Skulloc - Cast despawn trigger on Soulgrinder on aggro'),
(@NPC_SKULLOC, 0, 8, 0, 21, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Despawn on evade'),
(@NPC_SKULLOC, 0, 9, 0, 6, 0, 100, 1, 0, 0, 0, 0, 11, @SPELL_SKULLOC_SUMMON_CHEST, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skulloc - Summon chest on death');


/* QUEST: Ogre heaven

    It should be aviable after completing Into the soulgrinder
*/
UPDATE `quest_template` SET `PrevQuestId` = 11000 WHERE `Id` = 11009;