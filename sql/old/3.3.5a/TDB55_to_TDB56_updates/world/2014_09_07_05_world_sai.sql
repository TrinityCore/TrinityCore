
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(19546,19579,19545,19580,19543,19544,-70107,-70108,-70109,-70110,-70111) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1954600,1954500,1954400,1954300) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19546, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Just Summoned - Store Targetlist'),
(19546, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Just Summoned - Set Faction 7'),
(19546, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Just Summoned - Set Flags Immune to NPC/PC'),
(19546, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 19546, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Just Summoned - Start WP'),
(19546, 0, 4, 0, 40, 0, 100, 0, 5, 19546, 0, 0, 80, 1954600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Reached WP5 - Run Script'),
(19546, 0, 5, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 12544, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Aggro - Cast \'Frost Armor\''),
(19546, 0, 6, 0, 0, 0, 100, 0, 2000, 5000, 12000, 22000, 11, 17740, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - In Combat - Cast \'Mana Shield\''),
(19546, 0, 7, 0, 0, 0, 100, 0, 0, 6000, 2500, 8000, 11, 34447, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - In Combat - Cast \'Arcane Missiles\''),
(19546, 0, 8, 0, 25, 0, 100, 0, 0, 0, 0, 0, 28, 12544, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - On Reset - Remove Aura \'Frost Armor\''),
(19545, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - On Just Summoned - Store Targetlist'),
(19545, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - On Just Summoned - Set Faction 7'),
(19545, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - On Just Summoned - Set Flags Immune to NPC/PC'),
(19545, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 19545, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - On Just Summoned - Start WP'),
(19545, 0, 4, 0, 40, 0, 100, 0, 6, 19545, 0, 0, 80, 1954500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - On Reached WP6 - Run Script'),
(19545, 0, 5, 0, 0, 0, 100, 0, 0, 1000, 25000, 30000, 11, 33245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - In Combat - Cast \'Ice Barrier\''),
(19545, 0, 6, 0, 0, 0, 100, 0, 0, 10000, 2500, 9500, 11, 11831, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - In Combat - Cast \'Frost Nova\''),
(19545, 0, 7, 0, 0, 0, 100, 0, 0, 2500, 2500, 11000, 11, 9672, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - In Combat - Cast \'Frostbolt\''),
(19544, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - On Just Summoned - Store Targetlist'),
(19544, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - On Just Summoned - Set Faction 7'),
(19544, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - On Just Summoned - Set Flags Immune to NPC/PC'),
(19544, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 19544, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - On Just Summoned - Start WP'),
(19544, 0, 4, 0, 40, 0, 100, 0, 3, 19544, 0, 0, 80, 1954400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - On Reached WP3 - Run Script'),
(19544, 0, 5, 0, 0, 0, 100, 0, 0, 2500, 1000, 7500, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - In Combat - Cast \'Lightning Bolt\''),
(19544, 0, 6, 0, 0, 0, 100, 0, 0, 5000, 15000, 30000, 11, 36110, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - In Combat - Cast \'Summon Dancing Sword\''),
(19544, 0, 7, 0, 0, 0, 100, 0, 0, 10000, 5000, 15000, 11, 36109, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - In Combat - Cast \'Blink\''),
(19543, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Just Summoned - Store Targetlist'),
(19543, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Just Summoned - Remove Weapon'),
(19543, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Just Summoned - Set Faction 7'),
(19543, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Just Summoned - Set Flags Immune to NPC/PC'),
(19543, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 19543, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Just Summoned - Start WP'),
(19543, 0, 5, 0, 40, 0, 100, 0, 5, 19543, 0, 0, 80, 1954300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - On Reached WP5 - Run Script'),
(19543, 0, 6, 0, 0, 0, 100, 0, 0, 3000, 3000, 8000, 11, 36104, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - In Combat - Cast \'Torrent of Flames\''),
(19543, 0, 7, 0, 0, 0, 100, 0, 0, 2500, 8500, 12000, 11, 17273, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - In Combat - Cast \'Pyroblast\''),
(-70109, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 34212, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - OOC - Cast Blue beam'),
(-70107, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 34211, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - OOC - Cast Blue beam'),
(-70110, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 34209, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - OOC - Cast Blue beam'),
(-70108, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 34212, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - OOC - Cast Blue beam'),
(-70111, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 11, 34211, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Invisible Location Trigger - OOC - Cast Blue beam'),
(1954600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.014257, 'Abjurist Belmara - Script - Set Orientation'),
(1954600, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - Script - Play Emote Use_standing'),
(1954600, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - Script - Play Emote none'),
(1954600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 12742, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - Script - Equip Item'),
(1954600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - Script - Say Line'),
(1954600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 19547, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Abjurist Belmara - Script - Give Kill Credit'),
(1954500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.902409, 'Cohlien Frostweaver - Script - Set Orientation'),
(1954500, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Play Emote Use_standing'),
(1954500, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Say Line'),
(1954500, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Play Emote none'),
(1954500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 36, 19579, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Change Entry to Cohlien Frostweaver with Hat'),
(1954500, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Set Faction'),
(1954500, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 19550, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Cohlien Frostweaver - Script - Give Kill Credit'),
(1954400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.961897, 'Conjurer Luminrath - Script - Set Orientation'),
(1954400, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Say Line'),
(1954400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Play Emote Use_standing'),
(1954400, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Play Emote none'),
(1954400, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Say Line 2'),
(1954400, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 36, 19580, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Change Entry to Luminrath with Cape'),
(1954400, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Set Faction'),
(1954400, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 19548, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Conjurer Luminrath - Script - Give Kill Credit'),
(1954300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.537856, 'Battle-Mage Dathric - Script - Set Orientation'),
(1954300, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - Script - Play Emote Use_standing'),
(1954300, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - Script - Play Emote none'),
(1954300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 18983, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - Script - Equip Item'),
(1954300, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - Script - Say Line'),
(1954300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 19549, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Battle-Mage Dathric - Script - Give Kill Credit');

DELETE FROM `creature_text` WHERE `entry` IN(19545,19544,19543,19546);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(19545, 0, 0, 'Phew! There''s my lucky hat. I''ve been looking for it everywhere.', 12, 0, 100, 0, 0, 0, 'Cohlien Frostweaver',16926),
(19544, 0, 0, 'I can''t possibly go out without my cloak. I hope it''s in here...', 12, 0, 100, 0, 0, 0, 'Conjurer Luminrath',16927),
(19544, 1, 0, 'There it is! I could''ve sworn it wasn''t here last time I checked...', 12, 0, 100, 0, 0, 0, 'Conjurer Luminrath',16929),
(19543, 0, 0, 'I don''t know what I was thinking, going out without my sword. I would''ve put it on if I''d seen it here...', 12, 0, 100, 0, 0, 0, 'Battle-Mage Dathric',16931),
(19546, 0, 0, 'I can''t sleep without a good bedtime story. Now I''m certain to rest well.', 12, 0, 100, 0, 0, 0, 'Abjurist Belmara',16932);

DELETE FROM `waypoints` WHERE `entry` IN(19546,19545,19544,19543);

INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(19546, 1,2237.667, 2393.5, 112.7383, 'Abjurist Belmara'),
(19546, 2,2238.667, 2393.75, 112.9883, 'Abjurist Belmara'),
(19546, 3,2239.417, 2393.25, 112.9883, 'Abjurist Belmara'),
(19546, 4,2239.917, 2392.5, 112.9883, 'Abjurist Belmara'),
(19546, 5,2240.365, 2390.882, 112.6025, 'Abjurist Belmara'),
(19545, 1,2214.206, 2400.794, 108.8995, 'Cohlien Frostweaver'),
(19545, 2,2213.218, 2400.951, 108.8995, 'Cohlien Frostweaver'),
(19545, 3,2204.71, 2408.806, 108.6094, 'Cohlien Frostweaver'),
(19545, 4,2204.71, 2408.806, 108.6094, 'Cohlien Frostweaver'),
(19545, 5,2204.652, 2408.992, 108.6537, 'Cohlien Frostweaver'),
(19545, 6,2202.912, 2411.269, 108.6577, 'Cohlien Frostweaver'),
(19544, 1,2198.386, 2334.958, 89.4724, 'Conjurer Luminrath'),
(19544, 2,2197.577, 2334.37, 89.4724, 'Conjurer Luminrath'),
(19544, 3,2193.663, 2339.085, 90.02818, 'Conjurer Luminrath'),
(19543, 1,2235.705, 2320.857, 92.30136, 'Battle-Mage Dathric'),
(19543, 2,2235.67, 2319.858, 92.30136, 'Battle-Mage Dathric'),
(19543, 3,2233.228, 2317.592, 91.34792, 'Battle-Mage Dathric'),
(19543, 4,2230.454, 2316.294, 90.59956, 'Battle-Mage Dathric'),
(19543, 5,2228.403, 2313.777, 89.63835, 'Battle-Mage Dathric');

DELETE FROM `event_scripts` WHERE `id` IN(12607,12610,12609,12608);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(12607, 0, 10, 19546, 25000, 0, 2236.969, 2393.117, 112.374, 5.811946),
(12610, 0, 10, 19545, 25000, 0, 2212.535, 2401.582, 108.8762, 2.396056),
(12609, 0, 10, 19544, 25000, 0, 2197.269, 2334.741, 89.5162, 2.263612),
(12608, 0, 10, 19543, 25000, 0, 2235.094, 2319.323, 92.07642, 3.889618);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(34209,34211,34212);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 34209, 0, 0, 31, 0, 3, 19656, 0, 0, 0, 0, '', 'Blue Beam Targets Invisible Location trigger'),
(13, 1, 34211, 0, 0, 31, 0, 3, 19656, 0, 0, 0, 0, '', 'Blue Beam Targets Invisible Location trigger'),
(13, 1, 34212, 0, 0, 31, 0, 3, 19656, 0, 0, 0, 0, '', 'Blue Beam Targets Invisible Location trigger');

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=28503 AND `source_type`=0 AND `id`=7 AND `link`=8;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=9098 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=14389 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `spell_area` WHERE `spell`=34102;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(34102, 3733, 0, 0, 0, 0, 2, 1, 64, 11); -- Curse of the Violet Tower

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN(34209,34211,34212);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 34209, 64, '', '', 'Ignore LOS on Blue Beam'),
(0, 34211, 64, '', '', 'Ignore LOS on Blue Beam'),
(0, 34212, 64, '', '', 'Ignore LOS on Blue Beam');
