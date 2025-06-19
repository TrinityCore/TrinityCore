--
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 20904 AND `GroupID` = 1 AND `ID` = 0;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 20904 AND `GroupID` = 2 AND `ID` = 0;
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 20904 AND `GroupID` = 4 AND `ID` = 0;
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 20904 AND `GroupID` = 5 AND `ID` = 0;
UPDATE `creature_text` SET `Emote` = 11 WHERE `CreatureID` = 20904 AND `GroupID` = 6 AND `ID` = 0;
UPDATE `creature_text` SET `Emote` = 5 WHERE `CreatureID` = 20904 AND `GroupID` = 7 AND `ID` = 0;

UPDATE `conditions` SET `ConditionValue2` = 21437 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 36856;
UPDATE `conditions` SET `ConditionValue2` = 21436 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 36854;

DELETE FROM `creature_text` WHERE `CreatureID` IN (20977);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(20977,0,0,"Where in Bonzo's Brass Buttons am I? And who are-- yaaghh, that's one mother of a headache!",14,0,100,6,0,11171,19108,0,"Millhouse Manastorm SAY_INTRO_1"),
(20977,1,0,"\"Lowly\"? I don't care who you are, friend: no one refers to the mighty Millhouse Manastorm as \"lowly\"!",14,0,100,5,0,11172,19116,0,"Millhouse Manastorm SAY_INTRO_2"),
(20977,2,0,"I have no idea what goes on here, but I will gladly join your fight against this impudent imbecile!",14,0,100,0,0,0,19822,0,"Millhouse Manastorm SAY_INTRO_3"),
(20977,3,0,"Prepare to defend yourself, cretin!",14,0,100,5,0,0,19823,0,"Millhouse Manastorm SAY_INTRO_4"),
(20977,4,0,"I just need to get some things ready first. You guys go ahead and get started. I need to summon up some water....",14,0,100,0,0,11173,19117,0,"Millhouse Manastorm SAY_WATER"),
(20977,5,0,"Fantastic! Next, some protective spells. Yeah, now we're cookin'!",14,0,100,0,0,11174,19119,0,"Millhouse Manastorm SAY_BUFFS"),
(20977,6,0,"And of course I'll need some mana. You guys are gonna love this; just wait....",14,0,100,0,0,11175,19120,0,"Millhouse Manastorm SAY_DRINK"),
(20977,7,0,"Aaalllriiiight!! Who ordered up an extra large can of whoop-ass?",14,0,100,0,0,11176,19121,0,"Millhouse Manastorm SAY_READY"),
(20977,8,0,"I didn't even break a sweat on that one!",14,0,100,0,0,11177,19824,0,"Millhouse Manastorm SAY_SLAY1"),
(20977,8,1,"You guys feel free to jump in anytime.",14,0,100,0,0,11178,19825,0,"Millhouse Manastorm SAY_SLAY2"),
(20977,9,0,"I'm gonna light you up, sweet cheeks!",14,0,100,0,0,11179,19826,0,"Millhouse Manastorm SAY_PYRO"),
(20977,10,0,"Ice, ice baby.",14,0,100,0,0,11180,19827,0,"Millhouse Manastorm SAY_ICEBLOCK"),
(20977,11,0,"Heal me! For the love of all that's holy, heal me! I'm dying!!",14,0,100,0,0,11181,19828,0,"Millhouse Manastorm SAY_LOWHP"),
(20977,12,0,"You'll be hearing from my lawyer!",14,0,100,0,0,11182,19829,0,"Millhouse Manastorm SAY_DEATH"),
(20977,13,0,"Who's bad? Who's bad? That's right: we bad!",14,0,100,4,0,11183,19146,0,"Millhouse Manastorm SAY_COMPLETE");

UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20905 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20906 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20908 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20909 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20910 AND `source_type` = 0 AND `id` = 3;
UPDATE `smart_scripts` SET `action_param1` = 3, `action_param3` = 1 WHERE `entryorguid` = 20911 AND `source_type` = 0 AND `id` = 2;
