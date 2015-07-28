Set @Zootfizzle:= 28374;
Set @Dorian:= 28376;
Set @Hemet:= 28451;
Set @Stampy:= 28468;
DELETE FROM `vehicle_template_accessory` where `entry` in (@Stampy) AND `accessory_entry` in (@Hemet);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(@Stampy,@Hemet,1,1,'Stampy',8,0);
UPDATE creature_template SET npcflag= 16777216,  spell1=51756, spell2=51751, spell3=51752  WHERE entry=@Stampy; 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` in (@Zootfizzle, @Dorian, @Hemet, @Stampy);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (@Stampy);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(@Stampy, 46598, 1, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dorian*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hemet AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Hemet*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Dorian, 0, 0, 0, 19, 0, 100, 0, 12614, 0, 0, 0, 11, 51757, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest Accept - cast'),
(@Hemet, 0, 0, 0, 0, 0, 100, 0, 0, 0, 6000, 6000, 11, 51742, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dorian - IC - cast'),
(@Hemet, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 15000, 15000, 11, 51740, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dorian - IC - cast'),
(@Dorian, 0, 1, 0, 20, 0, 100, 0, 12614, 0, 0, 0, 80, @Dorian*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest rewarded - ActionList'),
(@Dorian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, @Hemet, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - Despawn'),
(@Dorian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @Hemet, 5, 0, 0, 0, 0, 8, 0, 0, 0, 6448.532715, 5082.552734, -63.941204, 0.673032, 'Dorian - ActionList - Summon'),
(@Dorian*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 75, 59872, 0, 0, 0, 0, 0, 19, @Hemet, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - AddAura to trigger to triiger the event'),
(@Hemet, 0, 2, 0, 23, 0, 100, 0, 59872, 1, 0, 0, 80, @Hemet*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - HasAura - Actionlist'),
(@Hemet*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 59872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Remove aura'),
(@Hemet*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 7, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 8, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Dorian, 20, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Talk'),
(@Hemet*100, 9, 10, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hemet - Actionlist - Despawn'),
-- Securing the Bait
(@Dorian, 0, 2, 0, 20, 0, 100, 0, 12605, 0, 0, 0, 80, @Dorian*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - On quest rewarded - ActionList'),
(@Dorian*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Zootfizzle, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk'),
(@Dorian*100+1, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Zootfizzle, 20, 0, 0, 0, 0, 0, 'Dorian - ActionList - talk');
Delete from `creature_text` where `entry` in (@Hemet, @Dorian, @Zootfizzle);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Hemet, 0, 0, 'What a fight you missed, Dorian! It was one for the ages!', 12, 0, 100, 0, 0, 0, 'Hemet', 28026),
(@Hemet, 1, 0, 'There we were, riding into battle at full speed on the back of Stampy...', 12, 0, 100, 0, 0, 0, 'Hemet', 28027),
(@Hemet, 2, 0, 'Everything was shaking all over the place. I could hardly steady my gun.', 12, 0, 100, 0, 0, 0, 'Hemet', 28028),
(@Hemet, 3, 0, 'And then we saw her, the fearsome beast!', 12, 0, 100, 0, 0, 0, 'Hemet', 28029),
(@Hemet, 4, 0, 'It took all of $n''s skill to maintain control of Stampy.', 12, 0, 100, 0, 0, 0, 'Hemet', 28030),
(@Hemet, 5, 0, 'The battle was a haze of blood, lead, and sweat. The broodmother''s attacks came faster and faster!', 12, 0, 100, 0, 0, 0, 'Hemet', 28032),
(@Hemet, 6, 0, 'But, in the end, $n and I prevailed through our wits and teamwork. And now we have this glorious trophy as a memento of our victory.', 12, 0, 100, 0, 0, 0, 'Hemet', 28033),
(@Hemet, 7, 0, 'Do I detect a bit of jealousy, Dorian?', 12, 0, 100, 0, 0, 0, 'Hemet', 28036),
(@Dorian, 0, 0, 'Well, I don''t know. I was here tending the fire and discussing the drawbacks of cogs with Zootfizzle. That''s pretty epic, too, in its own way.', 12, 0, 100, 0, 0, 0, 'Dorian', 28037),
(@Dorian, 1, 0, 'It''s your lucky day, Zootfizzle. $n has brought back more hatchlings for you.', 12, 0, 100, 0, 0, 0, 'Dorian', 28892),
(@Dorian, 2, 0, 'Well, you can always go back to the camp and help Weslex with all his cogs...', 12, 0, 100, 0, 0, 0, 'Dorian', 28894),
(@Zootfizzle, 0, 0, 'I''m not here to be the keeper of your hatchlings, Dorian. I''m doing research of my own, as well.', 12, 0, 100, 0, 0, 0, 'Zootfizzle', 28893),
(@Zootfizzle, 1, 0, 'No, not the cogs! Anything but the cogs!', 12, 0, 100, 0, 0, 0, 'Zootfizzle', 28895);
