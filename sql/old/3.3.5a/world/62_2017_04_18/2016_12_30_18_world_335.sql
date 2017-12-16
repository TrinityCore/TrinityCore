-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (57006, 57015, 57018, 57007, 57008, 57009, 57010, 57011);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `OptionBroadcastTextID`) VALUES
(57015, 0, 0, "Yes I checked, I'm missing the top piece!", 1, 1, 57016, 0, 0, 0, "", 11778),
(57015, 1, 0, "Yes I checked, I'm missing the left piece!", 1, 1, 57017, 0, 0, 0, "", 11780),
(57006, 0, 0, "I lost Lord Valthalak's Amulet!", 1, 1, 57014, 0, 0, 0, "", 11773),
(57006, 1, 0, "I lost a piece of Lord Valthalak's Amulet!", 1, 1, 57015, 0, 0, 0, "", 11776),
(57006, 2, 0,"I've misplaced the Brazier of Beckoning!", 1, 1, 57018, 0, 0, 0, "", 11784),
(57006, 3, 0,"Bodley, tell me what's going on.", 1, 1, 57007, 0, 0, 0, "", 11915),
(57018, 0, 0,"Yes, please summon it back!", 1, 1, 57019, 0, 0, 0, "", 11786),
(57007, 0, 0,"You were telling me about The Veiled Blade and how you took the wrong mission.", 1, 1, 57008, 0, 0, 0, "", 11917),
(57008, 0, 0,"No, no, please continue... it's just that the air up here is so, um, smoky.", 1, 1, 57009, 0, 0, 0, "",  11919),
(57009, 0, 0,"Please continue, Bodley.", 1, 1, 57010, 0, 0, 0, "", 11921),
(57010, 0, 0,"I thought you were almost done?", 1, 1, 57011, 0, 0, 0, "", 11923),
(57011, 0, 0,"What happened to your mercenary company, The Veiled Blade?", 1, 1, 57012, 0, 0, 0, "", 11925);

UPDATE `creature_template` SET `gossip_menu_id`=57006, `AIName`='SmartAI', `npcflag`=3 WHERE `entry`=16033;
DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 57006 AND 57019;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (57006,50002),(57007,50003),(57008,50004),(57009,50005),(57010,50006),(57011,50007),(57012,50008),(57006,50009),(57014,50010),(57015,50011),(57016,50012),(57017,50013),(57018,50014),(57019,50015);

DELETE FROM `npc_text` WHERE `ID` BETWEEN 50002 AND 50015;
INSERT INTO `npc_text` (`ID`, `text0_0`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`) VALUES 
(50002, "You can see me? Do you know how much I'm ignored up here just because no one can see me? How refreshing to finally have someone to talk to!$B$BSo, you must have been sent by some living member of my former mercenary company, am I right? Of course I am!$B$BBut enough idle chit-chat, there's a great deal of work for you and I if you're going to put things right and return Lord Valthalak's spirit to him!", 11772, 0, 1, 0, 1),
(50003, "It's quite simple, really, $n. My old merc company, The Veiled Blade, took the wrong mission at the wrong time.$B$BWe were hired by a goblin smuggler out of Booty Bay, one Gremnik Rizzlesprang, who was covetous of Lord Valthalak's spellbook. Or, maybe there was some old rivalry there? I suppose we'll never know now, because Gremnik was killed not too long ago by a group of Valthalak's spectral assassins. They really can be very deadly when a large number of them gather.$B$BWhere was I?", 11916, 0, 1, 0, 1),
(50004, "Oh yes, that's right.$B$BSo, here we are invading deep into the upper reaches of Blackrock Spire, against their lord and leader; this was before Drakkisath. Not too smart if you ask me, but our leader, Anthion Harmon, you met him, was always one who loved a challenge.$B$BSurprisingly, everything went according to plan, right up to the point where we were prying Valthalak's spellbook out of his stiff fingers. That's when it all went south.$B$BShould I continue? You look like your eyes are glazing over.", 11918, 0, 1, 0, 1),
(50005, "<Bodley looks at you dubiously, but continues...>$B$BThere we are, spellbook in hand, and Kormok, our two-headed ogre necromancer, gets this strange look in all four of his eyes. It was really creepy, because that second set of eyes always kind of looked dead, like a cow's eyes, you know? So, all of a sudden he just reaches out and rips this amulet off that Valthalak was wearing.$B$BThe rest of the company went crazy; some of us telling them to leave it alone, and others who wanted it for themselves.", 11920, 0, 1, 0, 1),
(50006, "Sheesh, you don't have to beg! Anyways, I'm almost done with the story.$B$BSo, the whole company is in the middle of that massive chamber fighting over this amulet, and you know how it echoes in there! In the end it was broken into three pieces, and we rolled the dice, with it going to various people or groups.$B$BThe rest is a bit of a blur, though, because it was at about that time that old Valthalak's spirit decided to make an entrance and start summoning forth all of these spectral assassins.", 11922, 0, 1, 0, 1),
(50007, "Cool your heels!$B$B<Bodley grumbles something under his breath about the impatience of the living>$B$BAs I was saying, Lord Valthalak's spirit and spectral assassins, summoned forth through his necromantic dabbling, started to assail us. Let me tell you, at that point we weren't in any condition to fight back, so we ran. I can still remember Mor Grayhoof, one of our druids, slip and fall at one point into the lower reaches of the spire.$B$BThe rest as they say, is history.", 11924, 0, 1, 0, 1),
(50008, "We broke up afterward, that's what happened. Too much bad blood, I guess...it had been building for a while. And the thing with the amulet was the straw that broke the kodo's back.$B$BEver since then Valthalak's servants have been picking us off one by one. Most of the amulet piece holders are dead, their souls corrupted by the portion of Valthalak's spirit contained within it.$B$BThat's why I'm glad that you're here, $n. With your help we'll be able to recombine the amulet and return it to Lord Valthalak!", 11926, 0, 1, 0, 1),
(50009, "$n! You've returned just to talk to me? That's very thoughtful of you, and you look pretty sweet in that outfit, too!$B$BYou don't know how good it makes me feel to see you. It can get pretty lonely up here, what with most of these yahoos not being able to see me, and all. It's a great thing that you did for all of us, and I'll never forget it!$B$BThanks for dropping in and saying hi, and don't be such a stranger.", 11830, 0, 1, 0, 1),
(50010, "Ah, $n, don't cry. Lucky for you, when last you gave me the amulet, I attuned myself to it. I'll just summon it back from wherever you dropped it.$B$BTry looking in your bags now.", 11774, 0, 1, 0, 1),
(50011, "There, there, $n, worry not! Which piece of the amulet have you misplaced?$B$BDid you check all of your bags and the bank?", 11777, 0, 1, 0, 1),
(50012, "Never fear, Bodley is on the job! Let's see here, ah yes... there it is. Let me just summon it... and, presto!$B$BTry not to lose it again, $n.", 11779, 0, 1, 0, 1),
(50013, "Yes, yes, calm down, $c, there's nothing to worry about. As luck would have it, when you first gave the left piece to me, I attuned myself to it, so summoning it back from wherever you 'misplaced' it is really not a problem.$B$BHere, and this time try to take better care of it.", 11781, 0, 1, 0, 1),
(50014, "You're kidding, right? Ok, ok, don't panic. Luckily when I was imbueing it with the component that you retrieved, I attuned myself to it as well. I should be able to locate and summon it from wherever it is that you left it.$B$BAre you sure that you've lost it? You looked in all of your bags and the bank?", 11785, 0, 1, 0, 1),
(50015, "There you go, $n. Good thing my powers of divination and summoning still work in this ghostly state, huh?", 11787, 0, 1, 0, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`=16033 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16033, 0, 0, 0, 62, 0, 100, 0, 57015, 0, 0, 0, 11, 27544, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Left'),
(16033, 0, 1, 0, 62, 0, 100, 0, 57015, 1, 0, 0, 11, 27542, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Top'),
(16033, 0, 2, 0, 62, 0, 100, 0, 57018, 0, 0, 0, 11, 27566, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Brasero'),
(16033, 0, 3, 0, 62, 0, 100, 0, 57006, 3, 0, 0, 11, 27537, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bodley - On Gossip Select - Cast Add Item Amulette');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (57006,57015);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (57006);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 57006, 1, 0, 0, 8, 0, 8966, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 0, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 1, 8, 0, 8967, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 1, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 1, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 2, 8, 0, 8968, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 2, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 2, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 3, 8, 0, 8969, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 3, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 3, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 1, 0, 4, 8, 0, 9015, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 1, 0, 4, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 1, 0, 4, 2, 0, 22047, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 0, 0, 0, 8, 0, 8994, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 0, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57006, 0, 0, 0, 2, 0, 22048, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57006, 2, 0, 0, 8, 0, 8995, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57006, 2, 0, 0, 2, 0, 22056, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 0, 8, 0, 8966, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 0, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 0, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 1, 8, 0, 8967, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 1, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 1, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 2, 8, 0, 8968, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 2, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 2, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 1, 0, 3, 8, 0, 8969, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 1, 0, 3, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 1, 0, 3, 2, 0, 21984, 1, 0, 1, 0, '', 'Requires Missing Item'),
(15, 57015, 0, 0, 4, 8, 0, 9015, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(15, 57015, 0, 0, 4, 8, 0, 8995, 0, 0, 1, 0, '', 'Requires Quest Not Rewarded'),
(15, 57015, 0, 0, 4, 2, 0, 22047, 1, 0, 1, 0, '', 'Requires Missing Item'),
(14, 57006, 50009, 0, 0, 8, 0, 8997, 0, 0, 0, 0, '', 'Requires Quest Rewarded'),
(14, 57006, 50009, 0, 1, 8, 0, 8998, 0, 0, 0, 0, '', 'Requires Quest Rewarded'); 
