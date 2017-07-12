--
DELETE FROM `quest_template_addon` WHERE `ID`=11272;
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(11272, 11234);

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry` IN (24041, 24044);

DELETE FROM `creature_text` WHERE `entry`=23780;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23780, 0, 0, "Archers at the ready!  Hold your fire!", 14, 0, 100, 0, 0, 0, 22662, 0, "High Executor Anselm"),
(23780, 1, 0, "What fool dares to enter her majesty's dominion unannounced?", 14, 0, 100, 0, 0, 0, 22663, 0, "High Executor Anselm"),
(23780, 2, 0, "Is that all you've come to say?", 12, 0, 100, 0, 0, 0, 22686, 0, "High Executor Anselm"),
(23780, 3, 0, "Send these scumbags back to hell!  Fire at will!", 14, 0, 100, 0, 0, 0, 22687, 0, "High Executor Anselm");

DELETE FROM `creature_text` WHERE `entry`=24041;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24041, 0, 0, "Ah, but it is you who intrudes on our master's territory.  He could wipe you out in an instant for that transgression alone!  Arthas does not have much love or patience for his escaped slaves.", 12, 0, 100, 0, 0, 0, 22665, 0, "Prince Keleseth"),
(24041, 1, 0, "But... he has learned of your victory over Stormwind's North Fleet and thinks you have potential.  Potential to see reason and abandon Sylvanas' childish rebellion.", 12, 0, 100, 0, 0, 0, 22669, 0, "Prince Keleseth"),
(24041, 2, 0, "Arthas is prepared to offer you power beyond your imagination.  The puny army you lead here would pale in comparison to the phalanxes at your command if you returned to the Scourge's embrace.", 12, 0, 100, 0, 0, 0, 22671, 0, "Prince Keleseth"),
(24041, 3, 0, "Behold the Vrykul!   A race that has perfected war and destruction to the point of an art form.  Already they've cast their lot with the Lich King!  Their dwellings surround you and their numbers are easily five times yours.", 12, 0, 100, 0, 0, 0, 22722, 0, "Prince Keleseth"),
(24041, 4, 0, "The choice is yours, Anselm.  Return to the Lich King's army and fight alongside them or remain loyal to your so-called queen and suffer their wrath as they drive you from their homelands!", 12, 0, 100, 0, 0, 0, 22723, 0, "Prince Keleseth"),
(24041, 5, 0, "Such a futile gesture.", 12, 0, 100, 0, 0, 0, 22758, 0, "Prince Keleseth"),
(24041, 6, 0, "Listen to your men's dying breaths as I drink in their souls!", 12, 0, 100, 0, 0, 0, 22766, 0, "Prince Keleseth"),
(24041, 7, 0, "This will not be the last you hear of me.  I will return to spit on your corpse after Utgarde's armies have descended upon you!", 12, 0, 100, 0, 0, 0, 22764, 0, "Prince Keleseth");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2378000;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2378000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 1"),
(2378000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 1"),
(2378000, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0"),
(2378000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 107, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Summon Group 2"),
(2378000, 9, 4, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1"),
(2378000, 9, 5, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 0 (Prince Keleseth)"),
(2378000, 9, 6, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 1 (Prince Keleseth)"),
(2378000, 9, 7, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2 (Prince Keleseth)"),
(2378000, 9, 8, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 3 (Prince Keleseth)"),
(2378000, 9, 9, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 4 (Prince Keleseth)"),
(2378000, 9, 10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 11, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 12, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 2"),
(2378000, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say 5 (Prince Keleseth)"),
(2378000, 9, 15, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Winterskorn Guard"),
(2378000, 9, 16, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 17, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Data on Forsaken Crossbow Man"),
(2378000, 9, 18, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 19, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 20, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Say"),
(2378000, 9, 21, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Set Phase 2"),
(2378000, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 24041, 0, 0, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Prince Keleseth"),
(2378000, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 24044, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Winterskorn Guard"),
(2378000, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 9, 23883, 0, 200, 0, 0, 0, 0, "High Executor Anselm - On Script - Despawn Forsaken Crossbow Man");

UPDATE `creature_summon_groups` SET `summonTime`=152000 WHERE `summonerId`=23780;
