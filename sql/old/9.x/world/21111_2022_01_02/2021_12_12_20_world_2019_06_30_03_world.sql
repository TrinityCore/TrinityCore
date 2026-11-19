--
DELETE FROM `smart_scripts` WHERE `entryorguid`=30037 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3003700, 3003701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30037, 0, 0, 1, 25, 0, 100, 512, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Reset - Set Event Phase 1"),
(30037, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Reset - Set Emote State STATE_READY1H"),
(30037, 0, 2, 0, 1, 1, 100, 0, 3000, 3000, 3000, 3000, 0, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - OOC - Play Emote ONESHOT_ATTACK1H (Phase 1)"),
(30037, 0, 3, 0, 1, 1, 20, 0, 10000, 90000, 90000, 120000, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - OOC - Say Line 1 (Phase 1)"),
(30037, 0, 4, 0, 4, 1, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Aggro - Set Event Phase 2 (Phase 1)"),
(30037, 0, 5, 0, 4, 2, 30, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Aggro - Say Line 0 (Phase 2)"),
(30037, 0, 6, 0, 6, 4, 100, 512, 0, 0, 0, 0, 0, 33, 30038, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - Just Died - Quest Credit 'Honor Challenge' (Phase 3)"),
(30037, 0, 7, 0, 8, 1, 100, 0, 21855, 0, 0, 0, 0, 80, 3003700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Spellhit 'Challenge Flag' - Run Actionlist (Phase 1)"),
(30037, 0, 8, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 80, 3003701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Data 1 1 Set - Run Actionlist (Phase 1)"),
(30037, 0, 9, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 11, 61227, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Aggro - Cast 'Jump Attack'"),
(30037, 0, 10, 0, 0, 0, 100, 0, 1000, 2600, 13000, 14000, 0, 11, 50370, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - In Combat - Cast 'Sunder Armor'"),
(30037, 0, 11, 0, 0, 0, 100, 0, 7000, 9000, 9000, 11000, 0, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - In Combat - Cast 'Mortal Strike'"),
(30037, 0, 12, 0, 0, 0, 100, 0, 6000, 8000, 20000, 25000, 0, 11, 49807, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - In Combat - Cast 'Whirlwind'"),
(3003700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Set Event Phase 3"),
(3003700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Set Emote State 0"),
(3003700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Face Invoker"),
(3003700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 30037, 8, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Set Data 1 1 (Mjordin Combatant)"),
(3003700, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Say Line 2"),
(3003700, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 52991, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Cast Spell 'Duel Flag'"),
(3003701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Set Event Phase 2"),
(3003701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Set Emote State 0"),
(3003701, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Mjordin Combatant - On Script - Despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=30037;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=21855;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 3, 30037, 0, 0, 29, 1, 30037, 8, 0, 0, 0, 0, "", "Run SAI for Mjordin Combatant only if there's a Mjordin Combatant within 8 yards"),
(13, 1, 21855, 0, 0, 31, 0, 3, 30037, 0, 0, 0, 0, "", "Spell 'Challenge Flag' only hits Mjordin Combatant");

DELETE FROM `creature_text` WHERE `CreatureID`=30037;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(30037, 0, 0, "Haraak foln!", 12, 0, 100, 0, 0, 13541, 30506, 0, "Mjordin Combatant"),
(30037, 0, 1, "I'll eat your heart!", 12, 0, 100, 0, 0, 13542, 30508, 0, "Mjordin Combatant"),
(30037, 0, 2, "I will take pleasure in gutting you!", 12, 0, 100, 0, 0, 13533, 30498, 0, "Mjordin Combatant"),
(30037, 0, 3, "Die, maggot!", 12, 0, 100, 0, 0, 13536, 30501, 0, "Mjordin Combatant"),
(30037, 0, 4, "Your entrails will make a fine necklace.", 12, 0, 100, 0, 0, 13535, 30500, 0, "Mjordin Combatant"),
(30037, 0, 5, "I will feed you to the dogs!", 12, 0, 100, 0, 0, 13534, 30499, 0, "Mjordin Combatant"),
(30037, 0, 6, "Ugglin oo bjorr!", 12, 0, 100, 0, 0, 13540, 30505, 0, "Mjordin Combatant"),
(30037, 1, 0, "You're weak, old woman!", 12, 0, 100, 14, 0, 0, 30635, 0, "Mjordin Combatant"),
(30037, 1, 1, "Hela take you!", 12, 0, 100, 14, 0, 0, 30636, 0, "Mjordin Combatant"),
(30037, 1, 2, "I will feast in the halls of Ymirheim tonight and you will pour my mead, cur.", 12, 0, 100, 14, 0, 0, 30637, 0, "Mjordin Combatant"),
(30037, 1, 3, "The runes foretold victory for me today!", 12, 0, 100, 14, 0, 0, 30638, 0, "Mjordin Combatant"),
(30037, 1, 4, "Getting tired? Hahahahaha!", 12, 0, 100, 14, 0, 0, 30639, 0, "Mjordin Combatant"),
(30037, 1, 5, "You'll sleep in the underworld tonight!", 12, 0, 100, 14, 0, 0, 30640, 0, "Mjordin Combatant"),
(30037, 1, 6, "You'll wish you'd never been awakened, boy.", 12, 0, 100, 14, 0, 0, 30641, 0, "Mjordin Combatant"),
(30037, 1, 7, "You complain much, like a shield-maiden!", 12, 0, 100, 14, 0, 0, 30642, 0, "Mjordin Combatant"),
(30037, 2, 0, "You think you can challenge me, little $r?", 12, 0, 100, 0, 0, 0, 30690, 0, "Mjordin Combatant"),
(30037, 2, 1, "Your race has no honor. But come anyway... you'll die like all the others!", 12, 0, 100, 0, 0, 0, 30691, 0, "Mjordin Combatant"),
(30037, 2, 2, "By Thorim's beard, this should be good sport!", 12, 0, 100, 0, 0, 0, 30692, 0, "Mjordin Combatant"),
(30037, 2, 3, "Come then, $r $c, I do not have all day!", 12, 0, 100, 0, 0, 0, 30693, 0, "Mjordin Combatant"),
(30037, 2, 4, "It will not get me any closer to proving myself at Valhalas to kill you, but it should be entertaining!", 12, 0, 100, 0, 0, 0, 30694, 0, "Mjordin Combatant"),
(30037, 2, 5, "If you seek death, you have found it!", 12, 0, 100, 0, 0, 0, 30695, 0, "Mjordin Combatant"),
(30037, 2, 6, "A quick trip to the underworld for you, and a laugh for me. Sounds like a fair trade!", 12, 0, 100, 0, 0, 0, 30696, 0, "Mjordin Combatant"),
(30037, 2, 7, "A Drakkari, one of the so-called Scarlet Onslaught, a gnome, a Hyldnir shield-maiden, and now you? Is this a joke?", 12, 0, 100, 0, 0, 0, 30697, 0, "Mjordin Combatant");
