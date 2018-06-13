-- 
UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry` IN (737, 773, 1937, 2121, 2285, 2498, 2921, 3845, 5204, 5394, 5591, 7882, 7900, 9078, 10926,11039,22292);
DELETE FROM `quest_greeting` WHERE `ID` IN (737, 773, 1937, 2076, 2121, 2285, 2498, 2921, 3845, 5204, 5394, 5591, 7882, 7900, 9078, 10926,11039,22292);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(737,  0, 0, 0, "Well,, hello there. You seem like you wouldn't be opposed to making some coin,, hm? I can tell from the look in your eyes. I am Mogul Kebok,, overseer of operations in Azeroth,, and if it is riches you seek,, perhaps I can make arrangements.", 0),
(773,  0, 0, 0, "$C,, eh? I am Krazek,, Baron Revilgaz's secretary. I know everything about the goings on in this jungle and beyond. Perhaps you'd be interested in knowing the going price on oil in Ratchet? No? Looking for work,, maybe? I can help you there.", 0),
(1937, 0, 0, 0, "The Dark Lady has put the challenge forth.  Now it is up to the Royal Apothecary Society to develop a new plague.  We shall bring Arthas and his wretched army to their knees.", 0),
(2076, 1, 0, 0, "This cauldron churns with thick,, green bubbles.  Skulls,, bones and organs of unknown creatures swim within its viscous broth...$B$BAnd rising lazily to the surface are the skulls of two,, once mighty trolls:$B$BGan'zulah and Nezzliok.", 0),
(2121, 0, 0, 0, "Information... With our scouts and agents,, we control the flow of information in Lordaeron. Scourge movements,, their holdings,, all underneath our watchful eyes...", 0),
(2285, 0, 0, 0, "My family boasts the finest collection of jewelry and objects of fine art among all the nobles of Stormwind!$B$BAnd we are always wishing to increase the size our collection...", 0),
(2498, 0, 0, 0, "What what?!?  We all have profit to make... and we won't do it by standing idle.", 0),
(2921, 0, 0, 0, "How perfect of you to come by,, $c.$B$BMy name is Lotwil Veriatus,, founding member of the Enlightened Assembly of Arcanology,, Alchemy,, and Engineering Sciences: we seek to blend the intelligent sciences of Azeroth together into one comprehensive school.", 0),
(3845, 0, 0, 0, "We elves have a long history.  Let us hope this history does not return to haunt us.", 0),
(5204, 0, 0, 0, "If we are to make our place in this world,, then we will do so through study,, and through the will to ignore our fading human instincts.", 0),
(5394, 0, 1, 0, "Don't let the heat bother you.  In the Badlands,, heat is the least of your worries.", 0),
(5591, 0, 1, 0, "This sty's a little shy of comfy,, but it has history,, so Stonard must be important to someone. I'd gamble that's why we stay here. It sure ain't for the view--it don't even look like home.", 0),
(7882, 0, 1, 0, "We're here to make a profit.  And having our goods stolen is no way to make a profit.", 0),
(7900, 0, 0, 0, "Hello,, $N. Perhaps you have some time to chat?", 0),
(9078, 0, 1, 0, "Dear $g boy:girl;,, you have arrived just in time to assist the Kargath Expeditionary Force.", 0),
(10926,0, 0, 0, "I never feel warm anymore...", 0),
(11039,0, 1, 0, "Greetings,, $N. I am Duke Nicholas Zverenhoff of the Argent Dawn.", 0),
(22292,0, 396, 0, "The Light does not yet shine on Skettis.", 0);
