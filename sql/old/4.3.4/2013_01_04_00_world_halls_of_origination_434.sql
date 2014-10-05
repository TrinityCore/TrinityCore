UPDATE `creature_template` SET `ScriptName`="npc_brann_bronzebeard_anraphet" WHERE `entry`=39908;
DELETE FROM `creature_text` WHERE `entry`=39908;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39908, 0,  0, 'Right, let''s go! Just need to input the final entry sequence into the door mechanism... and...', 12, 0, 100, 5, 0, 20897, 'Brann Bronzebeard'),
(39908, 1,  0, 'That did the trick! The control room should be right behind this... oh... wow...', 12, 0, 100, 5, 0, 20898, 'Brann Bronzebeard'),
(39908, 2,  0, 'What? This isn''t the control room! There''s another entire defense mechanism in place, and the blasted Rock Troggs broke into here somehow. Troggs. Why did it have to be Troggs!', 12, 0, 100, 5, 0, 20899, 'Brann Bronzebeard'),
(39908, 3,  0, 'Ok, let me think a moment.', 12, 0, 100, 1, 0, 20900, 'Brann Bronzebeard'),
(39908, 4,  0, 'Mirrors pointing all over the place.', 12, 0, 100, 25, 0, 20902, 'Brann Bronzebeard'),
(39908, 5,  0, 'Four platforms with huge elementals.', 12, 0, 100, 25, 0, 20901, 'Brann Bronzebeard'),
(39908, 6,  0, 'I got it! I saw a tablet that mentioned this chamber. This is the Vault of Lights! Ok, simple enough. I need you adventurers to take out each of the four elementals to trigger the opening sequence for the far door!', 12, 0, 100, 5, 0, 20903, 'Brann Bronzebeard'),
(39908, 7,  0, 'One down!', 14, 0, 100, 5, 0, 20904, 'Brann Bronzebeard'),
(39908, 8,  0, 'Another one down! Just look at those light beams! They seem to be connecting to the far door!', 14, 0, 100, 5, 0, 20905, 'Brann Bronzebeard'),
(39908, 9,  0, 'One more elemental to go! The door is almost open!', 14, 0, 100, 5, 0, 20906, 'Brann Bronzebeard'),
(39908, 10, 0, 'That''s it, you''ve done it! The vault door is opening! Now we can... oh, no!', 14, 0, 100, 5, 0, 20907, 'Brann Bronzebeard'),
(39908, 11, 0, 'We''ve done it! The control room is breached!', 14, 0, 100, 5, 0, 23709, 'Brann Bronzebeard'),
(39908, 12, 0, 'Here we go! Now this should only take a moment...', 14, 0, 100, 5, 0, 23710, 'Brann Bronzebeard');

UPDATE `creature_template` SET `ScriptName`="boss_anraphet" WHERE `entry`=39788;
DELETE FROM `creature_text` WHERE `entry`=39788;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39788, 0, 0, 'This unit has been activated outside normal operating protocols. Downloading new operational parameters. Download complete. Full unit self defense routines are now active. Destruction of foreign units in the system shall now commence.', 14, 0, 100, 0, 0, 20857, 'Anraphet - SAY_INTRO'),
(39788, 1, 0, 'Purge of unauthorized entities commencing.', 14, 0, 100, 0, 0, 20862, 'Anraphet - SAY_AGGRO'),
(39788, 2, 0, 'Omega Stance activated. Annihilation of foreign unit is now imminent.', 14, 0, 100, 0, 0, 20861, 'Anraphet - SAY_OMEGA_STANCE'),
(39788, 3, 0, 'Purge Complete.', 14, 0, 100, 0, 0, 20859, 'Anraphet - SAY_PLAYER_KILL'),
(39788, 3, 1, 'Target Annihilated.', 14, 0, 100, 0, 0, 20858, 'Anraphet - SAY_PLAYER_KILL'),
(39788, 4, 0, 'Anraphet unit shutting down...', 14, 0, 100, 0, 0, 20856, 'Anraphet - SAY_DEATH');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (76904,77106,77127);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76904,'spell_anraphet_alpha_beams'),
(77106,'spell_anraphet_omega_stance_summon'),
(77127,'spell_omega_stance_spider_effect');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (11339,11348,12512);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11339;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14, 11339, 15794, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Brann Bronzebeard gossip menu - Show only if DATA_VAULT_OF_LIGHTS is not done'),
(14, 11348, 15815, 0, 0, 13, 1, 18, 4, 0, 1, 0, 0, '', 'Brann Bronzebeard gossip menu - Show only if DATA_DEAD_ELEMENTALS is less than 4'),
(14, 12512, 17600, 0, 0, 13, 1, 18, 4, 0, 0, 0, 0, '', 'Brann Bronzebeard gossip menu - Show only if DATA_DEAD_ELEMENTALS is 4'),
(15, 11339, 0, 0, 0, 13, 1, 2, 3, 2, 1, 0, 0, '', 'Brann Bronzebeard gossip menu option - Show only if DATA_VAULT_OF_LIGHTS is not done');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=77437;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 6, 77437, 0, 0, 31, 0, 3, 39804, 0, 0, 0, 0, '', 'Destruction Protocol - Stone Trogg Pillager'),
(13, 6, 77437, 0, 1, 31, 0, 3, 40252, 0, 0, 0, 0, '', 'Destruction Protocol - Stone Trogg Rock Flinger'),
(13, 6, 77437, 0, 2, 31, 0, 3, 40251, 0, 0, 0, 0, '', 'Destruction Protocol - Stone Trogg Brute');

UPDATE `creature_template` SET `ScriptName`='npc_alpha_beam' WHERE `entry`=41144;
UPDATE `creature_template` SET `ScriptName`='npc_omega_stance' WHERE `entry`=41194;

DELETE FROM `spell_script_names` WHERE `spell_id`=94974;
