--
SET @Valdred   :=   49231;  
SET @Marshal   :=   49230; 
SET @Lilian    :=   38895;  
SET @Caice     :=   2307;
SET @Valdred2   :=   66168;  
SET @Marshal2   :=   66167; 
SET @Lilian2    :=   66166;  

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Valdred2, @Marshal2, @Lilian2);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Valdred, @Marshal, @Lilian, @Valdred2, @Marshal2, @Lilian2, @Caice, 49340)  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Valdred*100, @Marshal*100, @Lilian*100, @Valdred2*100, @Marshal2*100, @Lilian2*100, @Caice*100, 4934000)  AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Caice, 0, 0, 0, 19, 0, 100, 0, 24960, 0, 0, 0, 80, @Caice*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Caice - On quest accpet - Actionlist'),
(@Caice*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Valdred, 3, 120000, 0, 0, 0, 8, 0, 0, 0, 1740.36, 1704.34, 128.765, 1.552963, 'Caice - Actionlist - cast spell'),
(@Caice*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Lilian, 3, 120000, 0, 0, 0, 8, 0, 0, 0, 1757.48, 1666.03, 121.208, 0.029290, 'Caice - Actionlist - Cast spell'),
(@Caice*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Marshal, 3, 120000, 0, 0, 0, 8, 0, 0, 0, 1753.89, 1640.63, 117.495, 0, 'Caice - Actionlist - Cast spell'),
(@Caice, 0, 1, 0, 19, 0, 100, 0, 25089, 0, 0, 0, 85, 91938, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caice - On Quest Accept - Cast Spell To Summon'),
(@Valdred, 0, 0, 0, 62, 0, 100, 0, 12489, 0, 0, 0, 80, @Valdred*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - On Gossip Select - Actionlist'),
(@Valdred*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Close gossip'),
(@Valdred*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 91876, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Cast summon Valdred'),
(@Valdred*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - despawn'),
(@Valdred, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - On Just summoned - add aura state kneels'),
(@Valdred2, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Valdred2*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - On Gossip Select - Actionlist'),
(@Valdred2*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Talk1'),
(@Valdred2*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1689.709961, 1674.790039, 135.675003, 0.349066, 'Valdred - Action list - Go to point'),
(@Valdred2*100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Talk2'),
(@Valdred2*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valdred - Actionlist - Despawn'),
(@Marshal, 0, 0, 0, 62, 0, 100, 0, 12486, 0, 0, 0, 80, @Marshal*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - On Gossip Select - Actionlist'),
(@Marshal*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Close gossip'),
(@Marshal*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 91873, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Cast summon Marshal'),
(@Marshal*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - despawn'),
(@Marshal2, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Marshal2*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - On Gossip Select - Actionlist'),
(@Marshal2*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Talk1'),
(@Marshal2*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1753.036621, 1613.100586, 113.051300, 2.014602, 'Marshal - Action list - Go to point'),
(@Marshal2*100, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Marshal - Actionlist - Despawn'),
(@Lilian, 0, 0, 0, 62, 0, 100, 0, 12484, 0, 0, 0, 80, @Lilian*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Gossip Select - Actionlist'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Close gossip'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 91874, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Cast summon Lilian'),
(@Lilian*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - despawn'),
(@Lilian, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On spawn - set emote state'),
(@Lilian2, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Lilian2*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Gossip Select - Actionlist'),
(@Lilian2*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Talk1'),
(@Lilian2*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1727.873535, 1629.106567, 118.862335, 5.497842, 'Lilian - Action list - Go to point'),
(@Lilian2*100, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Despawn'),
(49340, 0, 0, 1, 75, 0, 100, 1, 0, 49337, 3, 0, 86, 91945, 2, 19, 49337, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Corpse - On DISTANCE_CREATURE - cross cast'),
(49340, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 2, 0, 0, 0, 0, 19, 49337, 20, 0, 0, 0, 0, 0, 'Corpse - On DISTANCE_CREATURE - cast');

DELETE FROM `creature_text` WHERE `entry` IN (@Valdred, @Marshal, @Lilian, @Valdred2, @Marshal2, @Lilian2);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Valdred2, 0, 0, 'I see. Well then, let''s get to work, $n! The Dark Lady needs us, right?', 12, 0, 100, 1, 0, 0, 'Valdred', 49351),
(@Valdred2, 1, 0, 'Valdred Moray, reporting for duty, sir!', 14, 0, 100, 1, 0, 0, 'Valdred', 49408),
(@Marshal2, 0, 0, 'Who are you calling a monster? You''re the monster! I''m just a man who died.', 12, 0, 100, 1, 0, 0, 'Marshal', 49345),
(@Lilian2, 0, 0, 'No. You''re lying! My father will protect me!', 12, 0, 100, 0, 0, 0, 'Lilian', 49337);
